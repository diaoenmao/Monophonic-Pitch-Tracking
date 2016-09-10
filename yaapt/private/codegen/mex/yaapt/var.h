/*
 * var.h
 *
 * Code generation for function 'var'
 *
 */

#ifndef VAR_H
#define VAR_H

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
extern real_T local_var(const emlrtStack *sp, const emxArray_real_T *x, real_T w,
  boolean_T omitnan);

#ifdef __WATCOMC__

#pragma aux local_var value [8087];

#endif
#endif

/* End of code generation (var.h) */
