/*
 * Add.h
 *
 * Code generation for function 'Add'
 *
 */

#ifndef __ADD_H__
#define __ADD_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "Add_types.h"

/* Function Declarations */
extern void Add(const emlrtStack *sp, const emxArray_real_T *arr, real_T b,
                emxArray_real_T *out);

#endif

/* End of code generation (Add.h) */
