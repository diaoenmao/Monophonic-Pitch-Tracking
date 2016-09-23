/*
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo no_emlrtRSI = { 108, "diff",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" };

static emlrtRSInfo oo_emlrtRSI = { 106, "diff",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" };

static emlrtRTEInfo qe_emlrtRTEI = { 1, 14, "diff",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" };

static emlrtRTEInfo sg_emlrtRTEI = { 51, 19, "diff",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" };

/* Function Definitions */
void b_diff(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T ySize_idx_1;
  boolean_T overflow;
  int32_T iyLead;
  real_T work_data_idx_0;
  int32_T m;
  real_T tmp1;
  real_T tmp2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ySize_idx_1 = x->size[1] - 1;
  if (muIntScalarMin_sint32(ySize_idx_1, 1) < 1) {
    iyLead = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)y, iyLead, (int32_T)sizeof(real_T),
                      &qe_emlrtRTEI);
  } else {
    overflow = (x->size[1] != 1);
    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(sp, &sg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    ySize_idx_1 = x->size[1] - 1;
    iyLead = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = ySize_idx_1;
    emxEnsureCapacity(sp, (emxArray__common *)y, iyLead, (int32_T)sizeof(real_T),
                      &qe_emlrtRTEI);
    if (!(y->size[1] == 0)) {
      ySize_idx_1 = 1;
      iyLead = 0;
      work_data_idx_0 = x->data[0];
      st.site = &oo_emlrtRSI;
      overflow = ((!(2 > x->size[1])) && (x->size[1] > 2147483646));
      if (overflow) {
        b_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (m = 2; m <= x->size[1]; m++) {
        tmp1 = x->data[ySize_idx_1];
        st.site = &no_emlrtRSI;
        tmp2 = work_data_idx_0;
        work_data_idx_0 = tmp1;
        tmp1 -= tmp2;
        ySize_idx_1++;
        y->data[iyLead] = tmp1;
        iyLead++;
      }
    }
  }
}

void diff(const real_T x[6], real_T y[5])
{
  int32_T ixLead;
  int32_T iyLead;
  real_T work;
  int32_T m;
  real_T tmp2;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 5; m++) {
    tmp2 = work;
    work = x[ixLead];
    tmp2 = x[ixLead] - tmp2;
    ixLead++;
    y[iyLead] = tmp2;
    iyLead++;
  }
}

/* End of code generation (diff.c) */
