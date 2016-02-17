/*
 * File: yaapt_terminate.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_terminate.h"
#include "yaapt_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void yaapt_terminate(void)
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

/*
 * File trailer for yaapt_terminate.c
 *
 * [EOF]
 */
