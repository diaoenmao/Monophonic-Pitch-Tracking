/*
 * File: nlfer.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

#ifndef __NLFER_H__
#define __NLFER_H__

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
extern void nlfer(const emxArray_real_T *Data, double Fs, double
                  Prm_frame_length, double Prm_frame_space, double Prm_f0_min,
                  double Prm_f0_max, double Prm_fft_length, double
                  Prm_nlfer_thresh1, emxArray_real_T *Energy, emxArray_boolean_T
                  *VUVEnergy);

#endif

/*
 * File trailer for nlfer.h
 *
 * [EOF]
 */
