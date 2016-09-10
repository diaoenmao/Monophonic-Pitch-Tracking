/*
 * yaapt.h
 *
 * Code generation for function 'yaapt'
 *
 */

#ifndef YAAPT_H
#define YAAPT_H

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
extern void yaapt(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs,
                  const real_T Parameter[34], emxArray_real_T *Pitch, real_T
                  *numfrms, real_T *frmrate);

#endif

/* End of code generation (yaapt.h) */
