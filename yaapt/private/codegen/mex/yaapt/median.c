/*
 * median.c
 *
 * Code generation for function 'median'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "median.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ck_emlrtRSI = { 53, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRSInfo dk_emlrtRSI = { 54, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRSInfo ek_emlrtRSI = { 98, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRSInfo fk_emlrtRSI = { 101, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo gk_emlrtRSI = { 234, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo hk_emlrtRSI = { 239, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo ik_emlrtRSI = { 292, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo xc_emlrtRTEI = { 1, 14, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo yc_emlrtRTEI = { 92, 14, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo ad_emlrtRTEI = { 98, 1, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo bd_emlrtRTEI = { 234, 1, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo ig_emlrtRTEI = { 24, 19, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo jg_emlrtRTEI = { 21, 19, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

/* Function Declarations */
static real_T vectormedian(const emlrtStack *sp, const emxArray_real_T *v);

/* Function Definitions */

/*
 *
 */
static real_T vectormedian(const emlrtStack *sp, const emxArray_real_T *v)
{
  real_T m;
  emxArray_int32_T *idx;
  int32_T i;
  int32_T midm1;
  uint32_T unnamed_idx_0;
  int32_T k;
  emxArray_int32_T *iwork;
  int32_T n;
  boolean_T overflow;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
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
  emxInit_int32_T1(sp, &idx, 1, &ad_emlrtRTEI, true);
  i = v->size[0];
  midm1 = asr_s32(i + (i < 0), 1U);
  st.site = &ek_emlrtRSI;
  unnamed_idx_0 = (uint32_T)v->size[0];
  i = idx->size[0];
  idx->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity(&st, (emxArray__common *)idx, i, (int32_T)sizeof(int32_T),
                    &yc_emlrtRTEI);
  k = (int32_T)unnamed_idx_0;
  for (i = 0; i < k; i++) {
    idx->data[i] = 0;
  }

  if (v->size[0] == 0) {
  } else {
    emxInit_int32_T1(&st, &iwork, 1, &bd_emlrtRTEI, true);
    b_st.site = &fk_emlrtRSI;
    n = v->size[0] + 1;
    c_st.site = &gk_emlrtRSI;
    i = iwork->size[0];
    iwork->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity(&c_st, (emxArray__common *)iwork, i, (int32_T)sizeof
                      (int32_T), &yc_emlrtRTEI);
    c_st.site = &hk_emlrtRSI;
    if (1 > v->size[0] - 1) {
      overflow = false;
    } else {
      overflow = (v->size[0] - 1 > 2147483645);
    }

    if (overflow) {
      d_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (k = 1; k <= n - 2; k += 2) {
      if ((v->data[k - 1] <= v->data[k]) || muDoubleScalarIsNaN(v->data[k])) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    if ((v->size[0] & 1) != 0) {
      idx->data[v->size[0] - 1] = v->size[0];
    }

    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((v->data[idx->data[p - 1] - 1] <= v->data[idx->data[q] - 1]) ||
              muDoubleScalarIsNaN(v->data[idx->data[q] - 1])) {
            overflow = true;
          } else {
            overflow = false;
          }

          if (overflow) {
            iwork->data[k] = idx->data[p - 1];
            p++;
            if (p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                iwork->data[k] = idx->data[q];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q];
            q++;
            if (q + 1 == qEnd) {
              while (p < pEnd) {
                k++;
                iwork->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        c_st.site = &ik_emlrtRSI;
        for (k = 0; k + 1 <= kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }

        j = qEnd;
      }

      i = i2;
    }

    emxFree_int32_T(&iwork);
  }

  if (muDoubleScalarIsNaN(v->data[idx->data[idx->size[0] - 1] - 1])) {
    m = v->data[idx->data[idx->size[0] - 1] - 1];
  } else if (midm1 << 1 == v->size[0]) {
    if (((v->data[idx->data[midm1 - 1] - 1] < 0.0) && (v->data[idx->data[midm1]
          - 1] >= 0.0)) || muDoubleScalarIsInf(v->data[idx->data[midm1 - 1] - 1])
        || muDoubleScalarIsInf(v->data[idx->data[midm1] - 1])) {
      m = (v->data[idx->data[midm1 - 1] - 1] + v->data[idx->data[midm1] - 1]) /
        2.0;
    } else {
      m = v->data[idx->data[midm1 - 1] - 1] + (v->data[idx->data[midm1] - 1] -
        v->data[idx->data[midm1 - 1] - 1]) / 2.0;
    }
  } else {
    m = v->data[idx->data[midm1] - 1];
  }

  emxFree_int32_T(&idx);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return m;
}

/*
 *
 */
void median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  uint32_T sz[2];
  int32_T ub_loop;
  int32_T loop_ub;
  int32_T i;
  emxArray_real_T *b_x;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i35;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack d_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  overflow = !c_isequal(x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &jg_emlrtRTEI,
      "Coder:toolbox:median_specialEmpty", 0);
  }

  if (((x->size[0] == 1) && (x->size[1] == 1)) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ig_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  for (ub_loop = 0; ub_loop < 2; ub_loop++) {
    sz[ub_loop] = (uint32_T)x->size[ub_loop];
  }

  ub_loop = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, ub_loop, (int32_T)sizeof(real_T),
                    &xc_emlrtRTEI);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    ub_loop = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, ub_loop, (int32_T)sizeof(real_T),
                      &xc_emlrtRTEI);
    loop_ub = y->size[1];
    for (ub_loop = 0; ub_loop < loop_ub; ub_loop++) {
      y->data[y->size[0] * ub_loop] = rtNaN;
    }
  } else {
    ub_loop = x->size[1];
    st.site = &ck_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    emlrtEnterParallelRegion(sp, omp_in_parallel());
    emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(b_x,b_i,b_loop_ub,i35,b_emlrtJBEnviron) \
 firstprivate(c_st,d_st,emlrtHadParallelError)

    {
      if (setjmp(b_emlrtJBEnviron) == 0) {
        c_st.prev = sp;
        c_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
        c_st.site = NULL;
        emlrtSetJmpBuf(&c_st, &b_emlrtJBEnviron);
        d_st.prev = &c_st;
        d_st.tls = c_st.tls;
        emxInit_real_T1(&c_st, &b_x, 1, &xc_emlrtRTEI, true);
      } else {
        emlrtHadParallelError = true;
      }

#pragma omp for nowait

      for (i = 1; i <= ub_loop; i++) {
        if (emlrtHadParallelError)
          continue;
        if (setjmp(b_emlrtJBEnviron) == 0) {
          b_i = i;
          b_loop_ub = x->size[0];
          i35 = b_x->size[0];
          b_x->size[0] = b_loop_ub;
          emxEnsureCapacity(&c_st, (emxArray__common *)b_x, i35, (int32_T)sizeof
                            (real_T), &xc_emlrtRTEI);
          for (i35 = 0; i35 < b_loop_ub; i35++) {
            b_x->data[i35] = x->data[i35 + x->size[0] * (b_i - 1)];
          }

          d_st.site = &dk_emlrtRSI;
          y->data[b_i - 1] = vectormedian(&d_st, b_x);
        } else {
          emlrtHadParallelError = true;
        }
      }

      if (!emlrtHadParallelError) {
        emlrtHeapReferenceStackLeaveScope(&c_st, 1);
        emxFree_real_T(&b_x);
      }
    }

    emlrtPopJmpBuf(sp, &emlrtJBStack);
    emlrtExitParallelRegion(sp, omp_in_parallel());
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (median.c) */
