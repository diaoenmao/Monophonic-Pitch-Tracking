/*
 * eml_error.c
 *
 * Code generation for function 'eml_error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "eml_error.h"

/* Variable Definitions */
static emlrtRTEInfo pd_emlrtRTEI = { 20, 5, "eml_error",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_error.m" };

/* Function Definitions */

/*
 *
 */
void b_eml_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &pd_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
}

/*
 *
 */
void c_eml_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &pd_emlrtRTEI, "MATLAB:interp1:NaNinX", 0);
}

/*
 *
 */
void d_eml_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &pd_emlrtRTEI,
    "Coder:toolbox:interp1_nonMonotonicX", 0);
}

/*
 *
 */
void e_eml_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &pd_emlrtRTEI,
    "Coder:toolbox:cat_UnsupportedVariableSizeEmpty", 0);
}

/*
 *
 */
void eml_error(const emlrtStack *sp)
{
  static char_T cv8[4][1] = { { 's' }, { 'q' }, { 'r' }, { 't' } };

  emlrtErrorWithMessageIdR2012b(sp, &pd_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, cv8);
}

/* End of code generation (eml_error.c) */
