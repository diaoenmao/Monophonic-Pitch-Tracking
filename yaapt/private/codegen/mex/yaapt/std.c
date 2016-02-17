/*
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "std.h"
#include "yaapt_emxutil.h"
#include "sqrt.h"
#include "eml_int_forloop_overflow_check.h"
#include "error1.h"
#include "isequal.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo tj_emlrtRSI = { 12, "std",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRSInfo uj_emlrtRSI = { 111, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo vj_emlrtRSI = { 143, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo wj_emlrtRSI = { 150, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo pk_emlrtRSI = { 108, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo md_emlrtRTEI = { 1, 14, "std",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRTEInfo fg_emlrtRTEI = { 18, 19, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo gg_emlrtRTEI = { 21, 19, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

/* Function Definitions */

/*
 *
 */
real_T b_std(const emlrtStack *sp, const emxArray_real_T *varargin_1)
{
  boolean_T overflow;
  int32_T n;
  int32_T d;
  real_T x;
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tj_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  overflow = !d_isequal(varargin_1);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &fg_emlrtRTEI,
      "Coder:toolbox:var_specialEmpty", 0);
  }

  if ((varargin_1->size[1] == 1) || (varargin_1->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &gg_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  n = varargin_1->size[1];
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  if (varargin_1->size[1] == 0) {
    x = 0.0;
  } else {
    b_st.site = &uj_emlrtRSI;
    ix = 0;
    xbar = varargin_1->data[0];
    c_st.site = &vj_emlrtRSI;
    if (2 > varargin_1->size[1]) {
      overflow = false;
    } else {
      overflow = (varargin_1->size[1] > 2147483646);
    }

    if (overflow) {
      d_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (k = 2; k <= n; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (real_T)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    x = r * r;
    c_st.site = &wj_emlrtRSI;
    if (2 > varargin_1->size[1]) {
      overflow = false;
    } else {
      overflow = (varargin_1->size[1] > 2147483646);
    }

    if (overflow) {
      d_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (k = 2; k <= n; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      x += r * r;
    }

    x /= (real_T)d;
  }

  st.site = &tj_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &td_emlrtRSI;
    error(&b_st);
  }

  return muDoubleScalarSqrt(x);
}

/*
 *
 */
void c_std(const emlrtStack *sp, const emxArray_real_T *varargin_1,
           emxArray_real_T *y)
{
  int32_T n;
  int32_T d;
  uint32_T sz[2];
  int32_T ix;
  int32_T vstride;
  int32_T iy;
  boolean_T overflow;
  int32_T j;
  int32_T b_ix;
  real_T xbar;
  boolean_T b20;
  int32_T k;
  real_T r;
  real_T b_y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tj_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  n = varargin_1->size[1];
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  for (ix = 0; ix < 2; ix++) {
    sz[ix] = (uint32_T)varargin_1->size[ix];
  }

  ix = y->size[0];
  y->size[0] = (int32_T)sz[0];
  emxEnsureCapacity(&st, (emxArray__common *)y, ix, (int32_T)sizeof(real_T),
                    &md_emlrtRTEI);
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    vstride = y->size[0];
    ix = y->size[0];
    y->size[0] = vstride;
    emxEnsureCapacity(&st, (emxArray__common *)y, ix, (int32_T)sizeof(real_T),
                      &md_emlrtRTEI);
    for (ix = 0; ix < vstride; ix++) {
      y->data[ix] = 0.0;
    }
  } else {
    vstride = varargin_1->size[0];
    ix = -1;
    iy = -1;
    b_st.site = &pk_emlrtRSI;
    overflow = (varargin_1->size[0] > 2147483646);
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (j = 1; j <= vstride; j++) {
      ix++;
      iy++;
      b_st.site = &uj_emlrtRSI;
      b_ix = ix;
      xbar = varargin_1->data[ix];
      c_st.site = &vj_emlrtRSI;
      if (2 > n) {
        b20 = false;
      } else {
        b20 = (n > 2147483646);
      }

      if (b20) {
        d_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (k = 2; k <= n; k++) {
        b_ix += vstride;
        xbar += varargin_1->data[b_ix];
      }

      xbar /= (real_T)n;
      b_ix = ix;
      r = varargin_1->data[ix] - xbar;
      b_y = r * r;
      c_st.site = &wj_emlrtRSI;
      for (k = 2; k <= n; k++) {
        b_ix += vstride;
        r = varargin_1->data[b_ix] - xbar;
        b_y += r * r;
      }

      b_y /= (real_T)d;
      y->data[iy] = b_y;
    }
  }

  st.site = &tj_emlrtRSI;
  c_sqrt(&st, y);
}

/* End of code generation (std.c) */
