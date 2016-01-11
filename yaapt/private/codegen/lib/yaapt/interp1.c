/*
 * File: interp1.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 12-Jan-2016 01:25:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "interp1.h"
#include "yaapt_emxutil.h"
#include "pchip.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *varargin_1
 *                const emxArray_real_T *varargin_2
 *                const emxArray_real_T *varargin_3
 *                emxArray_real_T *Vq
 * Return Type  : void
 */
void interp1(const emxArray_real_T *varargin_1, const emxArray_real_T
             *varargin_2, const emxArray_real_T *varargin_3, emxArray_real_T *Vq)
{
  emxArray_real_T *y;
  int high_i;
  int nd2;
  emxArray_real_T *x;
  int nx;
  unsigned int outsize[2];
  int k;
  emxArray_real_T *pp_breaks;
  emxArray_real_T *pp_coefs;
  emxArray_real_T *b_y;
  int exitg1;
  int low_i;
  double xloc;
  double v;
  emxInit_real_T(&y, 2);
  high_i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_2->size[1];
  emxEnsureCapacity((emxArray__common *)y, high_i, (int)sizeof(double));
  nd2 = varargin_2->size[0] * varargin_2->size[1];
  for (high_i = 0; high_i < nd2; high_i++) {
    y->data[high_i] = varargin_2->data[high_i];
  }

  emxInit_real_T(&x, 2);
  high_i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = varargin_1->size[1];
  emxEnsureCapacity((emxArray__common *)x, high_i, (int)sizeof(double));
  nd2 = varargin_1->size[0] * varargin_1->size[1];
  for (high_i = 0; high_i < nd2; high_i++) {
    x->data[high_i] = varargin_1->data[high_i];
  }

  nx = varargin_1->size[1];
  for (high_i = 0; high_i < 2; high_i++) {
    outsize[high_i] = (unsigned int)varargin_3->size[high_i];
  }

  high_i = Vq->size[0] * Vq->size[1];
  Vq->size[0] = 1;
  Vq->size[1] = (int)outsize[1];
  emxEnsureCapacity((emxArray__common *)Vq, high_i, (int)sizeof(double));
  nd2 = (int)outsize[1];
  for (high_i = 0; high_i < nd2; high_i++) {
    Vq->data[high_i] = 0.0;
  }

  if (varargin_3->size[1] == 0) {
  } else {
    k = 1;
    emxInit_real_T(&pp_breaks, 2);
    emxInit_real_T(&pp_coefs, 2);
    emxInit_real_T(&b_y, 2);
    do {
      exitg1 = 0;
      if (k <= nx) {
        if (rtIsNaN(varargin_1->data[k - 1])) {
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        if (varargin_1->data[1] < varargin_1->data[0]) {
          high_i = nx >> 1;
          for (low_i = 1; low_i <= high_i; low_i++) {
            xloc = x->data[low_i - 1];
            x->data[low_i - 1] = x->data[nx - low_i];
            x->data[nx - low_i] = xloc;
          }

          nd2 = varargin_2->size[1] >> 1;
          for (low_i = 1; low_i <= nd2; low_i++) {
            high_i = varargin_2->size[1] - low_i;
            xloc = y->data[low_i - 1];
            y->data[low_i - 1] = y->data[high_i];
            y->data[high_i] = xloc;
          }
        }

        nd2 = y->size[1];
        high_i = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = nd2;
        emxEnsureCapacity((emxArray__common *)b_y, high_i, (int)sizeof(double));
        for (high_i = 0; high_i < nd2; high_i++) {
          b_y->data[b_y->size[0] * high_i] = y->data[high_i];
        }

        pchip(x, b_y, pp_breaks, pp_coefs);
        for (k = 0; k + 1 <= varargin_3->size[1]; k++) {
          if (rtIsNaN(varargin_3->data[k])) {
            Vq->data[k] = rtNaN;
          } else {
            if (rtIsNaN(varargin_3->data[k])) {
              v = varargin_3->data[k];
            } else {
              low_i = 1;
              nd2 = 2;
              high_i = pp_breaks->size[1];
              while (high_i > nd2) {
                nx = (low_i >> 1) + (high_i >> 1);
                if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
                  nx++;
                }

                if (varargin_3->data[k] >= pp_breaks->data[nx - 1]) {
                  low_i = nx;
                  nd2 = nx + 1;
                } else {
                  high_i = nx;
                }
              }

              xloc = varargin_3->data[k] - pp_breaks->data[low_i - 1];
              v = pp_coefs->data[low_i - 1];
              for (nd2 = 0; nd2 < 3; nd2++) {
                v = xloc * v + pp_coefs->data[(low_i + (nd2 + 1) *
                  (pp_breaks->size[1] - 1)) - 1];
              }
            }

            Vq->data[k] = v;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_real_T(&b_y);
    emxFree_real_T(&pp_coefs);
    emxFree_real_T(&pp_breaks);
  }

  emxFree_real_T(&x);
  emxFree_real_T(&y);
}

/*
 * File trailer for interp1.c
 *
 * [EOF]
 */
