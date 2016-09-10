/*
 * Smooth.h
 *
 * Code generation for function 'Smooth'
 *
 */

#ifndef SMOOTH_H
#define SMOOTH_H

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
extern void Smooth(const emlrtStack *sp, emxArray_real_T *arr, real_T
                   Prm_smooth_threshold);

#endif

/* End of code generation (Smooth.h) */
