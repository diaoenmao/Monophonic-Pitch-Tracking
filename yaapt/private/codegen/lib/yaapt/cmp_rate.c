/*
 * File: cmp_rate.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cmp_rate.h"
#include "yaapt_emxutil.h"
#include "sort1.h"
#include "yaapt_rtwutil.h"

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
 *                double maxcands
 *                double lag_min
 *                double lag_max
 *                double Prm_nccf_thresh1
 *                double Prm_nccf_thresh2
 *                double Prm_nccf_pwidth
 *                emxArray_real_T *Pitch
 *                emxArray_real_T *Merit
 * Return Type  : void
 */
void cmp_rate(const emxArray_real_T *Phi, double Fs, double maxcands, double
              lag_min, double lag_max, double Prm_nccf_thresh1, double
              Prm_nccf_thresh2, double Prm_nccf_pwidth, emxArray_real_T *Pitch,
              emxArray_real_T *Merit)
{
  double center;
  double numpeaks;
  double b_Pitch[20];
  double b_Merit[20];
  double d3;
  int i30;
  int n;
  boolean_T exitg2;
  double b_n;
  double mtmp;
  int iidx[20];
  double c_Pitch[20];
  int loop_ub;
  int unnamed_idx_1;
  int ixstart;
  int c_n;
  int itmp;
  boolean_T guard1 = false;
  int ix;
  boolean_T exitg3;
  emxArray_real_T *r29;
  boolean_T exitg1;
  emxArray_real_T *b;
  emxArray_real_T *r30;
  emxArray_real_T *r31;

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
  center = rt_roundd_snf(Prm_nccf_pwidth / 2.0);

  /*  The threshold value used for the first pass of */
  /*  peak picking for each frame.any peaks found greater than this */
  /*  are chosen in the first pass. */
  /*   The threshold value used to limit peak searching. */
  /*   If a peak is found at least this great, no further  searching is */
  /*   done increased from prev. value of 0.85. */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  numpeaks = 0.0;

  /*  Pitch     = zeros(1, maxcands); */
  /*  Merit     = zeros(1, maxcands); */
  memset(&b_Pitch[0], 0, 20U * sizeof(double));
  memset(&b_Merit[0], 0, 20U * sizeof(double));

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  d3 = lag_min - center;
  i30 = (int)(lag_max + (1.0 - d3));
  n = 0;
  exitg2 = false;
  while ((!exitg2) && (n <= i30 - 1)) {
    b_n = d3 + (double)n;
    mtmp = (b_n + Prm_nccf_pwidth) - 1.0;
    if (b_n > mtmp) {
      loop_ub = 1;
      unnamed_idx_1 = 1;
    } else {
      loop_ub = (int)b_n;
      unnamed_idx_1 = (int)mtmp + 1;
    }

    ixstart = 1;
    c_n = unnamed_idx_1 - loop_ub;
    mtmp = Phi->data[loop_ub - 1];
    itmp = 1;
    if (unnamed_idx_1 - loop_ub > 1) {
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

      if (ixstart < unnamed_idx_1 - loop_ub) {
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
    if ((itmp == center) && (mtmp > Prm_nccf_thresh1)) {
      numpeaks++;
      b_Pitch[(int)numpeaks - 1] = Fs / ((b_n + (double)itmp) - 1.0);
      b_Merit[(int)numpeaks - 1] = mtmp;

      /*          if(numpeaks > length(Pitch)) */
      /*              tempPitch = [tempPitch Fs/(n+lag-1)]; */
      /*              tempMerit = [Merit y]; */
      /*              Pitch = tempPitch; */
      /*              Merit = tempMerit; */
      /*          else */
      /*              Pitch(numpeaks) = Fs/(n+lag-1); */
      /*              Merit(numpeaks) = y; */
      /*          end */
      if (mtmp > Prm_nccf_thresh2) {
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
  c_sort(b_Merit, iidx);
  for (i30 = 0; i30 < 20; i30++) {
    c_Pitch[i30] = b_Pitch[iidx[i30] - 1];
  }

  memcpy(&b_Pitch[0], &c_Pitch[0], 20U * sizeof(double));
  if ((numpeaks <= maxcands) || rtIsNaN(maxcands)) {
  } else {
    numpeaks = maxcands;
  }

  if (1.0 > numpeaks) {
    loop_ub = 0;
  } else {
    loop_ub = (int)numpeaks;
  }

  i30 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 1;
  Merit->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)Merit, i30, (int)sizeof(double));
  for (i30 = 0; i30 < loop_ub; i30++) {
    Merit->data[Merit->size[0] * i30] = b_Merit[i30];
  }

  if (1.0 > numpeaks) {
    loop_ub = 0;
  } else {
    loop_ub = (int)numpeaks;
  }

  i30 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 1;
  Pitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)Pitch, i30, (int)sizeof(double));
  for (i30 = 0; i30 < loop_ub; i30++) {
    Pitch->data[Pitch->size[0] * i30] = b_Pitch[i30];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  if (numpeaks < maxcands) {
    if (loop_ub == 0) {
      i30 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = (int)maxcands;
      emxEnsureCapacity((emxArray__common *)Pitch, i30, (int)sizeof(double));
      loop_ub = (int)maxcands;
      for (i30 = 0; i30 < loop_ub; i30++) {
        Pitch->data[i30] = 0.0;
      }

      i30 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = (int)maxcands;
      emxEnsureCapacity((emxArray__common *)Merit, i30, (int)sizeof(double));
      loop_ub = (int)maxcands;
      for (i30 = 0; i30 < loop_ub; i30++) {
        Merit->data[i30] = 0.001;
      }
    } else {
      emxInit_real_T(&r29, 2);
      ixstart = Pitch->size[1];
      c_n = (int)(maxcands - numpeaks);
      i30 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[1] = ixstart + (int)(maxcands - numpeaks);
      emxEnsureCapacity((emxArray__common *)Pitch, i30, (int)sizeof(double));
      unnamed_idx_1 = (int)(maxcands - numpeaks);
      i30 = r29->size[0] * r29->size[1];
      r29->size[0] = 1;
      r29->size[1] = unnamed_idx_1;
      emxEnsureCapacity((emxArray__common *)r29, i30, (int)sizeof(double));
      for (i30 = 0; i30 < unnamed_idx_1; i30++) {
        r29->data[r29->size[0] * i30] = 0.0;
      }

      for (i30 = 0; i30 < c_n; i30++) {
        Pitch->data[ixstart + i30] = r29->data[i30];
      }

      emxFree_real_T(&r29);
      emxInit_real_T(&b, 2);
      i30 = b->size[0] * b->size[1];
      b->size[0] = 1;
      b->size[1] = (int)(maxcands - numpeaks);
      emxEnsureCapacity((emxArray__common *)b, i30, (int)sizeof(double));
      loop_ub = (int)(maxcands - numpeaks);
      for (i30 = 0; i30 < loop_ub; i30++) {
        b->data[i30] = 1.0;
      }

      emxInit_real_T(&r30, 2);
      i30 = r30->size[0] * r30->size[1];
      r30->size[0] = 1;
      r30->size[1] = b->size[1];
      emxEnsureCapacity((emxArray__common *)r30, i30, (int)sizeof(double));
      loop_ub = b->size[0] * b->size[1];
      for (i30 = 0; i30 < loop_ub; i30++) {
        r30->data[i30] = 0.001 * b->data[i30];
      }

      emxInit_real_T(&r31, 2);
      ixstart = Merit->size[1];
      c_n = r30->size[1];
      i30 = Merit->size[0] * Merit->size[1];
      Merit->size[1] = ixstart + c_n;
      emxEnsureCapacity((emxArray__common *)Merit, i30, (int)sizeof(double));
      i30 = r31->size[0] * r31->size[1];
      r31->size[0] = 1;
      r31->size[1] = b->size[1];
      emxEnsureCapacity((emxArray__common *)r31, i30, (int)sizeof(double));
      loop_ub = b->size[1];
      emxFree_real_T(&r30);
      for (i30 = 0; i30 < loop_ub; i30++) {
        r31->data[r31->size[0] * i30] = 0.001 * b->data[b->size[0] * i30];
      }

      emxFree_real_T(&b);
      for (i30 = 0; i30 < c_n; i30++) {
        Merit->data[ixstart + i30] = r31->data[i30];
      }

      emxFree_real_T(&r31);

      /*      Pitch(numpeaks+1:maxcands) = 0; */
      /*      Merit(numpeaks+1:maxcands) = 0.001; */
    }
  }

  /*  Normlize merits */
  ixstart = 1;
  n = Merit->size[1];
  mtmp = Merit->data[0];
  if (Merit->size[1] > 1) {
    if (rtIsNaN(Merit->data[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!rtIsNaN(Merit->data[ix - 1])) {
          mtmp = Merit->data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < Merit->size[1]) {
      while (ixstart + 1 <= n) {
        if (Merit->data[ixstart] > mtmp) {
          mtmp = Merit->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  if (mtmp > 1.0) {
    i30 = Merit->size[0] * Merit->size[1];
    Merit->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)Merit, i30, (int)sizeof(double));
    loop_ub = Merit->size[0];
    unnamed_idx_1 = Merit->size[1];
    loop_ub *= unnamed_idx_1;
    for (i30 = 0; i30 < loop_ub; i30++) {
      Merit->data[i30] /= mtmp;
    }
  }
}

/*
 * File trailer for cmp_rate.c
 *
 * [EOF]
 */
