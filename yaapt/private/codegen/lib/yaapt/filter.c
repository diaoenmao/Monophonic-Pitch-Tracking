/*
 * File: filter.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "filter.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const double b[151]
 *                const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void filter(const double b[151], const emxArray_real_T *x, emxArray_real_T *y)
{
  unsigned int uv0[2];
  int j;
  int k;
  int jend;
  double dbuffer[151];
  double b_dbuffer;
  for (j = 0; j < 2; j++) {
    uv0[j] = (unsigned int)x->size[j];
  }

  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, j, (int)sizeof(double));
  if (x->size[1] >= 302) {
    j = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, j, (int)sizeof(double));
    j = y->size[0] * y->size[1];
    y->size[1] = (int)uv0[1];
    emxEnsureCapacity((emxArray__common *)y, j, (int)sizeof(double));
    k = (int)uv0[1];
    for (j = 0; j < k; j++) {
      y->data[j] = 0.0;
    }

    for (k = 0; k < 151; k++) {
      jend = (k + x->size[1]) - k;
      for (j = k; j + 1 <= jend; j++) {
        y->data[j] += b[k] * x->data[j - k];
      }
    }
  } else {
    memset(&dbuffer[1], 0, 150U * sizeof(double));
    for (j = 0; j + 1 <= x->size[1]; j++) {
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
