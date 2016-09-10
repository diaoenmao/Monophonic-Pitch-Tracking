/*
 * File: median.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
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
  int i22;
  int i;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  int midm1;
  int b_i;
  double m;
  boolean_T p;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  i22 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)y, i22, (int)sizeof(double));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    i22 = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, i22, (int)sizeof(double));
    midm1 = y->size[1];
    for (i22 = 0; i22 < midm1; i22++) {
      y->data[y->size[0] * i22] = rtNaN;
    }
  } else {
    i = 0;
    emxInit_int32_T1(&idx, 1);
    emxInit_int32_T1(&iwork, 1);
    while (i + 1 <= x->size[1]) {
      midm1 = x->size[0];
      i22 = idx->size[0];
      idx->size[0] = midm1;
      emxEnsureCapacity((emxArray__common *)idx, i22, (int)sizeof(int));
      for (i22 = 0; i22 < midm1; i22++) {
        idx->data[i22] = 0;
      }

      i22 = x->size[0] + 1;
      b_i = iwork->size[0];
      iwork->size[0] = midm1;
      emxEnsureCapacity((emxArray__common *)iwork, b_i, (int)sizeof(int));
      for (midm1 = 1; midm1 <= i22 - 2; midm1 += 2) {
        m = x->data[midm1 + x->size[0] * i];
        if ((x->data[(midm1 + x->size[0] * i) - 1] <= m) || rtIsNaN(m)) {
          p = true;
        } else {
          p = false;
        }

        if (p) {
          idx->data[midm1 - 1] = midm1;
          idx->data[midm1] = midm1 + 1;
        } else {
          idx->data[midm1 - 1] = midm1 + 1;
          idx->data[midm1] = midm1;
        }
      }

      b_i = x->size[0];
      if ((b_i & 1) != 0) {
        b_i = x->size[0] - 1;
        midm1 = x->size[0];
        idx->data[b_i] = midm1;
      }

      b_i = 2;
      while (b_i < i22 - 1) {
        i2 = b_i << 1;
        j = 1;
        for (pEnd = 1 + b_i; pEnd < i22; pEnd = qEnd + b_i) {
          b_p = j;
          q = pEnd;
          qEnd = j + i2;
          if (qEnd > i22) {
            qEnd = i22;
          }

          midm1 = 0;
          kEnd = qEnd - j;
          while (midm1 + 1 <= kEnd) {
            m = x->data[(idx->data[q - 1] + x->size[0] * i) - 1];
            if ((x->data[(idx->data[b_p - 1] + x->size[0] * i) - 1] <= m) ||
                rtIsNaN(m)) {
              p = true;
            } else {
              p = false;
            }

            if (p) {
              iwork->data[midm1] = idx->data[b_p - 1];
              b_p++;
              if (b_p == pEnd) {
                while (q < qEnd) {
                  midm1++;
                  iwork->data[midm1] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[midm1] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (b_p < pEnd) {
                  midm1++;
                  iwork->data[midm1] = idx->data[b_p - 1];
                  b_p++;
                }
              }
            }

            midm1++;
          }

          for (midm1 = 0; midm1 + 1 <= kEnd; midm1++) {
            idx->data[(j + midm1) - 1] = iwork->data[midm1];
          }

          j = qEnd;
        }

        b_i = i2;
      }

      i22 = x->size[0];
      midm1 = i22 >> 1;
      i22 = x->size[0];
      if (rtIsNaN(x->data[(idx->data[i22 - 1] + x->size[0] * i) - 1])) {
        m = rtNaN;
      } else {
        i22 = x->size[0];
        if ((i22 & 1) == 0) {
          if (((x->data[(idx->data[midm1 - 1] + x->size[0] * i) - 1] < 0.0) &&
               (x->data[(idx->data[midm1] + x->size[0] * i) - 1] >= 0.0)) ||
              rtIsInf(x->data[(idx->data[midm1 - 1] + x->size[0] * i) - 1]) ||
              rtIsInf(x->data[(idx->data[midm1] + x->size[0] * i) - 1])) {
            m = (x->data[(idx->data[midm1 - 1] + x->size[0] * i) - 1] + x->data
                 [(idx->data[midm1] + x->size[0] * i) - 1]) / 2.0;
          } else {
            m = x->data[(idx->data[midm1 - 1] + x->size[0] * i) - 1] + (x->data
              [(idx->data[midm1] + x->size[0] * i) - 1] - x->data[(idx->
              data[midm1 - 1] + x->size[0] * i) - 1]) / 2.0;
          }
        } else {
          m = x->data[(idx->data[midm1] + x->size[0] * i) - 1];
        }
      }

      y->data[i] = m;
      i++;
    }

    emxFree_int32_T(&iwork);
    emxFree_int32_T(&idx);
  }
}

/*
 * File trailer for median.c
 *
 * [EOF]
 */
