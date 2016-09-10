/*
 * cat.h
 *
 * Code generation for function 'cat'
 *
 */

#ifndef CAT_H
#define CAT_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
                emxArray_real_T *varargin_2, emxArray_real_T *y);

#endif

/* End of code generation (cat.h) */
