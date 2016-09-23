/*
 * path1.c
 *
 * Code generation for function 'path1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "path1.h"
#include "yaapt_emxutil.h"
#include "error.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo tk_emlrtRSI = { 31, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRSInfo uk_emlrtRSI = { 34, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRSInfo vk_emlrtRSI = { 61, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo ld_emlrtRTEI = { 1, 17, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo md_emlrtRTEI = { 38, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 46, 22, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 74, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 75, 13, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtRTEInfo kg_emlrtRTEI = { 99, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 97, 6, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 97, 1, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 100, 14, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 100, 21, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 100, 4, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 72, 5, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 74, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 75, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 75, 31, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 69, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 69, 9, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 51, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 60, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 64, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 64, 33, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 64, 35, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 64, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 54, 16, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 54, 31, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 54, 33, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 54, 35, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 54, 39, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 55, 26, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 55, 41, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 55, 43, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 55, 45, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 55, 17, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 56, 22, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 56, 24, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 46, 20, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 46, 5, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

/* Function Definitions */
void path1(const emlrtStack *sp, const emxArray_real_T *Local, const
           emxArray_real_T *Trans, real_T PATH_data[], int32_T PATH_size[2])
{
  int32_T N;
  int32_T M;
  emxArray_real_T *PRED;
  int32_T i34;
  int32_T loop_ub;
  int32_T p_size_idx_1;
  real_T p_data[4999];
  int32_T PCOST_size_idx_1;
  int32_T CCOST_size_idx_1;
  real_T PCOST_data[499];
  int32_T J;
  real_T CCOST_data[499];
  int32_T I;
  int32_T K;
  int32_T b_I;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 15U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 0);

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
  if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 0, Local->size[0] >= 500)) {
    /* if M is greater than 100, stop the routine; */
    st.site = &tk_emlrtRSI;
    i_error(&st);
  }

  if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 1, Local->size[1] >= 5000)) {
    /* if N is greater than 1000, stop the routine; */
    st.site = &uk_emlrtRSI;
    j_error(&st);
  }

  emxInit_real_T(sp, &PRED, 2, &md_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 1);
  i34 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = Local->size[0];
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)PRED, i34, (int32_T)sizeof(real_T),
                    &ld_emlrtRTEI);
  loop_ub = Local->size[0] * Local->size[1];
  for (i34 = 0; i34 < loop_ub; i34++) {
    PRED->data[i34] = 1.0;
  }

  /* initializing several desired matrix; */
  PATH_size[0] = 1;
  PATH_size[1] = Local->size[1];
  loop_ub = Local->size[1];
  for (i34 = 0; i34 < loop_ub; i34++) {
    PATH_data[i34] = 1.0;
  }

  p_size_idx_1 = Local->size[1];
  loop_ub = Local->size[1];
  for (i34 = 0; i34 < loop_ub; i34++) {
    p_data[i34] = 0.0;
  }

  /* PATH=zeros(1,N); */
  PCOST_size_idx_1 = Local->size[0];
  loop_ub = Local->size[0];
  for (i34 = 0; i34 < loop_ub; i34++) {
    PCOST_data[i34] = 0.0;
  }

  CCOST_size_idx_1 = Local->size[0];
  loop_ub = Local->size[0];
  for (i34 = 0; i34 < loop_ub; i34++) {
    CCOST_data[i34] = 0.0;
  }

  J = 1;
  while (J - 1 <= M) {
    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 2);

    /* initializing the previous costs; */
    i34 = Local->size[1];
    if (!(1 <= i34)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i34, &yf_emlrtBCI, sp);
    }

    i34 = Local->size[0];
    if (!((J >= 1) && (J <= i34))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, i34, &hh_emlrtBCI, sp);
    }

    if (!((J >= 1) && (J <= PCOST_size_idx_1))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, PCOST_size_idx_1, &ih_emlrtBCI, sp);
    }

    PCOST_data[J - 1] = Local->data[J - 1];
    J++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 0, 0);
  I = 2;
  while (I - 2 <= N - 2) {
    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 1, 1);

    /* this loop is doing the heart work of this routine. That means to */
    J = 1;
    while (J - 1 <= M) {
      covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 2, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 3);
      if (!((J >= 1) && (J <= CCOST_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, CCOST_size_idx_1, &og_emlrtBCI, sp);
      }

      CCOST_data[J - 1] = 1.0E+30;

      /* get the lowest cost path; */
      K = 1;
      while (K - 1 <= M) {
        covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 3, 1);
        if (!((K >= 1) && (K <= PCOST_size_idx_1))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, PCOST_size_idx_1, &ug_emlrtBCI, sp);
        }

        i34 = Trans->size[0];
        if (!((K >= 1) && (K <= i34))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, i34, &vg_emlrtBCI, sp);
        }

        i34 = Trans->size[1];
        if (!((J >= 1) && (J <= i34))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, i34, &wg_emlrtBCI, sp);
        }

        i34 = Trans->size[2];
        if (!((I >= 1) && (I <= i34))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i34, &xg_emlrtBCI, sp);
        }

        if (!((J >= 1) && (J <= CCOST_size_idx_1))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, CCOST_size_idx_1, &yg_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 2, PCOST_data[K - 1] +
                       Trans->data[((K + Trans->size[0] * (J - 1)) + Trans->
              size[0] * Trans->size[1] * (I - 1)) - 1] <= CCOST_data[J - 1])) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 4);

          /* deciding the optimal path between two points in two next column;  */
          if (!((K >= 1) && (K <= PCOST_size_idx_1))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, PCOST_size_idx_1, &ah_emlrtBCI,
              sp);
          }

          i34 = Trans->size[0];
          if (!((K >= 1) && (K <= i34))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, i34, &bh_emlrtBCI, sp);
          }

          i34 = Trans->size[1];
          if (!((J >= 1) && (J <= i34))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i34, &ch_emlrtBCI, sp);
          }

          i34 = Trans->size[2];
          if (!((I >= 1) && (I <= i34))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i34, &dh_emlrtBCI, sp);
          }

          if (!((J >= 1) && (J <= CCOST_size_idx_1))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, CCOST_size_idx_1, &eh_emlrtBCI,
              sp);
          }

          CCOST_data[J - 1] = PCOST_data[K - 1] + Trans->data[((K + Trans->size
            [0] * (J - 1)) + Trans->size[0] * Trans->size[1] * (I - 1)) - 1];
          i34 = PRED->size[0];
          if (!((J >= 1) && (J <= i34))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i34, &fh_emlrtBCI, sp);
          }

          i34 = PRED->size[1];
          if (!((I >= 1) && (I <= i34))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i34, &gh_emlrtBCI, sp);
          }

          PRED->data[(J + PRED->size[0] * (I - 1)) - 1] = 1.0 + (real_T)(K - 1);

          /* this line is very importent, used to mark the chosen points; */
        }

        K++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 3, 0);
      if (!((J >= 1) && (J <= CCOST_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, CCOST_size_idx_1, &pg_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 3, CCOST_data[J - 1] >=
                     1.0E+30)) {
        st.site = &vk_emlrtRSI;
        k_error(&st);
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 5);
      if (!((J >= 1) && (J <= CCOST_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, CCOST_size_idx_1, &qg_emlrtBCI, sp);
      }

      i34 = Local->size[0];
      if (!((J >= 1) && (J <= i34))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i34, &rg_emlrtBCI, sp);
      }

      i34 = Local->size[1];
      if (!((I >= 1) && (I <= i34))) {
        emlrtDynamicBoundsCheckR2012b(I, 1, i34, &sg_emlrtBCI, sp);
      }

      if (!((J >= 1) && (J <= CCOST_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, CCOST_size_idx_1, &tg_emlrtBCI, sp);
      }

      CCOST_data[J - 1] += Local->data[(J + Local->size[0] * (I - 1)) - 1];

      /* new cost is gotten by the adding of Local cost and current cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 2, 0);
    J = 1;
    while (J - 1 <= M) {
      covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 4, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 6);
      if (!((J >= 1) && (J <= CCOST_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, CCOST_size_idx_1, &mg_emlrtBCI, sp);
      }

      if (!((J >= 1) && (J <= PCOST_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, PCOST_size_idx_1, &ng_emlrtBCI, sp);
      }

      PCOST_data[J - 1] = CCOST_data[J - 1];

      /* using the new current cost to update the previous cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 7);
    if (!((I >= 1) && (I <= p_size_idx_1))) {
      emlrtDynamicBoundsCheckR2012b(I, 1, p_size_idx_1, &ig_emlrtBCI, sp);
    }

    p_data[I - 1] = 1.0;
    J = 0;
    while (J <= M - 1) {
      covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 5, 1);

      /* obtaining the points with lowest cost in every column; */
      if (!(1 <= CCOST_size_idx_1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, CCOST_size_idx_1, &ag_emlrtBCI, sp);
      }

      if (!((J + 2 >= 1) && (J + 2 <= CCOST_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(J + 2, 1, CCOST_size_idx_1, &jg_emlrtBCI,
          sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 4, CCOST_data[J + 1] <=
                     CCOST_data[0])) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 8);
        if (!(1 <= CCOST_size_idx_1)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, CCOST_size_idx_1, &bg_emlrtBCI, sp);
        }

        if (!((J + 2 >= 1) && (J + 2 <= CCOST_size_idx_1))) {
          emlrtDynamicBoundsCheckR2012b(J + 2, 1, CCOST_size_idx_1, &kg_emlrtBCI,
            sp);
        }

        CCOST_data[0] = CCOST_data[J + 1];
        if (!((I >= 1) && (I <= p_size_idx_1))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, p_size_idx_1, &lg_emlrtBCI, sp);
        }

        p_data[I - 1] = 2.0 + (real_T)J;
      }

      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 5, 0);
    I++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 9);

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
  loop_ub = Local->size[1];
  i34 = Local->size[1];
  if (!((i34 >= 1) && (i34 <= p_size_idx_1))) {
    emlrtDynamicBoundsCheckR2012b(i34, 1, p_size_idx_1, &cg_emlrtBCI, sp);
  }

  PCOST_size_idx_1 = Local->size[1];
  if (!((PCOST_size_idx_1 >= 1) && (PCOST_size_idx_1 <= loop_ub))) {
    emlrtDynamicBoundsCheckR2012b(PCOST_size_idx_1, 1, loop_ub, &dg_emlrtBCI, sp);
  }

  PATH_data[PCOST_size_idx_1 - 1] = p_data[i34 - 1];
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &kg_emlrtRTEI, sp);
  I = 0;
  while (I <= Local->size[1] - 2) {
    b_I = N - I;
    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 6, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 10);

    /* using this loop to get the path finally; from the last point going */
    i34 = PRED->size[0];
    if (!((b_I >= 1) && (b_I <= PATH_size[1]))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, PATH_size[1], &fg_emlrtBCI, sp);
    }

    PCOST_size_idx_1 = (int32_T)PATH_data[b_I - 1];
    if (!((PCOST_size_idx_1 >= 1) && (PCOST_size_idx_1 <= i34))) {
      emlrtDynamicBoundsCheckR2012b(PCOST_size_idx_1, 1, i34, &eg_emlrtBCI, sp);
    }

    i34 = PRED->size[1];
    if (!((b_I >= 1) && (b_I <= i34))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, i34, &gg_emlrtBCI, sp);
    }

    i34 = b_I - 1;
    if (!((i34 >= 1) && (i34 <= PATH_size[1]))) {
      emlrtDynamicBoundsCheckR2012b(i34, 1, PATH_size[1], &hg_emlrtBCI, sp);
    }

    PATH_data[i34 - 1] = PRED->data[(PCOST_size_idx_1 + PRED->size[0] * (b_I - 1))
      - 1];

    /* backward to find the previous points, etc; */
    I++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&PRED);
  covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 6, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 11);

  /* getting the final path.  */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (path1.c) */
