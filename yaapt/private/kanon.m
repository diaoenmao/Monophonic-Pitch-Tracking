% Cripple Pachebel's Canon on Matlab
% Have fun

fs = 44100; % sample rate 意思是44100 samples/sec 1个sample等于16 bit等于2 byte
            % 比特率为 44100 * 16 / 1024 = 4306 kbps
dt = 1/fs;  % 用来sample的周期

T16 = 0.125;% 十六分之一音符 设定为0.125秒

t16 = 0:dt:T16; % 这是一个十六分之一音符经过sample之后
[~, k] = size(t16); % k = 5513, 多了一个零

t4 = linspace(0,4*T16,4*k); % 这是一个四分之一音符 4*T16 = 4*1/16 = 1/2
t8 = linspace(0,2*T16,2*k); % 这是一个八分之一音符 2*T16 = 2*1/16 = 1/8

[~, i] = size(t4); % 长度为十六分之一音符的4倍
[~, j] = size(t8); % 长度为十六分之一音符的2倍

% Modification functions
% 这几个mod分别制造了一个sin的半周期 应该是用来调整每个音符的响度，使其更加圆润
mod4 = sin(pi*t4/t4(end));
% figure
plot(t4,mod4)
mod8 = sin(pi*t8/t8(end));
% figure
% plot(t8,mod8)
mod16 = sin(pi*t16/t16(end));
% figure
% plot(t16,mod16)

f0 = 2*146.8; % reference frequency
              % 这是一个参考频率？它是用于制作各个音符的频率，
              % 具体为什么设置成这个频率？
              % 发现了，没什么太大意义，就是提供一个频率变化的基准
              % 貌似是以D4为原型
% 这是一个ScaleTable
% 
ScaleTable = [2/3 3/4 5/6 15/16 ...
              1 9/8 5/4 4/3 3/2 5/3 9/5 15/8 ...
              2 9/4 5/2 8/3 3 10/3 15/4 4 ...
              1/2 9/16 5/8];
% 1/4 notes
do0f = mod4.*cos(2*pi*ScaleTable(21)*f0*t4); % ScaleTable(21) = 1/2, f = 146.8, D3 = 147
re0f = mod4.*cos(2*pi*ScaleTable(22)*f0*t4); % ScaleTable(22) = 9/16, f = 165.15, E3 = 165
mi0f = mod4.*cos(2*pi*ScaleTable(23)*f0*t4); % ScaleTable(23) = 5/8, f = 183.5, F#3/Gb3 = 185
fa0f = mod4.*cos(2*pi*ScaleTable(1)*f0*t4);  % ScaleTable(1) = 2/3, f = 195.73, G3 = 196
so0f = mod4.*cos(2*pi*ScaleTable(2)*f0*t4);  % ScaleTable(2) = 3/4, f = 220.2, A3 = 220
la0f = mod4.*cos(2*pi*ScaleTable(3)*f0*t4);  % ScaleTable(3) = 5/6, f = 244.67, B3 = 247
ti0f = mod4.*cos(2*pi*ScaleTable(4)*f0*t4);  % ScaleTable(4) = 15/16, f = 275.25, C#4/Db4 = 277

do1f = mod4.*cos(2*pi*ScaleTable(5)*f0*t4);  % ScaleTable(5) = 1, f = 293.6, D4 = 294
re1f = mod4.*cos(2*pi*ScaleTable(6)*f0*t4);  % ScaleTable(6) = 9/8, f = 330.3, E4 = 330
mi1f = mod4.*cos(2*pi*ScaleTable(7)*f0*t4);  % ScaleTable(7) = 5/4, f = 367, F#4/Gb4 = 370
fa1f = mod4.*cos(2*pi*ScaleTable(8)*f0*t4);  % ScaleTable(8) = 4/3, f = 391.47, G4 = 392
so1f = mod4.*cos(2*pi*ScaleTable(9)*f0*t4);  % ScaleTable(9) = 3/2, f = 440.4, A4 = 440
la1f = mod4.*cos(2*pi*ScaleTable(10)*f0*t4);  % ScaleTable(10) = 5/3, f = 489.33, B4 = 494
tb1f = mod4.*cos(2*pi*ScaleTable(11)*f0*t4);  % ScaleTable(11) = 9/5, f = 528.48, C5 = 523
ti1f = mod4.*cos(2*pi*ScaleTable(12)*f0*t4);  % ScaleTable(12) = 15/8, f = 550.5, C#5/Db5 = 554

do2f = mod4.*cos(2*pi*ScaleTable(13)*f0*t4);  % ScaleTable(13) = 2, f = 587.2, D5 = 587
re2f = mod4.*cos(2*pi*ScaleTable(14)*f0*t4);  % ScaleTable(14) = 9/4, f = 660.6, E3 = 659
mi2f = mod4.*cos(2*pi*ScaleTable(15)*f0*t4);  % ScaleTable(15) = 5/2, f = 734, F#5/Gb5 = 740
fa2f = mod4.*cos(2*pi*ScaleTable(16)*f0*t4);  % ScaleTable(16) = 8/3, f = 782.93, G5 = 784
so2f = mod4.*cos(2*pi*ScaleTable(17)*f0*t4);  % ScaleTable(17) = 3, f = 880.8, A5 = 880
la2f = mod4.*cos(2*pi*ScaleTable(18)*f0*t4);  % ScaleTable(18) = 10/3, f = 978.67, B5 = 988
ti2f = mod4.*cos(2*pi*ScaleTable(19)*f0*t4);  % ScaleTable(19) = 15/4, f = 1101, C#6/Db6 = 1109

do3f = mod4.*cos(2*pi*ScaleTable(20)*f0*t4);  % ScaleTable(20) = 4, f = 1174.4, D6 = 1175
blkf = zeros(1,i); % 一个空白的四分之一音符

% 1/8 notes
% 同上面的四分之一音符，频率变化未更改只是持续之间缩短一半
fa0e = mod8.*cos(2*pi*ScaleTable(1)*f0*t8);
so0e = mod8.*cos(2*pi*ScaleTable(2)*f0*t8);
la0e = mod8.*cos(2*pi*ScaleTable(3)*f0*t8);
ti0e = mod8.*cos(2*pi*ScaleTable(4)*f0*t8);
do1e = mod8.*cos(2*pi*ScaleTable(5)*f0*t8);
re1e = mod8.*cos(2*pi*ScaleTable(6)*f0*t8);
mi1e = mod8.*cos(2*pi*ScaleTable(7)*f0*t8);
fa1e = mod8.*cos(2*pi*ScaleTable(8)*f0*t8);
so1e = mod8.*cos(2*pi*ScaleTable(9)*f0*t8);
la1e = mod8.*cos(2*pi*ScaleTable(10)*f0*t8);
tb1e = mod8.*cos(2*pi*ScaleTable(11)*f0*t8);
ti1e = mod8.*cos(2*pi*ScaleTable(12)*f0*t8);
do2e = mod8.*cos(2*pi*ScaleTable(13)*f0*t8);
re2e = mod8.*cos(2*pi*ScaleTable(14)*f0*t8);
mi2e = mod8.*cos(2*pi*ScaleTable(15)*f0*t8);
fa2e = mod8.*cos(2*pi*ScaleTable(16)*f0*t8);
so2e = mod8.*cos(2*pi*ScaleTable(17)*f0*t8);
la2e = mod8.*cos(2*pi*ScaleTable(18)*f0*t8);
ti2e = mod8.*cos(2*pi*ScaleTable(19)*f0*t8);
do3e = mod8.*cos(2*pi*ScaleTable(20)*f0*t8);
blke = zeros(1,j); % 一个八分之一空白音符

% 1/16 notes
% 同上面的八分之一音符，频率变化未更改只是持续之间缩短一半
fa0s = mod16.*cos(2*pi*ScaleTable(1)*f0*t16);
so0s = mod16.*cos(2*pi*ScaleTable(2)*f0*t16);
la0s = mod16.*cos(2*pi*ScaleTable(3)*f0*t16);
ti0s = mod16.*cos(2*pi*ScaleTable(4)*f0*t16);
do1s = mod16.*cos(2*pi*ScaleTable(5)*f0*t16);
re1s = mod16.*cos(2*pi*ScaleTable(6)*f0*t16);
mi1s = mod16.*cos(2*pi*ScaleTable(7)*f0*t16);
fa1s = mod16.*cos(2*pi*ScaleTable(8)*f0*t16);
so1s = mod16.*cos(2*pi*ScaleTable(9)*f0*t16);
la1s = mod16.*cos(2*pi*ScaleTable(10)*f0*t16);
tb1s = mod16.*cos(2*pi*ScaleTable(11)*f0*t16);
ti1s = mod16.*cos(2*pi*ScaleTable(12)*f0*t16);
do2s = mod16.*cos(2*pi*ScaleTable(13)*f0*t16);
re2s = mod16.*cos(2*pi*ScaleTable(14)*f0*t16);
mi2s = mod16.*cos(2*pi*ScaleTable(15)*f0*t16);
fa2s = mod16.*cos(2*pi*ScaleTable(16)*f0*t16);
so2s = mod16.*cos(2*pi*ScaleTable(17)*f0*t16);
la2s = mod16.*cos(2*pi*ScaleTable(18)*f0*t16);
ti2s = mod16.*cos(2*pi*ScaleTable(19)*f0*t16);
do3s = mod16.*cos(2*pi*ScaleTable(20)*f0*t16);
blks = zeros(1,k);% 一个十六分之一空白音符

% Blank Block
% 由空白的四分之一音符组成的空格
blkblock = [blkf blkf blkf blkf  blkf blkf blkf blkf...
            blkf blkf blkf blkf  blkf blkf blkf blkf];
% sound(blkblock,fs) 

% Base Melodys
% 模拟大提琴提供的基础背景旋律
cello = [do1f do1f so0f so0f  la0f la0f mi0f mi0f...
         fa0f fa0f do0f do0f  fa0f fa0f so0f so0f];
% sound(cello,fs) 
     
% So-FUCKING-Long Melody     
% 模拟小提琴提供的主旋律
violin = [mi2f mi2f re2f re2f  do2f do2f ti1f ti1f...
          la1f la1f so1f so1f  la1f la1f ti1f ti1f ...%
          do2f do2f ti1f ti1f  la1f la1f so1f so1f...
          fa1f fa1f mi1f mi1f  fa1f fa1f re1f re1f ...%
          do1f mi1f so1f fa1f  mi1f do1f mi1f re1f...
          do1f la0f do1f so1f  fa1f la1f so1f fa1f...%
          mi1f do1f re1f ti1f  do2f mi2f so2f so1f...
          la1f fa1f so1f mi1f  do1f do2f blkf blke ti1e ...%
          do2e ti1e do2e do1e  ti0e so1e re1e mi1e...
          do1e do2e ti1e la1e  ti1e mi2e so2e la2e...
          fa2e mi2e re2e fa2e  mi2e re2e do2e ti1e...
          la1e so1e fa1e mi1e  re1e fa1e mi1e re1e... %%
          do1e re1e mi1e fa1e  so1e re1e so1e fa1e...
          mi1e la1e so1e fa1e  so1e fa1e mi1e re1e...
          do1e la0e la1e ti1e  do2e ti1e la1e so1e...
          fa1e mi1e re1e la1e  so1e la1e so1e fa1e...%
          mi1f mi2e blke re2f re2f  blkf do1f mi2f mi2f...
          la2f la2f so2f so2f  la2f la2f ti2f ti2f...%
          do3e blke do2e blke ti1f ti1f  blkf la1f do2f do2f...
          do2f do2f do2f do2f  do2f fa2f re2f so2f...%
          so2e mi2s fa2s so2e mi2s fa2s so2s so1s la1s ti1s ...
          do2s re2s mi2s fa2s mi2e do2s re2s...
          mi2e mi1s fa1s so1s la1s so1s fa1s so1s mi1s fa1s so1s...
          fa1e la1s so1s fa1e mi1s re1s mi1s re1s do1s re1s mi1s fa1s so1s la1s...
          fa2e la1s so1s la1e ti1s do2s so1s la1s ti1s do2s re2s mi2s fa2s so2s...%
          mi2e do2s re2s mi2e re2s do2s re2s ti1s do2s re2s mi2s re2s do2s ti1s...
          do2e la1s ti1s do2e do1s re1s mi1s fa1s mi1s re1s mi1s do2s ti1s do2s...
          la1e do2s ti1s la1e so1s fa1s so1s fa1s mi1s fa1s so1s la1s ti1s do2s...
          la2e do2s ti1s do2e ti1s la1s ti1s do2s re2s do2s ti1s do1s la1s ti1s...%%
          do2e blke blkf ti1e blke blkf la1e blke blkf do2e blke blkf...
          do1e blke blkf do1e blke blkf do1e blke blkf do1e blke blkf...%
          blkf so1e blke blkf so1e blke blkf mi1e blke blkf so1e blke...
          blkf fa1e blke blkf mi1e blke blkf fa1e blke blkf re2e blke...%
          mi2e mi1e fa1e mi1e re1e re2e mi2e re2e do2e mi1e do1e do2e ti1e so0e fa0e so0e...
          la0e la1e so1e la1e so1e so0e fa0e so0e do1e la1e so1e la1e ti1e ti0e la0e ti0e...%
          do1e do2e re2e do2e ti1e ti0e do1e ti0e la0e la1e so1e la1e ti1e ti0e mi1e re1e...
          do1e do2e re2e fa2e mi2e mi1e so1e mi2e do2e fa2e mi2e fa2e re2e so1e fa1e so1e...%
          mi1e so1e so1e so1e so1e so1e so1e so1e mi1e mi1e mi1e mi1e mi1e mi1e so1e so1e...
          fa1e fa1e fa1e do2e do2e do2e do2e do2e do2e do2e la1e la1e so1e so1e re2e ti1e...%%
          so1e mi2e mi2e mi2e re2e re2e re2e re2e do2e do2e do2e do2e so2e so2e so2e so2e...
          la2e la2e la2e la2e so2e so2e so2e so2e la2e la2e la2e la2e ti2e ti1e ti1e ti1e...%
          do2e do1s re1s mi1e do1e ti0e ti1s do2s re2e ti1e la1e la0s ti0s do1e la0e ti0e so1s fa1s mi1e re1e...
          do1e mi1s re1s do1e fa1e mi1e do1s re1s mi1e so1e fa1e la1s so1s fa1e mi1e re1e so1s fa1s mi1e re1e...%
          mi1e do2s ti1s do2e mi1e so1e so1s la1s ti1e so1e mi1e do2s re2s mi2e do2e mi2e mi2s re2s do2e ti1e...
          la1e la1s so1s la1e ti1e do2e mi2s re2s do2e mi2e fa2e do2s ti1s la1e la1e so1e re1e so1e so1e...%
          so1f so1f so1f so1f  do1f do1f do1f so1f...
          fa1f fa1f so1f so1f  fa1f do1f do1f do1e ti0e...%
          do1f do2f ti1f ti1f  la1f la1f so1f so1f...
          do1f do1e re1e mi1f mi1f  do2f do2f ti1f ti1f...%%
          do2f];
% sound(violin,fs)   
% 下面则是重复之前建立好的旋律，并由于需要组合起来
% cello
c1 = [cello cello cello cello cello...
      cello cello cello cello cello...
      cello cello cello cello cello...
      cello cello cello cello cello...
      cello cello cello blkf];
% violin1
v1 = [blkblock violin blkblock blkblock];
% violin2
v2 = [blkblock blkblock violin blkblock];
% violin3
v3 = [blkblock blkblock blkblock violin];


% Get dirty
s = c1+v1+v2+v3;
% 这个地方应该是把音符的音量整体缩小，使得其值在0到1之间
s = s/max(s);
audiowrite('kanon.wav',s,fs);
sound(s,fs);