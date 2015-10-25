/*
 * File: fix.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 25-Oct-2015 03:48:36
 */

/* Include files */
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
