/*
 * mpower.c
 *
 * Code generation for function 'mpower'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mpower.h"
#include "error1.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo fc_emlrtRSI = { 37, "mpower",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m" };

static emlrtRSInfo hc_emlrtRSI = { 61, "power",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

/* Function Definitions */

/*
 *
 */
real_T b_mpower(const emlrtStack *sp, real_T a, real_T b)
{
  real_T c;
  boolean_T p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gc_emlrtRSI;
  c = muDoubleScalarPower(a, b);
  p = false;
  if (a < 0.0) {
    if (muDoubleScalarIsNaN(b) || (muDoubleScalarFloor(b) == b)) {
      p = true;
    } else {
      p = false;
    }

    p = !p;
  }

  if (p) {
    c_st.site = &hc_emlrtRSI;
    d_error(&c_st);
  }

  return c;
}

/*
 *
 */
real_T mpower(real_T a)
{
  return a * a;
}

/* End of code generation (mpower.c) */
