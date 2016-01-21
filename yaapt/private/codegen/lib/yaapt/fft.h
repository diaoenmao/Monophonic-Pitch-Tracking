/*
 * File: fft.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Jan-2016 05:43:25
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
extern void fft(const emxArray_real_T *x, creal_T y[8192]);

#endif

/*
 * File trailer for fft.h
 *
 * [EOF]
 */
