/*
 * fix.c
 *
 * Code generation for function 'fix'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "fix.h"

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

/*
 *
 */
void c_fix(emxArray_real_T *x)
{
  int32_T i43;
  int32_T k;
  real_T b_x;
  i43 = x->size[0];
  for (k = 0; k < i43; k++) {
    if (x->data[k] < 0.0) {
      b_x = muDoubleScalarCeil(x->data[k]);
    } else {
      b_x = muDoubleScalarFloor(x->data[k]);
    }

    x->data[k] = b_x;
  }
}

/* End of code generation (fix.c) */
