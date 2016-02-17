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
#include "combine_vector_elements.h"
#include "isequal.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
real_T b_sum(const emlrtStack *sp, const emxArray_boolean_T *x)
{
  real_T y;
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i32;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &lf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      i32 = x->size[k];
      if (i32 != 0) {
        exitg1 = 1;
      } else {
        k++;
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
    emlrtErrorWithMessageIdR2012b(&st, &mf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &eg_emlrtRSI;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    c_st.site = &ig_emlrtRSI;
    if (2 > x->size[1]) {
      overflow = false;
    } else {
      overflow = (x->size[1] > 2147483646);
    }

    if (overflow) {
      d_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (k = 2; k <= x->size[1]; k++) {
      y += (real_T)x->data[k - 1];
    }
  }

  return y;
}

/*
 *
 */
real_T sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  boolean_T b14;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b14 = true;
  } else {
    b14 = false;
  }

  if (b14) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &lf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  b14 = !d_isequal(x);
  if (b14) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &mf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &eg_emlrtRSI;
  return combine_vector_elements(&b_st, x);
}

/* End of code generation (sum.c) */
