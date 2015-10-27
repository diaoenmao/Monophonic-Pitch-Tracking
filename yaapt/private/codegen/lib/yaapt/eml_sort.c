/*
 * File: eml_sort.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 26-Oct-2015 23:41:06
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "eml_sort.h"
#include "yaapt_emxutil.h"

/* Function Declarations */
static void b_eml_sort(const double x[4], double y[4], int idx[4]);
static void d_eml_sort(const double x[3], double y[3], int idx[3]);
static void f_eml_sort(const emxArray_real_T *x, int dim, emxArray_real_T *y,
  emxArray_int32_T *idx);

/* Function Definitions */

/*
 * Arguments    : const double x[4]
 *                double y[4]
 *                int idx[4]
 * Return Type  : void
 */
static void b_eml_sort(const double x[4], double y[4], int idx[4])
{
  int k;
  boolean_T p;
  signed char idx0[4];
  int i;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  for (k = 0; k < 4; k++) {
    idx[k] = k + 1;
  }

  for (k = 0; k < 4; k += 2) {
    if ((x[k] >= x[k + 1]) || rtIsNaN(x[k])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  for (i = 0; i < 4; i++) {
    idx0[i] = 1;
  }

  i = 2;
  while (i < 4) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 5; pEnd = qEnd + i) {
      b_p = j - 1;
      q = pEnd;
      qEnd = j + i2;
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if ((x[idx[b_p] - 1] >= x[idx[q - 1] - 1]) || rtIsNaN(x[idx[b_p] - 1]))
        {
          p = true;
        } else {
          p = false;
        }

        if (p) {
          idx0[k] = (signed char)idx[b_p];
          b_p++;
          if (b_p + 1 == pEnd) {
            while (q < qEnd) {
              k++;
              idx0[k] = (signed char)idx[q - 1];
              q++;
            }
          }
        } else {
          idx0[k] = (signed char)idx[q - 1];
          q++;
          if (q == qEnd) {
            while (b_p + 1 < pEnd) {
              k++;
              idx0[k] = (signed char)idx[b_p];
              b_p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k + 1 <= kEnd; k++) {
        idx[(j + k) - 1] = idx0[k];
      }

      j = qEnd;
    }

    i = i2;
  }

  for (k = 0; k < 4; k++) {
    y[k] = x[idx[k] - 1];
  }
}

/*
 * Arguments    : const double x[3]
 *                double y[3]
 *                int idx[3]
 * Return Type  : void
 */
static void d_eml_sort(const double x[3], double y[3], int idx[3])
{
  boolean_T p;
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
      y[0] = x[0];
      y[1] = x[1];
      y[2] = x[2];
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
        y[0] = x[0];
        y[1] = x[2];
        y[2] = x[1];
      } else {
        idx[0] = 3;
        idx[1] = 1;
        idx[2] = 2;
        y[0] = x[2];
        y[1] = x[0];
        y[2] = x[1];
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
      y[0] = x[1];
      y[1] = x[0];
      y[2] = x[2];
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
        y[0] = x[1];
        y[1] = x[2];
        y[2] = x[0];
      } else {
        idx[0] = 3;
        idx[1] = 2;
        idx[2] = 1;
        y[0] = x[2];
        y[1] = x[1];
        y[2] = x[0];
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int dim
 *                emxArray_real_T *y
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
static void f_eml_sort(const emxArray_real_T *x, int dim, emxArray_real_T *y,
  emxArray_int32_T *idx)
{
  emxArray_real_T *vwork;
  unsigned int uv4[2];
  int i2;
  int ix;
  int vstride;
  int k;
  int vspread;
  int npages;
  int b_i2;
  int i;
  emxArray_int32_T *iidx;
  emxArray_int32_T *idx0;
  int i1;
  int j;
  boolean_T p;
  int b_j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  b_emxInit_real_T(&vwork, 1);
  uv4[0] = (unsigned int)x->size[dim - 1];
  i2 = vwork->size[0];
  vwork->size[0] = (int)uv4[0];
  emxEnsureCapacity((emxArray__common *)vwork, i2, (int)sizeof(double));
  for (i2 = 0; i2 < 2; i2++) {
    ix = y->size[0] * y->size[1];
    y->size[i2] = x->size[i2];
    emxEnsureCapacity((emxArray__common *)y, ix, (int)sizeof(double));
  }

  for (i2 = 0; i2 < 2; i2++) {
    uv4[i2] = (unsigned int)x->size[i2];
  }

  i2 = idx->size[0] * idx->size[1];
  idx->size[0] = (int)uv4[0];
  idx->size[1] = (int)uv4[1];
  emxEnsureCapacity((emxArray__common *)idx, i2, (int)sizeof(int));
  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  vspread = (x->size[dim - 1] - 1) * vstride;
  npages = 1;
  k = dim + 1;
  while (k < 3) {
    npages *= x->size[1];
    k = 3;
  }

  b_i2 = 0;
  i = 1;
  b_emxInit_int32_T(&iidx, 1);
  b_emxInit_int32_T(&idx0, 1);
  while (i <= npages) {
    i1 = b_i2;
    b_i2 += vspread;
    for (j = 1; j <= vstride; j++) {
      i1++;
      b_i2++;
      ix = i1;
      for (k = 0; k < x->size[dim - 1]; k++) {
        vwork->data[k] = x->data[ix - 1];
        ix += vstride;
      }

      uv4[0] = (unsigned int)vwork->size[0];
      i2 = iidx->size[0];
      iidx->size[0] = (int)uv4[0];
      emxEnsureCapacity((emxArray__common *)iidx, i2, (int)sizeof(int));
      if (vwork->size[0] == 0) {
      } else {
        for (k = 1; k <= vwork->size[0]; k++) {
          iidx->data[k - 1] = k;
        }

        for (k = 1; k <= vwork->size[0] - 1; k += 2) {
          if ((vwork->data[k - 1] >= vwork->data[k]) || rtIsNaN(vwork->data[k -
               1])) {
            p = true;
          } else {
            p = false;
          }

          if (p) {
          } else {
            iidx->data[k - 1] = k + 1;
            iidx->data[k] = k;
          }
        }

        i2 = idx0->size[0];
        idx0->size[0] = vwork->size[0];
        emxEnsureCapacity((emxArray__common *)idx0, i2, (int)sizeof(int));
        ix = vwork->size[0];
        for (i2 = 0; i2 < ix; i2++) {
          idx0->data[i2] = 1;
        }

        ix = 2;
        while (ix < vwork->size[0]) {
          i2 = ix << 1;
          b_j = 1;
          for (pEnd = 1 + ix; pEnd < vwork->size[0] + 1; pEnd = qEnd + ix) {
            b_p = b_j - 1;
            q = pEnd;
            qEnd = b_j + i2;
            if (qEnd > vwork->size[0] + 1) {
              qEnd = vwork->size[0] + 1;
            }

            k = 0;
            kEnd = qEnd - b_j;
            while (k + 1 <= kEnd) {
              if ((vwork->data[iidx->data[b_p] - 1] >= vwork->data[iidx->data[q
                   - 1] - 1]) || rtIsNaN(vwork->data[iidx->data[b_p] - 1])) {
                p = true;
              } else {
                p = false;
              }

              if (p) {
                idx0->data[k] = iidx->data[b_p];
                b_p++;
                if (b_p + 1 == pEnd) {
                  while (q < qEnd) {
                    k++;
                    idx0->data[k] = iidx->data[q - 1];
                    q++;
                  }
                }
              } else {
                idx0->data[k] = iidx->data[q - 1];
                q++;
                if (q == qEnd) {
                  while (b_p + 1 < pEnd) {
                    k++;
                    idx0->data[k] = iidx->data[b_p];
                    b_p++;
                  }
                }
              }

              k++;
            }

            for (k = 0; k + 1 <= kEnd; k++) {
              iidx->data[(b_j + k) - 1] = idx0->data[k];
            }

            b_j = qEnd;
          }

          ix = i2;
        }
      }

      ix = i1 - 1;
      for (k = 0; k < x->size[dim - 1]; k++) {
        y->data[ix] = vwork->data[iidx->data[k] - 1];
        idx->data[ix] = iidx->data[k];
        ix += vstride;
      }
    }

    i++;
  }

  emxFree_int32_T(&idx0);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

/*
 * Arguments    : const double x[3]
 *                double y[3]
 *                int idx[3]
 * Return Type  : void
 */
void c_eml_sort(const double x[3], double y[3], int idx[3])
{
  d_eml_sort(x, y, idx);
}

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void e_eml_sort(const emxArray_real_T *x, emxArray_real_T *y, emxArray_int32_T
                *idx)
{
  f_eml_sort(x, 1, y, idx);
}

/*
 * Arguments    : const double x[4]
 *                double y[4]
 *                int idx[4]
 * Return Type  : void
 */
void eml_sort(const double x[4], double y[4], int idx[4])
{
  b_eml_sort(x, y, idx);
}

/*
 * File trailer for eml_sort.c
 *
 * [EOF]
 */
