/*
 * File: mean.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Jan-2016 00:47:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mean.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                double y_data[]
 *                int y_size[1]
 * Return Type  : void
 */
void b_mean(const emxArray_real_T *x, double y_data[], int y_size[1])
{
  int ix;
  int k;
  double s;
  emxArray_real_T *r6;
  emxArray_real_T b_y_data;
  y_size[0] = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    ix = y_size[0];
    y_size[0] = ix;
    for (k = 0; k < ix; k++) {
      y_data[k] = 0.0;
    }
  } else {
    ix = 0;
    s = x->data[0];
    for (k = 2; k <= x->size[1]; k++) {
      ix++;
      s += x->data[ix];
    }

    y_data[0] = s;
  }

  emxInit_real_T1(&r6, 1);
  b_y_data.data = (double *)y_data;
  b_y_data.size = (int *)y_size;
  b_y_data.allocatedSize = -1;
  b_y_data.numDimensions = 1;
  b_y_data.canFreeData = false;
  c_rdivide(&b_y_data, x->size[1], r6);
  y_size[0] = r6->size[0];
  ix = r6->size[0];
  for (k = 0; k < ix; k++) {
    y_data[k] = r6->data[k];
  }

  emxFree_real_T(&r6);
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
