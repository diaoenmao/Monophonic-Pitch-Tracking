/*
 * File: mean.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 26-Oct-2015 23:41:06
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
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_mean(const emxArray_real_T *x, emxArray_real_T *y)
{
  unsigned int sz[2];
  int ix;
  int iy;
  int i;
  int ixstart;
  emxArray_real_T *b_y;
  for (ix = 0; ix < 2; ix++) {
    sz[ix] = (unsigned int)x->size[ix];
  }

  ix = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)sz[1];
  emxEnsureCapacity((emxArray__common *)y, ix, (int)sizeof(double));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    ix = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, ix, (int)sizeof(double));
    ix = y->size[0] * y->size[1];
    y->size[1] = (int)sz[1];
    emxEnsureCapacity((emxArray__common *)y, ix, (int)sizeof(double));
    iy = (int)sz[1];
    for (ix = 0; ix < iy; ix++) {
      y->data[ix] = 0.0;
    }
  } else {
    ix = 0;
    iy = -1;
    for (i = 1; i <= x->size[1]; i++) {
      ixstart = ix;
      ix++;
      iy++;
      y->data[iy] = x->data[ixstart];
    }
  }

  emxInit_real_T(&b_y, 2);
  ix = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)b_y, ix, (int)sizeof(double));
  iy = y->size[0] * y->size[1];
  for (ix = 0; ix < iy; ix++) {
    b_y->data[ix] = y->data[ix];
  }

  c_rdivide(b_y, x->size[0], y);
  emxFree_real_T(&b_y);
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
