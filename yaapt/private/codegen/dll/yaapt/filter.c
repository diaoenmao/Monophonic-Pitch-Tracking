/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "filter.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_filter(const emxArray_real_T *x, emxArray_real_T *y)
{
  int k;
  int nx;
  int j;
  double dbuffer[3];
  double b_dbuffer;
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(double));
  nx = x->size[1];
  if (x->size[1] >= 6) {
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(double));
    j = y->size[1];
    for (k = 0; k < j; k++) {
      y->data[y->size[0] * k] = 0.0;
    }

    for (k = 0; k < 3; k++) {
      for (j = k; j + 1 <= nx; j++) {
        y->data[j] += 0.33333333333333331 * x->data[j - k];
      }
    }
  } else {
    for (k = 0; k < 2; k++) {
      dbuffer[k + 1] = 0.0;
    }

    for (j = 0; j + 1 <= nx; j++) {
      for (k = 0; k < 2; k++) {
        dbuffer[k] = dbuffer[k + 1];
      }

      dbuffer[2] = 0.0;
      for (k = 0; k < 3; k++) {
        b_dbuffer = dbuffer[k] + x->data[j] * 0.33333333333333331;
        dbuffer[k] = b_dbuffer;
      }

      y->data[j] = dbuffer[0];
    }
  }
}

/*
 * Arguments    : const double b[151]
 *                const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void filter(const double b[151], const emxArray_real_T *x, emxArray_real_T *y)
{
  int j;
  int nx;
  int k;
  double dbuffer[151];
  double b_dbuffer;
  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, j, (int)sizeof(double));
  nx = x->size[1];
  if (x->size[1] >= 302) {
    j = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, j, (int)sizeof(double));
    k = y->size[1];
    for (j = 0; j < k; j++) {
      y->data[y->size[0] * j] = 0.0;
    }

    for (k = 0; k < 151; k++) {
      for (j = k; j + 1 <= nx; j++) {
        y->data[j] += b[k] * x->data[j - k];
      }
    }
  } else {
    memset(&dbuffer[1], 0, 150U * sizeof(double));
    for (j = 0; j + 1 <= nx; j++) {
      for (k = 0; k < 150; k++) {
        dbuffer[k] = dbuffer[k + 1];
      }

      dbuffer[150] = 0.0;
      for (k = 0; k < 151; k++) {
        b_dbuffer = dbuffer[k] + x->data[j] * b[k];
        dbuffer[k] = b_dbuffer;
      }

      y->data[j] = dbuffer[0];
    }
  }
}

/*
 * File trailer for filter.c
 *
 * [EOF]
 */
