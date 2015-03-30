%%full length entry
tic
[y,fs] = audioread('test.wav');
[fxd,tt] = fxrapt(y,fs,'u');
fx =zeros(1,tt(1,1));
for i=1:size(tt,1)
    fx = [fx zeros(1,tt(i,2)-tt(i,1))+fxd(i)];
end
toc
%%1s per entry
tic
fx_1sd = [];
tt_1s=[];
wavfiles_1s = dir('./1s per entry/*.wav');
numfiles_1s = numel(wavfiles_1s);
for i = 1:numfiles_1s
    [y_1s,fs] = audioread(sprintf('./1s per entry/%d.wav',i));
    [fx_temp,tt_temp] = fxrapt(y_1s,fs,'u');
    fx_1sd = [fx_1sd fx_temp'];
    if (i > 1)
        interval_temp = tt_1s(end,1:2) - tt_1s(end-1,1:2);
        temp = tt_temp(1,1:2) - interval_temp;
        entry_length = size(tt_temp,1);
        tt_temp(:,1:2) = tt_temp(:,1:2) + repmat(tt_1s(end,1:2),entry_length,1) - repmat(temp,entry_length,1) ;
    end
    tt_1s = [tt_1s; tt_temp];
end
fx_1s =zeros(1,tt_1s(1,1));
for i=1:size(tt_1s,1)
    fx_1s = [fx_1s zeros(1,tt_1s(i,2)-tt_1s(i,1))+fx_1sd(i)];
end
toc
%%500ms per entry
tic
fx_500msd = [];
tt_500ms=[];
wavfiles_500ms = dir('./500ms per entry/*.wav');
numfiles_500ms = numel(wavfiles_500ms);
for i = 1:numfiles_500ms
    [y_500ms,fs] = audioread(sprintf('./500ms per entry/%d.wav',i));
    [fx_temp,tt_temp] = fxrapt(y_500ms,fs,'u');
    fx_500msd = [fx_500msd fx_temp'];
    if (i > 1)
        interval_temp = tt_500ms(end,1:2) - tt_500ms(end-1,1:2);
        temp = tt_temp(1,1:2) - interval_temp;
        entry_length = size(tt_temp,1);
        tt_temp(:,1:2) = tt_temp(:,1:2) + repmat(tt_1s(end,1:2),entry_length,1) - repmat(temp,entry_length,1);
    end
    tt_500ms = [tt_500ms; tt_temp];
end
fx_500ms =zeros(1,tt_500ms(1,1));
for i=1:size(tt_500ms,1)
    fx_500ms = [fx_500ms zeros(1,tt_500ms(i,2)-tt_500ms(i,1))+fx_500msd(i)];
end
toc
%%100ms per entry
tic
fx_100msd = [];
tt_100ms=[];
wavfiles_100ms = dir('./100ms per entry/*.wav');
numfiles_100ms = numel(wavfiles_100ms);
for i = 1:numfiles_100ms
    [y_100ms,fs] = audioread(sprintf('./100ms per entry/%d.wav',i));
    [fx_temp,tt_temp] = fxrapt(y_100ms,fs,'u');
    fx_100msd = [fx_100msd fx_temp'];
    if (i > 1)
        interval_temp = tt_100ms(end,1:2) - tt_100ms(end-1,1:2);
        temp = tt_temp(1,1:2) - interval_temp;
        entry_length = size(tt_temp,1);
        tt_temp(:,1:2) = tt_temp(:,1:2) + repmat(tt_1s(end,1:2),entry_length,1) - repmat(temp,entry_length,1);
    end
    tt_100ms = [tt_100ms; tt_temp];
end
fx_100ms =zeros(1,tt_100ms(1,1));
for i=1:size(tt_100ms,1)
    fx_100ms = [fx_100ms zeros(1,tt_100ms(i,2)-tt_100ms(i,1))+fx_100msd(i)];
end
toc
%%plot
figure
subplot(5,1,1)
plot(0:1/fs:(length(y)-1)/fs,y);
title('full entry')
subplot(5,1,2)
fx = resample(fx,round((length(fx)-1)/((length(y)-1)/fs)),fs);
plot(0:1/fs:(length(fx)-1)/fs,fx);
title('1s entry')
subplot(5,1,3)
fx_1s = resample(fx_1s,round((length(fx_1s)-1)/((length(y)-1)/fs)),fs);
plot(0:1/fs:(length(fx_1s)-1)/fs,fx_1s);
title('500ms entry')
subplot(5,1,4)
fx_500ms = resample(fx_500ms,round((length(fx_500ms)-1)/((length(y)-1)/fs)),fs);
plot(0:1/fs:(length(fx_500ms)-1)/fs,fx_500ms);
subplot(5,1,5)
fx_100ms = resample(fx_100ms,round((length(fx_100ms)-1)/((length(y)-1)/fs)),fs);
plot(0:1/fs:(length(fx_100ms)-1)/fs,fx_100ms);
title('100ms entry')