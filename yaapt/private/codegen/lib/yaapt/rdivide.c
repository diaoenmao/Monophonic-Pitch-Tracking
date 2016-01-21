/*
 * File: rdivide.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Jan-2016 05:43:25
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "rdivide.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const double x[5776]
 *                const double y[5776]
 *                double z[5776]
 * Return Type  : void
 */
void b_rdivide(const double x[5776], const double y[5776], double z[5776])
{
  int i1;
  for (i1 = 0; i1 < 5776; i1++) {
    z[i1] = x[i1] / y[i1];
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
 * Arguments    : const emxArray_real_T *x
 *                double y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void d_rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z)
{
  int i5;
  int loop_ub;
  i5 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i5, (int)sizeof(double));
  loop_ub = x->size[0] * x->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    z->data[i5] = x->data[i5] / y;
  }
}

/*
 * Arguments    : double x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void e_rdivide(double x, const emxArray_real_T *y, emxArray_real_T *z)
{
  int i7;
  int loop_ub;
  i7 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)z, i7, (int)sizeof(double));
  loop_ub = y->size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    z->data[i7] = x / y->data[i7];
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void f_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
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
 * Arguments    : const double x[75]
 *                const double y[75]
 *                double z[75]
 * Return Type  : void
 */
void rdivide(const double x[75], const double y[75], double z[75])
{
  int i;
  for (i = 0; i < 75; i++) {
    z[i] = x[i] / y[i];
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
