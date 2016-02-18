/*
 * File: Myfirls.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myfirls.h"
#include "yaapt_emxutil.h"
#include "sinc.h"
#include "rdivide.h"
#include "cos.h"
#include "Myhanning.h"
#include "Myspecgram.h"
#include "mldivide.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * FIRLS Linear-phase FIR filter design using least-squares error minimization
 *  B=FIRLS(N,F,M) returns a length N+1 linear phase (real, symmetric
 *  coefficients) FIR filter which has the best approximation to the
 *  desired frequency response described by F and M in the least squares
 *  sense. F is a vector of frequency band edges in pairs, in ascending
 *  order between 0 and 1. 1 corresponds to the Nyquist frequency or half
 *  the sampling frequency. M is a real vector the same size as F
 *  which specifies the desired magnitude of the frequency response of the
 *  resultant filter B. The desired response is the line connecting the
 *  points (F(k),M(k)) and (F(k+1),M(k+1)) for odd k; FIRLS treats the
 *  bands between F(k+1) and F(k+2) for odd k as "transition bands" or
 *  "don't care" regions. Thus the desired magnitude is piecewise linear
 *  with transition bands.  The integrated squared error is minimized.
 *
 *  B=FIRLS(N,F,M,W) uses the weights in W to weight the error. W has one
 *  entry per band (so it is half the length of F and M) which tells
 *  FIRLS how much emphasis to put on minimizing the integral squared error
 *  in each band relative to the other bands.
 *
 *  B=FIRLS(N,F,M,'Hilbert') and B=FIRLS(N,F,M,W,'Hilbert') design filters
 *  that have odd symmetry, that is, B(k) = -B(N+2-k) for k = 1, ..., N+1.
 *  A special case is a Hilbert transformer which has an approx. magnitude
 *  of 1 across the entire band, e.g. B=FIRLS(30,[.1 .9],[1 1],'Hilbert').
 *
 *  B=FIRLS(N,F,M,'differentiator') and B=FIRLS(N,F,M,W,'differentiator')
 *  also design filters with odd symmetry, but with a special weighting
 *  scheme for non-zero magnitude bands. The weight is assumed to be equal
 *  to the inverse of frequency, squared, times the weight W. Thus the
 *  filter has a much better fit at low frequency than at high frequency.
 *  This designs FIR differentiators.
 *
 *  See also REMEZ, FIR1, FIR2, FREQZ and FILTER.
 * Arguments    : double N
 *                double F[6]
 *                emxArray_real_T *h
 * Return Type  : void
 */
void Myfirls(double N, double F[6], emxArray_real_T *h)
{
  int i4;
  double L;
  emxArray_real_T *m;
  int n;
  double xtmp;
  double apnd;
  double ndbl;
  double cdiff;
  int nm1d2;
  int k;
  int loop_ub;
  emxArray_real_T *a;
  unsigned int uv1[2];
  emxArray_real_T *I1;
  int i5;
  emxArray_real_T *I2;
  emxArray_real_T *G;
  double b0;
  emxArray_real_T *b_k;
  emxArray_real_T *b;
  emxArray_real_T *r3;
  emxArray_real_T *r4;
  emxArray_real_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *b_b;
  emxArray_real_T *p;
  emxArray_real_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *r9;
  emxArray_real_T *r10;
  emxArray_real_T *r11;
  emxArray_real_T *r12;
  emxArray_real_T *y;
  emxArray_real_T *c_k;
  int s;
  int b_s;
  static const signed char M[6] = { 0, 0, 1, 1, 0, 0 };

  double b_m;
  double b1;
  int i6;
  emxArray_real_T *b_p;
  emxArray_real_T *b_a;

  /* 	Example of a length 29 low-pass filter: */
  /* 		h=firls(30,[0 .1 .2 .5]*2,[1 1 0 0]); */
  /* 	Example of a low-pass differentiator:  */
  /* 		h=firls(N,[0 10 20 40]/50,[0 .2 0 0],'differentiator'); */
  /*  */
  /*        Author(s): T. Krauss, 10-18-91 */
  /*    		   T. Krauss, 3-30-93, updated */
  /* 	Copyright (c) 1984-94 by The MathWorks, Inc. */
  /* 	$Revision: 1.8 $  $Date: 1994/01/25 17:59:10 $ */
  /*  check number of arguments, set up defaults. */
  /*  nargchk(3,5,nargin); */
  /*  if (nargin==3) */
  /*      ftype = ''; */
  /*  end */
  /*  if (nargin==4), */
  /*      if isstr(W),  */
  /*          ftype = W; W = ones(length(F)/2,1); */
  /*      else */
  /*          ftype = ''; */
  /*      end */
  /*  end	 */
  /*  if (nargin==5), */
  /*      if isempty(W),  */
  /*          W = ones(length(F)/2,1); */
  /*      end */
  /*  end */
  /*  if isempty(ftype) */
  /*  else */
  /*      ftype = lower(ftype); */
  /*      if strcmp(ftype,'h')|strcmp(ftype,'hilbert') */
  /*          ftype = 1;  differ = 0; */
  /*      elseif strcmp(ftype,'d')|strcmp(ftype,'differentiator') */
  /*          ftype = 1;  differ = 1; */
  /*      else */
  /*          error('Requires symmetry to be ''Hilbert'' or ''differentiator''.') */
  /*      end */
  /*  end */
  N++;

  /*  filter length */
  for (i4 = 0; i4 < 6; i4++) {
    F[i4] /= 2.0;
  }

  /*  make these guys columns */
  L = (N - 1.0) / 2.0;

  /*  Type I and Type II linear phase FIR  */
  /*  basis vectors are cos(2*pi*m*f) (see m below) */
  emxInit_real_T(&m, 2);
  if (rt_remd_snf(N, 2.0) == 0.0) {
    if (rtIsNaN(L)) {
      n = 1;
      xtmp = rtNaN;
      apnd = L;
    } else if (L < 0.0) {
      n = 0;
      xtmp = 0.0;
      apnd = L;
    } else if (rtIsInf(L)) {
      n = 1;
      xtmp = rtNaN;
      apnd = L;
    } else {
      xtmp = 0.0;
      ndbl = floor(L + 0.5);
      apnd = ndbl;
      cdiff = ndbl - L;
      if (fabs(cdiff) < 4.4408920985006262E-16 * L) {
        ndbl++;
        apnd = L;
      } else if (cdiff > 0.0) {
        apnd = ndbl - 1.0;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int)ndbl;
      } else {
        n = 0;
      }
    }

    i4 = m->size[0] * m->size[1];
    m->size[0] = 1;
    m->size[1] = n;
    emxEnsureCapacity((emxArray__common *)m, i4, (int)sizeof(double));
    if (n > 0) {
      m->data[0] = xtmp;
      if (n > 1) {
        m->data[n - 1] = apnd;
        i4 = n - 1;
        nm1d2 = i4 / 2;
        for (k = 1; k < nm1d2; k++) {
          m->data[k] = xtmp + (double)k;
          m->data[(n - k) - 1] = apnd - (double)k;
        }

        if (nm1d2 << 1 == n - 1) {
          m->data[nm1d2] = (xtmp + apnd) / 2.0;
        } else {
          m->data[nm1d2] = xtmp + (double)nm1d2;
          m->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    i4 = m->size[0] * m->size[1];
    m->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)m, i4, (int)sizeof(double));
    n = m->size[0];
    nm1d2 = m->size[1];
    loop_ub = n * nm1d2;
    for (i4 = 0; i4 < loop_ub; i4++) {
      m->data[i4] += 0.5;
    }

    /*  type II */
  } else {
    if (rtIsNaN(L)) {
      n = 1;
      xtmp = rtNaN;
      apnd = L;
    } else if (L < 0.0) {
      n = 0;
      xtmp = 0.0;
      apnd = L;
    } else if (rtIsInf(L)) {
      n = 1;
      xtmp = rtNaN;
      apnd = L;
    } else {
      xtmp = 0.0;
      ndbl = floor(L + 0.5);
      apnd = ndbl;
      cdiff = ndbl - L;
      if (fabs(cdiff) < 4.4408920985006262E-16 * L) {
        ndbl++;
        apnd = L;
      } else if (cdiff > 0.0) {
        apnd = ndbl - 1.0;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int)ndbl;
      } else {
        n = 0;
      }
    }

    i4 = m->size[0] * m->size[1];
    m->size[0] = 1;
    m->size[1] = n;
    emxEnsureCapacity((emxArray__common *)m, i4, (int)sizeof(double));
    if (n > 0) {
      m->data[0] = xtmp;
      if (n > 1) {
        m->data[n - 1] = apnd;
        i4 = n - 1;
        nm1d2 = i4 / 2;
        for (k = 1; k < nm1d2; k++) {
          m->data[k] = xtmp + (double)k;
          m->data[(n - k) - 1] = apnd - (double)k;
        }

        if (nm1d2 << 1 == n - 1) {
          m->data[nm1d2] = (xtmp + apnd) / 2.0;
        } else {
          m->data[nm1d2] = xtmp + (double)nm1d2;
          m->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    /*  type I */
  }

  emxInit_real_T2(&a, 1);

  /*      k=m'; */
  i4 = a->size[0];
  a->size[0] = m->size[1];
  emxEnsureCapacity((emxArray__common *)a, i4, (int)sizeof(double));
  loop_ub = m->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    a->data[i4] = m->data[m->size[0] * i4];
  }

  for (i4 = 0; i4 < 2; i4++) {
    uv1[i4] = (unsigned int)m->size[i4];
  }

  emxInit_real_T(&I1, 2);
  loop_ub = a->size[0];
  i4 = I1->size[0] * I1->size[1];
  I1->size[0] = loop_ub;
  I1->size[1] = (int)uv1[1];
  emxEnsureCapacity((emxArray__common *)I1, i4, (int)sizeof(double));
  nm1d2 = (int)uv1[1];
  for (i4 = 0; i4 < nm1d2; i4++) {
    for (i5 = 0; i5 < loop_ub; i5++) {
      I1->data[i5 + I1->size[0] * i4] = a->data[i5] + m->data[m->size[0] * i4];
    }
  }

  /*  entries are m + k */
  for (i4 = 0; i4 < 2; i4++) {
    uv1[i4] = (unsigned int)m->size[i4];
  }

  emxInit_real_T(&I2, 2);
  loop_ub = a->size[0];
  i4 = I2->size[0] * I2->size[1];
  I2->size[0] = loop_ub;
  I2->size[1] = (int)uv1[1];
  emxEnsureCapacity((emxArray__common *)I2, i4, (int)sizeof(double));
  nm1d2 = (int)uv1[1];
  for (i4 = 0; i4 < nm1d2; i4++) {
    for (i5 = 0; i5 < loop_ub; i5++) {
      I2->data[i5 + I2->size[0] * i4] = a->data[i5] - m->data[m->size[0] * i4];
    }
  }

  /*  entries are m - k */
  for (i4 = 0; i4 < 2; i4++) {
    uv1[i4] = (unsigned int)I1->size[i4];
  }

  emxInit_real_T(&G, 2);
  i4 = G->size[0] * G->size[1];
  G->size[0] = (int)uv1[0];
  G->size[1] = (int)uv1[1];
  emxEnsureCapacity((emxArray__common *)G, i4, (int)sizeof(double));
  loop_ub = (int)uv1[0] * (int)uv1[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    G->data[i4] = 0.0;
  }

  b0 = 0.0;

  /*   first entry must be handled separately (where k(1)=0) */
  emxInit_real_T2(&b_k, 1);
  if (rt_remd_snf(N, 2.0) != 0.0) {
    if (2 > a->size[0]) {
      i4 = 0;
      i5 = 0;
    } else {
      i4 = 1;
      i5 = a->size[0];
    }

    k = b_k->size[0];
    b_k->size[0] = i5 - i4;
    emxEnsureCapacity((emxArray__common *)b_k, k, (int)sizeof(double));
    loop_ub = i5 - i4;
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_k->data[i5] = a->data[i4 + i5];
    }
  } else {
    i4 = b_k->size[0];
    b_k->size[0] = m->size[1];
    emxEnsureCapacity((emxArray__common *)b_k, i4, (int)sizeof(double));
    loop_ub = m->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_k->data[i4] = m->data[m->size[0] * i4];
    }
  }

  emxFree_real_T(&m);
  emxInit_real_T2(&b, 1);
  uv1[0] = (unsigned int)b_k->size[0];
  i4 = b->size[0];
  b->size[0] = (int)uv1[0];
  emxEnsureCapacity((emxArray__common *)b, i4, (int)sizeof(double));
  loop_ub = (int)uv1[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b->data[i4] = 0.0;
  }

  emxInit_real_T(&r3, 2);
  emxInit_real_T(&r4, 2);
  emxInit_real_T(&r5, 2);
  emxInit_real_T(&r6, 2);
  emxInit_real_T2(&b_b, 1);
  emxInit_real_T2(&p, 1);
  emxInit_real_T(&r7, 2);
  emxInit_real_T(&r8, 2);
  emxInit_real_T(&r9, 2);
  emxInit_real_T(&r10, 2);
  emxInit_real_T2(&r11, 1);
  emxInit_real_T2(&r12, 1);
  emxInit_real_T2(&y, 1);
  emxInit_real_T2(&c_k, 1);
  for (s = 0; s < 3; s++) {
    b_s = s << 1;
    b_m = (double)(M[b_s + 1] - M[b_s]) / (F[b_s + 1] - F[b_s]);

    /*   slope */
    b1 = (double)M[b_s] - b_m * F[b_s];

    /*   y-intercept */
    b0 += b1 * (F[b_s + 1] - F[b_s]) + b_m / 2.0 * (F[b_s + 1] * F[b_s + 1] -
      F[b_s] * F[b_s]);
    i4 = p->size[0];
    p->size[0] = b_k->size[0];
    emxEnsureCapacity((emxArray__common *)p, i4, (int)sizeof(double));
    loop_ub = b_k->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      p->data[i4] = 6.2831853071795862 * b_k->data[i4] * F[b_s + 1];
    }

    b_cos(p);
    i4 = b_b->size[0];
    b_b->size[0] = b_k->size[0];
    emxEnsureCapacity((emxArray__common *)b_b, i4, (int)sizeof(double));
    loop_ub = b_k->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_b->data[i4] = 6.2831853071795862 * b_k->data[i4] * F[b_s];
    }

    b_cos(b_b);
    xtmp = b_m / 39.478417604357432;
    i4 = y->size[0];
    y->size[0] = p->size[0];
    emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
    loop_ub = p->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      y->data[i4] = xtmp * (p->data[i4] - b_b->data[i4]);
    }

    i4 = c_k->size[0];
    c_k->size[0] = b_k->size[0];
    emxEnsureCapacity((emxArray__common *)c_k, i4, (int)sizeof(double));
    loop_ub = b_k->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      c_k->data[i4] = b_k->data[i4] * b_k->data[i4];
    }

    b_rdivide(y, c_k, a);
    i4 = b->size[0];
    emxEnsureCapacity((emxArray__common *)b, i4, (int)sizeof(double));
    loop_ub = b->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b->data[i4] += a->data[i4];
    }

    ndbl = F[b_s + 1] * (b_m * F[b_s + 1] + b1);
    i4 = r12->size[0];
    r12->size[0] = b_k->size[0];
    emxEnsureCapacity((emxArray__common *)r12, i4, (int)sizeof(double));
    loop_ub = b_k->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      r12->data[i4] = 2.0 * b_k->data[i4] * F[b_s + 1];
    }

    sinc(r12, p);
    xtmp = F[b_s] * (b_m * F[b_s] + b1);
    i4 = r11->size[0];
    r11->size[0] = b_k->size[0];
    emxEnsureCapacity((emxArray__common *)r11, i4, (int)sizeof(double));
    loop_ub = b_k->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      r11->data[i4] = 2.0 * b_k->data[i4] * F[b_s];
    }

    sinc(r11, b_b);
    i4 = b->size[0];
    emxEnsureCapacity((emxArray__common *)b, i4, (int)sizeof(double));
    loop_ub = b->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b->data[i4] += ndbl * p->data[i4] - xtmp * b_b->data[i4];
    }

    i4 = r10->size[0] * r10->size[1];
    r10->size[0] = I1->size[0];
    r10->size[1] = I1->size[1];
    emxEnsureCapacity((emxArray__common *)r10, i4, (int)sizeof(double));
    loop_ub = I1->size[0] * I1->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      r10->data[i4] = 2.0 * I1->data[i4] * F[b_s + 1];
    }

    b_sinc(r10, r3);
    i4 = r9->size[0] * r9->size[1];
    r9->size[0] = I2->size[0];
    r9->size[1] = I2->size[1];
    emxEnsureCapacity((emxArray__common *)r9, i4, (int)sizeof(double));
    loop_ub = I2->size[0] * I2->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      r9->data[i4] = 2.0 * I2->data[i4] * F[b_s + 1];
    }

    b_sinc(r9, r4);
    i4 = r8->size[0] * r8->size[1];
    r8->size[0] = I1->size[0];
    r8->size[1] = I1->size[1];
    emxEnsureCapacity((emxArray__common *)r8, i4, (int)sizeof(double));
    loop_ub = I1->size[0] * I1->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      r8->data[i4] = 2.0 * I1->data[i4] * F[b_s];
    }

    b_sinc(r8, r5);
    i4 = r7->size[0] * r7->size[1];
    r7->size[0] = I2->size[0];
    r7->size[1] = I2->size[1];
    emxEnsureCapacity((emxArray__common *)r7, i4, (int)sizeof(double));
    loop_ub = I2->size[0] * I2->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      r7->data[i4] = 2.0 * I2->data[i4] * F[b_s];
    }

    b_sinc(r7, r6);
    ndbl = 0.5 * F[b_s + 1];
    xtmp = 0.5 * F[b_s];
    i4 = G->size[0] * G->size[1];
    emxEnsureCapacity((emxArray__common *)G, i4, (int)sizeof(double));
    nm1d2 = G->size[0];
    k = G->size[1];
    loop_ub = nm1d2 * k;
    for (i4 = 0; i4 < loop_ub; i4++) {
      G->data[i4] += ndbl * (r3->data[i4] + r4->data[i4]) - xtmp * (r5->data[i4]
        + r6->data[i4]);
    }
  }

  emxFree_real_T(&c_k);
  emxFree_real_T(&y);
  emxFree_real_T(&r12);
  emxFree_real_T(&r11);
  emxFree_real_T(&r10);
  emxFree_real_T(&r9);
  emxFree_real_T(&r8);
  emxFree_real_T(&r7);
  emxFree_real_T(&r6);
  emxFree_real_T(&r5);
  emxFree_real_T(&r4);
  emxFree_real_T(&r3);
  emxFree_real_T(&b_k);
  emxFree_real_T(&I2);
  emxFree_real_T(&I1);
  if (rt_remd_snf(N, 2.0) != 0.0) {
    i4 = p->size[0];
    p->size[0] = 1 + b->size[0];
    emxEnsureCapacity((emxArray__common *)p, i4, (int)sizeof(double));
    p->data[0] = b0;
    loop_ub = b->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      p->data[i4 + 1] = b->data[i4];
    }
  } else {
    i4 = p->size[0];
    p->size[0] = b->size[0];
    emxEnsureCapacity((emxArray__common *)p, i4, (int)sizeof(double));
    loop_ub = b->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      p->data[i4] = b->data[i4];
    }
  }

  emxFree_real_T(&b);
  mldivide(G, p, a);
  emxFree_real_T(&G);
  if (rt_remd_snf(N, 2.0) != 0.0) {
    if (2.0 > L + 1.0) {
      i4 = 1;
      i5 = 1;
      k = 0;
    } else {
      i4 = (int)(L + 1.0);
      i5 = -1;
      k = 2;
    }

    if (2.0 > L + 1.0) {
      n = 0;
      i6 = 0;
    } else {
      n = 1;
      i6 = (int)(L + 1.0);
    }

    emxInit_real_T2(&b_p, 1);
    nm1d2 = b_p->size[0];
    b_p->size[0] = div_s32_floor(k - i4, i5) + 1;
    emxEnsureCapacity((emxArray__common *)b_p, nm1d2, (int)sizeof(double));
    loop_ub = div_s32_floor(k - i4, i5);
    for (k = 0; k <= loop_ub; k++) {
      b_p->data[k] = a->data[(i4 + i5 * k) - 1];
    }

    emxInit_real_T2(&b_a, 1);
    rdivide(b_p, 2.0, p);
    i4 = b_a->size[0];
    b_a->size[0] = i6 - n;
    emxEnsureCapacity((emxArray__common *)b_a, i4, (int)sizeof(double));
    loop_ub = i6 - n;
    emxFree_real_T(&b_p);
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_a->data[i4] = a->data[n + i4];
    }

    rdivide(b_a, 2.0, b_b);
    i4 = h->size[0] * h->size[1];
    h->size[0] = 1;
    h->size[1] = (p->size[0] + b_b->size[0]) + 1;
    emxEnsureCapacity((emxArray__common *)h, i4, (int)sizeof(double));
    loop_ub = p->size[0];
    emxFree_real_T(&b_a);
    for (i4 = 0; i4 < loop_ub; i4++) {
      h->data[h->size[0] * i4] = p->data[i4];
    }

    h->data[h->size[0] * p->size[0]] = a->data[0];
    loop_ub = b_b->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      h->data[h->size[0] * ((i4 + p->size[0]) + 1)] = b_b->data[i4];
    }
  } else {
    i4 = p->size[0];
    p->size[0] = a->size[0];
    emxEnsureCapacity((emxArray__common *)p, i4, (int)sizeof(double));
    loop_ub = a->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      p->data[i4] = a->data[i4];
    }

    n = a->size[0];
    nm1d2 = a->size[0] >> 1;
    for (k = 1; k <= nm1d2; k++) {
      xtmp = p->data[k - 1];
      p->data[k - 1] = p->data[n - k];
      p->data[n - k] = xtmp;
    }

    emxInit_real_T(&b_p, 2);
    i4 = b_p->size[0] * b_p->size[1];
    b_p->size[0] = 1;
    b_p->size[1] = p->size[0] + a->size[0];
    emxEnsureCapacity((emxArray__common *)b_p, i4, (int)sizeof(double));
    loop_ub = p->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_p->data[b_p->size[0] * i4] = p->data[i4];
    }

    loop_ub = a->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_p->data[b_p->size[0] * (i4 + p->size[0])] = a->data[i4];
    }

    i4 = h->size[0] * h->size[1];
    h->size[0] = 1;
    h->size[1] = b_p->size[1];
    emxEnsureCapacity((emxArray__common *)h, i4, (int)sizeof(double));
    loop_ub = b_p->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      h->data[h->size[0] * i4] = 0.5 * b_p->data[b_p->size[0] * i4];
    }

    emxFree_real_T(&b_p);
  }

  emxFree_real_T(&b_b);
  emxFree_real_T(&p);
  emxFree_real_T(&a);

  /*  elseif (ftype == 1),  % Type III and Type IV linear phase FIR */
  /*                    %  basis vectors are sin(2*pi*m*f) (see m below) */
  /*      if (differ),      % weight non-zero bands with 1/f^2 */
  /*          do_weight = ( abs(M(1:2:length(M))) +  abs(M(2:2:length(M))) ) > 0; */
  /*      else */
  /*          do_weight = zeros(size(F)); */
  /*      end */
  /*   */
  /*      if rem(N,2), */
  /*          m=(1:L);      % type III */
  /*      else */
  /*          m=(0:L)+.5;   % type IV */
  /*      end; */
  /*      k=m'; */
  /*      I1=k(:,ones(size(m)))+m(ones(size(k)),:);    % entries are m + k */
  /*      I2=k(:,ones(size(m)))-m(ones(size(k)),:);    % entries are m - k */
  /*      b=zeros(size(k)); */
  /*      G=zeros(size(I1)); */
  /*   */
  /*      i = sqrt(-1); */
  /*      for s=1:2:length(F), */
  /*          if (do_weight((s+1)/2)),      % weight bands with 1/f^2 */
  /*              if F(s) == 0, F(s) = 1e-5; end     % avoid singularities */
  /*              m=(M(s+1)-M(s))/(F(s+1)-F(s)); */
  /*              b1=M(s)-m*F(s); */
  /*              snint1 = sineint(2*pi*k*F(s+1)) - sineint(2*pi*k*F(s)); */
  /*              %snint1 = (-1/2/i)*(expint(i*2*pi*k*F(s+1)) ... */
  /*              %    -expint(-i*2*pi*k*F(s+1)) -expint(i*2*pi*k*F(s)) ... */
  /*              %    +expint(-i*2*pi*k*F(s)) ); */
  /*              % csint1 = cosint(2*pi*k*F(s+1)) - cosint(2*pi*k*F(s)) ; */
  /*              csint1 = (-1/2)*(expint(i*2*pi*k*F(s+1))+expint(-i*2*pi*k*F(s+1))... */
  /*                              -expint(i*2*pi*k*F(s))  -expint(-i*2*pi*k*F(s)) ); */
  /*              b=b + ( m*snint1 ... */
  /*                  + b1*2*pi*k.*( -sinc(2*k*F(s+1)) + sinc(2*k*F(s)) + csint1 ))... */
  /*                  * abs(W((s+1)/2)^2); */
  /*              snint1 = sineint(2*pi*F(s+1)*(-I2)); */
  /*              snint2 = sineint(2*pi*F(s+1)*I1); */
  /*              snint3 = sineint(2*pi*F(s)*(-I2)); */
  /*              snint4 = sineint(2*pi*F(s)*I1); */
  /*              G = G - ( ( -1/2*( cos(2*pi*F(s+1)*(-I2))/F(s+1)  ... */
  /*                        - 2*snint1*pi.*I2 ... */
  /*                        - cos(2*pi*F(s+1)*I1)/F(s+1) ... */
  /*                        - 2*snint2*pi.*I1 )) ... */
  /*                    - ( -1/2*( cos(2*pi*F(s)*(-I2))/F(s)  ... */
  /*                        - 2*snint3*pi.*I2 ... */
  /*                        - cos(2*pi*F(s)*I1)/F(s) ... */
  /*                        - 2*snint4*pi.*I1) ) ) ... */
  /*                           * abs(W((s+1)/2)^2); */
  /*          else      % use usual weights */
  /*              m=(M(s+1)-M(s))/(F(s+1)-F(s)); */
  /*              b1=M(s)-m*F(s); */
  /*              b=b+(m/(4*pi*pi)*(sin(2*pi*k*F(s+1))-sin(2*pi*k*F(s)))./(k.*k))... */
  /*                           * abs(W((s+1)/2)^2) ; */
  /*              b = b + (((m*F(s)+b1)*cos(2*pi*k*F(s)) - ... */
  /*                   (m*F(s+1)+b1)*cos(2*pi*k*F(s+1)))./(2*pi*k)) ... */
  /*                           * abs(W((s+1)/2)^2) ; */
  /*              G = G + (.5*F(s+1)*(sinc(2*I1*F(s+1))-sinc(2*I2*F(s+1))) ... */
  /*                 - .5*F(s)*(sinc(2*I1*F(s))-sinc(2*I2*F(s)))) * abs(W((s+1)/2)^2); */
  /*          end; */
  /*      end */
  /*   */
  /*      a=G\b; */
  /*      if (rem(N,2)~=0), */
  /*          h=.5*[flipud(a); 0; -a].'; */
  /*      else */
  /*          h=.5*[flipud(a); -a].'; */
  /*      end */
  /*  end     */
}

/*
 * File trailer for Myfirls.c
 *
 * [EOF]
 */
