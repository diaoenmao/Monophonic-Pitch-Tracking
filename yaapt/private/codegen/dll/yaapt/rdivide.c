/*
 * File: rdivide.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

/* Include files */
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
 * Arguments    : double x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void d_rdivide(double x, const emxArray_real_T *y, emxArray_real_T *z)
{
  int i6;
  int loop_ub;
  i6 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)z, i6, (int)sizeof(double));
  loop_ub = y->size[0];
  for (i6 = 0; i6 < loop_ub; i6++) {
    z->data[i6] = x / y->data[i6];
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void e_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
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
