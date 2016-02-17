/*
 * File: nonlinear.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

#ifndef __NONLINEAR_H__
#define __NONLINEAR_H__

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
