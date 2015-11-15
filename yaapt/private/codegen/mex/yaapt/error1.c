/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error1.c
 *
 * Code generation for function 'error1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "error1.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo nd_emlrtRTEI = { 17, 9, "error",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\error.m" };

/* Function Definitions */

/*
 *
 */
void d_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &nd_emlrtRTEI, "MATLAB:nomem", 0);
}

/*
 *
 */
void e_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'g', 'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  emlrtErrorWithMessageIdR2012b(sp, &nd_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, varargin_1, 12, varargin_2);
}

/*
 *
 */
void error(const emlrtStack *sp)
{
  static const char_T varargin_1[4] = { 's', 'q', 'r', 't' };

  emlrtErrorWithMessageIdR2012b(sp, &nd_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, varargin_1);
}

/*
 *
 */
void f_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &nd_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
}

/*
 *
 */
void i_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &nd_emlrtRTEI, "MATLAB:interp1:NaNinX", 0);
}

/*
 *
 */
void j_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &nd_emlrtRTEI,
    "Coder:toolbox:interp1_nonMonotonicX", 0);
}

/*
 *
 */
void k_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &nd_emlrtRTEI,
    "Coder:toolbox:cat_UnsupportedVariableSizeEmpty", 0);
}

/* End of code generation (error1.c) */
