function[Pitch, numfrms, frmrate] = yaapt(Data, Fs, Parameter)

% YAAPT Fundamental Frequency (Pitch) tracking
%
% [Pitch, numfrms, frmrate] = yaapt(Data, Fs, VU, ExtrPrm, fig)
%   , the function is to check input parameters and invoke a number of associated routines 
%   for the YAAPT pitch tracking.
%
% INPUTS: 
%   Data:       Input speech raw data
%   Fs:         Sampling rate of the input data
%   VU:         Whether to use voiced/unvoiced decision with 1 for True and 0 for 
%               False.The default is 1.
%   ExtrPrm:    Extra parameters in a struct type for performance control.
%               See available parameters defined in yaapt.m 
%               e.g., 
%               ExtrPrm.f0_min = 60;         % Change minimum search F0 to 60Hz 
%               ExtrmPrm.fft_length = 8192;  % Change FFT length to 8192
%   fig:        Whether to plot pitch tracks, spectrum, engergy, etc. The parameter
%               is 1 for True and 0 for False. The default is 0.   
%
% OUTPUTS:
%   Pitch:      Final pitch track in Hz. Unvoiced frames are assigned to 0s.
%   numfrms:    Total number of calculated frames, or the length of
%               output pitch track
%   frmrate:    Frame rate of output pitch track in ms

%  Creation Date:  June 2000
%  Revision date:  Jan 2, 2002 , Jan 13, 2002 Feb 19, 2002, Mar 3, 2002
%                  June 11, 2002, Jun 30, 2006, July 27, 2007
%                  May 20, 2012: Add the VU parameter for whether to use
%                  voiced/unvoiced decision. 
%  Authors:        Hongbing Hu, Stephen A.Zahorian

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     This file is a part of the YAAPT program, designed for a fundamental 
%   frequency tracking algorithm that is extermely robust for both high quality 
%   and telephone speech.  
%     The YAAPT program was created by the Speech Communication Laboratory of
%   the state university of New York at Binghamton. The program is available 
%   at http://www.ws.binghamton.edu/zahorian as free software. Further 
%   information about the program can be found at "A spectral/temporal 
%   method for robust fundamental frequency tracking," J.Acosut.Soc.Am. 123(6), 
%   June 2008.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%-- PARAMETERS ----------------------------------------------------------------
% Preliminary input arguments check
if nargin<2
    error('No enough input arguments');
end

% Default values for the tracking with voiced/unvoiced decision
Prm = struct(...
    'frame_length',   Parameter(1), ... % Length of each analysis frame (ms)
    'frame_space',    Parameter(2), ... % Spacing between analysis frame (ms)
    'f0_min',         Parameter(3), ... % Minimum F0 searched (Hz)
    'f0_max',        Parameter(4), ... % Maximum F0 searached (Hz)
    'fft_length',   Parameter(5), ... % FFT length
    'bp_forder',     Parameter(6), ... % Order of bandpass filter (even)
    'bp_low',         Parameter(7), ... % Low frequency of filter passband (Hz)
    'bp_high',      Parameter(8), ... % High frequency of filter passband (Hz)
    'nlfer_thresh1',Parameter(9), ... % NLFER boundary for voiced/unvoiced decisions
    'nlfer_thresh2', Parameter(10), ... % Threshold for NLFER definitely unvocied
    'shc_numharms',    Parameter(11), ... % Number of harmonics in SHC calculation
    'shc_window',     Parameter(12), ... % SHC window length (Hz)
    'shc_maxpeaks',    Parameter(13), ... % Maximum number of SHC peaks to be found
    'shc_pwidth',     Parameter(14), ... % Window width in SHC peak picking (Hz)
    'shc_thresh1',   Parameter(15), ... % Threshold 1 for SHC peak picking
    'shc_thresh2',  Parameter(16), ... % Threshold 2 for SHC peak picking
    'f0_double',     Parameter(17), ... % F0 doubling decision threshold (Hz)
    'f0_half',       Parameter(18), ... % F0 halving decision threshold (Hz)
    'dp5_k1',         Parameter(19), ... % Weight used in dynaimc program
    'dec_factor',      Parameter(20), ... % Factor for signal resampling
    'nccf_thresh1', Parameter(21), ... % Threshold for considering a peak in NCCF
    'nccf_thresh2',  Parameter(22), ... % Threshold for terminating serach in NCCF
    'nccf_maxcands',   Parameter(23), ... % Maximum number of candidates found
    'nccf_pwidth',     Parameter(24), ... % Window width in NCCF peak picking
    'merit_boost',  Parameter(25), ... % Boost merit
    'merit_pivot',  Parameter(26), ... % Merit assigned to unvoiced candidates in
                          ... % defintely unvoiced frames
    'merit_extra',   Parameter(27), ... % Merit assigned to extra candidates
                          ... % in reducing F0 doubling/halving errors
    'median_value',    Parameter(28), ... % Order of medial filter
    'dp_w1',        Parameter(29), ... % DP weight factor for V-V transitions
    'dp_w2',         Parameter(30), ... % DP weight factor for V-UV or UV-V transitions
    'dp_w3',         Parameter(31), ... % DP weight factor of UV-UV transitions
    'dp_w4',         Parameter(32), ... % Weight factor for local costs
    'smooth_threshold', Parameter(33), ... % Threshold of smoothing chunks
    'end', Parameter(34));


% Select parameter set 
% if (nargin > 2 && ~isempty(VU) && VU == 0)
%     Prm = Prm_aV;
% else 
%     Prm = Prm_VU;
% end
% Not needed if ignoring gross error minimization

% Overwrite parameters if they are passed from command line(ExtrPar)  
% if ((nargin > 3) && isstruct(ExtrPrm))
%     fdNames = fieldnames(ExtrPrm);
%     for n = 1:length(fdNames)
%         pName = char(fdNames(n));
%         Prm.(pName) = ExtrPrm.(pName);
%         %message('PT:det', 'Parameter %s replaced: %d', pName,Prm.(pName));
%     end
% end
%Prm

% Whether to plot pitch tracks, spectrum, engergy, etc.
% GraphPar = 0;
% if (nargin > 4 && ~isempty(fig))
%     GraphPar = fig;
% end

%-- MAIN ROUTINE --------------------------------------------------------------
%  Step 1. Preprocessing
%  Create the squared or absolute values of filtered speech data
Data_after = Preprocess(Data);
[DataB, DataC, DataD, nFs] = nonlinear(Data_after, Fs, Prm);

%  Check frame size, frame jump and the number of frames for nonlinear singal
% nframesize = fix(Prm.frame_length*nFs/1000);    
% if (nframesize < 15)
%     error('Frame length value %d is too short', Prm.frame_length);
% end
% if (nframesize > 2048)
%     error('Frame length value %d exceeds the limit', Prm.frame_length);
% end

%  Step 2. Spectral pitch tracking
%  Calculate NLFER and determine voiced/unvoiced frames with NLFER
[Energy, VUVEnergy]= nlfer(DataB, nFs, Prm);

%  Calculate an approximate pitch track from the spectrum.
%  At this point, SPitch is best estimate of pitch track from spectrum
[SPitch, VUVSPitch, pAvg, pStd]= spec_trk(DataD, nFs, VUVEnergy, Prm);


%  Step 3. Temporal pitch tracking based on NCCF
%  Calculate a pitch track based on time-domain processing
%  Pitch tracking from the filterd original signal 
[TPitch1, TMerit1] = tm_trk(DataB, nFs, SPitch, pStd, pAvg, Prm);

%  Pitch tracking from the filterd nonlinear signal 
[TPitch2, TMerit2] = tm_trk(DataD, nFs, SPitch, pStd, pAvg, Prm);

% Refine pitch candidates 
[RPitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, ...
                        Energy, VUVEnergy, Prm);
                    
% Step 5. Use dyanamic programming to determine the final pitch
Pitch_before  = dynamic(RPitch, Merit, Energy, Prm);
numfrms = length(Pitch_before);
frmrate = Prm.frame_space; 
 
[Pitch_Freq,~] = freqSelect(Pitch_before);
% Pitch = Pitch_Optimization(Pitch_Freq, Prm);
Pitch = Smooth2(Pitch_Freq, Prm);
pt_figs(DataB, DataD, nFs, SPitch, Energy, VUVEnergy, RPitch, Pitch, Prm);
  %figure(3)
  % plot(SPitch, 'b')
  % hold on
  % plot(Pitch, 'r')
  % hold off
  % title ('spectral pitch track')
  % pause


%  If VU = 0,  be sure entire track is voiced
%     if (VU == 0)      %  Only applies if we want all voiced track    
%        IDX_unvoiced = (Pitch < 1);
%          Num_UV       = sum (IDX_unvoiced);    % Total number unvoiced frames
%           if (Num_UV > 0) 
%             for n = 1:numfrms;    %  there should be a more efficient way to do this
%                if (IDX_unvoiced(n) == 1);
%                  Pitch(n) = SPitch(n);
%                 end;  
%             end; 
%           end;  
%      end;

% Replace above VU = 0 section for new ptch_fix() function
% if (VU==0)
%     Pitch = ptch_fix(Pitch);
% end
        

    % Pitch = SPitch;   % to see how good spectral track is

%== FIGURE ====================================================================
%  Several plots to illustrate processing and performance
% if (GraphPar)     

% end

%==============================================================================
end