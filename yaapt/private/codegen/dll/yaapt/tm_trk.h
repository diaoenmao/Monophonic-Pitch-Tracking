/*
 * File: tm_trk.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

#ifndef __TM_TRK_H__
#define __TM_TRK_H__

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

  extern void tm_trk(const emxArray_real_T *Data, double Fs, const
                     emxArray_real_T *SPitch, const double pStd_data[], const
                     int pStd_size[1], emxArray_real_T *Pitch, emxArray_real_T
                     *Merit);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for tm_trk.h
 *
 * [EOF]
 */
