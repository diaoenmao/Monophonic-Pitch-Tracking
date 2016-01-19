/*
 * File: mldivide.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Jan-2016 00:47:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mldivide.h"
#include "xtrsm.h"
#include "xgetrf.h"

/* Function Definitions */

/*
 * Arguments    : const double A[5776]
 *                double B[76]
 * Return Type  : void
 */
void mldivide(const double A[5776], double B[76])
{
  double b_A[5776];
  int info;
  int ipiv[76];
  double temp;
  memcpy(&b_A[0], &A[0], 5776U * sizeof(double));
  xgetrf(b_A, ipiv, &info);
  for (info = 0; info < 75; info++) {
    if (ipiv[info] != info + 1) {
      temp = B[info];
      B[info] = B[ipiv[info] - 1];
      B[ipiv[info] - 1] = temp;
    }
  }

  xtrsm(b_A, B);
  b_xtrsm(b_A, B);
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
