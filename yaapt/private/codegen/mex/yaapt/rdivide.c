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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo j_emlrtRTEI = { 1, 14, "rdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

/* Function Definitions */

/*
 *
 */
void b_rdivide(const emlrtStack *sp, const emxArray_real_T *x, const
               emxArray_real_T *y, emxArray_real_T *z)
{
  real_T b_x[2];
  real_T b_y[2];
  int32_T i9;
  int32_T loop_ub;
  b_x[0] = x->size[0];
  b_x[1] = 1.0;
  b_y[0] = y->size[0];
  b_y[1] = 1.0;
  if (isequal(b_x, b_y)) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &gf_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  i9 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i9, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  loop_ub = x->size[0];
  for (i9 = 0; i9 < loop_ub; i9++) {
    z->data[i9] = x->data[i9] / y->data[i9];
  }
}

/*
 *
 */
void c_rdivide(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
               emxArray_real_T *z)
{
  int32_T i14;
  int32_T loop_ub;
  i14 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)z, i14, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  for (i14 = 0; i14 < loop_ub; i14++) {
    z->data[i14] = x->data[i14] / y;
  }
}

/*
 *
 */
void d_rdivide(const emlrtStack *sp, real_T x, const emxArray_real_T *y,
               emxArray_real_T *z)
{
  int32_T i25;
  int32_T loop_ub;
  i25 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i25, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  loop_ub = y->size[0];
  for (i25 = 0; i25 < loop_ub; i25++) {
    z->data[i25] = x / y->data[i25];
  }
}

/*
 *
 */
void rdivide(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
             emxArray_real_T *z)
{
  int32_T i3;
  int32_T loop_ub;
  i3 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i3, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  loop_ub = x->size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    z->data[i3] = x->data[i3] / y;
  }
}

/* End of code generation (rdivide.c) */
