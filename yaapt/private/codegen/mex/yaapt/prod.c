/*
 * prod.c
 *
 * Code generation for function 'prod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "prod.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo si_emlrtRSI = { 11, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtRTEInfo tc_emlrtRTEI = { 1, 14, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

/* Function Definitions */

/*
 *
 */
void prod(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  uint32_T sz[2];
  int32_T ixstart;
  int32_T k;
  int32_T vlen;
  int32_T ix;
  int32_T iy;
  int32_T i;
  real_T s;
  boolean_T b13;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &si_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (((x->size[0] == 1) && (x->size[1] == 1)) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &lf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = !c_isequal(x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &mf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &eg_emlrtRSI;
  for (ixstart = 0; ixstart < 2; ixstart++) {
    sz[ixstart] = (uint32_T)x->size[ixstart];
  }

  ixstart = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)y, ixstart, (int32_T)sizeof
                    (real_T), &tc_emlrtRTEI);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    ixstart = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, ixstart, (int32_T)sizeof
                      (real_T), &tc_emlrtRTEI);
    k = y->size[1];
    for (ixstart = 0; ixstart < k; ixstart++) {
      y->data[y->size[0] * ixstart] = 1.0;
    }
  } else {
    vlen = x->size[0];
    ix = -1;
    iy = -1;
    c_st.site = &fg_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      d_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (i = 1; i <= x->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      c_st.site = &gg_emlrtRSI;
      if (2 > vlen) {
        b13 = false;
      } else {
        b13 = (vlen > 2147483646);
      }

      if (b13) {
        d_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (k = 2; k <= vlen; k++) {
        ix++;
        s *= x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

/* End of code generation (prod.c) */
