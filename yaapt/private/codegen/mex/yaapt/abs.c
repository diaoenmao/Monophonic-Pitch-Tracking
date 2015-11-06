/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "abs.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"

/* Function Definitions */

/*
 *
 */
void b_abs(const creal_T x[8192], real_T y[8192])
{
  int32_T k;
  for (k = 0; k < 8192; k++) {
    y[k] = muDoubleScalarHypot(x[k].re, x[k].im);
  }
}

/*
 *
 */
void c_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T uv1[2];
  int32_T i21;
  int32_T k;
  for (i21 = 0; i21 < 2; i21++) {
    uv1[i21] = (uint32_T)x->size[i21];
  }

  i21 = y->size[0] * y->size[1];
  y->size[0] = 4;
  y->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i21, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  i21 = x->size[1] << 2;
  for (k = 0; k < i21; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
