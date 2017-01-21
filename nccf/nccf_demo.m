%% Emprical Constants
clc
clear all
Fs = 8000;          %Sampling Rate
%Duration = 2.0;     %Signal Duration 
t = .01;            %Frame advance Duration
w = .0075;          %Analysis window Duration
%% Derived Constants
T = 1/Fs;           %Sampling Interval
z = t/T;            %Frame advance lanegth (samples)
n = w/T;            %Analysis window length (samples)
K = Fs/50;          %Max Lags
% M = (Duration*Fs-K)/z;     %Number of Frames
%time = 0:T:Duration-T; 

%% Signal Generation
% y=0.4*chirp(time,200,Duration,400,'li');
%y = 0.4*sawtooth(2*pi*440*time);
%y = 0.4*cos(2*pi*440*time);
[y,fs]=audioread('test.wav');
y=resample(y,Fs,fs);
time=(0:length(y)-1)/Fs;
Duration = time(end);
M = fix((Duration*Fs-K)/z);     %Number of Frames
subplot(2,1,1)
plot(time,y)
%set(gca,'ylim',[-0.5,0.5])

%% NCCF
R = zeros(K,M);
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