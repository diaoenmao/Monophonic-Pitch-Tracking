function []= pt_figs(DataB, DataD, Fs, SPitch, Energy, VUVEnergy, ...
                      Pitch, FinPitch, Prm)

% PT_FIGUS Plot the figures about Pitch tracking
%   The function is to illustrate the pitch tracking processing.

lenData = length(DataB); 

fft_length = Prm.fft_length;
frame_size = Prm.frame_length*Fs/1000;    
frame_jump = Prm.frame_space*Fs/1000; 
startt = 1/Fs;
finalt = lenData/Fs;
startf     =  0;                  % starting frequency for spectral plots
finalf     =  Prm.f0_max;  % Ending frequency  for spectral plots


%== FIGURE 1 ==================================================================
%the plot containing the time domain acoustic signal.

figure(1);
tt_spec     =  linspace(startt, finalt, lenData); % X axis

subplot(2,1,1);
plot(tt_spec, DataB);
axis([startt, finalt, -max(DataB), max(DataB)]);
title('The filtered original speech signal');
xlabel('Time (Seconds)');
ylabel('Amplitude');

subplot(2,1,2);
plot(tt_spec, DataD);
axis([startt, finalt, -max(DataD), max(DataD)]);
title('The nonlinear processed speech signal');
xlabel('Time (Seconds)');
ylabel('Amplitude');

                         
%== FIGURE 2 ==================================================================
% the plotting of spectral pitch track on the spectrum

figure(2);
eps  = .00000000000000001;

N_startf = round((startf/Fs) * fft_length+1);
N_finalf = round((finalf/Fs) * fft_length+1); % add +1 6/3/13

% Hongbing: use 2*fft_length? since 2*frame_size is used in spec3_f0()
Spec_mag = abs(specgram(DataB,fft_length,Fs,frame_size,frame_size-frame_jump));
Spec_log = log(Spec_mag + eps);
Spec_log = Spec_log(N_startf:N_finalf,:);


Spec_mag1 = abs(specgram(DataD,fft_length,Fs,frame_size,frame_size-frame_jump));
Spec_log1 = log(Spec_mag1 + eps);
Spec_log1 = Spec_log1(N_startf:N_finalf,:);


[nrow,ncol] =  size(Spec_log);
tt_spec     =  linspace(startt, finalt, ncol); % X axis
ff_spec     =  linspace(startf, finalf, nrow);  % Y axis

subplot(2,1,1);
imagesc(tt_spec,ff_spec,Spec_log);
colormap(jet);
axis([startt finalt startf finalf]);
axis xy;
hold on;
plot(tt_spec, SPitch, '.k');
plot(tt_spec, Energy*(finalf/2), 'b');  
legend('Spectral pitch track', 'Energy');
title('Spectral pitch track and energy overlaid on spectrogram (original)');
xlabel('Time (Seconds)');
ylabel('Frequency (Hz)');
hold off;


subplot(2,1,2);
imagesc(tt_spec,ff_spec,Spec_log1);
colormap(jet);
axis([startt finalt startf finalf]);
axis xy;
hold on;
plot(tt_spec, SPitch, '.k');
plot(tt_spec, Energy*(finalf/2), 'b');  
legend('Spectral pitch track', 'Energy');
title('Spectral pitch track and energy overlaid on spectrogram (nonlinear)');
xlabel('Time (Seconds)');
ylabel('Frequency (Hz)');
hold off;


%== FIGURE 3 ==================================================================
% plotting the multiple candidates got after certain modifications based 
% on the energy ratio of the low frequency regions of the spectrogram.

figure(3)
col=char('.b','.r','.g','.k','.m', '.c');                         
[num_cand, numfrm] = size(Pitch); 

subplot(1,1,1);
plot(FinPitch,'k');
hold on;
%for i = num_cand:-1:1
for i = 6:-1:1
    plot(Pitch(i,:), col(i,:));
end;
plot(SPitch, 'r');
if isfield(Prm, 'Pitch_ref')
    plot(Prm.Pitch_ref,'g'); 
end
%plot(Pitch_best,'y--');
%legend('Final pitch', 'Pitch cand. 3', 'Pitch cand. 2', 'Pitch cand. 1'); 
legend('Final pitch','Cand 6','Cand 5','Cand 4','Cand 3','Cand 2','Cand 1'); 
axis([1 numfrm startf finalf]);
title('Sorted pitch candidates');
xlabel('Number of frames');
ylabel('Frequency (Hz)');
hold off;



%== FIGURE 4 ==================================================================
% plotting the final pitch, voiced/unvoiced and spectrum

figure(4)
if isfield(Prm, 'Pitch_ref')
    minlen = min(length(tt_spec), length(Prm.Pitch_ref));
else 
    minlen = length(tt_spec);
end
subplot(2,1,1);
imagesc(tt_spec,ff_spec,Spec_log);
colormap(jet);
axis([startt finalt startf finalf]);
axis xy;
hold on;
plot(tt_spec, FinPitch,'.k');
plot(tt_spec, VUVEnergy*(finalf/3), 'b');  
if isfield(Prm, 'Pitch_ref')
    plot(tt_spec(1:minlen), Prm.Pitch_ref(1:minlen),'sb');
    legend('Final pitch', 'Voiced/Unvoiced', 'Reference pitch');
else
    legend('Final pitch', 'Voiced/Unvoiced');
end
hold off;
title('Final pitch track overlaid on spectrogram (original)');
xlabel('Time (Seconds)');
ylabel('Frequency (Hz)');


subplot(2,1,2);
imagesc(tt_spec,ff_spec,Spec_log1);
colormap(jet);
axis([startt finalt startf finalf]);
axis xy;
hold on;
plot(tt_spec, FinPitch,'.k');
plot(tt_spec, VUVEnergy*(finalf/3), 'b');  
if isfield(Prm, 'Pitch_ref')
    plot(tt_spec(1:minlen), Prm.Pitch_ref(1:minlen),'sb');
    legend('Final pitch', 'Voiced/Unvoiced', 'Reference pitch');
else
    legend('Final pitch', 'Voiced/Unvoiced');
end
hold off;
title('Final pitch track overlaid on spectrogram (nonlinear)');
xlabel('Time (Seconds)');
ylabel('Frequency (Hz)');


%==============================================================================
pause;



