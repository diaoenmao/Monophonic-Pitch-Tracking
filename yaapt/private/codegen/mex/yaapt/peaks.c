/*
 * peaks.c
 *
 * Code generation for function 'peaks'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "peaks.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "mean.h"
#include "tm_trk.h"
#include "fix.h"
#include "mod.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ti_emlrtRSI = { 75, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo ui_emlrtRSI = { 81, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo vi_emlrtRSI = { 99, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo wi_emlrtRSI = { 113, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo xi_emlrtRSI = { 122, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo f_emlrtMCI = { 60, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo g_emlrtMCI = { 64, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRTEInfo uc_emlrtRTEI = { 1, 26, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtDCInfo pb_emlrtDCI = { 163, 25, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo qb_emlrtDCI = { 163, 25, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 160, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo rb_emlrtDCI = { 160, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 160, 38, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 159, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo sb_emlrtDCI = { 159, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 159, 39, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 151, 31, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 145, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 139, 27, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 133, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo tb_emlrtDCI = { 128, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ub_emlrtDCI = { 127, 10, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo gf_emlrtBCI = { 1, 100, 106, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo vb_emlrtDCI = { 115, 27, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo wb_emlrtDCI = { 115, 27, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 99, 21, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo xb_emlrtDCI = { 99, 21, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtRTEInfo eg_emlrtRTEI = { 98, 1, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtDCInfo yb_emlrtDCI = { 84, 25, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ac_emlrtDCI = { 84, 25, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 81, 17, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo bc_emlrtDCI = { 81, 17, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 75, 16, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo cc_emlrtDCI = { 75, 16, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo dc_emlrtDCI = { 136, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ec_emlrtDCI = { 136, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo fc_emlrtDCI = { 137, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo gc_emlrtDCI = { 137, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo hc_emlrtDCI = { 157, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ic_emlrtDCI = { 157, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo jc_emlrtDCI = { 158, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo kc_emlrtDCI = { 158, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo kf_emlrtBCI = { 1, 100, 123, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 139, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo lc_emlrtDCI = { 139, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 141, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo mc_emlrtDCI = { 148, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo nc_emlrtDCI = { 148, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo oc_emlrtDCI = { 149, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo pc_emlrtDCI = { 149, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 151, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo qc_emlrtDCI = { 151, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 152, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtRSInfo lo_emlrtRSI = { 64, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo mo_emlrtRSI = { 60, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [36]);
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [37]);
static void disp(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                 emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [36])
{
  const mxArray *y;
  static const int32_T iv60[2] = { 1, 36 };

  const mxArray *m12;
  y = NULL;
  m12 = emlrtCreateCharArray(2, iv60);
  emlrtInitCharArrayR2013a(sp, 36, m12, &u[0]);
  emlrtAssign(&y, m12);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [37])
{
  const mxArray *y;
  static const int32_T iv61[2] = { 1, 37 };

  const mxArray *m13;
  y = NULL;
  m13 = emlrtCreateCharArray(2, iv61);
  emlrtInitCharArrayR2013a(sp, 37, m13, &u[0]);
  emlrtAssign(&y, m13);
  return y;
}

static void disp(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                 emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "disp", true, location);
}

/*
 * function[Pitch, Merit] = peaks(Data, delta, maxpeaks, Prm)
 */
void peaks(const emlrtStack *sp, emxArray_real_T *Data, real_T delta, real_T
           maxpeaks, real_T Prm_f0_min, real_T Prm_f0_max, real_T Prm_shc_pwidth,
           real_T Prm_shc_thresh1, real_T Prm_shc_thresh2, real_T Prm_f0_double,
           real_T Prm_f0_half, real_T Prm_merit_extra, emxArray_real_T *Pitch,
           emxArray_real_T *Merit)
{
  real_T width;
  real_T center;
  real_T min_lag;
  real_T max_lag;
  static const char_T cv8[36] = { 'm', 'i', 'n', '_', 'l', 'a', 'g', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 'l', 'o', 'w', ' ', 'a', 'n', 'd', ' ', 'a',
    'd', 'j', 'u', 's', 't', 'e', 'd', ' ', '(', '%', 'd', ')' };

  static const char_T cv9[37] = { 'm', 'a', 'x', '_', 'l', 'a', 'g', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 'h', 'i', 'g', 'h', ' ', 'a', 'n', 'd', ' ',
    'a', 'd', 'j', 'u', 's', 't', 'e', 'd', ' ', '(', '%', 'd', ')' };

  real_T b_Pitch[100];
  real_T b_Merit[100];
  int32_T i29;
  int32_T n;
  int32_T i30;
  boolean_T b15;
  int32_T ixstart;
  int32_T b_n;
  real_T mtmp;
  boolean_T b16;
  int32_T ix;
  boolean_T exitg2;
  boolean_T b_ixstart;
  emxArray_real_T *b_Data;
  emxArray_real_T *c_Data;
  real_T avg_data;
  real_T numpeaks;
  real_T c_n;
  int32_T i31;
  int32_T itmp;
  boolean_T b17;
  boolean_T exitg1;
  boolean_T c_ixstart;
  int32_T iidx[100];
  real_T c_Pitch[100];
  emxArray_real_T *r29;
  emxArray_real_T *r30;
  emxArray_real_T *d_Pitch;
  emxArray_real_T *c_Merit;
  emxArray_real_T *r31;
  emxArray_real_T *r32;
  emxArray_int32_T *r33;
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

  /* PEAKS  find peaks in SHC  */
  /*  */
  /*    [Pitch,Merit] = peaks(Data, delta, maxpeaks, Prm) */
  /*    computes peaks in a frequency domain function */
  /*    associated with the peaks found in each frame based on the */
  /*    correlation sequence. */
  /*  */
  /* INPUTS: */
  /*    Data:  The input signal(either autocorrelated/normalized cross correlated). */
  /*    delta: The resolution of spectrum */
  /*    maxpeaks: The max number of peaks picked  */
  /*    Prm:   Parameters */
  /*  */
  /* OUTPUTS:  */
  /*    Pitch:  The Pitch/Pitch values for the peaks found for each frame. */
  /*    Merit:  The Merit values of the peaks found in each frame. */
  /*   Creation date:   March 1, 2006 */
  /*   Revision dates:  March 11, 2006,  Jun 26, 2006, July 27, 2007 */
  /*   Programmer: S.A.Zahorian, Princy  Dikshit, Hongbing Hu */
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
  /*  Threshold for max avaliable peak */
  /* 'peaks:37' PEAK_THRESH1 = Prm.shc_thresh1; */
  /*  Threshold for available peaks */
  /* 'peaks:40' PEAK_THRESH2 = Prm.shc_thresh2; */
  /* -- COMPUTED VARIABLES -------------------------------------------------------- */
  /* 'peaks:43' epsilon = .00000000000001; */
  /*  Length in Hz of range(must be largest to be a peak) */
  /* 'peaks:46' width   = fix(Prm.shc_pwidth/delta); */
  width = Prm_shc_pwidth / delta;
  b_fix(&width);

  /*  Window width in sample */
  /* 'peaks:47' if (mod(width,2)==0) */
  if (b_mod(width, 2.0) == 0.0) {
    /* 'peaks:48' width = width + 1; */
    width++;
  }

  /*  The center of the window is defined as the peak location. */
  /* 'peaks:51' center = ceil(width/2); */
  center = muDoubleScalarCeil(width / 2.0);

  /*  Lowest frequency at which F0 is allowed */
  /* 'peaks:54' min_lag  = fix(Prm.f0_min/delta - width/4); */
  min_lag = Prm_f0_min / delta - width / 4.0;
  b_fix(&min_lag);

  /*  Highest frequency at which F0 is allowed */
  /* 'peaks:56' max_lag  = fix(Prm.f0_max/delta + width/4); */
  max_lag = Prm_f0_max / delta + width / 4.0;
  b_fix(&max_lag);

  /* 'peaks:58' if (min_lag < 1) */
  if (min_lag < 1.0) {
    /* 'peaks:59' min_lag = 1; */
    min_lag = 1.0;

    /* 'peaks:60' disp('min_lag is too low and adjusted (%d)', min_lag); */
    st.site = &mo_emlrtRSI;
    disp(&st, b_emlrt_marshallOut(&st, cv8), emlrt_marshallOut(1.0), &f_emlrtMCI);
  }

  /* 'peaks:62' if max_lag > (length(Data) - width) */
  if (max_lag > (real_T)Data->size[1] - width) {
    /* 'peaks:63' max_lag = length(Data) - width; */
    max_lag = (real_T)Data->size[1] - width;

    /* 'peaks:64' disp('max_lag is too high and adjusted (%d)', max_lag); */
    st.site = &lo_emlrtRSI;
    disp(&st, c_emlrt_marshallOut(&st, cv9), emlrt_marshallOut(max_lag),
         &g_emlrtMCI);
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'peaks:69' max_allow_lags = 100; */
  /* 'peaks:70' Pitch     = zeros(1, max_allow_lags); */
  /*  Peak(Pitch) candidates */
  /* 'peaks:71' Merit     = zeros(1, max_allow_lags); */
  for (i29 = 0; i29 < 100; i29++) {
    b_Pitch[i29] = 0.0;
    b_Merit[i29] = 0.0;
  }

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  /* 'peaks:75' max_data = max(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i29 = 0;
    n = 0;
  } else {
    i29 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &cc_emlrtDCI, sp);
    }

    i30 = (int32_T)min_lag;
    if (!((i30 >= 1) && (i30 <= i29))) {
      emlrtDynamicBoundsCheckR2012b(i30, 1, i29, &jf_emlrtBCI, sp);
    }

    i29 = i30 - 1;
    i30 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &cc_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i30))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i30, &jf_emlrtBCI, sp);
    }
  }

  st.site = &ti_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  if ((n - i29 == 1) || (n - i29 != 1)) {
    b15 = true;
  } else {
    b15 = false;
  }

  if (b15) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (n - i29 > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &xf_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &hb_emlrtRSI;
  ixstart = 1;
  b_n = n - i29;
  mtmp = Data->data[i29];
  if (n - i29 > 1) {
    if (muDoubleScalarIsNaN(mtmp)) {
      e_st.site = &ib_emlrtRSI;
      if (2 > n - i29) {
        b16 = false;
      } else {
        b16 = (n - i29 > 2147483646);
      }

      if (b16) {
        f_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= b_n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(Data->data[(i29 + ix) - 1])) {
          mtmp = Data->data[(i29 + ix) - 1];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < n - i29) {
      e_st.site = &jb_emlrtRSI;
      if (ixstart + 1 > n - i29) {
        b_ixstart = false;
      } else {
        b_ixstart = (n - i29 > 2147483646);
      }

      if (b_ixstart) {
        f_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      for (ix = ixstart - 1; ix + 2 <= b_n; ix++) {
        if (Data->data[(i29 + ix) + 1] > mtmp) {
          mtmp = Data->data[(i29 + ix) + 1];
        }
      }
    }
  }

  /* 'peaks:76' if (max_data > epsilon) */
  if (mtmp > 1.0E-14) {
    emxInit_real_T(sp, &b_Data, 2, &uc_emlrtRTEI, true);

    /* 'peaks:77' Data = Data/max_data; */
    i29 = b_Data->size[0] * b_Data->size[1];
    b_Data->size[0] = 1;
    b_Data->size[1] = Data->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_Data, i29, (int32_T)sizeof
                      (real_T), &uc_emlrtRTEI);
    n = Data->size[0] * Data->size[1];
    for (i29 = 0; i29 < n; i29++) {
      b_Data->data[i29] = Data->data[i29];
    }

    c_rdivide(sp, b_Data, mtmp, Data);
    emxFree_real_T(&b_Data);
  }

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  /* 'peaks:81' avg_data = mean(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i29 = 0;
    n = 0;
  } else {
    i29 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &bc_emlrtDCI, sp);
    }

    i30 = (int32_T)min_lag;
    if (!((i30 >= 1) && (i30 <= i29))) {
      emlrtDynamicBoundsCheckR2012b(i30, 1, i29, &if_emlrtBCI, sp);
    }

    i29 = i30 - 1;
    i30 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &bc_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i30))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i30, &if_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &c_Data, 2, &uc_emlrtRTEI, true);
  i30 = c_Data->size[0] * c_Data->size[1];
  c_Data->size[0] = 1;
  c_Data->size[1] = n - i29;
  emxEnsureCapacity(sp, (emxArray__common *)c_Data, i30, (int32_T)sizeof(real_T),
                    &uc_emlrtRTEI);
  n -= i29;
  for (i30 = 0; i30 < n; i30++) {
    c_Data->data[c_Data->size[0] * i30] = Data->data[i29 + i30];
  }

  st.site = &ui_emlrtRSI;
  avg_data = mean(&st, c_Data);

  /* 'peaks:82' if (avg_data > 1/PEAK_THRESH1) */
  emxFree_real_T(&c_Data);
  if (avg_data > 1.0 / Prm_shc_thresh1) {
    /*     numpeaks = 0; */
    /* 'peaks:84' Pitch    = zeros(1, maxpeaks); */
    i29 = Pitch->size[0] * Pitch->size[1];
    Pitch->size[0] = 1;
    if (!(maxpeaks > 0.0)) {
      emlrtNonNegativeCheckR2012b(maxpeaks, &ac_emlrtDCI, sp);
    }

    mtmp = maxpeaks;
    if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
      emlrtIntegerCheckR2012b(mtmp, &yb_emlrtDCI, sp);
    }

    Pitch->size[1] = (int32_T)mtmp;
    emxEnsureCapacity(sp, (emxArray__common *)Pitch, i29, (int32_T)sizeof(real_T),
                      &uc_emlrtRTEI);
    if (!(maxpeaks > 0.0)) {
      emlrtNonNegativeCheckR2012b(maxpeaks, &ac_emlrtDCI, sp);
    }

    if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
      emlrtIntegerCheckR2012b(mtmp, &yb_emlrtDCI, sp);
    }

    n = (int32_T)mtmp;
    for (i29 = 0; i29 < n; i29++) {
      Pitch->data[i29] = 0.0;
    }

    /* 'peaks:85' Merit    = ones (1, maxpeaks); */
    i29 = Merit->size[0] * Merit->size[1];
    Merit->size[0] = 1;
    Merit->size[1] = (int32_T)maxpeaks;
    emxEnsureCapacity(sp, (emxArray__common *)Merit, i29, (int32_T)sizeof(real_T),
                      &uc_emlrtRTEI);
    n = (int32_T)maxpeaks;
    for (i29 = 0; i29 < n; i29++) {
      Merit->data[i29] = 1.0;
    }

    /*  force an early end for unoviced frame  */
  } else {
    /*  Step 1 */
    /*  Find all peaks for search range */
    /*  a "peak" must be the higher than a specfied number of */
    /*  points on either side of point.  Peaks are further "cleaned" */
    /*  up, to retain only best peaks i.e. peaks which do not meet certain */
    /*  criteria are eliminated. */
    /* 'peaks:97' numpeaks = 0; */
    numpeaks = 0.0;

    /* 'peaks:98' for n = min_lag:max_lag */
    i29 = (int32_T)(max_lag + (1.0 - min_lag));
    emlrtForLoopVectorCheckR2012b(min_lag, 1.0, max_lag, mxDOUBLE_CLASS, i29,
      &eg_emlrtRTEI, sp);
    b_n = 0;
    while (b_n <= i29 - 1) {
      c_n = min_lag + (real_T)b_n;

      /* 'peaks:99' [y, lag]  = max(Data(n:(n+width-1))); */
      mtmp = (c_n + width) - 1.0;
      if (c_n > mtmp) {
        i30 = 0;
        i31 = 0;
      } else {
        i30 = Data->size[1];
        if (c_n != (int32_T)muDoubleScalarFloor(c_n)) {
          emlrtIntegerCheckR2012b(c_n, &xb_emlrtDCI, sp);
        }

        n = (int32_T)c_n;
        if (!((n >= 1) && (n <= i30))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, i30, &hf_emlrtBCI, sp);
        }

        i30 = n - 1;
        n = Data->size[1];
        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &xb_emlrtDCI, sp);
        }

        i31 = (int32_T)mtmp;
        if (!((i31 >= 1) && (i31 <= n))) {
          emlrtDynamicBoundsCheckR2012b(i31, 1, n, &hf_emlrtBCI, sp);
        }
      }

      st.site = &vi_emlrtRSI;
      b_st.site = &yi_emlrtRSI;
      c_st.site = &aj_emlrtRSI;
      if ((i31 - i30 == 1) || (i31 - i30 != 1)) {
        b15 = true;
      } else {
        b15 = false;
      }

      if (b15) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (i31 - i30 > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &xf_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &hb_emlrtRSI;
      ixstart = 2;
      n = i31 - i30;
      mtmp = Data->data[i30];
      itmp = 1;
      if (i31 - i30 > 1) {
        if (muDoubleScalarIsNaN(mtmp)) {
          e_st.site = &ib_emlrtRSI;
          if (2 > i31 - i30) {
            b17 = false;
          } else {
            b17 = (i31 - i30 > 2147483646);
          }

          if (b17) {
            f_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&f_st, true);
          }

          ix = 2;
          exitg1 = false;
          while ((!exitg1) && (ix <= n)) {
            ixstart = ix + 1;
            if (!muDoubleScalarIsNaN(Data->data[(i30 + ix) - 1])) {
              mtmp = Data->data[(i30 + ix) - 1];
              itmp = ix;
              exitg1 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart - 1 < i31 - i30) {
          e_st.site = &jb_emlrtRSI;
          if (ixstart > i31 - i30) {
            c_ixstart = false;
          } else {
            c_ixstart = (i31 - i30 > 2147483646);
          }

          if (c_ixstart) {
            f_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&f_st, true);
          }

          while (ixstart <= n) {
            if (Data->data[(i30 + ixstart) - 1] > mtmp) {
              mtmp = Data->data[(i30 + ixstart) - 1];
              itmp = ixstart;
            }

            ixstart++;
          }
        }
      }

      /*  find peaks which are larger than threshold    */
      /* 'peaks:101' if (lag == center) && y>(PEAK_THRESH2*avg_data) */
      if ((itmp == center) && (mtmp > Prm_shc_thresh2 * avg_data)) {
        /*  Note Pitch(1) = delta, Pitch(2) = 2*delta */
        /*  Convert FFT indices to Pitch in Hz */
        /* 'peaks:105' numpeaks = numpeaks + 1; */
        numpeaks++;

        /* 'peaks:106' Pitch(numpeaks)  = (n+center-1)*delta; */
        i30 = (int32_T)numpeaks;
        if (!((i30 >= 1) && (i30 <= 100))) {
          emlrtDynamicBoundsCheckR2012b(i30, 1, 100, &gf_emlrtBCI, sp);
        }

        b_Pitch[i30 - 1] = ((c_n + center) - 1.0) * delta;

        /* 'peaks:107' Merit(numpeaks)  = y; */
        b_Merit[(int32_T)numpeaks - 1] = mtmp;
      }

      b_n++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  Step 2 */
    /*  Be sure there is large peak */
    /* 'peaks:113' if (max(Merit)/avg_data < PEAK_THRESH1) */
    st.site = &wi_emlrtRSI;
    b_st.site = &fb_emlrtRSI;
    c_st.site = &gb_emlrtRSI;
    d_st.site = &hb_emlrtRSI;
    mtmp = b_Merit[0];
    e_st.site = &jb_emlrtRSI;
    for (ix = 1; ix + 1 < 101; ix++) {
      if (b_Merit[ix] > mtmp) {
        mtmp = b_Merit[ix];
      }
    }

    if (mtmp / avg_data < Prm_shc_thresh1) {
      /*    numpeaks = 0; */
      /* 'peaks:115' Pitch      = zeros(1, maxpeaks); */
      i29 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      if (!(maxpeaks > 0.0)) {
        emlrtNonNegativeCheckR2012b(maxpeaks, &wb_emlrtDCI, sp);
      }

      mtmp = maxpeaks;
      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
        emlrtIntegerCheckR2012b(mtmp, &vb_emlrtDCI, sp);
      }

      Pitch->size[1] = (int32_T)mtmp;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i29, (int32_T)sizeof
                        (real_T), &uc_emlrtRTEI);
      if (!(maxpeaks > 0.0)) {
        emlrtNonNegativeCheckR2012b(maxpeaks, &wb_emlrtDCI, sp);
      }

      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
        emlrtIntegerCheckR2012b(mtmp, &vb_emlrtDCI, sp);
      }

      n = (int32_T)mtmp;
      for (i29 = 0; i29 < n; i29++) {
        Pitch->data[i29] = 0.0;
      }

      /* 'peaks:116' Merit     = ones (1, maxpeaks); */
      i29 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i29, (int32_T)sizeof
                        (real_T), &uc_emlrtRTEI);
      n = (int32_T)maxpeaks;
      for (i29 = 0; i29 < n; i29++) {
        Merit->data[i29] = 1.0;
      }
    } else {
      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      /* 'peaks:122' [Merit, Idx] = sort(Merit, 'descend'); */
      st.site = &xi_emlrtRSI;
      b_st.site = &bj_emlrtRSI;
      sort(&b_st, b_Merit, iidx);

      /* 'peaks:123' Pitch = Pitch(Idx); */
      for (i29 = 0; i29 < 100; i29++) {
        if (!((iidx[i29] >= 1) && (iidx[i29] <= 100))) {
          emlrtDynamicBoundsCheckR2012b(iidx[i29], 1, 100, &kf_emlrtBCI, sp);
        }

        c_Pitch[i29] = b_Pitch[iidx[i29] - 1];
      }

      memcpy(&b_Pitch[0], &c_Pitch[0], 100U * sizeof(real_T));

      /*  keep the number of peaks not greater than max number */
      /* 'peaks:125' numpeaks = min(numpeaks, maxpeaks); */
      numpeaks = muDoubleScalarMin(numpeaks, maxpeaks);

      /* 'peaks:127' Pitch  = Pitch(1:numpeaks); */
      if (1.0 > numpeaks) {
        n = 0;
      } else {
        if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
          emlrtIntegerCheckR2012b(numpeaks, &ub_emlrtDCI, sp);
        }

        n = (int32_T)numpeaks;
      }

      i29 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = n;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i29, (int32_T)sizeof
                        (real_T), &uc_emlrtRTEI);
      for (i29 = 0; i29 < n; i29++) {
        Pitch->data[Pitch->size[0] * i29] = b_Pitch[i29];
      }

      /* 'peaks:128' Merit = Merit(1:numpeaks); */
      if (1.0 > numpeaks) {
        itmp = 0;
      } else {
        if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
          emlrtIntegerCheckR2012b(numpeaks, &tb_emlrtDCI, sp);
        }

        itmp = (int32_T)numpeaks;
      }

      i29 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = itmp;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i29, (int32_T)sizeof
                        (real_T), &uc_emlrtRTEI);
      for (i29 = 0; i29 < itmp; i29++) {
        Merit->data[Merit->size[0] * i29] = b_Merit[i29];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      /* 'peaks:131' if (numpeaks > 0) */
      if (numpeaks > 0.0) {
        /*  if best peak has F < this, insert peak at 2F */
        /* 'peaks:133' if (Pitch(1) > Prm.f0_double) */
        if (!(1 <= n)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, n, &ff_emlrtBCI, sp);
        }

        if (b_Pitch[0] > Prm_f0_double) {
          /* 'peaks:134' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = muDoubleScalarMin(numpeaks + 1.0, maxpeaks);

          /* 'peaks:135' if(numpeaks>length(Pitch)) */
          if (numpeaks > n) {
            emxInit_real_T(sp, &r29, 2, &uc_emlrtRTEI, true);

            /* 'peaks:136' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp > 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &ec_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &dc_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            b_n = Pitch->size[1];
            i29 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[1] = b_n + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)Pitch, i29, (int32_T)
                              sizeof(real_T), &uc_emlrtRTEI);
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp > 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &ec_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &dc_emlrtDCI, sp);
            }

            n = (int32_T)mtmp;
            i29 = r29->size[0] * r29->size[1];
            r29->size[0] = 1;
            r29->size[1] = n;
            emxEnsureCapacity(sp, (emxArray__common *)r29, i29, (int32_T)sizeof
                              (real_T), &uc_emlrtRTEI);
            for (i29 = 0; i29 < n; i29++) {
              r29->data[r29->size[0] * i29] = 0.0;
            }

            for (i29 = 0; i29 < ixstart; i29++) {
              Pitch->data[b_n + i29] = r29->data[i29];
            }

            emxFree_real_T(&r29);
            emxInit_real_T(sp, &r30, 2, &uc_emlrtRTEI, true);

            /* 'peaks:137' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            mtmp = numpeaks - (real_T)itmp;
            if (!(mtmp > 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &gc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &fc_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            b_n = Merit->size[1];
            i29 = Merit->size[0] * Merit->size[1];
            Merit->size[1] = b_n + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)Merit, i29, (int32_T)
                              sizeof(real_T), &uc_emlrtRTEI);
            mtmp = numpeaks - (real_T)itmp;
            if (!(mtmp > 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &gc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &fc_emlrtDCI, sp);
            }

            n = (int32_T)mtmp;
            i29 = r30->size[0] * r30->size[1];
            r30->size[0] = 1;
            r30->size[1] = n;
            emxEnsureCapacity(sp, (emxArray__common *)r30, i29, (int32_T)sizeof
                              (real_T), &uc_emlrtRTEI);
            for (i29 = 0; i29 < n; i29++) {
              r30->data[r30->size[0] * i29] = 0.0;
            }

            for (i29 = 0; i29 < ixstart; i29++) {
              Merit->data[b_n + i29] = r30->data[i29];
            }

            emxFree_real_T(&r30);
          }

          /* 'peaks:139' Pitch(numpeaks) = Pitch(1)/2.0; */
          i29 = Pitch->size[1];
          if (!(1 <= i29)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i29, &ef_emlrtBCI, sp);
          }

          i29 = Pitch->size[1];
          if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
            emlrtIntegerCheckR2012b(numpeaks, &lc_emlrtDCI, sp);
          }

          i30 = (int32_T)numpeaks;
          if (!((i30 >= 1) && (i30 <= i29))) {
            emlrtDynamicBoundsCheckR2012b(i30, 1, i29, &lf_emlrtBCI, sp);
          }

          Pitch->data[i30 - 1] = Pitch->data[0] / 2.0;

          /*  Set merit for inserted peaks */
          /* 'peaks:141' Merit(numpeaks) = Prm.merit_extra; */
          i29 = Merit->size[1];
          i30 = (int32_T)numpeaks;
          if (!((i30 >= 1) && (i30 <= i29))) {
            emlrtDynamicBoundsCheckR2012b(i30, 1, i29, &mf_emlrtBCI, sp);
          }

          Merit->data[i30 - 1] = Prm_merit_extra;
        }

        /*  If best peak has F > this, insert peak at half F */
        /* 'peaks:145' if (Pitch(1) < Prm.f0_half) */
        i29 = Pitch->size[1];
        if (!(1 <= i29)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i29, &df_emlrtBCI, sp);
        }

        if (Pitch->data[0] < Prm_f0_half) {
          /* 'peaks:146' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = muDoubleScalarMin(numpeaks + 1.0, maxpeaks);

          /* 'peaks:147' if(numpeaks>length(Pitch)) */
          if (numpeaks > Pitch->size[1]) {
            emxInit_real_T(sp, &d_Pitch, 2, &uc_emlrtRTEI, true);

            /* 'peaks:148' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            n = Pitch->size[1];
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp > 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &nc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &mc_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            i29 = d_Pitch->size[0] * d_Pitch->size[1];
            d_Pitch->size[0] = 1;
            d_Pitch->size[1] = Pitch->size[1] + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)d_Pitch, i29, (int32_T)
                              sizeof(real_T), &uc_emlrtRTEI);
            n = Pitch->size[1];
            for (i29 = 0; i29 < n; i29++) {
              d_Pitch->data[d_Pitch->size[0] * i29] = Pitch->data[Pitch->size[0]
                * i29];
            }

            for (i29 = 0; i29 < ixstart; i29++) {
              d_Pitch->data[d_Pitch->size[0] * (i29 + Pitch->size[1])] = 0.0;
            }

            i29 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[0] = 1;
            Pitch->size[1] = d_Pitch->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)Pitch, i29, (int32_T)
                              sizeof(real_T), &uc_emlrtRTEI);
            n = d_Pitch->size[1];
            for (i29 = 0; i29 < n; i29++) {
              Pitch->data[Pitch->size[0] * i29] = d_Pitch->data[d_Pitch->size[0]
                * i29];
            }

            emxFree_real_T(&d_Pitch);
            emxInit_real_T(sp, &c_Merit, 2, &uc_emlrtRTEI, true);

            /* 'peaks:149' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            n = Merit->size[1];
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp > 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &pc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &oc_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            i29 = c_Merit->size[0] * c_Merit->size[1];
            c_Merit->size[0] = 1;
            c_Merit->size[1] = Merit->size[1] + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)c_Merit, i29, (int32_T)
                              sizeof(real_T), &uc_emlrtRTEI);
            n = Merit->size[1];
            for (i29 = 0; i29 < n; i29++) {
              c_Merit->data[c_Merit->size[0] * i29] = Merit->data[Merit->size[0]
                * i29];
            }

            for (i29 = 0; i29 < ixstart; i29++) {
              c_Merit->data[c_Merit->size[0] * (i29 + Merit->size[1])] = 0.0;
            }

            i29 = Merit->size[0] * Merit->size[1];
            Merit->size[0] = 1;
            Merit->size[1] = c_Merit->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)Merit, i29, (int32_T)
                              sizeof(real_T), &uc_emlrtRTEI);
            n = c_Merit->size[1];
            for (i29 = 0; i29 < n; i29++) {
              Merit->data[Merit->size[0] * i29] = c_Merit->data[c_Merit->size[0]
                * i29];
            }

            emxFree_real_T(&c_Merit);
          }

          /* 'peaks:151' Pitch(numpeaks) = 2.0*Pitch(1); */
          i29 = Pitch->size[1];
          if (!(1 <= i29)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i29, &cf_emlrtBCI, sp);
          }

          i29 = Pitch->size[1];
          if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
            emlrtIntegerCheckR2012b(numpeaks, &qc_emlrtDCI, sp);
          }

          i30 = (int32_T)numpeaks;
          if (!((i30 >= 1) && (i30 <= i29))) {
            emlrtDynamicBoundsCheckR2012b(i30, 1, i29, &nf_emlrtBCI, sp);
          }

          Pitch->data[i30 - 1] = 2.0 * Pitch->data[0];

          /* 'peaks:152' Merit(numpeaks) = Prm.merit_extra; */
          i29 = Merit->size[1];
          i30 = (int32_T)numpeaks;
          if (!((i30 >= 1) && (i30 <= i29))) {
            emlrtDynamicBoundsCheckR2012b(i30, 1, i29, &of_emlrtBCI, sp);
          }

          Merit->data[i30 - 1] = Prm_merit_extra;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        /* 'peaks:156' if (numpeaks < maxpeaks) */
        if (numpeaks < maxpeaks) {
          emxInit_real_T(sp, &r31, 2, &uc_emlrtRTEI, true);

          /* 'peaks:157' Pitch = [Pitch zeros(1,maxpeaks-numpeaks)]; */
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp > 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &ic_emlrtDCI, sp);
          }

          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &hc_emlrtDCI, sp);
          }

          ixstart = (int32_T)mtmp;
          b_n = Pitch->size[1];
          i29 = Pitch->size[0] * Pitch->size[1];
          Pitch->size[1] = b_n + ixstart;
          emxEnsureCapacity(sp, (emxArray__common *)Pitch, i29, (int32_T)sizeof
                            (real_T), &uc_emlrtRTEI);
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp > 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &ic_emlrtDCI, sp);
          }

          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &hc_emlrtDCI, sp);
          }

          n = (int32_T)mtmp;
          i29 = r31->size[0] * r31->size[1];
          r31->size[0] = 1;
          r31->size[1] = n;
          emxEnsureCapacity(sp, (emxArray__common *)r31, i29, (int32_T)sizeof
                            (real_T), &uc_emlrtRTEI);
          for (i29 = 0; i29 < n; i29++) {
            r31->data[r31->size[0] * i29] = 0.0;
          }

          for (i29 = 0; i29 < ixstart; i29++) {
            Pitch->data[b_n + i29] = r31->data[i29];
          }

          emxFree_real_T(&r31);
          emxInit_real_T(sp, &r32, 2, &uc_emlrtRTEI, true);

          /* 'peaks:158' Merit = [Merit zeros(1,maxpeaks-numpeaks)]; */
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp > 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &kc_emlrtDCI, sp);
          }

          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &jc_emlrtDCI, sp);
          }

          ixstart = (int32_T)mtmp;
          b_n = Merit->size[1];
          i29 = Merit->size[0] * Merit->size[1];
          Merit->size[1] = b_n + ixstart;
          emxEnsureCapacity(sp, (emxArray__common *)Merit, i29, (int32_T)sizeof
                            (real_T), &uc_emlrtRTEI);
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp > 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &kc_emlrtDCI, sp);
          }

          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &jc_emlrtDCI, sp);
          }

          n = (int32_T)mtmp;
          i29 = r32->size[0] * r32->size[1];
          r32->size[0] = 1;
          r32->size[1] = n;
          emxEnsureCapacity(sp, (emxArray__common *)r32, i29, (int32_T)sizeof
                            (real_T), &uc_emlrtRTEI);
          for (i29 = 0; i29 < n; i29++) {
            r32->data[r32->size[0] * i29] = 0.0;
          }

          for (i29 = 0; i29 < ixstart; i29++) {
            Merit->data[b_n + i29] = r32->data[i29];
          }

          emxFree_real_T(&r32);

          /* 'peaks:159' Pitch(numpeaks+1:maxpeaks)  = Pitch(1); */
          if (numpeaks + 1.0 > maxpeaks) {
            i29 = 0;
            n = 0;
          } else {
            i29 = Pitch->size[1];
            if (numpeaks + 1.0 != (int32_T)muDoubleScalarFloor(numpeaks + 1.0))
            {
              emlrtIntegerCheckR2012b(numpeaks + 1.0, &sb_emlrtDCI, sp);
            }

            i30 = (int32_T)(numpeaks + 1.0);
            if (!((i30 >= 1) && (i30 <= i29))) {
              emlrtDynamicBoundsCheckR2012b(i30, 1, i29, &af_emlrtBCI, sp);
            }

            i29 = i30 - 1;
            i30 = Pitch->size[1];
            if (maxpeaks != (int32_T)muDoubleScalarFloor(maxpeaks)) {
              emlrtIntegerCheckR2012b(maxpeaks, &sb_emlrtDCI, sp);
            }

            n = (int32_T)maxpeaks;
            if (!((n >= 1) && (n <= i30))) {
              emlrtDynamicBoundsCheckR2012b(n, 1, i30, &af_emlrtBCI, sp);
            }
          }

          emxInit_int32_T(sp, &r33, 2, &uc_emlrtRTEI, true);
          i30 = r33->size[0] * r33->size[1];
          r33->size[0] = 1;
          r33->size[1] = n - i29;
          emxEnsureCapacity(sp, (emxArray__common *)r33, i30, (int32_T)sizeof
                            (int32_T), &uc_emlrtRTEI);
          n -= i29;
          for (i30 = 0; i30 < n; i30++) {
            r33->data[r33->size[0] * i30] = i29 + i30;
          }

          i29 = Pitch->size[1];
          if (!(1 <= i29)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i29, &bf_emlrtBCI, sp);
          }

          mtmp = Pitch->data[0];
          n = r33->size[0] * r33->size[1];
          for (i29 = 0; i29 < n; i29++) {
            Pitch->data[r33->data[i29]] = mtmp;
          }

          /* 'peaks:160' Merit(numpeaks+1:maxpeaks) = Merit(1); */
          if (numpeaks + 1.0 > maxpeaks) {
            i29 = 0;
            n = 0;
          } else {
            i29 = Merit->size[1];
            if (numpeaks + 1.0 != (int32_T)muDoubleScalarFloor(numpeaks + 1.0))
            {
              emlrtIntegerCheckR2012b(numpeaks + 1.0, &rb_emlrtDCI, sp);
            }

            i30 = (int32_T)(numpeaks + 1.0);
            if (!((i30 >= 1) && (i30 <= i29))) {
              emlrtDynamicBoundsCheckR2012b(i30, 1, i29, &xe_emlrtBCI, sp);
            }

            i29 = i30 - 1;
            i30 = Merit->size[1];
            if (maxpeaks != (int32_T)muDoubleScalarFloor(maxpeaks)) {
              emlrtIntegerCheckR2012b(maxpeaks, &rb_emlrtDCI, sp);
            }

            n = (int32_T)maxpeaks;
            if (!((n >= 1) && (n <= i30))) {
              emlrtDynamicBoundsCheckR2012b(n, 1, i30, &xe_emlrtBCI, sp);
            }
          }

          i30 = r33->size[0] * r33->size[1];
          r33->size[0] = 1;
          r33->size[1] = n - i29;
          emxEnsureCapacity(sp, (emxArray__common *)r33, i30, (int32_T)sizeof
                            (int32_T), &uc_emlrtRTEI);
          n -= i29;
          for (i30 = 0; i30 < n; i30++) {
            r33->data[r33->size[0] * i30] = i29 + i30;
          }

          i29 = Merit->size[1];
          if (!(1 <= i29)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i29, &ye_emlrtBCI, sp);
          }

          mtmp = Merit->data[0];
          n = r33->size[0] * r33->size[1];
          for (i29 = 0; i29 < n; i29++) {
            Merit->data[r33->data[i29]] = mtmp;
          }

          emxFree_int32_T(&r33);
        }
      } else {
        /* 'peaks:162' else */
        /* 'peaks:163' Pitch    = zeros(1, maxpeaks); */
        i29 = Pitch->size[0] * Pitch->size[1];
        Pitch->size[0] = 1;
        if (!(maxpeaks > 0.0)) {
          emlrtNonNegativeCheckR2012b(maxpeaks, &qb_emlrtDCI, sp);
        }

        mtmp = maxpeaks;
        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &pb_emlrtDCI, sp);
        }

        Pitch->size[1] = (int32_T)mtmp;
        emxEnsureCapacity(sp, (emxArray__common *)Pitch, i29, (int32_T)sizeof
                          (real_T), &uc_emlrtRTEI);
        if (!(maxpeaks > 0.0)) {
          emlrtNonNegativeCheckR2012b(maxpeaks, &qb_emlrtDCI, sp);
        }

        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &pb_emlrtDCI, sp);
        }

        n = (int32_T)mtmp;
        for (i29 = 0; i29 < n; i29++) {
          Pitch->data[i29] = 0.0;
        }

        /* 'peaks:164' Merit    = ones (1, maxpeaks); */
        i29 = Merit->size[0] * Merit->size[1];
        Merit->size[0] = 1;
        Merit->size[1] = (int32_T)maxpeaks;
        emxEnsureCapacity(sp, (emxArray__common *)Merit, i29, (int32_T)sizeof
                          (real_T), &uc_emlrtRTEI);
        n = (int32_T)maxpeaks;
        for (i29 = 0; i29 < n; i29++) {
          Merit->data[i29] = 1.0;
        }
      }
    }
  }

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (peaks.c) */
