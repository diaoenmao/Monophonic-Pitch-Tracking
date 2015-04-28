function [Reference, YAAPT, RAPT, MyRAPT] = Test (reference_filename,wave_filename,Sample_path,Output_path)
reference = strcat(Sample_path,reference_filename);
wave = strcat(Sample_path,wave_filename);
output_reference = strcat(Output_path,'Reference.txt');
output_yaapt = strcat(Output_path,'YAAPT.txt');
output_rapt = strcat(Output_path,'RAPT.txt');
output_myrapt = strcat(Output_path,'MyRAPT.txt');
[raw_time,F0_reference] = importfile(reference);
[y,fs]=audioread(wave);

%% YAAPT
tic
yd = downsample(y,4);
Pitch = yaapt(yd,fs/4,1,[]);
time_yaapt = 0:0.01:length(Pitch)*0.01-0.01;
F0_yaapt = interp1(time_yaapt,Pitch,raw_time,'nearest');
F0_yaapt(isnan(F0_yaapt)) = 0;
toc

%% RAPT
tic
fx = fxrapt(y,fs,'u');
fx(isnan(fx)) = 0;
time_rapt = 0:0.01:length(fx)*0.01-0.01;
F0_rapt = interp1(time_rapt,fx,raw_time,'nearest');
F0_rapt(isnan(F0_rapt)) = 0;
toc

%% MyRAPT
tic
[F0,~] = myrapt(y,fs);
time_myrapt = 0:0.01:length(F0)*0.01-0.01;
F0_myrapt = interp1(time_myrapt,F0,raw_time,'nearest');
F0_myrapt(isnan(F0_myrapt)) = 0;
toc

%% File output
Reference = [raw_time'; F0_reference'];
YAAPT = [raw_time'; F0_yaapt'];
RAPT = [raw_time'; F0_rapt'];
MyRAPT = [raw_time'; F0_myrapt'];

fileID = fopen(output_reference,'w+');
fprintf(fileID,'%6.4f %12.8f\n',Reference);
fclose(fileID);

fileID = fopen(output_yaapt,'w+');
fprintf(fileID,'%6.4f %12.8f\n',YAAPT);
fclose(fileID);

fileID = fopen(output_rapt,'w+');
fprintf(fileID,'%6.4f %12.8f\n',RAPT);
fclose(fileID);

fileID = fopen(output_myrapt,'w+');
fprintf(fileID,'%6.4f %12.8f\n',MyRAPT);
fclose(fileID);
end
