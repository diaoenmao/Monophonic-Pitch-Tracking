/*
 * File: nonlinear.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

#ifndef NONLINEAR_H
#define NONLINEAR_H

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
extern void nonlinear(const emxArray_real_T *DataA, double Fs, double
                      Prm_bp_forder, double Prm_bp_low, double Prm_bp_high,
                      double Prm_dec_factor, emxArray_real_T *DataB,
                      emxArray_real_T *DataC, emxArray_real_T *DataD, double
                      *newFs);

#endif

/*
 * File trailer for nonlinear.h
 *
 * [EOF]
 */
