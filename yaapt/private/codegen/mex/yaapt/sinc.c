/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sinc.c
 *
 * Code generation for function 'sinc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sinc.h"
#include "rdivide.h"
#include "sin.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 24, "sinc",
  "F:\\MATLAB\\toolbox\\signal\\signal\\sinc.m" };

static emlrtBCInfo pb_emlrtBCI = { 1, 5776, 25, 1, "", "sinc",
  "F:\\MATLAB\\toolbox\\signal\\signal\\sinc.m", 0 };

/* Function Definitions */

/*
 *
 */
void b_sinc(const emlrtStack *sp, real_T x[5776], real_T y[5776])
{
  boolean_T b_x[5776];
  int32_T i4;
  int32_T ii_size[1];
  int32_T ii_data[5776];
  int32_T loop_ub;
  int32_T i_data[5776];
  int32_T i5;
  real_T dv4[5776];
  real_T dv5[5776];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i4 = 0; i4 < 5776; i4++) {
    b_x[i4] = (x[i4] == 0.0);
  }

  b_st.site = &y_emlrtRSI;
  eml_find(&b_st, b_x, ii_data, ii_size);
  loop_ub = ii_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    i_data[i4] = ii_data[i4];
  }

  loop_ub = ii_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    i5 = i_data[i4];
    if (!((i5 >= 1) && (i5 <= 5776))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, 5776, &pb_emlrtBCI, sp);
    }

    ii_data[i4] = i5;
  }

  loop_ub = ii_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    x[ii_data[i4] - 1] = 1.0;
  }

  for (i4 = 0; i4 < 5776; i4++) {
    dv4[i4] = 3.1415926535897931 * x[i4];
  }

  b_sin(dv4);
  for (i4 = 0; i4 < 5776; i4++) {
    dv5[i4] = 3.1415926535897931 * x[i4];
  }

  b_rdivide(dv4, dv5, y);
  loop_ub = ii_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    ii_data[i4] = i_data[i4];
  }

  loop_ub = ii_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    y[ii_data[i4] - 1] = 1.0;
  }
}

/*
 *
 */
void sinc(const emlrtStack *sp, real_T x[75], real_T y[75])
{
  int32_T idx;
  int8_T ii_data[75];
  int32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T loop_ub;
  int32_T iv9[2];
  int8_T i_data[75];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &y_emlrtRSI;
  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 76)) {
    guard1 = false;
    if (x[ii - 1] == 0.0) {
      idx++;
      ii_data[idx - 1] = (int8_T)ii;
      if (idx >= 75) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (1 > idx) {
    loop_ub = 0;
  } else {
    loop_ub = idx;
  }

  iv9[0] = 1;
  iv9[1] = loop_ub;
  c_st.site = &ab_emlrtRSI;
  indexShapeCheck(&c_st, 75, iv9);
  for (idx = 0; idx < loop_ub; idx++) {
    i_data[idx] = ii_data[idx];
  }

  for (idx = 0; idx < loop_ub; idx++) {
    ii = i_data[idx];
    ii_data[idx] = (int8_T)ii;
  }

  for (idx = 0; idx < loop_ub; idx++) {
    x[ii_data[idx] - 1] = 1.0;
  }

  for (idx = 0; idx < 75; idx++) {
    y[idx] = muDoubleScalarSin(3.1415926535897931 * x[idx]) /
      (3.1415926535897931 * x[idx]);
  }

  for (idx = 0; idx < loop_ub; idx++) {
    ii_data[idx] = i_data[idx];
  }

  for (idx = 0; idx < loop_ub; idx++) {
    y[ii_data[idx] - 1] = 1.0;
  }
}

/* End of code generation (sinc.c) */
