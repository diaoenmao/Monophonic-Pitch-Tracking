/*
 * File: spec_trk.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
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
#ifdef __cplusplus

extern "C" {

#endif

  extern void spec_trk(emxArray_real_T *Data, double Fs, const
                       emxArray_boolean_T *VUVEnergy, emxArray_real_T *SPitch,
                       emxArray_real_T *VUVSPitch, double pAvg_data[], int
                       pAvg_size[1], double pStd_data[], int pStd_size[1]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for spec_trk.h
 *
 * [EOF]
 */
