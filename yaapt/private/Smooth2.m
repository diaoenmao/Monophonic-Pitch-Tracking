function [out] = Smooth2(arr, Prm)
min_length = Prm.smooth_threshold;
stable_length = 50;
absorb_threshold = 0.5;
pivot = arr(1);
headidx = 1;
headpitches = arr(1);
for i=1:length(arr)
    if(arr(i)~=pivot)
        headidx = [headidx i];
        headpitches = [headpitches arr(i)];
    end
    pivot=arr(i);
end

%idx = 1:length(arr);
prev_headidx = headidx;
tmp_headidx = [headidx length(arr)];
pitcheslength = diff(tmp_headidx);
visited = zeros(1,length(pitcheslength));
while(1)
    tmp_headidx = [headidx length(arr)];
    pitcheslength = diff(tmp_headidx);
    [sorted_pitcheslength,sorted_idx]=sort(pitcheslength);
        if(all(visited==1))
%         if(isequal(prev_headidx,headidx)&& all((diff(tmp_headidx)>min_length | headpitches==0)))
        if(isequal(prev_headidx,headidx))
            break;
        else
            visited = zeros(1,length(pitcheslength));
        end
        end
    
    sorted_pitches = headpitches(sorted_idx);
    prev_headidx = headidx;
    index = find(visited==0,1);
    visited(index) = 1;  
    %sorted_headidx = headidx(sorted_idx);

        

    check_pitch = sorted_pitches(index);
    check_pitchlength = sorted_pitcheslength(index);
    check_idx = sorted_idx(index);
    if(all(check_idx==1))
        left_pitch = 0;
        left_pitchlength = 0;
        right_pitch = headpitches(check_idx+1);
        right_pitchlength = pitcheslength(check_idx+1);
    elseif(all(check_idx==length(headidx)))
        left_pitch = headpitches(check_idx-1);
        left_pitchlength = pitcheslength(check_idx-1);
        right_pitch = 0;
        right_pitchlength = 0;
    else
        left_pitch = headpitches(check_idx-1);
        left_pitchlength = pitcheslength(check_idx-1);
        right_pitch = headpitches(check_idx+1);
        right_pitchlength = pitcheslength(check_idx+1);
    end
    %Smooth Criteria
    if(all(check_pitch ~= 0))
        if(all(left_pitch==0) && all(right_pitch == 0))
            if(all(check_pitchlength<min_length/2))
                headidx = headidx([1:check_idx-1, check_idx+2:end]);
                headpitches = headpitches([1:check_idx-1, check_idx+2:end]);
                visited = visited([1:index-1, index+2:end]);
            end
        elseif(all(left_pitch ~= 0) && all(right_pitch == 0))
            if((all(check_pitchlength/left_pitchlength<absorb_threshold)||all(check_pitchlength<min_length))&&all(check_pitchlength<stable_length))
                headidx = headidx([1:check_idx-1, check_idx+1:end]);
                headpitches = headpitches([1:check_idx-1, check_idx+1:end]);
                visited = visited([1:index-1, index+1:end]);
            end
        elseif(all(left_pitch == 0) && all(right_pitch ~= 0))
            if((all(check_pitchlength/right_pitchlength<absorb_threshold)||all(check_pitchlength<min_length))&&all(check_pitchlength<stable_length))
                temp = headidx(check_idx);
                headidx = headidx([1:check_idx-1, check_idx+1:end]);
                headidx(check_idx) = temp;
                headpitches = headpitches([1:check_idx-1, check_idx+1:end]);
                visited = visited([1:index-1, index+1:end]);
            end
        else
           if(all(left_pitchlength>right_pitchlength))
               if((all(check_pitchlength/left_pitchlength<absorb_threshold)||all(check_pitchlength<min_length))&&all(check_pitchlength<stable_length))
                    headidx = headidx([1:check_idx-1, check_idx+1:end]);
                    headpitches = headpitches([1:check_idx-1, check_idx+1:end]);
                    visited = visited([1:index-1, index+1:end]);             
               end
           elseif(all(left_pitchlength < right_pitchlength))
               if((all(check_pitchlength/left_pitchlength<absorb_threshold)||all(check_pitchlength<min_length))&&all(check_pitchlength<stable_length))
                    temp = headidx(check_idx);
                    headidx = headidx([1:check_idx-1, check_idx+1:end]);
                    headidx(check_idx) = temp;
                    headpitches = headpitches([1:check_idx-1, check_idx+1:end]);
                    visited = visited([1:index-1, index+1:end]);                   
               end
           else
               if((all(check_pitchlength/(left_pitchlength+right_pitchlength)<absorb_threshold)||all(check_pitchlength<min_length))&&all(check_pitchlength<stable_length))
                   headidx = headidx([1:check_idx-1, check_idx+2:end]);
                   headpitches = headpitches([1:check_idx-1, check_idx+2:end]);
                   visited = visited([1:index-1, index+2:end]);
               end
           end
        end
%     elseif(check_idx~=1&&check_idx~=length(headidx))
%            if(left_pitchlength>right_pitchlength)
%                if(((check_pitchlength/left_pitchlength<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length)
%                     headidx = headidx([1:check_idx-1, check_idx+1:end]);
%                     headpitches = headpitches([1:check_idx-1, check_idx+1:end]);
%                     visited = visited([1:index-1, index+1:end]);             
%                end
%            elseif(left_pitchlength < right_pitchlength)
%                if(((check_pitchlength/left_pitchlength<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length)
%                     temp = headidx(check_idx);
%                     headidx = headidx([1:check_idx-1, check_idx+1:end]);
%                     headidx(check_idx) = temp;
%                     headpitches = headpitches([1:check_idx-1, check_idx+1:end]);
%                     visited = visited([1:index-1, index+1:end]);                   
%                end
%            else
%                if(((check_pitchlength/(left_pitchlength+right_pitchlength)<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length)
%                    headidx = headidx([1:check_idx-1, check_idx+2:end]);
%                    headpitches = headpitches([1:check_idx-1, check_idx+2:end]);
%                    visited = visited([1:index-1, index+2:end]);
%                end
%            end
    end
            
end
out = zeros(1,length(arr));
tmp_headidx = [headidx length(arr)];
for i=1:length(headidx)
    out(tmp_headidx(i):tmp_headidx(i+1)) = headpitches(i).*ones(1,tmp_headidx(i+1)-tmp_headidx(i)+1);
end
            
            
            
            
            
end