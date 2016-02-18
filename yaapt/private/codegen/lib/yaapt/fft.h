/*
 * File: fft.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

#ifndef __FFT_H__
#define __FFT_H__

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
