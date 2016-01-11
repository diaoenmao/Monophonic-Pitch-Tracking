/*
 * File: repmat.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 12-Jan-2016 01:25:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "repmat.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : double varargin_2
 *                emxArray_real_T *b
 * Return Type  : void
 */
void b_repmat(double varargin_2, emxArray_real_T *b)
{
  int jtilecol;
  int ibtile;
  int k;
  jtilecol = b->size[0] * b->size[1];
  b->size[0] = 4;
  b->size[1] = (int)varargin_2;
  emxEnsureCapacity((emxArray__common *)b, jtilecol, (int)sizeof(double));
  if (!((int)varargin_2 == 0)) {
    for (jtilecol = 1; jtilecol <= (int)varargin_2; jtilecol++) {
      ibtile = (jtilecol - 1) << 2;
      for (k = 0; k < 4; k++) {
        b->data[ibtile + k] = 1.0 + (((double)k + 1.0) - 1.0);
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *a
 *                emxArray_real_T *b
 * Return Type  : void
 */
void repmat(const emxArray_real_T *a, emxArray_real_T *b)
{
  int outsize_idx_1;
  int ibmat;
  int itilerow;
  outsize_idx_1 = a->size[1];
  ibmat = b->size[0] * b->size[1];
  b->size[0] = 4;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity((emxArray__common *)b, ibmat, (int)sizeof(double));
  if ((!(a->size[1] == 0)) && (!(outsize_idx_1 == 0))) {
    for (outsize_idx_1 = 0; outsize_idx_1 + 1 <= a->size[1]; outsize_idx_1++) {
      ibmat = outsize_idx_1 << 2;
      for (itilerow = 0; itilerow < 4; itilerow++) {
        b->data[ibmat + itilerow] = a->data[outsize_idx_1];
      }
    }
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
