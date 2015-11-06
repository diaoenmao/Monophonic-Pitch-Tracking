/*
 * pchip.c
 *
 * Code generation for function 'pchip'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "pchip.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo hh_emlrtRSI = { 15, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo ih_emlrtRSI = { 24, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo jh_emlrtRSI = { 40, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo kh_emlrtRSI = { 52, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo lh_emlrtRSI = { 62, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo mh_emlrtRSI = { 84, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo nh_emlrtRSI = { 32, "chckxy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRSInfo oh_emlrtRSI = { 36, "chckxy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRSInfo ph_emlrtRSI = { 38, "chckxy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRSInfo qh_emlrtRSI = { 42, "chckxy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRSInfo rh_emlrtRSI = { 44, "pwchcore",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m" };

static emlrtMCInfo pb_emlrtMCI = { 15, 19, "errorIf",
  "F:\\MATLAB\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\errorIf.m" };

static emlrtRTEInfo oc_emlrtRTEI = { 23, 1, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo pc_emlrtRTEI = { 38, 1, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo qc_emlrtRTEI = { 47, 1, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo rc_emlrtRTEI = { 1, 14, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo sc_emlrtRTEI = { 32, 5, "pwchcore",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m" };

static emlrtDCInfo fb_emlrtDCI = { 32, 37, "pwchcore",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m", 4 };

static emlrtDCInfo gb_emlrtDCI = { 23, 28, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m", 4 };

static emlrtDCInfo hb_emlrtDCI = { 38, 28, "pchip",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m", 4 };

static emlrtRSInfo qj_emlrtRSI = { 15, "errorIf",
  "F:\\MATLAB\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\errorIf.m" };

/* Function Definitions */

/*
 *
 */
void pchip(const emlrtStack *sp, const emxArray_real_T *x, const emxArray_real_T
           *y, emxArray_real_T *v_breaks, emxArray_real_T *v_coefs)
{
  const mxArray *b_y;
  static const int32_T iv63[2] = { 1, 26 };

  const mxArray *m31;
  char_T cv100[26];
  int32_T i;
  static const char_T cv101[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'c', 'k', 'x', 'y', ':', 'N', 'o', 't', 'E', 'n', 'o', 'u', 'g', 'h', 'P',
    't', 's' };

  boolean_T p;
  boolean_T exitg2;
  const mxArray *c_y;
  static const int32_T iv64[2] = { 1, 47 };

  char_T cv102[47];
  static const char_T cv103[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'M', 'u', 's', 't', 'B', 'e', 'F', 'i', 'n', 'i',
    't', 'e', 'A', 'n', 'd', 'S', 't', 'r', 'i', 'c', 't', 'l', 'y', 'I', 'n',
    'c', 'r', 'e', 'a', 's', 'i', 'n', 'g' };

  boolean_T exitg1;
  const mxArray *d_y;
  static const int32_T iv65[2] = { 1, 28 };

  char_T cv104[28];
  static const char_T cv105[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'U', 'n', 's', 'u', 'p', 'p', 'o', 'r', 't', 'e',
    'd', 'N', 'a', 'N' };

  const mxArray *e_y;
  static const int32_T iv66[2] = { 1, 36 };

  char_T cv106[36];
  static const char_T cv107[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'c', 'k', 'x', 'y', ':', 'N', 'u', 'm', 'S', 'i', 't', 'e', 's', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h', 'V', 'a', 'l', 'u', 'e', 's' };

  const mxArray *f_y;
  const mxArray *g_y;
  emxArray_real_T *h;
  int32_T szdel[2];
  emxArray_real_T *del;
  uint32_T uv2[2];
  emxArray_real_T *slopes;
  real_T signd1;
  real_T hs3;
  real_T w1;
  int32_T x_idx_0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &hh_emlrtRSI;
  b_st.site = &nh_emlrtRSI;
  if (x->size[1] >= 2) {
  } else {
    b_y = NULL;
    m31 = emlrtCreateCharArray(2, iv63);
    for (i = 0; i < 26; i++) {
      cv100[i] = cv101[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 26, m31, cv100);
    emlrtAssign(&b_y, m31);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, b_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  if ((x->size[1] >= 1) && ((!muDoubleScalarIsInf(x->data[0])) &&
       (!muDoubleScalarIsNaN(x->data[0])))) {
    p = true;
  } else {
    p = false;
  }

  if (p) {
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i <= x->size[1] - 2)) {
      if (!(x->data[i] < x->data[i + 1])) {
        p = false;
        exitg2 = true;
      } else {
        i++;
      }
    }
  }

  if (p && (!muDoubleScalarIsInf(x->data[x->size[1] - 1]))) {
    p = true;
  } else {
    p = false;
  }

  b_st.site = &oh_emlrtRSI;
  if (p) {
  } else {
    c_y = NULL;
    m31 = emlrtCreateCharArray(2, iv64);
    for (i = 0; i < 47; i++) {
      cv102[i] = cv103[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 47, m31, cv102);
    emlrtAssign(&c_y, m31);
    c_st.site = &nj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, c_y, &l_emlrtMCI), &l_emlrtMCI);
  }

  p = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= y->size[1] - 1)) {
    if (muDoubleScalarIsNaN(y->data[i])) {
      p = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  b_st.site = &ph_emlrtRSI;
  if (!p) {
  } else {
    d_y = NULL;
    m31 = emlrtCreateCharArray(2, iv65);
    for (i = 0; i < 28; i++) {
      cv104[i] = cv105[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 28, m31, cv104);
    emlrtAssign(&d_y, m31);
    c_st.site = &qj_emlrtRSI;
    f_error(&c_st, b_message(&c_st, d_y, &pb_emlrtMCI), &pb_emlrtMCI);
  }

  if (y->size[1] != x->size[1]) {
    b_st.site = &qh_emlrtRSI;
    if (y->size[1] == x->size[1] + 2) {
    } else {
      e_y = NULL;
      m31 = emlrtCreateCharArray(2, iv66);
      for (i = 0; i < 36; i++) {
        cv106[i] = cv107[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 36, m31, cv106);
      emlrtAssign(&e_y, m31);
      f_y = NULL;
      m31 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
      *(int32_T *)mxGetData(m31) = x->size[1];
      emlrtAssign(&f_y, m31);
      g_y = NULL;
      m31 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
      *(int32_T *)mxGetData(m31) = y->size[1];
      emlrtAssign(&g_y, m31);
      c_st.site = &nj_emlrtRSI;
      f_error(&c_st, c_message(&c_st, e_y, f_y, g_y, &l_emlrtMCI), &l_emlrtMCI);
    }
  }

  emxInit_real_T(&st, &h, 2, &oc_emlrtRTEI, true);
  i = x->size[1] - 1;
  emlrtNonNegativeCheckFastR2012b(i, &gb_emlrtDCI, sp);
  i = h->size[0] * h->size[1];
  h->size[0] = 1;
  h->size[1] = x->size[1] - 1;
  emxEnsureCapacity(sp, (emxArray__common *)h, i, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  st.site = &ih_emlrtRSI;
  for (i = 1; i < x->size[1]; i++) {
    h->data[i - 1] = x->data[i] - x->data[i - 1];
  }

  for (i = 0; i < 2; i++) {
    szdel[i] = y->size[i];
  }

  szdel[1]--;
  for (i = 0; i < 2; i++) {
    emlrtNonNegativeCheckFastR2012b(szdel[i], &hb_emlrtDCI, sp);
  }

  emxInit_real_T(sp, &del, 2, &pc_emlrtRTEI, true);
  i = del->size[0] * del->size[1];
  del->size[0] = 1;
  del->size[1] = szdel[1];
  emxEnsureCapacity(sp, (emxArray__common *)del, i, (int32_T)sizeof(real_T),
                    &pc_emlrtRTEI);
  st.site = &jh_emlrtRSI;
  for (i = 0; i + 1 < x->size[1]; i++) {
    del->data[i] = (y->data[i + 1] - y->data[i]) / h->data[i];
  }

  for (i = 0; i < 2; i++) {
    uv2[i] = (uint32_T)y->size[i];
  }

  emxInit_real_T(sp, &slopes, 2, &qc_emlrtRTEI, true);
  i = slopes->size[0] * slopes->size[1];
  slopes->size[0] = 1;
  slopes->size[1] = (int32_T)uv2[1];
  emxEnsureCapacity(sp, (emxArray__common *)slopes, i, (int32_T)sizeof(real_T),
                    &qc_emlrtRTEI);
  if (x->size[1] == 2) {
    st.site = &kh_emlrtRSI;
    for (i = 0; i < 2; i++) {
      slopes->data[i] = del->data[0];
    }
  } else {
    st.site = &lh_emlrtRSI;
    for (i = 1; i <= x->size[1] - 2; i++) {
      signd1 = h->data[i - 1] + h->data[i];
      hs3 = 3.0 * signd1;
      w1 = (h->data[i - 1] + signd1) / hs3;
      signd1 = (h->data[i] + signd1) / hs3;
      hs3 = 0.0;
      if (del->data[i - 1] < 0.0) {
        if (del->data[i] <= del->data[i - 1]) {
          hs3 = del->data[i - 1] / (w1 * (del->data[i - 1] / del->data[i]) +
            signd1);
        } else {
          if (del->data[i] < 0.0) {
            hs3 = del->data[i] / (w1 + signd1 * (del->data[i] / del->data[i - 1]));
          }
        }
      } else {
        if (del->data[i - 1] > 0.0) {
          if (del->data[i] >= del->data[i - 1]) {
            hs3 = del->data[i - 1] / (w1 * (del->data[i - 1] / del->data[i]) +
              signd1);
          } else {
            if (del->data[i] > 0.0) {
              hs3 = del->data[i] / (w1 + signd1 * (del->data[i] / del->data[i -
                1]));
            }
          }
        }
      }

      slopes->data[i] = hs3;
    }

    hs3 = ((2.0 * h->data[0] + h->data[1]) * del->data[0] - h->data[0] *
           del->data[1]) / (h->data[0] + h->data[1]);
    signd1 = muDoubleScalarSign(del->data[0]);
    if (muDoubleScalarSign(hs3) != signd1) {
      hs3 = 0.0;
    } else {
      if ((signd1 != muDoubleScalarSign(del->data[1])) && (muDoubleScalarAbs(hs3)
           > muDoubleScalarAbs(3.0 * del->data[0]))) {
        hs3 = 3.0 * del->data[0];
      }
    }

    slopes->data[0] = hs3;
    hs3 = ((2.0 * h->data[x->size[1] - 2] + h->data[x->size[1] - 3]) * del->
           data[x->size[1] - 2] - h->data[x->size[1] - 2] * del->data[x->size[1]
           - 3]) / (h->data[x->size[1] - 2] + h->data[x->size[1] - 3]);
    signd1 = muDoubleScalarSign(del->data[x->size[1] - 2]);
    if (muDoubleScalarSign(hs3) != signd1) {
      hs3 = 0.0;
    } else {
      if ((signd1 != muDoubleScalarSign(del->data[x->size[1] - 3])) &&
          (muDoubleScalarAbs(hs3) > muDoubleScalarAbs(3.0 * del->data[x->size[1]
            - 2]))) {
        hs3 = 3.0 * del->data[x->size[1] - 2];
      }
    }

    slopes->data[x->size[1] - 1] = hs3;
  }

  st.site = &mh_emlrtRSI;
  x_idx_0 = x->size[1];
  i = v_breaks->size[0] * v_breaks->size[1];
  v_breaks->size[0] = 1;
  v_breaks->size[1] = x_idx_0;
  emxEnsureCapacity(&st, (emxArray__common *)v_breaks, i, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  for (i = 0; i < x_idx_0; i++) {
    v_breaks->data[v_breaks->size[0] * i] = x->data[i];
  }

  i = slopes->size[1] - 1;
  emlrtNonNegativeCheckFastR2012b(i, &fb_emlrtDCI, &st);
  i = v_coefs->size[0] * v_coefs->size[1];
  v_coefs->size[0] = slopes->size[1] - 1;
  v_coefs->size[1] = 4;
  emxEnsureCapacity(&st, (emxArray__common *)v_coefs, i, (int32_T)sizeof(real_T),
                    &sc_emlrtRTEI);
  b_st.site = &rh_emlrtRSI;
  for (i = 0; i + 1 < x->size[1]; i++) {
    signd1 = (del->data[i] - slopes->data[i]) / h->data[i];
    hs3 = (slopes->data[i + 1] - del->data[i]) / h->data[i];
    v_coefs->data[i] = (hs3 - signd1) / h->data[i];
    v_coefs->data[(slopes->size[1] + i) - 1] = 2.0 * signd1 - hs3;
    v_coefs->data[((slopes->size[1] - 1) << 1) + i] = slopes->data[i];
    v_coefs->data[3 * (slopes->size[1] - 1) + i] = y->data[i];
  }

  emxFree_real_T(&slopes);
  emxFree_real_T(&del);
  emxFree_real_T(&h);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (pchip.c) */
