START_DIR = C:\bh\users_EV\sandpit\BH_CAR~1\devel\TASK_C~3

MATLAB_ROOT = C:\MATLAB\R2017b
MAKEFILE = bh_my_detect_ALGORITHM_for_codegen_mex_mex.mk

include bh_my_detect_ALGORITHM_for_codegen_mex_mex.mki


SRC_FILES =  \
	bh_my_detect_ALGORITHM_for_codegen_mex_mexutil.c \
	bh_my_detect_ALGORITHM_for_codegen_mex_data.c \
	bh_my_detect_ALGORITHM_for_codegen_mex_initialize.c \
	bh_my_detect_ALGORITHM_for_codegen_mex_terminate.c \
	bh_my_detect_ALGORITHM_for_codegen.c \
	bh_my_lane_preprocess_mask.c \
	bh_my_track_ALGORITHM_for_codegen.c \
	ybp_finder_CLS.c \
	eml_int_forloop_overflow_check.c \
	assertValidSizeArg.c \
	warning.c \
	linearizeSRGB.c \
	power.c \
	error.c \
	XYZToLAB.c \
	scalexpAlloc.c \
	sqrt.c \
	indexShapeCheck.c \
	bh_mask_fraction_of_BW_image.c \
	regionprops.c \
	bwconncomp.c \
	sum.c \
	combineVectorElements.c \
	ind2sub.c \
	mean.c \
	mod.c \
	sort1.c \
	sortIdx.c \
	find.c \
	lane_info_CLS.c \
	bh_line_homog_CLS.c \
	eig.c \
	xzggev.c \
	xzlascl.c \
	xzggbal.c \
	xzgeqr2.c \
	xnrm2.c \
	xdlapy3.c \
	recip.c \
	xzlartg.c \
	xzhgeqz.c \
	xzlanhs.c \
	xztgevc.c \
	xzggbak.c \
	diag.c \
	error1.c \
	box_info_CLS.c \
	my_laneKF_CLS.c \
	my_KF_general_CLS.c \
	_coder_bh_my_detect_ALGORITHM_for_codegen_mex_info.c \
	_coder_bh_my_detect_ALGORITHM_for_codegen_mex_api.c \
	_coder_bh_my_detect_ALGORITHM_for_codegen_mex_mex.c \
	bh_my_detect_ALGORITHM_for_codegen_mex_emxutil.c \
	c_mexapi_version.c

MEX_FILE_NAME_WO_EXT = bh_my_detect_ALGORITHM_for_codegen_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
TARGET = $(MEX_FILE_NAME)

BlockModules_LIBS = "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwbwlookup_tbb.lib" "$(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwippreconstruct.lib" 
SYS_LIBS = $(BlockModules_LIBS) libmwblas.lib 


#
#====================================================================
# gmake makefile fragment for building MEX functions using MSVC
# Copyright 2007-2016 The MathWorks, Inc.
#====================================================================
#
SHELL = cmd
OBJEXT = obj
CC = $(COMPILER)
LD = $(LINKER)
.SUFFIXES: .$(OBJEXT)

OBJLISTC = $(SRC_FILES:.c=.$(OBJEXT))
OBJLIST  = $(OBJLISTC:.cpp=.$(OBJEXT))

TARGETMT = $(TARGET).manifest
MEX = $(TARGETMT)
STRICTFP = /fp:strict

target: $(MEX)

MATLAB_INCLUDES = /I "$(MATLAB_ROOT)\simulink\include"
MATLAB_INCLUDES+= /I "$(MATLAB_ROOT)\toolbox\shared\simtargets"
SYS_INCLUDE = $(MATLAB_INCLUDES)

# Additional includes

SYS_INCLUDE += /I "$(START_DIR)\codegen\mex\bh_my_detect_ALGORITHM_for_codegen_mex"
SYS_INCLUDE += /I "$(START_DIR)"
SYS_INCLUDE += /I ".\interface"
SYS_INCLUDE += /I "$(MATLAB_ROOT)\extern\include"
SYS_INCLUDE += /I "."

DIRECTIVES = $(MEX_FILE_NAME_WO_EXT)_mex.arf
COMP_FLAGS = $(COMPFLAGS) $(OMPFLAGS)
LINK_FLAGS = $(filter-out /export:mexFunction, $(LINKFLAGS))
LINK_FLAGS += /NODEFAULTLIB:LIBCMT
ifeq ($(EMC_CONFIG),optim)
  COMP_FLAGS += $(OPTIMFLAGS) $(STRICTFP)
  LINK_FLAGS += $(LINKOPTIMFLAGS)
else
  COMP_FLAGS += $(DEBUGFLAGS)
  LINK_FLAGS += $(LINKDEBUGFLAGS)
endif
LINK_FLAGS += $(OMPLINKFLAGS)
LINK_FLAGS += /OUT:$(TARGET)
LINK_FLAGS +=  /LIBPATH:"$(MATLAB_ROOT)\extern\lib\win64\microsoft"

CFLAGS = $(COMP_FLAGS)   $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS = $(COMP_FLAGS)   $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CC) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : $(START_DIR)/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\mex\bh_my_detect_ALGORITHM_for_codegen_mex/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) $(CFLAGS) "$<"



%.$(OBJEXT) : $(START_DIR)/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\mex\bh_my_detect_ALGORITHM_for_codegen_mex/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : interface/%.cpp
	$(CC) $(CPPFLAGS) "$<"



$(TARGET): $(OBJLIST) $(MAKEFILE) $(DIRECTIVES)
	$(LD) $(LINK_FLAGS) $(OBJLIST) $(USER_LIBS) $(SYS_LIBS) @$(DIRECTIVES)
	@cmd /C "echo Build completed using compiler $(EMC_COMPILER)"

$(TARGETMT): $(TARGET)
	mt -outputresource:"$(TARGET);2" -manifest "$(TARGET).manifest"

#====================================================================

