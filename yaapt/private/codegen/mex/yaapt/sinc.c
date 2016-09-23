/*
 * sinc.c
 *
 * Code generation for function 'sinc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sinc.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rdivide.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo xb_emlrtRSI = { 24, "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m" };

static emlrtRSInfo yb_emlrtRSI = { 26, "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m" };

static emlrtRSInfo dc_emlrtRSI = { 10, "sin",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\sin.m" };

static emlrtRTEInfo t_emlrtRTEI = { 1, 12, "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m" };

static emlrtRTEInfo v_emlrtRTEI = { 24, 1, "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m" };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 25, 1, "", "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 27, 1, "", "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m", 0 };

static emlrtRTEInfo jf_emlrtRTEI = { 126, 19, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

/* Function Definitions */
void b_sinc(const emlrtStack *sp, emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_boolean_T *b_x;
  int32_T i9;
  int32_T idx;
  int32_T nx;
  boolean_T p;
  emxArray_int32_T *ii;
  int32_T b_ii;
  boolean_T exitg2;
  boolean_T guard1 = false;
  int32_T iv13[2];
  emxArray_real_T *i;
  emxArray_real_T *b_y;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T b_p;
  boolean_T exitg1;
  int32_T c_y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_x, 2, &t_emlrtRTEI, true);
  st.site = &xb_emlrtRSI;
  i9 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = x->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i9, (int32_T)sizeof(boolean_T),
                    &t_emlrtRTEI);
  idx = x->size[0] * x->size[1];
  for (i9 = 0; i9 < idx; i9++) {
    b_x->data[i9] = (x->data[i9] == 0.0);
  }

  b_st.site = &ac_emlrtRSI;
  nx = b_x->size[0] * b_x->size[1];
  idx = 0;
  if ((!((b_x->size[0] == 1) || (b_x->size[1] == 1))) || (b_x->size[0] != 1) ||
      (b_x->size[1] <= 1)) {
    p = true;
  } else {
    p = false;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &jf_emlrtRTEI,
      "Coder:toolbox:find_incompatibleShape", 0);
  }

  emxInit_int32_T1(&b_st, &ii, 1, &w_emlrtRTEI, true);
  i9 = ii->size[0];
  ii->size[0] = nx;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i9, (int32_T)sizeof(int32_T),
                    &t_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  if ((!(1 > nx)) && (nx > 2147483646)) {
    d_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  b_ii = 1;
  exitg2 = false;
  while ((!exitg2) && (b_ii <= nx)) {
    guard1 = false;
    if (b_x->data[b_ii - 1]) {
      idx++;
      ii->data[idx - 1] = b_ii;
      if (idx >= nx) {
        exitg2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      b_ii++;
    }
  }

  emxFree_boolean_T(&b_x);
  if (idx <= nx) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &if_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (nx == 1) {
    if (idx == 0) {
      i9 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i9, (int32_T)sizeof
                        (int32_T), &t_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i9 = 0;
    } else {
      i9 = idx;
    }

    iv13[0] = 1;
    iv13[1] = i9;
    c_st.site = &cc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv13);
    nx = ii->size[0];
    ii->size[0] = i9;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &u_emlrtRTEI);
  }

  emxInit_real_T2(&b_st, &i, 1, &v_emlrtRTEI, true);
  i9 = i->size[0];
  i->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)i, i9, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  idx = ii->size[0];
  for (i9 = 0; i9 < idx; i9++) {
    i->data[i9] = ii->data[i9];
  }

  b_ii = x->size[0] * x->size[1];
  i9 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i9, (int32_T)sizeof(int32_T),
                    &t_emlrtRTEI);
  idx = i->size[0];
  for (i9 = 0; i9 < idx; i9++) {
    nx = (int32_T)i->data[i9];
    if (!((nx >= 1) && (nx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, b_ii, &yb_emlrtBCI, sp);
    }

    ii->data[i9] = nx;
  }

  idx = ii->size[0];
  for (i9 = 0; i9 < idx; i9++) {
    x->data[ii->data[i9] - 1] = 1.0;
  }

  i9 = y->size[0] * y->size[1];
  y->size[0] = x->size[0];
  y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i9, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  idx = x->size[0] * x->size[1];
  for (i9 = 0; i9 < idx; i9++) {
    y->data[i9] = 3.1415926535897931 * x->data[i9];
  }

  st.site = &yb_emlrtRSI;
  b_st.site = &dc_emlrtRSI;
  nx = y->size[0] * y->size[1];
  c_st.site = &cb_emlrtRSI;
  if ((!(1 > nx)) && (nx > 2147483646)) {
    d_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (b_ii = 0; b_ii + 1 <= nx; b_ii++) {
    y->data[b_ii] = muDoubleScalarSin(y->data[b_ii]);
  }

  emxInit_real_T(&b_st, &b_y, 2, &t_emlrtRTEI, true);
  i9 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = x->size[0];
  b_y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_y, i9, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  idx = x->size[0] * x->size[1];
  for (i9 = 0; i9 < idx; i9++) {
    b_y->data[i9] = 3.1415926535897931 * x->data[i9];
  }

  st.site = &yb_emlrtRSI;
  for (i9 = 0; i9 < 2; i9++) {
    varargin_1[i9] = (uint32_T)y->size[i9];
  }

  for (i9 = 0; i9 < 2; i9++) {
    varargin_2[i9] = (uint32_T)b_y->size[i9];
  }

  p = false;
  b_p = true;
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 2)) {
    if (!((int32_T)varargin_1[b_ii] == (int32_T)varargin_2[b_ii])) {
      b_p = false;
      exitg1 = true;
    } else {
      b_ii++;
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &hf_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  i9 = y->size[0] * y->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, i9, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  c_y = y->size[0];
  b_ii = y->size[1];
  idx = c_y * b_ii;
  for (i9 = 0; i9 < idx; i9++) {
    y->data[i9] /= b_y->data[i9];
  }

  emxFree_real_T(&b_y);
  c_y = y->size[0] * y->size[1];
  i9 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i9, (int32_T)sizeof(int32_T),
                    &t_emlrtRTEI);
  idx = i->size[0];
  for (i9 = 0; i9 < idx; i9++) {
    nx = (int32_T)i->data[i9];
    if (!((nx >= 1) && (nx <= c_y))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, c_y, &ac_emlrtBCI, sp);
    }

    ii->data[i9] = nx;
  }

  emxFree_real_T(&i);
  idx = ii->size[0];
  for (i9 = 0; i9 < idx; i9++) {
    y->data[ii->data[i9] - 1] = 1.0;
  }

  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void sinc(const emlrtStack *sp, emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_boolean_T *b_x;
  int32_T i8;
  int32_T nx;
  emxArray_int32_T *ii;
  int32_T idx;
  boolean_T overflow;
  int32_T b_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv12[2];
  emxArray_real_T *i;
  emxArray_real_T *c_x;
  emxArray_real_T *r12;
  emxArray_real_T *r13;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T1(sp, &b_x, 1, &t_emlrtRTEI, true);
  st.site = &xb_emlrtRSI;
  i8 = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i8, (int32_T)sizeof(boolean_T),
                    &t_emlrtRTEI);
  nx = x->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    b_x->data[i8] = (x->data[i8] == 0.0);
  }

  emxInit_int32_T1(&st, &ii, 1, &w_emlrtRTEI, true);
  b_st.site = &ac_emlrtRSI;
  nx = b_x->size[0];
  idx = 0;
  i8 = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i8, (int32_T)sizeof(int32_T),
                    &t_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  overflow = ((!(1 > b_x->size[0])) && (b_x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= nx)) {
    guard1 = false;
    if (b_x->data[b_ii - 1]) {
      idx++;
      ii->data[idx - 1] = b_ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      b_ii++;
    }
  }

  if (idx <= b_x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &if_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      i8 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i8, (int32_T)sizeof
                        (int32_T), &t_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i8 = 0;
    } else {
      i8 = idx;
    }

    iv12[0] = 1;
    iv12[1] = i8;
    c_st.site = &cc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv12);
    idx = ii->size[0];
    ii->size[0] = i8;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &u_emlrtRTEI);
  }

  emxFree_boolean_T(&b_x);
  emxInit_real_T2(&b_st, &i, 1, &v_emlrtRTEI, true);
  i8 = i->size[0];
  i->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)i, i8, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  nx = ii->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    i->data[i8] = ii->data[i8];
  }

  b_ii = x->size[0];
  i8 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i8, (int32_T)sizeof(int32_T),
                    &t_emlrtRTEI);
  nx = i->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    idx = (int32_T)i->data[i8];
    if (!((idx >= 1) && (idx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, b_ii, &yb_emlrtBCI, sp);
    }

    ii->data[i8] = idx;
  }

  nx = ii->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    x->data[ii->data[i8] - 1] = 1.0;
  }

  emxInit_real_T2(sp, &c_x, 1, &t_emlrtRTEI, true);
  i8 = c_x->size[0];
  c_x->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_x, i8, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  nx = x->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    c_x->data[i8] = 3.1415926535897931 * x->data[i8];
  }

  emxInit_real_T2(sp, &r12, 1, &t_emlrtRTEI, true);
  st.site = &yb_emlrtRSI;
  b_st.site = &dc_emlrtRSI;
  i8 = r12->size[0];
  r12->size[0] = c_x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)r12, i8, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  nx = c_x->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    r12->data[i8] = c_x->data[i8];
  }

  c_st.site = &cb_emlrtRSI;
  overflow = ((!(1 > c_x->size[0])) && (c_x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (b_ii = 0; b_ii + 1 <= c_x->size[0]; b_ii++) {
    r12->data[b_ii] = muDoubleScalarSin(r12->data[b_ii]);
  }

  emxFree_real_T(&c_x);
  emxInit_real_T2(&b_st, &r13, 1, &t_emlrtRTEI, true);
  i8 = r13->size[0];
  r13->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r13, i8, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  nx = x->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    r13->data[i8] = 3.1415926535897931 * x->data[i8];
  }

  st.site = &yb_emlrtRSI;
  rdivide(&st, r12, r13, y);
  b_ii = y->size[0];
  i8 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i8, (int32_T)sizeof(int32_T),
                    &t_emlrtRTEI);
  nx = i->size[0];
  emxFree_real_T(&r13);
  emxFree_real_T(&r12);
  for (i8 = 0; i8 < nx; i8++) {
    idx = (int32_T)i->data[i8];
    if (!((idx >= 1) && (idx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, b_ii, &ac_emlrtBCI, sp);
    }

    ii->data[i8] = idx;
  }

  emxFree_real_T(&i);
  nx = ii->size[0];
  for (i8 = 0; i8 < nx; i8++) {
    y->data[ii->data[i8] - 1] = 1.0;
  }

  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sinc.c) */
