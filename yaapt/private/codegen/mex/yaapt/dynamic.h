/*
 * dynamic.h
 *
 * Code generation for function 'dynamic'
 *
 */

#ifndef __DYNAMIC_H__
#define __DYNAMIC_H__

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
extern void dynamic(const emlrtStack *sp, const emxArray_real_T *Pitch, const
                    emxArray_real_T *Merit, const emxArray_real_T *Energy,
                    emxArray_real_T *FinPitch);

#endif

/* End of code generation (dynamic.h) */
