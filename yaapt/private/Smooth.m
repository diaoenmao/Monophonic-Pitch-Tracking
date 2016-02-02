function [out] = Smooth(arr)
% Smooth frequency data by 3 chunks
% arr = frequency data
% out = data after smoothed
% 3 chunks is one window, if the lengh of the middle chunk is below
% threshold it will be absorbed by the head or tail chunk.
chunk1_value = 0;
chunk2_value = 0;
chunk3_value = 0;
chunk1 = [];
chunk2 = [];
chunk3 = [];
pointer = 0;
fixed_threshold = 10; % 10 frames
% percent_threshold = 0.01; % 1 percent
for i=1:length(arr)
    if pointer== 0 
	   chunk1_value = arr(i);
	   chunk1 = i;
       pointer = pointer + 1;
	elseif pointer == 1		
		if isempty(chunk1)
			chunk1_value=arr(i);
			chunk1 = i;
		else
			if arr(i)==chunk1_value
				chunk1 = [chunk1 i];
			else
				pointer = pointer +1;
				chunk2_value = arr(i);
				chunk2 = i;
			end
		end
	elseif pointer == 2
		if arr(i)==chunk2_value
			chunk2 = [chunk2 i];
		else
			pointer = pointer +1;
			chunk3_value = arr(i);
			chunk3 = i;
		end
	elseif pointer == 3
		if arr(i)==chunk3_value
			chunk3 = [chunk3 i];
        else
            % new chunk found
			len_tmp=[length(chunk1), length(chunk2), length(chunk3)];
			[min_len,idx] = min(len_tmp);
            if(min_len<=fixed_threshold)
                if idx == 1
                    for m=1:length(chunk1)
                        arr(chunk1(m)) = chunk2_value;
                    end
                elseif idx == 2
                    len_tmp(idx) = max(len_tmp)+100;
                    [~,second_min_idx] = min(len_tmp);
                    if second_min_idx == 1
                        for m=1:length(chunk2)
                            arr(chunk2(m)) = chunk1_value;
                        end
                    elseif second_min_idx == 3
                        for m=1:length(chunk2)
                            arr(chunk2(m)) = chunk3_value;
                        end
                    end
                elseif idx == 3
                    for m=1:length(chunk3)
                        arr(chunk3(m)) = chunk2_value;
                    end
                end
            end
			chunk1_value = arr(i);
			chunk2_value = 0;
			chunk3_value = 0;
			chunk1 = i;
			chunk2 = [];
			chunk3 = [];
			pointer = 1;
		end
    end
    if i==length(arr)
        if pointer == 2
            if length(chunk1)<fixed_threshold
                for m=1:length(chunk1)
                    arr(chunk1(m)) = chunk2_value;
                end     
            end
        elseif pointer == 3
            len_tmp=[length(chunk1), length(chunk2), length(chunk3)];
			[min_len,idx] = min(len_tmp);
            if(min_len<=fixed_threshold)
                if idx == 1
                    for m=1:length(chunk1)
                        arr(chunk1(m)) = chunk2_value;
                    end
                elseif idx == 2
                    len_tmp(idx) = max(len_tmp)+100;
                    [~,second_min_idx] = min(len_tmp);
                    if second_min_idx == 1
                        for m=1:length(chunk2)
                            arr(chunk2(m)) = chunk1_value;
                        end
                    elseif second_min_idx == 3
                        for m=1:length(chunk2)
                            arr(chunk2(m)) = chunk3_value;
                        end
                    end
                elseif idx == 3
                    for m=1:length(chunk3)
                        arr(chunk3(m)) = chunk2_value;
                    end
                end
            end
        end
    end
end
out = arr;
end
			
			
			
			
					