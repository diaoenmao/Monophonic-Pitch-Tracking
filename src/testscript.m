tic
[y,fs]=audioread('test.wav');
[F0,t0] = myrapt(y,fs);
figure
plot(F0)
toc
tic
[s,Fs] = audioread('test.wav');
[fx,tt] = learnrapt(s,Fs);
figure
plot(fx)
toc
tic
[s,Fs] = audioread('test.wav');
[Pitch, nf] = yaapt(s,Fs,1,[]);
figure
plot(Pitch)
toc