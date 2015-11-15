/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo jh_emlrtRSI = { 56, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

static emlrtRTEInfo gc_emlrtRTEI = { 1, 14, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

/* Function Definitions */

/*
 *
 */
void b_mean(const emlrtStack *sp, const emxArray_real_T *x, real_T y_data[],
            int32_T y_size[1])
{
  int32_T vlen;
  int32_T ix;
  real_T s;
  boolean_T b11;
  int32_T k;
  emxArray_real_T *r14;
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
  st.site = &ed_emlrtRSI;
  y_size[0] = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vlen = y_size[0];
    y_size[0] = vlen;
    for (ix = 0; ix < vlen; ix++) {
      y_data[ix] = 0.0;
    }
  } else {
    vlen = x->size[1];
    b_st.site = &jh_emlrtRSI;
    ix = 0;
    s = x->data[0];
    b_st.site = &dd_emlrtRSI;
    if (2 > vlen) {
      b11 = false;
    } else {
      b11 = (vlen > 2147483646);
    }

    if (b11) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 2; k <= vlen; k++) {
      ix++;
      s += x->data[ix];
    }

    y_data[0] = s;
  }

  emxInit_real_T1(&st, &r14, 1, &gc_emlrtRTEI, true);
  b_y_data.data = (real_T *)y_data;
  b_y_data.size = (int32_T *)y_size;
  b_y_data.allocatedSize = -1;
  b_y_data.numDimensions = 1;
  b_y_data.canFreeData = false;
  c_rdivide(sp, &b_y_data, x->size[1], r14);
  y_size[0] = r14->size[0];
  vlen = r14->size[0];
  for (ix = 0; ix < vlen; ix++) {
    y_data[ix] = r14->data[ix];
  }

  emxFree_real_T(&r14);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
real_T mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  boolean_T b3;
  real_T b_x;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b3 = true;
  } else {
    b3 = false;
  }

  if (b3) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ae_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  b3 = !b_isequal(x);
  if (b3) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &yd_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b3 = !b_isequal(x);
  if (b3) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &xd_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  st.site = &ed_emlrtRSI;
  b_x = combine_vector_elements(&st, x);
  return b_x / (real_T)x->size[1];
}

/* End of code generation (mean.c) */
