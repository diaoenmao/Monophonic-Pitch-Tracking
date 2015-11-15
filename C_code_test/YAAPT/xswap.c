/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xswap.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 14-Nov-2015 18:37:50
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xswap.h"

/* Function Definitions */

/*
 * Arguments    : double x[5776]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[5776], int ix0, int iy0)
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
 * File trailer for xswap.c
 *
 * [EOF]
 */
