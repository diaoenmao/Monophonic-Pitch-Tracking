/*
 * File: std.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "std.h"
#include "yaapt_emxutil.h"
#include "sqrt.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *varargin_1
 * Return Type  : double
 */
double b_std(const emxArray_real_T *varargin_1)
{
  double y;
  int i18;
  int d;
  int ix;
  double xbar;
  int k;
  double r;
  i18 = varargin_1->size[1];
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  if (varargin_1->size[1] == 0) {
    y = 0.0;
  } else {
    ix = 0;
    xbar = varargin_1->data[0];
    for (k = 2; k <= i18; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (double)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    for (k = 2; k <= i18; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      y += r * r;
    }

    y /= (double)d;
  }

  return sqrt(y);
}

/*
 * Arguments    : const emxArray_real_T *varargin_1
 *                double y_data[]
 *                int y_size[1]
 * Return Type  : void
 */
void c_std(const emxArray_real_T *varargin_1, double y_data[], int y_size[1])
{
  int n;
  int d;
  int ix;
  double xbar;
  int k;
  emxArray_real_T *r25;
  double r;
  double y;
  n = varargin_1->size[1];
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  y_size[0] = varargin_1->size[0];
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    n = y_size[0];
    for (d = 0; d < n; d++) {
      y_data[d] = 0.0;
    }
  } else {
    ix = 0;
    xbar = varargin_1->data[0];
    for (k = 2; k <= n; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (double)n;
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    for (k = 2; k <= n; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      y += r * r;
    }

    y /= (double)d;
    y_data[0] = y;
  }

  emxInit_real_T2(&r25, 1);
  d = r25->size[0];
  r25->size[0] = y_size[0];
  emxEnsureCapacity((emxArray__common *)r25, d, (int)sizeof(double));
  n = y_size[0];
  for (d = 0; d < n; d++) {
    r25->data[d] = y_data[d];
  }

  b_sqrt(r25);
  y_size[0] = r25->size[0];
  n = r25->size[0];
  for (d = 0; d < n; d++) {
    y_data[d] = r25->data[d];
  }

  emxFree_real_T(&r25);
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
