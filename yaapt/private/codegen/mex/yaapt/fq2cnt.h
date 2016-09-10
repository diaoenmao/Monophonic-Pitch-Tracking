/*
 * fq2cnt.h
 *
 * Code generation for function 'fq2cnt'
 *
 */

#ifndef FQ2CNT_H
#define FQ2CNT_H

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
extern void fq2cnt(const emlrtStack *sp, const emxArray_real_T *fq,
                   emxArray_real_T *cnt);

#endif

/* End of code generation (fq2cnt.h) */
