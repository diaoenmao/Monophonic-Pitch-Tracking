/*
 * File: cos.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cos.h"

/* Function Definitions */

/*
 * Arguments    : double x[75]
 * Return Type  : void
 */
void b_cos(double x[75])
{
  int k;
  for (k = 0; k < 75; k++) {
    x[k] = cos(x[k]);
  }
}

/*
 * File trailer for cos.c
 *
 * [EOF]
 */
