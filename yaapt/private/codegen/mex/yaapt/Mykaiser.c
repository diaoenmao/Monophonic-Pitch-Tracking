/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Mykaiser.c
 *
 * Code generation for function 'Mykaiser'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Mykaiser.h"
#include "spec_trk.h"
#include "yaapt_emxutil.h"
#include "Mybesseli.h"
#include "sqrt.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo de_emlrtRSI = { 48, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtRSInfo ee_emlrtRSI = { 49, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtRSInfo fe_emlrtRSI = { 50, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtRTEInfo hb_emlrtRTEI = { 41, 14, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtRTEInfo ib_emlrtRTEI = { 48, 5, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

static emlrtECInfo p_emlrtECI = { -1, 49, 30, "Mykaiser",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m" };

/* Function Definitions */

/*
 * function w = Mykaiser (n)
 */
void Mykaiser(const emlrtStack *sp, real_T n, emxArray_real_T *w)
{
  int32_T k;
  int32_T b_n;
  real_T anew;
  real_T apnd;
  boolean_T n_too_large;
  real_T ndbl;
  real_T cdiff;
  emxArray_real_T *y;
  int32_T nm1d2;
  emxArray_real_T *b_k;
  real_T c_n;
  real_T en;
  real_T p;
  real_T a;
  int32_T count;
  real_T pold;
  real_T tempa;
  real_T em;
  real_T empal;
  real_T emp2al;
  real_T c_sum;
  real_T nend;
  real_T kk;
  int32_T count2;
  int32_T l;
  boolean_T exitg1;
  real_T tempc;
  emxArray_real_T *b_y;
  real_T b;
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
  /* 'Mykaiser:42' beta = 0.5; */
  /* 'Mykaiser:44' if (n == 1) */
  if (n == 1.0) {
    /* 'Mykaiser:45' w = 1; */
    k = w->size[0] * w->size[1];
    w->size[0] = 1;
    w->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)w, k, (int32_T)sizeof(real_T),
                      &hb_emlrtRTEI);
    w->data[0] = 1.0;
  } else {
    /* 'Mykaiser:46' else */
    /* 'Mykaiser:47' m = n - 1; */
    /* 'Mykaiser:48' k = (0 : m)'; */
    st.site = &de_emlrtRSI;
    b_st.site = &kc_emlrtRSI;
    c_st.site = &lc_emlrtRSI;
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

    d_st.site = &mc_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &td_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    emxInit_real_T(&d_st, &y, 2, &hb_emlrtRTEI, true);
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = b_n;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &hb_emlrtRTEI);
    if (b_n > 0) {
      y->data[0] = anew;
      if (b_n > 1) {
        y->data[b_n - 1] = apnd;
        k = b_n - 1;
        nm1d2 = asr_s32(k, 1U);
        d_st.site = &nc_emlrtRSI;
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

    emxInit_real_T1(&c_st, &b_k, 1, &ib_emlrtRTEI, true);
    k = b_k->size[0];
    b_k->size[0] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_k, k, (int32_T)sizeof(real_T),
                      &hb_emlrtRTEI);
    nm1d2 = y->size[1];
    for (k = 0; k < nm1d2; k++) {
      b_k->data[k] = y->data[y->size[0] * k];
    }

    emxFree_real_T(&y);

    /* 'Mykaiser:49' k = 2 * beta / m * sqrt (k .* (m - k)); */
    k = b_k->size[0];
    nm1d2 = b_k->size[0];
    if (k != nm1d2) {
      emlrtSizeEqCheck1DR2012b(k, nm1d2, &p_emlrtECI, sp);
    }

    anew = 1.0 / (n - 1.0);
    k = b_k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_k, k, (int32_T)sizeof(real_T),
                      &hb_emlrtRTEI);
    nm1d2 = b_k->size[0];
    for (k = 0; k < nm1d2; k++) {
      b_k->data[k] *= (n - 1.0) - b_k->data[k];
    }

    st.site = &ee_emlrtRSI;
    b_sqrt(&st, b_k);

    /* 'Mykaiser:50' w = Mybesseli (0, k) / Mybesseli (0, beta); */
    st.site = &fe_emlrtRSI;

    /* BESSELI Modified Bessel functions of the first kind. */
    /* 	I = BESSELI(ALPHA,X) computes modified Bessel functions of the */
    /* 	first kind, I_sub_alpha(X) for real, non-negative order ALPHA */
    /* 	and argument X.  In general, both ALPHA and X may be vectors. */
    /* 	The output I is m-by-n with m = length(X), n = length(ALPHA) and */
    /* 	    I(k,j) = I_sub_alpha(j)(X(k)). */
    /* 	The elements of X can be any nonnegative real values in any order. */
    /* 	For ALPHA there are two important restrictions: the increment */
    /* 	in ALPHA must be one, i.e. ALPHA = alpha:1:alpha+n-1, and the */
    /* 	elements must also be in the range 0 <= ALPHA(j) <= 1000. */
    /*  */
    /* 	E = BESSELI(ALPHA,X,1) computes I_sub_alpha(X)*EXP(-X). */
    /*  */
    /* 	The relationship between the Bessel functions of the first kind is */
    /*  */
    /* 	    I_sub_alpha(x) = i^(-alpha) * J_sub_alpha(i*x) */
    /*  */
    /* 	Examples: */
    /*  */
    /* 	    besseli(3:9,[0:.2:9.8 10:.5:20],1) generates the entire  */
    /* 	    71-by-7 table on page 423 of Abramowitz and Stegun, */
    /* 	    "Handbook of Mathematical Functions." */
    /*  */
    /* 	See also: BESSELJ, BESSELY, BESSELK. */
    /*    Acknowledgement: */
    /*  */
    /* 	This program is based on a Fortran program by W. J. Cody and */
    /* 	L. Stoltz, Applied Mathematics Division, Argonne National */
    /* 	Laboratory, dated May 30, 1989.  Their references include: */
    /*  */
    /* 	   "A Note on backward recurrence algorithms," Olver, F. W. J., */
    /* 	   and Sookne, D. J., Math. Comp. 26, 1972, pp 941-947. */
    /*  */
    /* 	   "Bessel functions of real argument and integer order," */
    /* 	   Sookne, D. J., NBS Jour. of Res. B. 77b, 1973, pp. 125-132. */
    /*  */
    /* 	   "Algorithm 597, Sequence of modified Bessel functions of the */
    /* 	   "first kind," Cody, W. J., Trans. Math. Soft., 1983, pp. 242-245. */
    /*  */
    /* 	MATLAB version: C. Moler, 10/6/92. */
    /* 	Copyright (c) 1984-94 by The MathWorks, Inc. */
    /*  */
    /*   Check for real, non-negative arguments. */
    /*  */
    /*     if nargin < 3, scale = 0; end */
    /*     if any(imag(xx)) | any(xx < 0) | any(imag(alpha)) | any(alpha < 0) */
    /*        error('Input arguments must be real and nonnegative.') */
    /*     end */
    /*     if isempty(alpha) | isempty(xx) */
    /*        bk = [];  */
    /*        return */
    /*     end */
    /* 'Mybesseli:56' scale = 0; */
    /*  */
    /*   Break alpha into integer and fractional parts, */
    /*   and initialize result array. */
    /*  */
    /* 'Mybesseli:61' nfirst = fix(alpha(1)); */
    /* 'Mybesseli:62' nb = fix(alpha(length(alpha))) + 1; */
    /* 'Mybesseli:63' b = NaN*ones(length(xx),nb); */
    /* 'Mybesseli:64' if ~(nb <= 1001) */
    /* 'Mybesseli:67' if length(alpha) > 1 */
    /*     resize = (length(alpha) == 1); */
    /* 'Mybesseli:73' resize_flag = (length(alpha) == 1); */
    /*     if resize, resize = size(xx); end */
    /* 'Mybesseli:75' if resize_flag */
    /* 'Mybesseli:76' resize = size(xx); */
    /* 'Mybesseli:78' xx = xx(:); */
    /*     b = NaN*ones(length(xx),nb); */
    /* 'Mybesseli:80' alpha = alpha(1) - nfirst; */
    /*  */
    /*   Asymptotic expansion for large x. */
    /*  */
    /* 'Mybesseli:84' v = find(1.e3 < xx); */
    /* 'Mybesseli:85' if any(v) */
    /*  */
    /*   Three-term backward recurrence for most x. */
    /*  */
    /* 'Mybesseli:99' v = find((1.e-4 <= xx) & (xx <= 1.e3)); */
    /* 'Mybesseli:100' if any(v) */
    /* 'Mybesseli:101' x = xx(v); */
    /* 'Mybesseli:102' magx = max(fix(x)); */
    /*  */
    /*      Initialize the forward sweep, the p-sequence of Olver. */
    /*  */
    /* 'Mybesseli:106' nbmx = nb-magx; */
    /* 'Mybesseli:107' n = magx+1; */
    c_n = 1.0;

    /* 'Mybesseli:108' en = (n+n) + (alpha+alpha); */
    en = 2.0;

    /* 'Mybesseli:109' plast = 1; */
    /* 'Mybesseli:110' p = en ./ x; */
    p = 4.0;

    /*  */
    /*      Calculate general significance test. */
    /*  */
    /* 'Mybesseli:114' test = 2/eps; */
    /* 'Mybesseli:115' if (2*magx > 80) */
    /* 'Mybesseli:117' else */
    /* 'Mybesseli:118' test = test / 1.585^magx; */
    /*        if (nbmx >= 3) */
    /*  % */
    /*  %     Calculate p-sequence until n = nb-1. */
    /*  % */
    /*           tover = eps*realmax; */
    /*           nstart = magx+2; */
    /*           nend = nb - 1; */
    /*           for k = nstart:nend */
    /*              n = k; */
    /*              en = en + 2; */
    /*              pold = plast; */
    /*              plast = p; */
    /*              p = en * plast./x + pold; */
    /*              if any(p > tover) */
    /*  % */
    /*  %           To avoid overflow, divide p-sequence by tover. */
    /*  %           Calculate p-sequence until abs(p) > 1. */
    /*  % */
    /*                 tover = realmax; */
    /*                 p = p / tover; */
    /*                 plast = plast / tover; */
    /*                 psave = p; */
    /*                 psavel = plast; */
    /*                 nstart = n + 1; */
    /*                 while any(p <= 1); */
    /*                    n = n + 1; */
    /*                    en = en + 2; */
    /*                    pold = plast; */
    /*                    plast = p; */
    /*                    p = en * plast./x + pold; */
    /*                 end */
    /*                 tempb = en ./ x; */
    /*  % */
    /*  %              Calculate backward test, and find ncalc, */
    /*  %              the highest n such that the test is passed. */
    /*  % */
    /*                 test = pold*plast*eps; */
    /*                 test = test*(0.5-0.5/min(tempb*tempb)); */
    /*                 p = plast * tover; */
    /*                 n = n - 1; */
    /*                 en = en - 2; */
    /*                 nend = min(nb,n); */
    /*                 ncalc = nend + 1; */
    /*                 for l = nstart:nend */
    /*                    pold = psavel; */
    /*                    psavel = psave; */
    /*                    psave = en * psavel./x + pold; */
    /*                    if any(psave.*psavel > test); */
    /*                       ncalc = l-1; */
    /*                       test = 0; */
    /*                       break */
    /*                    end */
    /*                 end */
    /*                 break */
    /*              end */
    /*           end */
    /*           if ~test */
    /*              n = nend; */
    /*              en = (n+n) + (alpha+alpha); */
    /*  % */
    /*  %           Calculate special significance test for nbmx > 2. */
    /*  % */
    /*              test = max(test,max(sqrt(plast/eps).*sqrt(p+p))); */
    /*           end */
    /*        end */
    /*  */
    /*      Calculate p-sequence until significance test passed. */
    /*  */
    /* 'Mybesseli:188' a = p; */
    a = 4.0;

    /* 'Mybesseli:189' count = 0; */
    count = 0;

    /* 'Mybesseli:190' while any(p < test) */
    while (!!(p < 9.007199254740992E+15)) {
      /* 'Mybesseli:191' n = n + 1; */
      c_n++;

      /* 'Mybesseli:192' en = en + 2; */
      en += 2.0;

      /* 'Mybesseli:193' if count == 1 */
      if (count == 1) {
        /* 'Mybesseli:194' plast = a; */
        /* 'Mybesseli:195' pold = plast; */
        pold = a;

        /* 'Mybesseli:196' a = p; */
        a = p;

        /* 'Mybesseli:197' p = en * a./x + pold; */
        p = en * p / 0.5 + pold;
      } else {
        /* 'Mybesseli:198' else */
        /* 'Mybesseli:199' count = 1; */
        count = 1;

        /* 'Mybesseli:200' a = p; */
        a = p;

        /* 'Mybesseli:201' p = en * a./x + ones(length(a),1); */
        p = en * p / 0.5 + 1.0;
      }

      /*           a = p; */
      /*           p = en * a./x + pold; */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /*  */
    /*      Initialize the backward recursion and the normalization sum. */
    /*  */
    /* 'Mybesseli:209' n = n + 1; */
    c_n++;

    /* 'Mybesseli:210' en = en + 2; */
    en += 2.0;

    /* 'Mybesseli:211' tempb = 0; */
    /* 'Mybesseli:212' tempa = 1 ./ p; */
    tempa = 1.0 / p;

    /* 'Mybesseli:213' em = n - 1; */
    em = c_n - 1.0;

    /* 'Mybesseli:214' empal = em + alpha; */
    empal = c_n - 1.0;

    /* 'Mybesseli:215' emp2al = (em - 1) + (alpha + alpha); */
    emp2al = (c_n - 1.0) - 1.0;

    /* 'Mybesseli:216' sum = tempa * empal * emp2al / em; */
    c_sum = tempa * (c_n - 1.0) * ((c_n - 1.0) - 1.0) / (c_n - 1.0);

    /* 'Mybesseli:217' nend = n - nb; */
    nend = c_n - 1.0;

    /* 'Mybesseli:218' skip = 0; */
    /* 'Mybesseli:219' if (nend < 0) */
    /* 'Mybesseli:223' else */
    /* 'Mybesseli:224' if (nend > 0) */
    /*  */
    /*            Recur backward via difference equation, calculating  */
    /*            (but not storing) b(n), until n = nb. */
    /*  */
    /* 'Mybesseli:229' kk= tempa; */
    kk = tempa;

    /* 'Mybesseli:230' count2 = 0; */
    count2 = 0;

    /* 'Mybesseli:231' for l = 1:nend */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, c_n - 1.0, mxDOUBLE_CLASS, (int32_T)
      (c_n - 1.0), &ee_emlrtRTEI, &st);
    l = 0;
    exitg1 = false;
    while ((!exitg1) && (l <= (int32_T)nend - 1)) {
      /* 'Mybesseli:232' n = n - 1; */
      c_n--;

      /* 'Mybesseli:233' en = en - 2; */
      en -= 2.0;

      /* 'Mybesseli:234' if count2 == 1 */
      if (count2 == 1) {
        /* 'Mybesseli:235' tempb = kk; */
        /* 'Mybesseli:236' tempc = tempb; */
        tempc = kk;

        /* 'Mybesseli:237' kk = tempa; */
        kk = tempa;

        /* 'Mybesseli:238' tempa = (en*kk) ./ x + tempc; */
        tempa = en * tempa / 0.5 + tempc;
      } else {
        /* 'Mybesseli:239' else */
        /* 'Mybesseli:240' count2 = 1; */
        count2 = 1;

        /* 'Mybesseli:241' kk = tempa; */
        kk = tempa;

        /* 'Mybesseli:242' tempa = (en*kk) ./ x; */
        tempa = en * tempa / 0.5;
      }

      /*                 tempc = tempb; */
      /*                 kk = tempa; */
      /*                 tempa = (en*kk) ./ x + tempc; */
      /* 'Mybesseli:247' em = em - 1; */
      em--;

      /* 'Mybesseli:248' emp2al = emp2al - 1; */
      emp2al--;

      /* 'Mybesseli:249' if (n == 1) */
      if (c_n == 1.0) {
        exitg1 = true;
      } else {
        /* 'Mybesseli:250' if (n == 2) */
        if (c_n == 2.0) {
          /* 'Mybesseli:250' emp2al = 1; */
          emp2al = 1.0;
        }

        /* 'Mybesseli:251' empal = empal - 1; */
        empal--;

        /* 'Mybesseli:252' sum = (sum + tempa*empal) * emp2al / em; */
        c_sum = (c_sum + tempa * empal) * emp2al / em;
        l++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    }

    emxInit_real_T1(&st, &b_y, 1, &hb_emlrtRTEI, true);

    /*  */
    /*         Store b(nb). */
    /*  */
    /* 'Mybesseli:258' b(v,n) = tempa; */
    k = (int32_T)c_n;
    if (!((k >= 1) && (k <= 1))) {
      emlrtDynamicBoundsCheckR2012b(k, 1, 1, &qd_emlrtBCI, &st);
    }

    /* 'Mybesseli:259' if (nb <= 1) */
    /* 'Mybesseli:260' sum = (sum + sum) + tempa; */
    c_sum = (c_sum + c_sum) + tempa;

    /* 'Mybesseli:261' skip = -1; */
    /* 'Mybesseli:280' if skip == 0 */
    /*  */
    /*      Calculate b(1) */
    /*  */
    /*        if skip == 0 */
    /*            b(v,1) = 2*empal*b(v,2) ./ x + b(v,3);  */
    /*        end */
    /*        if skip >= 0 */
    /*            sum = (sum + sum) + b(v,1);  */
    /*        end */
    /*  */
    /*      Normalize.  Divide all b(n) by sum. */
    /*  */
    /* 'Mybesseli:310' if (alpha ~= 0) */
    /* 'Mybesseli:313' if ~scale */
    /* 'Mybesseli:313' sum = sum .* exp(-x); */
    c_sum *= 0.60653065971263342;

    /* 'Mybesseli:314' for n = 1:nb */
    /* 'Mybesseli:315' b(v,n) = b(v,n) ./ sum; */
    b = tempa / c_sum;

    /*  */
    /*   Two-term ascending series for small x. */
    /*  */
    /* 'Mybesseli:321' v = find((0 < xx) & (xx < 1.e-4)); */
    /* 'Mybesseli:322' if any(v) */
    /*  */
    /*   x == 0 */
    /*  */
    /* 'Mybesseli:349' v = find(xx == 0); */
    /* 'Mybesseli:350' if any(v) */
    /*  */
    /*   Return the requested index range */
    /*  */
    /* 'Mybesseli:358' b = b(:,nfirst+1:nb); */
    /*     if resize */
    /* 'Mybesseli:360' if resize_flag */
    /* 'Mybesseli:361' output = reshape(b,resize(1),resize(2)); */
    k = b_y->size[0];
    b_y->size[0] = b_k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_y, k, (int32_T)sizeof(real_T),
                      &hb_emlrtRTEI);
    nm1d2 = b_k->size[0];
    for (k = 0; k < nm1d2; k++) {
      b_y->data[k] = anew * b_k->data[k];
    }

    emxFree_real_T(&b_k);
    st.site = &fe_emlrtRSI;
    Mybesseli(&st, b_y, w);
    k = w->size[0] * w->size[1];
    w->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)w, k, (int32_T)sizeof(real_T),
                      &hb_emlrtRTEI);
    nm1d2 = w->size[0];
    k = w->size[1];
    nm1d2 *= k;
    emxFree_real_T(&b_y);
    for (k = 0; k < nm1d2; k++) {
      w->data[k] /= b;
    }

    /*      w_test = besseli (0, k) / besseli (0, beta); */
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mykaiser.c) */
