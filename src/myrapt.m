function [fx,tt] = myrapt(s,Fs)
%% Emprical Constants
s=s(:); % force s to be a column
F0min = 50;                      %minimum F0 to search for (HZ)
F0max = 500;                     %maximum F0 to search for (HZ)
t = .01;                         %frame advance Duration
w = .0075;                       %correlation window Duration
tlpw = 0.005;                    %low pass filter window size (s)           [0.005]
candtr = 0.3;                   %minimum acceptable peak value
ncands = 20;                    %max number of hypothese(candidates) at each frame
% Constatnts for dynamic programming pitch selection
lagwt = 0.3;                    %linear lag taper factor for NCCF
freqwt = 0.02;                  %cost factor for F0 range
vtranc = 0.005;                 %fixed voicing-state transition cost
vtrac = 0.5;                   %delta amplitude modulated tranistion cost
vtrsc = 0.5;                   %delta spectrum modulated transition cost
vobias = 0.0;                   %bias to encourage voiced hypotheses
doublec = 0.35;                 %cost of exact F0 doubling or halving
absnoise = 0;                    % absolute rms noise level                  [0]
relnoise = 2.0;                  % rms noise level relative to noise floor   [2.0]
signoise = 0.001;                % ratio of peak signal rms to noise floor   [0.001]
preemph = -7000;                 %s-plane position of preemphasis zero      
nfullag = 7;                     %number of full lags to try (must be odd)
trms = 0.03;                    %window spacing for rms measurement
dtrms = 0.02;              %window spacing for rms measurement
%% Derived Constants
krms=round(trms*Fs);            % window length for rms measurement
kdrms=round(dtrms*Fs);          % window spacing for rms measurement
rmswin=hanning(krms).^2;
Fsd = Fs/(round(Fs/(4*F0max)));  %low sampling rate
kdsmp = Fs/Fsd;                  %downsample rate
hlpw=round(tlpw*Fs/2);          % force window to be an odd length
blp=sinc((-hlpw:hlpw)/kdsmp).*hamming(2*hlpw+1).';
zd = round(Fsd*t);                %downsampled frame step size for Fs(samples)
z = zd*kdsmp;                  %frame step size for Fs(samples)
nd = round(Fsd*w);                %downsampled correlation window length for Fs(samples), number of samples correlated at each lag
n = nd*kdsmp;                  %correlation window length for Fs(samples), number of samples correlated at each lag
rmsix=(1:krms)+floor((kdrms-z)/2); % rms index according to Talkin; better=(1:krms)+floor((kdrms-krms+1)/2)
Kmax = round(Fsd/F0min);          %max Lags, longeset lag at each frame for Fs
Kmin = ceil(Fsd/F0max);          %min Lags, shortest lag at each frame for Fs
spoff=max(hlpw-floor(kdsmp/2),1+kdrms-rmsix(1)-z);  % offset for first speech frame at full rate
sfoff=spoff-hlpw+floor(kdsmp/2); % offset for downsampling filter
sfi=1:nd;                   % initial decimated correlation window index array
sfhi=1:n;                   % initial correlation window index array
sfj=1:nd+Kmax;
sfmi=repmat((Kmin:Kmax)',1,nd)+repmat(sfi,Kmax-Kmin+1,1);
lagoff=(Kmin-1)*kdsmp;        % lag offset when converting to high sample rate
beta=lagwt*F0min/Fs;            % bias towards low lags
log2=log(2);
lpcord=2+round(Fs/1000);        % lpc order for itakura distance
hnfullag=floor(nfullag/2);      % half of nfullag which is lag tried in highpass
jumprat=exp((doublec+log2)/2);  % lag ratio at which octave jump cost is lowest
ssq=s.^2;
csssq=cumsum(ssq);
sqrt(min(csssq(n+1:end)-csssq(1:end-n))/n);
%unvoiced detection, term to decrease peaks of weak signals
afact=max([absnoise^2,max(ssq)*signoise^2,min(csssq(n+1:end)-csssq(1:end-n))*(relnoise/n)^2])^2*n^2;
%% Signal Generation
% Duration = 2.0;                 %signal Duration 
% time = 0:T:Duration-T; 
% y=0.4*chirp(time,200,Duration,400,'li');
% y = 0.4*sawtooth(2*pi*440*time);
% yh = 0.4*cos(2*pi*440*time);

% downsample signal to approx 2 kHz to speed up autocorrelation calculation
% kdsmp is the downsample factor
time = (0:length(s)-1)/Fs;
Duration = time(end);
M = round(length(time)/z);      %number of Frames 
sf=filter(blp/sum(blp),1,s(sfoff+1:end));
sp=filter([1 exp(preemph/Fs)],1,s); % preemphasised speech for LPC calculation
sf(1:length(blp)-1)=[];         % remove startup transient
sf=sf(1:kdsmp:end);             % downsample to =~2kHz
nsf=length(sf);                 % length of downsampled speech
ns=length(s);                   % length of full rate speech

 % Calculate the frame limit to ensure we don't run off the end of the speech or decimated speech:
 %   (a) For decimated autocorrelation when calculating sff():  (nframe-1)*kframed+kcorwd+maxlag <= nsf
 %   (b) For full rate autocorrelation when calculating sfh():  max(fho)+kcorw+maxlag*kdsamp+hnfllag <= ns
 %   (c) For rms ratio window when calculating rr            :  max(fho)+rmsix(end) <= ns
 % where max(fho) = (nframe-1)*kframe + spoff
 
 nframe=floor(1+min((nsf-nd-Kmax)/zd,(ns-spoff-max(n-Kmax*kdsmp-hnfullag,rmsix(end)))/z));
 
 % now search for autocorrelation peaks in the downsampled signal
 cost=zeros(nframe,ncands);      % cumulative cost
 prev=zeros(nframe,ncands);      % traceback pointer
 mcands=zeros(nframe,1);         % number of actual candidates excluding voiceless
 lagval=repmat(NaN,nframe,ncands-1);    % lag of each voiced candidate
 tv=zeros(nframe,3);             % diagnostics: 1=voiceless cost, 2=min voiced cost, 3:cumulative voiceless - min voiced
 costms=cell(nframe,1);

%% NCCF
R = zeros(Kmax,nframe);
Peaks = zeros(ncands,nframe);
Lags = zeros(ncands,nframe);
Result = struct('vipk',{});
for iframe=1:nframe % loop for each frame (~10 ms)
    
     % Find peaks in the normalized autocorrelation of subsampled (2Khz) speech
     % only keep peaks that are > 30% of highest peak
     
     fho=(iframe-1)*z+spoff;     % ignore first fho samples of sound, used in highpass
     sff=sf((iframe-1)*zd+sfj);  % sfj = 1:nd+Kmax
     sffdc=mean(sff(sfi));       % mean of initial correlation window length
     sff=sff-sffdc;              % subtract off the mean
     nccfd=normxcor(sff(1:nd),sff(Kmin+1:end));
     [ipkd,vpkd]=v_findpeaks(nccfd,'q');
     % Debugging: execute the line below to plot the autocorrelation peaks.
     % v_findpeaks(nccfd,'q'); xlabel(sprintf('Lag = (x+%d)*%g ms',Kmin-1,1000*kdsmp/Fs)); 
     % ylabel('Normalized Cross Correlation'); title (sprintf('Frame %d/%d',iframe,nframe));
     vipkd=[vpkd ipkd];
     vipkd(vpkd<max(vpkd)*candtr,:)=[];          % eliminate peaks that are small
     if size(vipkd,1)
         if size(vipkd,1)>ncands-1
             vipkd=sortrows(vipkd);
             vipkd(1:size(vipkd,1)-ncands+1,:)=[];   % eliminate lowest to leave only ncands-1
         end
         lagcan=round(vipkd(:,2)*kdsmp+lagoff);        % convert the lag candidate values to the full sample rate
         nlcan=length(lagcan);
     else
         nlcan=0;
     end
     R(1:length(nccfd),iframe) = nccfd;
     Peaks(1:nlcan,iframe) = vipkd(:,1);
     Lags(1:nlcan,iframe) = vipkd(:,2);  
     % If there are any candidate lag values (nlcan>0) then refine their accuracy at the full sample rate
 
     if nlcan
         laglist=reshape(repmat(lagcan(:)',nfullag,1)+repmat((-hnfullag:hnfullag)',1,nlcan),nfullag*nlcan,1); 
         sfh=s(fho+(1:n+max(lagcan)+hnfullag));   % jump off first few ignored samples
         sfhdc=mean(sfh(sfhi));                   % s with windowed samples starts at fho
         sfh=sfh-sfhdc;
         e0=sum(sfh(sfhi).^2);                     % energy of initial correlation window (only needed to store in tv(:,6)
         lagl2=repmat(lagcan(:)',nfullag+n-1,1)+repmat((1-hnfullag:hnfullag+n)',1,nlcan);
         nccf=normxcor(sfh(1:n),sfh(lagl2),afact);
         
         
         [maxcc,maxcci]=max(nccf,[],1);
         vipk=[maxcc(:) lagcan(:)+maxcci(:)-hnfullag-1];
         vipk=vipk(:,[1 2 2]);
         maxccj=maxcci(:)'+nfullag*(0:nlcan-1);    % vector index into nccf array
         msk=mod(maxcci,nfullag-1)~=1 & 2*nccf(maxccj)-nccf(mod(maxccj-2,nfullag*nlcan)+1)-nccf(mod(maxccj,nfullag*nlcan)+1)>0;  % don't do quadratic interpolation for the end ones
         if any(msk)
             maxccj=maxccj(msk);
             vipk(msk,3)=vipk(msk,3)+(nccf(maxccj+1)-nccf(maxccj-1))'./(2*(2*nccf(maxccj)-nccf(maxccj-1)-nccf(maxccj+1)))';
         end
         vipk(maxcc<max(maxcc)*candtr,:)=[];          % eliminate peaks that are small
         if size(vipk,1)>ncands-1
             vipk=sortrows(vipk);
             vipk(1:size(vipk,1)-ncands+1,:)=[];   % eliminate lowest to leave only ncands-1
         end
         Result(iframe).vipk = vipk;
         % vipk(:,1) has NCCF value, vipk(:,2) has integer peak position, vipk(:,3) has refined peak position
 
         mc=size(vipk,1);  % number of refined peaks we have
     else
         mc=0;             % no peaks because nlcan = 0
     end

 
     % We now have mc lag candidates at the full sample rate

     mc1=mc+1;               % total number of candidates including "unvoiced" possibility
     mcands(iframe)=mc;      % save number of lag candidates (needed for pitch consistency cost calculation)
     if mc
         lagval(iframe,1:mc)=vipk(:,3)';
         cost(iframe,1)=vobias+max(vipk(:,1));   % voiceless cost
         cost(iframe,2:mc1)=1-vipk(:,1)'.*(1-beta*vipk(:,3)');   % local voiced costs
         tv(iframe,2)=min(cost(iframe,2:mc1));
     else
         cost(iframe,1)=vobias;          % if no lag candidates (mc=0), then the voiceless case is the only possibility
     end
     tv(iframe,1)=cost(iframe,1);
     if iframe>1                         % if it is not the first frame, then calculate pitch consistency and v/uv transition costs
         mcp=mcands(iframe-1);           % number of candidates in previous frame
         costm=zeros(mcp+1,mc1);         % cost matrix: rows and cols correspond to candidates in previous and current frames (incl voiceless)
 
         % if both frames have at least one lag candidate, then calculate a pitch consistency cost
         % voice to voice
         if mc*mcp
             lrat=abs(log(repmat(lagval(iframe,1:mc),mcp,1)./repmat(lagval(iframe-1,1:mcp)',1,mc)));
             costm(2:end,2:end)=freqwt*min(lrat,doublec+abs(lrat-log2));  % allow pitch doubling/halving
         end
 
         % if either frame has a lag candidate, then calculate the cost of voiced/voiceless transition and vice versa
         % voiced/voiceless
         if mc+mcp
             rr=sqrt((rmswin'*s(fho+rmsix).^2)/(rmswin'*s(fho+rmsix-kdrms).^2)); % amplitude "gradient"
             ss=0.2/(distitar(lpcauto(sp(fho+rmsix),lpcord),lpcauto(sp(fho+rmsix-kdrms),lpcord),'e')-0.8);   % Spectral stationarity: note: Talkin uses Hanning instead of Hamming windows for LPC
             costm(1,2:end)= vtranc+vtrsc*ss+vtrac/rr;   % voiceless -> voiced cost
             costm(2:end,1)= vtranc+vtrsc*ss+vtrac*rr;   % voiced -> voiceless cost
             tv(iframe,4:5)=[costm(1,mc1) costm(mcp+1,1)];
         end
         costm=costm+repmat(cost(iframe-1,1:mcp+1)',1,mc1);  % add in cumulative costs
         [costi,previ]=min(costm,[],1);
         cost(iframe,1:mc1)=cost(iframe,1:mc1)+costi;
         prev(iframe,1:mc1)=previ;
     else                            % first ever frame
         costm=zeros(1,mc1); % create a cost matrix in case doing a backward recursion
     end
     if mc
         tv(iframe,3)=cost(iframe,1)-min(cost(iframe,2:mc1));
         tv(iframe,6)=5*log10(e0*e0/afact);
     end
     costms{iframe}=costm; % need to add repmatted cost into this
end
 
best=zeros(nframe,1);
 [cbest,best(nframe)]=min(cost(nframe,1:mcands(nframe)+1));
 for i=nframe:-1:2
     best(i-1)=prev(i,best(i));
 end
 vix=find(best>1);
 fx=repmat(NaN,nframe,1);                        % unvoiced frames will be NaN
 fx(vix)=Fs*lagval(vix+nframe*(best(vix)-2)).^(-1); % leave as NaN if unvoiced
 tt=zeros(nframe,3);
 tt(:,1)=(1:nframe)'*z+spoff;       % find frame times
 tt(:,2)=tt(:,1)+z-1;
 jratm=(jumprat+1/jumprat)/2;
 tt(2:end,3)=abs(fx(2:end)./fx(1:end-1)-jratm)>jumprat-jratm;    % new spurt if frequency ratio is outside (1/jumprat,jumprat)
 tt(1,3)=1;           % first frame always starts a spurt
 tt(1+find(isnan(fx(1:end-1))),3)=1; % NaN always forces a new spurt         
  

%% Plot
figure
tf=spoff+(0:nframe-1)'*z;      % one sample before start of each frame
ts=(1:ns)/Fs;                       % time scale for speech samples
tsa=[1:tf(1) tf(end)+z+1:ns];  % indexes for unprocessed speech [-1 term is an error methinks]
sup=repmat(NaN,ns,1);               % unprocessed speech - plot in black
sup(tsa)=s(tsa);
sv=reshape(s(tf(1)+1:tf(end)+z),z,nframe);               % processed speech
su=sv;
su(:,best>1)=NaN;                   % delete all voiced samples
sv(:,best==1)=NaN;                  % delete all unvoiced samples
tsuv=(tf(1)+1:tf(end)+z)/Fs;
su=su(:);
sv=sv(:);
ax=zeros(2,1);
ax(1)=subplot(411);
plot(ts,sup,'-k',tsuv,su,'r-',tsuv,sv,'b-');
title('Speech');
ax(2)=subplot(412);
imagesc([0, ns],[Kmin+1*kdsmp,Kmax*kdsmp],R)
set(gca,'YDir','normal');
colormap(flipud(colormap('gray')))
colorbar('southoutside')
ax(3)=subplot(413);
plot((tf+(z+1)/2)/Fs,lagval*1000/Fs,'xr')
xlabel('Time (s)');
ylabel('Period (ms)');
title('Lag Candidates');
ax(4)=subplot(414);
plot((tf+(z+1)/2)/Fs,fx,'-b')
xlabel('Time (s)');
ylabel('Frequency (Hz)');
title('Pitch');
end
