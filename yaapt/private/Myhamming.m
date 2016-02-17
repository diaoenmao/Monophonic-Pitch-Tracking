function w = Myhamming(n)
%HAMMING HAMMING(N) returns the N-point Hamming window.

%	Copyright (c) 1984-94 by The MathWorks, Inc.
%       $Revision: 1.4 $  $Date: 1994/01/25 17:59:14 $

w = .54 - .46*cos(2*pi*(0:n-1)'/(n-1));
end