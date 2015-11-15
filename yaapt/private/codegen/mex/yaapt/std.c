/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sg_emlrtRSI = { 12, "std",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRSInfo tg_emlrtRSI = { 111, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo ug_emlrtRSI = { 143, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo vg_emlrtRSI = { 150, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo kh_emlrtRSI = { 108, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo hc_emlrtRTEI = { 1, 14, "std",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRTEInfo ne_emlrtRTEI = { 18, 19, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo oe_emlrtRTEI = { 21, 19, "var",
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
  st.site = &sg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  overflow = !b_isequal(varargin_1);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ne_emlrtRTEI,
      "Coder:toolbox:var_specialEmpty", 0);
  }

  if ((varargin_1->size[1] == 1) || (varargin_1->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &oe_emlrtRTEI,
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
    b_st.site = &tg_emlrtRSI;
    ix = 0;
    xbar = varargin_1->data[0];
    c_st.site = &ug_emlrtRSI;
    if (2 > varargin_1->size[1]) {
      overflow = false;
    } else {
      overflow = (varargin_1->size[1] > 2147483646);
    }

    if (overflow) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= n; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (real_T)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    x = r * r;
    c_st.site = &vg_emlrtRSI;
    if (2 > varargin_1->size[1]) {
      overflow = false;
    } else {
      overflow = (varargin_1->size[1] > 2147483646);
    }

    if (overflow) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= n; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      x += r * r;
    }

    x /= (real_T)d;
  }

  st.site = &sg_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &ge_emlrtRSI;
    error(&b_st);
  }

  return muDoubleScalarSqrt(x);
}

/*
 *
 */
void c_std(const emlrtStack *sp, const emxArray_real_T *varargin_1, real_T
           y_data[], int32_T y_size[1])
{
  int32_T n;
  int32_T d;
  int32_T ix;
  real_T xbar;
  boolean_T b12;
  int32_T k;
  real_T r;
  real_T y;
  emxArray_real_T *r15;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &sg_emlrtRSI;
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
    b_st.site = &kh_emlrtRSI;
    b_st.site = &tg_emlrtRSI;
    ix = 0;
    xbar = varargin_1->data[0];
    c_st.site = &ug_emlrtRSI;
    if (2 > n) {
      b12 = false;
    } else {
      b12 = (n > 2147483646);
    }

    if (b12) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= n; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (real_T)n;
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    c_st.site = &vg_emlrtRSI;
    for (k = 2; k <= n; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      y += r * r;
    }

    y /= (real_T)d;
    y_data[0] = y;
  }

  emxInit_real_T1(&st, &r15, 1, &hc_emlrtRTEI, true);
  d = r15->size[0];
  r15->size[0] = y_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r15, d, (int32_T)sizeof(real_T),
                    &hc_emlrtRTEI);
  n = y_size[0];
  for (d = 0; d < n; d++) {
    r15->data[d] = y_data[d];
  }

  st.site = &sg_emlrtRSI;
  b_sqrt(&st, r15);
  y_size[0] = r15->size[0];
  n = r15->size[0];
  for (d = 0; d < n; d++) {
    y_data[d] = r15->data[d];
  }

  emxFree_real_T(&r15);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (std.c) */
