/*
 * File: yaapt.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

#ifndef YAAPT_H
#define YAAPT_H

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
extern void yaapt(const emxArray_real_T *Data, double Fs, const double
                  Parameter[34], emxArray_real_T *Pitch, double *numfrms, double
                  *frmrate);

#endif

/*
 * File trailer for yaapt.h
 *
 * [EOF]
 */
