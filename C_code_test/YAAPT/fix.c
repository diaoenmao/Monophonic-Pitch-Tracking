/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fix.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 14-Nov-2015 18:37:50
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "fix.h"

/* Function Definitions */

/*
 * Arguments    : double *x
 * Return Type  : void
 */
void b_fix(double *x)
{
  if (*x < 0.0) {
    *x = ceil(*x);
  } else {
    *x = floor(*x);
  }
}

/*
 * File trailer for fix.c
 *
 * [EOF]
 */
