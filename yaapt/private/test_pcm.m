Data = csvread('./data.csv'); 
Fs=22050;
[Pitch, nf] = yaapt(Data', Fs); 
subplot(2,1,1)
plot(Data)
subplot(2,1,2)
plot(Pitch)