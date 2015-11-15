/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo wb_emlrtRTEI = { 1, 14, "abs",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

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
  int32_T n;
  boolean_T b10;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  n = y->size[0] * y->size[1];
  y->size[0] = 4;
  y->size[1] = x->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &wb_emlrtRTEI);
  n = x->size[1] << 2;
  b_st.site = &yc_emlrtRSI;
  if (1 > n) {
    b10 = false;
  } else {
    b10 = (n > 2147483646);
  }

  if (b10) {
    c_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
