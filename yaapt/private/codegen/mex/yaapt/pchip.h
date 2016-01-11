/*
 * pchip.h
 *
 * Code generation for function 'pchip'
 *
 */

#ifndef __PCHIP_H__
#define __PCHIP_H__

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
extern void pchip(const emlrtStack *sp, const emxArray_real_T *x, const
                  emxArray_real_T *y, emxArray_real_T *v_breaks, emxArray_real_T
                  *v_coefs);

#endif

/* End of code generation (pchip.h) */
