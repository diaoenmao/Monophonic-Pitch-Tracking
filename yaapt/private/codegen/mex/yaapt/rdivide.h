/*
 * rdivide.h
 *
 * Code generation for function 'rdivide'
 *
 */

#ifndef __RDIVIDE_H__
#define __RDIVIDE_H__

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
extern void b_rdivide(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
                      emxArray_real_T *z);
extern void c_rdivide(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
                      emxArray_real_T *z);
extern void d_rdivide(const emlrtStack *sp, real_T x, const emxArray_real_T *y,
                      emxArray_real_T *z);
extern void e_rdivide(const emlrtStack *sp, const emxArray_real_T *x, const
                      emxArray_real_T *y, emxArray_real_T *z);
extern void rdivide(const real_T x[75], const real_T y[75], real_T z[75]);

#endif

/* End of code generation (rdivide.h) */
