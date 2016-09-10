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
#include "yaapt_emxutil.h"
#include "cmp_rate.h"
#include "crs_corr.h"
#include "fix.h"
#include "mrdivide.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ue_emlrtRSI = { 19, "scalexpAllocNoCheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m"
};

static emlrtRSInfo kn_emlrtRSI = { 55, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo ln_emlrtRSI = { 56, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo mn_emlrtRSI = { 74, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo nn_emlrtRSI = { 78, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo on_emlrtRSI = { 87, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo pn_emlrtRSI = { 95, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo qn_emlrtRSI = { 81, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo rn_emlrtRSI = { 243, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo sn_emlrtRSI = { 269, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRTEInfo ee_emlrtRTEI = { 1, 27, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo fe_emlrtRTEI = { 46, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo ge_emlrtRTEI = { 47, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo he_emlrtRTEI = { 49, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo ie_emlrtRTEI = { 50, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo je_emlrtRTEI = { 87, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo ke_emlrtRTEI = { 93, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo tb_emlrtECI = { -1, 52, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 52, 5, "SPitch(i)-2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo ub_emlrtECI = { -1, 53, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 53, 5, "SPitch(i)+2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtRTEInfo dh_emlrtRTEI = { 63, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtDCInfo gd_emlrtDCI = { 66, 14, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 66, 14, "Data", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo vb_emlrtECI = { -1, 55, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo wb_emlrtECI = { -1, 56, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 71, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 72, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtRTEInfo eh_emlrtRTEI = { 86, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo di_emlrtBCI = { -1, -1, 78, 14, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo xb_emlrtECI = { -1, 78, 6, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 87, 27, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo yb_emlrtECI = { 2, 87, 21, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo ac_emlrtECI = { -1, 90, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 90, 10,
  "match1(j) = diff(j) < freq_thresh", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 95, 52, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 78, 25, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo bc_emlrtECI = { -1, 78, 17, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ii_emlrtBCI = { -1, -1, 98, 41, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo cc_emlrtECI = { -1, 95, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 95, 10,
  "(1 - (diff(j)/freq_thresh)) * match1(j)", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo dc_emlrtECI = { 2, 98, 18, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ki_emlrtBCI = { -1, -1, 98, 11, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo ec_emlrtECI = { -1, 98, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtDCInfo hd_emlrtDCI = { 59, 15, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtDCInfo id_emlrtDCI = { 59, 15, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtDCInfo jd_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtDCInfo kd_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtBCInfo li_emlrtBCI = { -1, -1, 95, 28, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo mi_emlrtBCI = { -1, -1, 95, 10, "match", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ni_emlrtBCI = { -1, -1, 90, 22, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo oi_emlrtBCI = { -1, -1, 90, 10, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo pi_emlrtBCI = { -1, -1, 52, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo qi_emlrtBCI = { -1, -1, 52, 5, "temp_max", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ri_emlrtBCI = { -1, -1, 53, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo si_emlrtBCI = { -1, -1, 53, 5, "temp_min", "tm_trk",
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
  real_T nframesize;
  real_T nframejump;
  real_T numframes;
  int32_T i46;
  int32_T k;
  emxArray_real_T *SRange;
  emxArray_real_T *temp_max;
  emxArray_real_T *temp_min;
  int32_T i;
  emxArray_real_T *r35;
  emxArray_int32_T *r36;
  uint32_T uv8[2];
  emxArray_real_T *b_diff;
  emxArray_real_T *r37;
  boolean_T overflow;
  int32_T iv48[2];
  emxArray_real_T *match;
  int32_T iv49[2];
  real_T d1;
  real_T b_temp_max;
  int32_T n;
  emxArray_real_T *b_Data;
  real_T firstp;
  int32_T i47;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *b_SPitch;
  int32_T b_temp_min;
  int32_T c_Pitch[2];
  int32_T c_SPitch[2];
  int32_T iv50[1];
  int32_T iv51[1];
  int32_T j;
  int32_T iv52[2];
  int32_T b_match[2];
  int32_T iv53[2];
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
  emxInit_real_T1(sp, &freq_thresh, 1, &fe_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 16U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 0);

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
  i46 = freq_thresh->size[0];
  freq_thresh->size[0] = pStd->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)freq_thresh, i46, (int32_T)sizeof
                    (real_T), &ee_emlrtRTEI);
  k = pStd->size[0];
  for (i46 = 0; i46 < k; i46++) {
    freq_thresh->data[i46] = 5.0 * pStd->data[i46];
  }

  emxInit_real_T(sp, &SRange, 2, &ge_emlrtRTEI, true);

  /* 'tm_trk:47' SRange = zeros(2,length(SPitch)); */
  i46 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  SRange->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SRange, i46, (int32_T)sizeof(real_T),
                    &ee_emlrtRTEI);
  k = SPitch->size[1] << 1;
  for (i46 = 0; i46 < k; i46++) {
    SRange->data[i46] = 0.0;
  }

  emxInit_real_T(sp, &temp_max, 2, &he_emlrtRTEI, true);

  /*  Determine the search range according spectral pitch track */
  /* 'tm_trk:49' temp_max = zeros(1,length(SPitch)); */
  i46 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  temp_max->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_max, i46, (int32_T)sizeof
                    (real_T), &ee_emlrtRTEI);
  k = SPitch->size[1];
  for (i46 = 0; i46 < k; i46++) {
    temp_max->data[i46] = 0.0;
  }

  emxInit_real_T(sp, &temp_min, 2, &ie_emlrtRTEI, true);

  /* 'tm_trk:50' temp_min = zeros(1,length(SPitch)); */
  i46 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  temp_min->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_min, i46, (int32_T)sizeof
                    (real_T), &ee_emlrtRTEI);
  k = SPitch->size[1];
  for (i46 = 0; i46 < k; i46++) {
    temp_min->data[i46] = 0.0;
  }

  /* 'tm_trk:51' for i = 1:length(SPitch) */
  i = 1;
  emxInit_real_T1(sp, &r35, 1, &ee_emlrtRTEI, true);
  while (i - 1 <= SPitch->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 1);

    /* 'tm_trk:52' temp_max(i) = SPitch(i)-2*pStd; */
    i46 = r35->size[0];
    r35->size[0] = pStd->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r35, i46, (int32_T)sizeof(real_T),
                      &ee_emlrtRTEI);
    k = pStd->size[0];
    for (i46 = 0; i46 < k; i46++) {
      r35->data[i46] = 2.0 * pStd->data[i46];
    }

    i46 = r35->size[0];
    if (1 != i46) {
      emlrtSizeEqCheck1DR2012b(1, i46, &tb_emlrtECI, sp);
    }

    i46 = r35->size[0];
    if (!(1 <= i46)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i46, &xh_emlrtBCI, sp);
    }

    i46 = SPitch->size[1];
    if (!((i >= 1) && (i <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i46, &pi_emlrtBCI, sp);
    }

    i46 = temp_max->size[1];
    if (!((i >= 1) && (i <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i46, &qi_emlrtBCI, sp);
    }

    temp_max->data[i - 1] = SPitch->data[i - 1] - r35->data[0];

    /* 'tm_trk:53' temp_min(i) = SPitch(i)+2*pStd; */
    i46 = r35->size[0];
    r35->size[0] = pStd->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r35, i46, (int32_T)sizeof(real_T),
                      &ee_emlrtRTEI);
    k = pStd->size[0];
    for (i46 = 0; i46 < k; i46++) {
      r35->data[i46] = 2.0 * pStd->data[i46];
    }

    i46 = r35->size[0];
    if (1 != i46) {
      emlrtSizeEqCheck1DR2012b(1, i46, &ub_emlrtECI, sp);
    }

    i46 = r35->size[0];
    if (!(1 <= i46)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i46, &yh_emlrtBCI, sp);
    }

    i46 = SPitch->size[1];
    if (!((i >= 1) && (i <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i46, &ri_emlrtBCI, sp);
    }

    i46 = temp_min->size[1];
    if (!((i >= 1) && (i <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i46, &si_emlrtBCI, sp);
    }

    temp_min->data[i - 1] = SPitch->data[i - 1] + r35->data[0];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_int32_T1(sp, &r36, 1, &ee_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 2);

  /* 'tm_trk:55' SRange(1,:)  = max(temp_max, Prm.f0_min); */
  k = SPitch->size[1];
  i46 = r36->size[0];
  r36->size[0] = k;
  emxEnsureCapacity(sp, (emxArray__common *)r36, i46, (int32_T)sizeof(int32_T),
                    &ee_emlrtRTEI);
  for (i46 = 0; i46 < k; i46++) {
    r36->data[i46] = i46;
  }

  st.site = &kn_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &qn_emlrtRSI;
  e_st.site = &rn_emlrtRSI;
  f_st.site = &te_emlrtRSI;
  g_st.site = &ue_emlrtRSI;
  for (i46 = 0; i46 < 2; i46++) {
    uv8[i46] = (uint32_T)temp_max->size[i46];
  }

  emxInit_real_T(&g_st, &b_diff, 2, &je_emlrtRTEI, true);
  emxInit_real_T(&g_st, &r37, 2, &ee_emlrtRTEI, true);
  i46 = b_diff->size[0] * b_diff->size[1];
  b_diff->size[0] = 1;
  b_diff->size[1] = (int32_T)uv8[1];
  emxEnsureCapacity(&g_st, (emxArray__common *)b_diff, i46, (int32_T)sizeof
                    (real_T), &ee_emlrtRTEI);
  i46 = r37->size[0] * r37->size[1];
  r37->size[0] = 1;
  r37->size[1] = (int32_T)uv8[1];
  emxEnsureCapacity(&f_st, (emxArray__common *)r37, i46, (int32_T)sizeof(real_T),
                    &ee_emlrtRTEI);
  if (dimagree(r37, temp_max)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &jf_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &sn_emlrtRSI;
  overflow = ((!(1 > b_diff->size[1])) && (b_diff->size[1] > 2147483646));
  if (overflow) {
    f_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&f_st, true);
  }

  for (k = 0; k + 1 <= (int32_T)uv8[1]; k++) {
    r37->data[k] = muDoubleScalarMax(temp_max->data[k], Prm_f0_min);
  }

  iv48[0] = 1;
  iv48[1] = r36->size[0];
  emlrtSubAssignSizeCheckR2012b(iv48, 2, *(int32_T (*)[2])r37->size, 2,
    &vb_emlrtECI, sp);
  k = r37->size[1];
  for (i46 = 0; i46 < k; i46++) {
    SRange->data[SRange->size[0] * r36->data[i46]] = r37->data[r37->size[0] *
      i46];
  }

  /* 'tm_trk:56' SRange(2,:)  = min(temp_min, Prm.f0_max); */
  k = SRange->size[1];
  i46 = r36->size[0];
  r36->size[0] = k;
  emxEnsureCapacity(sp, (emxArray__common *)r36, i46, (int32_T)sizeof(int32_T),
                    &ee_emlrtRTEI);
  for (i46 = 0; i46 < k; i46++) {
    r36->data[i46] = i46;
  }

  st.site = &ln_emlrtRSI;
  b_st.site = &kb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &qn_emlrtRSI;
  e_st.site = &rn_emlrtRSI;
  f_st.site = &te_emlrtRSI;
  g_st.site = &ue_emlrtRSI;
  for (i46 = 0; i46 < 2; i46++) {
    uv8[i46] = (uint32_T)temp_min->size[i46];
  }

  emxInit_real_T(&g_st, &match, 2, &ke_emlrtRTEI, true);
  i46 = match->size[0] * match->size[1];
  match->size[0] = 1;
  match->size[1] = (int32_T)uv8[1];
  emxEnsureCapacity(&g_st, (emxArray__common *)match, i46, (int32_T)sizeof
                    (real_T), &ee_emlrtRTEI);
  i46 = r37->size[0] * r37->size[1];
  r37->size[0] = 1;
  r37->size[1] = (int32_T)uv8[1];
  emxEnsureCapacity(&f_st, (emxArray__common *)r37, i46, (int32_T)sizeof(real_T),
                    &ee_emlrtRTEI);
  if (dimagree(r37, temp_min)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &jf_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &sn_emlrtRSI;
  overflow = ((!(1 > match->size[1])) && (match->size[1] > 2147483646));
  if (overflow) {
    f_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&f_st, true);
  }

  for (k = 0; k + 1 <= (int32_T)uv8[1]; k++) {
    r37->data[k] = muDoubleScalarMin(temp_min->data[k], Prm_f0_max);
  }

  iv49[0] = 1;
  iv49[1] = r36->size[0];
  emlrtSubAssignSizeCheckR2012b(iv49, 2, *(int32_T (*)[2])r37->size, 2,
    &wb_emlrtECI, sp);
  k = r37->size[1];
  for (i46 = 0; i46 < k; i46++) {
    SRange->data[1 + SRange->size[0] * r36->data[i46]] = r37->data[r37->size[0] *
      i46];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'tm_trk:59' Pitch = zeros(maxcands, numframes); */
  i46 = Pitch->size[0] * Pitch->size[1];
  if (!(Prm_nccf_maxcands >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Prm_nccf_maxcands, &id_emlrtDCI, sp);
  }

  d1 = Prm_nccf_maxcands;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &hd_emlrtDCI, sp);
  }

  Pitch->size[0] = (int32_T)d1;
  if (!(numframes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &kd_emlrtDCI, sp);
  }

  d1 = numframes;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &jd_emlrtDCI, sp);
  }

  Pitch->size[1] = (int32_T)d1;
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i46, (int32_T)sizeof(real_T),
                    &ee_emlrtRTEI);
  if (!(Prm_nccf_maxcands >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Prm_nccf_maxcands, &id_emlrtDCI, sp);
  }

  d1 = Prm_nccf_maxcands;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &hd_emlrtDCI, sp);
  }

  if (!(numframes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &kd_emlrtDCI, sp);
  }

  b_temp_max = numframes;
  if (b_temp_max != (int32_T)muDoubleScalarFloor(b_temp_max)) {
    emlrtIntegerCheckR2012b(b_temp_max, &jd_emlrtDCI, sp);
  }

  k = (int32_T)d1 * (int32_T)b_temp_max;
  for (i46 = 0; i46 < k; i46++) {
    Pitch->data[i46] = 0.0;
  }

  /* 'tm_trk:60' Merit = zeros(maxcands, numframes); */
  i46 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = (int32_T)Prm_nccf_maxcands;
  Merit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i46, (int32_T)sizeof(real_T),
                    &ee_emlrtRTEI);
  k = (int32_T)Prm_nccf_maxcands * (int32_T)numframes;
  for (i46 = 0; i46 < k; i46++) {
    Merit->data[i46] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /* 'tm_trk:63' for n = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &dh_emlrtRTEI, sp);
  n = 0;
  emxInit_real_T1(sp, &b_Data, 1, &ee_emlrtRTEI, true);
  while (n <= (int32_T)numframes - 1) {
    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 3);

    /* 'tm_trk:65' firstp = 1+((n-1)*(nframejump)); */
    firstp = 1.0 + ((1.0 + (real_T)n) - 1.0) * nframejump;

    /* 'tm_trk:66' Signal = Data(firstp:firstp+nframesize-1); */
    d1 = (firstp + nframesize) - 1.0;
    if (firstp > d1) {
      i46 = 0;
      k = 0;
    } else {
      if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
        emlrtIntegerCheckR2012b(firstp, &gd_emlrtDCI, sp);
      }

      i46 = Data->size[1];
      i47 = (int32_T)firstp;
      if (!((i47 >= 1) && (i47 <= i46))) {
        emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &ai_emlrtBCI, sp);
      }

      i46 = i47 - 1;
      if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
        emlrtIntegerCheckR2012b(d1, &gd_emlrtDCI, sp);
      }

      i47 = Data->size[1];
      k = (int32_T)d1;
      if (!((k >= 1) && (k <= i47))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i47, &ai_emlrtBCI, sp);
      }
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    /* 'tm_trk:71' Lag_min0 = fix(Fs/SRange(2,n)) - 3; */
    i47 = SRange->size[1];
    b_temp_min = n + 1;
    if (!((b_temp_min >= 1) && (b_temp_min <= i47))) {
      emlrtDynamicBoundsCheckR2012b(b_temp_min, 1, i47, &bi_emlrtBCI, sp);
    }

    d1 = Fs / SRange->data[1 + SRange->size[0] * n];
    b_fix(&d1);

    /* 'tm_trk:72' Lag_max0 = fix(Fs/SRange(1,n)) + 3; */
    i47 = SRange->size[1];
    b_temp_min = n + 1;
    if (!((b_temp_min >= 1) && (b_temp_min <= i47))) {
      emlrtDynamicBoundsCheckR2012b(b_temp_min, 1, i47, &ci_emlrtBCI, sp);
    }

    b_temp_max = Fs / SRange->data[SRange->size[0] * n];
    if (b_temp_max < 0.0) {
      b_temp_max = muDoubleScalarCeil(b_temp_max);
    } else {
      b_temp_max = muDoubleScalarFloor(b_temp_max);
    }

    /*  Compute correaltion */
    /* 'tm_trk:74' Phi =  crs_corr(Signal', Lag_min0, Lag_max0); */
    i47 = b_Data->size[0];
    b_Data->size[0] = k - i46;
    emxEnsureCapacity(sp, (emxArray__common *)b_Data, i47, (int32_T)sizeof
                      (real_T), &ee_emlrtRTEI);
    k -= i46;
    for (i47 = 0; i47 < k; i47++) {
      b_Data->data[i47] = Data->data[i46 + i47];
    }

    st.site = &mn_emlrtRSI;
    crs_corr(&st, b_Data, d1 - 3.0, b_temp_max + 3.0, temp_max);

    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    /* 'tm_trk:78' [Pitch(:,n),Merit(:,n)] = cmp_rate(Phi,Fs,maxcands,Lag_min0,Lag_max0,Prm); */
    st.site = &nn_emlrtRSI;
    cmp_rate(&st, temp_max, Fs, Prm_nccf_maxcands, d1 - 3.0, b_temp_max + 3.0,
             Prm_nccf_thresh1, Prm_nccf_thresh2, Prm_nccf_pwidth, r37, temp_min);
    k = Pitch->size[0];
    i46 = r36->size[0];
    r36->size[0] = k;
    emxEnsureCapacity(sp, (emxArray__common *)r36, i46, (int32_T)sizeof(int32_T),
                      &ee_emlrtRTEI);
    for (i46 = 0; i46 < k; i46++) {
      r36->data[i46] = i46;
    }

    i46 = Pitch->size[1];
    i47 = n + 1;
    if (!((i47 >= 1) && (i47 <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &di_emlrtBCI, sp);
    }

    iv50[0] = r36->size[0];
    emlrtSubAssignSizeCheckR2012b(iv50, 1, *(int32_T (*)[2])r37->size, 2,
      &xb_emlrtECI, sp);
    k = r36->size[0];
    for (i46 = 0; i46 < k; i46++) {
      Pitch->data[r36->data[i46] + Pitch->size[0] * n] = r37->data[i46];
    }

    k = Merit->size[0];
    i46 = r36->size[0];
    r36->size[0] = k;
    emxEnsureCapacity(sp, (emxArray__common *)r36, i46, (int32_T)sizeof(int32_T),
                      &ee_emlrtRTEI);
    for (i46 = 0; i46 < k; i46++) {
      r36->data[i46] = i46;
    }

    i46 = Merit->size[1];
    i47 = n + 1;
    if (!((i47 >= 1) && (i47 <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &hi_emlrtBCI, sp);
    }

    iv51[0] = r36->size[0];
    emlrtSubAssignSizeCheckR2012b(iv51, 1, *(int32_T (*)[2])temp_min->size, 2,
      &bc_emlrtECI, sp);
    k = r36->size[0];
    for (i46 = 0; i46 < k; i46++) {
      Merit->data[r36->data[i46] + Merit->size[0] * n] = temp_min->data[i46];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Data);
  emxFree_real_T(&SRange);
  covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 1, 0);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  /* 'tm_trk:86' for i = 1:maxcands */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, Prm_nccf_maxcands, mxDOUBLE_CLASS,
    (int32_T)Prm_nccf_maxcands, &eh_emlrtRTEI, sp);
  i = 0;
  emxInit_real_T(sp, &b_Pitch, 2, &ee_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SPitch, 2, &ee_emlrtRTEI, true);
  while (i <= (int32_T)Prm_nccf_maxcands - 1) {
    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 4);

    /* 'tm_trk:87' diff   =  abs( (Pitch(i,:) - SPitch(1,:))); */
    i46 = Pitch->size[0];
    i47 = i + 1;
    if (!((i47 >= 1) && (i47 <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &ei_emlrtBCI, sp);
    }

    k = Pitch->size[1];
    i46 = b_Pitch->size[0] * b_Pitch->size[1];
    b_Pitch->size[0] = 1;
    b_Pitch->size[1] = k;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i46, (int32_T)sizeof
                      (real_T), &ee_emlrtRTEI);
    for (i46 = 0; i46 < k; i46++) {
      b_Pitch->data[b_Pitch->size[0] * i46] = Pitch->data[i + Pitch->size[0] *
        i46];
    }

    for (i46 = 0; i46 < 2; i46++) {
      c_Pitch[i46] = b_Pitch->size[i46];
    }

    k = SPitch->size[1];
    i46 = b_SPitch->size[0] * b_SPitch->size[1];
    b_SPitch->size[0] = 1;
    b_SPitch->size[1] = k;
    emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i46, (int32_T)sizeof
                      (real_T), &ee_emlrtRTEI);
    for (i46 = 0; i46 < k; i46++) {
      b_SPitch->data[b_SPitch->size[0] * i46] = SPitch->data[SPitch->size[0] *
        i46];
    }

    for (i46 = 0; i46 < 2; i46++) {
      c_SPitch[i46] = b_SPitch->size[i46];
    }

    if ((c_Pitch[0] != c_SPitch[0]) || (c_Pitch[1] != c_SPitch[1])) {
      emlrtSizeEqCheckNDR2012b(&c_Pitch[0], &c_SPitch[0], &yb_emlrtECI, sp);
    }

    st.site = &on_emlrtRSI;
    k = Pitch->size[1];
    i46 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)temp_max, i46, (int32_T)sizeof
                      (real_T), &ee_emlrtRTEI);
    for (i46 = 0; i46 < k; i46++) {
      temp_max->data[temp_max->size[0] * i46] = Pitch->data[i + Pitch->size[0] *
        i46] - SPitch->data[SPitch->size[0] * i46];
    }

    b_st.site = &mh_emlrtRSI;
    for (i46 = 0; i46 < 2; i46++) {
      uv8[i46] = (uint32_T)temp_max->size[i46];
    }

    i46 = b_diff->size[0] * b_diff->size[1];
    b_diff->size[0] = 1;
    b_diff->size[1] = (int32_T)uv8[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_diff, i46, (int32_T)sizeof
                      (real_T), &ee_emlrtRTEI);
    c_st.site = &nh_emlrtRSI;
    overflow = ((!(1 > temp_max->size[1])) && (temp_max->size[1] > 2147483646));
    if (overflow) {
      d_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (k = 0; k + 1 <= temp_max->size[1]; k++) {
      b_diff->data[k] = muDoubleScalarAbs(temp_max->data[k]);
    }

    /* 'tm_trk:88' match1 = zeros(1,length(diff)); */
    i46 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = b_diff->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)temp_max, i46, (int32_T)sizeof
                      (real_T), &ee_emlrtRTEI);
    k = b_diff->size[1];
    for (i46 = 0; i46 < k; i46++) {
      temp_max->data[i46] = 0.0;
    }

    /* 'tm_trk:89' for j = 1:length(diff) */
    j = 1;
    while (j - 1 <= b_diff->size[1] - 1) {
      covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 5);

      /* 'tm_trk:90' match1(j) = diff(j) < freq_thresh; */
      i46 = b_diff->size[1];
      if (!((j >= 1) && (j <= i46))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i46, &ni_emlrtBCI, sp);
      }

      b_temp_max = b_diff->data[j - 1];
      i46 = r35->size[0];
      r35->size[0] = freq_thresh->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)r35, i46, (int32_T)sizeof(real_T),
                        &ee_emlrtRTEI);
      k = freq_thresh->size[0];
      for (i46 = 0; i46 < k; i46++) {
        r35->data[i46] = (b_temp_max < freq_thresh->data[i46]);
      }

      i46 = r35->size[0];
      if (1 != i46) {
        emlrtSizeEqCheck1DR2012b(1, i46, &ac_emlrtECI, sp);
      }

      i46 = r35->size[0];
      if (!(1 <= i46)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i46, &fi_emlrtBCI, sp);
      }

      i46 = temp_max->size[1];
      if (!((j >= 1) && (j <= i46))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i46, &oi_emlrtBCI, sp);
      }

      temp_max->data[j - 1] = r35->data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 6);

    /*      match1 =  (diff < freq_thresh); */
    /* 'tm_trk:93' match = zeros(1,length(diff)); */
    i46 = match->size[0] * match->size[1];
    match->size[0] = 1;
    match->size[1] = b_diff->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)match, i46, (int32_T)sizeof(real_T),
                      &ee_emlrtRTEI);
    k = b_diff->size[1];
    for (i46 = 0; i46 < k; i46++) {
      match->data[i46] = 0.0;
    }

    /* 'tm_trk:94' for j = 1:length(diff) */
    j = 0;
    while (j <= b_diff->size[1] - 1) {
      covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 4, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 7);

      /* 'tm_trk:95' match(j) = ((1 - (diff(j)/freq_thresh)) * match1(j)); */
      i46 = b_diff->size[1];
      i47 = 1 + j;
      if (!((i47 >= 1) && (i47 <= i46))) {
        emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &li_emlrtBCI, sp);
      }

      st.site = &pn_emlrtRSI;
      mrdivide(&st, b_diff->data[i47 - 1], freq_thresh, temp_min);
      i46 = temp_min->size[0] * temp_min->size[1];
      temp_min->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)temp_min, i46, (int32_T)sizeof
                        (real_T), &ee_emlrtRTEI);
      k = temp_min->size[0];
      b_temp_min = temp_min->size[1];
      k *= b_temp_min;
      for (i46 = 0; i46 < k; i46++) {
        temp_min->data[i46] = 1.0 - temp_min->data[i46];
      }

      i46 = temp_max->size[1];
      i47 = j + 1;
      if (!((i47 >= 1) && (i47 <= i46))) {
        emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &gi_emlrtBCI, sp);
      }

      i46 = temp_min->size[0] * temp_min->size[1];
      temp_min->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)temp_min, i46, (int32_T)sizeof
                        (real_T), &ee_emlrtRTEI);
      k = temp_min->size[0];
      b_temp_min = temp_min->size[1];
      b_temp_max = temp_max->data[j];
      k *= b_temp_min;
      for (i46 = 0; i46 < k; i46++) {
        temp_min->data[i46] *= b_temp_max;
      }

      i46 = temp_min->size[1];
      if (1 != i46) {
        emlrtSizeEqCheck1DR2012b(1, i46, &cc_emlrtECI, sp);
      }

      i46 = temp_min->size[1];
      if (!(1 <= i46)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i46, &ji_emlrtBCI, sp);
      }

      i46 = match->size[1];
      i47 = 1 + j;
      if (!((i47 >= 1) && (i47 <= i46))) {
        emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &mi_emlrtBCI, sp);
      }

      match->data[i47 - 1] = temp_min->data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 8);

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    /* 'tm_trk:98' Merit(i,:) = ((1+merit_boost)*Merit(i,:)).*match; */
    i46 = Merit->size[0];
    i47 = i + 1;
    if (!((i47 >= 1) && (i47 <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &ii_emlrtBCI, sp);
    }

    k = Merit->size[1];
    i46 = r37->size[0] * r37->size[1];
    r37->size[0] = 1;
    r37->size[1] = k;
    emxEnsureCapacity(sp, (emxArray__common *)r37, i46, (int32_T)sizeof(real_T),
                      &ee_emlrtRTEI);
    for (i46 = 0; i46 < k; i46++) {
      r37->data[r37->size[0] * i46] = (1.0 + Prm_merit_boost) * Merit->data[i +
        Merit->size[0] * i46];
    }

    for (i46 = 0; i46 < 2; i46++) {
      iv52[i46] = r37->size[i46];
    }

    for (i46 = 0; i46 < 2; i46++) {
      b_match[i46] = match->size[i46];
    }

    if ((iv52[0] != b_match[0]) || (iv52[1] != b_match[1])) {
      emlrtSizeEqCheckNDR2012b(&iv52[0], &b_match[0], &dc_emlrtECI, sp);
    }

    i46 = Merit->size[0];
    i47 = i + 1;
    if (!((i47 >= 1) && (i47 <= i46))) {
      emlrtDynamicBoundsCheckR2012b(i47, 1, i46, &ki_emlrtBCI, sp);
    }

    k = Merit->size[1];
    i46 = r36->size[0];
    r36->size[0] = k;
    emxEnsureCapacity(sp, (emxArray__common *)r36, i46, (int32_T)sizeof(int32_T),
                      &ee_emlrtRTEI);
    for (i46 = 0; i46 < k; i46++) {
      r36->data[i46] = i46;
    }

    i46 = r37->size[0] * r37->size[1];
    r37->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r37, i46, (int32_T)sizeof(real_T),
                      &ee_emlrtRTEI);
    i46 = r37->size[0];
    i47 = r37->size[1];
    k = i46 * i47;
    for (i46 = 0; i46 < k; i46++) {
      r37->data[i46] *= match->data[i46];
    }

    iv53[0] = 1;
    iv53[1] = r36->size[0];
    emlrtSubAssignSizeCheckR2012b(iv53, 2, *(int32_T (*)[2])r37->size, 2,
      &ec_emlrtECI, sp);
    k = r37->size[1];
    for (i46 = 0; i46 < k; i46++) {
      Merit->data[i + Merit->size[0] * r36->data[i46]] = r37->data[r37->size[0] *
        i46];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_SPitch);
  emxFree_real_T(&b_Pitch);
  emxFree_real_T(&r35);
  emxFree_real_T(&r37);
  emxFree_int32_T(&r36);
  emxFree_real_T(&match);
  emxFree_real_T(&b_diff);
  emxFree_real_T(&temp_min);
  emxFree_real_T(&temp_max);
  emxFree_real_T(&freq_thresh);
  covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 2, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (tm_trk.c) */
