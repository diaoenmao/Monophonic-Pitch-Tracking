/*
 * tm_trk.c
 *
 * Code generation for function 'tm_trk'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "tm_trk.h"
#include "error1.h"
#include "yaapt_emxutil.h"
#include "cmp_rate.h"
#include "crs_corr.h"
#include "fix.h"
#include "warning.h"
#include "qrsolve.h"
#include "xgeqp3.h"
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ve_emlrtRSI = { 19, "scalexpAllocNoCheck",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m" };

static emlrtRSInfo rl_emlrtRSI = { 55, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo sl_emlrtRSI = { 56, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo tl_emlrtRSI = { 74, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo ul_emlrtRSI = { 78, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo vl_emlrtRSI = { 87, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo wl_emlrtRSI = { 95, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo xl_emlrtRSI = { 59, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo yl_emlrtRSI = { 182, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo am_emlrtRSI = { 208, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo nm_emlrtRSI = { 1, "mrdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p" };

static emlrtRTEInfo td_emlrtRTEI = { 1, 27, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo ud_emlrtRTEI = { 46, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo vd_emlrtRTEI = { 47, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo wd_emlrtRTEI = { 49, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo xd_emlrtRTEI = { 50, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo yd_emlrtRTEI = { 88, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo ae_emlrtRTEI = { 93, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo tb_emlrtECI = { -1, 98, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 98, 11, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo ub_emlrtECI = { 2, 98, 18, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 95, 10,
  "(1 - (diff(j)/freq_thresh)) * match1(j)", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo vb_emlrtECI = { -1, 95, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 98, 41, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo wb_emlrtECI = { -1, 78, 17, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 78, 25, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo di_emlrtBCI = { -1, -1, 95, 52, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 90, 10,
  "match1(j) = diff(j) < freq_thresh", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo xb_emlrtECI = { -1, 90, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 95, 28, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo yb_emlrtECI = { 2, 87, 21, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 87, 27, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo ac_emlrtECI = { -1, 78, 6, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 78, 14, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtRTEInfo rg_emlrtRTEI = { 86, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ii_emlrtBCI = { -1, -1, 72, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 71, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo bc_emlrtECI = { -1, 56, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo cc_emlrtECI = { -1, 55, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ki_emlrtBCI = { -1, -1, 66, 14, "Data", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtDCInfo ad_emlrtDCI = { 66, 14, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtRTEInfo sg_emlrtRTEI = { 63, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtDCInfo bd_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtDCInfo cd_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtDCInfo dd_emlrtDCI = { 59, 15, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtDCInfo ed_emlrtDCI = { 59, 15, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtBCInfo li_emlrtBCI = { -1, -1, 53, 5, "SPitch(i)+2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo dc_emlrtECI = { -1, 53, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo mi_emlrtBCI = { -1, -1, 52, 5, "SPitch(i)-2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo ec_emlrtECI = { -1, 52, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ni_emlrtBCI = { -1, -1, 95, 10, "match", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo oi_emlrtBCI = { -1, -1, 90, 22, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo pi_emlrtBCI = { -1, -1, 90, 10, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo qi_emlrtBCI = { -1, -1, 52, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ri_emlrtBCI = { -1, -1, 52, 5, "temp_max", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo si_emlrtBCI = { -1, -1, 53, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ti_emlrtBCI = { -1, -1, 53, 5, "temp_min", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

/* Function Definitions */

/*
 * function [Pitch, Merit] = tm_trk(Data, Fs, SPitch, pStd, pAvg, Prm)
 */
void tm_trk(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs, const
            emxArray_real_T *SPitch, const emxArray_real_T *pStd, real_T
            Prm_frame_length, real_T Prm_frame_space, real_T Prm_f0_min, real_T
            Prm_f0_max, real_T Prm_nccf_thresh1, real_T Prm_nccf_thresh2, real_T
            Prm_nccf_maxcands, real_T Prm_nccf_pwidth, real_T Prm_merit_boost,
            emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  emxArray_real_T *freq_thresh;
  emxArray_real_T *temp_max;
  real_T nframesize;
  real_T nframejump;
  real_T numframes;
  int32_T i41;
  int32_T minmn;
  emxArray_real_T *SRange;
  emxArray_real_T *temp_min;
  int32_T i;
  emxArray_real_T *tau;
  emxArray_int32_T *r39;
  uint32_T uv8[2];
  emxArray_real_T *match1;
  emxArray_real_T *r40;
  boolean_T overflow;
  int32_T iv48[2];
  emxArray_real_T *match;
  int32_T iv49[2];
  real_T d1;
  real_T tol;
  int32_T n;
  emxArray_real_T *b_Data;
  emxArray_real_T *r41;
  real_T firstp;
  int32_T rankR;
  int32_T maxmn;
  int32_T iv50[1];
  int32_T iv51[1];
  emxArray_real_T *Y;
  emxArray_int32_T *jpvt;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *c_Pitch;
  emxArray_real_T *b_SPitch;
  int32_T d_Pitch[2];
  int32_T c_SPitch[2];
  int32_T j;
  ptrdiff_t ipiv_t;
  ptrdiff_t info_t;
  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  char_T u[6];
  const mxArray *y;
  static const int32_T iv52[2] = { 1, 6 };

  const mxArray *m10;
  char_T cv10[14];
  int32_T iv53[2];
  int32_T b_match[2];
  int32_T iv54[2];
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
  emxInit_real_T1(sp, &freq_thresh, 1, &ud_emlrtRTEI, true);
  emxInit_real_T(sp, &temp_max, 2, &wd_emlrtRTEI, true);

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
  nframesize = Prm_frame_length * Fs / 1000.0;
  b_fix(&nframesize);

  /* 'tm_trk:38' nframejump = fix(Prm.frame_space*Fs/1000); */
  nframejump = Prm_frame_space * Fs / 1000.0;
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
  i41 = freq_thresh->size[0];
  freq_thresh->size[0] = pStd->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)freq_thresh, i41, (int32_T)sizeof
                    (real_T), &td_emlrtRTEI);
  minmn = pStd->size[0];
  for (i41 = 0; i41 < minmn; i41++) {
    freq_thresh->data[i41] = 5.0 * pStd->data[i41];
  }

  emxInit_real_T(sp, &SRange, 2, &vd_emlrtRTEI, true);

  /* 'tm_trk:47' SRange = zeros(2,length(SPitch)); */
  i41 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  SRange->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SRange, i41, (int32_T)sizeof(real_T),
                    &td_emlrtRTEI);
  minmn = SPitch->size[1] << 1;
  for (i41 = 0; i41 < minmn; i41++) {
    SRange->data[i41] = 0.0;
  }

  /*  Determine the search range according spectral pitch track */
  /* 'tm_trk:49' temp_max = zeros(1,length(SPitch)); */
  i41 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  temp_max->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_max, i41, (int32_T)sizeof
                    (real_T), &td_emlrtRTEI);
  minmn = SPitch->size[1];
  for (i41 = 0; i41 < minmn; i41++) {
    temp_max->data[i41] = 0.0;
  }

  emxInit_real_T(sp, &temp_min, 2, &xd_emlrtRTEI, true);

  /* 'tm_trk:50' temp_min = zeros(1,length(SPitch)); */
  i41 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  temp_min->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_min, i41, (int32_T)sizeof
                    (real_T), &td_emlrtRTEI);
  minmn = SPitch->size[1];
  for (i41 = 0; i41 < minmn; i41++) {
    temp_min->data[i41] = 0.0;
  }

  /* 'tm_trk:51' for i = 1:length(SPitch) */
  i = 1;
  emxInit_real_T1(sp, &tau, 1, &td_emlrtRTEI, true);
  while (i - 1 <= SPitch->size[1] - 1) {
    /* 'tm_trk:52' temp_max(i) = SPitch(i)-2*pStd; */
    i41 = tau->size[0];
    tau->size[0] = pStd->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tau, i41, (int32_T)sizeof(real_T),
                      &td_emlrtRTEI);
    minmn = pStd->size[0];
    for (i41 = 0; i41 < minmn; i41++) {
      tau->data[i41] = 2.0 * pStd->data[i41];
    }

    i41 = tau->size[0];
    if (1 != i41) {
      emlrtSizeEqCheck1DR2012b(1, i41, &ec_emlrtECI, sp);
    }

    i41 = tau->size[0];
    if (!(1 <= i41)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i41, &mi_emlrtBCI, sp);
    }

    i41 = SPitch->size[1];
    if (!((i >= 1) && (i <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i41, &qi_emlrtBCI, sp);
    }

    i41 = temp_max->size[1];
    if (!((i >= 1) && (i <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i41, &ri_emlrtBCI, sp);
    }

    temp_max->data[i - 1] = SPitch->data[i - 1] - tau->data[0];

    /* 'tm_trk:53' temp_min(i) = SPitch(i)+2*pStd; */
    i41 = tau->size[0];
    tau->size[0] = pStd->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tau, i41, (int32_T)sizeof(real_T),
                      &td_emlrtRTEI);
    minmn = pStd->size[0];
    for (i41 = 0; i41 < minmn; i41++) {
      tau->data[i41] = 2.0 * pStd->data[i41];
    }

    i41 = tau->size[0];
    if (1 != i41) {
      emlrtSizeEqCheck1DR2012b(1, i41, &dc_emlrtECI, sp);
    }

    i41 = tau->size[0];
    if (!(1 <= i41)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i41, &li_emlrtBCI, sp);
    }

    i41 = SPitch->size[1];
    if (!((i >= 1) && (i <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i41, &si_emlrtBCI, sp);
    }

    i41 = temp_min->size[1];
    if (!((i >= 1) && (i <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i41, &ti_emlrtBCI, sp);
    }

    temp_min->data[i - 1] = SPitch->data[i - 1] + tau->data[0];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_int32_T1(sp, &r39, 1, &td_emlrtRTEI, true);

  /* 'tm_trk:55' SRange(1,:)  = max(temp_max, Prm.f0_min); */
  minmn = SPitch->size[1];
  i41 = r39->size[0];
  r39->size[0] = minmn;
  emxEnsureCapacity(sp, (emxArray__common *)r39, i41, (int32_T)sizeof(int32_T),
                    &td_emlrtRTEI);
  for (i41 = 0; i41 < minmn; i41++) {
    r39->data[i41] = i41;
  }

  st.site = &rl_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &xl_emlrtRSI;
  e_st.site = &yl_emlrtRSI;
  f_st.site = &ue_emlrtRSI;
  g_st.site = &ve_emlrtRSI;
  for (i41 = 0; i41 < 2; i41++) {
    uv8[i41] = (uint32_T)temp_max->size[i41];
  }

  emxInit_real_T(&g_st, &match1, 2, &yd_emlrtRTEI, true);
  emxInit_real_T(&g_st, &r40, 2, &td_emlrtRTEI, true);
  i41 = match1->size[0] * match1->size[1];
  match1->size[0] = 1;
  match1->size[1] = (int32_T)uv8[1];
  emxEnsureCapacity(&g_st, (emxArray__common *)match1, i41, (int32_T)sizeof
                    (real_T), &td_emlrtRTEI);
  i41 = r40->size[0] * r40->size[1];
  r40->size[0] = 1;
  r40->size[1] = (int32_T)uv8[1];
  emxEnsureCapacity(&f_st, (emxArray__common *)r40, i41, (int32_T)sizeof(real_T),
                    &td_emlrtRTEI);
  if (dimagree(r40, temp_max)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &xe_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &am_emlrtRSI;
  if (1 > match1->size[1]) {
    overflow = false;
  } else {
    overflow = (match1->size[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&f_st, true);
  }

  for (minmn = 0; minmn + 1 <= (int32_T)uv8[1]; minmn++) {
    r40->data[minmn] = muDoubleScalarMax(temp_max->data[minmn], Prm_f0_min);
  }

  iv48[0] = 1;
  iv48[1] = r39->size[0];
  emlrtSubAssignSizeCheckR2012b(iv48, 2, *(int32_T (*)[2])r40->size, 2,
    &cc_emlrtECI, sp);
  minmn = r40->size[1];
  for (i41 = 0; i41 < minmn; i41++) {
    SRange->data[SRange->size[0] * r39->data[i41]] = r40->data[r40->size[0] *
      i41];
  }

  /* 'tm_trk:56' SRange(2,:)  = min(temp_min, Prm.f0_max); */
  minmn = SRange->size[1];
  i41 = r39->size[0];
  r39->size[0] = minmn;
  emxEnsureCapacity(sp, (emxArray__common *)r39, i41, (int32_T)sizeof(int32_T),
                    &td_emlrtRTEI);
  for (i41 = 0; i41 < minmn; i41++) {
    r39->data[i41] = i41;
  }

  st.site = &sl_emlrtRSI;
  b_st.site = &kb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &xl_emlrtRSI;
  e_st.site = &yl_emlrtRSI;
  f_st.site = &ue_emlrtRSI;
  g_st.site = &ve_emlrtRSI;
  for (i41 = 0; i41 < 2; i41++) {
    uv8[i41] = (uint32_T)temp_min->size[i41];
  }

  emxInit_real_T(&g_st, &match, 2, &ae_emlrtRTEI, true);
  i41 = match->size[0] * match->size[1];
  match->size[0] = 1;
  match->size[1] = (int32_T)uv8[1];
  emxEnsureCapacity(&g_st, (emxArray__common *)match, i41, (int32_T)sizeof
                    (real_T), &td_emlrtRTEI);
  i41 = r40->size[0] * r40->size[1];
  r40->size[0] = 1;
  r40->size[1] = (int32_T)uv8[1];
  emxEnsureCapacity(&f_st, (emxArray__common *)r40, i41, (int32_T)sizeof(real_T),
                    &td_emlrtRTEI);
  if (dimagree(r40, temp_min)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &xe_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &am_emlrtRSI;
  if (1 > match->size[1]) {
    overflow = false;
  } else {
    overflow = (match->size[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&f_st, true);
  }

  for (minmn = 0; minmn + 1 <= (int32_T)uv8[1]; minmn++) {
    r40->data[minmn] = muDoubleScalarMin(temp_min->data[minmn], Prm_f0_max);
  }

  iv49[0] = 1;
  iv49[1] = r39->size[0];
  emlrtSubAssignSizeCheckR2012b(iv49, 2, *(int32_T (*)[2])r40->size, 2,
    &bc_emlrtECI, sp);
  minmn = r40->size[1];
  for (i41 = 0; i41 < minmn; i41++) {
    SRange->data[1 + SRange->size[0] * r39->data[i41]] = r40->data[r40->size[0] *
      i41];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'tm_trk:59' Pitch = zeros(maxcands, numframes); */
  i41 = Pitch->size[0] * Pitch->size[1];
  if (!(Prm_nccf_maxcands > 0.0)) {
    emlrtNonNegativeCheckR2012b(Prm_nccf_maxcands, &ed_emlrtDCI, sp);
  }

  d1 = Prm_nccf_maxcands;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &dd_emlrtDCI, sp);
  }

  Pitch->size[0] = (int32_T)d1;
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &cd_emlrtDCI, sp);
  }

  d1 = numframes;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &bd_emlrtDCI, sp);
  }

  Pitch->size[1] = (int32_T)d1;
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i41, (int32_T)sizeof(real_T),
                    &td_emlrtRTEI);
  if (!(Prm_nccf_maxcands > 0.0)) {
    emlrtNonNegativeCheckR2012b(Prm_nccf_maxcands, &ed_emlrtDCI, sp);
  }

  d1 = Prm_nccf_maxcands;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &dd_emlrtDCI, sp);
  }

  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &cd_emlrtDCI, sp);
  }

  tol = numframes;
  if (tol != (int32_T)muDoubleScalarFloor(tol)) {
    emlrtIntegerCheckR2012b(tol, &bd_emlrtDCI, sp);
  }

  minmn = (int32_T)d1 * (int32_T)tol;
  for (i41 = 0; i41 < minmn; i41++) {
    Pitch->data[i41] = 0.0;
  }

  /* 'tm_trk:60' Merit = zeros(maxcands, numframes); */
  i41 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = (int32_T)Prm_nccf_maxcands;
  Merit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i41, (int32_T)sizeof(real_T),
                    &td_emlrtRTEI);
  minmn = (int32_T)Prm_nccf_maxcands * (int32_T)numframes;
  for (i41 = 0; i41 < minmn; i41++) {
    Merit->data[i41] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /* 'tm_trk:63' for n = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &sg_emlrtRTEI, sp);
  n = 0;
  emxInit_real_T1(sp, &b_Data, 1, &td_emlrtRTEI, true);
  emxInit_real_T(sp, &r41, 2, &td_emlrtRTEI, true);
  while (n <= (int32_T)numframes - 1) {
    /* 'tm_trk:65' firstp = 1+((n-1)*(nframejump)); */
    firstp = 1.0 + ((1.0 + (real_T)n) - 1.0) * nframejump;

    /* 'tm_trk:66' Signal = Data(firstp:firstp+nframesize-1); */
    d1 = (firstp + nframesize) - 1.0;
    if (firstp > d1) {
      i41 = 0;
      minmn = 0;
    } else {
      i41 = Data->size[1];
      if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
        emlrtIntegerCheckR2012b(firstp, &ad_emlrtDCI, sp);
      }

      rankR = (int32_T)firstp;
      if (!((rankR >= 1) && (rankR <= i41))) {
        emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &ki_emlrtBCI, sp);
      }

      i41 = rankR - 1;
      rankR = Data->size[1];
      if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
        emlrtIntegerCheckR2012b(d1, &ad_emlrtDCI, sp);
      }

      minmn = (int32_T)d1;
      if (!((minmn >= 1) && (minmn <= rankR))) {
        emlrtDynamicBoundsCheckR2012b(minmn, 1, rankR, &ki_emlrtBCI, sp);
      }
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    /* 'tm_trk:71' Lag_min0 = fix(Fs/SRange(2,n)) - 3; */
    rankR = SRange->size[1];
    maxmn = n + 1;
    if (!((maxmn >= 1) && (maxmn <= rankR))) {
      emlrtDynamicBoundsCheckR2012b(maxmn, 1, rankR, &ji_emlrtBCI, sp);
    }

    d1 = Fs / SRange->data[1 + SRange->size[0] * n];
    b_fix(&d1);

    /* 'tm_trk:72' Lag_max0 = fix(Fs/SRange(1,n)) + 3; */
    rankR = SRange->size[1];
    maxmn = n + 1;
    if (!((maxmn >= 1) && (maxmn <= rankR))) {
      emlrtDynamicBoundsCheckR2012b(maxmn, 1, rankR, &ii_emlrtBCI, sp);
    }

    tol = Fs / SRange->data[SRange->size[0] * n];
    b_fix(&tol);

    /*  Compute correaltion */
    /* 'tm_trk:74' Phi =  crs_corr(Signal', Lag_min0, Lag_max0); */
    rankR = b_Data->size[0];
    b_Data->size[0] = minmn - i41;
    emxEnsureCapacity(sp, (emxArray__common *)b_Data, rankR, (int32_T)sizeof
                      (real_T), &td_emlrtRTEI);
    minmn -= i41;
    for (rankR = 0; rankR < minmn; rankR++) {
      b_Data->data[rankR] = Data->data[i41 + rankR];
    }

    st.site = &tl_emlrtRSI;
    crs_corr(&st, b_Data, d1 - 3.0, tol + 3.0, r41);
    i41 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = r41->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)temp_max, i41, (int32_T)sizeof
                      (real_T), &td_emlrtRTEI);
    minmn = r41->size[0] * r41->size[1];
    for (i41 = 0; i41 < minmn; i41++) {
      temp_max->data[i41] = r41->data[i41];
    }

    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    /* 'tm_trk:78' [Pitch(:,n),Merit(:,n)] = cmp_rate(Phi,Fs,maxcands,Lag_min0,Lag_max0,Prm); */
    st.site = &ul_emlrtRSI;
    cmp_rate(&st, temp_max, Fs, Prm_nccf_maxcands, d1 - 3.0, tol + 3.0,
             Prm_nccf_thresh1, Prm_nccf_thresh2, Prm_nccf_pwidth, r40, temp_min);
    minmn = Pitch->size[0];
    i41 = r39->size[0];
    r39->size[0] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)r39, i41, (int32_T)sizeof(int32_T),
                      &td_emlrtRTEI);
    for (i41 = 0; i41 < minmn; i41++) {
      r39->data[i41] = i41;
    }

    i41 = Pitch->size[1];
    rankR = n + 1;
    if (!((rankR >= 1) && (rankR <= i41))) {
      emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &hi_emlrtBCI, sp);
    }

    iv50[0] = r39->size[0];
    emlrtSubAssignSizeCheckR2012b(iv50, 1, *(int32_T (*)[2])r40->size, 2,
      &ac_emlrtECI, sp);
    minmn = r39->size[0];
    for (i41 = 0; i41 < minmn; i41++) {
      Pitch->data[r39->data[i41] + Pitch->size[0] * n] = r40->data[i41];
    }

    minmn = Merit->size[0];
    i41 = r39->size[0];
    r39->size[0] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)r39, i41, (int32_T)sizeof(int32_T),
                      &td_emlrtRTEI);
    for (i41 = 0; i41 < minmn; i41++) {
      r39->data[i41] = i41;
    }

    i41 = Merit->size[1];
    rankR = n + 1;
    if (!((rankR >= 1) && (rankR <= i41))) {
      emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &ci_emlrtBCI, sp);
    }

    iv51[0] = r39->size[0];
    emlrtSubAssignSizeCheckR2012b(iv51, 1, *(int32_T (*)[2])temp_min->size, 2,
      &wb_emlrtECI, sp);
    minmn = r39->size[0];
    for (i41 = 0; i41 < minmn; i41++) {
      Merit->data[r39->data[i41] + Merit->size[0] * n] = temp_min->data[i41];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r41);
  emxFree_real_T(&b_Data);
  emxFree_real_T(&SRange);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  /* 'tm_trk:86' for i = 1:maxcands */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, Prm_nccf_maxcands, mxDOUBLE_CLASS,
    (int32_T)Prm_nccf_maxcands, &rg_emlrtRTEI, sp);
  i = 0;
  emxInit_real_T1(sp, &Y, 1, &td_emlrtRTEI, true);
  emxInit_int32_T(sp, &jpvt, 2, &td_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Pitch, 2, &td_emlrtRTEI, true);
  emxInit_real_T(sp, &c_Pitch, 2, &td_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SPitch, 2, &td_emlrtRTEI, true);
  while (i <= (int32_T)Prm_nccf_maxcands - 1) {
    /* 'tm_trk:87' diff   =  abs( (Pitch(i,:) - SPitch(1,:))); */
    i41 = Pitch->size[0];
    rankR = i + 1;
    if (!((rankR >= 1) && (rankR <= i41))) {
      emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &gi_emlrtBCI, sp);
    }

    minmn = Pitch->size[1];
    i41 = c_Pitch->size[0] * c_Pitch->size[1];
    c_Pitch->size[0] = 1;
    c_Pitch->size[1] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)c_Pitch, i41, (int32_T)sizeof
                      (real_T), &td_emlrtRTEI);
    for (i41 = 0; i41 < minmn; i41++) {
      c_Pitch->data[c_Pitch->size[0] * i41] = Pitch->data[i + Pitch->size[0] *
        i41];
    }

    for (i41 = 0; i41 < 2; i41++) {
      d_Pitch[i41] = c_Pitch->size[i41];
    }

    minmn = SPitch->size[1];
    i41 = b_SPitch->size[0] * b_SPitch->size[1];
    b_SPitch->size[0] = 1;
    b_SPitch->size[1] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i41, (int32_T)sizeof
                      (real_T), &td_emlrtRTEI);
    for (i41 = 0; i41 < minmn; i41++) {
      b_SPitch->data[b_SPitch->size[0] * i41] = SPitch->data[SPitch->size[0] *
        i41];
    }

    for (i41 = 0; i41 < 2; i41++) {
      c_SPitch[i41] = b_SPitch->size[i41];
    }

    if ((d_Pitch[0] != c_SPitch[0]) || (d_Pitch[1] != c_SPitch[1])) {
      emlrtSizeEqCheckNDR2012b(&d_Pitch[0], &c_SPitch[0], &yb_emlrtECI, sp);
    }

    minmn = Pitch->size[1];
    i41 = b_Pitch->size[0] * b_Pitch->size[1];
    b_Pitch->size[0] = 1;
    b_Pitch->size[1] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i41, (int32_T)sizeof
                      (real_T), &td_emlrtRTEI);
    for (i41 = 0; i41 < minmn; i41++) {
      b_Pitch->data[b_Pitch->size[0] * i41] = Pitch->data[i + Pitch->size[0] *
        i41] - SPitch->data[SPitch->size[0] * i41];
    }

    st.site = &vl_emlrtRSI;
    d_abs(&st, b_Pitch, temp_min);

    /* 'tm_trk:88' match1 = zeros(1,length(diff)); */
    i41 = match1->size[0] * match1->size[1];
    match1->size[0] = 1;
    match1->size[1] = temp_min->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)match1, i41, (int32_T)sizeof
                      (real_T), &td_emlrtRTEI);
    minmn = temp_min->size[1];
    for (i41 = 0; i41 < minmn; i41++) {
      match1->data[i41] = 0.0;
    }

    /* 'tm_trk:89' for j = 1:length(diff) */
    j = 1;
    while (j - 1 <= temp_min->size[1] - 1) {
      /* 'tm_trk:90' match1(j) = diff(j) < freq_thresh; */
      i41 = temp_min->size[1];
      if (!((j >= 1) && (j <= i41))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i41, &oi_emlrtBCI, sp);
      }

      tol = temp_min->data[j - 1];
      i41 = tau->size[0];
      tau->size[0] = freq_thresh->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)tau, i41, (int32_T)sizeof(real_T),
                        &td_emlrtRTEI);
      minmn = freq_thresh->size[0];
      for (i41 = 0; i41 < minmn; i41++) {
        tau->data[i41] = (tol < freq_thresh->data[i41]);
      }

      i41 = tau->size[0];
      if (1 != i41) {
        emlrtSizeEqCheck1DR2012b(1, i41, &xb_emlrtECI, sp);
      }

      i41 = tau->size[0];
      if (!(1 <= i41)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i41, &ei_emlrtBCI, sp);
      }

      i41 = match1->size[1];
      if (!((j >= 1) && (j <= i41))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i41, &pi_emlrtBCI, sp);
      }

      match1->data[j - 1] = tau->data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*      match1 =  (diff < freq_thresh); */
    /* 'tm_trk:93' match = zeros(1,length(diff)); */
    i41 = match->size[0] * match->size[1];
    match->size[0] = 1;
    match->size[1] = temp_min->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)match, i41, (int32_T)sizeof(real_T),
                      &td_emlrtRTEI);
    minmn = temp_min->size[1];
    for (i41 = 0; i41 < minmn; i41++) {
      match->data[i41] = 0.0;
    }

    /* 'tm_trk:94' for j = 1:length(diff) */
    j = 0;
    while (j <= temp_min->size[1] - 1) {
      /* 'tm_trk:95' match(j) = ((1 - (diff(j)/freq_thresh)) * match1(j)); */
      st.site = &wl_emlrtRSI;
      i41 = temp_min->size[1];
      rankR = j + 1;
      if (!((rankR >= 1) && (rankR <= i41))) {
        emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &fi_emlrtBCI, &st);
      }

      if (freq_thresh->size[0] == 0) {
        i41 = temp_max->size[0] * temp_max->size[1];
        temp_max->size[0] = 1;
        temp_max->size[1] = 0;
        emxEnsureCapacity(&st, (emxArray__common *)temp_max, i41, (int32_T)
                          sizeof(real_T), &td_emlrtRTEI);
      } else if (freq_thresh->size[0] == 1) {
        b_st.site = &nm_emlrtRSI;
        c_st.site = &pc_emlrtRSI;
        d_st.site = &rc_emlrtRSI;
        e_st.site = &vc_emlrtRSI;
        i41 = tau->size[0];
        tau->size[0] = freq_thresh->size[0];
        emxEnsureCapacity(&e_st, (emxArray__common *)tau, i41, (int32_T)sizeof
                          (real_T), &td_emlrtRTEI);
        minmn = freq_thresh->size[0];
        for (i41 = 0; i41 < minmn; i41++) {
          tau->data[i41] = freq_thresh->data[i41];
        }

        info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)1, (ptrdiff_t)1, &tau->
          data[0], (ptrdiff_t)1, &ipiv_t);
        minmn = (int32_T)info_t;
        f_st.site = &xc_emlrtRSI;
        if (minmn < 0) {
          if (minmn == -1010) {
            g_st.site = &cd_emlrtRSI;
            e_error(&g_st);
          } else {
            g_st.site = &dd_emlrtRSI;
            f_error(&g_st, minmn);
          }

          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
          maxmn = tau->size[0];
          i41 = tau->size[0];
          tau->size[0] = maxmn;
          emxEnsureCapacity(&e_st, (emxArray__common *)tau, i41, (int32_T)sizeof
                            (real_T), &td_emlrtRTEI);
          for (i41 = 0; i41 < maxmn; i41++) {
            tau->data[i41] = rtNaN;
          }

          f_st.site = &yc_emlrtRSI;
        } else {
          f_st.site = &ad_emlrtRSI;
        }

        if (minmn > 0) {
          d_st.site = &qc_emlrtRSI;
          if (!emlrtSetWarningFlag(&d_st)) {
            e_st.site = &kd_emlrtRSI;
            warning(&e_st);
          }
        }

        tol = 1.0 / tau->data[0] * temp_min->data[j];
        i41 = temp_max->size[0] * temp_max->size[1];
        temp_max->size[0] = 1;
        temp_max->size[1] = 1;
        emxEnsureCapacity(&st, (emxArray__common *)temp_max, i41, (int32_T)
                          sizeof(real_T), &td_emlrtRTEI);
        temp_max->data[0] = tol;
      } else {
        b_st.site = &nm_emlrtRSI;
        i41 = temp_max->size[0] * temp_max->size[1];
        temp_max->size[0] = 1;
        temp_max->size[1] = freq_thresh->size[0];
        emxEnsureCapacity(&b_st, (emxArray__common *)temp_max, i41, (int32_T)
                          sizeof(real_T), &td_emlrtRTEI);
        minmn = freq_thresh->size[0];
        for (i41 = 0; i41 < minmn; i41++) {
          temp_max->data[temp_max->size[0] * i41] = freq_thresh->data[i41];
        }

        c_st.site = &md_emlrtRSI;
        b_xgeqp3(&c_st, temp_max, tau, jpvt);
        c_st.site = &nd_emlrtRSI;
        rankR = 0;
        tol = 0.0;
        if (1 < temp_max->size[1]) {
          minmn = 1;
          maxmn = temp_max->size[1];
        } else {
          minmn = temp_max->size[1];
          maxmn = 1;
        }

        if (minmn > 0) {
          tol = (real_T)maxmn * muDoubleScalarAbs(temp_max->data[0]) *
            2.2204460492503131E-16;
          while ((rankR < 1) && (muDoubleScalarAbs(temp_max->data[0]) >= tol)) {
            rankR = 1;
          }
        }

        if ((rankR < minmn) && (!emlrtSetWarningFlag(&c_st))) {
          d_st.site = &ud_emlrtRSI;
          for (i41 = 0; i41 < 6; i41++) {
            u[i41] = rfmt[i41];
          }

          y = NULL;
          m10 = emlrtCreateCharArray(2, iv52);
          emlrtInitCharArrayR2013a(&d_st, 6, m10, &u[0]);
          emlrtAssign(&y, m10);
          e_st.site = &ko_emlrtRSI;
          emlrt_marshallIn(&e_st, b_sprintf(&e_st, y, emlrt_marshallOut(tol),
            &e_emlrtMCI), "sprintf", cv10);
          d_st.site = &vd_emlrtRSI;
          b_warning(&d_st, 0, cv10);
        }

        c_st.site = &od_emlrtRSI;
        b_LSQFromQR(&c_st, temp_max, tau, jpvt, temp_min->data[j], rankR, Y);
        i41 = temp_max->size[0] * temp_max->size[1];
        temp_max->size[0] = 1;
        temp_max->size[1] = Y->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)temp_max, i41, (int32_T)
                          sizeof(real_T), &td_emlrtRTEI);
        minmn = Y->size[0];
        for (i41 = 0; i41 < minmn; i41++) {
          temp_max->data[temp_max->size[0] * i41] = Y->data[i41];
        }
      }

      i41 = match1->size[1];
      rankR = j + 1;
      if (!((rankR >= 1) && (rankR <= i41))) {
        emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &di_emlrtBCI, sp);
      }

      i41 = temp_max->size[0] * temp_max->size[1];
      temp_max->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)temp_max, i41, (int32_T)sizeof
                        (real_T), &td_emlrtRTEI);
      minmn = temp_max->size[0];
      maxmn = temp_max->size[1];
      tol = match1->data[j];
      minmn *= maxmn;
      for (i41 = 0; i41 < minmn; i41++) {
        temp_max->data[i41] = (1.0 - temp_max->data[i41]) * tol;
      }

      i41 = temp_max->size[1];
      if (1 != i41) {
        emlrtSizeEqCheck1DR2012b(1, i41, &vb_emlrtECI, sp);
      }

      i41 = temp_max->size[1];
      if (!(1 <= i41)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i41, &ai_emlrtBCI, sp);
      }

      i41 = match->size[1];
      rankR = 1 + j;
      if (!((rankR >= 1) && (rankR <= i41))) {
        emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &ni_emlrtBCI, sp);
      }

      match->data[rankR - 1] = temp_max->data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    /* 'tm_trk:98' Merit(i,:) = ((1+merit_boost)*Merit(i,:)).*match; */
    i41 = Merit->size[0];
    rankR = i + 1;
    if (!((rankR >= 1) && (rankR <= i41))) {
      emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &bi_emlrtBCI, sp);
    }

    minmn = Merit->size[1];
    i41 = r40->size[0] * r40->size[1];
    r40->size[0] = 1;
    r40->size[1] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)r40, i41, (int32_T)sizeof(real_T),
                      &td_emlrtRTEI);
    for (i41 = 0; i41 < minmn; i41++) {
      r40->data[r40->size[0] * i41] = (1.0 + Prm_merit_boost) * Merit->data[i +
        Merit->size[0] * i41];
    }

    for (i41 = 0; i41 < 2; i41++) {
      iv53[i41] = r40->size[i41];
    }

    for (i41 = 0; i41 < 2; i41++) {
      b_match[i41] = match->size[i41];
    }

    if ((iv53[0] != b_match[0]) || (iv53[1] != b_match[1])) {
      emlrtSizeEqCheckNDR2012b(&iv53[0], &b_match[0], &ub_emlrtECI, sp);
    }

    i41 = Merit->size[0];
    rankR = i + 1;
    if (!((rankR >= 1) && (rankR <= i41))) {
      emlrtDynamicBoundsCheckR2012b(rankR, 1, i41, &yh_emlrtBCI, sp);
    }

    minmn = Merit->size[1];
    i41 = r39->size[0];
    r39->size[0] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)r39, i41, (int32_T)sizeof(int32_T),
                      &td_emlrtRTEI);
    for (i41 = 0; i41 < minmn; i41++) {
      r39->data[i41] = i41;
    }

    i41 = r40->size[0] * r40->size[1];
    r40->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r40, i41, (int32_T)sizeof(real_T),
                      &td_emlrtRTEI);
    i41 = r40->size[0];
    rankR = r40->size[1];
    minmn = i41 * rankR;
    for (i41 = 0; i41 < minmn; i41++) {
      r40->data[i41] *= match->data[i41];
    }

    iv54[0] = 1;
    iv54[1] = r39->size[0];
    emlrtSubAssignSizeCheckR2012b(iv54, 2, *(int32_T (*)[2])r40->size, 2,
      &tb_emlrtECI, sp);
    minmn = r40->size[1];
    for (i41 = 0; i41 < minmn; i41++) {
      Merit->data[i + Merit->size[0] * r39->data[i41]] = r40->data[r40->size[0] *
        i41];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_SPitch);
  emxFree_real_T(&c_Pitch);
  emxFree_real_T(&b_Pitch);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&tau);
  emxFree_real_T(&Y);
  emxFree_real_T(&r40);
  emxFree_int32_T(&r39);
  emxFree_real_T(&match);
  emxFree_real_T(&match1);
  emxFree_real_T(&temp_min);
  emxFree_real_T(&freq_thresh);
  emxFree_real_T(&temp_max);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (tm_trk.c) */
