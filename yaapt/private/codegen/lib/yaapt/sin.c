/*
 * File: sin.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Jan-2016 00:47:12
 */

/* Include Files */
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
