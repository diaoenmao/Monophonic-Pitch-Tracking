/*
 * File: crs_corr.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "crs_corr.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

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
  int i16;
  int unnamed_idx_1;
  int loop_ub;
  double formula_nume;
  emxArray_real_T *x_j;
  emxArray_real_T *a;
  double p;
  emxArray_real_T *x_jr;
  double k;
  int i17;
  int i18;
  int i19;
  double q;

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
  N = (double)Data->size[0] - lag_max;

  /*  range */
  i16 = Phi->size[0] * Phi->size[1];
  Phi->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)Phi, i16, (int)sizeof(double));
  unnamed_idx_1 = Data->size[0];
  i16 = Phi->size[0] * Phi->size[1];
  Phi->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)Phi, i16, (int)sizeof(double));
  loop_ub = Data->size[0];
  for (i16 = 0; i16 < loop_ub; i16++) {
    Phi->data[i16] = 0.0;
  }

  /*  Remove DC level */
  if (Data->size[0] == 0) {
    formula_nume = 0.0;
  } else {
    formula_nume = Data->data[0];
    for (unnamed_idx_1 = 2; unnamed_idx_1 <= Data->size[0]; unnamed_idx_1++) {
      formula_nume += Data->data[unnamed_idx_1 - 1];
    }
  }

  formula_nume /= (double)Data->size[0];
  i16 = Data->size[0];
  emxEnsureCapacity((emxArray__common *)Data, i16, (int)sizeof(double));
  loop_ub = Data->size[0];
  for (i16 = 0; i16 < loop_ub; i16++) {
    Data->data[i16] -= formula_nume;
  }

  if (1.0 > N) {
    loop_ub = 0;
  } else {
    loop_ub = (int)N;
  }

  b_emxInit_real_T(&x_j, 1);
  i16 = x_j->size[0];
  x_j->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)x_j, i16, (int)sizeof(double));
  for (i16 = 0; i16 < loop_ub; i16++) {
    x_j->data[i16] = Data->data[i16];
  }

  emxInit_real_T(&a, 2);

  /*  s[j]   1 <= j <= N. */
  i16 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = x_j->size[0];
  emxEnsureCapacity((emxArray__common *)a, i16, (int)sizeof(double));
  unnamed_idx_1 = x_j->size[0];
  for (i16 = 0; i16 < unnamed_idx_1; i16++) {
    a->data[a->size[0] * i16] = x_j->data[i16];
  }

  if ((a->size[1] == 1) || (loop_ub == 1)) {
    p = 0.0;
    for (i16 = 0; i16 < a->size[1]; i16++) {
      p += a->data[a->size[0] * i16] * x_j->data[i16];
    }
  } else {
    p = 0.0;
    for (i16 = 0; i16 < a->size[1]; i16++) {
      p += a->data[a->size[0] * i16] * x_j->data[i16];
    }
  }

  i16 = (int)(lag_max + (1.0 - lag_min));
  unnamed_idx_1 = 0;
  b_emxInit_real_T(&x_jr, 1);
  while (unnamed_idx_1 <= i16 - 1) {
    k = lag_min + (double)unnamed_idx_1;

    /*   to calculate the dot product of the signal and displaced version. */
    formula_nume = (k + N) - 1.0;
    if (k > formula_nume) {
      i17 = 0;
      i18 = 0;
    } else {
      i17 = (int)k - 1;
      i18 = (int)formula_nume;
    }

    i19 = x_jr->size[0];
    x_jr->size[0] = i18 - i17;
    emxEnsureCapacity((emxArray__common *)x_jr, i19, (int)sizeof(double));
    loop_ub = i18 - i17;
    for (i19 = 0; i19 < loop_ub; i19++) {
      x_jr->data[i19] = Data->data[i17 + i19];
    }

    /*  s[j]   -k <= j <= N+K-k-1. */
    i19 = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_j->size[0];
    emxEnsureCapacity((emxArray__common *)a, i19, (int)sizeof(double));
    loop_ub = x_j->size[0];
    for (i19 = 0; i19 < loop_ub; i19++) {
      a->data[a->size[0] * i19] = x_j->data[i19];
    }

    if ((a->size[1] == 1) || (i18 - i17 == 1)) {
      formula_nume = 0.0;
      for (i19 = 0; i19 < a->size[1]; i19++) {
        formula_nume += a->data[a->size[0] * i19] * x_jr->data[i19];
      }
    } else {
      formula_nume = 0.0;
      for (i19 = 0; i19 < a->size[1]; i19++) {
        formula_nume += a->data[a->size[0] * i19] * x_jr->data[i19];
      }
    }

    /*  the normalization factor for the denominator. */
    i19 = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_jr->size[0];
    emxEnsureCapacity((emxArray__common *)a, i19, (int)sizeof(double));
    loop_ub = x_jr->size[0];
    for (i19 = 0; i19 < loop_ub; i19++) {
      a->data[a->size[0] * i19] = x_jr->data[i19];
    }

    if ((a->size[1] == 1) || (i18 - i17 == 1)) {
      q = 0.0;
      for (i17 = 0; i17 < a->size[1]; i17++) {
        q += a->data[a->size[0] * i17] * x_jr->data[i17];
      }
    } else {
      q = 0.0;
      for (i17 = 0; i17 < a->size[1]; i17++) {
        q += a->data[a->size[0] * i17] * x_jr->data[i17];
      }
    }

    /*  calculate the normalized crosscorrelation value using the TALKIN FORMULA. */
    Phi->data[(int)k - 1] = formula_nume / sqrt(p * q);
    unnamed_idx_1++;
  }

  emxFree_real_T(&a);
  emxFree_real_T(&x_jr);
  emxFree_real_T(&x_j);

  /*    To test using autocorrelation */
  /*     Phi = xcorr(s); */
}

/*
 * File trailer for crs_corr.c
 *
 * [EOF]
 */
