/*
 * File: sortIdx.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

#ifndef SORTIDX_H
#define SORTIDX_H

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
extern void b_merge(int idx[20], double x[20], int offset, int np, int nq, int
                    iwork[20], double xwork[20]);
extern void b_sortIdx(emxArray_real_T *x, emxArray_int32_T *idx);
extern void merge_block(int idx[100], double x[100], int n, int iwork[100],
  double xwork[100]);
extern void sortIdx(emxArray_real_T *x, emxArray_int32_T *idx);

#endif

/*
 * File trailer for sortIdx.h
 *
 * [EOF]
 */
