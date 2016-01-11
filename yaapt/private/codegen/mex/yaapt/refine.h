/*
 * refine.h
 *
 * Code generation for function 'refine'
 *
 */

#ifndef __REFINE_H__
#define __REFINE_H__

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
#include "yaapt_types.h"

/* Function Declarations */
extern void refine(const emlrtStack *sp, const emxArray_real_T *TPitch1, const
                   emxArray_real_T *TMerit1, const emxArray_real_T *TPitch2,
                   const emxArray_real_T *TMerit2, const emxArray_real_T *SPitch,
                   const emxArray_real_T *Energy, const emxArray_boolean_T
                   *VUVEnergy, emxArray_real_T *Pitch, emxArray_real_T *Merit);

#endif

/* End of code generation (refine.h) */
