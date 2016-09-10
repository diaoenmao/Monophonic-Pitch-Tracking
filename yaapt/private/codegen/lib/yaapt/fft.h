/*
 * File: fft.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

#ifndef FFT_H
#define FFT_H

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
extern void b_fft(const emxArray_real_T *x, double varargin_1, emxArray_creal_T *
                  y);
extern void fft(const emxArray_creal_T *x, double varargin_1, emxArray_creal_T
                *y);

#endif

/*
 * File trailer for fft.h
 *
 * [EOF]
 */
