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
#include "nonlinear.h"
#include "spec_trk.h"
#include "freqSelect.h"
#include "dynamic.h"
#include "refine.h"
#include "tm_trk.h"
#include "nlfer.h"
#include "peaks.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 121, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo b_emlrtRSI = { 126, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo c_emlrtRSI = { 129, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo d_emlrtRSI = { 134, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo e_emlrtRSI = { 138, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo f_emlrtRSI = { 144, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo g_emlrtRSI = { 147, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo h_emlrtRSI = { 150, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo i_emlrtRSI = { 154, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo j_emlrtRSI = { 158, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo k_emlrtRSI = { 159, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 37, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRTEInfo b_emlrtRTEI = { 154, 1, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 8, 1, "Pitch_temp", "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 10, 44, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 10, 63, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 10, 80, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 10, 97, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 11, 25, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 11, 9, "Pitch_temp",
  "Pitch_Optimization",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Pitch_Optimization.m",
  0 };

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
 * function[Pitch, numfrms, frmrate] = yaapt(Data, Fs)
 */
void yaapt(yaaptStackData *SD, const emlrtStack *sp, const emxArray_real_T *Data,
           real_T Fs, emxArray_real_T *Pitch, real_T *numfrms, real_T *frmrate)
{
  emxArray_real_T *DataB;
  emxArray_real_T *DataC;
  emxArray_real_T *DataD;
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
  emxArray_real_T *Pitch_before;
  emxArray_real_T *pAvg;
  emxArray_real_T *pStd;
  emxArray_real_T *TPitch1;
  emxArray_real_T *TMerit1;
  emxArray_real_T *TPitch2;
  emxArray_real_T *TMerit2;
  emxArray_real_T *RPitch;
  emxArray_real_T *Merit;
  int32_T i1;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &DataB, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &DataC, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &DataD, 2, &emlrtRTEI, true);

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
  /* 'yaapt:55'     'frame_length',   20, ... % Length of each analysis frame (ms) */
  /* 'yaapt:56'     'frame_space',    30, ... % Spacing between analysis frame (ms) */
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
  /* 'yaapt:71'     'f0_double',     300, ... % F0 doubling decision threshold (Hz) */
  /* 'yaapt:72'     'f0_half',       300, ... % F0 halving decision threshold (Hz) */
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
  /*  Data_after = Preprocess(Data); */
  /* 'yaapt:121' [DataB, DataC, DataD, nFs] = nonlinear(Data, Fs, Prm); */
  st.site = &emlrtRSI;
  nonlinear(SD, &st, Data, Fs, DataB, DataC, DataD, &nFs);

  /*   Check frame size, frame jump and the number of frames for nonlinear singal */
  /* 'yaapt:124' nframesize = fix(Prm.frame_length*nFs/1000); */
  y = 20.0 * nFs / 1000.0;
  if (y < 0.0) {
    nframesize = muDoubleScalarCeil(y);
  } else {
    nframesize = muDoubleScalarFloor(y);
  }

  /* 'yaapt:125' if (nframesize < 15) */
  if (nframesize < 15.0) {
    /* 'yaapt:126' error('Frame length value %d is too short', Prm.frame_length); */
    st.site = &b_emlrtRSI;
    for (i0 = 0; i0 < 34; i0++) {
      u[i0] = varargin_1[i0];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(&st, 34, m0, &u[0]);
    emlrtAssign(&b_y, m0);
    b_st.site = &nm_emlrtRSI;
    o_error(&b_st, b_y, emlrt_marshallOut(20.0), &emlrtMCI);
  }

  /* 'yaapt:128' if (nframesize > 2048) */
  if (nframesize > 2048.0) {
    /* 'yaapt:129' error('Frame length value %d exceeds the limit', Prm.frame_length); */
    st.site = &c_emlrtRSI;
    for (i0 = 0; i0 < 39; i0++) {
      b_u[i0] = b_varargin_1[i0];
    }

    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(&st, 39, m0, &b_u[0]);
    emlrtAssign(&c_y, m0);
    b_st.site = &nm_emlrtRSI;
    o_error(&b_st, c_y, emlrt_marshallOut(20.0), &emlrtMCI);
  }

  emxInit_real_T(sp, &Energy, 2, &emlrtRTEI, true);
  emxInit_boolean_T(sp, &VUVEnergy, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_DataD, 2, &emlrtRTEI, true);

  /*   Step 2. Spectral pitch tracking */
  /*   Calculate NLFER and determine voiced/unvoiced frames with NLFER */
  /* 'yaapt:134' [Energy, VUVEnergy]= nlfer(DataB, nFs, Prm); */
  st.site = &d_emlrtRSI;
  nlfer(&st, DataB, nFs, Energy, VUVEnergy);

  /*   Calculate an approximate pitch track from the spectrum. */
  /*   At this point, SPitch is best estimate of pitch track from spectrum */
  /* 'yaapt:138' [SPitch, VUVSPitch, pAvg, pStd]= spec_trk(DataD, nFs, VUVEnergy, Prm); */
  i0 = b_DataD->size[0] * b_DataD->size[1];
  b_DataD->size[0] = 1;
  b_DataD->size[1] = DataD->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DataD, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = DataD->size[0] * DataD->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_DataD->data[i0] = DataD->data[i0];
  }

  emxInit_real_T(sp, &Pitch_before, 2, &b_emlrtRTEI, true);
  emxInit_real_T1(sp, &pAvg, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &pStd, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &TPitch1, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TMerit1, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TPitch2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TMerit2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &RPitch, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &Merit, 2, &emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  spec_trk(SD, &st, b_DataD, nFs, VUVEnergy, DataC, Pitch_before, pAvg, pStd);

  /*   Step 3. Temporal pitch tracking based on NCCF */
  /*   Calculate a pitch track based on time-domain processing */
  /*   Pitch tracking from the filterd original signal  */
  /* 'yaapt:144' [TPitch1, TMerit1] = tm_trk(DataB, nFs, SPitch, pStd, pAvg, Prm); */
  st.site = &f_emlrtRSI;
  tm_trk(&st, DataB, nFs, DataC, pStd, TPitch1, TMerit1);

  /*   Pitch tracking from the filterd nonlinear signal  */
  /* 'yaapt:147' [TPitch2, TMerit2] = tm_trk(DataD, nFs, SPitch, pStd, pAvg, Prm); */
  st.site = &g_emlrtRSI;
  tm_trk(&st, DataD, nFs, DataC, pStd, TPitch2, TMerit2);

  /*  Refine pitch candidates  */
  /* 'yaapt:150' [RPitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, ... */
  /* 'yaapt:151'                         Energy, VUVEnergy, Prm); */
  st.site = &h_emlrtRSI;
  refine(&st, TPitch1, TMerit1, TPitch2, TMerit2, DataC, Energy, VUVEnergy,
         RPitch, Merit);

  /*  Step 5. Use dyanamic programming to determine the final pitch */
  /* 'yaapt:154' Pitch_before  = dynamic(RPitch, Merit, Energy, Prm); */
  st.site = &i_emlrtRSI;
  dynamic(&st, RPitch, Merit, Energy, Pitch_before);

  /* 'yaapt:155' numfrms = length(Pitch_before); */
  *numfrms = Pitch_before->size[1];

  /* 'yaapt:156' frmrate = Prm.frame_space; */
  *frmrate = 30.0;

  /* 'yaapt:158' [Pitch_Freq,~] = freqSelect(Pitch_before); */
  st.site = &j_emlrtRSI;
  freqSelect(&st, Pitch_before, Pitch, DataC);

  /* 'yaapt:158' ~ */
  /* 'yaapt:159' Pitch = Pitch_Optimization(Pitch_Freq); */
  st.site = &k_emlrtRSI;

  /*  Preprocess the raw data from android voice recorder */
  /*  */
  /*  Data_in = Raw data android voice recorder */
  /*  Data_out = Head and tail muted data */
  /*  The noise comes from opening mic and closing mic */
  /* 'Pitch_Optimization:7' Pitch_temp = Pitch; */
  /* 'Pitch_Optimization:8' Pitch_temp(1:3)=0; */
  loop_ub = Pitch->size[1];
  emxFree_real_T(&b_DataD);
  emxFree_real_T(&Merit);
  emxFree_real_T(&RPitch);
  emxFree_real_T(&TMerit2);
  emxFree_real_T(&TPitch2);
  emxFree_real_T(&TMerit1);
  emxFree_real_T(&TPitch1);
  emxFree_real_T(&pStd);
  emxFree_real_T(&pAvg);
  emxFree_boolean_T(&VUVEnergy);
  emxFree_real_T(&Energy);
  emxFree_real_T(&DataD);
  emxFree_real_T(&DataC);
  emxFree_real_T(&DataB);
  emxFree_real_T(&Pitch_before);
  for (i0 = 0; i0 < 3; i0++) {
    i1 = 1 + i0;
    if (!(i1 <= loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub, &emlrtBCI, &st);
    }

    Pitch->data[i1 - 1] = 0.0;
  }

  /* 'Pitch_Optimization:9' for i=1:length(Pitch_temp) */
  i0 = Pitch->size[1];
  i = 1;
  while (i - 1 <= i0 - 1) {
    /* 'Pitch_Optimization:10' if( i+1<length(Pitch_temp) && i-1>0 && Pitch_temp(i-1) ~= Pitch_temp(i) && Pitch_temp(i) ~= Pitch_temp(i+1)) */
    if ((i + 1U < (uint32_T)Pitch->size[1]) && (i - 1 > 0)) {
      i1 = Pitch->size[1];
      loop_ub = i - 1;
      if (!((loop_ub >= 1) && (loop_ub <= i1))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &b_emlrtBCI, &st);
      }

      i1 = Pitch->size[1];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, &c_emlrtBCI, &st);
      }

      if (Pitch->data[loop_ub - 1] != Pitch->data[i - 1]) {
        i1 = Pitch->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, &d_emlrtBCI, &st);
        }

        i1 = Pitch->size[1];
        loop_ub = (int32_T)(i + 1U);
        if (!((loop_ub >= 1) && (loop_ub <= i1))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &e_emlrtBCI, &st);
        }

        if (Pitch->data[i - 1] != Pitch->data[loop_ub - 1]) {
          /* 'Pitch_Optimization:11' Pitch_temp(i) = Pitch_temp(i - 1); */
          i1 = Pitch->size[1];
          loop_ub = i - 1;
          if (!((loop_ub >= 1) && (loop_ub <= i1))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &f_emlrtBCI, &st);
          }

          i1 = Pitch->size[1];
          if (!((i >= 1) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i1, &g_emlrtBCI, &st);
          }

          Pitch->data[i - 1] = Pitch->data[loop_ub - 1];
        }
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* 'Pitch_Optimization:14' Pitch_out = Pitch_temp; */
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
