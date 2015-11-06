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
extern void tm_trk(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs,
                   const emxArray_real_T *SPitch, const real_T pStd_data[],
                   const int32_T pStd_size[1], emxArray_real_T *Pitch,
                   emxArray_real_T *Merit);

#endif

/* End of code generation (tm_trk.h) */
