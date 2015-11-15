/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dynamic5.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:14:51
 */

/* Include Files */
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
  int numframes;
  int Trans;
  int loop_ub;
  emxArray_real_T *b_Trans;
  int i;
  int j;
  int k;
  int c_Trans;
  emxArray_real_T *PRED;
  int N;
  double P_data[4999];
  double p_data[4999];
  double CCOST[4];
  double PCOST[4];
  int J;
  int I;
  int K;
  double b_CCOST;
  int b_I;
  int n;
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
  numframes = Pitch_array->size[1] - 1;

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

  emxInit_real_T2(&b_Trans, 3);

  /* initialization for the formation of the transition cost matrix */
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[0] = 4;
  b_Trans->size[1] = 4;
  b_Trans->size[2] = Pitch_array->size[1];
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = 16 * Pitch_array->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] = 0.0;
  }

  /* the transition cost matrix is proportional to frequency differences */
  /* between successive candidates. */
  for (i = 1; i - 1 < numframes; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
          b_Trans->size[1] * i] = fabs(Pitch_array->data[j + Pitch_array->size[0]
          * i] - Pitch_array->data[k + Pitch_array->size[0] * (i - 1)]) / 60.0;
        b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
          b_Trans->size[1] * i] = 0.05 * b_Trans->data[(k + b_Trans->size[0] * j)
          + b_Trans->size[0] * b_Trans->size[1] * i] + b_Trans->data[(k +
          b_Trans->size[0] * j) + b_Trans->size[0] * b_Trans->size[1] * i] *
          b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
          b_Trans->size[1] * i];
      }
    }
  }

  /*  Overal balance between Local and Transition costs */
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[0] = 4;
  b_Trans->size[1] = 4;
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  Trans = b_Trans->size[0];
  loop_ub = b_Trans->size[1];
  c_Trans = b_Trans->size[2];
  loop_ub = Trans * loop_ub * c_Trans;
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
  N = Local->size[1];

  /* getting the size of the local matrix; */
  Trans = PRED->size[0] * PRED->size[1];
  PRED->size[0] = 4;
  PRED->size[1] = Local->size[1];
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

  for (J = 0; J < 4; J++) {
    /* initializing the previous costs; */
    PCOST[J] = Local->data[J];
  }

  for (I = 1; I - 1 <= N - 2; I++) {
    /* this loop is doing the heart work of this routine. That means to */
    for (J = 0; J < 4; J++) {
      CCOST[J] = 1.0E+30;

      /* get the lowest cost path; */
      for (K = 0; K < 4; K++) {
        b_CCOST = CCOST[J];
        if (PCOST[K] + b_Trans->data[(K + b_Trans->size[0] * J) + b_Trans->size
            [0] * b_Trans->size[1] * I] <= CCOST[J]) {
          /* deciding the optimal path between two points in two next column;  */
          b_CCOST = PCOST[K] + b_Trans->data[(K + b_Trans->size[0] * J) +
            b_Trans->size[0] * b_Trans->size[1] * I];
          PRED->data[J + PRED->size[0] * I] = 1.0 + (double)K;

          /* this line is very importent, used to mark the chosen points; */
        }

        CCOST[J] = b_CCOST;
      }

      CCOST[J] += Local->data[J + Local->size[0] * I];

      /* new cost is gotten by the adding of Local cost and current cost; */
    }

    for (J = 0; J < 4; J++) {
      PCOST[J] = CCOST[J];

      /* using the new current cost to update the previous cost; */
    }

    p_data[I] = 1.0;
    for (J = 0; J < 3; J++) {
      /* obtaining the points with lowest cost in every column; */
      if (CCOST[J + 1] <= CCOST[0]) {
        CCOST[0] = CCOST[J + 1];
        p_data[I] = 2.0 + (double)J;
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
  for (I = 0; I <= Local->size[1] - 2; I++) {
    b_I = (N - I) - 1;

    /* using this loop to get the path finally; from the last point going */
    P_data[b_I - 1] = PRED->data[((int)P_data[b_I] + PRED->size[0] * b_I) - 1];

    /* backward to find the previous points, etc; */
  }

  emxFree_real_T(&PRED);
  emxFree_real_T(&Local);

  /* getting the final path.  */
  /*  Extract the final vocied F0 track which has the lowest cost */
  /*  At this point, VSpec_F0 is the spectral pitch track for voiced frames */
  Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch_array->size[1];
  emxEnsureCapacity((emxArray__common *)FinPitch, Trans, (int)sizeof(double));
  loop_ub = Pitch_array->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    FinPitch->data[Trans] = 0.0;
  }

  for (n = 0; n <= numframes; n++) {
    FinPitch->data[n] = Pitch_array->data[((int)P_data[n] + Pitch_array->size[0]
      * n) - 1];
  }
}

/*
 * File trailer for dynamic5.c
 *
 * [EOF]
 */
