/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "diff.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void diff(const real_T x[6], real_T y[5])
{
  int32_T ixLead;
  int32_T iyLead;
  real_T work;
  int32_T m;
  real_T tmp2;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 5; m++) {
    tmp2 = work;
    work = x[ixLead];
    tmp2 = x[ixLead] - tmp2;
    ixLead++;
    y[iyLead] = tmp2;
    iyLead++;
  }
}

/* End of code generation (diff.c) */
