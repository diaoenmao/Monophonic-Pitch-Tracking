/*
 * exp.h
 *
 * Code generation for function 'exp'
 *
 */

#ifndef EXP_H
#define EXP_H

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
extern void b_exp(const emlrtStack *sp, emxArray_real_T *x);

#endif

/* End of code generation (exp.h) */
