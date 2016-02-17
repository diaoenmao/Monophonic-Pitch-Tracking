/*
 * Myfir1.h
 *
 * Code generation for function 'Myfir1'
 *
 */

#ifndef __MYFIR1_H__
#define __MYFIR1_H__

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
extern void Myfir1(const emlrtStack *sp, real_T N, const real_T Wn[2],
                   emxArray_real_T *b);

#endif

/* End of code generation (Myfir1.h) */
