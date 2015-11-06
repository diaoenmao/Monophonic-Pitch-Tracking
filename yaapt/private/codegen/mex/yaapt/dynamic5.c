/*
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

/* Variable Definitions */
static emlrtRSInfo mg_emlrtRSI = { 58, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo gc_emlrtRTEI = { 1, 23, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo hc_emlrtRTEI = { 37, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo ic_emlrtRTEI = { 40, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 49, 59, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 48, 67, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 48, 48, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 64, 5, "FinPitch", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { 1, 4, 64, 31, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 64, 31, "Path", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 64, 40, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { 1, 4, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 48, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 49, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 49, 44, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

/* Function Definitions */

/*
 * function [FinPitch] = dynamic5(Pitch_array, Merit_array, k1)
 */
void dynamic5(const emlrtStack *sp, const emxArray_real_T *Pitch_array, const
              emxArray_real_T *Merit_array, real_T k1, emxArray_real_T *FinPitch)
{
  emxArray_real_T *Local;
  int32_T i23;
  int32_T loop_ub;
  emxArray_real_T *Trans;
  int32_T i;
  int32_T b_Trans;
  int32_T i24;
  int32_T i25;
  int32_T unnamed_idx_1;
  emxArray_real_T *PRED;
  int32_T b_unnamed_idx_1;
  real_T P_data[4999];
  real_T p_data[4999];
  real_T CCOST[4];
  real_T PCOST[4];
  real_T b_CCOST;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Local, 2, &hc_emlrtRTEI, true);

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
  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* forming the local cost matrix */
  /* 'dynamic5:37' Local = 1 - Merit_array; */
  i23 = Local->size[0] * Local->size[1];
  Local->size[0] = 4;
  Local->size[1] = Merit_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Local, i23, (int32_T)sizeof(real_T),
                    &gc_emlrtRTEI);
  loop_ub = Merit_array->size[0] * Merit_array->size[1];
  for (i23 = 0; i23 < loop_ub; i23++) {
    Local->data[i23] = 1.0 - Merit_array->data[i23];
  }

  c_emxInit_real_T(sp, &Trans, 3, &ic_emlrtRTEI, true);

  /* initialization for the formation of the transition cost matrix */
  /* 'dynamic5:40' Trans  = zeros(numcands, numcands, numframes); */
  i23 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = 4;
  Trans->size[1] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i23, (int32_T)sizeof(real_T),
                    &gc_emlrtRTEI);
  loop_ub = Pitch_array->size[1];
  i23 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[2] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i23, (int32_T)sizeof(real_T),
                    &gc_emlrtRTEI);
  loop_ub = 16 * Pitch_array->size[1];
  for (i23 = 0; i23 < loop_ub; i23++) {
    Trans->data[i23] = 0.0;
  }

  /* the transition cost matrix is proportional to frequency differences */
  /* between successive candidates. */
  /* 'dynamic5:45' for i = 2:numframes */
  i = 0;
  while (i <= Pitch_array->size[1] - 2) {
    /* 'dynamic5:46' for j = 1:numcands */
    for (b_Trans = 0; b_Trans < 4; b_Trans++) {
      /* 'dynamic5:47' for k = 1:numcands */
      for (loop_ub = 0; loop_ub < 4; loop_ub++) {
        /* 'dynamic5:48' Trans(k,j,i)  = (abs(Pitch_array(j,i) - Pitch_array(k,i-1)))/ F0_min ; */
        i23 = Pitch_array->size[1];
        i24 = (int32_T)(2.0 + (real_T)i);
        emlrtDynamicBoundsCheckFastR2012b(i24, 1, i23, &bf_emlrtBCI, sp);
        i23 = Pitch_array->size[1];
        i24 = (int32_T)((2.0 + (real_T)i) - 1.0);
        emlrtDynamicBoundsCheckFastR2012b(i24, 1, i23, &af_emlrtBCI, sp);
        i23 = Trans->size[2];
        i24 = 2 + i;
        Trans->data[(loop_ub + Trans->size[0] * b_Trans) + Trans->size[0] *
          Trans->size[1] * (emlrtDynamicBoundsCheckFastR2012b(i24, 1, i23,
          &sf_emlrtBCI, sp) - 1)] = muDoubleScalarAbs(Pitch_array->data[b_Trans
          + Pitch_array->size[0] * (i + 1)] - Pitch_array->data[loop_ub +
          Pitch_array->size[0] * i]) / 60.0;

        /* 'dynamic5:49' Trans(k,j,i) =  0.05*Trans(k,j,i) + Trans(k,j,i)^2; */
        i23 = Trans->size[2];
        i24 = (int32_T)(2.0 + (real_T)i);
        emlrtDynamicBoundsCheckFastR2012b(i24, 1, i23, &ye_emlrtBCI, sp);
        i23 = Trans->size[2];
        i24 = 2 + i;
        i25 = Trans->size[2];
        unnamed_idx_1 = 2 + i;
        Trans->data[(loop_ub + Trans->size[0] * b_Trans) + Trans->size[0] *
          Trans->size[1] * (emlrtDynamicBoundsCheckFastR2012b(i24, 1, i23,
          &tf_emlrtBCI, sp) - 1)] = 0.05 * Trans->data[(loop_ub + Trans->size[0]
          * b_Trans) + Trans->size[0] * Trans->size[1] *
          (emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_1, 1, i25, &uf_emlrtBCI,
            sp) - 1)] + Trans->data[(loop_ub + Trans->size[0] * b_Trans) +
          Trans->size[0] * Trans->size[1] * (i + 1)] * Trans->data[(loop_ub +
          Trans->size[0] * b_Trans) + Trans->size[0] * Trans->size[1] * (i + 1)];
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
      }

      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  /*  Overal balance between Local and Transition costs */
  /* 'dynamic5:55' Trans = k1 * Trans; */
  i23 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = 4;
  Trans->size[1] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i23, (int32_T)sizeof(real_T),
                    &gc_emlrtRTEI);
  loop_ub = Trans->size[0];
  i = Trans->size[1];
  b_Trans = Trans->size[2];
  loop_ub = loop_ub * i * b_Trans;
  for (i23 = 0; i23 < loop_ub; i23++) {
    Trans->data[i23] *= k1;
  }

  /*  search the best path */
  /* 'dynamic5:58' Path = path1(Local, Trans); */
  st.site = &mg_emlrtRSI;

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
  /* getting the size of the local matrix; */
  /* 'path1:30' if M>=500 */
  /* 'path1:33' if N>=5000 */
  if (Local->size[1] >= 5000) {
    /* if N is greater than 1000, stop the routine; */
    b_st.site = &ng_emlrtRSI;
    c_error(&b_st);
  }

  emxInit_real_T(&st, &PRED, 2, &jc_emlrtRTEI, true);

  /* 'path1:38' PRED=ones(M,N); */
  i23 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = 4;
  emxEnsureCapacity(&st, (emxArray__common *)PRED, i23, (int32_T)sizeof(real_T),
                    &gc_emlrtRTEI);
  b_unnamed_idx_1 = Local->size[1];
  i23 = PRED->size[0] * PRED->size[1];
  PRED->size[1] = b_unnamed_idx_1;
  emxEnsureCapacity(&st, (emxArray__common *)PRED, i23, (int32_T)sizeof(real_T),
                    &gc_emlrtRTEI);
  loop_ub = Local->size[1] << 2;
  for (i23 = 0; i23 < loop_ub; i23++) {
    PRED->data[i23] = 1.0;
  }

  /* initializing several desired matrix; */
  /* 'path1:39' P=ones(1,N); */
  b_unnamed_idx_1 = Local->size[1];
  loop_ub = Local->size[1];
  for (i23 = 0; i23 < loop_ub; i23++) {
    P_data[i23] = 1.0;
  }

  /* 'path1:40' p=zeros(1,N); */
  unnamed_idx_1 = Local->size[1];
  loop_ub = Local->size[1];
  for (i23 = 0; i23 < loop_ub; i23++) {
    p_data[i23] = 0.0;
  }

  /* PATH=zeros(1,N); */
  /* 'path1:42' PCOST = zeros(1,M); */
  /* 'path1:43' CCOST = zeros(1,M); */
  for (i23 = 0; i23 < 4; i23++) {
    CCOST[i23] = 0.0;
  }

  /* 'path1:45' for J=1:M */
  for (i = 0; i < 4; i++) {
    /* initializing the previous costs; */
    /* 'path1:46' PCOST(J)=Local(J,1); */
    i23 = Local->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i23, &xe_emlrtBCI, &st);
    PCOST[i] = Local->data[i];
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
  }

  /* 'path1:49' for I=2:N */
  loop_ub = 2;
  while (loop_ub - 2 <= Local->size[1] - 2) {
    /* this loop is doing the heart work of this routine. That means to */
    /* 'path1:50' for J=1:M */
    for (i = 0; i < 4; i++) {
      /* 'path1:51' CCOST(J)=1.0E+30; */
      CCOST[i] = 1.0E+30;

      /* get the lowest cost path; */
      /* 'path1:53' for K=1:M */
      for (b_Trans = 0; b_Trans < 4; b_Trans++) {
        b_CCOST = CCOST[i];

        /* 'path1:54' if PCOST(K)+Trans(K,J,I)<=CCOST(J) */
        i23 = Trans->size[2];
        if (PCOST[b_Trans] + Trans->data[(b_Trans + Trans->size[0] * i) +
            Trans->size[0] * Trans->size[1] * (emlrtDynamicBoundsCheckFastR2012b
             (loop_ub, 1, i23, &pf_emlrtBCI, &st) - 1)] <= CCOST[i]) {
          /* deciding the optimal path between two points in two next column;  */
          /* 'path1:55' CCOST(J)=PCOST(K)+Trans(K,J,I); */
          i23 = Trans->size[2];
          b_CCOST = PCOST[b_Trans] + Trans->data[(b_Trans + Trans->size[0] * i)
            + Trans->size[0] * Trans->size[1] *
            (emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i23, &qf_emlrtBCI,
              &st) - 1)];

          /* 'path1:56' PRED(J,I)=K; */
          i23 = PRED->size[1];
          PRED->data[i + PRED->size[0] * (emlrtDynamicBoundsCheckFastR2012b
            (loop_ub, 1, i23, &rf_emlrtBCI, &st) - 1)] = 1.0 + (real_T)b_Trans;

          /* this line is very importent, used to mark the chosen points; */
        }

        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
        CCOST[i] = b_CCOST;
      }

      /* 'path1:60' if CCOST(J)>=1.0E+30 */
      if (CCOST[i] >= 1.0E+30) {
        b_st.site = &og_emlrtRSI;
        d_error(&b_st);
      }

      /* 'path1:64' CCOST(J)=CCOST(J)+Local(J,I); */
      i23 = Local->size[1];
      CCOST[i] += Local->data[i + Local->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i23, &of_emlrtBCI, &st) -
         1)];

      /* new cost is gotten by the adding of Local cost and current cost; */
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
    }

    /* 'path1:68' for J=1:M */
    for (i = 0; i < 4; i++) {
      /* 'path1:69' PCOST(J)=CCOST(J); */
      PCOST[i] = CCOST[i];

      /* using the new current cost to update the previous cost; */
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
    }

    /* 'path1:72' p(I)=1; */
    p_data[emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, unnamed_idx_1,
      &mf_emlrtBCI, &st) - 1] = 1.0;

    /* 'path1:73' for J=2:M */
    for (i = 0; i < 3; i++) {
      /* obtaining the points with lowest cost in every column; */
      /* 'path1:74' if CCOST(J)<=CCOST(1) */
      if (CCOST[i + 1] <= CCOST[0]) {
        /* 'path1:75' CCOST(1)=CCOST(J); */
        CCOST[0] = CCOST[i + 1];

        /* 'path1:75' p(I)=J; */
        p_data[emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, unnamed_idx_1,
          &nf_emlrtBCI, &st) - 1] = 2.0 + (real_T)i;
      }

      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
    }

    loop_ub++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
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
  i = Local->size[1];
  i23 = Local->size[1];
  i24 = Local->size[1];
  P_data[emlrtDynamicBoundsCheckFastR2012b(i23, 1, i, &cf_emlrtBCI, &st) - 1] =
    p_data[emlrtDynamicBoundsCheckFastR2012b(i24, 1, unnamed_idx_1, &df_emlrtBCI,
    &st) - 1];

  /* 'path1:99' for I=N-1:-1:1 */
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &ud_emlrtRTEI, &st);
  loop_ub = 0;
  while (loop_ub <= Local->size[1] - 2) {
    i = Local->size[1] - loop_ub;

    /* using this loop to get the path finally; from the last point going */
    /* 'path1:100' P(I)=PRED(P(I+1),I+1); */
    i23 = i - 1;
    i24 = (int32_T)P_data[emlrtDynamicBoundsCheckFastR2012b(i, 1,
      b_unnamed_idx_1, &kf_emlrtBCI, &st) - 1];
    i25 = PRED->size[1];
    P_data[emlrtDynamicBoundsCheckFastR2012b(i23, 1, b_unnamed_idx_1,
      &if_emlrtBCI, &st) - 1] = PRED->data[(emlrtDynamicBoundsCheckFastR2012b
      (i24, 1, 4, &jf_emlrtBCI, &st) + PRED->size[0] *
      (emlrtDynamicBoundsCheckFastR2012b(i, 1, i25, &lf_emlrtBCI, &st) - 1)) - 1];

    /* backward to find the previous points, etc; */
    loop_ub++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
  }

  emxFree_real_T(&PRED);
  emxFree_real_T(&Local);

  /* 'path1:102' PATH=P; */
  /* getting the final path.  */
  /*  Extract the final vocied F0 track which has the lowest cost */
  /*  At this point, VSpec_F0 is the spectral pitch track for voiced frames */
  /* 'dynamic5:62' FinPitch = zeros(1,numframes); */
  i23 = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, i23, (int32_T)sizeof
                    (real_T), &gc_emlrtRTEI);
  unnamed_idx_1 = Pitch_array->size[1];
  i23 = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[1] = unnamed_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, i23, (int32_T)sizeof
                    (real_T), &gc_emlrtRTEI);
  loop_ub = Pitch_array->size[1];
  for (i23 = 0; i23 < loop_ub; i23++) {
    FinPitch->data[i23] = 0.0;
  }

  /* 'dynamic5:63' for n=1:numframes */
  i = 1;
  while (i - 1 <= Pitch_array->size[1] - 1) {
    /* 'dynamic5:64' FinPitch(n) = Pitch_array(Path(n), n); */
    i23 = FinPitch->size[1];
    i24 = (int32_T)P_data[emlrtDynamicBoundsCheckFastR2012b(i, 1,
      b_unnamed_idx_1, &gf_emlrtBCI, sp) - 1];
    i25 = Pitch_array->size[1];
    FinPitch->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i23, &ef_emlrtBCI, sp)
      - 1] = Pitch_array->data[(emlrtDynamicBoundsCheckFastR2012b(i24, 1, 4,
      &ff_emlrtBCI, sp) + Pitch_array->size[0] *
      (emlrtDynamicBoundsCheckFastR2012b(i, 1, i25, &hf_emlrtBCI, sp) - 1)) - 1];
    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (dynamic5.c) */
