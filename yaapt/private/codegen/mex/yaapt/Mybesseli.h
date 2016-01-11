/*
 * Mybesseli.h
 *
 * Code generation for function 'Mybesseli'
 *
 */

#ifndef __MYBESSELI_H__
#define __MYBESSELI_H__

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
extern void Mybesseli(const emlrtStack *sp, emxArray_real_T *xx, emxArray_real_T
                      *output);
extern real_T b_Mybesseli(const emlrtStack *sp);

#ifdef __WATCOMC__

#pragma aux b_Mybesseli value [8087];

#endif
#endif

/* End of code generation (Mybesseli.h) */
