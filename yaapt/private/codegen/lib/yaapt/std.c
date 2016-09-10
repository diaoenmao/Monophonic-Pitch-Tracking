/*
 * File: std.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
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
  int i20;
  int d;
  int ix;
  double xbar;
  int k;
  double r;
  i20 = varargin_1->size[1];
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
    for (k = 2; k <= i20; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (double)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    for (k = 2; k <= i20; k++) {
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
  emxArray_real_T *r26;
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

  emxInit_real_T1(&r26, 1);
  d = r26->size[0];
  r26->size[0] = y_size[0];
  emxEnsureCapacity((emxArray__common *)r26, d, (int)sizeof(double));
  n = y_size[0];
  for (d = 0; d < n; d++) {
    r26->data[d] = y_data[d];
  }

  b_sqrt(r26);
  y_size[0] = r26->size[0];
  n = r26->size[0];
  for (d = 0; d < n; d++) {
    y_data[d] = r26->data[d];
  }

  emxFree_real_T(&r26);
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
