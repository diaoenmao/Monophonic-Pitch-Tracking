/*
 * mod.h
 *
 * Code generation for function 'mod'
 *
 */

#ifndef MOD_H
#define MOD_H

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
extern real_T b_mod(real_T x);

#ifdef __WATCOMC__

#pragma aux b_mod value [8087];

#endif
#endif

/* End of code generation (mod.h) */
