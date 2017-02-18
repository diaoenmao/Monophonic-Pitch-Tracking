function midi = num2midi(num)
convention = 1;%0 starts from octave -1
midi = (num(:,2)+convention)*12+num(:,1)-1;
end