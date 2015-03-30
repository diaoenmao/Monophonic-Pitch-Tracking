[y,fs] = audioread('test.wav');
fxrapt(y,fs,'g');
tic
[fx,tt] = fxrapt(y,fs,'u');
toc
figure
plot(fx)