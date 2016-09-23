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
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo s_emlrtRTEI = { 1, 14, "rdivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

/* Function Definitions */
void b_rdivide(const emlrtStack *sp, real_T x, const emxArray_real_T *y,
               emxArray_real_T *z)
{
  int32_T i22;
  int32_T loop_ub;
  i22 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i22, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  loop_ub = y->size[0];
  for (i22 = 0; i22 < loop_ub; i22++) {
    z->data[i22] = x / y->data[i22];
  }
}

void c_rdivide(const emlrtStack *sp, const emxArray_real_T *y, emxArray_real_T
               *z)
{
  int32_T i24;
  int32_T loop_ub;
  i24 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i24, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  loop_ub = y->size[0];
  for (i24 = 0; i24 < loop_ub; i24++) {
    z->data[i24] = 1.0 / y->data[i24];
  }
}

void rdivide(const emlrtStack *sp, const emxArray_real_T *x, const
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
    emlrtErrorWithMessageIdR2012b(sp, &hf_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  k = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, k, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  loop_ub = x->size[0];
  for (k = 0; k < loop_ub; k++) {
    z->data[k] = x->data[k] / y->data[k];
  }
}

/* End of code generation (rdivide.c) */
