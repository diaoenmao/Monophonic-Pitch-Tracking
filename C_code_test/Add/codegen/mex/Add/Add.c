/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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

static emlrtBCInfo emlrtBCI = { -1, -1, 4, 14, "arr", "Add",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\Add.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 4, 5, "out", "Add",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\Add.m", 0 };

/* Function Definitions */
void Add(const emlrtStack *sp, const emxArray_real_T *arr, real_T b,
         emxArray_real_T *out)
{
  int32_T i0;
  int32_T loop_ub;
  int32_T i;
  i0 = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = arr->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)out, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = arr->size[0] * arr->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    out->data[i0] = arr->data[i0];
  }

  i = 1;
  while (i - 1 <= arr->size[1] - 1) {
    i0 = arr->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &emlrtBCI, sp);
    }

    i0 = out->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &b_emlrtBCI, sp);
    }

    out->data[i - 1] = arr->data[i - 1] + b;
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (Add.c) */
