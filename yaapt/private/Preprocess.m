function [Data_out] = Preprocess(Data_in)
% Preprocess the raw data from android voice recorder
%
% Data_in = Raw data android voice recorder
% Data_out = Head and tail muted data
% The noise comes from opening mic and closing mic
head_muted_length = 600;
tail_muted_length = 2000;
Data_temp = Data_in;
Data_temp(1:head_muted_length)=0;
Data_temp(end-tail_muted_length:end)=0;
Data_out = Data_temp;
end