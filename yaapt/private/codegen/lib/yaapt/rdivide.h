/*
 * File: rdivide.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

#ifndef __RDIVIDE_H__
#define __RDIVIDE_H__

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void b_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
                      emxArray_real_T *z);
extern void c_rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z);
extern void d_rdivide(double x, const emxArray_real_T *y, emxArray_real_T *z);
extern void rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z);

#endif

/*
 * File trailer for rdivide.h
 *
 * [EOF]
 */
