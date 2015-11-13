/*
 * File: dynamic.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:42:02
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "dynamic.h"
#include "yaapt_emxutil.h"
#include "mean.h"

/* Function Definitions */

/*
 * DYNAMIC Dynamic programming for YAAPT pitch tracking
 *
 *  [FinPitch] = dynamic(Pitch, Merit, Energy, Prm) is used
 *  to compute Local and Transition cost matrices
 *  to enable lowest cost tracking of pitch candidates;
 *  It uses NFLER from the spectrogram and the highly robust
 *  spectral F0 track, plus the merits, for
 *  computation of the cost matrices.
 *
 * INPUTS:
 *    Pitch:  Pitch array with elements arranged so that lowest
 *                       index correponds to  highest merit
 *    Merit:  Merit array with elements arranged as for pitch
 *    Energy: NLFER energy ratio from the low frequency regions of spectrogram.
 *    Prm:    Array of parameters used to control performance
 *
 * OUTPUTS:
 *    FinPitch: The final pitch track for the entire utterance pitch
 *    values are in HZ.Unvoiced frames are assigned 0.
 * Arguments    : const emxArray_real_T *Pitch
 *                const emxArray_real_T *Merit
 *                const emxArray_real_T *Energy
 *                emxArray_real_T *FinPitch
 * Return Type  : void
 */
void dynamic(const emxArray_real_T *Pitch, const emxArray_real_T *Merit, const
             emxArray_real_T *Energy, emxArray_real_T *FinPitch)
{
  emxArray_real_T *BestPitch;
  int loop_ub;
  int b_Pitch;
  int Trans;
  emxArray_boolean_T *b_BestPitch;
  emxArray_int32_T *r9;
  emxArray_real_T *c_BestPitch;
  emxArray_real_T *Local;
  double mean_pitch;
  emxArray_real_T *b_Trans;
  double y;
  double d1;
  emxArray_real_T *PRED;
  double P_data[4999];
  double p_data[4999];
  double PCOST_data[499];
  double CCOST_data[499];
  emxInit_real_T(&BestPitch, 2);

  /*  Note:   This routine is intended for more through testing of */
  /*     some thresholds used in dynamic6.   All the dp constants are */
  /*     set to fixed values that worked well in testing */
  /*     then the dp constants are used to specify the thresholds and other */
  /*      constants */
  /*    Creation date:   Spring 2001 */
  /*    Revision date:   January 3, 2002   June 16, 2007, July 27, 2007 */
  /*    Programmers: S. Zahorian,Kavita Kasi, Lingyun Gu, Hongbing Hu */
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
  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* Copy some arrays */
  loop_ub = Pitch->size[1];
  b_Pitch = Pitch->size[0];
  Trans = BestPitch->size[0] * BestPitch->size[1];
  BestPitch->size[0] = 1;
  BestPitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)BestPitch, Trans, (int)sizeof(double));
  for (Trans = 0; Trans < loop_ub; Trans++) {
    BestPitch->data[BestPitch->size[0] * Trans] = Pitch->data[(b_Pitch +
      Pitch->size[0] * Trans) - 2];
  }

  emxInit_boolean_T(&b_BestPitch, 2);
  Trans = b_BestPitch->size[0] * b_BestPitch->size[1];
  b_BestPitch->size[0] = 1;
  b_BestPitch->size[1] = BestPitch->size[1];
  emxEnsureCapacity((emxArray__common *)b_BestPitch, Trans, (int)sizeof
                    (boolean_T));
  loop_ub = BestPitch->size[0] * BestPitch->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_BestPitch->data[Trans] = (BestPitch->data[Trans] > 0.0);
  }

  emxInit_int32_T(&r9, 2);
  emxInit_real_T(&c_BestPitch, 2);
  eml_li_find(b_BestPitch, r9);
  Trans = c_BestPitch->size[0] * c_BestPitch->size[1];
  c_BestPitch->size[0] = 1;
  c_BestPitch->size[1] = r9->size[1];
  emxEnsureCapacity((emxArray__common *)c_BestPitch, Trans, (int)sizeof(double));
  loop_ub = r9->size[0] * r9->size[1];
  emxFree_boolean_T(&b_BestPitch);
  for (Trans = 0; Trans < loop_ub; Trans++) {
    c_BestPitch->data[Trans] = BestPitch->data[r9->data[Trans] - 1];
  }

  emxFree_int32_T(&r9);
  emxFree_real_T(&BestPitch);
  emxInit_real_T(&Local, 2);
  mean_pitch = mean(c_BestPitch);

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Forming the local cost matrix */
  Trans = Local->size[0] * Local->size[1];
  Local->size[0] = Merit->size[0];
  Local->size[1] = Merit->size[1];
  emxEnsureCapacity((emxArray__common *)Local, Trans, (int)sizeof(double));
  loop_ub = Merit->size[0] * Merit->size[1];
  emxFree_real_T(&c_BestPitch);
  for (Trans = 0; Trans < loop_ub; Trans++) {
    Local->data[Trans] = 1.0 - Merit->data[Trans];
  }

  c_emxInit_real_T(&b_Trans, 3);

  /*  Initialization for the formation of the transition cost matrix */
  loop_ub = Pitch->size[0];
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = Pitch->size[0];
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = Pitch->size[1];
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[2] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = Pitch->size[0] * Pitch->size[0] * Pitch->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] = 1.0;
  }

  /*  The transition cost matrix is proportional to frequency differences */
  /*  between successive candidates. */
  for (loop_ub = 1; loop_ub - 1 <= Pitch->size[1] - 2; loop_ub++) {
    for (b_Pitch = 0; b_Pitch < Pitch->size[0]; b_Pitch++) {
      for (Trans = 0; Trans < Pitch->size[0]; Trans++) {
        /*  both candidates voiced */
        if ((Pitch->data[b_Pitch + Pitch->size[0] * loop_ub] > 0.0) &&
            (Pitch->data[Trans + Pitch->size[0] * (loop_ub - 1)] > 0.0)) {
          b_Trans->data[(Trans + b_Trans->size[0] * b_Pitch) + b_Trans->size[0] *
            b_Trans->size[1] * loop_ub] = 0.15 * (fabs(Pitch->data[b_Pitch +
            Pitch->size[0] * loop_ub] - Pitch->data[Trans + Pitch->size[0] *
            (loop_ub - 1)]) / mean_pitch);
        }

        /*  one candiate is unvoiced */
        if (((Pitch->data[b_Pitch + Pitch->size[0] * loop_ub] == 0.0) &&
             (Pitch->data[Trans + Pitch->size[0] * (loop_ub - 1)] > 0.0)) ||
            ((Pitch->data[b_Pitch + Pitch->size[0] * loop_ub] > 0.0) &&
             (Pitch->data[Trans + Pitch->size[0] * (loop_ub - 1)] == 0.0))) {
          y = fabs(Energy->data[loop_ub - 1] - Energy->data[loop_ub]);
          if ((1.0 <= y) || rtIsNaN(y)) {
            d1 = 1.0;
          } else {
            d1 = y;
          }

          b_Trans->data[(Trans + b_Trans->size[0] * b_Pitch) + b_Trans->size[0] *
            b_Trans->size[1] * loop_ub] = 0.5 * (1.0 - d1);
        }

        /*  both candidates are unvoiced */
        if ((Pitch->data[b_Pitch + Pitch->size[0] * loop_ub] == 0.0) &&
            (Pitch->data[Trans + Pitch->size[0] * (loop_ub - 1)] == 0.0)) {
          b_Trans->data[(Trans + b_Trans->size[0] * b_Pitch) + b_Trans->size[0] *
            b_Trans->size[1] * loop_ub] = 0.1;
        }
      }
    }
  }

  /*  Overal balance between Local and Transition costs */
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = b_Trans->size[0];
  b_Pitch = b_Trans->size[1];
  Trans = b_Trans->size[2];
  loop_ub = loop_ub * b_Pitch * Trans;
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] /= 0.9;
  }

  emxInit_real_T(&PRED, 2);

  /*  Find the minimum cost path thru Pitch_Array using the Local and Trans costs */
  /* PATH1 find optimal path with the lowest cost */
  /*  */
  /* This routine is used to find the optimal path with lowest cost if two matrice(Local cost matrix and Transition cost) */
  /* are given. */
  /*  */
  /*  INPUTS:  */
  /*    Local is the two dimentional cost matrix denating the local cost; */
  /*    Trans is the three dimentional cost matrix denating the transition cost; */
  /*  */
  /*  OUTPUTS: */
  /*    PATH is the lowest cost path of the given matrix; */
  /*    Programmers: Dr. Zahorian, Lingyun Gu */
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
  /* getting the size of the local matrix; */
  loop_ub = Local->size[0];
  Trans = PRED->size[0] * PRED->size[1];
  PRED->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)PRED, Trans, (int)sizeof(double));
  loop_ub = Local->size[1];
  Trans = PRED->size[0] * PRED->size[1];
  PRED->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)PRED, Trans, (int)sizeof(double));
  loop_ub = Local->size[0] * Local->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    PRED->data[Trans] = 1.0;
  }

  /* initializing several desired matrix; */
  loop_ub = Local->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    P_data[Trans] = 1.0;
  }

  loop_ub = Local->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    p_data[Trans] = 0.0;
  }

  /* PATH=zeros(1,N); */
  loop_ub = Local->size[0];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    PCOST_data[Trans] = 0.0;
  }

  loop_ub = Local->size[0];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    CCOST_data[Trans] = 0.0;
  }

  for (loop_ub = 0; loop_ub < Local->size[0]; loop_ub++) {
    /* initializing the previous costs; */
    PCOST_data[loop_ub] = Local->data[loop_ub];
  }

  for (Trans = 1; Trans - 1 <= Local->size[1] - 2; Trans++) {
    /* this loop is doing the heart work of this routine. That means to */
    for (loop_ub = 0; loop_ub < Local->size[0]; loop_ub++) {
      CCOST_data[loop_ub] = 1.0E+30;

      /* get the lowest cost path; */
      for (b_Pitch = 0; b_Pitch < Local->size[0]; b_Pitch++) {
        if (PCOST_data[b_Pitch] + b_Trans->data[(b_Pitch + b_Trans->size[0] *
             loop_ub) + b_Trans->size[0] * b_Trans->size[1] * Trans] <=
            CCOST_data[loop_ub]) {
          /* deciding the optimal path between two points in two next column;  */
          CCOST_data[loop_ub] = PCOST_data[b_Pitch] + b_Trans->data[(b_Pitch +
            b_Trans->size[0] * loop_ub) + b_Trans->size[0] * b_Trans->size[1] *
            Trans];
          PRED->data[loop_ub + PRED->size[0] * Trans] = 1.0 + (double)b_Pitch;

          /* this line is very importent, used to mark the chosen points; */
        }
      }

      CCOST_data[loop_ub] += Local->data[loop_ub + Local->size[0] * Trans];

      /* new cost is gotten by the adding of Local cost and current cost; */
    }

    for (loop_ub = 0; loop_ub < Local->size[0]; loop_ub++) {
      PCOST_data[loop_ub] = CCOST_data[loop_ub];

      /* using the new current cost to update the previous cost; */
    }

    p_data[Trans] = 1.0;
    for (loop_ub = 0; loop_ub <= Local->size[0] - 2; loop_ub++) {
      /* obtaining the points with lowest cost in every column; */
      if (CCOST_data[loop_ub + 1] <= CCOST_data[0]) {
        CCOST_data[0] = CCOST_data[loop_ub + 1];
        p_data[Trans] = 2.0 + (double)loop_ub;
      }
    }
  }

  emxFree_real_T(&b_Trans);

  /*   Determine ending state with lowest cost */
  /*   Note that CCOST array is filled with costs of states for ending time step */
  /*   at this point in code */
  /*   IT would seem that following lines of code should be able */
  /*   to be substituted for the above similar lines, which are used every iteration */
  /*   However, results are same with clean speech, but slightly degraded with noisy */
  /*   speech */
  /*    p(N) = 1; */
  /*    for J=2:M                   %obtaining the points with lowest cost in every column; */
  /*      if CCOST(J)<=CCOST(1) */
  /*           CCOST(1)=CCOST(J);p(N)=J; */
  /*      end */
  /*    end */
  P_data[Local->size[1] - 1] = p_data[Local->size[1] - 1];
  for (Trans = 0; Trans <= Local->size[1] - 2; Trans++) {
    loop_ub = (Local->size[1] - Trans) - 1;

    /* using this loop to get the path finally; from the last point going */
    P_data[loop_ub - 1] = PRED->data[((int)P_data[loop_ub] + PRED->size[0] *
      loop_ub) - 1];

    /* backward to find the previous points, etc; */
  }

  emxFree_real_T(&PRED);
  emxFree_real_T(&Local);

  /* getting the final path.  */
  /* extracting the pitch, using Path */
  Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)FinPitch, Trans, (int)sizeof(double));
  loop_ub = Pitch->size[1];
  Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)FinPitch, Trans, (int)sizeof(double));
  loop_ub = Pitch->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    FinPitch->data[Trans] = 0.0;
  }

  for (loop_ub = 0; loop_ub < Pitch->size[1]; loop_ub++) {
    FinPitch->data[loop_ub] = Pitch->data[((int)P_data[loop_ub] + Pitch->size[0]
      * loop_ub) - 1];
  }
}

/*
 * Arguments    : const emxArray_boolean_T *x
 *                emxArray_int32_T *y
 * Return Type  : void
 */
void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int k;
  int i;
  int j;
  k = 0;
  for (i = 1; i <= x->size[1]; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = k;
  emxEnsureCapacity((emxArray__common *)y, j, (int)sizeof(int));
  j = 0;
  for (i = 1; i <= x->size[1]; i++) {
    if (x->data[i - 1]) {
      y->data[j] = i;
      j++;
    }
  }
}

/*
 * File trailer for dynamic.c
 *
 * [EOF]
 */
