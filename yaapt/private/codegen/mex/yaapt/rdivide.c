/*
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "isequal.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo t_emlrtRTEI = { 1, 14, "rdivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

/* Function Definitions */

/*
 *
 */
void b_rdivide(const emlrtStack *sp, real_T x, const emxArray_real_T *y,
               emxArray_real_T *z)
{
  int32_T i28;
  int32_T loop_ub;
  i28 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i28, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  loop_ub = y->size[0];
  for (i28 = 0; i28 < loop_ub; i28++) {
    z->data[i28] = x / y->data[i28];
  }
}

/*
 *
 */
void c_rdivide(const emlrtStack *sp, const emxArray_real_T *y, emxArray_real_T
               *z)
{
  int32_T i30;
  int32_T loop_ub;
  i30 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i30, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  loop_ub = y->size[0];
  for (i30 = 0; i30 < loop_ub; i30++) {
    z->data[i30] = 1.0 / y->data[i30];
  }
}

/*
 *
 */
void rdivide(const emlrtStack *sp, const emxArray_real_T *x, const
             emxArray_real_T *y, emxArray_real_T *z)
{
  real_T b_x[2];
  real_T b_y[2];
  int32_T i8;
  int32_T loop_ub;
  b_x[0] = x->size[0];
  b_x[1] = 1.0;
  b_y[0] = y->size[0];
  b_y[1] = 1.0;
  if (isequal(b_x, b_y)) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &qf_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  i8 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i8, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  loop_ub = x->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    z->data[i8] = x->data[i8] / y->data[i8];
  }
}

/* End of code generation (rdivide.c) */
