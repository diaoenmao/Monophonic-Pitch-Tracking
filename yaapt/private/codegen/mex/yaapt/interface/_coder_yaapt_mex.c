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
static jmp_buf emlrtJBEnviron;

/* Function Declarations */
static void yaapt_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[3]);

/* Function Definitions */
static void yaapt_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 5,
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
  yaapt_api(inputs, outputs);

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
  emlrtStack st = { NULL, NULL, NULL };

  mexAtExit(yaapt_atexit);

  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);

  /* Module initialization. */
  yaapt_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    /* Dispatch the entry-point. */
    yaapt_mexFunction(nlhs, plhs, nrhs, prhs);
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_yaapt_mex.c) */
