function result = melExEval(refFile,extFile,varargin)
% Tool to compare the F0 estimates from two sources. The inputs to the function are the 
% paths+filename for the target and the reference text files.
% 
% Usage -
%         result = melExEval(refFile,extFile)
%             refFile - Path + Filename for the reference F0 file in which the first column contains timestamps and second column F0 values.
%             extFile - Path + Filename for the extracted F0 file.
%             result - (1 by 6) array containing 1. Overall Pitch Accuracy, 2. Overall Chroma Accuracy, 3. Raw Pitch Accuracy,
%                                                4. Raw Chroma Accuracy, 5. Voicing Recall, 6. Voicing False Alarm 
%                                                
%         result = melExEval (___,Name,Value)
%             Name - Value pairs are
%             1.  'Delimiter' - accepts a sting input containing the delimiter separating the columns for the input files (Default: ' '<space>)
%             2.  'Tolerance' - accepts a positive numeric value which is the maximum allowable deviation from reference pitch in cents
%                               for the result to be deemed correct. (Default: 50)
%             3.  'OutputType' - accepts a string containing either 'array','cell' or 'struct'. Changes the class of the output to
%                                match the type specified. (Default: 'array')
% Example 
% x = melExEval('Reference.txt','MyRAPT.txt','Delimiter','\t','OutputType','struct');
% Copyright (c) 2015, Udit Gupta
% All rights reserved.
 
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are
% met:
% 
%     * Redistributions of source code must retain the above copyright
%       notice, this list of conditions and the following disclaimer.
%     * Redistributions in binary form must reproduce the above copyright
%       notice, this list of conditions and the following disclaimer in
%       the documentation and/or other materials provided with the distribution
% 
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.


% Validating and Parsing Inputs
P=inputParser;
addRequired(P,'refFile',@(x)exist(x,'file'));
addRequired(P,'extFile',@(x)exist(x,'file'));
addParameter(P,'delimiter',' ',@ischar);
addParameter(P,'tolerance',50,@(x)(isnumeric(x) && length(x)==1 && x>=0));
addParameter(P,'outputType','array',@(x)(ischar(x) && any(strcmpi(x,{'array','cell','struct'}))));
parse(P,refFile,extFile,varargin{:});
for param=P.Parameters
    eval([char(param),'=P.Results.',char(param),';']);
end

% Reading Files
reference = dlmread(refFile,delimiter);
extracted = dlmread(extFile,delimiter);
% TODO: Add Error Check
melRef = reference(:,2);
melExt = interp1(extracted(:,1),extracted(:,2),reference(:,1),'nearest','extrap'); % Finding nearest pitch in case of frame mismatch
pitchedRef = melRef~=0;
pitchedExt = melExt~=0;

% Conversion to Cents
dif = log2(13.75)+0.25;
f2c = @(X)  1200*(log2(abs(X))-dif);  %1200*(log2(X/13.75)-0.25)
melRef(pitchedRef)=f2c(melRef(pitchedRef)).*sign(melRef(pitchedRef));
melExt(pitchedExt)=f2c(melExt(pitchedExt)).*sign(melExt(pitchedExt));

% Calculating Results
result=cell(1,6); %1. Ovl Pitch Acc, 2. Ovl Chroma Acc, 3. Raw Pitch Acc, 4. Raw Chroma Acc, 5. Voc Recall, 6. Voc False Alarm 
GU = melRef<=0;
GV = ~GU;
TP = melExt>0 & GV;
FP = melExt>0 & GU;
TN = melExt<=0 & GU;
FN = melExt<=0 & GV;

% Calculating Recall and False Alarm
result{5} = sum(TP)/sum(GV);
result{6} = sum(FP)/sum(GU);

% Calculating Pitch Accuracies
TPC = TP & abs(melRef-melExt)<=tolerance;
FNC = FN & abs(abs(melRef)-abs(melExt))<=tolerance;
result{3} = sum(TPC|FNC)/sum(GV);
result{1} = sum(TPC|TN)/length(melRef);

% Calculating Chroma Accuracies
melExt(pitchedExt) = 100 + mod(abs(melExt(pitchedExt)),1200);
melRef(pitchedRef) = 100 + mod(abs(melRef(pitchedRef)),1200);
diff = abs(melRef-melExt);
swap = (diff>600) & pitchedExt & pitchedRef;
diff(swap) = 1200 - diff(swap);
TPC = TP & diff<=tolerance;
FNC = FN & diff<=tolerance;
result{4} = sum(TPC|FNC)/sum(GV);
result{2} = sum(TPC|TN)/length(melRef);

outputType=lower(outputType);
switch outputType
    case 'array'
        result = cell2mat(result);
    case 'struct'
        result = cell2struct(result,{'ovlPitch','ovlChroma','rawPitch','rawChroma','vocRecall','vocFalse'},2);
end

