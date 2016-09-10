/*
 * File: tm_trk.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

#ifndef TM_TRK_H
#define TM_TRK_H

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
extern void tm_trk(const emxArray_real_T *Data, double Fs, const emxArray_real_T
                   *SPitch, const double pStd_data[], const int pStd_size[1],
                   double Prm_frame_length, double Prm_frame_space, double
                   Prm_f0_min, double Prm_f0_max, double Prm_nccf_thresh1,
                   double Prm_nccf_thresh2, double Prm_nccf_maxcands, double
                   Prm_nccf_pwidth, double Prm_merit_boost, emxArray_real_T
                   *Pitch, emxArray_real_T *Merit);

#endif

/*
 * File trailer for tm_trk.h
 *
 * [EOF]
 */
