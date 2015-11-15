/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mod.h
 *
 * Code generation for function 'mod'
 *
 */

#ifndef __MOD_H__
#define __MOD_H__

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
extern real_T b_mod(real_T x);

#ifdef __WATCOMC__

#pragma aux b_mod value [8087];

#endif
#endif

/* End of code generation (mod.h) */
