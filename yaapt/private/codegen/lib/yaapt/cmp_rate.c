/*
 * File: cmp_rate.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Jan-2016 05:43:25
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cmp_rate.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"
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
  int i21;
  int n;
  boolean_T exitg2;
  double b_n;
  int loop_ub;
  int xs;
  int ixstart;
  int c_n;
  double mtmp;
  int itmp;
  int ix;
  boolean_T exitg3;
  boolean_T guard1 = false;
  int iidx[20];
  double b_Pitch[20];
  emxArray_real_T *r10;
  emxArray_real_T *r11;
  boolean_T exitg1;
  emxArray_real_T *r12;
  emxArray_real_T b_Merit_data;

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
  for (i21 = 0; i21 < 20; i21++) {
    Pitch[i21] = 0.0;
    Merit[i21] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  i21 = (int)(lag_max + (1.0 - (lag_min - 3.0)));
  n = 0;
  exitg2 = false;
  while ((!exitg2) && (n <= i21 - 1)) {
    b_n = (lag_min - 3.0) + (double)n;
    if (b_n > (b_n + 5.0) - 1.0) {
      loop_ub = 1;
      xs = 1;
    } else {
      loop_ub = (int)b_n;
      xs = (int)(unsigned int)b_n + 5;
    }

    ixstart = 1;
    c_n = xs - loop_ub;
    mtmp = Phi->data[loop_ub - 1];
    itmp = 1;
    if (xs - loop_ub > 1) {
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

      if (ixstart < xs - loop_ub) {
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
  for (i21 = 0; i21 < 20; i21++) {
    b_Pitch[i21] = Pitch[iidx[i21] - 1];
  }

  memcpy(&Pitch[0], &b_Pitch[0], 20U * sizeof(double));
  if (numpeaks <= 3) {
  } else {
    numpeaks = 3;
  }

  if (1 > numpeaks) {
    loop_ub = 0;
  } else {
    loop_ub = numpeaks;
  }

  Merit_size[0] = 1;
  Merit_size[1] = loop_ub;
  for (i21 = 0; i21 < loop_ub; i21++) {
    Merit_data[Merit_size[0] * i21] = Merit[i21];
  }

  if (1 > numpeaks) {
    loop_ub = 0;
  } else {
    loop_ub = numpeaks;
  }

  Pitch_size[0] = 1;
  Pitch_size[1] = loop_ub;
  for (i21 = 0; i21 < loop_ub; i21++) {
    Pitch_data[i21] = Pitch[i21];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  if (numpeaks < 3) {
    if (loop_ub == 0) {
      Pitch_size[0] = 1;
      Pitch_size[1] = 3;
      for (i21 = 0; i21 < 3; i21++) {
        Pitch_data[i21] = 0.0;
      }

      Merit_size[0] = 1;
      Merit_size[1] = 3;
      for (i21 = 0; i21 < 3; i21++) {
        Merit_data[i21] = 0.001;
      }
    } else {
      ixstart = 3 - numpeaks;
      Pitch_size[1] = (loop_ub - numpeaks) + 3;
      for (i21 = 0; i21 < ixstart; i21++) {
        Pitch_data[loop_ub + i21] = 0.0;
      }

      emxInit_real_T(&r10, 2);
      i21 = r10->size[0] * r10->size[1];
      r10->size[0] = 1;
      r10->size[1] = 3 - numpeaks;
      emxEnsureCapacity((emxArray__common *)r10, i21, (int)sizeof(double));
      loop_ub = 3 - numpeaks;
      for (i21 = 0; i21 < loop_ub; i21++) {
        r10->data[i21] = 0.001;
      }

      emxInit_real_T(&r11, 2);
      xs = Merit_size[1];
      ixstart = r10->size[1];
      Merit_size[1] = xs + ixstart;
      loop_ub = 3 - numpeaks;
      i21 = r11->size[0] * r11->size[1];
      r11->size[0] = 1;
      r11->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)r11, i21, (int)sizeof(double));
      emxFree_real_T(&r10);
      for (i21 = 0; i21 < loop_ub; i21++) {
        r11->data[r11->size[0] * i21] = 0.001;
      }

      for (i21 = 0; i21 < ixstart; i21++) {
        Merit_data[xs + i21] = r11->data[i21];
      }

      emxFree_real_T(&r11);

      /*      Pitch(numpeaks+1:maxcands) = 0; */
      /*      Merit(numpeaks+1:maxcands) = 0.001; */
    }
  }

  /*  Normlize merits */
  ixstart = 1;
  n = Merit_size[1];
  mtmp = Merit_data[0];
  if (Merit_size[1] > 1) {
    if (rtIsNaN(mtmp)) {
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
    emxInit_real_T(&r12, 2);
    b_Merit_data.data = (double *)Merit_data;
    b_Merit_data.size = (int *)Merit_size;
    b_Merit_data.allocatedSize = -1;
    b_Merit_data.numDimensions = 2;
    b_Merit_data.canFreeData = false;
    d_rdivide(&b_Merit_data, mtmp, r12);
    Merit_size[0] = 1;
    Merit_size[1] = r12->size[1];
    loop_ub = r12->size[0] * r12->size[1];
    for (i21 = 0; i21 < loop_ub; i21++) {
      Merit_data[i21] = r12->data[i21];
    }

    emxFree_real_T(&r12);
  }
}

/*
 * File trailer for cmp_rate.c
 *
 * [EOF]
 */
