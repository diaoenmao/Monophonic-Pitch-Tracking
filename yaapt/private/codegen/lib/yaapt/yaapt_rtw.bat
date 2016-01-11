@echo off

set MATLAB=F:\Matlab2015b

cd .

if "%1"=="" (F:\MATLAB~2\bin\win64\gmake -f yaapt_rtw.mk all) else (F:\MATLAB~2\bin\win64\gmake -f yaapt_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
