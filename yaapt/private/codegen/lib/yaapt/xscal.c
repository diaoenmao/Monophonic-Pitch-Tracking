/*
 * File: xscal.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xscal.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                double a
 *                emxArray_real_T *x
 *                int ix0
 * Return Type  : void
 */
void xscal(int n, double a, emxArray_real_T *x, int ix0)
{
  int i32;
  int k;
  i32 = (ix0 + n) - 1;
  for (k = ix0; k <= i32; k++) {
    x->data[k - 1] *= a;
  }
}

/*
 * File trailer for xscal.c
 *
 * [EOF]
 */
