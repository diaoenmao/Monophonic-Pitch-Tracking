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
#include "rdivide.h"
#include "sin.h"

/* Function Definitions */

/*
 *
 */
void b_sinc(real_T x[5776], real_T y[5776])
{
  int32_T idx;
  int16_T ii_data[5776];
  int32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int16_T b_ii_data[5776];
  int16_T i_data[5776];
  real_T dv9[5776];
  real_T dv10[5776];
  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 5777)) {
    guard1 = false;
    if (x[ii - 1] == 0.0) {
      idx++;
      ii_data[idx - 1] = (int16_T)ii;
      if (idx >= 5776) {
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
    idx = 0;
  }

  for (ii = 0; ii < idx; ii++) {
    b_ii_data[ii] = ii_data[ii];
  }

  for (ii = 0; ii < idx; ii++) {
    ii_data[ii] = b_ii_data[ii];
  }

  for (ii = 0; ii < idx; ii++) {
    i_data[ii] = ii_data[ii];
  }

  for (ii = 0; ii < idx; ii++) {
    ii_data[ii] = i_data[ii];
  }

  for (ii = 0; ii < idx; ii++) {
    x[ii_data[ii] - 1] = 1.0;
  }

  for (ii = 0; ii < 5776; ii++) {
    dv9[ii] = 3.1415926535897931 * x[ii];
  }

  b_sin(dv9);
  for (ii = 0; ii < 5776; ii++) {
    dv10[ii] = 3.1415926535897931 * x[ii];
  }

  b_rdivide(dv9, dv10, y);
  for (ii = 0; ii < idx; ii++) {
    ii_data[ii] = i_data[ii];
  }

  for (ii = 0; ii < idx; ii++) {
    y[ii_data[ii] - 1] = 1.0;
  }
}

/*
 *
 */
void sinc(real_T x[75], real_T y[75])
{
  int32_T idx;
  int8_T ii_data[75];
  int32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int8_T b_ii_data[75];
  int8_T i_data[75];
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
    ii = 0;
  } else {
    ii = idx;
  }

  for (idx = 0; idx < ii; idx++) {
    b_ii_data[idx] = ii_data[idx];
  }

  for (idx = 0; idx < ii; idx++) {
    ii_data[idx] = b_ii_data[idx];
  }

  for (idx = 0; idx < ii; idx++) {
    i_data[idx] = ii_data[idx];
  }

  for (idx = 0; idx < ii; idx++) {
    ii_data[idx] = i_data[idx];
  }

  for (idx = 0; idx < ii; idx++) {
    x[ii_data[idx] - 1] = 1.0;
  }

  for (idx = 0; idx < 75; idx++) {
    y[idx] = muDoubleScalarSin(3.1415926535897931 * x[idx]) /
      (3.1415926535897931 * x[idx]);
  }

  for (idx = 0; idx < ii; idx++) {
    ii_data[idx] = i_data[idx];
  }

  for (idx = 0; idx < ii; idx++) {
    y[ii_data[idx] - 1] = 1.0;
  }
}

/* End of code generation (sinc.c) */
