reference_filename2 = './Sample/BrandonWebster_YesSirICanFly_STEM_02.csv';
wave_filename2 = './Sample/BrandonWebster_YesSirICanFly_CLV.wav';
[raw_time,F0] = importfile(reference_filename);
[y,fs]=audioread(wave_filename);
time = 0:0.01:length(y)/fs;
F0_reference = interp1(raw_time,F0,time,'nearest');
F0_reference(isnan(F0_reference)) = 0;

%% YAAPT
tic
yd = downsample(y,4);
Pitch = yaapt(yd,fs/4,1,[]);
time_yaapt = 0:0.01:length(Pitch)*0.01-0.01;
F0_yaapt = interp1(time_yaapt,Pitch,time,'nearest');
F0_yaapt(isnan(F0_yaapt)) = 0;
toc

%% RAPT
tic
fx = fxrapt(y,fs,'u');
fx(isnan(fx)) = 0;
time_rapt = 0:0.01:length(fx)*0.01-0.01;
F0_rapt = interp1(time_rapt,fx,time,'nearest');
F0_rapt(isnan(F0_rapt)) = 0;
toc

%% MyRAPT
tic
[F0,~] = myrapt(y,fs);
time_myrapt = 0:0.01:length(F0)*0.01-0.01;
F0_myrapt = interp1(time_myrapt,F0,time,'nearest');
F0_myrapt(isnan(F0_myrapt)) = 0;
toc

%% File output
Reference = [time;F0_reference];
YAAPT = [time; F0_yaapt];
RAPT = [time; F0_rapt];
MyRAPT = [time; F0_myrapt];

fileID = fopen('Reference.txt','w');
fprintf(fileID,'%6s %12s\n','time','F0');
fprintf(fileID,'%6.2f %12.8f\n',Reference);
fclose(fileID);

fileID = fopen('YAAPT.txt','w');
fprintf(fileID,'%6s %12s\n','time','F0');
fprintf(fileID,'%6.2f %12.8f\n',YAAPT);
fclose(fileID);

fileID = fopen('RAPT.txt','w');
fprintf(fileID,'%6s %12s\n','time','F0');
fprintf(fileID,'%6.2f %12.8f\n',RAPT);
fclose(fileID);

fileID = fopen('MyRAPT.txt','w');
fprintf(fileID,'%6s %12s\n','time','F0');
fprintf(fileID,'%6.2f %12.8f\n',MyRAPT);
fclose(fileID);
