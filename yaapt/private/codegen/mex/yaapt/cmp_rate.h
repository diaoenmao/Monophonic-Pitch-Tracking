/*
 * cmp_rate.h
 *
 * Code generation for function 'cmp_rate'
 *
 */

#ifndef CMP_RATE_H
#define CMP_RATE_H

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
extern void cmp_rate(const emlrtStack *sp, const emxArray_real_T *Phi, real_T Fs,
                     real_T maxcands, real_T lag_min, real_T lag_max, real_T
                     Prm_nccf_thresh1, real_T Prm_nccf_thresh2, real_T
                     Prm_nccf_pwidth, emxArray_real_T *Pitch, emxArray_real_T
                     *Merit);

#endif

/* End of code generation (cmp_rate.h) */
