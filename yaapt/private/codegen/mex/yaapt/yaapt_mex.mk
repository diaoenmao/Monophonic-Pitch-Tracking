START_DIR = D:\GitHub\MONOPH~1\yaapt\private

MATLAB_ROOT = F:\MATLAB\R2016a
MAKEFILE = yaapt_mex.mk

include yaapt_mex.mki


SRC_FILES =  \
	yaapt_mexutil.c \
	yaapt_data.c \
	yaapt_initialize.c \
	yaapt_terminate.c \
	yaapt.c \
	nonlinear.c \
	mrdivide.c \
	rdivide.c \
	Myfir1.c \
	error.c \
	colon.c \
	eml_int_forloop_overflow_check.c \
	abs.c \
	scalexpAlloc.c \
	Myhamming.c \
	cos.c \
	any.c \
	isequal.c \
	diff.c \
	Myfirls.c \
	sqrt.c \
	error1.c \
	indexShapeCheck.c \
	mpower.c \
	sinc.c \
	mldivide.c \
	xgetrf.c \
	repmat.c \
	assertValidSizeArg.c \
	warning.c \
	qrsolve.c \
	xgeqp3.c \
	mean.c \
	combine_vector_elements.c \
	exp.c \
	filter.c \
	fix.c \
	nlfer.c \
	Myspecgram.c \
	Myhanning.c \
	fft.c \
	sum.c \
	spec_trk.c \
	mod.c \
	Mykaiser.c \
	Mybesseli.c \
	prod.c \
	peaks.c \
	sort1.c \
	sortIdx.c \
	std.c \
	Mymedfilt1.c \
	median.c \
	dynamic5.c \
	path1.c \
	tm_trk.c \
	crs_corr.c \
	cmp_rate.c \
	refine.c \
	cat.c \
	freqSelect.c \
	fq2cnt.c \
	Smooth2.c \
	all.c \
	_coder_yaapt_info.c \
	_coder_yaapt_api.c \
	_coder_yaapt_mex.c \
	yaapt_emxutil.c

MEX_FILE_NAME_WO_EXT = yaapt_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
TARGET = $(MEX_FILE_NAME)

SYS_LIBS = libmwblas.lib libmwlapack.lib 


#
#====================================================================
# gmake makefile fragment for building MEX functions using MSVC
# Copyright 2007-2015 The MathWorks, Inc.
#====================================================================
#
SHELL = cmd
OBJEXT = obj
CC = $(COMPILER)
LD = $(LINKER)
.SUFFIXES: .$(OBJEXT)

OBJLISTC = $(SRC_FILES:.c=.$(OBJEXT))
OBJLIST  = $(OBJLISTC:.cpp=.$(OBJEXT))

ifneq (,$(findstring $(EMC_COMPILER),msvc80 msvc90 msvc100 msvc100free msvc110 msvc120 msvc140 msvcsdk))
  TARGETMT = $(TARGET).manifest
  MEX = $(TARGETMT)
  STRICTFP = /fp:strict
else
  MEX = $(TARGET)
  STRICTFP = /Op
endif

target: $(MEX)

MATLAB_INCLUDES = /I "$(MATLAB_ROOT)\simulink\include"
MATLAB_INCLUDES+= /I "$(MATLAB_ROOT)\toolbox\shared\simtargets"
SYS_INCLUDE = $(MATLAB_INCLUDES)

# Additional includes

SYS_INCLUDE += /I "$(START_DIR)"
SYS_INCLUDE += /I "$(START_DIR)\codegen\mex\yaapt"
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

CFLAGS =  -DHAVE_LAPACK_CONFIG_H -DLAPACK_COMPLEX_STRUCTURE -DMW_HAVE_LAPACK_DECLS $(COMP_FLAGS) $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS =  $(CFLAGS)

%.$(OBJEXT) : %.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CC) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : $(START_DIR)/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\mex\yaapt/%.c
	$(CC) $(CFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) $(CFLAGS) "$<"



%.$(OBJEXT) : $(START_DIR)/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\mex\yaapt/%.cpp
	$(CC) $(CPPFLAGS) "$<"

%.$(OBJEXT) : interface/%.cpp
	$(CC) $(CPPFLAGS) "$<"



$(TARGET): $(OBJLIST) $(MAKEFILE) $(DIRECTIVES)
	$(LD) $(LINK_FLAGS) $(OBJLIST) $(USER_LIBS) $(SYS_LIBS) @$(DIRECTIVES)
	@cmd /C "echo Build completed using compiler $(EMC_COMPILER)"

$(TARGETMT): $(TARGET)
	mt -outputresource:"$(TARGET);2" -manifest "$(TARGET).manifest"

#====================================================================

