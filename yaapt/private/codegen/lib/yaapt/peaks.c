/*
 * File: peaks.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 11-Dec-2015 06:07:48
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "peaks.h"
#include "sort1.h"
#include "yaapt_emxutil.h"
#include "mean.h"

/* Function Definitions */

/*
 * PEAKS  find peaks in SHC
 *
 *    [Pitch,Merit] = peaks(Data, delta, maxpeaks, Prm)
 *    computes peaks in a frequency domain function
 *    associated with the peaks found in each frame based on the
 *    correlation sequence.
 *
 * INPUTS:
 *    Data:  The input signal(either autocorrelated/normalized cross correlated).
 *    delta: The resolution of spectrum
 *    maxpeaks: The max number of peaks picked
 *    Prm:   Parameters
 *
 * OUTPUTS:
 *    Pitch:  The Pitch/Pitch values for the peaks found for each frame.
 *    Merit:  The Merit values of the peaks found in each frame.
 * Arguments    : emxArray_real_T *Data
 *                double delta
 *                double Pitch_data[]
 *                int Pitch_size[2]
 *                double Merit_data[]
 *                int Merit_size[2]
 * Return Type  : void
 */
void peaks(emxArray_real_T *Data, double delta, double Pitch_data[], int
           Pitch_size[2], double Merit_data[], int Merit_size[2])
{
  double mtmp;
  double width;
  double center;
  double min_lag;
  double max_lag;
  double Pitch[100];
  double Merit[100];
  int i9;
  int i10;
  int ixstart;
  int n;
  int ix;
  boolean_T exitg2;
  emxArray_real_T *b_Data;
  int i11;
  double avg_data;
  int numpeaks;
  double b_n;
  int c_n;
  int itmp;
  boolean_T exitg1;
  int iidx[100];
  double b_Pitch[100];
  double b_Pitch_data[15];
  signed char tmp_data[3];

  /*   Creation date:   March 1, 2006 */
  /*   Revision dates:  March 11, 2006,  Jun 26, 2006, July 27, 2007 */
  /*   Programmer: S.A.Zahorian, Princy  Dikshit, Hongbing Hu */
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
  /*  Threshold for max avaliable peak */
  /*  Threshold for available peaks */
  /* -- COMPUTED VARIABLES -------------------------------------------------------- */
  /*  Length in Hz of range(must be largest to be a peak) */
  mtmp = 50.0 / delta;
  if (mtmp < 0.0) {
    width = ceil(mtmp);
  } else {
    width = floor(mtmp);
  }

  /*  Window width in sample */
  if (width - floor(width / 2.0) * 2.0 == 0.0) {
    width++;
  }

  /*  The center of the window is defined as the peak location. */
  center = ceil(width / 2.0);

  /*  Lowest frequency at which F0 is allowed */
  mtmp = 60.0 / delta - width / 4.0;
  if (mtmp < 0.0) {
    min_lag = ceil(mtmp);
  } else {
    min_lag = floor(mtmp);
  }

  /*  Highest frequency at which F0 is allowed */
  mtmp = 400.0 / delta + width / 4.0;
  if (mtmp < 0.0) {
    max_lag = ceil(mtmp);
  } else {
    max_lag = floor(mtmp);
  }

  if (min_lag < 1.0) {
    min_lag = 1.0;
  }

  if (max_lag > (double)Data->size[1] - width) {
    max_lag = (double)Data->size[1] - width;
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /*  Peak(Pitch) candidates */
  for (i9 = 0; i9 < 100; i9++) {
    Pitch[i9] = 0.0;
    Merit[i9] = 0.0;
  }

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  if (min_lag > max_lag) {
    i9 = 1;
    i10 = 1;
  } else {
    i9 = (int)min_lag;
    i10 = (int)max_lag + 1;
  }

  ixstart = 1;
  n = i10 - i9;
  mtmp = Data->data[i9 - 1];
  if (i10 - i9 > 1) {
    if (rtIsNaN(mtmp)) {
      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= n)) {
        ixstart = ix;
        if (!rtIsNaN(Data->data[(i9 + ix) - 2])) {
          mtmp = Data->data[(i9 + ix) - 2];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < i10 - i9) {
      for (ix = ixstart - 1; ix + 2 <= n; ix++) {
        if (Data->data[i9 + ix] > mtmp) {
          mtmp = Data->data[i9 + ix];
        }
      }
    }
  }

  if (mtmp > 1.0E-14) {
    i9 = Data->size[0] * Data->size[1];
    Data->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)Data, i9, (int)sizeof(double));
    ixstart = Data->size[0];
    n = Data->size[1];
    ix = ixstart * n;
    for (i9 = 0; i9 < ix; i9++) {
      Data->data[i9] /= mtmp;
    }
  }

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  if (min_lag > max_lag) {
    i9 = 0;
    i10 = 0;
  } else {
    i9 = (int)min_lag - 1;
    i10 = (int)max_lag;
  }

  emxInit_real_T(&b_Data, 2);
  i11 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = i10 - i9;
  emxEnsureCapacity((emxArray__common *)b_Data, i11, (int)sizeof(double));
  ix = i10 - i9;
  for (i10 = 0; i10 < ix; i10++) {
    b_Data->data[b_Data->size[0] * i10] = Data->data[i9 + i10];
  }

  avg_data = mean(b_Data);
  emxFree_real_T(&b_Data);
  if (avg_data > 0.2) {
    /*     numpeaks = 0; */
    Pitch_size[0] = 1;
    Pitch_size[1] = 4;
    Merit_size[0] = 1;
    Merit_size[1] = 4;
    for (i9 = 0; i9 < 4; i9++) {
      Pitch_data[i9] = 0.0;
      Merit_data[i9] = 1.0;
    }

    /*  force an early end for unoviced frame  */
  } else {
    /*  Step 1 */
    /*  Find all peaks for search range */
    /*  a "peak" must be the higher than a specfied number of */
    /*  points on either side of point.  Peaks are further "cleaned" */
    /*  up, to retain only best peaks i.e. peaks which do not meet certain */
    /*  criteria are eliminated. */
    numpeaks = 0;
    i9 = (int)(max_lag + (1.0 - min_lag));
    for (n = 0; n < i9; n++) {
      b_n = min_lag + (double)n;
      mtmp = (b_n + width) - 1.0;
      if (b_n > mtmp) {
        i10 = 1;
        i11 = 1;
      } else {
        i10 = (int)b_n;
        i11 = (int)mtmp + 1;
      }

      ixstart = 1;
      c_n = i11 - i10;
      mtmp = Data->data[i10 - 1];
      itmp = 1;
      if (i11 - i10 > 1) {
        if (rtIsNaN(mtmp)) {
          ix = 2;
          exitg1 = false;
          while ((!exitg1) && (ix <= c_n)) {
            ixstart = ix;
            if (!rtIsNaN(Data->data[(i10 + ix) - 2])) {
              mtmp = Data->data[(i10 + ix) - 2];
              itmp = ix;
              exitg1 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart < i11 - i10) {
          for (ix = ixstart + 1; ix <= c_n; ix++) {
            if (Data->data[(i10 + ix) - 2] > mtmp) {
              mtmp = Data->data[(i10 + ix) - 2];
              itmp = ix;
            }
          }
        }
      }

      /*  find peaks which are larger than threshold    */
      if ((itmp == center) && (mtmp > 1.25 * avg_data)) {
        /*  Note Pitch(1) = delta, Pitch(2) = 2*delta */
        /*  Convert FFT indices to Pitch in Hz */
        numpeaks++;
        Pitch[numpeaks - 1] = ((b_n + center) - 1.0) * delta;
        Merit[numpeaks - 1] = mtmp;
      }
    }

    /*  Step 2 */
    /*  Be sure there is large peak */
    mtmp = Merit[0];
    for (ix = 1; ix + 1 < 101; ix++) {
      if (Merit[ix] > mtmp) {
        mtmp = Merit[ix];
      }
    }

    if (mtmp / avg_data < 5.0) {
      /*    numpeaks = 0; */
      Pitch_size[0] = 1;
      Pitch_size[1] = 4;
      Merit_size[0] = 1;
      Merit_size[1] = 4;
      for (i9 = 0; i9 < 4; i9++) {
        Pitch_data[i9] = 0.0;
        Merit_data[i9] = 1.0;
      }
    } else {
      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      sort(Merit, iidx);
      for (i9 = 0; i9 < 100; i9++) {
        b_Pitch[i9] = Pitch[iidx[i9] - 1];
      }

      memcpy(&Pitch[0], &b_Pitch[0], 100U * sizeof(double));

      /*  keep the number of peaks not greater than max number */
      if (numpeaks <= 4) {
      } else {
        numpeaks = 4;
      }

      if (1 > numpeaks) {
        ix = 0;
      } else {
        ix = numpeaks;
      }

      Pitch_size[0] = 1;
      Pitch_size[1] = ix;
      for (i9 = 0; i9 < ix; i9++) {
        Pitch_data[i9] = Pitch[i9];
      }

      if (1 > numpeaks) {
        ixstart = 0;
      } else {
        ixstart = numpeaks;
      }

      Merit_size[0] = 1;
      Merit_size[1] = ixstart;
      for (i9 = 0; i9 < ixstart; i9++) {
        Merit_data[i9] = Merit[i9];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      if (numpeaks > 0) {
        /*  if best peak has F < this, insert peak at 2F */
        for (i9 = 0; i9 < ix; i9++) {
          b_Pitch_data[i9] = Pitch[i9];
        }

        if (b_Pitch_data[0] > 150.0) {
          if (numpeaks + 1 <= 4) {
            numpeaks++;
          } else {
            numpeaks = 4;
          }

          if (numpeaks > ix) {
            n = numpeaks - ix;
            Pitch_size[1] = (ix + numpeaks) - ix;
            for (i9 = 0; i9 < n; i9++) {
              Pitch_data[ix + i9] = 0.0;
            }

            n = numpeaks - ixstart;
            Merit_size[1] = (ixstart + numpeaks) - ixstart;
            for (i9 = 0; i9 < n; i9++) {
              Merit_data[ixstart + i9] = 0.0;
            }
          }

          Pitch_data[numpeaks - 1] = Pitch_data[0] / 2.0;

          /*  Set merit for inserted peaks */
          Merit_data[numpeaks - 1] = 0.4;
        }

        /*  If best peak has F > this, insert peak at half F */
        if (Pitch_data[0] < 150.0) {
          if (numpeaks + 1 <= 4) {
            numpeaks++;
          } else {
            numpeaks = 4;
          }

          if (numpeaks > Pitch_size[1]) {
            n = numpeaks - Pitch_size[1];
            ixstart = Pitch_size[1] + n;
            ix = Pitch_size[1];
            for (i9 = 0; i9 < ix; i9++) {
              b_Pitch_data[i9] = Pitch_data[i9];
            }

            for (i9 = 0; i9 < n; i9++) {
              b_Pitch_data[i9 + Pitch_size[1]] = 0.0;
            }

            Pitch_size[0] = 1;
            Pitch_size[1] = ixstart;
            for (i9 = 0; i9 < ixstart; i9++) {
              Pitch_data[i9] = b_Pitch_data[i9];
            }

            n = numpeaks - Merit_size[1];
            ixstart = Merit_size[1] + n;
            ix = Merit_size[1];
            for (i9 = 0; i9 < ix; i9++) {
              b_Pitch_data[i9] = Merit_data[i9];
            }

            for (i9 = 0; i9 < n; i9++) {
              b_Pitch_data[i9 + Merit_size[1]] = 0.0;
            }

            Merit_size[0] = 1;
            Merit_size[1] = ixstart;
            for (i9 = 0; i9 < ixstart; i9++) {
              Merit_data[i9] = b_Pitch_data[i9];
            }
          }

          Pitch_data[numpeaks - 1] = 2.0 * Pitch_data[0];
          Merit_data[numpeaks - 1] = 0.4;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        if (numpeaks < 4) {
          ixstart = Pitch_size[1];
          n = 4 - numpeaks;
          Pitch_size[1] = (Pitch_size[1] - numpeaks) + 4;
          for (i9 = 0; i9 < n; i9++) {
            Pitch_data[ixstart + i9] = 0.0;
          }

          ixstart = Merit_size[1];
          n = 4 - numpeaks;
          Merit_size[1] = (Merit_size[1] - numpeaks) + 4;
          for (i9 = 0; i9 < n; i9++) {
            Merit_data[ixstart + i9] = 0.0;
          }

          ix = -numpeaks;
          for (i9 = 0; i9 <= ix + 3; i9++) {
            tmp_data[i9] = (signed char)(numpeaks + i9);
          }

          mtmp = Pitch_data[0];
          ix = 4 - numpeaks;
          for (i9 = 0; i9 < ix; i9++) {
            Pitch_data[tmp_data[i9]] = mtmp;
          }

          ix = -numpeaks;
          for (i9 = 0; i9 <= ix + 3; i9++) {
            tmp_data[i9] = (signed char)(numpeaks + i9);
          }

          mtmp = Merit_data[0];
          ix = 4 - numpeaks;
          for (i9 = 0; i9 < ix; i9++) {
            Merit_data[tmp_data[i9]] = mtmp;
          }
        }
      } else {
        Pitch_size[0] = 1;
        Pitch_size[1] = 4;
        Merit_size[0] = 1;
        Merit_size[1] = 4;
        for (i9 = 0; i9 < 4; i9++) {
          Pitch_data[i9] = 0.0;
          Merit_data[i9] = 1.0;
        }
      }
    }
  }

  /* ============================================================================== */
}

/*
 * File trailer for peaks.c
 *
 * [EOF]
 */
