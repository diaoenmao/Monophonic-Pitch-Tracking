/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "fix.h"
#include "mod.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo uf_emlrtRSI = { 122, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo vf_emlrtRSI = { 99, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo wf_emlrtRSI = { 81, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo xf_emlrtRSI = { 75, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo e_emlrtMCI = { 60, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo f_emlrtMCI = { 64, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRTEInfo vb_emlrtRTEI = { 1, 26, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 160, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 159, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 151, 31, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 145, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 139, 27, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 133, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo le_emlrtBCI = { 1, 100, 106, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 99, 21, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 99, 21, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtRTEInfo me_emlrtRTEI = { 98, 1, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 81, 17, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo x_emlrtDCI = { 81, 17, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 75, 16, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 75, 16, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ab_emlrtDCI = { 136, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo bb_emlrtDCI = { 137, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo pe_emlrtBCI = { 1, 100, 123, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 139, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 141, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 148, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo db_emlrtDCI = { 149, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 151, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 152, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtRSInfo fk_emlrtRSI = { 64, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo gk_emlrtRSI = { 60, "peaks",
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
  static const int32_T iv35[2] = { 1, 36 };

  const mxArray *m10;
  y = NULL;
  m10 = emlrtCreateCharArray(2, iv35);
  emlrtInitCharArrayR2013a(sp, 36, m10, &u[0]);
  emlrtAssign(&y, m10);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [37])
{
  const mxArray *y;
  static const int32_T iv36[2] = { 1, 37 };

  const mxArray *m11;
  y = NULL;
  m11 = emlrtCreateCharArray(2, iv36);
  emlrtInitCharArrayR2013a(sp, 37, m11, &u[0]);
  emlrtAssign(&y, m11);
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
           Pitch_data[], int32_T Pitch_size[2], real_T Merit_data[], int32_T
           Merit_size[2])
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

  real_T Pitch[100];
  real_T Merit[100];
  int32_T i16;
  int32_T n;
  int32_T i17;
  boolean_T b7;
  int32_T ixstart;
  int32_T b_n;
  real_T mtmp;
  boolean_T b8;
  int32_T ix;
  boolean_T exitg2;
  boolean_T b_ixstart;
  int32_T itmp;
  emxArray_real_T *b_Data;
  real_T avg_data;
  int32_T numpeaks;
  real_T c_n;
  int32_T i18;
  boolean_T b9;
  boolean_T exitg1;
  boolean_T c_ixstart;
  int32_T iidx[100];
  real_T b_Pitch[100];
  real_T b_Pitch_data[15];
  int8_T tmp_data[3];
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
  if (b_mod(width) == 0.0) {
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
    st.site = &gk_emlrtRSI;
    disp(&st, b_emlrt_marshallOut(&st, cv4), emlrt_marshallOut(1.0), &e_emlrtMCI);
  }

  /* 'peaks:62' if max_lag > (length(Data) - width) */
  if (max_lag > (real_T)Data->size[1] - width) {
    /* 'peaks:63' max_lag = length(Data) - width; */
    max_lag = (real_T)Data->size[1] - width;

    /* 'peaks:64' disp('max_lag is too high and adjusted (%d)', max_lag); */
    st.site = &fk_emlrtRSI;
    disp(&st, c_emlrt_marshallOut(&st, cv5), emlrt_marshallOut(max_lag),
         &f_emlrtMCI);
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'peaks:69' max_allow_lags = 100; */
  /* 'peaks:70' Pitch     = zeros(1, max_allow_lags); */
  /*  Peak(Pitch) candidates */
  /* 'peaks:71' Merit     = zeros(1, max_allow_lags); */
  for (i16 = 0; i16 < 100; i16++) {
    Pitch[i16] = 0.0;
    Merit[i16] = 0.0;
  }

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  /* 'peaks:75' max_data = max(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i16 = 0;
    n = 0;
  } else {
    i16 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &y_emlrtDCI, sp);
    }

    i17 = (int32_T)min_lag;
    if (!((i17 >= 1) && (i17 <= i16))) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, i16, &oe_emlrtBCI, sp);
    }

    i16 = i17 - 1;
    i17 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &y_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i17))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i17, &oe_emlrtBCI, sp);
    }
  }

  st.site = &xf_emlrtRSI;
  b_st.site = &df_emlrtRSI;
  c_st.site = &ef_emlrtRSI;
  if ((n - i16 == 1) || (n - i16 != 1)) {
    b7 = true;
  } else {
    b7 = false;
  }

  if (b7) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &ie_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (n - i16 > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &he_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &ff_emlrtRSI;
  ixstart = 1;
  b_n = n - i16;
  mtmp = Data->data[i16];
  if (n - i16 > 1) {
    if (muDoubleScalarIsNaN(mtmp)) {
      e_st.site = &hf_emlrtRSI;
      if (2 > n - i16) {
        b8 = false;
      } else {
        b8 = (n - i16 > 2147483646);
      }

      if (b8) {
        f_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= b_n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(Data->data[(i16 + ix) - 1])) {
          mtmp = Data->data[(i16 + ix) - 1];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < n - i16) {
      e_st.site = &gf_emlrtRSI;
      if (ixstart + 1 > n - i16) {
        b_ixstart = false;
      } else {
        b_ixstart = (n - i16 > 2147483646);
      }

      if (b_ixstart) {
        f_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (ix = ixstart - 1; ix + 2 <= b_n; ix++) {
        if (Data->data[(i16 + ix) + 1] > mtmp) {
          mtmp = Data->data[(i16 + ix) + 1];
        }
      }
    }
  }

  /* 'peaks:76' if (max_data > epsilon) */
  if (mtmp > 1.0E-14) {
    /* 'peaks:77' Data = Data/max_data; */
    i16 = Data->size[0] * Data->size[1];
    Data->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)Data, i16, (int32_T)sizeof(real_T),
                      &vb_emlrtRTEI);
    n = Data->size[0];
    itmp = Data->size[1];
    ixstart = n * itmp;
    for (i16 = 0; i16 < ixstart; i16++) {
      Data->data[i16] /= mtmp;
    }
  }

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  /* 'peaks:81' avg_data = mean(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i16 = 0;
    n = 0;
  } else {
    i16 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &x_emlrtDCI, sp);
    }

    i17 = (int32_T)min_lag;
    if (!((i17 >= 1) && (i17 <= i16))) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, i16, &ne_emlrtBCI, sp);
    }

    i16 = i17 - 1;
    i17 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &x_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i17))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i17, &ne_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &b_Data, 2, &vb_emlrtRTEI, true);
  i17 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = n - i16;
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, i17, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  ixstart = n - i16;
  for (i17 = 0; i17 < ixstart; i17++) {
    b_Data->data[b_Data->size[0] * i17] = Data->data[i16 + i17];
  }

  st.site = &wf_emlrtRSI;
  avg_data = mean(&st, b_Data);

  /* 'peaks:82' if (avg_data > 1/PEAK_THRESH1) */
  emxFree_real_T(&b_Data);
  if (avg_data > 0.2) {
    /*     numpeaks = 0; */
    /* 'peaks:84' Pitch    = zeros(1, maxpeaks); */
    Pitch_size[0] = 1;
    Pitch_size[1] = 4;

    /* 'peaks:85' Merit    = ones (1, maxpeaks); */
    Merit_size[0] = 1;
    Merit_size[1] = 4;
    for (i16 = 0; i16 < 4; i16++) {
      Pitch_data[i16] = 0.0;
      Merit_data[i16] = 1.0;
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
    i16 = (int32_T)(max_lag + (1.0 - min_lag));
    emlrtForLoopVectorCheckR2012b(min_lag, 1.0, max_lag, mxDOUBLE_CLASS, i16,
      &me_emlrtRTEI, sp);
    b_n = 0;
    while (b_n <= i16 - 1) {
      c_n = min_lag + (real_T)b_n;

      /* 'peaks:99' [y, lag]  = max(Data(n:(n+width-1))); */
      mtmp = (c_n + width) - 1.0;
      if (c_n > mtmp) {
        i17 = 0;
        i18 = 0;
      } else {
        i17 = Data->size[1];
        if (c_n != (int32_T)muDoubleScalarFloor(c_n)) {
          emlrtIntegerCheckR2012b(c_n, &w_emlrtDCI, sp);
        }

        n = (int32_T)c_n;
        if (!((n >= 1) && (n <= i17))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, i17, &me_emlrtBCI, sp);
        }

        i17 = n - 1;
        n = Data->size[1];
        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &w_emlrtDCI, sp);
        }

        i18 = (int32_T)mtmp;
        if (!((i18 >= 1) && (i18 <= n))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, n, &me_emlrtBCI, sp);
        }
      }

      st.site = &vf_emlrtRSI;
      b_st.site = &yf_emlrtRSI;
      c_st.site = &ag_emlrtRSI;
      if ((i18 - i17 == 1) || (i18 - i17 != 1)) {
        b7 = true;
      } else {
        b7 = false;
      }

      if (b7) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &ie_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (i18 - i17 > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &he_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &ff_emlrtRSI;
      ixstart = 2;
      n = i18 - i17;
      mtmp = Data->data[i17];
      itmp = 1;
      if (i18 - i17 > 1) {
        if (muDoubleScalarIsNaN(mtmp)) {
          e_st.site = &hf_emlrtRSI;
          if (2 > i18 - i17) {
            b9 = false;
          } else {
            b9 = (i18 - i17 > 2147483646);
          }

          if (b9) {
            f_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          ix = 2;
          exitg1 = false;
          while ((!exitg1) && (ix <= n)) {
            ixstart = ix + 1;
            if (!muDoubleScalarIsNaN(Data->data[(i17 + ix) - 1])) {
              mtmp = Data->data[(i17 + ix) - 1];
              itmp = ix;
              exitg1 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart - 1 < i18 - i17) {
          e_st.site = &gf_emlrtRSI;
          if (ixstart > i18 - i17) {
            c_ixstart = false;
          } else {
            c_ixstart = (i18 - i17 > 2147483646);
          }

          if (c_ixstart) {
            f_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while (ixstart <= n) {
            if (Data->data[(i17 + ixstart) - 1] > mtmp) {
              mtmp = Data->data[(i17 + ixstart) - 1];
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
          emlrtDynamicBoundsCheckR2012b(numpeaks, 1, 100, &le_emlrtBCI, sp);
        }

        Pitch[numpeaks - 1] = ((c_n + center) - 1.0) * delta;

        /* 'peaks:107' Merit(numpeaks)  = y; */
        Merit[numpeaks - 1] = mtmp;
      }

      b_n++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  Step 2 */
    /*  Be sure there is large peak */
    /* 'peaks:113' if (max(Merit)/avg_data < PEAK_THRESH1) */
    mtmp = Merit[0];
    for (ix = 1; ix + 1 < 101; ix++) {
      if (Merit[ix] > mtmp) {
        mtmp = Merit[ix];
      }
    }

    if (mtmp / avg_data < 5.0) {
      /*    numpeaks = 0; */
      /* 'peaks:115' Pitch      = zeros(1, maxpeaks); */
      Pitch_size[0] = 1;
      Pitch_size[1] = 4;

      /* 'peaks:116' Merit     = ones (1, maxpeaks); */
      Merit_size[0] = 1;
      Merit_size[1] = 4;
      for (i16 = 0; i16 < 4; i16++) {
        Pitch_data[i16] = 0.0;
        Merit_data[i16] = 1.0;
      }
    } else {
      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      /* 'peaks:122' [Merit, Idx] = sort(Merit, 'descend'); */
      st.site = &uf_emlrtRSI;
      b_st.site = &bg_emlrtRSI;
      sort(&b_st, Merit, iidx);

      /* 'peaks:123' Pitch = Pitch(Idx); */
      for (i16 = 0; i16 < 100; i16++) {
        if (!((iidx[i16] >= 1) && (iidx[i16] <= 100))) {
          emlrtDynamicBoundsCheckR2012b(iidx[i16], 1, 100, &pe_emlrtBCI, sp);
        }

        b_Pitch[i16] = Pitch[iidx[i16] - 1];
      }

      memcpy(&Pitch[0], &b_Pitch[0], 100U * sizeof(real_T));

      /*  keep the number of peaks not greater than max number */
      /* 'peaks:125' numpeaks = min(numpeaks, maxpeaks); */
      numpeaks = (int32_T)muDoubleScalarMin(numpeaks, 4.0);

      /* 'peaks:127' Pitch  = Pitch(1:numpeaks); */
      if (1 > numpeaks) {
        ixstart = 0;
      } else {
        ixstart = numpeaks;
      }

      Pitch_size[0] = 1;
      Pitch_size[1] = ixstart;
      for (i16 = 0; i16 < ixstart; i16++) {
        Pitch_data[i16] = Pitch[i16];
      }

      /* 'peaks:128' Merit = Merit(1:numpeaks); */
      if (1 > numpeaks) {
        n = 0;
      } else {
        n = numpeaks;
      }

      Merit_size[0] = 1;
      Merit_size[1] = n;
      for (i16 = 0; i16 < n; i16++) {
        Merit_data[i16] = Merit[i16];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      /* 'peaks:131' if (numpeaks > 0) */
      if (numpeaks > 0) {
        /*  if best peak has F < this, insert peak at 2F */
        /* 'peaks:133' if (Pitch(1) > Prm.f0_double) */
        if (!(1 <= ixstart)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, ixstart, &ke_emlrtBCI, sp);
        }

        for (i16 = 0; i16 < ixstart; i16++) {
          b_Pitch_data[i16] = Pitch[i16];
        }

        if (b_Pitch_data[0] > 150.0) {
          /* 'peaks:134' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = (int32_T)muDoubleScalarMin((real_T)numpeaks + 1.0, 4.0);

          /* 'peaks:135' if(numpeaks>length(Pitch)) */
          if (numpeaks > ixstart) {
            /* 'peaks:136' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            itmp = numpeaks - ixstart;
            if (!(itmp > 0)) {
              emlrtNonNegativeCheckR2012b(itmp, &ab_emlrtDCI, sp);
            }

            Pitch_size[1] = ixstart + itmp;
            i16 = numpeaks - ixstart;
            if (!(i16 > 0)) {
              emlrtNonNegativeCheckR2012b(i16, &ab_emlrtDCI, sp);
            }

            for (i16 = 0; i16 < itmp; i16++) {
              Pitch_data[ixstart + i16] = 0.0;
            }

            /* 'peaks:137' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            itmp = numpeaks - n;
            if (!(itmp > 0)) {
              emlrtNonNegativeCheckR2012b(itmp, &bb_emlrtDCI, sp);
            }

            Merit_size[1] = n + itmp;
            i16 = numpeaks - n;
            if (!(i16 > 0)) {
              emlrtNonNegativeCheckR2012b(i16, &bb_emlrtDCI, sp);
            }

            for (i16 = 0; i16 < itmp; i16++) {
              Merit_data[n + i16] = 0.0;
            }
          }

          /* 'peaks:139' Pitch(numpeaks) = Pitch(1)/2.0; */
          if (!(1 <= Pitch_size[1])) {
            emlrtDynamicBoundsCheckR2012b(1, 1, Pitch_size[1], &je_emlrtBCI, sp);
          }

          if (!(numpeaks <= Pitch_size[1])) {
            emlrtDynamicBoundsCheckR2012b(numpeaks, 1, Pitch_size[1],
              &qe_emlrtBCI, sp);
          }

          Pitch_data[numpeaks - 1] = Pitch_data[0] / 2.0;

          /*  Set merit for inserted peaks */
          /* 'peaks:141' Merit(numpeaks) = Prm.merit_extra; */
          if (!(numpeaks <= Merit_size[1])) {
            emlrtDynamicBoundsCheckR2012b(numpeaks, 1, Merit_size[1],
              &re_emlrtBCI, sp);
          }

          Merit_data[numpeaks - 1] = 0.4;
        }

        /*  If best peak has F > this, insert peak at half F */
        /* 'peaks:145' if (Pitch(1) < Prm.f0_half) */
        if (!(1 <= Pitch_size[1])) {
          emlrtDynamicBoundsCheckR2012b(1, 1, Pitch_size[1], &ie_emlrtBCI, sp);
        }

        if (Pitch_data[0] < 150.0) {
          /* 'peaks:146' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = (int32_T)muDoubleScalarMin((real_T)numpeaks + 1.0, 4.0);

          /* 'peaks:147' if(numpeaks>length(Pitch)) */
          if (numpeaks > Pitch_size[1]) {
            /* 'peaks:148' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            itmp = numpeaks - Pitch_size[1];
            if (!(itmp > 0)) {
              emlrtNonNegativeCheckR2012b(itmp, &cb_emlrtDCI, sp);
            }

            n = Pitch_size[1] + itmp;
            ixstart = Pitch_size[1];
            for (i16 = 0; i16 < ixstart; i16++) {
              b_Pitch_data[i16] = Pitch_data[i16];
            }

            for (i16 = 0; i16 < itmp; i16++) {
              b_Pitch_data[i16 + Pitch_size[1]] = 0.0;
            }

            Pitch_size[0] = 1;
            Pitch_size[1] = n;
            for (i16 = 0; i16 < n; i16++) {
              Pitch_data[i16] = b_Pitch_data[i16];
            }

            /* 'peaks:149' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            itmp = numpeaks - Merit_size[1];
            if (!(itmp > 0)) {
              emlrtNonNegativeCheckR2012b(itmp, &db_emlrtDCI, sp);
            }

            n = Merit_size[1] + itmp;
            ixstart = Merit_size[1];
            for (i16 = 0; i16 < ixstart; i16++) {
              b_Pitch_data[i16] = Merit_data[i16];
            }

            for (i16 = 0; i16 < itmp; i16++) {
              b_Pitch_data[i16 + Merit_size[1]] = 0.0;
            }

            Merit_size[0] = 1;
            Merit_size[1] = n;
            for (i16 = 0; i16 < n; i16++) {
              Merit_data[i16] = b_Pitch_data[i16];
            }
          }

          /* 'peaks:151' Pitch(numpeaks) = 2.0*Pitch(1); */
          if (!(1 <= Pitch_size[1])) {
            emlrtDynamicBoundsCheckR2012b(1, 1, Pitch_size[1], &he_emlrtBCI, sp);
          }

          if (!(numpeaks <= Pitch_size[1])) {
            emlrtDynamicBoundsCheckR2012b(numpeaks, 1, Pitch_size[1],
              &se_emlrtBCI, sp);
          }

          Pitch_data[numpeaks - 1] = 2.0 * Pitch_data[0];

          /* 'peaks:152' Merit(numpeaks) = Prm.merit_extra; */
          if (!(numpeaks <= Merit_size[1])) {
            emlrtDynamicBoundsCheckR2012b(numpeaks, 1, Merit_size[1],
              &te_emlrtBCI, sp);
          }

          Merit_data[numpeaks - 1] = 0.4;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        /* 'peaks:156' if (numpeaks < maxpeaks) */
        if (numpeaks < 4) {
          /* 'peaks:157' Pitch = [Pitch zeros(1,maxpeaks-numpeaks)]; */
          n = Pitch_size[1];
          itmp = 4 - numpeaks;
          Pitch_size[1] = (Pitch_size[1] - numpeaks) + 4;
          for (i16 = 0; i16 < itmp; i16++) {
            Pitch_data[n + i16] = 0.0;
          }

          /* 'peaks:158' Merit = [Merit zeros(1,maxpeaks-numpeaks)]; */
          n = Merit_size[1];
          itmp = 4 - numpeaks;
          Merit_size[1] = (Merit_size[1] - numpeaks) + 4;
          for (i16 = 0; i16 < itmp; i16++) {
            Merit_data[n + i16] = 0.0;
          }

          /* 'peaks:159' Pitch(numpeaks+1:maxpeaks)  = Pitch(1); */
          i16 = numpeaks + 1;
          if (!(i16 <= Pitch_size[1])) {
            emlrtDynamicBoundsCheckR2012b(i16, 1, Pitch_size[1], &ge_emlrtBCI,
              sp);
          }

          if (!(4 <= Pitch_size[1])) {
            emlrtDynamicBoundsCheckR2012b(4, 1, Pitch_size[1], &ge_emlrtBCI, sp);
          }

          ixstart = -numpeaks;
          for (i16 = 0; i16 <= ixstart + 3; i16++) {
            tmp_data[i16] = (int8_T)(numpeaks + i16);
          }

          mtmp = Pitch_data[0];
          ixstart = 4 - numpeaks;
          for (i16 = 0; i16 < ixstart; i16++) {
            Pitch_data[tmp_data[i16]] = mtmp;
          }

          /* 'peaks:160' Merit(numpeaks+1:maxpeaks) = Merit(1); */
          i16 = numpeaks + 1;
          if (!(i16 <= Merit_size[1])) {
            emlrtDynamicBoundsCheckR2012b(i16, 1, Merit_size[1], &fe_emlrtBCI,
              sp);
          }

          if (!(4 <= Merit_size[1])) {
            emlrtDynamicBoundsCheckR2012b(4, 1, Merit_size[1], &fe_emlrtBCI, sp);
          }

          ixstart = -numpeaks;
          for (i16 = 0; i16 <= ixstart + 3; i16++) {
            tmp_data[i16] = (int8_T)(numpeaks + i16);
          }

          mtmp = Merit_data[0];
          ixstart = 4 - numpeaks;
          for (i16 = 0; i16 < ixstart; i16++) {
            Merit_data[tmp_data[i16]] = mtmp;
          }
        }
      } else {
        /* 'peaks:162' else */
        /* 'peaks:163' Pitch    = zeros(1, maxpeaks); */
        Pitch_size[0] = 1;
        Pitch_size[1] = 4;

        /* 'peaks:164' Merit    = ones (1, maxpeaks); */
        Merit_size[0] = 1;
        Merit_size[1] = 4;
        for (i16 = 0; i16 < 4; i16++) {
          Pitch_data[i16] = 0.0;
          Merit_data[i16] = 1.0;
        }
      }
    }
  }

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (peaks.c) */
