/*
 * nonlinear.h
 *
 * Code generation for function 'nonlinear'
 *
 */

#ifndef __NONLINEAR_H__
#define __NONLINEAR_H__

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
extern void nonlinear(yaaptStackData *SD, const emlrtStack *sp, const
                      emxArray_real_T *DataA, real_T Fs, emxArray_real_T *DataB,
                      emxArray_real_T *DataC, emxArray_real_T *DataD, real_T
                      *newFs);

#endif

/* End of code generation (nonlinear.h) */
