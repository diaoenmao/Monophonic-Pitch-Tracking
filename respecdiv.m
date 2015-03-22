function div = respecdiv(arr1,arr2)
%respecdiv - respectively divide two arrays
% [div] = sevnadj(arr)
%
% Exp. 
% arr1 = [2 3 4];
% arr2 = [3 4 5];
% div = respecdiv(arr1,arr2);
% div =  [2/3 2/4 2/5 3/3 3/4 3/5 4/3 4/4/ 4/5];
div=zeros(length(arr1),length(arr2));
if (~((isempty(arr1))||(isempty(arr2))))
    for i=1:length(arr1)
        div(i,:) = arr1(i)./arr2;
    end
else
    div = 0;
end
end

