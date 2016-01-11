/*
 * _coder_yaapt_mex.c
 *
 * Code generation for function '_coder_yaapt_mex'
 *
 */

/* Include files */
#include "yaapt.h"
#include "_coder_yaapt_mex.h"
#include "yaapt_terminate.h"
#include "_coder_yaapt_api.h"
#include "yaapt_initialize.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static yaaptStackData *yaaptStackDataGlobal = NULL;

/* Function Declarations */
static void yaapt_mexFunction(yaaptStackData *SD, int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void yaapt_mexFunction(yaaptStackData *SD, int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4, 5,
                        "yaapt");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "yaapt");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  yaapt_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  yaapt_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  yaaptStackDataGlobal = (yaaptStackData *)mxCalloc(1, 1U * sizeof
    (yaaptStackData));
  mexAtExit(yaapt_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  yaapt_initialize();

  /* Dispatch the entry-point. */
  yaapt_mexFunction(yaaptStackDataGlobal, nlhs, plhs, nrhs, prhs);
  mxFree(yaaptStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_yaapt_mex.c) */
