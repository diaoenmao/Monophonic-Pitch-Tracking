/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Add_api.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 14-Nov-2015 18:45:41
 */

#ifndef ___CODER_ADD_API_H__
#define ___CODER_ADD_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_Add_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void Add(emxArray_real_T *arr, real_T b, emxArray_real_T *out);
extern void Add_api(const mxArray *prhs[2], const mxArray *plhs[1]);
extern void Add_atexit(void);
extern void Add_initialize(void);
extern void Add_terminate(void);
extern void Add_xil_terminate(void);

#endif

/*
 * File trailer for _coder_Add_api.h
 *
 * [EOF]
 */
