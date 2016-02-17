/*
 * File: rdivide.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
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
  int i8;
  int loop_ub;
  i8 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i8, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    z->data[i8] = x->data[i8] / y->data[i8];
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
  int i12;
  int loop_ub;
  i12 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i12, (int)sizeof(double));
  loop_ub = x->size[0] * x->size[1];
  for (i12 = 0; i12 < loop_ub; i12++) {
    z->data[i12] = x->data[i12] / y;
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
  int i18;
  int loop_ub;
  i18 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)z, i18, (int)sizeof(double));
  loop_ub = y->size[0];
  for (i18 = 0; i18 < loop_ub; i18++) {
    z->data[i18] = x / y->data[i18];
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
  int i4;
  int loop_ub;
  i4 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i4, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    z->data[i4] = x->data[i4] / y;
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
