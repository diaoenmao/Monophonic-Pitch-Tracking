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
#include "eml_sort.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "mean.h"
#include "fix.h"
#include "mod.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo qf_emlrtRSI = { 122, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo rf_emlrtRSI = { 99, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo sf_emlrtRSI = { 81, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo tf_emlrtRSI = { 75, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo hb_emlrtMCI = { 60, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtMCInfo ib_emlrtMCI = { 64, 5, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRTEInfo cc_emlrtRTEI = { 1, 26, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 160, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 159, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 151, 31, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 145, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 139, 27, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 133, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { 1, 100, 106, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 99, 21, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 99, 21, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtRTEInfo vd_emlrtRTEI = { 98, 1, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 81, 17, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo x_emlrtDCI = { 81, 17, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 75, 16, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 75, 16, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ab_emlrtDCI = { 136, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo bb_emlrtDCI = { 137, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 139, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 141, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 148, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo db_emlrtDCI = { 149, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 151, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 152, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtRSInfo dl_emlrtRSI = { 64, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo el_emlrtRSI = { 60, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

/* Function Declarations */
static void disp(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                 emlrtMCInfo *location);

/* Function Definitions */
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
  const mxArray *y;
  static const int32_T iv45[2] = { 1, 36 };

  const mxArray *m23;
  char_T cv73[36];
  int32_T i;
  static const char_T cv74[36] = { 'm', 'i', 'n', '_', 'l', 'a', 'g', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 'l', 'o', 'w', ' ', 'a', 'n', 'd', ' ', 'a',
    'd', 'j', 'u', 's', 't', 'e', 'd', ' ', '(', '%', 'd', ')' };

  const mxArray *b_y;
  static const int32_T iv46[2] = { 1, 37 };

  char_T cv75[37];
  static const char_T cv76[37] = { 'm', 'a', 'x', '_', 'l', 'a', 'g', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 'h', 'i', 'g', 'h', ' ', 'a', 'n', 'd', ' ',
    'a', 'd', 'j', 'u', 's', 't', 'e', 'd', ' ', '(', '%', 'd', ')' };

  real_T Pitch[100];
  real_T Merit[100];
  int32_T i19;
  int32_T i20;
  int32_T loop_ub;
  boolean_T b4;
  const mxArray *c_y;
  static const int32_T iv47[2] = { 1, 36 };

  static const char_T cv77[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *d_y;
  static const int32_T iv48[2] = { 1, 39 };

  char_T cv78[39];
  static const char_T cv79[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T ixstart;
  real_T mtmp;
  boolean_T b5;
  boolean_T exitg2;
  boolean_T b_ixstart;
  emxArray_real_T *b_Data;
  real_T avg_data;
  int32_T numpeaks;
  int32_T n;
  real_T b_n;
  const mxArray *e_y;
  static const int32_T iv49[2] = { 1, 36 };

  const mxArray *f_y;
  static const int32_T iv50[2] = { 1, 39 };

  int32_T unnamed_idx_1;
  boolean_T b6;
  boolean_T exitg1;
  boolean_T c_ixstart;
  real_T b_Merit[100];
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
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
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
    y = NULL;
    m23 = emlrtCreateCharArray(2, iv45);
    for (i = 0; i < 36; i++) {
      cv73[i] = cv74[i];
    }

    emlrtInitCharArrayR2013a(sp, 36, m23, cv73);
    emlrtAssign(&y, m23);
    st.site = &el_emlrtRSI;
    disp(&st, y, emlrt_marshallOut(1.0), &hb_emlrtMCI);
  }

  /* 'peaks:62' if max_lag > (length(Data) - width) */
  if (max_lag > (real_T)Data->size[1] - width) {
    /* 'peaks:63' max_lag = length(Data) - width; */
    max_lag = (real_T)Data->size[1] - width;

    /* 'peaks:64' disp('max_lag is too high and adjusted (%d)', max_lag); */
    b_y = NULL;
    m23 = emlrtCreateCharArray(2, iv46);
    for (i = 0; i < 37; i++) {
      cv75[i] = cv76[i];
    }

    emlrtInitCharArrayR2013a(sp, 37, m23, cv75);
    emlrtAssign(&b_y, m23);
    st.site = &dl_emlrtRSI;
    disp(&st, b_y, emlrt_marshallOut(max_lag), &ib_emlrtMCI);
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'peaks:69' max_allow_lags = 100; */
  /* 'peaks:70' Pitch     = zeros(1, max_allow_lags); */
  for (i19 = 0; i19 < 100; i19++) {
    Pitch[i19] = 0.0;

    /*  Peak(Pitch) candidates */
    /* 'peaks:71' Merit     = zeros(1, max_allow_lags); */
    Merit[i19] = 0.0;
  }

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  /* 'peaks:75' max_data = max(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i19 = 0;
    i20 = 0;
  } else {
    i19 = Data->size[1];
    i20 = (int32_T)emlrtIntegerCheckFastR2012b(min_lag, &y_emlrtDCI, sp);
    i19 = emlrtDynamicBoundsCheckFastR2012b(i20, 1, i19, &se_emlrtBCI, sp) - 1;
    i20 = Data->size[1];
    loop_ub = (int32_T)emlrtIntegerCheckFastR2012b(max_lag, &y_emlrtDCI, sp);
    i20 = emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i20, &se_emlrtBCI, sp);
  }

  st.site = &tf_emlrtRSI;
  b_st.site = &ye_emlrtRSI;
  c_st.site = &af_emlrtRSI;
  if ((i20 - i19 == 1) || (i20 - i19 != 1)) {
    b4 = true;
  } else {
    b4 = false;
  }

  if (b4) {
  } else {
    c_y = NULL;
    m23 = emlrtCreateCharArray(2, iv47);
    for (i = 0; i < 36; i++) {
      cv73[i] = cv77[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m23, cv73);
    emlrtAssign(&c_y, m23);
    d_st.site = &gk_emlrtRSI;
    e_st.site = &mj_emlrtRSI;
    f_error(&d_st, b_message(&e_st, c_y, &r_emlrtMCI), &s_emlrtMCI);
  }

  if (i20 - i19 > 0) {
  } else {
    d_y = NULL;
    m23 = emlrtCreateCharArray(2, iv48);
    for (i = 0; i < 39; i++) {
      cv78[i] = cv79[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m23, cv78);
    emlrtAssign(&d_y, m23);
    d_st.site = &fk_emlrtRSI;
    e_st.site = &lj_emlrtRSI;
    f_error(&d_st, b_message(&e_st, d_y, &t_emlrtMCI), &u_emlrtMCI);
  }

  d_st.site = &bf_emlrtRSI;
  ixstart = 1;
  mtmp = Data->data[i19];
  if (i20 - i19 > 1) {
    if (muDoubleScalarIsNaN(mtmp)) {
      f_st.site = &df_emlrtRSI;
      if (2 > i20 - i19) {
        b5 = false;
      } else {
        b5 = (i20 - i19 > 2147483646);
      }

      if (b5) {
        g_st.site = &jb_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      i = 2;
      exitg2 = false;
      while ((!exitg2) && (i <= i20 - i19)) {
        ixstart = i;
        if (!muDoubleScalarIsNaN(Data->data[(i19 + i) - 1])) {
          mtmp = Data->data[(i19 + i) - 1];
          exitg2 = true;
        } else {
          i++;
        }
      }
    }

    if (ixstart < i20 - i19) {
      f_st.site = &cf_emlrtRSI;
      if (ixstart + 1 > i20 - i19) {
        b_ixstart = false;
      } else {
        b_ixstart = (i20 - i19 > 2147483646);
      }

      if (b_ixstart) {
        g_st.site = &jb_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (i = ixstart - 1; i + 2 <= i20 - i19; i++) {
        if (Data->data[(i19 + i) + 1] > mtmp) {
          mtmp = Data->data[(i19 + i) + 1];
        }
      }
    }
  }

  /* 'peaks:76' if (max_data > epsilon) */
  if (mtmp > 1.0E-14) {
    /* 'peaks:77' Data = Data/max_data; */
    i19 = Data->size[0] * Data->size[1];
    Data->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)Data, i19, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    i = Data->size[0];
    ixstart = Data->size[1];
    loop_ub = i * ixstart;
    for (i19 = 0; i19 < loop_ub; i19++) {
      Data->data[i19] /= mtmp;
    }
  }

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  /* 'peaks:81' avg_data = mean(Data(min_lag:max_lag)); */
  if (min_lag > max_lag) {
    i19 = 0;
    i20 = 0;
  } else {
    i19 = Data->size[1];
    i20 = (int32_T)emlrtIntegerCheckFastR2012b(min_lag, &x_emlrtDCI, sp);
    i19 = emlrtDynamicBoundsCheckFastR2012b(i20, 1, i19, &re_emlrtBCI, sp) - 1;
    i20 = Data->size[1];
    loop_ub = (int32_T)emlrtIntegerCheckFastR2012b(max_lag, &x_emlrtDCI, sp);
    i20 = emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i20, &re_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &b_Data, 2, &cc_emlrtRTEI, true);
  loop_ub = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = i20 - i19;
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, loop_ub, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  loop_ub = i20 - i19;
  for (i20 = 0; i20 < loop_ub; i20++) {
    b_Data->data[b_Data->size[0] * i20] = Data->data[i19 + i20];
  }

  st.site = &sf_emlrtRSI;
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
    for (i19 = 0; i19 < 4; i19++) {
      Pitch_data[i19] = 0.0;
      Merit_data[i19] = 1.0;
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
    i19 = (int32_T)(max_lag + (1.0 - min_lag));
    emlrtForLoopVectorCheckR2012b(min_lag, 1.0, max_lag, mxDOUBLE_CLASS, i19,
      &vd_emlrtRTEI, sp);
    n = 0;
    while (n <= i19 - 1) {
      b_n = min_lag + (real_T)n;

      /* 'peaks:99' [y, lag]  = max(Data(n:(n+width-1))); */
      max_lag = (b_n + width) - 1.0;
      if (b_n > max_lag) {
        i20 = 0;
        loop_ub = 0;
      } else {
        i20 = Data->size[1];
        loop_ub = (int32_T)emlrtIntegerCheckFastR2012b(b_n, &w_emlrtDCI, sp);
        i20 = emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i20, &qe_emlrtBCI,
          sp) - 1;
        loop_ub = Data->size[1];
        ixstart = (int32_T)emlrtIntegerCheckFastR2012b(max_lag, &w_emlrtDCI, sp);
        loop_ub = emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, loop_ub,
          &qe_emlrtBCI, sp);
      }

      st.site = &rf_emlrtRSI;
      b_st.site = &uf_emlrtRSI;
      c_st.site = &vf_emlrtRSI;
      if ((loop_ub - i20 == 1) || (loop_ub - i20 != 1)) {
        b4 = true;
      } else {
        b4 = false;
      }

      if (b4) {
      } else {
        e_y = NULL;
        m23 = emlrtCreateCharArray(2, iv49);
        for (i = 0; i < 36; i++) {
          cv73[i] = cv77[i];
        }

        emlrtInitCharArrayR2013a(&c_st, 36, m23, cv73);
        emlrtAssign(&e_y, m23);
        d_st.site = &gk_emlrtRSI;
        e_st.site = &mj_emlrtRSI;
        f_error(&d_st, b_message(&e_st, e_y, &r_emlrtMCI), &s_emlrtMCI);
      }

      if (loop_ub - i20 > 0) {
      } else {
        f_y = NULL;
        m23 = emlrtCreateCharArray(2, iv50);
        for (i = 0; i < 39; i++) {
          cv78[i] = cv79[i];
        }

        emlrtInitCharArrayR2013a(&c_st, 39, m23, cv78);
        emlrtAssign(&f_y, m23);
        d_st.site = &fk_emlrtRSI;
        e_st.site = &lj_emlrtRSI;
        f_error(&d_st, b_message(&e_st, f_y, &t_emlrtMCI), &u_emlrtMCI);
      }

      d_st.site = &bf_emlrtRSI;
      ixstart = 2;
      mtmp = Data->data[i20];
      unnamed_idx_1 = 1;
      if (loop_ub - i20 > 1) {
        if (muDoubleScalarIsNaN(mtmp)) {
          f_st.site = &df_emlrtRSI;
          if (2 > loop_ub - i20) {
            b6 = false;
          } else {
            b6 = (loop_ub - i20 > 2147483646);
          }

          if (b6) {
            g_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }

          i = 2;
          exitg1 = false;
          while ((!exitg1) && (i <= loop_ub - i20)) {
            ixstart = i + 1;
            if (!muDoubleScalarIsNaN(Data->data[(i20 + i) - 1])) {
              mtmp = Data->data[(i20 + i) - 1];
              unnamed_idx_1 = i;
              exitg1 = true;
            } else {
              i++;
            }
          }
        }

        if (ixstart - 1 < loop_ub - i20) {
          f_st.site = &cf_emlrtRSI;
          if (ixstart > loop_ub - i20) {
            c_ixstart = false;
          } else {
            c_ixstart = (loop_ub - i20 > 2147483646);
          }

          if (c_ixstart) {
            g_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }

          while (ixstart <= loop_ub - i20) {
            if (Data->data[(i20 + ixstart) - 1] > mtmp) {
              mtmp = Data->data[(i20 + ixstart) - 1];
              unnamed_idx_1 = ixstart;
            }

            ixstart++;
          }
        }
      }

      /*  find peaks which are larger than threshold    */
      /* 'peaks:101' if (lag == center) && y>(PEAK_THRESH2*avg_data) */
      if ((unnamed_idx_1 == center) && (mtmp > 1.25 * avg_data)) {
        /*  Note Pitch(1) = delta, Pitch(2) = 2*delta */
        /*  Convert FFT indices to Pitch in Hz */
        /* 'peaks:105' numpeaks = numpeaks + 1; */
        numpeaks++;

        /* 'peaks:106' Pitch(numpeaks)  = (n+center-1)*delta; */
        Pitch[emlrtDynamicBoundsCheckFastR2012b(numpeaks, 1, 100, &pe_emlrtBCI,
          sp) - 1] = ((b_n + center) - 1.0) * delta;

        /* 'peaks:107' Merit(numpeaks)  = y; */
        Merit[numpeaks - 1] = mtmp;
      }

      n++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    /*  Step 2 */
    /*  Be sure there is large peak */
    /* 'peaks:113' if (max(Merit)/avg_data < PEAK_THRESH1) */
    mtmp = Merit[0];
    for (i = 1; i + 1 < 101; i++) {
      if (Merit[i] > mtmp) {
        mtmp = Merit[i];
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
      for (i19 = 0; i19 < 4; i19++) {
        Pitch_data[i19] = 0.0;
        Merit_data[i19] = 1.0;
      }
    } else {
      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      /* 'peaks:122' [Merit, Idx] = sort(Merit, 'descend'); */
      st.site = &qf_emlrtRSI;
      memcpy(&b_Merit[0], &Merit[0], 100U * sizeof(real_T));
      b_st.site = &wf_emlrtRSI;
      eml_sort(b_Merit, Merit, iidx);

      /* 'peaks:123' Pitch = Pitch(Idx); */
      for (i19 = 0; i19 < 100; i19++) {
        b_Pitch[i19] = Pitch[iidx[i19] - 1];
      }

      memcpy(&Pitch[0], &b_Pitch[0], 100U * sizeof(real_T));

      /*  keep the number of peaks not greater than max number */
      /* 'peaks:125' numpeaks = min(numpeaks, maxpeaks); */
      numpeaks = (int32_T)muDoubleScalarMin(numpeaks, 4.0);

      /* 'peaks:127' Pitch  = Pitch(1:numpeaks); */
      if (1 > numpeaks) {
        loop_ub = 0;
      } else {
        loop_ub = numpeaks;
      }

      Pitch_size[0] = 1;
      Pitch_size[1] = loop_ub;
      for (i19 = 0; i19 < loop_ub; i19++) {
        Pitch_data[i19] = Pitch[i19];
      }

      /* 'peaks:128' Merit = Merit(1:numpeaks); */
      if (1 > numpeaks) {
        i = 0;
      } else {
        i = numpeaks;
      }

      Merit_size[0] = 1;
      Merit_size[1] = i;
      for (i19 = 0; i19 < i; i19++) {
        Merit_data[i19] = Merit[i19];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      /* 'peaks:131' if (numpeaks > 0) */
      if (numpeaks > 0) {
        /*  if best peak has F < this, insert peak at 2F */
        /* 'peaks:133' if (Pitch(1) > Prm.f0_double) */
        emlrtDynamicBoundsCheckFastR2012b(1, 1, loop_ub, &oe_emlrtBCI, sp);
        if (Pitch_data[0] > 150.0) {
          /* 'peaks:134' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = (int32_T)muDoubleScalarMin((real_T)numpeaks + 1.0, 4.0);

          /* 'peaks:135' if(numpeaks>length(Pitch)) */
          if (numpeaks > loop_ub) {
            /* 'peaks:136' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            i19 = numpeaks - loop_ub;
            unnamed_idx_1 = (int32_T)emlrtNonNegativeCheckFastR2012b(i19,
              &ab_emlrtDCI, sp);
            ixstart = loop_ub + unnamed_idx_1;
            for (i19 = 0; i19 < loop_ub; i19++) {
              b_Pitch_data[i19] = Pitch_data[i19];
            }

            for (i19 = 0; i19 < unnamed_idx_1; i19++) {
              b_Pitch_data[i19 + loop_ub] = 0.0;
            }

            Pitch_size[0] = 1;
            Pitch_size[1] = ixstart;
            for (i19 = 0; i19 < ixstart; i19++) {
              Pitch_data[i19] = b_Pitch_data[i19];
            }

            /* 'peaks:137' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            i19 = numpeaks - i;
            unnamed_idx_1 = (int32_T)emlrtNonNegativeCheckFastR2012b(i19,
              &bb_emlrtDCI, sp);
            ixstart = i + unnamed_idx_1;
            for (i19 = 0; i19 < i; i19++) {
              b_Pitch_data[i19] = Merit_data[i19];
            }

            for (i19 = 0; i19 < unnamed_idx_1; i19++) {
              b_Pitch_data[i19 + i] = 0.0;
            }

            Merit_size[0] = 1;
            Merit_size[1] = ixstart;
            for (i19 = 0; i19 < ixstart; i19++) {
              Merit_data[i19] = b_Pitch_data[i19];
            }
          }

          /* 'peaks:139' Pitch(numpeaks) = Pitch(1)/2.0; */
          emlrtDynamicBoundsCheckFastR2012b(1, 1, Pitch_size[1], &ne_emlrtBCI,
            sp);
          Pitch_data[emlrtDynamicBoundsCheckFastR2012b(numpeaks, 1, Pitch_size[1],
            &te_emlrtBCI, sp) - 1] = Pitch_data[0] / 2.0;

          /*  Set merit for inserted peaks */
          /* 'peaks:141' Merit(numpeaks) = Prm.merit_extra; */
          Merit_data[emlrtDynamicBoundsCheckFastR2012b(numpeaks, 1, Merit_size[1],
            &ue_emlrtBCI, sp) - 1] = 0.4;
        }

        /*  If best peak has F > this, insert peak at half F */
        /* 'peaks:145' if (Pitch(1) < Prm.f0_half) */
        emlrtDynamicBoundsCheckFastR2012b(1, 1, Pitch_size[1], &me_emlrtBCI, sp);
        if (Pitch_data[0] < 150.0) {
          /* 'peaks:146' numpeaks = min(numpeaks+1, maxpeaks); */
          numpeaks = (int32_T)muDoubleScalarMin((real_T)numpeaks + 1.0, 4.0);

          /* 'peaks:147' if(numpeaks>length(Pitch)) */
          if (numpeaks > Pitch_size[1]) {
            /* 'peaks:148' Pitch = [Pitch zeros(1,numpeaks-length(Pitch))]; */
            i19 = numpeaks - Pitch_size[1];
            unnamed_idx_1 = (int32_T)emlrtNonNegativeCheckFastR2012b(i19,
              &cb_emlrtDCI, sp);
            ixstart = Pitch_size[1] + unnamed_idx_1;
            loop_ub = Pitch_size[1];
            for (i19 = 0; i19 < loop_ub; i19++) {
              b_Pitch_data[i19] = Pitch_data[i19];
            }

            for (i19 = 0; i19 < unnamed_idx_1; i19++) {
              b_Pitch_data[i19 + Pitch_size[1]] = 0.0;
            }

            Pitch_size[0] = 1;
            Pitch_size[1] = ixstart;
            for (i19 = 0; i19 < ixstart; i19++) {
              Pitch_data[i19] = b_Pitch_data[i19];
            }

            /* 'peaks:149' Merit = [Merit zeros(1,numpeaks-length(Merit))]; */
            i19 = numpeaks - Merit_size[1];
            unnamed_idx_1 = (int32_T)emlrtNonNegativeCheckFastR2012b(i19,
              &db_emlrtDCI, sp);
            ixstart = Merit_size[1] + unnamed_idx_1;
            loop_ub = Merit_size[1];
            for (i19 = 0; i19 < loop_ub; i19++) {
              b_Pitch_data[i19] = Merit_data[i19];
            }

            for (i19 = 0; i19 < unnamed_idx_1; i19++) {
              b_Pitch_data[i19 + Merit_size[1]] = 0.0;
            }

            Merit_size[0] = 1;
            Merit_size[1] = ixstart;
            for (i19 = 0; i19 < ixstart; i19++) {
              Merit_data[i19] = b_Pitch_data[i19];
            }
          }

          /* 'peaks:151' Pitch(numpeaks) = 2.0*Pitch(1); */
          emlrtDynamicBoundsCheckFastR2012b(1, 1, Pitch_size[1], &le_emlrtBCI,
            sp);
          Pitch_data[emlrtDynamicBoundsCheckFastR2012b(numpeaks, 1, Pitch_size[1],
            &ve_emlrtBCI, sp) - 1] = 2.0 * Pitch_data[0];

          /* 'peaks:152' Merit(numpeaks) = Prm.merit_extra; */
          Merit_data[emlrtDynamicBoundsCheckFastR2012b(numpeaks, 1, Merit_size[1],
            &we_emlrtBCI, sp) - 1] = 0.4;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        /* 'peaks:156' if (numpeaks < maxpeaks) */
        if (numpeaks < 4) {
          /* 'peaks:157' Pitch = [Pitch zeros(1,maxpeaks-numpeaks)]; */
          i = Pitch_size[1];
          ixstart = 4 - numpeaks;
          Pitch_size[1] = (Pitch_size[1] - numpeaks) + 4;
          for (i19 = 0; i19 < ixstart; i19++) {
            Pitch_data[i + i19] = 0.0;
          }

          /* 'peaks:158' Merit = [Merit zeros(1,maxpeaks-numpeaks)]; */
          i = Merit_size[1];
          ixstart = 4 - numpeaks;
          Merit_size[1] = (Merit_size[1] - numpeaks) + 4;
          for (i19 = 0; i19 < ixstart; i19++) {
            Merit_data[i + i19] = 0.0;
          }

          /* 'peaks:159' Pitch(numpeaks+1:maxpeaks)  = Pitch(1); */
          i19 = numpeaks + 1;
          emlrtDynamicBoundsCheckFastR2012b(i19, 1, Pitch_size[1], &ke_emlrtBCI,
            sp);
          emlrtDynamicBoundsCheckFastR2012b(4, 1, Pitch_size[1], &ke_emlrtBCI,
            sp);
          loop_ub = -numpeaks;
          for (i19 = 0; i19 <= loop_ub + 3; i19++) {
            tmp_data[i19] = (int8_T)(numpeaks + i19);
          }

          max_lag = Pitch_data[0];
          loop_ub = 4 - numpeaks;
          for (i19 = 0; i19 < loop_ub; i19++) {
            Pitch_data[tmp_data[i19]] = max_lag;
          }

          /* 'peaks:160' Merit(numpeaks+1:maxpeaks) = Merit(1); */
          i19 = numpeaks + 1;
          emlrtDynamicBoundsCheckFastR2012b(i19, 1, Merit_size[1], &je_emlrtBCI,
            sp);
          emlrtDynamicBoundsCheckFastR2012b(4, 1, Merit_size[1], &je_emlrtBCI,
            sp);
          loop_ub = -numpeaks;
          for (i19 = 0; i19 <= loop_ub + 3; i19++) {
            tmp_data[i19] = (int8_T)(numpeaks + i19);
          }

          max_lag = Merit_data[0];
          loop_ub = 4 - numpeaks;
          for (i19 = 0; i19 < loop_ub; i19++) {
            Merit_data[tmp_data[i19]] = max_lag;
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
        for (i19 = 0; i19 < 4; i19++) {
          Pitch_data[i19] = 0.0;
          Merit_data[i19] = 1.0;
        }
      }
    }
  }

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (peaks.c) */
