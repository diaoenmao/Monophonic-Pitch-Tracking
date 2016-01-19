/*
 * combine_vector_elements.h
 *
 * Code generation for function 'combine_vector_elements'
 *
 */

#ifndef __COMBINE_VECTOR_ELEMENTS_H__
#define __COMBINE_VECTOR_ELEMENTS_H__

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
extern real_T combine_vector_elements(const emlrtStack *sp, const
  emxArray_real_T *x);

#ifdef __WATCOMC__

#pragma aux combine_vector_elements value [8087];

#endif
#endif

/* End of code generation (combine_vector_elements.h) */
