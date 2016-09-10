/*
 * Mymedfilt1.h
 *
 * Code generation for function 'Mymedfilt1'
 *
 */

#ifndef MYMEDFILT1_H
#define MYMEDFILT1_H

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
extern void Mymedfilt1(const emlrtStack *sp, emxArray_real_T *s, real_T w,
  emxArray_real_T *m);
extern void b_Mymedfilt1(const emlrtStack *sp, const emxArray_real_T *s, real_T
  w, emxArray_real_T *m);

#endif

/* End of code generation (Mymedfilt1.h) */
