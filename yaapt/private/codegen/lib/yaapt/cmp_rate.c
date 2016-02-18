/*
 * File: cmp_rate.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cmp_rate.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"
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
  int i28;
  double d3;
  int n;
  boolean_T exitg2;
  double b_n;
  double mtmp;
  int loop_ub;
  int xs;
  int ixstart;
  int c_n;
  int itmp;
  int ix;
  boolean_T exitg3;
  boolean_T guard1 = false;
  int iidx[20];
  double c_Pitch[20];
  emxArray_real_T *r30;
  emxArray_real_T *b;
  emxArray_real_T *r31;
  emxArray_real_T *r32;
  boolean_T exitg1;
  emxArray_real_T *c_Merit;

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
  for (i28 = 0; i28 < 20; i28++) {
    b_Pitch[i28] = 0.0;
    b_Merit[i28] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  d3 = lag_min - center;
  i28 = (int)(lag_max + (1.0 - d3));
  n = 0;
  exitg2 = false;
  while ((!exitg2) && (n <= i28 - 1)) {
    b_n = d3 + (double)n;
    mtmp = (b_n + Prm_nccf_pwidth) - 1.0;
    if (b_n > mtmp) {
      loop_ub = 1;
      xs = 1;
    } else {
      loop_ub = (int)b_n;
      xs = (int)mtmp + 1;
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
  for (i28 = 0; i28 < 20; i28++) {
    c_Pitch[i28] = b_Pitch[iidx[i28] - 1];
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

  i28 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 1;
  Merit->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)Merit, i28, (int)sizeof(double));
  for (i28 = 0; i28 < loop_ub; i28++) {
    Merit->data[Merit->size[0] * i28] = b_Merit[i28];
  }

  if (1.0 > numpeaks) {
    loop_ub = 0;
  } else {
    loop_ub = (int)numpeaks;
  }

  i28 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 1;
  Pitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)Pitch, i28, (int)sizeof(double));
  for (i28 = 0; i28 < loop_ub; i28++) {
    Pitch->data[Pitch->size[0] * i28] = b_Pitch[i28];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  if (numpeaks < maxcands) {
    if (loop_ub == 0) {
      i28 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = (int)maxcands;
      emxEnsureCapacity((emxArray__common *)Pitch, i28, (int)sizeof(double));
      loop_ub = (int)maxcands;
      for (i28 = 0; i28 < loop_ub; i28++) {
        Pitch->data[i28] = 0.0;
      }

      i28 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = (int)maxcands;
      emxEnsureCapacity((emxArray__common *)Merit, i28, (int)sizeof(double));
      loop_ub = (int)maxcands;
      for (i28 = 0; i28 < loop_ub; i28++) {
        Merit->data[i28] = 0.001;
      }
    } else {
      emxInit_real_T(&r30, 2);
      xs = Pitch->size[1];
      ixstart = (int)(maxcands - numpeaks);
      i28 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[1] = xs + (int)(maxcands - numpeaks);
      emxEnsureCapacity((emxArray__common *)Pitch, i28, (int)sizeof(double));
      loop_ub = (int)(maxcands - numpeaks);
      i28 = r30->size[0] * r30->size[1];
      r30->size[0] = 1;
      r30->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)r30, i28, (int)sizeof(double));
      for (i28 = 0; i28 < loop_ub; i28++) {
        r30->data[r30->size[0] * i28] = 0.0;
      }

      for (i28 = 0; i28 < ixstart; i28++) {
        Pitch->data[xs + i28] = r30->data[i28];
      }

      emxFree_real_T(&r30);
      emxInit_real_T(&b, 2);
      i28 = b->size[0] * b->size[1];
      b->size[0] = 1;
      b->size[1] = (int)(maxcands - numpeaks);
      emxEnsureCapacity((emxArray__common *)b, i28, (int)sizeof(double));
      loop_ub = (int)(maxcands - numpeaks);
      for (i28 = 0; i28 < loop_ub; i28++) {
        b->data[i28] = 1.0;
      }

      emxInit_real_T(&r31, 2);
      i28 = r31->size[0] * r31->size[1];
      r31->size[0] = 1;
      r31->size[1] = b->size[1];
      emxEnsureCapacity((emxArray__common *)r31, i28, (int)sizeof(double));
      loop_ub = b->size[0] * b->size[1];
      for (i28 = 0; i28 < loop_ub; i28++) {
        r31->data[i28] = 0.001 * b->data[i28];
      }

      emxInit_real_T(&r32, 2);
      xs = Merit->size[1];
      ixstart = r31->size[1];
      i28 = Merit->size[0] * Merit->size[1];
      Merit->size[1] = xs + ixstart;
      emxEnsureCapacity((emxArray__common *)Merit, i28, (int)sizeof(double));
      i28 = r32->size[0] * r32->size[1];
      r32->size[0] = 1;
      r32->size[1] = b->size[1];
      emxEnsureCapacity((emxArray__common *)r32, i28, (int)sizeof(double));
      loop_ub = b->size[1];
      emxFree_real_T(&r31);
      for (i28 = 0; i28 < loop_ub; i28++) {
        r32->data[r32->size[0] * i28] = 0.001 * b->data[b->size[0] * i28];
      }

      emxFree_real_T(&b);
      for (i28 = 0; i28 < ixstart; i28++) {
        Merit->data[xs + i28] = r32->data[i28];
      }

      emxFree_real_T(&r32);

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
    emxInit_real_T(&c_Merit, 2);
    i28 = c_Merit->size[0] * c_Merit->size[1];
    c_Merit->size[0] = 1;
    c_Merit->size[1] = Merit->size[1];
    emxEnsureCapacity((emxArray__common *)c_Merit, i28, (int)sizeof(double));
    loop_ub = Merit->size[0] * Merit->size[1];
    for (i28 = 0; i28 < loop_ub; i28++) {
      c_Merit->data[i28] = Merit->data[i28];
    }

    c_rdivide(c_Merit, mtmp, Merit);
    emxFree_real_T(&c_Merit);
  }
}

/*
 * File trailer for cmp_rate.c
 *
 * [EOF]
 */
