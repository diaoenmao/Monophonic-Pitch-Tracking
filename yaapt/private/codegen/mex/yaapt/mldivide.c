/*
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mldivide.h"
#include "xtrsm.h"
#include "lusolve.h"
#include "xgetrf.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = { 1, "mldivide",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

static emlrtRSInfo vb_emlrtRSI = { 128, "lusolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

static emlrtRSInfo wb_emlrtRSI = { 130, "lusolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

/* Function Definitions */

/*
 *
 */
void mldivide(const emlrtStack *sp, const real_T A[5776], real_T B[76])
{
  real_T b_A[5776];
  int32_T info;
  int32_T ipiv[76];
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &sb_emlrtRSI;
  memcpy(&b_A[0], &A[0], 5776U * sizeof(real_T));
  c_st.site = &ub_emlrtRSI;
  xgetrf(&c_st, b_A, ipiv, &info);
  if (info > 0) {
    c_st.site = &tb_emlrtRSI;
    warn_singular(&c_st);
  }

  for (info = 0; info < 75; info++) {
    if (ipiv[info] != info + 1) {
      temp = B[info];
      B[info] = B[ipiv[info] - 1];
      B[ipiv[info] - 1] = temp;
    }
  }

  c_st.site = &vb_emlrtRSI;
  xtrsm(b_A, B);
  c_st.site = &wb_emlrtRSI;
  b_xtrsm(b_A, B);
}

/* End of code generation (mldivide.c) */
