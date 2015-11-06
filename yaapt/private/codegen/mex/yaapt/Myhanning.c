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
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI = { 55, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRSInfo hc_emlrtRSI = { 60, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtRTEInfo s_emlrtRTEI = { 1, 14, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 56, 12, "w", "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m", 0 };

static emlrtECInfo i_emlrtECI = { -1, 56, 12, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 61, 12, "w", "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m", 0 };

static emlrtECInfo j_emlrtECI = { -1, 61, 12, "Myhanning",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m" };

/* Function Declarations */
static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);

/* Function Definitions */
static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(0, sp);
  } else {
    if (numerator >= 0) {
      absNumerator = (uint32_T)numerator;
    } else {
      absNumerator = (uint32_T)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (uint32_T)denominator;
    } else {
      absDenominator = (uint32_T)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    if (quotientNeedsNegation) {
      quotient = -(int32_T)tempAbsQuotient;
    } else {
      quotient = (int32_T)tempAbsQuotient;
    }
  }

  return quotient;
}

/*
 * function w = Myhanning(order)
 */
void Myhanning(const emlrtStack *sp, real_T order, emxArray_real_T *w)
{
  emxArray_real_T *y;
  emxArray_real_T *b_y;
  real_T half;
  int32_T n;
  real_T anew;
  real_T apnd;
  boolean_T n_too_large;
  real_T ndbl;
  real_T cdiff;
  const mxArray *c_y;
  static const int32_T iv16[2] = { 1, 21 };

  const mxArray *m8;
  char_T cv27[21];
  int32_T i;
  static const char_T cv28[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T i8;
  int32_T k;
  emxArray_real_T *r5;
  emxArray_real_T *b_w;
  int32_T i9;
  const mxArray *d_y;
  static const int32_T iv17[2] = { 1, 21 };

  emxArray_real_T *r6;
  emxArray_real_T *c_w;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
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
  emxInit_real_T(sp, &y, 2, &s_emlrtRTEI, true);
  b_emxInit_real_T(sp, &b_y, 1, &s_emlrtRTEI, true);
  if (!(muDoubleScalarRem(order, 2.0) != 0.0)) {
    /*  Even length window */
    /* 'Myhanning:54' half = n/2; */
    half = order / 2.0;

    /* 'Myhanning:55' w = .5*(1 - cos(2*pi*(1:half)'/(n+1))); */
    st.site = &gc_emlrtRSI;
    b_st.site = &ic_emlrtRSI;
    c_st.site = &jc_emlrtRSI;
    if (muDoubleScalarIsNaN(half)) {
      n = 0;
      anew = rtNaN;
      apnd = half;
      n_too_large = false;
    } else if (half < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = half;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(half)) {
      n = 0;
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
        n = (int32_T)ndbl - 1;
      } else {
        n = -1;
      }
    }

    d_st.site = &kc_emlrtRSI;
    if (!n_too_large) {
    } else {
      c_y = NULL;
      m8 = emlrtCreateCharArray(2, iv16);
      for (i = 0; i < 21; i++) {
        cv27[i] = cv28[i];
      }

      emlrtInitCharArrayR2013a(&d_st, 21, m8, cv27);
      emlrtAssign(&c_y, m8);
      e_st.site = &wk_emlrtRSI;
      f_st.site = &bk_emlrtRSI;
      f_error(&e_st, b_message(&f_st, c_y, &h_emlrtMCI), &i_emlrtMCI);
    }

    i8 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n + 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i8, (int32_T)sizeof(real_T),
                      &m_emlrtRTEI);
    if (n + 1 > 0) {
      y->data[0] = anew;
      if (n + 1 > 1) {
        y->data[n] = apnd;
        i8 = n + (n < 0);
        if (i8 >= 0) {
          i = (int32_T)((uint32_T)i8 >> 1);
        } else {
          i = ~(int32_T)((uint32_T)~i8 >> 1);
        }

        d_st.site = &lc_emlrtRSI;
        for (k = 1; k < i; k++) {
          y->data[k] = anew + (real_T)k;
          y->data[n - k] = apnd - (real_T)k;
        }

        if (i << 1 == n) {
          y->data[i] = (anew + apnd) / 2.0;
        } else {
          y->data[i] = anew + (real_T)i;
          y->data[i + 1] = apnd - (real_T)i;
        }
      }
    }

    b_emxInit_real_T(&c_st, &r5, 1, &s_emlrtRTEI, true);
    i8 = r5->size[0];
    r5->size[0] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r5, i8, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = y->size[1];
    for (i8 = 0; i8 < i; i8++) {
      r5->data[i8] = 6.2831853071795862 * y->data[y->size[0] * i8];
    }

    c_rdivide(sp, r5, order + 1.0, b_y);
    i8 = w->size[0];
    w->size[0] = b_y->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i8, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = b_y->size[0];
    emxFree_real_T(&r5);
    for (i8 = 0; i8 < i; i8++) {
      w->data[i8] = b_y->data[i8];
    }

    for (k = 0; k < b_y->size[0]; k++) {
      w->data[k] = muDoubleScalarCos(w->data[k]);
    }

    i8 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i8, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = w->size[0];
    for (i8 = 0; i8 < i; i8++) {
      w->data[i8] = 0.5 * (1.0 - w->data[i8]);
    }

    /* 'Myhanning:56' w = [w; w(end:-1:1)]; */
    if (1 > w->size[0]) {
      i8 = 1;
      k = 1;
      n = 0;
    } else {
      i8 = w->size[0];
      k = w->size[0];
      i8 = emlrtDynamicBoundsCheckFastR2012b(k, 1, i8, &yb_emlrtBCI, sp);
      k = -1;
      n = 1;
    }

    b_emxInit_real_T(sp, &b_w, 1, &s_emlrtRTEI, true);
    emlrtVectorVectorIndexCheckR2012b(w->size[0], 1, 1, div_s32_floor(sp, n - i8,
      k) + 1, &i_emlrtECI, sp);
    i9 = b_w->size[0];
    b_w->size[0] = (w->size[0] + div_s32_floor(sp, n - i8, k)) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)b_w, i9, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = w->size[0];
    for (i9 = 0; i9 < i; i9++) {
      b_w->data[i9] = w->data[i9];
    }

    i = div_s32_floor(sp, n - i8, k);
    for (n = 0; n <= i; n++) {
      b_w->data[n + w->size[0]] = w->data[(i8 + k * n) - 1];
    }

    i8 = w->size[0];
    w->size[0] = b_w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i8, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = b_w->size[0];
    for (i8 = 0; i8 < i; i8++) {
      w->data[i8] = b_w->data[i8];
    }

    emxFree_real_T(&b_w);
  } else {
    /* 'Myhanning:57' else */
    /*  Odd length window */
    /* 'Myhanning:59' half = (n+1)/2; */
    half = (order + 1.0) / 2.0;

    /* 'Myhanning:60' w = .5*(1 - cos(2*pi*(1:half)'/(n+1))); */
    st.site = &hc_emlrtRSI;
    b_st.site = &ic_emlrtRSI;
    c_st.site = &jc_emlrtRSI;
    if (muDoubleScalarIsNaN(half)) {
      n = 0;
      anew = rtNaN;
      apnd = half;
      n_too_large = false;
    } else if (half < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = half;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(half)) {
      n = 0;
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
        n = (int32_T)ndbl - 1;
      } else {
        n = -1;
      }
    }

    d_st.site = &kc_emlrtRSI;
    if (!n_too_large) {
    } else {
      d_y = NULL;
      m8 = emlrtCreateCharArray(2, iv17);
      for (i = 0; i < 21; i++) {
        cv27[i] = cv28[i];
      }

      emlrtInitCharArrayR2013a(&d_st, 21, m8, cv27);
      emlrtAssign(&d_y, m8);
      e_st.site = &wk_emlrtRSI;
      f_st.site = &bk_emlrtRSI;
      f_error(&e_st, b_message(&f_st, d_y, &h_emlrtMCI), &i_emlrtMCI);
    }

    i8 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n + 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i8, (int32_T)sizeof(real_T),
                      &m_emlrtRTEI);
    if (n + 1 > 0) {
      y->data[0] = anew;
      if (n + 1 > 1) {
        y->data[n] = apnd;
        i8 = n + (n < 0);
        if (i8 >= 0) {
          i = (int32_T)((uint32_T)i8 >> 1);
        } else {
          i = ~(int32_T)((uint32_T)~i8 >> 1);
        }

        d_st.site = &lc_emlrtRSI;
        for (k = 1; k < i; k++) {
          y->data[k] = anew + (real_T)k;
          y->data[n - k] = apnd - (real_T)k;
        }

        if (i << 1 == n) {
          y->data[i] = (anew + apnd) / 2.0;
        } else {
          y->data[i] = anew + (real_T)i;
          y->data[i + 1] = apnd - (real_T)i;
        }
      }
    }

    b_emxInit_real_T(&c_st, &r6, 1, &s_emlrtRTEI, true);
    i8 = r6->size[0];
    r6->size[0] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r6, i8, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = y->size[1];
    for (i8 = 0; i8 < i; i8++) {
      r6->data[i8] = 6.2831853071795862 * y->data[y->size[0] * i8];
    }

    c_rdivide(sp, r6, order + 1.0, b_y);
    i8 = w->size[0];
    w->size[0] = b_y->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i8, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = b_y->size[0];
    emxFree_real_T(&r6);
    for (i8 = 0; i8 < i; i8++) {
      w->data[i8] = b_y->data[i8];
    }

    for (k = 0; k < b_y->size[0]; k++) {
      w->data[k] = muDoubleScalarCos(w->data[k]);
    }

    i8 = w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i8, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = w->size[0];
    for (i8 = 0; i8 < i; i8++) {
      w->data[i8] = 0.5 * (1.0 - w->data[i8]);
    }

    /* 'Myhanning:61' w = [w; w(end-1:-1:1)]; */
    if (1 > w->size[0] - 1) {
      i8 = 1;
      k = 1;
      n = 0;
    } else {
      i8 = w->size[0];
      k = w->size[0] - 1;
      i8 = emlrtDynamicBoundsCheckFastR2012b(k, 1, i8, &ac_emlrtBCI, sp);
      k = -1;
      n = w->size[0];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, n, &ac_emlrtBCI, sp);
      n = 1;
    }

    b_emxInit_real_T(sp, &c_w, 1, &s_emlrtRTEI, true);
    emlrtVectorVectorIndexCheckR2012b(w->size[0], 1, 1, div_s32_floor(sp, n - i8,
      k) + 1, &j_emlrtECI, sp);
    i9 = c_w->size[0];
    c_w->size[0] = (w->size[0] + div_s32_floor(sp, n - i8, k)) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)c_w, i9, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = w->size[0];
    for (i9 = 0; i9 < i; i9++) {
      c_w->data[i9] = w->data[i9];
    }

    i = div_s32_floor(sp, n - i8, k);
    for (n = 0; n <= i; n++) {
      c_w->data[n + w->size[0]] = w->data[(i8 + k * n) - 1];
    }

    i8 = w->size[0];
    w->size[0] = c_w->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)w, i8, (int32_T)sizeof(real_T),
                      &s_emlrtRTEI);
    i = c_w->size[0];
    for (i8 = 0; i8 < i; i8++) {
      w->data[i8] = c_w->data[i8];
    }

    emxFree_real_T(&c_w);
  }

  emxFree_real_T(&b_y);
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
