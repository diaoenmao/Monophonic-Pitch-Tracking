/*
 * File: mean.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

/* Include files */
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
  unsigned int sz[2];
  int ix;
  int k;
  double s;
  emxArray_real_T *r4;
  emxArray_real_T b_y_data;
  for (ix = 0; ix < 2; ix++) {
    sz[ix] = (unsigned int)x->size[ix];
  }

  y_size[0] = (int)sz[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    y_size[0] = (int)sz[0];
    k = (int)sz[0];
    for (ix = 0; ix < k; ix++) {
      y_data[ix] = 0.0;
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

  b_emxInit_real_T(&r4, 1);
  b_y_data.data = (double *)y_data;
  b_y_data.size = (int *)y_size;
  b_y_data.allocatedSize = -1;
  b_y_data.numDimensions = 1;
  b_y_data.canFreeData = false;
  c_rdivide(&b_y_data, x->size[1], r4);
  y_size[0] = r4->size[0];
  k = r4->size[0];
  for (ix = 0; ix < k; ix++) {
    y_data[ix] = r4->data[ix];
  }

  emxFree_real_T(&r4);
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
