Data = csvread('./data.csv'); 
Fs=22050;
%  Parameter = [20,30,60,600,8192,150,50,1500,0.75,0.1,3,40,4,50,5,1.25,300,300,...
%      11,1,0.25,0.9,3,5,0.2,0.99,0.4,7,0.15,0.5,0.1,0.9,10,-1];
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
% player = audioplayer(int16(Data),Fs);
% play(player)