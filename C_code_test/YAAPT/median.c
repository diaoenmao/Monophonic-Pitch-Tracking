/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: median.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 14-Nov-2015 18:37:50
 */

/* Include Files */
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
  int ub_loop;
  int i;
  int b_i;
  int idx[5];
  int c_i;
  int iwork[5];
  int k;
  boolean_T p;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  double m;
  ub_loop = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, ub_loop, (int)sizeof(double));
  ub_loop = x->size[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_i,c_i,k,p,i2,j,pEnd,b_p,q,qEnd,kEnd,m) \
 firstprivate(idx,iwork)

  for (i = 1; i <= ub_loop; i++) {
    b_i = i;
    for (c_i = 0; c_i < 5; c_i++) {
      idx[c_i] = 0;
    }

    for (k = 0; k <= 2; k += 2) {
      if ((x->data[k + x->size[0] * (b_i - 1)] <= x->data[(k + x->size[0] * (b_i
             - 1)) + 1]) || rtIsNaN(x->data[(k + x->size[0] * (b_i - 1)) + 1]))
      {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        idx[k] = k + 1;
        idx[k + 1] = k + 2;
      } else {
        idx[k] = k + 2;
        idx[k + 1] = k + 1;
      }
    }

    idx[4] = 5;
    c_i = 2;
    while (c_i < 5) {
      i2 = c_i << 1;
      j = 1;
      for (pEnd = 1 + c_i; pEnd < 6; pEnd = qEnd + c_i) {
        b_p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > 6) {
          qEnd = 6;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((x->data[(idx[b_p - 1] + x->size[0] * (b_i - 1)) - 1] <= x->data
               [(idx[q] + x->size[0] * (b_i - 1)) - 1]) || rtIsNaN(x->data
               [(idx[q] + x->size[0] * (b_i - 1)) - 1])) {
            p = true;
          } else {
            p = false;
          }

          if (p) {
            iwork[k] = idx[b_p - 1];
            b_p++;
            if (b_p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                iwork[k] = idx[q];
                q++;
              }
            }
          } else {
            iwork[k] = idx[q];
            q++;
            if (q + 1 == qEnd) {
              while (b_p < pEnd) {
                k++;
                iwork[k] = idx[b_p - 1];
                b_p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k + 1 <= kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }

        j = qEnd;
      }

      c_i = i2;
    }

    if (rtIsNaN(x->data[(idx[4] + x->size[0] * (b_i - 1)) - 1])) {
      m = x->data[(idx[4] + x->size[0] * (b_i - 1)) - 1];
    } else {
      m = x->data[(idx[2] + x->size[0] * (b_i - 1)) - 1];
    }

    y->data[b_i - 1] = m;
  }
}

/*
 * File trailer for median.c
 *
 * [EOF]
 */
