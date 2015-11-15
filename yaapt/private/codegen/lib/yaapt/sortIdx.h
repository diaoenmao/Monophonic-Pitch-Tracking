/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:14:51
 */

#ifndef __SORTIDX_H__
#define __SORTIDX_H__

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
extern void merge_block(int idx[100], double x[100], int n, int iwork[100],
  double xwork[100]);
extern void sortIdx(emxArray_real_T *x, emxArray_int32_T *idx);

#endif

/*
 * File trailer for sortIdx.h
 *
 * [EOF]
 */
