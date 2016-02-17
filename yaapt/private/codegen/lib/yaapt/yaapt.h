/*
 * File: yaapt.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

#ifndef __YAAPT_H__
#define __YAAPT_H__

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
extern void yaapt(const emxArray_real_T *Data, double Fs, const double
                  Parameter[33], emxArray_real_T *Pitch, double *numfrms, double
                  *frmrate);

#endif

/*
 * File trailer for yaapt.h
 *
 * [EOF]
 */
