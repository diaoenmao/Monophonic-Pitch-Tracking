/*
 * File: prod.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 12-Jan-2016 01:25:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "prod.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void prod(const emxArray_real_T *x, emxArray_real_T *y)
{
  int ixstart;
  int k;
  int ix;
  int iy;
  int i;
  double s;
  ixstart = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, ixstart, (int)sizeof(double));
  if (x->size[1] == 0) {
    ixstart = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, ixstart, (int)sizeof(double));
    k = y->size[1];
    for (ixstart = 0; ixstart < k; ixstart++) {
      y->data[y->size[0] * ixstart] = 1.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (i = 1; i <= x->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      for (k = 0; k < 3; k++) {
        ix++;
        s *= x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

/*
 * File trailer for prod.c
 *
 * [EOF]
 */
