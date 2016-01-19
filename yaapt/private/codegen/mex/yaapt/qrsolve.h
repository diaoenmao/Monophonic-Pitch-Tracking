/*
 * qrsolve.h
 *
 * Code generation for function 'qrsolve'
 *
 */

#ifndef __QRSOLVE_H__
#define __QRSOLVE_H__

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
extern void LSQFromQR(const emlrtStack *sp, const emxArray_real_T *A, const
                      emxArray_real_T *tau, const emxArray_int32_T *jpvt, real_T
                      B, int32_T rankA, emxArray_real_T *Y);

#endif

/* End of code generation (qrsolve.h) */
