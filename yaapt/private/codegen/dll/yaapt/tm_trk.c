/*
 * File: tm_trk.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "tm_trk.h"
#include "yaapt_emxutil.h"
#include "eml_sort.h"
#include "crs_corr.h"
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
  int i15;
  int ixstart;
  double freq_thresh_data[1];
  emxArray_real_T *SRange;
  int unnamed_idx_1;
  emxArray_real_T *temp_max;
  emxArray_real_T *temp_min;
  int i;
  emxArray_real_T *b_y;
  unsigned int uv3[2];
  emxArray_real_T *c_y;
  double firstp;
  int n;
  emxArray_real_T *r6;
  emxArray_real_T *b_Data;
  emxArray_real_T *r7;
  double mtmp;
  int tmp_size_idx_1;
  double x;
  int j;
  int numpeaks;
  double b_Pitch[3];
  double b_Merit[3];
  boolean_T exitg2;
  int ix;
  boolean_T exitg3;
  boolean_T guard1 = false;
  double c_Merit[3];
  int iidx[3];
  double tmp_data[6];
  double b_tmp_data[6];
  boolean_T exitg1;
  emxArray_real_T *diff;
  emxArray_real_T *r8;
  signed char c_tmp_data[1];
  double y_data[1];
  b_emxInit_real_T(&y, 1);

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
  i15 = y->size[0];
  y->size[0] = pStd_size[0];
  emxEnsureCapacity((emxArray__common *)y, i15, (int)sizeof(double));
  ixstart = pStd_size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    y->data[i15] = 5.0 * pStd_data[i15];
  }

  ixstart = pStd_size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    freq_thresh_data[i15] = 5.0 * pStd_data[i15];
  }

  emxInit_real_T(&SRange, 2);
  i15 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  emxEnsureCapacity((emxArray__common *)SRange, i15, (int)sizeof(double));
  unnamed_idx_1 = SPitch->size[1];
  i15 = SRange->size[0] * SRange->size[1];
  SRange->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)SRange, i15, (int)sizeof(double));
  ixstart = SPitch->size[1] << 1;
  for (i15 = 0; i15 < ixstart; i15++) {
    SRange->data[i15] = 0.0;
  }

  emxInit_real_T(&temp_max, 2);

  /*  Determine the search range according spectral pitch track */
  i15 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)temp_max, i15, (int)sizeof(double));
  unnamed_idx_1 = SPitch->size[1];
  i15 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)temp_max, i15, (int)sizeof(double));
  ixstart = SPitch->size[1];
  for (i15 = 0; i15 < ixstart; i15++) {
    temp_max->data[i15] = 0.0;
  }

  emxInit_real_T(&temp_min, 2);
  i15 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)temp_min, i15, (int)sizeof(double));
  unnamed_idx_1 = SPitch->size[1];
  i15 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)temp_min, i15, (int)sizeof(double));
  ixstart = SPitch->size[1];
  for (i15 = 0; i15 < ixstart; i15++) {
    temp_min->data[i15] = 0.0;
  }

  i = 0;
  b_emxInit_real_T(&b_y, 1);
  while (i <= SPitch->size[1] - 1) {
    i15 = b_y->size[0];
    b_y->size[0] = pStd_size[0];
    emxEnsureCapacity((emxArray__common *)b_y, i15, (int)sizeof(double));
    ixstart = pStd_size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      b_y->data[i15] = 2.0 * pStd_data[i15];
    }

    temp_max->data[i] = SPitch->data[i] - b_y->data[0];
    i15 = b_y->size[0];
    b_y->size[0] = pStd_size[0];
    emxEnsureCapacity((emxArray__common *)b_y, i15, (int)sizeof(double));
    ixstart = pStd_size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      b_y->data[i15] = 2.0 * pStd_data[i15];
    }

    temp_min->data[i] = SPitch->data[i] + b_y->data[0];
    i++;
  }

  emxFree_real_T(&b_y);
  for (i15 = 0; i15 < 2; i15++) {
    uv3[i15] = (unsigned int)temp_max->size[i15];
  }

  emxInit_real_T(&c_y, 2);
  i15 = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = (int)uv3[1];
  emxEnsureCapacity((emxArray__common *)c_y, i15, (int)sizeof(double));
  for (unnamed_idx_1 = 0; unnamed_idx_1 + 1 <= (int)uv3[1]; unnamed_idx_1++) {
    if (temp_max->data[unnamed_idx_1] >= 60.0) {
      firstp = temp_max->data[unnamed_idx_1];
    } else {
      firstp = 60.0;
    }

    c_y->data[unnamed_idx_1] = firstp;
  }

  ixstart = c_y->size[1];
  for (i15 = 0; i15 < ixstart; i15++) {
    SRange->data[SRange->size[0] * i15] = c_y->data[c_y->size[0] * i15];
  }

  for (i15 = 0; i15 < 2; i15++) {
    uv3[i15] = (unsigned int)temp_min->size[i15];
  }

  i15 = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = (int)uv3[1];
  emxEnsureCapacity((emxArray__common *)c_y, i15, (int)sizeof(double));
  for (unnamed_idx_1 = 0; unnamed_idx_1 + 1 <= (int)uv3[1]; unnamed_idx_1++) {
    if (temp_min->data[unnamed_idx_1] <= 400.0) {
      firstp = temp_min->data[unnamed_idx_1];
    } else {
      firstp = 400.0;
    }

    c_y->data[unnamed_idx_1] = firstp;
  }

  ixstart = c_y->size[1];
  for (i15 = 0; i15 < ixstart; i15++) {
    SRange->data[1 + SRange->size[0] * i15] = c_y->data[c_y->size[0] * i15];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  i15 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 3;
  Pitch->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)Pitch, i15, (int)sizeof(double));
  ixstart = 3 * (int)numframes;
  for (i15 = 0; i15 < ixstart; i15++) {
    Pitch->data[i15] = 0.0;
  }

  i15 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 3;
  Merit->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)Merit, i15, (int)sizeof(double));
  ixstart = 3 * (int)numframes;
  for (i15 = 0; i15 < ixstart; i15++) {
    Merit->data[i15] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  n = 0;
  emxInit_real_T(&r6, 2);
  b_emxInit_real_T(&b_Data, 1);
  emxInit_real_T(&r7, 2);
  while (n <= (int)numframes - 1) {
    firstp = 1.0 + ((1.0 + (double)n) - 1.0) * nframejump;
    mtmp = (firstp + nframesize) - 1.0;
    if (firstp > mtmp) {
      i15 = 0;
      tmp_size_idx_1 = 0;
    } else {
      i15 = (int)firstp - 1;
      tmp_size_idx_1 = (int)mtmp;
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    firstp = Fs / SRange->data[1 + SRange->size[0] * n];
    if (firstp < 0.0) {
      x = ceil(firstp);
    } else {
      x = floor(firstp);
    }

    firstp = Fs / SRange->data[SRange->size[0] * n];
    if (firstp < 0.0) {
      firstp = ceil(firstp);
    } else {
      firstp = floor(firstp);
    }

    /*  Compute correaltion */
    j = b_Data->size[0];
    b_Data->size[0] = tmp_size_idx_1 - i15;
    emxEnsureCapacity((emxArray__common *)b_Data, j, (int)sizeof(double));
    ixstart = tmp_size_idx_1 - i15;
    for (tmp_size_idx_1 = 0; tmp_size_idx_1 < ixstart; tmp_size_idx_1++) {
      b_Data->data[tmp_size_idx_1] = Data->data[i15 + tmp_size_idx_1];
    }

    crs_corr(b_Data, x - 3.0, firstp + 3.0, temp_max);

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
    for (i15 = 0; i15 < 3; i15++) {
      b_Pitch[i15] = 0.0;
      b_Merit[i15] = 0.0;
    }

    /* -- MAIN ROUTINE -------------------------------------------------------------- */
    /*   Find all peaks for a (lag_min--to--lag_max) search range */
    /*    a "peak" must be the higher than a specfied number of */
    /*    points on either side of point.  Peaks are later "cleaned" */
    /*    up, to retain only best peaks i.e. peaks which do not meet certain */
    /*    criteria are eliminated. */
    /*    and allowing only the peaks which are a certain amplitude over the rest. */
    i15 = (int)((firstp + 3.0) + (1.0 - ((x - 3.0) - 3.0)));
    unnamed_idx_1 = 0;
    exitg2 = false;
    while ((!exitg2) && (unnamed_idx_1 <= i15 - 1)) {
      firstp = ((x - 3.0) - 3.0) + (double)unnamed_idx_1;
      if (firstp > (firstp + 5.0) - 1.0) {
        tmp_size_idx_1 = 1;
        j = 1;
      } else {
        tmp_size_idx_1 = (int)firstp;
        j = (int)(unsigned int)firstp + 5;
      }

      ixstart = 1;
      mtmp = temp_max->data[tmp_size_idx_1 - 1];
      i = 1;
      if (j - tmp_size_idx_1 > 1) {
        if (rtIsNaN(mtmp)) {
          ix = 2;
          exitg3 = false;
          while ((!exitg3) && (ix <= j - tmp_size_idx_1)) {
            ixstart = ix;
            if (!rtIsNaN(temp_max->data[(tmp_size_idx_1 + ix) - 2])) {
              mtmp = temp_max->data[(tmp_size_idx_1 + ix) - 2];
              i = ix;
              exitg3 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart < j - tmp_size_idx_1) {
          for (ix = ixstart + 1; ix <= j - tmp_size_idx_1; ix++) {
            if (temp_max->data[(tmp_size_idx_1 + ix) - 2] > mtmp) {
              mtmp = temp_max->data[(tmp_size_idx_1 + ix) - 2];
              i = ix;
            }
          }
        }
      }

      guard1 = false;
      if ((i == 3) && (mtmp > 0.25)) {
        numpeaks++;
        b_Pitch[numpeaks - 1] = Fs / ((firstp + 3.0) - 1.0);
        b_Merit[numpeaks - 1] = mtmp;
        if (mtmp > 0.9) {
          exitg2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        unnamed_idx_1++;
      }
    }

    /*  consider the case when the number of peaks are more than the maxcands. */
    /*  Then take only the best maxcands peaks based on the Merit values . */
    for (i15 = 0; i15 < 3; i15++) {
      c_Merit[i15] = b_Merit[i15];
    }

    c_eml_sort(c_Merit, b_Merit, iidx);
    for (i15 = 0; i15 < 3; i15++) {
      c_Merit[i15] = b_Pitch[iidx[i15] - 1];
    }

    for (i15 = 0; i15 < 3; i15++) {
      b_Pitch[i15] = c_Merit[i15];
    }

    if (1 > numpeaks) {
      ixstart = 0;
    } else {
      ixstart = numpeaks;
    }

    tmp_size_idx_1 = ixstart;
    for (i15 = 0; i15 < ixstart; i15++) {
      tmp_data[i15] = b_Merit[i15];
    }

    if (1 > numpeaks) {
      j = 0;
    } else {
      j = numpeaks;
    }

    for (i15 = 0; i15 < j; i15++) {
      b_tmp_data[i15] = b_Pitch[i15];
    }

    /*  if the number of peaks in the frame are less than the maxcands, then we  */
    /*  assign "null" values to remainder of peak and merit values in arrays */
    if (numpeaks < 3) {
      if (j == 0) {
        tmp_size_idx_1 = 3;
        for (i15 = 0; i15 < 3; i15++) {
          b_tmp_data[i15] = 0.0;
          tmp_data[i15] = 0.001;
        }
      } else {
        i = 3 - numpeaks;
        for (i15 = 0; i15 < i; i15++) {
          b_tmp_data[j + i15] = 0.0;
        }

        i15 = r6->size[0] * r6->size[1];
        r6->size[0] = 1;
        r6->size[1] = 3 - numpeaks;
        emxEnsureCapacity((emxArray__common *)r6, i15, (int)sizeof(double));
        j = 3 - numpeaks;
        for (i15 = 0; i15 < j; i15++) {
          r6->data[i15] = 0.001;
        }

        i = r6->size[1];
        tmp_size_idx_1 = ixstart + i;
        unnamed_idx_1 = 3 - numpeaks;
        i15 = r7->size[0] * r7->size[1];
        r7->size[0] = 1;
        r7->size[1] = unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)r7, i15, (int)sizeof(double));
        for (i15 = 0; i15 < unnamed_idx_1; i15++) {
          r7->data[r7->size[0] * i15] = 0.001;
        }

        for (i15 = 0; i15 < i; i15++) {
          tmp_data[ixstart + i15] = r7->data[i15];
        }

        /*      Pitch(numpeaks+1:maxcands) = 0; */
        /*      Merit(numpeaks+1:maxcands) = 0.001; */
      }
    }

    /*  Normlize merits */
    ixstart = 1;
    mtmp = tmp_data[0];
    if (tmp_size_idx_1 > 1) {
      if (rtIsNaN(tmp_data[0])) {
        ix = 2;
        exitg1 = false;
        while ((!exitg1) && (ix <= tmp_size_idx_1)) {
          ixstart = ix;
          if (!rtIsNaN(tmp_data[ix - 1])) {
            mtmp = tmp_data[ix - 1];
            exitg1 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < tmp_size_idx_1) {
        while (ixstart + 1 <= tmp_size_idx_1) {
          if (tmp_data[ixstart] > mtmp) {
            mtmp = tmp_data[ixstart];
          }

          ixstart++;
        }
      }
    }

    if (mtmp > 1.0) {
      for (i15 = 0; i15 < tmp_size_idx_1; i15++) {
        tmp_data[i15] /= mtmp;
      }
    }

    for (i15 = 0; i15 < 3; i15++) {
      Pitch->data[i15 + Pitch->size[0] * n] = b_tmp_data[i15];
    }

    for (i15 = 0; i15 < 3; i15++) {
      Merit->data[i15 + Merit->size[0] * n] = tmp_data[i15];
    }

    n++;
  }

  emxFree_real_T(&r7);
  emxFree_real_T(&b_Data);
  emxFree_real_T(&r6);
  emxFree_real_T(&SRange);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  emxInit_real_T(&diff, 2);
  emxInit_real_T(&r8, 2);
  for (i = 0; i < 3; i++) {
    ixstart = Pitch->size[1];
    i15 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = ixstart;
    emxEnsureCapacity((emxArray__common *)temp_max, i15, (int)sizeof(double));
    for (i15 = 0; i15 < ixstart; i15++) {
      temp_max->data[temp_max->size[0] * i15] = Pitch->data[i + Pitch->size[0] *
        i15] - SPitch->data[SPitch->size[0] * i15];
    }

    for (i15 = 0; i15 < 2; i15++) {
      uv3[i15] = (unsigned int)temp_max->size[i15];
    }

    i15 = diff->size[0] * diff->size[1];
    diff->size[0] = 1;
    diff->size[1] = (int)uv3[1];
    emxEnsureCapacity((emxArray__common *)diff, i15, (int)sizeof(double));
    for (unnamed_idx_1 = 0; unnamed_idx_1 < temp_max->size[1]; unnamed_idx_1++)
    {
      diff->data[unnamed_idx_1] = fabs(temp_max->data[unnamed_idx_1]);
    }

    i15 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)temp_max, i15, (int)sizeof(double));
    unnamed_idx_1 = diff->size[1];
    i15 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[1] = unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)temp_max, i15, (int)sizeof(double));
    ixstart = diff->size[1];
    for (i15 = 0; i15 < ixstart; i15++) {
      temp_max->data[i15] = 0.0;
    }

    for (j = 0; j < diff->size[1]; j++) {
      firstp = diff->data[j];
      ixstart = y->size[0];
      for (i15 = 0; i15 < ixstart; i15++) {
        c_tmp_data[i15] = (signed char)(firstp < y->data[i15]);
      }

      temp_max->data[j] = c_tmp_data[0];
    }

    /*      match1 =  (diff < freq_thresh); */
    i15 = temp_min->size[0] * temp_min->size[1];
    temp_min->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)temp_min, i15, (int)sizeof(double));
    unnamed_idx_1 = diff->size[1];
    i15 = temp_min->size[0] * temp_min->size[1];
    temp_min->size[1] = unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)temp_min, i15, (int)sizeof(double));
    ixstart = diff->size[1];
    for (i15 = 0; i15 < ixstart; i15++) {
      temp_min->data[i15] = 0.0;
    }

    for (j = 0; j < diff->size[1]; j++) {
      if (y->size[0] == 0) {
        unnamed_idx_1 = 0;
      } else {
        firstp = 1.0 / freq_thresh_data[0] * diff->data[j];
        unnamed_idx_1 = 1;
        y_data[0] = firstp;
      }

      i15 = c_y->size[0] * c_y->size[1];
      c_y->size[0] = 1;
      c_y->size[1] = unnamed_idx_1;
      emxEnsureCapacity((emxArray__common *)c_y, i15, (int)sizeof(double));
      firstp = temp_max->data[j];
      ixstart = unnamed_idx_1;
      i15 = 0;
      while (i15 <= ixstart - 1) {
        c_y->data[0] = (1.0 - y_data[0]) * firstp;
        i15 = 1;
      }

      temp_min->data[j] = c_y->data[0];
    }

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    unnamed_idx_1 = Merit->size[1];
    i15 = r8->size[0] * r8->size[1];
    r8->size[0] = 1;
    r8->size[1] = unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)r8, i15, (int)sizeof(double));
    for (i15 = 0; i15 < unnamed_idx_1; i15++) {
      r8->data[r8->size[0] * i15] = 1.2 * Merit->data[i + Merit->size[0] * i15] *
        temp_min->data[temp_min->size[0] * i15];
    }

    ixstart = r8->size[1];
    for (i15 = 0; i15 < ixstart; i15++) {
      Merit->data[i + Merit->size[0] * i15] = r8->data[r8->size[0] * i15];
    }
  }

  emxFree_real_T(&r8);
  emxFree_real_T(&c_y);
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
