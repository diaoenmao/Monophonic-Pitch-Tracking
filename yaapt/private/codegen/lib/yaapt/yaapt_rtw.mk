###########################################################################
## Makefile generated for MATLAB file/project 'yaapt'. 
## 
## Makefile     : yaapt_rtw.mk
## Generated on : Tue Jan 12 01:26:01 2016
## MATLAB Coder version: 3.0 (R2015b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/yaapt.lib
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
# PERL                    PERL Tool
# GEN_LNK_SCRIPT          Perl script to generate the command file
# CMD_FILE                Command file

PRODUCT_NAME              = yaapt
MAKEFILE                  = yaapt_rtw.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = F:/MATLAB~2
MATLAB_BIN                = F:/MATLAB~2/bin
MATLAB_ARCH_BIN           = F:/MATLAB~2/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = D:/GitHub/Monophonic-Pitch-Tracking/yaapt/private
ARCH                      = win64
RELATIVE_PATH_TO_ANCHOR   = .
PERL                      = $(MATLAB_ROOT)/sys/perl/win32/bin/perl.exe
GEN_LNK_SCRIPT            = $(MATLAB_ROOT)/rtw/c/tools/mkvc_lnk.pl
CMD_FILE                  = $(PRODUCT_NAME).lnk

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   R2015b
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

SHELL              = cmd
LCC_ROOT           = $(MATLAB_ROOT)/sys/lcc64/lcc64
LCC_BUILDLIB       = $(LCC_ROOT)/bin/buildlib
LCC_LIB            = $(LCC_ROOT)/lib64
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/microsoft
MW_LIB_DIR         = $(MATLAB_ROOT)/lib/win64
TOOLCHAIN_INCLUDES = -I$(LCC_ROOT)/include64
MEX_OPTS_FILE      = $(MATLAB_ROOT/rtw/c/tools/lcc-win64.xml

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Lcc-win64 C Compiler
CC_PATH = $(LCC_ROOT)/bin
CC = $(CC_PATH)/lcc64

# Linker: Lcc-win64 Linker
LD_PATH = $(LCC_ROOT)/bin
LD = $(LD_PATH)/lcclnk64

# Archiver: Lcc-win64 Archiver
AR_PATH = $(LCC_ROOT)/bin
AR = $(AR_PATH)/lcclib64

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -Fo
LDDEBUG             =
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = /out:
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              =
CFLAGS               = -c -w -noregistrylookup -nodeclspec -I$(LCC_ROOT)/include64
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL)
MEX_CFLAGS           = -win64 $(MEX_SRC) $(MEX_OPT_FILE)$(INCLUDES) -outdir $(RELATIVE_PATH_TO_ANCHOR)
MEX_LDFLAGS          = LINKFLAGS="$$LINKFLAGS $(LDFLAGS_ADDITIONAL)"
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dll -entry LibMain -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) $(DEF_FILE)

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .obj
C_EXT               = .c
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/yaapt.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/codegen/lib/yaapt -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_STANDARD = -DMODEL=yaapt -DHAVESTDIO -DUSE_RTMODEL

DEFINES = $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/yaapt/yaapt_rtwutil.c $(START_DIR)/codegen/lib/yaapt/yaapt_initialize.c $(START_DIR)/codegen/lib/yaapt/yaapt_terminate.c $(START_DIR)/codegen/lib/yaapt/yaapt.c $(START_DIR)/codegen/lib/yaapt/nonlinear.c $(START_DIR)/codegen/lib/yaapt/rdivide.c $(START_DIR)/codegen/lib/yaapt/abs.c $(START_DIR)/codegen/lib/yaapt/any.c $(START_DIR)/codegen/lib/yaapt/Myfirls.c $(START_DIR)/codegen/lib/yaapt/sqrt.c $(START_DIR)/codegen/lib/yaapt/cos.c $(START_DIR)/codegen/lib/yaapt/sinc.c $(START_DIR)/codegen/lib/yaapt/sin.c $(START_DIR)/codegen/lib/yaapt/mldivide.c $(START_DIR)/codegen/lib/yaapt/xgetrf.c $(START_DIR)/codegen/lib/yaapt/xswap.c $(START_DIR)/codegen/lib/yaapt/xtrsm.c $(START_DIR)/codegen/lib/yaapt/mean.c $(START_DIR)/codegen/lib/yaapt/exp.c $(START_DIR)/codegen/lib/yaapt/filter.c $(START_DIR)/codegen/lib/yaapt/fix.c $(START_DIR)/codegen/lib/yaapt/Myspecgram.c $(START_DIR)/codegen/lib/yaapt/Myhanning.c $(START_DIR)/codegen/lib/yaapt/fft.c $(START_DIR)/codegen/lib/yaapt/sum.c $(START_DIR)/codegen/lib/yaapt/spec_trk.c $(START_DIR)/codegen/lib/yaapt/mod.c $(START_DIR)/codegen/lib/yaapt/Mykaiser.c $(START_DIR)/codegen/lib/yaapt/Mybesseli.c $(START_DIR)/codegen/lib/yaapt/repmat.c $(START_DIR)/codegen/lib/yaapt/all.c $(START_DIR)/codegen/lib/yaapt/prod.c $(START_DIR)/codegen/lib/yaapt/peaks.c $(START_DIR)/codegen/lib/yaapt/sort1.c $(START_DIR)/codegen/lib/yaapt/sortIdx.c $(START_DIR)/codegen/lib/yaapt/std.c $(START_DIR)/codegen/lib/yaapt/Mymedfilt1.c $(START_DIR)/codegen/lib/yaapt/median.c $(START_DIR)/codegen/lib/yaapt/dynamic5.c $(START_DIR)/codegen/lib/yaapt/interp1.c $(START_DIR)/codegen/lib/yaapt/pchip.c $(START_DIR)/codegen/lib/yaapt/tm_trk.c $(START_DIR)/codegen/lib/yaapt/cmp_rate.c $(START_DIR)/codegen/lib/yaapt/cat.c $(START_DIR)/codegen/lib/yaapt/dynamic.c $(START_DIR)/codegen/lib/yaapt/yaapt_emxutil.c $(START_DIR)/codegen/lib/yaapt/yaapt_emxAPI.c $(START_DIR)/codegen/lib/yaapt/rt_nonfinite.c $(START_DIR)/codegen/lib/yaapt/rtGetNaN.c $(START_DIR)/codegen/lib/yaapt/rtGetInf.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = yaapt_rtwutil.obj yaapt_initialize.obj yaapt_terminate.obj yaapt.obj nonlinear.obj rdivide.obj abs.obj any.obj Myfirls.obj sqrt.obj cos.obj sinc.obj sin.obj mldivide.obj xgetrf.obj xswap.obj xtrsm.obj mean.obj exp.obj filter.obj fix.obj Myspecgram.obj Myhanning.obj fft.obj sum.obj spec_trk.obj mod.obj Mykaiser.obj Mybesseli.obj repmat.obj all.obj prod.obj peaks.obj sort1.obj sortIdx.obj std.obj Mymedfilt1.obj median.obj dynamic5.obj interp1.obj pchip.obj tm_trk.obj cmp_rate.obj cat.obj dynamic.obj yaapt_emxutil.obj yaapt_emxAPI.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

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

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : build


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(subst /,\,$(OBJS))
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) /out:$(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"
	$(RM) $(CMD_FILE)


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/codegen/lib/yaapt/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


