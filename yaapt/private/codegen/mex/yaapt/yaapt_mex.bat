@echo off
set MATLAB=F:\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="F:\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=yaapt_mex
set MEX_NAME=yaapt_mex
set MEX_EXT=.mexw64
call setEnv.bat
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
echo OMPFLAGS=/openmp >> yaapt_mex.mki
echo OMPLINKFLAGS=/nodefaultlib:vcomp /LIBPATH:"F:\MATLAB\R2016a\bin\win64" >> yaapt_mex.mki
echo EMC_COMPILER=msvc140>> yaapt_mex.mki
echo EMC_CONFIG=optim>> yaapt_mex.mki
"F:\MATLAB\R2016a\bin\win64\gmake" -B -f yaapt_mex.mk
