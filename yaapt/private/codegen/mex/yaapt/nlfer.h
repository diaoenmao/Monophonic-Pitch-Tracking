/*
 * nlfer.h
 *
 * Code generation for function 'nlfer'
 *
 */

#ifndef __NLFER_H__
#define __NLFER_H__

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
extern void nlfer(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs,
                  emxArray_real_T *Energy, emxArray_boolean_T *VUVEnergy);

#endif

/* End of code generation (nlfer.h) */
