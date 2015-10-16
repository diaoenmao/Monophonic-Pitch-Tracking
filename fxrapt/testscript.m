[y,fs] = audioread('01.wav');
fxrapt(y,fs,'g');
tic
[fx,tt] = fxrapt(y,fs,'u');
toc
figure
plot(fx)