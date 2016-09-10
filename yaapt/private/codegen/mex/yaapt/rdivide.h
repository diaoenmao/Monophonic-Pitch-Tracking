/*
 * rdivide.h
 *
 * Code generation for function 'rdivide'
 *
 */

#ifndef RDIVIDE_H
#define RDIVIDE_H

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
extern void b_rdivide(const emlrtStack *sp, real_T x, const emxArray_real_T *y,
                      emxArray_real_T *z);
extern void c_rdivide(const emlrtStack *sp, const emxArray_real_T *y,
                      emxArray_real_T *z);
extern void rdivide(const emlrtStack *sp, const emxArray_real_T *x, const
                    emxArray_real_T *y, emxArray_real_T *z);

#endif

/* End of code generation (rdivide.h) */
