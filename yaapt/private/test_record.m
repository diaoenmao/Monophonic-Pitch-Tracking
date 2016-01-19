Fs = 22050;
% Record your voice for 5 seconds.
recObj = audiorecorder(22050, 16, 1);
disp('Start speaking.')
recordblocking(recObj, 10);
disp('End of Recording.');

% Play back the recording.
play(recObj);

% Store data in double-precision array.
myRecording = getaudiodata(recObj);

[Pitch, nf] = yaapt(myRecording', Fs); 
subplot(2,1,1)
plot(myRecording)
subplot(2,1,2)
plot(Pitch)