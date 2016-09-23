/*
 * File: path1.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "path1.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * PATH1 find optimal path with the lowest cost
 *
 * This routine is used to find the optimal path with lowest cost if two matrice(Local cost matrix and Transition cost)
 * are given.
 *
 *  INPUTS:
 *    Local is the two dimentional cost matrix denating the local cost;
 *    Trans is the three dimentional cost matrix denating the transition cost;
 *
 *  OUTPUTS:
 *    PATH is the lowest cost path of the given matrix;
 * Arguments    : const emxArray_real_T *Local
 *                const emxArray_real_T *Trans
 *                double PATH_data[]
 *                int PATH_size[2]
 * Return Type  : void
 */
void path1(const emxArray_real_T *Local, const emxArray_real_T *Trans, double
           PATH_data[], int PATH_size[2])
{
  emxArray_real_T *PRED;
  int N;
  int M;
  int i21;
  int loop_ub;
  double p_data[4999];
  double PCOST_data[499];
  int J;
  double CCOST_data[499];
  int I;
  int K;
  int b_I;
  emxInit_real_T(&PRED, 2);

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
  N = Local->size[1] - 2;
  M = Local->size[0] - 1;

  /* getting the size of the local matrix; */
  i21 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = Local->size[0];
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity((emxArray__common *)PRED, i21, (int)sizeof(double));
  loop_ub = Local->size[0] * Local->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    PRED->data[i21] = 1.0;
  }

  /* initializing several desired matrix; */
  PATH_size[0] = 1;
  PATH_size[1] = Local->size[1];
  loop_ub = Local->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    PATH_data[i21] = 1.0;
  }

  loop_ub = Local->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    p_data[i21] = 0.0;
  }

  /* PATH=zeros(1,N); */
  loop_ub = Local->size[0];
  for (i21 = 0; i21 < loop_ub; i21++) {
    PCOST_data[i21] = 0.0;
  }

  loop_ub = Local->size[0];
  for (i21 = 0; i21 < loop_ub; i21++) {
    CCOST_data[i21] = 0.0;
  }

  for (J = 0; J <= M; J++) {
    /* initializing the previous costs; */
    PCOST_data[J] = Local->data[J];
  }

  for (I = 1; I - 1 <= N; I++) {
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
  PATH_data[Local->size[1] - 1] = p_data[Local->size[1] - 1];
  for (I = 0; I <= Local->size[1] - 2; I++) {
    b_I = (N - I) + 1;

    /* using this loop to get the path finally; from the last point going */
    PATH_data[b_I - 1] = PRED->data[((int)PATH_data[b_I] + PRED->size[0] * b_I)
      - 1];

    /* backward to find the previous points, etc; */
  }

  emxFree_real_T(&PRED);

  /* getting the final path.  */
}

/*
 * File trailer for path1.c
 *
 * [EOF]
 */
