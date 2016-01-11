/*
 * File: pchip.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 12-Jan-2016 01:25:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "pchip.h"
#include "yaapt_emxutil.h"

/* Function Declarations */
static double exteriorSlope(double d1, double d2, double h1, double h2);

/* Function Definitions */

/*
 * Arguments    : double d1
 *                double d2
 *                double h1
 *                double h2
 * Return Type  : double
 */
static double exteriorSlope(double d1, double d2, double h1, double h2)
{
  double s;
  double signd1;
  double b_s;
  double b_d2;
  s = ((2.0 * h1 + h2) * d1 - h1 * d2) / (h1 + h2);
  if (d1 < 0.0) {
    signd1 = -1.0;
  } else if (d1 > 0.0) {
    signd1 = 1.0;
  } else if (d1 == 0.0) {
    signd1 = 0.0;
  } else {
    signd1 = d1;
  }

  if (s < 0.0) {
    b_s = -1.0;
  } else if (s > 0.0) {
    b_s = 1.0;
  } else if (s == 0.0) {
    b_s = 0.0;
  } else {
    b_s = s;
  }

  if (b_s != signd1) {
    s = 0.0;
  } else {
    if (d2 < 0.0) {
      b_d2 = -1.0;
    } else if (d2 > 0.0) {
      b_d2 = 1.0;
    } else if (d2 == 0.0) {
      b_d2 = 0.0;
    } else {
      b_d2 = d2;
    }

    if ((signd1 != b_d2) && (fabs(s) > fabs(3.0 * d1))) {
      s = 3.0 * d1;
    }
  }

  return s;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *v_breaks
 *                emxArray_real_T *v_coefs
 * Return Type  : void
 */
void pchip(const emxArray_real_T *x, const emxArray_real_T *y, emxArray_real_T
           *v_breaks, emxArray_real_T *v_coefs)
{
  emxArray_real_T *h;
  int nx;
  int i16;
  int k;
  int szdel[2];
  emxArray_real_T *del;
  emxArray_real_T *slopes;
  double hs;
  double hs3;
  double w1;
  emxInit_real_T(&h, 2);
  nx = x->size[1] - 1;
  i16 = h->size[0] * h->size[1];
  h->size[0] = 1;
  h->size[1] = x->size[1] - 1;
  emxEnsureCapacity((emxArray__common *)h, i16, (int)sizeof(double));
  for (k = 1; k <= nx; k++) {
    h->data[k - 1] = x->data[k] - x->data[k - 1];
  }

  for (i16 = 0; i16 < 2; i16++) {
    szdel[i16] = y->size[i16];
  }

  emxInit_real_T(&del, 2);
  szdel[1]--;
  i16 = del->size[0] * del->size[1];
  del->size[0] = 1;
  del->size[1] = szdel[1];
  emxEnsureCapacity((emxArray__common *)del, i16, (int)sizeof(double));
  for (k = 0; k + 1 <= nx; k++) {
    del->data[k] = (y->data[k + 1] - y->data[k]) / h->data[k];
  }

  emxInit_real_T(&slopes, 2);
  i16 = slopes->size[0] * slopes->size[1];
  slopes->size[0] = 1;
  slopes->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)slopes, i16, (int)sizeof(double));
  if (x->size[1] == 2) {
    for (k = 0; k < 2; k++) {
      slopes->data[k] = del->data[0];
    }
  } else {
    for (k = 1; k < nx; k++) {
      hs = h->data[k - 1] + h->data[k];
      hs3 = 3.0 * hs;
      w1 = (h->data[k - 1] + hs) / hs3;
      hs = (h->data[k] + hs) / hs3;
      hs3 = 0.0;
      if (del->data[k - 1] < 0.0) {
        if (del->data[k] <= del->data[k - 1]) {
          hs3 = del->data[k - 1] / (w1 * (del->data[k - 1] / del->data[k]) + hs);
        } else {
          if (del->data[k] < 0.0) {
            hs3 = del->data[k] / (w1 + hs * (del->data[k] / del->data[k - 1]));
          }
        }
      } else {
        if (del->data[k - 1] > 0.0) {
          if (del->data[k] >= del->data[k - 1]) {
            hs3 = del->data[k - 1] / (w1 * (del->data[k - 1] / del->data[k]) +
              hs);
          } else {
            if (del->data[k] > 0.0) {
              hs3 = del->data[k] / (w1 + hs * (del->data[k] / del->data[k - 1]));
            }
          }
        }
      }

      slopes->data[k] = hs3;
    }

    slopes->data[0] = exteriorSlope(del->data[0], del->data[1], h->data[0],
      h->data[1]);
    slopes->data[x->size[1] - 1] = exteriorSlope(del->data[x->size[1] - 2],
      del->data[x->size[1] - 3], h->data[x->size[1] - 2], h->data[x->size[1] - 3]);
  }

  k = x->size[1];
  i16 = v_breaks->size[0] * v_breaks->size[1];
  v_breaks->size[0] = 1;
  v_breaks->size[1] = k;
  emxEnsureCapacity((emxArray__common *)v_breaks, i16, (int)sizeof(double));
  for (i16 = 0; i16 < k; i16++) {
    v_breaks->data[v_breaks->size[0] * i16] = x->data[i16];
  }

  nx = slopes->size[1] - 1;
  i16 = v_coefs->size[0] * v_coefs->size[1];
  v_coefs->size[0] = slopes->size[1] - 1;
  v_coefs->size[1] = 4;
  emxEnsureCapacity((emxArray__common *)v_coefs, i16, (int)sizeof(double));
  for (k = 0; k + 1 < x->size[1]; k++) {
    hs = (del->data[k] - slopes->data[k]) / h->data[k];
    hs3 = (slopes->data[k + 1] - del->data[k]) / h->data[k];
    v_coefs->data[k] = (hs3 - hs) / h->data[k];
    v_coefs->data[nx + k] = 2.0 * hs - hs3;
    v_coefs->data[(nx << 1) + k] = slopes->data[k];
    v_coefs->data[3 * nx + k] = y->data[k];
  }

  emxFree_real_T(&slopes);
  emxFree_real_T(&del);
  emxFree_real_T(&h);
}

/*
 * File trailer for pchip.c
 *
 * [EOF]
 */
