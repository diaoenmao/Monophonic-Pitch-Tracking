/*
 * Myhanning.c
 *
 * Code generation for function 'Myhanning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myhanning.h"
#include "yaapt_emxutil.h"
#include "indexShapeCheck.h"
#include "cos.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo re_emlrtRSI = { 55, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRSInfo se_emlrtRSI = { 56, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRSInfo te_emlrtRSI = { 60, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRSInfo ue_emlrtRSI = { 61, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRTEInfo mb_emlrtRTEI = { 1, 14, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 61, 12, "w", "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 56, 12, "w", "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m", 0 };

/* Function Definitions */
void Myhanning(const emlrtStack *sp, real_T order, emxArray_real_T *w)
{
  emxArray_real_T *y;
  real_T half;
  int32_T n;
  real_T anew;
  real_T apnd;
  real_T ndbl;
  boolean_T n_too_large;
  real_T cdiff;
  int32_T i15;
  int32_T nm1d2;
  int32_T k;
  emxArray_real_T *b_w;
  emxArray_real_T *c_w;
  int32_T iv22[2];
  int32_T i16;
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
  covrtLogFcn(&emlrtCoverageInstance, 8U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 0);

  /* HANNING   Hanning window. */
  /*    HANNING(N) returns the N-point symmetric Hanning window in a column */
  /*    vector.  Note that the first and last zero-weighted window samples */
  /*    are not included. */
  /*  */
  /*    HANNING(N,'symmetric') returns the same result as HANNING(N). */
  /*  */
  /*    HANNING(N,'periodic') returns the N-point periodic Hanning window, */
  /*    and includes the first zero-weighted window sample. */
  /*  */
  /*    NOTE: Use the HANN function to get a Hanning window which has the  */
  /*           first and last zero-weighted samples.  */
  /*  */
  /*    See also BARTLETT, BLACKMAN, BOXCAR, CHEBWIN, HAMMING, HANN, KAISER */
  /*    and TRIANG. */
  /*    Copyright 1988-2002 The MathWorks, Inc. */
  /*    $Revision: 1.11 $  $Date: 2002/04/15 01:11:49 $ */
  /*  Check number of inputs */
  /*  error(nargchk(1,2,nargin)); */
  /*  Check for trivial order */
  /* [n,w,trivialwin] = check_order(varargin{1}); */
  /* if trivialwin, return, end */
  /*  Select the sampling option */
  /*  if nargin == 1, */
  /*     sflag = 'symmetric'; */
  /*  else */
  /*     sflag = lower(varargin{2}); */
  /*  end */
  /*   */
  /*  % Allow partial strings for sampling options */
  /*  allsflags = {'symmetric','periodic'}; */
  /*  sflagindex = strmatch(sflag, allsflags); */
  /*  if length(sflagindex)~=1         % catch 0 or 2 matches */
  /*     error('Sampling flag must be either ''symmetric'' or ''periodic''.'); */
  /*  end */
  /*  sflag = allsflags{sflagindex}; */
  /*  Evaluate the window */
  /*  switch sflag, */
  /*  case 'periodic' */
  /*  Includes the first zero sample */
  /*     w = [0; sym_hanning(n-1)]; */
  /*  case 'symmetric' */
  /*  Does not include the first and last zero sample */
  /*     w = sym_hanning(n); */
  emxInit_real_T(sp, &y, 2, &mb_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 0, covrtLogMcdc
                 (&emlrtCoverageInstance, 8U, 0U, 0, !covrtLogCond
                  (&emlrtCoverageInstance, 8U, 0U, 0, muDoubleScalarRem(order,
          2.0) != 0.0)))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 1);

    /*  Even length window */
    half = order / 2.0;
    st.site = &re_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    c_st.site = &w_emlrtRSI;
    if (muDoubleScalarIsNaN(half)) {
      n = 1;
      anew = rtNaN;
      apnd = half;
      n_too_large = false;
    } else if (half < 1.0) {
      n = 0;
      anew = 1.0;
      apnd = half;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(half)) {
      n = 1;
      anew = rtNaN;
      apnd = half;
      n_too_large = !(1.0 == half);
    } else {
      anew = 1.0;
      ndbl = muDoubleScalarFloor((half - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - half;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * half) {
        ndbl++;
        apnd = half;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      n_too_large = (2.147483647E+9 < ndbl);
      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }
    }

    d_st.site = &x_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &df_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i15 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    if (n > 0) {
      y->data[0] = anew;
      if (n > 1) {
        y->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        d_st.site = &y_emlrtRSI;
        for (k = 1; k < nm1d2; k++) {
          y->data[k] = anew + (real_T)k;
          y->data[(n - k) - 1] = apnd - (real_T)k;
        }

        if (nm1d2 << 1 == n - 1) {
          y->data[nm1d2] = (anew + apnd) / 2.0;
        } else {
          y->data[nm1d2] = anew + (real_T)nm1d2;
          y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
        }
      }
    }

    i15 = w->size[0];
    w->size[0] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)w, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = y->size[1];
    for (i15 = 0; i15 < nm1d2; i15++) {
      w->data[i15] = 6.2831853071795862 * y->data[y->size[0] * i15] / (order +
        1.0);
    }

    st.site = &re_emlrtRSI;
    b_cos(&st, w);
    i15 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i15 = 0; i15 < nm1d2; i15++) {
      w->data[i15] = 1.0 - w->data[i15];
    }

    i15 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i15 = 0; i15 < nm1d2; i15++) {
      w->data[i15] *= 0.5;
    }

    if (1 > w->size[0]) {
      k = 1;
      i15 = 1;
      n = 0;
    } else {
      i15 = w->size[0];
      k = w->size[0];
      if (!((k >= 1) && (k <= i15))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i15, &jc_emlrtBCI, sp);
      }

      i15 = -1;
      n = 1;
    }

    emxInit_real_T2(sp, &c_w, 1, &mb_emlrtRTEI, true);
    iv22[0] = 1;
    iv22[1] = div_s32_floor(sp, n - k, i15) + 1;
    st.site = &se_emlrtRSI;
    indexShapeCheck(&st, w->size[0], iv22);
    i16 = c_w->size[0];
    c_w->size[0] = (w->size[0] + div_s32_floor(sp, n - k, i15)) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)c_w, i16, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i16 = 0; i16 < nm1d2; i16++) {
      c_w->data[i16] = w->data[i16];
    }

    nm1d2 = div_s32_floor(sp, n - k, i15);
    for (n = 0; n <= nm1d2; n++) {
      c_w->data[n + w->size[0]] = w->data[(k + i15 * n) - 1];
    }

    i15 = w->size[0];
    w->size[0] = c_w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = c_w->size[0];
    for (i15 = 0; i15 < nm1d2; i15++) {
      w->data[i15] = c_w->data[i15];
    }

    emxFree_real_T(&c_w);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 2);

    /*  Odd length window */
    half = (order + 1.0) / 2.0;
    st.site = &te_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    c_st.site = &w_emlrtRSI;
    if (muDoubleScalarIsNaN(half)) {
      n = 1;
      anew = rtNaN;
      apnd = half;
      n_too_large = false;
    } else if (half < 1.0) {
      n = 0;
      anew = 1.0;
      apnd = half;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(half)) {
      n = 1;
      anew = rtNaN;
      apnd = half;
      n_too_large = !(1.0 == half);
    } else {
      anew = 1.0;
      ndbl = muDoubleScalarFloor((half - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - half;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * half) {
        ndbl++;
        apnd = half;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      n_too_large = (2.147483647E+9 < ndbl);
      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }
    }

    d_st.site = &x_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &df_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i15 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    if (n > 0) {
      y->data[0] = anew;
      if (n > 1) {
        y->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        d_st.site = &y_emlrtRSI;
        for (k = 1; k < nm1d2; k++) {
          y->data[k] = anew + (real_T)k;
          y->data[(n - k) - 1] = apnd - (real_T)k;
        }

        if (nm1d2 << 1 == n - 1) {
          y->data[nm1d2] = (anew + apnd) / 2.0;
        } else {
          y->data[nm1d2] = anew + (real_T)nm1d2;
          y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
        }
      }
    }

    i15 = w->size[0];
    w->size[0] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)w, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = y->size[1];
    for (i15 = 0; i15 < nm1d2; i15++) {
      w->data[i15] = 6.2831853071795862 * y->data[y->size[0] * i15] / (order +
        1.0);
    }

    st.site = &te_emlrtRSI;
    b_cos(&st, w);
    i15 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i15 = 0; i15 < nm1d2; i15++) {
      w->data[i15] = 1.0 - w->data[i15];
    }

    i15 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i15 = 0; i15 < nm1d2; i15++) {
      w->data[i15] *= 0.5;
    }

    if (1.0 > (real_T)w->size[0] - 1.0) {
      k = 1;
      i15 = 1;
      n = 0;
    } else {
      i15 = w->size[0];
      k = (int32_T)((real_T)w->size[0] - 1.0);
      if (!((k >= 1) && (k <= i15))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i15, &ic_emlrtBCI, sp);
      }

      i15 = -1;
      n = w->size[0];
      if (!(1 <= n)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, n, &ic_emlrtBCI, sp);
      }

      n = 1;
    }

    emxInit_real_T2(sp, &b_w, 1, &mb_emlrtRTEI, true);
    iv22[0] = 1;
    iv22[1] = div_s32_floor(sp, n - k, i15) + 1;
    st.site = &ue_emlrtRSI;
    indexShapeCheck(&st, w->size[0], iv22);
    i16 = b_w->size[0];
    b_w->size[0] = (w->size[0] + div_s32_floor(sp, n - k, i15)) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)b_w, i16, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i16 = 0; i16 < nm1d2; i16++) {
      b_w->data[i16] = w->data[i16];
    }

    nm1d2 = div_s32_floor(sp, n - k, i15);
    for (n = 0; n <= nm1d2; n++) {
      b_w->data[n + w->size[0]] = w->data[(k + i15 * n) - 1];
    }

    i15 = w->size[0];
    w->size[0] = b_w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i15, (int32_T)sizeof(real_T),
                      &mb_emlrtRTEI);
    nm1d2 = b_w->size[0];
    for (i15 = 0; i15 < nm1d2; i15++) {
      w->data[i15] = b_w->data[i15];
    }

    emxFree_real_T(&b_w);
  }

  emxFree_real_T(&y);

  /* --------------------------------------------------------------------- */
  /*  function w = sym_hanning(n) */
  /* SYM_HANNING   Symmetric Hanning window.  */
  /*    SYM_HANNING Returns an exactly symmetric N point window by evaluating */
  /*    the first half and then flipping the same samples over the other half. */
  /*  if ~rem(n,2) */
  /*     % Even length window */
  /*     half = n/2; */
  /*     w = calc_hanning(half,n); */
  /*     w = [w; w(end:-1:1)]; */
  /*  else */
  /*     % Odd length window */
  /*     half = (n+1)/2; */
  /*     w = calc_hanning(half,n); */
  /*     w = [w; w(end-1:-1:1)]; */
  /*  end */
  /*  end */
  /* --------------------------------------------------------------------- */
  /*  function w = calc_hanning(m,n) */
  /* CALC_HANNING   Calculates Hanning window samples. */
  /*    CALC_HANNING Calculates and returns the first M points of an N point */
  /*    Hanning window. */
  /*  w = .5*(1 - cos(2*pi*(1:m)'/(n+1)));  */
  /*  [EOF] hanning.m */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Myhanning.c) */
