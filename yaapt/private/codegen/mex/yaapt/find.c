/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void eml_find(const emlrtStack *sp, const boolean_T x[5776], int32_T i_data[],
              int32_T i_size[1])
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv10[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 5777)) {
    guard1 = false;
    if (x[ii - 1]) {
      idx++;
      i_data[idx - 1] = ii;
      if (idx >= 5776) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  iv10[0] = 1;
  iv10[1] = idx;
  st.site = &ab_emlrtRSI;
  indexShapeCheck(&st, 5776, iv10);
  i_size[0] = idx;
}

/* End of code generation (find.c) */
