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
#include "mpower.h"
#include "yaapt_emxutil.h"
#include "nonlinear.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ai_emlrtRSI = { 49, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRSInfo bi_emlrtRSI = { 58, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo bc_emlrtRTEI = { 1, 23, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo cc_emlrtRTEI = { 37, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo dc_emlrtRTEI = { 40, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 48, 67, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 48, 48, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { 1, 4, 64, 31, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 64, 31, "Path", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 64, 40, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 64, 5, "FinPitch", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { 1, 4, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 48, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 49, 44, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 49, 59, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 49, 23, "Trans", "dynamic5",
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
  int32_T Trans;
  int32_T loop_ub;
  emxArray_real_T *b_Trans;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T c_Trans;
  int32_T N;
  static const char_T varargin_1[29] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ',
    'N', '>', '1', '0', '0', '0' };

  char_T u[29];
  const mxArray *y;
  static const int32_T iv23[2] = { 1, 29 };

  const mxArray *m6;
  emxArray_real_T *PRED;
  emxArray_real_T *P;
  emxArray_real_T *p;
  real_T PCOST[4];
  real_T CCOST[4];
  int32_T J;
  int32_T I;
  int32_T K;
  static const char_T b_varargin_1[30] = { 'C', 'C', 'O', 'S', 'T', '>', '1',
    '.', '0', 'E', '+', '5', '0', ',', ' ', 'S', 't', 'o', 'p', ' ', 'i', 'n',
    ' ', 'D', 'y', 'n', 'a', 'm', 'i', 'c' };

  char_T b_u[30];
  const mxArray *b_y;
  static const int32_T iv24[2] = { 1, 30 };

  int32_T b_I;
  int32_T n;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
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
  Trans = Local->size[0] * Local->size[1];
  Local->size[0] = 4;
  Local->size[1] = Merit_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Local, Trans, (int32_T)sizeof(real_T),
                    &bc_emlrtRTEI);
  loop_ub = Merit_array->size[0] * Merit_array->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    Local->data[Trans] = 1.0 - Merit_array->data[Trans];
  }

  emxInit_real_T2(sp, &b_Trans, 3, &dc_emlrtRTEI, true);

  /* initialization for the formation of the transition cost matrix */
  /* 'dynamic5:40' Trans  = zeros(numcands, numcands, numframes); */
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[0] = 4;
  b_Trans->size[1] = 4;
  b_Trans->size[2] = Pitch_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Trans, Trans, (int32_T)sizeof
                    (real_T), &bc_emlrtRTEI);
  loop_ub = 16 * Pitch_array->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] = 0.0;
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
        Trans = Pitch_array->size[1];
        c_Trans = (int32_T)(2.0 + (real_T)i);
        if (!((c_Trans >= 1) && (c_Trans <= Trans))) {
          emlrtDynamicBoundsCheckR2012b(c_Trans, 1, Trans, &ud_emlrtBCI, sp);
        }

        Trans = Pitch_array->size[1];
        c_Trans = (int32_T)((2.0 + (real_T)i) - 1.0);
        if (!((c_Trans >= 1) && (c_Trans <= Trans))) {
          emlrtDynamicBoundsCheckR2012b(c_Trans, 1, Trans, &td_emlrtBCI, sp);
        }

        Trans = b_Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, Trans, &me_emlrtBCI, sp);
        }

        b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
          b_Trans->size[1] * (i + 1)] = muDoubleScalarAbs(Pitch_array->data[j +
          Pitch_array->size[0] * (i + 1)] - Pitch_array->data[k +
          Pitch_array->size[0] * i]) / 60.0;

        /* 'dynamic5:49' Trans(k,j,i) =  0.05*Trans(k,j,i) + Trans(k,j,i)^2; */
        Trans = b_Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, Trans, &ne_emlrtBCI, sp);
        }

        Trans = b_Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, Trans, &oe_emlrtBCI, sp);
        }

        Trans = b_Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, Trans, &pe_emlrtBCI, sp);
        }

        st.site = &ai_emlrtRSI;
        b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
          b_Trans->size[1] * (i + 1)] = 0.05 * b_Trans->data[(k + b_Trans->size
          [0] * j) + b_Trans->size[0] * b_Trans->size[1] * (i + 1)] + mpower
          (b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
           b_Trans->size[1] * (i + 1)]);
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
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[0] = 4;
  b_Trans->size[1] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)b_Trans, Trans, (int32_T)sizeof
                    (real_T), &bc_emlrtRTEI);
  loop_ub = b_Trans->size[0];
  c_Trans = b_Trans->size[1];
  Trans = b_Trans->size[2];
  loop_ub = loop_ub * c_Trans * Trans;
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] *= k1;
  }

  /*  search the best path */
  /* 'dynamic5:58' Path = path1(Local, Trans); */
  st.site = &bi_emlrtRSI;

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
    b_st.site = &ci_emlrtRSI;
    for (Trans = 0; Trans < 29; Trans++) {
      u[Trans] = varargin_1[Trans];
    }

    y = NULL;
    m6 = emlrtCreateCharArray(2, iv23);
    emlrtInitCharArrayR2013a(&b_st, 29, m6, &u[0]);
    emlrtAssign(&y, m6);
    c_st.site = &nm_emlrtRSI;
    n_error(&c_st, y, &emlrtMCI);
  }

  emxInit_real_T(&st, &PRED, 2, &ec_emlrtRTEI, true);

  /* 'path1:38' PRED=ones(M,N); */
  Trans = PRED->size[0] * PRED->size[1];
  PRED->size[0] = 4;
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)PRED, Trans, (int32_T)sizeof(real_T),
                    &bc_emlrtRTEI);
  loop_ub = Local->size[1] << 2;
  for (Trans = 0; Trans < loop_ub; Trans++) {
    PRED->data[Trans] = 1.0;
  }

  emxInit_real_T(&st, &P, 2, &fc_emlrtRTEI, true);

  /* initializing several desired matrix; */
  /* 'path1:39' P=ones(1,N); */
  Trans = P->size[0] * P->size[1];
  P->size[0] = 1;
  P->size[1] = Local->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)P, Trans, (int32_T)sizeof(real_T),
                    &bc_emlrtRTEI);
  loop_ub = Local->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    P->data[Trans] = 1.0;
  }

  emxInit_real_T(&st, &p, 2, &gc_emlrtRTEI, true);

  /* 'path1:40' p=zeros(1,N); */
  Trans = p->size[0] * p->size[1];
  p->size[0] = 1;
  p->size[1] = Local->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)p, Trans, (int32_T)sizeof(real_T),
                    &bc_emlrtRTEI);
  loop_ub = Local->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    p->data[Trans] = 0.0;
  }

  /* PATH=zeros(1,N); */
  /* 'path1:42' PCOST = zeros(1,M); */
  /* 'path1:43' CCOST = zeros(1,M); */
  for (Trans = 0; Trans < 4; Trans++) {
    PCOST[Trans] = 0.0;
    CCOST[Trans] = 0.0;
  }

  /* 'path1:45' for J=1:M */
  J = 0;
  while (J < 4) {
    /* initializing the previous costs; */
    /* 'path1:46' PCOST(J)=Local(J,1); */
    Trans = Local->size[1];
    if (!(1 <= Trans)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Trans, &sd_emlrtBCI, &st);
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
        Trans = b_Trans->size[2];
        if (!((I >= 1) && (I <= Trans))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, Trans, &je_emlrtBCI, &st);
        }

        if (PCOST[K] + b_Trans->data[(K + b_Trans->size[0] * J) + b_Trans->size
            [0] * b_Trans->size[1] * (I - 1)] <= CCOST[J]) {
          /* deciding the optimal path between two points in two next column;  */
          /* 'path1:55' CCOST(J)=PCOST(K)+Trans(K,J,I); */
          Trans = b_Trans->size[2];
          if (!((I >= 1) && (I <= Trans))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, Trans, &ke_emlrtBCI, &st);
          }

          CCOST[J] = PCOST[K] + b_Trans->data[(K + b_Trans->size[0] * J) +
            b_Trans->size[0] * b_Trans->size[1] * (I - 1)];

          /* 'path1:56' PRED(J,I)=K; */
          Trans = PRED->size[1];
          if (!((I >= 1) && (I <= Trans))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, Trans, &le_emlrtBCI, &st);
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
        b_st.site = &di_emlrtRSI;
        for (Trans = 0; Trans < 30; Trans++) {
          b_u[Trans] = b_varargin_1[Trans];
        }

        b_y = NULL;
        m6 = emlrtCreateCharArray(2, iv24);
        emlrtInitCharArrayR2013a(&b_st, 30, m6, &b_u[0]);
        emlrtAssign(&b_y, m6);
        c_st.site = &nm_emlrtRSI;
        n_error(&c_st, b_y, &emlrtMCI);
      }

      /* 'path1:64' CCOST(J)=CCOST(J)+Local(J,I); */
      Trans = Local->size[1];
      if (!((I >= 1) && (I <= Trans))) {
        emlrtDynamicBoundsCheckR2012b(I, 1, Trans, &ie_emlrtBCI, &st);
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
    Trans = p->size[1];
    if (!((I >= 1) && (I <= Trans))) {
      emlrtDynamicBoundsCheckR2012b(I, 1, Trans, &ge_emlrtBCI, &st);
    }

    p->data[I - 1] = 1.0;

    /* 'path1:73' for J=2:M */
    J = 0;
    while (J < 3) {
      /* obtaining the points with lowest cost in every column; */
      /* 'path1:74' if CCOST(J)<=CCOST(1) */
      if (CCOST[J + 1] <= CCOST[0]) {
        /* 'path1:75' CCOST(1)=CCOST(J); */
        CCOST[0] = CCOST[J + 1];

        /* 'path1:75' p(I)=J; */
        Trans = p->size[1];
        if (!((I >= 1) && (I <= Trans))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, Trans, &he_emlrtBCI, &st);
        }

        p->data[I - 1] = 2.0 + (real_T)J;
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
  /* 'path1:97' P(N)=p(N); */
  loop_ub = Local->size[1];
  Trans = p->size[1];
  c_Trans = Local->size[1];
  if (!((c_Trans >= 1) && (c_Trans <= Trans))) {
    emlrtDynamicBoundsCheckR2012b(c_Trans, 1, Trans, &vd_emlrtBCI, &st);
  }

  Trans = Local->size[1];
  if (!((Trans >= 1) && (Trans <= loop_ub))) {
    emlrtDynamicBoundsCheckR2012b(Trans, 1, loop_ub, &wd_emlrtBCI, &st);
  }

  P->data[Trans - 1] = p->data[c_Trans - 1];

  /* 'path1:99' for I=N-1:-1:1 */
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &bf_emlrtRTEI, &st);
  I = 0;
  emxFree_real_T(&p);
  while (I <= Local->size[1] - 2) {
    b_I = N - I;

    /* using this loop to get the path finally; from the last point going */
    /* 'path1:100' P(I)=PRED(P(I+1),I+1); */
    Trans = P->size[1];
    if (!((b_I >= 1) && (b_I <= Trans))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, Trans, &de_emlrtBCI, &st);
    }

    Trans = (int32_T)P->data[b_I - 1];
    if (!((Trans >= 1) && (Trans <= 4))) {
      emlrtDynamicBoundsCheckR2012b(Trans, 1, 4, &ce_emlrtBCI, &st);
    }

    c_Trans = PRED->size[1];
    if (!((b_I >= 1) && (b_I <= c_Trans))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, c_Trans, &ee_emlrtBCI, &st);
    }

    c_Trans = P->size[1];
    loop_ub = b_I - 1;
    if (!((loop_ub >= 1) && (loop_ub <= c_Trans))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_Trans, &fe_emlrtBCI, &st);
    }

    P->data[loop_ub - 1] = PRED->data[(Trans + PRED->size[0] * (b_I - 1)) - 1];

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
  Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, Trans, (int32_T)sizeof
                    (real_T), &bc_emlrtRTEI);
  loop_ub = Pitch_array->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    FinPitch->data[Trans] = 0.0;
  }

  /* 'dynamic5:63' for n=1:numframes */
  n = 1;
  while (n - 1 <= numframes) {
    /* 'dynamic5:64' FinPitch(n) = Pitch_array(Path(n), n); */
    Trans = P->size[1];
    if (!((n >= 1) && (n <= Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, Trans, &yd_emlrtBCI, sp);
    }

    Trans = (int32_T)P->data[n - 1];
    if (!((Trans >= 1) && (Trans <= 4))) {
      emlrtDynamicBoundsCheckR2012b(Trans, 1, 4, &xd_emlrtBCI, sp);
    }

    c_Trans = Pitch_array->size[1];
    if (!((n >= 1) && (n <= c_Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, c_Trans, &ae_emlrtBCI, sp);
    }

    c_Trans = FinPitch->size[1];
    if (!((n >= 1) && (n <= c_Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, c_Trans, &be_emlrtBCI, sp);
    }

    FinPitch->data[n - 1] = Pitch_array->data[(Trans + Pitch_array->size[0] * (n
      - 1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&P);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (dynamic5.c) */
