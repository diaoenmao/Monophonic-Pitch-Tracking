/*
 * File: std.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 26-Oct-2015 23:41:06
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "std.h"
#include "yaapt_emxutil.h"

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
 *                emxArray_real_T *y
 * Return Type  : void
 */
void c_std(const emxArray_real_T *varargin_1, emxArray_real_T *y)
{
  unsigned int sz[2];
  int ix;
  emxArray_real_T *b_y;
  int iy;
  int i;
  double r;
  for (ix = 0; ix < 2; ix++) {
    sz[ix] = (unsigned int)varargin_1->size[ix];
  }

  emxInit_real_T(&b_y, 2);
  ix = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = (int)sz[1];
  emxEnsureCapacity((emxArray__common *)b_y, ix, (int)sizeof(double));
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    ix = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)b_y, ix, (int)sizeof(double));
    ix = b_y->size[0] * b_y->size[1];
    b_y->size[1] = (int)sz[1];
    emxEnsureCapacity((emxArray__common *)b_y, ix, (int)sizeof(double));
    iy = (int)sz[1];
    for (ix = 0; ix < iy; ix++) {
      b_y->data[ix] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (i = 1; i <= varargin_1->size[1]; i++) {
      ix++;
      iy++;
      r = varargin_1->data[ix] - varargin_1->data[ix];
      b_y->data[iy] = r * r;
    }
  }

  ix = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_y->size[1];
  emxEnsureCapacity((emxArray__common *)y, ix, (int)sizeof(double));
  iy = b_y->size[0] * b_y->size[1];
  for (ix = 0; ix < iy; ix++) {
    y->data[ix] = b_y->data[ix];
  }

  for (ix = 0; ix < b_y->size[1]; ix++) {
    y->data[ix] = sqrt(y->data[ix]);
  }

  emxFree_real_T(&b_y);
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
