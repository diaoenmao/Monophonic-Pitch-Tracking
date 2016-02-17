/*
 * tm_trk.h
 *
 * Code generation for function 'tm_trk'
 *
 */

#ifndef __TM_TRK_H__
#define __TM_TRK_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void tm_trk(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs,
                   const emxArray_real_T *SPitch, const emxArray_real_T *pStd,
                   real_T Prm_frame_length, real_T Prm_frame_space, real_T
                   Prm_f0_min, real_T Prm_f0_max, real_T Prm_nccf_thresh1,
                   real_T Prm_nccf_thresh2, real_T Prm_nccf_maxcands, real_T
                   Prm_nccf_pwidth, real_T Prm_merit_boost, emxArray_real_T
                   *Pitch, emxArray_real_T *Merit);

#endif

/* End of code generation (tm_trk.h) */
