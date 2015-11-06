/*
 * cos.c
 *
 * Code generation for function 'cos'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cos.h"

/* Function Definitions */

/*
 *
 */
void b_cos(real_T x[75])
{
  int32_T k;
  for (k = 0; k < 75; k++) {
    x[k] = muDoubleScalarCos(x[k]);
  }
}

/* End of code generation (cos.c) */
