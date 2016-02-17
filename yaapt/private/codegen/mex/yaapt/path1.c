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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo lk_emlrtRSI = { 31, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRSInfo mk_emlrtRSI = { 34, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRSInfo nk_emlrtRSI = { 61, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo fd_emlrtRTEI = { 1, 17, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo gd_emlrtRTEI = { 38, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo hd_emlrtRTEI = { 40, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo id_emlrtRTEI = { 42, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo jd_emlrtRTEI = { 43, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 46, 22, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 74, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 75, 13, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtRTEInfo kg_emlrtRTEI = { 99, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 97, 6, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 97, 1, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 100, 14, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 100, 21, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 100, 4, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 72, 5, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 74, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 75, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 75, 31, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 69, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 69, 9, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 51, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 60, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 64, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 64, 33, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 64, 35, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 64, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 54, 16, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 54, 31, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 54, 33, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 54, 35, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 54, 39, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 55, 26, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 55, 41, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 55, 43, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 55, 45, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 55, 17, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 56, 22, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 56, 24, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 46, 20, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 46, 5, "PCOST", "path1",
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
  int32_T i36;
  static const char_T varargin_1[28] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ',
    'M', '>', '1', '0', '0' };

  char_T u[28];
  const mxArray *y;
  static const int32_T iv44[2] = { 1, 28 };

  const mxArray *m9;
  static const char_T b_varargin_1[29] = { 'S', 't', 'o', 'p', ' ', 'i', 'n',
    ' ', 'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o',
    ' ', 'N', '>', '1', '0', '0', '0' };

  char_T b_u[29];
  const mxArray *b_y;
  static const int32_T iv45[2] = { 1, 29 };

  emxArray_real_T *PRED;
  int32_T loop_ub;
  emxArray_real_T *p;
  emxArray_real_T *PCOST;
  emxArray_real_T *CCOST;
  int32_T J;
  int32_T I;
  int32_T K;
  static const char_T c_varargin_1[30] = { 'C', 'C', 'O', 'S', 'T', '>', '1',
    '.', '0', 'E', '+', '5', '0', ',', ' ', 'S', 't', 'o', 'p', ' ', 'i', 'n',
    ' ', 'D', 'y', 'n', 'a', 'm', 'i', 'c' };

  char_T c_u[30];
  const mxArray *c_y;
  static const int32_T iv46[2] = { 1, 30 };

  int32_T i37;
  int32_T b_I;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

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
  if (Local->size[0] >= 500) {
    /* if M is greater than 100, stop the routine; */
    st.site = &lk_emlrtRSI;
    for (i36 = 0; i36 < 28; i36++) {
      u[i36] = varargin_1[i36];
    }

    y = NULL;
    m9 = emlrtCreateCharArray(2, iv44);
    emlrtInitCharArrayR2013a(&st, 28, m9, &u[0]);
    emlrtAssign(&y, m9);
    b_st.site = &ho_emlrtRSI;
    n_error(&b_st, y, &emlrtMCI);
  }

  /* 'path1:33' if N>=5000 */
  if (Local->size[1] >= 5000) {
    /* if N is greater than 1000, stop the routine; */
    st.site = &mk_emlrtRSI;
    for (i36 = 0; i36 < 29; i36++) {
      b_u[i36] = b_varargin_1[i36];
    }

    b_y = NULL;
    m9 = emlrtCreateCharArray(2, iv45);
    emlrtInitCharArrayR2013a(&st, 29, m9, &b_u[0]);
    emlrtAssign(&b_y, m9);
    b_st.site = &ho_emlrtRSI;
    n_error(&b_st, b_y, &emlrtMCI);
  }

  emxInit_real_T(sp, &PRED, 2, &gd_emlrtRTEI, true);

  /* 'path1:38' PRED=ones(M,N); */
  i36 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = Local->size[0];
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)PRED, i36, (int32_T)sizeof(real_T),
                    &fd_emlrtRTEI);
  loop_ub = Local->size[0] * Local->size[1];
  for (i36 = 0; i36 < loop_ub; i36++) {
    PRED->data[i36] = 1.0;
  }

  /* initializing several desired matrix; */
  /* 'path1:39' P=ones(1,N); */
  i36 = PATH->size[0] * PATH->size[1];
  PATH->size[0] = 1;
  PATH->size[1] = Local->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)PATH, i36, (int32_T)sizeof(real_T),
                    &fd_emlrtRTEI);
  loop_ub = Local->size[1];
  for (i36 = 0; i36 < loop_ub; i36++) {
    PATH->data[i36] = 1.0;
  }

  emxInit_real_T(sp, &p, 2, &hd_emlrtRTEI, true);

  /* 'path1:40' p=zeros(1,N); */
  i36 = p->size[0] * p->size[1];
  p->size[0] = 1;
  p->size[1] = Local->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)p, i36, (int32_T)sizeof(real_T),
                    &fd_emlrtRTEI);
  loop_ub = Local->size[1];
  for (i36 = 0; i36 < loop_ub; i36++) {
    p->data[i36] = 0.0;
  }

  emxInit_real_T(sp, &PCOST, 2, &id_emlrtRTEI, true);

  /* PATH=zeros(1,N); */
  /* 'path1:42' PCOST = zeros(1,M); */
  i36 = PCOST->size[0] * PCOST->size[1];
  PCOST->size[0] = 1;
  PCOST->size[1] = Local->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)PCOST, i36, (int32_T)sizeof(real_T),
                    &fd_emlrtRTEI);
  loop_ub = Local->size[0];
  for (i36 = 0; i36 < loop_ub; i36++) {
    PCOST->data[i36] = 0.0;
  }

  emxInit_real_T(sp, &CCOST, 2, &jd_emlrtRTEI, true);

  /* 'path1:43' CCOST = zeros(1,M); */
  i36 = CCOST->size[0] * CCOST->size[1];
  CCOST->size[0] = 1;
  CCOST->size[1] = Local->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)CCOST, i36, (int32_T)sizeof(real_T),
                    &fd_emlrtRTEI);
  loop_ub = Local->size[0];
  for (i36 = 0; i36 < loop_ub; i36++) {
    CCOST->data[i36] = 0.0;
  }

  /* 'path1:45' for J=1:M */
  J = 1;
  while (J - 1 <= M) {
    /* initializing the previous costs; */
    /* 'path1:46' PCOST(J)=Local(J,1); */
    i36 = Local->size[1];
    if (!(1 <= i36)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i36, &og_emlrtBCI, sp);
    }

    i36 = Local->size[0];
    if (!((J >= 1) && (J <= i36))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, i36, &wh_emlrtBCI, sp);
    }

    i36 = PCOST->size[1];
    if (!((J >= 1) && (J <= i36))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, i36, &xh_emlrtBCI, sp);
    }

    PCOST->data[J - 1] = Local->data[J - 1];
    J++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* 'path1:49' for I=2:N */
  I = 2;
  while (I - 2 <= N - 2) {
    /* this loop is doing the heart work of this routine. That means to */
    /* 'path1:50' for J=1:M */
    J = 1;
    while (J - 1 <= M) {
      /* 'path1:51' CCOST(J)=1.0E+30; */
      i36 = CCOST->size[1];
      if (!((J >= 1) && (J <= i36))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i36, &eh_emlrtBCI, sp);
      }

      CCOST->data[J - 1] = 1.0E+30;

      /* get the lowest cost path; */
      /* 'path1:53' for K=1:M */
      K = 1;
      while (K - 1 <= M) {
        /* 'path1:54' if PCOST(K)+Trans(K,J,I)<=CCOST(J) */
        i36 = PCOST->size[1];
        if (!((K >= 1) && (K <= i36))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, i36, &kh_emlrtBCI, sp);
        }

        i36 = Trans->size[0];
        if (!((K >= 1) && (K <= i36))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, i36, &lh_emlrtBCI, sp);
        }

        i36 = Trans->size[1];
        if (!((J >= 1) && (J <= i36))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, i36, &mh_emlrtBCI, sp);
        }

        i36 = Trans->size[2];
        if (!((I >= 1) && (I <= i36))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i36, &nh_emlrtBCI, sp);
        }

        i36 = CCOST->size[1];
        if (!((J >= 1) && (J <= i36))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, i36, &oh_emlrtBCI, sp);
        }

        if (PCOST->data[K - 1] + Trans->data[((K + Trans->size[0] * (J - 1)) +
             Trans->size[0] * Trans->size[1] * (I - 1)) - 1] <= CCOST->data[J -
            1]) {
          /* deciding the optimal path between two points in two next column;  */
          /* 'path1:55' CCOST(J)=PCOST(K)+Trans(K,J,I); */
          i36 = PCOST->size[1];
          if (!((K >= 1) && (K <= i36))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, i36, &ph_emlrtBCI, sp);
          }

          i36 = Trans->size[0];
          if (!((K >= 1) && (K <= i36))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, i36, &qh_emlrtBCI, sp);
          }

          i36 = Trans->size[1];
          if (!((J >= 1) && (J <= i36))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i36, &rh_emlrtBCI, sp);
          }

          i36 = Trans->size[2];
          if (!((I >= 1) && (I <= i36))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i36, &sh_emlrtBCI, sp);
          }

          i36 = CCOST->size[1];
          if (!((J >= 1) && (J <= i36))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i36, &th_emlrtBCI, sp);
          }

          CCOST->data[J - 1] = PCOST->data[K - 1] + Trans->data[((K +
            Trans->size[0] * (J - 1)) + Trans->size[0] * Trans->size[1] * (I - 1))
            - 1];

          /* 'path1:56' PRED(J,I)=K; */
          i36 = PRED->size[0];
          if (!((J >= 1) && (J <= i36))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i36, &uh_emlrtBCI, sp);
          }

          i36 = PRED->size[1];
          if (!((I >= 1) && (I <= i36))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i36, &vh_emlrtBCI, sp);
          }

          PRED->data[(J + PRED->size[0] * (I - 1)) - 1] = 1.0 + (real_T)(K - 1);

          /* this line is very importent, used to mark the chosen points; */
        }

        K++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* 'path1:60' if CCOST(J)>=1.0E+30 */
      i36 = CCOST->size[1];
      if (!((J >= 1) && (J <= i36))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i36, &fh_emlrtBCI, sp);
      }

      if (CCOST->data[J - 1] >= 1.0E+30) {
        st.site = &nk_emlrtRSI;
        for (i36 = 0; i36 < 30; i36++) {
          c_u[i36] = c_varargin_1[i36];
        }

        c_y = NULL;
        m9 = emlrtCreateCharArray(2, iv46);
        emlrtInitCharArrayR2013a(&st, 30, m9, &c_u[0]);
        emlrtAssign(&c_y, m9);
        b_st.site = &ho_emlrtRSI;
        n_error(&b_st, c_y, &emlrtMCI);
      }

      /* 'path1:64' CCOST(J)=CCOST(J)+Local(J,I); */
      i36 = CCOST->size[1];
      if (!((J >= 1) && (J <= i36))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i36, &gh_emlrtBCI, sp);
      }

      i36 = Local->size[0];
      if (!((J >= 1) && (J <= i36))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i36, &hh_emlrtBCI, sp);
      }

      i36 = Local->size[1];
      if (!((I >= 1) && (I <= i36))) {
        emlrtDynamicBoundsCheckR2012b(I, 1, i36, &ih_emlrtBCI, sp);
      }

      i36 = CCOST->size[1];
      if (!((J >= 1) && (J <= i36))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i36, &jh_emlrtBCI, sp);
      }

      CCOST->data[J - 1] += Local->data[(J + Local->size[0] * (I - 1)) - 1];

      /* new cost is gotten by the adding of Local cost and current cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* 'path1:68' for J=1:M */
    J = 1;
    while (J - 1 <= M) {
      /* 'path1:69' PCOST(J)=CCOST(J); */
      i36 = CCOST->size[1];
      if (!((J >= 1) && (J <= i36))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i36, &ch_emlrtBCI, sp);
      }

      i36 = PCOST->size[1];
      if (!((J >= 1) && (J <= i36))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i36, &dh_emlrtBCI, sp);
      }

      PCOST->data[J - 1] = CCOST->data[J - 1];

      /* using the new current cost to update the previous cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* 'path1:72' p(I)=1; */
    i36 = p->size[1];
    if (!((I >= 1) && (I <= i36))) {
      emlrtDynamicBoundsCheckR2012b(I, 1, i36, &xg_emlrtBCI, sp);
    }

    p->data[I - 1] = 1.0;

    /* 'path1:73' for J=2:M */
    J = 0;
    while (J <= M - 1) {
      /* obtaining the points with lowest cost in every column; */
      /* 'path1:74' if CCOST(J)<=CCOST(1) */
      i36 = CCOST->size[1];
      if (!(1 <= i36)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i36, &pg_emlrtBCI, sp);
      }

      i36 = CCOST->size[1];
      if (!((J + 2 >= 1) && (J + 2 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(J + 2, 1, i36, &yg_emlrtBCI, sp);
      }

      if (CCOST->data[J + 1] <= CCOST->data[0]) {
        /* 'path1:75' CCOST(1)=CCOST(J); */
        i36 = CCOST->size[1];
        if (!(1 <= i36)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i36, &qg_emlrtBCI, sp);
        }

        i36 = CCOST->size[1];
        if (!((J + 2 >= 1) && (J + 2 <= i36))) {
          emlrtDynamicBoundsCheckR2012b(J + 2, 1, i36, &ah_emlrtBCI, sp);
        }

        CCOST->data[0] = CCOST->data[J + 1];

        /* 'path1:75' p(I)=J; */
        i36 = p->size[1];
        if (!((I >= 1) && (I <= i36))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i36, &bh_emlrtBCI, sp);
        }

        p->data[I - 1] = 2.0 + (real_T)J;
      }

      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    I++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&CCOST);
  emxFree_real_T(&PCOST);

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
  i36 = p->size[1];
  i37 = Local->size[1];
  if (!((i37 >= 1) && (i37 <= i36))) {
    emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &rg_emlrtBCI, sp);
  }

  i36 = Local->size[1];
  if (!((i36 >= 1) && (i36 <= loop_ub))) {
    emlrtDynamicBoundsCheckR2012b(i36, 1, loop_ub, &sg_emlrtBCI, sp);
  }

  PATH->data[i36 - 1] = p->data[i37 - 1];

  /* 'path1:99' for I=N-1:-1:1 */
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &kg_emlrtRTEI, sp);
  I = 0;
  emxFree_real_T(&p);
  while (I <= Local->size[1] - 2) {
    b_I = N - I;

    /* using this loop to get the path finally; from the last point going */
    /* 'path1:100' P(I)=PRED(P(I+1),I+1); */
    i36 = PRED->size[0];
    i37 = PATH->size[1];
    if (!((b_I >= 1) && (b_I <= i37))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, i37, &ug_emlrtBCI, sp);
    }

    i37 = (int32_T)PATH->data[b_I - 1];
    if (!((i37 >= 1) && (i37 <= i36))) {
      emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &tg_emlrtBCI, sp);
    }

    i36 = PRED->size[1];
    if (!((b_I >= 1) && (b_I <= i36))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, i36, &vg_emlrtBCI, sp);
    }

    i36 = PATH->size[1];
    loop_ub = b_I - 1;
    if (!((loop_ub >= 1) && (loop_ub <= i36))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i36, &wg_emlrtBCI, sp);
    }

    PATH->data[loop_ub - 1] = PRED->data[(i37 + PRED->size[0] * (b_I - 1)) - 1];

    /* backward to find the previous points, etc; */
    I++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&PRED);

  /* 'path1:102' PATH=P; */
  /* getting the final path.  */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (path1.c) */
