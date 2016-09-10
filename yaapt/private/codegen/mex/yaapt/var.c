/*
 * var.c
 *
 * Code generation for function 'var'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "var.h"
#include "error1.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo jl_emlrtRSI = { 68, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo kl_emlrtRSI = { 138, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo ml_emlrtRSI = { 229, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

static emlrtRSInfo nl_emlrtRSI = { 241, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

/* Function Definitions */

/*
 *
 */
real_T local_var(const emlrtStack *sp, const emxArray_real_T *x, real_T w,
                 boolean_T omitnan)
{
  real_T y;
  int32_T i37;
  boolean_T overflow;
  real_T d;
  int32_T ix;
  real_T xbar;
  int32_T nn;
  int32_T k;
  real_T r;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  i37 = x->size[1];
  if ((w == 0.0) || (w == 1.0)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (!overflow) {
    st.site = &jl_emlrtRSI;
    j_error(&st);
  } else if (omitnan) {
    d = w;
  } else if ((w == 0.0) && (x->size[1] > 1)) {
    d = (real_T)x->size[1] - 1.0;
  } else {
    d = x->size[1];
  }

  if (x->size[1] == 0) {
    y = 0.0;
  } else if (omitnan) {
    st.site = &kl_emlrtRSI;
    y = 0.0;
    ix = 0;
    xbar = 0.0;
    nn = 0;
    b_st.site = &ml_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 1; k <= i37; k++) {
      if (!muDoubleScalarIsNaN(x->data[ix])) {
        xbar += x->data[ix];
        nn++;
      }

      ix++;
    }

    if (nn == 0) {
      y = rtNaN;
    } else {
      xbar /= (real_T)nn;
      ix = 0;
      b_st.site = &nl_emlrtRSI;
      overflow = (x->size[1] > 2147483646);
      if (overflow) {
        c_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (k = 1; k <= i37; k++) {
        if (!muDoubleScalarIsNaN(x->data[ix])) {
          r = x->data[ix] - xbar;
          y += r * r;
        }

        ix++;
      }

      if ((d == 0.0) && (nn > 1)) {
        nn--;
      }

      y /= (real_T)nn;
    }
  } else {
    st.site = &ll_emlrtRSI;
    ix = 0;
    xbar = x->data[0];
    b_st.site = &ol_emlrtRSI;
    overflow = ((!(2 > x->size[1])) && (x->size[1] > 2147483646));
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 2; k <= i37; k++) {
      ix++;
      xbar += x->data[ix];
    }

    xbar /= (real_T)x->size[1];
    ix = 0;
    r = x->data[0] - xbar;
    y = r * r;
    b_st.site = &pl_emlrtRSI;
    overflow = ((!(2 > x->size[1])) && (x->size[1] > 2147483646));
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 2; k <= i37; k++) {
      ix++;
      r = x->data[ix] - xbar;
      y += r * r;
    }

    y /= d;
  }

  return y;
}

/* End of code generation (var.c) */
