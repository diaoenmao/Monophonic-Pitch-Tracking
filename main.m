F0min = 100;
F0max = 500;
CAND_TR = 0.3;
t = 0.01;
z = round(t*Ts);
[high_pass,fs]=audioread(wavfile); 
fds=fs/(round(fs/(4*F0max)));
downsample_rate = fs/fds;
low_pass=downsample(high_pass,round(downsample_rate));
k_min=round(Fds/F0max);
k_max=round(Fs/F0min);
for i=1:z:length(low_pass)
    [nccf_lowpass,nccf_lowpass_lags]=xcorr(
end