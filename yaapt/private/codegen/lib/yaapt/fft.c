/*
 * File: fft.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "fft.h"
#include "yaapt_emxutil.h"

/* Function Declarations */
static int div_s32(int numerator, int denominator);
static void eml_fft(const emxArray_real_T *x, int n, emxArray_creal_T *y);

/* Function Definitions */

/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
static int div_s32(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
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
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int)absNumerator;
    } else {
      quotient = (int)absNumerator;
    }
  }

  return quotient;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int n
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void eml_fft(const emxArray_real_T *x, int n, emxArray_creal_T *y)
{
  int ju;
  int nd2;
  int minval;
  int ixDelta;
  emxArray_real_T *costab1q;
  int nRowsD2;
  int nRowsD4;
  int lastChan;
  double e;
  int k;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  int b_n;
  int ix;
  int chanStart;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int ihi;
  int istart;
  int j;
  double twid_im;
  ju = y->size[0];
  y->size[0] = n;
  emxEnsureCapacity((emxArray__common *)y, ju, (int)sizeof(creal_T));
  if (n > x->size[0]) {
    nd2 = y->size[0];
    ju = y->size[0];
    y->size[0] = nd2;
    emxEnsureCapacity((emxArray__common *)y, ju, (int)sizeof(creal_T));
    for (ju = 0; ju < nd2; ju++) {
      y->data[ju].re = 0.0;
      y->data[ju].im = 0.0;
    }
  }

  if (x->size[0] == 0) {
  } else {
    if (x->size[0] <= n) {
      minval = x->size[0];
    } else {
      minval = n;
    }

    nd2 = (x->size[0] - minval) + 1;
    if (1 >= nd2) {
      ixDelta = 1;
    } else {
      ixDelta = nd2;
    }

    emxInit_real_T(&costab1q, 2);
    nRowsD2 = n / 2;
    nRowsD4 = nRowsD2 / 2;
    lastChan = n * (div_s32(x->size[0], x->size[0]) - 1);
    e = 6.2831853071795862 / (double)n;
    ju = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = nRowsD4 + 1;
    emxEnsureCapacity((emxArray__common *)costab1q, ju, (int)sizeof(double));
    costab1q->data[0] = 1.0;
    nd2 = nRowsD4 / 2;
    for (k = 1; k <= nd2; k++) {
      costab1q->data[k] = cos(e * (double)k);
    }

    for (k = nd2 + 1; k < nRowsD4; k++) {
      costab1q->data[k] = sin(e * (double)(nRowsD4 - k));
    }

    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    costab1q->data[nRowsD4] = 0.0;
    b_n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    ju = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity((emxArray__common *)costab, ju, (int)sizeof(double));
    ju = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity((emxArray__common *)sintab, ju, (int)sizeof(double));
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= b_n; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[b_n - k];
    }

    for (k = costab1q->size[1]; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = -costab1q->data[k - b_n];
    }

    emxFree_real_T(&costab1q);
    ix = 0;
    chanStart = 0;
    while (((n > 0) && (chanStart <= lastChan)) || ((n < 0) && (chanStart >=
             lastChan))) {
      ju = 0;
      nd2 = chanStart;
      for (i = 1; i < minval; i++) {
        y->data[nd2].re = x->data[ix];
        y->data[nd2].im = 0.0;
        b_n = n;
        tst = true;
        while (tst) {
          b_n >>= 1;
          ju ^= b_n;
          tst = ((ju & b_n) == 0);
        }

        nd2 = chanStart + ju;
        ix++;
      }

      y->data[nd2].re = x->data[ix];
      y->data[nd2].im = 0.0;
      ix += ixDelta;
      nd2 = (chanStart + n) - 2;
      if (n > 1) {
        for (i = chanStart; i <= nd2; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }
      }

      nd2 = 2;
      ju = 4;
      k = nRowsD4;
      b_n = 1 + ((nRowsD4 - 1) << 2);
      while (k > 0) {
        i = chanStart;
        ihi = chanStart + b_n;
        while (i < ihi) {
          temp_re = y->data[i + nd2].re;
          temp_im = y->data[i + nd2].im;
          y->data[i + nd2].re = y->data[i].re - temp_re;
          y->data[i + nd2].im = y->data[i].im - temp_im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
          i += ju;
        }

        istart = chanStart + 1;
        for (j = k; j < nRowsD2; j += k) {
          e = costab->data[j];
          twid_im = sintab->data[j];
          i = istart;
          ihi = istart + b_n;
          while (i < ihi) {
            temp_re = e * y->data[i + nd2].re - twid_im * y->data[i + nd2].im;
            temp_im = e * y->data[i + nd2].im + twid_im * y->data[i + nd2].re;
            y->data[i + nd2].re = y->data[i].re - temp_re;
            y->data[i + nd2].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += ju;
          }

          istart++;
        }

        k /= 2;
        nd2 = ju;
        ju <<= 1;
        b_n -= nd2;
      }

      chanStart += n;
    }

    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                double varargin_1
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void b_fft(const emxArray_real_T *x, double varargin_1, emxArray_creal_T *y)
{
  emxArray_real_T *b_x;
  int i17;
  int loop_ub;
  emxArray_creal_T *b_y1;
  emxInit_real_T2(&b_x, 1);
  i17 = b_x->size[0];
  b_x->size[0] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b_x, i17, (int)sizeof(double));
  loop_ub = x->size[1];
  for (i17 = 0; i17 < loop_ub; i17++) {
    b_x->data[i17] = x->data[x->size[0] * i17];
  }

  emxInit_creal_T1(&b_y1, 1);
  eml_fft(b_x, (int)varargin_1, b_y1);
  i17 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_y1->size[0];
  emxEnsureCapacity((emxArray__common *)y, i17, (int)sizeof(creal_T));
  loop_ub = b_y1->size[0];
  emxFree_real_T(&b_x);
  for (i17 = 0; i17 < loop_ub; i17++) {
    y->data[y->size[0] * i17] = b_y1->data[i17];
  }

  emxFree_creal_T(&b_y1);
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                double varargin_1
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void fft(const emxArray_creal_T *x, double varargin_1, emxArray_creal_T *y)
{
  int sz[2];
  int ihi;
  int nd2;
  int n2;
  int i2;
  int minval;
  int ixDelta;
  emxArray_real_T *costab1q;
  int nRowsD2;
  int nRowsD4;
  int lastChan;
  double e;
  int k;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  int ix;
  int chanStart;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int istart;
  int j;
  double twid_im;
  for (ihi = 0; ihi < 2; ihi++) {
    sz[ihi] = x->size[ihi];
  }

  ihi = y->size[0] * y->size[1];
  y->size[0] = (int)varargin_1;
  y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)y, ihi, (int)sizeof(creal_T));
  if ((int)varargin_1 > x->size[0]) {
    ihi = y->size[0] * y->size[1];
    emxEnsureCapacity((emxArray__common *)y, ihi, (int)sizeof(creal_T));
    nd2 = y->size[1];
    for (ihi = 0; ihi < nd2; ihi++) {
      n2 = y->size[0];
      for (i2 = 0; i2 < n2; i2++) {
        y->data[i2 + y->size[0] * ihi].re = 0.0;
        y->data[i2 + y->size[0] * ihi].im = 0.0;
      }
    }
  }

  if ((x->size[0] == 0) || (x->size[1] == 0)) {
  } else {
    if (x->size[0] <= (int)varargin_1) {
      minval = x->size[0];
    } else {
      minval = (int)varargin_1;
    }

    nd2 = (x->size[0] - minval) + 1;
    if (1 >= nd2) {
      ixDelta = 1;
    } else {
      ixDelta = nd2;
    }

    emxInit_real_T(&costab1q, 2);
    ihi = (int)varargin_1;
    nRowsD2 = ihi / 2;
    nRowsD4 = nRowsD2 / 2;
    lastChan = (int)varargin_1 * (div_s32(x->size[0] * x->size[1], x->size[0]) -
      1);
    e = 6.2831853071795862 / (double)(int)varargin_1;
    ihi = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = nRowsD4 + 1;
    emxEnsureCapacity((emxArray__common *)costab1q, ihi, (int)sizeof(double));
    costab1q->data[0] = 1.0;
    nd2 = nRowsD4 / 2;
    for (k = 1; k <= nd2; k++) {
      costab1q->data[k] = cos(e * (double)k);
    }

    for (k = nd2 + 1; k < nRowsD4; k++) {
      costab1q->data[k] = sin(e * (double)(nRowsD4 - k));
    }

    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    costab1q->data[nRowsD4] = 0.0;
    nd2 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    ihi = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)costab, ihi, (int)sizeof(double));
    ihi = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)sintab, ihi, (int)sizeof(double));
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= nd2; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nd2 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nd2];
    }

    emxFree_real_T(&costab1q);
    ix = 0;
    chanStart = 0;
    while ((((int)varargin_1 > 0) && (chanStart <= lastChan)) || (((int)
             varargin_1 < 0) && (chanStart >= lastChan))) {
      n2 = 0;
      nd2 = chanStart;
      for (i = 1; i < minval; i++) {
        y->data[nd2] = x->data[ix];
        nd2 = (int)varargin_1;
        tst = true;
        while (tst) {
          nd2 >>= 1;
          n2 ^= nd2;
          tst = ((n2 & nd2) == 0);
        }

        nd2 = chanStart + n2;
        ix++;
      }

      y->data[nd2] = x->data[ix];
      ix += ixDelta;
      i2 = (chanStart + (int)varargin_1) - 2;
      if ((int)varargin_1 > 1) {
        for (i = chanStart; i <= i2; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }
      }

      nd2 = 2;
      n2 = 4;
      k = nRowsD4;
      i2 = 1 + ((nRowsD4 - 1) << 2);
      while (k > 0) {
        i = chanStart;
        ihi = chanStart + i2;
        while (i < ihi) {
          temp_re = y->data[i + nd2].re;
          temp_im = y->data[i + nd2].im;
          y->data[i + nd2].re = y->data[i].re - temp_re;
          y->data[i + nd2].im = y->data[i].im - temp_im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
          i += n2;
        }

        istart = chanStart + 1;
        for (j = k; j < nRowsD2; j += k) {
          e = costab->data[j];
          twid_im = sintab->data[j];
          i = istart;
          ihi = istart + i2;
          while (i < ihi) {
            temp_re = e * y->data[i + nd2].re - twid_im * y->data[i + nd2].im;
            temp_im = e * y->data[i + nd2].im + twid_im * y->data[i + nd2].re;
            y->data[i + nd2].re = y->data[i].re - temp_re;
            y->data[i + nd2].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += n2;
          }

          istart++;
        }

        k /= 2;
        nd2 = n2;
        n2 <<= 1;
        i2 -= nd2;
      }

      chanStart += (int)varargin_1;
    }

    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
