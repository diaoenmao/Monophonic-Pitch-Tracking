/*
 * error.h
 *
 * Code generation for function 'error'
 *
 */

#ifndef ERROR_H
#define ERROR_H

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
extern void b_error(const emlrtStack *sp);
extern void c_error(const emlrtStack *sp);
extern void i_error(const emlrtStack *sp);
extern void j_error(const emlrtStack *sp);
extern void k_error(const emlrtStack *sp);

#endif

/* End of code generation (error.h) */
