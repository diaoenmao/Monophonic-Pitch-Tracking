/*
 * File: Mykaiser.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Jan-2016 00:47:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Mykaiser.h"
#include "yaapt_emxutil.h"
#include "Mybesseli.h"
#include "sqrt.h"

/* Function Definitions */

/*
 * Arguments    : double n
 *                emxArray_real_T *w
 * Return Type  : void
 */
void Mykaiser(double n, emxArray_real_T *w)
{
  int k;
  int b_n;
  double anew;
  double apnd;
  double ndbl;
  double cdiff;
  emxArray_real_T *y;
  int nm1d2;
  emxArray_real_T *b_k;
  double c_n;
  double en;
  double p;
  double a;
  int count;
  double pold;
  double tempa;
  double em;
  double empal;
  double emp2al;
  double c_sum;
  double nend;
  double kk;
  int count2;
  int l;
  boolean_T exitg1;
  double tempc;
  emxArray_real_T *b_y;
  double b;

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
  if (n == 1.0) {
    k = w->size[0] * w->size[1];
    w->size[0] = 1;
    w->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)w, k, (int)sizeof(double));
    w->data[0] = 1.0;
  } else {
    if (rtIsNaN(n - 1.0)) {
      b_n = 1;
      anew = rtNaN;
      apnd = n - 1.0;
    } else if (n - 1.0 < 0.0) {
      b_n = 0;
      anew = 0.0;
      apnd = n - 1.0;
    } else if (rtIsInf(n - 1.0)) {
      b_n = 1;
      anew = rtNaN;
      apnd = n - 1.0;
    } else {
      anew = 0.0;
      ndbl = floor((n - 1.0) + 0.5);
      apnd = ndbl;
      cdiff = ndbl - (n - 1.0);
      if (fabs(cdiff) < 4.4408920985006262E-16 * fabs(n - 1.0)) {
        ndbl++;
        apnd = n - 1.0;
      } else if (cdiff > 0.0) {
        apnd = ndbl - 1.0;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        b_n = (int)ndbl;
      } else {
        b_n = 0;
      }
    }

    emxInit_real_T(&y, 2);
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = b_n;
    emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(double));
    if (b_n > 0) {
      y->data[0] = anew;
      if (b_n > 1) {
        y->data[b_n - 1] = apnd;
        k = b_n - 1;
        nm1d2 = k / 2;
        for (k = 1; k < nm1d2; k++) {
          y->data[k] = anew + (double)k;
          y->data[(b_n - k) - 1] = apnd - (double)k;
        }

        if (nm1d2 << 1 == b_n - 1) {
          y->data[nm1d2] = (anew + apnd) / 2.0;
        } else {
          y->data[nm1d2] = anew + (double)nm1d2;
          y->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    emxInit_real_T1(&b_k, 1);
    k = b_k->size[0];
    b_k->size[0] = y->size[1];
    emxEnsureCapacity((emxArray__common *)b_k, k, (int)sizeof(double));
    nm1d2 = y->size[1];
    for (k = 0; k < nm1d2; k++) {
      b_k->data[k] = y->data[y->size[0] * k];
    }

    emxFree_real_T(&y);
    anew = 1.0 / (n - 1.0);
    k = b_k->size[0];
    emxEnsureCapacity((emxArray__common *)b_k, k, (int)sizeof(double));
    nm1d2 = b_k->size[0];
    for (k = 0; k < nm1d2; k++) {
      b_k->data[k] *= (n - 1.0) - b_k->data[k];
    }

    b_sqrt(b_k);

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
    /*  */
    /*   Break alpha into integer and fractional parts, */
    /*   and initialize result array. */
    /*  */
    /*     resize = (length(alpha) == 1); */
    /*     if resize, resize = size(xx); end */
    /*     b = NaN*ones(length(xx),nb); */
    /*  */
    /*   Asymptotic expansion for large x. */
    /*  */
    /*  */
    /*   Three-term backward recurrence for most x. */
    /*  */
    /*  */
    /*      Initialize the forward sweep, the p-sequence of Olver. */
    /*  */
    c_n = 1.0;
    en = 2.0;
    p = 4.0;

    /*  */
    /*      Calculate general significance test. */
    /*  */
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
    a = 4.0;
    count = 0;
    while (!!(p < 9.007199254740992E+15)) {
      c_n++;
      en += 2.0;
      if (count == 1) {
        pold = a;
        a = p;
        p = en * p / 0.5 + pold;
      } else {
        count = 1;
        a = p;
        p = en * p / 0.5 + 1.0;
      }

      /*           a = p; */
      /*           p = en * a./x + pold; */
    }

    /*  */
    /*      Initialize the backward recursion and the normalization sum. */
    /*  */
    c_n++;
    en += 2.0;
    tempa = 1.0 / p;
    em = c_n - 1.0;
    empal = c_n - 1.0;
    emp2al = (c_n - 1.0) - 1.0;
    c_sum = tempa * (c_n - 1.0) * ((c_n - 1.0) - 1.0) / (c_n - 1.0);
    nend = c_n - 1.0;

    /*  */
    /*            Recur backward via difference equation, calculating  */
    /*            (but not storing) b(n), until n = nb. */
    /*  */
    kk = tempa;
    count2 = 0;
    l = 0;
    exitg1 = false;
    while ((!exitg1) && (l <= (int)nend - 1)) {
      c_n--;
      en -= 2.0;
      if (count2 == 1) {
        tempc = kk;
        kk = tempa;
        tempa = en * tempa / 0.5 + tempc;
      } else {
        count2 = 1;
        kk = tempa;
        tempa = en * tempa / 0.5;
      }

      /*                 tempc = tempb; */
      /*                 kk = tempa; */
      /*                 tempa = (en*kk) ./ x + tempc; */
      em--;
      emp2al--;
      if (c_n == 1.0) {
        exitg1 = true;
      } else {
        if (c_n == 2.0) {
          emp2al = 1.0;
        }

        empal--;
        c_sum = (c_sum + tempa * empal) * emp2al / em;
        l++;
      }
    }

    emxInit_real_T1(&b_y, 1);

    /*  */
    /*         Store b(nb). */
    /*  */
    c_sum = (c_sum + c_sum) + tempa;

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
    c_sum *= 0.60653065971263342;
    b = tempa / c_sum;

    /*  */
    /*   Two-term ascending series for small x. */
    /*  */
    /*  */
    /*   x == 0 */
    /*  */
    /*  */
    /*   Return the requested index range */
    /*  */
    /*     if resize */
    k = b_y->size[0];
    b_y->size[0] = b_k->size[0];
    emxEnsureCapacity((emxArray__common *)b_y, k, (int)sizeof(double));
    nm1d2 = b_k->size[0];
    for (k = 0; k < nm1d2; k++) {
      b_y->data[k] = anew * b_k->data[k];
    }

    emxFree_real_T(&b_k);
    Mybesseli(b_y, w);
    k = w->size[0] * w->size[1];
    w->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)w, k, (int)sizeof(double));
    nm1d2 = w->size[0];
    k = w->size[1];
    nm1d2 *= k;
    emxFree_real_T(&b_y);
    for (k = 0; k < nm1d2; k++) {
      w->data[k] /= b;
    }

    /*      w_test = besseli (0, k) / besseli (0, beta); */
  }
}

/*
 * File trailer for Mykaiser.c
 *
 * [EOF]
 */
