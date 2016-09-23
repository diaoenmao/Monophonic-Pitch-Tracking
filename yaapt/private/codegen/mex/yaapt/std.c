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
#include "eml_int_forloop_overflow_check.h"
#include "sqrt.h"
#include "error1.h"
#include "isequal.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ck_emlrtRSI = { 7, "std",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRSInfo dk_emlrtRSI = { 56, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo ek_emlrtRSI = { 149, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo fk_emlrtRSI = { 182, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo gk_emlrtRSI = { 189, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo xk_emlrtRSI = { 148, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo od_emlrtRTEI = { 1, 14, "std",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRTEInfo fg_emlrtRTEI = { 34, 19, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo gg_emlrtRTEI = { 37, 19, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

/* Function Definitions */
real_T b_std(const emlrtStack *sp, const emxArray_real_T *varargin_1)
{
  boolean_T overflow;
  int32_T i30;
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
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ck_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  overflow = !c_isequal(varargin_1);
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

  b_st.site = &dk_emlrtRSI;
  i30 = varargin_1->size[1];
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  if (varargin_1->size[1] == 0) {
    x = 0.0;
  } else {
    c_st.site = &ek_emlrtRSI;
    ix = 0;
    xbar = varargin_1->data[0];
    d_st.site = &fk_emlrtRSI;
    overflow = ((!(2 > varargin_1->size[1])) && (varargin_1->size[1] >
      2147483646));
    if (overflow) {
      e_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 2; k <= i30; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (real_T)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    x = r * r;
    d_st.site = &gk_emlrtRSI;
    overflow = ((!(2 > varargin_1->size[1])) && (varargin_1->size[1] >
      2147483646));
    if (overflow) {
      e_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 2; k <= i30; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      x += r * r;
    }

    x /= (real_T)d;
  }

  st.site = &ck_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &hd_emlrtRSI;
    error(&b_st);
  }

  return muDoubleScalarSqrt(x);
}

void c_std(const emlrtStack *sp, const emxArray_real_T *varargin_1, real_T
           y_data[], int32_T y_size[1])
{
  int32_T n;
  int32_T d;
  int32_T ix;
  real_T xbar;
  emxArray_real_T *r32;
  int32_T k;
  real_T r;
  real_T y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &ck_emlrtRSI;
  b_st.site = &dk_emlrtRSI;
  n = varargin_1->size[1];
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  y_size[0] = varargin_1->size[0];
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    n = y_size[0];
    for (d = 0; d < n; d++) {
      y_data[d] = 0.0;
    }
  } else {
    c_st.site = &xk_emlrtRSI;
    c_st.site = &ek_emlrtRSI;
    ix = 0;
    xbar = varargin_1->data[0];
    d_st.site = &fk_emlrtRSI;
    if ((!(2 > n)) && (n > 2147483646)) {
      e_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 2; k <= n; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (real_T)n;
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    d_st.site = &gk_emlrtRSI;
    for (k = 2; k <= n; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      y += r * r;
    }

    y /= (real_T)d;
    y_data[0] = y;
  }

  emxInit_real_T2(&b_st, &r32, 1, &od_emlrtRTEI, true);
  d = r32->size[0];
  r32->size[0] = y_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r32, d, (int32_T)sizeof(real_T),
                    &od_emlrtRTEI);
  n = y_size[0];
  for (d = 0; d < n; d++) {
    r32->data[d] = y_data[d];
  }

  st.site = &ck_emlrtRSI;
  c_sqrt(&st, r32);
  y_size[0] = r32->size[0];
  n = r32->size[0];
  for (d = 0; d < n; d++) {
    y_data[d] = r32->data[d];
  }

  emxFree_real_T(&r32);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (std.c) */
