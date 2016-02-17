/*
 * File: dynamic5.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "dynamic5.h"
#include "yaapt_emxutil.h"
#include "path1.h"

/* Function Definitions */

/*
 * Dynamic programming on speech processing
 *
 *  [FinPitch] =dynamic5(Pitch_array, Merit_array, k1);
 *  This routine is used to compute Local and Transition cost matrices
 *  to enable lowest cost tracking of pitch candidates;
 *  It uses NFLER from the spectrogram and the highly robust
 *  spectral F0 track, plus the merits, for
 *  computation of the cost matrices.
 * Arguments    : const emxArray_real_T *Pitch_array
 *                const emxArray_real_T *Merit_array
 *                double k1
 *                emxArray_real_T *FinPitch
 * Return Type  : void
 */
void dynamic5(const emxArray_real_T *Pitch_array, const emxArray_real_T
              *Merit_array, double k1, emxArray_real_T *FinPitch)
{
  emxArray_real_T *Trans;
  int numframes;
  int numcands;
  int b_Trans;
  int loop_ub;
  int i;
  int j;
  int k;
  int c_Trans;
  emxArray_real_T *r28;
  int Path_size[2];
  double Path_data[4999];
  int n;
  emxInit_real_T2(&Trans, 3);

  /*    Creation date:   Spring 2001 */
  /*    Revision dates:   January 3, 2002, March 7, 2005 */
  /*    Programmer: Dr. Zahorian,Kavita Kasi, Lingyun Gu; */
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
  /*  some initializations. */
  numframes = Pitch_array->size[1] - 1;
  numcands = Pitch_array->size[0] - 1;

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* forming the local cost matrix */
  /* initialization for the formation of the transition cost matrix */
  b_Trans = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = Pitch_array->size[0];
  Trans->size[1] = Pitch_array->size[0];
  Trans->size[2] = Pitch_array->size[1];
  emxEnsureCapacity((emxArray__common *)Trans, b_Trans, (int)sizeof(double));
  loop_ub = Pitch_array->size[0] * Pitch_array->size[0] * Pitch_array->size[1];
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    Trans->data[b_Trans] = 0.0;
  }

  /* the transition cost matrix is proportional to frequency differences */
  /* between successive candidates. */
  for (i = 1; i - 1 < numframes; i++) {
    for (j = 0; j <= numcands; j++) {
      for (k = 0; k <= numcands; k++) {
        Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1] *
          i] = fabs(Pitch_array->data[j + Pitch_array->size[0] * i] -
                    Pitch_array->data[k + Pitch_array->size[0] * (i - 1)]) /
          60.0;
        Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1] *
          i] = 0.05 * Trans->data[(k + Trans->size[0] * j) + Trans->size[0] *
          Trans->size[1] * i] + Trans->data[(k + Trans->size[0] * j) +
          Trans->size[0] * Trans->size[1] * i] * Trans->data[(k + Trans->size[0]
          * j) + Trans->size[0] * Trans->size[1] * i];
      }
    }
  }

  /*  Overal balance between Local and Transition costs */
  b_Trans = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity((emxArray__common *)Trans, b_Trans, (int)sizeof(double));
  b_Trans = Trans->size[0];
  loop_ub = Trans->size[1];
  c_Trans = Trans->size[2];
  loop_ub = b_Trans * loop_ub * c_Trans;
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    Trans->data[b_Trans] *= k1;
  }

  emxInit_real_T(&r28, 2);

  /*  search the best path */
  b_Trans = r28->size[0] * r28->size[1];
  r28->size[0] = Merit_array->size[0];
  r28->size[1] = Merit_array->size[1];
  emxEnsureCapacity((emxArray__common *)r28, b_Trans, (int)sizeof(double));
  loop_ub = Merit_array->size[0] * Merit_array->size[1];
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    r28->data[b_Trans] = 1.0 - Merit_array->data[b_Trans];
  }

  path1(r28, Trans, Path_data, Path_size);

  /*  Extract the final vocied F0 track which has the lowest cost */
  /*  At this point, VSpec_F0 is the spectral pitch track for voiced frames */
  b_Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch_array->size[1];
  emxEnsureCapacity((emxArray__common *)FinPitch, b_Trans, (int)sizeof(double));
  loop_ub = Pitch_array->size[1];
  emxFree_real_T(&r28);
  emxFree_real_T(&Trans);
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    FinPitch->data[b_Trans] = 0.0;
  }

  for (n = 0; n <= numframes; n++) {
    FinPitch->data[n] = Pitch_array->data[((int)Path_data[n] + Pitch_array->
      size[0] * n) - 1];
  }
}

/*
 * File trailer for dynamic5.c
 *
 * [EOF]
 */
