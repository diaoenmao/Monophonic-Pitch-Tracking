function [F0,t0] = myrapt(y,fs)
%% Emprical Constants
Fs = 8000;                       %sampling Rate
F0min = 50;                      %minimum F0 to search for (HZ)
F0max = 500;                     %maximum F0 to search for (HZ)
Fds = Fs/(round(Fs/(4*F0max)));  %low sampling rate
t = .01;                         %frame advance Duration
w = .0075;                       %analysis window Duration
CAND_TR = 0.3;                   %minimum acceptable peak value
N_CANDS = 20;                    %max number of hypothese(candidates) at each frame
A_FACT = 10^(-7);                  %unvoiced detection, term to decrease peaks of weak signals
% Constatnts for dynamic programming pitch selection
LAG_WT = 0.3;                    %linear lag taper factor for NCCF
FREQ_WT = 0.02;                  %cost factor for F0 range
VTRAN_C = 0.005;                 %fixed voicing-state transition cost
VTR_A_C = 0.5;                   %delta amplitude modulated tranistion cost
VTR_S_C = 0.5;                   %delta spectrum modulated transition cost
VO_BIAS = 0.0;                   %bias to encourage voiced hypotheses
DOUBLE_C = 0.35;                 %cost of exact F0 doubling or halving
preemph = -7000;                 %s-plane position of preemphasis zero      
nfullag = 7;                     %number of full lags to try (must be odd)
%% Derived Constants
T = 1/Fs;                        %sampling Interval for Fs
Td = 1/Fds;
kdsmp = Fs/Fds;
zd = round(t*Fds);
z = zd*kdsmp;                  %frame step size for Fs(samples)
nd = round(w*Fds);
n = nd*kdsmp;                  %analysis window length for Fs(samples), number of samples correlated at each lag

Kmax = round(Fds/F0min);        %max Lags, longeset lag at each frame for Fds
Kmin = round(Fds/F0max);        %min Lags, shortest lag at each frame for Fds

lagoff=(Kmin-1)*kdsmp;           %lag offset when converting to high sample rate
J = round(0.03*Fs);              %window spacing for rms measurement
h = round(0.02*Fs);              %window spacing for rms measurement
lpcord = 2+round(Fs/1000);       %lpc order for itakura distance
%% Signal Generation
% Duration = 2.0;                 %signal Duration 
% time = 0:T:Duration-T; 
% y=0.4*chirp(time,200,Duration,400,'li');
% y = 0.4*sawtooth(2*pi*440*time);
% yh = 0.4*cos(2*pi*440*time);
yh = resample(y,Fs,fs);
yd = resample(y,Fds,fs);
time = (0:length(yh)-1)/Fs;
timed = (0:length(yd)-1)/Fds;
Duration = time(end);
M = round(length(time)/z);
figure
subplot(3,1,1)
plot(time,yh)

Prm = struct(...
    'frame_length',   25, ... % Length of each analysis frame (ms)
    'frame_space',    10, ... % Spacing between analysis frame (ms)
    'f0_min',         60, ... % Minimum F0 searched (Hz)
    'f0_max',        400, ... % Maximum F0 searached (Hz)
    'fft_length',   8192, ... % FFT length
    'nlfer_thresh1',0.75); % NLFER boundary for voiced/unvoiced decisions
[Energy, VUVEnergy]= nlfer(y, fs, Prm);
VUVEnergy = logical(VUVEnergy);

%% NCCF LowPass
R = zeros(Kmax,M);
Peaks = zeros(N_CANDS,M);
Locations = zeros(N_CANDS,M);
yd = yd - mean(yd);
for i=0:M-1
    for j=i*zd+1:i*zd+nd
            if(i*zd+nd > length(yd))
                break;
            end
        e_m = sum(yd(i*zd+1:i*zd+nd).^2);
        for k=Kmin:Kmax-1
            if(i*zd+nd+k+1 > length(yd))
                break;
            end
            e_mpk = sum(yd(i*zd+1+k:i*zd+nd+k).^2);
            R(k,i+1)=R(k,i+1)+(yd(j)*yd(j+k)/sqrt(e_m*e_mpk));
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
    [p,loc_sort] = sort(p,'descend');
    loc = loc(loc_sort);
    if (length(p) > N_CANDS-1)
        p = p(1:N_CANDS-1);
        loc = loc(1:N_CANDS-1);
    end
    p(R(loc-1,i+1) == 0) = [];
    loc(R(loc-1,i+1) == 0) = [];   
    [~,p,~]=qint(R(loc-1,i+1),p,R(loc+1,i+1));
    Peaks(1:length(p),i+1) = p;
    Locations(1:length(loc),i+1) = loc;
end
Peaks(~VUVEnergy) = 0;
Locations(~VUVEnergy) = 0;
%% NCCF HighPass
RL = R;
R = zeros(Kmax,M);
High_Peaks = zeros(N_CANDS,M);
High_Locations = zeros(N_CANDS,M);
yh = yh - mean(yh);
Ii = struct('Cij',{},'Lij',{},'dij',{},'diI',{},'Li_1k',{},'deltaijk',{},'cost',{},'prev',{});
for i=0:M-1
    for j=i*z+1:i*z+n
        if(i*z+n > length(yh))
            break;
        end
        e_m = sum(yh(i*z+1:i*z+n).^2);
        Khat = Locations(:,i+1);
        Khat(Khat==0) = [];
        Khat = sevnadj(Khat');
        Khat(Khat==0) = [];
        Khat(Khat>Kmax) = [];
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
    [p,loc_sort] = sort(p,'descend');
    loc = loc(loc_sort);
    if (length(p) > N_CANDS-1)
        p = p(1:N_CANDS-1);
        loc = loc(1:N_CANDS-1);
    end
    p(R(loc-1,i+1) == 0) = [];
    loc(R(loc-1,i+1) == 0) = [];   
    High_Peaks(1:length(p),i+1) = p;
    High_Locations(1:length(loc),i+1) = loc;
    %% Peak Selection
    beta = LAG_WT/(Fs/F0min);
    Ii(i+1).Cij = p;                                                    %value of the jth local maximum in Peaks at frame i
    Ii(i+1).Lij = loc;                                                  %sample lag at which Cij was observed
    Ii(i+1).dij = 1-Ii(i+1).Cij.*(1-beta.*Ii(i+1).Lij);                 %objective function as the local cost for frame i is voiced with period TLij
    Ii(i+1).diI = VO_BIAS + max(Ii(i+1).Cij);                           %cost for the single unvoiced hypothesis at this frame
    if (~any(High_Locations(:,i+1)))
        Ii(i+1).diI = VO_BIAS;
    end
    if (i+1==1)                                                         %the first frame
        Ii(i+1).deltaijk = 0;                                           %inter-frame F0 transitioin cost delta at frame i
        Ii(i+1).cost = 0;
        costm=zeros(1,length(Ii(i+1).Lij)+1);
    else
        costm=zeros(length(Ii(i).Lij)+1,length(Ii(i+1).Lij)+1);
        if (any(High_Locations(:,i))&&(any(High_Locations(:,i+1))))        %current and previous frames are both voiced
            epsilonjk=abs(log(repmat(Ii(i+1).Lij',length(Ii(i).Lij),1)./repmat(Ii(i).Lij,1,length(Ii(i+1).Lij))));
            Ii(i+1).deltaijk = FREQ_WT*min(epsilonjk,DOUBLE_C+abs(epsilonjk-log(2.0)));
            costm(2:end,2:end)=Ii(i+1).deltaijk;
        else
            rmsidx = i*z+1+(1:J)+floor((h-z)/2);
            rmsidx_h = rmsidx-h;
            rmswin = hann(J);
            if (max(rmsidx(rmsidx_h>0))>length(yh) || max(rmsidx_h(rmsidx_h>0))>length(yh))
                break;
            end
            rri=sqrt((rmswin(rmsidx_h>0)'*yh(rmsidx(rmsidx_h>0)).^2)/(rmswin(rmsidx_h>0)'*yh(rmsidx_h(rmsidx_h>0)).^2));
            sp=filter([1 exp(preemph/fs)],1,yh);                               %preemphasised speech for LPC calculation
            Si=0.2/(distitar(lpcauto(sp(rmsidx(rmsidx_h>0)),lpcord),lpcauto(sp(rmsidx_h(rmsidx_h>0)),lpcord),'e')-0.8);
            if (any(High_Locations(:,i))&&(~any(High_Locations(:,i+1))))       %voiced to unvoiced 
                Ii(i+1).deltaijk = VTRAN_C + VTR_S_C*Si + VTR_A_C*rri;   
                costm(2:end,1)= Ii(i+1).deltaijk;
            elseif (~any(High_Locations(:,i))&&(any(High_Locations(:,i+1))))   %unvoiced to voiced
                Ii(i+1).deltaijk = VTRAN_C + VTR_S_C*Si + VTR_A_C/rri;
                costm(1,2:end) = Ii(i+1).deltaijk;
            elseif (~any(High_Locations(:,i))&&(~any(High_Locations(:,i+1))))  %unvoiced to unvoiced
                Ii(i+1).deltaijk = 0;
            end
        end
        costall = [Ii(i).diI;Ii(i).dij];
        if (isempty(costall))
            costall = 0;
        end
        costm=costm+repmat(costall,1,length(Ii(i+1).Lij)+1);  % add in cumulative costs
        [costi,previ]=min(costm,[],1);
        Ii(i+1).cost = [Ii(i+1).diI;Ii(i+1).dij]'+ costi;
        Ii(i+1).prev = previ; 
    end                          
end
%% Trace Back
best=zeros(1,length(Ii)-1);
[cbest,best(length(Ii)-1)]=min(Ii(end-1).cost);
for i=length(Ii)-2:-1:1
    best(i)=Ii(i+1).prev(best(i+1));
end
Lags =[];
for i=1:length(Ii)-1
    Lags = [Lags High_Locations(best(i),i)];
end
Lags(Lags ~= 0) = Lags(Lags ~= 0) * kdsmp;
Prm = struct(...
    'frame_length',   25, ... % Length of each analysis frame (ms)
    'frame_space',    10, ... % Spacing between analysis frame (ms)
    'f0_min',         60, ... % Minimum F0 searched (Hz)
    'f0_max',        400, ... % Maximum F0 searached (Hz)
    'fft_length',   8192, ... % FFT length
    'nlfer_thresh1',0.75); % NLFER boundary for voiced/unvoiced decisions
F0 = Fs./Lags;
F0(~isfinite(F0)) = 0;
[Energy, VUVEnergy]= nlfer(y, fs, Prm);
VUVEnergy = [zeros(1,length(F0)-length(VUVEnergy)) VUVEnergy];
VUVEnergy = logical(VUVEnergy);
B = 1/40*ones(1,40);
F0 = filter(B,1,F0);
F0(~VUVEnergy)=0;
t0 = 0:0.01:length(F0)*0.01-0.01;
%% Plot
subplot(3,1,2)
imagesc([0, Duration],[Kmin+1,Kmax],R)
set(gca,'YDir','normal');
colormap(flipud(colormap('gray')))
colorbar('southoutside')
subplot(3,1,3)
plot(t0,F0);
end

