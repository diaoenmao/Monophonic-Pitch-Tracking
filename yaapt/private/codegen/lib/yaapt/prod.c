/*
 * File: prod.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
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
  int vlen;
  int i;
  int xoffset;
  double s;
  int k;
  vlen = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, vlen, (int)sizeof(double));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vlen = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, vlen, (int)sizeof(double));
    i = y->size[1];
    for (vlen = 0; vlen < i; vlen++) {
      y->data[y->size[0] * vlen] = 1.0;
    }
  } else {
    vlen = x->size[0];
    for (i = 0; i + 1 <= x->size[1]; i++) {
      xoffset = i * vlen;
      s = x->data[xoffset];
      for (k = 2; k <= vlen; k++) {
        s *= x->data[(xoffset + k) - 1];
      }

      y->data[i] = s;
    }
  }
}

/*
 * File trailer for prod.c
 *
 * [EOF]
 */
