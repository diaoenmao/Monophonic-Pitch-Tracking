tic
[data1, fs1] = audioread('sample/f1nw0000pes.wav');
[ps, nf1] = yaapt(data1, fs1, 0, [], 0, 1);
time = toc
tic
[data1, fs1] = audioread('sample/f1nw0000pes.wav');
[ps, nf1] = yaapt(data1, fs1, 0, [], 0, 2);
time = toc
tic
[data1, fs1] = audioread('sample/f1nw0000pes.wav');
[ps, nf1] = yaapt(data1, fs1, 0, [], 0, 3);
time = toc