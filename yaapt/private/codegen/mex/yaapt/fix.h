/*
 * fix.h
 *
 * Code generation for function 'fix'
 *
 */

#ifndef __FIX_H__
#define __FIX_H__

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
extern void b_fix(real_T *x);
extern void c_fix(const emlrtStack *sp, emxArray_real_T *x);

#endif

/* End of code generation (fix.h) */
