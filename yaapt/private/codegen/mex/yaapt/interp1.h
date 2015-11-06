/*
 * interp1.h
 *
 * Code generation for function 'interp1'
 *
 */

#ifndef __INTERP1_H__
#define __INTERP1_H__

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
extern void interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
                    const emxArray_real_T *varargin_2, const emxArray_real_T
                    *varargin_3, emxArray_real_T *Vq);

#endif

/* End of code generation (interp1.h) */
