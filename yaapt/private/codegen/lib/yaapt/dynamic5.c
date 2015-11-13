/*
 * File: dynamic5.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "dynamic5.h"
#include "yaapt_emxutil.h"

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
  emxArray_real_T *Local;
  int Trans;
  int loop_ub;
  emxArray_real_T *b_Trans;
  int c_Trans;
  emxArray_real_T *PRED;
  double P_data[4999];
  double p_data[4999];
  double CCOST[4];
  double PCOST[4];
  double b_CCOST;
  emxInit_real_T(&Local, 2);

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
  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* forming the local cost matrix */
  Trans = Local->size[0] * Local->size[1];
  Local->size[0] = 4;
  Local->size[1] = Merit_array->size[1];
  emxEnsureCapacity((emxArray__common *)Local, Trans, (int)sizeof(double));
  loop_ub = Merit_array->size[0] * Merit_array->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    Local->data[Trans] = 1.0 - Merit_array->data[Trans];
  }

  c_emxInit_real_T(&b_Trans, 3);

  /* initialization for the formation of the transition cost matrix */
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[0] = 4;
  b_Trans->size[1] = 4;
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = Pitch_array->size[1];
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[2] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = 16 * Pitch_array->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] = 0.0;
  }

  /* the transition cost matrix is proportional to frequency differences */
  /* between successive candidates. */
  for (loop_ub = 1; loop_ub - 1 <= Pitch_array->size[1] - 2; loop_ub++) {
    for (Trans = 0; Trans < 4; Trans++) {
      for (c_Trans = 0; c_Trans < 4; c_Trans++) {
        b_Trans->data[(c_Trans + b_Trans->size[0] * Trans) + b_Trans->size[0] *
          b_Trans->size[1] * loop_ub] = fabs(Pitch_array->data[Trans +
          Pitch_array->size[0] * loop_ub] - Pitch_array->data[c_Trans +
          Pitch_array->size[0] * (loop_ub - 1)]) / 60.0;
        b_Trans->data[(c_Trans + b_Trans->size[0] * Trans) + b_Trans->size[0] *
          b_Trans->size[1] * loop_ub] = 0.05 * b_Trans->data[(c_Trans +
          b_Trans->size[0] * Trans) + b_Trans->size[0] * b_Trans->size[1] *
          loop_ub] + b_Trans->data[(c_Trans + b_Trans->size[0] * Trans) +
          b_Trans->size[0] * b_Trans->size[1] * loop_ub] * b_Trans->data
          [(c_Trans + b_Trans->size[0] * Trans) + b_Trans->size[0] *
          b_Trans->size[1] * loop_ub];
      }
    }
  }

  /*  Overal balance between Local and Transition costs */
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[0] = 4;
  b_Trans->size[1] = 4;
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = b_Trans->size[0];
  Trans = b_Trans->size[1];
  c_Trans = b_Trans->size[2];
  loop_ub = loop_ub * Trans * c_Trans;
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] *= k1;
  }

  emxInit_real_T(&PRED, 2);

  /*  search the best path */
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
  Trans = PRED->size[0] * PRED->size[1];
  PRED->size[0] = 4;
  emxEnsureCapacity((emxArray__common *)PRED, Trans, (int)sizeof(double));
  loop_ub = Local->size[1];
  Trans = PRED->size[0] * PRED->size[1];
  PRED->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)PRED, Trans, (int)sizeof(double));
  loop_ub = Local->size[1] << 2;
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
  for (Trans = 0; Trans < 4; Trans++) {
    CCOST[Trans] = 0.0;
  }

  for (loop_ub = 0; loop_ub < 4; loop_ub++) {
    /* initializing the previous costs; */
    PCOST[loop_ub] = Local->data[loop_ub];
  }

  for (c_Trans = 1; c_Trans - 1 <= Local->size[1] - 2; c_Trans++) {
    /* this loop is doing the heart work of this routine. That means to */
    for (loop_ub = 0; loop_ub < 4; loop_ub++) {
      CCOST[loop_ub] = 1.0E+30;

      /* get the lowest cost path; */
      for (Trans = 0; Trans < 4; Trans++) {
        b_CCOST = CCOST[loop_ub];
        if (PCOST[Trans] + b_Trans->data[(Trans + b_Trans->size[0] * loop_ub) +
            b_Trans->size[0] * b_Trans->size[1] * c_Trans] <= CCOST[loop_ub]) {
          /* deciding the optimal path between two points in two next column;  */
          b_CCOST = PCOST[Trans] + b_Trans->data[(Trans + b_Trans->size[0] *
            loop_ub) + b_Trans->size[0] * b_Trans->size[1] * c_Trans];
          PRED->data[loop_ub + PRED->size[0] * c_Trans] = 1.0 + (double)Trans;

          /* this line is very importent, used to mark the chosen points; */
        }

        CCOST[loop_ub] = b_CCOST;
      }

      CCOST[loop_ub] += Local->data[loop_ub + Local->size[0] * c_Trans];

      /* new cost is gotten by the adding of Local cost and current cost; */
    }

    for (loop_ub = 0; loop_ub < 4; loop_ub++) {
      PCOST[loop_ub] = CCOST[loop_ub];

      /* using the new current cost to update the previous cost; */
    }

    p_data[c_Trans] = 1.0;
    for (loop_ub = 0; loop_ub < 3; loop_ub++) {
      /* obtaining the points with lowest cost in every column; */
      if (CCOST[loop_ub + 1] <= CCOST[0]) {
        CCOST[0] = CCOST[loop_ub + 1];
        p_data[c_Trans] = 2.0 + (double)loop_ub;
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
  for (c_Trans = 0; c_Trans <= Local->size[1] - 2; c_Trans++) {
    loop_ub = (Local->size[1] - c_Trans) - 1;

    /* using this loop to get the path finally; from the last point going */
    P_data[loop_ub - 1] = PRED->data[((int)P_data[loop_ub] + PRED->size[0] *
      loop_ub) - 1];

    /* backward to find the previous points, etc; */
  }

  emxFree_real_T(&PRED);
  emxFree_real_T(&Local);

  /* getting the final path.  */
  /*  Extract the final vocied F0 track which has the lowest cost */
  /*  At this point, VSpec_F0 is the spectral pitch track for voiced frames */
  Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)FinPitch, Trans, (int)sizeof(double));
  loop_ub = Pitch_array->size[1];
  Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)FinPitch, Trans, (int)sizeof(double));
  loop_ub = Pitch_array->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    FinPitch->data[Trans] = 0.0;
  }

  for (loop_ub = 0; loop_ub < Pitch_array->size[1]; loop_ub++) {
    FinPitch->data[loop_ub] = Pitch_array->data[((int)P_data[loop_ub] +
      Pitch_array->size[0] * loop_ub) - 1];
  }
}

/*
 * File trailer for dynamic5.c
 *
 * [EOF]
 */
