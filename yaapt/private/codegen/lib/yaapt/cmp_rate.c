/*
 * File: cmp_rate.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 11-Dec-2015 06:07:48
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cmp_rate.h"
#include "yaapt_emxutil.h"
#include "sort1.h"

/* Function Definitions */

/*
 * CMP_RATE compute rate and merit from the autocorrelation sequence
 *
 *  [Pitch, Merit] = cmp_rate(Phi,Fs,maxcands,lag_min,lag_max,Prm);
 *   This routine computes Pitch estimates and the corresponding Merit values
 *   associated with the peaks found in each frame based on the correlation sequence.
 *
 *   INPUTS:
 *    Phi     : The input signal(either auto correlated/normalized cross correlated).
 *    Fs      : The sampling frequency.
 *    lag_min : The lowest lag(== 1/F0_max) involved in the F0 estimation.
 *    F0_max  : The highest lag(== 1/F0_min)  involved in the F0 estimation.
 *              greater than the peak at F0 during the first pass of search.
 *    maxcands: The maximum number of top candidates to be considered.
 *
 *   OUTPUTS:
 *     Pitch  : The Rate/Pitch values for the peaks found for each frame.
 *     Merit  : The Merit values of the peaks found in each frame.
 * Arguments    : const emxArray_real_T *Phi
 *                double Fs
 *                double lag_min
 *                double lag_max
 *                double Pitch_data[]
 *                int Pitch_size[2]
 *                double Merit_data[]
 *                int Merit_size[2]
 * Return Type  : void
 */
void cmp_rate(const emxArray_real_T *Phi, double Fs, double lag_min, double
              lag_max, double Pitch_data[], int Pitch_size[2], double
              Merit_data[], int Merit_size[2])
{
  int numpeaks;
  double Pitch[20];
  double Merit[20];
  int i20;
  int n;
  boolean_T exitg2;
  double b_n;
  int loop_ub;
  int b_loop_ub;
  int ixstart;
  int c_n;
  double mtmp;
  int itmp;
  int ix;
  boolean_T exitg3;
  boolean_T guard1 = false;
  int iidx[20];
  double b_Pitch[20];
  emxArray_real_T *r8;
  emxArray_real_T *r9;
  boolean_T exitg1;

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

  /*  Pitch     = zeros(1, maxcands); */
  /*  Merit     = zeros(1, maxcands); */
  for (i20 = 0; i20 < 20; i20++) {
    Pitch[i20] = 0.0;
    Merit[i20] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  i20 = (int)(lag_max + (1.0 - (lag_min - 3.0)));
  n = 0;
  exitg2 = false;
  while ((!exitg2) && (n <= i20 - 1)) {
    b_n = (lag_min - 3.0) + (double)n;
    if (b_n > (b_n + 5.0) - 1.0) {
      loop_ub = 1;
      b_loop_ub = 1;
    } else {
      loop_ub = (int)b_n;
      b_loop_ub = (int)(unsigned int)b_n + 5;
    }

    ixstart = 1;
    c_n = b_loop_ub - loop_ub;
    mtmp = Phi->data[loop_ub - 1];
    itmp = 1;
    if (b_loop_ub - loop_ub > 1) {
      if (rtIsNaN(mtmp)) {
        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix <= c_n)) {
          ixstart = ix;
          if (!rtIsNaN(Phi->data[(loop_ub + ix) - 2])) {
            mtmp = Phi->data[(loop_ub + ix) - 2];
            itmp = ix;
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < b_loop_ub - loop_ub) {
        while (ixstart + 1 <= c_n) {
          if (Phi->data[(loop_ub + ixstart) - 1] > mtmp) {
            mtmp = Phi->data[(loop_ub + ixstart) - 1];
            itmp = ixstart + 1;
          }

          ixstart++;
        }
      }
    }

    guard1 = false;
    if ((itmp == 3) && (mtmp > 0.25)) {
      numpeaks++;
      Pitch[numpeaks - 1] = Fs / ((b_n + 3.0) - 1.0);
      Merit[numpeaks - 1] = mtmp;

      /*          if(numpeaks > length(Pitch)) */
      /*              tempPitch = [tempPitch Fs/(n+lag-1)]; */
      /*              tempMerit = [Merit y]; */
      /*              Pitch = tempPitch; */
      /*              Merit = tempMerit; */
      /*          else */
      /*              Pitch(numpeaks) = Fs/(n+lag-1); */
      /*              Merit(numpeaks) = y; */
      /*          end */
      if (mtmp > 0.9) {
        exitg2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      n++;
    }
  }

  /*  consider the case when the number of peaks are more than the maxcands. */
  /*  Then take only the best maxcands peaks based on the Merit values . */
  c_sort(Merit, iidx);
  for (i20 = 0; i20 < 20; i20++) {
    b_Pitch[i20] = Pitch[iidx[i20] - 1];
  }

  memcpy(&Pitch[0], &b_Pitch[0], 20U * sizeof(double));
  if (numpeaks <= 3) {
  } else {
    numpeaks = 3;
  }

  if (1 > numpeaks) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = numpeaks;
  }

  Merit_size[0] = 1;
  Merit_size[1] = b_loop_ub;
  for (i20 = 0; i20 < b_loop_ub; i20++) {
    Merit_data[i20] = Merit[i20];
  }

  if (1 > numpeaks) {
    loop_ub = 0;
  } else {
    loop_ub = numpeaks;
  }

  Pitch_size[0] = 1;
  Pitch_size[1] = loop_ub;
  for (i20 = 0; i20 < loop_ub; i20++) {
    Pitch_data[i20] = Pitch[i20];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  if (numpeaks < 3) {
    if (loop_ub == 0) {
      Pitch_size[0] = 1;
      Pitch_size[1] = 3;
      Merit_size[0] = 1;
      Merit_size[1] = 3;
      for (i20 = 0; i20 < 3; i20++) {
        Pitch_data[i20] = 0.0;
        Merit_data[i20] = 0.001;
      }
    } else {
      ixstart = 3 - numpeaks;
      Pitch_size[1] = (loop_ub - numpeaks) + 3;
      for (i20 = 0; i20 < ixstart; i20++) {
        Pitch_data[loop_ub + i20] = 0.0;
      }

      emxInit_real_T(&r8, 2);
      i20 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = 3 - numpeaks;
      emxEnsureCapacity((emxArray__common *)r8, i20, (int)sizeof(double));
      loop_ub = 3 - numpeaks;
      for (i20 = 0; i20 < loop_ub; i20++) {
        r8->data[i20] = 0.001;
      }

      emxInit_real_T(&r9, 2);
      ixstart = r8->size[1];
      Merit_size[1] = b_loop_ub + ixstart;
      loop_ub = 3 - numpeaks;
      i20 = r9->size[0] * r9->size[1];
      r9->size[0] = 1;
      r9->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)r9, i20, (int)sizeof(double));
      emxFree_real_T(&r8);
      for (i20 = 0; i20 < loop_ub; i20++) {
        r9->data[r9->size[0] * i20] = 0.001;
      }

      for (i20 = 0; i20 < ixstart; i20++) {
        Merit_data[b_loop_ub + i20] = r9->data[i20];
      }

      emxFree_real_T(&r9);

      /*      Pitch(numpeaks+1:maxcands) = 0; */
      /*      Merit(numpeaks+1:maxcands) = 0.001; */
    }
  }

  /*  Normlize merits */
  ixstart = 1;
  n = Merit_size[1];
  mtmp = Merit_data[0];
  if (Merit_size[1] > 1) {
    if (rtIsNaN(Merit_data[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!rtIsNaN(Merit_data[ix - 1])) {
          mtmp = Merit_data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < Merit_size[1]) {
      while (ixstart + 1 <= n) {
        if (Merit_data[ixstart] > mtmp) {
          mtmp = Merit_data[ixstart];
        }

        ixstart++;
      }
    }
  }

  if (mtmp > 1.0) {
    Merit_size[0] = 1;
    b_loop_ub = Merit_size[1];
    for (i20 = 0; i20 < b_loop_ub; i20++) {
      Merit_data[i20] /= mtmp;
    }
  }
}

/*
 * File trailer for cmp_rate.c
 *
 * [EOF]
 */
