/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pchip.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 14-Nov-2015 18:37:50
 */

#ifndef __PCHIP_H__
#define __PCHIP_H__

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
extern void pchip(const emxArray_real_T *x, const emxArray_real_T *y,
                  emxArray_real_T *v_breaks, emxArray_real_T *v_coefs);

#endif

/*
 * File trailer for pchip.h
 *
 * [EOF]
 */
