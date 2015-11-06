/*
 * sin.c
 *
 * Code generation for function 'sin'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sin.h"

/* Function Definitions */

/*
 *
 */
void b_sin(real_T x[5776])
{
  int32_T k;
  for (k = 0; k < 5776; k++) {
    x[k] = muDoubleScalarSin(x[k]);
  }
}

/* End of code generation (sin.c) */
