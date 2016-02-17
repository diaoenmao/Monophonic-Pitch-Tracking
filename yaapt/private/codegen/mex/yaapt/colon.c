/*
 * colon.c
 *
 * Code generation for function 'colon'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "colon.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo id_emlrtRSI = { 151, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo jd_emlrtRSI = { 156, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo ab_emlrtRTEI = { 146, 14, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

/* Function Definitions */

/*
 *
 */
void eml_signed_integer_colon(const emlrtStack *sp, int32_T b, emxArray_int32_T *
  y)
{
  int32_T n;
  int32_T yk;
  boolean_T b3;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &id_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (b < 1) {
    n = 0;
  } else {
    n = b;
  }

  yk = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity(sp, (emxArray__common *)y, yk, (int32_T)sizeof(int32_T),
                    &ab_emlrtRTEI);
  if (n > 0) {
    y->data[0] = 1;
    yk = 1;
    st.site = &jd_emlrtRSI;
    if (2 > n) {
      b3 = false;
    } else {
      b3 = (n > 2147483646);
    }

    if (b3) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (k = 2; k <= n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }
}

/* End of code generation (colon.c) */
