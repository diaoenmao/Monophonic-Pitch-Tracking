/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * spec_trk.h
 *
 * Code generation for function 'spec_trk'
 *
 */

#ifndef __SPEC_TRK_H__
#define __SPEC_TRK_H__

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
extern void spec_trk(yaaptStackData *SD, const emlrtStack *sp, emxArray_real_T
                     *Data, real_T Fs, const emxArray_boolean_T *VUVEnergy,
                     emxArray_real_T *SPitch, emxArray_real_T *VUVSPitch, real_T
                     pAvg_data[], int32_T pAvg_size[1], real_T pStd_data[],
                     int32_T pStd_size[1]);

#endif

/* End of code generation (spec_trk.h) */
