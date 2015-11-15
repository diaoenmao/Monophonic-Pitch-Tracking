/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * tm_trk.c
 *
 * Code generation for function 'tm_trk'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "tm_trk.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "error1.h"
#include "cmp_rate.h"
#include "crs_corr.h"
#include "fix.h"
#include "warning.h"
#include "scalexpAlloc.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo gi_emlrtRSI = { 55, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo hi_emlrtRSI = { 56, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo ii_emlrtRSI = { 74, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo ji_emlrtRSI = { 78, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo ki_emlrtRSI = { 87, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo li_emlrtRSI = { 95, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo mi_emlrtRSI = { 59, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo ni_emlrtRSI = { 182, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo oi_emlrtRSI = { 208, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo pi_emlrtRSI = { 16, "min",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo dj_emlrtRSI = { 1, "mrdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p" };

static emlrtRTEInfo oc_emlrtRTEI = { 1, 27, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo pc_emlrtRTEI = { 19, 24, "scalexpAllocNoCheck",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m" };

static emlrtRTEInfo qc_emlrtRTEI = { 47, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo rc_emlrtRTEI = { 49, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo sc_emlrtRTEI = { 50, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo tc_emlrtRTEI = { 87, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo uc_emlrtRTEI = { 93, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo kb_emlrtECI = { -1, 52, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 52, 5, "SPitch(i)-2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo lb_emlrtECI = { -1, 53, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 53, 5, "SPitch(i)+2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtDCInfo gb_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtDCInfo hb_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtRTEInfo we_emlrtRTEI = { 63, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtDCInfo ib_emlrtDCI = { 66, 14, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 66, 14, "Data", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo mb_emlrtECI = { -1, 55, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo nb_emlrtECI = { -1, 56, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 71, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 72, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 78, 14, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo ob_emlrtECI = { -1, 78, 6, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo pb_emlrtECI = { 2, 87, 21, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 95, 28, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo qb_emlrtECI = { -1, 90, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 90, 10,
  "match1(j) = diff(j) < freq_thresh", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 95, 52, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 78, 25, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo rb_emlrtECI = { -1, 78, 17, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo sb_emlrtECI = { -1, 95, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 95, 10,
  "(1 - (diff(j)/freq_thresh)) * match1(j)", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo tb_emlrtECI = { 2, 98, 18, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo ub_emlrtECI = { -1, 98, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 95, 10, "match", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 90, 22, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 90, 10, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 52, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 52, 5, "temp_max", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 53, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 53, 5, "temp_min", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

/* Function Definitions */

/*
 * function [Pitch, Merit] = tm_trk(Data, Fs, SPitch, pStd, pAvg, Prm)
 */
void tm_trk(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs, const
            emxArray_real_T *SPitch, const real_T pStd_data[], const int32_T
            pStd_size[1], emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  emxArray_real_T *y;
  real_T nframesize;
  real_T nframejump;
  real_T numframes;
  int32_T i27;
  int32_T info;
  real_T freq_thresh_data[1];
  emxArray_real_T *SRange;
  emxArray_real_T *temp_max;
  emxArray_real_T *temp_min;
  int32_T i;
  emxArray_real_T *b_y;
  emxArray_int32_T *r16;
  emxArray_real_T *b_diff;
  emxArray_real_T *r17;
  boolean_T overflow;
  int32_T k;
  int32_T tmp_size[2];
  emxArray_real_T *match;
  int32_T b_tmp_size[2];
  real_T d0;
  int32_T n;
  emxArray_real_T *b_Data;
  real_T firstp;
  int32_T i28;
  real_T X;
  real_T tmp_data[6];
  real_T b_tmp_data[6];
  static const int32_T iv28[1] = { 3 };

  emxArray_real_T *b_Pitch;
  emxArray_real_T *b_SPitch;
  int32_T c_Pitch[2];
  int32_T c_SPitch[2];
  int32_T j;
  int8_T c_tmp_data[1];
  real_T A_data[1];
  ptrdiff_t ipiv_t;
  ptrdiff_t info_t;
  real_T y_data[1];
  int32_T iv29[2];
  int32_T b_match[2];
  int32_T iv30[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &y, 1, &oc_emlrtRTEI, true);

  /* TM_TRK  Temporal pitch tracking for YAAPT pitch tracking  */
  /*  */
  /*    [Pitch, Merit] = tm_trk(Data, Fs, SPitch, pStd, pAvg, Prm) */
  /*    computes estimates of pitch  using nonlinearly processed */
  /*    speech (typically square or absolute value) and frequency domain processing */
  /*    Search for frequencies which have energy at multiplies of that frequency */
  /*  */
  /* INPUTS: */
  /*    Data:   Nonlinearly processed signal */
  /*    Fs:    The sampling frequency. */
  /*    SPitch:The spectral F0 track, with the unvoiced */
  /*    pStd:  The STD of voiced spectral F0 track . */
  /*    pAvg:  The mean of voiced spectral F0 track . */
  /*    Prm:   Array of parameters used to control performance */
  /*  */
  /* OUTPUTS: */
  /*    Pitch: Computed pitch candidates array */
  /*    Merit: The merit of array of pitch candidates */
  /*    Creation :   Jun 20, 2006, July 27, 2007 */
  /*    Programers:  Hongbing Hu */
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
  /* -- PARAMETERS ---------------------------------------------------------------- */
  /* 'tm_trk:37' nframesize = fix(Prm.frame_length*Fs/1000); */
  nframesize = 25.0 * Fs / 1000.0;
  b_fix(&nframesize);

  /* 'tm_trk:38' nframejump = fix(Prm.frame_space*Fs/1000); */
  nframejump = 10.0 * Fs / 1000.0;
  b_fix(&nframejump);

  /* 'tm_trk:39' noverlap   = nframesize-nframejump; */
  /*  overlap width in sample  */
  /* 'tm_trk:40' numframes  = fix((length(Data)-noverlap)/nframejump); */
  numframes = ((real_T)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /* 'tm_trk:42' merit_boost = Prm.merit_boost; */
  /*  The maximum number of pitch candidates */
  /* 'tm_trk:44' maxcands   = Prm.nccf_maxcands; */
  /* freq_thresh = pAvg;  % seems too large */
  /* 'tm_trk:46' freq_thresh = 5 * pStd; */
  i27 = y->size[0];
  y->size[0] = pStd_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y, i27, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  info = pStd_size[0];
  for (i27 = 0; i27 < info; i27++) {
    y->data[i27] = 5.0 * pStd_data[i27];
  }

  info = pStd_size[0];
  for (i27 = 0; i27 < info; i27++) {
    freq_thresh_data[i27] = 5.0 * pStd_data[i27];
  }

  emxInit_real_T(sp, &SRange, 2, &qc_emlrtRTEI, true);

  /* 'tm_trk:47' SRange = zeros(2,length(SPitch)); */
  i27 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  SRange->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SRange, i27, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  info = SPitch->size[1] << 1;
  for (i27 = 0; i27 < info; i27++) {
    SRange->data[i27] = 0.0;
  }

  emxInit_real_T(sp, &temp_max, 2, &rc_emlrtRTEI, true);

  /*  Determine the search range according spectral pitch track */
  /* 'tm_trk:49' temp_max = zeros(1,length(SPitch)); */
  i27 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  temp_max->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_max, i27, (int32_T)sizeof
                    (real_T), &oc_emlrtRTEI);
  info = SPitch->size[1];
  for (i27 = 0; i27 < info; i27++) {
    temp_max->data[i27] = 0.0;
  }

  emxInit_real_T(sp, &temp_min, 2, &sc_emlrtRTEI, true);

  /* 'tm_trk:50' temp_min = zeros(1,length(SPitch)); */
  i27 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  temp_min->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_min, i27, (int32_T)sizeof
                    (real_T), &oc_emlrtRTEI);
  info = SPitch->size[1];
  for (i27 = 0; i27 < info; i27++) {
    temp_min->data[i27] = 0.0;
  }

  /* 'tm_trk:51' for i = 1:length(SPitch) */
  i = 1;
  emxInit_real_T1(sp, &b_y, 1, &oc_emlrtRTEI, true);
  while (i - 1 <= SPitch->size[1] - 1) {
    /* 'tm_trk:52' temp_max(i) = SPitch(i)-2*pStd; */
    i27 = b_y->size[0];
    b_y->size[0] = pStd_size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_y, i27, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    info = pStd_size[0];
    for (i27 = 0; i27 < info; i27++) {
      b_y->data[i27] = 2.0 * pStd_data[i27];
    }

    i27 = b_y->size[0];
    if (1 != i27) {
      emlrtSizeEqCheck1DR2012b(1, i27, &kb_emlrtECI, sp);
    }

    i27 = b_y->size[0];
    if (!(1 <= i27)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i27, &vf_emlrtBCI, sp);
    }

    i27 = SPitch->size[1];
    if (!((i >= 1) && (i <= i27))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i27, &kg_emlrtBCI, sp);
    }

    i27 = temp_max->size[1];
    if (!((i >= 1) && (i <= i27))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i27, &lg_emlrtBCI, sp);
    }

    temp_max->data[i - 1] = SPitch->data[i - 1] - b_y->data[0];

    /* 'tm_trk:53' temp_min(i) = SPitch(i)+2*pStd; */
    i27 = b_y->size[0];
    b_y->size[0] = pStd_size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_y, i27, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    info = pStd_size[0];
    for (i27 = 0; i27 < info; i27++) {
      b_y->data[i27] = 2.0 * pStd_data[i27];
    }

    i27 = b_y->size[0];
    if (1 != i27) {
      emlrtSizeEqCheck1DR2012b(1, i27, &lb_emlrtECI, sp);
    }

    i27 = b_y->size[0];
    if (!(1 <= i27)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i27, &wf_emlrtBCI, sp);
    }

    i27 = SPitch->size[1];
    if (!((i >= 1) && (i <= i27))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i27, &mg_emlrtBCI, sp);
    }

    i27 = temp_min->size[1];
    if (!((i >= 1) && (i <= i27))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i27, &ng_emlrtBCI, sp);
    }

    temp_min->data[i - 1] = SPitch->data[i - 1] + b_y->data[0];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_y);
  emxInit_int32_T(sp, &r16, 1, &oc_emlrtRTEI, true);

  /* 'tm_trk:55' SRange(1,:)  = max(temp_max, Prm.f0_min); */
  info = SPitch->size[1];
  i27 = r16->size[0];
  r16->size[0] = info;
  emxEnsureCapacity(sp, (emxArray__common *)r16, i27, (int32_T)sizeof(int32_T),
                    &oc_emlrtRTEI);
  for (i27 = 0; i27 < info; i27++) {
    r16->data[i27] = i27;
  }

  emxInit_real_T(sp, &b_diff, 2, &tc_emlrtRTEI, true);
  emxInit_real_T(sp, &r17, 2, &oc_emlrtRTEI, true);
  st.site = &gi_emlrtRSI;
  b_st.site = &df_emlrtRSI;
  c_st.site = &ef_emlrtRSI;
  d_st.site = &mi_emlrtRSI;
  e_st.site = &ni_emlrtRSI;
  i27 = b_diff->size[0] * b_diff->size[1];
  b_diff->size[0] = 1;
  b_diff->size[1] = temp_max->size[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)b_diff, i27, (int32_T)sizeof
                    (real_T), &pc_emlrtRTEI);
  info = temp_max->size[1];
  i27 = r17->size[0] * r17->size[1];
  r17->size[0] = 1;
  r17->size[1] = temp_max->size[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)r17, i27, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  if (dimagree(r17, temp_max)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &md_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &oi_emlrtRSI;
  if (1 > b_diff->size[1]) {
    overflow = false;
  } else {
    overflow = (b_diff->size[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= info; k++) {
    r17->data[k] = muDoubleScalarMax(temp_max->data[k], 60.0);
  }

  tmp_size[0] = 1;
  tmp_size[1] = r16->size[0];
  emlrtSubAssignSizeCheckR2012b(tmp_size, 2, *(int32_T (*)[2])r17->size, 2,
    &mb_emlrtECI, sp);
  info = r17->size[1];
  for (i27 = 0; i27 < info; i27++) {
    SRange->data[SRange->size[0] * r16->data[i27]] = r17->data[r17->size[0] *
      i27];
  }

  /* 'tm_trk:56' SRange(2,:)  = min(temp_min, Prm.f0_max); */
  info = SRange->size[1];
  i27 = r16->size[0];
  r16->size[0] = info;
  emxEnsureCapacity(sp, (emxArray__common *)r16, i27, (int32_T)sizeof(int32_T),
                    &oc_emlrtRTEI);
  for (i27 = 0; i27 < info; i27++) {
    r16->data[i27] = i27;
  }

  emxInit_real_T(sp, &match, 2, &uc_emlrtRTEI, true);
  st.site = &hi_emlrtRSI;
  b_st.site = &pi_emlrtRSI;
  c_st.site = &ef_emlrtRSI;
  d_st.site = &mi_emlrtRSI;
  e_st.site = &ni_emlrtRSI;
  i27 = match->size[0] * match->size[1];
  match->size[0] = 1;
  match->size[1] = temp_min->size[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)match, i27, (int32_T)sizeof
                    (real_T), &pc_emlrtRTEI);
  info = temp_min->size[1];
  i27 = r17->size[0] * r17->size[1];
  r17->size[0] = 1;
  r17->size[1] = temp_min->size[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)r17, i27, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  if (dimagree(r17, temp_min)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &md_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &oi_emlrtRSI;
  if (1 > match->size[1]) {
    overflow = false;
  } else {
    overflow = (match->size[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= info; k++) {
    r17->data[k] = muDoubleScalarMin(temp_min->data[k], 400.0);
  }

  b_tmp_size[0] = 1;
  b_tmp_size[1] = r16->size[0];
  emlrtSubAssignSizeCheckR2012b(b_tmp_size, 2, *(int32_T (*)[2])r17->size, 2,
    &nb_emlrtECI, sp);
  info = r17->size[1];
  for (i27 = 0; i27 < info; i27++) {
    SRange->data[1 + SRange->size[0] * r16->data[i27]] = r17->data[r17->size[0] *
      i27];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'tm_trk:59' Pitch = zeros(maxcands, numframes); */
  i27 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 3;
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &gb_emlrtDCI, sp);
  }

  if (numframes != (int32_T)muDoubleScalarFloor(numframes)) {
    emlrtIntegerCheckR2012b(numframes, &hb_emlrtDCI, sp);
  }

  Pitch->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i27, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &gb_emlrtDCI, sp);
  }

  d0 = numframes;
  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &hb_emlrtDCI, sp);
  }

  info = 3 * (int32_T)d0;
  for (i27 = 0; i27 < info; i27++) {
    Pitch->data[i27] = 0.0;
  }

  /* 'tm_trk:60' Merit = zeros(maxcands, numframes); */
  i27 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 3;
  Merit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i27, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  info = 3 * (int32_T)numframes;
  for (i27 = 0; i27 < info; i27++) {
    Merit->data[i27] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /* 'tm_trk:63' for n = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &we_emlrtRTEI, sp);
  n = 0;
  emxInit_real_T1(sp, &b_Data, 1, &oc_emlrtRTEI, true);
  while (n <= (int32_T)numframes - 1) {
    /* 'tm_trk:65' firstp = 1+((n-1)*(nframejump)); */
    firstp = 1.0 + ((1.0 + (real_T)n) - 1.0) * nframejump;

    /* 'tm_trk:66' Signal = Data(firstp:firstp+nframesize-1); */
    d0 = (firstp + nframesize) - 1.0;
    if (firstp > d0) {
      i27 = 0;
      k = 0;
    } else {
      if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
        emlrtIntegerCheckR2012b(firstp, &ib_emlrtDCI, sp);
      }

      i27 = Data->size[1];
      i28 = (int32_T)firstp;
      if (!((i28 >= 1) && (i28 <= i27))) {
        emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &xf_emlrtBCI, sp);
      }

      i27 = i28 - 1;
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &ib_emlrtDCI, sp);
      }

      i28 = Data->size[1];
      k = (int32_T)d0;
      if (!((k >= 1) && (k <= i28))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i28, &xf_emlrtBCI, sp);
      }
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    /* 'tm_trk:71' Lag_min0 = fix(Fs/SRange(2,n)) - 3; */
    i28 = SRange->size[1];
    info = n + 1;
    if (!((info >= 1) && (info <= i28))) {
      emlrtDynamicBoundsCheckR2012b(info, 1, i28, &yf_emlrtBCI, sp);
    }

    d0 = Fs / SRange->data[1 + SRange->size[0] * n];
    b_fix(&d0);

    /* 'tm_trk:72' Lag_max0 = fix(Fs/SRange(1,n)) + 3; */
    i28 = SRange->size[1];
    info = n + 1;
    if (!((info >= 1) && (info <= i28))) {
      emlrtDynamicBoundsCheckR2012b(info, 1, i28, &ag_emlrtBCI, sp);
    }

    X = Fs / SRange->data[SRange->size[0] * n];
    if (X < 0.0) {
      X = muDoubleScalarCeil(X);
    } else {
      X = muDoubleScalarFloor(X);
    }

    /*  Compute correaltion */
    /* 'tm_trk:74' Phi =  crs_corr(Signal', Lag_min0, Lag_max0); */
    i28 = b_Data->size[0];
    b_Data->size[0] = k - i27;
    emxEnsureCapacity(sp, (emxArray__common *)b_Data, i28, (int32_T)sizeof
                      (real_T), &oc_emlrtRTEI);
    info = k - i27;
    for (i28 = 0; i28 < info; i28++) {
      b_Data->data[i28] = Data->data[i27 + i28];
    }

    st.site = &ii_emlrtRSI;
    crs_corr(&st, b_Data, d0 - 3.0, X + 3.0, temp_max);

    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    /* 'tm_trk:78' [Pitch(:,n),Merit(:,n)] = cmp_rate(Phi,Fs,maxcands,Lag_min0,Lag_max0,Prm); */
    st.site = &ji_emlrtRSI;
    cmp_rate(&st, temp_max, Fs, d0 - 3.0, X + 3.0, b_tmp_data, tmp_size,
             tmp_data, b_tmp_size);
    i27 = Pitch->size[1];
    i28 = n + 1;
    if (!((i28 >= 1) && (i28 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &bg_emlrtBCI, sp);
    }

    emlrtSubAssignSizeCheckR2012b(iv28, 1, tmp_size, 2, &ob_emlrtECI, sp);
    for (i27 = 0; i27 < 3; i27++) {
      Pitch->data[i27 + Pitch->size[0] * n] = b_tmp_data[i27];
    }

    i27 = Merit->size[1];
    i28 = n + 1;
    if (!((i28 >= 1) && (i28 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &fg_emlrtBCI, sp);
    }

    emlrtSubAssignSizeCheckR2012b(iv28, 1, b_tmp_size, 2, &rb_emlrtECI, sp);
    for (i27 = 0; i27 < 3; i27++) {
      Merit->data[i27 + Merit->size[0] * n] = tmp_data[i27];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Data);
  emxFree_real_T(&SRange);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  /* 'tm_trk:86' for i = 1:maxcands */
  i = 0;
  emxInit_real_T(sp, &b_Pitch, 2, &oc_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SPitch, 2, &oc_emlrtRTEI, true);
  while (i < 3) {
    /* 'tm_trk:87' diff   =  abs( (Pitch(i,:) - SPitch(1,:))); */
    info = Pitch->size[1];
    i27 = b_Pitch->size[0] * b_Pitch->size[1];
    b_Pitch->size[0] = 1;
    b_Pitch->size[1] = info;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i27, (int32_T)sizeof
                      (real_T), &oc_emlrtRTEI);
    for (i27 = 0; i27 < info; i27++) {
      b_Pitch->data[b_Pitch->size[0] * i27] = Pitch->data[i + Pitch->size[0] *
        i27];
    }

    for (i27 = 0; i27 < 2; i27++) {
      c_Pitch[i27] = b_Pitch->size[i27];
    }

    info = SPitch->size[1];
    i27 = b_SPitch->size[0] * b_SPitch->size[1];
    b_SPitch->size[0] = 1;
    b_SPitch->size[1] = info;
    emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i27, (int32_T)sizeof
                      (real_T), &oc_emlrtRTEI);
    for (i27 = 0; i27 < info; i27++) {
      b_SPitch->data[b_SPitch->size[0] * i27] = SPitch->data[SPitch->size[0] *
        i27];
    }

    for (i27 = 0; i27 < 2; i27++) {
      c_SPitch[i27] = b_SPitch->size[i27];
    }

    if ((c_Pitch[0] != c_SPitch[0]) || (c_Pitch[1] != c_SPitch[1])) {
      emlrtSizeEqCheckNDR2012b(&c_Pitch[0], &c_SPitch[0], &pb_emlrtECI, sp);
    }

    st.site = &ki_emlrtRSI;
    info = Pitch->size[1];
    i27 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = info;
    emxEnsureCapacity(&st, (emxArray__common *)temp_max, i27, (int32_T)sizeof
                      (real_T), &oc_emlrtRTEI);
    for (i27 = 0; i27 < info; i27++) {
      temp_max->data[temp_max->size[0] * i27] = Pitch->data[i + Pitch->size[0] *
        i27] - SPitch->data[SPitch->size[0] * i27];
    }

    b_st.site = &xc_emlrtRSI;
    i27 = b_diff->size[0] * b_diff->size[1];
    b_diff->size[0] = 1;
    b_diff->size[1] = temp_max->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_diff, i27, (int32_T)sizeof
                      (real_T), &oc_emlrtRTEI);
    c_st.site = &yc_emlrtRSI;
    if (1 > temp_max->size[1]) {
      overflow = false;
    } else {
      overflow = (temp_max->size[1] > 2147483646);
    }

    if (overflow) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k + 1 <= temp_max->size[1]; k++) {
      b_diff->data[k] = muDoubleScalarAbs(temp_max->data[k]);
    }

    /* 'tm_trk:88' match1 = zeros(1,length(diff)); */
    i27 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = b_diff->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)temp_max, i27, (int32_T)sizeof
                      (real_T), &oc_emlrtRTEI);
    info = b_diff->size[1];
    for (i27 = 0; i27 < info; i27++) {
      temp_max->data[i27] = 0.0;
    }

    /* 'tm_trk:89' for j = 1:length(diff) */
    j = 1;
    while (j - 1 <= b_diff->size[1] - 1) {
      /* 'tm_trk:90' match1(j) = diff(j) < freq_thresh; */
      i27 = b_diff->size[1];
      if (!((j >= 1) && (j <= i27))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i27, &ig_emlrtBCI, sp);
      }

      X = b_diff->data[j - 1];
      k = y->size[0];
      info = y->size[0];
      for (i27 = 0; i27 < info; i27++) {
        c_tmp_data[i27] = (int8_T)(X < y->data[i27]);
      }

      if (1 != k) {
        emlrtSizeEqCheck1DR2012b(1, k, &qb_emlrtECI, sp);
      }

      if (!(1 <= k)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, k, &dg_emlrtBCI, sp);
      }

      i27 = temp_max->size[1];
      if (!((j >= 1) && (j <= i27))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i27, &jg_emlrtBCI, sp);
      }

      temp_max->data[j - 1] = c_tmp_data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*      match1 =  (diff < freq_thresh); */
    /* 'tm_trk:93' match = zeros(1,length(diff)); */
    i27 = match->size[0] * match->size[1];
    match->size[0] = 1;
    match->size[1] = b_diff->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)match, i27, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    info = b_diff->size[1];
    for (i27 = 0; i27 < info; i27++) {
      match->data[i27] = 0.0;
    }

    /* 'tm_trk:94' for j = 1:length(diff) */
    j = 0;
    while (j <= b_diff->size[1] - 1) {
      /* 'tm_trk:95' match(j) = ((1 - (diff(j)/freq_thresh)) * match1(j)); */
      st.site = &li_emlrtRSI;
      i27 = b_diff->size[1];
      i28 = j + 1;
      if (!((i28 >= 1) && (i28 <= i27))) {
        emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &cg_emlrtBCI, &st);
      }

      if (y->size[0] == 0) {
        k = 0;
      } else {
        b_st.site = &dj_emlrtRSI;
        c_st.site = &db_emlrtRSI;
        d_st.site = &fb_emlrtRSI;
        e_st.site = &ib_emlrtRSI;
        info = pStd_size[0];
        for (i27 = 0; i27 < info; i27++) {
          A_data[i27] = freq_thresh_data[i27];
        }

        info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)1, (ptrdiff_t)1, &A_data[0],
          (ptrdiff_t)1, &ipiv_t);
        info = (int32_T)info_t;
        f_st.site = &jb_emlrtRSI;
        if (info < 0) {
          if (info == -1010) {
            g_st.site = &kb_emlrtRSI;
            d_error(&g_st);
          } else {
            g_st.site = &lb_emlrtRSI;
            e_error(&g_st, info);
          }

          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
          A_data[0] = rtNaN;
        }

        if (info > 0) {
          d_st.site = &eb_emlrtRSI;
          if (!emlrtSetWarningFlag(&d_st)) {
            e_st.site = &nb_emlrtRSI;
            warning(&e_st);
          }
        }

        X = 1.0 / A_data[0] * b_diff->data[j];
        k = 1;
        y_data[0] = X;
      }

      i27 = temp_max->size[1];
      i28 = j + 1;
      if (!((i28 >= 1) && (i28 <= i27))) {
        emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &eg_emlrtBCI, sp);
      }

      i27 = temp_min->size[0] * temp_min->size[1];
      temp_min->size[0] = 1;
      temp_min->size[1] = k;
      emxEnsureCapacity(sp, (emxArray__common *)temp_min, i27, (int32_T)sizeof
                        (real_T), &oc_emlrtRTEI);
      X = temp_max->data[j];
      for (i27 = 0; i27 < k; i27++) {
        temp_min->data[i27] = (1.0 - y_data[i27]) * X;
      }

      i27 = temp_min->size[1];
      if (1 != i27) {
        emlrtSizeEqCheck1DR2012b(1, i27, &sb_emlrtECI, sp);
      }

      i27 = temp_min->size[1];
      if (!(1 <= i27)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i27, &gg_emlrtBCI, sp);
      }

      i27 = match->size[1];
      i28 = 1 + j;
      if (!((i28 >= 1) && (i28 <= i27))) {
        emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &hg_emlrtBCI, sp);
      }

      match->data[i28 - 1] = temp_min->data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    /* 'tm_trk:98' Merit(i,:) = ((1+merit_boost)*Merit(i,:)).*match; */
    info = Merit->size[1];
    i27 = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    r17->size[1] = info;
    emxEnsureCapacity(sp, (emxArray__common *)r17, i27, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    for (i27 = 0; i27 < info; i27++) {
      r17->data[r17->size[0] * i27] = 1.2 * Merit->data[i + Merit->size[0] * i27];
    }

    for (i27 = 0; i27 < 2; i27++) {
      iv29[i27] = r17->size[i27];
    }

    for (i27 = 0; i27 < 2; i27++) {
      b_match[i27] = match->size[i27];
    }

    if ((iv29[0] != b_match[0]) || (iv29[1] != b_match[1])) {
      emlrtSizeEqCheckNDR2012b(&iv29[0], &b_match[0], &tb_emlrtECI, sp);
    }

    info = Merit->size[1];
    i27 = r16->size[0];
    r16->size[0] = info;
    emxEnsureCapacity(sp, (emxArray__common *)r16, i27, (int32_T)sizeof(int32_T),
                      &oc_emlrtRTEI);
    for (i27 = 0; i27 < info; i27++) {
      r16->data[i27] = i27;
    }

    i27 = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r17, i27, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    i27 = r17->size[0];
    i28 = r17->size[1];
    info = i27 * i28;
    for (i27 = 0; i27 < info; i27++) {
      r17->data[i27] *= match->data[i27];
    }

    iv30[0] = 1;
    iv30[1] = r16->size[0];
    emlrtSubAssignSizeCheckR2012b(iv30, 2, *(int32_T (*)[2])r17->size, 2,
      &ub_emlrtECI, sp);
    info = r17->size[1];
    for (i27 = 0; i27 < info; i27++) {
      Merit->data[i + Merit->size[0] * r16->data[i27]] = r17->data[r17->size[0] *
        i27];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_SPitch);
  emxFree_real_T(&b_Pitch);
  emxFree_real_T(&y);
  emxFree_real_T(&r17);
  emxFree_int32_T(&r16);
  emxFree_real_T(&match);
  emxFree_real_T(&b_diff);
  emxFree_real_T(&temp_min);
  emxFree_real_T(&temp_max);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (tm_trk.c) */
