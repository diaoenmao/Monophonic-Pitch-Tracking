/*
 * File: exp.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
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
  int i22;
  int k;
  i22 = x->size[0];
  for (k = 0; k < i22; k++) {
    x->data[k] = exp(x->data[k]);
  }
}

/*
 * File trailer for exp.c
 *
 * [EOF]
 */
