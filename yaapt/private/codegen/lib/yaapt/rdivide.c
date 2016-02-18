/*
 * File: rdivide.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "rdivide.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void b_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
               emxArray_real_T *z)
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
 * Arguments    : const emxArray_real_T *x
 *                double y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void c_rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z)
{
  int i11;
  int loop_ub;
  i11 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i11, (int)sizeof(double));
  loop_ub = x->size[0] * x->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    z->data[i11] = x->data[i11] / y;
  }
}

/*
 * Arguments    : double x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void d_rdivide(double x, const emxArray_real_T *y, emxArray_real_T *z)
{
  int i16;
  int loop_ub;
  i16 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)z, i16, (int)sizeof(double));
  loop_ub = y->size[0];
  for (i16 = 0; i16 < loop_ub; i16++) {
    z->data[i16] = x / y->data[i16];
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                double y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z)
{
  int i3;
  int loop_ub;
  i3 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i3, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    z->data[i3] = x->data[i3] / y;
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
