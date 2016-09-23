/*
 * File: sinc.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sinc.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_sinc(emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_boolean_T *b_x;
  int b_y;
  int ii;
  emxArray_int32_T *b_ii;
  int nx;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *i;
  emxInit_boolean_T(&b_x, 2);
  b_y = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b_x, b_y, (int)sizeof(boolean_T));
  ii = x->size[0] * x->size[1];
  for (b_y = 0; b_y < ii; b_y++) {
    b_x->data[b_y] = (x->data[b_y] == 0.0);
  }

  emxInit_int32_T1(&b_ii, 1);
  nx = b_x->size[0] * b_x->size[1];
  idx = 0;
  b_y = b_ii->size[0];
  b_ii->size[0] = nx;
  emxEnsureCapacity((emxArray__common *)b_ii, b_y, (int)sizeof(int));
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx)) {
    guard1 = false;
    if (b_x->data[ii - 1]) {
      idx++;
      b_ii->data[idx - 1] = ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  emxFree_boolean_T(&b_x);
  if (nx == 1) {
    if (idx == 0) {
      b_y = b_ii->size[0];
      b_ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)b_ii, b_y, (int)sizeof(int));
    }
  } else {
    b_y = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)b_ii, b_y, (int)sizeof(int));
  }

  emxInit_real_T2(&i, 1);
  b_y = i->size[0];
  i->size[0] = b_ii->size[0];
  emxEnsureCapacity((emxArray__common *)i, b_y, (int)sizeof(double));
  ii = b_ii->size[0];
  for (b_y = 0; b_y < ii; b_y++) {
    i->data[b_y] = b_ii->data[b_y];
  }

  b_y = b_ii->size[0];
  b_ii->size[0] = i->size[0];
  emxEnsureCapacity((emxArray__common *)b_ii, b_y, (int)sizeof(int));
  ii = i->size[0];
  for (b_y = 0; b_y < ii; b_y++) {
    b_ii->data[b_y] = (int)i->data[b_y];
  }

  ii = b_ii->size[0];
  for (b_y = 0; b_y < ii; b_y++) {
    x->data[b_ii->data[b_y] - 1] = 1.0;
  }

  b_y = y->size[0] * y->size[1];
  y->size[0] = x->size[0];
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, b_y, (int)sizeof(double));
  ii = x->size[0] * x->size[1];
  for (b_y = 0; b_y < ii; b_y++) {
    y->data[b_y] = 3.1415926535897931 * x->data[b_y];
  }

  nx = y->size[0] * y->size[1];
  for (ii = 0; ii + 1 <= nx; ii++) {
    y->data[ii] = sin(y->data[ii]);
  }

  b_y = y->size[0] * y->size[1];
  emxEnsureCapacity((emxArray__common *)y, b_y, (int)sizeof(double));
  ii = y->size[0];
  b_y = y->size[1];
  ii *= b_y;
  for (b_y = 0; b_y < ii; b_y++) {
    y->data[b_y] /= 3.1415926535897931 * x->data[b_y];
  }

  b_y = b_ii->size[0];
  b_ii->size[0] = i->size[0];
  emxEnsureCapacity((emxArray__common *)b_ii, b_y, (int)sizeof(int));
  ii = i->size[0];
  for (b_y = 0; b_y < ii; b_y++) {
    b_ii->data[b_y] = (int)i->data[b_y];
  }

  emxFree_real_T(&i);
  ii = b_ii->size[0];
  for (b_y = 0; b_y < ii; b_y++) {
    y->data[b_ii->data[b_y] - 1] = 1.0;
  }

  emxFree_int32_T(&b_ii);
}

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void sinc(emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_boolean_T *b_x;
  int i7;
  int ii;
  emxArray_int32_T *b_ii;
  int nx;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *i;
  emxArray_real_T *c_x;
  emxArray_real_T *r12;
  emxInit_boolean_T1(&b_x, 1);
  i7 = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)b_x, i7, (int)sizeof(boolean_T));
  ii = x->size[0];
  for (i7 = 0; i7 < ii; i7++) {
    b_x->data[i7] = (x->data[i7] == 0.0);
  }

  emxInit_int32_T1(&b_ii, 1);
  nx = b_x->size[0];
  idx = 0;
  i7 = b_ii->size[0];
  b_ii->size[0] = b_x->size[0];
  emxEnsureCapacity((emxArray__common *)b_ii, i7, (int)sizeof(int));
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx)) {
    guard1 = false;
    if (b_x->data[ii - 1]) {
      idx++;
      b_ii->data[idx - 1] = ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      i7 = b_ii->size[0];
      b_ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)b_ii, i7, (int)sizeof(int));
    }
  } else {
    i7 = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)b_ii, i7, (int)sizeof(int));
  }

  emxFree_boolean_T(&b_x);
  emxInit_real_T2(&i, 1);
  i7 = i->size[0];
  i->size[0] = b_ii->size[0];
  emxEnsureCapacity((emxArray__common *)i, i7, (int)sizeof(double));
  ii = b_ii->size[0];
  for (i7 = 0; i7 < ii; i7++) {
    i->data[i7] = b_ii->data[i7];
  }

  i7 = b_ii->size[0];
  b_ii->size[0] = i->size[0];
  emxEnsureCapacity((emxArray__common *)b_ii, i7, (int)sizeof(int));
  ii = i->size[0];
  for (i7 = 0; i7 < ii; i7++) {
    b_ii->data[i7] = (int)i->data[i7];
  }

  ii = b_ii->size[0];
  for (i7 = 0; i7 < ii; i7++) {
    x->data[b_ii->data[i7] - 1] = 1.0;
  }

  i7 = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)y, i7, (int)sizeof(double));
  ii = x->size[0];
  for (i7 = 0; i7 < ii; i7++) {
    y->data[i7] = 3.1415926535897931 * x->data[i7];
  }

  emxInit_real_T2(&c_x, 1);
  i7 = c_x->size[0];
  c_x->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)c_x, i7, (int)sizeof(double));
  ii = y->size[0];
  for (i7 = 0; i7 < ii; i7++) {
    c_x->data[i7] = y->data[i7];
  }

  for (ii = 0; ii + 1 <= y->size[0]; ii++) {
    c_x->data[ii] = sin(c_x->data[ii]);
  }

  emxInit_real_T2(&r12, 1);
  i7 = r12->size[0];
  r12->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)r12, i7, (int)sizeof(double));
  ii = x->size[0];
  for (i7 = 0; i7 < ii; i7++) {
    r12->data[i7] = 3.1415926535897931 * x->data[i7];
  }

  rdivide(c_x, r12, y);
  i7 = b_ii->size[0];
  b_ii->size[0] = i->size[0];
  emxEnsureCapacity((emxArray__common *)b_ii, i7, (int)sizeof(int));
  ii = i->size[0];
  emxFree_real_T(&r12);
  emxFree_real_T(&c_x);
  for (i7 = 0; i7 < ii; i7++) {
    b_ii->data[i7] = (int)i->data[i7];
  }

  emxFree_real_T(&i);
  ii = b_ii->size[0];
  for (i7 = 0; i7 < ii; i7++) {
    y->data[b_ii->data[i7] - 1] = 1.0;
  }

  emxFree_int32_T(&b_ii);
}

/*
 * File trailer for sinc.c
 *
 * [EOF]
 */
