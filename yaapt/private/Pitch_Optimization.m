function [Pitch_out] = Pitch_Optimization(Pitch)
% Preprocess the raw data from android voice recorder
%
% Data_in = Raw data android voice recorder
% Data_out = Head and tail muted data
% The noise comes from opening mic and closing mic
Pitch_temp = Pitch;
for i=1:length(Pitch_temp)
    if( i+1<length(Pitch_temp) && i-1>0 && Pitch_temp(i-1) ~= Pitch_temp(i) && Pitch_temp(i) ~= Pitch_temp(i+1)) 
        Pitch_temp(i) = Pitch_temp(i - 1);
    end
end

Pitch_temp = Smooth(Pitch_temp);
Pitch_temp = Smooth(Pitch_temp);
Pitch_out = Smooth(Pitch_temp);
% Pitch_out = Pitch_temp;
end