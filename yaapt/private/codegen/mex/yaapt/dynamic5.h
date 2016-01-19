/*
 * dynamic5.h
 *
 * Code generation for function 'dynamic5'
 *
 */

#ifndef __DYNAMIC5_H__
#define __DYNAMIC5_H__

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
extern void dynamic5(const emlrtStack *sp, const emxArray_real_T *Pitch_array,
                     const emxArray_real_T *Merit_array, real_T k1,
                     emxArray_real_T *FinPitch);

#endif

/* End of code generation (dynamic5.h) */
