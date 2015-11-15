/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sqrt.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:14:51
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sqrt.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void b_sqrt(emxArray_real_T *x)
{
  int nx;
  int k;
  nx = x->size[0];
  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = sqrt(x->data[k]);
  }
}

/*
 * File trailer for sqrt.c
 *
 * [EOF]
 */
