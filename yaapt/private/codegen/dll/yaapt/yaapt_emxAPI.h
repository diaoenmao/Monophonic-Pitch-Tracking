/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: yaapt_emxAPI.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
 */

#ifndef __YAAPT_EMXAPI_H__
#define __YAAPT_EMXAPI_H__

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
#ifdef __cplusplus

extern "C" {

#endif

  extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
  extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
    numDimensions, int *size);
  extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int
    cols);
  extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
  extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
  extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for yaapt_emxAPI.h
 *
 * [EOF]
 */
