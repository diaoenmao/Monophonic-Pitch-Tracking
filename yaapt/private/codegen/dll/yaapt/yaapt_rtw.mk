###########################################################################
## Makefile generated for MATLAB file/project 'yaapt'. 
## 
## Makefile     : yaapt_rtw.mk
## Generated on : Sun Nov 15 00:16:21 2015
## MATLAB Coder version: 3.0 (R2015b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)\yaapt.dll
## Product type : dynamic-library
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
# DEF_FILE                Definition file

PRODUCT_NAME              = yaapt
MAKEFILE                  = yaapt_rtw.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = F:\MATLAB
MATLAB_BIN                = F:\MATLAB\bin
MATLAB_ARCH_BIN           = F:\MATLAB\bin\win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = D:\GitHub\Monophonic-Pitch-Tracking\yaapt\private
ARCH                      = win64
RELATIVE_PATH_TO_ANCHOR   = .
PERL                      = $(MATLAB_ROOT)\sys\perl\win32\bin\perl.exe
GEN_LNK_SCRIPT            = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl
CMD_FILE                  = $(PRODUCT_NAME).lnk
DEF_FILE                  = $(PRODUCT_NAME).def
NODEBUG                   = 1

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2013 v12.0 | nmake (64-bit Windows)
# Supported Version(s):    12.0
# ToolchainInfo Version:   R2015b
# Specification Revision:  1.0
# 

!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


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
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)\mex

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

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)\yaapt.dll
PRODUCT_TYPE = "dynamic-library"
BUILD_TYPE = "Dynamic Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = $(START_DIR);$(START_DIR)\codegen\dll\yaapt;$(MATLAB_ROOT)\extern\include;$(MATLAB_ROOT)\simulink\include;$(MATLAB_ROOT)\rtw\c\src;$(MATLAB_ROOT)\rtw\c\src\ext_mode\common;$(MATLAB_ROOT)\rtw\c\ert

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_STANDARD = -DMODEL=yaapt -DHAVESTDIO -DUSE_RTMODEL

DEFINES = $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\codegen\dll\yaapt\yaapt_rtwutil.c $(START_DIR)\codegen\dll\yaapt\yaapt_data.c $(START_DIR)\codegen\dll\yaapt\yaapt_initialize.c $(START_DIR)\codegen\dll\yaapt\yaapt_terminate.c $(START_DIR)\codegen\dll\yaapt\yaapt.c $(START_DIR)\codegen\dll\yaapt\nonlinear.c $(START_DIR)\codegen\dll\yaapt\rdivide.c $(START_DIR)\codegen\dll\yaapt\abs.c $(START_DIR)\codegen\dll\yaapt\any.c $(START_DIR)\codegen\dll\yaapt\Myfirls.c $(START_DIR)\codegen\dll\yaapt\sqrt.c $(START_DIR)\codegen\dll\yaapt\cos.c $(START_DIR)\codegen\dll\yaapt\sinc.c $(START_DIR)\codegen\dll\yaapt\sin.c $(START_DIR)\codegen\dll\yaapt\mldivide.c $(START_DIR)\codegen\dll\yaapt\xgetrf.c $(START_DIR)\codegen\dll\yaapt\xswap.c $(START_DIR)\codegen\dll\yaapt\xtrsm.c $(START_DIR)\codegen\dll\yaapt\mean.c $(START_DIR)\codegen\dll\yaapt\exp.c $(START_DIR)\codegen\dll\yaapt\filter.c $(START_DIR)\codegen\dll\yaapt\fix.c $(START_DIR)\codegen\dll\yaapt\Myspecgram.c $(START_DIR)\codegen\dll\yaapt\Myhanning.c $(START_DIR)\codegen\dll\yaapt\fft.c $(START_DIR)\codegen\dll\yaapt\sum.c $(START_DIR)\codegen\dll\yaapt\spec_trk.c $(START_DIR)\codegen\dll\yaapt\mod.c $(START_DIR)\codegen\dll\yaapt\Mykaiser.c $(START_DIR)\codegen\dll\yaapt\Mybesseli.c $(START_DIR)\codegen\dll\yaapt\repmat.c $(START_DIR)\codegen\dll\yaapt\all.c $(START_DIR)\codegen\dll\yaapt\prod.c $(START_DIR)\codegen\dll\yaapt\peaks.c $(START_DIR)\codegen\dll\yaapt\sort1.c $(START_DIR)\codegen\dll\yaapt\sortIdx.c $(START_DIR)\codegen\dll\yaapt\std.c $(START_DIR)\codegen\dll\yaapt\Mymedfilt1.c $(START_DIR)\codegen\dll\yaapt\median.c $(START_DIR)\codegen\dll\yaapt\dynamic5.c $(START_DIR)\codegen\dll\yaapt\interp1.c $(START_DIR)\codegen\dll\yaapt\pchip.c $(START_DIR)\codegen\dll\yaapt\tm_trk.c $(START_DIR)\codegen\dll\yaapt\cmp_rate.c $(START_DIR)\codegen\dll\yaapt\cat.c $(START_DIR)\codegen\dll\yaapt\dynamic.c $(START_DIR)\codegen\dll\yaapt\yaapt_emxutil.c $(START_DIR)\codegen\dll\yaapt\yaapt_emxAPI.c $(START_DIR)\codegen\dll\yaapt\rt_nonfinite.c $(START_DIR)\codegen\dll\yaapt\rtGetNaN.c $(START_DIR)\codegen\dll\yaapt\rtGetInf.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = yaapt_rtwutil.obj yaapt_data.obj yaapt_initialize.obj yaapt_terminate.obj yaapt.obj nonlinear.obj rdivide.obj abs.obj any.obj Myfirls.obj sqrt.obj cos.obj sinc.obj sin.obj mldivide.obj xgetrf.obj xswap.obj xtrsm.obj mean.obj exp.obj filter.obj fix.obj Myspecgram.obj Myhanning.obj fft.obj sum.obj spec_trk.obj mod.obj Mykaiser.obj Mybesseli.obj repmat.obj all.obj prod.obj peaks.obj sort1.obj sortIdx.obj std.obj Mymedfilt1.obj median.obj dynamic5.obj interp1.obj pchip.obj tm_trk.obj cmp_rate.obj cat.obj dynamic.obj yaapt_emxutil.obj yaapt_emxAPI.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj

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

CFLAGS_ = /openmp
CFLAGS_BASIC = $(DEFINES) 

CFLAGS = $(CFLAGS) $(CFLAGS_) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ = /openmp
CPPFLAGS_BASIC = $(DEFINES) 

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = /nodefaultlib:vcomp /LIBPATH:$(MATLAB_ROOT)\bin\$(ARCH) libiomp5md.lib

CPP_LDFLAGS = $(CPP_LDFLAGS) $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = /nodefaultlib:vcomp /LIBPATH:$(MATLAB_ROOT)\bin\$(ARCH) libiomp5md.lib

CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS) $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = /nodefaultlib:vcomp /LIBPATH:$(MATLAB_ROOT)\bin\$(ARCH) libiomp5md.lib

LDFLAGS = $(LDFLAGS) $(LDFLAGS_)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = /nodefaultlib:vcomp /LIBPATH:$(MATLAB_ROOT)\bin\$(ARCH) libiomp5md.lib

SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS) $(SHAREDLIB_LDFLAGS_)

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

#----------------------------------------
# Create a dynamic library
#----------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	@cmd /C "@echo ### Creating dynamic library "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_SHAREDLIB_LDFLAGS) -out:$(PRODUCT) @$(CMD_FILE) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
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


{$(START_DIR)\codegen\dll\yaapt}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\dll\yaapt}.cpp.obj :
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
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


