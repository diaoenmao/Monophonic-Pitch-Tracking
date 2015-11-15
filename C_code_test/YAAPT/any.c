/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: any.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 14-Nov-2015 18:37:50
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "any.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : boolean_T
 */
boolean_T any(const emxArray_real_T *x)
{
  boolean_T y;
  int ix;
  boolean_T exitg1;
  boolean_T b0;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x->size[0])) {
    if ((x->data[ix] == 0.0) || rtIsNaN(x->data[ix])) {
      b0 = true;
    } else {
      b0 = false;
    }

    if (!b0) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

/*
 * Arguments    : const emxArray_boolean_T *x
 * Return Type  : boolean_T
 */
boolean_T b_any(const emxArray_boolean_T *x)
{
  boolean_T y;
  int ix;
  boolean_T exitg1;
  boolean_T b1;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x->size[0])) {
    b1 = !x->data[ix - 1];
    if (!b1) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

/*
 * File trailer for any.c
 *
 * [EOF]
 */
