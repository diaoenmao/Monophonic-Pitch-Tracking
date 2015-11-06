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
#include "eml_error.h"
#include "eml_warning.h"
#include "isequal.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo eg_emlrtRSI = { 12, "std",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtMCInfo kb_emlrtMCI = { 18, 9, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtMCInfo lb_emlrtMCI = { 17, 19, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtMCInfo mb_emlrtMCI = { 23, 9, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtMCInfo nb_emlrtMCI = { 20, 19, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRTEInfo mc_emlrtRTEI = { 1, 14, "std",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" };

static emlrtRSInfo rj_emlrtRSI = { 23, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo sj_emlrtRSI = { 18, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo jk_emlrtRSI = { 20, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo kk_emlrtRSI = { 17, "var",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

/* Function Definitions */

/*
 *
 */
real_T b_std(const emlrtStack *sp, const emxArray_real_T *varargin_1)
{
  boolean_T b7;
  const mxArray *b_y;
  static const int32_T iv53[2] = { 1, 30 };

  const mxArray *m26;
  char_T cv84[30];
  int32_T i;
  static const char_T cv85[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'v', 'a', 'r', '_', 's', 'p', 'e', 'c', 'i', 'a',
    'l', 'E', 'm', 'p', 't', 'y' };

  const mxArray *c_y;
  static const int32_T iv54[2] = { 1, 36 };

  char_T cv86[36];
  static const char_T cv87[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  real_T x;
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  b7 = !b_isequal(varargin_1);
  if (b7) {
  } else {
    b_y = NULL;
    m26 = emlrtCreateCharArray(2, iv53);
    for (i = 0; i < 30; i++) {
      cv84[i] = cv85[i];
    }

    emlrtInitCharArrayR2013a(&st, 30, m26, cv84);
    emlrtAssign(&b_y, m26);
    b_st.site = &kk_emlrtRSI;
    c_st.site = &sj_emlrtRSI;
    f_error(&b_st, b_message(&c_st, b_y, &kb_emlrtMCI), &lb_emlrtMCI);
  }

  if ((varargin_1->size[1] == 1) || (varargin_1->size[1] != 1)) {
    b7 = true;
  } else {
    b7 = false;
  }

  if (b7) {
  } else {
    c_y = NULL;
    m26 = emlrtCreateCharArray(2, iv54);
    for (i = 0; i < 36; i++) {
      cv86[i] = cv87[i];
    }

    emlrtInitCharArrayR2013a(&st, 36, m26, cv86);
    emlrtAssign(&c_y, m26);
    b_st.site = &jk_emlrtRSI;
    c_st.site = &rj_emlrtRSI;
    f_error(&b_st, b_message(&c_st, c_y, &mb_emlrtMCI), &nb_emlrtMCI);
  }

  if (varargin_1->size[1] > 1) {
    i = varargin_1->size[1] - 1;
  } else {
    i = varargin_1->size[1];
  }

  if (varargin_1->size[1] == 0) {
    x = 0.0;
  } else {
    ix = 0;
    xbar = varargin_1->data[0];
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (real_T)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    x = r * r;
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      x += r * r;
    }

    x /= (real_T)i;
  }

  st.site = &eg_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &p_emlrtRSI;
    eml_error(&b_st);
  }

  return muDoubleScalarSqrt(x);
}

/*
 *
 */
void c_std(const emlrtStack *sp, const emxArray_real_T *varargin_1, real_T
           y_data[], int32_T y_size[1])
{
  int32_T d;
  uint32_T sz[2];
  int32_T k;
  int32_T ix;
  real_T xbar;
  real_T r;
  real_T y;
  emxArray_real_T *r16;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &eg_emlrtRSI;
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  for (k = 0; k < 2; k++) {
    sz[k] = (uint32_T)varargin_1->size[k];
  }

  y_size[0] = (int32_T)sz[0];
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    y_size[0] = (int32_T)sz[0];
    ix = (int32_T)sz[0];
    for (k = 0; k < ix; k++) {
      y_data[k] = 0.0;
    }
  } else {
    ix = 0;
    xbar = varargin_1->data[0];
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (real_T)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      y += r * r;
    }

    y /= (real_T)d;
    y_data[0] = y;
  }

  b_emxInit_real_T(&st, &r16, 1, &mc_emlrtRTEI, true);
  k = r16->size[0];
  r16->size[0] = y_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r16, k, (int32_T)sizeof(real_T),
                    &mc_emlrtRTEI);
  ix = y_size[0];
  for (k = 0; k < ix; k++) {
    r16->data[k] = y_data[k];
  }

  st.site = &eg_emlrtRSI;
  b_sqrt(&st, r16);
  y_size[0] = r16->size[0];
  ix = r16->size[0];
  for (k = 0; k < ix; k++) {
    y_data[k] = r16->data[k];
  }

  emxFree_real_T(&r16);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (std.c) */
