/*
 * Myhamming.c
 *
 * Code generation for function 'Myhamming'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myhamming.h"
#include "yaapt_emxutil.h"
#include "cos.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 7, "Myhamming",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhamming.m" };

static emlrtRTEInfo j_emlrtRTEI = { 1, 14, "Myhamming",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhamming.m" };

/* Function Definitions */
void Myhamming(const emlrtStack *sp, real_T n, emxArray_real_T *w)
{
  int32_T b_n;
  real_T anew;
  real_T apnd;
  real_T ndbl;
  boolean_T n_too_large;
  real_T cdiff;
  emxArray_real_T *y;
  int32_T k;
  int32_T nm1d2;
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
  covrtLogFcn(&emlrtCoverageInstance, 4U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 0);

  /* HAMMING HAMMING(N) returns the N-point Hamming window. */
  /* 	Copyright (c) 1984-94 by The MathWorks, Inc. */
  /*        $Revision: 1.4 $  $Date: 1994/01/25 17:59:14 $ */
  st.site = &u_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  if (muDoubleScalarIsNaN(n - 1.0)) {
    b_n = 1;
    anew = rtNaN;
    apnd = n - 1.0;
    n_too_large = false;
  } else if (n - 1.0 < 0.0) {
    b_n = 0;
    anew = 0.0;
    apnd = n - 1.0;
    n_too_large = false;
  } else if (muDoubleScalarIsInf(n - 1.0)) {
    b_n = 1;
    anew = rtNaN;
    apnd = n - 1.0;
    n_too_large = !(0.0 == n - 1.0);
  } else {
    anew = 0.0;
    ndbl = muDoubleScalarFloor((n - 1.0) + 0.5);
    apnd = ndbl;
    cdiff = ndbl - (n - 1.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarAbs(n
         - 1.0)) {
      ndbl++;
      apnd = n - 1.0;
    } else if (cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    n_too_large = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      b_n = (int32_T)ndbl;
    } else {
      b_n = 0;
    }
  }

  d_st.site = &x_emlrtRSI;
  if (!n_too_large) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &df_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &y, 2, &j_emlrtRTEI, true);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity(&c_st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  if (b_n > 0) {
    y->data[0] = anew;
    if (b_n > 1) {
      y->data[b_n - 1] = apnd;
      nm1d2 = (b_n - 1) / 2;
      d_st.site = &y_emlrtRSI;
      for (k = 1; k < nm1d2; k++) {
        y->data[k] = anew + (real_T)k;
        y->data[(b_n - k) - 1] = apnd - (real_T)k;
      }

      if (nm1d2 << 1 == b_n - 1) {
        y->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        y->data[nm1d2] = anew + (real_T)nm1d2;
        y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  k = w->size[0];
  w->size[0] = y->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)w, k, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  nm1d2 = y->size[1];
  for (k = 0; k < nm1d2; k++) {
    w->data[k] = 6.2831853071795862 * y->data[y->size[0] * k] / (n - 1.0);
  }

  emxFree_real_T(&y);
  st.site = &u_emlrtRSI;
  b_cos(&st, w);
  k = w->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)w, k, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  nm1d2 = w->size[0];
  for (k = 0; k < nm1d2; k++) {
    w->data[k] = 0.54 - 0.46 * w->data[k];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Myhamming.c) */
