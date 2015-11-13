/*
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
#include "spec_trk.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo gj_emlrtRSI = { 50, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRSInfo hj_emlrtRSI = { 96, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRSInfo ij_emlrtRSI = { 31, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo md_emlrtRTEI = { 1, 23, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRTEInfo nd_emlrtRTEI = { 49, 1, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRTEInfo od_emlrtRTEI = { 63, 1, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRTEInfo pd_emlrtRTEI = { 66, 1, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 80, 50, "Energy", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 80, 38, "Energy", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 75, 62, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 75, 60, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 75, 51, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 75, 49, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 49, 20, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 50, 19, "BestPitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 101, 3, "FinPitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 101, 23, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 101, 23, "Path", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 101, 31, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 74, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 75, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 69, 9, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 69, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 51, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 60, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 64, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 64, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 64, 33, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 54, 16, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 54, 31, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 54, 33, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 54, 39, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 55, 17, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 55, 26, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 55, 41, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 55, 43, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 56, 22, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo di_emlrtBCI = { -1, -1, 46, 5, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 46, 20, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 74, 24, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 74, 26, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 74, 44, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ii_emlrtBCI = { -1, -1, 74, 46, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 75, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ki_emlrtBCI = { -1, -1, 75, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo li_emlrtBCI = { -1, -1, 75, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo mi_emlrtBCI = { -1, -1, 79, 23, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ni_emlrtBCI = { -1, -1, 79, 25, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo oi_emlrtBCI = { -1, -1, 79, 40, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo pi_emlrtBCI = { -1, -1, 79, 42, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo qi_emlrtBCI = { -1, -1, 79, 60, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ri_emlrtBCI = { -1, -1, 79, 62, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo si_emlrtBCI = { -1, -1, 79, 76, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ti_emlrtBCI = { -1, -1, 79, 78, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ui_emlrtBCI = { -1, -1, 81, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo vi_emlrtBCI = { -1, -1, 81, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo wi_emlrtBCI = { -1, -1, 81, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo xi_emlrtBCI = { -1, -1, 85, 24, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo yi_emlrtBCI = { -1, -1, 85, 26, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo aj_emlrtBCI = { -1, -1, 85, 45, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo bj_emlrtBCI = { -1, -1, 85, 47, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo cj_emlrtBCI = { -1, -1, 86, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo dj_emlrtBCI = { -1, -1, 86, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ej_emlrtBCI = { -1, -1, 86, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

/* Function Definitions */

/*
 * function [FinPitch] = dynamic(Pitch, Merit, Energy, Prm)
 */
void dynamic(const emlrtStack *sp, const emxArray_real_T *Pitch, const
             emxArray_real_T *Merit, const emxArray_real_T *Energy,
             emxArray_real_T *FinPitch)
{
  emxArray_real_T *BestPitch;
  int32_T loop_ub;
  int32_T i37;
  int32_T i38;
  int32_T b_Pitch;
  emxArray_boolean_T *b_BestPitch;
  emxArray_int32_T *r20;
  emxArray_real_T *c_BestPitch;
  int32_T i39;
  emxArray_real_T *Local;
  real_T mean_pitch;
  emxArray_real_T *Trans;
  int32_T i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  emxArray_real_T *PRED;
  int32_T unnamed_idx_1;
  real_T P_data[4999];
  int32_T b_unnamed_idx_1;
  real_T p_data[4999];
  int32_T c_unnamed_idx_1;
  real_T PCOST_data[499];
  int32_T d_unnamed_idx_1;
  real_T CCOST_data[499];
  int32_T I;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &BestPitch, 2, &nd_emlrtRTEI, true);

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
  /* Copy some arrays */
  /* 'dynamic:49' BestPitch  = Pitch(numcands-1,:); */
  loop_ub = Pitch->size[1];
  i37 = Pitch->size[0];
  i38 = Pitch->size[0] - 1;
  b_Pitch = emlrtDynamicBoundsCheckFastR2012b(i38, 1, i37, &dh_emlrtBCI, sp);
  i37 = BestPitch->size[0] * BestPitch->size[1];
  BestPitch->size[0] = 1;
  BestPitch->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)BestPitch, i37, (int32_T)sizeof
                    (real_T), &md_emlrtRTEI);
  for (i37 = 0; i37 < loop_ub; i37++) {
    BestPitch->data[BestPitch->size[0] * i37] = Pitch->data[(b_Pitch +
      Pitch->size[0] * i37) - 1];
  }

  emxInit_boolean_T(sp, &b_BestPitch, 2, &md_emlrtRTEI, true);

  /* 'dynamic:50' mean_pitch = mean(BestPitch(BestPitch>0)); */
  i37 = b_BestPitch->size[0] * b_BestPitch->size[1];
  b_BestPitch->size[0] = 1;
  b_BestPitch->size[1] = BestPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_BestPitch, i37, (int32_T)sizeof
                    (boolean_T), &md_emlrtRTEI);
  loop_ub = BestPitch->size[0] * BestPitch->size[1];
  for (i37 = 0; i37 < loop_ub; i37++) {
    b_BestPitch->data[i37] = (BestPitch->data[i37] > 0.0);
  }

  b_emxInit_int32_T(sp, &r20, 2, &md_emlrtRTEI, true);
  emxInit_real_T(sp, &c_BestPitch, 2, &md_emlrtRTEI, true);
  st.site = &gj_emlrtRSI;
  eml_li_find(&st, b_BestPitch, r20);
  i37 = Pitch->size[1];
  i38 = c_BestPitch->size[0] * c_BestPitch->size[1];
  c_BestPitch->size[0] = 1;
  c_BestPitch->size[1] = r20->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_BestPitch, i38, (int32_T)sizeof
                    (real_T), &md_emlrtRTEI);
  loop_ub = r20->size[0] * r20->size[1];
  emxFree_boolean_T(&b_BestPitch);
  for (i38 = 0; i38 < loop_ub; i38++) {
    i39 = r20->data[i38];
    c_BestPitch->data[i38] = BestPitch->data[emlrtDynamicBoundsCheckFastR2012b
      (i39, 1, i37, &eh_emlrtBCI, sp) - 1];
  }

  emxFree_int32_T(&r20);
  emxFree_real_T(&BestPitch);
  emxInit_real_T(sp, &Local, 2, &od_emlrtRTEI, true);
  st.site = &gj_emlrtRSI;
  mean_pitch = mean(&st, c_BestPitch);

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
  i37 = Local->size[0] * Local->size[1];
  Local->size[0] = Merit->size[0];
  Local->size[1] = Merit->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Local, i37, (int32_T)sizeof(real_T),
                    &md_emlrtRTEI);
  loop_ub = Merit->size[0] * Merit->size[1];
  emxFree_real_T(&c_BestPitch);
  for (i37 = 0; i37 < loop_ub; i37++) {
    Local->data[i37] = 1.0 - Merit->data[i37];
  }

  c_emxInit_real_T(sp, &Trans, 3, &pd_emlrtRTEI, true);

  /*  Initialization for the formation of the transition cost matrix */
  /* 'dynamic:66' Trans  = ones(numcands,numcands,numframes); */
  b_Pitch = Pitch->size[0];
  i37 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = b_Pitch;
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i37, (int32_T)sizeof(real_T),
                    &md_emlrtRTEI);
  b_Pitch = Pitch->size[0];
  i37 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[1] = b_Pitch;
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i37, (int32_T)sizeof(real_T),
                    &md_emlrtRTEI);
  b_Pitch = Pitch->size[1];
  i37 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[2] = b_Pitch;
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i37, (int32_T)sizeof(real_T),
                    &md_emlrtRTEI);
  loop_ub = Pitch->size[0] * Pitch->size[0] * Pitch->size[1];
  for (i37 = 0; i37 < loop_ub; i37++) {
    Trans->data[i37] = 1.0;
  }

  /*  The transition cost matrix is proportional to frequency differences */
  /*  between successive candidates. */
  /* 'dynamic:70' for i = 2:numframes */
  i = 0;
  while (i <= Pitch->size[1] - 2) {
    /* 'dynamic:71' for j = 1:numcands */
    b_Pitch = 1;
    while (b_Pitch - 1 <= Pitch->size[0] - 1) {
      /* 'dynamic:72' for k = 1:numcands */
      loop_ub = 1;
      while (loop_ub - 1 <= Pitch->size[0] - 1) {
        /*  both candidates voiced */
        /* 'dynamic:74' if ((Pitch(j,i) > 0) && (Pitch(k,i-1) > 0) ) */
        i37 = Pitch->size[0];
        i38 = Pitch->size[1];
        if (Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i37,
              &fi_emlrtBCI, sp) + Pitch->size[0] *
                         (emlrtDynamicBoundsCheckFastR2012b(i + 2, 1, i38,
               &gi_emlrtBCI, sp) - 1)) - 1] > 0.0) {
          i37 = Pitch->size[0];
          i38 = Pitch->size[1];
          if (Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i37,
                &hi_emlrtBCI, sp) + Pitch->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(i + 1, 1, i38,
                 &ii_emlrtBCI, sp) - 1)) - 1] > 0.0) {
            /* 'dynamic:75' Trans(k,j,i) = dp_w1*(abs(Pitch(j,i)-Pitch(k,i-1))/mean_pitch); */
            i37 = Pitch->size[0];
            i38 = (b_Pitch - 1) + 1;
            emlrtDynamicBoundsCheckFastR2012b(i38, 1, i37, &ch_emlrtBCI, sp);
            i37 = Pitch->size[1];
            i38 = (int32_T)(2.0 + (real_T)i);
            emlrtDynamicBoundsCheckFastR2012b(i38, 1, i37, &bh_emlrtBCI, sp);
            i37 = Pitch->size[0];
            i38 = (loop_ub - 1) + 1;
            emlrtDynamicBoundsCheckFastR2012b(i38, 1, i37, &ah_emlrtBCI, sp);
            i37 = Pitch->size[1];
            i38 = (int32_T)((2.0 + (real_T)i) - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i38, 1, i37, &yg_emlrtBCI, sp);
            i37 = Trans->size[0];
            i38 = Trans->size[1];
            i39 = Trans->size[2];
            Trans->data[((emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i37,
              &ji_emlrtBCI, sp) + Trans->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i38,
              &ki_emlrtBCI, sp) - 1)) + Trans->size[0] * Trans->size[1] *
                         (emlrtDynamicBoundsCheckFastR2012b(i + 2, 1, i39,
              &li_emlrtBCI, sp) - 1)) - 1] = 0.15 * (muDoubleScalarAbs
              (Pitch->data[(b_Pitch + Pitch->size[0] * (i + 1)) - 1] -
               Pitch->data[(loop_ub + Pitch->size[0] * i) - 1]) / mean_pitch);
          }
        }

        /*  one candiate is unvoiced */
        /* 'dynamic:79' if (Pitch(j,i)==0 && Pitch(k,i-1)>0) || (Pitch(j,i)>0 && Pitch(k,i-1)==0) */
        i37 = Pitch->size[0];
        i38 = Pitch->size[1];
        guard1 = false;
        guard2 = false;
        if (Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i37,
              &mi_emlrtBCI, sp) + Pitch->size[0] *
                         (emlrtDynamicBoundsCheckFastR2012b(i + 2, 1, i38,
               &ni_emlrtBCI, sp) - 1)) - 1] == 0.0) {
          i37 = Pitch->size[0];
          i38 = Pitch->size[1];
          if (Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i37,
                &oi_emlrtBCI, sp) + Pitch->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(i + 1, 1, i38,
                 &pi_emlrtBCI, sp) - 1)) - 1] > 0.0) {
            guard1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          i37 = Pitch->size[0];
          i38 = Pitch->size[1];
          if (Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i37,
                &qi_emlrtBCI, sp) + Pitch->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(i + 2, 1, i38,
                 &ri_emlrtBCI, sp) - 1)) - 1] > 0.0) {
            i37 = Pitch->size[0];
            i38 = Pitch->size[1];
            if (Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i37,
                  &si_emlrtBCI, sp) + Pitch->size[0] *
                             (emlrtDynamicBoundsCheckFastR2012b(i + 1, 1, i38,
                   &ti_emlrtBCI, sp) - 1)) - 1] == 0.0) {
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* 'dynamic:80' benefit = min(1, abs(Energy(i-1)-Energy(i))); */
          i37 = Energy->size[1];
          i38 = (int32_T)((2.0 + (real_T)i) - 1.0);
          emlrtDynamicBoundsCheckFastR2012b(i38, 1, i37, &xg_emlrtBCI, sp);
          i37 = Energy->size[1];
          i38 = (int32_T)(2.0 + (real_T)i);
          emlrtDynamicBoundsCheckFastR2012b(i38, 1, i37, &wg_emlrtBCI, sp);

          /* 'dynamic:81' Trans(k,j,i) =  dp_w2*(1-benefit); */
          i37 = Trans->size[0];
          i38 = Trans->size[1];
          i39 = Trans->size[2];
          Trans->data[((emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i37,
            &ui_emlrtBCI, sp) + Trans->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i38,
            &vi_emlrtBCI, sp) - 1)) + Trans->size[0] * Trans->size[1] *
                       (emlrtDynamicBoundsCheckFastR2012b(i + 2, 1, i39,
            &wi_emlrtBCI, sp) - 1)) - 1] = 0.5 * (1.0 - muDoubleScalarMin(1.0,
            muDoubleScalarAbs(Energy->data[i] - Energy->data[i + 1])));
        }

        /*  both candidates are unvoiced */
        /* 'dynamic:85' if ((Pitch(j,i) == 0) && (Pitch(k,i-1) == 0)) */
        i37 = Pitch->size[0];
        i38 = Pitch->size[1];
        if (Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i37,
              &xi_emlrtBCI, sp) + Pitch->size[0] *
                         (emlrtDynamicBoundsCheckFastR2012b(i + 2, 1, i38,
               &yi_emlrtBCI, sp) - 1)) - 1] == 0.0) {
          i37 = Pitch->size[0];
          i38 = Pitch->size[1];
          if (Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i37,
                &aj_emlrtBCI, sp) + Pitch->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(i + 1, 1, i38,
                 &bj_emlrtBCI, sp) - 1)) - 1] == 0.0) {
            /* 'dynamic:86' Trans(k,j,i) =  dp_w3; */
            i37 = Trans->size[0];
            i38 = Trans->size[1];
            i39 = Trans->size[2];
            Trans->data[((emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i37,
              &cj_emlrtBCI, sp) + Trans->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i38,
              &dj_emlrtBCI, sp) - 1)) + Trans->size[0] * Trans->size[1] *
                         (emlrtDynamicBoundsCheckFastR2012b(i + 2, 1, i39,
              &ej_emlrtBCI, sp) - 1)) - 1] = 0.1;
          }
        }

        loop_ub++;
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
      }

      b_Pitch++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  /*  Overal balance between Local and Transition costs */
  /* 'dynamic:93' Trans = Trans/dp_w4; */
  i37 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i37, (int32_T)sizeof(real_T),
                    &md_emlrtRTEI);
  b_Pitch = Trans->size[0];
  loop_ub = Trans->size[1];
  i = Trans->size[2];
  loop_ub = b_Pitch * loop_ub * i;
  for (i37 = 0; i37 < loop_ub; i37++) {
    Trans->data[i37] /= 0.9;
  }

  /*  Find the minimum cost path thru Pitch_Array using the Local and Trans costs */
  /* 'dynamic:96' Path = path1(Local,Trans); */
  st.site = &hj_emlrtRSI;

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
  if (Local->size[0] >= 500) {
    /* if M is greater than 100, stop the routine; */
    b_st.site = &ij_emlrtRSI;
    e_error(&b_st);
  }

  /* 'path1:33' if N>=5000 */
  if (Local->size[1] >= 5000) {
    /* if N is greater than 1000, stop the routine; */
    b_st.site = &ng_emlrtRSI;
    c_error(&b_st);
  }

  emxInit_real_T(&st, &PRED, 2, &jc_emlrtRTEI, true);

  /* 'path1:38' PRED=ones(M,N); */
  b_Pitch = Local->size[0];
  i37 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = b_Pitch;
  emxEnsureCapacity(&st, (emxArray__common *)PRED, i37, (int32_T)sizeof(real_T),
                    &md_emlrtRTEI);
  b_Pitch = Local->size[1];
  i37 = PRED->size[0] * PRED->size[1];
  PRED->size[1] = b_Pitch;
  emxEnsureCapacity(&st, (emxArray__common *)PRED, i37, (int32_T)sizeof(real_T),
                    &md_emlrtRTEI);
  loop_ub = Local->size[0] * Local->size[1];
  for (i37 = 0; i37 < loop_ub; i37++) {
    PRED->data[i37] = 1.0;
  }

  /* initializing several desired matrix; */
  /* 'path1:39' P=ones(1,N); */
  unnamed_idx_1 = Local->size[1];
  loop_ub = Local->size[1];
  for (i37 = 0; i37 < loop_ub; i37++) {
    P_data[i37] = 1.0;
  }

  /* 'path1:40' p=zeros(1,N); */
  b_unnamed_idx_1 = Local->size[1];
  loop_ub = Local->size[1];
  for (i37 = 0; i37 < loop_ub; i37++) {
    p_data[i37] = 0.0;
  }

  /* PATH=zeros(1,N); */
  /* 'path1:42' PCOST = zeros(1,M); */
  c_unnamed_idx_1 = Local->size[0];
  loop_ub = Local->size[0];
  for (i37 = 0; i37 < loop_ub; i37++) {
    PCOST_data[i37] = 0.0;
  }

  /* 'path1:43' CCOST = zeros(1,M); */
  d_unnamed_idx_1 = Local->size[0];
  loop_ub = Local->size[0];
  for (i37 = 0; i37 < loop_ub; i37++) {
    CCOST_data[i37] = 0.0;
  }

  /* 'path1:45' for J=1:M */
  b_Pitch = 1;
  while (b_Pitch - 1 <= Local->size[0] - 1) {
    /* initializing the previous costs; */
    /* 'path1:46' PCOST(J)=Local(J,1); */
    i37 = Local->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i37, &xe_emlrtBCI, &st);
    i37 = Local->size[0];
    PCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, c_unnamed_idx_1,
      &di_emlrtBCI, &st) - 1] = Local->data[emlrtDynamicBoundsCheckFastR2012b
      (b_Pitch, 1, i37, &ei_emlrtBCI, &st) - 1];
    b_Pitch++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
  }

  /* 'path1:49' for I=2:N */
  I = 2;
  while (I - 2 <= Local->size[1] - 2) {
    /* this loop is doing the heart work of this routine. That means to */
    /* 'path1:50' for J=1:M */
    b_Pitch = 1;
    while (b_Pitch - 1 <= Local->size[0] - 1) {
      /* 'path1:51' CCOST(J)=1.0E+30; */
      CCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, d_unnamed_idx_1,
        &oh_emlrtBCI, &st) - 1] = 1.0E+30;

      /* get the lowest cost path; */
      /* 'path1:53' for K=1:M */
      i = 1;
      while (i - 1 <= Local->size[0] - 1) {
        /* 'path1:54' if PCOST(K)+Trans(K,J,I)<=CCOST(J) */
        i37 = Trans->size[0];
        i38 = Trans->size[1];
        i39 = Trans->size[2];
        if (PCOST_data[emlrtDynamicBoundsCheckFastR2012b(i, 1, c_unnamed_idx_1,
             &th_emlrtBCI, &st) - 1] + Trans->data
            [((emlrtDynamicBoundsCheckFastR2012b(i, 1, i37, &uh_emlrtBCI, &st) +
               Trans->size[0] * (emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1,
                i38, &vh_emlrtBCI, &st) - 1)) + Trans->size[0] * Trans->size[1] *
              (emlrtDynamicBoundsCheckFastR2012b(I, 1, i39, &pf_emlrtBCI, &st) -
               1)) - 1] <= CCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch,
             1, d_unnamed_idx_1, &wh_emlrtBCI, &st) - 1]) {
          /* deciding the optimal path between two points in two next column;  */
          /* 'path1:55' CCOST(J)=PCOST(K)+Trans(K,J,I); */
          i37 = Trans->size[0];
          i38 = Trans->size[1];
          i39 = Trans->size[2];
          CCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1,
            d_unnamed_idx_1, &xh_emlrtBCI, &st) - 1] =
            PCOST_data[emlrtDynamicBoundsCheckFastR2012b(i, 1, c_unnamed_idx_1,
            &yh_emlrtBCI, &st) - 1] + Trans->data
            [((emlrtDynamicBoundsCheckFastR2012b(i, 1, i37, &ai_emlrtBCI, &st) +
               Trans->size[0] * (emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1,
                 i38, &bi_emlrtBCI, &st) - 1)) + Trans->size[0] * Trans->size[1]
              * (emlrtDynamicBoundsCheckFastR2012b(I, 1, i39, &qf_emlrtBCI, &st)
                 - 1)) - 1];

          /* 'path1:56' PRED(J,I)=K; */
          i37 = PRED->size[0];
          i38 = PRED->size[1];
          PRED->data[(emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i37,
            &ci_emlrtBCI, &st) + PRED->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(I, 1, i38, &rf_emlrtBCI,
            &st) - 1)) - 1] = 1.0 + (real_T)(i - 1);

          /* this line is very importent, used to mark the chosen points; */
        }

        i++;
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
      }

      /* 'path1:60' if CCOST(J)>=1.0E+30 */
      if (CCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1,
           d_unnamed_idx_1, &ph_emlrtBCI, &st) - 1] >= 1.0E+30) {
        b_st.site = &og_emlrtRSI;
        d_error(&b_st);
      }

      /* 'path1:64' CCOST(J)=CCOST(J)+Local(J,I); */
      i37 = Local->size[0];
      i38 = Local->size[1];
      CCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, d_unnamed_idx_1,
        &qh_emlrtBCI, &st) - 1] = CCOST_data[emlrtDynamicBoundsCheckFastR2012b
        (b_Pitch, 1, d_unnamed_idx_1, &rh_emlrtBCI, &st) - 1] + Local->data
        [(emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, i37, &sh_emlrtBCI, &st)
          + Local->size[0] * (emlrtDynamicBoundsCheckFastR2012b(I, 1, i38,
            &of_emlrtBCI, &st) - 1)) - 1];

      /* new cost is gotten by the adding of Local cost and current cost; */
      b_Pitch++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
    }

    /* 'path1:68' for J=1:M */
    b_Pitch = 1;
    while (b_Pitch - 1 <= Local->size[0] - 1) {
      /* 'path1:69' PCOST(J)=CCOST(J); */
      PCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1, c_unnamed_idx_1,
        &mh_emlrtBCI, &st) - 1] = CCOST_data[emlrtDynamicBoundsCheckFastR2012b
        (b_Pitch, 1, d_unnamed_idx_1, &nh_emlrtBCI, &st) - 1];

      /* using the new current cost to update the previous cost; */
      b_Pitch++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
    }

    /* 'path1:72' p(I)=1; */
    p_data[emlrtDynamicBoundsCheckFastR2012b(I, 1, b_unnamed_idx_1, &mf_emlrtBCI,
      &st) - 1] = 1.0;

    /* 'path1:73' for J=2:M */
    b_Pitch = 0;
    while (b_Pitch <= Local->size[0] - 2) {
      /* obtaining the points with lowest cost in every column; */
      /* 'path1:74' if CCOST(J)<=CCOST(1) */
      if (CCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch + 2, 1,
           d_unnamed_idx_1, &kh_emlrtBCI, &st) - 1] <= CCOST_data[0]) {
        /* 'path1:75' CCOST(1)=CCOST(J); */
        CCOST_data[0] = CCOST_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch + 2,
          1, d_unnamed_idx_1, &lh_emlrtBCI, &st) - 1];

        /* 'path1:75' p(I)=J; */
        p_data[emlrtDynamicBoundsCheckFastR2012b(I, 1, b_unnamed_idx_1,
          &nf_emlrtBCI, &st) - 1] = 2.0 + (real_T)b_Pitch;
      }

      b_Pitch++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
    }

    I++;
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
  c_unnamed_idx_1 = Local->size[1];
  i37 = Local->size[1];
  i38 = Local->size[1];
  P_data[emlrtDynamicBoundsCheckFastR2012b(i37, 1, c_unnamed_idx_1, &cf_emlrtBCI,
    &st) - 1] = p_data[emlrtDynamicBoundsCheckFastR2012b(i38, 1, b_unnamed_idx_1,
    &df_emlrtBCI, &st) - 1];

  /* 'path1:99' for I=N-1:-1:1 */
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &wd_emlrtRTEI, &st);
  I = 0;
  while (I <= Local->size[1] - 2) {
    b_Pitch = Local->size[1] - I;

    /* using this loop to get the path finally; from the last point going */
    /* 'path1:100' P(I)=PRED(P(I+1),I+1); */
    i37 = b_Pitch - 1;
    i38 = PRED->size[0];
    i39 = (int32_T)P_data[emlrtDynamicBoundsCheckFastR2012b(b_Pitch, 1,
      unnamed_idx_1, &kf_emlrtBCI, &st) - 1];
    loop_ub = PRED->size[1];
    P_data[emlrtDynamicBoundsCheckFastR2012b(i37, 1, unnamed_idx_1, &if_emlrtBCI,
      &st) - 1] = PRED->data[(emlrtDynamicBoundsCheckFastR2012b(i39, 1, i38,
      &jh_emlrtBCI, &st) + PRED->size[0] * (emlrtDynamicBoundsCheckFastR2012b
      (b_Pitch, 1, loop_ub, &lf_emlrtBCI, &st) - 1)) - 1];

    /* backward to find the previous points, etc; */
    I++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
  }

  emxFree_real_T(&PRED);
  emxFree_real_T(&Local);

  /* 'path1:102' PATH=P; */
  /* getting the final path.  */
  /* extracting the pitch, using Path */
  /* 'dynamic:99' FinPitch = zeros(1,numframes); */
  i37 = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, i37, (int32_T)sizeof
                    (real_T), &md_emlrtRTEI);
  b_unnamed_idx_1 = Pitch->size[1];
  i37 = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[1] = b_unnamed_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, i37, (int32_T)sizeof
                    (real_T), &md_emlrtRTEI);
  loop_ub = Pitch->size[1];
  for (i37 = 0; i37 < loop_ub; i37++) {
    FinPitch->data[i37] = 0.0;
  }

  /* 'dynamic:100' for i = 1:numframes */
  i = 1;
  while (i - 1 <= Pitch->size[1] - 1) {
    /* 'dynamic:101' FinPitch(i) = Pitch(Path(i),i); */
    i37 = FinPitch->size[1];
    i38 = Pitch->size[0];
    i39 = (int32_T)P_data[emlrtDynamicBoundsCheckFastR2012b(i, 1, unnamed_idx_1,
      &hh_emlrtBCI, sp) - 1];
    loop_ub = Pitch->size[1];
    FinPitch->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i37, &fh_emlrtBCI, sp)
      - 1] = Pitch->data[(emlrtDynamicBoundsCheckFastR2012b(i39, 1, i38,
      &gh_emlrtBCI, sp) + Pitch->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i,
      1, loop_ub, &ih_emlrtBCI, sp) - 1)) - 1];
    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (dynamic.c) */
