/*
 * File: dynamic.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 26-Oct-2015 23:41:06
 */

#ifndef __DYNAMIC_H__
#define __DYNAMIC_H__

/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void dynamic(const emxArray_real_T *Pitch, const emxArray_real_T *Merit,
                    const emxArray_real_T *Energy, emxArray_real_T *FinPitch);
extern void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);

#endif

/*
 * File trailer for dynamic.h
 *
 * [EOF]
 */
