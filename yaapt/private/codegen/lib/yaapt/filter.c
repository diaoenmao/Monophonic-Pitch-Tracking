/*
 * File: filter.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "filter.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *b
 *                const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void filter(const emxArray_real_T *b, const emxArray_real_T *x, emxArray_real_T *
            y)
{
  int nb;
  int ndbuffer;
  int j;
  int nx;
  emxArray_real_T *dbuffer;
  int k;
  nb = b->size[1];
  if (1 >= b->size[1]) {
    ndbuffer = 0;
  } else {
    ndbuffer = b->size[1] - 1;
  }

  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, j, (int)sizeof(double));
  nx = x->size[1];
  if (x->size[1] >= (b->size[1] << 1)) {
    j = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, j, (int)sizeof(double));
    k = y->size[1];
    for (j = 0; j < k; j++) {
      y->data[y->size[0] * j] = 0.0;
    }

    for (k = 1; k <= nb; k++) {
      for (j = k; j <= nx; j++) {
        y->data[j - 1] += b->data[k - 1] * x->data[j - k];
      }
    }
  } else {
    emxInit_real_T2(&dbuffer, 1);
    j = dbuffer->size[0];
    dbuffer->size[0] = ndbuffer + 1;
    emxEnsureCapacity((emxArray__common *)dbuffer, j, (int)sizeof(double));
    for (k = 1; k <= ndbuffer; k++) {
      dbuffer->data[k] = 0.0;
    }

    for (j = 0; j + 1 <= nx; j++) {
      for (k = 1; k <= ndbuffer; k++) {
        dbuffer->data[k - 1] = dbuffer->data[k];
      }

      dbuffer->data[ndbuffer] = 0.0;
      for (k = 0; k + 1 <= nb; k++) {
        dbuffer->data[k] += x->data[j] * b->data[k];
      }

      y->data[j] = dbuffer->data[0];
    }

    emxFree_real_T(&dbuffer);
  }
}

/*
 * File trailer for filter.c
 *
 * [EOF]
 */
