/*
 * xaxpy.h
 *
 * Code generation for function 'xaxpy'
 *
 */

#ifndef __XAXPY_H__
#define __XAXPY_H__

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
extern void xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T ix0,
                  emxArray_real_T *y, int32_T iy0);

#endif

/* End of code generation (xaxpy.h) */
