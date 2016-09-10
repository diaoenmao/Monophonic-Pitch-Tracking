/*
 * File: rdivide.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
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
  int i16;
  int loop_ub;
  i16 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)z, i16, (int)sizeof(double));
  loop_ub = y->size[0];
  for (i16 = 0; i16 < loop_ub; i16++) {
    z->data[i16] = 1.0 / y->data[i16];
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
  int i7;
  int loop_ub;
  i7 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i7, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    z->data[i7] = x->data[i7] / y->data[i7];
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
