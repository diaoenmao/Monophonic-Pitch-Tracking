/*
 * File: Add.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:27:33
 */

/* Include files */
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
  int i;
  int loop_ub;
  i = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = arr->size[1];
  emxEnsureCapacity((emxArray__common *)out, i, (int)sizeof(double));
  loop_ub = arr->size[0] * arr->size[1];
  for (i = 0; i < loop_ub; i++) {
    out->data[i] = arr->data[i];
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
