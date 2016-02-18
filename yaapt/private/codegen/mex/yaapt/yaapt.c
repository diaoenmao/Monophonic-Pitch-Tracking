/*
 * yaapt.c
 *
 * Code generation for function 'yaapt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_emxutil.h"
#include "Smooth.h"
#include "freqSelect.h"
#include "path1.h"
#include "mean.h"
#include "refine.h"
#include "tm_trk.h"
#include "spec_trk.h"
#include "nlfer.h"
#include "nonlinear.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 121, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo b_emlrtRSI = { 122, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo c_emlrtRSI = { 127, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo d_emlrtRSI = { 130, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo e_emlrtRSI = { 135, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo f_emlrtRSI = { 139, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo g_emlrtRSI = { 145, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo h_emlrtRSI = { 148, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo i_emlrtRSI = { 151, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo j_emlrtRSI = { 155, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo k_emlrtRSI = { 159, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo l_emlrtRSI = { 160, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo pn_emlrtRSI = { 50, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRSInfo qn_emlrtRSI = { 96, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtRSInfo xn_emlrtRSI = { 14, "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m"
};

static emlrtRSInfo yn_emlrtRSI = { 15, "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m"
};

static emlrtRSInfo ao_emlrtRSI = { 16, "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 37, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRTEInfo b_emlrtRTEI = { 155, 1, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRTEInfo c_emlrtRTEI = { 9, 1, "Preprocess",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Preprocess.m" };

static emlrtRTEInfo d_emlrtRTEI = { 66, 1, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 80, 50, "Energy", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 80, 38, "Energy", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 75, 62, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 75, 60, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 75, 51, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 75, 49, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 49, 20, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 11, 1, "Data_temp", "Preprocess",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Preprocess.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 10, 1, "Data_temp", "Preprocess",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Preprocess.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 50, 19, "BestPitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 9, 44, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 9, 63, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 9, 80, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 9, 97, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 10, 25, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 10, 9, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 101, 23, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtDCInfo emlrtDCI = { 101, 23, "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 1 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 101, 23, "Path", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 101, 31, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 101, 3, "FinPitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 74, 24, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 74, 26, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 74, 44, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 74, 46, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 75, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 75, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 75, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 79, 23, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 79, 25, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 79, 40, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 79, 42, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 79, 60, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 79, 62, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 79, 76, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 79, 78, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 81, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 81, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 81, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 85, 24, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 85, 26, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 85, 45, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 85, 47, "Pitch", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 86, 23, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 86, 25, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 86, 27, "Trans", "dynamic",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m", 0 };

/* Function Declarations */
static void o_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);

/* Function Definitions */
static void o_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

/*
 * function[Pitch, numfrms, frmrate] = yaapt(Data, Fs, Parameter)
 */
void yaapt(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs, const
           real_T Parameter[34], emxArray_real_T *Pitch, real_T *numfrms, real_T
           *frmrate)
{
  emxArray_real_T *Data_temp;
  int32_T i0;
  int32_T loop_ub;
  int32_T b_Data;
  int32_T end;
  emxArray_int32_T *r0;
  emxArray_real_T *Pitch_before;
  emxArray_real_T *DataB;
  emxArray_real_T *DataD;
  real_T nFs;
  real_T y;
  real_T nframesize;
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

  emxArray_boolean_T *VUVEnergy;
  emxArray_real_T *b_DataD;
  struct_T expl_temp;
  emxArray_real_T *VUVSPitch;
  emxArray_real_T *pAvg;
  emxArray_real_T *pStd;
  emxArray_real_T *TPitch1;
  emxArray_real_T *TMerit1;
  emxArray_real_T *TPitch2;
  emxArray_real_T *TMerit2;
  emxArray_real_T *RPitch;
  emxArray_real_T *Merit;
  int32_T numframes;
  int32_T numcands;
  emxArray_real_T *b_RPitch;
  emxArray_real_T *c_RPitch;
  emxArray_real_T *Trans;
  real_T mean_pitch;
  int32_T j;
  int32_T k;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  emxArray_real_T *r1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Data_temp, 2, &c_emlrtRTEI, true);

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
  /*  % Order of bandpass filter (even) */
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
  /*  % Threshold of smoothing chunks */
  /* 'yaapt:54' Prm = struct(... */
  /* 'yaapt:55'     'frame_length',   Parameter(1), ... % Length of each analysis frame (ms) */
  /* 'yaapt:56'     'frame_space',    Parameter(2), ... % Spacing between analysis frame (ms) */
  /* 'yaapt:57'     'f0_min',         Parameter(3), ... % Minimum F0 searched (Hz) */
  /* 'yaapt:58'     'f0_max',        Parameter(4), ... % Maximum F0 searached (Hz) */
  /* 'yaapt:59'     'fft_length',   Parameter(5), ... % FFT length */
  /* 'yaapt:60'     'bp_forder',     Parameter(6), ... % Order of bandpass filter (even) */
  /* 'yaapt:61'     'bp_low',         Parameter(7), ... % Low frequency of filter passband (Hz) */
  /* 'yaapt:62'     'bp_high',      Parameter(8), ... % High frequency of filter passband (Hz) */
  /* 'yaapt:63'     'nlfer_thresh1',Parameter(9), ... % NLFER boundary for voiced/unvoiced decisions */
  /* 'yaapt:64'     'nlfer_thresh2', Parameter(10), ... % Threshold for NLFER definitely unvocied */
  /* 'yaapt:65'     'shc_numharms',    Parameter(11), ... % Number of harmonics in SHC calculation */
  /* 'yaapt:66'     'shc_window',     Parameter(12), ... % SHC window length (Hz) */
  /* 'yaapt:67'     'shc_maxpeaks',    Parameter(13), ... % Maximum number of SHC peaks to be found */
  /* 'yaapt:68'     'shc_pwidth',     Parameter(14), ... % Window width in SHC peak picking (Hz) */
  /* 'yaapt:69'     'shc_thresh1',   Parameter(15), ... % Threshold 1 for SHC peak picking */
  /* 'yaapt:70'     'shc_thresh2',  Parameter(16), ... % Threshold 2 for SHC peak picking */
  /* 'yaapt:71'     'f0_double',     Parameter(17), ... % F0 doubling decision threshold (Hz) */
  /* 'yaapt:72'     'f0_half',       Parameter(18), ... % F0 halving decision threshold (Hz) */
  /* 'yaapt:73'     'dp5_k1',         Parameter(19), ... % Weight used in dynaimc program */
  /* 'yaapt:74'     'dec_factor',      Parameter(20), ... % Factor for signal resampling */
  /* 'yaapt:75'     'nccf_thresh1', Parameter(21), ... % Threshold for considering a peak in NCCF */
  /* 'yaapt:76'     'nccf_thresh2',  Parameter(22), ... % Threshold for terminating serach in NCCF */
  /* 'yaapt:77'     'nccf_maxcands',   Parameter(23), ... % Maximum number of candidates found */
  /* 'yaapt:78'     'nccf_pwidth',     Parameter(24), ... % Window width in NCCF peak picking */
  /* 'yaapt:79'     'merit_boost',  Parameter(25), ... % Boost merit */
  /* 'yaapt:80'     'merit_pivot',  Parameter(26), ... % Merit assigned to unvoiced candidates in */
  /* 'yaapt:81'                           ... % defintely unvoiced frames */
  /* 'yaapt:82'     'merit_extra',   Parameter(27), ... % Merit assigned to extra candidates */
  /* 'yaapt:83'                           ... % in reducing F0 doubling/halving errors */
  /* 'yaapt:84'     'median_value',    Parameter(28), ... % Order of medial filter */
  /* 'yaapt:85'     'dp_w1',        Parameter(29), ... % DP weight factor for V-V transitions */
  /* 'yaapt:86'     'dp_w2',         Parameter(30), ... % DP weight factor for V-UV or UV-V transitions */
  /* 'yaapt:87'     'dp_w3',         Parameter(31), ... % DP weight factor of UV-UV transitions */
  /* 'yaapt:88'     'dp_w4',         Parameter(32), ... % Weight factor for local costs */
  /* 'yaapt:89'     'smooth_threshold', Parameter(33), ... % Threshold of smoothing chunks */
  /* 'yaapt:90'     'end', Parameter(34)); */
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
  /* 'yaapt:121' Data_after = Preprocess(Data); */
  st.site = &emlrtRSI;

  /*  Preprocess the raw data from android voice recorder */
  /*  */
  /*  Data_in = Raw data android voice recorder */
  /*  Data_out = Head and tail muted data */
  /*  The noise comes from opening mic and closing mic */
  /* 'Preprocess:7' head_muted_length = 600; */
  /* 'Preprocess:8' tail_muted_length = 2000; */
  /* 'Preprocess:9' Data_temp = Data_in; */
  i0 = Data_temp->size[0] * Data_temp->size[1];
  Data_temp->size[0] = 1;
  Data_temp->size[1] = Data->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Data_temp, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = Data->size[0] * Data->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Data_temp->data[i0] = Data->data[i0];
  }

  /* 'Preprocess:10' Data_temp(1:head_muted_length)=0; */
  b_Data = Data->size[1];
  for (i0 = 0; i0 < 600; i0++) {
    end = 1 + i0;
    if (!(end <= b_Data)) {
      emlrtDynamicBoundsCheckR2012b(end, 1, b_Data, &i_emlrtBCI, &st);
    }

    Data_temp->data[end - 1] = 0.0;
  }

  /* 'Preprocess:11' Data_temp(end-tail_muted_length:end)=0; */
  if (Data_temp->size[1] - 2000 > Data_temp->size[1]) {
    i0 = 0;
    b_Data = 0;
  } else {
    i0 = Data_temp->size[1];
    end = Data_temp->size[1] - 2000;
    if (!((end >= 1) && (end <= i0))) {
      emlrtDynamicBoundsCheckR2012b(end, 1, i0, &h_emlrtBCI, &st);
    }

    i0 = end - 1;
    end = Data_temp->size[1];
    b_Data = Data_temp->size[1];
    if (!((b_Data >= 1) && (b_Data <= end))) {
      emlrtDynamicBoundsCheckR2012b(b_Data, 1, end, &h_emlrtBCI, &st);
    }
  }

  emxInit_int32_T(&st, &r0, 2, &emlrtRTEI, true);
  end = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = b_Data - i0;
  emxEnsureCapacity(&st, (emxArray__common *)r0, end, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = b_Data - i0;
  for (end = 0; end < loop_ub; end++) {
    r0->data[r0->size[0] * end] = i0 + end;
  }

  loop_ub = r0->size[0] * r0->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Data_temp->data[r0->data[i0]] = 0.0;
  }

  emxInit_real_T(&st, &Pitch_before, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &DataB, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &DataD, 2, &emlrtRTEI, true);

  /* 'Preprocess:12' Data_out = Data_temp; */
  /* 'yaapt:122' [DataB, DataC, DataD, nFs] = nonlinear(Data_after, Fs, Prm); */
  st.site = &b_emlrtRSI;
  nonlinear(&st, Data_temp, Fs, Parameter[5], Parameter[6], Parameter[7],
            Parameter[19], DataB, Pitch_before, DataD, &nFs);

  /*   Check frame size, frame jump and the number of frames for nonlinear singal */
  /* 'yaapt:125' nframesize = fix(Prm.frame_length*nFs/1000); */
  y = Parameter[0] * nFs / 1000.0;
  if (y < 0.0) {
    nframesize = muDoubleScalarCeil(y);
  } else {
    nframesize = muDoubleScalarFloor(y);
  }

  /* 'yaapt:126' if (nframesize < 15) */
  if (nframesize < 15.0) {
    /* 'yaapt:127' error('Frame length value %d is too short', Prm.frame_length); */
    st.site = &c_emlrtRSI;
    for (i0 = 0; i0 < 34; i0++) {
      u[i0] = varargin_1[i0];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(&st, 34, m0, &u[0]);
    emlrtAssign(&b_y, m0);
    b_st.site = &ho_emlrtRSI;
    o_error(&b_st, b_y, emlrt_marshallOut(Parameter[0]), &emlrtMCI);
  }

  /* 'yaapt:129' if (nframesize > 2048) */
  if (nframesize > 2048.0) {
    /* 'yaapt:130' error('Frame length value %d exceeds the limit', Prm.frame_length); */
    st.site = &d_emlrtRSI;
    for (i0 = 0; i0 < 39; i0++) {
      b_u[i0] = b_varargin_1[i0];
    }

    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(&st, 39, m0, &b_u[0]);
    emlrtAssign(&c_y, m0);
    b_st.site = &ho_emlrtRSI;
    o_error(&b_st, c_y, emlrt_marshallOut(Parameter[0]), &emlrtMCI);
  }

  emxInit_boolean_T(sp, &VUVEnergy, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_DataD, 2, &emlrtRTEI, true);

  /*   Step 2. Spectral pitch tracking */
  /*   Calculate NLFER and determine voiced/unvoiced frames with NLFER */
  /* 'yaapt:135' [Energy, VUVEnergy]= nlfer(DataB, nFs, Prm); */
  st.site = &e_emlrtRSI;
  nlfer(&st, DataB, nFs, Parameter[0], Parameter[1], Parameter[2], Parameter[3],
        Parameter[4], Parameter[8], Data_temp, VUVEnergy);

  /*   Calculate an approximate pitch track from the spectrum. */
  /*   At this point, SPitch is best estimate of pitch track from spectrum */
  /* 'yaapt:139' [SPitch, VUVSPitch, pAvg, pStd]= spec_trk(DataD, nFs, VUVEnergy, Prm); */
  expl_temp.end = Parameter[33];
  expl_temp.smooth_threshold = Parameter[32];
  expl_temp.dp_w4 = Parameter[31];
  expl_temp.dp_w3 = Parameter[30];
  expl_temp.dp_w2 = Parameter[29];
  expl_temp.dp_w1 = Parameter[28];
  expl_temp.median_value = Parameter[27];
  expl_temp.merit_extra = Parameter[26];
  expl_temp.merit_pivot = Parameter[25];
  expl_temp.merit_boost = Parameter[24];
  expl_temp.nccf_pwidth = Parameter[23];
  expl_temp.nccf_maxcands = Parameter[22];
  expl_temp.nccf_thresh2 = Parameter[21];
  expl_temp.nccf_thresh1 = Parameter[20];
  expl_temp.dec_factor = Parameter[19];
  expl_temp.dp5_k1 = Parameter[18];
  expl_temp.f0_half = Parameter[17];
  expl_temp.f0_double = Parameter[16];
  expl_temp.shc_thresh2 = Parameter[15];
  expl_temp.shc_thresh1 = Parameter[14];
  expl_temp.shc_pwidth = Parameter[13];
  expl_temp.shc_maxpeaks = Parameter[12];
  expl_temp.shc_window = Parameter[11];
  expl_temp.shc_numharms = Parameter[10];
  expl_temp.nlfer_thresh2 = Parameter[9];
  expl_temp.nlfer_thresh1 = Parameter[8];
  expl_temp.bp_high = Parameter[7];
  expl_temp.bp_low = Parameter[6];
  expl_temp.bp_forder = Parameter[5];
  expl_temp.fft_length = Parameter[4];
  expl_temp.f0_max = Parameter[3];
  expl_temp.f0_min = Parameter[2];
  expl_temp.frame_space = Parameter[1];
  expl_temp.frame_length = Parameter[0];
  i0 = b_DataD->size[0] * b_DataD->size[1];
  b_DataD->size[0] = 1;
  b_DataD->size[1] = DataD->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DataD, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = DataD->size[0] * DataD->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_DataD->data[i0] = DataD->data[i0];
  }

  emxInit_real_T(sp, &VUVSPitch, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &pAvg, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &pStd, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &TPitch1, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TMerit1, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TPitch2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TMerit2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &RPitch, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &Merit, 2, &emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  spec_trk(&st, b_DataD, nFs, VUVEnergy, &expl_temp, Pitch_before, VUVSPitch,
           pAvg, pStd);

  /*   Step 3. Temporal pitch tracking based on NCCF */
  /*   Calculate a pitch track based on time-domain processing */
  /*   Pitch tracking from the filterd original signal  */
  /* 'yaapt:145' [TPitch1, TMerit1] = tm_trk(DataB, nFs, SPitch, pStd, pAvg, Prm); */
  st.site = &g_emlrtRSI;
  tm_trk(&st, DataB, nFs, Pitch_before, pStd, Parameter[0], Parameter[1],
         Parameter[2], Parameter[3], Parameter[20], Parameter[21], Parameter[22],
         Parameter[23], Parameter[24], TPitch1, TMerit1);

  /*   Pitch tracking from the filterd nonlinear signal  */
  /* 'yaapt:148' [TPitch2, TMerit2] = tm_trk(DataD, nFs, SPitch, pStd, pAvg, Prm); */
  st.site = &h_emlrtRSI;
  tm_trk(&st, DataD, nFs, Pitch_before, pStd, Parameter[0], Parameter[1],
         Parameter[2], Parameter[3], Parameter[20], Parameter[21], Parameter[22],
         Parameter[23], Parameter[24], TPitch2, TMerit2);

  /*  Refine pitch candidates  */
  /* 'yaapt:151' [RPitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, ... */
  /* 'yaapt:152'                         Energy, VUVEnergy, Prm); */
  st.site = &i_emlrtRSI;
  refine(&st, TPitch1, TMerit1, TPitch2, TMerit2, Pitch_before, Data_temp,
         VUVEnergy, Parameter[9], Parameter[25], Parameter[27], RPitch, Merit);

  /*  Step 5. Use dyanamic programming to determine the final pitch */
  /* 'yaapt:155' Pitch_before  = dynamic(RPitch, Merit, Energy, Prm); */
  st.site = &j_emlrtRSI;

  /* DYNAMIC Dynamic programming for YAAPT pitch tracking */
  /*  */
  /*  [FinPitch] = dynamic(Pitch, Merit, Energy, Prm) is used */
  /*  to compute Local and Transition cost matrices */
  /*  to enable lowest cost tracking of pitch candidates; */
  /*  It uses NFLER from the spectrogram and the highly robust */
  /*  spectral F0 track, plus the merits, for */
  /*  computation of the cost matrices. */
  /*  */
  /* INPUTS:  */
  /*    Pitch:  Pitch array with elements arranged so that lowest */
  /*                       index correponds to  highest merit */
  /*    Merit:  Merit array with elements arranged as for pitch */
  /*    Energy: NLFER energy ratio from the low frequency regions of spectrogram. */
  /*    Prm:    Array of parameters used to control performance */
  /*  */
  /* OUTPUTS:   */
  /*    FinPitch: The final pitch track for the entire utterance pitch */
  /*    values are in HZ.Unvoiced frames are assigned 0. */
  /*  Note:   This routine is intended for more through testing of */
  /*     some thresholds used in dynamic6.   All the dp constants are */
  /*     set to fixed values that worked well in testing */
  /*     then the dp constants are used to specify the thresholds and other */
  /*      constants */
  /*    Creation date:   Spring 2001 */
  /*    Revision date:   January 3, 2002   June 16, 2007, July 27, 2007 */
  /*    Programmers: S. Zahorian,Kavita Kasi, Lingyun Gu, Hongbing Hu */
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
  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'dynamic:46' [numcands, numframes] = size(Pitch); */
  numframes = RPitch->size[1] - 1;
  numcands = RPitch->size[0] - 1;

  /* Copy some arrays */
  /* 'dynamic:49' BestPitch  = Pitch(numcands-1,:); */
  i0 = RPitch->size[0];
  end = (int32_T)((real_T)RPitch->size[0] - 1.0);
  if (!((end >= 1) && (end <= i0))) {
    emlrtDynamicBoundsCheckR2012b(end, 1, i0, &g_emlrtBCI, &st);
  }

  /* 'dynamic:50' mean_pitch = mean(BestPitch(BestPitch>0)); */
  end = RPitch->size[1] - 1;
  b_Data = 0;
  emxFree_real_T(&b_DataD);
  emxFree_real_T(&TMerit2);
  emxFree_real_T(&TPitch2);
  emxFree_real_T(&TMerit1);
  emxFree_real_T(&TPitch1);
  emxFree_real_T(&pStd);
  emxFree_real_T(&pAvg);
  emxFree_boolean_T(&VUVEnergy);
  emxFree_real_T(&DataD);
  emxFree_real_T(&DataB);
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if (RPitch->data[(numcands + RPitch->size[0] * loop_ub) - 1] > 0.0) {
      b_Data++;
    }
  }

  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = b_Data;
  emxEnsureCapacity(&st, (emxArray__common *)r0, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  b_Data = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if (RPitch->data[(numcands + RPitch->size[0] * loop_ub) - 1] > 0.0) {
      r0->data[b_Data] = loop_ub + 1;
      b_Data++;
    }
  }

  emxInit_real_T(&st, &b_RPitch, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &c_RPitch, 2, &emlrtRTEI, true);
  i0 = RPitch->size[1];
  loop_ub = RPitch->size[1];
  b_Data = RPitch->size[0];
  end = c_RPitch->size[0] * c_RPitch->size[1];
  c_RPitch->size[0] = 1;
  c_RPitch->size[1] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)c_RPitch, end, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  for (end = 0; end < loop_ub; end++) {
    c_RPitch->data[c_RPitch->size[0] * end] = RPitch->data[(b_Data +
      RPitch->size[0] * end) - 2];
  }

  end = b_RPitch->size[0] * b_RPitch->size[1];
  b_RPitch->size[0] = 1;
  b_RPitch->size[1] = r0->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_RPitch, end, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = r0->size[1];
  for (end = 0; end < loop_ub; end++) {
    b_Data = r0->data[r0->size[0] * end];
    if (!((b_Data >= 1) && (b_Data <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_Data, 1, i0, &j_emlrtBCI, &st);
    }

    b_RPitch->data[b_RPitch->size[0] * end] = c_RPitch->data[b_Data - 1];
  }

  emxFree_real_T(&c_RPitch);
  emxFree_int32_T(&r0);
  emxInit_real_T2(&st, &Trans, 3, &d_emlrtRTEI, true);
  b_st.site = &pn_emlrtRSI;
  mean_pitch = mean(&b_st, b_RPitch);

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* 'dynamic:55' dp_w1 = Prm.dp_w1; */
  /* 'dynamic:56' dp_w2 = Prm.dp_w2; */
  /* 'dynamic:57' dp_w3 = Prm.dp_w3; */
  /* 'dynamic:58' dp_w4 = Prm.dp_w4; */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Forming the local cost matrix */
  /* 'dynamic:63' Local = 1 - Merit; */
  /*  Initialization for the formation of the transition cost matrix */
  /* 'dynamic:66' Trans  = ones(numcands,numcands,numframes); */
  i0 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = RPitch->size[0];
  Trans->size[1] = RPitch->size[0];
  Trans->size[2] = RPitch->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Trans, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = RPitch->size[0] * RPitch->size[0] * RPitch->size[1];
  emxFree_real_T(&b_RPitch);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Trans->data[i0] = 1.0;
  }

  /*  The transition cost matrix is proportional to frequency differences */
  /*  between successive candidates. */
  /* 'dynamic:70' for i = 2:numframes */
  loop_ub = 0;
  while (loop_ub <= numframes - 1) {
    /* 'dynamic:71' for j = 1:numcands */
    j = 1;
    while (j - 1 <= numcands) {
      /* 'dynamic:72' for k = 1:numcands */
      k = 1;
      while (k - 1 <= numcands) {
        /*  both candidates voiced */
        /* 'dynamic:74' if ((Pitch(j,i) > 0) && (Pitch(k,i-1) > 0) ) */
        i0 = RPitch->size[0];
        if (!((j >= 1) && (j <= i0))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i0, &u_emlrtBCI, &st);
        }

        i0 = RPitch->size[1];
        if (!((loop_ub + 2 >= 1) && (loop_ub + 2 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 2, 1, i0, &v_emlrtBCI, &st);
        }

        if (RPitch->data[(j + RPitch->size[0] * (loop_ub + 1)) - 1] > 0.0) {
          i0 = RPitch->size[0];
          if (!((k >= 1) && (k <= i0))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i0, &w_emlrtBCI, &st);
          }

          i0 = RPitch->size[1];
          if (!((loop_ub + 1 >= 1) && (loop_ub + 1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i0, &x_emlrtBCI, &st);
          }

          if (RPitch->data[(k + RPitch->size[0] * loop_ub) - 1] > 0.0) {
            /* 'dynamic:75' Trans(k,j,i) = dp_w1*(abs(Pitch(j,i)-Pitch(k,i-1))/mean_pitch); */
            i0 = RPitch->size[0];
            end = (j - 1) + 1;
            if (!((end >= 1) && (end <= i0))) {
              emlrtDynamicBoundsCheckR2012b(end, 1, i0, &f_emlrtBCI, &st);
            }

            i0 = RPitch->size[1];
            end = (int32_T)(2.0 + (real_T)loop_ub);
            if (!((end >= 1) && (end <= i0))) {
              emlrtDynamicBoundsCheckR2012b(end, 1, i0, &e_emlrtBCI, &st);
            }

            i0 = RPitch->size[0];
            end = (k - 1) + 1;
            if (!((end >= 1) && (end <= i0))) {
              emlrtDynamicBoundsCheckR2012b(end, 1, i0, &d_emlrtBCI, &st);
            }

            i0 = RPitch->size[1];
            end = (int32_T)((2.0 + (real_T)loop_ub) - 1.0);
            if (!((end >= 1) && (end <= i0))) {
              emlrtDynamicBoundsCheckR2012b(end, 1, i0, &c_emlrtBCI, &st);
            }

            i0 = Trans->size[0];
            if (!((k >= 1) && (k <= i0))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i0, &y_emlrtBCI, &st);
            }

            i0 = Trans->size[1];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, &ab_emlrtBCI, &st);
            }

            i0 = Trans->size[2];
            if (!((loop_ub + 2 >= 1) && (loop_ub + 2 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub + 2, 1, i0, &bb_emlrtBCI,
                &st);
            }

            Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                         Trans->size[1] * (loop_ub + 1)) - 1] = Parameter[28] *
              (muDoubleScalarAbs(RPitch->data[(j + RPitch->size[0] * (loop_ub +
                  1)) - 1] - RPitch->data[(k + RPitch->size[0] * loop_ub) - 1]) /
               mean_pitch);
          }
        }

        /*  one candiate is unvoiced */
        /* 'dynamic:79' if (Pitch(j,i)==0 && Pitch(k,i-1)>0) || (Pitch(j,i)>0 && Pitch(k,i-1)==0) */
        i0 = RPitch->size[0];
        if (!((j >= 1) && (j <= i0))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i0, &cb_emlrtBCI, &st);
        }

        i0 = RPitch->size[1];
        if (!((loop_ub + 2 >= 1) && (loop_ub + 2 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 2, 1, i0, &db_emlrtBCI, &st);
        }

        guard1 = false;
        guard2 = false;
        if (RPitch->data[(j + RPitch->size[0] * (loop_ub + 1)) - 1] == 0.0) {
          i0 = RPitch->size[0];
          if (!((k >= 1) && (k <= i0))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i0, &eb_emlrtBCI, &st);
          }

          i0 = RPitch->size[1];
          if (!((loop_ub + 1 >= 1) && (loop_ub + 1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i0, &fb_emlrtBCI, &st);
          }

          if (RPitch->data[(k + RPitch->size[0] * loop_ub) - 1] > 0.0) {
            guard1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          i0 = RPitch->size[0];
          if (!((j >= 1) && (j <= i0))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i0, &gb_emlrtBCI, &st);
          }

          i0 = RPitch->size[1];
          if (!((loop_ub + 2 >= 1) && (loop_ub + 2 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 2, 1, i0, &hb_emlrtBCI, &st);
          }

          if (RPitch->data[(j + RPitch->size[0] * (loop_ub + 1)) - 1] > 0.0) {
            i0 = RPitch->size[0];
            if (!((k >= 1) && (k <= i0))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i0, &ib_emlrtBCI, &st);
            }

            i0 = RPitch->size[1];
            if (!((loop_ub + 1 >= 1) && (loop_ub + 1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i0, &jb_emlrtBCI,
                &st);
            }

            if (RPitch->data[(k + RPitch->size[0] * loop_ub) - 1] == 0.0) {
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* 'dynamic:80' benefit = min(1, abs(Energy(i-1)-Energy(i))); */
          i0 = Data_temp->size[1];
          end = (int32_T)((2.0 + (real_T)loop_ub) - 1.0);
          if (!((end >= 1) && (end <= i0))) {
            emlrtDynamicBoundsCheckR2012b(end, 1, i0, &b_emlrtBCI, &st);
          }

          i0 = Data_temp->size[1];
          end = (int32_T)(2.0 + (real_T)loop_ub);
          if (!((end >= 1) && (end <= i0))) {
            emlrtDynamicBoundsCheckR2012b(end, 1, i0, &emlrtBCI, &st);
          }

          /* 'dynamic:81' Trans(k,j,i) =  dp_w2*(1-benefit); */
          i0 = Trans->size[0];
          if (!((k >= 1) && (k <= i0))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i0, &kb_emlrtBCI, &st);
          }

          i0 = Trans->size[1];
          if (!((j >= 1) && (j <= i0))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i0, &lb_emlrtBCI, &st);
          }

          i0 = Trans->size[2];
          if (!((loop_ub + 2 >= 1) && (loop_ub + 2 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 2, 1, i0, &mb_emlrtBCI, &st);
          }

          Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                       Trans->size[1] * (loop_ub + 1)) - 1] = Parameter[29] *
            (1.0 - muDoubleScalarMin(1.0, muDoubleScalarAbs(Data_temp->
               data[loop_ub] - Data_temp->data[loop_ub + 1])));
        }

        /*  both candidates are unvoiced */
        /* 'dynamic:85' if ((Pitch(j,i) == 0) && (Pitch(k,i-1) == 0)) */
        i0 = RPitch->size[0];
        if (!((j >= 1) && (j <= i0))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i0, &nb_emlrtBCI, &st);
        }

        i0 = RPitch->size[1];
        if (!((loop_ub + 2 >= 1) && (loop_ub + 2 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 2, 1, i0, &ob_emlrtBCI, &st);
        }

        if (RPitch->data[(j + RPitch->size[0] * (loop_ub + 1)) - 1] == 0.0) {
          i0 = RPitch->size[0];
          if (!((k >= 1) && (k <= i0))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i0, &pb_emlrtBCI, &st);
          }

          i0 = RPitch->size[1];
          if (!((loop_ub + 1 >= 1) && (loop_ub + 1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i0, &qb_emlrtBCI, &st);
          }

          if (RPitch->data[(k + RPitch->size[0] * loop_ub) - 1] == 0.0) {
            /* 'dynamic:86' Trans(k,j,i) =  dp_w3; */
            i0 = Trans->size[0];
            if (!((k >= 1) && (k <= i0))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i0, &rb_emlrtBCI, &st);
            }

            i0 = Trans->size[1];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, &sb_emlrtBCI, &st);
            }

            i0 = Trans->size[2];
            if (!((loop_ub + 2 >= 1) && (loop_ub + 2 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub + 2, 1, i0, &tb_emlrtBCI,
                &st);
            }

            Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                         Trans->size[1] * (loop_ub + 1)) - 1] = Parameter[30];
          }
        }

        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    loop_ub++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /*  Overal balance between Local and Transition costs */
  /* 'dynamic:93' Trans = Trans/dp_w4; */
  i0 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity(&st, (emxArray__common *)Trans, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  b_Data = Trans->size[0];
  loop_ub = Trans->size[1];
  end = Trans->size[2];
  loop_ub = b_Data * loop_ub * end;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Trans->data[i0] /= Parameter[31];
  }

  emxInit_real_T(&st, &r1, 2, &emlrtRTEI, true);

  /*  Find the minimum cost path thru Pitch_Array using the Local and Trans costs */
  /* 'dynamic:96' Path = path1(Local,Trans); */
  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = Merit->size[0];
  r1->size[1] = Merit->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)r1, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = Merit->size[0] * Merit->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    r1->data[i0] = 1.0 - Merit->data[i0];
  }

  emxFree_real_T(&Merit);
  b_st.site = &qn_emlrtRSI;
  path1(&b_st, r1, Trans, Data_temp);

  /* extracting the pitch, using Path */
  /* 'dynamic:99' FinPitch = zeros(1,numframes); */
  i0 = Pitch_before->size[0] * Pitch_before->size[1];
  Pitch_before->size[0] = 1;
  Pitch_before->size[1] = RPitch->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Pitch_before, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = RPitch->size[1];
  emxFree_real_T(&r1);
  emxFree_real_T(&Trans);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Pitch_before->data[i0] = 0.0;
  }

  /* 'dynamic:100' for i = 1:numframes */
  loop_ub = 1;
  while (loop_ub - 1 <= numframes) {
    /* 'dynamic:101' FinPitch(i) = Pitch(Path(i),i); */
    i0 = RPitch->size[0];
    end = Data_temp->size[1];
    if (!((loop_ub >= 1) && (loop_ub <= end))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, end, &r_emlrtBCI, &st);
    }

    y = Data_temp->data[loop_ub - 1];
    if (y != (int32_T)muDoubleScalarFloor(y)) {
      emlrtIntegerCheckR2012b(y, &emlrtDCI, &st);
    }

    end = (int32_T)y;
    if (!((end >= 1) && (end <= i0))) {
      emlrtDynamicBoundsCheckR2012b(end, 1, i0, &q_emlrtBCI, &st);
    }

    i0 = RPitch->size[1];
    if (!((loop_ub >= 1) && (loop_ub <= i0))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, &s_emlrtBCI, &st);
    }

    i0 = Pitch_before->size[1];
    if (!((loop_ub >= 1) && (loop_ub <= i0))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, &t_emlrtBCI, &st);
    }

    Pitch_before->data[loop_ub - 1] = RPitch->data[(end + RPitch->size[0] *
      (loop_ub - 1)) - 1];
    loop_ub++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxFree_real_T(&RPitch);

  /* 'yaapt:156' numfrms = length(Pitch_before); */
  *numfrms = Pitch_before->size[1];

  /* 'yaapt:157' frmrate = Prm.frame_space; */
  *frmrate = Parameter[1];

  /* 'yaapt:159' [Pitch_Freq,~] = freqSelect(Pitch_before); */
  st.site = &k_emlrtRSI;
  freqSelect(&st, Pitch_before, VUVSPitch, Data_temp);

  /* 'yaapt:159' ~ */
  /* 'yaapt:160' Pitch = Pitch_Optimization(Pitch_Freq, Prm); */
  st.site = &l_emlrtRSI;

  /*  Preprocess the raw data from android voice recorder */
  /*  */
  /*  Data_in = Raw data android voice recorder */
  /*  Data_out = Head and tail muted data */
  /*  The noise comes from opening mic and closing mic */
  /* 'Pitch_Optimization:7' Pitch_temp = Pitch; */
  i0 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 1;
  Pitch->size[1] = VUVSPitch->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Pitch, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = VUVSPitch->size[0] * VUVSPitch->size[1];
  emxFree_real_T(&Data_temp);
  emxFree_real_T(&Pitch_before);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Pitch->data[i0] = VUVSPitch->data[i0];
  }

  /* 'Pitch_Optimization:8' for i=1:length(Pitch_temp) */
  loop_ub = 1;
  while (loop_ub - 1 <= VUVSPitch->size[1] - 1) {
    /* 'Pitch_Optimization:9' if( i+1<length(Pitch_temp) && i-1>0 && Pitch_temp(i-1) ~= Pitch_temp(i) && Pitch_temp(i) ~= Pitch_temp(i+1)) */
    if ((loop_ub + 1U < (uint32_T)Pitch->size[1]) && (loop_ub - 1 > 0)) {
      i0 = Pitch->size[1];
      end = loop_ub - 1;
      if (!((end >= 1) && (end <= i0))) {
        emlrtDynamicBoundsCheckR2012b(end, 1, i0, &k_emlrtBCI, &st);
      }

      i0 = Pitch->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i0))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, &l_emlrtBCI, &st);
      }

      if (Pitch->data[end - 1] != Pitch->data[loop_ub - 1]) {
        i0 = Pitch->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, &m_emlrtBCI, &st);
        }

        i0 = Pitch->size[1];
        end = (int32_T)(loop_ub + 1U);
        if (!((end >= 1) && (end <= i0))) {
          emlrtDynamicBoundsCheckR2012b(end, 1, i0, &n_emlrtBCI, &st);
        }

        if (Pitch->data[loop_ub - 1] != Pitch->data[end - 1]) {
          /* 'Pitch_Optimization:10' Pitch_temp(i) = Pitch_temp(i - 1); */
          i0 = Pitch->size[1];
          end = loop_ub - 1;
          if (!((end >= 1) && (end <= i0))) {
            emlrtDynamicBoundsCheckR2012b(end, 1, i0, &o_emlrtBCI, &st);
          }

          i0 = Pitch->size[1];
          if (!((loop_ub >= 1) && (loop_ub <= i0))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, &p_emlrtBCI, &st);
          }

          Pitch->data[loop_ub - 1] = Pitch->data[end - 1];
        }
      }
    }

    loop_ub++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxFree_real_T(&VUVSPitch);

  /* 'Pitch_Optimization:14' Pitch_temp = Smooth(Pitch_temp, Prm); */
  b_st.site = &xn_emlrtRSI;
  Smooth(&b_st, Pitch, Parameter[32]);

  /* 'Pitch_Optimization:15' Pitch_temp = Smooth(Pitch_temp, Prm); */
  b_st.site = &yn_emlrtRSI;
  Smooth(&b_st, Pitch, Parameter[32]);

  /* 'Pitch_Optimization:16' Pitch_out = Smooth(Pitch_temp, Prm); */
  b_st.site = &ao_emlrtRSI;
  Smooth(&b_st, Pitch, Parameter[32]);

  /*  Pitch_out = Pitch_temp; */
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
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (yaapt.c) */
