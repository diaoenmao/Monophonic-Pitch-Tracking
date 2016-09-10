/*
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "eml_int_forloop_overflow_check.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo nf_emlrtRTEI = { 86, 15, "eml_int_forloop_overflow_check",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

/* Function Definitions */

/*
 *
 */
void check_forloop_overflow_error(const emlrtStack *sp, boolean_T overflow)
{
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &nf_emlrtRTEI,
      "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
