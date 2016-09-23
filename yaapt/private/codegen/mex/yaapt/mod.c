/*
 * mod.c
 *
 * Code generation for function 'mod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mod.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
real_T b_mod(real_T x)
{
  return x - muDoubleScalarFloor(x / 2.0) * 2.0;
}

/* End of code generation (mod.c) */
