/*
 * File: xgeqp3.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xgeqp3.h"
#include "xscal.h"
#include "xnrm2.h"
#include "ixamax.h"
#include "yaapt_emxutil.h"
#include "colon.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *A
 *                emxArray_real_T *tau
 *                emxArray_int32_T *jpvt
 * Return Type  : void
 */
void xgeqp3(emxArray_real_T *A, emxArray_real_T *tau, emxArray_int32_T *jpvt)
{
  int m;
  int n;
  int mn;
  int i30;
  emxArray_real_T *work;
  int itemp;
  emxArray_real_T *vn1;
  emxArray_real_T *vn2;
  int k;
  int nmi;
  int i;
  double xnorm;
  int i_i;
  double beta1;
  int pvt;
  int mmi;
  double absxk;
  int ix;
  int iy;
  double t;
  int i_ip1;
  int lastv;
  int lastc;
  boolean_T exitg2;
  int exitg1;
  m = A->size[0];
  n = A->size[1];
  if (A->size[0] <= A->size[1]) {
    mn = A->size[0];
  } else {
    mn = A->size[1];
  }

  i30 = tau->size[0];
  tau->size[0] = mn;
  emxEnsureCapacity((emxArray__common *)tau, i30, (int)sizeof(double));
  eml_signed_integer_colon(A->size[1], jpvt);
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
  } else {
    emxInit_real_T2(&work, 1);
    itemp = A->size[1];
    i30 = work->size[0];
    work->size[0] = itemp;
    emxEnsureCapacity((emxArray__common *)work, i30, (int)sizeof(double));
    for (i30 = 0; i30 < itemp; i30++) {
      work->data[i30] = 0.0;
    }

    emxInit_real_T2(&vn1, 1);
    emxInit_real_T2(&vn2, 1);
    itemp = A->size[1];
    i30 = vn1->size[0];
    vn1->size[0] = itemp;
    emxEnsureCapacity((emxArray__common *)vn1, i30, (int)sizeof(double));
    i30 = vn2->size[0];
    vn2->size[0] = vn1->size[0];
    emxEnsureCapacity((emxArray__common *)vn2, i30, (int)sizeof(double));
    k = 0;
    for (nmi = 0; nmi + 1 <= n; nmi++) {
      xnorm = 0.0;
      if (m < 1) {
      } else if (m == 1) {
        xnorm = fabs(A->data[k]);
      } else {
        beta1 = 2.2250738585072014E-308;
        pvt = k + m;
        for (itemp = k; itemp + 1 <= pvt; itemp++) {
          absxk = fabs(A->data[itemp]);
          if (absxk > beta1) {
            t = beta1 / absxk;
            xnorm = 1.0 + xnorm * t * t;
            beta1 = absxk;
          } else {
            t = absxk / beta1;
            xnorm += t * t;
          }
        }

        xnorm = beta1 * sqrt(xnorm);
      }

      vn1->data[nmi] = xnorm;
      vn2->data[nmi] = vn1->data[nmi];
      k += m;
    }

    for (i = 0; i + 1 <= mn; i++) {
      i_i = i + i * m;
      nmi = n - i;
      mmi = (m - i) - 1;
      itemp = ixamax(nmi, vn1, i + 1);
      pvt = (i + itemp) - 1;
      if (pvt + 1 != i + 1) {
        ix = m * pvt;
        iy = m * i;
        for (k = 1; k <= m; k++) {
          xnorm = A->data[ix];
          A->data[ix] = A->data[iy];
          A->data[iy] = xnorm;
          ix++;
          iy++;
        }

        itemp = jpvt->data[pvt];
        jpvt->data[pvt] = jpvt->data[i];
        jpvt->data[i] = itemp;
        vn1->data[pvt] = vn1->data[i];
        vn2->data[pvt] = vn2->data[i];
      }

      if (i + 1 < m) {
        t = A->data[i_i];
        absxk = 0.0;
        if (1 + mmi <= 0) {
        } else {
          xnorm = xnrm2(mmi, A, i_i + 2);
          if (xnorm != 0.0) {
            beta1 = rt_hypotd_snf(A->data[i_i], xnorm);
            if (A->data[i_i] >= 0.0) {
              beta1 = -beta1;
            }

            if (fabs(beta1) < 1.0020841800044864E-292) {
              itemp = 0;
              do {
                itemp++;
                xscal(mmi, 9.9792015476736E+291, A, i_i + 2);
                beta1 *= 9.9792015476736E+291;
                t *= 9.9792015476736E+291;
              } while (!(fabs(beta1) >= 1.0020841800044864E-292));

              xnorm = xnrm2(mmi, A, i_i + 2);
              beta1 = rt_hypotd_snf(t, xnorm);
              if (t >= 0.0) {
                beta1 = -beta1;
              }

              absxk = (beta1 - t) / beta1;
              xscal(mmi, 1.0 / (t - beta1), A, i_i + 2);
              for (k = 1; k <= itemp; k++) {
                beta1 *= 1.0020841800044864E-292;
              }

              t = beta1;
            } else {
              absxk = (beta1 - A->data[i_i]) / beta1;
              xscal(mmi, 1.0 / (A->data[i_i] - beta1), A, i_i + 2);
              t = beta1;
            }
          }
        }

        tau->data[i] = absxk;
        A->data[i_i] = t;
      } else {
        tau->data[i] = 0.0;
      }

      if (i + 1 < n) {
        t = A->data[i_i];
        A->data[i_i] = 1.0;
        i_ip1 = (i + (i + 1) * m) + 1;
        if (tau->data[i] != 0.0) {
          lastv = mmi + 1;
          itemp = i_i + mmi;
          while ((lastv > 0) && (A->data[itemp] == 0.0)) {
            lastv--;
            itemp--;
          }

          lastc = nmi - 1;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            itemp = i_ip1 + (lastc - 1) * m;
            k = itemp;
            do {
              exitg1 = 0;
              if (k <= (itemp + lastv) - 1) {
                if (A->data[k - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  k++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = 0;
          lastc = 0;
        }

        if (lastv > 0) {
          if (lastc == 0) {
          } else {
            for (iy = 1; iy <= lastc; iy++) {
              work->data[iy - 1] = 0.0;
            }

            iy = 0;
            i30 = i_ip1 + m * (lastc - 1);
            itemp = i_ip1;
            while ((m > 0) && (itemp <= i30)) {
              ix = i_i;
              xnorm = 0.0;
              pvt = (itemp + lastv) - 1;
              for (k = itemp; k <= pvt; k++) {
                xnorm += A->data[k - 1] * A->data[ix];
                ix++;
              }

              work->data[iy] += xnorm;
              iy++;
              itemp += m;
            }
          }

          if (-tau->data[i] == 0.0) {
          } else {
            itemp = i_ip1 - 1;
            pvt = 0;
            for (nmi = 1; nmi <= lastc; nmi++) {
              if (work->data[pvt] != 0.0) {
                xnorm = work->data[pvt] * -tau->data[i];
                ix = i_i;
                i30 = lastv + itemp;
                for (k = itemp; k + 1 <= i30; k++) {
                  A->data[k] += A->data[ix] * xnorm;
                  ix++;
                }
              }

              pvt++;
              itemp += m;
            }
          }
        }

        A->data[i_i] = t;
      }

      for (nmi = i + 1; nmi + 1 <= n; nmi++) {
        itemp = (i + m * nmi) + 1;
        if (vn1->data[nmi] != 0.0) {
          xnorm = fabs(A->data[i + A->size[0] * nmi]) / vn1->data[nmi];
          xnorm = 1.0 - xnorm * xnorm;
          if (xnorm < 0.0) {
            xnorm = 0.0;
          }

          beta1 = vn1->data[nmi] / vn2->data[nmi];
          beta1 = xnorm * (beta1 * beta1);
          if (beta1 <= 1.4901161193847656E-8) {
            if (i + 1 < m) {
              xnorm = 0.0;
              if (mmi < 1) {
              } else if (mmi == 1) {
                xnorm = fabs(A->data[itemp]);
              } else {
                beta1 = 2.2250738585072014E-308;
                pvt = itemp + mmi;
                while (itemp + 1 <= pvt) {
                  absxk = fabs(A->data[itemp]);
                  if (absxk > beta1) {
                    t = beta1 / absxk;
                    xnorm = 1.0 + xnorm * t * t;
                    beta1 = absxk;
                  } else {
                    t = absxk / beta1;
                    xnorm += t * t;
                  }

                  itemp++;
                }

                xnorm = beta1 * sqrt(xnorm);
              }

              vn1->data[nmi] = xnorm;
              vn2->data[nmi] = vn1->data[nmi];
            } else {
              vn1->data[nmi] = 0.0;
              vn2->data[nmi] = 0.0;
            }
          } else {
            vn1->data[nmi] *= sqrt(xnorm);
          }
        }
      }
    }

    emxFree_real_T(&vn2);
    emxFree_real_T(&vn1);
    emxFree_real_T(&work);
  }
}

/*
 * File trailer for xgeqp3.c
 *
 * [EOF]
 */
