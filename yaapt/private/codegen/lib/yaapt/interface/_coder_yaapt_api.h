/* 
 * File: _coder_yaapt_api.h 
 *  
 * MATLAB Coder version            : 2.6 
 * C/C++ source code generated on  : 25-Oct-2015 03:48:36 
 */

#ifndef ___CODER_YAAPT_API_H__
#define ___CODER_YAAPT_API_H__
/* Include files */
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    double *data;
    int *size;
    int allocatedSize;
    int numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /*typedef_emxArray_real_T*/

/* Function Declarations */
extern void yaapt_initialize(emlrtContext *aContext);
extern void yaapt_terminate(void);
extern void yaapt_atexit(void);
extern void yaapt_api(const mxArray *prhs[2], const mxArray *plhs[3]);
extern void yaapt(emxArray_real_T *Data, double Fs, emxArray_real_T *Pitch, double *numfrms, double *frmrate);
extern void yaapt_xil_terminate(void);

#endif
/* 
 * File trailer for _coder_yaapt_api.h 
 *  
 * [EOF] 
 */
