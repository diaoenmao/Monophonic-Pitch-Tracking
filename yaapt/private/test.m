[Data, Fs] = audioread ('sample/04.m4a'); 
[Pitch, nf] = yaapt(Data', Fs); 
 subplot(2,1,1)
 plot(Data)
 subplot(2,1,2)
 plot(Pitch)