/*
 * File: xtrsm.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 19:51:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xtrsm.h"

/* Function Definitions */

/*
 * Arguments    : const double A[5776]
 *                double B[76]
 * Return Type  : void
 */
void b_xtrsm(const double A[5776], double B[76])
{
  int k;
  int kAcol;
  int i;
  for (k = 75; k >= 0; k += -1) {
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
 * Arguments    : const double A[5776]
 *                double B[76]
 * Return Type  : void
 */
void xtrsm(const double A[5776], double B[76])
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
 * File trailer for xtrsm.c
 *
 * [EOF]
 */
