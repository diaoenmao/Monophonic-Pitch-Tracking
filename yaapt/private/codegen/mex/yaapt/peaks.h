/*
 * peaks.h
 *
 * Code generation for function 'peaks'
 *
 */

#ifndef __PEAKS_H__
#define __PEAKS_H__

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
extern void peaks(const emlrtStack *sp, emxArray_real_T *Data, real_T delta,
                  real_T Pitch_data[], int32_T Pitch_size[2], real_T Merit_data[],
                  int32_T Merit_size[2]);

#endif

/* End of code generation (peaks.h) */
