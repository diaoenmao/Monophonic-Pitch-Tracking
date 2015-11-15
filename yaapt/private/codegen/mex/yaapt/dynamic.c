/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dynamic.c
 *
 * Code generation for function 'dynamic'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "dynamic.h"
#include "yaapt_emxutil.h"
#include "error.h"
#include "mean.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo yj_emlrtRSI = { 50, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRSInfo ak_emlrtRSI = { 96, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRSInfo bk_emlrtRSI = { 31, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo dd_emlrtRTEI = { 1, 23, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRTEInfo ed_emlrtRTEI = { 63, 1, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRTEInfo fd_emlrtRTEI = { 66, 1, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 80, 50, "Energy", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 80, 38, "Energy", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 75, 62, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 75, 60, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 75, 51, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 75, 49, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 49, 20, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 50, 19, "BestPitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 101, 23, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 101, 23, "Path", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 101, 31, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 101, 3, "FinPitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 74, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 75, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 69, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 69, 9, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 51, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 60, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 64, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 64, 33, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 64, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 54, 16, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 54, 31, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 54, 33, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 54, 39, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 55, 26, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 55, 41, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 55, 43, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 55, 17, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 56, 22, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 46, 20, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 46, 5, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 74, 24, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo di_emlrtBCI = { -1, -1, 74, 26, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 74, 44, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 74, 46, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 75, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 75, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ii_emlrtBCI = { -1, -1, 75, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 79, 23, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ki_emlrtBCI = { -1, -1, 79, 25, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo li_emlrtBCI = { -1, -1, 79, 40, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo mi_emlrtBCI = { -1, -1, 79, 42, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ni_emlrtBCI = { -1, -1, 79, 60, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo oi_emlrtBCI = { -1, -1, 79, 62, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo pi_emlrtBCI = { -1, -1, 79, 76, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo qi_emlrtBCI = { -1, -1, 79, 78, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ri_emlrtBCI = { -1, -1, 81, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo si_emlrtBCI = { -1, -1, 81, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ti_emlrtBCI = { -1, -1, 81, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ui_emlrtBCI = { -1, -1, 85, 24, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo vi_emlrtBCI = { -1, -1, 85, 26, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo wi_emlrtBCI = { -1, -1, 85, 45, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo xi_emlrtBCI = { -1, -1, 85, 47, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo yi_emlrtBCI = { -1, -1, 86, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo aj_emlrtBCI = { -1, -1, 86, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo bj_emlrtBCI = { -1, -1, 86, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

/* Function Definitions */

/*
 * function [FinPitch] = dynamic(Pitch, Merit, Energy, Prm)
 */
void dynamic(const emlrtStack *sp, const emxArray_real_T *Pitch, const
             emxArray_real_T *Merit, const emxArray_real_T *Energy,
             emxArray_real_T *FinPitch)
{
  emxArray_int32_T *r22;
  int32_T numframes;
  int32_T numcands;
  int32_T i38;
  int32_T trueCount;
  int32_T end;
  int32_T i;
  int32_T partialTrueCount;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *c_Pitch;
  emxArray_real_T *Local;
  real_T mean_pitch;
  emxArray_real_T *Trans;
  int32_T j;
  int32_T k;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T N;
  int32_T M;
  emxArray_real_T *PRED;
  int32_T P_size_idx_1;
  real_T P_data[4999];
  real_T p_data[4999];
  real_T PCOST_data[499];
  real_T CCOST_data[499];
  int32_T J;
  int32_T I;
  int32_T K;
  int32_T b_I;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T1(sp, &r22, 2, &dd_emlrtRTEI, true);

  /* DYNAMIC Dynamic programming for YAAPT pitch tracking */
  /*  */
  /*  [FinPitch] = dynamic(Pitch, Merit, Energy, Prm) is used */
  /*  to compute Local and Transition cost matrices */
  /*  to enable lowest cost tracking of pitch candidates; */
  /*  It uses NFLER from the spectrogram and the highly robust */
  /*  spectral F0 track, plus the merits, for */
  /*  computation of the cost matrices. */
  /*  */
  /* INPUTS:  */
  /*    Pitch:  Pitch array with elements arranged so that lowest */
  /*                       index correponds to  highest merit */
  /*    Merit:  Merit array with elements arranged as for pitch */
  /*    Energy: NLFER energy ratio from the low frequency regions of spectrogram. */
  /*    Prm:    Array of parameters used to control performance */
  /*  */
  /* OUTPUTS:   */
  /*    FinPitch: The final pitch track for the entire utterance pitch */
  /*    values are in HZ.Unvoiced frames are assigned 0. */
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
  /* 'dynamic:46' [numcands, numframes] = size(Pitch); */
  numframes = Pitch->size[1] - 1;
  numcands = Pitch->size[0] - 1;

  /* Copy some arrays */
  /* 'dynamic:49' BestPitch  = Pitch(numcands-1,:); */
  i38 = Pitch->size[0];
  trueCount = (int32_T)((real_T)Pitch->size[0] - 1.0);
  if (!((trueCount >= 1) && (trueCount <= i38))) {
    emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &ah_emlrtBCI, sp);
  }

  /* 'dynamic:50' mean_pitch = mean(BestPitch(BestPitch>0)); */
  end = Pitch->size[1] - 1;
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    if (Pitch->data[(numcands + Pitch->size[0] * i) - 1] > 0.0) {
      trueCount++;
    }
  }

  i38 = r22->size[0] * r22->size[1];
  r22->size[0] = 1;
  r22->size[1] = trueCount;
  emxEnsureCapacity(sp, (emxArray__common *)r22, i38, (int32_T)sizeof(int32_T),
                    &dd_emlrtRTEI);
  partialTrueCount = 0;
  for (i = 0; i <= end; i++) {
    if (Pitch->data[(numcands + Pitch->size[0] * i) - 1] > 0.0) {
      r22->data[partialTrueCount] = i + 1;
      partialTrueCount++;
    }
  }

  emxInit_real_T(sp, &b_Pitch, 2, &dd_emlrtRTEI, true);
  emxInit_real_T(sp, &c_Pitch, 2, &dd_emlrtRTEI, true);
  i38 = Pitch->size[1];
  i = Pitch->size[1];
  end = Pitch->size[0];
  trueCount = c_Pitch->size[0] * c_Pitch->size[1];
  c_Pitch->size[0] = 1;
  c_Pitch->size[1] = i;
  emxEnsureCapacity(sp, (emxArray__common *)c_Pitch, trueCount, (int32_T)sizeof
                    (real_T), &dd_emlrtRTEI);
  for (trueCount = 0; trueCount < i; trueCount++) {
    c_Pitch->data[c_Pitch->size[0] * trueCount] = Pitch->data[(end + Pitch->
      size[0] * trueCount) - 2];
  }

  trueCount = b_Pitch->size[0] * b_Pitch->size[1];
  b_Pitch->size[0] = 1;
  b_Pitch->size[1] = r22->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, trueCount, (int32_T)sizeof
                    (real_T), &dd_emlrtRTEI);
  i = r22->size[1];
  for (trueCount = 0; trueCount < i; trueCount++) {
    partialTrueCount = r22->data[r22->size[0] * trueCount];
    if (!((partialTrueCount >= 1) && (partialTrueCount <= i38))) {
      emlrtDynamicBoundsCheckR2012b(partialTrueCount, 1, i38, &bh_emlrtBCI, sp);
    }

    b_Pitch->data[b_Pitch->size[0] * trueCount] = c_Pitch->data[partialTrueCount
      - 1];
  }

  emxFree_real_T(&c_Pitch);
  emxFree_int32_T(&r22);
  emxInit_real_T(sp, &Local, 2, &ed_emlrtRTEI, true);
  st.site = &yj_emlrtRSI;
  mean_pitch = mean(&st, b_Pitch);

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* 'dynamic:55' dp_w1 = Prm.dp_w1; */
  /* 'dynamic:56' dp_w2 = Prm.dp_w2; */
  /* 'dynamic:57' dp_w3 = Prm.dp_w3; */
  /* 'dynamic:58' dp_w4 = Prm.dp_w4; */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Forming the local cost matrix */
  /* 'dynamic:63' Local = 1 - Merit; */
  i38 = Local->size[0] * Local->size[1];
  Local->size[0] = Merit->size[0];
  Local->size[1] = Merit->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Local, i38, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  i = Merit->size[0] * Merit->size[1];
  emxFree_real_T(&b_Pitch);
  for (i38 = 0; i38 < i; i38++) {
    Local->data[i38] = 1.0 - Merit->data[i38];
  }

  emxInit_real_T2(sp, &Trans, 3, &fd_emlrtRTEI, true);

  /*  Initialization for the formation of the transition cost matrix */
  /* 'dynamic:66' Trans  = ones(numcands,numcands,numframes); */
  i38 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = Pitch->size[0];
  Trans->size[1] = Pitch->size[0];
  Trans->size[2] = Pitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i38, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  i = Pitch->size[0] * Pitch->size[0] * Pitch->size[1];
  for (i38 = 0; i38 < i; i38++) {
    Trans->data[i38] = 1.0;
  }

  /*  The transition cost matrix is proportional to frequency differences */
  /*  between successive candidates. */
  /* 'dynamic:70' for i = 2:numframes */
  i = 0;
  while (i <= numframes - 1) {
    /* 'dynamic:71' for j = 1:numcands */
    j = 1;
    while (j - 1 <= numcands) {
      /* 'dynamic:72' for k = 1:numcands */
      k = 1;
      while (k - 1 <= numcands) {
        /*  both candidates voiced */
        /* 'dynamic:74' if ((Pitch(j,i) > 0) && (Pitch(k,i-1) > 0) ) */
        i38 = Pitch->size[0];
        if (!((j >= 1) && (j <= i38))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i38, &ci_emlrtBCI, sp);
        }

        i38 = Pitch->size[1];
        if (!((i + 2 >= 1) && (i + 2 <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i38, &di_emlrtBCI, sp);
        }

        if (Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1] > 0.0) {
          i38 = Pitch->size[0];
          if (!((k >= 1) && (k <= i38))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i38, &ei_emlrtBCI, sp);
          }

          i38 = Pitch->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= i38))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i38, &fi_emlrtBCI, sp);
          }

          if (Pitch->data[(k + Pitch->size[0] * i) - 1] > 0.0) {
            /* 'dynamic:75' Trans(k,j,i) = dp_w1*(abs(Pitch(j,i)-Pitch(k,i-1))/mean_pitch); */
            i38 = Pitch->size[0];
            trueCount = (j - 1) + 1;
            if (!((trueCount >= 1) && (trueCount <= i38))) {
              emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &yg_emlrtBCI, sp);
            }

            i38 = Pitch->size[1];
            trueCount = (int32_T)(2.0 + (real_T)i);
            if (!((trueCount >= 1) && (trueCount <= i38))) {
              emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &xg_emlrtBCI, sp);
            }

            i38 = Pitch->size[0];
            trueCount = (k - 1) + 1;
            if (!((trueCount >= 1) && (trueCount <= i38))) {
              emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &wg_emlrtBCI, sp);
            }

            i38 = Pitch->size[1];
            trueCount = (int32_T)((2.0 + (real_T)i) - 1.0);
            if (!((trueCount >= 1) && (trueCount <= i38))) {
              emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &vg_emlrtBCI, sp);
            }

            i38 = Trans->size[0];
            if (!((k >= 1) && (k <= i38))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i38, &gi_emlrtBCI, sp);
            }

            i38 = Trans->size[1];
            if (!((j >= 1) && (j <= i38))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i38, &hi_emlrtBCI, sp);
            }

            i38 = Trans->size[2];
            if (!((i + 2 >= 1) && (i + 2 <= i38))) {
              emlrtDynamicBoundsCheckR2012b(i + 2, 1, i38, &ii_emlrtBCI, sp);
            }

            Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                         Trans->size[1] * (i + 1)) - 1] = 0.15 *
              (muDoubleScalarAbs(Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1]
                                 - Pitch->data[(k + Pitch->size[0] * i) - 1]) /
               mean_pitch);
          }
        }

        /*  one candiate is unvoiced */
        /* 'dynamic:79' if (Pitch(j,i)==0 && Pitch(k,i-1)>0) || (Pitch(j,i)>0 && Pitch(k,i-1)==0) */
        i38 = Pitch->size[0];
        if (!((j >= 1) && (j <= i38))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i38, &ji_emlrtBCI, sp);
        }

        i38 = Pitch->size[1];
        if (!((i + 2 >= 1) && (i + 2 <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i38, &ki_emlrtBCI, sp);
        }

        guard1 = false;
        guard2 = false;
        if (Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1] == 0.0) {
          i38 = Pitch->size[0];
          if (!((k >= 1) && (k <= i38))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i38, &li_emlrtBCI, sp);
          }

          i38 = Pitch->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= i38))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i38, &mi_emlrtBCI, sp);
          }

          if (Pitch->data[(k + Pitch->size[0] * i) - 1] > 0.0) {
            guard1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          i38 = Pitch->size[0];
          if (!((j >= 1) && (j <= i38))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i38, &ni_emlrtBCI, sp);
          }

          i38 = Pitch->size[1];
          if (!((i + 2 >= 1) && (i + 2 <= i38))) {
            emlrtDynamicBoundsCheckR2012b(i + 2, 1, i38, &oi_emlrtBCI, sp);
          }

          if (Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1] > 0.0) {
            i38 = Pitch->size[0];
            if (!((k >= 1) && (k <= i38))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i38, &pi_emlrtBCI, sp);
            }

            i38 = Pitch->size[1];
            if (!((i + 1 >= 1) && (i + 1 <= i38))) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, i38, &qi_emlrtBCI, sp);
            }

            if (Pitch->data[(k + Pitch->size[0] * i) - 1] == 0.0) {
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* 'dynamic:80' benefit = min(1, abs(Energy(i-1)-Energy(i))); */
          i38 = Energy->size[1];
          trueCount = (int32_T)((2.0 + (real_T)i) - 1.0);
          if (!((trueCount >= 1) && (trueCount <= i38))) {
            emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &ug_emlrtBCI, sp);
          }

          i38 = Energy->size[1];
          trueCount = (int32_T)(2.0 + (real_T)i);
          if (!((trueCount >= 1) && (trueCount <= i38))) {
            emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &tg_emlrtBCI, sp);
          }

          /* 'dynamic:81' Trans(k,j,i) =  dp_w2*(1-benefit); */
          i38 = Trans->size[0];
          if (!((k >= 1) && (k <= i38))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i38, &ri_emlrtBCI, sp);
          }

          i38 = Trans->size[1];
          if (!((j >= 1) && (j <= i38))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i38, &si_emlrtBCI, sp);
          }

          i38 = Trans->size[2];
          if (!((i + 2 >= 1) && (i + 2 <= i38))) {
            emlrtDynamicBoundsCheckR2012b(i + 2, 1, i38, &ti_emlrtBCI, sp);
          }

          Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                       Trans->size[1] * (i + 1)) - 1] = 0.5 * (1.0 -
            muDoubleScalarMin(1.0, muDoubleScalarAbs(Energy->data[i] -
            Energy->data[i + 1])));
        }

        /*  both candidates are unvoiced */
        /* 'dynamic:85' if ((Pitch(j,i) == 0) && (Pitch(k,i-1) == 0)) */
        i38 = Pitch->size[0];
        if (!((j >= 1) && (j <= i38))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i38, &ui_emlrtBCI, sp);
        }

        i38 = Pitch->size[1];
        if (!((i + 2 >= 1) && (i + 2 <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i38, &vi_emlrtBCI, sp);
        }

        if (Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1] == 0.0) {
          i38 = Pitch->size[0];
          if (!((k >= 1) && (k <= i38))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i38, &wi_emlrtBCI, sp);
          }

          i38 = Pitch->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= i38))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i38, &xi_emlrtBCI, sp);
          }

          if (Pitch->data[(k + Pitch->size[0] * i) - 1] == 0.0) {
            /* 'dynamic:86' Trans(k,j,i) =  dp_w3; */
            i38 = Trans->size[0];
            if (!((k >= 1) && (k <= i38))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i38, &yi_emlrtBCI, sp);
            }

            i38 = Trans->size[1];
            if (!((j >= 1) && (j <= i38))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i38, &aj_emlrtBCI, sp);
            }

            i38 = Trans->size[2];
            if (!((i + 2 >= 1) && (i + 2 <= i38))) {
              emlrtDynamicBoundsCheckR2012b(i + 2, 1, i38, &bj_emlrtBCI, sp);
            }

            Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                         Trans->size[1] * (i + 1)) - 1] = 0.1;
          }
        }

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
  /* 'dynamic:93' Trans = Trans/dp_w4; */
  i38 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i38, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  partialTrueCount = Trans->size[0];
  trueCount = Trans->size[1];
  end = Trans->size[2];
  i = partialTrueCount * trueCount * end;
  for (i38 = 0; i38 < i; i38++) {
    Trans->data[i38] /= 0.9;
  }

  /*  Find the minimum cost path thru Pitch_Array using the Local and Trans costs */
  /* 'dynamic:96' Path = path1(Local,Trans); */
  st.site = &ak_emlrtRSI;

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
    b_st.site = &bk_emlrtRSI;
    l_error(&b_st);
  }

  /* 'path1:33' if N>=5000 */
  if (Local->size[1] >= 5000) {
    /* if N is greater than 1000, stop the routine; */
    b_st.site = &hh_emlrtRSI;
    g_error(&b_st);
  }

  emxInit_real_T(&st, &PRED, 2, &ec_emlrtRTEI, true);

  /* 'path1:38' PRED=ones(M,N); */
  i38 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = Local->size[0];
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)PRED, i38, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  i = Local->size[0] * Local->size[1];
  for (i38 = 0; i38 < i; i38++) {
    PRED->data[i38] = 1.0;
  }

  /* initializing several desired matrix; */
  /* 'path1:39' P=ones(1,N); */
  P_size_idx_1 = Local->size[1];
  i = Local->size[1];
  for (i38 = 0; i38 < i; i38++) {
    P_data[i38] = 1.0;
  }

  /* 'path1:40' p=zeros(1,N); */
  end = Local->size[1];
  i = Local->size[1];
  for (i38 = 0; i38 < i; i38++) {
    p_data[i38] = 0.0;
  }

  /* PATH=zeros(1,N); */
  /* 'path1:42' PCOST = zeros(1,M); */
  partialTrueCount = Local->size[0];
  i = Local->size[0];
  for (i38 = 0; i38 < i; i38++) {
    PCOST_data[i38] = 0.0;
  }

  /* 'path1:43' CCOST = zeros(1,M); */
  trueCount = Local->size[0];
  i = Local->size[0];
  for (i38 = 0; i38 < i; i38++) {
    CCOST_data[i38] = 0.0;
  }

  /* 'path1:45' for J=1:M */
  J = 1;
  while (J - 1 <= M) {
    /* initializing the previous costs; */
    /* 'path1:46' PCOST(J)=Local(J,1); */
    i38 = Local->size[1];
    if (!(1 <= i38)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i38, &xe_emlrtBCI, &st);
    }

    i38 = Local->size[0];
    if (!((J >= 1) && (J <= i38))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, i38, &ai_emlrtBCI, &st);
    }

    if (!((J >= 1) && (J <= partialTrueCount))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, partialTrueCount, &bi_emlrtBCI, &st);
    }

    PCOST_data[J - 1] = Local->data[J - 1];
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
    J = 1;
    while (J - 1 <= M) {
      /* 'path1:51' CCOST(J)=1.0E+30; */
      if (!((J >= 1) && (J <= trueCount))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, trueCount, &lh_emlrtBCI, &st);
      }

      CCOST_data[J - 1] = 1.0E+30;

      /* get the lowest cost path; */
      /* 'path1:53' for K=1:M */
      K = 1;
      while (K - 1 <= M) {
        /* 'path1:54' if PCOST(K)+Trans(K,J,I)<=CCOST(J) */
        if (!((K >= 1) && (K <= partialTrueCount))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, partialTrueCount, &qh_emlrtBCI,
            &st);
        }

        i38 = Trans->size[0];
        if (!((K >= 1) && (K <= i38))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, i38, &rh_emlrtBCI, &st);
        }

        i38 = Trans->size[1];
        if (!((J >= 1) && (J <= i38))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, i38, &sh_emlrtBCI, &st);
        }

        i38 = Trans->size[2];
        if (!((I >= 1) && (I <= i38))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i38, &pf_emlrtBCI, &st);
        }

        if (!((J >= 1) && (J <= trueCount))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, trueCount, &th_emlrtBCI, &st);
        }

        if (PCOST_data[K - 1] + Trans->data[((K + Trans->size[0] * (J - 1)) +
             Trans->size[0] * Trans->size[1] * (I - 1)) - 1] <= CCOST_data[J - 1])
        {
          /* deciding the optimal path between two points in two next column;  */
          /* 'path1:55' CCOST(J)=PCOST(K)+Trans(K,J,I); */
          if (!((K >= 1) && (K <= partialTrueCount))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, partialTrueCount, &uh_emlrtBCI,
              &st);
          }

          i38 = Trans->size[0];
          if (!((K >= 1) && (K <= i38))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, i38, &vh_emlrtBCI, &st);
          }

          i38 = Trans->size[1];
          if (!((J >= 1) && (J <= i38))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i38, &wh_emlrtBCI, &st);
          }

          i38 = Trans->size[2];
          if (!((I >= 1) && (I <= i38))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i38, &qf_emlrtBCI, &st);
          }

          if (!((J >= 1) && (J <= trueCount))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, trueCount, &xh_emlrtBCI, &st);
          }

          CCOST_data[J - 1] = PCOST_data[K - 1] + Trans->data[((K + Trans->size
            [0] * (J - 1)) + Trans->size[0] * Trans->size[1] * (I - 1)) - 1];

          /* 'path1:56' PRED(J,I)=K; */
          i38 = PRED->size[0];
          if (!((J >= 1) && (J <= i38))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i38, &yh_emlrtBCI, &st);
          }

          i38 = PRED->size[1];
          if (!((I >= 1) && (I <= i38))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i38, &rf_emlrtBCI, &st);
          }

          PRED->data[(J + PRED->size[0] * (I - 1)) - 1] = 1.0 + (real_T)(K - 1);

          /* this line is very importent, used to mark the chosen points; */
        }

        K++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* 'path1:60' if CCOST(J)>=1.0E+30 */
      if (!((J >= 1) && (J <= trueCount))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, trueCount, &mh_emlrtBCI, &st);
      }

      if (CCOST_data[J - 1] >= 1.0E+30) {
        b_st.site = &ih_emlrtRSI;
        h_error(&b_st);
      }

      /* 'path1:64' CCOST(J)=CCOST(J)+Local(J,I); */
      if (!((J >= 1) && (J <= trueCount))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, trueCount, &nh_emlrtBCI, &st);
      }

      i38 = Local->size[0];
      if (!((J >= 1) && (J <= i38))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i38, &oh_emlrtBCI, &st);
      }

      i38 = Local->size[1];
      if (!((I >= 1) && (I <= i38))) {
        emlrtDynamicBoundsCheckR2012b(I, 1, i38, &of_emlrtBCI, &st);
      }

      if (!((J >= 1) && (J <= trueCount))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, trueCount, &ph_emlrtBCI, &st);
      }

      CCOST_data[J - 1] += Local->data[(J + Local->size[0] * (I - 1)) - 1];

      /* new cost is gotten by the adding of Local cost and current cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* 'path1:68' for J=1:M */
    J = 1;
    while (J - 1 <= M) {
      /* 'path1:69' PCOST(J)=CCOST(J); */
      if (!((J >= 1) && (J <= trueCount))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, trueCount, &jh_emlrtBCI, &st);
      }

      if (!((J >= 1) && (J <= partialTrueCount))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, partialTrueCount, &kh_emlrtBCI, &st);
      }

      PCOST_data[J - 1] = CCOST_data[J - 1];

      /* using the new current cost to update the previous cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* 'path1:72' p(I)=1; */
    if (!((I >= 1) && (I <= end))) {
      emlrtDynamicBoundsCheckR2012b(I, 1, end, &mf_emlrtBCI, &st);
    }

    p_data[I - 1] = 1.0;

    /* 'path1:73' for J=2:M */
    J = 0;
    while (J <= M - 1) {
      /* obtaining the points with lowest cost in every column; */
      /* 'path1:74' if CCOST(J)<=CCOST(1) */
      if (!((J + 2 >= 1) && (J + 2 <= trueCount))) {
        emlrtDynamicBoundsCheckR2012b(J + 2, 1, trueCount, &hh_emlrtBCI, &st);
      }

      if (CCOST_data[J + 1] <= CCOST_data[0]) {
        /* 'path1:75' CCOST(1)=CCOST(J); */
        if (!((J + 2 >= 1) && (J + 2 <= trueCount))) {
          emlrtDynamicBoundsCheckR2012b(J + 2, 1, trueCount, &ih_emlrtBCI, &st);
        }

        CCOST_data[0] = CCOST_data[J + 1];

        /* 'path1:75' p(I)=J; */
        if (!((I >= 1) && (I <= end))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, end, &nf_emlrtBCI, &st);
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
  partialTrueCount = Local->size[1];
  i38 = Local->size[1];
  if (!((i38 >= 1) && (i38 <= end))) {
    emlrtDynamicBoundsCheckR2012b(i38, 1, end, &cf_emlrtBCI, &st);
  }

  trueCount = Local->size[1];
  if (!((trueCount >= 1) && (trueCount <= partialTrueCount))) {
    emlrtDynamicBoundsCheckR2012b(trueCount, 1, partialTrueCount, &df_emlrtBCI,
      &st);
  }

  P_data[trueCount - 1] = p_data[i38 - 1];

  /* 'path1:99' for I=N-1:-1:1 */
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &pe_emlrtRTEI, &st);
  I = 0;
  while (I <= Local->size[1] - 2) {
    b_I = N - I;

    /* using this loop to get the path finally; from the last point going */
    /* 'path1:100' P(I)=PRED(P(I+1),I+1); */
    i38 = PRED->size[0];
    if (!((b_I >= 1) && (b_I <= P_size_idx_1))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, P_size_idx_1, &jf_emlrtBCI, &st);
    }

    trueCount = (int32_T)P_data[b_I - 1];
    if (!((trueCount >= 1) && (trueCount <= i38))) {
      emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &gh_emlrtBCI, &st);
    }

    i38 = PRED->size[1];
    if (!((b_I >= 1) && (b_I <= i38))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, i38, &kf_emlrtBCI, &st);
    }

    i38 = b_I - 1;
    if (!((i38 >= 1) && (i38 <= P_size_idx_1))) {
      emlrtDynamicBoundsCheckR2012b(i38, 1, P_size_idx_1, &lf_emlrtBCI, &st);
    }

    P_data[i38 - 1] = PRED->data[(trueCount + PRED->size[0] * (b_I - 1)) - 1];

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
  /* extracting the pitch, using Path */
  /* 'dynamic:99' FinPitch = zeros(1,numframes); */
  i38 = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, i38, (int32_T)sizeof
                    (real_T), &dd_emlrtRTEI);
  i = Pitch->size[1];
  for (i38 = 0; i38 < i; i38++) {
    FinPitch->data[i38] = 0.0;
  }

  /* 'dynamic:100' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'dynamic:101' FinPitch(i) = Pitch(Path(i),i); */
    i38 = Pitch->size[0];
    if (!((i >= 1) && (i <= P_size_idx_1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, P_size_idx_1, &dh_emlrtBCI, sp);
    }

    trueCount = (int32_T)P_data[i - 1];
    if (!((trueCount >= 1) && (trueCount <= i38))) {
      emlrtDynamicBoundsCheckR2012b(trueCount, 1, i38, &ch_emlrtBCI, sp);
    }

    i38 = Pitch->size[1];
    if (!((i >= 1) && (i <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i38, &eh_emlrtBCI, sp);
    }

    i38 = FinPitch->size[1];
    if (!((i >= 1) && (i <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i38, &fh_emlrtBCI, sp);
    }

    FinPitch->data[i - 1] = Pitch->data[(trueCount + Pitch->size[0] * (i - 1)) -
      1];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (dynamic.c) */
