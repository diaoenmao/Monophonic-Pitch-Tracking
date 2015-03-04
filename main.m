%% Emprical Constants
clc
clear all
Fs = 8000;                       %Sampling Rate
F0min = 50;                      %minimum F0 to search for (HZ)
F0max = 500;                     %maximum F0 to search for (HZ)
Fds = Fs/(round(Fs/(4*F0max)));  %Low sampling rate
CAND_TR = 0.3;                   %minimum acceptable peak value in NCCF
N_CANDS = 20;                    %max number of hypothese(candidates) at each frame
t = .01;                         %Frame advance Duration
w = .0075;                       %Analysis window Duration
%% Derived Constants
Ts = 1/Fs;                       %Sampling Interval for Fs
zs = round(t/Ts);                %Frame step size for Fs(samples)
ns = round(w/Ts);                %Analysis window length for Fs(samples), number of samples correlated at each lag 
Ks = round(Fs/F0min);            %Max Lags, longeset lag at each frame for Fs

Kds = round(Fds/F0min);          %Max Lags, longeset lag at each frame for Fds
%% Signal Generation
% y=0.4*chirp(time,200,Duration,400,'li');
%y = 0.4*sawtooth(2*pi*440*time);
%y = 0.4*cos(2*pi*440*time);
[y,fs]=audioread('test.wav');
y=resample(y,Fs,fs);
time=(0:length(y)-1)/Fs;
Duration = time(end);
M = round(length(time)/zs);     %Number of Frames
subplot(2,1,1)
plot(time,y)

%% NCCF
R = zeros(Ks,M);
y = y - mean(y);
for i=0:M-1
    for j=i*z+1:i*z+n
        e_m = sum(y(i*z+1:i*z+n).^2);
        for k=1:K
            e_mpk = sum(y(i*z+1+k-1:i*z+n+k-1).^2);
            R(k,i+1)=R(k,i+1)+(y(j)*y(j+k-1)/sqrt(e_m*e_mpk));
        end
    end
%     r = xcorr(sm,'coeff');
%     R(:,i+1) = r';
end
%%
subplot(2,1,2)
imagesc([0, Duration],[0,K-1],R)
set(gca,'YDir','normal');
colormap(flipud(colormap('gray')))
colorbar('southoutside')