/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dynamic5.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
 */

#ifndef __DYNAMIC5_H__
#define __DYNAMIC5_H__

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
#ifdef __cplusplus

extern "C" {

#endif

  extern void dynamic5(const emxArray_real_T *Pitch_array, const emxArray_real_T
                       *Merit_array, double k1, emxArray_real_T *FinPitch);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for dynamic5.h
 *
 * [EOF]
 */
