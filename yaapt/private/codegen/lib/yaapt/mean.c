/*
 * File: mean.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mean.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                double y_data[]
 *                int y_size[1]
 * Return Type  : void
 */
void b_mean(const emxArray_real_T *x, double y_data[], int y_size[1])
{
  double s;
  int k;
  int i25;
  int loop_ub;
  y_size[0] = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    k = y_size[0];
    for (i25 = 0; i25 < k; i25++) {
      y_data[i25] = 0.0;
    }
  } else {
    s = x->data[0];
    for (k = 2; k <= x->size[1]; k++) {
      s += x->data[k - 1];
    }

    y_data[0] = s;
  }

  k = x->size[1];
  loop_ub = y_size[0];
  for (i25 = 0; i25 < loop_ub; i25++) {
    y_data[i25] /= (double)k;
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double mean(const emxArray_real_T *x)
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

  y /= (double)x->size[1];
  return y;
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
