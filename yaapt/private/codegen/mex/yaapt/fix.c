/*
 * fix.c
 *
 * Code generation for function 'fix'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "fix.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ji_emlrtRSI = { 10, "fix",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\fix.m" };

/* Function Definitions */
void b_fix(real_T *x)
{
  if (*x < 0.0) {
    *x = muDoubleScalarCeil(*x);
  } else {
    *x = muDoubleScalarFloor(*x);
  }
}

void c_fix(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  real_T b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ji_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[0];
  b_st.site = &cb_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    if (x->data[k] < 0.0) {
      b_x = muDoubleScalarCeil(x->data[k]);
    } else {
      b_x = muDoubleScalarFloor(x->data[k]);
    }

    x->data[k] = b_x;
  }
}

/* End of code generation (fix.c) */
