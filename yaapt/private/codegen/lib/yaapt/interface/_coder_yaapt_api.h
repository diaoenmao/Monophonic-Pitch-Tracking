/*
 * File: _coder_yaapt_api.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

#ifndef ___CODER_YAAPT_API_H__
#define ___CODER_YAAPT_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_yaapt_api.h"

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
extern void yaapt(emxArray_real_T *Data, real_T Fs, real_T Parameter[34],
                  emxArray_real_T *Pitch, real_T *numfrms, real_T *frmrate);
extern void yaapt_api(const mxArray *prhs[3], const mxArray *plhs[3]);
extern void yaapt_atexit(void);
extern void yaapt_initialize(void);
extern void yaapt_terminate(void);
extern void yaapt_xil_terminate(void);

#endif

/*
 * File trailer for _coder_yaapt_api.h
 *
 * [EOF]
 */
