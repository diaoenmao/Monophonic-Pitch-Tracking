/*
 * yaapt_mexutil.h
 *
 * Code generation for function 'yaapt_mexutil'
 *
 */

#ifndef YAAPT_MEXUTIL_H
#define YAAPT_MEXUTIL_H

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
extern int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
extern emlrtCTX emlrtGetRootTLSGlobal(void);
extern void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX
  aTLS, void *aData);
extern const mxArray *emlrt_marshallOut(const real_T u);
extern void n_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

#endif

/* End of code generation (yaapt_mexutil.h) */
