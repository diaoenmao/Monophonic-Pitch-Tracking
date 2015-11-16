/*
 * File: sort1.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 19:51:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sort1.h"
#include "sortIdx.h"
#include "yaapt_emxutil.h"

/* Function Declarations */
static void b_sort(double x[100], int idx[100]);
static void d_sort(double x[3], int idx[3]);
static void f_sort(emxArray_real_T *x, int dim, emxArray_int32_T *idx);

/* Function Definitions */

/*
 * Arguments    : double x[100]
 *                int idx[100]
 * Return Type  : void
 */
static void b_sort(double x[100], int idx[100])
{
  double x4[4];
  signed char idx4[4];
  int m;
  double xwork[100];
  int nNaNs;
  int ib;
  int k;
  int i2;
  int i3;
  int i4;
  signed char perm[4];
  int iwork[100];
  memset(&idx[0], 0, 100U * sizeof(int));
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  memset(&xwork[0], 0, 100U * sizeof(double));
  nNaNs = -99;
  ib = 0;
  for (k = 0; k < 100; k++) {
    if (rtIsNaN(x[k])) {
      idx[-nNaNs] = k + 1;
      xwork[-nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (signed char)(k + 1);
      x4[ib - 1] = x[k];
      if (ib == 4) {
        ib = (k - nNaNs) - 102;
        if (x4[0] >= x4[1]) {
          m = 1;
          i2 = 2;
        } else {
          m = 2;
          i2 = 1;
        }

        if (x4[2] >= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        if (x4[m - 1] >= x4[i3 - 1]) {
          if (x4[i2 - 1] >= x4[i3 - 1]) {
            perm[0] = (signed char)m;
            perm[1] = (signed char)i2;
            perm[2] = (signed char)i3;
            perm[3] = (signed char)i4;
          } else if (x4[i2 - 1] >= x4[i4 - 1]) {
            perm[0] = (signed char)m;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)m;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else if (x4[m - 1] >= x4[i4 - 1]) {
          if (x4[i2 - 1] >= x4[i4 - 1]) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)m;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)m;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)m;
          perm[3] = (signed char)i2;
        }

        idx[ib] = idx4[perm[0] - 1];
        idx[ib + 1] = idx4[perm[1] - 1];
        idx[ib + 2] = idx4[perm[2] - 1];
        idx[ib + 3] = idx4[perm[3] - 1];
        x[ib] = x4[perm[0] - 1];
        x[ib + 1] = x4[perm[1] - 1];
        x[ib + 2] = x4[perm[2] - 1];
        x[ib + 3] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    for (m = 0; m < 4; m++) {
      perm[m] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (k = 1; k <= ib; k++) {
      idx[(k - nNaNs) - ib] = idx4[perm[k - 1] - 1];
      x[(k - nNaNs) - ib] = x4[perm[k - 1] - 1];
    }
  }

  m = (nNaNs + 99) >> 1;
  for (k = 1; k <= m; k++) {
    ib = (signed char)idx[k - nNaNs];
    idx[k - nNaNs] = (signed char)idx[100 - k];
    idx[100 - k] = ib;
    x[k - nNaNs] = xwork[100 - k];
    x[100 - k] = xwork[k - nNaNs];
  }

  if (((nNaNs + 99) & 1) != 0) {
    x[(m - nNaNs) + 1] = xwork[(m - nNaNs) + 1];
  }

  memset(&iwork[0], 0, 100U * sizeof(int));
  if (1 - nNaNs > 1) {
    merge_block(idx, x, 1 - nNaNs, iwork, xwork);
  }

  if ((nNaNs + 99 > 0) && (1 - nNaNs > 0)) {
    for (k = 1; k <= nNaNs + 99; k++) {
      xwork[k - 1] = x[k - nNaNs];
      iwork[k - 1] = idx[k - nNaNs];
    }

    for (k = -nNaNs; k + 1 > 0; k--) {
      x[(nNaNs + k) + 99] = x[k];
      idx[(nNaNs + k) + 99] = idx[k];
    }

    for (k = 0; k + 1 <= nNaNs + 99; k++) {
      x[k] = xwork[k];
      idx[k] = iwork[k];
    }
  }
}

/*
 * Arguments    : double x[3]
 *                int idx[3]
 * Return Type  : void
 */
static void d_sort(double x[3], int idx[3])
{
  double b_x[3];
  int i24;
  boolean_T p;
  for (i24 = 0; i24 < 3; i24++) {
    b_x[i24] = x[i24];
  }

  if ((x[0] >= x[1]) || rtIsNaN(x[0])) {
    p = true;
  } else {
    p = false;
  }

  if (p) {
    if ((x[1] >= x[2]) || rtIsNaN(x[1])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx[0] = 1;
      idx[1] = 2;
      idx[2] = 3;
    } else {
      if ((x[0] >= x[2]) || rtIsNaN(x[0])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        idx[0] = 1;
        idx[1] = 3;
        idx[2] = 2;
        b_x[1] = x[2];
        b_x[2] = x[1];
      } else {
        idx[0] = 3;
        idx[1] = 1;
        idx[2] = 2;
        b_x[2] = x[1];
        b_x[1] = x[0];
        b_x[0] = x[2];
      }
    }
  } else {
    if ((x[0] >= x[2]) || rtIsNaN(x[0])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx[0] = 2;
      idx[1] = 1;
      idx[2] = 3;
      b_x[0] = x[1];
      b_x[1] = x[0];
    } else {
      if ((x[1] >= x[2]) || rtIsNaN(x[1])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        idx[0] = 2;
        idx[1] = 3;
        idx[2] = 1;
        b_x[0] = x[1];
        b_x[1] = x[2];
        b_x[2] = x[0];
      } else {
        idx[0] = 3;
        idx[1] = 2;
        idx[2] = 1;
        b_x[0] = x[2];
        b_x[2] = x[0];
      }
    }
  }

  for (i24 = 0; i24 < 3; i24++) {
    x[i24] = b_x[i24];
  }
}

/*
 * Arguments    : emxArray_real_T *x
 *                int dim
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
static void f_sort(emxArray_real_T *x, int dim, emxArray_int32_T *idx)
{
  emxArray_real_T *vwork;
  int i25;
  int vstride;
  int k;
  int iv1[2];
  int npages;
  int pagesize;
  int i;
  emxArray_int32_T *iidx;
  int pageoffset;
  int j;
  int idx0;
  emxInit_real_T1(&vwork, 1);
  i25 = x->size[dim - 1];
  vstride = x->size[dim - 1];
  k = vwork->size[0];
  vwork->size[0] = vstride;
  emxEnsureCapacity((emxArray__common *)vwork, k, (int)sizeof(double));
  for (k = 0; k < 2; k++) {
    iv1[k] = x->size[k];
  }

  k = idx->size[0] * idx->size[1];
  idx->size[0] = iv1[0];
  idx->size[1] = iv1[1];
  emxEnsureCapacity((emxArray__common *)idx, k, (int)sizeof(int));
  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  npages = 1;
  k = dim + 1;
  while (k < 3) {
    npages *= x->size[1];
    k = 3;
  }

  pagesize = x->size[dim - 1] * vstride;
  i = 1;
  emxInit_int32_T1(&iidx, 1);
  while (i <= npages) {
    pageoffset = (i - 1) * pagesize;
    for (j = 0; j + 1 <= vstride; j++) {
      idx0 = pageoffset + j;
      for (k = 0; k + 1 <= i25; k++) {
        vwork->data[k] = x->data[idx0 + k * vstride];
      }

      sortIdx(vwork, iidx);
      for (k = 0; k + 1 <= i25; k++) {
        x->data[idx0 + k * vstride] = vwork->data[k];
        idx->data[idx0 + k * vstride] = iidx->data[k];
      }
    }

    i++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

/*
 * Arguments    : double x[3]
 *                int idx[3]
 * Return Type  : void
 */
void c_sort(double x[3], int idx[3])
{
  d_sort(x, idx);
}

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void e_sort(emxArray_real_T *x, emxArray_int32_T *idx)
{
  f_sort(x, 1, idx);
}

/*
 * Arguments    : double x[100]
 *                int idx[100]
 * Return Type  : void
 */
void sort(double x[100], int idx[100])
{
  b_sort(x, idx);
}

/*
 * File trailer for sort1.c
 *
 * [EOF]
 */
