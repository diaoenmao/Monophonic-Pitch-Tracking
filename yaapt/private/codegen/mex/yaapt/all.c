/*
 * all.c
 *
 * Code generation for function 'all'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "all.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo of_emlrtRSI = { 12, "all",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\all.m" };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 126, 24, "", "allOrAny",
  "F:\\MATLAB\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\allOrAny.m", 0
};

/* Function Definitions */

/*
 *
 */
boolean_T all(const emlrtStack *sp, const emxArray_boolean_T *x)
{
  boolean_T y;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv59[2] = { 1, 41 };

  const mxArray *m29;
  char_T cv92[41];
  int32_T i;
  static const char_T cv93[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p',
    't', 'y' };

  const mxArray *c_y;
  static const int32_T iv60[2] = { 1, 51 };

  char_T cv94[51];
  static const char_T cv95[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T exitg1;
  int32_T i27;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &of_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  overflow = !c_isequal(x);
  b_st.site = &sc_emlrtRSI;
  if (overflow) {
  } else {
    b_y = NULL;
    m29 = emlrtCreateCharArray(2, iv59);
    for (i = 0; i < 41; i++) {
      cv92[i] = cv93[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 41, m29, cv92);
    emlrtAssign(&b_y, m29);
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
    m29 = emlrtCreateCharArray(2, iv60);
    for (i = 0; i < 51; i++) {
      cv94[i] = cv95[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 51, m29, cv94);
    emlrtAssign(&c_y, m29);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, c_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  y = true;
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
    i27 = x->size[0];
    if (x->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i27, &vf_emlrtBCI, &st)
        - 1] == 0) {
      y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  return y;
}

/* End of code generation (all.c) */
