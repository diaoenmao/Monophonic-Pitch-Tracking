/*
 * File: tm_trk.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Jan-2016 05:43:25
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "tm_trk.h"
#include "yaapt_emxutil.h"
#include "cmp_rate.h"
#include "fix.h"

/* Function Definitions */

/*
 * TM_TRK  Temporal pitch tracking for YAAPT pitch tracking
 *
 *    [Pitch, Merit] = tm_trk(Data, Fs, SPitch, pStd, pAvg, Prm)
 *    computes estimates of pitch  using nonlinearly processed
 *    speech (typically square or absolute value) and frequency domain processing
 *    Search for frequencies which have energy at multiplies of that frequency
 *
 * INPUTS:
 *    Data:   Nonlinearly processed signal
 *    Fs:    The sampling frequency.
 *    SPitch:The spectral F0 track, with the unvoiced
 *    pStd:  The STD of voiced spectral F0 track .
 *    pAvg:  The mean of voiced spectral F0 track .
 *    Prm:   Array of parameters used to control performance
 *
 * OUTPUTS:
 *    Pitch: Computed pitch candidates array
 *    Merit: The merit of array of pitch candidates
 * Arguments    : const emxArray_real_T *Data
 *                double Fs
 *                const emxArray_real_T *SPitch
 *                const double pStd_data[]
 *                const int pStd_size[1]
 *                emxArray_real_T *Pitch
 *                emxArray_real_T *Merit
 * Return Type  : void
 */
void tm_trk(const emxArray_real_T *Data, double Fs, const emxArray_real_T
            *SPitch, const double pStd_data[], const int pStd_size[1],
            emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  emxArray_real_T *y;
  double nframesize;
  double nframejump;
  double numframes;
  int i18;
  int loop_ub;
  double freq_thresh_data[1];
  emxArray_real_T *SRange;
  emxArray_real_T *temp_max;
  emxArray_real_T *temp_min;
  int i;
  emxArray_real_T *b_Data;
  emxArray_real_T *b_y;
  int unnamed_idx_1;
  int k;
  double X;
  int n;
  emxArray_real_T *x_j;
  emxArray_real_T *x_jr;
  double firstp;
  double x;
  double b_x;
  int i19;
  double N;
  double p;
  double b_k;
  int i20;
  double formula_nume;
  double q;
  int tmp_size[2];
  double tmp_data[6];
  int b_tmp_size[2];
  double b_tmp_data[6];
  emxArray_real_T *diff;
  emxArray_real_T *r9;
  int j;
  signed char c_tmp_data[1];
  double y_data[1];
  emxInit_real_T1(&y, 1);

  /*    Creation :   Jun 20, 2006, July 27, 2007 */
  /*    Programers:  Hongbing Hu */
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
  /* -- PARAMETERS ---------------------------------------------------------------- */
  nframesize = 20.0 * Fs / 1000.0;
  b_fix(&nframesize);
  nframejump = 30.0 * Fs / 1000.0;
  b_fix(&nframejump);

  /*  overlap width in sample  */
  numframes = ((double)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /*  The maximum number of pitch candidates */
  /* freq_thresh = pAvg;  % seems too large */
  i18 = y->size[0];
  y->size[0] = pStd_size[0];
  emxEnsureCapacity((emxArray__common *)y, i18, (int)sizeof(double));
  loop_ub = pStd_size[0];
  for (i18 = 0; i18 < loop_ub; i18++) {
    y->data[i18] = 5.0 * pStd_data[i18];
  }

  loop_ub = pStd_size[0];
  for (i18 = 0; i18 < loop_ub; i18++) {
    freq_thresh_data[i18] = 5.0 * pStd_data[i18];
  }

  emxInit_real_T(&SRange, 2);
  i18 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  SRange->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)SRange, i18, (int)sizeof(double));
  loop_ub = SPitch->size[1] << 1;
  for (i18 = 0; i18 < loop_ub; i18++) {
    SRange->data[i18] = 0.0;
  }

  emxInit_real_T(&temp_max, 2);

  /*  Determine the search range according spectral pitch track */
  i18 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  temp_max->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)temp_max, i18, (int)sizeof(double));
  loop_ub = SPitch->size[1];
  for (i18 = 0; i18 < loop_ub; i18++) {
    temp_max->data[i18] = 0.0;
  }

  emxInit_real_T(&temp_min, 2);
  i18 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  temp_min->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)temp_min, i18, (int)sizeof(double));
  loop_ub = SPitch->size[1];
  for (i18 = 0; i18 < loop_ub; i18++) {
    temp_min->data[i18] = 0.0;
  }

  i = 0;
  emxInit_real_T1(&b_Data, 1);
  while (i <= SPitch->size[1] - 1) {
    i18 = b_Data->size[0];
    b_Data->size[0] = pStd_size[0];
    emxEnsureCapacity((emxArray__common *)b_Data, i18, (int)sizeof(double));
    loop_ub = pStd_size[0];
    for (i18 = 0; i18 < loop_ub; i18++) {
      b_Data->data[i18] = 2.0 * pStd_data[i18];
    }

    temp_max->data[i] = SPitch->data[i] - b_Data->data[0];
    i18 = b_Data->size[0];
    b_Data->size[0] = pStd_size[0];
    emxEnsureCapacity((emxArray__common *)b_Data, i18, (int)sizeof(double));
    loop_ub = pStd_size[0];
    for (i18 = 0; i18 < loop_ub; i18++) {
      b_Data->data[i18] = 2.0 * pStd_data[i18];
    }

    temp_min->data[i] = SPitch->data[i] + b_Data->data[0];
    i++;
  }

  emxInit_real_T(&b_y, 2);
  unnamed_idx_1 = temp_max->size[1];
  i18 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = temp_max->size[1];
  emxEnsureCapacity((emxArray__common *)b_y, i18, (int)sizeof(double));
  for (k = 0; k + 1 <= unnamed_idx_1; k++) {
    if (temp_max->data[k] >= 60.0) {
      X = temp_max->data[k];
    } else {
      X = 60.0;
    }

    b_y->data[k] = X;
  }

  loop_ub = b_y->size[1];
  for (i18 = 0; i18 < loop_ub; i18++) {
    SRange->data[SRange->size[0] * i18] = b_y->data[b_y->size[0] * i18];
  }

  unnamed_idx_1 = temp_min->size[1];
  i18 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = temp_min->size[1];
  emxEnsureCapacity((emxArray__common *)b_y, i18, (int)sizeof(double));
  for (k = 0; k + 1 <= unnamed_idx_1; k++) {
    if (temp_min->data[k] <= 400.0) {
      X = temp_min->data[k];
    } else {
      X = 400.0;
    }

    b_y->data[k] = X;
  }

  loop_ub = b_y->size[1];
  for (i18 = 0; i18 < loop_ub; i18++) {
    SRange->data[1 + SRange->size[0] * i18] = b_y->data[b_y->size[0] * i18];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  i18 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 3;
  Pitch->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)Pitch, i18, (int)sizeof(double));
  loop_ub = 3 * (int)numframes;
  for (i18 = 0; i18 < loop_ub; i18++) {
    Pitch->data[i18] = 0.0;
  }

  i18 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 3;
  Merit->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)Merit, i18, (int)sizeof(double));
  loop_ub = 3 * (int)numframes;
  for (i18 = 0; i18 < loop_ub; i18++) {
    Merit->data[i18] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  n = 0;
  emxInit_real_T1(&x_j, 1);
  emxInit_real_T1(&x_jr, 1);
  while (n <= (int)numframes - 1) {
    firstp = 1.0 + ((1.0 + (double)n) - 1.0) * nframejump;
    X = (firstp + nframesize) - 1.0;
    if (firstp > X) {
      i18 = 0;
      unnamed_idx_1 = 0;
    } else {
      i18 = (int)firstp - 1;
      unnamed_idx_1 = (int)X;
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    X = Fs / SRange->data[1 + SRange->size[0] * n];
    if (X < 0.0) {
      x = ceil(X);
    } else {
      x = floor(X);
    }

    X = Fs / SRange->data[SRange->size[0] * n];
    if (X < 0.0) {
      b_x = ceil(X);
    } else {
      b_x = floor(X);
    }

    /*  Compute correaltion */
    i19 = b_Data->size[0];
    b_Data->size[0] = unnamed_idx_1 - i18;
    emxEnsureCapacity((emxArray__common *)b_Data, i19, (int)sizeof(double));
    loop_ub = unnamed_idx_1 - i18;
    for (unnamed_idx_1 = 0; unnamed_idx_1 < loop_ub; unnamed_idx_1++) {
      b_Data->data[unnamed_idx_1] = Data->data[i18 + unnamed_idx_1];
    }

    /*  CRS_CORR compute NCCF (Normalized cross correlation Function)  */
    /*  */
    /*    [Phi] = crs_corr(Data, lag_min, lag_max) computes the */
    /*    normalized cross correlation sequence based on the RAPT algorithm  */
    /*    discussed by DAVID TALKIN. */
    /*    "Assume that "S" is the input signal sequence, "Phi" is correlation sequence, */
    /*        Phi(k)=SUM((S[j])*(S[j+k]))/sqrt((SUM(s[j]^2)*(S[j+k]^2))) */
    /*        where 1 <= k <= Lag_max and 1 <= j <= N. Summation is based on j only */
    /*        Phi(k) should range from -1 to 1". */
    /*  */
    /*  INPUTS:    */
    /*    Data:     Data array of signal values. */
    /*    lag_min:  minimum value of lag to consider */
    /*    lag_max:  maximum value of lag to consider */
    /*    Note that calculations will be based on (len-----lag_max)  points */
    /*  */
    /*  OUTPUTS: */
    /*    Phi     : The normalized cross correlated */
    /*  */
    /*    Note: The index of the first reasonable peak value of Phi is considered */
    /*    to be the period of the input signal. */
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
    N = (double)b_Data->size[0] - (b_x + 3.0);

    /*  range */
    i18 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = b_Data->size[0];
    emxEnsureCapacity((emxArray__common *)temp_max, i18, (int)sizeof(double));
    loop_ub = b_Data->size[0];
    for (i18 = 0; i18 < loop_ub; i18++) {
      temp_max->data[i18] = 0.0;
    }

    /*  Remove DC level */
    if (b_Data->size[0] == 0) {
      X = 0.0;
    } else {
      X = b_Data->data[0];
      for (k = 2; k <= b_Data->size[0]; k++) {
        X += b_Data->data[k - 1];
      }
    }

    X /= (double)b_Data->size[0];
    i18 = b_Data->size[0];
    emxEnsureCapacity((emxArray__common *)b_Data, i18, (int)sizeof(double));
    loop_ub = b_Data->size[0];
    for (i18 = 0; i18 < loop_ub; i18++) {
      b_Data->data[i18] -= X;
    }

    if (1.0 > N) {
      loop_ub = 0;
    } else {
      loop_ub = (int)N;
    }

    i18 = x_j->size[0];
    x_j->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)x_j, i18, (int)sizeof(double));
    for (i18 = 0; i18 < loop_ub; i18++) {
      x_j->data[i18] = b_Data->data[i18];
    }

    /*  s[j]   1 <= j <= N. */
    i18 = temp_min->size[0] * temp_min->size[1];
    temp_min->size[0] = 1;
    temp_min->size[1] = x_j->size[0];
    emxEnsureCapacity((emxArray__common *)temp_min, i18, (int)sizeof(double));
    unnamed_idx_1 = x_j->size[0];
    for (i18 = 0; i18 < unnamed_idx_1; i18++) {
      temp_min->data[temp_min->size[0] * i18] = x_j->data[i18];
    }

    if ((temp_min->size[1] == 1) || (loop_ub == 1)) {
      X = 0.0;
      for (i18 = 0; i18 < temp_min->size[1]; i18++) {
        X += temp_min->data[temp_min->size[0] * i18] * x_j->data[i18];
      }

      p = X;
    } else {
      X = 0.0;
      for (i18 = 0; i18 < temp_min->size[1]; i18++) {
        X += temp_min->data[temp_min->size[0] * i18] * x_j->data[i18];
      }

      p = X;
    }

    i18 = (int)((b_x + 3.0) + (1.0 - (x - 3.0)));
    for (k = 0; k < i18; k++) {
      b_k = (x - 3.0) + (double)k;

      /*   to calculate the dot product of the signal and displaced version. */
      X = (b_k + N) - 1.0;
      if (b_k > X) {
        unnamed_idx_1 = 0;
        i19 = 0;
      } else {
        unnamed_idx_1 = (int)b_k - 1;
        i19 = (int)X;
      }

      i20 = x_jr->size[0];
      x_jr->size[0] = i19 - unnamed_idx_1;
      emxEnsureCapacity((emxArray__common *)x_jr, i20, (int)sizeof(double));
      loop_ub = i19 - unnamed_idx_1;
      for (i20 = 0; i20 < loop_ub; i20++) {
        x_jr->data[i20] = b_Data->data[unnamed_idx_1 + i20];
      }

      /*  s[j]   -k <= j <= N+K-k-1. */
      i20 = temp_min->size[0] * temp_min->size[1];
      temp_min->size[0] = 1;
      temp_min->size[1] = x_j->size[0];
      emxEnsureCapacity((emxArray__common *)temp_min, i20, (int)sizeof(double));
      loop_ub = x_j->size[0];
      for (i20 = 0; i20 < loop_ub; i20++) {
        temp_min->data[temp_min->size[0] * i20] = x_j->data[i20];
      }

      if ((temp_min->size[1] == 1) || (i19 - unnamed_idx_1 == 1)) {
        X = 0.0;
        for (i20 = 0; i20 < temp_min->size[1]; i20++) {
          X += temp_min->data[temp_min->size[0] * i20] * x_jr->data[i20];
        }

        formula_nume = X;
      } else {
        X = 0.0;
        for (i20 = 0; i20 < temp_min->size[1]; i20++) {
          X += temp_min->data[temp_min->size[0] * i20] * x_jr->data[i20];
        }

        formula_nume = X;
      }

      /*  the normalization factor for the denominator. */
      i20 = temp_min->size[0] * temp_min->size[1];
      temp_min->size[0] = 1;
      temp_min->size[1] = x_jr->size[0];
      emxEnsureCapacity((emxArray__common *)temp_min, i20, (int)sizeof(double));
      loop_ub = x_jr->size[0];
      for (i20 = 0; i20 < loop_ub; i20++) {
        temp_min->data[temp_min->size[0] * i20] = x_jr->data[i20];
      }

      if ((temp_min->size[1] == 1) || (i19 - unnamed_idx_1 == 1)) {
        X = 0.0;
        for (unnamed_idx_1 = 0; unnamed_idx_1 < temp_min->size[1]; unnamed_idx_1
             ++) {
          X += temp_min->data[temp_min->size[0] * unnamed_idx_1] * x_jr->
            data[unnamed_idx_1];
        }

        q = X;
      } else {
        X = 0.0;
        for (unnamed_idx_1 = 0; unnamed_idx_1 < temp_min->size[1]; unnamed_idx_1
             ++) {
          X += temp_min->data[temp_min->size[0] * unnamed_idx_1] * x_jr->
            data[unnamed_idx_1];
        }

        q = X;
      }

      /*  calculate the normalized crosscorrelation value using the TALKIN FORMULA. */
      temp_max->data[(int)b_k - 1] = formula_nume / sqrt(p * q);
    }

    /*    To test using autocorrelation */
    /*     Phi = xcorr(s); */
    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    cmp_rate(temp_max, Fs, x - 3.0, b_x + 3.0, b_tmp_data, b_tmp_size, tmp_data,
             tmp_size);
    for (i18 = 0; i18 < 3; i18++) {
      Pitch->data[i18 + Pitch->size[0] * n] = b_tmp_data[i18];
    }

    for (i18 = 0; i18 < 3; i18++) {
      Merit->data[i18 + Merit->size[0] * n] = tmp_data[i18];
    }

    n++;
  }

  emxFree_real_T(&x_jr);
  emxFree_real_T(&x_j);
  emxFree_real_T(&b_Data);
  emxFree_real_T(&SRange);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  emxInit_real_T(&diff, 2);
  emxInit_real_T(&r9, 2);
  for (i = 0; i < 3; i++) {
    loop_ub = Pitch->size[1];
    i18 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)temp_max, i18, (int)sizeof(double));
    for (i18 = 0; i18 < loop_ub; i18++) {
      temp_max->data[temp_max->size[0] * i18] = Pitch->data[i + Pitch->size[0] *
        i18] - SPitch->data[SPitch->size[0] * i18];
    }

    i18 = diff->size[0] * diff->size[1];
    diff->size[0] = 1;
    diff->size[1] = temp_max->size[1];
    emxEnsureCapacity((emxArray__common *)diff, i18, (int)sizeof(double));
    for (k = 0; k + 1 <= temp_max->size[1]; k++) {
      diff->data[k] = fabs(temp_max->data[k]);
    }

    i18 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = diff->size[1];
    emxEnsureCapacity((emxArray__common *)temp_max, i18, (int)sizeof(double));
    loop_ub = diff->size[1];
    for (i18 = 0; i18 < loop_ub; i18++) {
      temp_max->data[i18] = 0.0;
    }

    for (j = 0; j < diff->size[1]; j++) {
      X = diff->data[j];
      loop_ub = y->size[0];
      for (i18 = 0; i18 < loop_ub; i18++) {
        c_tmp_data[i18] = (signed char)(X < y->data[i18]);
      }

      temp_max->data[j] = c_tmp_data[0];
    }

    /*      match1 =  (diff < freq_thresh); */
    i18 = temp_min->size[0] * temp_min->size[1];
    temp_min->size[0] = 1;
    temp_min->size[1] = diff->size[1];
    emxEnsureCapacity((emxArray__common *)temp_min, i18, (int)sizeof(double));
    loop_ub = diff->size[1];
    for (i18 = 0; i18 < loop_ub; i18++) {
      temp_min->data[i18] = 0.0;
    }

    for (j = 0; j < diff->size[1]; j++) {
      if (y->size[0] == 0) {
        unnamed_idx_1 = 0;
      } else {
        X = 1.0 / freq_thresh_data[0] * diff->data[j];
        unnamed_idx_1 = 1;
        y_data[0] = X;
      }

      i18 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = unnamed_idx_1;
      emxEnsureCapacity((emxArray__common *)b_y, i18, (int)sizeof(double));
      X = temp_max->data[j];
      for (i18 = 0; i18 < unnamed_idx_1; i18++) {
        b_y->data[i18] = (1.0 - y_data[i18]) * X;
      }

      temp_min->data[j] = b_y->data[0];
    }

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    unnamed_idx_1 = Merit->size[1];
    i18 = r9->size[0] * r9->size[1];
    r9->size[0] = 1;
    r9->size[1] = unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)r9, i18, (int)sizeof(double));
    for (i18 = 0; i18 < unnamed_idx_1; i18++) {
      r9->data[r9->size[0] * i18] = 1.2 * Merit->data[i + Merit->size[0] * i18] *
        temp_min->data[temp_min->size[0] * i18];
    }

    loop_ub = r9->size[1];
    for (i18 = 0; i18 < loop_ub; i18++) {
      Merit->data[i + Merit->size[0] * i18] = r9->data[r9->size[0] * i18];
    }
  }

  emxFree_real_T(&r9);
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  emxFree_real_T(&diff);
  emxFree_real_T(&temp_min);
  emxFree_real_T(&temp_max);
}

/*
 * File trailer for tm_trk.c
 *
 * [EOF]
 */
