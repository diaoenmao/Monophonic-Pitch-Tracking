/*
 * File: Add.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 14-Nov-2015 01:36:16
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Add.h"

/* Function Definitions */

/*
 * Arguments    : const double arr[5]
 *                double b
 *                double out[5]
 * Return Type  : void
 */
void Add(const double arr[5], double b, double out[5])
{
  int i;
  for (i = 0; i < 5; i++) {
    out[i] = arr[i] + b;
  }
}

/*
 * File trailer for Add.c
 *
 * [EOF]
 */
