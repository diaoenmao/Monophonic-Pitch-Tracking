/*
 * File: mean.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Jan-2016 05:43:25
 */

#ifndef __MEAN_H__
#define __MEAN_H__

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
extern void b_mean(const emxArray_real_T *x, double y_data[], int y_size[1]);
extern double mean(const emxArray_real_T *x);

#endif

/*
 * File trailer for mean.h
 *
 * [EOF]
 */
