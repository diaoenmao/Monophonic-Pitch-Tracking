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
#include "eml_error.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "pchip.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo sg_emlrtRSI = { 41, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo tg_emlrtRSI = { 114, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo ug_emlrtRSI = { 144, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo vg_emlrtRSI = { 153, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo wg_emlrtRSI = { 155, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo xg_emlrtRSI = { 162, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo yg_emlrtRSI = { 168, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo ah_emlrtRSI = { 173, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo bh_emlrtRSI = { 175, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo ch_emlrtRSI = { 200, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo dh_emlrtRSI = { 15, "fliplr",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\fliplr.m" };

static emlrtRSInfo eh_emlrtRSI = { 242, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo fh_emlrtRSI = { 253, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo gh_emlrtRSI = { 259, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtRSInfo sh_emlrtRSI = { 90, "ppval",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

static emlrtRTEInfo nc_emlrtRTEI = { 1, 15, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 1, 1, "", "bsearch",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\bsearch.p", 0 };

/* Function Definitions */

/*
 *
 */
void interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
             emxArray_real_T *varargin_2, const emxArray_real_T *varargin_3,
             emxArray_real_T *Vq)
{
  emxArray_real_T *y;
  int32_T i28;
  int32_T i;
  emxArray_real_T *x;
  const mxArray *b_y;
  static const int32_T iv61[2] = { 1, 35 };

  const mxArray *m30;
  char_T cv96[35];
  static const char_T cv97[35] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'Y', 'I', 'n',
    'v', 'a', 'l', 'i', 'd', 'L', 'e', 'n', 'g', 't', 'h' };

  uint32_T outsize[2];
  const mxArray *c_y;
  static const int32_T iv62[2] = { 1, 27 };

  char_T cv98[27];
  static const char_T cv99[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n',
    't', 'e', 'r', 'p', '1', ':', 'N', 'o', 't', 'E', 'n', 'o', 'u', 'g', 'h',
    'P', 't', 's' };

  boolean_T overflow;
  int32_T k;
  emxArray_real_T *pp_breaks;
  emxArray_real_T *pp_coefs;
  emxArray_real_T *d_y;
  int32_T exitg1;
  int32_T mid_i;
  real_T xloc;
  int32_T high_i;
  real_T yit;
  int32_T low_i;
  int32_T b_low_i;
  int32_T b_high_i;
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
  emxInit_real_T(sp, &y, 2, &nc_emlrtRTEI, true);
  st.site = &sg_emlrtRSI;
  i28 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_2->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, i28, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  i = varargin_2->size[0] * varargin_2->size[1];
  for (i28 = 0; i28 < i; i28++) {
    y->data[i28] = varargin_2->data[i28];
  }

  emxInit_real_T(&st, &x, 2, &nc_emlrtRTEI, true);
  i28 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = varargin_1->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)x, i28, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  i = varargin_1->size[0] * varargin_1->size[1];
  for (i28 = 0; i28 < i; i28++) {
    x->data[i28] = varargin_1->data[i28];
  }

  b_st.site = &tg_emlrtRSI;
  if (varargin_1->size[1] == varargin_2->size[1]) {
  } else {
    b_y = NULL;
    m30 = emlrtCreateCharArray(2, iv61);
    for (i = 0; i < 35; i++) {
      cv96[i] = cv97[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 35, m30, cv96);
    emlrtAssign(&b_y, m30);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, b_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  for (i28 = 0; i28 < 2; i28++) {
    outsize[i28] = (uint32_T)varargin_3->size[i28];
  }

  b_st.site = &ug_emlrtRSI;
  if (varargin_1->size[1] > 1) {
  } else {
    c_y = NULL;
    m30 = emlrtCreateCharArray(2, iv62);
    for (i = 0; i < 27; i++) {
      cv98[i] = cv99[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 27, m30, cv98);
    emlrtAssign(&c_y, m30);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, c_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  i28 = Vq->size[0] * Vq->size[1];
  Vq->size[0] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)Vq, i28, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  i28 = Vq->size[0] * Vq->size[1];
  Vq->size[1] = (int32_T)outsize[1];
  emxEnsureCapacity(&st, (emxArray__common *)Vq, i28, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  i = (int32_T)outsize[1];
  for (i28 = 0; i28 < i; i28++) {
    Vq->data[i28] = 0.0;
  }

  if (varargin_3->size[1] == 0) {
  } else {
    b_st.site = &vg_emlrtRSI;
    if (1 > varargin_1->size[1]) {
      overflow = false;
    } else {
      overflow = (varargin_1->size[1] > 2147483646);
    }

    if (overflow) {
      c_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    k = 1;
    emxInit_real_T(&st, &pp_breaks, 2, &nc_emlrtRTEI, true);
    emxInit_real_T(&st, &pp_coefs, 2, &nc_emlrtRTEI, true);
    emxInit_real_T(&st, &d_y, 2, &nc_emlrtRTEI, true);
    do {
      exitg1 = 0;
      if (k <= varargin_1->size[1]) {
        if (muDoubleScalarIsNaN(varargin_1->data[k - 1])) {
          b_st.site = &wg_emlrtRSI;
          c_eml_error(&b_st);
        } else {
          k++;
        }
      } else {
        if (varargin_1->data[1] < varargin_1->data[0]) {
          i28 = varargin_1->size[1];
          if (i28 >= 0) {
            i = (int32_T)((uint32_T)i28 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i28 >> 1);
          }

          b_st.site = &xg_emlrtRSI;
          for (mid_i = 1; mid_i <= i; mid_i++) {
            xloc = x->data[mid_i - 1];
            x->data[mid_i - 1] = x->data[varargin_1->size[1] - mid_i];
            x->data[varargin_1->size[1] - mid_i] = xloc;
          }

          b_st.site = &yg_emlrtRSI;
          i28 = varargin_2->size[1];
          i28 += (i28 < 0);
          if (i28 >= 0) {
            i = (int32_T)((uint32_T)i28 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i28 >> 1);
          }

          c_st.site = &dh_emlrtRSI;
          for (mid_i = 1; mid_i <= i; mid_i++) {
            high_i = varargin_2->size[1] - mid_i;
            xloc = y->data[y->size[0] * (mid_i - 1)];
            y->data[y->size[0] * (mid_i - 1)] = y->data[y->size[0] * high_i];
            y->data[y->size[0] * high_i] = xloc;
          }
        }

        b_st.site = &ah_emlrtRSI;
        for (k = 1; k + 1 <= varargin_1->size[1]; k++) {
          if (x->data[k] <= x->data[k - 1]) {
            b_st.site = &bh_emlrtRSI;
            d_eml_error(&b_st);
          }
        }

        b_st.site = &ch_emlrtRSI;
        i = y->size[1];
        i28 = d_y->size[0] * d_y->size[1];
        d_y->size[0] = 1;
        d_y->size[1] = i;
        emxEnsureCapacity(&b_st, (emxArray__common *)d_y, i28, (int32_T)sizeof
                          (real_T), &nc_emlrtRTEI);
        for (i28 = 0; i28 < i; i28++) {
          d_y->data[d_y->size[0] * i28] = y->data[i28];
        }

        c_st.site = &eh_emlrtRSI;
        pchip(&c_st, x, d_y, pp_breaks, pp_coefs);
        c_st.site = &fh_emlrtRSI;
        overflow = (varargin_3->size[1] > 2147483646);
        if (overflow) {
          d_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (k = 0; k + 1 <= varargin_3->size[1]; k++) {
          if (muDoubleScalarIsNaN(varargin_3->data[k])) {
            Vq->data[k] = rtNaN;
          } else {
            c_st.site = &gh_emlrtRSI;
            if (muDoubleScalarIsNaN(varargin_3->data[k])) {
              yit = varargin_3->data[k];
            } else {
              d_st.site = &sh_emlrtRSI;
              low_i = 1;
              i = 2;
              high_i = pp_breaks->size[1];
              while (high_i > i) {
                if (low_i >= 0) {
                  b_low_i = (int32_T)((uint32_T)low_i >> 1);
                } else {
                  b_low_i = ~(int32_T)((uint32_T)~low_i >> 1);
                }

                if (high_i >= 0) {
                  b_high_i = (int32_T)((uint32_T)high_i >> 1);
                } else {
                  b_high_i = ~(int32_T)((uint32_T)~high_i >> 1);
                }

                mid_i = b_low_i + b_high_i;
                if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
                  mid_i++;
                }

                i28 = pp_breaks->size[1];
                if (varargin_3->data[k] >= pp_breaks->
                    data[emlrtDynamicBoundsCheckFastR2012b(mid_i, 1, i28,
                     &wf_emlrtBCI, &d_st) - 1]) {
                  low_i = mid_i;
                  i = mid_i + 1;
                } else {
                  high_i = mid_i;
                }
              }

              xloc = varargin_3->data[k] - pp_breaks->data[low_i - 1];
              yit = pp_coefs->data[low_i - 1];
              for (i = 0; i < 3; i++) {
                yit = xloc * yit + pp_coefs->data[(low_i + (i + 1) *
                  (pp_breaks->size[1] - 1)) - 1];
              }
            }

            Vq->data[k] = yit;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_real_T(&d_y);
    emxFree_real_T(&pp_coefs);
    emxFree_real_T(&pp_breaks);
  }

  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (interp1.c) */
