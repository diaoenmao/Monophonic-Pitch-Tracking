/*
 * File: peaks.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
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
extern void peaks(emxArray_real_T *Data, double delta, double maxpeaks, double
                  Prm_f0_min, double Prm_f0_max, double Prm_shc_pwidth, double
                  Prm_shc_thresh1, double Prm_shc_thresh2, double Prm_f0_double,
                  double Prm_f0_half, double Prm_merit_extra, emxArray_real_T
                  *Pitch, emxArray_real_T *Merit);

#endif

/*
 * File trailer for peaks.h
 *
 * [EOF]
 */
