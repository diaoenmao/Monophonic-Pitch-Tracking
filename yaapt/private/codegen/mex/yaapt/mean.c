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
#include "combine_vector_elements.h"
#include "isequal.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wk_emlrtRSI = { 102, "combine_vector_elements",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

/* Function Definitions */
void b_mean(const emlrtStack *sp, const emxArray_real_T *x, real_T y_data[],
            int32_T y_size[1])
{
  int32_T vlen;
  int32_T i40;
  real_T s;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y_size[0] = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vlen = y_size[0];
    for (i40 = 0; i40 < vlen; i40++) {
      y_data[i40] = 0.0;
    }
  } else {
    vlen = x->size[1];
    b_st.site = &wk_emlrtRSI;
    s = x->data[0];
    b_st.site = &rg_emlrtRSI;
    if ((!(2 > vlen)) && (vlen > 2147483646)) {
      c_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 2; k <= vlen; k++) {
      s += x->data[k - 1];
    }

    y_data[0] = s;
  }

  vlen = x->size[1];
  k = y_size[0];
  for (i40 = 0; i40 < k; i40++) {
    y_data[i40] /= (real_T)vlen;
  }
}

real_T mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  boolean_T b0;
  real_T b_x;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &sf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  b0 = !c_isequal(x);
  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &tf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b0 = !c_isequal(x);
  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &uf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  st.site = &sg_emlrtRSI;
  b_x = combine_vector_elements(&st, x);
  return b_x / (real_T)x->size[1];
}

/* End of code generation (mean.c) */
