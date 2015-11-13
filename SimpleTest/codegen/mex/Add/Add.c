/*
 * Add.c
 *
 * Code generation for function 'Add'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Add.h"
#include "Add_emxutil.h"
#include "Add_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 16, "Add",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\Add.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 4, 5, "out", "Add",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\Add.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 4, 14, "arr", "Add",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\Add.m", 0 };

/* Function Definitions */
void Add(const emlrtStack *sp, const emxArray_real_T *arr, real_T b,
         emxArray_real_T *out)
{
  int32_T i0;
  int32_T loop_ub;
  int32_T i1;
  i0 = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = arr->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)out, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = arr->size[0] * arr->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    out->data[i0] = arr->data[i0];
  }

  loop_ub = 1;
  while (loop_ub - 1 <= arr->size[1] - 1) {
    i0 = out->size[1];
    i1 = arr->size[1];
    out->data[emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i0, &emlrtBCI, sp) -
      1] = arr->data[emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i1,
      &b_emlrtBCI, sp) - 1] + b;
    loop_ub++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }
}

/* End of code generation (Add.c) */
