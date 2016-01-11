START_DIR = D:\GitHub\MONOPH~1\yaapt\private

MATLAB_ROOT = F:\MATLAB~2
MAKEFILE = yaapt_mex.mk

include yaapt_mex.mki


SRC_FILES =  \
	yaapt_mexutil.c \
	yaapt_data.c \
	yaapt_initialize.c \
	yaapt_terminate.c \
	yaapt.c \
	nonlinear.c \
	rdivide.c \
	error.c \
	eml_int_forloop_overflow_check.c \
	abs.c \
	scalexpAlloc.c \
	any.c \
	isequal.c \
	diff.c \
	Myfirls.c \
	sqrt.c \
	error1.c \
	mpower.c \
	cos.c \
	sinc.c \
	indexShapeCheck.c \
	mldivide.c \
	lusolve.c \
	xgetrf.c \
	repmat.c \
	assertValidSizeArg.c \
	warning.c \
	xtrsm.c \
	mean.c \
	combine_vector_elements.c \
	exp.c \
	filter.c \
	xaxpy.c \
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
	all.c \
	prod.c \
	peaks.c \
	sort1.c \
	sortIdx.c \
	std.c \
	Mymedfilt1.c \
	median.c \
	dynamic5.c \
	interp1.c \
	pchip.c \
	tm_trk.c \
	crs_corr.c \
	cmp_rate.c \
	qrsolve.c \
	xgeqp3.c \
	refine.c \
	cat.c \
	dynamic.c \
	_coder_yaapt_info.c \
	_coder_yaapt_api.c \
	_coder_yaapt_mex.c \
	yaapt_emxutil.c

MEX_FILE_NAME_WO_EXT = yaapt_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
TARGET = $(MEX_FILE_NAME)

SYS_LIBS = libmwlapack.lib 


#
#====================================================================
# gmake makefile fragment for building MEX functions using LCC
# Copyright 2007-2012 The MathWorks, Inc.
#====================================================================
#
SHELL = cmd
OBJEXT = obj
CC = $(COMPILER)
LD = $(LINKER)
.SUFFIXES: .$(OBJEXT)

OBJLIST += $(SRC_FILES:.c=.$(OBJEXT))
MEXSTUB = $(MEX_FILE_NAME_WO_EXT)2.$(OBJEXT)
LCCSTUB = $(MEX_FILE_NAME_WO_EXT)_lccstub.$(OBJEXT)

target: $(TARGET)

ML_INCLUDES = -I"$(MATLAB_ROOT)\simulink\include"
ML_INCLUDES+= -I"$(MATLAB_ROOT)\toolbox\shared\simtargets"
SYS_INCLUDE = $(ML_INCLUDES)

LCC_ROOT = $(MATLAB_ROOT)\sys\lcc64\lcc64

# Additional includes

SYS_INCLUDE += -I"$(START_DIR)"
SYS_INCLUDE += -I"$(START_DIR)\codegen\mex\yaapt"
SYS_INCLUDE += -I".\interface"
SYS_INCLUDE += -I"$(MATLAB_ROOT)\extern\include"
SYS_INCLUDE += -I"."

EML_LIBS = libemlrt.lib libcovrt.lib libut.lib libmwblas.lib libmwmathutil.lib
SYS_LIBS += $(EML_LIBS)

DIRECTIVES = $(MEX_FILE_NAME_WO_EXT)_mex.def

COMP_FLAGS = $(COMPFLAGS) -DMX_COMPAT_32
LINK_FLAGS0= $(subst $(MEXSTUB),$(LCCSTUB),$(LINKFLAGS))
LINK_FLAGS = $(filter-out "mexFunction.def", $(LINK_FLAGS0))


ifeq ($(EMC_CONFIG),optim)
  COMP_FLAGS += $(OPTIMFLAGS)
  LINK_FLAGS += $(LINKOPTIMFLAGS)
else
  COMP_FLAGS += $(DEBUGFLAGS)
  LINK_FLAGS += $(LINKDEBUGFLAGS)
endif
LINK_FLAGS += -o $(TARGET)
LINK_FLAGS +=  -L"$(MATLAB_ROOT)\extern\lib\win64\microsoft"

CFLAGS =  -DHAVE_LAPACK_CONFIG_H -DLAPACK_COMPLEX_STRUCTURE -DMW_HAVE_LAPACK_DECLS $(COMP_FLAGS) $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : $(START_DIR)/%.c
	$(CC) -Fo"$@" $(CFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\mex\yaapt/%.c
	$(CC) -Fo"$@" $(CFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) -Fo"$@" $(CFLAGS) "$<"



$(LCCSTUB) : $(LCC_ROOT)\mex\lccstub.c
	$(CC) -Fo$(LCCSTUB) $(CFLAGS) "$<"

$(TARGET): $(OBJLIST) $(LCCSTUB) $(MAKEFILE) $(DIRECTIVES)
	$(LD) $(OBJLIST) $(LINK_FLAGS) $(LINKFLAGSPOST) $(SYS_LIBS) $(DIRECTIVES)
	@cmd /C "echo Build completed using compiler $(EMC_COMPILER)"

#====================================================================

