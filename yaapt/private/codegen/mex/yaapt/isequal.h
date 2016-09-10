/*
 * isequal.h
 *
 * Code generation for function 'isequal'
 *
 */

#ifndef ISEQUAL_H
#define ISEQUAL_H

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
extern boolean_T b_isequal(const emxArray_real_T *varargin_1);
extern boolean_T c_isequal(const emxArray_real_T *varargin_1);
extern boolean_T d_isequal(const emxArray_real_T *varargin_1);
extern boolean_T e_isequal(const emxArray_boolean_T *varargin_1);
extern boolean_T isequal(const real_T varargin_1[2], const real_T varargin_2[2]);

#endif

/* End of code generation (isequal.h) */
