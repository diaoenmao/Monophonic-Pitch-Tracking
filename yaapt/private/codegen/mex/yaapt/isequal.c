/*
 * isequal.c
 *
 * Code generation for function 'isequal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "isequal.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
boolean_T b_isequal(const emxArray_real_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  int32_T i21;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (1 + k <= 1) {
        i21 = varargin_1->size[k];
      } else {
        i21 = 1;
      }

      if (i21 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

/*
 *
 */
boolean_T c_isequal(const emxArray_real_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  int32_T i22;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      i22 = varargin_1->size[k];
      if (i22 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

/*
 *
 */
boolean_T d_isequal(const emxArray_real_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  int32_T i23;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      i23 = varargin_1->size[k];
      if (i23 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

/*
 *
 */
boolean_T e_isequal(const emxArray_boolean_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  int32_T i26;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (1 + k <= 1) {
        i26 = varargin_1->size[k];
      } else {
        i26 = 1;
      }

      if (i26 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

/*
 *
 */
boolean_T isequal(const real_T varargin_1[2], const real_T varargin_2[2])
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
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

  return p;
}

/* End of code generation (isequal.c) */
