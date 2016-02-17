/*
 * diff.h
 *
 * Code generation for function 'diff'
 *
 */

#ifndef __DIFF_H__
#define __DIFF_H__

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
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void b_diff(const real_T x[6], real_T y[5]);
extern real_T diff(const real_T x[2]);

#ifdef __WATCOMC__

#pragma aux diff value [8087];

#endif
#endif

/* End of code generation (diff.h) */
