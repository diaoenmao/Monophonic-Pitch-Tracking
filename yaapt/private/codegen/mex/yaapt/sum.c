/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sum.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Function Definitions */

/*
 *
 */
real_T b_sum(const emlrtStack *sp, const emxArray_boolean_T *x)
{
  real_T y;
  boolean_T overflow;
  boolean_T p;
  int32_T i;
  int32_T exitg1;
  const mxArray *b_y;
  static const int32_T iv51[2] = { 1, 30 };

  const mxArray *m25;
  char_T cv80[30];
  static const char_T cv81[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 's', 'u', 'm', '_', 's', 'p', 'e', 'c', 'i', 'a',
    'l', 'E', 'm', 'p', 't', 'y' };

  const mxArray *c_y;
  static const int32_T iv52[2] = { 1, 36 };

  char_T cv82[36];
  static const char_T cv83[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  overflow = false;
  p = false;
  i = 0;
  do {
    exitg1 = 0;
    if (i < 2) {
      if (x->size[i] != 0) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    b_y = NULL;
    m25 = emlrtCreateCharArray(2, iv51);
    for (i = 0; i < 30; i++) {
      cv80[i] = cv81[i];
    }

    emlrtInitCharArrayR2013a(sp, 30, m25, cv80);
    emlrtAssign(&b_y, m25);
    st.site = &mk_emlrtRSI;
    b_st.site = &uj_emlrtRSI;
    f_error(&st, b_message(&b_st, b_y, &m_emlrtMCI), &n_emlrtMCI);
  }

  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    c_y = NULL;
    m25 = emlrtCreateCharArray(2, iv52);
    for (i = 0; i < 36; i++) {
      cv82[i] = cv83[i];
    }

    emlrtInitCharArrayR2013a(sp, 36, m25, cv82);
    emlrtAssign(&c_y, m25);
    st.site = &lk_emlrtRSI;
    b_st.site = &tj_emlrtRSI;
    f_error(&st, b_message(&b_st, c_y, &o_emlrtMCI), &p_emlrtMCI);
  }

  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    st.site = &bd_emlrtRSI;
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
      y += (real_T)x->data[i - 1];
    }
  }

  return y;
}

/*
 *
 */
real_T sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv43[2] = { 1, 30 };

  const mxArray *m22;
  char_T cv69[30];
  int32_T i;
  static const char_T cv70[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 's', 'u', 'm', '_', 's', 'p', 'e', 'c', 'i', 'a',
    'l', 'E', 'm', 'p', 't', 'y' };

  const mxArray *c_y;
  static const int32_T iv44[2] = { 1, 36 };

  char_T cv71[36];
  static const char_T cv72[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  overflow = !b_isequal(x);
  if (overflow) {
  } else {
    b_y = NULL;
    m22 = emlrtCreateCharArray(2, iv43);
    for (i = 0; i < 30; i++) {
      cv69[i] = cv70[i];
    }

    emlrtInitCharArrayR2013a(sp, 30, m22, cv69);
    emlrtAssign(&b_y, m22);
    st.site = &mk_emlrtRSI;
    b_st.site = &uj_emlrtRSI;
    f_error(&st, b_message(&b_st, b_y, &m_emlrtMCI), &n_emlrtMCI);
  }

  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    c_y = NULL;
    m22 = emlrtCreateCharArray(2, iv44);
    for (i = 0; i < 36; i++) {
      cv71[i] = cv72[i];
    }

    emlrtInitCharArrayR2013a(sp, 36, m22, cv71);
    emlrtAssign(&c_y, m22);
    st.site = &lk_emlrtRSI;
    b_st.site = &tj_emlrtRSI;
    f_error(&st, b_message(&b_st, c_y, &o_emlrtMCI), &p_emlrtMCI);
  }

  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    st.site = &bd_emlrtRSI;
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

  return y;
}

/* End of code generation (sum.c) */
