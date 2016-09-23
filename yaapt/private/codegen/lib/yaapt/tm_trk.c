/*
 * File: tm_trk.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
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
 *                double Prm_frame_length
 *                double Prm_frame_space
 *                double Prm_f0_min
 *                double Prm_f0_max
 *                double Prm_nccf_thresh1
 *                double Prm_nccf_thresh2
 *                double Prm_nccf_maxcands
 *                double Prm_nccf_pwidth
 *                double Prm_merit_boost
 *                emxArray_real_T *Pitch
 *                emxArray_real_T *Merit
 * Return Type  : void
 */
void tm_trk(const emxArray_real_T *Data, double Fs, const emxArray_real_T
            *SPitch, const double pStd_data[], const int pStd_size[1], double
            Prm_frame_length, double Prm_frame_space, double Prm_f0_min, double
            Prm_f0_max, double Prm_nccf_thresh1, double Prm_nccf_thresh2, double
            Prm_nccf_maxcands, double Prm_nccf_pwidth, double Prm_merit_boost,
            emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  emxArray_real_T *y;
  double nframesize;
  double nframejump;
  double numframes;
  int i24;
  int loop_ub;
  emxArray_real_T *SRange;
  double freq_thresh_data[1];
  emxArray_real_T *temp_max;
  emxArray_real_T *temp_min;
  int i;
  emxArray_real_T *b_Data;
  emxArray_real_T *b_y;
  int unnamed_idx_1;
  int k;
  double X;
  int n;
  emxArray_int32_T *r26;
  emxArray_real_T *x_j;
  emxArray_real_T *x_jr;
  double firstp;
  int i25;
  emxArray_boolean_T *Idx_unvoiced;
  double x;
  emxArray_real_T *b_diff;
  emxArray_real_T *r27;
  double b_x;
  int j;
  signed char tmp_data[1];
  double N;
  double y_data[1];
  double p;
  double b_k;
  int i26;
  double formula_nume;
  double q;
  emxInit_real_T2(&y, 1);

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
  nframesize = Prm_frame_length * Fs / 1000.0;
  b_fix(&nframesize);
  nframejump = Prm_frame_space * Fs / 1000.0;
  b_fix(&nframejump);

  /*  overlap width in sample  */
  numframes = ((double)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /*  The maximum number of pitch candidates */
  /* freq_thresh = pAvg;  % seems too large */
  i24 = y->size[0];
  y->size[0] = pStd_size[0];
  emxEnsureCapacity((emxArray__common *)y, i24, (int)sizeof(double));
  loop_ub = pStd_size[0];
  for (i24 = 0; i24 < loop_ub; i24++) {
    y->data[i24] = 5.0 * pStd_data[i24];
  }

  loop_ub = pStd_size[0];
  for (i24 = 0; i24 < loop_ub; i24++) {
    freq_thresh_data[i24] = 5.0 * pStd_data[i24];
  }

  emxInit_real_T(&SRange, 2);
  i24 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  SRange->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)SRange, i24, (int)sizeof(double));
  loop_ub = SPitch->size[1] << 1;
  for (i24 = 0; i24 < loop_ub; i24++) {
    SRange->data[i24] = 0.0;
  }

  emxInit_real_T(&temp_max, 2);

  /*  Determine the search range according spectral pitch track */
  i24 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  temp_max->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)temp_max, i24, (int)sizeof(double));
  loop_ub = SPitch->size[1];
  for (i24 = 0; i24 < loop_ub; i24++) {
    temp_max->data[i24] = 0.0;
  }

  emxInit_real_T(&temp_min, 2);
  i24 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  temp_min->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)temp_min, i24, (int)sizeof(double));
  loop_ub = SPitch->size[1];
  for (i24 = 0; i24 < loop_ub; i24++) {
    temp_min->data[i24] = 0.0;
  }

  i = 0;
  emxInit_real_T2(&b_Data, 1);
  while (i <= SPitch->size[1] - 1) {
    i24 = b_Data->size[0];
    b_Data->size[0] = pStd_size[0];
    emxEnsureCapacity((emxArray__common *)b_Data, i24, (int)sizeof(double));
    loop_ub = pStd_size[0];
    for (i24 = 0; i24 < loop_ub; i24++) {
      b_Data->data[i24] = 2.0 * pStd_data[i24];
    }

    temp_max->data[i] = SPitch->data[i] - b_Data->data[0];
    i24 = b_Data->size[0];
    b_Data->size[0] = pStd_size[0];
    emxEnsureCapacity((emxArray__common *)b_Data, i24, (int)sizeof(double));
    loop_ub = pStd_size[0];
    for (i24 = 0; i24 < loop_ub; i24++) {
      b_Data->data[i24] = 2.0 * pStd_data[i24];
    }

    temp_min->data[i] = SPitch->data[i] + b_Data->data[0];
    i++;
  }

  emxInit_real_T(&b_y, 2);
  unnamed_idx_1 = temp_max->size[1];
  i24 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = temp_max->size[1];
  emxEnsureCapacity((emxArray__common *)b_y, i24, (int)sizeof(double));
  for (k = 0; k + 1 <= unnamed_idx_1; k++) {
    if ((temp_max->data[k] >= Prm_f0_min) || rtIsNaN(Prm_f0_min)) {
      X = temp_max->data[k];
    } else {
      X = Prm_f0_min;
    }

    b_y->data[k] = X;
  }

  loop_ub = b_y->size[1];
  for (i24 = 0; i24 < loop_ub; i24++) {
    SRange->data[SRange->size[0] * i24] = b_y->data[b_y->size[0] * i24];
  }

  unnamed_idx_1 = temp_min->size[1];
  i24 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = temp_min->size[1];
  emxEnsureCapacity((emxArray__common *)b_y, i24, (int)sizeof(double));
  for (k = 0; k + 1 <= unnamed_idx_1; k++) {
    if ((temp_min->data[k] <= Prm_f0_max) || rtIsNaN(Prm_f0_max)) {
      X = temp_min->data[k];
    } else {
      X = Prm_f0_max;
    }

    b_y->data[k] = X;
  }

  loop_ub = b_y->size[1];
  for (i24 = 0; i24 < loop_ub; i24++) {
    SRange->data[1 + SRange->size[0] * i24] = b_y->data[b_y->size[0] * i24];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  i24 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = (int)Prm_nccf_maxcands;
  Pitch->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)Pitch, i24, (int)sizeof(double));
  loop_ub = (int)Prm_nccf_maxcands * (int)numframes;
  for (i24 = 0; i24 < loop_ub; i24++) {
    Pitch->data[i24] = 0.0;
  }

  i24 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = (int)Prm_nccf_maxcands;
  Merit->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)Merit, i24, (int)sizeof(double));
  loop_ub = (int)Prm_nccf_maxcands * (int)numframes;
  for (i24 = 0; i24 < loop_ub; i24++) {
    Merit->data[i24] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  n = 0;
  emxInit_int32_T1(&r26, 1);
  emxInit_real_T2(&x_j, 1);
  emxInit_real_T2(&x_jr, 1);
  while (n <= (int)numframes - 1) {
    firstp = 1.0 + ((1.0 + (double)n) - 1.0) * nframejump;
    X = (firstp + nframesize) - 1.0;
    if (firstp > X) {
      i24 = 0;
      i25 = 0;
    } else {
      i24 = (int)firstp - 1;
      i25 = (int)X;
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
    unnamed_idx_1 = b_Data->size[0];
    b_Data->size[0] = i25 - i24;
    emxEnsureCapacity((emxArray__common *)b_Data, unnamed_idx_1, (int)sizeof
                      (double));
    loop_ub = i25 - i24;
    for (i25 = 0; i25 < loop_ub; i25++) {
      b_Data->data[i25] = Data->data[i24 + i25];
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
    i24 = temp_min->size[0] * temp_min->size[1];
    temp_min->size[0] = 1;
    temp_min->size[1] = b_Data->size[0];
    emxEnsureCapacity((emxArray__common *)temp_min, i24, (int)sizeof(double));
    loop_ub = b_Data->size[0];
    for (i24 = 0; i24 < loop_ub; i24++) {
      temp_min->data[i24] = 0.0;
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
    i24 = b_Data->size[0];
    emxEnsureCapacity((emxArray__common *)b_Data, i24, (int)sizeof(double));
    loop_ub = b_Data->size[0];
    for (i24 = 0; i24 < loop_ub; i24++) {
      b_Data->data[i24] -= X;
    }

    if (1.0 > N) {
      loop_ub = 0;
    } else {
      loop_ub = (int)N;
    }

    i24 = x_j->size[0];
    x_j->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)x_j, i24, (int)sizeof(double));
    for (i24 = 0; i24 < loop_ub; i24++) {
      x_j->data[i24] = b_Data->data[i24];
    }

    /*  s[j]   1 <= j <= N. */
    i24 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = x_j->size[0];
    emxEnsureCapacity((emxArray__common *)temp_max, i24, (int)sizeof(double));
    unnamed_idx_1 = x_j->size[0];
    for (i24 = 0; i24 < unnamed_idx_1; i24++) {
      temp_max->data[temp_max->size[0] * i24] = x_j->data[i24];
    }

    if ((temp_max->size[1] == 1) || (loop_ub == 1)) {
      X = 0.0;
      for (i24 = 0; i24 < temp_max->size[1]; i24++) {
        X += temp_max->data[temp_max->size[0] * i24] * x_j->data[i24];
      }

      p = X;
    } else {
      X = 0.0;
      for (i24 = 0; i24 < temp_max->size[1]; i24++) {
        X += temp_max->data[temp_max->size[0] * i24] * x_j->data[i24];
      }

      p = X;
    }

    i24 = (int)((b_x + 3.0) + (1.0 - (x - 3.0)));
    for (k = 0; k < i24; k++) {
      b_k = (x - 3.0) + (double)k;

      /*   to calculate the dot product of the signal and displaced version. */
      X = (b_k + N) - 1.0;
      if (b_k > X) {
        i25 = 1;
        unnamed_idx_1 = 1;
      } else {
        i25 = (int)b_k;
        unnamed_idx_1 = (int)X + 1;
      }

      i26 = x_jr->size[0];
      x_jr->size[0] = unnamed_idx_1 - i25;
      emxEnsureCapacity((emxArray__common *)x_jr, i26, (int)sizeof(double));
      loop_ub = unnamed_idx_1 - i25;
      for (i26 = 0; i26 < loop_ub; i26++) {
        x_jr->data[i26] = b_Data->data[(i25 + i26) - 1];
      }

      /*  s[j]   -k <= j <= N+K-k-1. */
      i26 = temp_max->size[0] * temp_max->size[1];
      temp_max->size[0] = 1;
      temp_max->size[1] = x_j->size[0];
      emxEnsureCapacity((emxArray__common *)temp_max, i26, (int)sizeof(double));
      loop_ub = x_j->size[0];
      for (i26 = 0; i26 < loop_ub; i26++) {
        temp_max->data[temp_max->size[0] * i26] = x_j->data[i26];
      }

      if ((temp_max->size[1] == 1) || (unnamed_idx_1 - i25 == 1)) {
        X = 0.0;
        for (i26 = 0; i26 < temp_max->size[1]; i26++) {
          X += temp_max->data[temp_max->size[0] * i26] * x_jr->data[i26];
        }

        formula_nume = X;
      } else {
        X = 0.0;
        for (i26 = 0; i26 < temp_max->size[1]; i26++) {
          X += temp_max->data[temp_max->size[0] * i26] * x_jr->data[i26];
        }

        formula_nume = X;
      }

      /*  the normalization factor for the denominator. */
      i26 = temp_max->size[0] * temp_max->size[1];
      temp_max->size[0] = 1;
      temp_max->size[1] = x_jr->size[0];
      emxEnsureCapacity((emxArray__common *)temp_max, i26, (int)sizeof(double));
      loop_ub = x_jr->size[0];
      for (i26 = 0; i26 < loop_ub; i26++) {
        temp_max->data[temp_max->size[0] * i26] = x_jr->data[i26];
      }

      if ((temp_max->size[1] == 1) || (unnamed_idx_1 - i25 == 1)) {
        X = 0.0;
        for (i25 = 0; i25 < temp_max->size[1]; i25++) {
          X += temp_max->data[temp_max->size[0] * i25] * x_jr->data[i25];
        }

        q = X;
      } else {
        X = 0.0;
        for (i25 = 0; i25 < temp_max->size[1]; i25++) {
          X += temp_max->data[temp_max->size[0] * i25] * x_jr->data[i25];
        }

        q = X;
      }

      /*  calculate the normalized crosscorrelation value using the TALKIN FORMULA. */
      temp_min->data[(int)b_k - 1] = formula_nume / sqrt(p * q);
    }

    /*    To test using autocorrelation */
    /*     Phi = xcorr(s); */
    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    cmp_rate(temp_min, Fs, Prm_nccf_maxcands, x - 3.0, b_x + 3.0,
             Prm_nccf_thresh1, Prm_nccf_thresh2, Prm_nccf_pwidth, b_y, temp_max);
    loop_ub = Pitch->size[0];
    i24 = r26->size[0];
    r26->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)r26, i24, (int)sizeof(int));
    for (i24 = 0; i24 < loop_ub; i24++) {
      r26->data[i24] = i24;
    }

    unnamed_idx_1 = r26->size[0];
    for (i24 = 0; i24 < unnamed_idx_1; i24++) {
      Pitch->data[r26->data[i24] + Pitch->size[0] * n] = b_y->data[i24];
    }

    loop_ub = Merit->size[0];
    i24 = r26->size[0];
    r26->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)r26, i24, (int)sizeof(int));
    for (i24 = 0; i24 < loop_ub; i24++) {
      r26->data[i24] = i24;
    }

    unnamed_idx_1 = r26->size[0];
    for (i24 = 0; i24 < unnamed_idx_1; i24++) {
      Merit->data[r26->data[i24] + Merit->size[0] * n] = temp_max->data[i24];
    }

    n++;
  }

  emxFree_real_T(&x_jr);
  emxFree_real_T(&x_j);
  emxFree_real_T(&b_Data);
  emxFree_int32_T(&r26);
  emxFree_real_T(&SRange);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  i = 0;
  emxInit_boolean_T(&Idx_unvoiced, 2);
  emxInit_real_T(&b_diff, 2);
  emxInit_real_T(&r27, 2);
  while (i <= (int)Prm_nccf_maxcands - 1) {
    i24 = Idx_unvoiced->size[0] * Idx_unvoiced->size[1];
    Idx_unvoiced->size[0] = 1;
    Idx_unvoiced->size[1] = SPitch->size[1];
    emxEnsureCapacity((emxArray__common *)Idx_unvoiced, i24, (int)sizeof
                      (boolean_T));
    loop_ub = SPitch->size[0] * SPitch->size[1];
    for (i24 = 0; i24 < loop_ub; i24++) {
      Idx_unvoiced->data[i24] = (SPitch->data[i24] == 0.0);
    }

    loop_ub = Pitch->size[1];
    i24 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)temp_max, i24, (int)sizeof(double));
    for (i24 = 0; i24 < loop_ub; i24++) {
      temp_max->data[temp_max->size[0] * i24] = Pitch->data[i + Pitch->size[0] *
        i24] - SPitch->data[SPitch->size[0] * i24];
    }

    i24 = b_diff->size[0] * b_diff->size[1];
    b_diff->size[0] = 1;
    b_diff->size[1] = temp_max->size[1];
    emxEnsureCapacity((emxArray__common *)b_diff, i24, (int)sizeof(double));
    for (k = 0; k + 1 <= temp_max->size[1]; k++) {
      b_diff->data[k] = fabs(temp_max->data[k]);
    }

    /*      diff(Idx_unvoiced) = freq_thresh + 1; */
    i24 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = b_diff->size[1];
    emxEnsureCapacity((emxArray__common *)temp_max, i24, (int)sizeof(double));
    loop_ub = b_diff->size[1];
    for (i24 = 0; i24 < loop_ub; i24++) {
      temp_max->data[i24] = 0.0;
    }

    i24 = b_diff->size[1];
    for (j = 0; j < i24; j++) {
      if (Idx_unvoiced->data[j]) {
        b_diff->data[j] = y->data[0] + 1.0;
      }

      X = b_diff->data[j];
      loop_ub = y->size[0];
      for (i25 = 0; i25 < loop_ub; i25++) {
        tmp_data[i25] = (signed char)(X < y->data[i25]);
      }

      temp_max->data[j] = tmp_data[0];
    }

    /*      match1 =  (diff < freq_thresh); */
    i24 = temp_min->size[0] * temp_min->size[1];
    temp_min->size[0] = 1;
    temp_min->size[1] = b_diff->size[1];
    emxEnsureCapacity((emxArray__common *)temp_min, i24, (int)sizeof(double));
    loop_ub = b_diff->size[1];
    for (i24 = 0; i24 < loop_ub; i24++) {
      temp_min->data[i24] = 0.0;
    }

    for (k = 0; k < b_diff->size[1]; k++) {
      if (y->size[0] == 0) {
        unnamed_idx_1 = 0;
      } else {
        X = 1.0 / freq_thresh_data[0] * b_diff->data[k];
        unnamed_idx_1 = 1;
        y_data[0] = X;
      }

      i24 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = unnamed_idx_1;
      emxEnsureCapacity((emxArray__common *)b_y, i24, (int)sizeof(double));
      X = temp_max->data[k];
      for (i24 = 0; i24 < unnamed_idx_1; i24++) {
        b_y->data[i24] = (1.0 - y_data[i24]) * X;
      }

      temp_min->data[k] = b_y->data[0];
    }

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    unnamed_idx_1 = Merit->size[1];
    i24 = r27->size[0] * r27->size[1];
    r27->size[0] = 1;
    r27->size[1] = unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)r27, i24, (int)sizeof(double));
    for (i24 = 0; i24 < unnamed_idx_1; i24++) {
      r27->data[r27->size[0] * i24] = (1.0 + Prm_merit_boost) * Merit->data[i +
        Merit->size[0] * i24] * temp_min->data[temp_min->size[0] * i24];
    }

    loop_ub = r27->size[1];
    for (i24 = 0; i24 < loop_ub; i24++) {
      Merit->data[i + Merit->size[0] * i24] = r27->data[r27->size[0] * i24];
    }

    i++;
  }

  emxFree_real_T(&r27);
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  emxFree_real_T(&b_diff);
  emxFree_boolean_T(&Idx_unvoiced);
  emxFree_real_T(&temp_min);
  emxFree_real_T(&temp_max);
}

/*
 * File trailer for tm_trk.c
 *
 * [EOF]
 */
