/*
 * File: Add.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 19:57:34
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Add.h"
#include "Add_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *arr
 *                double b
 *                emxArray_real_T *out
 * Return Type  : void
 */
void Add(const emxArray_real_T *arr, double b, emxArray_real_T *out)
{
  int i0;
  int loop_ub;
  int i;
  i0 = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = arr->size[1];
  emxEnsureCapacity((emxArray__common *)out, i0, (int)sizeof(double));
  loop_ub = arr->size[0] * arr->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    out->data[i0] = arr->data[i0];
  }

  for (i = 0; i < arr->size[1]; i++) {
    out->data[i] = arr->data[i] + b;
  }
}

/*
 * File trailer for Add.c
 *
 * [EOF]
 */
