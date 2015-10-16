out=zeros(1,length(Pitch));
for i=1:length(Pitch)
    if(VUVEnergy(i))
        out(i)=Pitch(i);
    end
end
figure
plot(out,'.-');
        