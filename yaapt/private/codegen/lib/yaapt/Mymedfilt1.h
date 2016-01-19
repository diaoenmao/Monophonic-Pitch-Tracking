/*
 * File: Mymedfilt1.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Jan-2016 00:47:12
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
extern void Mymedfilt1(emxArray_real_T *s, emxArray_real_T *m);
extern void b_Mymedfilt1(const emxArray_real_T *s, emxArray_real_T *m);
extern void c_Mymedfilt1(emxArray_real_T *s, emxArray_real_T *m);

#endif

/*
 * File trailer for Mymedfilt1.h
 *
 * [EOF]
 */
