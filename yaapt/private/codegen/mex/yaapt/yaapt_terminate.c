/*
 * yaapt_terminate.c
 *
 * Code generation for function 'yaapt_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_terminate.h"
#include "_coder_yaapt_mex.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
void yaapt_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void yaapt_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (yaapt_terminate.c) */
