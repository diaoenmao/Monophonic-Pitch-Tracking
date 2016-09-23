/*
 * prod.c
 *
 * Code generation for function 'prod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "prod.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "isequal.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo dj_emlrtRSI = { 10, "prod",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtRTEInfo bd_emlrtRTEI = { 1, 14, "prod",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

/* Function Definitions */
void prod(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  int32_T vlen;
  int32_T i;
  int32_T xoffset;
  real_T s;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dj_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (((x->size[0] == 1) && (x->size[1] == 1)) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &nf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = !b_isequal(x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &mf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &pg_emlrtRSI;
  vlen = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)y, vlen, (int32_T)sizeof(real_T),
                    &bd_emlrtRTEI);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vlen = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, vlen, (int32_T)sizeof(real_T),
                      &bd_emlrtRTEI);
    i = y->size[1];
    for (vlen = 0; vlen < i; vlen++) {
      y->data[y->size[0] * vlen] = 1.0;
    }
  } else {
    vlen = x->size[0];
    c_st.site = &qg_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      d_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (i = 0; i + 1 <= x->size[1]; i++) {
      xoffset = i * vlen;
      s = x->data[xoffset];
      c_st.site = &rg_emlrtRSI;
      if ((!(2 > vlen)) && (vlen > 2147483646)) {
        d_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 2; k <= vlen; k++) {
        s *= x->data[(xoffset + k) - 1];
      }

      y->data[i] = s;
    }
  }
}

/* End of code generation (prod.c) */
