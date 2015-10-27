/*
 * File: crs_corr.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 26-Oct-2015 23:41:06
 */

#ifndef __CRS_CORR_H__
#define __CRS_CORR_H__

/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void crs_corr(emxArray_real_T *Data, double lag_min, double lag_max,
                     emxArray_real_T *Phi);
extern double eml_matlab_zlarfg(void);

#endif

/*
 * File trailer for crs_corr.h
 *
 * [EOF]
 */
