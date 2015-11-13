/*
 * File: fft.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

#ifndef __FFT_H__
#define __FFT_H__

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
#ifdef __cplusplus

extern "C" {

#endif

  extern void fft(const emxArray_real_T *x, creal_T y[8192]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for fft.h
 *
 * [EOF]
 */
