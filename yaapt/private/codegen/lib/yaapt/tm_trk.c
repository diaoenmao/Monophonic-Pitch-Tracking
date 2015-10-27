/*
 * File: tm_trk.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 26-Oct-2015 23:41:06
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "tm_trk.h"
#include "rdivide.h"
#include "eml_sort.h"
#include "crs_corr.h"
#include "yaapt_emxutil.h"
#include "fix.h"
#include "yaapt_rtwutil.h"

/* Function Declarations */
static double b_eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B);
static double b_eml_xnrm2(int n, const emxArray_real_T *x, int ix0);
static void b_eml_xscal(int n, double a, emxArray_real_T *x);

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *B
 * Return Type  : double
 */
static double b_eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B)
{
  double Y;
  int mn;
  emxArray_real_T *b_A;
  int i;
  int knt;
  int b_mn;
  double atmp;
  double tau_data_idx_0;
  double xnorm;
  double beta1;
  if (A->size[0] <= 1) {
    mn = A->size[0];
  } else {
    mn = 1;
  }

  b_emxInit_real_T(&b_A, 1);
  i = b_A->size[0];
  b_A->size[0] = A->size[0];
  emxEnsureCapacity((emxArray__common *)b_A, i, (int)sizeof(double));
  knt = A->size[0];
  for (i = 0; i < knt; i++) {
    b_A->data[i] = A->data[i];
  }

  if (A->size[0] <= 1) {
    b_mn = A->size[0];
  } else {
    b_mn = 1;
  }

  if (A->size[0] == 0) {
  } else {
    i = 1;
    while (i <= b_mn) {
      if (1 < A->size[0]) {
        atmp = b_A->data[0];
        tau_data_idx_0 = 0.0;
        xnorm = b_eml_xnrm2(A->size[0] - 1, b_A, 2);
        if (xnorm != 0.0) {
          beta1 = rt_hypotd_snf(b_A->data[0], xnorm);
          if (b_A->data[0] >= 0.0) {
            beta1 = -beta1;
          }

          if (fabs(beta1) < 1.0020841800044864E-292) {
            knt = 0;
            do {
              knt++;
              b_eml_xscal(A->size[0] - 1, 9.9792015476736E+291, b_A);
              beta1 *= 9.9792015476736E+291;
              atmp *= 9.9792015476736E+291;
            } while (!(fabs(beta1) >= 1.0020841800044864E-292));

            xnorm = b_eml_xnrm2(A->size[0] - 1, b_A, 2);
            beta1 = rt_hypotd_snf(atmp, xnorm);
            if (atmp >= 0.0) {
              beta1 = -beta1;
            }

            tau_data_idx_0 = (beta1 - atmp) / beta1;
            b_eml_xscal(A->size[0] - 1, 1.0 / (atmp - beta1), b_A);
            for (i = 1; i <= knt; i++) {
              beta1 *= 1.0020841800044864E-292;
            }

            atmp = beta1;
          } else {
            tau_data_idx_0 = (beta1 - b_A->data[0]) / beta1;
            xnorm = 1.0 / (b_A->data[0] - beta1);
            b_eml_xscal(A->size[0] - 1, xnorm, b_A);
            atmp = beta1;
          }
        }
      } else {
        atmp = b_A->data[0];
        tau_data_idx_0 = eml_matlab_zlarfg();
      }

      b_A->data[0] = atmp;
      i = 2;
    }
  }

  atmp = 0.0;
  if (mn > 0) {
    if (A->size[0] >= 1) {
      i = A->size[0];
    } else {
      i = 1;
    }

    xnorm = (double)i * fabs(b_A->data[0]) * 2.2204460492503131E-16;
    i = 0;
    while ((i <= 0) && (!(fabs(b_A->data[0]) <= xnorm))) {
      atmp++;
      i = 1;
    }
  }

  Y = 0.0;
  i = 0;
  while (i <= mn - 1) {
    if (tau_data_idx_0 != 0.0) {
      xnorm = B->data[0];
      for (i = 1; i - 1 <= A->size[0] - 2; i++) {
        xnorm += b_A->data[i] * B->data[i];
      }

      xnorm *= tau_data_idx_0;
      if (xnorm != 0.0) {
        B->data[0] -= xnorm;
        for (i = 1; i - 1 <= A->size[0] - 2; i++) {
          B->data[i] -= b_A->data[i] * xnorm;
        }
      }
    }

    i = 1;
  }

  for (i = 0; i < (int)atmp; i++) {
    Y = B->data[0];
  }

  for (i = 0; i < (int)-(1.0 + (-1.0 - atmp)); i++) {
    Y /= b_A->data[0];
  }

  emxFree_real_T(&b_A);
  return Y;
}

/*
 * Arguments    : int n
 *                const emxArray_real_T *x
 *                int ix0
 * Return Type  : double
 */
static double b_eml_xnrm2(int n, const emxArray_real_T *x, int ix0)
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
 * Return Type  : void
 */
static void b_eml_xscal(int n, double a, emxArray_real_T *x)
{
  int k;
  for (k = 1; k + 1 <= n + 1; k++) {
    x->data[k] *= a;
  }
}

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
 *                const emxArray_real_T *pStd
 *                emxArray_real_T *Pitch
 *                emxArray_real_T *Merit
 * Return Type  : void
 */
void tm_trk(const emxArray_real_T *Data, double Fs, const emxArray_real_T
            *SPitch, const emxArray_real_T *pStd, emxArray_real_T *Pitch,
            emxArray_real_T *Merit)
{
  emxArray_real_T *freq_thresh;
  double nframesize;
  double nframejump;
  double numframes;
  int i16;
  int loop_ub;
  emxArray_real_T *SRange;
  emxArray_real_T *Phi;
  unsigned int uv3[2];
  emxArray_real_T *diff;
  double y;
  int n;
  emxArray_real_T *b_Data;
  double firstp;
  int i17;
  double x;
  int i;
  int numpeaks;
  double b_Pitch[3];
  double b_Merit[3];
  boolean_T exitg2;
  int ixstart;
  int itmp;
  int ix;
  boolean_T exitg3;
  boolean_T guard1 = false;
  double c_Merit[3];
  int iidx[3];
  int tmp_size[2];
  double tmp_data[3];
  double b_tmp_data[3];
  int c_tmp_data[3];
  boolean_T exitg1;
  emxArray_real_T d_tmp_data;
  emxArray_real_T *b_freq_thresh;
  emxArray_real_T *b_diff;
  emxArray_real_T *r3;
  emxInit_real_T(&freq_thresh, 2);

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
  nframesize = 25.0 * Fs / 1000.0;
  b_fix(&nframesize);
  nframejump = 10.0 * Fs / 1000.0;
  b_fix(&nframejump);

  /*  overlap width in sample  */
  numframes = ((double)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /*  The maximum number of pitch candidates */
  /* freq_thresh = pAvg;  % seems too large */
  i16 = freq_thresh->size[0] * freq_thresh->size[1];
  freq_thresh->size[0] = 1;
  freq_thresh->size[1] = pStd->size[1];
  emxEnsureCapacity((emxArray__common *)freq_thresh, i16, (int)sizeof(double));
  loop_ub = pStd->size[0] * pStd->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    freq_thresh->data[i16] = 5.0 * pStd->data[i16];
  }

  emxInit_real_T(&SRange, 2);
  i16 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  emxEnsureCapacity((emxArray__common *)SRange, i16, (int)sizeof(double));
  loop_ub = SPitch->size[1];
  i16 = SRange->size[0] * SRange->size[1];
  SRange->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)SRange, i16, (int)sizeof(double));
  loop_ub = SPitch->size[1] << 1;
  for (i16 = 0; i16 < loop_ub; i16++) {
    SRange->data[i16] = 0.0;
  }

  emxInit_real_T(&Phi, 2);

  /*  Determine the search range according spectral pitch track */
  i16 = Phi->size[0] * Phi->size[1];
  Phi->size[0] = 1;
  Phi->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Phi, i16, (int)sizeof(double));
  loop_ub = SPitch->size[0] * SPitch->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    Phi->data[i16] = SPitch->data[i16] - 2.0 * pStd->data[i16];
  }

  for (i16 = 0; i16 < 2; i16++) {
    uv3[i16] = (unsigned int)Phi->size[i16];
  }

  emxInit_real_T(&diff, 2);
  i16 = diff->size[0] * diff->size[1];
  diff->size[0] = 1;
  diff->size[1] = (int)uv3[1];
  emxEnsureCapacity((emxArray__common *)diff, i16, (int)sizeof(double));
  for (loop_ub = 0; loop_ub + 1 <= (int)uv3[1]; loop_ub++) {
    if (Phi->data[loop_ub] >= 60.0) {
      y = Phi->data[loop_ub];
    } else {
      y = 60.0;
    }

    diff->data[loop_ub] = y;
  }

  loop_ub = diff->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    SRange->data[SRange->size[0] * i16] = diff->data[diff->size[0] * i16];
  }

  i16 = Phi->size[0] * Phi->size[1];
  Phi->size[0] = 1;
  Phi->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Phi, i16, (int)sizeof(double));
  loop_ub = SPitch->size[0] * SPitch->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    Phi->data[i16] = SPitch->data[i16] + 2.0 * pStd->data[i16];
  }

  for (i16 = 0; i16 < 2; i16++) {
    uv3[i16] = (unsigned int)Phi->size[i16];
  }

  i16 = diff->size[0] * diff->size[1];
  diff->size[0] = 1;
  diff->size[1] = (int)uv3[1];
  emxEnsureCapacity((emxArray__common *)diff, i16, (int)sizeof(double));
  for (loop_ub = 0; loop_ub + 1 <= (int)uv3[1]; loop_ub++) {
    if (Phi->data[loop_ub] <= 400.0) {
      y = Phi->data[loop_ub];
    } else {
      y = 400.0;
    }

    diff->data[loop_ub] = y;
  }

  loop_ub = diff->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    SRange->data[1 + SRange->size[0] * i16] = diff->data[diff->size[0] * i16];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  i16 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 3;
  Pitch->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)Pitch, i16, (int)sizeof(double));
  loop_ub = 3 * (int)numframes;
  for (i16 = 0; i16 < loop_ub; i16++) {
    Pitch->data[i16] = 0.0;
  }

  i16 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 3;
  Merit->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)Merit, i16, (int)sizeof(double));
  loop_ub = 3 * (int)numframes;
  for (i16 = 0; i16 < loop_ub; i16++) {
    Merit->data[i16] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  n = 0;
  emxInit_real_T(&b_Data, 2);
  while (n <= (int)numframes - 1) {
    firstp = 1.0 + ((1.0 + (double)n) - 1.0) * nframejump;
    y = (firstp + nframesize) - 1.0;
    if (firstp > y) {
      i16 = 0;
      i17 = 0;
    } else {
      i16 = (int)firstp - 1;
      i17 = (int)y;
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    y = Fs / SRange->data[1 + SRange->size[0] * n];
    if (y < 0.0) {
      x = ceil(y);
    } else {
      x = floor(y);
    }

    y = Fs / SRange->data[SRange->size[0] * n];
    if (y < 0.0) {
      firstp = ceil(y);
    } else {
      firstp = floor(y);
    }

    /*  Compute correaltion */
    i = b_Data->size[0] * b_Data->size[1];
    b_Data->size[0] = 1;
    b_Data->size[1] = i17 - i16;
    emxEnsureCapacity((emxArray__common *)b_Data, i, (int)sizeof(double));
    loop_ub = i17 - i16;
    for (i17 = 0; i17 < loop_ub; i17++) {
      b_Data->data[b_Data->size[0] * i17] = Data->data[i16 + i17];
    }

    crs_corr(b_Data, x - 3.0, firstp + 3.0, Phi);

    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    /*  CMP_RATE compute rate and merit from the autocorrelation sequence */
    /*  */
    /*  [Pitch, Merit] = cmp_rate(Phi,Fs,maxcands,lag_min,lag_max,Prm); */
    /*   This routine computes Pitch estimates and the corresponding Merit values  */
    /*   associated with the peaks found in each frame based on the correlation sequence. */
    /*  */
    /*   INPUTS: */
    /*    Phi     : The input signal(either auto correlated/normalized cross correlated). */
    /*    Fs      : The sampling frequency. */
    /*    lag_min : The lowest lag(== 1/F0_max) involved in the F0 estimation. */
    /*    F0_max  : The highest lag(== 1/F0_min)  involved in the F0 estimation. */
    /*              greater than the peak at F0 during the first pass of search. */
    /*    maxcands: The maximum number of top candidates to be considered. */
    /*  */
    /*   OUTPUTS: */
    /*     Pitch  : The Rate/Pitch values for the peaks found for each frame. */
    /*     Merit  : The Merit values of the peaks found in each frame. */
    /*   Creation date:   2002 */
    /*   Revision dates:   March 26, 2002, December 24, 2005 */
    /*   Programmer: S.A.Zahorian,Kasi Kavita */
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
    /* -- PARAMETERS: set up all of these parameters -------------------------------- */
    /* Width of the window used in first pass of peak picking. */
    /*  The center of the window is defined as the peak location. */
    /*  The threshold value used for the first pass of */
    /*  peak picking for each frame.any peaks found greater than this */
    /*  are chosen in the first pass. */
    /*   The threshold value used to limit peak searching. */
    /*   If a peak is found at least this great, no further  searching is */
    /*   done increased from prev. value of 0.85. */
    /* -- INITIALIZATION ----------------------------------------------------------- */
    numpeaks = 0;
    for (i16 = 0; i16 < 3; i16++) {
      b_Pitch[i16] = 0.0;
      b_Merit[i16] = 0.0;
    }

    /* -- MAIN ROUTINE -------------------------------------------------------------- */
    /*   Find all peaks for a (lag_min--to--lag_max) search range */
    /*    a "peak" must be the higher than a specfied number of */
    /*    points on either side of point.  Peaks are later "cleaned" */
    /*    up, to retain only best peaks i.e. peaks which do not meet certain */
    /*    criteria are eliminated. */
    /*    and allowing only the peaks which are a certain amplitude over the rest. */
    i16 = (int)((firstp + 3.0) + (1.0 - ((x - 3.0) - 3.0)));
    loop_ub = 0;
    exitg2 = false;
    while ((!exitg2) && (loop_ub <= i16 - 1)) {
      firstp = ((x - 3.0) - 3.0) + (double)loop_ub;
      if (firstp > (firstp + 5.0) - 1.0) {
        i17 = 0;
        i = 0;
      } else {
        i17 = (int)firstp - 1;
        i = (int)((unsigned int)firstp + 4U);
      }

      ixstart = 1;
      y = Phi->data[i17];
      itmp = 1;
      if (i - i17 > 1) {
        if (rtIsNaN(y)) {
          ix = 2;
          exitg3 = false;
          while ((!exitg3) && (ix <= i - i17)) {
            ixstart = ix;
            if (!rtIsNaN(Phi->data[(i17 + ix) - 1])) {
              y = Phi->data[(i17 + ix) - 1];
              itmp = ix;
              exitg3 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart < i - i17) {
          for (ix = ixstart + 1; ix <= i - i17; ix++) {
            if (Phi->data[(i17 + ix) - 1] > y) {
              y = Phi->data[(i17 + ix) - 1];
              itmp = ix;
            }
          }
        }
      }

      guard1 = false;
      if ((itmp == 3) && (y > 0.25)) {
        numpeaks++;
        b_Pitch[numpeaks - 1] = Fs / ((firstp + 3.0) - 1.0);
        b_Merit[numpeaks - 1] = y;
        if (y > 0.9) {
          exitg2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        loop_ub++;
      }
    }

    /*  consider the case when the number of peaks are more than the maxcands. */
    /*  Then take only the best maxcands peaks based on the Merit values . */
    for (i16 = 0; i16 < 3; i16++) {
      c_Merit[i16] = b_Merit[i16];
    }

    c_eml_sort(c_Merit, b_Merit, iidx);
    for (i16 = 0; i16 < 3; i16++) {
      c_Merit[i16] = b_Pitch[iidx[i16] - 1];
    }

    for (i16 = 0; i16 < 3; i16++) {
      b_Pitch[i16] = c_Merit[i16];
    }

    if (1 > numpeaks) {
      loop_ub = 0;
    } else {
      loop_ub = numpeaks;
    }

    tmp_size[0] = 1;
    tmp_size[1] = loop_ub;
    for (i16 = 0; i16 < loop_ub; i16++) {
      tmp_data[tmp_size[0] * i16] = b_Merit[i16];
    }

    if (1 > numpeaks) {
      loop_ub = 0;
    } else {
      loop_ub = numpeaks;
    }

    for (i16 = 0; i16 < loop_ub; i16++) {
      b_tmp_data[i16] = b_Pitch[i16];
    }

    /*  if the number of peaks in the frame are less than the maxcands, then we  */
    /*  assign "null" values to remainder of peak and merit values in arrays */
    if (numpeaks < 3) {
      loop_ub = -numpeaks;
      for (i16 = 0; i16 <= loop_ub + 2; i16++) {
        c_tmp_data[i16] = numpeaks + i16;
      }

      loop_ub = 3 - numpeaks;
      for (i16 = 0; i16 < loop_ub; i16++) {
        b_tmp_data[c_tmp_data[i16]] = 0.0;
      }

      loop_ub = -numpeaks;
      for (i16 = 0; i16 <= loop_ub + 2; i16++) {
        c_tmp_data[i16] = numpeaks + i16;
      }

      loop_ub = 3 - numpeaks;
      for (i16 = 0; i16 < loop_ub; i16++) {
        tmp_data[c_tmp_data[i16]] = 0.001;
      }
    }

    /*  Normlize merits */
    ixstart = 1;
    y = tmp_data[0];
    if (tmp_size[1] > 1) {
      if (rtIsNaN(y)) {
        ix = 2;
        exitg1 = false;
        while ((!exitg1) && (ix <= tmp_size[1])) {
          ixstart = ix;
          if (!rtIsNaN(tmp_data[ix - 1])) {
            y = tmp_data[ix - 1];
            exitg1 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < tmp_size[1]) {
        while (ixstart + 1 <= tmp_size[1]) {
          if (tmp_data[ixstart] > y) {
            y = tmp_data[ixstart];
          }

          ixstart++;
        }
      }
    }

    if (y > 1.0) {
      d_tmp_data.data = (double *)&tmp_data;
      d_tmp_data.size = (int *)&tmp_size;
      d_tmp_data.allocatedSize = 3;
      d_tmp_data.numDimensions = 2;
      d_tmp_data.canFreeData = false;
      c_rdivide(&d_tmp_data, y, diff);
      tmp_size[0] = 1;
      tmp_size[1] = diff->size[1];
      loop_ub = diff->size[0] * diff->size[1];
      for (i16 = 0; i16 < loop_ub; i16++) {
        tmp_data[i16] = diff->data[i16];
      }
    }

    for (i16 = 0; i16 < 3; i16++) {
      Pitch->data[i16 + Pitch->size[0] * n] = b_tmp_data[i16];
    }

    for (i16 = 0; i16 < 3; i16++) {
      Merit->data[i16 + Merit->size[0] * n] = tmp_data[i16];
    }

    n++;
  }

  emxFree_real_T(&b_Data);
  emxFree_real_T(&SRange);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  b_emxInit_real_T(&b_freq_thresh, 1);
  b_emxInit_real_T(&b_diff, 1);
  emxInit_real_T(&r3, 2);
  for (i = 0; i < 3; i++) {
    loop_ub = Pitch->size[1];
    i16 = Phi->size[0] * Phi->size[1];
    Phi->size[0] = 1;
    Phi->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)Phi, i16, (int)sizeof(double));
    for (i16 = 0; i16 < loop_ub; i16++) {
      Phi->data[Phi->size[0] * i16] = Pitch->data[i + Pitch->size[0] * i16] -
        SPitch->data[SPitch->size[0] * i16];
    }

    for (i16 = 0; i16 < 2; i16++) {
      uv3[i16] = (unsigned int)Phi->size[i16];
    }

    i16 = diff->size[0] * diff->size[1];
    diff->size[0] = 1;
    diff->size[1] = (int)uv3[1];
    emxEnsureCapacity((emxArray__common *)diff, i16, (int)sizeof(double));
    for (loop_ub = 0; loop_ub < Phi->size[1]; loop_ub++) {
      diff->data[loop_ub] = fabs(Phi->data[loop_ub]);
    }

    if ((diff->size[1] == 0) || (freq_thresh->size[1] == 0)) {
      i16 = Phi->size[0] * Phi->size[1];
      Phi->size[0] = 1;
      Phi->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)Phi, i16, (int)sizeof(double));
      Phi->data[0] = 0.0;
    } else if (1 == freq_thresh->size[1]) {
      i16 = Phi->size[0] * Phi->size[1];
      Phi->size[0] = 1;
      Phi->size[1] = diff->size[1];
      emxEnsureCapacity((emxArray__common *)Phi, i16, (int)sizeof(double));
      loop_ub = diff->size[0] * diff->size[1];
      for (i16 = 0; i16 < loop_ub; i16++) {
        Phi->data[i16] = diff->data[i16];
      }

      Phi->data[0] *= 1.0 / freq_thresh->data[0];
    } else {
      i16 = b_freq_thresh->size[0];
      b_freq_thresh->size[0] = freq_thresh->size[1];
      emxEnsureCapacity((emxArray__common *)b_freq_thresh, i16, (int)sizeof
                        (double));
      loop_ub = freq_thresh->size[1];
      for (i16 = 0; i16 < loop_ub; i16++) {
        b_freq_thresh->data[i16] = freq_thresh->data[freq_thresh->size[0] * i16];
      }

      i16 = b_diff->size[0];
      b_diff->size[0] = diff->size[1];
      emxEnsureCapacity((emxArray__common *)b_diff, i16, (int)sizeof(double));
      loop_ub = diff->size[1];
      for (i16 = 0; i16 < loop_ub; i16++) {
        b_diff->data[i16] = diff->data[diff->size[0] * i16];
      }

      i16 = Phi->size[0] * Phi->size[1];
      Phi->size[0] = 1;
      Phi->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)Phi, i16, (int)sizeof(double));
      y = b_eml_qrsolve(b_freq_thresh, b_diff);
      Phi->data[0] = y;
    }

    loop_ub = Merit->size[1];
    i16 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)r3, i16, (int)sizeof(double));
    for (i16 = 0; i16 < loop_ub; i16++) {
      r3->data[r3->size[0] * i16] = 1.2 * Merit->data[i + Merit->size[0] * i16] *
        ((1.0 - Phi->data[Phi->size[0] * i16]) * (double)(diff->data[diff->size
          [0] * i16] < freq_thresh->data[freq_thresh->size[0] * i16]));
    }

    loop_ub = r3->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      Merit->data[i + Merit->size[0] * i16] = r3->data[r3->size[0] * i16];
    }
  }

  emxFree_real_T(&r3);
  emxFree_real_T(&b_diff);
  emxFree_real_T(&b_freq_thresh);
  emxFree_real_T(&diff);
  emxFree_real_T(&Phi);
  emxFree_real_T(&freq_thresh);
}

/*
 * File trailer for tm_trk.c
 *
 * [EOF]
 */
