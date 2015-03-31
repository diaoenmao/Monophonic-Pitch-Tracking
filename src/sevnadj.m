function sd = sevnadj(arr)
%sevnadj - Seven adjacent element of each given element in given array
%
% [sd] = sevnadj(arr)
%
% Exp. 
% arr = [55 32];
% sd = sevnadj(arr);
% sd =  [52:58 29:35];
if (~(isempty(arr)))
    sd = [arr-3 arr-2 arr-1 arr arr+1 arr+2 arr+3];
else
    sd = 0;
end
end

