/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mod.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mod.h"

/* Function Definitions */

/*
 * Arguments    : double x
 * Return Type  : double
 */
double b_mod(double x)
{
  return x - floor(x / 2.0) * 2.0;
}

/*
 * File trailer for mod.c
 *
 * [EOF]
 */
