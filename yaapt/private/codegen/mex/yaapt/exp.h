/*
 * exp.h
 *
 * Code generation for function 'exp'
 *
 */

#ifndef __EXP_H__
#define __EXP_H__

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
extern void b_exp(const emlrtStack *sp, emxArray_real_T *x);

#endif

/* End of code generation (exp.h) */
