/*
 * File: filter.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

#ifndef FILTER_H
#define FILTER_H

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
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
