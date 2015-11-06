/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sqrt.h"
#include "eml_error.h"
#include "yaapt_data.h"

/* Function Definitions */

/*
 *
 */
void b_sqrt(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T k;
  int32_T i42;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (k = 0; k < x->size[0]; k++) {
    if (x->data[k] < 0.0) {
      st.site = &p_emlrtRSI;
      eml_error(&st);
    }
  }

  i42 = x->size[0];
  for (k = 0; k < i42; k++) {
    x->data[k] = muDoubleScalarSqrt(x->data[k]);
  }
}

/*
 *
 */
void c_sqrt(const emlrtStack *sp, real_T *x)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (*x < 0.0) {
    st.site = &p_emlrtRSI;
    eml_error(&st);
  }

  *x = muDoubleScalarSqrt(*x);
}

/* End of code generation (sqrt.c) */
