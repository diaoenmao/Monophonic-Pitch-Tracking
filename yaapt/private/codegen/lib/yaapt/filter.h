/*
 * File: filter.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

#ifndef __FILTER_H__
#define __FILTER_H__

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
extern void b_filter(const emxArray_real_T *x, emxArray_real_T *y);
extern void filter(const emxArray_real_T *b, const emxArray_real_T *x,
                   emxArray_real_T *y);

#endif

/*
 * File trailer for filter.h
 *
 * [EOF]
 */
