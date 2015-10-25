/*
 * File: spec_trk.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 25-Oct-2015 03:48:36
 */

#ifndef __SPEC_TRK_H__
#define __SPEC_TRK_H__

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
extern void spec_trk(emxArray_real_T *Data, double Fs, const emxArray_boolean_T *
                     VUVEnergy, emxArray_real_T *SPitch, emxArray_real_T
                     *VUVSPitch, emxArray_real_T *pAvg, emxArray_real_T *pStd);

#endif

/*
 * File trailer for spec_trk.h
 *
 * [EOF]
 */
