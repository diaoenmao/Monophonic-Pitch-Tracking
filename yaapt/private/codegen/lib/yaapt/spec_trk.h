/*
 * File: spec_trk.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

#ifndef SPEC_TRK_H
#define SPEC_TRK_H

/* Include Files */
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
                     VUVEnergy, const struct_T *Prm, emxArray_real_T *SPitch,
                     emxArray_real_T *VUVSPitch, double pAvg_data[], int
                     pAvg_size[1], double pStd_data[], int pStd_size[1]);

#endif

/*
 * File trailer for spec_trk.h
 *
 * [EOF]
 */
