/*
 * yaapt.h
 *
 * Code generation for function 'yaapt'
 *
 */

#ifndef __YAAPT_H__
#define __YAAPT_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void yaapt(yaaptStackData *SD, const emlrtStack *sp, const
                  emxArray_real_T *Data, real_T Fs, emxArray_real_T *Pitch,
                  real_T *numfrms, real_T *frmrate);

#endif

/* End of code generation (yaapt.h) */
