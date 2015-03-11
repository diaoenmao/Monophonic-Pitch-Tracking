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
[y,fs]=audioread('test.wav');
y=resample(y,Fs,fs);
time=(0:length(y)-1)/Fs;
Duration = time(end);
M = round(length(time)/z);     %Number of Frames
subplot(2,1,1)
plot(time,y)

%% NCCF
R = zeros(K,M);
Peaks = zeros(K,M);
Locations = zeros(K,M);
y = y - mean(y);
for i=0:M-1
    for j=i*z+1:i*z+n
        e_m = sum(y(i*z+1:i*z+n).^2);
        for k=Kdmin:K
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
    Peaks(1:length(p),i+1) = p;
    Locations(1:length(loc),i+1) = loc;
%     r = xcorr(sm,'coeff');
%     R(:,i+1) = r';
end
%% Peak Selection
%%
subplot(2,1,2)
imagesc([0, Duration],[Kdmin,K],R)
set(gca,'YDir','normal');
colormap(flipud(colormap('gray')))
colorbar('southoutside')