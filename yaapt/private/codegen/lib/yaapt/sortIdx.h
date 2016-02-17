/*
 * File: sortIdx.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
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
extern void b_merge(int idx[20], double x[20], int offset, int np, int nq, int
                    iwork[20], double xwork[20]);
extern void merge_block(int idx[100], double x[100], int n, int iwork[100],
  double xwork[100]);
extern void sortIdx(emxArray_real_T *x, emxArray_int32_T *idx);

#endif

/*
 * File trailer for sortIdx.h
 *
 * [EOF]
 */
