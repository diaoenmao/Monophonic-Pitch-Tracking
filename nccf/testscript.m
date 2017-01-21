tic
[y,fs]=audioread('test.wav');
[F0,t0] = myrapt(y,fs);
figure
plot(F0)
toc
fxrapt(s,Fs,'g');
tic
[s,Fs] = audioread('test.wav');
[fx,tt] = fxrapt(s,Fs,'u');
figure
plot(fx)
toc
tic
[s,Fs] = audioread('test.wav');
sd = downsample(s,4);
[Pitch, nf] = yaapt(sd,8000,1,[]);
figure
plot(Pitch)
toc