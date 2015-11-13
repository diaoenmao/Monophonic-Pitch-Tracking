/*
 * File: peaks.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

#ifndef __PEAKS_H__
#define __PEAKS_H__

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

  extern void peaks(emxArray_real_T *Data, double delta, double Pitch_data[],
                    int Pitch_size[2], double Merit_data[], int Merit_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for peaks.h
 *
 * [EOF]
 */
