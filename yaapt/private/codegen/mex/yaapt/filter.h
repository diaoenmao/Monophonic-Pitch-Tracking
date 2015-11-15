/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#ifndef __FILTER_H__
#define __FILTER_H__

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
extern void b_filter(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y);
extern void filter(const emlrtStack *sp, const real_T b[151], const
                   emxArray_real_T *x, emxArray_real_T *y);

#endif

/* End of code generation (filter.h) */
