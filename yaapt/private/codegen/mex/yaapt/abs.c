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
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo sc_emlrtRTEI = { 1, 14, "abs",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

/* Function Definitions */

/*
 *
 */
void b_abs(const emlrtStack *sp, const emxArray_creal_T *x, emxArray_real_T *y)
{
  uint32_T uv3[2];
  int32_T k;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (k = 0; k < 2; k++) {
    uv3[k] = (uint32_T)x->size[k];
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)uv3[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &sc_emlrtRTEI);
  b_st.site = &cg_emlrtRSI;
  if (1 > x->size[1]) {
    overflow = false;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = 0; k + 1 <= x->size[1]; k++) {
    y->data[k] = muDoubleScalarHypot(x->data[k].re, x->data[k].im);
  }
}

/*
 *
 */
void c_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T uv4[2];
  int32_T n;
  boolean_T b18;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (n = 0; n < 2; n++) {
    uv4[n] = (uint32_T)x->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv4[0];
  y->size[1] = (int32_T)uv4[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &sc_emlrtRTEI);
  n = x->size[0] * x->size[1];
  b_st.site = &cg_emlrtRSI;
  if (1 > n) {
    b18 = false;
  } else {
    b18 = (n > 2147483646);
  }

  if (b18) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/*
 *
 */
void d_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T uv9[2];
  int32_T k;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (k = 0; k < 2; k++) {
    uv9[k] = (uint32_T)x->size[k];
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)uv9[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &sc_emlrtRTEI);
  b_st.site = &cg_emlrtRSI;
  if (1 > x->size[1]) {
    overflow = false;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = 0; k + 1 <= x->size[1]; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
