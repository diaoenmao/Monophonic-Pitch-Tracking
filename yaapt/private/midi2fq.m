function fq = midi2fq(midi)
load('target_freq.mat');
[~,idx] = ismember(midi,FreqData(:,1));
fq=FreqData(idx,2);
end