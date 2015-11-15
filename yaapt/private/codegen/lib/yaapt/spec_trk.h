/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: spec_trk.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:14:51
 */

#ifndef __SPEC_TRK_H__
#define __SPEC_TRK_H__

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
extern void spec_trk(emxArray_real_T *Data, double Fs, const emxArray_boolean_T *
                     VUVEnergy, emxArray_real_T *SPitch, emxArray_real_T
                     *VUVSPitch, double pAvg_data[], int pAvg_size[1], double
                     pStd_data[], int pStd_size[1]);

#endif

/*
 * File trailer for spec_trk.h
 *
 * [EOF]
 */
