/*
 * File: eml_sort.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 25-Oct-2015 03:48:36
 */

#ifndef __EML_SORT_H__
#define __EML_SORT_H__

/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void c_eml_sort(const double x[3], double y[3], int idx[3]);
extern void e_eml_sort(const emxArray_real_T *x, emxArray_real_T *y,
  emxArray_int32_T *idx);
extern void eml_sort(const double x[4], double y[4], int idx[4]);

#endif

/*
 * File trailer for eml_sort.h
 *
 * [EOF]
 */
