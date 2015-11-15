/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * median.c
 *
 * Code generation for function 'median'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "median.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo ac_emlrtRTEI = { 1, 14, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

/* Function Definitions */

/*
 *
 */
void median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T ub_loop;
  boolean_T overflow;
  int32_T i;
  int32_T b_i;
  int32_T idx[5];
  int32_T c_i;
  int32_T iwork[5];
  int32_T k;
  boolean_T p;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
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
  ub_loop = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, ub_loop, (int32_T)sizeof(real_T),
                    &ac_emlrtRTEI);
  ub_loop = x->size[1];
  st.site = &ch_emlrtRSI;
  if (1 > x->size[1]) {
    overflow = false;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(b_i,c_i,k,p,i2,j,pEnd,b_p,q,qEnd,kEnd,m,b_emlrtJBEnviron) \
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

    for (i = 1; i <= ub_loop; i++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        b_i = i;
        for (c_i = 0; c_i < 5; c_i++) {
          idx[c_i] = 0;
        }

        for (k = 0; k <= 2; k += 2) {
          if ((x->data[k + x->size[0] * (b_i - 1)] <= x->data[(k + x->size[0] *
                (b_i - 1)) + 1]) || muDoubleScalarIsNaN(x->data[(k + x->size[0] *
                (b_i - 1)) + 1])) {
            p = true;
          } else {
            p = false;
          }

          if (p) {
            idx[k] = k + 1;
            idx[k + 1] = k + 2;
          } else {
            idx[k] = k + 2;
            idx[k + 1] = k + 1;
          }
        }

        idx[4] = 5;
        c_i = 2;
        while (c_i < 5) {
          i2 = c_i << 1;
          j = 1;
          for (pEnd = 1 + c_i; pEnd < 6; pEnd = qEnd + c_i) {
            b_p = j;
            q = pEnd - 1;
            qEnd = j + i2;
            if (qEnd > 6) {
              qEnd = 6;
            }

            k = 0;
            kEnd = qEnd - j;
            while (k + 1 <= kEnd) {
              if ((x->data[(idx[b_p - 1] + x->size[0] * (b_i - 1)) - 1] <=
                   x->data[(idx[q] + x->size[0] * (b_i - 1)) - 1]) ||
                  muDoubleScalarIsNaN(x->data[(idx[q] + x->size[0] * (b_i - 1))
                                      - 1])) {
                p = true;
              } else {
                p = false;
              }

              if (p) {
                iwork[k] = idx[b_p - 1];
                b_p++;
                if (b_p == pEnd) {
                  while (q + 1 < qEnd) {
                    k++;
                    iwork[k] = idx[q];
                    q++;
                  }
                }
              } else {
                iwork[k] = idx[q];
                q++;
                if (q + 1 == qEnd) {
                  while (b_p < pEnd) {
                    k++;
                    iwork[k] = idx[b_p - 1];
                    b_p++;
                  }
                }
              }

              k++;
            }

            for (k = 0; k + 1 <= kEnd; k++) {
              idx[(j + k) - 1] = iwork[k];
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

/* End of code generation (median.c) */
