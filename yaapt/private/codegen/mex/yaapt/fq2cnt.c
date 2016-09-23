/*
 * fq2cnt.c
 *
 * Code generation for function 'fq2cnt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "fq2cnt.h"
#include "error1.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wm_emlrtRSI = { 10, "fq2cnt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\fq2cnt.m" };

static emlrtRSInfo xm_emlrtRSI = { 24, "log2",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m" };

static emlrtRSInfo ym_emlrtRSI = { 27, "log2",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m" };

static emlrtRSInfo an_emlrtRSI = { 53, "applyScalarFunction",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"
};

static emlrtRTEInfo je_emlrtRTEI = { 1, 18, "fq2cnt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\fq2cnt.m" };

/* Function Definitions */
void fq2cnt(const emlrtStack *sp, const emxArray_real_T *fq, emxArray_real_T
            *cnt)
{
  emxArray_real_T *x;
  int32_T k;
  int32_T loop_ub;
  boolean_T overflow;
  int32_T b_k;
  int32_T c_k;
  real_T t;
  int32_T eint;
  int32_T inte;
  jmp_buf * volatile emlrtJBStack;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &x, 2, &je_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 22U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 22U, 0);

  /*  FQ2CNT Transform input frequency to cent unit */
  /*  */
  /*  fq = input frequency */
  /*  cnt = output cent scale with base at 13.75 Hz */
  /*  Each piano key frequency is linearly separated 100 cents  */
  /*  Ex: A4 - Ab4 */
  /*  fq2cnt(440) - fq2cnt(415.305) = 6000 - 5900 = 100 */
  /*  */
  k = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = fq->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)x, k, (int32_T)sizeof(real_T),
                    &je_emlrtRTEI);
  loop_ub = fq->size[0] * fq->size[1];
  for (k = 0; k < loop_ub; k++) {
    x->data[k] = fq->data[k] / 13.75;
  }

  st.site = &wm_emlrtRSI;
  overflow = false;
  for (k = 0; k < x->size[1]; k++) {
    if (overflow || (x->data[k] < 0.0)) {
      overflow = true;
    } else {
      overflow = false;
    }
  }

  if (overflow) {
    b_st.site = &xm_emlrtRSI;
    m_error(&b_st);
  }

  b_st.site = &ym_emlrtRSI;
  k = cnt->size[0] * cnt->size[1];
  cnt->size[0] = 1;
  cnt->size[1] = x->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)cnt, k, (int32_T)sizeof(real_T),
                    &je_emlrtRTEI);
  k = x->size[1];
  c_st.site = &an_emlrtRSI;
  overflow = ((!(1 > x->size[1])) && (x->size[1] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  emlrtEnterParallelRegion(&b_st, omp_in_parallel());
  emlrtPushJmpBuf(&b_st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(c_k,t,inte) \
 firstprivate(eint)

  for (b_k = 1; b_k <= k; b_k++) {
    c_k = b_k;
    if (x->data[c_k - 1] == 0.0) {
      t = rtMinusInf;
    } else if (x->data[c_k - 1] < 0.0) {
      t = rtNaN;
    } else if ((!muDoubleScalarIsInf(x->data[c_k - 1])) && (!muDoubleScalarIsNaN
                (x->data[c_k - 1]))) {
      if ((!muDoubleScalarIsInf(x->data[c_k - 1])) && (!muDoubleScalarIsNaN
           (x->data[c_k - 1]))) {
        t = frexp(x->data[c_k - 1], &eint);
        inte = eint;
      } else {
        t = x->data[c_k - 1];
        inte = 0;
      }

      if (t == 0.5) {
        t = (real_T)inte - 1.0;
      } else {
        t = muDoubleScalarLog(t) / 0.69314718055994529 + (real_T)inte;
      }
    } else {
      t = x->data[c_k - 1];
    }

    cnt->data[c_k - 1] = t;
  }

  emlrtPopJmpBuf(&b_st, &emlrtJBStack);
  emlrtExitParallelRegion(&b_st, omp_in_parallel());
  emxFree_real_T(&x);
  k = cnt->size[0] * cnt->size[1];
  cnt->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)cnt, k, (int32_T)sizeof(real_T),
                    &je_emlrtRTEI);
  k = cnt->size[0];
  loop_ub = cnt->size[1];
  loop_ub *= k;
  for (k = 0; k < loop_ub; k++) {
    cnt->data[k] *= 1200.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fq2cnt.c) */
