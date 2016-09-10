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
#include "var.h"
#include "isequal.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo hl_emlrtRSI = { 7, "std",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRSInfo il_emlrtRSI = { 56, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo im_emlrtRSI = { 148, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo wd_emlrtRTEI = { 1, 14, "std",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRTEInfo qg_emlrtRTEI = { 37, 19, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo rg_emlrtRTEI = { 34, 19, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

/* Function Definitions */

/*
 *
 */
real_T b_std(const emlrtStack *sp, const emxArray_real_T *varargin_1)
{
  boolean_T b5;
  real_T x;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hl_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b5 = !d_isequal(varargin_1);
  if (b5) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &rg_emlrtRTEI,
      "Coder:toolbox:var_specialEmpty", 0);
  }

  if ((varargin_1->size[1] == 1) || (varargin_1->size[1] != 1)) {
    b5 = true;
  } else {
    b5 = false;
  }

  if (b5) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &qg_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  b_st.site = &il_emlrtRSI;
  x = local_var(&b_st, varargin_1, 0.0, false);
  st.site = &hl_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &sd_emlrtRSI;
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
  int32_T j;
  int32_T vstride;
  boolean_T overflow;
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  real_T b_y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hl_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &il_emlrtRSI;
  n = varargin_1->size[1];
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  for (j = 0; j < 2; j++) {
    sz[j] = (uint32_T)varargin_1->size[j];
  }

  j = y->size[0];
  y->size[0] = (int32_T)sz[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                    &wd_emlrtRTEI);
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    vstride = y->size[0];
    j = y->size[0];
    y->size[0] = vstride;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                      &wd_emlrtRTEI);
    for (j = 0; j < vstride; j++) {
      y->data[j] = 0.0;
    }
  } else {
    vstride = varargin_1->size[0];
    c_st.site = &im_emlrtRSI;
    overflow = (varargin_1->size[0] > 2147483646);
    if (overflow) {
      d_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (j = 0; j + 1 <= vstride; j++) {
      c_st.site = &ll_emlrtRSI;
      ix = j;
      xbar = varargin_1->data[j];
      d_st.site = &ol_emlrtRSI;
      if ((!(2 > n)) && (n > 2147483646)) {
        e_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&e_st, true);
      }

      for (k = 2; k <= n; k++) {
        ix += vstride;
        xbar += varargin_1->data[ix];
      }

      xbar /= (real_T)n;
      ix = j;
      r = varargin_1->data[j] - xbar;
      b_y = r * r;
      d_st.site = &pl_emlrtRSI;
      for (k = 2; k <= n; k++) {
        ix += vstride;
        r = varargin_1->data[ix] - xbar;
        b_y += r * r;
      }

      b_y /= (real_T)d;
      y->data[j] = b_y;
    }
  }

  st.site = &hl_emlrtRSI;
  c_sqrt(&st, y);
}

/* End of code generation (std.c) */
