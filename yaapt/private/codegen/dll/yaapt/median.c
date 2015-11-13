/*
 * File: median.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "median.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void median(const emxArray_real_T *x, emxArray_real_T *y)
{
  unsigned int sz[2];
  int i1;
  int i2;
  int iy;
  int i;
  double vwork[5];
  int k;
  signed char idx[5];
  boolean_T p;
  signed char idx0[5];
  int b_i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  for (i1 = 0; i1 < 2; i1++) {
    sz[i1] = (unsigned int)x->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)sz[1];
  emxEnsureCapacity((emxArray__common *)y, i1, (int)sizeof(double));
  i2 = 0;
  iy = -1;
  for (i = 1; i <= x->size[1]; i++) {
    i1 = i2;
    i2 += 5;
    for (k = 0; k < 5; k++) {
      vwork[k] = x->data[i1];
      i1++;
    }

    iy++;
    for (k = 0; k < 5; k++) {
      idx[k] = (signed char)(k + 1);
    }

    for (k = 0; k < 3; k += 2) {
      if ((vwork[k] <= vwork[k + 1]) || rtIsNaN(vwork[k + 1])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
      } else {
        idx[k] = (signed char)(k + 2);
        idx[k + 1] = (signed char)(k + 1);
      }
    }

    for (i1 = 0; i1 < 5; i1++) {
      idx0[i1] = 1;
    }

    i1 = 2;
    while (i1 < 5) {
      b_i2 = i1 << 1;
      j = 1;
      for (pEnd = 1 + i1; pEnd < 6; pEnd = qEnd + i1) {
        b_p = j;
        q = pEnd - 1;
        qEnd = j + b_i2;
        if (qEnd > 6) {
          qEnd = 6;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((vwork[idx[b_p - 1] - 1] <= vwork[idx[q] - 1]) || rtIsNaN
              (vwork[idx[q] - 1])) {
            p = true;
          } else {
            p = false;
          }

          if (p) {
            idx0[k] = idx[b_p - 1];
            b_p++;
            if (b_p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                idx0[k] = idx[q];
                q++;
              }
            }
          } else {
            idx0[k] = idx[q];
            q++;
            if (q + 1 == qEnd) {
              while (b_p < pEnd) {
                k++;
                idx0[k] = idx[b_p - 1];
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

      i1 = b_i2;
    }

    if (rtIsNaN(vwork[idx[4] - 1])) {
      y->data[iy] = vwork[idx[4] - 1];
    } else {
      y->data[iy] = vwork[idx[2] - 1];
    }
  }
}

/*
 * File trailer for median.c
 *
 * [EOF]
 */
