/*
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#ifndef __FILTER_H__
#define __FILTER_H__

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
extern void filter(const emlrtStack *sp, const real_T b[151], const
                   emxArray_real_T *x, emxArray_real_T *y);

#endif

/* End of code generation (filter.h) */
