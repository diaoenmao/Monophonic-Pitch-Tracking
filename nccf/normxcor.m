 function v=normxcor(x,y,d)
 % Calculate the normalized cross correlation of column vectors x and y
 % we can calculate this in two ways but fft is much faster even for nx small
 % We must have nx<=ny and the output length is ny-nx+1
 % note that this routine does not do mean subtraction even though this is normally a good idea
 % if y is a matrix, we correlate with each column
 % d is a constant added onto the normalization factor
 % v(j)=x'*yj/sqrt(d + x'*x * yj'*yj) where yj=y(j:j+nx-1) for j=1:ny-nx+1
 
 if nargin<3
     d=0;
 end
 nx=length(x);
 [ny,my]=size(y);
 nv=1+ny-nx;
 if nx>ny
     error('second argument is shorter than the first');
 end
 
 nf=pow2(nextpow2(ny));
 w=irfft(repmat(conj(rfft(x,nf,1)),1,my).*rfft(y,nf,1));
 s=zeros(ny+1,my);
 s(2:end,:)=cumsum(y.^2,1);
 v=w(1:nv,:)./sqrt(d+(x'*x).*(s(nx+1:end,:)-s(1:end-nx,:)));