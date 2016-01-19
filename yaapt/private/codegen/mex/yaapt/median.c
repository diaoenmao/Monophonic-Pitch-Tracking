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
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo th_emlrtRSI = { 53, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo ac_emlrtRTEI = { 1, 14, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo af_emlrtRTEI = { 21, 19, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

/* Function Definitions */

/*
 *
 */
void b_median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i44;
  uint32_T sz[2];
  int32_T i;
  int32_T b_i;
  int32_T idx[7];
  int32_T c_i;
  int32_T iwork[7];
  int32_T b_k;
  boolean_T b_p;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T c_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  real_T m;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  jmp_buf b_emlrtJBEnviron;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      i44 = x->size[k];
      if (i44 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &af_emlrtRTEI,
      "Coder:toolbox:median_specialEmpty", 0);
  }

  for (i44 = 0; i44 < 2; i44++) {
    sz[i44] = (uint32_T)x->size[i44];
  }

  i44 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i44, (int32_T)sizeof(real_T),
                    &ac_emlrtRTEI);
  if (x->size[1] == 0) {
    i44 = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, i44, (int32_T)sizeof(real_T),
                      &ac_emlrtRTEI);
    k = y->size[1];
    for (i44 = 0; i44 < k; i44++) {
      y->data[y->size[0] * i44] = rtNaN;
    }
  } else {
    k = x->size[1];
    st.site = &th_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    emlrtEnterParallelRegion(sp, omp_in_parallel());
    emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(b_i,c_i,b_k,b_p,i2,j,pEnd,c_p,q,qEnd,kEnd,m,b_emlrtJBEnviron) \
 firstprivate(c_st,idx,emlrtHadParallelError,iwork)

    {
      if (setjmp(b_emlrtJBEnviron) == 0) {
        c_st.prev = sp;
        c_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
        c_st.site = NULL;
        emlrtSetJmpBuf(&c_st, &b_emlrtJBEnviron);
      } else {
        emlrtHadParallelError = true;
      }

#pragma omp for nowait

      for (i = 1; i <= k; i++) {
        if (emlrtHadParallelError)
          continue;
        if (setjmp(b_emlrtJBEnviron) == 0) {
          b_i = i;
          for (c_i = 0; c_i < 7; c_i++) {
            idx[c_i] = 0;
          }

          for (b_k = 0; b_k <= 4; b_k += 2) {
            if ((x->data[b_k + x->size[0] * (b_i - 1)] <= x->data[(b_k + x->
                  size[0] * (b_i - 1)) + 1]) || muDoubleScalarIsNaN(x->data[(b_k
                  + x->size[0] * (b_i - 1)) + 1])) {
              b_p = true;
            } else {
              b_p = false;
            }

            if (b_p) {
              idx[b_k] = b_k + 1;
              idx[b_k + 1] = b_k + 2;
            } else {
              idx[b_k] = b_k + 2;
              idx[b_k + 1] = b_k + 1;
            }
          }

          idx[6] = 7;
          c_i = 2;
          while (c_i < 7) {
            i2 = c_i << 1;
            j = 1;
            for (pEnd = 1 + c_i; pEnd < 8; pEnd = qEnd + c_i) {
              c_p = j;
              q = pEnd - 1;
              qEnd = j + i2;
              if (qEnd > 8) {
                qEnd = 8;
              }

              b_k = 0;
              kEnd = qEnd - j;
              while (b_k + 1 <= kEnd) {
                if ((x->data[(idx[c_p - 1] + x->size[0] * (b_i - 1)) - 1] <=
                     x->data[(idx[q] + x->size[0] * (b_i - 1)) - 1]) ||
                    muDoubleScalarIsNaN(x->data[(idx[q] + x->size[0] * (b_i - 1))
                     - 1])) {
                  b_p = true;
                } else {
                  b_p = false;
                }

                if (b_p) {
                  iwork[b_k] = idx[c_p - 1];
                  c_p++;
                  if (c_p == pEnd) {
                    while (q + 1 < qEnd) {
                      b_k++;
                      iwork[b_k] = idx[q];
                      q++;
                    }
                  }
                } else {
                  iwork[b_k] = idx[q];
                  q++;
                  if (q + 1 == qEnd) {
                    while (c_p < pEnd) {
                      b_k++;
                      iwork[b_k] = idx[c_p - 1];
                      c_p++;
                    }
                  }
                }

                b_k++;
              }

              for (b_k = 0; b_k + 1 <= kEnd; b_k++) {
                idx[(j + b_k) - 1] = iwork[b_k];
              }

              j = qEnd;
            }

            c_i = i2;
          }

          if (muDoubleScalarIsNaN(x->data[(idx[6] + x->size[0] * (b_i - 1)) - 1]))
          {
            m = x->data[(idx[6] + x->size[0] * (b_i - 1)) - 1];
          } else {
            m = x->data[(idx[3] + x->size[0] * (b_i - 1)) - 1];
          }

          y->data[b_i - 1] = m;
        } else {
          emlrtHadParallelError = true;
        }
      }
    }

    emlrtPopJmpBuf(sp, &emlrtJBStack);
    emlrtExitParallelRegion(sp, omp_in_parallel());
  }
}

/*
 *
 */
void median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i28;
  uint32_T sz[2];
  int32_T i;
  int32_T b_i;
  int32_T idx[5];
  int32_T c_i;
  int32_T iwork[5];
  int32_T b_k;
  boolean_T b_p;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T c_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  real_T m;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  jmp_buf b_emlrtJBEnviron;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      i28 = x->size[k];
      if (i28 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &af_emlrtRTEI,
      "Coder:toolbox:median_specialEmpty", 0);
  }

  for (i28 = 0; i28 < 2; i28++) {
    sz[i28] = (uint32_T)x->size[i28];
  }

  i28 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i28, (int32_T)sizeof(real_T),
                    &ac_emlrtRTEI);
  if (x->size[1] == 0) {
    i28 = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, i28, (int32_T)sizeof(real_T),
                      &ac_emlrtRTEI);
    k = y->size[1];
    for (i28 = 0; i28 < k; i28++) {
      y->data[y->size[0] * i28] = rtNaN;
    }
  } else {
    k = x->size[1];
    st.site = &th_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    emlrtEnterParallelRegion(sp, omp_in_parallel());
    emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(b_i,c_i,b_k,b_p,i2,j,pEnd,c_p,q,qEnd,kEnd,m,b_emlrtJBEnviron) \
 firstprivate(c_st,idx,emlrtHadParallelError,iwork)

    {
      if (setjmp(b_emlrtJBEnviron) == 0) {
        c_st.prev = sp;
        c_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
        c_st.site = NULL;
        emlrtSetJmpBuf(&c_st, &b_emlrtJBEnviron);
      } else {
        emlrtHadParallelError = true;
      }

#pragma omp for nowait

      for (i = 1; i <= k; i++) {
        if (emlrtHadParallelError)
          continue;
        if (setjmp(b_emlrtJBEnviron) == 0) {
          b_i = i;
          for (c_i = 0; c_i < 5; c_i++) {
            idx[c_i] = 0;
          }

          for (b_k = 0; b_k <= 2; b_k += 2) {
            if ((x->data[b_k + x->size[0] * (b_i - 1)] <= x->data[(b_k + x->
                  size[0] * (b_i - 1)) + 1]) || muDoubleScalarIsNaN(x->data[(b_k
                  + x->size[0] * (b_i - 1)) + 1])) {
              b_p = true;
            } else {
              b_p = false;
            }

            if (b_p) {
              idx[b_k] = b_k + 1;
              idx[b_k + 1] = b_k + 2;
            } else {
              idx[b_k] = b_k + 2;
              idx[b_k + 1] = b_k + 1;
            }
          }

          idx[4] = 5;
          c_i = 2;
          while (c_i < 5) {
            i2 = c_i << 1;
            j = 1;
            for (pEnd = 1 + c_i; pEnd < 6; pEnd = qEnd + c_i) {
              c_p = j;
              q = pEnd - 1;
              qEnd = j + i2;
              if (qEnd > 6) {
                qEnd = 6;
              }

              b_k = 0;
              kEnd = qEnd - j;
              while (b_k + 1 <= kEnd) {
                if ((x->data[(idx[c_p - 1] + x->size[0] * (b_i - 1)) - 1] <=
                     x->data[(idx[q] + x->size[0] * (b_i - 1)) - 1]) ||
                    muDoubleScalarIsNaN(x->data[(idx[q] + x->size[0] * (b_i - 1))
                     - 1])) {
                  b_p = true;
                } else {
                  b_p = false;
                }

                if (b_p) {
                  iwork[b_k] = idx[c_p - 1];
                  c_p++;
                  if (c_p == pEnd) {
                    while (q + 1 < qEnd) {
                      b_k++;
                      iwork[b_k] = idx[q];
                      q++;
                    }
                  }
                } else {
                  iwork[b_k] = idx[q];
                  q++;
                  if (q + 1 == qEnd) {
                    while (c_p < pEnd) {
                      b_k++;
                      iwork[b_k] = idx[c_p - 1];
                      c_p++;
                    }
                  }
                }

                b_k++;
              }

              for (b_k = 0; b_k + 1 <= kEnd; b_k++) {
                idx[(j + b_k) - 1] = iwork[b_k];
              }

              j = qEnd;
            }

            c_i = i2;
          }

          if (muDoubleScalarIsNaN(x->data[(idx[4] + x->size[0] * (b_i - 1)) - 1]))
          {
            m = x->data[(idx[4] + x->size[0] * (b_i - 1)) - 1];
          } else {
            m = x->data[(idx[2] + x->size[0] * (b_i - 1)) - 1];
          }

          y->data[b_i - 1] = m;
        } else {
          emlrtHadParallelError = true;
        }
      }
    }

    emlrtPopJmpBuf(sp, &emlrtJBStack);
    emlrtExitParallelRegion(sp, omp_in_parallel());
  }
}

/* End of code generation (median.c) */
