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
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "mean.h"
#include "fix.h"
#include "mod.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo lg_emlrtRSI = { 75, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo mg_emlrtRSI = { 81, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo ng_emlrtRSI = { 99, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo og_emlrtRSI = { 113, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo pg_emlrtRSI = { 122, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo e_emlrtMCI = { 60, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo f_emlrtMCI = { 64, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRTEInfo vb_emlrtRTEI = { 1, 26, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 160, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 159, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 151, 31, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 145, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 139, 27, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 133, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { 1, 100, 106, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 99, 21, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 99, 21, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtRTEInfo we_emlrtRTEI = { 98, 1, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 81, 17, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo ab_emlrtDCI = { 81, 17, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 75, 16, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo bb_emlrtDCI = { 75, 16, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo cb_emlrtDCI = { 136, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo db_emlrtDCI = { 137, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo dd_emlrtBCI = { 1, 100, 123, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 139, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 141, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo eb_emlrtDCI = { 148, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo fb_emlrtDCI = { 149, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 151, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 152, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtRSInfo om_emlrtRSI = { 64, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo pm_emlrtRSI = { 60, "peaks",
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
  static const int32_T iv45[2] = { 1, 36 };

  const mxArray *m11;
  y = NULL;
  m11 = emlrtCreateCharArray(2, iv45);
  emlrtInitCharArrayR2013a(sp, 36, m11, &u[0]);
  emlrtAssign(&y, m11);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [37])
{
  const mxArray *y;
  static const int32_T iv46[2] = { 1, 37 };

  const mxArray *m12;
  y = NULL;
  m12 = emlrtCreateCharArray(2, iv46);
  emlrtInitCharArrayR2013a(sp, 37, m12, &u[0]);
  emlrtAssign(&y, m12);
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
void peaks(const emlrtStack *sp, emxArray_real_T *Data, real_T delta,
           emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  real_T width;
  real_T center;
  real_T min_lag;
  real_T max_lag;
  static const char_T cv4[36] = { 'm', 'i', 'n', '_', 'l', 'a', 'g', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 'l', 'o', 'w', ' ', 'a', 'n', 'd', ' ', 'a',
    'd', 'j', 'u', 's', 't', 'e', 'd', ' ', '(', '%', 'd', ')' };

  static const char_T cv5[37] = { 'm', 'a', 'x', '_', 'l', 'a', 'g', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 'h', 'i', 'g', 'h', ' ', 'a', 'n', 'd', ' ',
    'a', 'd', 'j', 'u', 's', 't', 'e', 'd', ' ', '(', '%', 'd', ')' };

  real_T b_Pitch[100];
  real_T b_Merit[100];
  int32_T i22;
  int32_T n;
  int32_T i23;
  boolean_T b8;
  int32_T ixstart;
  int32_T b_n;
  real_T mtmp;
  boolean_T b9;
  int32_T ix;
  boolean_T exitg2;
  boolean_T b_ixstart;
  emxArray_real_T *b_Data;
  emxArray_real_T *c_Data;
  real_T avg_data;
  int32_T numpeaks;
  real_T c_n;
  int32_T i24;
  int32_T itmp;
  boolean_T b10;
  boolean_T exitg1;
  boolean_T c_ixstart;
  int32_T iidx[100];
  real_T c_Pitch[100];
  emxArray_real_T *r10;
  emxArray_real_T *r11;
  emxArray_real_T *d_Pitch;
  emxArray_real_T *c_Merit;
  emxArray_real_T *r12;
  emxArray_real_T *r13;
  emxArray_int32_T *r14;
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
  width = 50.0 / delta;
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
  min_lag = 60.0 / delta - width / 4.0;
  b_fix(&min_lag);

  /*  Highest frequency at which F0 is allowed */
  /* 'peaks:56' max_lag  = fix(Prm.f0_max/delta + width/4); */
  max_lag = 400.0 / delta + width / 4.0;
  b_fix(&max_lag);

  /* 'peaks:58' if (min_lag < 1) */
  if (min_lag < 1.0) {
    /* 'peaks:59' min_lag = 1; */
    min_lag = 1.0;

    /* 'peaks:60' disp('min_lag is too low and adjusted (%d)', min_lag); */
    st.site = &pm_emlrtRSI;
    disp(&st, b_emlrt_marshallOut(&st, cv4), emlrt_marshallOut(1.0), &e_emlrtMCI);
  }

  /* 'peaks:62' if max_lag > (length(Data) - width) */
  if (max_lag > (real_T)Data->size[1] - width) {
    /* 'peaks:63' max_lag = length(Data) - width; */
    max_lag = (real_T)Data->size[1] - width;

    /* 'peaks:64' disp('max_lag is too high and adjusted (%d)', max_lag); */
    st.site = &om_emlrtRSI;
    disp(&st, c_emlrt_marshallOut(&st, cv5), emlrt_marshallOut(max_lag),
         &f_emlrtMCI);
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'peaks:69' max_allow_lags = 100; */
  /* 'peaks:70' Pitch     = zeros(1, max_allow_lags); */
  /*  Peak(Pitch) candidates */
  /* 'peaks:71' Merit     = zeros(1, max_allow_lags); */
  for (i22 = 0; i22 < 100; i22++) {
    b_Pitch[i22] = 0.0;
    b_Merit[i22] = 0.0;
  }

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  /* 'peaks:75' max_data = max(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i22 = 0;
    n = 0;
  } else {
    i22 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &bb_emlrtDCI, sp);
    }

    i23 = (int32_T)min_lag;
    if (!((i23 >= 1) && (i23 <= i22))) {
      emlrtDynamicBoundsCheckR2012b(i23, 1, i22, &cd_emlrtBCI, sp);
    }

    i22 = i23 - 1;
    i23 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &bb_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i23))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i23, &cd_emlrtBCI, sp);
    }
  }

  st.site = &lg_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  if ((n - i22 == 1) || (n - i22 != 1)) {
    b8 = true;
  } else {
    b8 = false;
  }

  if (b8) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &re_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (n - i22 > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &qe_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &gb_emlrtRSI;
  ixstart = 1;
  b_n = n - i22;
  mtmp = Data->data[i22];
  if (n - i22 > 1) {
    if (muDoubleScalarIsNaN(mtmp)) {
      e_st.site = &hb_emlrtRSI;
      if (2 > n - i22) {
        b9 = false;
      } else {
        b9 = (n - i22 > 2147483646);
      }

      if (b9) {
        f_st.site = &jb_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= b_n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(Data->data[(i22 + ix) - 1])) {
          mtmp = Data->data[(i22 + ix) - 1];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < n - i22) {
      e_st.site = &ib_emlrtRSI;
      if (ixstart + 1 > n - i22) {
        b_ixstart = false;
      } else {
        b_ixstart = (n - i22 > 2147483646);
      }

      if (b_ixstart) {
        f_st.site = &jb_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      for (ix = ixstart - 1; ix + 2 <= b_n; ix++) {
        if (Data->data[(i22 + ix) + 1] > mtmp) {
          mtmp = Data->data[(i22 + ix) + 1];
        }
      }
    }
  }

  /* 'peaks:76' if (max_data > epsilon) */
  if (mtmp > 1.0E-14) {
    emxInit_real_T(sp, &b_Data, 2, &vb_emlrtRTEI, true);

    /* 'peaks:77' Data = Data/max_data; */
    i22 = b_Data->size[0] * b_Data->size[1];
    b_Data->size[0] = 1;
    b_Data->size[1] = Data->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_Data, i22, (int32_T)sizeof
                      (real_T), &vb_emlrtRTEI);
    n = Data->size[0] * Data->size[1];
    for (i22 = 0; i22 < n; i22++) {
      b_Data->data[i22] = Data->data[i22];
    }

    c_rdivide(sp, b_Data, mtmp, Data);
    emxFree_real_T(&b_Data);
  }

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  /* 'peaks:81' avg_data = mean(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i22 = 0;
    n = 0;
  } else {
    i22 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &ab_emlrtDCI, sp);
    }

    i23 = (int32_T)min_lag;
    if (!((i23 >= 1) && (i23 <= i22))) {
      emlrtDynamicBoundsCheckR2012b(i23, 1, i22, &bd_emlrtBCI, sp);
    }

    i22 = i23 - 1;
    i23 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &ab_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i23))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i23, &bd_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &c_Data, 2, &vb_emlrtRTEI, true);
  i23 = c_Data->size[0] * c_Data->size[1];
  c_Data->size[0] = 1;
  c_Data->size[1] = n - i22;
  emxEnsureCapacity(sp, (emxArray__common *)c_Data, i23, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  n -= i22;
  for (i23 = 0; i23 < n; i23++) {
    c_Data->data[c_Data->size[0] * i23] = Data->data[i22 + i23];
  }

  st.site = &mg_emlrtRSI;
  avg_data = mean(&st, c_Data);

  /* 'peaks:82' if (avg_data > 1/PEAK_THRESH1) */
  emxFree_real_T(&c_Data);
  if (avg_data > 0.2) {
    /*     numpeaks = 0; */
    /* 'peaks:84' Pitch    = zeros(1, maxpeaks); */
    i22 = Pitch->size[0] * Pitch->size[1];
    Pitch->size[0] = 1;
    Pitch->size[1] = 4;
    emxEnsureCapacity(sp, (emxArray__common *)Pitch, i22, (int32_T)sizeof(real_T),
                      &vb_emlrtRTEI);
    for (i22 = 0; i22 < 4; i22++) {
      Pitch->data[i22] = 0.0;
    }

    /* 'peaks:85' Merit    = ones (1, maxpeaks); */
    i22 = Merit->size[0] * Merit->size[1];
    Merit->size[0] = 1;
    Merit->size[1] = 4;
    emxEnsureCapacity(sp, (emxArray__common *)Merit, i22, (int32_T)sizeof(real_T),
                      &vb_emlrtRTEI);
    for (i22 = 0; i22 < 4; i22++) {
      Merit->data[i22] = 1.0;
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
    numpeaks = 0;

    /* 'peaks:98' for n = min_lag:max_lag */
    i22 = (int32_T)(max_lag + (1.0 - min_lag));
    emlrtForLoopVectorCheckR2012b(min_lag, 1.0, max_lag, mxDOUBLE_CLASS, i22,
      &we_emlrtRTEI, sp);
    b_n = 0;
    while (b_n <= i22 - 1) {
      c_n = min_lag + (real_T)b_n;

      /* 'peaks:99' [y, lag]  = max(Data(n:(n+width-1))); */
      mtmp = (c_n + width) - 1.0;
      if (c_n > mtmp) {
        i23 = 0;
        i24 = 0;
      } else {
        i23 = Data->size[1];
        if (c_n != (int32_T)muDoubleScalarFloor(c_n)) {
          emlrtIntegerCheckR2012b(c_n, &y_emlrtDCI, sp);
        }

        n = (int32_T)c_n;
        if (!((n >= 1) && (n <= i23))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, i23, &ad_emlrtBCI, sp);
        }

        i23 = n - 1;
        n = Data->size[1];
        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &y_emlrtDCI, sp);
        }

        i24 = (int32_T)mtmp;
        if (!((i24 >= 1) && (i24 <= n))) {
          emlrtDynamicBoundsCheckR2012b(i24, 1, n, &ad_emlrtBCI, sp);
        }
      }

      st.site = &ng_emlrtRSI;
      b_st.site = &qg_emlrtRSI;
      c_st.site = &rg_emlrtRSI;
      if ((i24 - i23 == 1) || (i24 - i23 != 1)) {
        b8 = true;
      } else {
        b8 = false;
      }

      if (b8) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &re_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (i24 - i23 > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &qe_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &gb_emlrtRSI;
      ixstart = 2;
      n = i24 - i23;
      mtmp = Data->data[i23];
      itmp = 1;
      if (i24 - i23 > 1) {
        if (muDoubleScalarIsNaN(mtmp)) {
          e_st.site = &hb_emlrtRSI;
          if (2 > i24 - i23) {
            b10 = false;
          } else {
            b10 = (i24 - i23 > 2147483646);
          }

          if (b10) {
            f_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&f_st, true);
          }

          ix = 2;
          exitg1 = false;
          while ((!exitg1) && (ix <= n)) {
            ixstart = ix + 1;
            if (!muDoubleScalarIsNaN(Data->data[(i23 + ix) - 1])) {
              mtmp = Data->data[(i23 + ix) - 1];
              itmp = ix;
              exitg1 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart - 1 < i24 - i23) {
          e_st.site = &ib_emlrtRSI;
          if (ixstart > i24 - i23) {
            c_ixstart = false;
          } else {
            c_ixstart = (i24 - i23 > 2147483646);
          }

          if (c_ixstart) {
            f_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&f_st, true);
          }

          while (ixstart <= n) {
            if (Data->data[(i23 + ixstart) - 1] > mtmp) {
              mtmp = Data->data[(i23 + ixstart) - 1];
              itmp = ixstart;
            }

            ixstart++;
          }
        }
      }

      /*  find peaks which are larger than threshold    */
      /* 'peaks:101' if (lag == center) && y>(PEAK_THRESH2*avg_data) */
      if ((itmp == center) && (mtmp > 1.25 * avg_data)) {
        /*  Note Pitch(1) = delta, Pitch(2) = 2*delta */
        /*  Convert FFT indices to Pitch in Hz */
        /* 'peaks:105' numpeaks = numpeaks + 1; */
        numpeaks++;

        /* 'peaks:106' Pitch(numpeaks)  = (n+center-1)*delta; */
        if (!((numpeaks >= 1) && (numpeaks <= 100))) {
          emlrtDynamicBoundsCheckR2012b(numpeaks, 1, 100, &yc_emlrtBCI, sp);
        }

        b_Pitch[numpeaks - 1] = ((c_n + center) - 1.0) * delta;

        /* 'peaks:107' Merit(numpeaks)  = y; */
        b_Merit[numpeaks - 1] = mtmp;
      }

      b_n++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  Step 2 */
    /*  Be sure there is large peak */
    /* 'peaks:113' if (max(Merit)/avg_data < PEAK_THRESH1) */
    st.site = &og_emlrtRSI;
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    d_st.site = &gb_emlrtRSI;
    mtmp = b_Merit[0];
    e_st.site = &ib_emlrtRSI;
    for (ix = 1; ix + 1 < 101; ix++) {
      if (b_Merit[ix] > mtmp) {
        mtmp = b_Merit[ix];
      }
    }

    if (mtmp / avg_data < 5.0) {
      /*    numpeaks = 0; */
      /* 'peaks:115' Pitch      = zeros(1, maxpeaks); */
      i22 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = 4;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i22, (int32_T)sizeof
                        (real_T), &vb_emlrtRTEI);
      for (i22 = 0; i22 < 4; i22++) {
        Pitch->data[i22] = 0.0;
      }

      /* 'peaks:116' Merit     = ones (1, maxpeaks); */
      i22 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = 4;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i22, (int32_T)sizeof
                        (real_T), &vb_emlrtRTEI);
      for (i22 = 0; i22 < 4; i22++) {
        Merit->data[i22] = 1.0;
      }
    } else {
      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      /* 'peaks:122' [Merit, Idx] = sort(Merit, 'descend'); */
      st.site = &pg_emlrtRSI;
      b_st.site = &sg_emlrtRSI;
      sort(&b_st, b_Merit, iidx);

      /* 'peaks:123' Pitch = Pitch(Idx); */
      for (i22 = 0; i22 < 100; i22++) {
        if (!((iidx[i22] >= 1) && (iidx[i22] <= 100))) {
          emlrtDynamicBoundsCheckR2012b(iidx[i22], 1, 100, &dd_emlrtBCI, sp);
        }

        c_Pitch[i22] = b_Pitch[iidx[i22] - 1];
      }

      memcpy(&b_Pitch[0], &c_Pitch[0], 100U * sizeof(real_T));

      /*  keep the number of peaks not greater than max number */
      /* 'peaks:125' numpeaks = min(numpeaks, maxpeaks); */
      numpeaks = (int32_T)muDoubleScalarMin(numpeaks, 4.0);

      /* 'peaks:127' Pitch  = Pitch(1:numpeaks); */
      if (1 > numpeaks) {
        n = 0;
      } else {
        n = numpeaks;
      }

      i22 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = n;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i22, (int32_T)sizeof
                        (real_T), &vb_emlrtRTEI);
      for (i22 = 0; i22 < n; i22++) {
        Pitch->data[Pitch->size[0] * i22] = b_Pitch[i22];
      }

      /* 'peaks:128' Merit = Merit(1:numpeaks); */
      if (1 > numpeaks) {
        itmp = 0;
      } else {
        itmp = numpeaks;
      }

      i22 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = itmp;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i22, (int32_T)sizeof
                        (real_T), &vb_emlrtRTEI);
      for (i22 = 0; i22 < itmp; i22++) {
        Merit->data[Merit->size[0] * i22] = b_Merit[i22];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      /* 'peaks:131' if (numpeaks > 0) */
      if (numpeaks > 0) {
        /*  if best peak has F < this, insert peak at 2F */
        /* 'peaks:133' if (Pitch(1) > Prm.f0_double) */
        if (!(1 <= n)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, n, &xc_emlrtBCI, sp);
        }

        if (b_Pitch[0] > 150.0) {
          /* 'peaks:134' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = (int32_T)muDoubleScalarMin((real_T)numpeaks + 1.0, 4.0);

          /* 'peaks:135' if(numpeaks>length(Pitch)) */
          if (numpeaks > n) {
            emxInit_real_T(sp, &r10, 2, &vb_emlrtRTEI, true);

            /* 'peaks:136' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            ixstart = numpeaks - n;
            if (!(ixstart > 0)) {
              emlrtNonNegativeCheckR2012b(ixstart, &cb_emlrtDCI, sp);
            }

            b_n = Pitch->size[1];
            i22 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[1] = b_n + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)Pitch, i22, (int32_T)
                              sizeof(real_T), &vb_emlrtRTEI);
            n = numpeaks - n;
            if (!(n > 0)) {
              emlrtNonNegativeCheckR2012b(n, &cb_emlrtDCI, sp);
            }

            i22 = r10->size[0] * r10->size[1];
            r10->size[0] = 1;
            r10->size[1] = n;
            emxEnsureCapacity(sp, (emxArray__common *)r10, i22, (int32_T)sizeof
                              (real_T), &vb_emlrtRTEI);
            for (i22 = 0; i22 < n; i22++) {
              r10->data[r10->size[0] * i22] = 0.0;
            }

            for (i22 = 0; i22 < ixstart; i22++) {
              Pitch->data[b_n + i22] = r10->data[i22];
            }

            emxFree_real_T(&r10);
            emxInit_real_T(sp, &r11, 2, &vb_emlrtRTEI, true);

            /* 'peaks:137' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            ixstart = numpeaks - itmp;
            if (!(ixstart > 0)) {
              emlrtNonNegativeCheckR2012b(ixstart, &db_emlrtDCI, sp);
            }

            b_n = Merit->size[1];
            i22 = Merit->size[0] * Merit->size[1];
            Merit->size[1] = b_n + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)Merit, i22, (int32_T)
                              sizeof(real_T), &vb_emlrtRTEI);
            n = numpeaks - itmp;
            if (!(n > 0)) {
              emlrtNonNegativeCheckR2012b(n, &db_emlrtDCI, sp);
            }

            i22 = r11->size[0] * r11->size[1];
            r11->size[0] = 1;
            r11->size[1] = n;
            emxEnsureCapacity(sp, (emxArray__common *)r11, i22, (int32_T)sizeof
                              (real_T), &vb_emlrtRTEI);
            for (i22 = 0; i22 < n; i22++) {
              r11->data[r11->size[0] * i22] = 0.0;
            }

            for (i22 = 0; i22 < ixstart; i22++) {
              Merit->data[b_n + i22] = r11->data[i22];
            }

            emxFree_real_T(&r11);
          }

          /* 'peaks:139' Pitch(numpeaks) = Pitch(1)/2.0; */
          i22 = Pitch->size[1];
          if (!(1 <= i22)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i22, &wc_emlrtBCI, sp);
          }

          i22 = Pitch->size[1];
          if (!(numpeaks <= i22)) {
            emlrtDynamicBoundsCheckR2012b(numpeaks, 1, i22, &ed_emlrtBCI, sp);
          }

          Pitch->data[numpeaks - 1] = Pitch->data[0] / 2.0;

          /*  Set merit for inserted peaks */
          /* 'peaks:141' Merit(numpeaks) = Prm.merit_extra; */
          i22 = Merit->size[1];
          if (!(numpeaks <= i22)) {
            emlrtDynamicBoundsCheckR2012b(numpeaks, 1, i22, &fd_emlrtBCI, sp);
          }

          Merit->data[numpeaks - 1] = 0.4;
        }

        /*  If best peak has F > this, insert peak at half F */
        /* 'peaks:145' if (Pitch(1) < Prm.f0_half) */
        i22 = Pitch->size[1];
        if (!(1 <= i22)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i22, &vc_emlrtBCI, sp);
        }

        if (Pitch->data[0] < 150.0) {
          /* 'peaks:146' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = (int32_T)muDoubleScalarMin((real_T)numpeaks + 1.0, 4.0);

          /* 'peaks:147' if(numpeaks>length(Pitch)) */
          if (numpeaks > Pitch->size[1]) {
            emxInit_real_T(sp, &d_Pitch, 2, &vb_emlrtRTEI, true);

            /* 'peaks:148' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            n = Pitch->size[1];
            ixstart = numpeaks - n;
            if (!(ixstart > 0)) {
              emlrtNonNegativeCheckR2012b(ixstart, &eb_emlrtDCI, sp);
            }

            i22 = d_Pitch->size[0] * d_Pitch->size[1];
            d_Pitch->size[0] = 1;
            d_Pitch->size[1] = Pitch->size[1] + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)d_Pitch, i22, (int32_T)
                              sizeof(real_T), &vb_emlrtRTEI);
            n = Pitch->size[1];
            for (i22 = 0; i22 < n; i22++) {
              d_Pitch->data[d_Pitch->size[0] * i22] = Pitch->data[Pitch->size[0]
                * i22];
            }

            for (i22 = 0; i22 < ixstart; i22++) {
              d_Pitch->data[d_Pitch->size[0] * (i22 + Pitch->size[1])] = 0.0;
            }

            i22 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[0] = 1;
            Pitch->size[1] = d_Pitch->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)Pitch, i22, (int32_T)
                              sizeof(real_T), &vb_emlrtRTEI);
            n = d_Pitch->size[1];
            for (i22 = 0; i22 < n; i22++) {
              Pitch->data[Pitch->size[0] * i22] = d_Pitch->data[d_Pitch->size[0]
                * i22];
            }

            emxFree_real_T(&d_Pitch);
            emxInit_real_T(sp, &c_Merit, 2, &vb_emlrtRTEI, true);

            /* 'peaks:149' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            n = Merit->size[1];
            ixstart = numpeaks - n;
            if (!(ixstart > 0)) {
              emlrtNonNegativeCheckR2012b(ixstart, &fb_emlrtDCI, sp);
            }

            i22 = c_Merit->size[0] * c_Merit->size[1];
            c_Merit->size[0] = 1;
            c_Merit->size[1] = Merit->size[1] + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)c_Merit, i22, (int32_T)
                              sizeof(real_T), &vb_emlrtRTEI);
            n = Merit->size[1];
            for (i22 = 0; i22 < n; i22++) {
              c_Merit->data[c_Merit->size[0] * i22] = Merit->data[Merit->size[0]
                * i22];
            }

            for (i22 = 0; i22 < ixstart; i22++) {
              c_Merit->data[c_Merit->size[0] * (i22 + Merit->size[1])] = 0.0;
            }

            i22 = Merit->size[0] * Merit->size[1];
            Merit->size[0] = 1;
            Merit->size[1] = c_Merit->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)Merit, i22, (int32_T)
                              sizeof(real_T), &vb_emlrtRTEI);
            n = c_Merit->size[1];
            for (i22 = 0; i22 < n; i22++) {
              Merit->data[Merit->size[0] * i22] = c_Merit->data[c_Merit->size[0]
                * i22];
            }

            emxFree_real_T(&c_Merit);
          }

          /* 'peaks:151' Pitch(numpeaks) = 2.0*Pitch(1); */
          i22 = Pitch->size[1];
          if (!(1 <= i22)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i22, &uc_emlrtBCI, sp);
          }

          i22 = Pitch->size[1];
          if (!(numpeaks <= i22)) {
            emlrtDynamicBoundsCheckR2012b(numpeaks, 1, i22, &gd_emlrtBCI, sp);
          }

          Pitch->data[numpeaks - 1] = 2.0 * Pitch->data[0];

          /* 'peaks:152' Merit(numpeaks) = Prm.merit_extra; */
          i22 = Merit->size[1];
          if (!(numpeaks <= i22)) {
            emlrtDynamicBoundsCheckR2012b(numpeaks, 1, i22, &hd_emlrtBCI, sp);
          }

          Merit->data[numpeaks - 1] = 0.4;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        /* 'peaks:156' if (numpeaks < maxpeaks) */
        if (numpeaks < 4) {
          emxInit_real_T(sp, &r12, 2, &vb_emlrtRTEI, true);

          /* 'peaks:157' Pitch = [Pitch zeros(1,maxpeaks-numpeaks)]; */
          b_n = Pitch->size[1];
          n = 4 - numpeaks;
          i22 = Pitch->size[0] * Pitch->size[1];
          Pitch->size[1] = (b_n - numpeaks) + 4;
          emxEnsureCapacity(sp, (emxArray__common *)Pitch, i22, (int32_T)sizeof
                            (real_T), &vb_emlrtRTEI);
          ixstart = 4 - numpeaks;
          i22 = r12->size[0] * r12->size[1];
          r12->size[0] = 1;
          r12->size[1] = ixstart;
          emxEnsureCapacity(sp, (emxArray__common *)r12, i22, (int32_T)sizeof
                            (real_T), &vb_emlrtRTEI);
          for (i22 = 0; i22 < ixstart; i22++) {
            r12->data[r12->size[0] * i22] = 0.0;
          }

          for (i22 = 0; i22 < n; i22++) {
            Pitch->data[b_n + i22] = r12->data[i22];
          }

          emxFree_real_T(&r12);
          emxInit_real_T(sp, &r13, 2, &vb_emlrtRTEI, true);

          /* 'peaks:158' Merit = [Merit zeros(1,maxpeaks-numpeaks)]; */
          b_n = Merit->size[1];
          n = 4 - numpeaks;
          i22 = Merit->size[0] * Merit->size[1];
          Merit->size[1] = (b_n - numpeaks) + 4;
          emxEnsureCapacity(sp, (emxArray__common *)Merit, i22, (int32_T)sizeof
                            (real_T), &vb_emlrtRTEI);
          ixstart = 4 - numpeaks;
          i22 = r13->size[0] * r13->size[1];
          r13->size[0] = 1;
          r13->size[1] = ixstart;
          emxEnsureCapacity(sp, (emxArray__common *)r13, i22, (int32_T)sizeof
                            (real_T), &vb_emlrtRTEI);
          for (i22 = 0; i22 < ixstart; i22++) {
            r13->data[r13->size[0] * i22] = 0.0;
          }

          for (i22 = 0; i22 < n; i22++) {
            Merit->data[b_n + i22] = r13->data[i22];
          }

          emxFree_real_T(&r13);
          emxInit_int32_T1(sp, &r14, 2, &vb_emlrtRTEI, true);

          /* 'peaks:159' Pitch(numpeaks+1:maxpeaks)  = Pitch(1); */
          i22 = Pitch->size[1];
          if (!(numpeaks + 1 <= i22)) {
            emlrtDynamicBoundsCheckR2012b(numpeaks + 1, 1, i22, &tc_emlrtBCI, sp);
          }

          i22 = numpeaks - 4;
          i23 = Pitch->size[1];
          if (!(4 <= i23)) {
            emlrtDynamicBoundsCheckR2012b(4, 1, i23, &tc_emlrtBCI, sp);
          }

          i23 = r14->size[0] * r14->size[1];
          r14->size[0] = 1;
          r14->size[1] = -i22;
          emxEnsureCapacity(sp, (emxArray__common *)r14, i23, (int32_T)sizeof
                            (int32_T), &vb_emlrtRTEI);
          n = -i22;
          for (i23 = 0; i23 < n; i23++) {
            r14->data[r14->size[0] * i23] = (i22 + i23) + 4;
          }

          mtmp = Pitch->data[0];
          n = r14->size[0] * r14->size[1];
          for (i22 = 0; i22 < n; i22++) {
            Pitch->data[r14->data[i22]] = mtmp;
          }

          /* 'peaks:160' Merit(numpeaks+1:maxpeaks) = Merit(1); */
          i22 = Merit->size[1];
          if (!(numpeaks + 1 <= i22)) {
            emlrtDynamicBoundsCheckR2012b(numpeaks + 1, 1, i22, &sc_emlrtBCI, sp);
          }

          i22 = numpeaks - 4;
          i23 = Merit->size[1];
          if (!(4 <= i23)) {
            emlrtDynamicBoundsCheckR2012b(4, 1, i23, &sc_emlrtBCI, sp);
          }

          i23 = r14->size[0] * r14->size[1];
          r14->size[0] = 1;
          r14->size[1] = -i22;
          emxEnsureCapacity(sp, (emxArray__common *)r14, i23, (int32_T)sizeof
                            (int32_T), &vb_emlrtRTEI);
          n = -i22;
          for (i23 = 0; i23 < n; i23++) {
            r14->data[r14->size[0] * i23] = (i22 + i23) + 4;
          }

          mtmp = Merit->data[0];
          n = r14->size[0] * r14->size[1];
          for (i22 = 0; i22 < n; i22++) {
            Merit->data[r14->data[i22]] = mtmp;
          }

          emxFree_int32_T(&r14);
        }
      } else {
        /* 'peaks:162' else */
        /* 'peaks:163' Pitch    = zeros(1, maxpeaks); */
        i22 = Pitch->size[0] * Pitch->size[1];
        Pitch->size[0] = 1;
        Pitch->size[1] = 4;
        emxEnsureCapacity(sp, (emxArray__common *)Pitch, i22, (int32_T)sizeof
                          (real_T), &vb_emlrtRTEI);
        for (i22 = 0; i22 < 4; i22++) {
          Pitch->data[i22] = 0.0;
        }

        /* 'peaks:164' Merit    = ones (1, maxpeaks); */
        i22 = Merit->size[0] * Merit->size[1];
        Merit->size[0] = 1;
        Merit->size[1] = 4;
        emxEnsureCapacity(sp, (emxArray__common *)Merit, i22, (int32_T)sizeof
                          (real_T), &vb_emlrtRTEI);
        for (i22 = 0; i22 < 4; i22++) {
          Merit->data[i22] = 1.0;
        }
      }
    }
  }

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (peaks.c) */
