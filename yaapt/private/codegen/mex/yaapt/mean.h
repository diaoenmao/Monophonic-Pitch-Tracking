/*
 * mean.h
 *
 * Code generation for function 'mean'
 *
 */

#ifndef __MEAN_H__
#define __MEAN_H__

/* Include files */
#include <math.h>
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
extern void b_mean(const emlrtStack *sp, const emxArray_real_T *x, real_T
                   y_data[], int32_T y_size[1]);
extern real_T c_mean(const emlrtStack *sp, const emxArray_real_T *x);

#ifdef __WATCOMC__

#pragma aux c_mean value [8087];

#endif

extern real_T mean(const emlrtStack *sp, const emxArray_real_T *x);

#ifdef __WATCOMC__

#pragma aux mean value [8087];

#endif
#endif

/* End of code generation (mean.h) */
