/*
 * File: abs.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
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
  int i10;
  int k;
  for (i10 = 0; i10 < 2; i10++) {
    uv1[i10] = (unsigned int)x->size[i10];
  }

  i10 = y->size[0] * y->size[1];
  y->size[0] = 4;
  y->size[1] = (int)uv1[1];
  emxEnsureCapacity((emxArray__common *)y, i10, (int)sizeof(double));
  i10 = x->size[1] << 2;
  for (k = 0; k < i10; k++) {
    y->data[k] = fabs(x->data[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
