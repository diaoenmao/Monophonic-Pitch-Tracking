/*
 * _coder_yaapt_mex.c
 *
 * Code generation for function 'yaapt'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_yaapt_api.h"
#include "yaapt_initialize.h"
#include "yaapt_terminate.h"

/* Function Declarations */
static void yaapt_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "yaapt", NULL, false, {585839548U,4280471661U,1452683995U,3644522327U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void yaapt_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[3];
  const mxArray *inputs[2];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  yaaptStackData* yaaptStackDataLocal = (yaaptStackData*)mxCalloc(1,sizeof(yaaptStackData));
  /* Module initialization. */
  yaapt_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 2, mxCHAR_CLASS, 5, "yaapt");
  } else if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 5, "yaapt");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  yaapt_api(yaaptStackDataLocal, inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  yaapt_terminate();
  mxFree(yaaptStackDataLocal);
}

void yaapt_atexit_wrapper(void)
{
   yaapt_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(yaapt_atexit_wrapper);
  /* Dispatch the entry-point. */
  yaapt_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_yaapt_mex.c) */
