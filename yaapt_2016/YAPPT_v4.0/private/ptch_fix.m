function [pitch] = ptch_fix(pitch,CmdFile)

% PTCH_FIX
%   This is a MATLAB script to attempt some correction measures on the
%   calculated pitch track. The calculated pitch tracks must be present
%   already.

% INPUTS:
%   CmdFile: Command file (use default 'ptch_fix.dat', if not specified)
%
% OUTPUTS:
%   pitch:  The pitch track after applying correction techniques
%
% NOTES:
%   The setup files needed to run this program are
%   ptch_fix.dat  - contains parameters needed for running the script.

% 
%   Creation date:       Spring 2013
%   Revision date:       

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


%% Initialization ------------------

% DEFAULT_COMMAND_FILE = 'ptch_fix.dat';% default name of command file if this program is
                                      % run without an input argument
% Message output control
% message('enable',  {'PT:bsc'});
% message('disable', {'PT:det', 'PT:wrf'});


% % Default values

pitch_half = 0;
pitch_half_sens = 2.9;
pitch_double = 0;
pitch_double_sens = 3.5;
interp = 1;
smooth_factor = 5;
smooth = 0;
extrap = 1;
ptch_typ = 100;

% Step 1 - Read ptch_fix.dat
if nargin > 1
    fid = fopen(CmdFile,'r');
    if (fid == -1)
        error('ptch_fix.m -> Error: cannot open %s!\n', CmdFile);
    end


%% Main Routine --------------------

while feof(fid) ~= 1 
    s = upper(fgetl(fid));
    [varname, s] = strtok(s);
    if  (length(varname) > 1) && (~strcmp(varname(1:2),'//'))   
        % check for length > 1 instead of using isempty to avoid 
        % the Eof char in case of QEdit was used to edit the command file
        
        value = strtok(s);
        % now find what variable it is
        switch (varname)
         case 'COMP_LST_FILE:'
          COMP_LST_FILE = value;
         case 'PITCH_HALF:'
          pitch_half = str2num(value);
         case 'PITCH_HALF_SENS:'
          pitch_half_sens = str2num(value);
         case 'PITCH_DOUBLE_SENS:'
          pitch_double_sens = str2num(value);
         case 'PITCH_DOUBLE:'
          pitch_double = str2num(value);
         case 'SMOOTH_INTERP:'
          interp = str2num(value);
         case 'SMOOTH_FACTOR:'
          smooth_factor = str2num(value);
         case 'SMOOTH:'
          smooth = str2num(value);
         case 'EXTRAP:'
          extrap = str2num(value); 
         otherwise 
          warning('Unknown variable name: %s\n',varname);
        end % end switch
    end
end

fclose(fid);
end

% Obsoleted code - can be removed
%--------------------------------------
%  Step 2 - Read File with list of Sentences
% [SenLst, NumSen] = rd_lst(COMP_LST_FILE);  % to read computed tracks

% Step 3 - Processing each Sentence
% message('PT:bsc', 'The number of files: %d', NumSen);
% for iSen = 1:NumSen
%     
%     % Get name of each pitch track file
%     Filename1 = strtok(SenLst(iSen,:));
%     
%     message('PT:bsc','Processing file #%d', iSen);
%     message('PT:bsc', '%s', Filename1);
%     
%     % Read pitch  track and reference pitch track
%     [pitch]   = rd_feat(Filename1);
%     message('PT:wrf', 'Read pitch file: %s', Filename1);
%----------------------------------------


    % Attempt to correct some pitch halving of the calculated track.
    % Find the indicies of values that are below 2.5 std dev below the mean
    
    if (pitch_half > 0)
        if (pitch_half == 1)        % Zero them out.
            pitch(pitch < (mean(nonzeros(pitch)) - pitch_half_sens*std(nonzeros(pitch)))) = 0;
        elseif(pitch_half == 2)    % Alternatively, double those values.
            pitch(pitch < (mean(nonzeros(pitch)) - pitch_half_sens*std(nonzeros(pitch)))) = 2.*pitch(pitch < (mean(nonzeros(pitch)) - pitch_half_sens*std(nonzeros(pitch))));
        end
    end
    
    % Attempt to correct some pitch doubling of the calculated track.
    % Find the indicies of values that are above 3.5 std dev above the mean
    
    if (pitch_double > 0)
        if (pitch_double == 1)        % Zero them out.
            pitch(pitch > (mean(nonzeros(pitch)) + pitch_double_sens*std(nonzeros(pitch)))) = 0;
        elseif(pitch_double == 2)    % Alternatively, double those values.
            pitch(pitch > (mean(nonzeros(pitch)) + pitch_double_sens*std(nonzeros(pitch)))) = .5.*pitch(pitch > (mean(nonzeros(pitch)) + pitch_double_sens*std(nonzeros(pitch))));
        end
    end
    
    if (interp)  % Interpolate the pitch 
        % Use a smoothed version of the pitch track to interpolate
        % Apply a median filter and then substitute the smoothed interpolated
        % sections into the calculated pitch track
        pitch2 = medfilt1(pitch,smooth_factor);
        if (length(find(pitch2))<2)
            pitch((pitch==0)) = ptch_typ;
        else
        pitch2 = interp1(find(pitch2),pitch2(pitch2>0),[1:length(pitch2)],'pchip',mean(nonzeros(pitch2)));
        pitch(pitch==0) = pitch2(pitch==0);
        end
    end
    
    if (smooth>0)
        pitch = medfilt1(pitch,smooth);
    end
 
    % Interpolate the pitch track 
%     pitch = interp1(find(pitch),pitch(pitch>0),[1:length(pitch)],'pchip',0);

    if(extrap)      % Smoothly extend the end points
        zero = find(pitch==0);      % Find index of all zeros
        j = 1;
        while (length(zero)>=j && zero(j)==j)
            j=j+1;                  % Find number of preceeding zeros
        end
        zero = zero(end:-1:1);
        len_trk  = length(pitch);
        k = 1;
        while (length(zero)>=j && zero(k)==len_trk-k+1)% Do basically the same thing again
            k=k+1;                  % But now, we find the number of
        end;                        % trailing zeros
        pitch([1:j-1 len_trk-k+2:end]) = mean(nonzeros(pitch));
    end
end

