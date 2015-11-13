@echo off
set MATLAB=F:\MATLAB
set MATLAB_ARCH=win64
set MATLAB_BIN="F:\MATLAB\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=Add_sil
set MEX_NAME=Add_sil
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for Add_sil > Add_sil_mex.mki
echo COMPILER=%COMPILER%>> Add_sil_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> Add_sil_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> Add_sil_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> Add_sil_mex.mki
echo LINKER=%LINKER%>> Add_sil_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> Add_sil_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> Add_sil_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> Add_sil_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> Add_sil_mex.mki
echo BORLAND=%BORLAND%>> Add_sil_mex.mki
echo OMPFLAGS= >> Add_sil_mex.mki
echo OMPLINKFLAGS= >> Add_sil_mex.mki
echo EMC_COMPILER=msvc120>> Add_sil_mex.mki
echo EMC_CONFIG=optim>> Add_sil_mex.mki
"F:\MATLAB\bin\win64\gmake" -B -f Add_sil_mex.mk
