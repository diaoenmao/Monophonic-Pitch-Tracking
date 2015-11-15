/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Mymedfilt1.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
 */

#ifndef __MYMEDFILT1_H__
#define __MYMEDFILT1_H__

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

  extern void Mymedfilt1(emxArray_real_T *s, emxArray_real_T *m);
  extern void b_Mymedfilt1(const emxArray_real_T *s, emxArray_real_T *m);
  extern void c_Mymedfilt1(emxArray_real_T *s, emxArray_real_T *m);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for Mymedfilt1.h
 *
 * [EOF]
 */
