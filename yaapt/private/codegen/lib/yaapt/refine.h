/*
 * File: refine.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

#ifndef __REFINE_H__
#define __REFINE_H__

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void refine(const emxArray_real_T *TPitch1, const emxArray_real_T
                   *TMerit1, const emxArray_real_T *TPitch2, const
                   emxArray_real_T *TMerit2, const emxArray_real_T *SPitch,
                   const emxArray_real_T *Energy, const emxArray_boolean_T
                   *VUVEnergy, double Prm_nlfer_thresh2, double Prm_merit_pivot,
                   double Prm_median_value, emxArray_real_T *Pitch,
                   emxArray_real_T *Merit);

#endif

/*
 * File trailer for refine.h
 *
 * [EOF]
 */
