function h=Myfirls(N,F,M)
% FIRLS	Linear-phase FIR filter design using least-squares error minimization
%	B=FIRLS(N,F,M) returns a length N+1 linear phase (real, symmetric
%	coefficients) FIR filter which has the best approximation to the 
%	desired frequency response described by F and M in the least squares 
%	sense. F is a vector of frequency band edges in pairs, in ascending 
%	order between 0 and 1. 1 corresponds to the Nyquist frequency or half
%	the sampling frequency. M is a real vector the same size as F 
%	which specifies the desired magnitude of the frequency response of the
%	resultant filter B. The desired response is the line connecting the
%	points (F(k),M(k)) and (F(k+1),M(k+1)) for odd k; FIRLS treats the 
%	bands between F(k+1) and F(k+2) for odd k as "transition bands" or 
%	"don't care" regions. Thus the desired magnitude is piecewise linear
%	with transition bands.  The integrated squared error is minimized.
%
%	B=FIRLS(N,F,M,W) uses the weights in W to weight the error. W has one
%	entry per band (so it is half the length of F and M) which tells
%	FIRLS how much emphasis to put on minimizing the integral squared error
%	in each band relative to the other bands.
%	
%	B=FIRLS(N,F,M,'Hilbert') and B=FIRLS(N,F,M,W,'Hilbert') design filters 
%	that have odd symmetry, that is, B(k) = -B(N+2-k) for k = 1, ..., N+1. 
%	A special case is a Hilbert transformer which has an approx. magnitude
%	of 1 across the entire band, e.g. B=FIRLS(30,[.1 .9],[1 1],'Hilbert'). 
%
%	B=FIRLS(N,F,M,'differentiator') and B=FIRLS(N,F,M,W,'differentiator')
%	also design filters with odd symmetry, but with a special weighting
%	scheme for non-zero magnitude bands. The weight is assumed to be equal 
%	to the inverse of frequency, squared, times the weight W. Thus the 
%	filter has a much better fit at low frequency than at high frequency. 
%	This designs FIR differentiators.
%
%	See also REMEZ, FIR1, FIR2, FREQZ and FILTER.

%	Example of a length 29 low-pass filter:
%		h=firls(30,[0 .1 .2 .5]*2,[1 1 0 0]);
%	Example of a low-pass differentiator: 
%		h=firls(N,[0 10 20 40]/50,[0 .2 0 0],'differentiator');
%
%       Author(s): T. Krauss, 10-18-91
%   		   T. Krauss, 3-30-93, updated
%	Copyright (c) 1984-94 by The MathWorks, Inc.
%	$Revision: 1.8 $  $Date: 1994/01/25 17:59:10 $

% check number of arguments, set up defaults.
% nargchk(3,5,nargin);
% if (nargin==3)
    W = ones(length(F)/2,1);
%     ftype = '';
% end
% if (nargin==4),
%     if isstr(W), 
%         ftype = W; W = ones(length(F)/2,1);
%     else
%         ftype = '';
%     end
% end	
% if (nargin==5),
%     if isempty(W), 
%         W = ones(length(F)/2,1);
%     end
% end
% if isempty(ftype)
    ftype = 0;  differ = 0;
% else
%     ftype = lower(ftype);
%     if strcmp(ftype,'h')|strcmp(ftype,'hilbert')
%         ftype = 1;  differ = 0;
%     elseif strcmp(ftype,'d')|strcmp(ftype,'differentiator')
%         ftype = 1;  differ = 1;
%     else
%         error('Requires symmetry to be ''Hilbert'' or ''differentiator''.')
%     end
% end

N = N+1;                   % filter length
F=F(:)/2;  M=M(:);  W=sqrt(W(:));  % make these guys columns
if (rem(length(F),2)~=0)
    error('F must have even length');
end;
if (length(F)~=length(M))
    error('F and M must be equal lengths');
end;
if (length(F)~=length(W)*2)
    error('There should be one weight per band.');
end;
if any(diff(F)<0),
    error('Frequencies in F must be nondecreasing.')
end
if (max(F)>1)|(min(F)<0)
    error('Frequencies in F must be in range [0,1].')
end

L=(N-1)/2;

if (ftype == 0),  % Type I and Type II linear phase FIR 
                  % basis vectors are cos(2*pi*m*f) (see m below)
    if (rem(N,2)==0),
        m=(0:L)+.5;   % type II
    else
        m=(0:L);      % type I
    end
%     k=m';
    a=m';
    I1=a(:,ones(size(m)))+m(ones(size(a)),:);    % entries are m + k
    I2=a(:,ones(size(m)))-m(ones(size(a)),:);    % entries are m - k
    G=zeros(size(I1));

    if (rem(N,2)~=0),
        k=a(2:length(a));
        b0=0;       %  first entry must be handled separately (where k(1)=0)
    else
        k=m';
    end
    b=zeros(size(k));
    for s=1:2:length(F),
        m=(M(s+1)-M(s))/(F(s+1)-F(s));    %  slope
        b1=M(s)-m*F(s);                   %  y-intercept
        b0 = b0 + (b1*(F(s+1)-F(s)) + m/2*(F(s+1)*F(s+1)-F(s)*F(s)))...
                     * abs(W((s+1)/2)^2) ;
        b = b+(m/(4*pi*pi)*(cos(2*pi*k*F(s+1))-cos(2*pi*k*F(s)))./(k.*k))...
                     * abs(W((s+1)/2)^2);
        b = b + (F(s+1)*(m*F(s+1)+b1)*sinc(2*k*F(s+1)) ...
                   - F(s)*(m*F(s)+b1)*sinc(2*k*F(s))) ...
                     * abs(W((s+1)/2)^2);
        G = G + (.5*F(s+1)*(sinc(2*I1*F(s+1))+sinc(2*I2*F(s+1))) ...
               - .5*F(s)*(sinc(2*I1*F(s))+sinc(2*I2*F(s))) ) ...
                     * abs(W((s+1)/2)^2);
    end;
    if (rem(N,2)~=0),
        p=[b0; b];
    else
        p=b;
    end

    a=G\p;
    if (rem(N,2)~=0),
        h=[a(L+1:-1:2)/2; a(1); a(2:L+1)/2].';
    else
        h=.5*[flipud(a); a].';
    end;
% elseif (ftype == 1),  % Type III and Type IV linear phase FIR
%                   %  basis vectors are sin(2*pi*m*f) (see m below)
%     if (differ),      % weight non-zero bands with 1/f^2
%         do_weight = ( abs(M(1:2:length(M))) +  abs(M(2:2:length(M))) ) > 0;
%     else
%         do_weight = zeros(size(F));
%     end
% 
%     if rem(N,2),
%         m=(1:L);      % type III
%     else
%         m=(0:L)+.5;   % type IV
%     end;
%     k=m';
%     I1=k(:,ones(size(m)))+m(ones(size(k)),:);    % entries are m + k
%     I2=k(:,ones(size(m)))-m(ones(size(k)),:);    % entries are m - k
%     b=zeros(size(k));
%     G=zeros(size(I1));
% 
%     i = sqrt(-1);
%     for s=1:2:length(F),
%         if (do_weight((s+1)/2)),      % weight bands with 1/f^2
%             if F(s) == 0, F(s) = 1e-5; end     % avoid singularities
%             m=(M(s+1)-M(s))/(F(s+1)-F(s));
%             b1=M(s)-m*F(s);
%             snint1 = sineint(2*pi*k*F(s+1)) - sineint(2*pi*k*F(s));
%             %snint1 = (-1/2/i)*(expint(i*2*pi*k*F(s+1)) ...
%             %    -expint(-i*2*pi*k*F(s+1)) -expint(i*2*pi*k*F(s)) ...
%             %    +expint(-i*2*pi*k*F(s)) );
%             % csint1 = cosint(2*pi*k*F(s+1)) - cosint(2*pi*k*F(s)) ;
%             csint1 = (-1/2)*(expint(i*2*pi*k*F(s+1))+expint(-i*2*pi*k*F(s+1))...
%                             -expint(i*2*pi*k*F(s))  -expint(-i*2*pi*k*F(s)) );
%             b=b + ( m*snint1 ...
%                 + b1*2*pi*k.*( -sinc(2*k*F(s+1)) + sinc(2*k*F(s)) + csint1 ))...
%                 * abs(W((s+1)/2)^2);
%             snint1 = sineint(2*pi*F(s+1)*(-I2));
%             snint2 = sineint(2*pi*F(s+1)*I1);
%             snint3 = sineint(2*pi*F(s)*(-I2));
%             snint4 = sineint(2*pi*F(s)*I1);
%             G = G - ( ( -1/2*( cos(2*pi*F(s+1)*(-I2))/F(s+1)  ...
%                       - 2*snint1*pi.*I2 ...
%                       - cos(2*pi*F(s+1)*I1)/F(s+1) ...
%                       - 2*snint2*pi.*I1 )) ...
%                   - ( -1/2*( cos(2*pi*F(s)*(-I2))/F(s)  ...
%                       - 2*snint3*pi.*I2 ...
%                       - cos(2*pi*F(s)*I1)/F(s) ...
%                       - 2*snint4*pi.*I1) ) ) ...
%                          * abs(W((s+1)/2)^2);
%         else      % use usual weights
%             m=(M(s+1)-M(s))/(F(s+1)-F(s));
%             b1=M(s)-m*F(s);
%             b=b+(m/(4*pi*pi)*(sin(2*pi*k*F(s+1))-sin(2*pi*k*F(s)))./(k.*k))...
%                          * abs(W((s+1)/2)^2) ;
%             b = b + (((m*F(s)+b1)*cos(2*pi*k*F(s)) - ...
%                  (m*F(s+1)+b1)*cos(2*pi*k*F(s+1)))./(2*pi*k)) ...
%                          * abs(W((s+1)/2)^2) ;
%             G = G + (.5*F(s+1)*(sinc(2*I1*F(s+1))-sinc(2*I2*F(s+1))) ...
%                - .5*F(s)*(sinc(2*I1*F(s))-sinc(2*I2*F(s)))) * abs(W((s+1)/2)^2);
%         end;
%     end
% 
%     a=G\b;
%     if (rem(N,2)~=0),
%         h=.5*[flipud(a); 0; -a].';
%     else
%         h=.5*[flipud(a); -a].';
%     end
% end    
end
