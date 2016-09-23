fid = fopen('./sample/bad01.pcm');
Data = fread(fid, Inf, 'int16');
Fs=22050;
% player = audioplayer(Data,Fs);
% play(player)
time=linspace(0, length(Data)/Fs, length(Data));
% figure
% plot(time,Data)
Data =double(Data);
load('default_parameter.mat')
[Pitch, nf] = yaapt(Data', Fs, Parameter); 
subplot(4,1,1)
plot(Data)
subplot(4,1,2)
plot(Pitch)
% Pitch_out = Smooth(Pitch);
% subplot(4,1,3)
% plot(Pitch_out)
% subplot(4,1,4)
% plot(Smooth(Pitch_out))
