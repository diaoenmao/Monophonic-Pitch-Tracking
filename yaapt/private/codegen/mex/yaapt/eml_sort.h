/*
 * eml_sort.h
 *
 * Code generation for function 'eml_sort'
 *
 */

#ifndef __EML_SORT_H__
#define __EML_SORT_H__

/* Include files */
#include <math.h>
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
extern void c_eml_sort(const real_T x[3], real_T y[3], int32_T idx[3]);
extern void e_eml_sort(const emlrtStack *sp, const emxArray_real_T *x,
  emxArray_real_T *y, emxArray_int32_T *idx);
extern void eml_sort(const real_T x[100], real_T y[100], int32_T idx[100]);

#endif

/* End of code generation (eml_sort.h) */
