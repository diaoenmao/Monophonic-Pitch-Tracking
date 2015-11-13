/*
 * File: eml_sort.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
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
#ifdef __cplusplus

extern "C" {

#endif

  extern void c_eml_sort(const double x[3], double y[3], int idx[3]);
  extern void e_eml_sort(const emxArray_real_T *x, emxArray_real_T *y,
    emxArray_int32_T *idx);
  extern void eml_sort(const double x[100], double y[100], int idx[100]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for eml_sort.h
 *
 * [EOF]
 */
