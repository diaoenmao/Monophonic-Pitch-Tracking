/*
 * yaapt_initialize.c
 *
 * Code generation for function 'yaapt_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_initialize.h"
#include "_coder_yaapt_mex.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Function Definitions */
void yaapt_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (yaapt_initialize.c) */
