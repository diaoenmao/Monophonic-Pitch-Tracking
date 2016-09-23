/*
 * File: mrdivide.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mrdivide.h"

/* Function Definitions */

/*
 * Arguments    : double A_data[]
 *                int A_size[2]
 *                const double B_data[]
 *                const int B_size[2]
 * Return Type  : void
 */
void mrdivide(double A_data[], int A_size[2], const double B_data[], const int
              B_size[2])
{
  if ((A_size[1] == 0) || (B_size[1] == 0)) {
    A_size[0] = 1;
    A_size[1] = 1;
    A_data[0] = 0.0;
  } else if (A_size[1] == 0) {
  } else {
    A_data[0] *= 1.0 / B_data[0];
  }
}

/*
 * File trailer for mrdivide.c
 *
 * [EOF]
 */
