/*
 * File: cat.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Jan-2016 05:43:25
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cat.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *varargin_1
 *                const emxArray_real_T *varargin_2
 *                emxArray_real_T *y
 * Return Type  : void
 */
void cat(const emxArray_real_T *varargin_1, const emxArray_real_T *varargin_2,
         emxArray_real_T *y)
{
  unsigned int sz1[2];
  int iy;
  unsigned int ysize[2];
  int i;
  int ix;
  int l;
  for (iy = 0; iy < 2; iy++) {
    sz1[iy] = (unsigned int)varargin_1->size[iy];
  }

  for (iy = 0; iy < 2; iy++) {
    ysize[iy] = sz1[iy];
  }

  ysize[0] += 3U;
  iy = y->size[0] * y->size[1];
  y->size[0] = (int)ysize[0];
  y->size[1] = (int)ysize[1];
  emxEnsureCapacity((emxArray__common *)y, iy, (int)sizeof(double));
  for (iy = 0; iy < 2; iy++) {
    ysize[iy] = (unsigned int)y->size[iy];
  }

  iy = 0;
  for (i = 0; i < (int)ysize[1]; i++) {
    ix = i * 3;
    for (l = 0; l < 3; l++) {
      y->data[iy] = varargin_1->data[ix];
      ix++;
      iy++;
    }

    ix = i * 3;
    for (l = 0; l < 3; l++) {
      y->data[iy] = varargin_2->data[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * File trailer for cat.c
 *
 * [EOF]
 */
