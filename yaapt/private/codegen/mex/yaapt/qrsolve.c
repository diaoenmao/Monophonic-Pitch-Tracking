/*
 * qrsolve.c
 *
 * Code generation for function 'qrsolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "qrsolve.h"
#include "error1.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wd_emlrtRSI = { 72, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo xd_emlrtRSI = { 79, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo yd_emlrtRSI = { 86, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo ae_emlrtRSI = { 89, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo be_emlrtRSI = { 29, "xunormqr",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m" };

static emlrtRSInfo ce_emlrtRSI = { 97, "xunormqr",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m" };

static emlrtRTEInfo cb_emlrtRTEI = { 54, 14, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

/* Function Definitions */

/*
 *
 */
void LSQFromQR(const emlrtStack *sp, const emxArray_real_T *A, const
               emxArray_real_T *tau, const emxArray_int32_T *jpvt,
               emxArray_real_T *B, int32_T rankA, emxArray_real_T *Y)
{
  int32_T mn;
  int32_T j;
  ptrdiff_t nrc_t;
  boolean_T p;
  boolean_T b4;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  mn = A->size[1];
  j = Y->size[0];
  Y->size[0] = mn;
  emxEnsureCapacity(sp, (emxArray__common *)Y, j, (int32_T)sizeof(real_T),
                    &cb_emlrtRTEI);
  for (j = 0; j < mn; j++) {
    Y->data[j] = 0.0;
  }

  st.site = &wd_emlrtRSI;
  b_st.site = &be_emlrtRSI;
  mn = muIntScalarMin_sint32(A->size[0], A->size[1]);
  if ((!((A->size[0] == 0) || (A->size[1] == 0))) && (!(B->size[0] == 0))) {
    nrc_t = (ptrdiff_t)B->size[0];
    nrc_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)1, (ptrdiff_t)mn,
      &A->data[0], (ptrdiff_t)A->size[0], &tau->data[0], &B->data[0], nrc_t);
    mn = (int32_T)nrc_t;
    c_st.site = &ce_emlrtRSI;
    if (mn != 0) {
      if (mn == -1010) {
        d_st.site = &cd_emlrtRSI;
        e_error(&d_st);
      } else {
        d_st.site = &dd_emlrtRSI;
        h_error(&d_st, mn);
      }

      p = true;
    } else {
      p = false;
    }

    if (p) {
      mn = B->size[0];
      j = B->size[0];
      B->size[0] = mn;
      emxEnsureCapacity(&b_st, (emxArray__common *)B, j, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (j = 0; j < mn; j++) {
        B->data[j] = rtNaN;
      }
    }
  }

  st.site = &xd_emlrtRSI;
  if (1 > rankA) {
    b4 = false;
  } else {
    b4 = (rankA > 2147483646);
  }

  if (b4) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st, true);
  }

  for (mn = 0; mn + 1 <= rankA; mn++) {
    Y->data[jpvt->data[mn] - 1] = B->data[mn];
  }

  st.site = &yd_emlrtRSI;
  for (j = rankA - 1; j + 1 > 0; j--) {
    Y->data[jpvt->data[j] - 1] /= A->data[j + A->size[0] * j];
    st.site = &ae_emlrtRSI;
    for (mn = 0; mn + 1 <= j; mn++) {
      Y->data[jpvt->data[mn] - 1] -= Y->data[jpvt->data[j] - 1] * A->data[mn +
        A->size[0] * j];
    }
  }
}

/*
 *
 */
void b_LSQFromQR(const emlrtStack *sp, const emxArray_real_T *A, const
                 emxArray_real_T *tau, const emxArray_int32_T *jpvt, real_T B,
                 int32_T rankA, emxArray_real_T *Y)
{
  int32_T mn;
  int32_T j;
  ptrdiff_t nrc_t;
  boolean_T p;
  boolean_T b23;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  mn = A->size[1];
  j = Y->size[0];
  Y->size[0] = mn;
  emxEnsureCapacity(sp, (emxArray__common *)Y, j, (int32_T)sizeof(real_T),
                    &cb_emlrtRTEI);
  for (j = 0; j < mn; j++) {
    Y->data[j] = 0.0;
  }

  st.site = &wd_emlrtRSI;
  b_st.site = &be_emlrtRSI;
  mn = muIntScalarMin_sint32(1, A->size[1]);
  if (!(A->size[1] == 0)) {
    nrc_t = (ptrdiff_t)1;
    nrc_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)1, (ptrdiff_t)mn,
      &A->data[0], (ptrdiff_t)1, &tau->data[0], &B, nrc_t);
    mn = (int32_T)nrc_t;
    c_st.site = &ce_emlrtRSI;
    if (mn != 0) {
      if (mn == -1010) {
        d_st.site = &cd_emlrtRSI;
        e_error(&d_st);
      } else {
        d_st.site = &dd_emlrtRSI;
        h_error(&d_st, mn);
      }

      p = true;
    } else {
      p = false;
    }

    if (p) {
      B = rtNaN;
    }
  }

  st.site = &xd_emlrtRSI;
  if (1 > rankA) {
    b23 = false;
  } else {
    b23 = (rankA > 2147483646);
  }

  if (b23) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st, true);
  }

  for (mn = 1; mn <= rankA; mn++) {
    Y->data[jpvt->data[mn - 1] - 1] = B;
  }

  st.site = &yd_emlrtRSI;
  for (j = rankA - 1; j + 1 > 0; j--) {
    Y->data[jpvt->data[j] - 1] /= A->data[j + A->size[0] * j];
    st.site = &ae_emlrtRSI;
    for (mn = 0; mn + 1 <= j; mn++) {
      Y->data[jpvt->data[mn] - 1] -= Y->data[jpvt->data[j] - 1] * A->data[mn +
        A->size[0] * j];
    }
  }
}

/* End of code generation (qrsolve.c) */
