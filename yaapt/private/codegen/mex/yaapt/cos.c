/*
 * cos.c
 *
 * Code generation for function 'cos'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cos.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 10, "cos",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\cos.m" };

/* Function Definitions */

/*
 *
 */
void b_cos(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[0];
  b_st.site = &eb_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarCos(x->data[k]);
  }
}

/* End of code generation (cos.c) */
