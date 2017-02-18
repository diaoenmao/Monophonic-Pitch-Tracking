function num = fq2num(fq)
load('bin_cnt.mat')
cnt=fq2cnt(fq);
num=zeros(length(fq),2);
for i=1:length(fq)
    [num(i,2),num(i,1)]=find(cnt(i)>=bin_cnt_low&cnt(i)<=bin_cnt_high);
end
end