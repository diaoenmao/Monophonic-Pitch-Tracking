@echo off
set MATLAB=F:\MATLAB~2
set MATLAB_ARCH=win64
set MATLAB_BIN="F:\Matlab2015b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=yaapt_mex
set MEX_NAME=yaapt_mex
set MEX_EXT=.mexw64
call "F:\MATLAB~2\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for yaapt > yaapt_mex.mki
echo COMPILER=%COMPILER%>> yaapt_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> yaapt_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> yaapt_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> yaapt_mex.mki
echo LINKER=%LINKER%>> yaapt_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> yaapt_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> yaapt_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> yaapt_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> yaapt_mex.mki
echo BORLAND=%BORLAND%>> yaapt_mex.mki
echo OMPFLAGS= >> yaapt_mex.mki
echo OMPLINKFLAGS= >> yaapt_mex.mki
echo EMC_COMPILER=lcc64>> yaapt_mex.mki
echo EMC_CONFIG=optim>> yaapt_mex.mki
"F:\Matlab2015b\bin\win64\gmake" -B -f yaapt_mex.mk
