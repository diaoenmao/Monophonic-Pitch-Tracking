tic
[s,Fs] = audioread('test.wav');
[fx,tt] = myrapt(s,Fs);
figure
plot(fx)
toc
tic
[s,Fs] = audioread('test.wav');
[Pitch, nf] = yaapt(s,Fs,1,[]);
figure
plot(Pitch)
toc