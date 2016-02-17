/*
 * File: sum.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_boolean_T *x
 * Return Type  : double
 */
double b_sum(const emxArray_boolean_T *x)
{
  double y;
  int k;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[1]; k++) {
      y += (double)x->data[k - 1];
    }
  }

  return y;
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double sum(const emxArray_real_T *x)
{
  double y;
  int k;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[1]; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
