/*
 * File: rdivide.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

#ifndef __RDIVIDE_H__
#define __RDIVIDE_H__

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

  extern void b_rdivide(const double x[5776], const double y[5776], double z
                        [5776]);
  extern void c_rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z);
  extern void d_rdivide(double x, const emxArray_real_T *y, emxArray_real_T *z);
  extern void e_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
                        emxArray_real_T *z);
  extern void rdivide(const double x[75], const double y[75], double z[75]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for rdivide.h
 *
 * [EOF]
 */
