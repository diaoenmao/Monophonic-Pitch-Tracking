/*
 * File: pchip.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Jan-2016 05:43:25
 */

#ifndef __PCHIP_H__
#define __PCHIP_H__

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
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
