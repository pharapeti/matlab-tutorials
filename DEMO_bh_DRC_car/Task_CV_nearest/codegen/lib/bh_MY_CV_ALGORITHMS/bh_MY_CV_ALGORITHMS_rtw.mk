###########################################################################
## Makefile generated for MATLAB file/project 'bh_MY_CV_ALGORITHMS'. 
## 
## Makefile     : bh_MY_CV_ALGORITHMS_rtw.mk
## Generated on : Tue Jan 23 10:19:20 2018
## MATLAB Coder version: 3.4 (R2017b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)\bh_MY_CV_ALGORITHMS.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.
# GEN_LINKER_RESPONSE     Command to generate a linker response file 
# CMD_FILE                Command file

PRODUCT_NAME              = bh_MY_CV_ALGORITHMS
MAKEFILE                  = bh_MY_CV_ALGORITHMS_rtw.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:\MATLAB\R2017b
MATLAB_BIN                = C:\MATLAB\R2017b\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:\bh\users_EV\sandpit\bh_car_models\devel\Task_CV_nearest
ARCH                      = win64
RELATIVE_PATH_TO_ANCHOR   = .
GEN_LINKER_RESPONSE       = $(MATLAB_ARCH_BIN)\createResponseFile.exe 1 
CMD_FILE                  = $(PRODUCT_NAME).rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2013 v12.0 | nmake (64-bit Windows)
# Supported Version(s):    12.0
# ToolchainInfo Version:   R2017b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MEX_OPTS_FILE       = $(MATLAB_ROOT)\bin\$(ARCH)\mexopts\msvc2013.xml
MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
MEX_ARCH            = -win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /Od /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /Od /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           = $(MEX_ARCH) OPTIMFLAGS="/Od /Oy- $(MDFLAG) $(DEFINES)" $(MEX_OPTS_FLAG)
MEX_LDFLAGS          = LDFLAGS=='$$LDFLAGS'
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .obj
C_EXT               = .c
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
HPP_EXT             = .hpp
OBJ_EXT             = .obj
CPP_EXT             = .cpp
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)\bh_MY_CV_ALGORITHMS.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS;$(START_DIR);$(MATLAB_ROOT)\extern\include;$(MATLAB_ROOT)\simulink\include;$(MATLAB_ROOT)\rtw\c\src;$(MATLAB_ROOT)\rtw\c\src\ext_mode\common;$(MATLAB_ROOT)\rtw\c\ert

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_STANDARD = -DMODEL=bh_MY_CV_ALGORITHMS -DHAVESTDIO -DUSE_RTMODEL

DEFINES = $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_MY_CV_ALGORITHMS_rtwutil.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_MY_CV_ALGORITHMS_initialize.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_MY_CV_ALGORITHMS_terminate.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_my_detect_ALGORITHM_for_codegen.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_my_lane_preprocess_mask.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_my_track_ALGORITHM_for_codegen.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\ybp_finder_CLS.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\abs.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\linearizeSRGB.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\power.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\XYZToLAB.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\sqrt.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_mask_fraction_of_BW_image.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\regionprops.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bwconncomp.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\sum.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\combineVectorElements.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\mod.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\sort1.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\sortIdx.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\lane_info_CLS.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_line_homog_CLS.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\eig.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xzggev.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xzlascl.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xzgeqr2.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xnrm2.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xdlapy3.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\recip.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xzgghrd.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xzlartg.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xzhgeqz.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xzlanhs.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xztgevc.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\xzggbak.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\diag.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\box_info_CLS.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\my_laneKF_CLS.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\my_KF_general_CLS.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_MY_CV_ALGORITHMS_emxutil.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\bh_MY_CV_ALGORITHMS_emxAPI.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\rt_nonfinite.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\rtGetNaN.c $(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS\rtGetInf.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = bh_MY_CV_ALGORITHMS_rtwutil.obj bh_MY_CV_ALGORITHMS_initialize.obj bh_MY_CV_ALGORITHMS_terminate.obj bh_my_detect_ALGORITHM_for_codegen.obj bh_my_lane_preprocess_mask.obj bh_my_track_ALGORITHM_for_codegen.obj ybp_finder_CLS.obj abs.obj linearizeSRGB.obj power.obj XYZToLAB.obj sqrt.obj bh_mask_fraction_of_BW_image.obj regionprops.obj bwconncomp.obj sum.obj combineVectorElements.obj mod.obj sort1.obj sortIdx.obj lane_info_CLS.obj bh_line_homog_CLS.obj eig.obj xzggev.obj xzlascl.obj xzgeqr2.obj xnrm2.obj xdlapy3.obj recip.obj xzgghrd.obj xzlartg.obj xzhgeqz.obj xzlanhs.obj xztgevc.obj xzggbak.obj diag.obj box_info_CLS.obj my_laneKF_CLS.obj my_KF_general_CLS.obj bh_MY_CV_ALGORITHMS_emxutil.obj bh_MY_CV_ALGORITHMS_emxAPI.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwbwlookup_tbb.lib $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwippreconstruct.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) 

CFLAGS = $(CFLAGS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) 

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


prebuild : 


download : build


execute : download


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	$(GEN_LINKER_RESPONSE) $(CMD_FILE) $(OBJS)
	@cmd /C "@echo ### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) -out:$(PRODUCT) @$(CMD_FILE)
	@cmd /C "@echo ### Created: $(PRODUCT)"
	$(RM) $(CMD_FILE)


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\lib\bh_MY_CV_ALGORITHMS}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


