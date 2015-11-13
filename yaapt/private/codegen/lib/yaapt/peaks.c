/*
 * File: peaks.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "peaks.h"
#include "eml_sort.h"
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
  double max_lag;
  double width;
  double center;
  double min_lag;
  double Pitch[100];
  double Merit[100];
  int i8;
  int i9;
  int ixstart;
  double mtmp;
  int ix;
  boolean_T exitg2;
  int loop_ub;
  emxArray_real_T *b_Data;
  int unnamed_idx_1;
  double avg_data;
  int numpeaks;
  double n;
  int itmp;
  boolean_T exitg1;
  double b_Merit[100];
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
  max_lag = 50.0 / delta;
  if (max_lag < 0.0) {
    width = ceil(max_lag);
  } else {
    width = floor(max_lag);
  }

  /*  Window width in sample */
  if (width - floor(width / 2.0) * 2.0 == 0.0) {
    width++;
  }

  /*  The center of the window is defined as the peak location. */
  center = ceil(width / 2.0);

  /*  Lowest frequency at which F0 is allowed */
  max_lag = 60.0 / delta - width / 4.0;
  if (max_lag < 0.0) {
    min_lag = ceil(max_lag);
  } else {
    min_lag = floor(max_lag);
  }

  /*  Highest frequency at which F0 is allowed */
  max_lag = 400.0 / delta + width / 4.0;
  if (max_lag < 0.0) {
    max_lag = ceil(max_lag);
  } else {
    max_lag = floor(max_lag);
  }

  if (min_lag < 1.0) {
    min_lag = 1.0;
  }

  if (max_lag > (double)Data->size[1] - width) {
    max_lag = (double)Data->size[1] - width;
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  for (i8 = 0; i8 < 100; i8++) {
    Pitch[i8] = 0.0;

    /*  Peak(Pitch) candidates */
    Merit[i8] = 0.0;
  }

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  if (min_lag > max_lag) {
    i8 = 0;
    i9 = 0;
  } else {
    i8 = (int)min_lag - 1;
    i9 = (int)max_lag;
  }

  ixstart = 1;
  mtmp = Data->data[i8];
  if (i9 - i8 > 1) {
    if (rtIsNaN(mtmp)) {
      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= i9 - i8)) {
        ixstart = ix;
        if (!rtIsNaN(Data->data[(i8 + ix) - 1])) {
          mtmp = Data->data[(i8 + ix) - 1];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < i9 - i8) {
      for (ix = ixstart - 1; ix + 2 <= i9 - i8; ix++) {
        if (Data->data[(i8 + ix) + 1] > mtmp) {
          mtmp = Data->data[(i8 + ix) + 1];
        }
      }
    }
  }

  if (mtmp > 1.0E-14) {
    i8 = Data->size[0] * Data->size[1];
    Data->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)Data, i8, (int)sizeof(double));
    ixstart = Data->size[0];
    ix = Data->size[1];
    loop_ub = ixstart * ix;
    for (i8 = 0; i8 < loop_ub; i8++) {
      Data->data[i8] /= mtmp;
    }
  }

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  if (min_lag > max_lag) {
    i8 = 0;
    i9 = 0;
  } else {
    i8 = (int)min_lag - 1;
    i9 = (int)max_lag;
  }

  emxInit_real_T(&b_Data, 2);
  unnamed_idx_1 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = i9 - i8;
  emxEnsureCapacity((emxArray__common *)b_Data, unnamed_idx_1, (int)sizeof
                    (double));
  loop_ub = i9 - i8;
  for (i9 = 0; i9 < loop_ub; i9++) {
    b_Data->data[b_Data->size[0] * i9] = Data->data[i8 + i9];
  }

  avg_data = mean(b_Data);
  emxFree_real_T(&b_Data);
  if (avg_data > 0.2) {
    /*     numpeaks = 0; */
    Pitch_size[0] = 1;
    Pitch_size[1] = 4;
    Merit_size[0] = 1;
    Merit_size[1] = 4;
    for (i8 = 0; i8 < 4; i8++) {
      Pitch_data[i8] = 0.0;
      Merit_data[i8] = 1.0;
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
    i8 = (int)(max_lag + (1.0 - min_lag));
    for (loop_ub = 0; loop_ub < i8; loop_ub++) {
      n = min_lag + (double)loop_ub;
      max_lag = (n + width) - 1.0;
      if (n > max_lag) {
        i9 = 0;
        unnamed_idx_1 = 0;
      } else {
        i9 = (int)n - 1;
        unnamed_idx_1 = (int)max_lag;
      }

      ixstart = 1;
      mtmp = Data->data[i9];
      itmp = 1;
      if (unnamed_idx_1 - i9 > 1) {
        if (rtIsNaN(mtmp)) {
          ix = 2;
          exitg1 = false;
          while ((!exitg1) && (ix <= unnamed_idx_1 - i9)) {
            ixstart = ix;
            if (!rtIsNaN(Data->data[(i9 + ix) - 1])) {
              mtmp = Data->data[(i9 + ix) - 1];
              itmp = ix;
              exitg1 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart < unnamed_idx_1 - i9) {
          for (ix = ixstart + 1; ix <= unnamed_idx_1 - i9; ix++) {
            if (Data->data[(i9 + ix) - 1] > mtmp) {
              mtmp = Data->data[(i9 + ix) - 1];
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
        Pitch[numpeaks - 1] = ((n + center) - 1.0) * delta;
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
      for (i8 = 0; i8 < 4; i8++) {
        Pitch_data[i8] = 0.0;
        Merit_data[i8] = 1.0;
      }
    } else {
      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      memcpy(&b_Merit[0], &Merit[0], 100U * sizeof(double));
      eml_sort(b_Merit, Merit, iidx);
      for (i8 = 0; i8 < 100; i8++) {
        b_Pitch[i8] = Pitch[iidx[i8] - 1];
      }

      memcpy(&Pitch[0], &b_Pitch[0], 100U * sizeof(double));

      /*  keep the number of peaks not greater than max number */
      if (numpeaks <= 4) {
      } else {
        numpeaks = 4;
      }

      if (1 > numpeaks) {
        loop_ub = 0;
      } else {
        loop_ub = numpeaks;
      }

      Pitch_size[0] = 1;
      Pitch_size[1] = loop_ub;
      for (i8 = 0; i8 < loop_ub; i8++) {
        Pitch_data[i8] = Pitch[i8];
      }

      if (1 > numpeaks) {
        ix = 0;
      } else {
        ix = numpeaks;
      }

      Merit_size[0] = 1;
      Merit_size[1] = ix;
      for (i8 = 0; i8 < ix; i8++) {
        Merit_data[i8] = Merit[i8];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      if (numpeaks > 0) {
        /*  if best peak has F < this, insert peak at 2F */
        if (Pitch_data[0] > 150.0) {
          if (numpeaks + 1 <= 4) {
            numpeaks++;
          } else {
            numpeaks = 4;
          }

          if (numpeaks > loop_ub) {
            unnamed_idx_1 = numpeaks - loop_ub;
            ixstart = loop_ub + unnamed_idx_1;
            for (i8 = 0; i8 < loop_ub; i8++) {
              b_Pitch_data[i8] = Pitch_data[i8];
            }

            for (i8 = 0; i8 < unnamed_idx_1; i8++) {
              b_Pitch_data[i8 + loop_ub] = 0.0;
            }

            Pitch_size[0] = 1;
            Pitch_size[1] = ixstart;
            for (i8 = 0; i8 < ixstart; i8++) {
              Pitch_data[i8] = b_Pitch_data[i8];
            }

            unnamed_idx_1 = numpeaks - ix;
            ixstart = ix + unnamed_idx_1;
            for (i8 = 0; i8 < ix; i8++) {
              b_Pitch_data[i8] = Merit_data[i8];
            }

            for (i8 = 0; i8 < unnamed_idx_1; i8++) {
              b_Pitch_data[i8 + ix] = 0.0;
            }

            Merit_size[0] = 1;
            Merit_size[1] = ixstart;
            for (i8 = 0; i8 < ixstart; i8++) {
              Merit_data[i8] = b_Pitch_data[i8];
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
            unnamed_idx_1 = numpeaks - Pitch_size[1];
            ixstart = Pitch_size[1] + unnamed_idx_1;
            loop_ub = Pitch_size[1];
            for (i8 = 0; i8 < loop_ub; i8++) {
              b_Pitch_data[i8] = Pitch_data[i8];
            }

            for (i8 = 0; i8 < unnamed_idx_1; i8++) {
              b_Pitch_data[i8 + Pitch_size[1]] = 0.0;
            }

            Pitch_size[0] = 1;
            Pitch_size[1] = ixstart;
            for (i8 = 0; i8 < ixstart; i8++) {
              Pitch_data[i8] = b_Pitch_data[i8];
            }

            unnamed_idx_1 = numpeaks - Merit_size[1];
            ixstart = Merit_size[1] + unnamed_idx_1;
            loop_ub = Merit_size[1];
            for (i8 = 0; i8 < loop_ub; i8++) {
              b_Pitch_data[i8] = Merit_data[i8];
            }

            for (i8 = 0; i8 < unnamed_idx_1; i8++) {
              b_Pitch_data[i8 + Merit_size[1]] = 0.0;
            }

            Merit_size[0] = 1;
            Merit_size[1] = ixstart;
            for (i8 = 0; i8 < ixstart; i8++) {
              Merit_data[i8] = b_Pitch_data[i8];
            }
          }

          Pitch_data[numpeaks - 1] = 2.0 * Pitch_data[0];
          Merit_data[numpeaks - 1] = 0.4;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        if (numpeaks < 4) {
          ixstart = Pitch_size[1];
          ix = 4 - numpeaks;
          Pitch_size[1] = (Pitch_size[1] - numpeaks) + 4;
          for (i8 = 0; i8 < ix; i8++) {
            Pitch_data[ixstart + i8] = 0.0;
          }

          ixstart = Merit_size[1];
          ix = 4 - numpeaks;
          Merit_size[1] = (Merit_size[1] - numpeaks) + 4;
          for (i8 = 0; i8 < ix; i8++) {
            Merit_data[ixstart + i8] = 0.0;
          }

          loop_ub = -numpeaks;
          for (i8 = 0; i8 <= loop_ub + 3; i8++) {
            tmp_data[i8] = (signed char)(numpeaks + i8);
          }

          max_lag = Pitch_data[0];
          loop_ub = 4 - numpeaks;
          for (i8 = 0; i8 < loop_ub; i8++) {
            Pitch_data[tmp_data[i8]] = max_lag;
          }

          loop_ub = -numpeaks;
          for (i8 = 0; i8 <= loop_ub + 3; i8++) {
            tmp_data[i8] = (signed char)(numpeaks + i8);
          }

          max_lag = Merit_data[0];
          loop_ub = 4 - numpeaks;
          for (i8 = 0; i8 < loop_ub; i8++) {
            Merit_data[tmp_data[i8]] = max_lag;
          }
        }
      } else {
        Pitch_size[0] = 1;
        Pitch_size[1] = 4;
        Merit_size[0] = 1;
        Merit_size[1] = 4;
        for (i8 = 0; i8 < 4; i8++) {
          Pitch_data[i8] = 0.0;
          Merit_data[i8] = 1.0;
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
