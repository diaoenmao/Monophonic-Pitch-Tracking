/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * yaapt_mexutil.h
 *
 * Code generation for function 'yaapt_mexutil'
 *
 */

#ifndef __YAAPT_MEXUTIL_H__
#define __YAAPT_MEXUTIL_H__

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
extern int32_T asr_s32(int32_T u, uint32_T n);
extern int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
extern emlrtCTX emlrtGetRootTLSGlobal(void);
extern void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX
  aTLS, void *aData);
extern const mxArray *emlrt_marshallOut(const real_T u);
extern void m_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

#endif

/* End of code generation (yaapt_mexutil.h) */
