/*
 * spec_trk.h
 *
 * Code generation for function 'spec_trk'
 *
 */

#ifndef __SPEC_TRK_H__
#define __SPEC_TRK_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void eml_li_find(const emlrtStack *sp, const emxArray_boolean_T *x,
  emxArray_int32_T *y);
extern void eml_xaxpy(const emlrtStack *sp, int32_T n, real_T a, const
                      emxArray_real_T *x, emxArray_real_T *y, int32_T iy0);
extern void spec_trk(yaaptStackData *SD, const emlrtStack *sp, emxArray_real_T
                     *Data, real_T Fs, const emxArray_boolean_T *VUVEnergy,
                     emxArray_real_T *SPitch, emxArray_real_T *VUVSPitch, real_T
                     pAvg_data[], int32_T pAvg_size[1], real_T pStd_data[],
                     int32_T pStd_size[1]);

#endif

/* End of code generation (spec_trk.h) */
