/*
 * cmp_rate.h
 *
 * Code generation for function 'cmp_rate'
 *
 */

#ifndef __CMP_RATE_H__
#define __CMP_RATE_H__

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
extern void cmp_rate(const emlrtStack *sp, const emxArray_real_T *Phi, real_T Fs,
                     real_T lag_min, real_T lag_max, real_T Pitch_data[],
                     int32_T Pitch_size[2], real_T Merit_data[], int32_T
                     Merit_size[2]);

#endif

/* End of code generation (cmp_rate.h) */
