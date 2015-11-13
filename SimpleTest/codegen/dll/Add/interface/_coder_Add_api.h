/* 
 * File: _coder_Add_api.h 
 *  
 * MATLAB Coder version            : 2.6 
 * C/C++ source code generated on  : 13-Nov-2015 04:26:57 
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

/* Function Declarations */
extern void Add_initialize(emlrtContext *aContext);
extern void Add_terminate(void);
extern void Add_atexit(void);
extern void Add_api(const mxArray *prhs[2], const mxArray *plhs[1]);
extern void Add(double arr[5], double b, double out[5]);
extern void Add_xil_terminate(void);

#endif
/* 
 * File trailer for _coder_Add_api.h 
 *  
 * [EOF] 
 */
