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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo q_emlrtRTEI = { 1, 14, "rdivide",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

static emlrtRTEInfo ne_emlrtRTEI = { 13, 15, "rdivide",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

/* Function Definitions */

/*
 *
 */
void b_rdivide(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
               emxArray_real_T *z)
{
  int32_T i13;
  int32_T loop_ub;
  i13 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i13, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  loop_ub = x->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    z->data[i13] = x->data[i13] / y;
  }
}

/*
 *
 */
void c_rdivide(const emlrtStack *sp, real_T x, const emxArray_real_T *y,
               emxArray_real_T *z)
{
  int32_T i18;
  int32_T loop_ub;
  i18 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i18, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  loop_ub = y->size[0];
  for (i18 = 0; i18 < loop_ub; i18++) {
    z->data[i18] = x / y->data[i18];
  }
}

/*
 *
 */
void d_rdivide(const emlrtStack *sp, const emxArray_real_T *x, const
               emxArray_real_T *y, emxArray_real_T *z)
{
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  int32_T loop_ub;
  varargin_1[0] = (uint32_T)x->size[0];
  varargin_1[1] = 1U;
  varargin_2[0] = (uint32_T)y->size[0];
  varargin_2[1] = 1U;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!((int32_T)varargin_1[k] == (int32_T)varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ne_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  k = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, k, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  loop_ub = x->size[0];
  for (k = 0; k < loop_ub; k++) {
    z->data[k] = x->data[k] / y->data[k];
  }
}

/*
 *
 */
void rdivide(const real_T x[75], const real_T y[75], real_T z[75])
{
  int32_T i;
  for (i = 0; i < 75; i++) {
    z[i] = x[i] / y[i];
  }
}

/* End of code generation (rdivide.c) */
