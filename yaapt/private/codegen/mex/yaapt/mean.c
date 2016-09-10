/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mean.h"
#include "combine_vector_elements.h"
#include "isequal.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sh_emlrtRSI = { 40, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRSInfo hm_emlrtRSI = { 102, "combine_vector_elements",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

static emlrtRTEInfo vd_emlrtRTEI = { 1, 14, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRTEInfo dg_emlrtRTEI = { 17, 15, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRTEInfo eg_emlrtRTEI = { 21, 5, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRTEInfo fg_emlrtRTEI = { 30, 5, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

/* Function Definitions */

/*
 *
 */
void b_mean(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T j;
  int32_T vlen;
  int32_T vstride;
  boolean_T overflow;
  real_T s;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (j = 0; j < 2; j++) {
    sz[j] = (uint32_T)x->size[j];
  }

  j = y->size[0];
  y->size[0] = (int32_T)sz[0];
  emxEnsureCapacity(&st, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                    &vd_emlrtRTEI);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vlen = y->size[0];
    j = y->size[0];
    y->size[0] = vlen;
    emxEnsureCapacity(&st, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                      &vd_emlrtRTEI);
    for (j = 0; j < vlen; j++) {
      y->data[j] = 0.0;
    }
  } else {
    vlen = x->size[1];
    vstride = x->size[0];
    b_st.site = &hm_emlrtRSI;
    overflow = (x->size[0] > 2147483646);
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (j = 0; j + 1 <= vstride; j++) {
      s = x->data[j];
      b_st.site = &rh_emlrtRSI;
      if ((!(2 > vlen)) && (vlen > 2147483646)) {
        c_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (k = 2; k <= vlen; k++) {
        s += x->data[j + (k - 1) * vstride];
      }

      y->data[j] = s;
    }
  }

  vlen = x->size[1];
  j = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                    &vd_emlrtRTEI);
  vstride = y->size[0];
  for (j = 0; j < vstride; j++) {
    y->data[j] /= (real_T)vlen;
  }
}

/*
 *
 */
real_T c_mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &dg_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = !b_isequal(x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &eg_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  overflow = !b_isequal(x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &fg_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  st.site = &sh_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    b_st.site = &th_emlrtRSI;
    overflow = ((!(2 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 2; k <= x->size[0]; k++) {
      y += x->data[k - 1];
    }
  }

  y /= (real_T)x->size[0];
  return y;
}

/*
 *
 */
real_T mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  boolean_T b1;
  real_T b_x;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b1 = true;
  } else {
    b1 = false;
  }

  if (b1) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &dg_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  b1 = !d_isequal(x);
  if (b1) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &eg_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b1 = !d_isequal(x);
  if (b1) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &fg_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  st.site = &sh_emlrtRSI;
  b_x = combine_vector_elements(&st, x);
  return b_x / (real_T)x->size[1];
}

/* End of code generation (mean.c) */
