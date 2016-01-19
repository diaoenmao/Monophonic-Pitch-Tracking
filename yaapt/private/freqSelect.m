function [freq,cent] = freqSelect(fq)
% KEYSELECT Determine input fq as piano key
%
% fq = input frequency
% key{i} = output string denotes piano key, a cell array
% 
% upper limit is 1000 Hz, 7450 cents, B4 at 7400 cents
% lower limit is 65.4064 Hz, 2650 cents, C2 at 2700 cents
% key example format:
% ... B2 C3 C#3Db3 D3 D#3Eb3 E3 F3 F#3Gb3 G3 G#3Ab3 A3 A#3Bb3 B3 C4 ...
% Ex:
% >> key = keySelect(200)
% cnt = 4.6350e+03
% key = 'G3' (1x1 cell)
%
cnt = fq2cnt(fq);
% key = cell(1,length(cnt));
cent = zeros(1,length(cnt));
freq = zeros(1,length(cnt));
for i = 1:length(cnt)
    if (cnt(i) > 5050 && cnt(i) <= 7450)
        if (cnt(i) > 6250)
            if (cnt(i) > 6850)
                if (cnt(i) > 7150)
                    if (cnt(i) > 7250)
                        if (cnt(i) > 7350)
                            freq(i) = 987.767; % 7400
                            cent(i) = 7400;
                        else
                            freq(i) = 932.328; % 7300  
                            cent(i) = 7300;
                        end
                    else
                        freq(i) = 880.000; % 7200   
                        cent(i) = 7200;
                    end                
                else
                    if (cnt(i) > 7050)
                        freq(i) = 830.609; % 7100 
                        cent(i) = 7100;
                    else
                        if (cnt(i) > 6950)
                            freq(i) = 783.991; % 7000    
                            cent(i) = 7000;
                        else
                            freq(i) = 739.989; % 6900    
                            cent(i) = 6900;
                        end                    
                    end                  
                end         
            else
                if (cnt(i) > 6550)
                    if (cnt(i) > 6750)
                        freq(i) = 698.456; % 6800
                        cent(i) = 6800;
                    else
                        if (cnt(i) > 6650)
                            freq(i) = 659.255; % 6700
                            cent(i) = 6700;
                        else
                            freq(i) = 622.254; % 6600       
                            cent(i) = 6600;
                        end                    
                    end                  
                else
                    if (cnt(i) > 6450)
                        freq(i) = 587.33; % 6500    
                        cent(i) = 6500;
                    else
                        if (cnt(i) > 6350)
                            freq(i) = 554.365; % 6400  
                            cent(i) = 6400;
                        else
                            freq(i) = 523.251; % 6300      
                            cent(i) = 6300;
                        end                    
                    end                  
                end                        
            end
        else
            if (cnt(i) > 5650)
                if (cnt(i) > 5950)
                    if (cnt(i) > 6150)
                        freq(i) = 493.883; % 6200 
                        cent(i) = 6200;
                    else
                        if (cnt(i) > 6050)
                            freq(i) = 466.164; % 6100 
                            cent(i) = 6100;
                        else
                            freq(i) = 440; % 6000
                            cent(i) = 6000;
                        end                       
                    end                  
                else
                    if (cnt(i) > 5850)
                        freq(i) = 415.305; % 5900 
                        cent(i) = 5900;
                    else
                        if (cnt(i) > 5750)
                            freq(i) = 391.995; % 5800 
                            cent(i) = 5800;
                        else
                            freq(i) = 369.994; % 5700
                            cent(i) = 5700;
                        end                    
                    end                 
                end             
            else
                if (cnt(i) > 5350)
                    if (cnt(i) > 5550)
                       freq(i) = 349.228; % 5600 
                        cent(i) = 5600;
                    else
                        if (cnt(i) > 5450)
                            freq(i) = 329.628; % 5500 
                            cent(i) = 5500;
                        else
                            freq(i) = 311.127; % 5400 
                            cent(i) = 5400;
                        end                    
                    end                  
                else
                    if (cnt(i) > 5250)
                        freq(i) = 293.665; % 5300 
                        cent(i) = 5300;
                    else
                        if (cnt(i) > 5150)
                            freq(i) = 277.183; % 5200 
                            cent(i) = 5200;
                        else
                            freq(i) = 261.626; % 5100  
                            cent(i) = 5100;
                        end                    
                    end                  
                end              
            end        
        end
    elseif (cnt(i) <= 5050 && cnt(i) > 2650)
        if (cnt(i) > 3850)
            if (cnt(i) > 4450)
                if (cnt(i) > 4750)
                    if (cnt(i) > 4950)
                       freq(i) = 246.942; % 5000  
                        cent(i) = 5000;
                    else
                        if (cnt(i) > 4850)
                            freq(i) = 233.082; % 4900
                            cent(i) = 4900;
                        else
                            freq(i) = 220; % 4800  
                            cent(i) = 4800;
                        end                    
                   end                  
                else
                    if (cnt(i) > 4650)
                       freq(i) = 207.652; % 4700 
                        cent(i) = 4700;
                    else
                        if (cnt(i) > 4550)
                            freq(i) = 195.998; % 4600 
                            cent(i) = 4600;
                        else
                            freq(i) = 184.997; % 4500
                            cent(i) = 4500;
                        end                    
                    end                  
                end             
            else
                if (cnt(i) > 4150)
                    if (cnt(i) > 4350)
                        freq(i) = 174.614; % 4400 
                        cent(i) = 4400;
                    else
                        if (cnt(i) > 4250)
                            freq(i) = 164.814; % 4300
                            cent(i) = 4300;
                        else
                            freq(i) = 155.563; % 4200
                            cent(i) = 4200;
                        end                    
                    end                  
                else
                    if (cnt(i) > 4050)
                        freq(i) = 146.832; % 4100 
                        cent(i) = 4100;
                    else
                        if (cnt(i) > 3950)
                            freq(i) = 138.591; % 4000 
                            cent(i) = 4000;
                        else
                            freq(i) = 130.813; % 3900
                            cent(i) = 3900;
                        end                    
                    end                  
                end              
            end     
        else
            if (cnt(i) > 3250)
                if (cnt(i) > 3550)
                    if (cnt(i) > 3750)
                        freq(i) = 123.471; % 3800
                        cent(i) = 3800;
                    else
                        if (cnt(i) > 3650)
                            freq(i) = 116.541; % 3700    
                            cent(i) = 3700;
                        else
                            freq(i) = 110; % 3600
                            cent(i) = 3600;
                        end                    
                    end                 
                else
                    if (cnt(i) > 3450)
                         freq(i) = 103.826; % 3500 
                         cent(i) = 3500;
                    else
                        if (cnt(i) > 3350)
                            freq(i) = 97.9989; % 3400
                            cent(i) = 3400;
                        else
                            freq(i) = 92.4986; % 3300 
                            cent(i) = 3300;
                        end                    
                    end                  
                end              
            else
                if (cnt(i) > 2950)
                    if (cnt(i) > 3150)
                        freq(i) = 87.3071; % 3200 
                        cent(i) = 3200;
                    else
                        if (cnt(i) > 3050)
                            freq(i) = 82.4069; % 3100   
                            cent(i) = 3100;
                        else
                            freq(i) = 77.7817; % 3000 
                            cent(i) = 3000;
                        end                    
                    end                  
                else
                    if (cnt(i) > 2850)
                        freq(i) = 73.4162; % 2900
                        cent(i) = 2900;
                    else
                        if (cnt(i) > 2750)
                            freq(i) = 69.2957; % 2800  
                            cent(i) = 2800;
                        else
                            freq(i) = 65.4064; % 2700  
                            cent(i) = 2700;
                        end                       
                    end                  
                end              
            end        
        end
    else 
        cent(i) = 0;
%         display('input frequency out of range, range is from 65 Hz to 1000 Hz');
    end
end
end