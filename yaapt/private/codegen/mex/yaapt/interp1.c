/*
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "interp1.h"
#include "median.h"
#include "yaapt_emxutil.h"
#include "error1.h"
#include "eml_int_forloop_overflow_check.h"
#include "pchip.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sk_emlrtRSI = { 41, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo tk_emlrtRSI = { 153, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo uk_emlrtRSI = { 155, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo vk_emlrtRSI = { 162, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo wk_emlrtRSI = { 168, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo xk_emlrtRSI = { 173, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo yk_emlrtRSI = { 175, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo al_emlrtRSI = { 200, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo bl_emlrtRSI = { 21, "fliplr",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\fliplr.m" };

static emlrtRSInfo cl_emlrtRSI = { 242, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo dl_emlrtRSI = { 263, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRTEInfo nd_emlrtRTEI = { 1, 15, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRTEInfo od_emlrtRTEI = { 240, 9, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRTEInfo lg_emlrtRTEI = { 144, 15, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRTEInfo mg_emlrtRTEI = { 114, 23, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

/* Function Definitions */

/*
 *
 */
void interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
             emxArray_real_T *varargin_2, const emxArray_real_T *varargin_3,
             emxArray_real_T *Vq)
{
  emxArray_real_T *y;
  int32_T j2;
  int32_T nd2;
  emxArray_real_T *x;
  int32_T nx;
  uint32_T outsize[2];
  uint32_T uv5[2];
  boolean_T overflow;
  emxArray_real_T *xi;
  b_struct_T pp;
  emxArray_real_T *b_y;
  int32_T exitg1;
  int32_T b_j1;
  real_T xtmp;
  int32_T k;
  int32_T b_k;
  real_T v;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  real_T xloc;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  jmp_buf b_emlrtJBEnviron;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &y, 2, &nd_emlrtRTEI, true);
  st.site = &sk_emlrtRSI;
  j2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_2->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, j2, (int32_T)sizeof(real_T),
                    &nd_emlrtRTEI);
  nd2 = varargin_2->size[0] * varargin_2->size[1];
  for (j2 = 0; j2 < nd2; j2++) {
    y->data[j2] = varargin_2->data[j2];
  }

  emxInit_real_T(&st, &x, 2, &nd_emlrtRTEI, true);
  j2 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = varargin_1->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)x, j2, (int32_T)sizeof(real_T),
                    &nd_emlrtRTEI);
  nd2 = varargin_1->size[0] * varargin_1->size[1];
  for (j2 = 0; j2 < nd2; j2++) {
    x->data[j2] = varargin_1->data[j2];
  }

  nx = varargin_1->size[1];
  if (varargin_1->size[1] == varargin_2->size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &mg_emlrtRTEI,
      "Coder:MATLAB:interp1_YInvalidLength", 0);
  }

  for (j2 = 0; j2 < 2; j2++) {
    outsize[j2] = (uint32_T)varargin_3->size[j2];
  }

  if (varargin_1->size[1] > 1) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &lg_emlrtRTEI,
      "MATLAB:interp1:NotEnoughPts", 0);
  }

  for (j2 = 0; j2 < 2; j2++) {
    uv5[j2] = (uint32_T)varargin_3->size[j2];
  }

  j2 = Vq->size[0] * Vq->size[1];
  Vq->size[0] = 1;
  Vq->size[1] = (int32_T)outsize[1];
  emxEnsureCapacity(&st, (emxArray__common *)Vq, j2, (int32_T)sizeof(real_T),
                    &nd_emlrtRTEI);
  nd2 = (int32_T)outsize[1];
  for (j2 = 0; j2 < nd2; j2++) {
    Vq->data[j2] = 0.0;
  }

  if (varargin_3->size[1] == 0) {
  } else {
    b_st.site = &tk_emlrtRSI;
    overflow = (varargin_1->size[1] > 2147483646);
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    nd2 = 1;
    emxInit_real_T(&st, &xi, 2, &nd_emlrtRTEI, true);
    emxInitStruct_struct_T(&st, &pp, &od_emlrtRTEI, true);
    emxInit_real_T(&st, &b_y, 2, &nd_emlrtRTEI, true);
    do {
      exitg1 = 0;
      if (nd2 <= nx) {
        if (muDoubleScalarIsNaN(varargin_1->data[nd2 - 1])) {
          b_st.site = &uk_emlrtRSI;
          j_error(&b_st);
        } else {
          nd2++;
        }
      } else {
        if (varargin_1->data[1] < varargin_1->data[0]) {
          nd2 = asr_s32(nx, 1U);
          b_st.site = &vk_emlrtRSI;
          for (b_j1 = 1; b_j1 <= nd2; b_j1++) {
            xtmp = x->data[b_j1 - 1];
            x->data[b_j1 - 1] = x->data[nx - b_j1];
            x->data[nx - b_j1] = xtmp;
          }

          b_st.site = &wk_emlrtRSI;
          nd2 = asr_s32(varargin_2->size[1], 1U);
          c_st.site = &bl_emlrtRSI;
          for (b_j1 = 1; b_j1 <= nd2; b_j1++) {
            j2 = varargin_2->size[1] - b_j1;
            xtmp = y->data[b_j1 - 1];
            y->data[b_j1 - 1] = y->data[j2];
            y->data[j2] = xtmp;
          }
        }

        b_st.site = &xk_emlrtRSI;
        for (nd2 = 1; nd2 + 1 <= nx; nd2++) {
          if (x->data[nd2] <= x->data[nd2 - 1]) {
            b_st.site = &yk_emlrtRSI;
            k_error(&b_st);
          }
        }

        b_st.site = &al_emlrtRSI;
        j2 = xi->size[0] * xi->size[1];
        xi->size[0] = 1;
        xi->size[1] = varargin_3->size[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)xi, j2, (int32_T)sizeof
                          (real_T), &nd_emlrtRTEI);
        nd2 = varargin_3->size[0] * varargin_3->size[1];
        for (j2 = 0; j2 < nd2; j2++) {
          xi->data[j2] = varargin_3->data[j2];
        }

        j2 = Vq->size[0] * Vq->size[1];
        Vq->size[0] = 1;
        Vq->size[1] = (int32_T)uv5[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)Vq, j2, (int32_T)sizeof
                          (real_T), &nd_emlrtRTEI);
        nd2 = (int32_T)uv5[1];
        for (j2 = 0; j2 < nd2; j2++) {
          Vq->data[j2] = 0.0;
        }

        nd2 = y->size[1];
        j2 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = nd2;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_y, j2, (int32_T)sizeof
                          (real_T), &nd_emlrtRTEI);
        for (j2 = 0; j2 < nd2; j2++) {
          b_y->data[b_y->size[0] * j2] = y->data[j2];
        }

        c_st.site = &cl_emlrtRSI;
        pchip(&c_st, x, b_y, pp.breaks, pp.coefs);
        nd2 = varargin_3->size[1];
        c_st.site = &dl_emlrtRSI;
        overflow = (varargin_3->size[1] > 2147483646);
        if (overflow) {
          d_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&d_st, true);
        }

        emlrtEnterParallelRegion(&b_st, omp_in_parallel());
        emlrtPushJmpBuf(&b_st, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(b_k,low_i,v,low_ip1,high_i,xloc,mid_i,b_emlrtJBEnviron) \
 firstprivate(e_st,b_st,emlrtHadParallelError)

        {
          if (setjmp(b_emlrtJBEnviron) == 0) {
            e_st.prev = &b_st;
            e_st.tls = emlrtAllocTLS(&b_st, omp_get_thread_num());
            e_st.site = NULL;
            emlrtSetJmpBuf(&e_st, &b_emlrtJBEnviron);
          } else {
            emlrtHadParallelError = true;
          }

#pragma omp for nowait

          for (k = 1; k <= nd2; k++) {
            if (emlrtHadParallelError)
              continue;
            if (setjmp(b_emlrtJBEnviron) == 0) {
              b_k = k;
              if (muDoubleScalarIsNaN(xi->data[b_k - 1])) {
                Vq->data[b_k - 1] = rtNaN;
              } else {
                if (muDoubleScalarIsNaN(xi->data[b_k - 1])) {
                  v = xi->data[b_k - 1];
                } else {
                  low_i = 1;
                  low_ip1 = 2;
                  high_i = pp.breaks->size[1];
                  while (high_i > low_ip1) {
                    mid_i = asr_s32(low_i, 1U) + asr_s32(high_i, 1U);
                    if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
                      mid_i++;
                    }

                    if (xi->data[b_k - 1] >= pp.breaks->data[mid_i - 1]) {
                      low_i = mid_i;
                      low_ip1 = mid_i + 1;
                    } else {
                      high_i = mid_i;
                    }
                  }

                  xloc = xi->data[b_k - 1] - pp.breaks->data[low_i - 1];
                  v = pp.coefs->data[low_i - 1];
                  for (low_ip1 = 0; low_ip1 < 3; low_ip1++) {
                    v = xloc * v + pp.coefs->data[(low_i + (low_ip1 + 1) *
                      (pp.breaks->size[1] - 1)) - 1];
                  }
                }

                Vq->data[b_k - 1] = v;
              }
            } else {
              emlrtHadParallelError = true;
            }
          }
        }

        emlrtPopJmpBuf(&b_st, &emlrtJBStack);
        emlrtExitParallelRegion(&b_st, omp_in_parallel());
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_real_T(&b_y);
    emxFreeStruct_struct_T(&pp);
    emxFree_real_T(&xi);
  }

  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (interp1.c) */
