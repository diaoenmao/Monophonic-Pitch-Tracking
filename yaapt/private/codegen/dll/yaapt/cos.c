/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: cos.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cos.h"

/* Function Definitions */

/*
 * Arguments    : double x[75]
 * Return Type  : void
 */
void b_cos(double x[75])
{
  int k;
  for (k = 0; k < 75; k++) {
    x[k] = cos(x[k]);
  }
}

/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void c_cos(emxArray_real_T *x)
{
  int nx;
  int k;
  nx = x->size[0];
  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = cos(x->data[k]);
  }
}

/*
 * File trailer for cos.c
 *
 * [EOF]
 */
