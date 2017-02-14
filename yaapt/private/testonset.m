close all
%% Data set up
load('target_freq.mat')
load('bin_freq.mat')
load('bin_cnt.mat')
target_freq = FreqData(:,2);


% Fs = 44100;
% recObj = audiorecorder(Fs, 16, 1);
% disp('Start speaking.')
% recordblocking(recObj, 3);
% disp('End of Recording.');
% Data = getaudiodata(recObj);
% audiowrite('sample/record.wav',Data,Fs)
[Data, Fs] = audioread ('sample/a a a a.wav');
time=linspace(0,length(Data)/Fs,length(Data));

%% Bandpass filter
% bp_low = 20;
% bp_high = 4410;
% Filter_order = 150;
% w1  = (bp_low / (Fs/2));
% w2  = (bp_high / (Fs/2));
% w   = [w1 w2];
% bandpass = Myfir1(Filter_order,w);
% Data = filter(bandpass,1,Data);

%% Decimation
% max_Fs = 8820;
% fft_length = 8192*4;
% noverlap = floor(fft_length/2);
% if(Fs>max_Fs)
%     dec_fac = Fs/max_Fs;
%     dec_Fs = Fs/dec_fac;
%     rate = rats(dec_fac);
%     indx_slash = find(rate=='/', 1);
%     if(~isempty(indx_slash))
%       Q = str2double(rate(1:indx_slash-1));
%       P = str2double(rate(indx_slash+1:end));
%       dec_data = resample(Data,P,Q);
%     else
%         dec_data = decimate(Data,dec_fac);
%     end
% else
%     dec_data = Data;
%     dec_Fs = Fs;
% end
% player = audioplayer(dec_data,dec_Fs);
% play(player);
dec_data = Data;
dec_Fs = Fs;

%% audio play and plot
player = audioplayer(dec_data,dec_Fs);
play(player);
dec_time=linspace(0,length(dec_data)/dec_Fs,length(dec_data));
figure
plot(dec_time,dec_data)

%% Analysis set up

time_frame_length = 10;
time_frame_overlap = 5;
time_frame_jump = time_frame_length - time_frame_overlap;
time_n_frame_length = fix(time_frame_length*dec_Fs/1000);
time_n_frame_overlap = fix(time_frame_overlap*dec_Fs/1000);
time_n_frame_jump = time_n_frame_length-time_n_frame_overlap;
time_numframes = fix((length(dec_data)-time_n_frame_overlap)/(time_n_frame_jump));
time_background_ref = 50;
time_background_frame_idx  = fix(time_background_ref/time_frame_jump);

frq_frame_length = 10;
frq_frame_overlap = 5;
frq_frame_jump = frq_frame_length - frq_frame_overlap;
frq_n_frame_length = fix(frq_frame_length*dec_Fs/1000);
frq_n_frame_overlap = fix(frq_frame_overlap*dec_Fs/1000);
frq_n_frame_jump = frq_n_frame_length-frq_n_frame_overlap;
frq_numframes = fix((length(dec_data)-frq_n_frame_overlap)/(frq_n_frame_jump));
frq_background_ref = 50;
frq_background_frame_idx  = fix(frq_background_ref/frq_frame_jump);

Voiced = zeros(time_numframes,1);




%% Time Domain
% tic
% time_window = kaiser(time_n_frame_length);
% time_Energy_0 = zeros(time_numframes,1);
% time_Energy = zeros(time_numframes,1);
% time_Attack = zeros(time_numframes,1);
% tframes = linspace(0,length(dec_data)/dec_Fs,time_numframes)';
% for i = 1:time_numframes
%     firstep = 1+(i-1)*(time_n_frame_jump);
%     current_frame = Data(firstep:firstep+time_n_frame_length-1);
%     time_Energy(i) = 1/time_n_frame_length*sum(current_frame.^2.*time_window);
%     time_Attack(i) = max(abs(current_frame).*time_window);
% end
% time_background_Energy = mean(time_Energy(1:time_background_frame_idx));
% time_Energy_L2_logdiff = [0;(diff(log(time_Energy)))];
% toc
% figure
% plot(tframes,time_Energy)
% figure
% plot(tframes,time_Energy_L2_logdiff)
% figure
% plot(tframes,time_Attack)
%




% time_threshold=5;
% Voiced(time_Energy/time_background_Energy>time_threshold)=1;
% figure
% plot(tframes,Voiced)

%% Frequency Domain
tic
fft_length = 8192;
res_window = kaiser(frq_n_frame_length);
[s,f,t] = spectrogram(dec_data,res_window,frq_n_frame_overlap,fft_length,dec_Fs,'yaxis');
toc
s = s(2:end,:); % No DC
frq_Energy = sum(abs(s).^2);
frq_Energy_HFC = [1:size(s)]*abs(s).^2;
frq_Energy(frq_Energy==0)=1;
frq_Spectral_Difference = [0 sum(abs(diff(abs(s),1,2)))];
frq_Spectral_Difference_Detection = frq_Spectral_Difference./[1 frq_Energy(1:end-1)];
frqframes = linspace(0,length(dec_data)/dec_Fs,frq_numframes)';
frq_background_Energy = mean(frq_Energy(1:frq_background_frame_idx));


% figure
% plot(frqframes,frq_Energy)
% figure
% plot(frqframes,frq_Energy_HFC)
% figure
% plot(frqframes,frq_Spectral_Difference)
% figure
% plot(frqframes,frq_Spectral_Difference_Detection)
% figure
% mag = abs(s);
% him = imagesc(t,f,mag);
% axis xy
% colormap(1-gray)

% peakpick_can =frq_Energy_HFC;
% peakpick_can= (peakpick_can-mean(peakpick_can))/std(peakpick_can);
% w=3;m=3;
% frq_threshold=0.005;
% for i=1:frq_numframes
% %     k=1+(i-1)*(w);
%     window1_idx = max(1,i-w);
%     window2_idx = max(1,i-m*w);
%     window1 = peakpick_can(window1_idx:i);
%     [~,tmp]=max(window1);
%     mask1(i) = tmp==length(window1);
%     window2=peakpick_can(window2_idx:i);
%     mask2(i) = peakpick_can(i)>(mean(window2)+frq_threshold);
%       
% end
% figure
% plot(mask1)
% figure
% plot(mask2)
% Voiced=mask1&mask2;



frq_threshold=100;
Voiced((frq_Energy/frq_background_Energy)>frq_threshold)=1;
figure
plot(frqframes,Voiced)



