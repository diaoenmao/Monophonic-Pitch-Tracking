/*
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 */

#ifndef REPMAT_H
#define REPMAT_H

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
extern void b_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T
                     varargin_2, emxArray_real_T *b);
extern void repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T
                   varargin_1, emxArray_real_T *b);

#endif

/* End of code generation (repmat.h) */
