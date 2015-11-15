/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: peaks.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:14:51
 */

#ifndef __PEAKS_H__
#define __PEAKS_H__

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
extern void peaks(emxArray_real_T *Data, double delta, double Pitch_data[], int
                  Pitch_size[2], double Merit_data[], int Merit_size[2]);

#endif

/*
 * File trailer for peaks.h
 *
 * [EOF]
 */
