fq = [100;200;250;1000;2000;3000];
fq=fq(randperm(length(fq)));
num = fq2num(fq);
midi=num2midi(num);
midi2=fq2midi(fq);

num2=midi2num(midi);
fq2=num2fq(num2);
fq3=midi2fq(midi);