/*
 * Mykaiser.c
 *
 * Code generation for function 'Mykaiser'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Mykaiser.h"
#include "yaapt_emxutil.h"
#include "Mybesseli.h"
#include "sqrt.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo mh_emlrtRSI = { 48, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtRSInfo nh_emlrtRSI = { 49, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtRSInfo oh_emlrtRSI = { 50, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtRTEInfo mc_emlrtRTEI = { 41, 14, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtRTEInfo nc_emlrtRTEI = { 48, 5, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtECInfo w_emlrtECI = { -1, 49, 30, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

/* Function Definitions */
void Mykaiser(const emlrtStack *sp, real_T n, emxArray_real_T *w)
{
  int32_T k;
  int32_T b_n;
  real_T anew;
  real_T apnd;
  real_T ndbl;
  boolean_T n_too_large;
  real_T cdiff;
  emxArray_real_T *y;
  emxArray_real_T *b_k;
  int32_T nm1d2;
  emxArray_real_T *b_y;
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
  covrtLogFcn(&emlrtCoverageInstance, 10U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 0);

  /*  Copyright (C) 1995, 1996, 1997  Kurt Hornik */
  /*   */
  /*  This program is free software; you can redistribute it and/or modify */
  /*  it under the terms of the GNU General Public License as published by */
  /*  the Free Software Foundation; either version 2, or (at your option) */
  /*  any later version. */
  /*   */
  /*  This program is distributed in the hope that it will be useful, but */
  /*  WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU */
  /*  General Public License for more details.  */
  /*   */
  /*  You should have received a copy of the GNU General Public License */
  /*  along with this file.  If not, see <http://www.gnu.org/licenses/>. */
  /*  usage:  kaiser (n, beta) */
  /*  */
  /*  Returns the filter coefficients of the n-point Kaiser window with */
  /*  parameter beta. */
  /*  */
  /*  For the definition of the Kaiser window, see A. V. Oppenheim & */
  /*  R. W. Schafer, "Discrete-Time Signal Processing". */
  /*  */
  /*  The continuous version of width n centered about x=0 is: */
  /*  */
  /*          besseli(0, beta * sqrt(1-(2*x/n).^2)) */
  /*  k(x) =  -------------------------------------,  n/2 <= x <= n/2 */
  /*                 besseli(0, beta) */
  /*  */
  /*  See also: kaiserord */
  /*  Author:  Kurt Hornik <Kurt.Hornik@ci.tuwien.ac.at> */
  /*  Description:  Coefficients of the Kaiser window */
  /*  2000-02 Paul Kienzle (pkienzle@kienzle.powernet.co.uk) */
  /*     use besseli rather than jybess */
  /*     note, although Oppenheim & Schafer, 2nd edition has a formula */
  /*     which looks completely different than the one herein, it gives */
  /*     identical results */
  if (covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 0, n == 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 1);
    k = w->size[0] * w->size[1];
    w->size[0] = 1;
    w->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)w, k, (int32_T)sizeof(real_T),
                      &mc_emlrtRTEI);
    w->data[0] = 1.0;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 2);
    st.site = &mh_emlrtRSI;
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
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarAbs
          (n - 1.0)) {
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
      emlrtErrorWithMessageIdR2012b(&d_st, &df_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    emxInit_real_T(&d_st, &y, 2, &mc_emlrtRTEI, true);
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = b_n;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &mc_emlrtRTEI);
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

    emxInit_real_T2(&c_st, &b_k, 1, &nc_emlrtRTEI, true);
    k = b_k->size[0];
    b_k->size[0] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_k, k, (int32_T)sizeof(real_T),
                      &mc_emlrtRTEI);
    nm1d2 = y->size[1];
    for (k = 0; k < nm1d2; k++) {
      b_k->data[k] = y->data[y->size[0] * k];
    }

    emxFree_real_T(&y);
    k = b_k->size[0];
    nm1d2 = b_k->size[0];
    if (k != nm1d2) {
      emlrtSizeEqCheck1DR2012b(k, nm1d2, &w_emlrtECI, sp);
    }

    anew = 1.0 / (n - 1.0);
    k = b_k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_k, k, (int32_T)sizeof(real_T),
                      &mc_emlrtRTEI);
    nm1d2 = b_k->size[0];
    for (k = 0; k < nm1d2; k++) {
      b_k->data[k] *= (n - 1.0) - b_k->data[k];
    }

    emxInit_real_T2(sp, &b_y, 1, &mc_emlrtRTEI, true);
    st.site = &nh_emlrtRSI;
    c_sqrt(&st, b_k);
    k = b_y->size[0];
    b_y->size[0] = b_k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_y, k, (int32_T)sizeof(real_T),
                      &mc_emlrtRTEI);
    nm1d2 = b_k->size[0];
    for (k = 0; k < nm1d2; k++) {
      b_y->data[k] = anew * b_k->data[k];
    }

    emxFree_real_T(&b_k);
    st.site = &oh_emlrtRSI;
    Mybesseli(&st, b_y, w);
    st.site = &oh_emlrtRSI;
    anew = b_Mybesseli(&st);
    k = w->size[0] * w->size[1];
    w->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)w, k, (int32_T)sizeof(real_T),
                      &mc_emlrtRTEI);
    nm1d2 = w->size[0];
    k = w->size[1];
    nm1d2 *= k;
    emxFree_real_T(&b_y);
    for (k = 0; k < nm1d2; k++) {
      w->data[k] /= anew;
    }

    /*      w_test = besseli (0, k) / besseli (0, beta); */
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mykaiser.c) */
