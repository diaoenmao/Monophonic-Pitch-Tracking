/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: abs.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "abs.h"
#include "yaapt_emxutil.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T x[8192]
 *                double y[8192]
 * Return Type  : void
 */
void b_abs(const creal_T x[8192], double y[8192])
{
  int k;
  for (k = 0; k < 8192; k++) {
    y[k] = rt_hypotd_snf(x[k].re, x[k].im);
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void c_abs(const emxArray_real_T *x, emxArray_real_T *y)
{
  int n;
  int k;
  n = y->size[0] * y->size[1];
  y->size[0] = 4;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, n, (int)sizeof(double));
  n = x->size[1] << 2;
  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = fabs(x->data[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
