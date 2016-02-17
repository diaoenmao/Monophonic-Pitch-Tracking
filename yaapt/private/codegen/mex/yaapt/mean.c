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
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo hg_emlrtRSI = { 34, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRSInfo ok_emlrtRSI = { 56, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

static emlrtRTEInfo ld_emlrtRTEI = { 1, 14, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRTEInfo rf_emlrtRTEI = { 29, 5, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRTEInfo sf_emlrtRTEI = { 20, 5, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRTEInfo tf_emlrtRTEI = { 16, 15, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

/* Function Definitions */

/*
 *
 */
void b_mean(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T vlen;
  emxArray_real_T *b_y;
  int32_T vstride;
  int32_T iy;
  int32_T ixstart;
  boolean_T overflow;
  int32_T j;
  int32_T ix;
  real_T s;
  boolean_T b19;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &hg_emlrtRSI;
  for (vlen = 0; vlen < 2; vlen++) {
    sz[vlen] = (uint32_T)x->size[vlen];
  }

  emxInit_real_T1(&st, &b_y, 1, &ld_emlrtRTEI, true);
  vlen = b_y->size[0];
  b_y->size[0] = (int32_T)sz[0];
  emxEnsureCapacity(&st, (emxArray__common *)b_y, vlen, (int32_T)sizeof(real_T),
                    &ld_emlrtRTEI);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vstride = b_y->size[0];
    vlen = b_y->size[0];
    b_y->size[0] = vstride;
    emxEnsureCapacity(&st, (emxArray__common *)b_y, vlen, (int32_T)sizeof(real_T),
                      &ld_emlrtRTEI);
    for (vlen = 0; vlen < vstride; vlen++) {
      b_y->data[vlen] = 0.0;
    }
  } else {
    vlen = x->size[1];
    vstride = x->size[0];
    iy = -1;
    ixstart = -1;
    b_st.site = &ok_emlrtRSI;
    overflow = (x->size[0] > 2147483646);
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (j = 1; j <= vstride; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      b_st.site = &gg_emlrtRSI;
      if (2 > vlen) {
        b19 = false;
      } else {
        b19 = (vlen > 2147483646);
      }

      if (b19) {
        c_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (k = 2; k <= vlen; k++) {
        ix += vstride;
        s += x->data[ix];
      }

      iy++;
      b_y->data[iy] = s;
    }
  }

  rdivide(sp, b_y, x->size[1], y);
  emxFree_real_T(&b_y);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
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
    emlrtErrorWithMessageIdR2012b(sp, &tf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = !b_isequal(x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &sf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  overflow = !b_isequal(x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &rf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  st.site = &hg_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    b_st.site = &ig_emlrtRSI;
    if (2 > x->size[0]) {
      overflow = false;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

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
  boolean_T b8;
  real_T b_x;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b8 = true;
  } else {
    b8 = false;
  }

  if (b8) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &tf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  b8 = !d_isequal(x);
  if (b8) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &sf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b8 = !d_isequal(x);
  if (b8) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &rf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  st.site = &hg_emlrtRSI;
  b_x = combine_vector_elements(&st, x);
  return b_x / (real_T)x->size[1];
}

/* End of code generation (mean.c) */
