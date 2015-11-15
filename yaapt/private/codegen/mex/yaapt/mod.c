/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mod.c
 *
 * Code generation for function 'mod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mod.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
real_T b_mod(real_T x)
{
  return x - muDoubleScalarFloor(x / 2.0) * 2.0;
}

/* End of code generation (mod.c) */
