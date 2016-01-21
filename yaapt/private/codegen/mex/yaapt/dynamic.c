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
#include "nonlinear.h"
#include "mean.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo dm_emlrtRSI = { 50, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRSInfo em_emlrtRSI = { 96, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRSInfo fm_emlrtRSI = { 31, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo jd_emlrtRTEI = { 1, 23, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRTEInfo kd_emlrtRTEI = { 63, 1, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRTEInfo ld_emlrtRTEI = { 66, 1, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRTEInfo md_emlrtRTEI = { 42, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtRTEInfo nd_emlrtRTEI = { 43, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 75, 13, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 74, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 80, 50, "Energy", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 80, 38, "Energy", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 75, 62, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 75, 60, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 75, 51, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 75, 49, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 49, 20, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 50, 19, "BestPitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 101, 23, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 101, 23, "Path", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 101, 31, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 101, 3, "FinPitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 100, 14, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 74, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 75, 22, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 69, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo di_emlrtBCI = { -1, -1, 69, 9, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 51, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 60, 12, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 64, 18, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 64, 33, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ii_emlrtBCI = { -1, -1, 64, 9, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 54, 16, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ki_emlrtBCI = { -1, -1, 54, 31, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo li_emlrtBCI = { -1, -1, 54, 33, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo mi_emlrtBCI = { -1, -1, 54, 39, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ni_emlrtBCI = { -1, -1, 55, 26, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo oi_emlrtBCI = { -1, -1, 55, 41, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo pi_emlrtBCI = { -1, -1, 55, 43, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo qi_emlrtBCI = { -1, -1, 55, 17, "CCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ri_emlrtBCI = { -1, -1, 56, 22, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo si_emlrtBCI = { -1, -1, 46, 20, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ti_emlrtBCI = { -1, -1, 46, 5, "PCOST", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

static emlrtBCInfo ui_emlrtBCI = { -1, -1, 74, 24, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo vi_emlrtBCI = { -1, -1, 74, 26, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo wi_emlrtBCI = { -1, -1, 74, 44, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo xi_emlrtBCI = { -1, -1, 74, 46, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo yi_emlrtBCI = { -1, -1, 75, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo aj_emlrtBCI = { -1, -1, 75, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo bj_emlrtBCI = { -1, -1, 75, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo cj_emlrtBCI = { -1, -1, 79, 23, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo dj_emlrtBCI = { -1, -1, 79, 25, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ej_emlrtBCI = { -1, -1, 79, 40, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo fj_emlrtBCI = { -1, -1, 79, 42, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo gj_emlrtBCI = { -1, -1, 79, 60, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo hj_emlrtBCI = { -1, -1, 79, 62, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ij_emlrtBCI = { -1, -1, 79, 76, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo jj_emlrtBCI = { -1, -1, 79, 78, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo kj_emlrtBCI = { -1, -1, 81, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo lj_emlrtBCI = { -1, -1, 81, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo mj_emlrtBCI = { -1, -1, 81, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo nj_emlrtBCI = { -1, -1, 85, 24, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo oj_emlrtBCI = { -1, -1, 85, 26, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo pj_emlrtBCI = { -1, -1, 85, 45, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo qj_emlrtBCI = { -1, -1, 85, 47, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo rj_emlrtBCI = { -1, -1, 86, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo sj_emlrtBCI = { -1, -1, 86, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo tj_emlrtBCI = { -1, -1, 86, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

/* Function Definitions */

/*
 * function [FinPitch] = dynamic(Pitch, Merit, Energy, Prm)
 */
void dynamic(const emlrtStack *sp, const emxArray_real_T *Pitch, const
             emxArray_real_T *Merit, const emxArray_real_T *Energy,
             emxArray_real_T *FinPitch)
{
  emxArray_int32_T *r27;
  int32_T numframes;
  int32_T numcands;
  int32_T i46;
  int32_T i47;
  int32_T end;
  int32_T trueCount;
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
  static const char_T varargin_1[28] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ',
    'M', '>', '1', '0', '0' };

  char_T u[28];
  const mxArray *y;
  static const int32_T iv42[2] = { 1, 28 };

  const mxArray *m9;
  static const char_T b_varargin_1[29] = { 'S', 't', 'o', 'p', ' ', 'i', 'n',
    ' ', 'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o',
    ' ', 'N', '>', '1', '0', '0', '0' };

  char_T b_u[29];
  const mxArray *b_y;
  static const int32_T iv43[2] = { 1, 29 };

  emxArray_real_T *PRED;
  emxArray_real_T *P;
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
  static const int32_T iv44[2] = { 1, 30 };

  int32_T b_I;
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
  emxInit_int32_T1(sp, &r27, 2, &jd_emlrtRTEI, true);

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
  i46 = Pitch->size[0];
  i47 = (int32_T)((real_T)Pitch->size[0] - 1.0);
  if (!((i47 >= 1) && (i47 <= i46))) {
    emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &sh_emlrtBCI, sp);
  }

  /* 'dynamic:50' mean_pitch = mean(BestPitch(BestPitch>0)); */
  end = Pitch->size[1] - 1;
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    if (Pitch->data[(numcands + Pitch->size[0] * i) - 1] > 0.0) {
      trueCount++;
    }
  }

  i46 = r27->size[0] * r27->size[1];
  r27->size[0] = 1;
  r27->size[1] = trueCount;
  emxEnsureCapacity(sp, (emxArray__common *)r27, i46, (int32_T)sizeof(int32_T),
                    &jd_emlrtRTEI);
  partialTrueCount = 0;
  for (i = 0; i <= end; i++) {
    if (Pitch->data[(numcands + Pitch->size[0] * i) - 1] > 0.0) {
      r27->data[partialTrueCount] = i + 1;
      partialTrueCount++;
    }
  }

  emxInit_real_T(sp, &b_Pitch, 2, &jd_emlrtRTEI, true);
  emxInit_real_T(sp, &c_Pitch, 2, &jd_emlrtRTEI, true);
  i46 = Pitch->size[1];
  partialTrueCount = Pitch->size[1];
  end = Pitch->size[0];
  i47 = c_Pitch->size[0] * c_Pitch->size[1];
  c_Pitch->size[0] = 1;
  c_Pitch->size[1] = partialTrueCount;
  emxEnsureCapacity(sp, (emxArray__common *)c_Pitch, i47, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  for (i47 = 0; i47 < partialTrueCount; i47++) {
    c_Pitch->data[c_Pitch->size[0] * i47] = Pitch->data[(end + Pitch->size[0] *
      i47) - 2];
  }

  i47 = b_Pitch->size[0] * b_Pitch->size[1];
  b_Pitch->size[0] = 1;
  b_Pitch->size[1] = r27->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i47, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = r27->size[1];
  for (i47 = 0; i47 < partialTrueCount; i47++) {
    trueCount = r27->data[r27->size[0] * i47];
    if (!((trueCount >= 1) && (trueCount <= i46))) {
      emlrtDynamicBoundsCheckR2012b(trueCount, 1, i46, &th_emlrtBCI, sp);
    }

    b_Pitch->data[b_Pitch->size[0] * i47] = c_Pitch->data[trueCount - 1];
  }

  emxFree_real_T(&c_Pitch);
  emxFree_int32_T(&r27);
  emxInit_real_T(sp, &Local, 2, &kd_emlrtRTEI, true);
  st.site = &dm_emlrtRSI;
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
  i46 = Local->size[0] * Local->size[1];
  Local->size[0] = Merit->size[0];
  Local->size[1] = Merit->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Local, i46, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = Merit->size[0] * Merit->size[1];
  emxFree_real_T(&b_Pitch);
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    Local->data[i46] = 1.0 - Merit->data[i46];
  }

  emxInit_real_T2(sp, &Trans, 3, &ld_emlrtRTEI, true);

  /*  Initialization for the formation of the transition cost matrix */
  /* 'dynamic:66' Trans  = ones(numcands,numcands,numframes); */
  i46 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = Pitch->size[0];
  Trans->size[1] = Pitch->size[0];
  Trans->size[2] = Pitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i46, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = Pitch->size[0] * Pitch->size[0] * Pitch->size[1];
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    Trans->data[i46] = 1.0;
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
        i46 = Pitch->size[0];
        if (!((j >= 1) && (j <= i46))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i46, &ui_emlrtBCI, sp);
        }

        i46 = Pitch->size[1];
        if (!((i + 2 >= 1) && (i + 2 <= i46))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i46, &vi_emlrtBCI, sp);
        }

        if (Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1] > 0.0) {
          i46 = Pitch->size[0];
          if (!((k >= 1) && (k <= i46))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i46, &wi_emlrtBCI, sp);
          }

          i46 = Pitch->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= i46))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i46, &xi_emlrtBCI, sp);
          }

          if (Pitch->data[(k + Pitch->size[0] * i) - 1] > 0.0) {
            /* 'dynamic:75' Trans(k,j,i) = dp_w1*(abs(Pitch(j,i)-Pitch(k,i-1))/mean_pitch); */
            i46 = Pitch->size[0];
            i47 = (j - 1) + 1;
            if (!((i47 >= 1) && (i47 <= i46))) {
              emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &rh_emlrtBCI, sp);
            }

            i46 = Pitch->size[1];
            i47 = (int32_T)(2.0 + (real_T)i);
            if (!((i47 >= 1) && (i47 <= i46))) {
              emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &qh_emlrtBCI, sp);
            }

            i46 = Pitch->size[0];
            i47 = (k - 1) + 1;
            if (!((i47 >= 1) && (i47 <= i46))) {
              emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &ph_emlrtBCI, sp);
            }

            i46 = Pitch->size[1];
            i47 = (int32_T)((2.0 + (real_T)i) - 1.0);
            if (!((i47 >= 1) && (i47 <= i46))) {
              emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &oh_emlrtBCI, sp);
            }

            i46 = Trans->size[0];
            if (!((k >= 1) && (k <= i46))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i46, &yi_emlrtBCI, sp);
            }

            i46 = Trans->size[1];
            if (!((j >= 1) && (j <= i46))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i46, &aj_emlrtBCI, sp);
            }

            i46 = Trans->size[2];
            if (!((i + 2 >= 1) && (i + 2 <= i46))) {
              emlrtDynamicBoundsCheckR2012b(i + 2, 1, i46, &bj_emlrtBCI, sp);
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
        i46 = Pitch->size[0];
        if (!((j >= 1) && (j <= i46))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i46, &cj_emlrtBCI, sp);
        }

        i46 = Pitch->size[1];
        if (!((i + 2 >= 1) && (i + 2 <= i46))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i46, &dj_emlrtBCI, sp);
        }

        guard1 = false;
        guard2 = false;
        if (Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1] == 0.0) {
          i46 = Pitch->size[0];
          if (!((k >= 1) && (k <= i46))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i46, &ej_emlrtBCI, sp);
          }

          i46 = Pitch->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= i46))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i46, &fj_emlrtBCI, sp);
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
          i46 = Pitch->size[0];
          if (!((j >= 1) && (j <= i46))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i46, &gj_emlrtBCI, sp);
          }

          i46 = Pitch->size[1];
          if (!((i + 2 >= 1) && (i + 2 <= i46))) {
            emlrtDynamicBoundsCheckR2012b(i + 2, 1, i46, &hj_emlrtBCI, sp);
          }

          if (Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1] > 0.0) {
            i46 = Pitch->size[0];
            if (!((k >= 1) && (k <= i46))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i46, &ij_emlrtBCI, sp);
            }

            i46 = Pitch->size[1];
            if (!((i + 1 >= 1) && (i + 1 <= i46))) {
              emlrtDynamicBoundsCheckR2012b(i + 1, 1, i46, &jj_emlrtBCI, sp);
            }

            if (Pitch->data[(k + Pitch->size[0] * i) - 1] == 0.0) {
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* 'dynamic:80' benefit = min(1, abs(Energy(i-1)-Energy(i))); */
          i46 = Energy->size[1];
          i47 = (int32_T)((2.0 + (real_T)i) - 1.0);
          if (!((i47 >= 1) && (i47 <= i46))) {
            emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &nh_emlrtBCI, sp);
          }

          i46 = Energy->size[1];
          i47 = (int32_T)(2.0 + (real_T)i);
          if (!((i47 >= 1) && (i47 <= i46))) {
            emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &mh_emlrtBCI, sp);
          }

          /* 'dynamic:81' Trans(k,j,i) =  dp_w2*(1-benefit); */
          i46 = Trans->size[0];
          if (!((k >= 1) && (k <= i46))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i46, &kj_emlrtBCI, sp);
          }

          i46 = Trans->size[1];
          if (!((j >= 1) && (j <= i46))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i46, &lj_emlrtBCI, sp);
          }

          i46 = Trans->size[2];
          if (!((i + 2 >= 1) && (i + 2 <= i46))) {
            emlrtDynamicBoundsCheckR2012b(i + 2, 1, i46, &mj_emlrtBCI, sp);
          }

          Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                       Trans->size[1] * (i + 1)) - 1] = 0.5 * (1.0 -
            muDoubleScalarMin(1.0, muDoubleScalarAbs(Energy->data[i] -
            Energy->data[i + 1])));
        }

        /*  both candidates are unvoiced */
        /* 'dynamic:85' if ((Pitch(j,i) == 0) && (Pitch(k,i-1) == 0)) */
        i46 = Pitch->size[0];
        if (!((j >= 1) && (j <= i46))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i46, &nj_emlrtBCI, sp);
        }

        i46 = Pitch->size[1];
        if (!((i + 2 >= 1) && (i + 2 <= i46))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i46, &oj_emlrtBCI, sp);
        }

        if (Pitch->data[(j + Pitch->size[0] * (i + 1)) - 1] == 0.0) {
          i46 = Pitch->size[0];
          if (!((k >= 1) && (k <= i46))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i46, &pj_emlrtBCI, sp);
          }

          i46 = Pitch->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= i46))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i46, &qj_emlrtBCI, sp);
          }

          if (Pitch->data[(k + Pitch->size[0] * i) - 1] == 0.0) {
            /* 'dynamic:86' Trans(k,j,i) =  dp_w3; */
            i46 = Trans->size[0];
            if (!((k >= 1) && (k <= i46))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i46, &rj_emlrtBCI, sp);
            }

            i46 = Trans->size[1];
            if (!((j >= 1) && (j <= i46))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i46, &sj_emlrtBCI, sp);
            }

            i46 = Trans->size[2];
            if (!((i + 2 >= 1) && (i + 2 <= i46))) {
              emlrtDynamicBoundsCheckR2012b(i + 2, 1, i46, &tj_emlrtBCI, sp);
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
  i46 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, i46, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = Trans->size[0];
  trueCount = Trans->size[1];
  end = Trans->size[2];
  partialTrueCount = partialTrueCount * trueCount * end;
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    Trans->data[i46] /= 0.9;
  }

  /*  Find the minimum cost path thru Pitch_Array using the Local and Trans costs */
  /* 'dynamic:96' Path = path1(Local,Trans); */
  st.site = &em_emlrtRSI;

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
    b_st.site = &fm_emlrtRSI;
    for (i46 = 0; i46 < 28; i46++) {
      u[i46] = varargin_1[i46];
    }

    y = NULL;
    m9 = emlrtCreateCharArray(2, iv42);
    emlrtInitCharArrayR2013a(&b_st, 28, m9, &u[0]);
    emlrtAssign(&y, m9);
    c_st.site = &nm_emlrtRSI;
    n_error(&c_st, y, &emlrtMCI);
  }

  /* 'path1:33' if N>=5000 */
  if (Local->size[1] >= 5000) {
    /* if N is greater than 1000, stop the routine; */
    b_st.site = &ci_emlrtRSI;
    for (i46 = 0; i46 < 29; i46++) {
      b_u[i46] = b_varargin_1[i46];
    }

    b_y = NULL;
    m9 = emlrtCreateCharArray(2, iv43);
    emlrtInitCharArrayR2013a(&b_st, 29, m9, &b_u[0]);
    emlrtAssign(&b_y, m9);
    c_st.site = &nm_emlrtRSI;
    n_error(&c_st, b_y, &emlrtMCI);
  }

  emxInit_real_T(&st, &PRED, 2, &ec_emlrtRTEI, true);

  /* 'path1:38' PRED=ones(M,N); */
  i46 = PRED->size[0] * PRED->size[1];
  PRED->size[0] = Local->size[0];
  PRED->size[1] = Local->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)PRED, i46, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = Local->size[0] * Local->size[1];
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    PRED->data[i46] = 1.0;
  }

  emxInit_real_T(&st, &P, 2, &fc_emlrtRTEI, true);

  /* initializing several desired matrix; */
  /* 'path1:39' P=ones(1,N); */
  i46 = P->size[0] * P->size[1];
  P->size[0] = 1;
  P->size[1] = Local->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)P, i46, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = Local->size[1];
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    P->data[i46] = 1.0;
  }

  emxInit_real_T(&st, &p, 2, &gc_emlrtRTEI, true);

  /* 'path1:40' p=zeros(1,N); */
  i46 = p->size[0] * p->size[1];
  p->size[0] = 1;
  p->size[1] = Local->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)p, i46, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = Local->size[1];
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    p->data[i46] = 0.0;
  }

  emxInit_real_T(&st, &PCOST, 2, &md_emlrtRTEI, true);

  /* PATH=zeros(1,N); */
  /* 'path1:42' PCOST = zeros(1,M); */
  i46 = PCOST->size[0] * PCOST->size[1];
  PCOST->size[0] = 1;
  PCOST->size[1] = Local->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)PCOST, i46, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = Local->size[0];
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    PCOST->data[i46] = 0.0;
  }

  emxInit_real_T(&st, &CCOST, 2, &nd_emlrtRTEI, true);

  /* 'path1:43' CCOST = zeros(1,M); */
  i46 = CCOST->size[0] * CCOST->size[1];
  CCOST->size[0] = 1;
  CCOST->size[1] = Local->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)CCOST, i46, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  partialTrueCount = Local->size[0];
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    CCOST->data[i46] = 0.0;
  }

  /* 'path1:45' for J=1:M */
  J = 1;
  while (J - 1 <= M) {
    /* initializing the previous costs; */
    /* 'path1:46' PCOST(J)=Local(J,1); */
    i46 = Local->size[1];
    if (!(1 <= i46)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i46, &sd_emlrtBCI, &st);
    }

    i46 = Local->size[0];
    if (!((J >= 1) && (J <= i46))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, i46, &si_emlrtBCI, &st);
    }

    i46 = PCOST->size[1];
    if (!((J >= 1) && (J <= i46))) {
      emlrtDynamicBoundsCheckR2012b(J, 1, i46, &ti_emlrtBCI, &st);
    }

    PCOST->data[J - 1] = Local->data[J - 1];
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
      i46 = CCOST->size[1];
      if (!((J >= 1) && (J <= i46))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i46, &ei_emlrtBCI, &st);
      }

      CCOST->data[J - 1] = 1.0E+30;

      /* get the lowest cost path; */
      /* 'path1:53' for K=1:M */
      K = 1;
      while (K - 1 <= M) {
        /* 'path1:54' if PCOST(K)+Trans(K,J,I)<=CCOST(J) */
        i46 = PCOST->size[1];
        if (!((K >= 1) && (K <= i46))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, i46, &ji_emlrtBCI, &st);
        }

        i46 = Trans->size[0];
        if (!((K >= 1) && (K <= i46))) {
          emlrtDynamicBoundsCheckR2012b(K, 1, i46, &ki_emlrtBCI, &st);
        }

        i46 = Trans->size[1];
        if (!((J >= 1) && (J <= i46))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, i46, &li_emlrtBCI, &st);
        }

        i46 = Trans->size[2];
        if (!((I >= 1) && (I <= i46))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i46, &je_emlrtBCI, &st);
        }

        i46 = CCOST->size[1];
        if (!((J >= 1) && (J <= i46))) {
          emlrtDynamicBoundsCheckR2012b(J, 1, i46, &mi_emlrtBCI, &st);
        }

        if (PCOST->data[K - 1] + Trans->data[((K + Trans->size[0] * (J - 1)) +
             Trans->size[0] * Trans->size[1] * (I - 1)) - 1] <= CCOST->data[J -
            1]) {
          /* deciding the optimal path between two points in two next column;  */
          /* 'path1:55' CCOST(J)=PCOST(K)+Trans(K,J,I); */
          i46 = PCOST->size[1];
          if (!((K >= 1) && (K <= i46))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, i46, &ni_emlrtBCI, &st);
          }

          i46 = Trans->size[0];
          if (!((K >= 1) && (K <= i46))) {
            emlrtDynamicBoundsCheckR2012b(K, 1, i46, &oi_emlrtBCI, &st);
          }

          i46 = Trans->size[1];
          if (!((J >= 1) && (J <= i46))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i46, &pi_emlrtBCI, &st);
          }

          i46 = Trans->size[2];
          if (!((I >= 1) && (I <= i46))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i46, &ke_emlrtBCI, &st);
          }

          i46 = CCOST->size[1];
          if (!((J >= 1) && (J <= i46))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i46, &qi_emlrtBCI, &st);
          }

          CCOST->data[J - 1] = PCOST->data[K - 1] + Trans->data[((K +
            Trans->size[0] * (J - 1)) + Trans->size[0] * Trans->size[1] * (I - 1))
            - 1];

          /* 'path1:56' PRED(J,I)=K; */
          i46 = PRED->size[0];
          if (!((J >= 1) && (J <= i46))) {
            emlrtDynamicBoundsCheckR2012b(J, 1, i46, &ri_emlrtBCI, &st);
          }

          i46 = PRED->size[1];
          if (!((I >= 1) && (I <= i46))) {
            emlrtDynamicBoundsCheckR2012b(I, 1, i46, &le_emlrtBCI, &st);
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
      i46 = CCOST->size[1];
      if (!((J >= 1) && (J <= i46))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i46, &fi_emlrtBCI, &st);
      }

      if (CCOST->data[J - 1] >= 1.0E+30) {
        b_st.site = &di_emlrtRSI;
        for (i46 = 0; i46 < 30; i46++) {
          c_u[i46] = c_varargin_1[i46];
        }

        c_y = NULL;
        m9 = emlrtCreateCharArray(2, iv44);
        emlrtInitCharArrayR2013a(&b_st, 30, m9, &c_u[0]);
        emlrtAssign(&c_y, m9);
        c_st.site = &nm_emlrtRSI;
        n_error(&c_st, c_y, &emlrtMCI);
      }

      /* 'path1:64' CCOST(J)=CCOST(J)+Local(J,I); */
      i46 = CCOST->size[1];
      if (!((J >= 1) && (J <= i46))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i46, &gi_emlrtBCI, &st);
      }

      i46 = Local->size[0];
      if (!((J >= 1) && (J <= i46))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i46, &hi_emlrtBCI, &st);
      }

      i46 = Local->size[1];
      if (!((I >= 1) && (I <= i46))) {
        emlrtDynamicBoundsCheckR2012b(I, 1, i46, &ie_emlrtBCI, &st);
      }

      i46 = CCOST->size[1];
      if (!((J >= 1) && (J <= i46))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i46, &ii_emlrtBCI, &st);
      }

      CCOST->data[J - 1] += Local->data[(J + Local->size[0] * (I - 1)) - 1];

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
      i46 = CCOST->size[1];
      if (!((J >= 1) && (J <= i46))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i46, &ci_emlrtBCI, &st);
      }

      i46 = PCOST->size[1];
      if (!((J >= 1) && (J <= i46))) {
        emlrtDynamicBoundsCheckR2012b(J, 1, i46, &di_emlrtBCI, &st);
      }

      PCOST->data[J - 1] = CCOST->data[J - 1];

      /* using the new current cost to update the previous cost; */
      J++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* 'path1:72' p(I)=1; */
    i46 = p->size[1];
    if (!((I >= 1) && (I <= i46))) {
      emlrtDynamicBoundsCheckR2012b(I, 1, i46, &ge_emlrtBCI, &st);
    }

    p->data[I - 1] = 1.0;

    /* 'path1:73' for J=2:M */
    J = 0;
    while (J <= M - 1) {
      /* obtaining the points with lowest cost in every column; */
      /* 'path1:74' if CCOST(J)<=CCOST(1) */
      i46 = CCOST->size[1];
      if (!(1 <= i46)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i46, &lh_emlrtBCI, &st);
      }

      i46 = CCOST->size[1];
      if (!((J + 2 >= 1) && (J + 2 <= i46))) {
        emlrtDynamicBoundsCheckR2012b(J + 2, 1, i46, &ai_emlrtBCI, &st);
      }

      if (CCOST->data[J + 1] <= CCOST->data[0]) {
        /* 'path1:75' CCOST(1)=CCOST(J); */
        i46 = CCOST->size[1];
        if (!(1 <= i46)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i46, &kh_emlrtBCI, &st);
        }

        i46 = CCOST->size[1];
        if (!((J + 2 >= 1) && (J + 2 <= i46))) {
          emlrtDynamicBoundsCheckR2012b(J + 2, 1, i46, &bi_emlrtBCI, &st);
        }

        CCOST->data[0] = CCOST->data[J + 1];

        /* 'path1:75' p(I)=J; */
        i46 = p->size[1];
        if (!((I >= 1) && (I <= i46))) {
          emlrtDynamicBoundsCheckR2012b(I, 1, i46, &he_emlrtBCI, &st);
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

  emxFree_real_T(&CCOST);
  emxFree_real_T(&PCOST);
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
  trueCount = Local->size[1];
  i46 = p->size[1];
  i47 = Local->size[1];
  if (!((i47 >= 1) && (i47 <= i46))) {
    emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &vd_emlrtBCI, &st);
  }

  i46 = Local->size[1];
  if (!((i46 >= 1) && (i46 <= trueCount))) {
    emlrtDynamicBoundsCheckR2012b(i46, 1, trueCount, &wd_emlrtBCI, &st);
  }

  P->data[i46 - 1] = p->data[i47 - 1];

  /* 'path1:99' for I=N-1:-1:1 */
  emlrtForLoopVectorCheckR2012b((real_T)Local->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, Local->size[1] - 1, &bf_emlrtRTEI, &st);
  I = 0;
  emxFree_real_T(&p);
  while (I <= Local->size[1] - 2) {
    b_I = N - I;

    /* using this loop to get the path finally; from the last point going */
    /* 'path1:100' P(I)=PRED(P(I+1),I+1); */
    i46 = PRED->size[0];
    i47 = P->size[1];
    if (!((b_I >= 1) && (b_I <= i47))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, i47, &de_emlrtBCI, &st);
    }

    i47 = (int32_T)P->data[b_I - 1];
    if (!((i47 >= 1) && (i47 <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &yh_emlrtBCI, &st);
    }

    i46 = PRED->size[1];
    if (!((b_I >= 1) && (b_I <= i46))) {
      emlrtDynamicBoundsCheckR2012b(b_I, 1, i46, &ee_emlrtBCI, &st);
    }

    i46 = P->size[1];
    trueCount = b_I - 1;
    if (!((trueCount >= 1) && (trueCount <= i46))) {
      emlrtDynamicBoundsCheckR2012b(trueCount, 1, i46, &fe_emlrtBCI, &st);
    }

    P->data[trueCount - 1] = PRED->data[(i47 + PRED->size[0] * (b_I - 1)) - 1];

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
  i46 = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, i46, (int32_T)sizeof
                    (real_T), &jd_emlrtRTEI);
  partialTrueCount = Pitch->size[1];
  for (i46 = 0; i46 < partialTrueCount; i46++) {
    FinPitch->data[i46] = 0.0;
  }

  /* 'dynamic:100' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'dynamic:101' FinPitch(i) = Pitch(Path(i),i); */
    i46 = Pitch->size[0];
    i47 = P->size[1];
    if (!((i >= 1) && (i <= i47))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i47, &vh_emlrtBCI, sp);
    }

    i47 = (int32_T)P->data[i - 1];
    if (!((i47 >= 1) && (i47 <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &uh_emlrtBCI, sp);
    }

    i46 = Pitch->size[1];
    if (!((i >= 1) && (i <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i46, &wh_emlrtBCI, sp);
    }

    i46 = FinPitch->size[1];
    if (!((i >= 1) && (i <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i46, &xh_emlrtBCI, sp);
    }

    FinPitch->data[i - 1] = Pitch->data[(i47 + Pitch->size[0] * (i - 1)) - 1];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&P);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (dynamic.c) */
