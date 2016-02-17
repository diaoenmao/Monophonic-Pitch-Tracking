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
#include "median.h"
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "indexShapeCheck.h"
#include "cos.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo if_emlrtRSI = { 55, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRSInfo jf_emlrtRSI = { 56, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRSInfo kf_emlrtRSI = { 60, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRSInfo lf_emlrtRSI = { 61, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRTEInfo ob_emlrtRTEI = { 1, 14, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtBCInfo kc_emlrtBCI = { 0, MAX_int32_T, 56, 14, "w(end:-1:1)",
  "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 56, 12, "w", "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { 0, MAX_int32_T, 61, 14, "w(end-1:-1:1)",
  "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 61, 12, "w", "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m", 0 };

/* Function Definitions */

/*
 * function w = Myhanning(order)
 */
void Myhanning(const emlrtStack *sp, real_T order, emxArray_real_T *w)
{
  emxArray_real_T *y;
  real_T half;
  int32_T n;
  real_T anew;
  real_T apnd;
  boolean_T n_too_large;
  real_T ndbl;
  real_T cdiff;
  int32_T i19;
  int32_T nm1d2;
  int32_T k;
  emxArray_real_T *r19;
  emxArray_real_T *b_w;
  int32_T iv27[2];
  int32_T i20;
  emxArray_real_T *r20;
  emxArray_real_T *c_w;
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
  /* 'Myhanning:27' n=order; */
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
  /* 'Myhanning:52' if ~rem(n,2) */
  emxInit_real_T(sp, &y, 2, &ob_emlrtRTEI, true);
  if (!(muDoubleScalarRem(order, 2.0) != 0.0)) {
    /*  Even length window */
    /* 'Myhanning:54' half = n/2; */
    half = order / 2.0;

    /* 'Myhanning:55' w = .5*(1 - cos(2*pi*(1:half)'/(n+1))); */
    st.site = &if_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
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

    d_st.site = &ab_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &ye_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i19 = y->size[0] * y->size[1];
    y->size[0] = 1;
    if (!(n > 0)) {
      emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
    }

    y->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    if (n > 0) {
      y->data[0] = anew;
      if (n > 1) {
        y->data[n - 1] = apnd;
        i19 = n - 1;
        nm1d2 = asr_s32(i19, 1U);
        d_st.site = &bb_emlrtRSI;
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

    emxInit_real_T1(&c_st, &r19, 1, &ob_emlrtRTEI, true);
    i19 = r19->size[0];
    r19->size[0] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r19, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = y->size[1];
    for (i19 = 0; i19 < nm1d2; i19++) {
      r19->data[i19] = 6.2831853071795862 * y->data[y->size[0] * i19];
    }

    rdivide(sp, r19, order + 1.0, w);
    st.site = &if_emlrtRSI;
    b_cos(&st, w);
    i19 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = w->size[0];
    emxFree_real_T(&r19);
    for (i19 = 0; i19 < nm1d2; i19++) {
      w->data[i19] = 1.0 - w->data[i19];
    }

    i19 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i19 = 0; i19 < nm1d2; i19++) {
      w->data[i19] *= 0.5;
    }

    /* 'Myhanning:56' w = [w; w(end:-1:1)]; */
    i19 = w->size[0];
    if (!(i19 >= 0)) {
      emlrtDynamicBoundsCheckR2012b(i19, 0, MAX_int32_T, &kc_emlrtBCI, sp);
    }

    if (1 > w->size[0]) {
      k = 1;
      i19 = 1;
      n = 0;
    } else {
      i19 = w->size[0];
      k = w->size[0];
      if (!((k >= 1) && (k <= i19))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i19, &lc_emlrtBCI, sp);
      }

      i19 = -1;
      n = 1;
    }

    emxInit_real_T1(sp, &b_w, 1, &ob_emlrtRTEI, true);
    iv27[0] = 1;
    iv27[1] = div_s32_floor(sp, n - k, i19) + 1;
    st.site = &jf_emlrtRSI;
    indexShapeCheck(&st, w->size[0], iv27);
    i20 = b_w->size[0];
    b_w->size[0] = (w->size[0] + div_s32_floor(sp, n - k, i19)) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)b_w, i20, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i20 = 0; i20 < nm1d2; i20++) {
      b_w->data[i20] = w->data[i20];
    }

    nm1d2 = div_s32_floor(sp, n - k, i19);
    for (n = 0; n <= nm1d2; n++) {
      b_w->data[n + w->size[0]] = w->data[(k + i19 * n) - 1];
    }

    i19 = w->size[0];
    w->size[0] = b_w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = b_w->size[0];
    for (i19 = 0; i19 < nm1d2; i19++) {
      w->data[i19] = b_w->data[i19];
    }

    emxFree_real_T(&b_w);
  } else {
    /* 'Myhanning:57' else */
    /*  Odd length window */
    /* 'Myhanning:59' half = (n+1)/2; */
    half = (order + 1.0) / 2.0;

    /* 'Myhanning:60' w = .5*(1 - cos(2*pi*(1:half)'/(n+1))); */
    st.site = &kf_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
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

    d_st.site = &ab_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &ye_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i19 = y->size[0] * y->size[1];
    y->size[0] = 1;
    if (!(n > 0)) {
      emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
    }

    y->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    if (n > 0) {
      y->data[0] = anew;
      if (n > 1) {
        y->data[n - 1] = apnd;
        i19 = n - 1;
        nm1d2 = asr_s32(i19, 1U);
        d_st.site = &bb_emlrtRSI;
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

    emxInit_real_T1(&c_st, &r20, 1, &ob_emlrtRTEI, true);
    i19 = r20->size[0];
    r20->size[0] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r20, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = y->size[1];
    for (i19 = 0; i19 < nm1d2; i19++) {
      r20->data[i19] = 6.2831853071795862 * y->data[y->size[0] * i19];
    }

    rdivide(sp, r20, order + 1.0, w);
    st.site = &kf_emlrtRSI;
    b_cos(&st, w);
    i19 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = w->size[0];
    emxFree_real_T(&r20);
    for (i19 = 0; i19 < nm1d2; i19++) {
      w->data[i19] = 1.0 - w->data[i19];
    }

    i19 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i19 = 0; i19 < nm1d2; i19++) {
      w->data[i19] *= 0.5;
    }

    /* 'Myhanning:61' w = [w; w(end-1:-1:1)]; */
    i19 = w->size[0];
    if (!(i19 >= 0)) {
      emlrtDynamicBoundsCheckR2012b(i19, 0, MAX_int32_T, &mc_emlrtBCI, sp);
    }

    if (1.0 > (real_T)w->size[0] - 1.0) {
      k = 1;
      i19 = 1;
      n = 0;
    } else {
      i19 = w->size[0];
      k = (int32_T)((real_T)w->size[0] - 1.0);
      if (!((k >= 1) && (k <= i19))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i19, &nc_emlrtBCI, sp);
      }

      i19 = -1;
      n = w->size[0];
      if (!(1 <= n)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, n, &nc_emlrtBCI, sp);
      }

      n = 1;
    }

    emxInit_real_T1(sp, &c_w, 1, &ob_emlrtRTEI, true);
    iv27[0] = 1;
    iv27[1] = div_s32_floor(sp, n - k, i19) + 1;
    st.site = &lf_emlrtRSI;
    indexShapeCheck(&st, w->size[0], iv27);
    i20 = c_w->size[0];
    c_w->size[0] = (w->size[0] + div_s32_floor(sp, n - k, i19)) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)c_w, i20, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = w->size[0];
    for (i20 = 0; i20 < nm1d2; i20++) {
      c_w->data[i20] = w->data[i20];
    }

    nm1d2 = div_s32_floor(sp, n - k, i19);
    for (n = 0; n <= nm1d2; n++) {
      c_w->data[n + w->size[0]] = w->data[(k + i19 * n) - 1];
    }

    i19 = w->size[0];
    w->size[0] = c_w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i19, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    nm1d2 = c_w->size[0];
    for (i19 = 0; i19 < nm1d2; i19++) {
      w->data[i19] = c_w->data[i19];
    }

    emxFree_real_T(&c_w);
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
