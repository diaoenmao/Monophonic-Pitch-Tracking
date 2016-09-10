load('default_parameter.mat')

[Data, Fs] = audioread ('sample/04.wav');
player = audioplayer(Data,Fs);
play(player);
[Pitch, nf] = yaapt(Data',Fs, Parameter); 
figure
subplot(2,1,1)
plot(Data)
subplot(2,1,2)
plot(Pitch)