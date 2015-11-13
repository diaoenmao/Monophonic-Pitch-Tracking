/*
 * File: yaapt.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

#ifndef __YAAPT_H__
#define __YAAPT_H__

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

  extern void yaapt(const emxArray_real_T *Data, double Fs, emxArray_real_T
                    *Pitch, double *numfrms, double *frmrate);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for yaapt.h
 *
 * [EOF]
 */
