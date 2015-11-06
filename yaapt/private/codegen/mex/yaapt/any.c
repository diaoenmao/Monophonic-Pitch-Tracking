/*
 * any.c
 *
 * Code generation for function 'any'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "any.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo rc_emlrtRSI = { 12, "any",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\any.m" };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 131, 46, "", "allOrAny",
  "F:\\MATLAB\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\allOrAny.m", 0
};

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 131, 26, "", "allOrAny",
  "F:\\MATLAB\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\allOrAny.m", 0
};

/* Function Definitions */

/*
 *
 */
boolean_T any(const boolean_T x[5])
{
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 5)) {
    if (!(x[k] == 0)) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

/*
 *
 */
boolean_T b_any(const emlrtStack *sp, const emxArray_real_T *x)
{
  boolean_T y;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv19[2] = { 1, 41 };

  const mxArray *m10;
  char_T cv31[41];
  int32_T i;
  static const char_T cv32[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p',
    't', 'y' };

  const mxArray *c_y;
  static const int32_T iv20[2] = { 1, 51 };

  char_T cv33[51];
  static const char_T cv34[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T exitg1;
  int32_T i11;
  boolean_T guard1 = false;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  overflow = !isequal(x);
  b_st.site = &sc_emlrtRSI;
  if (overflow) {
  } else {
    b_y = NULL;
    m10 = emlrtCreateCharArray(2, iv19);
    for (i = 0; i < 41; i++) {
      cv31[i] = cv32[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 41, m10, cv31);
    emlrtAssign(&b_y, m10);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, b_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  b_st.site = &tc_emlrtRSI;
  if (overflow) {
  } else {
    c_y = NULL;
    m10 = emlrtCreateCharArray(2, iv20);
    for (i = 0; i < 51; i++) {
      cv33[i] = cv34[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 51, m10, cv33);
    emlrtAssign(&c_y, m10);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, c_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  y = false;
  b_st.site = &uc_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  i = 1;
  exitg1 = false;
  while ((!exitg1) && (i <= x->size[0])) {
    i11 = x->size[0];
    guard1 = false;
    if (x->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i11, &cc_emlrtBCI, &st)
        - 1] == 0.0) {
      guard1 = true;
    } else {
      i11 = x->size[0];
      emlrtDynamicBoundsCheckFastR2012b(i, 1, i11, &bc_emlrtBCI, &st);
      if (muDoubleScalarIsNaN(x->data[i - 1])) {
        guard1 = true;
      } else {
        overflow = false;
      }
    }

    if (guard1) {
      overflow = true;
    }

    if (!overflow) {
      y = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  return y;
}

/*
 *
 */
boolean_T c_any(const emlrtStack *sp, const emxArray_boolean_T *x)
{
  boolean_T y;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv34[2] = { 1, 41 };

  const mxArray *m15;
  char_T cv51[41];
  int32_T i;
  static const char_T cv52[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p',
    't', 'y' };

  const mxArray *c_y;
  static const int32_T iv35[2] = { 1, 51 };

  char_T cv53[51];
  static const char_T cv54[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T exitg1;
  int32_T i16;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  overflow = !c_isequal(x);
  b_st.site = &sc_emlrtRSI;
  if (overflow) {
  } else {
    b_y = NULL;
    m15 = emlrtCreateCharArray(2, iv34);
    for (i = 0; i < 41; i++) {
      cv51[i] = cv52[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 41, m15, cv51);
    emlrtAssign(&b_y, m15);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, b_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  b_st.site = &tc_emlrtRSI;
  if (overflow) {
  } else {
    c_y = NULL;
    m15 = emlrtCreateCharArray(2, iv35);
    for (i = 0; i < 51; i++) {
      cv53[i] = cv54[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 51, m15, cv53);
    emlrtAssign(&c_y, m15);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, c_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  y = false;
  b_st.site = &uc_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  i = 1;
  exitg1 = false;
  while ((!exitg1) && (i <= x->size[0])) {
    i16 = x->size[0];
    if (x->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i16, &cc_emlrtBCI, &st)
        - 1] == 0) {
      overflow = true;
    } else {
      i16 = x->size[0];
      emlrtDynamicBoundsCheckFastR2012b(i, 1, i16, &bc_emlrtBCI, &st);
      overflow = false;
    }

    if (!overflow) {
      y = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  return y;
}

/* End of code generation (any.c) */
