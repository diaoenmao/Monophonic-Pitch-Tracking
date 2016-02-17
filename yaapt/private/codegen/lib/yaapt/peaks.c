/*
 * File: peaks.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "peaks.h"
#include "yaapt_emxutil.h"
#include "sort1.h"
#include "mean.h"
#include "rdivide.h"
#include "fix.h"
#include "mod.h"

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
 *                double maxpeaks
 *                double Prm_f0_min
 *                double Prm_f0_max
 *                double Prm_shc_pwidth
 *                double Prm_shc_thresh1
 *                double Prm_shc_thresh2
 *                double Prm_f0_double
 *                double Prm_f0_half
 *                double Prm_merit_extra
 *                emxArray_real_T *Pitch
 *                emxArray_real_T *Merit
 * Return Type  : void
 */
void peaks(emxArray_real_T *Data, double delta, double maxpeaks, double
           Prm_f0_min, double Prm_f0_max, double Prm_shc_pwidth, double
           Prm_shc_thresh1, double Prm_shc_thresh2, double Prm_f0_double, double
           Prm_f0_half, double Prm_merit_extra, emxArray_real_T *Pitch,
           emxArray_real_T *Merit)
{
  double width;
  double center;
  double min_lag;
  double max_lag;
  double b_Pitch[100];
  double b_Merit[100];
  int i20;
  int i21;
  int ixstart;
  int n;
  double mtmp;
  int ix;
  boolean_T exitg2;
  emxArray_real_T *b_Data;
  int loop_ub;
  emxArray_real_T *c_Data;
  double avg_data;
  double numpeaks;
  double b_n;
  int c_n;
  int itmp;
  boolean_T exitg1;
  int iidx[100];
  double c_Pitch[100];
  emxArray_real_T *d_Pitch;
  emxArray_real_T *e_Pitch;
  emxArray_real_T *c_Merit;
  emxArray_real_T *r25;
  emxArray_real_T *r26;
  emxArray_int32_T *r27;

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
  width = Prm_shc_pwidth / delta;
  b_fix(&width);

  /*  Window width in sample */
  if (b_mod(width) == 0.0) {
    width++;
  }

  /*  The center of the window is defined as the peak location. */
  center = ceil(width / 2.0);

  /*  Lowest frequency at which F0 is allowed */
  min_lag = Prm_f0_min / delta - width / 4.0;
  b_fix(&min_lag);

  /*  Highest frequency at which F0 is allowed */
  max_lag = Prm_f0_max / delta + width / 4.0;
  b_fix(&max_lag);
  if (min_lag < 1.0) {
    min_lag = 1.0;
  }

  if (max_lag > (double)Data->size[1] - width) {
    max_lag = (double)Data->size[1] - width;
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /*  Peak(Pitch) candidates */
  for (i20 = 0; i20 < 100; i20++) {
    b_Pitch[i20] = 0.0;
    b_Merit[i20] = 0.0;
  }

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  if (min_lag > max_lag) {
    i20 = 1;
    i21 = 1;
  } else {
    i20 = (int)min_lag;
    i21 = (int)max_lag + 1;
  }

  ixstart = 1;
  n = i21 - i20;
  mtmp = Data->data[i20 - 1];
  if (i21 - i20 > 1) {
    if (rtIsNaN(mtmp)) {
      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= n)) {
        ixstart = ix;
        if (!rtIsNaN(Data->data[(i20 + ix) - 2])) {
          mtmp = Data->data[(i20 + ix) - 2];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < i21 - i20) {
      for (ix = ixstart - 1; ix + 2 <= n; ix++) {
        if (Data->data[i20 + ix] > mtmp) {
          mtmp = Data->data[i20 + ix];
        }
      }
    }
  }

  if (mtmp > 1.0E-14) {
    emxInit_real_T(&b_Data, 2);
    i20 = b_Data->size[0] * b_Data->size[1];
    b_Data->size[0] = 1;
    b_Data->size[1] = Data->size[1];
    emxEnsureCapacity((emxArray__common *)b_Data, i20, (int)sizeof(double));
    loop_ub = Data->size[0] * Data->size[1];
    for (i20 = 0; i20 < loop_ub; i20++) {
      b_Data->data[i20] = Data->data[i20];
    }

    c_rdivide(b_Data, mtmp, Data);
    emxFree_real_T(&b_Data);
  }

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  if (min_lag > max_lag) {
    i20 = 0;
    i21 = 0;
  } else {
    i20 = (int)min_lag - 1;
    i21 = (int)max_lag;
  }

  emxInit_real_T(&c_Data, 2);
  loop_ub = c_Data->size[0] * c_Data->size[1];
  c_Data->size[0] = 1;
  c_Data->size[1] = i21 - i20;
  emxEnsureCapacity((emxArray__common *)c_Data, loop_ub, (int)sizeof(double));
  loop_ub = i21 - i20;
  for (i21 = 0; i21 < loop_ub; i21++) {
    c_Data->data[c_Data->size[0] * i21] = Data->data[i20 + i21];
  }

  avg_data = mean(c_Data);
  emxFree_real_T(&c_Data);
  if (avg_data > 1.0 / Prm_shc_thresh1) {
    /*     numpeaks = 0; */
    i20 = Pitch->size[0] * Pitch->size[1];
    Pitch->size[0] = 1;
    Pitch->size[1] = (int)maxpeaks;
    emxEnsureCapacity((emxArray__common *)Pitch, i20, (int)sizeof(double));
    loop_ub = (int)maxpeaks;
    for (i20 = 0; i20 < loop_ub; i20++) {
      Pitch->data[i20] = 0.0;
    }

    i20 = Merit->size[0] * Merit->size[1];
    Merit->size[0] = 1;
    Merit->size[1] = (int)maxpeaks;
    emxEnsureCapacity((emxArray__common *)Merit, i20, (int)sizeof(double));
    loop_ub = (int)maxpeaks;
    for (i20 = 0; i20 < loop_ub; i20++) {
      Merit->data[i20] = 1.0;
    }

    /*  force an early end for unoviced frame  */
  } else {
    /*  Step 1 */
    /*  Find all peaks for search range */
    /*  a "peak" must be the higher than a specfied number of */
    /*  points on either side of point.  Peaks are further "cleaned" */
    /*  up, to retain only best peaks i.e. peaks which do not meet certain */
    /*  criteria are eliminated. */
    numpeaks = 0.0;
    i20 = (int)(max_lag + (1.0 - min_lag));
    for (n = 0; n < i20; n++) {
      b_n = min_lag + (double)n;
      mtmp = (b_n + width) - 1.0;
      if (b_n > mtmp) {
        i21 = 1;
        loop_ub = 1;
      } else {
        i21 = (int)b_n;
        loop_ub = (int)mtmp + 1;
      }

      ixstart = 1;
      c_n = loop_ub - i21;
      mtmp = Data->data[i21 - 1];
      itmp = 1;
      if (loop_ub - i21 > 1) {
        if (rtIsNaN(mtmp)) {
          ix = 2;
          exitg1 = false;
          while ((!exitg1) && (ix <= c_n)) {
            ixstart = ix;
            if (!rtIsNaN(Data->data[(i21 + ix) - 2])) {
              mtmp = Data->data[(i21 + ix) - 2];
              itmp = ix;
              exitg1 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart < loop_ub - i21) {
          for (ix = ixstart + 1; ix <= c_n; ix++) {
            if (Data->data[(i21 + ix) - 2] > mtmp) {
              mtmp = Data->data[(i21 + ix) - 2];
              itmp = ix;
            }
          }
        }
      }

      /*  find peaks which are larger than threshold    */
      if ((itmp == center) && (mtmp > Prm_shc_thresh2 * avg_data)) {
        /*  Note Pitch(1) = delta, Pitch(2) = 2*delta */
        /*  Convert FFT indices to Pitch in Hz */
        numpeaks++;
        b_Pitch[(int)numpeaks - 1] = ((b_n + center) - 1.0) * delta;
        b_Merit[(int)numpeaks - 1] = mtmp;
      }
    }

    /*  Step 2 */
    /*  Be sure there is large peak */
    mtmp = b_Merit[0];
    for (ix = 1; ix + 1 < 101; ix++) {
      if (b_Merit[ix] > mtmp) {
        mtmp = b_Merit[ix];
      }
    }

    if (mtmp / avg_data < Prm_shc_thresh1) {
      /*    numpeaks = 0; */
      i20 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = (int)maxpeaks;
      emxEnsureCapacity((emxArray__common *)Pitch, i20, (int)sizeof(double));
      loop_ub = (int)maxpeaks;
      for (i20 = 0; i20 < loop_ub; i20++) {
        Pitch->data[i20] = 0.0;
      }

      i20 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = (int)maxpeaks;
      emxEnsureCapacity((emxArray__common *)Merit, i20, (int)sizeof(double));
      loop_ub = (int)maxpeaks;
      for (i20 = 0; i20 < loop_ub; i20++) {
        Merit->data[i20] = 1.0;
      }
    } else {
      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      sort(b_Merit, iidx);
      for (i20 = 0; i20 < 100; i20++) {
        c_Pitch[i20] = b_Pitch[iidx[i20] - 1];
      }

      memcpy(&b_Pitch[0], &c_Pitch[0], 100U * sizeof(double));

      /*  keep the number of peaks not greater than max number */
      if ((numpeaks <= maxpeaks) || rtIsNaN(maxpeaks)) {
      } else {
        numpeaks = maxpeaks;
      }

      if (1.0 > numpeaks) {
        loop_ub = 0;
      } else {
        loop_ub = (int)numpeaks;
      }

      i20 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)Pitch, i20, (int)sizeof(double));
      for (i20 = 0; i20 < loop_ub; i20++) {
        Pitch->data[Pitch->size[0] * i20] = b_Pitch[i20];
      }

      if (1.0 > numpeaks) {
        ixstart = 0;
      } else {
        ixstart = (int)numpeaks;
      }

      i20 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = ixstart;
      emxEnsureCapacity((emxArray__common *)Merit, i20, (int)sizeof(double));
      for (i20 = 0; i20 < ixstart; i20++) {
        Merit->data[Merit->size[0] * i20] = b_Merit[i20];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      if (numpeaks > 0.0) {
        emxInit_real_T(&d_Pitch, 2);

        /*  if best peak has F < this, insert peak at 2F */
        i20 = d_Pitch->size[0] * d_Pitch->size[1];
        d_Pitch->size[0] = 1;
        d_Pitch->size[1] = loop_ub;
        emxEnsureCapacity((emxArray__common *)d_Pitch, i20, (int)sizeof(double));
        for (i20 = 0; i20 < loop_ub; i20++) {
          d_Pitch->data[d_Pitch->size[0] * i20] = b_Pitch[i20];
        }

        if (d_Pitch->data[0] > Prm_f0_double) {
          if ((numpeaks + 1.0 <= maxpeaks) || rtIsNaN(maxpeaks)) {
            numpeaks++;
          } else {
            numpeaks = maxpeaks;
          }

          if (numpeaks > loop_ub) {
            n = Pitch->size[1];
            ix = (int)(numpeaks - (double)loop_ub);
            i20 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[1] = n + (int)(numpeaks - (double)loop_ub);
            emxEnsureCapacity((emxArray__common *)Pitch, i20, (int)sizeof(double));
            for (i20 = 0; i20 < ix; i20++) {
              Pitch->data[n + i20] = 0.0;
            }

            n = Merit->size[1];
            ix = (int)(numpeaks - (double)ixstart);
            i20 = Merit->size[0] * Merit->size[1];
            Merit->size[1] = n + (int)(numpeaks - (double)ixstart);
            emxEnsureCapacity((emxArray__common *)Merit, i20, (int)sizeof(double));
            for (i20 = 0; i20 < ix; i20++) {
              Merit->data[n + i20] = 0.0;
            }
          }

          Pitch->data[(int)numpeaks - 1] = Pitch->data[0] / 2.0;

          /*  Set merit for inserted peaks */
          Merit->data[(int)numpeaks - 1] = Prm_merit_extra;
        }

        emxFree_real_T(&d_Pitch);

        /*  If best peak has F > this, insert peak at half F */
        if (Pitch->data[0] < Prm_f0_half) {
          if ((numpeaks + 1.0 <= maxpeaks) || rtIsNaN(maxpeaks)) {
            numpeaks++;
          } else {
            numpeaks = maxpeaks;
          }

          if (numpeaks > Pitch->size[1]) {
            emxInit_real_T(&e_Pitch, 2);
            ixstart = Pitch->size[1];
            ixstart = (int)(numpeaks - (double)ixstart);
            i20 = e_Pitch->size[0] * e_Pitch->size[1];
            e_Pitch->size[0] = 1;
            e_Pitch->size[1] = Pitch->size[1] + ixstart;
            emxEnsureCapacity((emxArray__common *)e_Pitch, i20, (int)sizeof
                              (double));
            loop_ub = Pitch->size[1];
            for (i20 = 0; i20 < loop_ub; i20++) {
              e_Pitch->data[e_Pitch->size[0] * i20] = Pitch->data[Pitch->size[0]
                * i20];
            }

            for (i20 = 0; i20 < ixstart; i20++) {
              e_Pitch->data[e_Pitch->size[0] * (i20 + Pitch->size[1])] = 0.0;
            }

            i20 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[0] = 1;
            Pitch->size[1] = e_Pitch->size[1];
            emxEnsureCapacity((emxArray__common *)Pitch, i20, (int)sizeof(double));
            loop_ub = e_Pitch->size[1];
            for (i20 = 0; i20 < loop_ub; i20++) {
              Pitch->data[Pitch->size[0] * i20] = e_Pitch->data[e_Pitch->size[0]
                * i20];
            }

            emxFree_real_T(&e_Pitch);
            emxInit_real_T(&c_Merit, 2);
            ixstart = Merit->size[1];
            ixstart = (int)(numpeaks - (double)ixstart);
            i20 = c_Merit->size[0] * c_Merit->size[1];
            c_Merit->size[0] = 1;
            c_Merit->size[1] = Merit->size[1] + ixstart;
            emxEnsureCapacity((emxArray__common *)c_Merit, i20, (int)sizeof
                              (double));
            loop_ub = Merit->size[1];
            for (i20 = 0; i20 < loop_ub; i20++) {
              c_Merit->data[c_Merit->size[0] * i20] = Merit->data[Merit->size[0]
                * i20];
            }

            for (i20 = 0; i20 < ixstart; i20++) {
              c_Merit->data[c_Merit->size[0] * (i20 + Merit->size[1])] = 0.0;
            }

            i20 = Merit->size[0] * Merit->size[1];
            Merit->size[0] = 1;
            Merit->size[1] = c_Merit->size[1];
            emxEnsureCapacity((emxArray__common *)Merit, i20, (int)sizeof(double));
            loop_ub = c_Merit->size[1];
            for (i20 = 0; i20 < loop_ub; i20++) {
              Merit->data[Merit->size[0] * i20] = c_Merit->data[c_Merit->size[0]
                * i20];
            }

            emxFree_real_T(&c_Merit);
          }

          Pitch->data[(int)numpeaks - 1] = 2.0 * Pitch->data[0];
          Merit->data[(int)numpeaks - 1] = Prm_merit_extra;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        if (numpeaks < maxpeaks) {
          emxInit_real_T(&r25, 2);
          n = Pitch->size[1];
          ix = (int)(maxpeaks - numpeaks);
          i20 = Pitch->size[0] * Pitch->size[1];
          Pitch->size[1] = n + (int)(maxpeaks - numpeaks);
          emxEnsureCapacity((emxArray__common *)Pitch, i20, (int)sizeof(double));
          ixstart = (int)(maxpeaks - numpeaks);
          i20 = r25->size[0] * r25->size[1];
          r25->size[0] = 1;
          r25->size[1] = ixstart;
          emxEnsureCapacity((emxArray__common *)r25, i20, (int)sizeof(double));
          for (i20 = 0; i20 < ixstart; i20++) {
            r25->data[r25->size[0] * i20] = 0.0;
          }

          for (i20 = 0; i20 < ix; i20++) {
            Pitch->data[n + i20] = r25->data[i20];
          }

          emxFree_real_T(&r25);
          emxInit_real_T(&r26, 2);
          n = Merit->size[1];
          ix = (int)(maxpeaks - numpeaks);
          i20 = Merit->size[0] * Merit->size[1];
          Merit->size[1] = n + (int)(maxpeaks - numpeaks);
          emxEnsureCapacity((emxArray__common *)Merit, i20, (int)sizeof(double));
          ixstart = (int)(maxpeaks - numpeaks);
          i20 = r26->size[0] * r26->size[1];
          r26->size[0] = 1;
          r26->size[1] = ixstart;
          emxEnsureCapacity((emxArray__common *)r26, i20, (int)sizeof(double));
          for (i20 = 0; i20 < ixstart; i20++) {
            r26->data[r26->size[0] * i20] = 0.0;
          }

          for (i20 = 0; i20 < ix; i20++) {
            Merit->data[n + i20] = r26->data[i20];
          }

          emxFree_real_T(&r26);
          if (numpeaks + 1.0 > maxpeaks) {
            i20 = 0;
            i21 = 0;
          } else {
            i20 = (int)(numpeaks + 1.0) - 1;
            i21 = (int)maxpeaks;
          }

          emxInit_int32_T(&r27, 2);
          loop_ub = r27->size[0] * r27->size[1];
          r27->size[0] = 1;
          r27->size[1] = i21 - i20;
          emxEnsureCapacity((emxArray__common *)r27, loop_ub, (int)sizeof(int));
          loop_ub = i21 - i20;
          for (i21 = 0; i21 < loop_ub; i21++) {
            r27->data[r27->size[0] * i21] = i20 + i21;
          }

          mtmp = Pitch->data[0];
          loop_ub = r27->size[0] * r27->size[1];
          for (i20 = 0; i20 < loop_ub; i20++) {
            Pitch->data[r27->data[i20]] = mtmp;
          }

          if (numpeaks + 1.0 > maxpeaks) {
            i20 = 0;
            i21 = 0;
          } else {
            i20 = (int)(numpeaks + 1.0) - 1;
            i21 = (int)maxpeaks;
          }

          loop_ub = r27->size[0] * r27->size[1];
          r27->size[0] = 1;
          r27->size[1] = i21 - i20;
          emxEnsureCapacity((emxArray__common *)r27, loop_ub, (int)sizeof(int));
          loop_ub = i21 - i20;
          for (i21 = 0; i21 < loop_ub; i21++) {
            r27->data[r27->size[0] * i21] = i20 + i21;
          }

          mtmp = Merit->data[0];
          loop_ub = r27->size[0] * r27->size[1];
          for (i20 = 0; i20 < loop_ub; i20++) {
            Merit->data[r27->data[i20]] = mtmp;
          }

          emxFree_int32_T(&r27);
        }
      } else {
        i20 = Pitch->size[0] * Pitch->size[1];
        Pitch->size[0] = 1;
        Pitch->size[1] = (int)maxpeaks;
        emxEnsureCapacity((emxArray__common *)Pitch, i20, (int)sizeof(double));
        loop_ub = (int)maxpeaks;
        for (i20 = 0; i20 < loop_ub; i20++) {
          Pitch->data[i20] = 0.0;
        }

        i20 = Merit->size[0] * Merit->size[1];
        Merit->size[0] = 1;
        Merit->size[1] = (int)maxpeaks;
        emxEnsureCapacity((emxArray__common *)Merit, i20, (int)sizeof(double));
        loop_ub = (int)maxpeaks;
        for (i20 = 0; i20 < loop_ub; i20++) {
          Merit->data[i20] = 1.0;
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
