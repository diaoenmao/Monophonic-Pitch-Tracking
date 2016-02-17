/*
 * File: yaapt_rtwutil.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

#ifndef __YAAPT_RTWUTIL_H__
#define __YAAPT_RTWUTIL_H__

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
extern int div_s32_floor(int numerator, int denominator);
extern double rt_hypotd_snf(double u0, double u1);
extern double rt_remd_snf(double u0, double u1);
extern double rt_roundd_snf(double u);

#endif

/*
 * File trailer for yaapt_rtwutil.h
 *
 * [EOF]
 */
