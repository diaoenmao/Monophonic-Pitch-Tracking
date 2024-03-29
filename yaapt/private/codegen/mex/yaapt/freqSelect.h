/*
 * freqSelect.h
 *
 * Code generation for function 'freqSelect'
 *
 */

#ifndef FREQSELECT_H
#define FREQSELECT_H

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
extern void freqSelect(const emlrtStack *sp, const emxArray_real_T *fq,
  emxArray_real_T *freq, emxArray_real_T *cent);

#endif

/* End of code generation (freqSelect.h) */
