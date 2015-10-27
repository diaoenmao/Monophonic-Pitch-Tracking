/*
 * File: abs.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 26-Oct-2015 23:41:06
 */

/* Include files */
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
  unsigned int uv1[2];
  int i11;
  int k;
  for (i11 = 0; i11 < 2; i11++) {
    uv1[i11] = (unsigned int)x->size[i11];
  }

  i11 = y->size[0] * y->size[1];
  y->size[0] = 4;
  y->size[1] = (int)uv1[1];
  emxEnsureCapacity((emxArray__common *)y, i11, (int)sizeof(double));
  i11 = x->size[1] << 2;
  for (k = 0; k < i11; k++) {
    y->data[k] = fabs(x->data[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
