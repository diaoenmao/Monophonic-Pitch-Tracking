/*
 * pchip.h
 *
 * Code generation for function 'pchip'
 *
 */

#ifndef PCHIP_H
#define PCHIP_H

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
extern void pchip(const emlrtStack *sp, const emxArray_real_T *x, const
                  emxArray_real_T *y, emxArray_real_T *v_breaks, emxArray_real_T
                  *v_coefs);

#endif

/* End of code generation (pchip.h) */
