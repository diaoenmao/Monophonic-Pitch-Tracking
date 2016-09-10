/*
 * spec_trk.h
 *
 * Code generation for function 'spec_trk'
 *
 */

#ifndef SPEC_TRK_H
#define SPEC_TRK_H

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
extern void spec_trk(const emlrtStack *sp, emxArray_real_T *Data, real_T Fs,
                     const emxArray_boolean_T *VUVEnergy, const struct_T *Prm,
                     emxArray_real_T *SPitch, emxArray_real_T *VUVSPitch,
                     emxArray_real_T *pAvg, emxArray_real_T *pStd);

#endif

/* End of code generation (spec_trk.h) */
