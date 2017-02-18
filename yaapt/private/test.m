close all
%% Note Detection
load('target_freq.mat')
[Data, Fs] = audioread ('sample/04.wav');
interval = onsetoffset(Data,Fs);
n_interval = size(interval,1);
blocksnum = zeros(n_interval,2);
for i=1:size(interval,1)
    blocksnum(i,:) = blocknum(Data(interval(i,1):interval(i,2)),Fs);
end
midi=num2midi(blocksnum);
midi_fq=midi2fq(midi);

%% play
newData = zeros(length(Data),1);
duration = diff(interval,1,2)+1;
for i=1:length(duration)
    t = linspace(0,duration(i)./Fs,duration(i));
    mod = sin(pi*t/t(end));
    newData(interval(i,1):interval(i,2),1)=mod.*cos(2*pi*midi_fq(i)*t);
end

time=linspace(0,length(Data)/Fs,length(Data));
figure
plot(time,Data)
figure
plot(time,newData)
newplayer = audioplayer([Data;newData],Fs);
play(newplayer);