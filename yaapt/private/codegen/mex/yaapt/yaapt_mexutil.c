/*
 * yaapt_mexutil.c
 *
 * Code generation for function 'yaapt_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_mexutil.h"
#include "lapacke.h"

/* Function Definitions */
int32_T asr_s32(int32_T u, uint32_T n)
{
  int32_T y;
  if (u >= 0) {
    y = (int32_T)((uint32_T)u >> n);
  } else {
    y = -(int32_T)((uint32_T)-(u + 1) >> n) - 1;
  }

  return y;
}

const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m10;
  y = NULL;
  m10 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m10);
  return y;
}

void m_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

/* End of code generation (yaapt_mexutil.c) */
