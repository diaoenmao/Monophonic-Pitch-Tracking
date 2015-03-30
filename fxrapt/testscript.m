[y,fs] = audioread('test.wav');
fxrapt(y,fs,'g');
tic
[fx,tt] = fxrapt(y,fs,'u');
toc
plot(tt(:,1),fx)