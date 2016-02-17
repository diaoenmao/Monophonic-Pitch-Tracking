/*
 * File: Mymedfilt1.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
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
extern void Mymedfilt1(emxArray_real_T *s, double w, emxArray_real_T *m);
extern void b_Mymedfilt1(const emxArray_real_T *s, double w, emxArray_real_T *m);

#endif

/*
 * File trailer for Mymedfilt1.h
 *
 * [EOF]
 */
