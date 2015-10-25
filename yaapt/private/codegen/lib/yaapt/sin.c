/*
 * File: sin.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 25-Oct-2015 03:48:36
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sin.h"

/* Function Definitions */

/*
 * Arguments    : double x[5776]
 * Return Type  : void
 */
void b_sin(double x[5776])
{
  int k;
  for (k = 0; k < 5776; k++) {
    x[k] = sin(x[k]);
  }
}

/*
 * File trailer for sin.c
 *
 * [EOF]
 */
