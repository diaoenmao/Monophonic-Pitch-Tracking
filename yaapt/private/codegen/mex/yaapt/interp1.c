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
#include "spec_trk.h"
#include "error1.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "pchip.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo gi_emlrtRSI = { 41, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo hi_emlrtRSI = { 153, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo ii_emlrtRSI = { 155, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo ji_emlrtRSI = { 162, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo ki_emlrtRSI = { 168, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo li_emlrtRSI = { 173, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo mi_emlrtRSI = { 175, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo ni_emlrtRSI = { 200, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo oi_emlrtRSI = { 21, "fliplr",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\fliplr.m" };

static emlrtRSInfo pi_emlrtRSI = { 242, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo qi_emlrtRSI = { 263, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo ri_emlrtRSI = { 267, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRTEInfo ic_emlrtRTEI = { 1, 15, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRTEInfo ve_emlrtRTEI = { 144, 15, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRTEInfo we_emlrtRTEI = { 114, 23, "interp1",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

/* Function Definitions */

/*
 *
 */
void interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
             emxArray_real_T *varargin_2, const emxArray_real_T *varargin_3,
             emxArray_real_T *Vq)
{
  emxArray_real_T *y;
  int32_T high_i;
  int32_T nd2;
  emxArray_real_T *x;
  int32_T nx;
  uint32_T outsize[2];
  uint32_T uv2[2];
  boolean_T overflow;
  int32_T k;
  emxArray_real_T *pp_breaks;
  emxArray_real_T *pp_coefs;
  emxArray_real_T *b_y;
  int32_T exitg1;
  int32_T mid_i;
  real_T xloc;
  real_T v;
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
  emxInit_real_T(sp, &y, 2, &ic_emlrtRTEI, true);
  st.site = &gi_emlrtRSI;
  high_i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_2->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, high_i, (int32_T)sizeof(real_T),
                    &ic_emlrtRTEI);
  nd2 = varargin_2->size[0] * varargin_2->size[1];
  for (high_i = 0; high_i < nd2; high_i++) {
    y->data[high_i] = varargin_2->data[high_i];
  }

  emxInit_real_T(&st, &x, 2, &ic_emlrtRTEI, true);
  high_i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = varargin_1->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)x, high_i, (int32_T)sizeof(real_T),
                    &ic_emlrtRTEI);
  nd2 = varargin_1->size[0] * varargin_1->size[1];
  for (high_i = 0; high_i < nd2; high_i++) {
    x->data[high_i] = varargin_1->data[high_i];
  }

  nx = varargin_1->size[1];
  if (varargin_1->size[1] == varargin_2->size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &we_emlrtRTEI,
      "Coder:MATLAB:interp1_YInvalidLength", 0);
  }

  for (high_i = 0; high_i < 2; high_i++) {
    outsize[high_i] = (uint32_T)varargin_3->size[high_i];
  }

  if (varargin_1->size[1] > 1) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ve_emlrtRTEI,
      "MATLAB:interp1:NotEnoughPts", 0);
  }

  for (high_i = 0; high_i < 2; high_i++) {
    uv2[high_i] = (uint32_T)varargin_3->size[high_i];
  }

  high_i = Vq->size[0] * Vq->size[1];
  Vq->size[0] = 1;
  Vq->size[1] = (int32_T)outsize[1];
  emxEnsureCapacity(&st, (emxArray__common *)Vq, high_i, (int32_T)sizeof(real_T),
                    &ic_emlrtRTEI);
  nd2 = (int32_T)outsize[1];
  for (high_i = 0; high_i < nd2; high_i++) {
    Vq->data[high_i] = 0.0;
  }

  if (varargin_3->size[1] == 0) {
  } else {
    b_st.site = &hi_emlrtRSI;
    overflow = (varargin_1->size[1] > 2147483646);
    if (overflow) {
      c_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    k = 1;
    emxInit_real_T(&st, &pp_breaks, 2, &ic_emlrtRTEI, true);
    emxInit_real_T(&st, &pp_coefs, 2, &ic_emlrtRTEI, true);
    emxInit_real_T(&st, &b_y, 2, &ic_emlrtRTEI, true);
    do {
      exitg1 = 0;
      if (k <= nx) {
        if (muDoubleScalarIsNaN(varargin_1->data[k - 1])) {
          b_st.site = &ii_emlrtRSI;
          h_error(&b_st);
        } else {
          k++;
        }
      } else {
        if (varargin_1->data[1] < varargin_1->data[0]) {
          nd2 = asr_s32(nx, 1U);
          b_st.site = &ji_emlrtRSI;
          for (mid_i = 1; mid_i <= nd2; mid_i++) {
            xloc = x->data[mid_i - 1];
            x->data[mid_i - 1] = x->data[nx - mid_i];
            x->data[nx - mid_i] = xloc;
          }

          b_st.site = &ki_emlrtRSI;
          nd2 = asr_s32(varargin_2->size[1], 1U);
          c_st.site = &oi_emlrtRSI;
          for (mid_i = 1; mid_i <= nd2; mid_i++) {
            high_i = varargin_2->size[1] - mid_i;
            xloc = y->data[mid_i - 1];
            y->data[mid_i - 1] = y->data[high_i];
            y->data[high_i] = xloc;
          }
        }

        b_st.site = &li_emlrtRSI;
        for (k = 1; k + 1 <= nx; k++) {
          if (x->data[k] <= x->data[k - 1]) {
            b_st.site = &mi_emlrtRSI;
            i_error(&b_st);
          }
        }

        b_st.site = &ni_emlrtRSI;
        high_i = Vq->size[0] * Vq->size[1];
        Vq->size[0] = 1;
        Vq->size[1] = (int32_T)uv2[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)Vq, high_i, (int32_T)sizeof
                          (real_T), &ic_emlrtRTEI);
        nd2 = (int32_T)uv2[1];
        for (high_i = 0; high_i < nd2; high_i++) {
          Vq->data[high_i] = 0.0;
        }

        nd2 = y->size[1];
        high_i = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = nd2;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_y, high_i, (int32_T)
                          sizeof(real_T), &ic_emlrtRTEI);
        for (high_i = 0; high_i < nd2; high_i++) {
          b_y->data[b_y->size[0] * high_i] = y->data[high_i];
        }

        c_st.site = &pi_emlrtRSI;
        pchip(&c_st, x, b_y, pp_breaks, pp_coefs);
        c_st.site = &qi_emlrtRSI;
        overflow = (varargin_3->size[1] > 2147483646);
        if (overflow) {
          d_st.site = &ib_emlrtRSI;
          check_forloop_overflow_error(&d_st, true);
        }

        for (k = 0; k + 1 <= varargin_3->size[1]; k++) {
          if (muDoubleScalarIsNaN(varargin_3->data[k])) {
            Vq->data[k] = rtNaN;
          } else {
            c_st.site = &ri_emlrtRSI;
            if (muDoubleScalarIsNaN(varargin_3->data[k])) {
              v = varargin_3->data[k];
            } else {
              nx = 1;
              nd2 = 2;
              high_i = pp_breaks->size[1];
              while (high_i > nd2) {
                mid_i = asr_s32(nx, 1U) + asr_s32(high_i, 1U);
                if (((nx & 1) == 1) && ((high_i & 1) == 1)) {
                  mid_i++;
                }

                if (varargin_3->data[k] >= pp_breaks->data[mid_i - 1]) {
                  nx = mid_i;
                  nd2 = mid_i + 1;
                } else {
                  high_i = mid_i;
                }
              }

              xloc = varargin_3->data[k] - pp_breaks->data[nx - 1];
              v = pp_coefs->data[nx - 1];
              for (nd2 = 0; nd2 < 3; nd2++) {
                v = xloc * v + pp_coefs->data[(nx + (nd2 + 1) * (pp_breaks->
                  size[1] - 1)) - 1];
              }
            }

            Vq->data[k] = v;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_real_T(&b_y);
    emxFree_real_T(&pp_coefs);
    emxFree_real_T(&pp_breaks);
  }

  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (interp1.c) */
