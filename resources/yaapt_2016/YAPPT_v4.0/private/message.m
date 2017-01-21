function [vgout] = message(varargin)
%MESSAGE Displays a message in the command window. This is an alternative
%   to WARNING, avoiding the automatic text "Warning: ", and also
%   allowing for more flexible formatting, based on FPRINTF.
%  
%Usage:
%   MESSAGE('MSG') is equivalent to FPRINTF(1,'MSG')
%   MESSAGE('MSG', a1, a2, ...) is equivalent to FPRINTF(1,'MSG', a1, a2...)
%   MESSAGE('MSGID', 'MSG') allows for suppressing according to the
%   enabled state of MSGID.
% 
%   MESSAGE('ON')    turns on MESSAGE (default).  When MESSAGE is ON,
%   messages can still be suppressed with DISABLE (see below).
%   MESSAGE('OFF')   suppresses all messages, regardless of ENABLE
%   state of MSGID (see below).
% 
%   MESSAGE('CLEAR') clears all MESSAGE memory.
% 
%   MESSAGE('ENABLE', 'MSGID') enables messages with identifier MSGID.  MSGID
%   can be a string or a cell array of strings.
%   MESSAGE('DISABLE', 'MSGID') suppresses messages with identifier MSGID.
%   MSGID can be a string or a cell array of strings.
%
%
%   MESSAGE('QUERY') returns the current enabled states of all 
%   MSGIDs as well as the MSGID names. [STATE,MSGID] =
%   MESSAGE('QUERY') returns the current enabled states of all
%   MSGIDs as well as the MSGID names in a cell array.
%   [STATE,MSGID] = MESSAGE('QUERY', 'MSGID') returns the current enabled states
%   of the user specified MSGIDs.  If MSGID is cellstr, a vector indicating
%   the states is returned.
% 
%
%Examples:
%
% 1.  >> message('Hello')
%     Hello
% 2.  >> message('Level 1','Hello')  %behaves identically to FPRINTF
%     Level 1
% 3.  >> message('Level 1 %s','Hello')
%     Level 1 Hello
% 4.  >> message('enable',{'Level 1','Level 2'})
%     >> message('Level 1','Hello')
%     Hello
% 5.  >> message('enable','Level 1')
%     >> message('off')
%     >> message('Level 1','Hello')    %no output returned
%     >> state = message('query','Level 1')
%          State  Warning Identifier
%             on  Message ON/OFF
%            off  MYFUNC:Convert
%            off  MYFUNC:IntVal
%             on  MYFUNC:Overall
%
%     See also WARNING, ERROR, FPRINTF


%Notes:
%1. MESSAGE stores a structural array called "message" as application data
%   of the command window.  Be careful when working with command window app data.
% 
%2. All keywords are case insensitive.
%   ('on' , 'off' , 'enable', 'disable', 'clear' , 'query')  
% 
%3. Note from Example 5 above that setting "message('off')" does not affect
%the enabled state of individual MSGIDs.  This functionality allows the
%user to toggle ON and OFF without bookkeeping of the MSGID
%enabled states.
% 
% 4. Note from Example 2 above that if a MSGID has not been defined, MESSAGE will
% behave exactly like FPRINTF, ignoring extra arguments if not specified in
% the first string argument, as shown in Example 3.


% 
%Author:
% Revised by Hongbing HU (hongbing.hu@binghamton.edu), 06/11/2007
% Todd C Pataky (0todd0@gmail.com)  14-June-2006

%Programming notes:
%1. The app data stored in the command window is of the following format:
%       message.on = 1;
%       message.msgid = {'a','aaa','b','c'}
%       message.enabled = [1 0 1 1];


%%%%%%%%%%%%%%%%
%PRELIMINARY ERROR CHECKS
%%%%%%%%%%%%%%%%
if nargin==0
    eval('help message');
    return
end


x1 = varargin{1};
if ~ischar(x1)
    error('First input argument must be a string.')
end
if ~isequal(upper(x1),'QUERY') && (nargout > 0)
    error('Too many output arguments.  Output only given when using "QUERY".')
end
if nargout > 1
    error('Too many output arguments');
end

%%%%%%%%%%%%%%%%
%INITIALIZE MESSAGE STRUCTURE (if not yet initialized)
%%%%%%%%%%%%%%%%
M = getappdata(0,'message');
if isempty(M)
    M.on = 1;
    M.msgid = {};
    M.enabled = [];
    setappdata(0,'message',M);
end

switch upper(x1)
%%%%%%%%%%%%%%%%
%1. ON / OFF
%%%%%%%%%%%%%%%%
 case {'ON', 'OFF'}
    if nargin>1
        error('Too many input arguments. Only one argument permitted for %s.',upper(x1))
    end
    M.on = strmatch(upper(x1),{'OFF','ON'})  -   1;
    setappdata(0,'message',M);

%%%%%%%%%%%%%%%%
%2. ENABLE / DISABLE
%%%%%%%%%%%%%%%%
 case {'ENABLE', 'DISABLE'}
    if nargin~=2
        error('Must use 2 input arguments when using %s',upper(x1))
    end
    x2 = varargin{2};
    if ~( ischar(x2) || iscellstr(x2) )
        error('MSGID must be a string or a cell array of strings.')
    end
    if ischar(x2)
        x2 = {x2};
    end
    state = strmatch(upper(x1),{'DISABLE','ENABLE'})  -   1;
    [ismem,ind] = ismember(x2,M.msgid);
    % Change state of MSGIDs that already exist
    M.enabled(ind(ind>0)) = state;
    % Add MSGIDs that do not yet exist
    x2 = x2(~ismem);
    M.msgid = [M.msgid x2];
    M.enabled = [M.enabled  state*ones(1,length(x2))  ];
    [M.msgid, ind] = sort(M.msgid);
    M.enabled  = M.enabled(ind);
    setappdata(0,'message',M);

%%%%%%%%%%%%%%%%
%3. CLEAR
%%%%%%%%%%%%%%%%
 case 'CLEAR'
    if nargin==1
        if isappdata(0,'message')
            rmappdata(0,'message');
        end
    else 
        error('Too many input arguments. No extra arguments permitted for "CLEAR".')
    end
    
%%%%%%%%%%%%%%%%
%4. QUERY
%%%%%%%%%%%%%%%%
 case 'QUERY'
    ffn = {'off', 'on'};
    if nargin==1
        if nargout==0
                fprintf('%8s  %s\n', 'State', 'Message Identifier');
                fprintf('%8s  %s\n', ffn{M.on+1}, 'Message ON/OFF');
            for n=1:length(M.msgid)
                fprintf('%8s  %s\n', ffn{M.enabled(n)+1}, M.msgid{n});
            end;
        else
            vgout.identifier = M.msgid;
            vgout.state = M.enabled;
        end;
    else
        x2 = varargin{2};
        if ~( ischar(x2) || iscellstr(x2) )
            error('MSGID must be a string or a cell array of strings.')
        end
        if ischar(x2)
            x2 = {x2};
        end
        [found,ind] = ismember(x2,M.msgid);
        % Check whether all MSGIDs are existing
        if ~all(found)
            error('MSGID "%s" not found.',  x2{~found});
        end
        if nargout==0
            Me = M.enabled(ind);
            Mm = {M.msgid{ind}};
            fprintf('%8s  %s\n', 'State', 'Message Identifier');
            for n=1:length(Mm)
                fprintf('%8s  %s\n', ffn{Me(n)+1}, Mm{n});
            end;
        else
            vgout.identifier = M.msgid(ind);
            vgout.state = M.enabled(ind);
        end;
    end;

%%%%%%%%%%%%%%%%
%5. Display message  
%%%%%%%%%%%%%%%%
 otherwise
  if ~M.on
      return
  end;
  if isempty(regexp(x1, '\S:\S', 'match'))
      fprintf(varargin{:}), fprintf('\n');
  else
      [dmy,ind] = ismember(x1,M.msgid);
      if ind
          if M.enabled(ind);
              fprintf(varargin{2:end}), fprintf('\n');
          end;
      elseif (nargin > 1)
          fprintf(varargin{2:end}), fprintf('\n');
      else
          error('When the first input is a message identifier, a second input is required.');
      end
  end;
end;

