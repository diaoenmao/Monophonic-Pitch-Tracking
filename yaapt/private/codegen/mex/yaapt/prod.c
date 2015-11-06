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
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo pf_emlrtRSI = { 68, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtMCInfo fb_emlrtMCI = { 18, 9, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtMCInfo gb_emlrtMCI = { 17, 19, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtRTEInfo ac_emlrtRTEI = { 53, 1, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtRTEInfo bc_emlrtRTEI = { 1, 14, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtRSInfo vj_emlrtRSI = { 18, "prod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\prod.m" };

static emlrtRSInfo ok_emlrtRSI = { 17, "prod",
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
  const mxArray *b_y;
  static const int32_T iv42[2] = { 1, 31 };

  const mxArray *m21;
  char_T cv67[31];
  int32_T i;
  static const char_T cv68[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'p', 'r', 'o', 'd', '_', 's', 'p', 'e', 'c', 'i',
    'a', 'l', 'E', 'm', 'p', 't', 'y' };

  uint32_T sz[2];
  int32_T ixstart;
  int32_T ix;
  int32_T iy;
  real_T b_p;
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
    b_y = NULL;
    m21 = emlrtCreateCharArray(2, iv42);
    for (i = 0; i < 31; i++) {
      cv67[i] = cv68[i];
    }

    emlrtInitCharArrayR2013a(sp, 31, m21, cv67);
    emlrtAssign(&b_y, m21);
    st.site = &ok_emlrtRSI;
    b_st.site = &vj_emlrtRSI;
    f_error(&st, b_message(&b_st, b_y, &fb_emlrtMCI), &gb_emlrtMCI);
  }

  for (k = 0; k < 2; k++) {
    sz[k] = (uint32_T)x->size[k];
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &ac_emlrtRTEI);
  if (x->size[1] == 0) {
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &bc_emlrtRTEI);
    k = y->size[0] * y->size[1];
    y->size[1] = (int32_T)sz[1];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &bc_emlrtRTEI);
    ixstart = (int32_T)sz[1];
    for (k = 0; k < ixstart; k++) {
      y->data[k] = 1.0;
    }
  } else {
    ix = -1;
    iy = -1;
    st.site = &pf_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      c_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (i = 1; i <= x->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      b_p = x->data[ixstart];
      for (k = 0; k < 3; k++) {
        ix++;
        b_p *= x->data[ix];
      }

      iy++;
      y->data[iy] = b_p;
    }
  }
}

/* End of code generation (prod.c) */
