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
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo gm_emlrtRSI = { 10, "fq2cnt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\fq2cnt.m" };

static emlrtRSInfo hm_emlrtRSI = { 23, "log2",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m" };

static emlrtRSInfo im_emlrtRSI = { 24, "log2",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m" };

static emlrtRSInfo jm_emlrtRSI = { 27, "log2",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m" };

static emlrtRSInfo km_emlrtRSI = { 53, "applyScalarFunction",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m" };

static emlrtRTEInfo qd_emlrtRTEI = { 1, 18, "fq2cnt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\fq2cnt.m" };

/* Function Definitions */

/*
 * function [cnt] = fq2cnt(fq)
 */
void fq2cnt(const emlrtStack *sp, const emxArray_real_T *fq, emxArray_real_T
            *cnt)
{
  emxArray_real_T *x;
  boolean_T overflow;
  int32_T k;
  uint32_T uv7[2];
  int32_T b_cnt;
  int32_T b_k;
  int32_T c_k;
  real_T fdbl;
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
  emxInit_real_T(sp, &x, 2, &qd_emlrtRTEI, true);

  /*  FQ2CNT Transform input frequency to cent unit */
  /*  */
  /*  fq = input frequency */
  /*  cnt = output cent scale with base at 13.75 Hz */
  /*  Each piano key frequency is linearly separated 100 cents  */
  /*  Ex: A4 - Ab4 */
  /*  fq2cnt(440) - fq2cnt(415.305) = 6000 - 5900 = 100 */
  /*  */
  /* 'fq2cnt:10' cnt = 1200.*log2((fq./13.75)); */
  c_rdivide(sp, fq, 13.75, x);
  st.site = &gm_emlrtRSI;
  b_st.site = &hm_emlrtRSI;
  overflow = false;
  for (k = 0; k < x->size[1]; k++) {
    if (overflow || (x->data[k] < 0.0)) {
      overflow = true;
    } else {
      overflow = false;
    }
  }

  if (overflow) {
    b_st.site = &im_emlrtRSI;
    m_error(&b_st);
  }

  b_st.site = &jm_emlrtRSI;
  for (b_cnt = 0; b_cnt < 2; b_cnt++) {
    uv7[b_cnt] = (uint32_T)x->size[b_cnt];
  }

  b_cnt = cnt->size[0] * cnt->size[1];
  cnt->size[0] = 1;
  cnt->size[1] = (int32_T)uv7[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)cnt, b_cnt, (int32_T)sizeof
                    (real_T), &qd_emlrtRTEI);
  k = x->size[1];
  c_st.site = &km_emlrtRSI;
  if (1 > x->size[1]) {
    overflow = false;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  emlrtEnterParallelRegion(&b_st, omp_in_parallel());
  emlrtPushJmpBuf(&b_st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(c_k,fdbl,inte) \
 firstprivate(eint)

  for (b_k = 1; b_k <= k; b_k++) {
    c_k = b_k;
    if (x->data[c_k - 1] == 0.0) {
      fdbl = rtMinusInf;
    } else if (x->data[c_k - 1] < 0.0) {
      fdbl = rtNaN;
    } else if ((!muDoubleScalarIsInf(x->data[c_k - 1])) && (!muDoubleScalarIsNaN
                (x->data[c_k - 1]))) {
      if ((!muDoubleScalarIsInf(x->data[c_k - 1])) && (!muDoubleScalarIsNaN
           (x->data[c_k - 1]))) {
        fdbl = frexp(x->data[c_k - 1], &eint);
        inte = eint;
      } else {
        fdbl = x->data[c_k - 1];
        inte = 0;
      }

      if (fdbl == 0.5) {
        fdbl = (real_T)inte - 1.0;
      } else {
        fdbl = muDoubleScalarLog(fdbl) / 0.69314718055994529 + (real_T)inte;
      }
    } else {
      fdbl = x->data[c_k - 1];
    }

    cnt->data[c_k - 1] = fdbl;
  }

  emlrtPopJmpBuf(&b_st, &emlrtJBStack);
  emlrtExitParallelRegion(&b_st, omp_in_parallel());
  emxFree_real_T(&x);
  b_cnt = cnt->size[0] * cnt->size[1];
  cnt->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)cnt, b_cnt, (int32_T)sizeof(real_T),
                    &qd_emlrtRTEI);
  k = cnt->size[0];
  b_cnt = cnt->size[1];
  k *= b_cnt;
  for (b_cnt = 0; b_cnt < k; b_cnt++) {
    cnt->data[b_cnt] *= 1200.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fq2cnt.c) */
