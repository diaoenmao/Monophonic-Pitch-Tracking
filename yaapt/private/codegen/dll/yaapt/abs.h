/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: abs.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
 */

#ifndef __ABS_H__
#define __ABS_H__

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
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_abs(const creal_T x[8192], double y[8192]);
  extern void c_abs(const emxArray_real_T *x, emxArray_real_T *y);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for abs.h
 *
 * [EOF]
 */
