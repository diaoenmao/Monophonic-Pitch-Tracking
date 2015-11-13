/* 
 * File: _coder_Add_api.h 
 *  
 * MATLAB Coder version            : 2.6 
 * C/C++ source code generated on  : 13-Nov-2015 04:27:33 
 */

#ifndef ___CODER_ADD_API_H__
#define ___CODER_ADD_API_H__
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
extern void Add_initialize(emlrtContext *aContext);
extern void Add_terminate(void);
extern void Add_atexit(void);
extern void Add_api(const mxArray *prhs[2], const mxArray *plhs[1]);
extern void Add(emxArray_real_T *arr, double b, emxArray_real_T *out);
extern void Add_xil_terminate(void);

#endif
/* 
 * File trailer for _coder_Add_api.h 
 *  
 * [EOF] 
 */
