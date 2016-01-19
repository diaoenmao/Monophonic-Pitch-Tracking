Data = csvread('./data.csv'); 
Fs=22050;
[Pitch, nf] = yaapt(Data', Fs); 
subplot(3,1,1)
plot(Data)
subplot(3,1,2)
plot(Pitch)
Pitch_opt = Pitch_Optimization(Pitch);
subplot(3,1,3)
plot(Pitch_opt)
player = audioplayer(int16(Data),Fs);
play(player)