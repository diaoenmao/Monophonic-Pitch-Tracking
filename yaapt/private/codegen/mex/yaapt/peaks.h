/*
 * peaks.h
 *
 * Code generation for function 'peaks'
 *
 */

#ifndef __PEAKS_H__
#define __PEAKS_H__

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
#include "yaapt_types.h"

/* Function Declarations */
extern void peaks(const emlrtStack *sp, emxArray_real_T *Data, real_T delta,
                  emxArray_real_T *Pitch, emxArray_real_T *Merit);

#endif

/* End of code generation (peaks.h) */
