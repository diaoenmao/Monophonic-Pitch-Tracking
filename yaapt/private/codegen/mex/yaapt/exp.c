/*
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "exp.h"

/* Function Definitions */

/*
 *
 */
void b_exp(emxArray_real_T *x)
{
  int32_T i44;
  int32_T k;
  i44 = x->size[0];
  for (k = 0; k < i44; k++) {
    x->data[k] = muDoubleScalarExp(x->data[k]);
  }
}

/* End of code generation (exp.c) */
