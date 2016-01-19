/*
 * xgetrf.h
 *
 * Code generation for function 'xgetrf'
 *
 */

#ifndef __XGETRF_H__
#define __XGETRF_H__

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
extern void xgetrf(const emlrtStack *sp, real_T A[5776], int32_T ipiv[76],
                   int32_T *info);

#endif

/* End of code generation (xgetrf.h) */
