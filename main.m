%% Emprical Constants
clc
clear all
Fs = 8000;                       %Sampling Rate
F0min = 50;                      %minimum F0 to search for (HZ)
F0max = 500;                     %maximum F0 to search for (HZ)
Fds = Fs/(round(Fs/(4*F0max)));  %Low sampling rate
t = .01;                         %Frame advance Duration
w = .0075;                       %Analysis window Duration
CAND_TR = 0.3;                   % minimum acceptable peak value
N_CANDS = 20;                    %max number of hypothese(candidates) at each frame
A_FACT = 10000;                  %unvoiced detection, term to decrease peaks of weak signals
% Constatnts for dynamic programming pitch selection
LAG_WT = 0.3;                    %linear lag taper factor for NCCF
FREQ_WT = 0.02;                  %cost factor for F0 range
VTRAN_C = 0.005;                 %fixed voicing-state transition cost
VTR_A_C = 0.5;                   %delta amplitude modulated tranistion cost
VTR_S_C = 0.5;                   %delta spectrum modulated transition cost
VO_BIAS = 0.0;                   %bias to encourage voiced hypotheses
DOUBLE_C = 0.35;                  %cost of exact F0 doubling or halving
%% Derived Constants
T = 1/Fs;                       %Sampling Interval for Fs
z = round(t/T);                %Frame step size for Fs(samples)
n = round(w/T);                %Analysis window length for Fs(samples), number of samples correlated at each lag 
K = round(Fs/F0min);            %Max Lags, longeset lag at each frame for Fs
Kmin = round(Fs/F0max);         %Min Lags, shortest lag at each frame for Fs

Kdmax = round(Fds/F0min);        %Max Lags, longeset lag at each frame for Fds
Kdmin = round(Fds/F0max);        %Min Lags, shortest lag at each frame for Fds


%% Signal Generation
%y=0.4*chirp(time,200,Duration,400,'li');
%y = 0.4*sawtooth(2*pi*440*time);
%y = 0.4*cos(2*pi*440*time);
[yh,fs]=audioread('test.wav');
y=resample(yh,Fs,fs);
time=(0:length(y)-1)/Fs;
Duration = time(end);
M = round(length(time)/z);     %Number of Frames
subplot(2,1,1)
plot(time,y)

%% NCCF LOWPASS
R = zeros(K,M);
Peaks = zeros(N_CANDS,M);
Locations = zeros(N_CANDS,M);
y = y - mean(y);
for i=0:M-1
    for j=i*z+1:i*z+n
        e_m = sum(y(i*z+1:i*z+n).^2);
        for k=Kdmin:K-1
            if(i*z+n+k+1 > length(y))
                break;
            end
            e_mpk = sum(y(i*z+1+k:i*z+n+k).^2);
            R(k,i+1)=R(k,i+1)+(y(j)*y(j+k)/sqrt(e_m*e_mpk));
        end
    end
    [max_peak loc_max] = max(R(:,i+1));
    [p,loc] = findpeaks(R(:,i+1));
    if (~any(ismember(p,max_peak)))
        p = [p;max_peak];
        loc = [loc;loc_max];
    end
    p = p(p >CAND_TR*max_peak);
    loc = loc(p>CAND_TR*max_peak);
    if (length(p) > N_CANDS-1)
        [p,loc_sort] = sort(p,'descend');
        loc = loc(loc_sort);
        p = p(1:N_CANDS-1);
        loc = loc(1:N_CANDS-1);
    end
    p(R(loc-1,i+1) == 0) = [];
    loc(R(loc-1,i+1) == 0) = [];   
    [~,p,~]=qint(R(loc-1,i+1),p,R(loc+1,i+1));
    Peaks(1:length(p),i+1) = p;
    Locations(1:length(loc),i+1) = loc;
end
%% NCCF HIGHPASS
R = zeros(K,M);
High_Peaks = zeros(N_CANDS,M);
High_Locations = zeros(N_CANDS,M);
yh = yh - mean(yh);
for i=0:M-1
    for j=i*z+1:i*z+n
        e_m = sum(yh(i*z+1:i*z+n).^2);
        Khat = Locations(:,i+1);
        Khat(Khat==0) = [];
        Khat = sevnadj(Khat');
        Khat(Khat==0) = [];
        Khat(Khat>K) = [];
        if (~isempty(Khat))
            for k=Khat
               if(i*z+n+k+1 > length(yh))
                  break;
               end
              e_mpk = sum(yh(i*z+1+k:i*z+n+k).^2);
              R(k,i+1)=R(k,i+1)+(yh(j)*yh(j+k)/sqrt(A_FACT+e_m*e_mpk));
            end
        end
    end
    [max_peak loc_max] = max(R(:,i+1));
    [p,loc] = findpeaks(R(:,i+1));
    if (~any(ismember(p,max_peak)))
        p = [p;max_peak];
        loc = [loc;loc_max];
    end
    p = p(p >CAND_TR*max_peak);
    loc = loc(p>CAND_TR*max_peak);
    if (length(p) > N_CANDS-1)
        [p,loc_sort] = sort(p,'descend');
        loc = loc(loc_sort);
        p = p(1:N_CANDS-1);
        loc = loc(1:N_CANDS-1);
    end
    p(R(loc-1,i+1) == 0) = [];
    loc(R(loc-1,i+1) == 0) = [];   
    High_Peaks(1:length(p),i+1) = p;
    High_Locations(1:length(loc),i+1) = loc;
    %% Peak Selection
    deltaijk = cell(M);
    beta = LAG_WT/(Fs/F0min);
    Cij = p;
    Lij = loc;
    dij = 1-Cij.*(1-beta.*Lij);     %objective function as the local cost for frame i is voiced with period TLij
    diI = VO_BIAS + max(Cij);       %cost for the single unvoiced hypothesis at this frame   
    if (i==0)
        deltaijk(i)=0;
    elseif (any(High_Locations(1:length(loc),i)~=0)&&(any(p~=0)))  %current adn previous frames are both voiced
        Li_1k = High_Locations(1:length(loc),i);
        Li_1k(Li_1k==0) = [];
        epsilonjk = abs(log(respecdiv(Lij,Li_1k)));     
        
        deltaijk(i) = FREQ_WT*min(epsilonjk,DOUBLE_C+abs(epsilonjk-log(2.0))); %inter-frame F0 transitioin cost delta at frame i
    end
end






%%
subplot(2,1,2)
imagesc([0, Duration],[Kdmin,K],R)
set(gca,'YDir','normal');
colormap(flipud(colormap('gray')))
colorbar('southoutside')