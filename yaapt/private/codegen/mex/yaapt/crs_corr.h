/*
 * crs_corr.h
 *
 * Code generation for function 'crs_corr'
 *
 */

#ifndef __CRS_CORR_H__
#define __CRS_CORR_H__

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
extern void crs_corr(const emlrtStack *sp, emxArray_real_T *Data, real_T lag_min,
                     real_T lag_max, emxArray_real_T *Phi);

#endif

/* End of code generation (crs_corr.h) */
