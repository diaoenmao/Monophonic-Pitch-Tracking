/*
 * File: cmp_rate.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

#ifndef __CMP_RATE_H__
#define __CMP_RATE_H__

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
extern void cmp_rate(const emxArray_real_T *Phi, double Fs, double maxcands,
                     double lag_min, double lag_max, double Prm_nccf_thresh1,
                     double Prm_nccf_thresh2, double Prm_nccf_pwidth,
                     emxArray_real_T *Pitch, emxArray_real_T *Merit);

#endif

/*
 * File trailer for cmp_rate.h
 *
 * [EOF]
 */
