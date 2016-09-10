/*
 * peaks.h
 *
 * Code generation for function 'peaks'
 *
 */

#ifndef PEAKS_H
#define PEAKS_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void peaks(const emlrtStack *sp, emxArray_real_T *Data, real_T delta,
                  real_T maxpeaks, real_T Prm_f0_min, real_T Prm_f0_max, real_T
                  Prm_shc_pwidth, real_T Prm_shc_thresh1, real_T Prm_shc_thresh2,
                  real_T Prm_f0_double, real_T Prm_f0_half, real_T
                  Prm_merit_extra, emxArray_real_T *Pitch, emxArray_real_T
                  *Merit);

#endif

/* End of code generation (peaks.h) */
