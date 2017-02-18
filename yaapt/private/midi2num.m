function num = midi2num(midi)
convention = 1;%0 starts from octave -1
num = zeros(length(midi),2);
num(:,1) = mod((midi),12)+1;
num(:,2) = floor((midi)./12)-convention;
end