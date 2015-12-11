/*
 * File: dynamic.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 11-Dec-2015 06:07:48
 */

/* Include Files */
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
  emxArray_int32_T *r10;
  int numframes;
  int numcands;
  int end;
  int trueCount;
  int i;
  int partialTrueCount;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *c_Pitch;
  emxArray_real_T *Local;
  double mean_pitch;
  emxArray_real_T *Trans;
  int j;
  int k;
  double y;
  double d1;
  emxArray_real_T *PRED;
  int N;
  int M;
  double P_data[4999];
  double p_data[4999];
  double PCOST_data[499];
  double CCOST_data[499];
  int J;
  int I;
  int K;
  int b_I;
  emxInit_int32_T(&r10, 2);

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
  numframes = Pitch->size[1] - 1;
  numcands = Pitch->size[0] - 1;

  /* Copy some arrays */
  end = Pitch->size[1] - 1;
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    if (Pitch->data[(numcands + Pitch->size[0] * i) - 1] > 0.0) {
      trueCount++;
    }
  }

  i = r10->size[0] * r10->size[1];
  r10->size[0] = 1;
  r10->size[1] = trueCount;
  emxEnsureCapacity((emxArray__common *)r10, i, (int)sizeof(int));
  partialTrueCount = 0;
  for (i = 0; i <= end; i++) {
    if (Pitch->data[(numcands + Pitch->size[0] * i) - 1] > 0.0) {
      r10->data[partialTrueCount] = i + 1;
      partialTrueCount++;
    }
  }

  emxInit_real_T(&b_Pitch, 2);
  emxInit_real_T(&c_Pitch, 2);
  partialTrueCount = Pitch->size[1];
  end = Pitch->size[0];
  i = c_Pitch->size[0] * c_Pitch->size[1];
  c_Pitch->size[0] = 1;
  c_Pitch->size[1] = partialTrueCount;
  emxEnsureCapacity((emxArray__common *)c_Pitch, i, (int)sizeof(double));
  for (i = 0; i < partialTrueCount; i++) {
    c_Pitch->data[c_Pitch->size[0] * i] = Pitch->data[(end + Pitch->size[0] * i)
      - 2];
  }

  i = b_Pitch->size[0] * b_Pitch->size[1];
  b_Pitch->size[0] = 1;
  b_Pitch->size[1] = r10->size[1];
  emxEnsureCapacity((emxArray__common *)b_Pitch, i, (int)sizeof(double));
  partialTrueCount = r10->size[1];
  for (i = 0; i < partialTrueCount; i++) {
    b_Pitch->data[b_Pitch->size[0] * i] = c_Pitch->data[r10->data[r10->size[0] *
      i] - 1];
  }

  emxFree_real_T(&c_Pitch);
  emxFree_int32_T(&r10);
  emxInit_real_T(&Local, 2);
  mean_pitch = mean(b_Pitch);

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Forming the local cost matrix */
  i = Local->size[0] * Local->size[1];
  Local->size[0] = Merit->size[0];
  Local->size[1] = Merit->size[1];
  emxEnsureCapacity((emxArray__common *)Local, i, (int)sizeof(double));
  partialTrueCount = Merit->size[0] * Merit->size[1];
  emxFree_real_T(&b_Pitch);
  for (i = 0; i < partialTrueCount; i++) {
    Local->data[i] = 1.0 - Merit->data[i];
  }

  emxInit_real_T2(&Trans, 3);

  /*  Initialization for the formation of the transition cost matrix */
  i = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = Pitch->size[0];
  Trans->size[1] = Pitch->size[0];
  Trans->size[2] = Pitch->size[1];
  emxEnsureCapacity((emxArray__common *)Trans, i, (int)sizeof(double));
  partialTrueCount = Pitch->size[0] * Pitch->size[0] * Pitch->size[1];
  for (i = 0; i < partialTrueCount; i++) {
    Trans->data[i] = 1.0;
  }

  /*  The transition cost matrix is proportional to frequency differences */
  /*  between successive candidates. */
  for (i = 1; i - 1 < numframes; i++) {
    for (j = 0; j <= numcands; j++) {
      for (k = 0; k <= numcands; k++) {
        /*  both candidates voiced */
        if ((Pitch->data[j + Pitch->size[0] * i] > 0.0) && (Pitch->data[k +
             Pitch->size[0] * (i - 1)] > 0.0)) {
          Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1]
            * i] = 0.15 * (fabs(Pitch->data[j + Pitch->size[0] * i] -
                                Pitch->data[k + Pitch->size[0] * (i - 1)]) /
                           mean_pitch);
        }

        /*  one candiate is unvoiced */
        if (((Pitch->data[j + Pitch->size[0] * i] == 0.0) && (Pitch->data[k +
              Pitch->size[0] * (i - 1)] > 0.0)) || ((Pitch->data[j + Pitch->
              size[0] * i] > 0.0) && (Pitch->data[k + Pitch->size[0] * (i - 1)] ==
              0.0))) {
          y = fabs(Energy->data[i - 1] - Energy->data[i]);
          if ((1.0 <= y) || rtIsNaN(y)) {
            d1 = 1.0;
          } else {
            d1 = y;
          }

          Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1]
            * i] = 0.5 * (1.0 - d1);
        }

        /*  both candidates are unvoiced */
        if ((Pitch->data[j + Pitch->size[0] * i] == 0.0) && (Pitch->data[k +
             Pitch->size[0] * (i - 1)] == 0.0)) {
          Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1]
            * i] = 0.1;
        }
      }
    }
  }

  /*  Overal balance between Local and Transition costs */
  i = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity((emxArray__common *)Trans, i, (int)sizeof(double));
  partialTrueCount = Trans->size[0];
  end = Trans->size[1];
  trueCount = Trans->size[2];
  partialTrueCount = partialTrueCount * end * trueCount;
  for (i = 0; i < partialTrueCount; i++) {
    Trans->data[i] /= 0.9;
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
  N = Local->size[1];
  M = Local->size[0] - 1;

  /* getting the size of the local matrix; */
  i = PRED->size[0] * PRED->size[1];
  PRED->size[0] = Local->size[0];
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity((emxArray__common *)PRED, i, (int)sizeof(double));
  partialTrueCount = Local->size[0] * Local->size[1];
  for (i = 0; i < partialTrueCount; i++) {
    PRED->data[i] = 1.0;
  }

  /* initializing several desired matrix; */
  partialTrueCount = Local->size[1];
  for (i = 0; i < partialTrueCount; i++) {
    P_data[i] = 1.0;
  }

  partialTrueCount = Local->size[1];
  for (i = 0; i < partialTrueCount; i++) {
    p_data[i] = 0.0;
  }

  /* PATH=zeros(1,N); */
  partialTrueCount = Local->size[0];
  for (i = 0; i < partialTrueCount; i++) {
    PCOST_data[i] = 0.0;
  }

  partialTrueCount = Local->size[0];
  for (i = 0; i < partialTrueCount; i++) {
    CCOST_data[i] = 0.0;
  }

  for (J = 0; J <= M; J++) {
    /* initializing the previous costs; */
    PCOST_data[J] = Local->data[J];
  }

  for (I = 1; I - 1 <= N - 2; I++) {
    /* this loop is doing the heart work of this routine. That means to */
    for (J = 0; J <= M; J++) {
      CCOST_data[J] = 1.0E+30;

      /* get the lowest cost path; */
      for (K = 0; K <= M; K++) {
        if (PCOST_data[K] + Trans->data[(K + Trans->size[0] * J) + Trans->size[0]
            * Trans->size[1] * I] <= CCOST_data[J]) {
          /* deciding the optimal path between two points in two next column;  */
          CCOST_data[J] = PCOST_data[K] + Trans->data[(K + Trans->size[0] * J) +
            Trans->size[0] * Trans->size[1] * I];
          PRED->data[J + PRED->size[0] * I] = 1.0 + (double)K;

          /* this line is very importent, used to mark the chosen points; */
        }
      }

      CCOST_data[J] += Local->data[J + Local->size[0] * I];

      /* new cost is gotten by the adding of Local cost and current cost; */
    }

    for (J = 0; J <= M; J++) {
      PCOST_data[J] = CCOST_data[J];

      /* using the new current cost to update the previous cost; */
    }

    p_data[I] = 1.0;
    for (J = 0; J < M; J++) {
      /* obtaining the points with lowest cost in every column; */
      if (CCOST_data[J + 1] <= CCOST_data[0]) {
        CCOST_data[0] = CCOST_data[J + 1];
        p_data[I] = 2.0 + (double)J;
      }
    }
  }

  emxFree_real_T(&Trans);

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
  /* extracting the pitch, using Path */
  i = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch->size[1];
  emxEnsureCapacity((emxArray__common *)FinPitch, i, (int)sizeof(double));
  partialTrueCount = Pitch->size[1];
  for (i = 0; i < partialTrueCount; i++) {
    FinPitch->data[i] = 0.0;
  }

  for (i = 0; i <= numframes; i++) {
    FinPitch->data[i] = Pitch->data[((int)P_data[i] + Pitch->size[0] * i) - 1];
  }
}

/*
 * File trailer for dynamic.c
 *
 * [EOF]
 */
