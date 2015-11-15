/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fix.c
 *
 * Code generation for function 'fix'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "fix.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void b_fix(real_T *x)
{
  if (*x < 0.0) {
    *x = muDoubleScalarCeil(*x);
  } else {
    *x = muDoubleScalarFloor(*x);
  }
}

/* End of code generation (fix.c) */
