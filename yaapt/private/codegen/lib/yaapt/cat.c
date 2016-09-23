/*
 * File: cat.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
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
  int ysize[2];
  int iy;
  int i;
  int ix;
  int l;
  ysize[0] = varargin_1->size[0] + varargin_2->size[0];
  ysize[1] = varargin_1->size[1];
  iy = y->size[0] * y->size[1];
  y->size[0] = ysize[0];
  y->size[1] = ysize[1];
  emxEnsureCapacity((emxArray__common *)y, iy, (int)sizeof(double));
  for (iy = 0; iy < 2; iy++) {
    ysize[iy] = y->size[iy];
  }

  iy = 0;
  for (i = 0; i < ysize[1]; i++) {
    ix = i * varargin_1->size[0];
    for (l = 1; l <= varargin_1->size[0]; l++) {
      y->data[iy] = varargin_1->data[ix];
      ix++;
      iy++;
    }

    ix = i * varargin_2->size[0];
    for (l = 1; l <= varargin_2->size[0]; l++) {
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
