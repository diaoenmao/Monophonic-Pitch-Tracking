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
#include "indexShapeCheck.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 24, "sinc",
  "F:\\MATLAB\\toolbox\\signal\\signal\\sinc.m" };

static emlrtRTEInfo e_emlrtRTEI = { 1, 12, "sinc",
  "F:\\MATLAB\\toolbox\\signal\\signal\\sinc.m" };

static emlrtRTEInfo g_emlrtRTEI = { 24, 1, "sinc",
  "F:\\MATLAB\\toolbox\\signal\\signal\\sinc.m" };

/* Function Definitions */

/*
 *
 */
void b_sinc(const emlrtStack *sp, real_T x[5776], real_T y[5776])
{
  emxArray_int32_T *ii;
  int32_T idx;
  int32_T i4;
  int32_T b_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *i;
  int32_T iv7[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &ii, 1, &h_emlrtRTEI, true);
  st.site = &ob_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  idx = 0;
  i4 = ii->size[0];
  ii->size[0] = 5776;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i4, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 5777)) {
    guard1 = false;
    if (x[b_ii - 1] == 0.0) {
      idx++;
      ii->data[idx - 1] = b_ii;
      if (idx >= 5776) {
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

  if (1 > idx) {
    i4 = 0;
  } else {
    i4 = idx;
  }

  emxInit_real_T1(&b_st, &i, 1, &g_emlrtRTEI, true);
  iv7[0] = 1;
  iv7[1] = i4;
  c_st.site = &qb_emlrtRSI;
  indexShapeCheck(&c_st, 5776, iv7);
  b_ii = ii->size[0];
  ii->size[0] = i4;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, b_ii, (int32_T)sizeof(int32_T),
                    &f_emlrtRTEI);
  i4 = i->size[0];
  i->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)i, i4, (int32_T)sizeof(real_T),
                    &e_emlrtRTEI);
  b_ii = ii->size[0];
  for (i4 = 0; i4 < b_ii; i4++) {
    i->data[i4] = ii->data[i4];
  }

  i4 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i4, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  b_ii = i->size[0];
  for (i4 = 0; i4 < b_ii; i4++) {
    ii->data[i4] = (int32_T)i->data[i4];
  }

  b_ii = ii->size[0];
  for (i4 = 0; i4 < b_ii; i4++) {
    x[ii->data[i4] - 1] = 1.0;
  }

  for (b_ii = 0; b_ii < 5776; b_ii++) {
    y[b_ii] = muDoubleScalarSin(3.1415926535897931 * x[b_ii]) /
      (3.1415926535897931 * x[b_ii]);
  }

  i4 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i4, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  b_ii = i->size[0];
  for (i4 = 0; i4 < b_ii; i4++) {
    ii->data[i4] = (int32_T)i->data[i4];
  }

  emxFree_real_T(&i);
  b_ii = ii->size[0];
  for (i4 = 0; i4 < b_ii; i4++) {
    y[ii->data[i4] - 1] = 1.0;
  }

  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void sinc(const emlrtStack *sp, real_T x[75], real_T y[75])
{
  emxArray_int32_T *ii;
  int32_T idx;
  int32_T i3;
  int32_T k;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *i;
  int32_T iv6[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &ii, 1, &h_emlrtRTEI, true);
  st.site = &ob_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  idx = 0;
  i3 = ii->size[0];
  ii->size[0] = 75;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i3, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k < 76)) {
    guard1 = false;
    if (x[k - 1] == 0.0) {
      idx++;
      ii->data[idx - 1] = k;
      if (idx >= 75) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      k++;
    }
  }

  if (1 > idx) {
    i3 = 0;
  } else {
    i3 = idx;
  }

  emxInit_real_T1(&b_st, &i, 1, &g_emlrtRTEI, true);
  iv6[0] = 1;
  iv6[1] = i3;
  c_st.site = &qb_emlrtRSI;
  indexShapeCheck(&c_st, 75, iv6);
  k = ii->size[0];
  ii->size[0] = i3;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, k, (int32_T)sizeof(int32_T),
                    &f_emlrtRTEI);
  i3 = i->size[0];
  i->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)i, i3, (int32_T)sizeof(real_T),
                    &e_emlrtRTEI);
  k = ii->size[0];
  for (i3 = 0; i3 < k; i3++) {
    i->data[i3] = ii->data[i3];
  }

  i3 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i3, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  k = i->size[0];
  for (i3 = 0; i3 < k; i3++) {
    ii->data[i3] = (int32_T)i->data[i3];
  }

  k = ii->size[0];
  for (i3 = 0; i3 < k; i3++) {
    x[ii->data[i3] - 1] = 1.0;
  }

  for (k = 0; k < 75; k++) {
    y[k] = muDoubleScalarSin(3.1415926535897931 * x[k]) / (3.1415926535897931 *
      x[k]);
  }

  i3 = ii->size[0];
  ii->size[0] = i->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i3, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  k = i->size[0];
  for (i3 = 0; i3 < k; i3++) {
    ii->data[i3] = (int32_T)i->data[i3];
  }

  emxFree_real_T(&i);
  k = ii->size[0];
  for (i3 = 0; i3 < k; i3++) {
    y[ii->data[i3] - 1] = 1.0;
  }

  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sinc.c) */
