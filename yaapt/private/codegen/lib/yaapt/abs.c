/*
 * File: abs.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "abs.h"
#include "yaapt_emxutil.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_creal_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_abs(const emxArray_creal_T *x, emxArray_real_T *y)
{
  int k;
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(double));
  for (k = 0; k + 1 <= x->size[1]; k++) {
    y->data[k] = rt_hypotd_snf(x->data[k].re, x->data[k].im);
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void c_abs(const emxArray_real_T *x, emxArray_real_T *y)
{
  unsigned int uv3[2];
  int n;
  int k;
  for (n = 0; n < 2; n++) {
    uv3[n] = (unsigned int)x->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = (int)uv3[0];
  y->size[1] = (int)uv3[1];
  emxEnsureCapacity((emxArray__common *)y, n, (int)sizeof(double));
  n = x->size[0] * x->size[1];
  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = fabs(x->data[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
