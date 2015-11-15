/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * prod.c
 *
 * Code generation for function 'prod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "prod.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo tf_emlrtRSI = { 11, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtRTEInfo ub_emlrtRTEI = { 1, 14, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

/* Function Definitions */

/*
 *
 */
void prod(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T ixstart;
  int32_T ix;
  int32_T iy;
  int32_T i;
  real_T s;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (x->size[k] != 0) {
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
    emlrtErrorWithMessageIdR2012b(&st, &sd_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &bd_emlrtRSI;
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &ub_emlrtRTEI);
  if (x->size[1] == 0) {
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &ub_emlrtRTEI);
    ixstart = y->size[1];
    for (k = 0; k < ixstart; k++) {
      y->data[y->size[0] * k] = 1.0;
    }
  } else {
    ix = -1;
    iy = -1;
    c_st.site = &cd_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (i = 1; i <= x->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      for (k = 0; k < 3; k++) {
        ix++;
        s *= x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

/* End of code generation (prod.c) */
