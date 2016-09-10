/*
 * File: mldivide.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mldivide.h"
#include "yaapt_emxutil.h"
#include "colon.h"
#include "xgeqp3.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                emxArray_real_T *Y
 * Return Type  : void
 */
void mldivide(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *Y)
{
  emxArray_real_T *b_A;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  emxArray_real_T *b_B;
  unsigned int unnamed_idx_0;
  int i9;
  int n;
  int minmn;
  int rankR;
  int maxmn;
  int j;
  int mmj;
  int c;
  int ix;
  double wj;
  int i10;
  int mn;
  int i;
  double s;
  emxInit_real_T(&b_A, 2);
  emxInit_real_T1(&tau, 1);
  emxInit_int32_T(&jpvt, 2);
  emxInit_real_T1(&b_B, 1);
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0)) {
    unnamed_idx_0 = (unsigned int)A->size[1];
    i9 = Y->size[0];
    Y->size[0] = (int)unnamed_idx_0;
    emxEnsureCapacity((emxArray__common *)Y, i9, (int)sizeof(double));
    minmn = (int)unnamed_idx_0;
    for (i9 = 0; i9 < minmn; i9++) {
      Y->data[i9] = 0.0;
    }
  } else if (A->size[0] == A->size[1]) {
    n = A->size[1];
    i9 = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity((emxArray__common *)b_A, i9, (int)sizeof(double));
    minmn = A->size[0] * A->size[1];
    for (i9 = 0; i9 < minmn; i9++) {
      b_A->data[i9] = A->data[i9];
    }

    minmn = A->size[1];
    eml_signed_integer_colon(minmn, jpvt);
    if (A->size[1] - 1 <= A->size[1]) {
      i9 = A->size[1] - 1;
    } else {
      i9 = A->size[1];
    }

    for (j = 0; j + 1 <= i9; j++) {
      mmj = n - j;
      c = j * (n + 1);
      if (mmj < 1) {
        minmn = -1;
      } else {
        minmn = 0;
        if (mmj > 1) {
          ix = c;
          wj = fabs(b_A->data[c]);
          for (maxmn = 2; maxmn <= mmj; maxmn++) {
            ix++;
            s = fabs(b_A->data[ix]);
            if (s > wj) {
              minmn = maxmn - 1;
              wj = s;
            }
          }
        }
      }

      if (b_A->data[c + minmn] != 0.0) {
        if (minmn != 0) {
          jpvt->data[j] = (j + minmn) + 1;
          ix = j;
          minmn += j;
          for (maxmn = 1; maxmn <= n; maxmn++) {
            wj = b_A->data[ix];
            b_A->data[ix] = b_A->data[minmn];
            b_A->data[minmn] = wj;
            ix += n;
            minmn += n;
          }
        }

        i10 = c + mmj;
        for (i = c + 1; i + 1 <= i10; i++) {
          b_A->data[i] /= b_A->data[c];
        }
      }

      minmn = n - j;
      maxmn = (c + n) + 1;
      mn = c + n;
      for (rankR = 1; rankR < minmn; rankR++) {
        wj = b_A->data[mn];
        if (b_A->data[mn] != 0.0) {
          ix = c + 1;
          i10 = mmj + maxmn;
          for (i = maxmn; i + 1 < i10; i++) {
            b_A->data[i] += b_A->data[ix] * -wj;
            ix++;
          }
        }

        mn += n;
        maxmn += n;
      }
    }

    i9 = Y->size[0];
    Y->size[0] = B->size[0];
    emxEnsureCapacity((emxArray__common *)Y, i9, (int)sizeof(double));
    minmn = B->size[0];
    for (i9 = 0; i9 < minmn; i9++) {
      Y->data[i9] = B->data[i9];
    }

    for (minmn = 0; minmn + 1 < n; minmn++) {
      if (jpvt->data[minmn] != minmn + 1) {
        wj = Y->data[minmn];
        Y->data[minmn] = Y->data[jpvt->data[minmn] - 1];
        Y->data[jpvt->data[minmn] - 1] = wj;
      }
    }

    for (maxmn = 0; maxmn + 1 <= n; maxmn++) {
      minmn = n * maxmn;
      if (Y->data[maxmn] != 0.0) {
        for (i = maxmn + 1; i + 1 <= n; i++) {
          Y->data[i] -= Y->data[maxmn] * b_A->data[i + minmn];
        }
      }
    }

    for (maxmn = A->size[1] - 1; maxmn + 1 > 0; maxmn--) {
      minmn = n * maxmn;
      if (Y->data[maxmn] != 0.0) {
        wj = b_A->data[maxmn + minmn];
        Y->data[maxmn] /= wj;
        for (i = 0; i + 1 <= maxmn; i++) {
          Y->data[i] -= Y->data[maxmn] * b_A->data[i + minmn];
        }
      }
    }
  } else {
    i9 = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity((emxArray__common *)b_A, i9, (int)sizeof(double));
    minmn = A->size[0] * A->size[1];
    for (i9 = 0; i9 < minmn; i9++) {
      b_A->data[i9] = A->data[i9];
    }

    xgeqp3(b_A, tau, jpvt);
    rankR = 0;
    if (b_A->size[0] < b_A->size[1]) {
      minmn = b_A->size[0];
      maxmn = b_A->size[1];
    } else {
      minmn = b_A->size[1];
      maxmn = b_A->size[0];
    }

    if (minmn > 0) {
      while ((rankR < minmn) && (fabs(b_A->data[rankR + b_A->size[0] * rankR]) >=
              (double)maxmn * fabs(b_A->data[0]) * 2.2204460492503131E-16)) {
        rankR++;
      }
    }

    minmn = b_A->size[1];
    i9 = Y->size[0];
    Y->size[0] = minmn;
    emxEnsureCapacity((emxArray__common *)Y, i9, (int)sizeof(double));
    for (i9 = 0; i9 < minmn; i9++) {
      Y->data[i9] = 0.0;
    }

    i9 = b_B->size[0];
    b_B->size[0] = B->size[0];
    emxEnsureCapacity((emxArray__common *)b_B, i9, (int)sizeof(double));
    minmn = B->size[0];
    for (i9 = 0; i9 < minmn; i9++) {
      b_B->data[i9] = B->data[i9];
    }

    maxmn = b_A->size[0];
    minmn = b_A->size[0];
    mn = b_A->size[1];
    if (minmn <= mn) {
      mn = minmn;
    }

    for (j = 0; j + 1 <= mn; j++) {
      if (tau->data[j] != 0.0) {
        wj = b_B->data[j];
        for (i = j + 1; i + 1 <= maxmn; i++) {
          wj += b_A->data[i + b_A->size[0] * j] * b_B->data[i];
        }

        wj *= tau->data[j];
        if (wj != 0.0) {
          b_B->data[j] -= wj;
          for (i = j + 1; i + 1 <= maxmn; i++) {
            b_B->data[i] -= b_A->data[i + b_A->size[0] * j] * wj;
          }
        }
      }
    }

    for (i = 0; i + 1 <= rankR; i++) {
      Y->data[jpvt->data[i] - 1] = b_B->data[i];
    }

    for (j = rankR - 1; j + 1 > 0; j--) {
      Y->data[jpvt->data[j] - 1] /= b_A->data[j + b_A->size[0] * j];
      for (i = 0; i + 1 <= j; i++) {
        Y->data[jpvt->data[i] - 1] -= Y->data[jpvt->data[j] - 1] * b_A->data[i +
          b_A->size[0] * j];
      }
    }
  }

  emxFree_real_T(&b_B);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&tau);
  emxFree_real_T(&b_A);
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
