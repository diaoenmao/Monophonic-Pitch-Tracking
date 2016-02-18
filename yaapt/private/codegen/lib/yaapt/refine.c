/*
 * File: refine.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "refine.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"
#include "Mymedfilt1.h"
#include "sort1.h"
#include "cat.h"

/* Function Definitions */

/*
 * REFINE Refine pitch candidates for YAAPT Pitch tracking
 *
 *  [Pitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, Energy, VUVEnergy, Prm)
 *    refins pitch cadidates obtained from NCCF using spectral pitch
 *    track and NLFER energy information.
 *
 *  INPUTS:
 *    TPitch1:  Pitch candidates array 1
 *    TMerti1:  Merits for pitch candidates array 1
 *    TPitch2:  Pitch candidates array 2
 *    TMerti2:  Merits for pitch candidates array 2
 *    SPitch:   Smoothed spectral pitch track
 *    Energy:   NLFER Energy information
 *    VUVEnergy: Voiced/Unvoiced information determined by NLFER energy
 *    Prm:      Parameters
 *
 *  OUTPUTS:
 *    Pitch:   Refined overall pitch candidates
 *    Merit:   Merit for overall pitch candidates
 * Arguments    : const emxArray_real_T *TPitch1
 *                const emxArray_real_T *TMerit1
 *                const emxArray_real_T *TPitch2
 *                const emxArray_real_T *TMerit2
 *                const emxArray_real_T *SPitch
 *                const emxArray_real_T *Energy
 *                const emxArray_boolean_T *VUVEnergy
 *                double Prm_nlfer_thresh2
 *                double Prm_merit_pivot
 *                double Prm_median_value
 *                emxArray_real_T *Pitch
 *                emxArray_real_T *Merit
 * Return Type  : void
 */
void refine(const emxArray_real_T *TPitch1, const emxArray_real_T *TMerit1,
            const emxArray_real_T *TPitch2, const emxArray_real_T *TMerit2,
            const emxArray_real_T *SPitch, const emxArray_real_T *Energy, const
            emxArray_boolean_T *VUVEnergy, double Prm_nlfer_thresh2, double
            Prm_merit_pivot, double Prm_median_value, emxArray_real_T *Pitch,
            emxArray_real_T *Merit)
{
  emxArray_real_T *Idx;
  emxArray_int32_T *iidx;
  int numframes;
  int maxcands;
  int BestPitch;
  int loop_ub;
  int n;
  emxArray_real_T *r33;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *b_BestPitch;
  int c_BestPitch;
  int i;
  int j;
  double y;
  double d4;
  emxArray_real_T *r34;
  emxInit_real_T(&Idx, 2);
  emxInit_int32_T(&iidx, 2);

  /*    Creation: July 27 2007 */
  /*    Author:   Hongbing Hu */
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
  /*  Threshold for NLFER energy */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Merge pitch candidates and their merits from two types of the signal */
  cat(TPitch1, TPitch2, Pitch);
  cat(TMerit1, TMerit2, Merit);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  numframes = Pitch->size[1] - 1;
  maxcands = Pitch->size[0];
  e_sort(Merit, iidx);
  BestPitch = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity((emxArray__common *)Idx, BestPitch, (int)sizeof(double));
  loop_ub = iidx->size[0] * iidx->size[1];
  for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
    Idx->data[BestPitch] = iidx->data[BestPitch];
  }

  emxFree_int32_T(&iidx);
  n = 0;
  emxInit_real_T2(&r33, 1);
  while (n <= numframes) {
    loop_ub = Idx->size[0];
    BestPitch = r33->size[0];
    r33->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)r33, BestPitch, (int)sizeof(double));
    for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
      r33->data[BestPitch] = Pitch->data[((int)Idx->data[BestPitch + Idx->size[0]
        * n] + Pitch->size[0] * n) - 1];
    }

    loop_ub = r33->size[0];
    for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
      Pitch->data[BestPitch + Pitch->size[0] * n] = r33->data[BestPitch];
    }

    n++;
  }

  emxFree_real_T(&r33);
  emxFree_real_T(&Idx);
  emxInit_real_T(&b_Pitch, 2);

  /*  A best pitch track is generated from the best candidates */
  loop_ub = Pitch->size[1];
  BestPitch = b_Pitch->size[0] * b_Pitch->size[1];
  b_Pitch->size[0] = 1;
  b_Pitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_Pitch, BestPitch, (int)sizeof(double));
  for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
    b_Pitch->data[b_Pitch->size[0] * BestPitch] = Pitch->data[Pitch->size[0] *
      BestPitch];
  }

  emxInit_real_T(&b_BestPitch, 2);
  Mymedfilt1(b_Pitch, Prm_median_value, b_BestPitch);
  BestPitch = b_BestPitch->size[0] * b_BestPitch->size[1];
  b_BestPitch->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)b_BestPitch, BestPitch, (int)sizeof
                    (double));
  c_BestPitch = b_BestPitch->size[0];
  BestPitch = b_BestPitch->size[1];
  loop_ub = c_BestPitch * BestPitch;
  emxFree_real_T(&b_Pitch);
  for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
    b_BestPitch->data[BestPitch] *= (double)VUVEnergy->data[BestPitch];
  }

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  for (i = 0; i <= numframes; i++) {
    if (Energy->data[i] <= Prm_nlfer_thresh2) {
      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      loop_ub = Pitch->size[0];
      for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
        Pitch->data[BestPitch + Pitch->size[0] * i] = 0.0;
      }

      loop_ub = Merit->size[0];
      for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
        Merit->data[BestPitch + Merit->size[0] * i] = Prm_merit_pivot;
      }
    } else if (Pitch->data[Pitch->size[0] * i] > 0.0) {
      /*  already have the voiced candidate, Want to have at */
      /*  least one unvoiced candidate */
      Pitch->data[(maxcands + Pitch->size[0] * i) - 1] = 0.0;
      Merit->data[(maxcands + Merit->size[0] * i) - 1] = 1.0 - Merit->data
        [Merit->size[0] * i];
      for (j = 1; j - 1 <= maxcands - 3; j++) {
        if (Pitch->data[j + Pitch->size[0] * i] == 0.0) {
          Merit->data[j + Merit->size[0] * i] = 0.0;
        }
      }
    } else {
      /*  there was no voiced candidate from nccf fill in */
      /*  option for F0 from spectrogram */
      Pitch->data[Pitch->size[0] * i] = SPitch->data[i];
      y = Energy->data[i] / 2.0;
      if ((1.0 <= y) || rtIsNaN(y)) {
        Merit->data[Merit->size[0] * i] = 1.0;
      } else {
        Merit->data[Merit->size[0] * i] = y;
      }

      /*  all other candidates will be unvoiced */
      /*  with low merit */
      if (2 > maxcands) {
        BestPitch = 0;
        c_BestPitch = 0;
      } else {
        BestPitch = 1;
        c_BestPitch = maxcands;
      }

      loop_ub = c_BestPitch - BestPitch;
      for (c_BestPitch = 0; c_BestPitch < loop_ub; c_BestPitch++) {
        Pitch->data[(BestPitch + c_BestPitch) + Pitch->size[0] * i] = 0.0;
      }

      if (2 > maxcands) {
        BestPitch = 0;
        c_BestPitch = 0;
      } else {
        BestPitch = 1;
        c_BestPitch = maxcands;
      }

      y = Merit->data[Merit->size[0] * i];
      loop_ub = c_BestPitch - BestPitch;
      for (c_BestPitch = 0; c_BestPitch < loop_ub; c_BestPitch++) {
        Merit->data[(BestPitch + c_BestPitch) + Merit->size[0] * i] = 1.0 - y;
      }
    }
  }

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  for (i = 0; i <= numframes; i++) {
    Pitch->data[(maxcands + Pitch->size[0] * i) - 2] = b_BestPitch->
      data[b_BestPitch->size[0] * i];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    if (b_BestPitch->data[b_BestPitch->size[0] * i] > 0.0) {
      /*  voiced */
      Merit->data[(maxcands + Merit->size[0] * i) - 2] = Merit->data[Merit->
        size[0] * i];
    } else {
      /*  unvoiced */
      y = Energy->data[i] / 2.0;
      if ((1.0 <= y) || rtIsNaN(y)) {
        d4 = 1.0;
      } else {
        d4 = y;
      }

      Merit->data[(maxcands + Merit->size[0] * i) - 2] = 1.0 - d4;
    }
  }

  emxFree_real_T(&b_BestPitch);

  /*   Copy over the SPitch array */
  loop_ub = SPitch->size[1];
  for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
    Pitch->data[(maxcands + Pitch->size[0] * BestPitch) - 3] = SPitch->
      data[SPitch->size[0] * BestPitch];
  }

  emxInit_real_T(&r34, 2);
  c_rdivide(Energy, 5.0, r34);
  loop_ub = r34->size[1];
  for (BestPitch = 0; BestPitch < loop_ub; BestPitch++) {
    Merit->data[(maxcands + Merit->size[0] * BestPitch) - 3] = r34->data
      [r34->size[0] * BestPitch];
  }

  emxFree_real_T(&r34);

  /* ============================================================================== */
}

/*
 * File trailer for refine.c
 *
 * [EOF]
 */
