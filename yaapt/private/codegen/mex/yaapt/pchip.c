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
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo xm_emlrtRSI = { 15, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo ym_emlrtRSI = { 24, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo an_emlrtRSI = { 40, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo bn_emlrtRSI = { 52, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo cn_emlrtRSI = { 62, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo dn_emlrtRSI = { 84, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo ae_emlrtRTEI = { 1, 14, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo be_emlrtRTEI = { 23, 1, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo ce_emlrtRTEI = { 38, 1, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo de_emlrtRTEI = { 47, 1, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo yg_emlrtRTEI = { 42, 19, "chckxy",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRTEInfo ah_emlrtRTEI = { 38, 1, "chckxy",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRTEInfo bh_emlrtRTEI = { 36, 15, "chckxy",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRTEInfo ch_emlrtRTEI = { 32, 15, "chckxy",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtDCInfo ed_emlrtDCI = { 38, 28, "pchip",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m", 4 };

static emlrtDCInfo fd_emlrtDCI = { 32, 37, "pwchcore",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m",
  4 };

/* Function Definitions */

/*
 *
 */
void pchip(const emlrtStack *sp, const emxArray_real_T *x, const emxArray_real_T
           *y, emxArray_real_T *v_breaks, emxArray_real_T *v_coefs)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg2;
  boolean_T exitg1;
  emxArray_real_T *h;
  int32_T nx;
  int32_T i45;
  int32_T szdel[2];
  emxArray_real_T *del;
  uint32_T uv6[2];
  emxArray_real_T *slopes;
  real_T hs3;
  real_T signd1;
  real_T w1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &xm_emlrtRSI;
  if (x->size[1] >= 2) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ch_emlrtRTEI,
      "MATLAB:chckxy:NotEnoughPts", 0);
  }

  p = ((!muDoubleScalarIsInf(x->data[0])) && (!muDoubleScalarIsNaN(x->data[0])));
  if (p) {
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k <= x->size[1] - 2)) {
      if (!(x->data[k] < x->data[k + 1])) {
        p = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
  }

  if (p && (!muDoubleScalarIsInf(x->data[x->size[1] - 1]))) {
    p = true;
  } else {
    p = false;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &bh_emlrtRTEI,
      "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing", 0);
  }

  p = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= y->size[1] - 1)) {
    if (muDoubleScalarIsNaN(y->data[k])) {
      p = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ah_emlrtRTEI,
      "Coder:toolbox:UnsupportedNaN", 0);
  }

  if ((y->size[1] != x->size[1]) && (!(y->size[1] == x->size[1] + 2))) {
    emlrtErrorWithMessageIdR2012b(&st, &yg_emlrtRTEI,
      "MATLAB:chckxy:NumSitesMismatchValues", 4, 12, x->size[1], 12, y->size[1]);
  }

  emxInit_real_T(&st, &h, 2, &be_emlrtRTEI, true);
  nx = x->size[1];
  i45 = h->size[0] * h->size[1];
  h->size[0] = 1;
  h->size[1] = x->size[1] - 1;
  emxEnsureCapacity(sp, (emxArray__common *)h, i45, (int32_T)sizeof(real_T),
                    &ae_emlrtRTEI);
  st.site = &ym_emlrtRSI;
  for (k = 1; k < nx; k++) {
    h->data[k - 1] = x->data[k] - x->data[k - 1];
  }

  for (i45 = 0; i45 < 2; i45++) {
    szdel[i45] = y->size[i45];
  }

  szdel[1]--;
  for (i45 = 0; i45 < 2; i45++) {
    k = szdel[i45];
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &ed_emlrtDCI, sp);
    }
  }

  emxInit_real_T(sp, &del, 2, &ce_emlrtRTEI, true);
  i45 = del->size[0] * del->size[1];
  del->size[0] = 1;
  del->size[1] = szdel[1];
  emxEnsureCapacity(sp, (emxArray__common *)del, i45, (int32_T)sizeof(real_T),
                    &ae_emlrtRTEI);
  st.site = &an_emlrtRSI;
  for (k = 0; k + 1 < nx; k++) {
    del->data[k] = (y->data[k + 1] - y->data[k]) / h->data[k];
  }

  for (i45 = 0; i45 < 2; i45++) {
    uv6[i45] = (uint32_T)y->size[i45];
  }

  emxInit_real_T(sp, &slopes, 2, &de_emlrtRTEI, true);
  i45 = slopes->size[0] * slopes->size[1];
  slopes->size[0] = 1;
  slopes->size[1] = (int32_T)uv6[1];
  emxEnsureCapacity(sp, (emxArray__common *)slopes, i45, (int32_T)sizeof(real_T),
                    &ae_emlrtRTEI);
  if (x->size[1] == 2) {
    st.site = &bn_emlrtRSI;
    for (k = 1; k <= nx; k++) {
      slopes->data[k - 1] = del->data[0];
    }
  } else {
    st.site = &cn_emlrtRSI;
    for (k = 1; k <= nx - 2; k++) {
      signd1 = h->data[k - 1] + h->data[k];
      hs3 = 3.0 * signd1;
      w1 = (h->data[k - 1] + signd1) / hs3;
      signd1 = (h->data[k] + signd1) / hs3;
      hs3 = 0.0;
      if (del->data[k - 1] < 0.0) {
        if (del->data[k] <= del->data[k - 1]) {
          hs3 = del->data[k - 1] / (w1 * (del->data[k - 1] / del->data[k]) +
            signd1);
        } else {
          if (del->data[k] < 0.0) {
            hs3 = del->data[k] / (w1 + signd1 * (del->data[k] / del->data[k - 1]));
          }
        }
      } else {
        if (del->data[k - 1] > 0.0) {
          if (del->data[k] >= del->data[k - 1]) {
            hs3 = del->data[k - 1] / (w1 * (del->data[k - 1] / del->data[k]) +
              signd1);
          } else {
            if (del->data[k] > 0.0) {
              hs3 = del->data[k] / (w1 + signd1 * (del->data[k] / del->data[k -
                1]));
            }
          }
        }
      }

      slopes->data[k] = hs3;
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

  st.site = &dn_emlrtRSI;
  k = x->size[1];
  i45 = v_breaks->size[0] * v_breaks->size[1];
  v_breaks->size[0] = 1;
  v_breaks->size[1] = k;
  emxEnsureCapacity(&st, (emxArray__common *)v_breaks, i45, (int32_T)sizeof
                    (real_T), &ae_emlrtRTEI);
  for (i45 = 0; i45 < k; i45++) {
    v_breaks->data[v_breaks->size[0] * i45] = x->data[i45];
  }

  nx = slopes->size[1] - 1;
  i45 = v_coefs->size[0] * v_coefs->size[1];
  k = slopes->size[1] - 1;
  if (!(k >= 0)) {
    emlrtNonNegativeCheckR2012b(k, &fd_emlrtDCI, &st);
  }

  v_coefs->size[0] = k;
  v_coefs->size[1] = 4;
  emxEnsureCapacity(&st, (emxArray__common *)v_coefs, i45, (int32_T)sizeof
                    (real_T), &ae_emlrtRTEI);
  for (k = 0; k + 1 < x->size[1]; k++) {
    signd1 = (del->data[k] - slopes->data[k]) / h->data[k];
    hs3 = (slopes->data[k + 1] - del->data[k]) / h->data[k];
    v_coefs->data[k] = (hs3 - signd1) / h->data[k];
    v_coefs->data[nx + k] = 2.0 * signd1 - hs3;
    v_coefs->data[(nx << 1) + k] = slopes->data[k];
    v_coefs->data[3 * nx + k] = y->data[k];
  }

  emxFree_real_T(&slopes);
  emxFree_real_T(&del);
  emxFree_real_T(&h);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (pchip.c) */
