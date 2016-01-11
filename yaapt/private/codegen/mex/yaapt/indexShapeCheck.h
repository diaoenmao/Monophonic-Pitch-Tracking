/*
 * indexShapeCheck.h
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

#ifndef __INDEXSHAPECHECK_H__
#define __INDEXSHAPECHECK_H__

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
extern void b_indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const
  int32_T indexSize[2]);
extern void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const
  int32_T indexSize[2]);

#endif

/* End of code generation (indexShapeCheck.h) */
