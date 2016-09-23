/*
 * File: refine.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "refine.h"
#include "yaapt_emxutil.h"
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
  int i28;
  int ibmat;
  int n;
  emxArray_real_T *r31;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *BestPitch;
  int outsize_idx_1;
  int i;
  double y;
  int j;
  double d3;
  emxArray_boolean_T *b;
  int Pitch_idx_0;
  boolean_T p;
  int itilerow;
  emxArray_int32_T *r32;
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
  i28 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity((emxArray__common *)Idx, i28, (int)sizeof(double));
  ibmat = iidx->size[0] * iidx->size[1];
  for (i28 = 0; i28 < ibmat; i28++) {
    Idx->data[i28] = iidx->data[i28];
  }

  emxFree_int32_T(&iidx);
  n = 0;
  emxInit_real_T2(&r31, 1);
  while (n <= numframes) {
    ibmat = Idx->size[0];
    i28 = r31->size[0];
    r31->size[0] = ibmat;
    emxEnsureCapacity((emxArray__common *)r31, i28, (int)sizeof(double));
    for (i28 = 0; i28 < ibmat; i28++) {
      r31->data[i28] = Pitch->data[((int)Idx->data[i28 + Idx->size[0] * n] +
        Pitch->size[0] * n) - 1];
    }

    ibmat = r31->size[0];
    for (i28 = 0; i28 < ibmat; i28++) {
      Pitch->data[i28 + Pitch->size[0] * n] = r31->data[i28];
    }

    n++;
  }

  emxFree_real_T(&r31);
  emxFree_real_T(&Idx);
  emxInit_real_T(&b_Pitch, 2);

  /*  A best pitch track is generated from the best candidates */
  ibmat = Pitch->size[1];
  i28 = b_Pitch->size[0] * b_Pitch->size[1];
  b_Pitch->size[0] = 1;
  b_Pitch->size[1] = ibmat;
  emxEnsureCapacity((emxArray__common *)b_Pitch, i28, (int)sizeof(double));
  for (i28 = 0; i28 < ibmat; i28++) {
    b_Pitch->data[b_Pitch->size[0] * i28] = Pitch->data[Pitch->size[0] * i28];
  }

  emxInit_real_T(&BestPitch, 2);
  Mymedfilt1(b_Pitch, Prm_median_value, BestPitch);
  i28 = BestPitch->size[0] * BestPitch->size[1];
  BestPitch->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)BestPitch, i28, (int)sizeof(double));
  ibmat = BestPitch->size[0];
  outsize_idx_1 = BestPitch->size[1];
  ibmat *= outsize_idx_1;
  emxFree_real_T(&b_Pitch);
  for (i28 = 0; i28 < ibmat; i28++) {
    BestPitch->data[i28] *= (double)VUVEnergy->data[i28];
  }

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  for (i = 0; i <= numframes; i++) {
    if (Energy->data[i] <= Prm_nlfer_thresh2) {
      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      ibmat = Pitch->size[0];
      for (i28 = 0; i28 < ibmat; i28++) {
        Pitch->data[i28 + Pitch->size[0] * i] = 0.0;
      }

      ibmat = Merit->size[0];
      for (i28 = 0; i28 < ibmat; i28++) {
        Merit->data[i28 + Merit->size[0] * i] = Prm_merit_pivot;
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
        i28 = 0;
        outsize_idx_1 = 1;
      } else {
        i28 = 1;
        outsize_idx_1 = maxcands + 1;
      }

      ibmat = (outsize_idx_1 - i28) - 1;
      for (outsize_idx_1 = 0; outsize_idx_1 < ibmat; outsize_idx_1++) {
        Pitch->data[(i28 + outsize_idx_1) + Pitch->size[0] * i] = 0.0;
      }

      if (2 > maxcands) {
        i28 = 0;
        outsize_idx_1 = 1;
      } else {
        i28 = 1;
        outsize_idx_1 = maxcands + 1;
      }

      y = Merit->data[Merit->size[0] * i];
      ibmat = (outsize_idx_1 - i28) - 1;
      for (outsize_idx_1 = 0; outsize_idx_1 < ibmat; outsize_idx_1++) {
        Merit->data[(i28 + outsize_idx_1) + Merit->size[0] * i] = 1.0 - y;
      }
    }
  }

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  for (i = 0; i <= numframes; i++) {
    Pitch->data[(maxcands + Pitch->size[0] * i) - 2] = BestPitch->data
      [BestPitch->size[0] * i];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    if (BestPitch->data[BestPitch->size[0] * i] > 0.0) {
      /*  voiced */
      Merit->data[(maxcands + Merit->size[0] * i) - 2] = Merit->data[Merit->
        size[0] * i];
    } else {
      /*  unvoiced */
      y = Energy->data[i] / 2.0;
      if ((1.0 <= y) || rtIsNaN(y)) {
        d3 = 1.0;
      } else {
        d3 = y;
      }

      Merit->data[(maxcands + Merit->size[0] * i) - 2] = 1.0 - d3;
    }
  }

  emxFree_real_T(&BestPitch);

  /*   Copy over the SPitch array */
  ibmat = SPitch->size[1];
  for (i28 = 0; i28 < ibmat; i28++) {
    Pitch->data[(maxcands + Pitch->size[0] * i28) - 3] = SPitch->data
      [SPitch->size[0] * i28];
  }

  ibmat = Energy->size[1];
  for (i28 = 0; i28 < ibmat; i28++) {
    Merit->data[(maxcands + Merit->size[0] * i28) - 3] = Energy->data
      [Energy->size[0] * i28] / 5.0;
  }

  emxInit_boolean_T(&b, 2);
  Pitch_idx_0 = Pitch->size[0];
  outsize_idx_1 = VUVEnergy->size[1];
  i28 = b->size[0] * b->size[1];
  b->size[0] = Pitch_idx_0;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity((emxArray__common *)b, i28, (int)sizeof(boolean_T));
  if (Pitch_idx_0 == 0) {
    p = true;
  } else if (outsize_idx_1 == 0) {
    p = true;
  } else {
    p = false;
  }

  if (!p) {
    Pitch_idx_0 = Pitch->size[0];
    for (outsize_idx_1 = 0; outsize_idx_1 + 1 <= VUVEnergy->size[1];
         outsize_idx_1++) {
      ibmat = outsize_idx_1 * Pitch_idx_0;
      for (itilerow = 1; itilerow <= Pitch_idx_0; itilerow++) {
        b->data[(ibmat + itilerow) - 1] = VUVEnergy->data[outsize_idx_1];
      }
    }
  }

  i28 = b->size[0] * b->size[1];
  emxEnsureCapacity((emxArray__common *)b, i28, (int)sizeof(boolean_T));
  outsize_idx_1 = b->size[0];
  ibmat = b->size[1];
  ibmat *= outsize_idx_1;
  for (i28 = 0; i28 < ibmat; i28++) {
    b->data[i28] = !b->data[i28];
  }

  itilerow = b->size[0] * b->size[1] - 1;
  outsize_idx_1 = 0;
  for (i = 0; i <= itilerow; i++) {
    if (b->data[i]) {
      outsize_idx_1++;
    }
  }

  emxInit_int32_T1(&r32, 1);
  i28 = r32->size[0];
  r32->size[0] = outsize_idx_1;
  emxEnsureCapacity((emxArray__common *)r32, i28, (int)sizeof(int));
  ibmat = 0;
  for (i = 0; i <= itilerow; i++) {
    if (b->data[i]) {
      r32->data[ibmat] = i + 1;
      ibmat++;
    }
  }

  emxFree_boolean_T(&b);
  ibmat = r32->size[0];
  for (i28 = 0; i28 < ibmat; i28++) {
    Pitch->data[r32->data[i28] - 1] = 0.0;
  }

  emxFree_int32_T(&r32);

  /* ============================================================================== */
}

/*
 * File trailer for refine.c
 *
 * [EOF]
 */
