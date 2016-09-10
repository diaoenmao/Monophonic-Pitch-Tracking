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
#include "isequal.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rdivide.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ic_emlrtRSI = { 24, "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m" };

static emlrtRSInfo jc_emlrtRSI = { 26, "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m" };

static emlrtRSInfo nc_emlrtRSI = { 10, "sin",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\sin.m" };

static emlrtRTEInfo u_emlrtRTEI = { 1, 12, "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m" };

static emlrtRTEInfo w_emlrtRTEI = { 24, 1, "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m" };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 25, 1, "", "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m", 0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 27, 1, "", "sinc",
  "F:\\MATLAB\\R2016a\\toolbox\\signal\\signal\\sinc.m", 0 };

static emlrtRTEInfo sf_emlrtRTEI = { 126, 19, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtDCInfo l_emlrtDCI = { 131, 30, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m", 4 };

/* Function Definitions */

/*
 *
 */
void b_sinc(const emlrtStack *sp, emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_boolean_T *b_x;
  int32_T i10;
  int32_T idx;
  int32_T nx;
  boolean_T b0;
  emxArray_int32_T *ii;
  int32_T b_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv18[2];
  emxArray_real_T *i;
  emxArray_real_T *b_y;
  real_T c_y[2];
  real_T d_y[2];
  int32_T e_y;
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
  emxInit_boolean_T(sp, &b_x, 2, &u_emlrtRTEI, true);
  st.site = &ic_emlrtRSI;
  i10 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = x->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i10, (int32_T)sizeof(boolean_T),
                    &u_emlrtRTEI);
  idx = x->size[0] * x->size[1];
  for (i10 = 0; i10 < idx; i10++) {
    b_x->data[i10] = (x->data[i10] == 0.0);
  }

  b_st.site = &kc_emlrtRSI;
  nx = b_x->size[0] * b_x->size[1];
  idx = 0;
  if ((!((b_x->size[0] == 1) || (b_x->size[1] == 1))) || (b_x->size[0] != 1) ||
      (b_x->size[1] <= 1)) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &sf_emlrtRTEI,
      "Coder:toolbox:find_incompatibleShape", 0);
  }

  emxInit_int32_T1(&b_st, &ii, 1, &x_emlrtRTEI, true);
  i10 = ii->size[0];
  if (!(nx >= 0)) {
    emlrtNonNegativeCheckR2012b(nx, &l_emlrtDCI, &b_st);
  }

  ii->size[0] = nx;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i10, (int32_T)sizeof(int32_T),
                    &u_emlrtRTEI);
  c_st.site = &lc_emlrtRSI;
  if ((!(1 > nx)) && (nx > 2147483646)) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
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

  emxFree_boolean_T(&b_x);
  if (idx <= nx) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &rf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (nx == 1) {
    if (idx == 0) {
      i10 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i10, (int32_T)sizeof
                        (int32_T), &u_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i10 = 0;
    } else {
      i10 = idx;
    }

    iv18[0] = 1;
    iv18[1] = i10;
    c_st.site = &mc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv18);
    nx = ii->size[0];
    ii->size[0] = i10;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &v_emlrtRTEI);
  }

  emxInit_real_T1(&b_st, &i, 1, &w_emlrtRTEI, true);
  i10 = i->size[0];
  i->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)i, i10, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  idx = ii->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    i->data[i10] = ii->data[i10];
  }

  b_ii = x->size[0] * x->size[1];
  i10 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i10, (int32_T)sizeof(int32_T),
                    &u_emlrtRTEI);
  idx = i->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    nx = (int32_T)i->data[i10];
    if (!((nx >= 1) && (nx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, b_ii, &bc_emlrtBCI, sp);
    }

    ii->data[i10] = nx;
  }

  idx = ii->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    x->data[ii->data[i10] - 1] = 1.0;
  }

  i10 = y->size[0] * y->size[1];
  y->size[0] = x->size[0];
  y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i10, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  idx = x->size[0] * x->size[1];
  for (i10 = 0; i10 < idx; i10++) {
    y->data[i10] = 3.1415926535897931 * x->data[i10];
  }

  st.site = &jc_emlrtRSI;
  b_st.site = &nc_emlrtRSI;
  nx = y->size[0] * y->size[1];
  c_st.site = &eb_emlrtRSI;
  if ((!(1 > nx)) && (nx > 2147483646)) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  for (b_ii = 0; b_ii + 1 <= nx; b_ii++) {
    y->data[b_ii] = muDoubleScalarSin(y->data[b_ii]);
  }

  emxInit_real_T(&b_st, &b_y, 2, &u_emlrtRTEI, true);
  i10 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = x->size[0];
  b_y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_y, i10, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  idx = x->size[0] * x->size[1];
  for (i10 = 0; i10 < idx; i10++) {
    b_y->data[i10] = 3.1415926535897931 * x->data[i10];
  }

  st.site = &jc_emlrtRSI;
  for (i10 = 0; i10 < 2; i10++) {
    c_y[i10] = y->size[i10];
  }

  for (i10 = 0; i10 < 2; i10++) {
    d_y[i10] = b_y->size[i10];
  }

  if (isequal(c_y, d_y)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &qf_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  i10 = y->size[0] * y->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, i10, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  e_y = y->size[0];
  b_ii = y->size[1];
  idx = e_y * b_ii;
  for (i10 = 0; i10 < idx; i10++) {
    y->data[i10] /= b_y->data[i10];
  }

  emxFree_real_T(&b_y);
  e_y = y->size[0] * y->size[1];
  i10 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i10, (int32_T)sizeof(int32_T),
                    &u_emlrtRTEI);
  idx = i->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    nx = (int32_T)i->data[i10];
    if (!((nx >= 1) && (nx <= e_y))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, e_y, &cc_emlrtBCI, sp);
    }

    ii->data[i10] = nx;
  }

  emxFree_real_T(&i);
  idx = ii->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    y->data[ii->data[i10] - 1] = 1.0;
  }

  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void sinc(const emlrtStack *sp, emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_boolean_T *b_x;
  int32_T i9;
  int32_T nx;
  emxArray_int32_T *ii;
  int32_T idx;
  boolean_T overflow;
  int32_T b_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv17[2];
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
  emxInit_boolean_T1(sp, &b_x, 1, &u_emlrtRTEI, true);
  st.site = &ic_emlrtRSI;
  i9 = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i9, (int32_T)sizeof(boolean_T),
                    &u_emlrtRTEI);
  nx = x->size[0];
  for (i9 = 0; i9 < nx; i9++) {
    b_x->data[i9] = (x->data[i9] == 0.0);
  }

  emxInit_int32_T1(&st, &ii, 1, &x_emlrtRTEI, true);
  b_st.site = &kc_emlrtRSI;
  nx = b_x->size[0];
  idx = 0;
  i9 = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i9, (int32_T)sizeof(int32_T),
                    &u_emlrtRTEI);
  c_st.site = &lc_emlrtRSI;
  overflow = ((!(1 > b_x->size[0])) && (b_x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
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
    emlrtErrorWithMessageIdR2012b(&b_st, &rf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      i9 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i9, (int32_T)sizeof
                        (int32_T), &u_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i9 = 0;
    } else {
      i9 = idx;
    }

    iv17[0] = 1;
    iv17[1] = i9;
    c_st.site = &mc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv17);
    idx = ii->size[0];
    ii->size[0] = i9;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &v_emlrtRTEI);
  }

  emxFree_boolean_T(&b_x);
  emxInit_real_T1(&b_st, &i, 1, &w_emlrtRTEI, true);
  i9 = i->size[0];
  i->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)i, i9, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  nx = ii->size[0];
  for (i9 = 0; i9 < nx; i9++) {
    i->data[i9] = ii->data[i9];
  }

  b_ii = x->size[0];
  i9 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i9, (int32_T)sizeof(int32_T),
                    &u_emlrtRTEI);
  nx = i->size[0];
  for (i9 = 0; i9 < nx; i9++) {
    idx = (int32_T)i->data[i9];
    if (!((idx >= 1) && (idx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, b_ii, &bc_emlrtBCI, sp);
    }

    ii->data[i9] = idx;
  }

  nx = ii->size[0];
  for (i9 = 0; i9 < nx; i9++) {
    x->data[ii->data[i9] - 1] = 1.0;
  }

  emxInit_real_T1(sp, &c_x, 1, &u_emlrtRTEI, true);
  i9 = c_x->size[0];
  c_x->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_x, i9, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  nx = x->size[0];
  for (i9 = 0; i9 < nx; i9++) {
    c_x->data[i9] = 3.1415926535897931 * x->data[i9];
  }

  emxInit_real_T1(sp, &r12, 1, &u_emlrtRTEI, true);
  st.site = &jc_emlrtRSI;
  b_st.site = &nc_emlrtRSI;
  i9 = r12->size[0];
  r12->size[0] = c_x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)r12, i9, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  nx = c_x->size[0];
  for (i9 = 0; i9 < nx; i9++) {
    r12->data[i9] = c_x->data[i9];
  }

  c_st.site = &eb_emlrtRSI;
  overflow = ((!(1 > c_x->size[0])) && (c_x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  for (b_ii = 0; b_ii + 1 <= c_x->size[0]; b_ii++) {
    r12->data[b_ii] = muDoubleScalarSin(r12->data[b_ii]);
  }

  emxFree_real_T(&c_x);
  emxInit_real_T1(&b_st, &r13, 1, &u_emlrtRTEI, true);
  i9 = r13->size[0];
  r13->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r13, i9, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  nx = x->size[0];
  for (i9 = 0; i9 < nx; i9++) {
    r13->data[i9] = 3.1415926535897931 * x->data[i9];
  }

  st.site = &jc_emlrtRSI;
  rdivide(&st, r12, r13, y);
  b_ii = y->size[0];
  i9 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i9, (int32_T)sizeof(int32_T),
                    &u_emlrtRTEI);
  nx = i->size[0];
  emxFree_real_T(&r13);
  emxFree_real_T(&r12);
  for (i9 = 0; i9 < nx; i9++) {
    idx = (int32_T)i->data[i9];
    if (!((idx >= 1) && (idx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, b_ii, &cc_emlrtBCI, sp);
    }

    ii->data[i9] = idx;
  }

  emxFree_real_T(&i);
  nx = ii->size[0];
  for (i9 = 0; i9 < nx; i9++) {
    y->data[ii->data[i9] - 1] = 1.0;
  }

  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sinc.c) */
