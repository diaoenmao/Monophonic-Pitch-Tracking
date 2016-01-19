function [cnt] = fq2cnt(fq)
% FQ2CNT Transform input frequency to cent unit
%
% fq = input frequency
% cnt = output cent scale with base at 13.75 Hz
% Each piano key frequency is linearly separated 100 cents 
% Ex: A4 - Ab4
% fq2cnt(440) - fq2cnt(415.305) = 6000 - 5900 = 100
%
cnt = 1200.*log2((fq./13.75));
end