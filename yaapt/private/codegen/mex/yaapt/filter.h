/*
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#ifndef FILTER_H
#define FILTER_H

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
extern void b_filter(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y);
extern void filter(const emlrtStack *sp, const emxArray_real_T *b, const
                   emxArray_real_T *x, emxArray_real_T *y);

#endif

/* End of code generation (filter.h) */
