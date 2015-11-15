/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "lapacke.h"

/* Function Definitions */
void yaapt_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
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
