/*
 * File: yaapt_initialize.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 11-Dec-2015 06:07:48
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_initialize.h"
#include "yaapt_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void yaapt_initialize(void)
{
  rt_InitInfAndNaN(8U);
  omp_init_nest_lock(&emlrtNestLockGlobal);
}

/*
 * File trailer for yaapt_initialize.c
 *
 * [EOF]
 */
