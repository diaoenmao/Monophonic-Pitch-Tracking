/*
 * median.h
 *
 * Code generation for function 'median'
 *
 */

#ifndef __MEDIAN_H__
#define __MEDIAN_H__

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
extern void b_median(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y);
extern void median(const emlrtStack *sp, const emxArray_real_T *x,
                   emxArray_real_T *y);

#endif

/* End of code generation (median.h) */
