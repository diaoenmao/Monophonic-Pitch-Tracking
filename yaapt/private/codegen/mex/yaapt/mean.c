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
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo xc_emlrtRSI = { 25, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRSInfo yc_emlrtRSI = { 28, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRSInfo ad_emlrtRSI = { 47, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

static emlrtRSInfo pg_emlrtRSI = { 72, "sum",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

static emlrtRTEInfo lc_emlrtRTEI = { 1, 14, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

/* Function Definitions */

/*
 *
 */
void b_mean(const emlrtStack *sp, const emxArray_real_T *x, real_T y_data[],
            int32_T y_size[1])
{
  uint32_T sz[2];
  int32_T ix;
  int32_T k;
  real_T s;
  boolean_T overflow;
  emxArray_real_T *r15;
  emxArray_real_T b_y_data;
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
  st.site = &ad_emlrtRSI;
  for (ix = 0; ix < 2; ix++) {
    sz[ix] = (uint32_T)x->size[ix];
  }

  y_size[0] = (int32_T)sz[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    y_size[0] = (int32_T)sz[0];
    k = (int32_T)sz[0];
    for (ix = 0; ix < k; ix++) {
      y_data[ix] = 0.0;
    }
  } else {
    b_st.site = &pg_emlrtRSI;
    ix = 0;
    s = x->data[0];
    b_st.site = &wc_emlrtRSI;
    if (2 > x->size[1]) {
      overflow = false;
    } else {
      overflow = (x->size[1] > 2147483646);
    }

    if (overflow) {
      c_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 2; k <= x->size[1]; k++) {
      ix++;
      s += x->data[ix];
    }

    y_data[0] = s;
  }

  b_emxInit_real_T(&st, &r15, 1, &lc_emlrtRTEI, true);
  b_y_data.data = (real_T *)y_data;
  b_y_data.size = (int32_T *)y_size;
  b_y_data.allocatedSize = -1;
  b_y_data.numDimensions = 1;
  b_y_data.canFreeData = false;
  c_rdivide(sp, &b_y_data, x->size[1], r15);
  y_size[0] = r15->size[0];
  k = r15->size[0];
  for (ix = 0; ix < k; ix++) {
    y_data[ix] = r15->data[ix];
  }

  emxFree_real_T(&r15);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
real_T c_mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv76[2] = { 1, 31 };

  const mxArray *m34;
  char_T cv114[31];
  int32_T i;
  static const char_T cv115[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'm', 'e', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i',
    'a', 'l', 'E', 'm', 'p', 't', 'y' };

  const mxArray *c_y;
  static const int32_T iv77[2] = { 1, 36 };

  char_T cv116[36];
  static const char_T cv117[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  overflow = !isequal(x);
  st.site = &xc_emlrtRSI;
  if (overflow) {
  } else {
    b_y = NULL;
    m34 = emlrtCreateCharArray(2, iv76);
    for (i = 0; i < 31; i++) {
      cv114[i] = cv115[i];
    }

    emlrtInitCharArrayR2013a(&st, 31, m34, cv114);
    emlrtAssign(&b_y, m34);
    b_st.site = &nj_emlrtRSI;
    f_error(&b_st, b_message(&b_st, b_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  st.site = &yc_emlrtRSI;
  if (overflow) {
  } else {
    c_y = NULL;
    m34 = emlrtCreateCharArray(2, iv77);
    for (i = 0; i < 36; i++) {
      cv116[i] = cv117[i];
    }

    emlrtInitCharArrayR2013a(&st, 36, m34, cv116);
    emlrtAssign(&c_y, m34);
    b_st.site = &nj_emlrtRSI;
    f_error(&b_st, b_message(&b_st, c_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  st.site = &ad_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    b_st.site = &bd_emlrtRSI;
    if (2 > x->size[0]) {
      overflow = false;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

    if (overflow) {
      c_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (i = 2; i <= x->size[0]; i++) {
      y += x->data[i - 1];
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
  real_T y;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv21[2] = { 1, 31 };

  const mxArray *m11;
  char_T cv35[31];
  int32_T i;
  static const char_T cv36[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'm', 'e', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i',
    'a', 'l', 'E', 'm', 'p', 't', 'y' };

  const mxArray *c_y;
  static const int32_T iv22[2] = { 1, 36 };

  char_T cv37[36];
  static const char_T cv38[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  overflow = !b_isequal(x);
  st.site = &xc_emlrtRSI;
  if (overflow) {
  } else {
    b_y = NULL;
    m11 = emlrtCreateCharArray(2, iv21);
    for (i = 0; i < 31; i++) {
      cv35[i] = cv36[i];
    }

    emlrtInitCharArrayR2013a(&st, 31, m11, cv35);
    emlrtAssign(&b_y, m11);
    b_st.site = &nj_emlrtRSI;
    f_error(&b_st, b_message(&b_st, b_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  st.site = &yc_emlrtRSI;
  if (overflow) {
  } else {
    c_y = NULL;
    m11 = emlrtCreateCharArray(2, iv22);
    for (i = 0; i < 36; i++) {
      cv37[i] = cv38[i];
    }

    emlrtInitCharArrayR2013a(&st, 36, m11, cv37);
    emlrtAssign(&c_y, m11);
    b_st.site = &nj_emlrtRSI;
    f_error(&b_st, b_message(&b_st, c_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  st.site = &ad_emlrtRSI;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    b_st.site = &bd_emlrtRSI;
    if (2 > x->size[1]) {
      overflow = false;
    } else {
      overflow = (x->size[1] > 2147483646);
    }

    if (overflow) {
      c_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (i = 2; i <= x->size[1]; i++) {
      y += x->data[i - 1];
    }
  }

  y /= (real_T)x->size[1];
  return y;
}

/* End of code generation (mean.c) */
