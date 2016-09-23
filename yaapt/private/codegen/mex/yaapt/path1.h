/*
 * path1.h
 *
 * Code generation for function 'path1'
 *
 */

#ifndef PATH1_H
#define PATH1_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void path1(const emlrtStack *sp, const emxArray_real_T *Local, const
                  emxArray_real_T *Trans, real_T PATH_data[], int32_T PATH_size
                  [2]);

#endif

/* End of code generation (path1.h) */
