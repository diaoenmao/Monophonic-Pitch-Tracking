/*
 * File: median.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
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
  int loop_ub;
  int i;
  emxArray_int32_T *iwork;
  emxArray_int32_T *idx;
  int b_i;
  int i23;
  int midm1;
  int k;
  int c_i;
  double m;
  boolean_T p;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  ub_loop = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, ub_loop, (int)sizeof(double));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    ub_loop = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, ub_loop, (int)sizeof(double));
    loop_ub = y->size[1];
    for (ub_loop = 0; ub_loop < loop_ub; ub_loop++) {
      y->data[y->size[0] * ub_loop] = rtNaN;
    }
  } else {
    ub_loop = x->size[1];

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(iwork,idx,b_i,i23,midm1,k,c_i,m,p,i2,j,pEnd,b_p,q,qEnd,kEnd)

    {
      emxInit_int32_T1(&iwork, 1);
      emxInit_int32_T1(&idx, 1);

#pragma omp for nowait

      for (i = 1; i <= ub_loop; i++) {
        b_i = i;
        i23 = x->size[0];
        midm1 = i23 / 2;
        k = x->size[0];
        i23 = idx->size[0];
        idx->size[0] = k;
        emxEnsureCapacity((emxArray__common *)idx, i23, (int)sizeof(int));
        for (i23 = 0; i23 < k; i23++) {
          idx->data[i23] = 0;
        }

        i23 = x->size[0] + 1;
        c_i = iwork->size[0];
        iwork->size[0] = k;
        emxEnsureCapacity((emxArray__common *)iwork, c_i, (int)sizeof(int));
        for (k = 1; k <= i23 - 2; k += 2) {
          m = x->data[k + x->size[0] * (b_i - 1)];
          if ((x->data[(k + x->size[0] * (b_i - 1)) - 1] <= m) || rtIsNaN(m)) {
            p = true;
          } else {
            p = false;
          }

          if (p) {
            idx->data[k - 1] = k;
            idx->data[k] = k + 1;
          } else {
            idx->data[k - 1] = k + 1;
            idx->data[k] = k;
          }
        }

        c_i = x->size[0];
        if ((c_i & 1) != 0) {
          c_i = x->size[0] - 1;
          k = x->size[0];
          idx->data[c_i] = k;
        }

        c_i = 2;
        while (c_i < i23 - 1) {
          i2 = c_i << 1;
          j = 1;
          for (pEnd = 1 + c_i; pEnd < i23; pEnd = qEnd + c_i) {
            b_p = j;
            q = pEnd;
            qEnd = j + i2;
            if (qEnd > i23) {
              qEnd = i23;
            }

            k = 0;
            kEnd = qEnd - j;
            while (k + 1 <= kEnd) {
              m = x->data[(idx->data[q - 1] + x->size[0] * (b_i - 1)) - 1];
              if ((x->data[(idx->data[b_p - 1] + x->size[0] * (b_i - 1)) - 1] <=
                   m) || rtIsNaN(m)) {
                p = true;
              } else {
                p = false;
              }

              if (p) {
                iwork->data[k] = idx->data[b_p - 1];
                b_p++;
                if (b_p == pEnd) {
                  while (q < qEnd) {
                    k++;
                    iwork->data[k] = idx->data[q - 1];
                    q++;
                  }
                }
              } else {
                iwork->data[k] = idx->data[q - 1];
                q++;
                if (q == qEnd) {
                  while (b_p < pEnd) {
                    k++;
                    iwork->data[k] = idx->data[b_p - 1];
                    b_p++;
                  }
                }
              }

              k++;
            }

            for (k = 0; k + 1 <= kEnd; k++) {
              idx->data[(j + k) - 1] = iwork->data[k];
            }

            j = qEnd;
          }

          c_i = i2;
        }

        if (rtIsNaN(x->data[(idx->data[idx->size[0] - 1] + x->size[0] * (b_i - 1))
                    - 1])) {
          m = x->data[(idx->data[idx->size[0] - 1] + x->size[0] * (b_i - 1)) - 1];
        } else {
          i23 = x->size[0];
          if (midm1 << 1 == i23) {
            if (((x->data[(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1] <
                  0.0) && (x->data[(idx->data[midm1] + x->size[0] * (b_i - 1)) -
                           1] >= 0.0)) || rtIsInf(x->data[(idx->data[midm1 - 1]
                  + x->size[0] * (b_i - 1)) - 1]) || rtIsInf(x->data[(idx->
                  data[midm1] + x->size[0] * (b_i - 1)) - 1])) {
              m = (x->data[(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1]
                   + x->data[(idx->data[midm1] + x->size[0] * (b_i - 1)) - 1]) /
                2.0;
            } else {
              m = x->data[(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1] +
                (x->data[(idx->data[midm1] + x->size[0] * (b_i - 1)) - 1] -
                 x->data[(idx->data[midm1 - 1] + x->size[0] * (b_i - 1)) - 1]) /
                2.0;
            }
          } else {
            m = x->data[(idx->data[midm1] + x->size[0] * (b_i - 1)) - 1];
          }
        }

        y->data[b_i - 1] = m;
      }

      emxFree_int32_T(&idx);
      emxFree_int32_T(&iwork);
    }
  }
}

/*
 * File trailer for median.c
 *
 * [EOF]
 */
