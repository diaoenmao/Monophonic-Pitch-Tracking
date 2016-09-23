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
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo lk_emlrtRSI = { 78, "median",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRSInfo mk_emlrtRSI = { 79, "median",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRSInfo nk_emlrtRSI = { 140, "median",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRSInfo ok_emlrtRSI = { 101, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo pk_emlrtRSI = { 239, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo qk_emlrtRSI = { 292, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo fd_emlrtRTEI = { 1, 14, "median",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo gd_emlrtRTEI = { 234, 9, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo hd_emlrtRTEI = { 140, 1, "median",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo id_emlrtRTEI = { 234, 1, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo ig_emlrtRTEI = { 20, 19, "median",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo jg_emlrtRTEI = { 17, 19, "median",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

/* Function Definitions */
void median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  int32_T ub_loop;
  int32_T loop_ub;
  int32_T i;
  emxArray_int32_T *iwork;
  emxArray_int32_T *idx;
  int32_T b_i;
  int32_T midm1;
  int32_T i33;
  int32_T c_i;
  real_T m;
  boolean_T p;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  overflow = !b_isequal(x);
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

  ub_loop = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, ub_loop, (int32_T)sizeof(real_T),
                    &fd_emlrtRTEI);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    ub_loop = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, ub_loop, (int32_T)sizeof(real_T),
                      &fd_emlrtRTEI);
    loop_ub = y->size[1];
    for (ub_loop = 0; ub_loop < loop_ub; ub_loop++) {
      y->data[y->size[0] * ub_loop] = rtNaN;
    }
  } else {
    ub_loop = x->size[1];
    st.site = &lk_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    emlrtEnterParallelRegion(sp, omp_in_parallel());
    emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(iwork,idx,b_i,midm1,i33,c_i,m,p,i2,j,pEnd,b_p,q,qEnd,kEnd,b_emlrtJBEnviron) \
 firstprivate(c_st,d_st,e_st,f_st,g_st,h_st,emlrtHadParallelError)

    {
      if (setjmp(b_emlrtJBEnviron) == 0) {
        c_st.prev = sp;
        c_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
        c_st.site = NULL;
        emlrtSetJmpBuf(&c_st, &b_emlrtJBEnviron);
        d_st.prev = &c_st;
        d_st.tls = c_st.tls;
        e_st.prev = &d_st;
        e_st.tls = d_st.tls;
        f_st.prev = &e_st;
        f_st.tls = e_st.tls;
        g_st.prev = &f_st;
        g_st.tls = f_st.tls;
        h_st.prev = &g_st;
        h_st.tls = g_st.tls;
        emxInit_int32_T1(&c_st, &iwork, 1, &id_emlrtRTEI, true);
        emxInit_int32_T1(&c_st, &idx, 1, &hd_emlrtRTEI, true);
      } else {
        emlrtHadParallelError = true;
      }

#pragma omp for nowait

      for (i = 1; i <= ub_loop; i++) {
        if (emlrtHadParallelError)
          continue;
        if (setjmp(b_emlrtJBEnviron) == 0) {
          b_i = i;
          d_st.site = &mk_emlrtRSI;
          e_st.site = &nk_emlrtRSI;
          midm1 = x->size[0];
          i33 = idx->size[0];
          idx->size[0] = midm1;
          emxEnsureCapacity(&e_st, (emxArray__common *)idx, i33, (int32_T)sizeof
                            (int32_T), &fd_emlrtRTEI);
          for (i33 = 0; i33 < midm1; i33++) {
            idx->data[i33] = 0;
          }

          f_st.site = &ok_emlrtRSI;
          i33 = x->size[0] + 1;
          c_i = iwork->size[0];
          iwork->size[0] = midm1;
          emxEnsureCapacity(&f_st, (emxArray__common *)iwork, c_i, (int32_T)
                            sizeof(int32_T), &gd_emlrtRTEI);
          g_st.site = &pk_emlrtRSI;
          if ((!(1 > i33 - 2)) && (i33 - 2 > 2147483645)) {
            h_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&h_st);
          }

          for (midm1 = 1; midm1 <= i33 - 2; midm1 += 2) {
            m = x->data[midm1 + x->size[0] * (b_i - 1)];
            if ((x->data[(midm1 + x->size[0] * (b_i - 1)) - 1] <= m) ||
                muDoubleScalarIsNaN(m)) {
              p = true;
            } else {
              p = false;
            }

            if (p) {
              idx->data[midm1 - 1] = midm1;
              idx->data[midm1] = midm1 + 1;
            } else {
              idx->data[midm1 - 1] = midm1 + 1;
              idx->data[midm1] = midm1;
            }
          }

          c_i = x->size[0];
          if ((c_i & 1) != 0) {
            c_i = x->size[0] - 1;
            midm1 = x->size[0];
            idx->data[c_i] = midm1;
          }

          c_i = 2;
          while (c_i < i33 - 1) {
            i2 = c_i << 1;
            j = 1;
            for (pEnd = 1 + c_i; pEnd < i33; pEnd = qEnd + c_i) {
              b_p = j;
              q = pEnd;
              qEnd = j + i2;
              if (qEnd > i33) {
                qEnd = i33;
              }

              midm1 = 0;
              kEnd = qEnd - j;
              while (midm1 + 1 <= kEnd) {
                m = x->data[(idx->data[q - 1] + x->size[0] * (b_i - 1)) - 1];
                if ((x->data[(idx->data[b_p - 1] + x->size[0] * (b_i - 1)) - 1] <=
                     m) || muDoubleScalarIsNaN(m)) {
                  p = true;
                } else {
                  p = false;
                }

                if (p) {
                  iwork->data[midm1] = idx->data[b_p - 1];
                  b_p++;
                  if (b_p == pEnd) {
                    while (q < qEnd) {
                      midm1++;
                      iwork->data[midm1] = idx->data[q - 1];
                      q++;
                    }
                  }
                } else {
                  iwork->data[midm1] = idx->data[q - 1];
                  q++;
                  if (q == qEnd) {
                    while (b_p < pEnd) {
                      midm1++;
                      iwork->data[midm1] = idx->data[b_p - 1];
                      b_p++;
                    }
                  }
                }

                midm1++;
              }

              g_st.site = &qk_emlrtRSI;
              for (midm1 = 0; midm1 + 1 <= kEnd; midm1++) {
                idx->data[(j + midm1) - 1] = iwork->data[midm1];
              }

              j = qEnd;
            }

            c_i = i2;
          }

          i33 = x->size[0];
          midm1 = i33 >> 1;
          i33 = x->size[0];
          if (muDoubleScalarIsNaN(x->data[(idx->data[i33 - 1] + x->size[0] *
                (b_i - 1)) - 1])) {
            m = rtNaN;
          } else {
            i33 = x->size[0];
            if ((i33 & 1) == 0) {
              if (((x->data[(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1]
                    < 0.0) && (x->data[(idx->data[midm1] + x->size[0] * (b_i - 1))
                               - 1] >= 0.0)) || muDoubleScalarIsInf(x->data
                   [(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1]) ||
                  muDoubleScalarIsInf(x->data[(idx->data[midm1] + x->size[0] *
                    (b_i - 1)) - 1])) {
                m = (x->data[(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1]
                     + x->data[(idx->data[midm1] + x->size[0] * (b_i - 1)) - 1])
                  / 2.0;
              } else {
                m = x->data[(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1]
                  + (x->data[(idx->data[midm1] + x->size[0] * (b_i - 1)) - 1] -
                     x->data[(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1])
                  / 2.0;
              }
            } else {
              m = x->data[(idx->data[midm1] + x->size[0] * (b_i - 1)) - 1];
            }
          }

          y->data[b_i - 1] = m;
        } else {
          emlrtHadParallelError = true;
        }
      }

      if (!emlrtHadParallelError) {
        emlrtHeapReferenceStackLeaveScope(&c_st, 2);
        emxFree_int32_T(&idx);
        emxFree_int32_T(&iwork);
      }
    }

    emlrtPopJmpBuf(sp, &emlrtJBStack);
    emlrtExitParallelRegion(sp, omp_in_parallel());
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (median.c) */
