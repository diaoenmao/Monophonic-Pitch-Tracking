/*
 * File: sinc.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Jan-2016 00:47:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sinc.h"
#include "rdivide.h"
#include "sin.h"

/* Function Definitions */

/*
 * Arguments    : double x[5776]
 *                double y[5776]
 * Return Type  : void
 */
void b_sinc(double x[5776], double y[5776])
{
  int idx;
  short ii_data[5776];
  int ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  short i_data[5776];
  double dv3[5776];
  double dv4[5776];
  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 5777)) {
    guard1 = false;
    if (x[ii - 1] == 0.0) {
      idx++;
      ii_data[idx - 1] = (short)ii;
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
    i_data[ii] = ii_data[ii];
  }

  for (ii = 0; ii < idx; ii++) {
    ii_data[ii] = i_data[ii];
  }

  for (ii = 0; ii < idx; ii++) {
    x[ii_data[ii] - 1] = 1.0;
  }

  for (ii = 0; ii < 5776; ii++) {
    dv3[ii] = 3.1415926535897931 * x[ii];
  }

  b_sin(dv3);
  for (ii = 0; ii < 5776; ii++) {
    dv4[ii] = 3.1415926535897931 * x[ii];
  }

  b_rdivide(dv3, dv4, y);
  for (ii = 0; ii < idx; ii++) {
    ii_data[ii] = i_data[ii];
  }

  for (ii = 0; ii < idx; ii++) {
    y[ii_data[ii] - 1] = 1.0;
  }
}

/*
 * Arguments    : double x[75]
 *                double y[75]
 * Return Type  : void
 */
void sinc(double x[75], double y[75])
{
  int idx;
  signed char ii_data[75];
  int ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  signed char i_data[75];
  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 76)) {
    guard1 = false;
    if (x[ii - 1] == 0.0) {
      idx++;
      ii_data[idx - 1] = (signed char)ii;
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
    i_data[idx] = ii_data[idx];
  }

  for (idx = 0; idx < ii; idx++) {
    ii_data[idx] = i_data[idx];
  }

  for (idx = 0; idx < ii; idx++) {
    x[ii_data[idx] - 1] = 1.0;
  }

  for (idx = 0; idx < 75; idx++) {
    y[idx] = sin(3.1415926535897931 * x[idx]) / (3.1415926535897931 * x[idx]);
  }

  for (idx = 0; idx < ii; idx++) {
    ii_data[idx] = i_data[idx];
  }

  for (idx = 0; idx < ii; idx++) {
    y[ii_data[idx] - 1] = 1.0;
  }
}

/*
 * File trailer for sinc.c
 *
 * [EOF]
 */
