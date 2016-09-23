/*
 * File: fft.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "fft.h"
#include "yaapt_emxutil.h"

/* Function Declarations */
static void b_generate_twiddle_tables(int nRows, boolean_T useRadix2,
  emxArray_real_T *costab, emxArray_real_T *sintab, emxArray_real_T *sintabinv);
static void b_r2br_r2dit_trig(const emxArray_creal_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y);
static void eml_fft(const emxArray_real_T *x, int n, emxArray_creal_T *y);
static void generate_twiddle_tables(int nRows, boolean_T useRadix2,
  emxArray_real_T *costab, emxArray_real_T *sintab, emxArray_real_T *sintabinv);
static void get_algo_sizes(int n1, boolean_T useRadix2, int *N2blue, int *nRows);
static void r2br_r2dit_trig(const emxArray_creal_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y);
static void r2br_r2dit_trig_impl(const emxArray_creal_T *x, int unsigned_nRows,
  const emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T
  *y);

/* Function Definitions */

/*
 * Arguments    : int nRows
 *                boolean_T useRadix2
 *                emxArray_real_T *costab
 *                emxArray_real_T *sintab
 *                emxArray_real_T *sintabinv
 * Return Type  : void
 */
static void b_generate_twiddle_tables(int nRows, boolean_T useRadix2,
  emxArray_real_T *costab, emxArray_real_T *sintab, emxArray_real_T *sintabinv)
{
  emxArray_real_T *costab1q;
  double e;
  int nRowsD4;
  int nd2;
  int k;
  int n2;
  emxInit_real_T(&costab1q, 2);
  e = 6.2831853071795862 / (double)nRows;
  nRowsD4 = nRows / 2 / 2;
  nd2 = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = nRowsD4 + 1;
  emxEnsureCapacity((emxArray__common *)costab1q, nd2, (int)sizeof(double));
  costab1q->data[0] = 1.0;
  nd2 = nRowsD4 / 2;
  for (k = 1; k <= nd2; k++) {
    costab1q->data[k] = cos(e * (double)k);
  }

  for (k = nd2 + 1; k < nRowsD4; k++) {
    costab1q->data[k] = sin(e * (double)(nRowsD4 - k));
  }

  costab1q->data[nRowsD4] = 0.0;
  if (!useRadix2) {
    nRowsD4 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)costab, nd2, (int)sizeof(double));
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)sintab, nd2, (int)sizeof(double));
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)sintabinv, nd2, (int)sizeof(double));
    for (k = 1; k <= nRowsD4; k++) {
      sintabinv->data[k] = costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      sintabinv->data[k] = costab1q->data[k - nRowsD4];
    }

    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nRowsD4];
    }
  } else {
    nRowsD4 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)costab, nd2, (int)sizeof(double));
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)sintab, nd2, (int)sizeof(double));
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nRowsD4];
    }

    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)sintabinv, nd2, (int)sizeof(double));
  }

  emxFree_real_T(&costab1q);
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                int n1_unsigned
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void b_r2br_r2dit_trig(const emxArray_creal_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y)
{
  int j;
  int nRowsD2;
  int nRowsD4;
  int iDelta2;
  int iy;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double r;
  double twid_im;
  int ihi;
  if (x->size[0] <= n1_unsigned) {
    j = x->size[0];
  } else {
    j = n1_unsigned;
  }

  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  iDelta2 = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity((emxArray__common *)y, iDelta2, (int)sizeof(creal_T));
  if (n1_unsigned > x->size[0]) {
    iy = y->size[0];
    iDelta2 = y->size[0];
    y->size[0] = iy;
    emxEnsureCapacity((emxArray__common *)y, iDelta2, (int)sizeof(creal_T));
    for (iDelta2 = 0; iDelta2 < iy; iDelta2++) {
      y->data[iDelta2].re = 0.0;
      y->data[iDelta2].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 1; i < j; i++) {
    y->data[iy] = x->data[ix];
    iDelta2 = n1_unsigned;
    tst = true;
    while (tst) {
      iDelta2 >>= 1;
      ju ^= iDelta2;
      tst = ((ju & iDelta2) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy] = x->data[ix];
  if (n1_unsigned > 1) {
    for (i = 0; i <= n1_unsigned - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iy = 2;
  iDelta2 = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iDelta2) {
      temp_re = y->data[i + iy].re;
      temp_im = y->data[i + iy].im;
      y->data[i + iy].re = y->data[i].re - temp_re;
      y->data[i + iy].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      r = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      ihi = ju + ix;
      while (i < ihi) {
        temp_re = r * y->data[i + iy].re - twid_im * y->data[i + iy].im;
        temp_im = r * y->data[i + iy].im + twid_im * y->data[i + iy].re;
        y->data[i + iy].re = y->data[i].re - temp_re;
        y->data[i + iy].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iDelta2;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iy = iDelta2;
    iDelta2 <<= 1;
    ix -= iy;
  }

  if (y->size[0] > 1) {
    r = 1.0 / (double)y->size[0];
    iDelta2 = y->size[0];
    emxEnsureCapacity((emxArray__common *)y, iDelta2, (int)sizeof(creal_T));
    iy = y->size[0];
    for (iDelta2 = 0; iDelta2 < iy; iDelta2++) {
      y->data[iDelta2].re *= r;
      y->data[iDelta2].im *= r;
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int n
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void eml_fft(const emxArray_real_T *x, int n, emxArray_creal_T *y)
{
  int nInt2m1;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  emxArray_creal_T *wwc;
  emxArray_creal_T *fy;
  emxArray_creal_T *fv;
  boolean_T useRadix2;
  int N2blue;
  int idx;
  int nInt2;
  int ihi;
  int nRowsD2;
  int nRowsD4;
  int rt;
  int j;
  double nt_im;
  double temp_re;
  double temp_im;
  double nt_re;
  double fv_re;
  double fv_im;
  double wwc_im;
  double b_fv_re;
  nInt2m1 = x->size[0];
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  emxInit_real_T(&sintabinv, 2);
  emxInit_creal_T1(&wwc, 1);
  emxInit_creal_T1(&fy, 1);
  emxInit_creal_T1(&fv, 1);
  if ((nInt2m1 == 0) || (n == 0)) {
    nInt2 = y->size[0];
    y->size[0] = n;
    emxEnsureCapacity((emxArray__common *)y, nInt2, (int)sizeof(creal_T));
    nInt2m1 = x->size[0];
    if (n > nInt2m1) {
      ihi = y->size[0];
      nInt2 = y->size[0];
      y->size[0] = ihi;
      emxEnsureCapacity((emxArray__common *)y, nInt2, (int)sizeof(creal_T));
      for (nInt2 = 0; nInt2 < ihi; nInt2++) {
        y->data[nInt2].re = 0.0;
        y->data[nInt2].im = 0.0;
      }
    }
  } else {
    useRadix2 = ((!(n <= 0)) && ((n & (n - 1)) == 0));
    get_algo_sizes(n, useRadix2, &N2blue, &idx);
    b_generate_twiddle_tables(idx, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      nInt2m1 = x->size[0];
      if (nInt2m1 <= n) {
        nInt2m1 = x->size[0];
      } else {
        nInt2m1 = n;
      }

      nRowsD2 = n / 2;
      nRowsD4 = nRowsD2 / 2;
      nInt2 = y->size[0];
      y->size[0] = n;
      emxEnsureCapacity((emxArray__common *)y, nInt2, (int)sizeof(creal_T));
      idx = x->size[0];
      if (n > idx) {
        ihi = y->size[0];
        nInt2 = y->size[0];
        y->size[0] = ihi;
        emxEnsureCapacity((emxArray__common *)y, nInt2, (int)sizeof(creal_T));
        for (nInt2 = 0; nInt2 < ihi; nInt2++) {
          y->data[nInt2].re = 0.0;
          y->data[nInt2].im = 0.0;
        }
      }

      rt = 0;
      nInt2 = 0;
      idx = 0;
      for (N2blue = 1; N2blue < nInt2m1; N2blue++) {
        y->data[idx].re = x->data[rt];
        y->data[idx].im = 0.0;
        idx = n;
        useRadix2 = true;
        while (useRadix2) {
          idx >>= 1;
          nInt2 ^= idx;
          useRadix2 = ((nInt2 & idx) == 0);
        }

        idx = nInt2;
        rt++;
      }

      y->data[idx].re = x->data[rt];
      y->data[idx].im = 0.0;
      if (n > 1) {
        for (N2blue = 0; N2blue <= n - 2; N2blue += 2) {
          temp_re = y->data[N2blue + 1].re;
          temp_im = y->data[N2blue + 1].im;
          y->data[N2blue + 1].re = y->data[N2blue].re - y->data[N2blue + 1].re;
          y->data[N2blue + 1].im = y->data[N2blue].im - y->data[N2blue + 1].im;
          y->data[N2blue].re += temp_re;
          y->data[N2blue].im += temp_im;
        }
      }

      idx = 2;
      rt = 4;
      nInt2 = 1 + ((nRowsD4 - 1) << 2);
      while (nRowsD4 > 0) {
        for (N2blue = 0; N2blue < nInt2; N2blue += rt) {
          temp_re = y->data[N2blue + idx].re;
          temp_im = y->data[N2blue + idx].im;
          y->data[N2blue + idx].re = y->data[N2blue].re - temp_re;
          y->data[N2blue + idx].im = y->data[N2blue].im - temp_im;
          y->data[N2blue].re += temp_re;
          y->data[N2blue].im += temp_im;
        }

        nInt2m1 = 1;
        for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
          nt_re = costab->data[j];
          nt_im = sintab->data[j];
          N2blue = nInt2m1;
          ihi = nInt2m1 + nInt2;
          while (N2blue < ihi) {
            temp_re = nt_re * y->data[N2blue + idx].re - nt_im * y->data[N2blue
              + idx].im;
            temp_im = nt_re * y->data[N2blue + idx].im + nt_im * y->data[N2blue
              + idx].re;
            y->data[N2blue + idx].re = y->data[N2blue].re - temp_re;
            y->data[N2blue + idx].im = y->data[N2blue].im - temp_im;
            y->data[N2blue].re += temp_re;
            y->data[N2blue].im += temp_im;
            N2blue += rt;
          }

          nInt2m1++;
        }

        nRowsD4 /= 2;
        idx = rt;
        rt <<= 1;
        nInt2 -= idx;
      }
    } else {
      nInt2m1 = (n + n) - 1;
      nInt2 = wwc->size[0];
      wwc->size[0] = nInt2m1;
      emxEnsureCapacity((emxArray__common *)wwc, nInt2, (int)sizeof(creal_T));
      idx = n;
      rt = 0;
      wwc->data[n - 1].re = 1.0;
      wwc->data[n - 1].im = 0.0;
      nInt2 = n << 1;
      for (j = 1; j < n; j++) {
        ihi = (j << 1) - 1;
        if (nInt2 - rt <= ihi) {
          rt += ihi - nInt2;
        } else {
          rt += ihi;
        }

        nt_im = -3.1415926535897931 * (double)rt / (double)n;
        wwc->data[idx - 2].re = cos(nt_im);
        wwc->data[idx - 2].im = -sin(nt_im);
        idx--;
      }

      idx = 0;
      for (j = nInt2m1 - 1; j >= n; j--) {
        wwc->data[j] = wwc->data[idx];
        idx++;
      }

      nInt2m1 = x->size[0];
      if (n <= nInt2m1) {
        rt = n;
      } else {
        rt = x->size[0];
      }

      nInt2 = y->size[0];
      y->size[0] = n;
      emxEnsureCapacity((emxArray__common *)y, nInt2, (int)sizeof(creal_T));
      nInt2m1 = x->size[0];
      if (n > nInt2m1) {
        ihi = y->size[0];
        nInt2 = y->size[0];
        y->size[0] = ihi;
        emxEnsureCapacity((emxArray__common *)y, nInt2, (int)sizeof(creal_T));
        for (nInt2 = 0; nInt2 < ihi; nInt2++) {
          y->data[nInt2].re = 0.0;
          y->data[nInt2].im = 0.0;
        }
      }

      idx = 0;
      for (j = 0; j + 1 <= rt; j++) {
        nt_re = wwc->data[(n + j) - 1].re;
        nt_im = wwc->data[(n + j) - 1].im;
        y->data[j].re = nt_re * x->data[idx];
        y->data[j].im = nt_im * -x->data[idx];
        idx++;
      }

      while (rt + 1 <= n) {
        y->data[rt].re = 0.0;
        y->data[rt].im = 0.0;
        rt++;
      }

      r2br_r2dit_trig_impl(y, N2blue, costab, sintab, fy);
      r2br_r2dit_trig(wwc, N2blue, costab, sintab, fv);
      nInt2 = fy->size[0];
      emxEnsureCapacity((emxArray__common *)fy, nInt2, (int)sizeof(creal_T));
      idx = fy->size[0];
      for (nInt2 = 0; nInt2 < idx; nInt2++) {
        nt_re = fy->data[nInt2].re;
        nt_im = fy->data[nInt2].im;
        fv_re = fv->data[nInt2].re;
        fv_im = fv->data[nInt2].im;
        fy->data[nInt2].re = nt_re * fv_re - nt_im * fv_im;
        fy->data[nInt2].im = nt_re * fv_im + nt_im * fv_re;
      }

      b_r2br_r2dit_trig(fy, N2blue, costab, sintabinv, fv);
      idx = 0;
      for (j = n - 1; j + 1 <= wwc->size[0]; j++) {
        nt_re = wwc->data[j].re;
        fv_re = fv->data[j].re;
        nt_im = wwc->data[j].im;
        fv_im = fv->data[j].im;
        temp_re = wwc->data[j].re;
        temp_im = fv->data[j].im;
        wwc_im = wwc->data[j].im;
        b_fv_re = fv->data[j].re;
        y->data[idx].re = nt_re * fv_re + nt_im * fv_im;
        y->data[idx].im = temp_re * temp_im - wwc_im * b_fv_re;
        idx++;
      }
    }
  }

  emxFree_creal_T(&fv);
  emxFree_creal_T(&fy);
  emxFree_creal_T(&wwc);
  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
}

/*
 * Arguments    : int nRows
 *                boolean_T useRadix2
 *                emxArray_real_T *costab
 *                emxArray_real_T *sintab
 *                emxArray_real_T *sintabinv
 * Return Type  : void
 */
static void generate_twiddle_tables(int nRows, boolean_T useRadix2,
  emxArray_real_T *costab, emxArray_real_T *sintab, emxArray_real_T *sintabinv)
{
  emxArray_real_T *costab1q;
  double e;
  int nRowsD4;
  int nd2;
  int k;
  int n2;
  emxInit_real_T(&costab1q, 2);
  e = 6.2831853071795862 / (double)nRows;
  nRowsD4 = nRows / 2 / 2;
  nd2 = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = nRowsD4 + 1;
  emxEnsureCapacity((emxArray__common *)costab1q, nd2, (int)sizeof(double));
  costab1q->data[0] = 1.0;
  nd2 = nRowsD4 / 2;
  for (k = 1; k <= nd2; k++) {
    costab1q->data[k] = cos(e * (double)k);
  }

  for (k = nd2 + 1; k < nRowsD4; k++) {
    costab1q->data[k] = sin(e * (double)(nRowsD4 - k));
  }

  costab1q->data[nRowsD4] = 0.0;
  if (!useRadix2) {
    nRowsD4 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)costab, nd2, (int)sizeof(double));
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)sintab, nd2, (int)sizeof(double));
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)sintabinv, nd2, (int)sizeof(double));
    for (k = 1; k <= nRowsD4; k++) {
      sintabinv->data[k] = costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      sintabinv->data[k] = costab1q->data[k - nRowsD4];
    }

    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nRowsD4];
    }
  } else {
    nRowsD4 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)costab, nd2, (int)sizeof(double));
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = n2 + 1;
    emxEnsureCapacity((emxArray__common *)sintab, nd2, (int)sizeof(double));
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nRowsD4];
    }

    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)sintabinv, nd2, (int)sizeof(double));
  }

  emxFree_real_T(&costab1q);
}

/*
 * Arguments    : int n1
 *                boolean_T useRadix2
 *                int *N2blue
 *                int *nRows
 * Return Type  : void
 */
static void get_algo_sizes(int n1, boolean_T useRadix2, int *N2blue, int *nRows)
{
  int nn1m1;
  int pmax;
  int pmin;
  boolean_T exitg1;
  int p;
  int pow2p;
  *N2blue = 1;
  if (useRadix2) {
    *nRows = n1;
  } else {
    if (n1 > 0) {
      nn1m1 = (n1 + n1) - 1;
      pmax = 31;
      if (nn1m1 <= 1) {
        pmax = 0;
      } else {
        pmin = 0;
        exitg1 = false;
        while ((!exitg1) && (pmax - pmin > 1)) {
          p = (pmin + pmax) >> 1;
          pow2p = 1 << p;
          if (pow2p == nn1m1) {
            pmax = p;
            exitg1 = true;
          } else if (pow2p > nn1m1) {
            pmax = p;
          } else {
            pmin = p;
          }
        }
      }

      *N2blue = 1 << pmax;
    }

    *nRows = *N2blue;
  }
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                int n1_unsigned
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void r2br_r2dit_trig(const emxArray_creal_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y)
{
  int j;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  int ihi;
  if (x->size[0] <= n1_unsigned) {
    j = x->size[0];
  } else {
    j = n1_unsigned;
  }

  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity((emxArray__common *)y, iy, (int)sizeof(creal_T));
  if (n1_unsigned > x->size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity((emxArray__common *)y, iy, (int)sizeof(creal_T));
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 1; i < j; i++) {
    y->data[iy] = x->data[ix];
    iDelta = n1_unsigned;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy] = x->data[ix];
  if (n1_unsigned > 1) {
    for (i = 0; i <= n1_unsigned - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re = y->data[i + iDelta].re;
      temp_im = y->data[i + iDelta].im;
      y->data[i + iDelta].re = y->data[i].re - temp_re;
      y->data[i + iDelta].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      ihi = ju + ix;
      while (i < ihi) {
        temp_re = twid_re * y->data[i + iDelta].re - twid_im * y->data[i +
          iDelta].im;
        temp_im = twid_re * y->data[i + iDelta].im + twid_im * y->data[i +
          iDelta].re;
        y->data[i + iDelta].re = y->data[i].re - temp_re;
        y->data[i + iDelta].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy <<= 1;
    ix -= iDelta;
  }
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                int unsigned_nRows
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void r2br_r2dit_trig_impl(const emxArray_creal_T *x, int unsigned_nRows,
  const emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T
  *y)
{
  int j;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  int ihi;
  if (x->size[0] <= unsigned_nRows) {
    j = x->size[0];
  } else {
    j = unsigned_nRows;
  }

  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity((emxArray__common *)y, iy, (int)sizeof(creal_T));
  iy = x->size[0];
  if (unsigned_nRows > iy) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity((emxArray__common *)y, iy, (int)sizeof(creal_T));
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 1; i < j; i++) {
    y->data[iy] = x->data[ix];
    iDelta = unsigned_nRows;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy] = x->data[ix];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= unsigned_nRows - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re = y->data[i + iDelta].re;
      temp_im = y->data[i + iDelta].im;
      y->data[i + iDelta].re = y->data[i].re - temp_re;
      y->data[i + iDelta].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      ihi = ju + ix;
      while (i < ihi) {
        temp_re = twid_re * y->data[i + iDelta].re - twid_im * y->data[i +
          iDelta].im;
        temp_im = twid_re * y->data[i + iDelta].im + twid_im * y->data[i +
          iDelta].re;
        y->data[i + iDelta].re = y->data[i].re - temp_re;
        y->data[i + iDelta].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy <<= 1;
    ix -= iDelta;
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
  emxArray_creal_T *b_y1;
  int b_x[2];
  emxArray_real_T c_x;
  int i15;
  int loop_ub;
  emxInit_creal_T1(&b_y1, 1);
  b_x[0] = x->size[1];
  b_x[1] = 1;
  c_x = *x;
  c_x.size = (int *)&b_x;
  c_x.numDimensions = 1;
  eml_fft(&c_x, (int)varargin_1, b_y1);
  i15 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)varargin_1;
  emxEnsureCapacity((emxArray__common *)y, i15, (int)sizeof(creal_T));
  loop_ub = (int)varargin_1;
  for (i15 = 0; i15 < loop_ub; i15++) {
    y->data[i15] = b_y1->data[i15];
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
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  emxArray_creal_T *wwc;
  emxArray_creal_T *rwork;
  emxArray_creal_T *fy;
  emxArray_creal_T *fv;
  boolean_T useRadix2;
  int sz[2];
  int ihi;
  int rt;
  int idx;
  unsigned int sx[2];
  int nInt2m1;
  int nInt2;
  int iy;
  int k;
  int nRowsD2;
  double nt_im;
  int nRowsD4;
  double nt_re;
  int i;
  double temp_re;
  double temp_im;
  double wwc_re;
  double fv_im;
  double fv_re;
  double b_fv_im;
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  emxInit_real_T(&sintabinv, 2);
  emxInit_creal_T1(&wwc, 1);
  emxInit_creal_T1(&rwork, 1);
  emxInit_creal_T1(&fy, 1);
  emxInit_creal_T1(&fv, 1);
  if ((x->size[0] == 0) || ((int)varargin_1 == 0)) {
    for (idx = 0; idx < 2; idx++) {
      sz[idx] = x->size[idx];
    }

    idx = y->size[0] * y->size[1];
    y->size[0] = (int)varargin_1;
    y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)y, idx, (int)sizeof(creal_T));
    if ((int)varargin_1 > x->size[0]) {
      idx = y->size[0] * y->size[1];
      emxEnsureCapacity((emxArray__common *)y, idx, (int)sizeof(creal_T));
      nInt2 = y->size[1];
      for (idx = 0; idx < nInt2; idx++) {
        rt = y->size[0];
        for (iy = 0; iy < rt; iy++) {
          y->data[iy + y->size[0] * idx].re = 0.0;
          y->data[iy + y->size[0] * idx].im = 0.0;
        }
      }
    }
  } else {
    useRadix2 = ((!((int)varargin_1 <= 0)) && (((int)varargin_1 & ((int)
      varargin_1 - 1)) == 0));
    get_algo_sizes((int)varargin_1, useRadix2, &ihi, &rt);
    generate_twiddle_tables(rt, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      for (idx = 0; idx < 2; idx++) {
        sx[idx] = (unsigned int)x->size[idx];
      }

      for (idx = 0; idx < 2; idx++) {
        sz[idx] = x->size[idx];
      }

      idx = y->size[0] * y->size[1];
      y->size[0] = (int)varargin_1;
      y->size[1] = sz[1];
      emxEnsureCapacity((emxArray__common *)y, idx, (int)sizeof(creal_T));
      if ((int)varargin_1 > x->size[0]) {
        idx = y->size[0] * y->size[1];
        emxEnsureCapacity((emxArray__common *)y, idx, (int)sizeof(creal_T));
        nInt2 = y->size[1];
        for (idx = 0; idx < nInt2; idx++) {
          rt = y->size[0];
          for (iy = 0; iy < rt; iy++) {
            y->data[iy + y->size[0] * idx].re = 0.0;
            y->data[iy + y->size[0] * idx].im = 0.0;
          }
        }
      }

      for (k = 0; k + 1 <= (int)sx[1]; k++) {
        if (x->size[0] <= (int)varargin_1) {
          ihi = x->size[0];
        } else {
          ihi = (int)varargin_1;
        }

        nRowsD2 = (int)varargin_1 / 2;
        nRowsD4 = nRowsD2 / 2;
        idx = rwork->size[0];
        rwork->size[0] = (int)varargin_1;
        emxEnsureCapacity((emxArray__common *)rwork, idx, (int)sizeof(creal_T));
        iy = x->size[0];
        if ((int)varargin_1 > iy) {
          iy = rwork->size[0];
          idx = rwork->size[0];
          rwork->size[0] = iy;
          emxEnsureCapacity((emxArray__common *)rwork, idx, (int)sizeof(creal_T));
          for (idx = 0; idx < iy; idx++) {
            rwork->data[idx].re = 0.0;
            rwork->data[idx].im = 0.0;
          }
        }

        nInt2 = k * x->size[0];
        nInt2m1 = 0;
        iy = 0;
        for (i = 1; i < ihi; i++) {
          rwork->data[iy] = x->data[nInt2];
          rt = (int)varargin_1;
          useRadix2 = true;
          while (useRadix2) {
            rt >>= 1;
            nInt2m1 ^= rt;
            useRadix2 = ((nInt2m1 & rt) == 0);
          }

          iy = nInt2m1;
          nInt2++;
        }

        rwork->data[iy] = x->data[nInt2];
        if ((int)varargin_1 > 1) {
          for (i = 0; i <= (int)varargin_1 - 2; i += 2) {
            temp_re = rwork->data[i + 1].re;
            temp_im = rwork->data[i + 1].im;
            rwork->data[i + 1].re = rwork->data[i].re - rwork->data[i + 1].re;
            rwork->data[i + 1].im = rwork->data[i].im - rwork->data[i + 1].im;
            rwork->data[i].re += temp_re;
            rwork->data[i].im += temp_im;
          }
        }

        rt = 2;
        nInt2 = 4;
        nInt2m1 = 1 + ((nRowsD4 - 1) << 2);
        while (nRowsD4 > 0) {
          for (i = 0; i < nInt2m1; i += nInt2) {
            temp_re = rwork->data[i + rt].re;
            temp_im = rwork->data[i + rt].im;
            rwork->data[i + rt].re = rwork->data[i].re - temp_re;
            rwork->data[i + rt].im = rwork->data[i].im - temp_im;
            rwork->data[i].re += temp_re;
            rwork->data[i].im += temp_im;
          }

          idx = 1;
          for (iy = nRowsD4; iy < nRowsD2; iy += nRowsD4) {
            nt_re = costab->data[iy];
            nt_im = sintab->data[iy];
            i = idx;
            ihi = idx + nInt2m1;
            while (i < ihi) {
              temp_re = nt_re * rwork->data[i + rt].re - nt_im * rwork->data[i +
                rt].im;
              temp_im = nt_re * rwork->data[i + rt].im + nt_im * rwork->data[i +
                rt].re;
              rwork->data[i + rt].re = rwork->data[i].re - temp_re;
              rwork->data[i + rt].im = rwork->data[i].im - temp_im;
              rwork->data[i].re += temp_re;
              rwork->data[i].im += temp_im;
              i += nInt2;
            }

            idx++;
          }

          nRowsD4 /= 2;
          rt = nInt2;
          nInt2 <<= 1;
          nInt2m1 -= rt;
        }

        for (rt = 0; rt + 1 <= (int)varargin_1; rt++) {
          y->data[rt + y->size[0] * k] = rwork->data[rt];
        }
      }
    } else {
      for (idx = 0; idx < 2; idx++) {
        sx[idx] = (unsigned int)x->size[idx];
      }

      nInt2m1 = ((int)varargin_1 + (int)varargin_1) - 1;
      idx = wwc->size[0];
      wwc->size[0] = nInt2m1;
      emxEnsureCapacity((emxArray__common *)wwc, idx, (int)sizeof(creal_T));
      idx = (int)varargin_1;
      rt = 0;
      wwc->data[(int)varargin_1 - 1].re = 1.0;
      wwc->data[(int)varargin_1 - 1].im = 0.0;
      nInt2 = (int)varargin_1 << 1;
      for (k = 1; k < (int)varargin_1; k++) {
        iy = (k << 1) - 1;
        if (nInt2 - rt <= iy) {
          rt += iy - nInt2;
        } else {
          rt += iy;
        }

        nt_im = -3.1415926535897931 * (double)rt / (double)(int)varargin_1;
        nt_re = cos(nt_im);
        nt_im = sin(nt_im);
        wwc->data[idx - 2].re = nt_re;
        wwc->data[idx - 2].im = -nt_im;
        idx--;
      }

      idx = 0;
      for (k = nInt2m1 - 1; k >= (int)varargin_1; k--) {
        wwc->data[k] = wwc->data[idx];
        idx++;
      }

      for (idx = 0; idx < 2; idx++) {
        sz[idx] = x->size[idx];
      }

      idx = y->size[0] * y->size[1];
      y->size[0] = (int)varargin_1;
      y->size[1] = sz[1];
      emxEnsureCapacity((emxArray__common *)y, idx, (int)sizeof(creal_T));
      if ((int)varargin_1 > x->size[0]) {
        idx = y->size[0] * y->size[1];
        emxEnsureCapacity((emxArray__common *)y, idx, (int)sizeof(creal_T));
        nInt2 = y->size[1];
        for (idx = 0; idx < nInt2; idx++) {
          rt = y->size[0];
          for (iy = 0; iy < rt; iy++) {
            y->data[iy + y->size[0] * idx].re = 0.0;
            y->data[iy + y->size[0] * idx].im = 0.0;
          }
        }
      }

      for (k = 0; k + 1 <= (int)sx[1]; k++) {
        if ((int)varargin_1 <= x->size[0]) {
          nInt2 = (int)varargin_1;
        } else {
          nInt2 = x->size[0];
        }

        idx = rwork->size[0];
        rwork->size[0] = (int)varargin_1;
        emxEnsureCapacity((emxArray__common *)rwork, idx, (int)sizeof(creal_T));
        iy = x->size[0];
        if ((int)varargin_1 > iy) {
          iy = rwork->size[0];
          idx = rwork->size[0];
          rwork->size[0] = iy;
          emxEnsureCapacity((emxArray__common *)rwork, idx, (int)sizeof(creal_T));
          for (idx = 0; idx < iy; idx++) {
            rwork->data[idx].re = 0.0;
            rwork->data[idx].im = 0.0;
          }
        }

        rt = k * x->size[0];
        for (iy = 0; iy + 1 <= nInt2; iy++) {
          nt_re = wwc->data[((int)varargin_1 + iy) - 1].re;
          nt_im = wwc->data[((int)varargin_1 + iy) - 1].im;
          temp_re = x->data[rt].re;
          temp_im = x->data[rt].im;
          wwc_re = x->data[rt].im;
          fv_im = x->data[rt].re;
          rwork->data[iy].re = nt_re * temp_re + nt_im * temp_im;
          rwork->data[iy].im = nt_re * wwc_re - nt_im * fv_im;
          rt++;
        }

        while (nInt2 + 1 <= (int)varargin_1) {
          rwork->data[nInt2].re = 0.0;
          rwork->data[nInt2].im = 0.0;
          nInt2++;
        }

        r2br_r2dit_trig_impl(rwork, ihi, costab, sintab, fy);
        r2br_r2dit_trig(wwc, ihi, costab, sintab, fv);
        idx = fy->size[0];
        emxEnsureCapacity((emxArray__common *)fy, idx, (int)sizeof(creal_T));
        nInt2 = fy->size[0];
        for (idx = 0; idx < nInt2; idx++) {
          temp_re = fy->data[idx].re;
          temp_im = fy->data[idx].im;
          fv_re = fv->data[idx].re;
          b_fv_im = fv->data[idx].im;
          fy->data[idx].re = temp_re * fv_re - temp_im * b_fv_im;
          fy->data[idx].im = temp_re * b_fv_im + temp_im * fv_re;
        }

        b_r2br_r2dit_trig(fy, ihi, costab, sintabinv, fv);
        idx = 0;
        for (iy = (int)varargin_1 - 1; iy + 1 <= wwc->size[0]; iy++) {
          temp_re = wwc->data[iy].re;
          fv_re = fv->data[iy].re;
          temp_im = wwc->data[iy].im;
          b_fv_im = fv->data[iy].im;
          wwc_re = wwc->data[iy].re;
          fv_im = fv->data[iy].im;
          nt_re = wwc->data[iy].im;
          nt_im = fv->data[iy].re;
          rwork->data[idx].re = temp_re * fv_re + temp_im * b_fv_im;
          rwork->data[idx].im = wwc_re * fv_im - nt_re * nt_im;
          idx++;
        }

        for (rt = 0; rt + 1 <= (int)varargin_1; rt++) {
          y->data[rt + y->size[0] * k] = rwork->data[rt];
        }
      }
    }
  }

  emxFree_creal_T(&fv);
  emxFree_creal_T(&fy);
  emxFree_creal_T(&rwork);
  emxFree_creal_T(&wwc);
  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
