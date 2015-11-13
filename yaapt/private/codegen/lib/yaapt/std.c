/*
 * File: std.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
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
  int d;
  int ix;
  double xbar;
  int k;
  double r;
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
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (double)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
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
  int d;
  unsigned int sz[2];
  int k;
  int ix;
  double xbar;
  double r;
  double y;
  emxArray_real_T *r5;
  if (varargin_1->size[1] > 1) {
    d = varargin_1->size[1] - 1;
  } else {
    d = varargin_1->size[1];
  }

  for (k = 0; k < 2; k++) {
    sz[k] = (unsigned int)varargin_1->size[k];
  }

  y_size[0] = (int)sz[0];
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    y_size[0] = (int)sz[0];
    ix = (int)sz[0];
    for (k = 0; k < ix; k++) {
      y_data[k] = 0.0;
    }
  } else {
    ix = 0;
    xbar = varargin_1->data[0];
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      xbar += varargin_1->data[ix];
    }

    xbar /= (double)varargin_1->size[1];
    ix = 0;
    r = varargin_1->data[0] - xbar;
    y = r * r;
    for (k = 0; k <= varargin_1->size[1] - 2; k++) {
      ix++;
      r = varargin_1->data[ix] - xbar;
      y += r * r;
    }

    y /= (double)d;
    y_data[0] = y;
  }

  b_emxInit_real_T(&r5, 1);
  k = r5->size[0];
  r5->size[0] = y_size[0];
  emxEnsureCapacity((emxArray__common *)r5, k, (int)sizeof(double));
  ix = y_size[0];
  for (k = 0; k < ix; k++) {
    r5->data[k] = y_data[k];
  }

  b_sqrt(r5);
  y_size[0] = r5->size[0];
  ix = r5->size[0];
  for (k = 0; k < ix; k++) {
    y_data[k] = r5->data[k];
  }

  emxFree_real_T(&r5);
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
