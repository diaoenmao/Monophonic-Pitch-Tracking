/*
 * File: filter.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 27-Oct-2015 00:20:18
 */

#ifndef __FILTER_H__
#define __FILTER_H__

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
extern void filter(const double b[151], const emxArray_real_T *x,
                   emxArray_real_T *y);

#endif

/*
 * File trailer for filter.h
 *
 * [EOF]
 */
