/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * yaapt.c
 *
 * Code generation for function 'yaapt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_emxutil.h"
#include "nonlinear.h"
#include "spec_trk.h"
#include "dynamic.h"
#include "Mymedfilt1.h"
#include "sort1.h"
#include "cat.h"
#include "tm_trk.h"
#include "nlfer.h"
#include "peaks.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 120, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo b_emlrtRSI = { 125, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo c_emlrtRSI = { 128, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo d_emlrtRSI = { 133, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo e_emlrtRSI = { 137, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo f_emlrtRSI = { 143, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo g_emlrtRSI = { 146, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo h_emlrtRSI = { 149, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo i_emlrtRSI = { 153, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo ej_emlrtRSI = { 57, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo fj_emlrtRSI = { 51, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo gj_emlrtRSI = { 46, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo hj_emlrtRSI = { 45, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 37, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRTEInfo b_emlrtRTEI = { 57, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 53, 30, "Idx", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 53, 33, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 53, 13, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo emlrtECI = { -1, 53, 5, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtECInfo b_emlrtECI = { 2, 57, 13, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 64, 17, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 65, 17, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 81, 33, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 85, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 85, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 86, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 86, 30, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 101, 40, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 106, 7, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo c_emlrtECI = { -1, 106, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 107, 7, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo d_emlrtECI = { -1, 107, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 94, 39, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 94, 11, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 94, 22, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 98, 21, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 101, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 101, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 99, 39, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 99, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 99, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 62, 9, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 67, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 80, 27, "SPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 80, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 81, 21, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 86, 47, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 70, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 70, 28, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 71, 46, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 71, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 71, 28, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 73, 27, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 73, 29, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 74, 27, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 74, 29, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 53, 24, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

/* Function Declarations */
static void n_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);

/* Function Definitions */
static void n_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

/*
 * function[Pitch, numfrms, frmrate] = yaapt(Data, Fs)
 */
void yaapt(yaaptStackData *SD, const emlrtStack *sp, const emxArray_real_T *Data,
           real_T Fs, emxArray_real_T *Pitch, real_T *numfrms, real_T *frmrate)
{
  emxArray_real_T *DataB;
  emxArray_real_T *DataD;
  emxArray_real_T *BestPitch;
  real_T nFs;
  real_T y;
  real_T nframesize;
  int32_T i0;
  static const char_T varargin_1[34] = { 'F', 'r', 'a', 'm', 'e', ' ', 'l', 'e',
    'n', 'g', 't', 'h', ' ', 'v', 'a', 'l', 'u', 'e', ' ', '%', 'd', ' ', 'i',
    's', ' ', 't', 'o', 'o', ' ', 's', 'h', 'o', 'r', 't' };

  char_T u[34];
  const mxArray *b_y;
  static const int32_T iv0[2] = { 1, 34 };

  const mxArray *m0;
  static const char_T b_varargin_1[39] = { 'F', 'r', 'a', 'm', 'e', ' ', 'l',
    'e', 'n', 'g', 't', 'h', ' ', 'v', 'a', 'l', 'u', 'e', ' ', '%', 'd', ' ',
    'e', 'x', 'c', 'e', 'e', 'd', 's', ' ', 't', 'h', 'e', ' ', 'l', 'i', 'm',
    'i', 't' };

  char_T b_u[39];
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 39 };

  emxArray_real_T *Energy;
  emxArray_boolean_T *VUVEnergy;
  emxArray_real_T *b_DataD;
  int32_T loop_ub;
  emxArray_real_T *SPitch;
  emxArray_real_T *TPitch1;
  emxArray_real_T *TMerit1;
  emxArray_real_T *TPitch2;
  emxArray_real_T *TMerit2;
  emxArray_real_T *RPitch;
  emxArray_real_T *Merit;
  emxArray_real_T *Idx;
  emxArray_int32_T *iidx;
  int32_T pStd_size[1];
  real_T pStd_data[1];
  int32_T pAvg_size[1];
  real_T pAvg_data[1];
  int32_T numframes;
  int32_T maxcands;
  int32_T n;
  emxArray_real_T *r0;
  emxArray_int32_T *r1;
  emxArray_real_T *b_RPitch;
  int32_T i1;
  int32_T c_RPitch;
  int32_T b_BestPitch;
  int32_T c_BestPitch;
  int32_T iv2[1];
  int32_T d_RPitch[1];
  emxArray_real_T *e_RPitch;
  int32_T d_BestPitch[2];
  int32_T b_VUVEnergy[2];
  int32_T i;
  int32_T j;
  int32_T iv3[2];
  int32_T iv4[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &DataB, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &DataD, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &BestPitch, 2, &b_emlrtRTEI, true);

  /*  YAAPT Fundamental Frequency (Pitch) tracking */
  /*  */
  /*  [Pitch, numfrms, frmrate] = yaapt(Data, Fs, VU, ExtrPrm, fig) */
  /*    , the function is to check input parameters and invoke a number of associated routines  */
  /*    for the YAAPT pitch tracking. */
  /*  */
  /*  INPUTS:  */
  /*    Data:       Input speech raw data */
  /*    Fs:         Sampling rate of the input data */
  /*    VU:         Whether to use voiced/unvoiced decision with 1 for True and 0 for  */
  /*                False.The default is 1. */
  /*    ExtrPrm:    Extra parameters in a struct type for performance control. */
  /*                See available parameters defined in yaapt.m  */
  /*                e.g.,  */
  /*                ExtrPrm.f0_min = 60;         % Change minimum search F0 to 60Hz  */
  /*                ExtrmPrm.fft_length = 8192;  % Change FFT length to 8192 */
  /*    fig:        Whether to plot pitch tracks, spectrum, engergy, etc. The parameter */
  /*                is 1 for True and 0 for False. The default is 0.    */
  /*  */
  /*  OUTPUTS: */
  /*    Pitch:      Final pitch track in Hz. Unvoiced frames are assigned to 0s. */
  /*    numfrms:    Total number of calculated frames, or the length of */
  /*                output pitch track */
  /*    frmrate:    Frame rate of output pitch track in ms */
  /*   Creation Date:  June 2000 */
  /*   Revision date:  Jan 2, 2002 , Jan 13, 2002 Feb 19, 2002, Mar 3, 2002 */
  /*                   June 11, 2002, Jun 30, 2006, July 27, 2007 */
  /*                   May 20, 2012: Add the VU parameter for whether to use */
  /*                   voiced/unvoiced decision.  */
  /*   Authors:        Hongbing Hu, Stephen A.Zahorian */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*      This file is a part of the YAAPT program, designed for a fundamental  */
  /*    frequency tracking algorithm that is extermely robust for both high quality  */
  /*    and telephone speech.   */
  /*      The YAAPT program was created by the Speech Communication Laboratory of */
  /*    the state university of New York at Binghamton. The program is available  */
  /*    at http://www.ws.binghamton.edu/zahorian as free software. Further  */
  /*    information about the program can be found at "A spectral/temporal  */
  /*    method for robust fundamental frequency tracking," J.Acosut.Soc.Am. 123(6),  */
  /*    June 2008. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* -- PARAMETERS ---------------------------------------------------------------- */
  /*  Preliminary input arguments check */
  /* 'yaapt:49' if nargin<2 */
  /*  Default values for the tracking with voiced/unvoiced decision */
  /*  % Length of each analysis frame (ms) */
  /*  % Spacing between analysis frame (ms) */
  /*  % Minimum F0 searched (Hz) */
  /*  % Maximum F0 searached (Hz) */
  /*  % FFT length */
  /*  % Order of bandpass filter */
  /*  % Low frequency of filter passband (Hz) */
  /*  % High frequency of filter passband (Hz) */
  /*  % NLFER boundary for voiced/unvoiced decisions */
  /*  % Threshold for NLFER definitely unvocied */
  /*  % Number of harmonics in SHC calculation */
  /*  % SHC window length (Hz) */
  /*  % Maximum number of SHC peaks to be found */
  /*  % Window width in SHC peak picking (Hz) */
  /*  % Threshold 1 for SHC peak picking */
  /*  % Threshold 2 for SHC peak picking */
  /*  % F0 doubling decision threshold (Hz) */
  /*  % F0 halving decision threshold (Hz) */
  /*  % Weight used in dynaimc program */
  /*  % Factor for signal resampling */
  /*  % Threshold for considering a peak in NCCF */
  /*  % Threshold for terminating serach in NCCF */
  /*  % Maximum number of candidates found */
  /*  % Window width in NCCF peak picking */
  /*  % Boost merit */
  /*  % Merit assigned to unvoiced candidates in */
  /*  % defintely unvoiced frames */
  /*  % Merit assigned to extra candidates */
  /*  % in reducing F0 doubling/halving errors */
  /*  % Order of medial filter */
  /*  % DP weight factor for V-V transitions */
  /*  % DP weight factor for V-UV or UV-V transitions */
  /*  % DP weight factor of UV-UV transitions */
  /*  % Weight factor for local costs */
  /* 'yaapt:54' Prm = struct(... */
  /* 'yaapt:55'     'frame_length',   25, ... % Length of each analysis frame (ms) */
  /* 'yaapt:56'     'frame_space',    10, ... % Spacing between analysis frame (ms) */
  /* 'yaapt:57'     'f0_min',         60, ... % Minimum F0 searched (Hz) */
  /* 'yaapt:58'     'f0_max',        400, ... % Maximum F0 searached (Hz) */
  /* 'yaapt:59'     'fft_length',   8192, ... % FFT length */
  /* 'yaapt:60'     'bp_forder',     150, ... % Order of bandpass filter */
  /* 'yaapt:61'     'bp_low',         50, ... % Low frequency of filter passband (Hz) */
  /* 'yaapt:62'     'bp_high',      1500, ... % High frequency of filter passband (Hz) */
  /* 'yaapt:63'     'nlfer_thresh1',0.75, ... % NLFER boundary for voiced/unvoiced decisions */
  /* 'yaapt:64'     'nlfer_thresh2', 0.1, ... % Threshold for NLFER definitely unvocied */
  /* 'yaapt:65'     'shc_numharms',    3, ... % Number of harmonics in SHC calculation */
  /* 'yaapt:66'     'shc_window',     40, ... % SHC window length (Hz) */
  /* 'yaapt:67'     'shc_maxpeaks',    4, ... % Maximum number of SHC peaks to be found */
  /* 'yaapt:68'     'shc_pwidth',     50, ... % Window width in SHC peak picking (Hz) */
  /* 'yaapt:69'     'shc_thresh1',   5.0, ... % Threshold 1 for SHC peak picking */
  /* 'yaapt:70'     'shc_thresh2',  1.25, ... % Threshold 2 for SHC peak picking */
  /* 'yaapt:71'     'f0_double',     150, ... % F0 doubling decision threshold (Hz) */
  /* 'yaapt:72'     'f0_half',       150, ... % F0 halving decision threshold (Hz) */
  /* 'yaapt:73'     'dp5_k1',         11, ... % Weight used in dynaimc program */
  /* 'yaapt:74'     'dec_factor',      1, ... % Factor for signal resampling */
  /* 'yaapt:75'     'nccf_thresh1', 0.25, ... % Threshold for considering a peak in NCCF */
  /* 'yaapt:76'     'nccf_thresh2',  0.9, ... % Threshold for terminating serach in NCCF */
  /* 'yaapt:77'     'nccf_maxcands',   3, ... % Maximum number of candidates found */
  /* 'yaapt:78'     'nccf_pwidth',     5, ... % Window width in NCCF peak picking */
  /* 'yaapt:79'     'merit_boost',  0.20, ... % Boost merit */
  /* 'yaapt:80'     'merit_pivot',  0.99, ... % Merit assigned to unvoiced candidates in */
  /* 'yaapt:81'                           ... % defintely unvoiced frames */
  /* 'yaapt:82'     'merit_extra',   0.4, ... % Merit assigned to extra candidates */
  /* 'yaapt:83'                           ... % in reducing F0 doubling/halving errors */
  /* 'yaapt:84'     'median_value',    7, ... % Order of medial filter */
  /* 'yaapt:85'     'dp_w1',        0.15, ... % DP weight factor for V-V transitions */
  /* 'yaapt:86'     'dp_w2',         0.5, ... % DP weight factor for V-UV or UV-V transitions */
  /* 'yaapt:87'     'dp_w3',         0.1, ... % DP weight factor of UV-UV transitions */
  /* 'yaapt:88'     'dp_w4',         0.9, ... % Weight factor for local costs */
  /* 'yaapt:89'     'end', -1); */
  /*  Select parameter set  */
  /*  if (nargin > 2 && ~isempty(VU) && VU == 0) */
  /*      Prm = Prm_aV; */
  /*  else  */
  /*      Prm = Prm_VU; */
  /*  end */
  /*  Not needed if ignoring gross error minimization */
  /*  Overwrite parameters if they are passed from command line(ExtrPar)   */
  /*  if ((nargin > 3) && isstruct(ExtrPrm)) */
  /*      fdNames = fieldnames(ExtrPrm); */
  /*      for n = 1:length(fdNames) */
  /*          pName = char(fdNames(n)); */
  /*          Prm.(pName) = ExtrPrm.(pName); */
  /*          %message('PT:det', 'Parameter %s replaced: %d', pName,Prm.(pName)); */
  /*      end */
  /*  end */
  /* Prm */
  /*  Whether to plot pitch tracks, spectrum, engergy, etc. */
  /*  GraphPar = 0; */
  /*  if (nargin > 4 && ~isempty(fig)) */
  /*      GraphPar = fig; */
  /*  end */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Step 1. Preprocessing */
  /*   Create the squared or absolute values of filtered speech data */
  /* 'yaapt:120' [DataB, DataC, DataD, nFs] = nonlinear(Data, Fs, Prm); */
  st.site = &emlrtRSI;
  nonlinear(SD, &st, Data, Fs, DataB, BestPitch, DataD, &nFs);

  /*   Check frame size, frame jump and the number of frames for nonlinear singal */
  /* 'yaapt:123' nframesize = fix(Prm.frame_length*nFs/1000); */
  y = 25.0 * nFs / 1000.0;
  if (y < 0.0) {
    nframesize = muDoubleScalarCeil(y);
  } else {
    nframesize = muDoubleScalarFloor(y);
  }

  /* 'yaapt:124' if (nframesize < 15) */
  if (nframesize < 15.0) {
    /* 'yaapt:125' error('Frame length value %d is too short', Prm.frame_length); */
    st.site = &b_emlrtRSI;
    for (i0 = 0; i0 < 34; i0++) {
      u[i0] = varargin_1[i0];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(&st, 34, m0, &u[0]);
    emlrtAssign(&b_y, m0);
    b_st.site = &dk_emlrtRSI;
    n_error(&b_st, b_y, emlrt_marshallOut(25.0), &emlrtMCI);
  }

  /* 'yaapt:127' if (nframesize > 2048) */
  if (nframesize > 2048.0) {
    /* 'yaapt:128' error('Frame length value %d exceeds the limit', Prm.frame_length); */
    st.site = &c_emlrtRSI;
    for (i0 = 0; i0 < 39; i0++) {
      b_u[i0] = b_varargin_1[i0];
    }

    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(&st, 39, m0, &b_u[0]);
    emlrtAssign(&c_y, m0);
    b_st.site = &dk_emlrtRSI;
    n_error(&b_st, c_y, emlrt_marshallOut(25.0), &emlrtMCI);
  }

  emxInit_real_T(sp, &Energy, 2, &emlrtRTEI, true);
  emxInit_boolean_T(sp, &VUVEnergy, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_DataD, 2, &emlrtRTEI, true);

  /*   Step 2. Spectral pitch tracking */
  /*   Calculate NLFER and determine voiced/unvoiced frames with NLFER */
  /* 'yaapt:133' [Energy, VUVEnergy]= nlfer(DataB, nFs, Prm); */
  st.site = &d_emlrtRSI;
  nlfer(&st, DataB, nFs, Energy, VUVEnergy);

  /*   Calculate an approximate pitch track from the spectrum. */
  /*   At this point, SPitch is best estimate of pitch track from spectrum */
  /* 'yaapt:137' [SPitch, VUVSPitch, pAvg, pStd]= spec_trk(DataD, nFs, VUVEnergy, Prm); */
  i0 = b_DataD->size[0] * b_DataD->size[1];
  b_DataD->size[0] = 1;
  b_DataD->size[1] = DataD->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DataD, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = DataD->size[0] * DataD->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_DataD->data[i0] = DataD->data[i0];
  }

  emxInit_real_T(sp, &SPitch, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TPitch1, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TMerit1, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TPitch2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TMerit2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &RPitch, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &Merit, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &Idx, 2, &emlrtRTEI, true);
  emxInit_int32_T1(sp, &iidx, 2, &emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  spec_trk(SD, &st, b_DataD, nFs, VUVEnergy, SPitch, BestPitch, pAvg_data,
           pAvg_size, pStd_data, pStd_size);

  /*   Step 3. Temporal pitch tracking based on NCCF */
  /*   Calculate a pitch track based on time-domain processing */
  /*   Pitch tracking from the filterd original signal  */
  /* 'yaapt:143' [TPitch1, TMerit1] = tm_trk(DataB, nFs, SPitch, pStd, pAvg, Prm); */
  st.site = &f_emlrtRSI;
  tm_trk(&st, DataB, nFs, SPitch, pStd_data, pStd_size, TPitch1, TMerit1);

  /*   Pitch tracking from the filterd nonlinear signal  */
  /* 'yaapt:146' [TPitch2, TMerit2] = tm_trk(DataD, nFs, SPitch, pStd, pAvg, Prm); */
  st.site = &g_emlrtRSI;
  tm_trk(&st, DataD, nFs, SPitch, pStd_data, pStd_size, TPitch2, TMerit2);

  /*  Refine pitch candidates  */
  /* 'yaapt:149' [RPitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, ... */
  /* 'yaapt:150'                         Energy, VUVEnergy, Prm); */
  st.site = &h_emlrtRSI;

  /*  REFINE Refine pitch candidates for YAAPT Pitch tracking */
  /*  */
  /*  [Pitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, Energy, VUVEnergy, Prm) */
  /*    refins pitch cadidates obtained from NCCF using spectral pitch */
  /*    track and NLFER energy information. */
  /*  */
  /*  INPUTS:  */
  /*    TPitch1:  Pitch candidates array 1 */
  /*    TMerti1:  Merits for pitch candidates array 1 */
  /*    TPitch2:  Pitch candidates array 2 */
  /*    TMerti2:  Merits for pitch candidates array 2 */
  /*    SPitch:   Smoothed spectral pitch track */
  /*    Energy:   NLFER Energy information */
  /*    VUVEnergy: Voiced/Unvoiced information determined by NLFER energy */
  /*    Prm:      Parameters */
  /*  */
  /*  OUTPUTS: */
  /*    Pitch:   Refined overall pitch candidates */
  /*    Merit:   Merit for overall pitch candidates */
  /*    Creation: July 27 2007 */
  /*    Author:   Hongbing Hu */
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
  /*  Threshold for NLFER energy */
  /* 'refine:39' nlfer_thresh2  = Prm.nlfer_thresh2; */
  /* 'refine:40' Merit_pivot = Prm.merit_pivot; */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Merge pitch candidates and their merits from two types of the signal */
  /* 'refine:45' Pitch = cat(1,TPitch1, TPitch2); */
  b_st.site = &hj_emlrtRSI;
  cat(&b_st, TPitch1, TPitch2, RPitch);

  /* 'refine:46' Merit = cat(1,TMerit1, TMerit2); */
  b_st.site = &gj_emlrtRSI;
  cat(&b_st, TMerit1, TMerit2, Merit);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  /* 'refine:50' [maxcands, numframes] = size(Pitch); */
  numframes = RPitch->size[1] - 1;
  maxcands = RPitch->size[0];

  /* 'refine:51' [Merit, Idx] = sort(Merit, 'descend'); */
  b_st.site = &fj_emlrtRSI;
  c_st.site = &bg_emlrtRSI;
  e_sort(&c_st, Merit, iidx);
  i0 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)Idx, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = iidx->size[0] * iidx->size[1];
  emxFree_real_T(&b_DataD);
  emxFree_real_T(&TMerit2);
  emxFree_real_T(&TPitch2);
  emxFree_real_T(&TMerit1);
  emxFree_real_T(&TPitch1);
  emxFree_real_T(&DataD);
  emxFree_real_T(&DataB);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Idx->data[i0] = iidx->data[i0];
  }

  emxFree_int32_T(&iidx);

  /* 'refine:52' for n=1:numframes */
  n = 0;
  emxInit_real_T1(&st, &r0, 1, &emlrtRTEI, true);
  emxInit_int32_T(&st, &r1, 1, &emlrtRTEI, true);
  emxInit_real_T1(&st, &b_RPitch, 1, &emlrtRTEI, true);
  while (n <= numframes) {
    /* 'refine:53' Pitch(:,n) = Pitch(Idx(:,n),n); */
    loop_ub = RPitch->size[0];
    i0 = r1->size[0];
    r1->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r1->data[i0] = i0;
    }

    i0 = RPitch->size[1];
    i1 = n + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &c_emlrtBCI, &st);
    }

    loop_ub = Idx->size[0];
    i0 = Idx->size[1];
    i1 = 1 + n;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &emlrtBCI, &st);
    }

    c_RPitch = RPitch->size[0];
    i0 = RPitch->size[1];
    b_BestPitch = 1 + n;
    if (!((b_BestPitch >= 1) && (b_BestPitch <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_BestPitch, 1, i0, &b_emlrtBCI, &st);
    }

    i0 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_BestPitch = (int32_T)Idx->data[i0 + Idx->size[0] * (i1 - 1)];
      if (!((c_BestPitch >= 1) && (c_BestPitch <= c_RPitch))) {
        emlrtDynamicBoundsCheckR2012b(c_BestPitch, 1, c_RPitch, &mb_emlrtBCI,
          &st);
      }

      r0->data[i0] = RPitch->data[(c_BestPitch + RPitch->size[0] * (b_BestPitch
        - 1)) - 1];
    }

    iv2[0] = r1->size[0];
    loop_ub = Idx->size[0];
    i0 = b_RPitch->size[0];
    b_RPitch->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)b_RPitch, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_RPitch->data[i0] = RPitch->data[((int32_T)Idx->data[i0 + Idx->size[0] *
        n] + RPitch->size[0] * n) - 1];
    }

    d_RPitch[0] = b_RPitch->size[0];
    emlrtSubAssignSizeCheckR2012b(iv2, 1, d_RPitch, 1, &emlrtECI, &st);
    loop_ub = r0->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      RPitch->data[r1->data[i0] + RPitch->size[0] * n] = r0->data[i0];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxFree_real_T(&b_RPitch);
  emxFree_real_T(&r0);
  emxFree_real_T(&Idx);
  emxInit_real_T(&st, &e_RPitch, 2, &emlrtRTEI, true);

  /*  A best pitch track is generated from the best candidates */
  /* 'refine:57' BestPitch = Mymedfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  loop_ub = RPitch->size[1];
  i0 = e_RPitch->size[0] * e_RPitch->size[1];
  e_RPitch->size[0] = 1;
  e_RPitch->size[1] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)e_RPitch, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    e_RPitch->data[e_RPitch->size[0] * i0] = RPitch->data[RPitch->size[0] * i0];
  }

  b_st.site = &ej_emlrtRSI;
  c_Mymedfilt1(&b_st, e_RPitch, BestPitch);
  emxFree_real_T(&e_RPitch);
  for (i0 = 0; i0 < 2; i0++) {
    d_BestPitch[i0] = BestPitch->size[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    b_VUVEnergy[i0] = VUVEnergy->size[i0];
  }

  if ((d_BestPitch[0] != b_VUVEnergy[0]) || (d_BestPitch[1] != b_VUVEnergy[1]))
  {
    emlrtSizeEqCheckNDR2012b(&d_BestPitch[0], &b_VUVEnergy[0], &b_emlrtECI, &st);
  }

  i0 = BestPitch->size[0] * BestPitch->size[1];
  BestPitch->size[0] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)BestPitch, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  b_BestPitch = BestPitch->size[0];
  c_BestPitch = BestPitch->size[1];
  loop_ub = b_BestPitch * c_BestPitch;
  for (i0 = 0; i0 < loop_ub; i0++) {
    BestPitch->data[i0] *= (real_T)VUVEnergy->data[i0];
  }

  emxFree_boolean_T(&VUVEnergy);

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  /* 'refine:61' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'refine:62' if (Energy(i)<=nlfer_thresh2) */
    i0 = Energy->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &w_emlrtBCI, &st);
    }

    if (Energy->data[i - 1] <= 0.1) {
      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      /* 'refine:64' Pitch(:,i) = 0; */
      loop_ub = RPitch->size[0];
      c_RPitch = RPitch->size[1];
      if (!((i >= 1) && (i <= c_RPitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, c_RPitch, &d_emlrtBCI, &st);
      }

      for (i0 = 0; i0 < loop_ub; i0++) {
        RPitch->data[i0 + RPitch->size[0] * (i - 1)] = 0.0;
      }

      /* 'refine:65' Merit(:,i) = Merit_pivot; */
      loop_ub = Merit->size[0];
      b_BestPitch = Merit->size[1];
      if (!((i >= 1) && (i <= b_BestPitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, b_BestPitch, &e_emlrtBCI, &st);
      }

      for (i0 = 0; i0 < loop_ub; i0++) {
        Merit->data[i0 + Merit->size[0] * (i - 1)] = 0.99;
      }
    } else {
      /* 'refine:66' else */
      /* 'refine:67' if (Pitch(1,i) > 0) */
      i0 = RPitch->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, &x_emlrtBCI, &st);
      }

      if (RPitch->data[RPitch->size[0] * (i - 1)] > 0.0) {
        /*  already have the voiced candidate, Want to have at */
        /*  least one unvoiced candidate */
        /* 'refine:70' Pitch(maxcands,i) = 0.0; */
        i0 = RPitch->size[0];
        if (!((maxcands >= 1) && (maxcands <= i0))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i0, &db_emlrtBCI, &st);
        }

        i0 = RPitch->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, &eb_emlrtBCI, &st);
        }

        RPitch->data[(maxcands + RPitch->size[0] * (i - 1)) - 1] = 0.0;

        /* 'refine:71' Merit(maxcands,i) = (1 - Merit(1,i)) ; */
        i0 = Merit->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, &fb_emlrtBCI, &st);
        }

        i0 = Merit->size[0];
        if (!((maxcands >= 1) && (maxcands <= i0))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i0, &gb_emlrtBCI, &st);
        }

        i0 = Merit->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, &hb_emlrtBCI, &st);
        }

        Merit->data[(maxcands + Merit->size[0] * (i - 1)) - 1] = 1.0 -
          Merit->data[Merit->size[0] * (i - 1)];

        /* 'refine:72' for j = 2:maxcands-1 */
        j = 2;
        while (j - 2 <= maxcands - 3) {
          /* 'refine:73' if (Pitch(j,i) == 0) */
          i0 = RPitch->size[0];
          if (!((j >= 1) && (j <= i0))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i0, &ib_emlrtBCI, &st);
          }

          i0 = RPitch->size[1];
          if (!((i >= 1) && (i <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i0, &jb_emlrtBCI, &st);
          }

          if (RPitch->data[(j + RPitch->size[0] * (i - 1)) - 1] == 0.0) {
            /* 'refine:74' Merit(j,i) = 0.0; */
            i0 = Merit->size[0];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, &kb_emlrtBCI, &st);
            }

            i0 = Merit->size[1];
            if (!((i >= 1) && (i <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i0, &lb_emlrtBCI, &st);
            }

            Merit->data[(j + Merit->size[0] * (i - 1)) - 1] = 0.0;
          }

          j++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }
      } else {
        /* 'refine:77' else */
        /*  there was no voiced candidate from nccf fill in */
        /*  option for F0 from spectrogram */
        /* 'refine:80' Pitch(1,i)  = SPitch(i); */
        i0 = SPitch->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, &y_emlrtBCI, &st);
        }

        i0 = RPitch->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, &ab_emlrtBCI, &st);
        }

        RPitch->data[RPitch->size[0] * (i - 1)] = SPitch->data[i - 1];

        /* 'refine:81' Merit(1,i) = min(1, Energy(i)/2); */
        i0 = Energy->size[1];
        i1 = (i - 1) + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &f_emlrtBCI, &st);
        }

        i0 = Merit->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, &bb_emlrtBCI, &st);
        }

        Merit->data[Merit->size[0] * (i - 1)] = muDoubleScalarMin(1.0,
          Energy->data[i - 1] / 2.0);

        /*  all other candidates will be unvoiced */
        /*  with low merit */
        /* 'refine:85' Pitch(2:maxcands,i) = 0.0; */
        i0 = RPitch->size[0];
        i1 = maxcands;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &g_emlrtBCI, &st);
        }

        c_RPitch = RPitch->size[1];
        if (!((i >= 1) && (i <= c_RPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, c_RPitch, &h_emlrtBCI, &st);
        }

        loop_ub = maxcands - 1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          RPitch->data[(i0 + RPitch->size[0] * (i - 1)) + 1] = 0.0;
        }

        /* 'refine:86' Merit(2:maxcands,i) = 1 - Merit(1,i); */
        i0 = Merit->size[0];
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &i_emlrtBCI, &st);
        }

        b_BestPitch = Merit->size[1];
        if (!((i >= 1) && (i <= b_BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, b_BestPitch, &cb_emlrtBCI, &st);
        }

        y = Merit->data[Merit->size[0] * (i - 1)];
        b_BestPitch = Merit->size[1];
        if (!((i >= 1) && (i <= b_BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, b_BestPitch, &j_emlrtBCI, &st);
        }

        loop_ub = maxcands - 1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          Merit->data[(i0 + Merit->size[0] * (i - 1)) + 1] = 1.0 - y;
        }
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  /* 'refine:93' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'refine:94' Pitch(maxcands-1,i) = BestPitch(1,i); */
    i0 = BestPitch->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &n_emlrtBCI, &st);
    }

    i0 = RPitch->size[0];
    i1 = maxcands - 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &o_emlrtBCI, &st);
    }

    i0 = RPitch->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &p_emlrtBCI, &st);
    }

    RPitch->data[(i1 + RPitch->size[0] * (i - 1)) - 1] = BestPitch->
      data[BestPitch->size[0] * (i - 1)];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    /* 'refine:98' if (BestPitch(1,i) > 0) */
    i0 = BestPitch->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &q_emlrtBCI, &st);
    }

    if (BestPitch->data[BestPitch->size[0] * (i - 1)] > 0.0) {
      /*  voiced */
      /* 'refine:99' Merit(maxcands-1,i) = Merit(1,i); */
      i0 = Merit->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, &t_emlrtBCI, &st);
      }

      i0 = Merit->size[0];
      i1 = maxcands - 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &u_emlrtBCI, &st);
      }

      i0 = Merit->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, &v_emlrtBCI, &st);
      }

      Merit->data[(i1 + Merit->size[0] * (i - 1)) - 1] = Merit->data[Merit->
        size[0] * (i - 1)];
    } else {
      /* 'refine:100' else */
      /*  unvoiced */
      /* 'refine:101' Merit(maxcands-1,i) = 1-min(1, Energy(i)/2); */
      i0 = Energy->size[1];
      i1 = (i - 1) + 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &k_emlrtBCI, &st);
      }

      i0 = Merit->size[0];
      i1 = maxcands - 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &r_emlrtBCI, &st);
      }

      i0 = Merit->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, &s_emlrtBCI, &st);
      }

      Merit->data[(i1 + Merit->size[0] * (i - 1)) - 1] = 1.0 - muDoubleScalarMin
        (1.0, Energy->data[i - 1] / 2.0);
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /*   Copy over the SPitch array */
  /* 'refine:106' Pitch(maxcands-2,:) = SPitch; */
  i0 = RPitch->size[0];
  i1 = (int32_T)((real_T)maxcands - 2.0);
  if (!((i1 >= 1) && (i1 <= i0))) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &l_emlrtBCI, &st);
  }

  loop_ub = RPitch->size[1];
  i0 = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    r1->data[i0] = i0;
  }

  iv3[0] = 1;
  iv3[1] = r1->size[0];
  emlrtSubAssignSizeCheckR2012b(iv3, 2, *(int32_T (*)[2])SPitch->size, 2,
    &c_emlrtECI, &st);
  loop_ub = SPitch->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    RPitch->data[(maxcands + RPitch->size[0] * r1->data[i0]) - 3] = SPitch->
      data[SPitch->size[0] * i0];
  }

  emxFree_real_T(&SPitch);

  /* 'refine:107' Merit(maxcands-2,:) = Energy/5; */
  i0 = Merit->size[0];
  i1 = (int32_T)((real_T)maxcands - 2.0);
  if (!((i1 >= 1) && (i1 <= i0))) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &m_emlrtBCI, &st);
  }

  loop_ub = Merit->size[1];
  i0 = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    r1->data[i0] = i0;
  }

  i0 = BestPitch->size[0] * BestPitch->size[1];
  BestPitch->size[0] = 1;
  BestPitch->size[1] = Energy->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)BestPitch, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = Energy->size[0] * Energy->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    BestPitch->data[i0] = Energy->data[i0] / 5.0;
  }

  iv4[0] = 1;
  iv4[1] = r1->size[0];
  emlrtSubAssignSizeCheckR2012b(iv4, 2, *(int32_T (*)[2])BestPitch->size, 2,
    &d_emlrtECI, &st);
  loop_ub = BestPitch->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Merit->data[(maxcands + Merit->size[0] * r1->data[i0]) - 3] =
      BestPitch->data[BestPitch->size[0] * i0];
  }

  emxFree_int32_T(&r1);
  emxFree_real_T(&BestPitch);

  /* ============================================================================== */
  /*  Step 5. Use dyanamic programming to determine the final pitch */
  /* 'yaapt:153' Pitch  = dynamic(RPitch, Merit, Energy, Prm); */
  st.site = &i_emlrtRSI;
  dynamic(&st, RPitch, Merit, Energy, Pitch);

  /* 'yaapt:154' numfrms = length(Pitch); */
  *numfrms = Pitch->size[1];

  /* 'yaapt:155' frmrate = Prm.frame_space; */
  *frmrate = 10.0;

  /* figure(3) */
  /*  plot(SPitch, 'b') */
  /*  hold on */
  /*  plot(Pitch, 'r') */
  /*  hold off */
  /*  title ('spectral pitch track') */
  /*  pause */
  /*   If VU = 0,  be sure entire track is voiced */
  /*      if (VU == 0)      %  Only applies if we want all voiced track     */
  /*         IDX_unvoiced = (Pitch < 1); */
  /*           Num_UV       = sum (IDX_unvoiced);    % Total number unvoiced frames */
  /*            if (Num_UV > 0)  */
  /*              for n = 1:numfrms;    %  there should be a more efficient way to do this */
  /*                 if (IDX_unvoiced(n) == 1); */
  /*                   Pitch(n) = SPitch(n); */
  /*                  end;   */
  /*              end;  */
  /*            end;   */
  /*       end; */
  /*  Replace above VU = 0 section for new ptch_fix() function */
  /*  if (VU==0) */
  /*      Pitch = ptch_fix(Pitch); */
  /*  end */
  /*  Pitch = SPitch;   % to see how good spectral track is */
  /* == FIGURE ==================================================================== */
  /*   Several plots to illustrate processing and performance */
  /*  if (GraphPar)      */
  /*      pt_figs(DataB, DataD, nFs, SPitch, Energy, VUVEnergy, RPitch, Pitch, Prm); */
  /*  end */
  /* ============================================================================== */
  emxFree_real_T(&Merit);
  emxFree_real_T(&RPitch);
  emxFree_real_T(&Energy);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (yaapt.c) */
