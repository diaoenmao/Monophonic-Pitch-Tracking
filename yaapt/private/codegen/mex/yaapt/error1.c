/*
 * error1.c
 *
 * Code generation for function 'error1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "error1.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo ff_emlrtRTEI = { 17, 9, "error",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\error.m" };

/* Function Definitions */
void d_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &ff_emlrtRTEI, "MATLAB:nomem", 0);
}

void e_error(const emlrtStack *sp, int32_T varargin_2)
{
  emlrtErrorWithMessageIdR2012b(sp, &ff_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, "LAPACKE_dgetrf_work", 12,
    varargin_2);
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &ff_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
}

void f_error(const emlrtStack *sp, int32_T varargin_2)
{
  emlrtErrorWithMessageIdR2012b(sp, &ff_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, "LAPACKE_dgeqp3", 12,
    varargin_2);
}

void g_error(const emlrtStack *sp, int32_T varargin_2)
{
  emlrtErrorWithMessageIdR2012b(sp, &ff_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, "LAPACKE_dormqr", 12,
    varargin_2);
}

void h_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &ff_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
}

void l_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &ff_emlrtRTEI,
    "Coder:toolbox:cat_UnsupportedVariableSizeEmpty", 0);
}

void m_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &ff_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "log2");
}

/* End of code generation (error1.c) */
