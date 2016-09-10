/*
 * sinc.h
 *
 * Code generation for function 'sinc'
 *
 */

#ifndef SINC_H
#define SINC_H

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
extern void b_sinc(const emlrtStack *sp, emxArray_real_T *x, emxArray_real_T *y);
extern void sinc(const emlrtStack *sp, emxArray_real_T *x, emxArray_real_T *y);

#endif

/* End of code generation (sinc.h) */
