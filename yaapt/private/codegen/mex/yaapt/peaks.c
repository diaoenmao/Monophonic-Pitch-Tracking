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
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "mean.h"
#include "mrdivide.h"
#include "fix.h"
#include "mod.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo hk_emlrtRSI = { 75, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo ik_emlrtRSI = { 81, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo jk_emlrtRSI = { 99, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo kk_emlrtRSI = { 113, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo lk_emlrtRSI = { 122, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo f_emlrtMCI = { 60, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo g_emlrtMCI = { 64, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRTEInfo fd_emlrtRTEI = { 1, 26, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 160, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo vb_emlrtDCI = { 160, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 160, 38, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 159, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo wb_emlrtDCI = { 159, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 159, 39, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 151, 31, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 145, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 139, 27, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 133, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo xb_emlrtDCI = { 128, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo yb_emlrtDCI = { 127, 10, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo ff_emlrtBCI = { 1, 100, 106, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 99, 21, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo ac_emlrtDCI = { 99, 21, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtRTEInfo pg_emlrtRTEI = { 98, 1, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 81, 17, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo bc_emlrtDCI = { 81, 17, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 75, 16, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo cc_emlrtDCI = { 75, 16, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo dc_emlrtDCI = { 84, 25, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ec_emlrtDCI = { 84, 25, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo fc_emlrtDCI = { 115, 27, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo gc_emlrtDCI = { 115, 27, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo hc_emlrtDCI = { 163, 25, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ic_emlrtDCI = { 163, 25, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo jc_emlrtDCI = { 136, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo kc_emlrtDCI = { 136, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo lc_emlrtDCI = { 157, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo mc_emlrtDCI = { 157, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo nc_emlrtDCI = { 137, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo oc_emlrtDCI = { 137, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo pc_emlrtDCI = { 158, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo qc_emlrtDCI = { 158, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo jf_emlrtBCI = { 1, 100, 123, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 139, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo rc_emlrtDCI = { 139, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 141, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo sc_emlrtDCI = { 148, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo tc_emlrtDCI = { 148, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo uc_emlrtDCI = { 149, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo vc_emlrtDCI = { 149, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 151, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo wc_emlrtDCI = { 151, 9, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 152, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtRSInfo jq_emlrtRSI = { 64, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo kq_emlrtRSI = { 60, "peaks",
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
  const mxArray *m12;
  static const int32_T iv60[2] = { 1, 36 };

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
  const mxArray *m13;
  static const int32_T iv61[2] = { 1, 37 };

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
  static const char_T cv7[36] = { 'm', 'i', 'n', '_', 'l', 'a', 'g', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 'l', 'o', 'w', ' ', 'a', 'n', 'd', ' ', 'a',
    'd', 'j', 'u', 's', 't', 'e', 'd', ' ', '(', '%', 'd', ')' };

  static const char_T cv8[37] = { 'm', 'a', 'x', '_', 'l', 'a', 'g', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 'h', 'i', 'g', 'h', ' ', 'a', 'n', 'd', ' ',
    'a', 'd', 'j', 'u', 's', 't', 'e', 'd', ' ', '(', '%', 'd', ')' };

  real_T b_Pitch[100];
  real_T b_Merit[100];
  int32_T i33;
  int32_T n;
  int32_T i34;
  boolean_T b4;
  int32_T ixstart;
  int32_T b_n;
  real_T mtmp;
  int32_T ix;
  boolean_T exitg2;
  int32_T itmp;
  emxArray_real_T *b_Data;
  real_T avg_data;
  real_T numpeaks;
  real_T c_n;
  int32_T i35;
  int32_T iidx[100];
  real_T c_Pitch[100];
  boolean_T exitg1;
  emxArray_real_T *r25;
  emxArray_real_T *r26;
  emxArray_real_T *d_Pitch;
  emxArray_real_T *r27;
  emxArray_real_T *r28;
  emxArray_real_T *c_Merit;
  emxArray_int32_T *r29;
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
  covrtLogFcn(&emlrtCoverageInstance, 12U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 0);

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
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 0, b_mod(width, 2.0) == 0.0))
  {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 1);

    /* 'peaks:48' width = width + 1; */
    width++;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 2);

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
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 1, min_lag < 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 3);

    /* 'peaks:59' min_lag = 1; */
    min_lag = 1.0;

    /* 'peaks:60' disp('min_lag is too low and adjusted (%d)', min_lag); */
    st.site = &kq_emlrtRSI;
    disp(&st, b_emlrt_marshallOut(&st, cv7), emlrt_marshallOut(1.0), &f_emlrtMCI);
  }

  /* 'peaks:62' if max_lag > (length(Data) - width) */
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 2, max_lag > (real_T)
                 Data->size[1] - width)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 4);

    /* 'peaks:63' max_lag = length(Data) - width; */
    max_lag = (real_T)Data->size[1] - width;

    /* 'peaks:64' disp('max_lag is too high and adjusted (%d)', max_lag); */
    st.site = &jq_emlrtRSI;
    disp(&st, c_emlrt_marshallOut(&st, cv8), emlrt_marshallOut(max_lag),
         &g_emlrtMCI);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 5);

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'peaks:69' max_allow_lags = 100; */
  /* 'peaks:70' Pitch     = zeros(1, max_allow_lags); */
  /*  Peak(Pitch) candidates */
  /* 'peaks:71' Merit     = zeros(1, max_allow_lags); */
  memset(&b_Pitch[0], 0, 100U * sizeof(real_T));
  memset(&b_Merit[0], 0, 100U * sizeof(real_T));

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  /* 'peaks:75' max_data = max(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i33 = 0;
    n = 0;
  } else {
    i33 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &cc_emlrtDCI, sp);
    }

    i34 = (int32_T)min_lag;
    if (!((i34 >= 1) && (i34 <= i33))) {
      emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &if_emlrtBCI, sp);
    }

    i33 = i34 - 1;
    i34 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &cc_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i34))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i34, &if_emlrtBCI, sp);
    }
  }

  st.site = &hk_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  if ((n - i33 == 1) || (n - i33 != 1)) {
    b4 = true;
  } else {
    b4 = false;
  }

  if (b4) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &ig_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (n - i33 > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &hg_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &hb_emlrtRSI;
  ixstart = 1;
  b_n = n - i33;
  mtmp = Data->data[i33];
  if (n - i33 > 1) {
    if (muDoubleScalarIsNaN(mtmp)) {
      e_st.site = &ib_emlrtRSI;
      if ((!(2 > n - i33)) && (n - i33 > 2147483646)) {
        f_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= b_n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(Data->data[(i33 + ix) - 1])) {
          mtmp = Data->data[(i33 + ix) - 1];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < n - i33) {
      e_st.site = &jb_emlrtRSI;
      if ((!(ixstart + 1 > n - i33)) && (n - i33 > 2147483646)) {
        f_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      for (ix = ixstart - 1; ix + 2 <= b_n; ix++) {
        if (Data->data[(i33 + ix) + 1] > mtmp) {
          mtmp = Data->data[(i33 + ix) + 1];
        }
      }
    }
  }

  /* 'peaks:76' if (max_data > epsilon) */
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 3, mtmp > 1.0E-14)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 6);

    /* 'peaks:77' Data = Data/max_data; */
    i33 = Data->size[0] * Data->size[1];
    Data->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)Data, i33, (int32_T)sizeof(real_T),
                      &fd_emlrtRTEI);
    n = Data->size[0];
    itmp = Data->size[1];
    n *= itmp;
    for (i33 = 0; i33 < n; i33++) {
      Data->data[i33] /= mtmp;
    }
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 7);

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  /* 'peaks:81' avg_data = mean(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i33 = 0;
    n = 0;
  } else {
    i33 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &bc_emlrtDCI, sp);
    }

    i34 = (int32_T)min_lag;
    if (!((i34 >= 1) && (i34 <= i33))) {
      emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &hf_emlrtBCI, sp);
    }

    i33 = i34 - 1;
    i34 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &bc_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i34))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i34, &hf_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &b_Data, 2, &fd_emlrtRTEI, true);
  i34 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = n - i33;
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, i34, (int32_T)sizeof(real_T),
                    &fd_emlrtRTEI);
  n -= i33;
  for (i34 = 0; i34 < n; i34++) {
    b_Data->data[b_Data->size[0] * i34] = Data->data[i33 + i34];
  }

  st.site = &ik_emlrtRSI;
  avg_data = mean(&st, b_Data);

  /* 'peaks:82' if (avg_data > 1/PEAK_THRESH1) */
  emxFree_real_T(&b_Data);
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 4, avg_data > 1.0 /
                 Prm_shc_thresh1)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 8);

    /*     numpeaks = 0; */
    /* 'peaks:84' Pitch    = zeros(1, maxpeaks); */
    i33 = Pitch->size[0] * Pitch->size[1];
    Pitch->size[0] = 1;
    if (!(maxpeaks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(maxpeaks, &ec_emlrtDCI, sp);
    }

    mtmp = maxpeaks;
    if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
      emlrtIntegerCheckR2012b(mtmp, &dc_emlrtDCI, sp);
    }

    Pitch->size[1] = (int32_T)mtmp;
    emxEnsureCapacity(sp, (emxArray__common *)Pitch, i33, (int32_T)sizeof(real_T),
                      &fd_emlrtRTEI);
    if (!(maxpeaks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(maxpeaks, &ec_emlrtDCI, sp);
    }

    if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
      emlrtIntegerCheckR2012b(mtmp, &dc_emlrtDCI, sp);
    }

    n = (int32_T)mtmp;
    for (i33 = 0; i33 < n; i33++) {
      Pitch->data[i33] = 0.0;
    }

    /* 'peaks:85' Merit    = ones (1, maxpeaks); */
    i33 = Merit->size[0] * Merit->size[1];
    Merit->size[0] = 1;
    Merit->size[1] = (int32_T)maxpeaks;
    emxEnsureCapacity(sp, (emxArray__common *)Merit, i33, (int32_T)sizeof(real_T),
                      &fd_emlrtRTEI);
    n = (int32_T)maxpeaks;
    for (i33 = 0; i33 < n; i33++) {
      Merit->data[i33] = 1.0;
    }

    /*  force an early end for unoviced frame  */
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 9);

    /*  Step 1 */
    /*  Find all peaks for search range */
    /*  a "peak" must be the higher than a specfied number of */
    /*  points on either side of point.  Peaks are further "cleaned" */
    /*  up, to retain only best peaks i.e. peaks which do not meet certain */
    /*  criteria are eliminated. */
    /* 'peaks:97' numpeaks = 0; */
    numpeaks = 0.0;

    /* 'peaks:98' for n = min_lag:max_lag */
    i33 = (int32_T)(max_lag + (1.0 - min_lag));
    emlrtForLoopVectorCheckR2012b(min_lag, 1.0, max_lag, mxDOUBLE_CLASS, i33,
      &pg_emlrtRTEI, sp);
    b_n = 0;
    while (b_n <= i33 - 1) {
      c_n = min_lag + (real_T)b_n;
      covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 10);

      /* 'peaks:99' [y, lag]  = max(Data(n:(n+width-1))); */
      mtmp = (c_n + width) - 1.0;
      if (c_n > mtmp) {
        i34 = 0;
        i35 = 0;
      } else {
        i34 = Data->size[1];
        if (c_n != (int32_T)muDoubleScalarFloor(c_n)) {
          emlrtIntegerCheckR2012b(c_n, &ac_emlrtDCI, sp);
        }

        n = (int32_T)c_n;
        if (!((n >= 1) && (n <= i34))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, i34, &gf_emlrtBCI, sp);
        }

        i34 = n - 1;
        n = Data->size[1];
        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &ac_emlrtDCI, sp);
        }

        i35 = (int32_T)mtmp;
        if (!((i35 >= 1) && (i35 <= n))) {
          emlrtDynamicBoundsCheckR2012b(i35, 1, n, &gf_emlrtBCI, sp);
        }
      }

      st.site = &jk_emlrtRSI;
      b_st.site = &mk_emlrtRSI;
      c_st.site = &nk_emlrtRSI;
      if ((i35 - i34 == 1) || (i35 - i34 != 1)) {
        b4 = true;
      } else {
        b4 = false;
      }

      if (b4) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &ig_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (i35 - i34 > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &hg_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &hb_emlrtRSI;
      ixstart = 2;
      n = i35 - i34;
      mtmp = Data->data[i34];
      itmp = 1;
      if (i35 - i34 > 1) {
        if (muDoubleScalarIsNaN(mtmp)) {
          e_st.site = &ib_emlrtRSI;
          if ((!(2 > i35 - i34)) && (i35 - i34 > 2147483646)) {
            f_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&f_st, true);
          }

          ix = 2;
          exitg1 = false;
          while ((!exitg1) && (ix <= n)) {
            ixstart = ix + 1;
            if (!muDoubleScalarIsNaN(Data->data[(i34 + ix) - 1])) {
              mtmp = Data->data[(i34 + ix) - 1];
              itmp = ix;
              exitg1 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart - 1 < i35 - i34) {
          e_st.site = &jb_emlrtRSI;
          if ((!(ixstart > i35 - i34)) && (i35 - i34 > 2147483646)) {
            f_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&f_st, true);
          }

          while (ixstart <= n) {
            if (Data->data[(i34 + ixstart) - 1] > mtmp) {
              mtmp = Data->data[(i34 + ixstart) - 1];
              itmp = ixstart;
            }

            ixstart++;
          }
        }
      }

      /*  find peaks which are larger than threshold    */
      /* 'peaks:101' if (lag == center) && y>(PEAK_THRESH2*avg_data) */
      if (covrtLogCond(&emlrtCoverageInstance, 12U, 0U, 0, itmp == center) &&
          covrtLogCond(&emlrtCoverageInstance, 12U, 0U, 1, mtmp >
                       Prm_shc_thresh2 * avg_data)) {
        covrtLogMcdc(&emlrtCoverageInstance, 12U, 0U, 0, true);
        covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 5, true);
        covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 11);

        /*  Note Pitch(1) = delta, Pitch(2) = 2*delta */
        /*  Convert FFT indices to Pitch in Hz */
        /* 'peaks:105' numpeaks = numpeaks + 1; */
        numpeaks++;

        /* 'peaks:106' Pitch(numpeaks)  = (n+center-1)*delta; */
        i34 = (int32_T)numpeaks;
        if (!((i34 >= 1) && (i34 <= 100))) {
          emlrtDynamicBoundsCheckR2012b(i34, 1, 100, &ff_emlrtBCI, sp);
        }

        b_Pitch[i34 - 1] = ((c_n + center) - 1.0) * delta;

        /* 'peaks:107' Merit(numpeaks)  = y; */
        b_Merit[(int32_T)numpeaks - 1] = mtmp;
      } else {
        covrtLogMcdc(&emlrtCoverageInstance, 12U, 0U, 0, false);
        covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 5, false);
      }

      b_n++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 0, 0);

    /*  Step 2 */
    /*  Be sure there is large peak */
    /* 'peaks:113' if (max(Merit)/avg_data < PEAK_THRESH1) */
    st.site = &kk_emlrtRSI;
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

    if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 6, mtmp / avg_data <
                   Prm_shc_thresh1)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 12);

      /*    numpeaks = 0; */
      /* 'peaks:115' Pitch      = zeros(1, maxpeaks); */
      i33 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      if (!(maxpeaks >= 0.0)) {
        emlrtNonNegativeCheckR2012b(maxpeaks, &gc_emlrtDCI, sp);
      }

      mtmp = maxpeaks;
      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
        emlrtIntegerCheckR2012b(mtmp, &fc_emlrtDCI, sp);
      }

      Pitch->size[1] = (int32_T)mtmp;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i33, (int32_T)sizeof
                        (real_T), &fd_emlrtRTEI);
      if (!(maxpeaks >= 0.0)) {
        emlrtNonNegativeCheckR2012b(maxpeaks, &gc_emlrtDCI, sp);
      }

      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
        emlrtIntegerCheckR2012b(mtmp, &fc_emlrtDCI, sp);
      }

      n = (int32_T)mtmp;
      for (i33 = 0; i33 < n; i33++) {
        Pitch->data[i33] = 0.0;
      }

      /* 'peaks:116' Merit     = ones (1, maxpeaks); */
      i33 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i33, (int32_T)sizeof
                        (real_T), &fd_emlrtRTEI);
      n = (int32_T)maxpeaks;
      for (i33 = 0; i33 < n; i33++) {
        Merit->data[i33] = 1.0;
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 13);

      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      /* 'peaks:122' [Merit, Idx] = sort(Merit, 'descend'); */
      st.site = &lk_emlrtRSI;
      b_st.site = &ok_emlrtRSI;
      sort(&b_st, b_Merit, iidx);

      /* 'peaks:123' Pitch = Pitch(Idx); */
      for (i33 = 0; i33 < 100; i33++) {
        if (!((iidx[i33] >= 1) && (iidx[i33] <= 100))) {
          emlrtDynamicBoundsCheckR2012b(iidx[i33], 1, 100, &jf_emlrtBCI, sp);
        }

        c_Pitch[i33] = b_Pitch[iidx[i33] - 1];
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
          emlrtIntegerCheckR2012b(numpeaks, &yb_emlrtDCI, sp);
        }

        n = (int32_T)numpeaks;
      }

      i33 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = n;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i33, (int32_T)sizeof
                        (real_T), &fd_emlrtRTEI);
      for (i33 = 0; i33 < n; i33++) {
        Pitch->data[Pitch->size[0] * i33] = b_Pitch[i33];
      }

      /* 'peaks:128' Merit = Merit(1:numpeaks); */
      if (1.0 > numpeaks) {
        itmp = 0;
      } else {
        if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
          emlrtIntegerCheckR2012b(numpeaks, &xb_emlrtDCI, sp);
        }

        itmp = (int32_T)numpeaks;
      }

      i33 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = itmp;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i33, (int32_T)sizeof
                        (real_T), &fd_emlrtRTEI);
      for (i33 = 0; i33 < itmp; i33++) {
        Merit->data[Merit->size[0] * i33] = b_Merit[i33];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      /* 'peaks:131' if (numpeaks > 0) */
      if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 7, numpeaks > 0.0)) {
        /*  if best peak has F < this, insert peak at 2F */
        /* 'peaks:133' if (Pitch(1) > Prm.f0_double) */
        if (!(1 <= n)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, n, &ef_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 8, b_Pitch[0] >
                       Prm_f0_double)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 14);

          /* 'peaks:134' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = muDoubleScalarMin(numpeaks + 1.0, maxpeaks);

          /* 'peaks:135' if(numpeaks>length(Pitch)) */
          if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 9, numpeaks > n)) {
            emxInit_real_T(sp, &r25, 2, &fd_emlrtRTEI, true);
            covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 15);

            /* 'peaks:136' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &kc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &jc_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            b_n = Pitch->size[1];
            i33 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[1] = b_n + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)Pitch, i33, (int32_T)
                              sizeof(real_T), &fd_emlrtRTEI);
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &kc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &jc_emlrtDCI, sp);
            }

            n = (int32_T)mtmp;
            i33 = r25->size[0] * r25->size[1];
            r25->size[0] = 1;
            r25->size[1] = n;
            emxEnsureCapacity(sp, (emxArray__common *)r25, i33, (int32_T)sizeof
                              (real_T), &fd_emlrtRTEI);
            for (i33 = 0; i33 < n; i33++) {
              r25->data[r25->size[0] * i33] = 0.0;
            }

            for (i33 = 0; i33 < ixstart; i33++) {
              Pitch->data[b_n + i33] = r25->data[i33];
            }

            emxFree_real_T(&r25);
            emxInit_real_T(sp, &r27, 2, &fd_emlrtRTEI, true);

            /* 'peaks:137' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            mtmp = numpeaks - (real_T)itmp;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &oc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &nc_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            b_n = Merit->size[1];
            i33 = Merit->size[0] * Merit->size[1];
            Merit->size[1] = b_n + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)Merit, i33, (int32_T)
                              sizeof(real_T), &fd_emlrtRTEI);
            mtmp = numpeaks - (real_T)itmp;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &oc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &nc_emlrtDCI, sp);
            }

            n = (int32_T)mtmp;
            i33 = r27->size[0] * r27->size[1];
            r27->size[0] = 1;
            r27->size[1] = n;
            emxEnsureCapacity(sp, (emxArray__common *)r27, i33, (int32_T)sizeof
                              (real_T), &fd_emlrtRTEI);
            for (i33 = 0; i33 < n; i33++) {
              r27->data[r27->size[0] * i33] = 0.0;
            }

            for (i33 = 0; i33 < ixstart; i33++) {
              Merit->data[b_n + i33] = r27->data[i33];
            }

            emxFree_real_T(&r27);
          }

          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 16);

          /* 'peaks:139' Pitch(numpeaks) = Pitch(1)/2.0; */
          i33 = Pitch->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &df_emlrtBCI, sp);
          }

          i33 = Pitch->size[1];
          if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
            emlrtIntegerCheckR2012b(numpeaks, &rc_emlrtDCI, sp);
          }

          i34 = (int32_T)numpeaks;
          if (!((i34 >= 1) && (i34 <= i33))) {
            emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &kf_emlrtBCI, sp);
          }

          Pitch->data[i34 - 1] = Pitch->data[0] / 2.0;

          /*  Set merit for inserted peaks */
          /* 'peaks:141' Merit(numpeaks) = Prm.merit_extra; */
          i33 = Merit->size[1];
          i34 = (int32_T)numpeaks;
          if (!((i34 >= 1) && (i34 <= i33))) {
            emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &lf_emlrtBCI, sp);
          }

          Merit->data[i34 - 1] = Prm_merit_extra;
        }

        /*  If best peak has F > this, insert peak at half F */
        /* 'peaks:145' if (Pitch(1) < Prm.f0_half) */
        i33 = Pitch->size[1];
        if (!(1 <= i33)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i33, &cf_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 10, Pitch->data[0] <
                       Prm_f0_half)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 17);

          /* 'peaks:146' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = muDoubleScalarMin(numpeaks + 1.0, maxpeaks);

          /* 'peaks:147' if(numpeaks>length(Pitch)) */
          if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 11, numpeaks >
                         Pitch->size[1])) {
            emxInit_real_T(sp, &d_Pitch, 2, &fd_emlrtRTEI, true);
            covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 18);

            /* 'peaks:148' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            n = Pitch->size[1];
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &tc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &sc_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            i33 = d_Pitch->size[0] * d_Pitch->size[1];
            d_Pitch->size[0] = 1;
            d_Pitch->size[1] = Pitch->size[1] + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)d_Pitch, i33, (int32_T)
                              sizeof(real_T), &fd_emlrtRTEI);
            n = Pitch->size[1];
            for (i33 = 0; i33 < n; i33++) {
              d_Pitch->data[d_Pitch->size[0] * i33] = Pitch->data[Pitch->size[0]
                * i33];
            }

            for (i33 = 0; i33 < ixstart; i33++) {
              d_Pitch->data[d_Pitch->size[0] * (i33 + Pitch->size[1])] = 0.0;
            }

            i33 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[0] = 1;
            Pitch->size[1] = d_Pitch->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)Pitch, i33, (int32_T)
                              sizeof(real_T), &fd_emlrtRTEI);
            n = d_Pitch->size[1];
            for (i33 = 0; i33 < n; i33++) {
              Pitch->data[Pitch->size[0] * i33] = d_Pitch->data[d_Pitch->size[0]
                * i33];
            }

            emxFree_real_T(&d_Pitch);
            emxInit_real_T(sp, &c_Merit, 2, &fd_emlrtRTEI, true);

            /* 'peaks:149' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            n = Merit->size[1];
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &vc_emlrtDCI, sp);
            }

            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &uc_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            i33 = c_Merit->size[0] * c_Merit->size[1];
            c_Merit->size[0] = 1;
            c_Merit->size[1] = Merit->size[1] + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)c_Merit, i33, (int32_T)
                              sizeof(real_T), &fd_emlrtRTEI);
            n = Merit->size[1];
            for (i33 = 0; i33 < n; i33++) {
              c_Merit->data[c_Merit->size[0] * i33] = Merit->data[Merit->size[0]
                * i33];
            }

            for (i33 = 0; i33 < ixstart; i33++) {
              c_Merit->data[c_Merit->size[0] * (i33 + Merit->size[1])] = 0.0;
            }

            i33 = Merit->size[0] * Merit->size[1];
            Merit->size[0] = 1;
            Merit->size[1] = c_Merit->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)Merit, i33, (int32_T)
                              sizeof(real_T), &fd_emlrtRTEI);
            n = c_Merit->size[1];
            for (i33 = 0; i33 < n; i33++) {
              Merit->data[Merit->size[0] * i33] = c_Merit->data[c_Merit->size[0]
                * i33];
            }

            emxFree_real_T(&c_Merit);
          }

          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 19);

          /* 'peaks:151' Pitch(numpeaks) = 2.0*Pitch(1); */
          i33 = Pitch->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &bf_emlrtBCI, sp);
          }

          i33 = Pitch->size[1];
          if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
            emlrtIntegerCheckR2012b(numpeaks, &wc_emlrtDCI, sp);
          }

          i34 = (int32_T)numpeaks;
          if (!((i34 >= 1) && (i34 <= i33))) {
            emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &mf_emlrtBCI, sp);
          }

          Pitch->data[i34 - 1] = 2.0 * Pitch->data[0];

          /* 'peaks:152' Merit(numpeaks) = Prm.merit_extra; */
          i33 = Merit->size[1];
          i34 = (int32_T)numpeaks;
          if (!((i34 >= 1) && (i34 <= i33))) {
            emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &nf_emlrtBCI, sp);
          }

          Merit->data[i34 - 1] = Prm_merit_extra;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        /* 'peaks:156' if (numpeaks < maxpeaks) */
        if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 12, numpeaks < maxpeaks))
        {
          emxInit_real_T(sp, &r26, 2, &fd_emlrtRTEI, true);
          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 20);

          /* 'peaks:157' Pitch = [Pitch zeros(1,maxpeaks-numpeaks)]; */
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp >= 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &mc_emlrtDCI, sp);
          }

          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &lc_emlrtDCI, sp);
          }

          ixstart = (int32_T)mtmp;
          b_n = Pitch->size[1];
          i33 = Pitch->size[0] * Pitch->size[1];
          Pitch->size[1] = b_n + ixstart;
          emxEnsureCapacity(sp, (emxArray__common *)Pitch, i33, (int32_T)sizeof
                            (real_T), &fd_emlrtRTEI);
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp >= 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &mc_emlrtDCI, sp);
          }

          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &lc_emlrtDCI, sp);
          }

          n = (int32_T)mtmp;
          i33 = r26->size[0] * r26->size[1];
          r26->size[0] = 1;
          r26->size[1] = n;
          emxEnsureCapacity(sp, (emxArray__common *)r26, i33, (int32_T)sizeof
                            (real_T), &fd_emlrtRTEI);
          for (i33 = 0; i33 < n; i33++) {
            r26->data[r26->size[0] * i33] = 0.0;
          }

          for (i33 = 0; i33 < ixstart; i33++) {
            Pitch->data[b_n + i33] = r26->data[i33];
          }

          emxFree_real_T(&r26);
          emxInit_real_T(sp, &r28, 2, &fd_emlrtRTEI, true);

          /* 'peaks:158' Merit = [Merit zeros(1,maxpeaks-numpeaks)]; */
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp >= 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &qc_emlrtDCI, sp);
          }

          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &pc_emlrtDCI, sp);
          }

          ixstart = (int32_T)mtmp;
          b_n = Merit->size[1];
          i33 = Merit->size[0] * Merit->size[1];
          Merit->size[1] = b_n + ixstart;
          emxEnsureCapacity(sp, (emxArray__common *)Merit, i33, (int32_T)sizeof
                            (real_T), &fd_emlrtRTEI);
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp >= 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &qc_emlrtDCI, sp);
          }

          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &pc_emlrtDCI, sp);
          }

          n = (int32_T)mtmp;
          i33 = r28->size[0] * r28->size[1];
          r28->size[0] = 1;
          r28->size[1] = n;
          emxEnsureCapacity(sp, (emxArray__common *)r28, i33, (int32_T)sizeof
                            (real_T), &fd_emlrtRTEI);
          for (i33 = 0; i33 < n; i33++) {
            r28->data[r28->size[0] * i33] = 0.0;
          }

          for (i33 = 0; i33 < ixstart; i33++) {
            Merit->data[b_n + i33] = r28->data[i33];
          }

          emxFree_real_T(&r28);

          /* 'peaks:159' Pitch(numpeaks+1:maxpeaks)  = Pitch(1); */
          if (numpeaks + 1.0 > maxpeaks) {
            i33 = 0;
            n = 0;
          } else {
            i33 = Pitch->size[1];
            if (numpeaks + 1.0 != (int32_T)muDoubleScalarFloor(numpeaks + 1.0))
            {
              emlrtIntegerCheckR2012b(numpeaks + 1.0, &wb_emlrtDCI, sp);
            }

            i34 = (int32_T)(numpeaks + 1.0);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &ye_emlrtBCI, sp);
            }

            i33 = i34 - 1;
            i34 = Pitch->size[1];
            if (maxpeaks != (int32_T)muDoubleScalarFloor(maxpeaks)) {
              emlrtIntegerCheckR2012b(maxpeaks, &wb_emlrtDCI, sp);
            }

            n = (int32_T)maxpeaks;
            if (!((n >= 1) && (n <= i34))) {
              emlrtDynamicBoundsCheckR2012b(n, 1, i34, &ye_emlrtBCI, sp);
            }
          }

          emxInit_int32_T(sp, &r29, 2, &fd_emlrtRTEI, true);
          i34 = r29->size[0] * r29->size[1];
          r29->size[0] = 1;
          r29->size[1] = n - i33;
          emxEnsureCapacity(sp, (emxArray__common *)r29, i34, (int32_T)sizeof
                            (int32_T), &fd_emlrtRTEI);
          n -= i33;
          for (i34 = 0; i34 < n; i34++) {
            r29->data[r29->size[0] * i34] = i33 + i34;
          }

          i33 = Pitch->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &af_emlrtBCI, sp);
          }

          mtmp = Pitch->data[0];
          n = r29->size[0] * r29->size[1];
          for (i33 = 0; i33 < n; i33++) {
            Pitch->data[r29->data[i33]] = mtmp;
          }

          /* 'peaks:160' Merit(numpeaks+1:maxpeaks) = Merit(1); */
          if (numpeaks + 1.0 > maxpeaks) {
            i33 = 0;
            n = 0;
          } else {
            i33 = Merit->size[1];
            if (numpeaks + 1.0 != (int32_T)muDoubleScalarFloor(numpeaks + 1.0))
            {
              emlrtIntegerCheckR2012b(numpeaks + 1.0, &vb_emlrtDCI, sp);
            }

            i34 = (int32_T)(numpeaks + 1.0);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &we_emlrtBCI, sp);
            }

            i33 = i34 - 1;
            i34 = Merit->size[1];
            if (maxpeaks != (int32_T)muDoubleScalarFloor(maxpeaks)) {
              emlrtIntegerCheckR2012b(maxpeaks, &vb_emlrtDCI, sp);
            }

            n = (int32_T)maxpeaks;
            if (!((n >= 1) && (n <= i34))) {
              emlrtDynamicBoundsCheckR2012b(n, 1, i34, &we_emlrtBCI, sp);
            }
          }

          i34 = r29->size[0] * r29->size[1];
          r29->size[0] = 1;
          r29->size[1] = n - i33;
          emxEnsureCapacity(sp, (emxArray__common *)r29, i34, (int32_T)sizeof
                            (int32_T), &fd_emlrtRTEI);
          n -= i33;
          for (i34 = 0; i34 < n; i34++) {
            r29->data[r29->size[0] * i34] = i33 + i34;
          }

          i33 = Merit->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &xe_emlrtBCI, sp);
          }

          mtmp = Merit->data[0];
          n = r29->size[0] * r29->size[1];
          for (i33 = 0; i33 < n; i33++) {
            Merit->data[r29->data[i33]] = mtmp;
          }

          emxFree_int32_T(&r29);
        }
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 21);

        /* 'peaks:162' else */
        /* 'peaks:163' Pitch    = zeros(1, maxpeaks); */
        i33 = Pitch->size[0] * Pitch->size[1];
        Pitch->size[0] = 1;
        if (!(maxpeaks >= 0.0)) {
          emlrtNonNegativeCheckR2012b(maxpeaks, &ic_emlrtDCI, sp);
        }

        mtmp = maxpeaks;
        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &hc_emlrtDCI, sp);
        }

        Pitch->size[1] = (int32_T)mtmp;
        emxEnsureCapacity(sp, (emxArray__common *)Pitch, i33, (int32_T)sizeof
                          (real_T), &fd_emlrtRTEI);
        if (!(maxpeaks >= 0.0)) {
          emlrtNonNegativeCheckR2012b(maxpeaks, &ic_emlrtDCI, sp);
        }

        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &hc_emlrtDCI, sp);
        }

        n = (int32_T)mtmp;
        for (i33 = 0; i33 < n; i33++) {
          Pitch->data[i33] = 0.0;
        }

        /* 'peaks:164' Merit    = ones (1, maxpeaks); */
        i33 = Merit->size[0] * Merit->size[1];
        Merit->size[0] = 1;
        Merit->size[1] = (int32_T)maxpeaks;
        emxEnsureCapacity(sp, (emxArray__common *)Merit, i33, (int32_T)sizeof
                          (real_T), &fd_emlrtRTEI);
        n = (int32_T)maxpeaks;
        for (i33 = 0; i33 < n; i33++) {
          Merit->data[i33] = 1.0;
        }
      }
    }
  }

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (peaks.c) */
