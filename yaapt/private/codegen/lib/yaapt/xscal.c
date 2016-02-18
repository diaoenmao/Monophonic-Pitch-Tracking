/*
 * File: xscal.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
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
  int i30;
  int k;
  i30 = (ix0 + n) - 1;
  for (k = ix0; k <= i30; k++) {
    x->data[k - 1] *= a;
  }
}

/*
 * File trailer for xscal.c
 *
 * [EOF]
 */
