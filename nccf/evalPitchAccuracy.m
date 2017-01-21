function [totalMatch, pitchMatch, unpitchMatch] = evalPitchAccuracy(extracted, reference)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% [totalMatch, pitchMatch, unpitchMatch] = evalPitchAccuracy(extracted, reference)
% algorithm for the evaluation of melody extractors after option 1
% input:
% extracted - string with path/filename of the extracted melody
% reference - string with path/filename of the reference melody
% Both files are assumed to be ASCII files containing data at the same frame rate.
% Unpitched frames are coded as 0Hz pitch.
% The algorithm assumes that the pitch information in Hz for each frame is stored in the 
% last column of the files.
%
% output:
% pitchMatch - Concordance measure for the pitched frames (in reference) only
% unpitchMatch - Concordance measure for the unpitched frames (in reference) only
% totalMatch - Combined concordance measure
%
% Source: http://ismir2004.ismir.net/melody_contest/results.html
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% disp('-------------------------------------');
% load text files and crop frequency values
mel1 = load(extracted);
[frames1, cols] = size(mel1);
mel1 = mel1(:,cols);
mel2 = load(reference);
[frames2, cols] = size(mel2);
mel2 = mel2(:,cols);
 
% check length of files
if frames1<frames2
%     disp(' Warning! Extracted melody is shorter than the reference!');
%     disp(' Zeros are appended.');
    mel1(frames1+1:frames2)=0;
end
if frames1>frames2
%     disp(' Warning! Extracted melody is longer than the reference!');
%     disp(' Melody is truncated.');
    mel1(frames2+1:frames1)=[];
end
 
%%% compute unpitchMatch
%%% (frames have no pitch in the reference, but have one in the extracted melody)
 
unpitched = mel2==0;
nopitchdet = mel1==0;
unpitchMatch = 100*sum(nopitchdet(unpitched))/sum(unpitched);
% disp([' unpitched frame accordance:  ',num2str(unpitchMatch),'%']);
 
%%% compute absolute errors on log frequency scale
% scale conversion for pitched frames
mel1(~nopitchdet) = 1200*(log2(mel1(~nopitchdet)/13.75)-0.25);
mel2(~unpitched) = 1200*(log2(mel2(~unpitched)/13.75)-0.25);
errCent = abs(mel1-mel2);
 
% 1 semitone is error threshold
errCent(errCent>100) = 100;
 
% compute pitchMatch
pitchMatch = 100 - mean(errCent(~unpitched));
% disp([' pitched frame accordance:  ',num2str(pitchMatch),'%']);
 
% compute totalMatch
totalMatch = 100 - mean(errCent);
% disp(['     TOTAL ACCORDANCE:  ',num2str(totalMatch),'%']);
% disp('-------------------------------------');
 
%%% plot melody lines
% figure;
% plot(mel2,'ob');
% hold on
% plot(mel1,'xr');