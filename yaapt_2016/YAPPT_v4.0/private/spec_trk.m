function[SPitch, VUVSPitch, pAvg, pStd]= spec_trk(Data, Fs, VUVEnergy, Prm)
%SPEC_TRK  Spectral pitch tracking for YAAPT pitch tracking
%
%   [SPitch, VUVSPitch, pAvg, pStd]=spec_trk(Data, Fs, VUVEnergy, Prm) 
%   computes estimates of pitch  using nonlinearly processed
%   speech (typically square or absolute value) and frequency domain processing
%   Search for frequencies which have energy at multiplies of that frequency
%
%INPUTS:
%   Data:      Nonlinearly processed signal, filtered with F1. (~50 to 1500Hz)
%   Fs:        The sampling frequency.
%   VUVEnergy: Voiced/ unvoiced decision, depending on nlfer
%   Prm:       Parameters
%
%OUTPUTS:
%   SPitch:    The spectral Pitch track, with the unvoiced regions filled using interpolation.
%   VUVSPitch: The spectral Pitch track, with  unvoiced regions set at zero
%   pAvg:      The average of the Pitch track value.
%   pStd:      The standard deviation in the track.

%   Creation date:  Feb 20, 2006
%   Revision dates: Feb 22, 2006,  March 11, 2006, April 5, 2006,
%                   Jun 25, 2006,  June 13, 2007
%   Programers:     Hongbing Hu, Princy, Zahorian

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     This file is a part of the YAAPT program, designed for a fundamental 
%   frequency tracking algorithm that is extermely robust for both high quality 
%   and telephone speech.  
%     The YAAPT program was created by the Speech Communication Laboratory of
%   the state university of New York at Binghamton. The program is available 
%   at http://www.ws.binghamton.edu/zahorian as free software. Further 
%   information about the program could be found at "A spectral/temporal 
%   method for robust fundamental frequency tracking," J.Acosut.Soc.Am. 123(6), 
%   June 2008.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%-- PARAMETERS: set up all of these parameters --------------------------------
nframesize = fix(Prm.frame_length*Fs/1000);


nframejump = fix(Prm.frame_space*Fs/1000);
noverlap= nframesize-nframejump;         % overlap width in sample 
numframes = fix((length(Data)-noverlap)/nframejump);
nframesize = nframesize*2;

% Max number of peak candidates found
maxpeaks = Prm.shc_maxpeaks;
nfftlength = Prm.fft_length;                       % FFT length
% Resolution of spectrum
delta         = Fs/nfftlength;               
% Window width in sample
window_length = fix(Prm.shc_window/delta);
if (mod(window_length,2)==0)
    window_length = window_length + 1;
end
% Half window width
half_winlen   = fix(Prm.shc_window/(delta*2)); 
% Max range of SHC 
max_SHC   = fix((Prm.f0_max+Prm.shc_pwidth*2)/delta);
% Min range of SHC 
min_SHC   = ceil(Prm.f0_min/delta);       
% Number of harmomics considered
numharmonics = Prm.shc_numharms;


%-- INITIALIZATION -----------------------------------------------------------
CandsPitch = zeros(maxpeaks, numframes);
CandsMerit = ones(maxpeaks, numframes);
% Zero padding
Data(end:(numframes-1)*nframejump+nframesize) = 0;

%-- MAIN ROUTINE --------------------------------------------------------------
% Compute SHC for voiced frame
Kaiser_window = kaiser(nframesize);
SHC = zeros(1,max_SHC);

winix = repmat([1:window_length], numharmonics+1,1);
rowix = repmat([1:numharmonics+1]', 1, window_length);
Magnit1_len = fix((numharmonics+2)*Prm.f0_max/delta)+window_length;
for frame = 1:numframes
    if (VUVEnergy(frame) > 0)
        firstp = 1+(frame-1)*(nframejump);
        Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window;
        Signal = Signal - mean(Signal);
        Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))];
        Magnit1 = Magnit(1:Magnit1_len);
        Magnit1 = Magnit1/max(Magnit1);
        
        % Compute SHC (Spectral Harmonic Correlation)
        for k=min_SHC:max_SHC;
            SHC(k) = sum(prod(Magnit1( winix + k*rowix )));
        end
      
        a = max(SHC);
%         display(a);
%         pause
        
        if a>1 
            SHC = SHC/a;
        end
        
        [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm);
    else 
        % if energy is low,  let frame be considered as unvoiced
        CandsPitch(:,frame) = zeros(1,maxpeaks);
        CandsMerit(:,frame) = ones(1, maxpeaks);
    end
end


% display('Running new code');

% for frame = 1:numframes
%     if (VUVEnergy(frame) > 0)
%         firstp = 1+(frame-1)*(nframejump);
%         Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window;
%         Signal = Signal - mean(Signal);
%         Magnit = abs(fft(Signal , nfftlength));
%         
%         % Compute SHC (Spectral Harmonic Correlation)
%         for k=min_SHC:max_SHC;
%             MultHarms = ones(1, window_length);
% 
%             % Set each harmonics, 1=f0 2=2*f0 etc
%             for n=1:numharmonics+1  % Number of harmomics considered
%                 nstart = n*k-half_winlen;
%                 if nstart < 0
%                     Harm =  zeros(1, window_length);
%                     Harm(abs(nstart)+1:window_length)=Magnit(1:nstart+window_length);
%                 else
%                     Harm(1:window_length)=Magnit(nstart+1:nstart+window_length);
%                 end
%                 MultHarms = MultHarms .* Harm;
%             end
%             SHC(k) = sum(MultHarms);
%         end
%         [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm);
%     else 
%         % if energy is low,  let frame be considered as unvoiced
%         CandsPitch(:,frame) = zeros(1,maxpeaks);
%         CandsMerit(:,frame) = ones(1, maxpeaks);
%     end
% end

% Extract the Pitch candidates of voiced frames for the future Pitch selection 
SPitch = CandsPitch(1,:);
Idx_voiced = SPitch > 0; 
VCandsPitch  = CandsPitch(:,Idx_voiced);
VCandsMerit = CandsMerit(:,Idx_voiced);
Num_VCands = sum(Idx_voiced);

% Average, STD of the first choice candidates
avg_voiced = mean(VCandsPitch(1,:));
std_voiced = std(VCandsPitch(1,:));

% Weight the deltas, so that higher merit candidates are considered
% more favorably
delta1 = abs((VCandsPitch - 0.8*avg_voiced)).*(3-VCandsMerit);

% Interpolation of the weigthed candidates
[VR, Idx] = min(delta1); 
VPeak_minmrt  = zeros(1, length(Idx));
VMerit_minmrt = zeros(1, length(Idx));
for n=1: length(Idx)
    VPeak_minmrt(n)  = VCandsPitch(Idx(n), n);
    VMerit_minmrt(n) = VCandsMerit(Idx(n), n); 
end
VPeak_minmrt = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2));
% Replace the lowest merit candidates by the median smoothed ones
% computed from highest merit peaks above
for n=1: length(Idx)
    VCandsPitch(Idx(n), n) = VPeak_minmrt(n);
    % Assign merit for the smoothed peaks
    VCandsMerit(Idx(n), n) = VMerit_minmrt(n);
end

% Use dynamic programming to find best overal path among pitch candidates
% Dynamic weight for transition costs
% balance between local and transition costs
weight_trans = Prm.dp5_k1*std_voiced/avg_voiced;

if (Num_VCands >2) 
  [VPitch] = dynamic5(VCandsPitch, VCandsMerit,weight_trans);
   VPitch = medfilt1(VPitch, max(Prm.median_value-2, 1));
    
else
     
    if (Num_VCands > 0) 
      for i = 1:Num_VCands   % assume at least 1 voiced candidate
       VPitch (i) = 150;   %   Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates
      end; 
                %   This should only occur for very short pitch tracks, and even then rarely
    else
        VPitch(1) = 150;    % to handle when no real voiced candidates
        Idx_voiced(1) = 1;
    end;
    
end;       


% Computing some statistics from the voiced frames
pAvg = mean(VPitch);
pStd = std(VPitch);

% Streching out the smoothed pitch track
SPitch(Idx_voiced) = VPitch;

% Interpolating thru unvoiced frames
if (SPitch(1) < pAvg/2) SPitch(1)   = pAvg;   end;
if (SPitch(end) <pAvg/2) SPitch(end) = pAvg;  end;

[Indrows, Indcols, Vals] = find(SPitch);
SPitch = interp1(Indcols, Vals, [1:numframes], 'pchip');

FILTER_ORDER = 3;
flt_b = (ones(1,FILTER_ORDER))/FILTER_ORDER ;
flt_a = 1;

SPitch = filter(flt_b, flt_a, SPitch);


%  above messes up  first few values of SPitch  ---  simple fix up
%  Note--   this fix up should be based on above filter order

SPitch(1) = SPitch(3);
SPitch(2) = SPitch (4);

% Create pitch track with Voiced/Unvoiced decision
VUVSPitch = SPitch;
VUVSPitch(VUVEnergy==0) = 0;

% SPitch = SPitch - delta;
