/*
 * File: mldivide.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mldivide.h"

/* Function Declarations */
static void b_eml_xtrsm(const double A[5776], double B[76]);
static void eml_xswap(double x[5776], int ix0, int iy0);
static void eml_xtrsm(const double A[5776], double B[76]);

/* Function Definitions */

/*
 * Arguments    : const double A[5776]
 *                double B[76]
 * Return Type  : void
 */
static void b_eml_xtrsm(const double A[5776], double B[76])
{
  int k;
  int kAcol;
  int i;
  for (k = 75; k > -1; k += -1) {
    kAcol = 76 * k;
    if (B[k] != 0.0) {
      B[k] /= A[k + kAcol];
      for (i = 0; i + 1 <= k; i++) {
        B[i] -= B[k] * A[i + kAcol];
      }
    }
  }
}

/*
 * Arguments    : double x[5776]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
static void eml_xswap(double x[5776], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 76; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix += 76;
    iy += 76;
  }
}

/*
 * Arguments    : const double A[5776]
 *                double B[76]
 * Return Type  : void
 */
static void eml_xtrsm(const double A[5776], double B[76])
{
  int k;
  int kAcol;
  int i;
  for (k = 0; k < 76; k++) {
    kAcol = 76 * k;
    if (B[k] != 0.0) {
      for (i = k + 1; i + 1 < 77; i++) {
        B[i] -= B[k] * A[i + kAcol];
      }
    }
  }
}

/*
 * Arguments    : const double A[5776]
 *                double B[76]
 * Return Type  : void
 */
void mldivide(const double A[5776], double B[76])
{
  double b_A[5776];
  unsigned char ipiv[76];
  int i20;
  int j;
  int c;
  int jA;
  int ix;
  double temp;
  int jy;
  double s;
  int b_j;
  int ijA;
  memcpy(&b_A[0], &A[0], 5776U * sizeof(double));
  for (i20 = 0; i20 < 76; i20++) {
    ipiv[i20] = (unsigned char)(1 + i20);
  }

  for (j = 0; j < 75; j++) {
    c = j * 77;
    jA = 1;
    ix = c;
    temp = fabs(b_A[c]);
    for (jy = 2; jy <= 76 - j; jy++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > temp) {
        jA = jy;
        temp = s;
      }
    }

    if (b_A[(c + jA) - 1] != 0.0) {
      if (jA - 1 != 0) {
        ipiv[j] = (unsigned char)(j + jA);
        eml_xswap(b_A, j + 1, j + jA);
      }

      i20 = (c - j) + 76;
      for (jA = c + 1; jA + 1 <= i20; jA++) {
        b_A[jA] /= b_A[c];
      }
    }

    jA = c;
    jy = c + 76;
    for (b_j = 1; b_j <= 75 - j; b_j++) {
      temp = b_A[jy];
      if (b_A[jy] != 0.0) {
        ix = c + 1;
        i20 = (jA - j) + 152;
        for (ijA = 77 + jA; ijA + 1 <= i20; ijA++) {
          b_A[ijA] += b_A[ix] * -temp;
          ix++;
        }
      }

      jy += 76;
      jA += 76;
    }
  }

  for (jA = 0; jA < 75; jA++) {
    if (ipiv[jA] != jA + 1) {
      temp = B[jA];
      B[jA] = B[ipiv[jA] - 1];
      B[ipiv[jA] - 1] = temp;
    }
  }

  eml_xtrsm(b_A, B);
  b_eml_xtrsm(b_A, B);
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
