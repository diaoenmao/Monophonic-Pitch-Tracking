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
#include "error1.h"
#include "eml_int_forloop_overflow_check.h"
#include "cmp_rate.h"
#include "crs_corr.h"
#include "fix.h"
#include "warning.h"
#include "scalexpAlloc.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo yk_emlrtRSI = { 55, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo al_emlrtRSI = { 56, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo bl_emlrtRSI = { 74, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo cl_emlrtRSI = { 78, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo dl_emlrtRSI = { 88, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo el_emlrtRSI = { 100, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo fl_emlrtRSI = { 81, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo gl_emlrtRSI = { 243, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo hl_emlrtRSI = { 269, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo il_emlrtRSI = { 13, "min",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRTEInfo pd_emlrtRTEI = { 1, 27, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo qd_emlrtRTEI = { 19, 24, "scalexpAllocNoCheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m"
};

static emlrtRTEInfo rd_emlrtRTEI = { 47, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo sd_emlrtRTEI = { 49, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo td_emlrtRTEI = { 50, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo ud_emlrtRTEI = { 87, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo vd_emlrtRTEI = { 88, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo wd_emlrtRTEI = { 98, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo rb_emlrtECI = { -1, 52, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 52, 5, "SPitch(i)-2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo sb_emlrtECI = { -1, 53, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 53, 5, "SPitch(i)+2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtRTEInfo lg_emlrtRTEI = { 63, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtDCInfo yb_emlrtDCI = { 66, 14, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 66, 14, "Data", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo tb_emlrtECI = { -1, 55, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo ub_emlrtECI = { -1, 56, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 71, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 72, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtRTEInfo mg_emlrtRTEI = { 86, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 78, 14, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo vb_emlrtECI = { -1, 78, 6, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 88, 27, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo wb_emlrtECI = { 2, 88, 21, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo xb_emlrtECI = { -1, 93, 13, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 93, 13, "freq_thresh + 1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 100, 28, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo yb_emlrtECI = { -1, 95, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 95, 10,
  "match1(j) = diff(j) < freq_thresh", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 100, 52, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 78, 25, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo ac_emlrtECI = { -1, 78, 17, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 103, 41, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo bc_emlrtECI = { -1, 100, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 100, 10,
  "(1 - (diff(k)/freq_thresh)) * match1(k)", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo cc_emlrtECI = { 2, 103, 18, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 103, 11, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo dc_emlrtECI = { -1, 103, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtDCInfo ac_emlrtDCI = { 59, 15, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtDCInfo bc_emlrtDCI = { 59, 15, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtDCInfo cc_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtDCInfo dc_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 100, 10, "match", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 92, 12, "Idx_unvoiced", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 93, 13, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 95, 22, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo di_emlrtBCI = { -1, -1, 95, 10, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 52, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 52, 5, "temp_max", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 53, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 53, 5, "temp_min", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

/* Function Definitions */
void tm_trk(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs, const
            emxArray_real_T *SPitch, const real_T pStd_data[], const int32_T
            pStd_size[1], real_T Prm_frame_length, real_T Prm_frame_space,
            real_T Prm_f0_min, real_T Prm_f0_max, real_T Prm_nccf_thresh1,
            real_T Prm_nccf_thresh2, real_T Prm_nccf_maxcands, real_T
            Prm_nccf_pwidth, real_T Prm_merit_boost, emxArray_real_T *Pitch,
            emxArray_real_T *Merit)
{
  emxArray_real_T *y;
  real_T nframesize;
  real_T nframejump;
  real_T numframes;
  int32_T i41;
  int32_T loop_ub;
  emxArray_real_T *SRange;
  real_T freq_thresh_data[1];
  emxArray_real_T *temp_max;
  emxArray_real_T *temp_min;
  int32_T i;
  emxArray_real_T *b_y;
  emxArray_int32_T *r33;
  int32_T info;
  emxArray_real_T *c_diff;
  emxArray_real_T *r34;
  boolean_T overflow;
  int32_T k;
  int32_T iv43[2];
  emxArray_real_T *match;
  int32_T iv44[2];
  real_T d0;
  real_T X;
  int32_T n;
  emxArray_real_T *b_Data;
  real_T firstp;
  int32_T i42;
  emxArray_boolean_T *Idx_unvoiced;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *b_SPitch;
  int32_T c_Pitch[2];
  int32_T iv45[1];
  int32_T c_SPitch[2];
  int32_T iv46[1];
  int32_T j;
  int8_T tmp_data[1];
  int32_T iv47[2];
  ptrdiff_t ipiv_t;
  real_T A_data[1];
  ptrdiff_t info_t;
  int32_T b_match[2];
  real_T y_data[1];
  int32_T iv48[2];
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
  emxInit_real_T2(sp, &y, 1, &pd_emlrtRTEI, true);
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
  nframesize = Prm_frame_length * Fs / 1000.0;
  b_fix(&nframesize);
  nframejump = Prm_frame_space * Fs / 1000.0;
  b_fix(&nframejump);

  /*  overlap width in sample  */
  numframes = ((real_T)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /*  The maximum number of pitch candidates */
  /* freq_thresh = pAvg;  % seems too large */
  i41 = y->size[0];
  y->size[0] = pStd_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  loop_ub = pStd_size[0];
  for (i41 = 0; i41 < loop_ub; i41++) {
    y->data[i41] = 5.0 * pStd_data[i41];
  }

  loop_ub = pStd_size[0];
  for (i41 = 0; i41 < loop_ub; i41++) {
    freq_thresh_data[i41] = 5.0 * pStd_data[i41];
  }

  emxInit_real_T(sp, &SRange, 2, &rd_emlrtRTEI, true);
  i41 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  SRange->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SRange, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  loop_ub = SPitch->size[1] << 1;
  for (i41 = 0; i41 < loop_ub; i41++) {
    SRange->data[i41] = 0.0;
  }

  emxInit_real_T(sp, &temp_max, 2, &sd_emlrtRTEI, true);

  /*  Determine the search range according spectral pitch track */
  i41 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  temp_max->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_max, i41, (int32_T)sizeof
                    (real_T), &pd_emlrtRTEI);
  loop_ub = SPitch->size[1];
  for (i41 = 0; i41 < loop_ub; i41++) {
    temp_max->data[i41] = 0.0;
  }

  emxInit_real_T(sp, &temp_min, 2, &td_emlrtRTEI, true);
  i41 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  temp_min->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_min, i41, (int32_T)sizeof
                    (real_T), &pd_emlrtRTEI);
  loop_ub = SPitch->size[1];
  for (i41 = 0; i41 < loop_ub; i41++) {
    temp_min->data[i41] = 0.0;
  }

  i = 1;
  emxInit_real_T2(sp, &b_y, 1, &pd_emlrtRTEI, true);
  while (i - 1 <= SPitch->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 1);
    i41 = b_y->size[0];
    b_y->size[0] = pStd_size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_y, i41, (int32_T)sizeof(real_T),
                      &pd_emlrtRTEI);
    loop_ub = pStd_size[0];
    for (i41 = 0; i41 < loop_ub; i41++) {
      b_y->data[i41] = 2.0 * pStd_data[i41];
    }

    i41 = b_y->size[0];
    if (1 != i41) {
      emlrtSizeEqCheck1DR2012b(1, i41, &rb_emlrtECI, sp);
    }

    i41 = b_y->size[0];
    if (!(1 <= i41)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i41, &jh_emlrtBCI, sp);
    }

    i41 = SPitch->size[1];
    if (!((i >= 1) && (i <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i41, &ei_emlrtBCI, sp);
    }

    i41 = temp_max->size[1];
    if (!((i >= 1) && (i <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i41, &fi_emlrtBCI, sp);
    }

    temp_max->data[i - 1] = SPitch->data[i - 1] - b_y->data[0];
    i41 = b_y->size[0];
    b_y->size[0] = pStd_size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_y, i41, (int32_T)sizeof(real_T),
                      &pd_emlrtRTEI);
    loop_ub = pStd_size[0];
    for (i41 = 0; i41 < loop_ub; i41++) {
      b_y->data[i41] = 2.0 * pStd_data[i41];
    }

    i41 = b_y->size[0];
    if (1 != i41) {
      emlrtSizeEqCheck1DR2012b(1, i41, &sb_emlrtECI, sp);
    }

    i41 = b_y->size[0];
    if (!(1 <= i41)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i41, &kh_emlrtBCI, sp);
    }

    i41 = SPitch->size[1];
    if (!((i >= 1) && (i <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i41, &gi_emlrtBCI, sp);
    }

    i41 = temp_min->size[1];
    if (!((i >= 1) && (i <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i41, &hi_emlrtBCI, sp);
    }

    temp_min->data[i - 1] = SPitch->data[i - 1] + b_y->data[0];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_y);
  emxInit_int32_T1(sp, &r33, 1, &pd_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 2);
  info = SPitch->size[1];
  i41 = r33->size[0];
  r33->size[0] = info;
  emxEnsureCapacity(sp, (emxArray__common *)r33, i41, (int32_T)sizeof(int32_T),
                    &pd_emlrtRTEI);
  for (i41 = 0; i41 < info; i41++) {
    r33->data[i41] = i41;
  }

  emxInit_real_T(sp, &c_diff, 2, &vd_emlrtRTEI, true);
  emxInit_real_T(sp, &r34, 2, &pd_emlrtRTEI, true);
  st.site = &yk_emlrtRSI;
  b_st.site = &ki_emlrtRSI;
  c_st.site = &li_emlrtRSI;
  d_st.site = &fl_emlrtRSI;
  e_st.site = &gl_emlrtRSI;
  i41 = c_diff->size[0] * c_diff->size[1];
  c_diff->size[0] = 1;
  c_diff->size[1] = temp_max->size[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)c_diff, i41, (int32_T)sizeof
                    (real_T), &qd_emlrtRTEI);
  info = temp_max->size[1];
  i41 = r34->size[0] * r34->size[1];
  r34->size[0] = 1;
  r34->size[1] = temp_max->size[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)r34, i41, (int32_T)sizeof(real_T),
                    &e_emlrtRTEI);
  if (dimagree(r34, temp_max)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &af_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &hl_emlrtRSI;
  overflow = ((!(1 > c_diff->size[1])) && (c_diff->size[1] > 2147483646));
  if (overflow) {
    f_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= info; k++) {
    r34->data[k] = muDoubleScalarMax(temp_max->data[k], Prm_f0_min);
  }

  iv43[0] = 1;
  iv43[1] = r33->size[0];
  emlrtSubAssignSizeCheckR2012b(iv43, 2, *(int32_T (*)[2])r34->size, 2,
    &tb_emlrtECI, sp);
  loop_ub = r34->size[1];
  for (i41 = 0; i41 < loop_ub; i41++) {
    SRange->data[SRange->size[0] * r33->data[i41]] = r34->data[r34->size[0] *
      i41];
  }

  loop_ub = SRange->size[1];
  i41 = r33->size[0];
  r33->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r33, i41, (int32_T)sizeof(int32_T),
                    &pd_emlrtRTEI);
  for (i41 = 0; i41 < loop_ub; i41++) {
    r33->data[i41] = i41;
  }

  emxInit_real_T(sp, &match, 2, &wd_emlrtRTEI, true);
  st.site = &al_emlrtRSI;
  b_st.site = &il_emlrtRSI;
  c_st.site = &li_emlrtRSI;
  d_st.site = &fl_emlrtRSI;
  e_st.site = &gl_emlrtRSI;
  i41 = match->size[0] * match->size[1];
  match->size[0] = 1;
  match->size[1] = temp_min->size[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)match, i41, (int32_T)sizeof
                    (real_T), &qd_emlrtRTEI);
  info = temp_min->size[1];
  i41 = r34->size[0] * r34->size[1];
  r34->size[0] = 1;
  r34->size[1] = temp_min->size[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)r34, i41, (int32_T)sizeof(real_T),
                    &e_emlrtRTEI);
  if (dimagree(r34, temp_min)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &af_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &hl_emlrtRSI;
  overflow = ((!(1 > match->size[1])) && (match->size[1] > 2147483646));
  if (overflow) {
    f_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= info; k++) {
    r34->data[k] = muDoubleScalarMin(temp_min->data[k], Prm_f0_max);
  }

  iv44[0] = 1;
  iv44[1] = r33->size[0];
  emlrtSubAssignSizeCheckR2012b(iv44, 2, *(int32_T (*)[2])r34->size, 2,
    &ub_emlrtECI, sp);
  loop_ub = r34->size[1];
  for (i41 = 0; i41 < loop_ub; i41++) {
    SRange->data[1 + SRange->size[0] * r33->data[i41]] = r34->data[r34->size[0] *
      i41];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  i41 = Pitch->size[0] * Pitch->size[1];
  if (!(Prm_nccf_maxcands >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Prm_nccf_maxcands, &bc_emlrtDCI, sp);
  }

  d0 = Prm_nccf_maxcands;
  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &ac_emlrtDCI, sp);
  }

  Pitch->size[0] = (int32_T)d0;
  if (!(numframes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &dc_emlrtDCI, sp);
  }

  d0 = numframes;
  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &cc_emlrtDCI, sp);
  }

  Pitch->size[1] = (int32_T)d0;
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  if (!(Prm_nccf_maxcands >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Prm_nccf_maxcands, &bc_emlrtDCI, sp);
  }

  d0 = Prm_nccf_maxcands;
  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &ac_emlrtDCI, sp);
  }

  if (!(numframes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &dc_emlrtDCI, sp);
  }

  X = numframes;
  if (X != (int32_T)muDoubleScalarFloor(X)) {
    emlrtIntegerCheckR2012b(X, &cc_emlrtDCI, sp);
  }

  loop_ub = (int32_T)d0 * (int32_T)X;
  for (i41 = 0; i41 < loop_ub; i41++) {
    Pitch->data[i41] = 0.0;
  }

  i41 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = (int32_T)Prm_nccf_maxcands;
  Merit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i41, (int32_T)sizeof(real_T),
                    &pd_emlrtRTEI);
  loop_ub = (int32_T)Prm_nccf_maxcands * (int32_T)numframes;
  for (i41 = 0; i41 < loop_ub; i41++) {
    Merit->data[i41] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &lg_emlrtRTEI, sp);
  n = 0;
  emxInit_real_T2(sp, &b_Data, 1, &pd_emlrtRTEI, true);
  while (n <= (int32_T)numframes - 1) {
    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 3);
    firstp = 1.0 + ((1.0 + (real_T)n) - 1.0) * nframejump;
    d0 = (firstp + nframesize) - 1.0;
    if (firstp > d0) {
      i41 = 0;
      info = 0;
    } else {
      if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
        emlrtIntegerCheckR2012b(firstp, &yb_emlrtDCI, sp);
      }

      i41 = Data->size[1];
      i42 = (int32_T)firstp;
      if (!((i42 >= 1) && (i42 <= i41))) {
        emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &lh_emlrtBCI, sp);
      }

      i41 = i42 - 1;
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &yb_emlrtDCI, sp);
      }

      i42 = Data->size[1];
      info = (int32_T)d0;
      if (!((info >= 1) && (info <= i42))) {
        emlrtDynamicBoundsCheckR2012b(info, 1, i42, &lh_emlrtBCI, sp);
      }
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    i42 = SRange->size[1];
    loop_ub = n + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i42))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i42, &mh_emlrtBCI, sp);
    }

    d0 = Fs / SRange->data[1 + SRange->size[0] * n];
    b_fix(&d0);
    i42 = SRange->size[1];
    loop_ub = n + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i42))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i42, &nh_emlrtBCI, sp);
    }

    X = Fs / SRange->data[SRange->size[0] * n];
    b_fix(&X);

    /*  Compute correaltion */
    i42 = b_Data->size[0];
    b_Data->size[0] = info - i41;
    emxEnsureCapacity(sp, (emxArray__common *)b_Data, i42, (int32_T)sizeof
                      (real_T), &pd_emlrtRTEI);
    loop_ub = info - i41;
    for (i42 = 0; i42 < loop_ub; i42++) {
      b_Data->data[i42] = Data->data[i41 + i42];
    }

    st.site = &bl_emlrtRSI;
    crs_corr(&st, b_Data, d0 - 3.0, X + 3.0, temp_max);

    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    st.site = &cl_emlrtRSI;
    cmp_rate(&st, temp_max, Fs, Prm_nccf_maxcands, d0 - 3.0, X + 3.0,
             Prm_nccf_thresh1, Prm_nccf_thresh2, Prm_nccf_pwidth, r34, temp_min);
    loop_ub = Pitch->size[0];
    i41 = r33->size[0];
    r33->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r33, i41, (int32_T)sizeof(int32_T),
                      &pd_emlrtRTEI);
    for (i41 = 0; i41 < loop_ub; i41++) {
      r33->data[i41] = i41;
    }

    i41 = Pitch->size[1];
    i42 = n + 1;
    if (!((i42 >= 1) && (i42 <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &oh_emlrtBCI, sp);
    }

    iv45[0] = r33->size[0];
    emlrtSubAssignSizeCheckR2012b(iv45, 1, *(int32_T (*)[2])r34->size, 2,
      &vb_emlrtECI, sp);
    info = r33->size[0];
    for (i41 = 0; i41 < info; i41++) {
      Pitch->data[r33->data[i41] + Pitch->size[0] * n] = r34->data[i41];
    }

    loop_ub = Merit->size[0];
    i41 = r33->size[0];
    r33->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r33, i41, (int32_T)sizeof(int32_T),
                      &pd_emlrtRTEI);
    for (i41 = 0; i41 < loop_ub; i41++) {
      r33->data[i41] = i41;
    }

    i41 = Merit->size[1];
    i42 = n + 1;
    if (!((i42 >= 1) && (i42 <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &uh_emlrtBCI, sp);
    }

    iv46[0] = r33->size[0];
    emlrtSubAssignSizeCheckR2012b(iv46, 1, *(int32_T (*)[2])temp_min->size, 2,
      &ac_emlrtECI, sp);
    info = r33->size[0];
    for (i41 = 0; i41 < info; i41++) {
      Merit->data[r33->data[i41] + Merit->size[0] * n] = temp_min->data[i41];
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
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, Prm_nccf_maxcands, mxDOUBLE_CLASS,
    (int32_T)Prm_nccf_maxcands, &mg_emlrtRTEI, sp);
  i = 0;
  emxInit_boolean_T(sp, &Idx_unvoiced, 2, &ud_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Pitch, 2, &pd_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SPitch, 2, &pd_emlrtRTEI, true);
  while (i <= (int32_T)Prm_nccf_maxcands - 1) {
    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 4);
    i41 = Idx_unvoiced->size[0] * Idx_unvoiced->size[1];
    Idx_unvoiced->size[0] = 1;
    Idx_unvoiced->size[1] = SPitch->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)Idx_unvoiced, i41, (int32_T)sizeof
                      (boolean_T), &pd_emlrtRTEI);
    loop_ub = SPitch->size[0] * SPitch->size[1];
    for (i41 = 0; i41 < loop_ub; i41++) {
      Idx_unvoiced->data[i41] = (SPitch->data[i41] == 0.0);
    }

    i41 = Pitch->size[0];
    i42 = i + 1;
    if (!((i42 >= 1) && (i42 <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &ph_emlrtBCI, sp);
    }

    loop_ub = Pitch->size[1];
    i41 = b_Pitch->size[0] * b_Pitch->size[1];
    b_Pitch->size[0] = 1;
    b_Pitch->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i41, (int32_T)sizeof
                      (real_T), &pd_emlrtRTEI);
    for (i41 = 0; i41 < loop_ub; i41++) {
      b_Pitch->data[b_Pitch->size[0] * i41] = Pitch->data[i + Pitch->size[0] *
        i41];
    }

    for (i41 = 0; i41 < 2; i41++) {
      c_Pitch[i41] = b_Pitch->size[i41];
    }

    loop_ub = SPitch->size[1];
    i41 = b_SPitch->size[0] * b_SPitch->size[1];
    b_SPitch->size[0] = 1;
    b_SPitch->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i41, (int32_T)sizeof
                      (real_T), &pd_emlrtRTEI);
    for (i41 = 0; i41 < loop_ub; i41++) {
      b_SPitch->data[b_SPitch->size[0] * i41] = SPitch->data[SPitch->size[0] *
        i41];
    }

    for (i41 = 0; i41 < 2; i41++) {
      c_SPitch[i41] = b_SPitch->size[i41];
    }

    if ((c_Pitch[0] != c_SPitch[0]) || (c_Pitch[1] != c_SPitch[1])) {
      emlrtSizeEqCheckNDR2012b(&c_Pitch[0], &c_SPitch[0], &wb_emlrtECI, sp);
    }

    st.site = &dl_emlrtRSI;
    loop_ub = Pitch->size[1];
    i41 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)temp_max, i41, (int32_T)sizeof
                      (real_T), &pd_emlrtRTEI);
    for (i41 = 0; i41 < loop_ub; i41++) {
      temp_max->data[temp_max->size[0] * i41] = Pitch->data[i + Pitch->size[0] *
        i41] - SPitch->data[SPitch->size[0] * i41];
    }

    b_st.site = &mg_emlrtRSI;
    i41 = c_diff->size[0] * c_diff->size[1];
    c_diff->size[0] = 1;
    c_diff->size[1] = temp_max->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)c_diff, i41, (int32_T)sizeof
                      (real_T), &pd_emlrtRTEI);
    c_st.site = &ng_emlrtRSI;
    overflow = ((!(1 > temp_max->size[1])) && (temp_max->size[1] > 2147483646));
    if (overflow) {
      d_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k + 1 <= temp_max->size[1]; k++) {
      c_diff->data[k] = muDoubleScalarAbs(temp_max->data[k]);
    }

    /*      diff(Idx_unvoiced) = freq_thresh + 1; */
    i41 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = c_diff->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)temp_max, i41, (int32_T)sizeof
                      (real_T), &pd_emlrtRTEI);
    loop_ub = c_diff->size[1];
    for (i41 = 0; i41 < loop_ub; i41++) {
      temp_max->data[i41] = 0.0;
    }

    i41 = c_diff->size[1];
    j = 1;
    while (j - 1 <= i41 - 1) {
      covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 3, 1);
      i42 = Idx_unvoiced->size[1];
      if (!((j >= 1) && (j <= i42))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i42, &ai_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 16U, 0U, 0, Idx_unvoiced->data[j -
                     1])) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 5);
        i42 = y->size[0];
        if (1 != i42) {
          emlrtSizeEqCheck1DR2012b(1, i42, &xb_emlrtECI, sp);
        }

        i42 = y->size[0];
        if (!(1 <= i42)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i42, &qh_emlrtBCI, sp);
        }

        i42 = c_diff->size[1];
        if (!((j >= 1) && (j <= i42))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i42, &bi_emlrtBCI, sp);
        }

        c_diff->data[j - 1] = y->data[0] + 1.0;
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 6);
      i42 = c_diff->size[1];
      if (!((j >= 1) && (j <= i42))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i42, &ci_emlrtBCI, sp);
      }

      X = c_diff->data[j - 1];
      info = y->size[0];
      loop_ub = y->size[0];
      for (i42 = 0; i42 < loop_ub; i42++) {
        tmp_data[i42] = (int8_T)(X < y->data[i42]);
      }

      if (1 != info) {
        emlrtSizeEqCheck1DR2012b(1, info, &yb_emlrtECI, sp);
      }

      if (!(1 <= info)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, info, &sh_emlrtBCI, sp);
      }

      i42 = temp_max->size[1];
      if (!((j >= 1) && (j <= i42))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i42, &di_emlrtBCI, sp);
      }

      temp_max->data[j - 1] = tmp_data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 7);

    /*      match1 =  (diff < freq_thresh); */
    i41 = match->size[0] * match->size[1];
    match->size[0] = 1;
    match->size[1] = c_diff->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)match, i41, (int32_T)sizeof(real_T),
                      &pd_emlrtRTEI);
    loop_ub = c_diff->size[1];
    for (i41 = 0; i41 < loop_ub; i41++) {
      match->data[i41] = 0.0;
    }

    k = 0;
    while (k <= c_diff->size[1] - 1) {
      covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 4, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 8);
      st.site = &el_emlrtRSI;
      i41 = c_diff->size[1];
      i42 = k + 1;
      if (!((i42 >= 1) && (i42 <= i41))) {
        emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &rh_emlrtBCI, &st);
      }

      if (y->size[0] == 0) {
        info = 0;
      } else {
        b_st.site = &vl_emlrtRSI;
        c_st.site = &fc_emlrtRSI;
        d_st.site = &hc_emlrtRSI;
        e_st.site = &lc_emlrtRSI;
        loop_ub = pStd_size[0];
        for (i41 = 0; i41 < loop_ub; i41++) {
          A_data[i41] = freq_thresh_data[i41];
        }

        info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)1, (ptrdiff_t)1, &A_data[0],
          (ptrdiff_t)1, &ipiv_t);
        info = (int32_T)info_t;
        f_st.site = &mc_emlrtRSI;
        if (info < 0) {
          if (info == -1010) {
            g_st.site = &pc_emlrtRSI;
            d_error(&g_st);
          } else {
            g_st.site = &qc_emlrtRSI;
            e_error(&g_st, info);
          }
        }

        if (info > 0) {
          d_st.site = &gc_emlrtRSI;
          if (!emlrtSetWarningFlag(&d_st)) {
            e_st.site = &xc_emlrtRSI;
            warning(&e_st);
          }
        }

        X = 1.0 / A_data[0] * c_diff->data[k];
        info = 1;
        y_data[0] = X;
      }

      i41 = temp_max->size[1];
      i42 = k + 1;
      if (!((i42 >= 1) && (i42 <= i41))) {
        emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &th_emlrtBCI, sp);
      }

      i41 = temp_min->size[0] * temp_min->size[1];
      temp_min->size[0] = 1;
      temp_min->size[1] = info;
      emxEnsureCapacity(sp, (emxArray__common *)temp_min, i41, (int32_T)sizeof
                        (real_T), &pd_emlrtRTEI);
      X = temp_max->data[k];
      for (i41 = 0; i41 < info; i41++) {
        temp_min->data[i41] = (1.0 - y_data[i41]) * X;
      }

      i41 = temp_min->size[1];
      if (1 != i41) {
        emlrtSizeEqCheck1DR2012b(1, i41, &bc_emlrtECI, sp);
      }

      i41 = temp_min->size[1];
      if (!(1 <= i41)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i41, &wh_emlrtBCI, sp);
      }

      i41 = match->size[1];
      i42 = 1 + k;
      if (!((i42 >= 1) && (i42 <= i41))) {
        emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &yh_emlrtBCI, sp);
      }

      match->data[i42 - 1] = temp_min->data[0];
      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 9);

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    i41 = Merit->size[0];
    i42 = i + 1;
    if (!((i42 >= 1) && (i42 <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &vh_emlrtBCI, sp);
    }

    loop_ub = Merit->size[1];
    i41 = r34->size[0] * r34->size[1];
    r34->size[0] = 1;
    r34->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r34, i41, (int32_T)sizeof(real_T),
                      &pd_emlrtRTEI);
    for (i41 = 0; i41 < loop_ub; i41++) {
      r34->data[r34->size[0] * i41] = (1.0 + Prm_merit_boost) * Merit->data[i +
        Merit->size[0] * i41];
    }

    for (i41 = 0; i41 < 2; i41++) {
      iv47[i41] = r34->size[i41];
    }

    for (i41 = 0; i41 < 2; i41++) {
      b_match[i41] = match->size[i41];
    }

    if ((iv47[0] != b_match[0]) || (iv47[1] != b_match[1])) {
      emlrtSizeEqCheckNDR2012b(&iv47[0], &b_match[0], &cc_emlrtECI, sp);
    }

    i41 = Merit->size[0];
    i42 = i + 1;
    if (!((i42 >= 1) && (i42 <= i41))) {
      emlrtDynamicBoundsCheckR2012b(i42, 1, i41, &xh_emlrtBCI, sp);
    }

    loop_ub = Merit->size[1];
    i41 = r33->size[0];
    r33->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r33, i41, (int32_T)sizeof(int32_T),
                      &pd_emlrtRTEI);
    for (i41 = 0; i41 < loop_ub; i41++) {
      r33->data[i41] = i41;
    }

    i41 = r34->size[0] * r34->size[1];
    r34->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r34, i41, (int32_T)sizeof(real_T),
                      &pd_emlrtRTEI);
    i41 = r34->size[0];
    i42 = r34->size[1];
    loop_ub = i41 * i42;
    for (i41 = 0; i41 < loop_ub; i41++) {
      r34->data[i41] *= match->data[i41];
    }

    iv48[0] = 1;
    iv48[1] = r33->size[0];
    emlrtSubAssignSizeCheckR2012b(iv48, 2, *(int32_T (*)[2])r34->size, 2,
      &dc_emlrtECI, sp);
    loop_ub = r34->size[1];
    for (i41 = 0; i41 < loop_ub; i41++) {
      Merit->data[i + Merit->size[0] * r33->data[i41]] = r34->data[r34->size[0] *
        i41];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_SPitch);
  emxFree_real_T(&b_Pitch);
  emxFree_real_T(&y);
  emxFree_real_T(&r34);
  emxFree_int32_T(&r33);
  emxFree_real_T(&match);
  emxFree_real_T(&c_diff);
  emxFree_boolean_T(&Idx_unvoiced);
  emxFree_real_T(&temp_min);
  emxFree_real_T(&temp_max);
  covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 2, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (tm_trk.c) */
