/*
 * File: sort1.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

#ifndef __SORT1_H__
#define __SORT1_H__

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
extern void c_sort(double x[20], int idx[20]);
extern void e_sort(emxArray_real_T *x, emxArray_int32_T *idx);
extern void sort(double x[100], int idx[100]);

#endif

/*
 * File trailer for sort1.h
 *
 * [EOF]
 */
