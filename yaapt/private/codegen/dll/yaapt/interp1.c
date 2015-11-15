/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: interp1.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:15:57
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
  int j2;
  int nd2;
  emxArray_real_T *x;
  int nx;
  unsigned int outsize[2];
  emxArray_real_T *xi;
  struct_T pp;
  emxArray_real_T *b_y;
  int exitg1;
  int b_j1;
  double xtmp;
  int k;
  int b_k;
  double v;
  int low_i;
  int low_ip1;
  int high_i;
  int mid_i;
  double xloc;
  emxInit_real_T(&y, 2);
  j2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_2->size[1];
  emxEnsureCapacity((emxArray__common *)y, j2, (int)sizeof(double));
  nd2 = varargin_2->size[0] * varargin_2->size[1];
  for (j2 = 0; j2 < nd2; j2++) {
    y->data[j2] = varargin_2->data[j2];
  }

  emxInit_real_T(&x, 2);
  j2 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = varargin_1->size[1];
  emxEnsureCapacity((emxArray__common *)x, j2, (int)sizeof(double));
  nd2 = varargin_1->size[0] * varargin_1->size[1];
  for (j2 = 0; j2 < nd2; j2++) {
    x->data[j2] = varargin_1->data[j2];
  }

  nx = varargin_1->size[1];
  for (j2 = 0; j2 < 2; j2++) {
    outsize[j2] = (unsigned int)varargin_3->size[j2];
  }

  j2 = Vq->size[0] * Vq->size[1];
  Vq->size[0] = 1;
  Vq->size[1] = (int)outsize[1];
  emxEnsureCapacity((emxArray__common *)Vq, j2, (int)sizeof(double));
  nd2 = (int)outsize[1];
  for (j2 = 0; j2 < nd2; j2++) {
    Vq->data[j2] = 0.0;
  }

  if (varargin_3->size[1] == 0) {
  } else {
    nd2 = 1;
    emxInit_real_T(&xi, 2);
    emxInitStruct_struct_T(&pp);
    emxInit_real_T(&b_y, 2);
    do {
      exitg1 = 0;
      if (nd2 <= nx) {
        if (rtIsNaN(varargin_1->data[nd2 - 1])) {
          exitg1 = 1;
        } else {
          nd2++;
        }
      } else {
        if (varargin_1->data[1] < varargin_1->data[0]) {
          j2 = nx >> 1;
          for (b_j1 = 1; b_j1 <= j2; b_j1++) {
            xtmp = x->data[b_j1 - 1];
            x->data[b_j1 - 1] = x->data[nx - b_j1];
            x->data[nx - b_j1] = xtmp;
          }

          nd2 = varargin_2->size[1] >> 1;
          for (b_j1 = 1; b_j1 <= nd2; b_j1++) {
            j2 = varargin_2->size[1] - b_j1;
            xtmp = y->data[b_j1 - 1];
            y->data[b_j1 - 1] = y->data[j2];
            y->data[j2] = xtmp;
          }
        }

        j2 = xi->size[0] * xi->size[1];
        xi->size[0] = 1;
        xi->size[1] = varargin_3->size[1];
        emxEnsureCapacity((emxArray__common *)xi, j2, (int)sizeof(double));
        nd2 = varargin_3->size[0] * varargin_3->size[1];
        for (j2 = 0; j2 < nd2; j2++) {
          xi->data[j2] = varargin_3->data[j2];
        }

        nd2 = y->size[1];
        j2 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = nd2;
        emxEnsureCapacity((emxArray__common *)b_y, j2, (int)sizeof(double));
        for (j2 = 0; j2 < nd2; j2++) {
          b_y->data[b_y->size[0] * j2] = y->data[j2];
        }

        pchip(x, b_y, pp.breaks, pp.coefs);
        nd2 = varargin_3->size[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_k,low_i,v,low_ip1,high_i,xloc,mid_i)

        for (k = 1; k <= nd2; k++) {
          b_k = k;
          if (rtIsNaN(xi->data[b_k - 1])) {
            Vq->data[b_k - 1] = rtNaN;
          } else {
            if (rtIsNaN(xi->data[b_k - 1])) {
              v = xi->data[b_k - 1];
            } else {
              low_i = 1;
              low_ip1 = 2;
              high_i = pp.breaks->size[1];
              while (high_i > low_ip1) {
                mid_i = (low_i >> 1) + (high_i >> 1);
                if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
                  mid_i++;
                }

                if (xi->data[b_k - 1] >= pp.breaks->data[mid_i - 1]) {
                  low_i = mid_i;
                  low_ip1 = mid_i + 1;
                } else {
                  high_i = mid_i;
                }
              }

              xloc = xi->data[b_k - 1] - pp.breaks->data[low_i - 1];
              v = pp.coefs->data[low_i - 1];
              for (low_ip1 = 0; low_ip1 < 3; low_ip1++) {
                v = xloc * v + pp.coefs->data[(low_i + (low_ip1 + 1) *
                  (pp.breaks->size[1] - 1)) - 1];
              }
            }

            Vq->data[b_k - 1] = v;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_real_T(&b_y);
    emxFreeStruct_struct_T(&pp);
    emxFree_real_T(&xi);
  }

  emxFree_real_T(&x);
  emxFree_real_T(&y);
}

/*
 * File trailer for interp1.c
 *
 * [EOF]
 */
