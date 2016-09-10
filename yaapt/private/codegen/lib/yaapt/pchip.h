/*
 * File: pchip.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

#ifndef PCHIP_H
#define PCHIP_H

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void pchip(const emxArray_real_T *x, const emxArray_real_T *y,
                  emxArray_real_T *v_breaks, emxArray_real_T *v_coefs);

#endif

/*
 * File trailer for pchip.h
 *
 * [EOF]
 */
