Data = csvread('./data.csv'); 
Fs=22050;
[Pitch, nf] = yaapt(Data', Fs); 
subplot(4,1,1)
plot(Data)
subplot(4,1,2)
plot(Pitch)
% Pitch_out = Smooth(Pitch);
% subplot(4,1,3)
% plot(Pitch_out)
% subplot(4,1,4)
% plot(Smooth(Pitch_out))
% player = audioplayer(int16(Data),Fs);
% play(player)