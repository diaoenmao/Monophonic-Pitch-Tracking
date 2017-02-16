close all
[Data, Fs] = audioread ('sample/record.wav');
player = audioplayer(Data,Fs);
play(player);
time=linspace(0,length(Data)/Fs,length(Data));
figure
plot(time,Data)
interval = onsetoffset(Data,Fs);
n_interval = size(interval,1);
blocksfreq = zeros(n_interval,2);
for i=1:size(interval,1)
    blocksfreq(i,:) = blockfreq(Data(interval(i,1):interval(i,2)),Fs);
end
