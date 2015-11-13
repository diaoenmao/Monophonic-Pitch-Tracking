/*
 * File: Myhanning.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myhanning.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"
#include "yaapt_rtwutil.h"

/* Function Declarations */
static int div_s32_floor(int numerator, int denominator);
static double rt_remd_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
  unsigned int tempAbsQuotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator >= 0) {
      absNumerator = (unsigned int)numerator;
    } else {
      absNumerator = (unsigned int)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (unsigned int)denominator;
    } else {
      absDenominator = (unsigned int)-denominator;
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
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }

  return quotient;
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_remd_snf(double u0, double u1)
{
  double y;
  double b_u1;
  double tr;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = rtNaN;
  } else {
    if (u1 < 0.0) {
      b_u1 = ceil(u1);
    } else {
      b_u1 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != b_u1)) {
      tr = u0 / u1;
      if (fabs(tr - rt_roundd_snf(tr)) <= DBL_EPSILON * fabs(tr)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/*
 * HANNING   Hanning window.
 *    HANNING(N) returns the N-point symmetric Hanning window in a column
 *    vector.  Note that the first and last zero-weighted window samples
 *    are not included.
 *
 *    HANNING(N,'symmetric') returns the same result as HANNING(N).
 *
 *    HANNING(N,'periodic') returns the N-point periodic Hanning window,
 *    and includes the first zero-weighted window sample.
 *
 *    NOTE: Use the HANN function to get a Hanning window which has the
 *           first and last zero-weighted samples.
 *
 *    See also BARTLETT, BLACKMAN, BOXCAR, CHEBWIN, HAMMING, HANN, KAISER
 *    and TRIANG.
 * Arguments    : double order
 *                emxArray_real_T *w
 * Return Type  : void
 */
void Myhanning(double order, emxArray_real_T *w)
{
  emxArray_real_T *y;
  emxArray_real_T *b_y;
  double half;
  int n;
  double anew;
  double apnd;
  double ndbl;
  double cdiff;
  int i2;
  int nm1d2;
  int k;
  emxArray_real_T *r2;
  emxArray_real_T *b_w;
  int i3;

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
  emxInit_real_T(&y, 2);
  b_emxInit_real_T(&b_y, 1);
  if (!(rt_remd_snf(order, 2.0) != 0.0)) {
    /*  Even length window */
    half = order / 2.0;
    if (rtIsNaN(half)) {
      n = 0;
      anew = rtNaN;
      apnd = half;
    } else if (half < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = half;
    } else if (rtIsInf(half)) {
      n = 0;
      anew = rtNaN;
      apnd = half;
    } else {
      anew = 1.0;
      ndbl = floor((half - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - half;
      if (fabs(cdiff) < 4.4408920985006262E-16 * half) {
        ndbl++;
        apnd = half;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int)ndbl - 1;
      } else {
        n = -1;
      }
    }

    i2 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n + 1;
    emxEnsureCapacity((emxArray__common *)y, i2, (int)sizeof(double));
    if (n + 1 > 0) {
      y->data[0] = anew;
      if (n + 1 > 1) {
        y->data[n] = apnd;
        nm1d2 = n / 2;
        for (k = 1; k < nm1d2; k++) {
          y->data[k] = anew + (double)k;
          y->data[n - k] = apnd - (double)k;
        }

        if (nm1d2 << 1 == n) {
          y->data[nm1d2] = (anew + apnd) / 2.0;
        } else {
          y->data[nm1d2] = anew + (double)nm1d2;
          y->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    b_emxInit_real_T(&r2, 1);
    i2 = r2->size[0];
    r2->size[0] = y->size[1];
    emxEnsureCapacity((emxArray__common *)r2, i2, (int)sizeof(double));
    nm1d2 = y->size[1];
    for (i2 = 0; i2 < nm1d2; i2++) {
      r2->data[i2] = 6.2831853071795862 * y->data[y->size[0] * i2];
    }

    c_rdivide(r2, order + 1.0, b_y);
    i2 = w->size[0];
    w->size[0] = b_y->size[0];
    emxEnsureCapacity((emxArray__common *)w, i2, (int)sizeof(double));
    nm1d2 = b_y->size[0];
    emxFree_real_T(&r2);
    for (i2 = 0; i2 < nm1d2; i2++) {
      w->data[i2] = b_y->data[i2];
    }

    for (k = 0; k < b_y->size[0]; k++) {
      w->data[k] = cos(w->data[k]);
    }

    i2 = w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i2, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i2 = 0; i2 < nm1d2; i2++) {
      w->data[i2] = 0.5 * (1.0 - w->data[i2]);
    }

    if (1 > w->size[0]) {
      i2 = 1;
      k = 1;
      n = 0;
    } else {
      i2 = w->size[0];
      k = -1;
      n = 1;
    }

    b_emxInit_real_T(&b_w, 1);
    i3 = b_w->size[0];
    b_w->size[0] = (w->size[0] + div_s32_floor(n - i2, k)) + 1;
    emxEnsureCapacity((emxArray__common *)b_w, i3, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i3 = 0; i3 < nm1d2; i3++) {
      b_w->data[i3] = w->data[i3];
    }

    nm1d2 = div_s32_floor(n - i2, k);
    for (n = 0; n <= nm1d2; n++) {
      b_w->data[n + w->size[0]] = w->data[(i2 + k * n) - 1];
    }

    i2 = w->size[0];
    w->size[0] = b_w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i2, (int)sizeof(double));
    nm1d2 = b_w->size[0];
    for (i2 = 0; i2 < nm1d2; i2++) {
      w->data[i2] = b_w->data[i2];
    }

    emxFree_real_T(&b_w);
  } else {
    /*  Odd length window */
    half = (order + 1.0) / 2.0;
    if (rtIsNaN(half)) {
      n = 0;
      anew = rtNaN;
      apnd = half;
    } else if (half < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = half;
    } else if (rtIsInf(half)) {
      n = 0;
      anew = rtNaN;
      apnd = half;
    } else {
      anew = 1.0;
      ndbl = floor((half - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - half;
      if (fabs(cdiff) < 4.4408920985006262E-16 * half) {
        ndbl++;
        apnd = half;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int)ndbl - 1;
      } else {
        n = -1;
      }
    }

    i2 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n + 1;
    emxEnsureCapacity((emxArray__common *)y, i2, (int)sizeof(double));
    if (n + 1 > 0) {
      y->data[0] = anew;
      if (n + 1 > 1) {
        y->data[n] = apnd;
        nm1d2 = n / 2;
        for (k = 1; k < nm1d2; k++) {
          y->data[k] = anew + (double)k;
          y->data[n - k] = apnd - (double)k;
        }

        if (nm1d2 << 1 == n) {
          y->data[nm1d2] = (anew + apnd) / 2.0;
        } else {
          y->data[nm1d2] = anew + (double)nm1d2;
          y->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    b_emxInit_real_T(&r2, 1);
    i2 = r2->size[0];
    r2->size[0] = y->size[1];
    emxEnsureCapacity((emxArray__common *)r2, i2, (int)sizeof(double));
    nm1d2 = y->size[1];
    for (i2 = 0; i2 < nm1d2; i2++) {
      r2->data[i2] = 6.2831853071795862 * y->data[y->size[0] * i2];
    }

    c_rdivide(r2, order + 1.0, b_y);
    i2 = w->size[0];
    w->size[0] = b_y->size[0];
    emxEnsureCapacity((emxArray__common *)w, i2, (int)sizeof(double));
    nm1d2 = b_y->size[0];
    emxFree_real_T(&r2);
    for (i2 = 0; i2 < nm1d2; i2++) {
      w->data[i2] = b_y->data[i2];
    }

    for (k = 0; k < b_y->size[0]; k++) {
      w->data[k] = cos(w->data[k]);
    }

    i2 = w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i2, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i2 = 0; i2 < nm1d2; i2++) {
      w->data[i2] = 0.5 * (1.0 - w->data[i2]);
    }

    if (1 > w->size[0] - 1) {
      i2 = 1;
      k = 1;
      n = 0;
    } else {
      i2 = w->size[0] - 1;
      k = -1;
      n = 1;
    }

    b_emxInit_real_T(&b_w, 1);
    i3 = b_w->size[0];
    b_w->size[0] = (w->size[0] + div_s32_floor(n - i2, k)) + 1;
    emxEnsureCapacity((emxArray__common *)b_w, i3, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i3 = 0; i3 < nm1d2; i3++) {
      b_w->data[i3] = w->data[i3];
    }

    nm1d2 = div_s32_floor(n - i2, k);
    for (n = 0; n <= nm1d2; n++) {
      b_w->data[n + w->size[0]] = w->data[(i2 + k * n) - 1];
    }

    i2 = w->size[0];
    w->size[0] = b_w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i2, (int)sizeof(double));
    nm1d2 = b_w->size[0];
    for (i2 = 0; i2 < nm1d2; i2++) {
      w->data[i2] = b_w->data[i2];
    }

    emxFree_real_T(&b_w);
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
}

/*
 * File trailer for Myhanning.c
 *
 * [EOF]
 */
