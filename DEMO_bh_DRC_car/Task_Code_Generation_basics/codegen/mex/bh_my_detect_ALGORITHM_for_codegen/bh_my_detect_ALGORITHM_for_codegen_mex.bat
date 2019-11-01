@echo off
set MATLAB=C:\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=bh_my_detect_ALGORITHM_for_codegen_mex
set MEX_NAME=bh_my_detect_ALGORITHM_for_codegen_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for bh_my_detect_ALGORITHM_for_codegen > bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo COMPILER=%COMPILER%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo LINKER=%LINKER%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo OMPFLAGS= >> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo OMPLINKFLAGS= >> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo EMC_COMPILER=msvc120>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
echo EMC_CONFIG=optim>> bh_my_detect_ALGORITHM_for_codegen_mex.mki
"C:\MATLAB\R2017b\bin\win64\gmake" -B -f bh_my_detect_ALGORITHM_for_codegen_mex.mk
