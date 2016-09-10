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
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo em_emlrtRSI = { 31, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRSInfo fm_emlrtRSI = { 34, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRSInfo gm_emlrtRSI = { 61, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo pd_emlrtRTEI = { 1, 17, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo qd_emlrtRTEI = { 38, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo rd_emlrtRTEI = { 40, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo sd_emlrtRTEI = { 42, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo td_emlrtRTEI = { 43, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 46, 22, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 74, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 75, 13, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtRTEInfo vg_emlrtRTEI = { 99, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 97, 6, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 97, 1, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 100, 14, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 100, 21, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 100, 4, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 72, 5, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 74, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 75, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 75, 31, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 69, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 69, 9, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 51, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 60, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 64, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 64, 33, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 64, 35, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 64, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 54, 16, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 54, 31, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 54, 33, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 54, 35, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 54, 39, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 55, 26, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 55, 41, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 55, 43, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 55, 45, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 55, 17, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 56, 22, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 56, 24, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 46, 20, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 46, 5, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

/* Function Definitions */

/*
 * function [PATH]=path1(Local,Trans)
 */
void path1(const emlrtStack *sp, const emxArray_real_T *Local, const
           emxArray_real_T *Trans, emxArray_real_T *PATH)
{
  int32_T N;
  int32_T M;
  int32_T i41;
  emxArray_real_T *PRED;
  const mxArray *y;
  char_T u[28];
  static const char_T varargin_1[28] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ',
    'M', '>', '1', '0', '0' };

  const mxArray *m9;
  static const int32_T iv44[2] = { 1, 28 };

  const mxArray *b_y;
  char_T b_u[29];
  static const char_T b_varargin_1[29] = { 'S', 't', 'o', 'p', ' ', 'i', 'n',
    ' ', 'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o',
    ' ', 'N', '>', '1', '0', '0', '0' };

  static const int32_T iv45[2] = { 1, 29 };

  int32_T loop_ub;
  emxArray_real_T *p;
  emxArray_real_T *PCOST;
  emxArray_real_T *CCOST;
  int32_T J;
  int32_T I;
  int32_T K;
  int32_T i42;
  const mxArray *c_y;
  char_T c_u[30];
  static const char_T c_varargin_1[30] = { 'C', 'C', 'O', 'S', 'T', '>', '1',
    '.', '0', 'E', '+', '5', '0', ',', ' ', 'S', 't', 'o', 'p', ' ', 'i', 'n',
    ' ', 'D', 'y', 'n', 'a', 'm', 'i', 'c' };

  static const int32_T iv46[2] = { 1, 30 };

  int32_T b_I;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
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
  /* 'path1:28' [M,N]=size(Local); */
  N = Local->size[1];
  M = Local->size[0] - 1;

  /* getting the size of the local matrix; */
  /* 'path1:30' if M>=500 */
  if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 0, Local->size[0] >= 500)) {
    /* if M is greater than 100, stop the routine; */
    st.site = &em_emlrtRSI;
    for (i41 = 0; i41 < 28; i41++) {
      u[i41] = varargin_1[i41];
    }

    y = NULL;
    m9 = emlrtCreateCharArray(2, iv44);
    emlrtInitCharArrayR2013a(&st, 28, m9, &u[0]);
    emlrtAssign(&y, m9);
    b_st.site = &fq_emlrtRSI;
    o_error(&b_st, y, &emlrtMCI);
  }

  /* 'path1:33' if N>=5000 */
  if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 1, Local->size[1] >= 5000)) {
    /* if N is greater than 1000, stop the routine; */
    st.site = &fm_emlrtRSI;
    for (i41 = 0; i41 < 29; i41++) {
      b_u[i41] = b_varargin_1[i41];
    }

    b_y = NULL;
    m9 = emlrtCreateCharArray(2, iv45);
    emlrtInitCharArrayR2013a(&st, 29, m9, &b_u[0]);
    emlrtAssign(&b_y, m9);
    b_st.site = &fq_emlrtRSI;
    o_error(&b_st, b_y, &emlrtMCI);
  }

  emxInit_real_T(sp, &PRED, 2, &qd_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 1);

  /* 'path1:38' PRED=ones(M,N); */
  i41 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = Local->size[0];
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)PRED, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  loop_ub = Local->size[0] * Local->size[1];
  for (i41 = 0; i41 < loop_ub; i41++) {
    PRED->data[i41] = 1.0;
  }

  /* initializing several desired matrix; */
  /* 'path1:39' P=ones(1,N); */
  i41 = PATH->size[0] * PATH->size[1];
  PATH->size[0] = 1;
  PATH->size[1] = Local->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)PATH, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  loop_ub = Local->size[1];
  for (i41 = 0; i41 < loop_ub; i41++) {
    PATH->data[i41] = 1.0;
  }

  emxInit_real_T(sp, &p, 2, &rd_emlrtRTEI, true);

  /* 'path1:40' p=zeros(1,N); */
  i41 = p->size[0] * p->size[1];
  p->size[0] = 1;
  p->size[1] = Local->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)p, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  loop_ub = Local->size[1];
  for (i41 = 0; i41 < loop_ub; i41++) {
    p->data[i41] = 0.0;
  }

  emxInit_real_T(sp, &PCOST, 2, &sd_emlrtRTEI, true);

  /* PATH=zeros(1,N); */
  /* 'path1:42' PCOST = zeros(1,M); */
  i41 = PCOST->size[0] * PCOST->size[1];
  PCOST->size[0] = 1;
  PCOST->size[1] = Local->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)PCOST, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  loop_ub = Local->size[0];
  for (i41 = 0; i41 < loop_ub; i41++) {
    PCOST->data[i41] = 0.0;
  }

  emxInit_real_T(sp, &CCOST, 2, &td_emlrtRTEI, true);

  /* 'path1:43' CCOST = zeros(1,M); */
  i41 = CCOST->size[0] * CCOST->size[1];
  CCOST->size[0] = 1;
  CCOST->size[1] = Local->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)CCOST, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  loop_ub = Local->size[0];
  for (i41 = 0; i41 < loop_ub; i41++) {
    CCOST->data[i41] = 0.0;
  }

  /* 'path1:45' for J=1:M */
  J = 1;
  while (J - 1 <= M) {
    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 2);

    /* initializing the previous costs; */
    /* 'path1:46' PCOST(J)=Local(J,1); */
    i41 = Local->size[1];
    if (!(1 <= i41)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i41, &ng_emlrtBCI, sp);
    }

    i41 = Local->size[0];
    if (!((J >= 1) && (J <= i41))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, i41, &vh_emlrtBCI, sp);
    }

    i41 = PCOST->size[1];
    if (!((J >= 1) && (J <= i41))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, i41, &wh_emlrtBCI, sp);
    }

    PCOST->data[J - 1] = Local->data[J - 1];
    J++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 0, 0);

  /* 'path1:49' for I=2:N */
  I = 2;
  while (I - 2 <= N - 2) {
    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 1, 1);

    /* this loop is doing the heart work of this routine. That means to */
    /* 'path1:50' for J=1:M */
    J = 1;
    while (J - 1 <= M) {
      covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 2, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 3);

      /* 'path1:51' CCOST(J)=1.0E+30; */
      i41 = CCOST->size[1];
      if (!((J >= 1) && (J <= i41))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i41, &dh_emlrtBCI, sp);
      }

      CCOST->data[J - 1] = 1.0E+30;

      /* get the lowest cost path; */
      /* 'path1:53' for K=1:M */
      K = 1;
      while (K - 1 <= M) {
        covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 3, 1);

        /* 'path1:54' if PCOST(K)+Trans(K,J,I)<=CCOST(J) */
        i41 = PCOST->size[1];
        if (!((K >= 1) && (K <= i41))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, i41, &jh_emlrtBCI, sp);
        }

        i41 = Trans->size[0];
        if (!((K >= 1) && (K <= i41))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, i41, &kh_emlrtBCI, sp);
        }

        i41 = Trans->size[1];
        if (!((J >= 1) && (J <= i41))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, i41, &lh_emlrtBCI, sp);
        }

        i41 = Trans->size[2];
        if (!((I >= 1) && (I <= i41))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i41, &mh_emlrtBCI, sp);
        }

        i41 = CCOST->size[1];
        if (!((J >= 1) && (J <= i41))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, i41, &nh_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 2, PCOST->data[K - 1] +
                       Trans->data[((K + Trans->size[0] * (J - 1)) + Trans->
              size[0] * Trans->size[1] * (I - 1)) - 1] <= CCOST->data[J - 1])) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 4);

          /* deciding the optimal path between two points in two next column;  */
          /* 'path1:55' CCOST(J)=PCOST(K)+Trans(K,J,I); */
          i41 = PCOST->size[1];
          if (!((K >= 1) && (K <= i41))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, i41, &oh_emlrtBCI, sp);
          }

          i41 = Trans->size[0];
          if (!((K >= 1) && (K <= i41))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, i41, &ph_emlrtBCI, sp);
          }

          i41 = Trans->size[1];
          if (!((J >= 1) && (J <= i41))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i41, &qh_emlrtBCI, sp);
          }

          i41 = Trans->size[2];
          if (!((I >= 1) && (I <= i41))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i41, &rh_emlrtBCI, sp);
          }

          i41 = CCOST->size[1];
          if (!((J >= 1) && (J <= i41))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i41, &sh_emlrtBCI, sp);
          }

          CCOST->data[J - 1] = PCOST->data[K - 1] + Trans->data[((K +
            Trans->size[0] * (J - 1)) + Trans->size[0] * Trans->size[1] * (I - 1))
            - 1];

          /* 'path1:56' PRED(J,I)=K; */
          i41 = PRED->size[0];
          if (!((J >= 1) && (J <= i41))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i41, &th_emlrtBCI, sp);
          }

          i41 = PRED->size[1];
          if (!((I >= 1) && (I <= i41))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i41, &uh_emlrtBCI, sp);
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

      /* 'path1:60' if CCOST(J)>=1.0E+30 */
      i41 = CCOST->size[1];
      if (!((J >= 1) && (J <= i41))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i41, &eh_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 3, CCOST->data[J - 1] >=
                     1.0E+30)) {
        st.site = &gm_emlrtRSI;
        for (i41 = 0; i41 < 30; i41++) {
          c_u[i41] = c_varargin_1[i41];
        }

        c_y = NULL;
        m9 = emlrtCreateCharArray(2, iv46);
        emlrtInitCharArrayR2013a(&st, 30, m9, &c_u[0]);
        emlrtAssign(&c_y, m9);
        b_st.site = &fq_emlrtRSI;
        o_error(&b_st, c_y, &emlrtMCI);
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 5);

      /* 'path1:64' CCOST(J)=CCOST(J)+Local(J,I); */
      i41 = CCOST->size[1];
      if (!((J >= 1) && (J <= i41))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i41, &fh_emlrtBCI, sp);
      }

      i41 = Local->size[0];
      if (!((J >= 1) && (J <= i41))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i41, &gh_emlrtBCI, sp);
      }

      i41 = Local->size[1];
      if (!((I >= 1) && (I <= i41))) {
        emlrtDynamicBoundsCheckR2012b(I, 1, i41, &hh_emlrtBCI, sp);
      }

      i41 = CCOST->size[1];
      if (!((J >= 1) && (J <= i41))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i41, &ih_emlrtBCI, sp);
      }

      CCOST->data[J - 1] += Local->data[(J + Local->size[0] * (I - 1)) - 1];

      /* new cost is gotten by the adding of Local cost and current cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 2, 0);

    /* 'path1:68' for J=1:M */
    J = 1;
    while (J - 1 <= M) {
      covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 4, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 6);

      /* 'path1:69' PCOST(J)=CCOST(J); */
      i41 = CCOST->size[1];
      if (!((J >= 1) && (J <= i41))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i41, &bh_emlrtBCI, sp);
      }

      i41 = PCOST->size[1];
      if (!((J >= 1) && (J <= i41))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i41, &ch_emlrtBCI, sp);
      }

      PCOST->data[J - 1] = CCOST->data[J - 1];

      /* using the new current cost to update the previous cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 7);

    /* 'path1:72' p(I)=1; */
    i41 = p->size[1];
    if (!((I >= 1) && (I <= i41))) {
      emlrtDynamicBoundsCheckR2012b(I, 1, i41, &wg_emlrtBCI, sp);
    }

    p->data[I - 1] = 1.0;

    /* 'path1:73' for J=2:M */
    J = 0;
    while (J <= M - 1) {
      covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 5, 1);

      /* obtaining the points with lowest cost in every column; */
      /* 'path1:74' if CCOST(J)<=CCOST(1) */
      i41 = CCOST->size[1];
      if (!(1 <= i41)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i41, &og_emlrtBCI, sp);
      }

      i41 = CCOST->size[1];
      if (!((J + 2 >= 1) && (J + 2 <= i41))) {
        emlrtDynamicBoundsCheckR2012b(J + 2, 1, i41, &xg_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 4, CCOST->data[J + 1] <=
                     CCOST->data[0])) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 8);

        /* 'path1:75' CCOST(1)=CCOST(J); */
        i41 = CCOST->size[1];
        if (!(1 <= i41)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i41, &pg_emlrtBCI, sp);
        }

        i41 = CCOST->size[1];
        if (!((J + 2 >= 1) && (J + 2 <= i41))) {
          emlrtDynamicBoundsCheckR2012b(J + 2, 1, i41, &yg_emlrtBCI, sp);
        }

        CCOST->data[0] = CCOST->data[J + 1];

        /* 'path1:75' p(I)=J; */
        i41 = p->size[1];
        if (!((I >= 1) && (I <= i41))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i41, &ah_emlrtBCI, sp);
        }

        p->data[I - 1] = 2.0 + (real_T)J;
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

  emxFree_real_T(&CCOST);
  emxFree_real_T(&PCOST);
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
  /* 'path1:97' P(N)=p(N); */
  loop_ub = Local->size[1];
  i41 = p->size[1];
  i42 = Local->size[1];
  if (!((i42 >= 1) && (i42 <= i41))) {
    emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &qg_emlrtBCI, sp);
  }

  i41 = Local->size[1];
  if (!((i41 >= 1) && (i41 <= loop_ub))) {
    emlrtDynamicBoundsCheckR2012b(i41, 1, loop_ub, &rg_emlrtBCI, sp);
  }

  PATH->data[i41 - 1] = p->data[i42 - 1];

  /* 'path1:99' for I=N-1:-1:1 */
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &vg_emlrtRTEI, sp);
  I = 0;
  emxFree_real_T(&p);
  while (I <= Local->size[1] - 2) {
    b_I = N - I;
    covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 6, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 10);

    /* using this loop to get the path finally; from the last point going */
    /* 'path1:100' P(I)=PRED(P(I+1),I+1); */
    i41 = PRED->size[0];
    i42 = PATH->size[1];
    if (!((b_I >= 1) && (b_I <= i42))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, i42, &tg_emlrtBCI, sp);
    }

    i42 = (int32_T)PATH->data[b_I - 1];
    if (!((i42 >= 1) && (i42 <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &sg_emlrtBCI, sp);
    }

    i41 = PRED->size[1];
    if (!((b_I >= 1) && (b_I <= i41))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, i41, &ug_emlrtBCI, sp);
    }

    i41 = PATH->size[1];
    loop_ub = b_I - 1;
    if (!((loop_ub >= 1) && (loop_ub <= i41))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i41, &vg_emlrtBCI, sp);
    }

    PATH->data[loop_ub - 1] = PRED->data[(i42 + PRED->size[0] * (b_I - 1)) - 1];

    /* backward to find the previous points, etc; */
    I++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&PRED);
  covrtLogFor(&emlrtCoverageInstance, 15U, 0U, 6, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 11);

  /* 'path1:102' PATH=P; */
  /* getting the final path.  */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (path1.c) */
