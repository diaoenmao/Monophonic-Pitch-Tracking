/*
 * File: xgetrf.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 11-Dec-2015 06:07:48
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xgetrf.h"
#include "xswap.h"

/* Function Definitions */

/*
 * Arguments    : double A[5776]
 *                int ipiv[76]
 *                int *info
 * Return Type  : void
 */
void xgetrf(double A[5776], int ipiv[76], int *info)
{
  int i23;
  int j;
  int c;
  int jA;
  int ix;
  double smax;
  int jy;
  double s;
  int b_j;
  int ijA;
  for (i23 = 0; i23 < 76; i23++) {
    ipiv[i23] = 1 + i23;
  }

  *info = 0;
  for (j = 0; j < 75; j++) {
    c = j * 77;
    jA = 1;
    ix = c;
    smax = fabs(A[c]);
    for (jy = 2; jy <= 76 - j; jy++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        jA = jy;
        smax = s;
      }
    }

    if (A[(c + jA) - 1] != 0.0) {
      if (jA - 1 != 0) {
        ipiv[j] = j + jA;
        xswap(A, j + 1, j + jA);
      }

      i23 = (c - j) + 76;
      for (jA = c + 1; jA + 1 <= i23; jA++) {
        A[jA] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    jA = c;
    jy = c + 76;
    for (b_j = 1; b_j <= 75 - j; b_j++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = c + 1;
        i23 = (jA - j) + 152;
        for (ijA = 77 + jA; ijA + 1 <= i23; ijA++) {
          A[ijA] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 76;
      jA += 76;
    }
  }

  if ((*info == 0) && (!(A[5775] != 0.0))) {
    *info = 76;
  }
}

/*
 * File trailer for xgetrf.c
 *
 * [EOF]
 */
