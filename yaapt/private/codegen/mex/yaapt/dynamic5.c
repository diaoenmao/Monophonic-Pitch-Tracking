/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dynamic5.c
 *
 * Code generation for function 'dynamic5'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "dynamic5.h"
#include "yaapt_emxutil.h"
#include "error.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo gh_emlrtRSI = { 58, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo bc_emlrtRTEI = { 1, 23, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo cc_emlrtRTEI = { 37, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo dc_emlrtRTEI = { 40, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 49, 59, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 48, 67, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 48, 48, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { 1, 4, 64, 31, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 64, 31, "Path", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 64, 40, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 64, 5, "FinPitch", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo if_emlrtBCI = { 1, 4, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 48, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 49, 44, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 49, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

/* Function Definitions */

/*
 * function [FinPitch] = dynamic5(Pitch_array, Merit_array, k1)
 */
void dynamic5(const emlrtStack *sp, const emxArray_real_T *Pitch_array, const
              emxArray_real_T *Merit_array, real_T k1, emxArray_real_T *FinPitch)
{
  emxArray_real_T *Local;
  int32_T numframes;
  int32_T i21;
  int32_T loop_ub;
  emxArray_real_T *Trans;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T b_Trans;
  int32_T c_Trans;
  int32_T N;
  emxArray_real_T *PRED;
  int32_T P_size_idx_1;
  real_T P_data[4999];
  real_T p_data[4999];
  real_T PCOST[4];
  real_T CCOST[4];
  int32_T J;
  int32_T I;
  int32_T K;
  int32_T b_I;
  int32_T n;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Local, 2, &cc_emlrtRTEI, true);

  /*   Dynamic programming on speech processing */
  /*  */
  /*  [FinPitch] =dynamic5(Pitch_array, Merit_array, k1); */
  /*  This routine is used to compute Local and Transition cost matrices */
  /*  to enable lowest cost tracking of pitch candidates; */
  /*  It uses NFLER from the spectrogram and the highly robust */
  /*  spectral F0 track, plus the merits, for */
  /*  computation of the cost matrices. */
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
  /* 'dynamic5:27' F0_min = 60; */
  /*  some initializations. */
  /* 'dynamic5:30' [numcands, numframes] = size(Pitch_array); */
  numframes = Pitch_array->size[1] - 1;

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* forming the local cost matrix */
  /* 'dynamic5:37' Local = 1 - Merit_array; */
  i21 = Local->size[0] * Local->size[1];
  Local->size[0] = 4;
  Local->size[1] = Merit_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Local, i21, (int32_T)sizeof(real_T),
                    &bc_emlrtRTEI);
  loop_ub = Merit_array->size[0] * Merit_array->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    Local->data[i21] = 1.0 - Merit_array->data[i21];
  }

  emxInit_real_T2(sp, &Trans, 3, &dc_emlrtRTEI, true);

  /* initialization for the formation of the transition cost matrix */
  /* 'dynamic5:40' Trans  = zeros(numcands, numcands, numframes); */
  i21 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = 4;
  Trans->size[1] = 4;
  Trans->size[2] = Pitch_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i21, (int32_T)sizeof(real_T),
                    &bc_emlrtRTEI);
  loop_ub = 16 * Pitch_array->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    Trans->data[i21] = 0.0;
  }

  /* the transition cost matrix is proportional to frequency differences */
  /* between successive candidates. */
  /* 'dynamic5:45' for i = 2:numframes */
  i = 0;
  while (i <= numframes - 1) {
    /* 'dynamic5:46' for j = 1:numcands */
    j = 0;
    while (j < 4) {
      /* 'dynamic5:47' for k = 1:numcands */
      k = 0;
      while (k < 4) {
        /* 'dynamic5:48' Trans(k,j,i)  = (abs(Pitch_array(j,i) - Pitch_array(k,i-1)))/ F0_min ; */
        i21 = Pitch_array->size[1];
        b_Trans = (int32_T)(2.0 + (real_T)i);
        if (!((b_Trans >= 1) && (b_Trans <= i21))) {
          emlrtDynamicBoundsCheckR2012b(b_Trans, 1, i21, &bf_emlrtBCI, sp);
        }

        i21 = Pitch_array->size[1];
        b_Trans = (int32_T)((2.0 + (real_T)i) - 1.0);
        if (!((b_Trans >= 1) && (b_Trans <= i21))) {
          emlrtDynamicBoundsCheckR2012b(b_Trans, 1, i21, &af_emlrtBCI, sp);
        }

        i21 = Trans->size[2];
        b_Trans = 2 + i;
        if (!((b_Trans >= 1) && (b_Trans <= i21))) {
          emlrtDynamicBoundsCheckR2012b(b_Trans, 1, i21, &sf_emlrtBCI, sp);
        }

        Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1] *
          (b_Trans - 1)] = muDoubleScalarAbs(Pitch_array->data[j +
          Pitch_array->size[0] * (i + 1)] - Pitch_array->data[k +
          Pitch_array->size[0] * i]) / 60.0;

        /* 'dynamic5:49' Trans(k,j,i) =  0.05*Trans(k,j,i) + Trans(k,j,i)^2; */
        i21 = Trans->size[2];
        b_Trans = (int32_T)(2.0 + (real_T)i);
        if (!((b_Trans >= 1) && (b_Trans <= i21))) {
          emlrtDynamicBoundsCheckR2012b(b_Trans, 1, i21, &ye_emlrtBCI, sp);
        }

        i21 = Trans->size[2];
        b_Trans = 2 + i;
        if (!((b_Trans >= 1) && (b_Trans <= i21))) {
          emlrtDynamicBoundsCheckR2012b(b_Trans, 1, i21, &tf_emlrtBCI, sp);
        }

        i21 = Trans->size[2];
        c_Trans = 2 + i;
        if (!((c_Trans >= 1) && (c_Trans <= i21))) {
          emlrtDynamicBoundsCheckR2012b(c_Trans, 1, i21, &uf_emlrtBCI, sp);
        }

        Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1] *
          (c_Trans - 1)] = 0.05 * Trans->data[(k + Trans->size[0] * j) +
          Trans->size[0] * Trans->size[1] * (b_Trans - 1)] + Trans->data[(k +
          Trans->size[0] * j) + Trans->size[0] * Trans->size[1] * (i + 1)] *
          Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1]
          * (i + 1)];
        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  Overal balance between Local and Transition costs */
  /* 'dynamic5:55' Trans = k1 * Trans; */
  i21 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = 4;
  Trans->size[1] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i21, (int32_T)sizeof(real_T),
                    &bc_emlrtRTEI);
  loop_ub = Trans->size[0];
  c_Trans = Trans->size[1];
  b_Trans = Trans->size[2];
  loop_ub = loop_ub * c_Trans * b_Trans;
  for (i21 = 0; i21 < loop_ub; i21++) {
    Trans->data[i21] *= k1;
  }

  /*  search the best path */
  /* 'dynamic5:58' Path = path1(Local, Trans); */
  st.site = &gh_emlrtRSI;

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
  /* 'path1:28' [M,N]=size(Local); */
  N = Local->size[1];

  /* getting the size of the local matrix; */
  /* 'path1:30' if M>=500 */
  /* 'path1:33' if N>=5000 */
  if (Local->size[1] >= 5000) {
    /* if N is greater than 1000, stop the routine; */
    b_st.site = &hh_emlrtRSI;
    g_error(&b_st);
  }

  emxInit_real_T(&st, &PRED, 2, &ec_emlrtRTEI, true);

  /* 'path1:38' PRED=ones(M,N); */
  i21 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = 4;
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)PRED, i21, (int32_T)sizeof(real_T),
                    &bc_emlrtRTEI);
  loop_ub = Local->size[1] << 2;
  for (i21 = 0; i21 < loop_ub; i21++) {
    PRED->data[i21] = 1.0;
  }

  /* initializing several desired matrix; */
  /* 'path1:39' P=ones(1,N); */
  P_size_idx_1 = Local->size[1];
  loop_ub = Local->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    P_data[i21] = 1.0;
  }

  /* 'path1:40' p=zeros(1,N); */
  b_Trans = Local->size[1];
  loop_ub = Local->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    p_data[i21] = 0.0;
  }

  /* PATH=zeros(1,N); */
  /* 'path1:42' PCOST = zeros(1,M); */
  /* 'path1:43' CCOST = zeros(1,M); */
  for (i21 = 0; i21 < 4; i21++) {
    PCOST[i21] = 0.0;
    CCOST[i21] = 0.0;
  }

  /* 'path1:45' for J=1:M */
  J = 0;
  while (J < 4) {
    /* initializing the previous costs; */
    /* 'path1:46' PCOST(J)=Local(J,1); */
    i21 = Local->size[1];
    if (!(1 <= i21)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i21, &xe_emlrtBCI, &st);
    }

    PCOST[J] = Local->data[J];
    J++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* 'path1:49' for I=2:N */
  I = 2;
  while (I - 2 <= N - 2) {
    /* this loop is doing the heart work of this routine. That means to */
    /* 'path1:50' for J=1:M */
    J = 0;
    while (J < 4) {
      /* 'path1:51' CCOST(J)=1.0E+30; */
      CCOST[J] = 1.0E+30;

      /* get the lowest cost path; */
      /* 'path1:53' for K=1:M */
      K = 0;
      while (K < 4) {
        /* 'path1:54' if PCOST(K)+Trans(K,J,I)<=CCOST(J) */
        i21 = Trans->size[2];
        if (!((I >= 1) && (I <= i21))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i21, &pf_emlrtBCI, &st);
        }

        if (PCOST[K] + Trans->data[(K + Trans->size[0] * J) + Trans->size[0] *
            Trans->size[1] * (I - 1)] <= CCOST[J]) {
          /* deciding the optimal path between two points in two next column;  */
          /* 'path1:55' CCOST(J)=PCOST(K)+Trans(K,J,I); */
          i21 = Trans->size[2];
          if (!((I >= 1) && (I <= i21))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i21, &qf_emlrtBCI, &st);
          }

          CCOST[J] = PCOST[K] + Trans->data[(K + Trans->size[0] * J) +
            Trans->size[0] * Trans->size[1] * (I - 1)];

          /* 'path1:56' PRED(J,I)=K; */
          i21 = PRED->size[1];
          if (!((I >= 1) && (I <= i21))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i21, &rf_emlrtBCI, &st);
          }

          PRED->data[J + PRED->size[0] * (I - 1)] = 1.0 + (real_T)K;

          /* this line is very importent, used to mark the chosen points; */
        }

        K++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* 'path1:60' if CCOST(J)>=1.0E+30 */
      if (CCOST[J] >= 1.0E+30) {
        b_st.site = &ih_emlrtRSI;
        h_error(&b_st);
      }

      /* 'path1:64' CCOST(J)=CCOST(J)+Local(J,I); */
      i21 = Local->size[1];
      if (!((I >= 1) && (I <= i21))) {
        emlrtDynamicBoundsCheckR2012b(I, 1, i21, &of_emlrtBCI, &st);
      }

      CCOST[J] += Local->data[J + Local->size[0] * (I - 1)];

      /* new cost is gotten by the adding of Local cost and current cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* 'path1:68' for J=1:M */
    J = 0;
    while (J < 4) {
      /* 'path1:69' PCOST(J)=CCOST(J); */
      PCOST[J] = CCOST[J];

      /* using the new current cost to update the previous cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* 'path1:72' p(I)=1; */
    if (!((I >= 1) && (I <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(I, 1, b_Trans, &mf_emlrtBCI, &st);
    }

    p_data[I - 1] = 1.0;

    /* 'path1:73' for J=2:M */
    J = 0;
    while (J < 3) {
      /* obtaining the points with lowest cost in every column; */
      /* 'path1:74' if CCOST(J)<=CCOST(1) */
      if (CCOST[J + 1] <= CCOST[0]) {
        /* 'path1:75' CCOST(1)=CCOST(J); */
        CCOST[0] = CCOST[J + 1];

        /* 'path1:75' p(I)=J; */
        if (!((I >= 1) && (I <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, b_Trans, &nf_emlrtBCI, &st);
        }

        p_data[I - 1] = 2.0 + (real_T)J;
      }

      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    I++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
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
  /* 'path1:97' P(N)=p(N); */
  c_Trans = Local->size[1];
  i21 = Local->size[1];
  if (!((i21 >= 1) && (i21 <= b_Trans))) {
    emlrtDynamicBoundsCheckR2012b(i21, 1, b_Trans, &cf_emlrtBCI, &st);
  }

  b_Trans = Local->size[1];
  if (!((b_Trans >= 1) && (b_Trans <= c_Trans))) {
    emlrtDynamicBoundsCheckR2012b(b_Trans, 1, c_Trans, &df_emlrtBCI, &st);
  }

  P_data[b_Trans - 1] = p_data[i21 - 1];

  /* 'path1:99' for I=N-1:-1:1 */
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &pe_emlrtRTEI, &st);
  I = 0;
  while (I <= Local->size[1] - 2) {
    b_I = N - I;

    /* using this loop to get the path finally; from the last point going */
    /* 'path1:100' P(I)=PRED(P(I+1),I+1); */
    if (!((b_I >= 1) && (b_I <= P_size_idx_1))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, P_size_idx_1, &jf_emlrtBCI, &st);
    }

    i21 = (int32_T)P_data[b_I - 1];
    if (!((i21 >= 1) && (i21 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i21, 1, 4, &if_emlrtBCI, &st);
    }

    b_Trans = PRED->size[1];
    if (!((b_I >= 1) && (b_I <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, b_Trans, &kf_emlrtBCI, &st);
    }

    b_Trans = b_I - 1;
    if (!((b_Trans >= 1) && (b_Trans <= P_size_idx_1))) {
      emlrtDynamicBoundsCheckR2012b(b_Trans, 1, P_size_idx_1, &lf_emlrtBCI, &st);
    }

    P_data[b_Trans - 1] = PRED->data[(i21 + PRED->size[0] * (b_I - 1)) - 1];

    /* backward to find the previous points, etc; */
    I++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxFree_real_T(&PRED);
  emxFree_real_T(&Local);

  /* 'path1:102' PATH=P; */
  /* getting the final path.  */
  /*  Extract the final vocied F0 track which has the lowest cost */
  /*  At this point, VSpec_F0 is the spectral pitch track for voiced frames */
  /* 'dynamic5:62' FinPitch = zeros(1,numframes); */
  i21 = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, i21, (int32_T)sizeof
                    (real_T), &bc_emlrtRTEI);
  loop_ub = Pitch_array->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    FinPitch->data[i21] = 0.0;
  }

  /* 'dynamic5:63' for n=1:numframes */
  n = 1;
  while (n - 1 <= numframes) {
    /* 'dynamic5:64' FinPitch(n) = Pitch_array(Path(n), n); */
    if (!((n >= 1) && (n <= P_size_idx_1))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, P_size_idx_1, &ff_emlrtBCI, sp);
    }

    i21 = (int32_T)P_data[n - 1];
    if (!((i21 >= 1) && (i21 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i21, 1, 4, &ef_emlrtBCI, sp);
    }

    b_Trans = Pitch_array->size[1];
    if (!((n >= 1) && (n <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, b_Trans, &gf_emlrtBCI, sp);
    }

    b_Trans = FinPitch->size[1];
    if (!((n >= 1) && (n <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, b_Trans, &hf_emlrtBCI, sp);
    }

    FinPitch->data[n - 1] = Pitch_array->data[(i21 + Pitch_array->size[0] * (n -
      1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (dynamic5.c) */
