/*
 * Add_initialize.c
 *
 * Code generation for function 'Add_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Add.h"
#include "Add_initialize.h"
#include "Add_data.h"

/* Function Definitions */
void Add_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (Add_initialize.c) */
