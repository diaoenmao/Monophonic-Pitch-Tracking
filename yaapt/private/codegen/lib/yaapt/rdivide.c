/*
 * File: rdivide.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "rdivide.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void b_rdivide(const emxArray_real_T *y, emxArray_real_T *z)
{
  int i14;
  int loop_ub;
  i14 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)z, i14, (int)sizeof(double));
  loop_ub = y->size[0];
  for (i14 = 0; i14 < loop_ub; i14++) {
    z->data[i14] = 1.0 / y->data[i14];
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void rdivide(const emxArray_real_T *x, const emxArray_real_T *y, emxArray_real_T
             *z)
{
  int i6;
  int loop_ub;
  i6 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i6, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i6 = 0; i6 < loop_ub; i6++) {
    z->data[i6] = x->data[i6] / y->data[i6];
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
