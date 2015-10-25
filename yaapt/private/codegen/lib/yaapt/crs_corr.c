/*
 * File: crs_corr.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 25-Oct-2015 03:48:36
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "crs_corr.h"
#include "yaapt_emxutil.h"
#include "colon.h"
#include "mean.h"
#include "yaapt_rtwutil.h"

/* Function Declarations */
static int eml_ixamax(int n, const emxArray_real_T *x, int ix0);
static void eml_lusolve(const emxArray_real_T *A, const emxArray_real_T *B,
  emxArray_real_T *X);
static void eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B,
  emxArray_real_T *Y);
static double eml_xnrm2(int n, const emxArray_real_T *x, int ix0);
static void eml_xscal(int n, double a, emxArray_real_T *x, int ix0);

/* Function Definitions */

/*
 * Arguments    : int n
 *                const emxArray_real_T *x
 *                int ix0
 * Return Type  : int
 */
static int eml_ixamax(int n, const emxArray_real_T *x, int ix0)
{
  int idxmax;
  int ix;
  double smax;
  int k;
  double s;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      ix = ix0 - 1;
      smax = fabs(x->data[ix0 - 1]);
      for (k = 2; k <= n; k++) {
        ix++;
        s = fabs(x->data[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                emxArray_real_T *X
 * Return Type  : void
 */
static void eml_lusolve(const emxArray_real_T *A, const emxArray_real_T *B,
  emxArray_real_T *X)
{
  emxArray_real_T *b_A;
  int i21;
  int iy;
  emxArray_int32_T *ipiv;
  int j;
  int mmj;
  int c;
  int ix;
  double smax;
  int k;
  double s;
  int i22;
  int i;
  int jAcol;
  int jA;
  emxInit_real_T(&b_A, 2);
  i21 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)b_A, i21, (int)sizeof(double));
  iy = A->size[0] * A->size[1];
  for (i21 = 0; i21 < iy; i21++) {
    b_A->data[i21] = A->data[i21];
  }

  emxInit_int32_T(&ipiv, 2);
  iy = A->size[1];
  eml_signed_integer_colon(iy, ipiv);
  if (A->size[1] < 1) {
  } else {
    if (A->size[1] - 1 <= A->size[1]) {
      i21 = A->size[1] - 1;
    } else {
      i21 = A->size[1];
    }

    for (j = 0; j + 1 <= i21; j++) {
      mmj = A->size[1] - j;
      c = j * (A->size[1] + 1);
      if (mmj < 1) {
        iy = -1;
      } else {
        iy = 0;
        if (mmj > 1) {
          ix = c;
          smax = fabs(b_A->data[c]);
          for (k = 1; k + 1 <= mmj; k++) {
            ix++;
            s = fabs(b_A->data[ix]);
            if (s > smax) {
              iy = k;
              smax = s;
            }
          }
        }
      }

      if (b_A->data[c + iy] != 0.0) {
        if (iy != 0) {
          ipiv->data[j] = (j + iy) + 1;
          ix = j;
          iy += j;
          for (k = 1; k <= A->size[1]; k++) {
            smax = b_A->data[ix];
            b_A->data[ix] = b_A->data[iy];
            b_A->data[iy] = smax;
            ix += A->size[1];
            iy += A->size[1];
          }
        }

        i22 = c + mmj;
        for (i = c + 1; i + 1 <= i22; i++) {
          b_A->data[i] /= b_A->data[c];
        }
      }

      jAcol = (A->size[1] - j) - 1;
      jA = c + A->size[1];
      iy = c + A->size[1];
      for (i = 1; i <= jAcol; i++) {
        smax = b_A->data[iy];
        if (b_A->data[iy] != 0.0) {
          ix = c + 1;
          i22 = mmj + jA;
          for (k = 1 + jA; k + 1 <= i22; k++) {
            b_A->data[k] += b_A->data[ix] * -smax;
            ix++;
          }
        }

        iy += A->size[1];
        jA += A->size[1];
      }
    }
  }

  i21 = X->size[0] * X->size[1];
  X->size[0] = B->size[0];
  X->size[1] = B->size[1];
  emxEnsureCapacity((emxArray__common *)X, i21, (int)sizeof(double));
  iy = B->size[0] * B->size[1];
  for (i21 = 0; i21 < iy; i21++) {
    X->data[i21] = B->data[i21];
  }

  if ((A->size[1] == 0) || ((B->size[0] == 0) || (B->size[1] == 0))) {
  } else {
    for (j = 0; j + 1 <= A->size[1]; j++) {
      iy = B->size[0] * j;
      jAcol = A->size[1] * j;
      for (k = 0; k + 1 <= j; k++) {
        jA = B->size[0] * k;
        if (b_A->data[k + jAcol] != 0.0) {
          for (i = 0; i + 1 <= B->size[0]; i++) {
            X->data[i + iy] -= b_A->data[k + jAcol] * X->data[i + jA];
          }
        }
      }

      smax = 1.0 / b_A->data[j + jAcol];
      for (i = 0; i + 1 <= B->size[0]; i++) {
        X->data[i + iy] *= smax;
      }
    }
  }

  if ((A->size[1] == 0) || ((X->size[0] == 0) || (X->size[1] == 0))) {
  } else {
    for (j = A->size[1]; j > 0; j--) {
      iy = B->size[0] * (j - 1);
      jAcol = A->size[1] * (j - 1);
      for (k = j; k + 1 <= A->size[1]; k++) {
        jA = B->size[0] * k;
        if (b_A->data[k + jAcol] != 0.0) {
          for (i = 0; i + 1 <= B->size[0]; i++) {
            X->data[i + iy] -= b_A->data[k + jAcol] * X->data[i + jA];
          }
        }
      }
    }
  }

  emxFree_real_T(&b_A);
  for (iy = A->size[1] - 2; iy + 1 > 0; iy--) {
    if (ipiv->data[iy] != iy + 1) {
      for (jAcol = 0; jAcol + 1 <= B->size[0]; jAcol++) {
        smax = X->data[jAcol + X->size[0] * iy];
        X->data[jAcol + X->size[0] * iy] = X->data[jAcol + X->size[0] *
          (ipiv->data[iy] - 1)];
        X->data[jAcol + X->size[0] * (ipiv->data[iy] - 1)] = smax;
      }
    }
  }

  emxFree_int32_T(&ipiv);
}

/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *B
 *                emxArray_real_T *Y
 * Return Type  : void
 */
static void eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B,
  emxArray_real_T *Y)
{
  int nb;
  int mn;
  emxArray_real_T *b_A;
  int i23;
  int k;
  int m;
  int n;
  int b_mn;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  emxArray_real_T *work;
  emxArray_real_T *vn1;
  emxArray_real_T *vn2;
  int j;
  int i;
  int i_i;
  int nmi;
  int mmi;
  int pvt;
  int ix;
  int iy;
  double xnorm;
  double atmp;
  double absxk;
  int i_ip1;
  int lastv;
  boolean_T exitg2;
  int32_T exitg1;
  double t;
  unsigned int unnamed_idx_0;
  unsigned int unnamed_idx_1;
  nb = B->size[1] - 1;
  if (A->size[0] <= A->size[1]) {
    mn = A->size[0];
  } else {
    mn = A->size[1];
  }

  emxInit_real_T(&b_A, 2);
  i23 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)b_A, i23, (int)sizeof(double));
  k = A->size[0] * A->size[1];
  for (i23 = 0; i23 < k; i23++) {
    b_A->data[i23] = A->data[i23];
  }

  m = b_A->size[0];
  n = b_A->size[1];
  if (b_A->size[0] <= b_A->size[1]) {
    b_mn = b_A->size[0];
  } else {
    b_mn = b_A->size[1];
  }

  b_emxInit_real_T(&tau, 1);
  emxInit_int32_T(&jpvt, 2);
  i23 = tau->size[0];
  tau->size[0] = b_mn;
  emxEnsureCapacity((emxArray__common *)tau, i23, (int)sizeof(double));
  eml_signed_integer_colon(b_A->size[1], jpvt);
  if ((b_A->size[0] == 0) || (b_A->size[1] == 0)) {
  } else {
    b_emxInit_real_T(&work, 1);
    k = b_A->size[1];
    i23 = work->size[0];
    work->size[0] = k;
    emxEnsureCapacity((emxArray__common *)work, i23, (int)sizeof(double));
    for (i23 = 0; i23 < k; i23++) {
      work->data[i23] = 0.0;
    }

    b_emxInit_real_T(&vn1, 1);
    b_emxInit_real_T(&vn2, 1);
    k = b_A->size[1];
    i23 = vn1->size[0];
    vn1->size[0] = k;
    emxEnsureCapacity((emxArray__common *)vn1, i23, (int)sizeof(double));
    i23 = vn2->size[0];
    vn2->size[0] = k;
    emxEnsureCapacity((emxArray__common *)vn2, i23, (int)sizeof(double));
    k = 1;
    for (j = 0; j + 1 <= b_A->size[1]; j++) {
      vn1->data[j] = eml_xnrm2(b_A->size[0], b_A, k);
      vn2->data[j] = vn1->data[j];
      k += b_A->size[0];
    }

    for (i = 0; i + 1 <= b_mn; i++) {
      i_i = i + i * m;
      nmi = (n - i) - 1;
      mmi = (m - i) - 1;
      k = eml_ixamax(1 + nmi, vn1, i + 1);
      pvt = (i + k) - 1;
      if (pvt + 1 != i + 1) {
        ix = m * pvt;
        iy = m * i;
        for (k = 1; k <= m; k++) {
          xnorm = b_A->data[ix];
          b_A->data[ix] = b_A->data[iy];
          b_A->data[iy] = xnorm;
          ix++;
          iy++;
        }

        k = jpvt->data[pvt];
        jpvt->data[pvt] = jpvt->data[i];
        jpvt->data[i] = k;
        vn1->data[pvt] = vn1->data[i];
        vn2->data[pvt] = vn2->data[i];
      }

      if (i + 1 < m) {
        atmp = b_A->data[i_i];
        absxk = 0.0;
        if (1 + mmi <= 0) {
        } else {
          xnorm = eml_xnrm2(mmi, b_A, i_i + 2);
          if (xnorm != 0.0) {
            xnorm = rt_hypotd_snf(b_A->data[i_i], xnorm);
            if (b_A->data[i_i] >= 0.0) {
              xnorm = -xnorm;
            }

            if (fabs(xnorm) < 1.0020841800044864E-292) {
              pvt = 0;
              do {
                pvt++;
                eml_xscal(mmi, 9.9792015476736E+291, b_A, i_i + 2);
                xnorm *= 9.9792015476736E+291;
                atmp *= 9.9792015476736E+291;
              } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

              xnorm = eml_xnrm2(mmi, b_A, i_i + 2);
              xnorm = rt_hypotd_snf(atmp, xnorm);
              if (atmp >= 0.0) {
                xnorm = -xnorm;
              }

              absxk = (xnorm - atmp) / xnorm;
              eml_xscal(mmi, 1.0 / (atmp - xnorm), b_A, i_i + 2);
              for (k = 1; k <= pvt; k++) {
                xnorm *= 1.0020841800044864E-292;
              }

              atmp = xnorm;
            } else {
              absxk = (xnorm - b_A->data[i_i]) / xnorm;
              atmp = 1.0 / (b_A->data[i_i] - xnorm);
              eml_xscal(mmi, atmp, b_A, i_i + 2);
              atmp = xnorm;
            }
          }
        }

        tau->data[i] = absxk;
      } else {
        atmp = b_A->data[i_i];
        tau->data[i] = eml_matlab_zlarfg();
      }

      b_A->data[i_i] = atmp;
      if (i + 1 < n) {
        atmp = b_A->data[i_i];
        b_A->data[i_i] = 1.0;
        i_ip1 = (i + (i + 1) * m) + 1;
        if (tau->data[i] != 0.0) {
          lastv = mmi;
          k = i_i + mmi;
          while ((lastv + 1 > 0) && (b_A->data[k] == 0.0)) {
            lastv--;
            k--;
          }

          exitg2 = false;
          while ((!exitg2) && (nmi > 0)) {
            k = i_ip1 + (nmi - 1) * m;
            j = k;
            do {
              exitg1 = 0;
              if (j <= k + lastv) {
                if (b_A->data[j - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  j++;
                }
              } else {
                nmi--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = -1;
          nmi = 0;
        }

        if (lastv + 1 > 0) {
          if (nmi == 0) {
          } else {
            for (iy = 1; iy <= nmi; iy++) {
              work->data[iy - 1] = 0.0;
            }

            iy = 0;
            i23 = i_ip1 + m * (nmi - 1);
            pvt = i_ip1;
            while ((m > 0) && (pvt <= i23)) {
              ix = i_i;
              xnorm = 0.0;
              k = pvt + lastv;
              for (j = pvt; j <= k; j++) {
                xnorm += b_A->data[j - 1] * b_A->data[ix];
                ix++;
              }

              work->data[iy] += xnorm;
              iy++;
              pvt += m;
            }
          }

          if (-tau->data[i] == 0.0) {
          } else {
            pvt = 0;
            for (j = 1; j <= nmi; j++) {
              if (work->data[pvt] != 0.0) {
                xnorm = work->data[pvt] * -tau->data[i];
                ix = i_i;
                i23 = lastv + i_ip1;
                for (k = i_ip1; k <= i23; k++) {
                  b_A->data[k - 1] += b_A->data[ix] * xnorm;
                  ix++;
                }
              }

              pvt++;
              i_ip1 += m;
            }
          }
        }

        b_A->data[i_i] = atmp;
      }

      for (j = i + 1; j + 1 <= n; j++) {
        k = (i + m * j) + 1;
        if (vn1->data[j] != 0.0) {
          xnorm = fabs(b_A->data[i + b_A->size[0] * j]) / vn1->data[j];
          xnorm = 1.0 - xnorm * xnorm;
          if (xnorm < 0.0) {
            xnorm = 0.0;
          }

          atmp = vn1->data[j] / vn2->data[j];
          atmp = xnorm * (atmp * atmp);
          if (atmp <= 1.4901161193847656E-8) {
            if (i + 1 < m) {
              atmp = 0.0;
              if (mmi < 1) {
              } else if (mmi == 1) {
                atmp = fabs(b_A->data[k]);
              } else {
                xnorm = 2.2250738585072014E-308;
                pvt = k + mmi;
                while (k + 1 <= pvt) {
                  absxk = fabs(b_A->data[k]);
                  if (absxk > xnorm) {
                    t = xnorm / absxk;
                    atmp = 1.0 + atmp * t * t;
                    xnorm = absxk;
                  } else {
                    t = absxk / xnorm;
                    atmp += t * t;
                  }

                  k++;
                }

                atmp = xnorm * sqrt(atmp);
              }

              vn1->data[j] = atmp;
              vn2->data[j] = vn1->data[j];
            } else {
              vn1->data[j] = 0.0;
              vn2->data[j] = 0.0;
            }
          } else {
            vn1->data[j] *= sqrt(xnorm);
          }
        }
      }
    }

    emxFree_real_T(&vn2);
    emxFree_real_T(&vn1);
    emxFree_real_T(&work);
  }

  atmp = 0.0;
  if (mn > 0) {
    if (A->size[0] >= A->size[1]) {
      k = A->size[0];
    } else {
      k = A->size[1];
    }

    xnorm = (double)k * fabs(b_A->data[0]) * 2.2204460492503131E-16;
    k = 0;
    while ((k <= mn - 1) && (!(fabs(b_A->data[k + b_A->size[0] * k]) <= xnorm)))
    {
      atmp++;
      k++;
    }
  }

  unnamed_idx_0 = (unsigned int)A->size[1];
  unnamed_idx_1 = (unsigned int)B->size[1];
  i23 = Y->size[0] * Y->size[1];
  Y->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)Y, i23, (int)sizeof(double));
  i23 = Y->size[0] * Y->size[1];
  Y->size[1] = (int)unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)Y, i23, (int)sizeof(double));
  k = (int)unnamed_idx_0 * (int)unnamed_idx_1;
  for (i23 = 0; i23 < k; i23++) {
    Y->data[i23] = 0.0;
  }

  for (j = 0; j < mn; j++) {
    if (tau->data[j] != 0.0) {
      for (k = 0; k <= nb; k++) {
        xnorm = B->data[j + B->size[0] * k];
        i23 = A->size[0] + (int)(1.0 - ((1.0 + (double)j) + 1.0));
        for (i = 0; i < i23; i++) {
          unnamed_idx_0 = ((unsigned int)j + i) + 2U;
          xnorm += b_A->data[((int)unnamed_idx_0 + b_A->size[0] * j) - 1] *
            B->data[((int)unnamed_idx_0 + B->size[0] * k) - 1];
        }

        xnorm *= tau->data[j];
        if (xnorm != 0.0) {
          B->data[j + B->size[0] * k] -= xnorm;
          i23 = A->size[0] + (int)(1.0 - ((1.0 + (double)j) + 1.0));
          for (i = 0; i < i23; i++) {
            unnamed_idx_0 = ((unsigned int)j + i) + 2U;
            B->data[((int)unnamed_idx_0 + B->size[0] * k) - 1] -= b_A->data
              [((int)unnamed_idx_0 + b_A->size[0] * j) - 1] * xnorm;
          }
        }
      }
    }
  }

  emxFree_real_T(&tau);
  for (k = 0; k <= nb; k++) {
    for (i = 0; i < (int)atmp; i++) {
      Y->data[(jpvt->data[i] + Y->size[0] * k) - 1] = B->data[i + B->size[0] * k];
    }

    for (j = 0; j < (int)-(1.0 + (-1.0 - atmp)); j++) {
      xnorm = atmp + -(double)j;
      Y->data[(jpvt->data[(int)xnorm - 1] + Y->size[0] * k) - 1] /= b_A->data
        [((int)xnorm + b_A->size[0] * ((int)xnorm - 1)) - 1];
      for (i = 0; i <= (int)xnorm - 2; i++) {
        Y->data[(jpvt->data[i] + Y->size[0] * k) - 1] -= Y->data[(jpvt->data
          [(int)xnorm - 1] + Y->size[0] * k) - 1] * b_A->data[i + b_A->size[0] *
          ((int)xnorm - 1)];
      }
    }
  }

  emxFree_int32_T(&jpvt);
  emxFree_real_T(&b_A);
}

/*
 * Arguments    : int n
 *                const emxArray_real_T *x
 *                int ix0
 * Return Type  : double
 */
static double eml_xnrm2(int n, const emxArray_real_T *x, int ix0)
{
  double y;
  double scale;
  int kend;
  int k;
  double absxk;
  double t;
  y = 0.0;
  if (n < 1) {
  } else if (n == 1) {
    y = fabs(x->data[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x->data[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

/*
 * Arguments    : int n
 *                double a
 *                emxArray_real_T *x
 *                int ix0
 * Return Type  : void
 */
static void eml_xscal(int n, double a, emxArray_real_T *x, int ix0)
{
  int i26;
  int k;
  i26 = (ix0 + n) - 1;
  for (k = ix0; k <= i26; k++) {
    x->data[k - 1] *= a;
  }
}

/*
 * CRS_CORR compute NCCF (Normalized cross correlation Function)
 *
 *    [Phi] = crs_corr(Data, lag_min, lag_max) computes the
 *    normalized cross correlation sequence based on the RAPT algorithm
 *    discussed by DAVID TALKIN.
 *    "Assume that "S" is the input signal sequence, "Phi" is correlation sequence,
 *        Phi(k)=SUM((S[j])*(S[j+k]))/sqrt((SUM(s[j]^2)*(S[j+k]^2)))
 *        where 1 <= k <= Lag_max and 1 <= j <= N. Summation is based on j only
 *        Phi(k) should range from -1 to 1".
 *
 *  INPUTS:
 *    Data:     Data array of signal values.
 *    lag_min:  minimum value of lag to consider
 *    lag_max:  maximum value of lag to consider
 *    Note that calculations will be based on (len-----lag_max)  points
 *
 *  OUTPUTS:
 *    Phi     : The normalized cross correlated
 *
 *    Note: The index of the first reasonable peak value of Phi is considered
 *    to be the period of the input signal.
 * Arguments    : emxArray_real_T *Data
 *                double lag_min
 *                double lag_max
 *                emxArray_real_T *Phi
 * Return Type  : void
 */
void crs_corr(emxArray_real_T *Data, double lag_min, double lag_max,
              emxArray_real_T *Phi)
{
  double N;
  int i18;
  int unnamed_idx_1;
  double d2;
  emxArray_real_T *x_j;
  emxArray_real_T *p;
  int br;
  int i19;
  int k;
  emxArray_real_T *x_jr;
  emxArray_real_T *formula_nume;
  emxArray_real_T *q;
  emxArray_real_T *formula_denom;
  emxArray_real_T *b_formula_denom;
  emxArray_real_T *b_formula_nume;
  double b_k;
  int i20;
  int cr;
  int ar;
  unsigned int unnamed_idx_0;
  unsigned int b_unnamed_idx_1;
  int ic;
  int ib;
  int ia;

  /*   Programmer: S.A.Zahorian,Kasi Kavita. */
  /*   Creation date:  2000 */
  /*   Revision date:  March 26, 2002 */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*      This file is a part of the YAAPT program, designed for a fundamental  */
  /*    frequency tracking algorithm that is extermely robust for both high quality  */
  /*    and telephone speech.   */
  /*      The YAAPT program was created by the Speech Communication Laboratory of */
  /*    the state university of New York at Binghamton. The program is available  */
  /*    at http://www.ws.binghamton.edu/zahorian as free software. Further  */
  /*    information about the program could be found at "A spectral/temporal  */
  /*    method for robust fundamental frequency tracking," J.Acosut.Soc.Am. 123(6),  */
  /*    June 2008. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Some initialization */
  /*  The length of data */
  N = (double)Data->size[1] - lag_max;

  /*  range */
  i18 = Phi->size[0] * Phi->size[1];
  Phi->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)Phi, i18, (int)sizeof(double));
  unnamed_idx_1 = Data->size[1];
  i18 = Phi->size[0] * Phi->size[1];
  Phi->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)Phi, i18, (int)sizeof(double));
  unnamed_idx_1 = Data->size[1];
  for (i18 = 0; i18 < unnamed_idx_1; i18++) {
    Phi->data[i18] = 0.0;
  }

  /*  Remove DC level */
  d2 = mean(Data);
  i18 = Data->size[0] * Data->size[1];
  Data->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)Data, i18, (int)sizeof(double));
  unnamed_idx_1 = Data->size[1];
  for (i18 = 0; i18 < unnamed_idx_1; i18++) {
    Data->data[Data->size[0] * i18] -= d2;
  }

  if (1.0 > N) {
    unnamed_idx_1 = 0;
  } else {
    unnamed_idx_1 = (int)N;
  }

  emxInit_real_T(&x_j, 2);
  i18 = x_j->size[0] * x_j->size[1];
  x_j->size[0] = 1;
  x_j->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)x_j, i18, (int)sizeof(double));
  for (i18 = 0; i18 < unnamed_idx_1; i18++) {
    x_j->data[x_j->size[0] * i18] = Data->data[i18];
  }

  emxInit_real_T(&p, 2);

  /*  s[j]   1 <= j <= N. */
  i18 = p->size[0] * p->size[1];
  p->size[0] = x_j->size[1];
  p->size[1] = x_j->size[1];
  emxEnsureCapacity((emxArray__common *)p, i18, (int)sizeof(double));
  unnamed_idx_1 = x_j->size[1];
  for (i18 = 0; i18 < unnamed_idx_1; i18++) {
    br = x_j->size[1];
    for (i19 = 0; i19 < br; i19++) {
      p->data[i18 + p->size[0] * i19] = x_j->data[x_j->size[0] * i18] *
        x_j->data[x_j->size[0] * i19];
    }
  }

  i18 = (int)(lag_max + (1.0 - lag_min));
  k = 0;
  emxInit_real_T(&x_jr, 2);
  emxInit_real_T(&formula_nume, 2);
  emxInit_real_T(&q, 2);
  emxInit_real_T(&formula_denom, 2);
  emxInit_real_T(&b_formula_denom, 2);
  emxInit_real_T(&b_formula_nume, 2);
  while (k <= i18 - 1) {
    b_k = lag_min + (double)k;

    /*   to calculate the dot product of the signal and displaced version. */
    d2 = (b_k + N) - 1.0;
    if (b_k > d2) {
      i19 = 0;
      i20 = 0;
    } else {
      i19 = (int)b_k - 1;
      i20 = (int)d2;
    }

    cr = x_jr->size[0] * x_jr->size[1];
    x_jr->size[0] = 1;
    x_jr->size[1] = i20 - i19;
    emxEnsureCapacity((emxArray__common *)x_jr, cr, (int)sizeof(double));
    unnamed_idx_1 = i20 - i19;
    for (i20 = 0; i20 < unnamed_idx_1; i20++) {
      x_jr->data[x_jr->size[0] * i20] = Data->data[i19 + i20];
    }

    /*  s[j]   -k <= j <= N+K-k-1. */
    i19 = formula_nume->size[0] * formula_nume->size[1];
    formula_nume->size[0] = x_j->size[1];
    formula_nume->size[1] = x_jr->size[1];
    emxEnsureCapacity((emxArray__common *)formula_nume, i19, (int)sizeof(double));
    unnamed_idx_1 = x_j->size[1];
    for (i19 = 0; i19 < unnamed_idx_1; i19++) {
      br = x_jr->size[1];
      for (i20 = 0; i20 < br; i20++) {
        formula_nume->data[i19 + formula_nume->size[0] * i20] = x_j->data
          [x_j->size[0] * i19] * x_jr->data[x_jr->size[0] * i20];
      }
    }

    /*  the normalization factor for the denominator. */
    i19 = q->size[0] * q->size[1];
    q->size[0] = x_jr->size[1];
    q->size[1] = x_jr->size[1];
    emxEnsureCapacity((emxArray__common *)q, i19, (int)sizeof(double));
    unnamed_idx_1 = x_jr->size[1];
    for (i19 = 0; i19 < unnamed_idx_1; i19++) {
      br = x_jr->size[1];
      for (i20 = 0; i20 < br; i20++) {
        q->data[i19 + q->size[0] * i20] = x_jr->data[x_jr->size[0] * i19] *
          x_jr->data[x_jr->size[0] * i20];
      }
    }

    if ((p->size[1] == 1) || (q->size[0] == 1)) {
      i19 = formula_denom->size[0] * formula_denom->size[1];
      formula_denom->size[0] = p->size[0];
      formula_denom->size[1] = q->size[1];
      emxEnsureCapacity((emxArray__common *)formula_denom, i19, (int)sizeof
                        (double));
      unnamed_idx_1 = p->size[0];
      for (i19 = 0; i19 < unnamed_idx_1; i19++) {
        br = q->size[1];
        for (i20 = 0; i20 < br; i20++) {
          formula_denom->data[i19 + formula_denom->size[0] * i20] = 0.0;
          ar = p->size[1];
          for (cr = 0; cr < ar; cr++) {
            formula_denom->data[i19 + formula_denom->size[0] * i20] += p->
              data[i19 + p->size[0] * cr] * q->data[cr + q->size[0] * i20];
          }
        }
      }
    } else {
      unnamed_idx_0 = (unsigned int)p->size[0];
      b_unnamed_idx_1 = (unsigned int)q->size[1];
      i19 = formula_denom->size[0] * formula_denom->size[1];
      formula_denom->size[0] = (int)unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)formula_denom, i19, (int)sizeof
                        (double));
      i19 = formula_denom->size[0] * formula_denom->size[1];
      formula_denom->size[1] = (int)b_unnamed_idx_1;
      emxEnsureCapacity((emxArray__common *)formula_denom, i19, (int)sizeof
                        (double));
      unnamed_idx_1 = (int)unnamed_idx_0 * (int)b_unnamed_idx_1;
      for (i19 = 0; i19 < unnamed_idx_1; i19++) {
        formula_denom->data[i19] = 0.0;
      }

      if ((p->size[0] == 0) || (q->size[1] == 0)) {
      } else {
        unnamed_idx_1 = p->size[0] * (q->size[1] - 1);
        for (cr = 0; cr <= unnamed_idx_1; cr += p->size[0]) {
          i19 = cr + p->size[0];
          for (ic = cr; ic + 1 <= i19; ic++) {
            formula_denom->data[ic] = 0.0;
          }
        }

        br = 0;
        for (cr = 0; cr <= unnamed_idx_1; cr += p->size[0]) {
          ar = -1;
          i19 = br + p->size[1];
          for (ib = br; ib + 1 <= i19; ib++) {
            if (q->data[ib] != 0.0) {
              ia = ar;
              i20 = cr + p->size[0];
              for (ic = cr; ic + 1 <= i20; ic++) {
                ia++;
                formula_denom->data[ic] += q->data[ib] * p->data[ia];
              }
            }

            ar += p->size[0];
          }

          br += p->size[1];
        }
      }
    }

    /*  calculate the normalized crosscorrelation value using the TALKIN FORMULA. */
    i19 = formula_denom->size[0] * formula_denom->size[1];
    for (unnamed_idx_1 = 0; unnamed_idx_1 < i19; unnamed_idx_1++) {
      formula_denom->data[unnamed_idx_1] = sqrt(formula_denom->
        data[unnamed_idx_1]);
    }

    if ((formula_nume->size[0] == 0) || (formula_nume->size[1] == 0) ||
        ((formula_denom->size[0] == 0) || (formula_denom->size[1] == 0))) {
      unnamed_idx_0 = (unsigned int)formula_nume->size[0];
      b_unnamed_idx_1 = (unsigned int)formula_denom->size[0];
      i19 = q->size[0] * q->size[1];
      q->size[0] = (int)unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)q, i19, (int)sizeof(double));
      i19 = q->size[0] * q->size[1];
      q->size[1] = (int)b_unnamed_idx_1;
      emxEnsureCapacity((emxArray__common *)q, i19, (int)sizeof(double));
      unnamed_idx_1 = (int)unnamed_idx_0 * (int)b_unnamed_idx_1;
      for (i19 = 0; i19 < unnamed_idx_1; i19++) {
        q->data[i19] = 0.0;
      }
    } else if (formula_denom->size[0] == formula_denom->size[1]) {
      eml_lusolve(formula_denom, formula_nume, q);
    } else {
      i19 = b_formula_denom->size[0] * b_formula_denom->size[1];
      b_formula_denom->size[0] = formula_denom->size[1];
      b_formula_denom->size[1] = formula_denom->size[0];
      emxEnsureCapacity((emxArray__common *)b_formula_denom, i19, (int)sizeof
                        (double));
      unnamed_idx_1 = formula_denom->size[0];
      for (i19 = 0; i19 < unnamed_idx_1; i19++) {
        br = formula_denom->size[1];
        for (i20 = 0; i20 < br; i20++) {
          b_formula_denom->data[i20 + b_formula_denom->size[0] * i19] =
            formula_denom->data[i19 + formula_denom->size[0] * i20];
        }
      }

      i19 = b_formula_nume->size[0] * b_formula_nume->size[1];
      b_formula_nume->size[0] = formula_nume->size[1];
      b_formula_nume->size[1] = formula_nume->size[0];
      emxEnsureCapacity((emxArray__common *)b_formula_nume, i19, (int)sizeof
                        (double));
      unnamed_idx_1 = formula_nume->size[0];
      for (i19 = 0; i19 < unnamed_idx_1; i19++) {
        br = formula_nume->size[1];
        for (i20 = 0; i20 < br; i20++) {
          b_formula_nume->data[i20 + b_formula_nume->size[0] * i19] =
            formula_nume->data[i19 + formula_nume->size[0] * i20];
        }
      }

      eml_qrsolve(b_formula_denom, b_formula_nume, formula_nume);
      i19 = q->size[0] * q->size[1];
      q->size[0] = formula_nume->size[1];
      q->size[1] = formula_nume->size[0];
      emxEnsureCapacity((emxArray__common *)q, i19, (int)sizeof(double));
      unnamed_idx_1 = formula_nume->size[0];
      for (i19 = 0; i19 < unnamed_idx_1; i19++) {
        br = formula_nume->size[1];
        for (i20 = 0; i20 < br; i20++) {
          q->data[i20 + q->size[0] * i19] = formula_nume->data[i19 +
            formula_nume->size[0] * i20];
        }
      }
    }

    Phi->data[(int)b_k - 1] = q->data[0];
    k++;
  }

  emxFree_real_T(&b_formula_nume);
  emxFree_real_T(&b_formula_denom);
  emxFree_real_T(&formula_denom);
  emxFree_real_T(&q);
  emxFree_real_T(&formula_nume);
  emxFree_real_T(&x_jr);
  emxFree_real_T(&p);
  emxFree_real_T(&x_j);

  /*    To test using autocorrelation */
  /*     Phi = xcorr(s); */
}

/*
 * Arguments    : void
 * Return Type  : double
 */
double eml_matlab_zlarfg(void)
{
  return 0.0;
}

/*
 * File trailer for crs_corr.c
 *
 * [EOF]
 */
