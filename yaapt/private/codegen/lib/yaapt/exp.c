/*
 * File: exp.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 12-Jan-2016 01:25:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "exp.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void b_exp(emxArray_real_T *x)
{
  int nx;
  int k;
  nx = x->size[0];
  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = exp(x->data[k]);
  }
}

/*
 * File trailer for exp.c
 *
 * [EOF]
 */
