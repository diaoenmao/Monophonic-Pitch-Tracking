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
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo th_emlrtRSI = { 55, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo uh_emlrtRSI = { 56, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo vh_emlrtRSI = { 74, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo wh_emlrtRSI = { 78, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo xh_emlrtRSI = { 95, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo yh_emlrtRSI = { 59, "eml_min_or_max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m" };

static emlrtRSInfo ai_emlrtRSI = { 129, "eml_min_or_max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m" };

static emlrtRSInfo bi_emlrtRSI = { 16, "min",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo oi_emlrtRSI = { 1, "mrdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p" };

static emlrtRTEInfo tc_emlrtRTEI = { 1, 27, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo uc_emlrtRTEI = { 47, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo vc_emlrtRTEI = { 49, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo wc_emlrtRTEI = { 50, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo xc_emlrtRTEI = { 87, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo yc_emlrtRTEI = { 93, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo ob_emlrtECI = { -1, 98, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo pb_emlrtECI = { 2, 98, 18, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 95, 10,
  "match(j) = ((1 - (diff(j)/freq_thresh)) * match1(j))", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo qb_emlrtECI = { -1, 95, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo rb_emlrtECI = { -1, 78, 17, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 78, 25, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 95, 52, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 90, 10,
  "match1(j) = diff(j) < freq_thresh", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo sb_emlrtECI = { -1, 90, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 95, 28, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo tb_emlrtECI = { 2, 87, 21, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo ub_emlrtECI = { -1, 78, 6, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 78, 14, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 72, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 71, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo vb_emlrtECI = { -1, 56, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo wb_emlrtECI = { -1, 55, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 66, 14, "Data", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtDCInfo ib_emlrtDCI = { 66, 14, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtRTEInfo xd_emlrtRTEI = { 63, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 53, 5, "SPitch(i)+2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo xb_emlrtECI = { -1, 53, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 52, 5, "SPitch(i)-2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo yb_emlrtECI = { -1, 52, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtDCInfo jb_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 95, 10, "match", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 90, 22, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 90, 10, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 52, 5, "temp_max", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 52, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 53, 5, "temp_min", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 53, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

/* Function Definitions */

/*
 * function [Pitch, Merit] = tm_trk(Data, Fs, SPitch, pStd, pAvg, Prm)
 */
void tm_trk(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs, const
            emxArray_real_T *SPitch, const real_T pStd_data[], const int32_T
            pStd_size[1], emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  real_T firstp;
  real_T nframesize;
  real_T nframejump;
  real_T numframes;
  emxArray_real_T *y;
  int32_T i29;
  int32_T loop_ub;
  real_T freq_thresh_data[1];
  emxArray_real_T *SRange;
  int32_T unnamed_idx_1;
  emxArray_real_T *temp_max;
  emxArray_real_T *temp_min;
  int32_T i;
  emxArray_real_T *b_y;
  int32_T i30;
  emxArray_int32_T *r17;
  uint32_T uv3[2];
  emxArray_real_T *b_diff;
  boolean_T overflow;
  int32_T b_Pitch[2];
  int32_T b_SPitch[2];
  int32_T n;
  emxArray_real_T *b_Data;
  real_T x;
  real_T tmp_data[6];
  real_T b_tmp_data[6];
  static const int32_T iv67[1] = { 3 };

  emxArray_real_T *match;
  emxArray_real_T *c_Pitch;
  emxArray_real_T *c_SPitch;
  int8_T c_tmp_data[1];
  real_T b_freq_thresh_data[1];
  real_T y_data[1];
  int32_T iv68[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

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
  firstp = 25.0 * Fs / 1000.0;
  if (firstp < 0.0) {
    nframesize = muDoubleScalarCeil(firstp);
  } else {
    nframesize = muDoubleScalarFloor(firstp);
  }

  /* 'tm_trk:38' nframejump = fix(Prm.frame_space*Fs/1000); */
  firstp = 10.0 * Fs / 1000.0;
  if (firstp < 0.0) {
    nframejump = muDoubleScalarCeil(firstp);
  } else {
    nframejump = muDoubleScalarFloor(firstp);
  }

  /* 'tm_trk:39' noverlap   = nframesize-nframejump; */
  /*  overlap width in sample  */
  /* 'tm_trk:40' numframes  = fix((length(Data)-noverlap)/nframejump); */
  firstp = ((real_T)Data->size[1] - (nframesize - nframejump)) / nframejump;
  if (firstp < 0.0) {
    numframes = muDoubleScalarCeil(firstp);
  } else {
    numframes = muDoubleScalarFloor(firstp);
  }

  b_emxInit_real_T(sp, &y, 1, &tc_emlrtRTEI, true);

  /* 'tm_trk:42' merit_boost = Prm.merit_boost; */
  /*  The maximum number of pitch candidates */
  /* 'tm_trk:44' maxcands   = Prm.nccf_maxcands; */
  /* freq_thresh = pAvg;  % seems too large */
  /* 'tm_trk:46' freq_thresh = 5 * pStd; */
  i29 = y->size[0];
  y->size[0] = pStd_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y, i29, (int32_T)sizeof(real_T),
                    &tc_emlrtRTEI);
  loop_ub = pStd_size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    y->data[i29] = 5.0 * pStd_data[i29];
  }

  loop_ub = pStd_size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    freq_thresh_data[i29] = 5.0 * pStd_data[i29];
  }

  emxInit_real_T(sp, &SRange, 2, &uc_emlrtRTEI, true);

  /* 'tm_trk:47' SRange = zeros(2,length(SPitch)); */
  i29 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)SRange, i29, (int32_T)sizeof(real_T),
                    &tc_emlrtRTEI);
  unnamed_idx_1 = SPitch->size[1];
  i29 = SRange->size[0] * SRange->size[1];
  SRange->size[1] = unnamed_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)SRange, i29, (int32_T)sizeof(real_T),
                    &tc_emlrtRTEI);
  loop_ub = SPitch->size[1] << 1;
  for (i29 = 0; i29 < loop_ub; i29++) {
    SRange->data[i29] = 0.0;
  }

  emxInit_real_T(sp, &temp_max, 2, &vc_emlrtRTEI, true);

  /*  Determine the search range according spectral pitch track */
  /* 'tm_trk:49' temp_max = zeros(1,length(SPitch)); */
  i29 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)temp_max, i29, (int32_T)sizeof
                    (real_T), &tc_emlrtRTEI);
  unnamed_idx_1 = SPitch->size[1];
  i29 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[1] = unnamed_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)temp_max, i29, (int32_T)sizeof
                    (real_T), &tc_emlrtRTEI);
  loop_ub = SPitch->size[1];
  for (i29 = 0; i29 < loop_ub; i29++) {
    temp_max->data[i29] = 0.0;
  }

  emxInit_real_T(sp, &temp_min, 2, &wc_emlrtRTEI, true);

  /* 'tm_trk:50' temp_min = zeros(1,length(SPitch)); */
  i29 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)temp_min, i29, (int32_T)sizeof
                    (real_T), &tc_emlrtRTEI);
  unnamed_idx_1 = SPitch->size[1];
  i29 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[1] = unnamed_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)temp_min, i29, (int32_T)sizeof
                    (real_T), &tc_emlrtRTEI);
  loop_ub = SPitch->size[1];
  for (i29 = 0; i29 < loop_ub; i29++) {
    temp_min->data[i29] = 0.0;
  }

  /* 'tm_trk:51' for i = 1:length(SPitch) */
  i = 1;
  b_emxInit_real_T(sp, &b_y, 1, &tc_emlrtRTEI, true);
  while (i - 1 <= SPitch->size[1] - 1) {
    /* 'tm_trk:52' temp_max(i) = SPitch(i)-2*pStd; */
    i29 = b_y->size[0];
    b_y->size[0] = pStd_size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_y, i29, (int32_T)sizeof(real_T),
                      &tc_emlrtRTEI);
    loop_ub = pStd_size[0];
    for (i29 = 0; i29 < loop_ub; i29++) {
      b_y->data[i29] = 2.0 * pStd_data[i29];
    }

    i29 = b_y->size[0];
    emlrtSizeEqCheck1DFastR2012b(1, i29, &yb_emlrtECI, sp);
    i29 = b_y->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i29, &ig_emlrtBCI, sp);
    i29 = temp_max->size[1];
    i30 = SPitch->size[1];
    temp_max->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i29, &mg_emlrtBCI, sp)
      - 1] = SPitch->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i30,
      &ng_emlrtBCI, sp) - 1] - b_y->data[0];

    /* 'tm_trk:53' temp_min(i) = SPitch(i)+2*pStd; */
    i29 = b_y->size[0];
    b_y->size[0] = pStd_size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_y, i29, (int32_T)sizeof(real_T),
                      &tc_emlrtRTEI);
    loop_ub = pStd_size[0];
    for (i29 = 0; i29 < loop_ub; i29++) {
      b_y->data[i29] = 2.0 * pStd_data[i29];
    }

    i29 = b_y->size[0];
    emlrtSizeEqCheck1DFastR2012b(1, i29, &xb_emlrtECI, sp);
    i29 = b_y->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i29, &hg_emlrtBCI, sp);
    i29 = temp_min->size[1];
    i30 = SPitch->size[1];
    temp_min->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i29, &og_emlrtBCI, sp)
      - 1] = SPitch->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i30,
      &pg_emlrtBCI, sp) - 1] + b_y->data[0];
    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&b_y);
  emxInit_int32_T(sp, &r17, 1, &tc_emlrtRTEI, true);

  /* 'tm_trk:55' SRange(1,:)  = max(temp_max, Prm.f0_min); */
  unnamed_idx_1 = SPitch->size[1];
  i29 = r17->size[0];
  r17->size[0] = unnamed_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)r17, i29, (int32_T)sizeof(int32_T),
                    &tc_emlrtRTEI);
  for (i29 = 0; i29 < unnamed_idx_1; i29++) {
    r17->data[i29] = i29;
  }

  st.site = &th_emlrtRSI;
  b_st.site = &ye_emlrtRSI;
  c_st.site = &af_emlrtRSI;
  d_st.site = &yh_emlrtRSI;
  for (i29 = 0; i29 < 2; i29++) {
    uv3[i29] = (uint32_T)temp_max->size[i29];
  }

  emxInit_real_T(&d_st, &b_diff, 2, &xc_emlrtRTEI, true);
  i29 = b_diff->size[0] * b_diff->size[1];
  b_diff->size[0] = 1;
  b_diff->size[1] = (int32_T)uv3[1];
  emxEnsureCapacity(&d_st, (emxArray__common *)b_diff, i29, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  e_st.site = &ai_emlrtRSI;
  if (1 > (int32_T)uv3[1]) {
    overflow = false;
  } else {
    overflow = ((int32_T)uv3[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (unnamed_idx_1 = 0; unnamed_idx_1 + 1 <= (int32_T)uv3[1]; unnamed_idx_1++)
  {
    b_diff->data[unnamed_idx_1] = muDoubleScalarMax(temp_max->data[unnamed_idx_1],
      60.0);
  }

  b_Pitch[0] = 1;
  b_Pitch[1] = r17->size[0];
  emlrtSubAssignSizeCheckR2012b(b_Pitch, 2, *(int32_T (*)[2])b_diff->size, 2,
    &wb_emlrtECI, sp);
  loop_ub = b_diff->size[1];
  for (i29 = 0; i29 < loop_ub; i29++) {
    SRange->data[SRange->size[0] * r17->data[i29]] = b_diff->data[b_diff->size[0]
      * i29];
  }

  /* 'tm_trk:56' SRange(2,:)  = min(temp_min, Prm.f0_max); */
  loop_ub = SRange->size[1];
  i29 = r17->size[0];
  r17->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r17, i29, (int32_T)sizeof(int32_T),
                    &tc_emlrtRTEI);
  for (i29 = 0; i29 < loop_ub; i29++) {
    r17->data[i29] = i29;
  }

  st.site = &uh_emlrtRSI;
  b_st.site = &bi_emlrtRSI;
  c_st.site = &af_emlrtRSI;
  d_st.site = &yh_emlrtRSI;
  for (i29 = 0; i29 < 2; i29++) {
    uv3[i29] = (uint32_T)temp_min->size[i29];
  }

  i29 = b_diff->size[0] * b_diff->size[1];
  b_diff->size[0] = 1;
  b_diff->size[1] = (int32_T)uv3[1];
  emxEnsureCapacity(&d_st, (emxArray__common *)b_diff, i29, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  e_st.site = &ai_emlrtRSI;
  if (1 > (int32_T)uv3[1]) {
    overflow = false;
  } else {
    overflow = ((int32_T)uv3[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (unnamed_idx_1 = 0; unnamed_idx_1 + 1 <= (int32_T)uv3[1]; unnamed_idx_1++)
  {
    b_diff->data[unnamed_idx_1] = muDoubleScalarMin(temp_min->data[unnamed_idx_1],
      400.0);
  }

  b_SPitch[0] = 1;
  b_SPitch[1] = r17->size[0];
  emlrtSubAssignSizeCheckR2012b(b_SPitch, 2, *(int32_T (*)[2])b_diff->size, 2,
    &vb_emlrtECI, sp);
  loop_ub = b_diff->size[1];
  for (i29 = 0; i29 < loop_ub; i29++) {
    SRange->data[1 + SRange->size[0] * r17->data[i29]] = b_diff->data
      [b_diff->size[0] * i29];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'tm_trk:59' Pitch = zeros(maxcands, numframes); */
  i29 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 3;
  Pitch->size[1] = (int32_T)emlrtNonNegativeCheckFastR2012b(numframes,
    &jb_emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i29, (int32_T)sizeof(real_T),
                    &tc_emlrtRTEI);
  loop_ub = 3 * (int32_T)emlrtNonNegativeCheckFastR2012b(numframes, &jb_emlrtDCI,
    sp);
  for (i29 = 0; i29 < loop_ub; i29++) {
    Pitch->data[i29] = 0.0;
  }

  /* 'tm_trk:60' Merit = zeros(maxcands, numframes); */
  i29 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 3;
  Merit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i29, (int32_T)sizeof(real_T),
                    &tc_emlrtRTEI);
  loop_ub = 3 * (int32_T)numframes;
  for (i29 = 0; i29 < loop_ub; i29++) {
    Merit->data[i29] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /* 'tm_trk:63' for n = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &xd_emlrtRTEI, sp);
  n = 0;
  b_emxInit_real_T(sp, &b_Data, 1, &tc_emlrtRTEI, true);
  while (n <= (int32_T)numframes - 1) {
    /* 'tm_trk:65' firstp = 1+((n-1)*(nframejump)); */
    firstp = 1.0 + ((1.0 + (real_T)n) - 1.0) * nframejump;

    /* 'tm_trk:66' Signal = Data(firstp:firstp+nframesize-1); */
    x = (firstp + nframesize) - 1.0;
    if (firstp > x) {
      i29 = 0;
      i30 = 0;
    } else {
      i29 = Data->size[1];
      i30 = (int32_T)emlrtIntegerCheckFastR2012b(firstp, &ib_emlrtDCI, sp);
      i29 = emlrtDynamicBoundsCheckFastR2012b(i30, 1, i29, &gg_emlrtBCI, sp) - 1;
      i30 = Data->size[1];
      unnamed_idx_1 = (int32_T)emlrtIntegerCheckFastR2012b(x, &ib_emlrtDCI, sp);
      i30 = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_1, 1, i30,
        &gg_emlrtBCI, sp);
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    /* 'tm_trk:71' Lag_min0 = fix(Fs/SRange(2,n)) - 3; */
    unnamed_idx_1 = SRange->size[1];
    loop_ub = n + 1;
    emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, unnamed_idx_1, &fg_emlrtBCI,
      sp);
    firstp = Fs / SRange->data[1 + SRange->size[0] * n];
    if (firstp < 0.0) {
      x = muDoubleScalarCeil(firstp);
    } else {
      x = muDoubleScalarFloor(firstp);
    }

    /* 'tm_trk:72' Lag_max0 = fix(Fs/SRange(1,n)) + 3; */
    unnamed_idx_1 = SRange->size[1];
    loop_ub = n + 1;
    emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, unnamed_idx_1, &eg_emlrtBCI,
      sp);
    firstp = Fs / SRange->data[SRange->size[0] * n];
    if (firstp < 0.0) {
      firstp = muDoubleScalarCeil(firstp);
    } else {
      firstp = muDoubleScalarFloor(firstp);
    }

    /*  Compute correaltion */
    /* 'tm_trk:74' Phi =  crs_corr(Signal', Lag_min0, Lag_max0); */
    unnamed_idx_1 = b_Data->size[0];
    b_Data->size[0] = i30 - i29;
    emxEnsureCapacity(sp, (emxArray__common *)b_Data, unnamed_idx_1, (int32_T)
                      sizeof(real_T), &tc_emlrtRTEI);
    loop_ub = i30 - i29;
    for (i30 = 0; i30 < loop_ub; i30++) {
      b_Data->data[i30] = Data->data[i29 + i30];
    }

    st.site = &vh_emlrtRSI;
    crs_corr(&st, b_Data, x - 3.0, firstp + 3.0, temp_max);

    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    /* 'tm_trk:78' [Pitch(:,n),Merit(:,n)] = cmp_rate(Phi,Fs,maxcands,Lag_min0,Lag_max0,Prm); */
    st.site = &wh_emlrtRSI;
    cmp_rate(&st, temp_max, Fs, x - 3.0, firstp + 3.0, b_tmp_data, b_Pitch,
             tmp_data, b_SPitch);
    i29 = Pitch->size[1];
    i30 = n + 1;
    emlrtDynamicBoundsCheckFastR2012b(i30, 1, i29, &dg_emlrtBCI, sp);
    emlrtSubAssignSizeCheckR2012b(iv67, 1, b_Pitch, 2, &ub_emlrtECI, sp);
    for (i29 = 0; i29 < 3; i29++) {
      Pitch->data[i29 + Pitch->size[0] * n] = b_tmp_data[i29];
    }

    i29 = Merit->size[1];
    i30 = n + 1;
    emlrtDynamicBoundsCheckFastR2012b(i30, 1, i29, &yf_emlrtBCI, sp);
    emlrtSubAssignSizeCheckR2012b(iv67, 1, b_SPitch, 2, &rb_emlrtECI, sp);
    for (i29 = 0; i29 < 3; i29++) {
      Merit->data[i29 + Merit->size[0] * n] = tmp_data[i29];
    }

    n++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&b_Data);
  emxFree_real_T(&SRange);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  /* 'tm_trk:86' for i = 1:maxcands */
  emxInit_real_T(sp, &match, 2, &yc_emlrtRTEI, true);
  emxInit_real_T(sp, &c_Pitch, 2, &tc_emlrtRTEI, true);
  emxInit_real_T(sp, &c_SPitch, 2, &tc_emlrtRTEI, true);
  for (i = 0; i < 3; i++) {
    /* 'tm_trk:87' diff   =  abs( (Pitch(i,:) - SPitch(1,:))); */
    loop_ub = Pitch->size[1];
    i29 = c_Pitch->size[0] * c_Pitch->size[1];
    c_Pitch->size[0] = 1;
    c_Pitch->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)c_Pitch, i29, (int32_T)sizeof
                      (real_T), &tc_emlrtRTEI);
    for (i29 = 0; i29 < loop_ub; i29++) {
      c_Pitch->data[c_Pitch->size[0] * i29] = Pitch->data[i + Pitch->size[0] *
        i29];
    }

    for (i29 = 0; i29 < 2; i29++) {
      b_Pitch[i29] = c_Pitch->size[i29];
    }

    loop_ub = SPitch->size[1];
    i29 = c_SPitch->size[0] * c_SPitch->size[1];
    c_SPitch->size[0] = 1;
    c_SPitch->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)c_SPitch, i29, (int32_T)sizeof
                      (real_T), &tc_emlrtRTEI);
    for (i29 = 0; i29 < loop_ub; i29++) {
      c_SPitch->data[c_SPitch->size[0] * i29] = SPitch->data[SPitch->size[0] *
        i29];
    }

    for (i29 = 0; i29 < 2; i29++) {
      b_SPitch[i29] = c_SPitch->size[i29];
    }

    emlrtSizeEqCheck2DFastR2012b(b_Pitch, b_SPitch, &tb_emlrtECI, sp);
    loop_ub = Pitch->size[1];
    i29 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)temp_max, i29, (int32_T)sizeof
                      (real_T), &tc_emlrtRTEI);
    for (i29 = 0; i29 < loop_ub; i29++) {
      temp_max->data[temp_max->size[0] * i29] = Pitch->data[i + Pitch->size[0] *
        i29] - SPitch->data[SPitch->size[0] * i29];
    }

    for (i29 = 0; i29 < 2; i29++) {
      uv3[i29] = (uint32_T)temp_max->size[i29];
    }

    i29 = b_diff->size[0] * b_diff->size[1];
    b_diff->size[0] = 1;
    b_diff->size[1] = (int32_T)uv3[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_diff, i29, (int32_T)sizeof
                      (real_T), &i_emlrtRTEI);
    for (unnamed_idx_1 = 0; unnamed_idx_1 < temp_max->size[1]; unnamed_idx_1++)
    {
      b_diff->data[unnamed_idx_1] = muDoubleScalarAbs(temp_max->
        data[unnamed_idx_1]);
    }

    /* 'tm_trk:88' match1 = zeros(1,length(diff)); */
    i29 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)temp_max, i29, (int32_T)sizeof
                      (real_T), &tc_emlrtRTEI);
    unnamed_idx_1 = b_diff->size[1];
    i29 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[1] = unnamed_idx_1;
    emxEnsureCapacity(sp, (emxArray__common *)temp_max, i29, (int32_T)sizeof
                      (real_T), &tc_emlrtRTEI);
    loop_ub = b_diff->size[1];
    for (i29 = 0; i29 < loop_ub; i29++) {
      temp_max->data[i29] = 0.0;
    }

    /* 'tm_trk:89' for j = 1:length(diff) */
    n = 1;
    while (n - 1 <= b_diff->size[1] - 1) {
      /* 'tm_trk:90' match1(j) = diff(j) < freq_thresh; */
      i29 = b_diff->size[1];
      firstp = b_diff->data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i29,
        &kg_emlrtBCI, sp) - 1];
      unnamed_idx_1 = y->size[0];
      loop_ub = y->size[0];
      for (i29 = 0; i29 < loop_ub; i29++) {
        c_tmp_data[i29] = (int8_T)(firstp < y->data[i29]);
      }

      emlrtSizeEqCheck1DFastR2012b(1, unnamed_idx_1, &sb_emlrtECI, sp);
      emlrtDynamicBoundsCheckFastR2012b(1, 1, unnamed_idx_1, &bg_emlrtBCI, sp);
      i29 = temp_max->size[1];
      temp_max->data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i29, &lg_emlrtBCI,
        sp) - 1] = c_tmp_data[0];
      n++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    /*      match1 =  (diff < freq_thresh); */
    /* 'tm_trk:93' match = zeros(1,length(diff)); */
    i29 = match->size[0] * match->size[1];
    match->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)match, i29, (int32_T)sizeof(real_T),
                      &tc_emlrtRTEI);
    unnamed_idx_1 = b_diff->size[1];
    i29 = match->size[0] * match->size[1];
    match->size[1] = unnamed_idx_1;
    emxEnsureCapacity(sp, (emxArray__common *)match, i29, (int32_T)sizeof(real_T),
                      &tc_emlrtRTEI);
    loop_ub = b_diff->size[1];
    for (i29 = 0; i29 < loop_ub; i29++) {
      match->data[i29] = 0.0;
    }

    /* 'tm_trk:94' for j = 1:length(diff) */
    n = 0;
    while (n <= b_diff->size[1] - 1) {
      /* 'tm_trk:95' match(j) = ((1 - (diff(j)/freq_thresh)) * match1(j)); */
      st.site = &xh_emlrtRSI;
      i29 = b_diff->size[1];
      i30 = n + 1;
      emlrtDynamicBoundsCheckFastR2012b(i30, 1, i29, &cg_emlrtBCI, &st);
      if (y->size[0] == 0) {
        unnamed_idx_1 = 0;
      } else {
        b_st.site = &oi_emlrtRSI;
        c_st.site = &u_emlrtRSI;
        unnamed_idx_1 = 0;
        loop_ub = pStd_size[0];
        for (i29 = 0; i29 < loop_ub; i29++) {
          b_freq_thresh_data[i29] = freq_thresh_data[i29];
        }

        if (!(b_freq_thresh_data[0] != 0.0)) {
          unnamed_idx_1 = 1;
        }

        if (unnamed_idx_1 > 0) {
          d_st.site = &v_emlrtRSI;
          e_st.site = &pb_emlrtRSI;
          eml_warning(&e_st);
        }

        firstp = 1.0 / freq_thresh_data[0] * b_diff->data[n];
        unnamed_idx_1 = 1;
        y_data[0] = firstp;
      }

      i29 = temp_max->size[1];
      i30 = n + 1;
      emlrtDynamicBoundsCheckFastR2012b(i30, 1, i29, &ag_emlrtBCI, sp);
      i29 = temp_min->size[0] * temp_min->size[1];
      temp_min->size[0] = 1;
      temp_min->size[1] = unnamed_idx_1;
      emxEnsureCapacity(sp, (emxArray__common *)temp_min, i29, (int32_T)sizeof
                        (real_T), &tc_emlrtRTEI);
      firstp = temp_max->data[n];
      loop_ub = unnamed_idx_1;
      i29 = 0;
      while (i29 <= loop_ub - 1) {
        temp_min->data[0] = (1.0 - y_data[0]) * firstp;
        i29 = 1;
      }

      i29 = temp_min->size[1];
      emlrtSizeEqCheck1DFastR2012b(1, i29, &qb_emlrtECI, sp);
      i29 = temp_min->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i29, &xf_emlrtBCI, sp);
      i29 = match->size[1];
      i30 = 1 + n;
      match->data[emlrtDynamicBoundsCheckFastR2012b(i30, 1, i29, &jg_emlrtBCI,
        sp) - 1] = temp_min->data[0];
      n++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    /* 'tm_trk:98' Merit(i,:) = ((1+merit_boost)*Merit(i,:)).*match; */
    loop_ub = Merit->size[1];
    i29 = b_diff->size[0] * b_diff->size[1];
    b_diff->size[0] = 1;
    b_diff->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_diff, i29, (int32_T)sizeof
                      (real_T), &tc_emlrtRTEI);
    for (i29 = 0; i29 < loop_ub; i29++) {
      b_diff->data[b_diff->size[0] * i29] = 1.2 * Merit->data[i + Merit->size[0]
        * i29];
    }

    for (i29 = 0; i29 < 2; i29++) {
      b_Pitch[i29] = b_diff->size[i29];
    }

    for (i29 = 0; i29 < 2; i29++) {
      b_SPitch[i29] = match->size[i29];
    }

    emlrtSizeEqCheck2DFastR2012b(b_Pitch, b_SPitch, &pb_emlrtECI, sp);
    loop_ub = Merit->size[1];
    i29 = r17->size[0];
    r17->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r17, i29, (int32_T)sizeof(int32_T),
                      &tc_emlrtRTEI);
    for (i29 = 0; i29 < loop_ub; i29++) {
      r17->data[i29] = i29;
    }

    i29 = b_diff->size[0] * b_diff->size[1];
    b_diff->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)b_diff, i29, (int32_T)sizeof
                      (real_T), &tc_emlrtRTEI);
    unnamed_idx_1 = b_diff->size[0];
    loop_ub = b_diff->size[1];
    loop_ub *= unnamed_idx_1;
    for (i29 = 0; i29 < loop_ub; i29++) {
      b_diff->data[i29] *= match->data[i29];
    }

    iv68[0] = 1;
    iv68[1] = r17->size[0];
    emlrtSubAssignSizeCheckR2012b(iv68, 2, *(int32_T (*)[2])b_diff->size, 2,
      &ob_emlrtECI, sp);
    loop_ub = b_diff->size[1];
    for (i29 = 0; i29 < loop_ub; i29++) {
      Merit->data[i + Merit->size[0] * r17->data[i29]] = b_diff->data
        [b_diff->size[0] * i29];
    }

    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&c_SPitch);
  emxFree_real_T(&c_Pitch);
  emxFree_real_T(&y);
  emxFree_int32_T(&r17);
  emxFree_real_T(&match);
  emxFree_real_T(&b_diff);
  emxFree_real_T(&temp_min);
  emxFree_real_T(&temp_max);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (tm_trk.c) */
