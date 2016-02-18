/*
 * File: yaapt.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Smooth.h"
#include "yaapt_emxutil.h"
#include "freqSelect.h"
#include "path1.h"
#include "mean.h"
#include "refine.h"
#include "tm_trk.h"
#include "spec_trk.h"
#include "rdivide.h"
#include "Myspecgram.h"
#include "cmp_rate.h"
#include "nonlinear.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * YAAPT Fundamental Frequency (Pitch) tracking
 *
 *  [Pitch, numfrms, frmrate] = yaapt(Data, Fs, VU, ExtrPrm, fig)
 *    , the function is to check input parameters and invoke a number of associated routines
 *    for the YAAPT pitch tracking.
 *
 *  INPUTS:
 *    Data:       Input speech raw data
 *    Fs:         Sampling rate of the input data
 *    VU:         Whether to use voiced/unvoiced decision with 1 for True and 0 for
 *                False.The default is 1.
 *    ExtrPrm:    Extra parameters in a struct type for performance control.
 *                See available parameters defined in yaapt.m
 *                e.g.,
 *                ExtrPrm.f0_min = 60;         % Change minimum search F0 to 60Hz
 *                ExtrmPrm.fft_length = 8192;  % Change FFT length to 8192
 *    fig:        Whether to plot pitch tracks, spectrum, engergy, etc. The parameter
 *                is 1 for True and 0 for False. The default is 0.
 *
 *  OUTPUTS:
 *    Pitch:      Final pitch track in Hz. Unvoiced frames are assigned to 0s.
 *    numfrms:    Total number of calculated frames, or the length of
 *                output pitch track
 *    frmrate:    Frame rate of output pitch track in ms
 * Arguments    : const emxArray_real_T *Data
 *                double Fs
 *                const double Parameter[34]
 *                emxArray_real_T *Pitch
 *                double *numfrms
 *                double *frmrate
 * Return Type  : void
 */
void yaapt(const emxArray_real_T *Data, double Fs, const double Parameter[34],
           emxArray_real_T *Pitch, double *numfrms, double *frmrate)
{
  emxArray_real_T *Data_temp;
  int i0;
  int loop_ub;
  int n;
  emxArray_int32_T *r0;
  int ix;
  emxArray_real_T *DataB;
  emxArray_real_T *DataC;
  emxArray_real_T *DataD;
  double nFs;
  double s;
  double nframesize;
  emxArray_real_T *b_DataB;
  double N_F0_min;
  double N_F0_max;
  emxArray_creal_T *SpecData;
  double b_s;
  emxArray_creal_T *x;
  int iy;
  int k;
  emxArray_creal_T *b_SpecData;
  unsigned int uv0[2];
  emxArray_real_T *y;
  emxArray_real_T *Energy;
  emxArray_boolean_T *VUVEnergy;
  double avgEnergy;
  emxArray_real_T *b_DataD;
  struct_T expl_temp;
  emxArray_real_T *TMerit1;
  emxArray_real_T *TPitch2;
  emxArray_real_T *TMerit2;
  emxArray_real_T *RPitch;
  emxArray_real_T *Merit;
  int pStd_size[1];
  double pStd_data[1];
  int pAvg_size[1];
  double pAvg_data[1];
  int numframes;
  int numcands;
  emxArray_real_T *b_RPitch;
  emxArray_real_T *c_RPitch;
  emxArray_real_T *Trans;
  double mean_pitch;
  int j;
  double d0;
  emxArray_real_T *r1;
  int Path_size[2];
  double Path_data[4999];
  emxInit_real_T(&Data_temp, 2);

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
  /*  Preprocess the raw data from android voice recorder */
  /*  */
  /*  Data_in = Raw data android voice recorder */
  /*  Data_out = Head and tail muted data */
  /*  The noise comes from opening mic and closing mic */
  i0 = Data_temp->size[0] * Data_temp->size[1];
  Data_temp->size[0] = 1;
  Data_temp->size[1] = Data->size[1];
  emxEnsureCapacity((emxArray__common *)Data_temp, i0, (int)sizeof(double));
  loop_ub = Data->size[0] * Data->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Data_temp->data[i0] = Data->data[i0];
  }

  for (i0 = 0; i0 < 600; i0++) {
    Data_temp->data[i0] = 0.0;
  }

  if (Data_temp->size[1] - 2000 > Data_temp->size[1]) {
    i0 = 1;
    n = 0;
  } else {
    i0 = Data_temp->size[1] - 2000;
    n = Data_temp->size[1];
  }

  emxInit_int32_T(&r0, 2);
  ix = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = (n - i0) + 1;
  emxEnsureCapacity((emxArray__common *)r0, ix, (int)sizeof(int));
  loop_ub = (n - i0) + 1;
  for (n = 0; n < loop_ub; n++) {
    r0->data[r0->size[0] * n] = (i0 + n) - 1;
  }

  loop_ub = r0->size[0] * r0->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Data_temp->data[r0->data[i0]] = 0.0;
  }

  emxInit_real_T(&DataB, 2);
  emxInit_real_T(&DataC, 2);
  emxInit_real_T(&DataD, 2);
  nonlinear(Data_temp, Fs, Parameter[5], Parameter[6], Parameter[7], Parameter
            [19], DataB, DataC, DataD, &nFs);

  /*   Check frame size, frame jump and the number of frames for nonlinear singal */
  /*   Step 2. Spectral pitch tracking */
  /*   Calculate NLFER and determine voiced/unvoiced frames with NLFER */
  /*  NLFER  Normalized Low Frequency Energy Ratio */
  /*  */
  /*    [Energy, VUVEnergy]= nlfer(Data, Fs, Prm) computes the */
  /*    nromlized low frequency energy ratio. */
  /*  */
  /*  INPUTS: */
  /*    Data:  Nonlinear, filtered signal for NLFER caculation */
  /*    Fs:    The sampling frequency. */
  /*    Prm:   Array of parameters used to control performance */
  /*  */
  /*  OUTPUTS: */
  /*    Energy:     NLFER Energy of the data */
  /*    VUVEnergy:  Voiced/Unvoiced decisions (optimum??) */
  /*    Creation date:  Oct 17, 2006, July 13, 2007 */
  /*    Programers:     Hongbing Hu, S. Zahorian */
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
  /* -- PARAMETERS: set up all of these parameters -------------------------------- */
  /*  FFT length */
  s = Parameter[0] * nFs / 1000.0;
  if (s < 0.0) {
    nframesize = ceil(s);
  } else {
    nframesize = floor(s);
  }

  s = Parameter[1] * nFs / 1000.0;
  emxInit_real_T(&b_DataB, 2);

  /*  If normalized low-frequency energy is below this, assume unvoiced frame */
  /*  Low freqeuncy range for NLFER */
  N_F0_min = rt_roundd_snf(Parameter[2] * 2.0 / nFs * Parameter[4]);
  N_F0_max = rt_roundd_snf(Parameter[3] / nFs * Parameter[4]);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Spectrogram of the data */
  i0 = b_DataB->size[0] * b_DataB->size[1];
  b_DataB->size[0] = 1;
  b_DataB->size[1] = DataB->size[1];
  emxEnsureCapacity((emxArray__common *)b_DataB, i0, (int)sizeof(double));
  loop_ub = DataB->size[0] * DataB->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_DataB->data[i0] = DataB->data[i0];
  }

  emxInit_creal_T(&SpecData, 2);
  if (s < 0.0) {
    b_s = ceil(s);
  } else {
    b_s = floor(s);
  }

  Myspecgram(b_DataB, Parameter[4], nframesize, nframesize - b_s, SpecData);

  /*  SpecData_test = specgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  /*  Compute normalize low-frequency energy ratio  */
  emxFree_real_T(&b_DataB);
  if (N_F0_min > N_F0_max) {
    i0 = 0;
    n = 0;
  } else {
    i0 = (int)N_F0_min - 1;
    n = (int)N_F0_max;
  }

  emxInit_creal_T(&x, 2);
  loop_ub = SpecData->size[1];
  ix = x->size[0] * x->size[1];
  x->size[0] = n - i0;
  x->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)x, ix, (int)sizeof(creal_T));
  for (ix = 0; ix < loop_ub; ix++) {
    iy = n - i0;
    for (k = 0; k < iy; k++) {
      x->data[k + x->size[0] * ix] = SpecData->data[(i0 + k) + SpecData->size[0]
        * ix];
    }
  }

  emxInit_creal_T(&b_SpecData, 2);
  loop_ub = SpecData->size[1];
  ix = b_SpecData->size[0] * b_SpecData->size[1];
  b_SpecData->size[0] = n - i0;
  b_SpecData->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_SpecData, ix, (int)sizeof(creal_T));
  for (ix = 0; ix < loop_ub; ix++) {
    iy = n - i0;
    for (k = 0; k < iy; k++) {
      b_SpecData->data[k + b_SpecData->size[0] * ix] = SpecData->data[(i0 + k) +
        SpecData->size[0] * ix];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    uv0[ix] = (unsigned int)b_SpecData->size[ix];
  }

  emxFree_creal_T(&b_SpecData);
  emxInit_real_T(&y, 2);
  ix = y->size[0] * y->size[1];
  y->size[0] = (int)uv0[0];
  y->size[1] = (int)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, ix, (int)sizeof(double));
  ix = SpecData->size[1];
  n = (n - i0) * ix;
  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = rt_hypotd_snf(x->data[k].re, x->data[k].im);
  }

  emxFree_creal_T(&x);
  emxFree_creal_T(&SpecData);
  i0 = Data_temp->size[0] * Data_temp->size[1];
  Data_temp->size[0] = 1;
  Data_temp->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)Data_temp, i0, (int)sizeof(double));
  if ((y->size[0] == 0) || (y->size[1] == 0)) {
    i0 = Data_temp->size[0] * Data_temp->size[1];
    Data_temp->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)Data_temp, i0, (int)sizeof(double));
    loop_ub = Data_temp->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      Data_temp->data[Data_temp->size[0] * i0] = 0.0;
    }
  } else {
    ix = 0;
    iy = -1;
    for (loop_ub = 1; loop_ub <= y->size[1]; loop_ub++) {
      n = ix;
      ix++;
      s = y->data[n];
      for (k = 2; k <= y->size[0]; k++) {
        ix++;
        s += y->data[ix - 1];
      }

      iy++;
      Data_temp->data[iy] = s;
    }
  }

  emxInit_real_T(&Energy, 2);
  emxInit_boolean_T(&VUVEnergy, 2);
  avgEnergy = mean(Data_temp);
  c_rdivide(Data_temp, avgEnergy, Energy);

  /*  The frame is voiced if NLFER enery > threshold, otherwise is unvoiced. */
  i0 = VUVEnergy->size[0] * VUVEnergy->size[1];
  VUVEnergy->size[0] = 1;
  VUVEnergy->size[1] = Energy->size[1];
  emxEnsureCapacity((emxArray__common *)VUVEnergy, i0, (int)sizeof(boolean_T));
  loop_ub = Energy->size[0] * Energy->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    VUVEnergy->data[i0] = (Energy->data[i0] > Parameter[8]);
  }

  emxInit_real_T(&b_DataD, 2);

  /*   Calculate an approximate pitch track from the spectrum. */
  /*   At this point, SPitch is best estimate of pitch track from spectrum */
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
  emxEnsureCapacity((emxArray__common *)b_DataD, i0, (int)sizeof(double));
  loop_ub = DataD->size[0] * DataD->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_DataD->data[i0] = DataD->data[i0];
  }

  emxInit_real_T(&TMerit1, 2);
  emxInit_real_T(&TPitch2, 2);
  emxInit_real_T(&TMerit2, 2);
  emxInit_real_T(&RPitch, 2);
  emxInit_real_T(&Merit, 2);
  spec_trk(b_DataD, nFs, VUVEnergy, &expl_temp, Data_temp, DataC, pAvg_data,
           pAvg_size, pStd_data, pStd_size);

  /*   Step 3. Temporal pitch tracking based on NCCF */
  /*   Calculate a pitch track based on time-domain processing */
  /*   Pitch tracking from the filterd original signal  */
  tm_trk(DataB, nFs, Data_temp, pStd_data, pStd_size, Parameter[0], Parameter[1],
         Parameter[2], Parameter[3], Parameter[20], Parameter[21], Parameter[22],
         Parameter[23], Parameter[24], y, TMerit1);

  /*   Pitch tracking from the filterd nonlinear signal  */
  tm_trk(DataD, nFs, Data_temp, pStd_data, pStd_size, Parameter[0], Parameter[1],
         Parameter[2], Parameter[3], Parameter[20], Parameter[21], Parameter[22],
         Parameter[23], Parameter[24], TPitch2, TMerit2);

  /*  Refine pitch candidates  */
  refine(y, TMerit1, TPitch2, TMerit2, Data_temp, Energy, VUVEnergy, Parameter[9],
         Parameter[25], Parameter[27], RPitch, Merit);

  /*  Step 5. Use dyanamic programming to determine the final pitch */
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
  numframes = RPitch->size[1] - 1;
  numcands = RPitch->size[0] - 1;

  /* Copy some arrays */
  ix = RPitch->size[1] - 1;
  n = 0;
  emxFree_real_T(&b_DataD);
  emxFree_real_T(&y);
  emxFree_real_T(&TMerit2);
  emxFree_real_T(&TPitch2);
  emxFree_real_T(&TMerit1);
  emxFree_boolean_T(&VUVEnergy);
  emxFree_real_T(&DataD);
  emxFree_real_T(&DataB);
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (RPitch->data[(numcands + RPitch->size[0] * loop_ub) - 1] > 0.0) {
      n++;
    }
  }

  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = n;
  emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(int));
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (RPitch->data[(numcands + RPitch->size[0] * loop_ub) - 1] > 0.0) {
      r0->data[n] = loop_ub + 1;
      n++;
    }
  }

  emxInit_real_T(&b_RPitch, 2);
  emxInit_real_T(&c_RPitch, 2);
  loop_ub = RPitch->size[1];
  n = RPitch->size[0];
  i0 = c_RPitch->size[0] * c_RPitch->size[1];
  c_RPitch->size[0] = 1;
  c_RPitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)c_RPitch, i0, (int)sizeof(double));
  for (i0 = 0; i0 < loop_ub; i0++) {
    c_RPitch->data[c_RPitch->size[0] * i0] = RPitch->data[(n + RPitch->size[0] *
      i0) - 2];
  }

  i0 = b_RPitch->size[0] * b_RPitch->size[1];
  b_RPitch->size[0] = 1;
  b_RPitch->size[1] = r0->size[1];
  emxEnsureCapacity((emxArray__common *)b_RPitch, i0, (int)sizeof(double));
  loop_ub = r0->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_RPitch->data[b_RPitch->size[0] * i0] = c_RPitch->data[r0->data[r0->size[0]
      * i0] - 1];
  }

  emxFree_real_T(&c_RPitch);
  emxFree_int32_T(&r0);
  emxInit_real_T1(&Trans, 3);
  mean_pitch = mean(b_RPitch);

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Forming the local cost matrix */
  /*  Initialization for the formation of the transition cost matrix */
  i0 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = RPitch->size[0];
  Trans->size[1] = RPitch->size[0];
  Trans->size[2] = RPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Trans, i0, (int)sizeof(double));
  loop_ub = RPitch->size[0] * RPitch->size[0] * RPitch->size[1];
  emxFree_real_T(&b_RPitch);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Trans->data[i0] = 1.0;
  }

  /*  The transition cost matrix is proportional to frequency differences */
  /*  between successive candidates. */
  for (loop_ub = 1; loop_ub - 1 < numframes; loop_ub++) {
    for (j = 0; j <= numcands; j++) {
      for (k = 0; k <= numcands; k++) {
        /*  both candidates voiced */
        if ((RPitch->data[j + RPitch->size[0] * loop_ub] > 0.0) && (RPitch->
             data[k + RPitch->size[0] * (loop_ub - 1)] > 0.0)) {
          Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1]
            * loop_ub] = Parameter[28] * (fabs(RPitch->data[j + RPitch->size[0] *
            loop_ub] - RPitch->data[k + RPitch->size[0] * (loop_ub - 1)]) /
            mean_pitch);
        }

        /*  one candiate is unvoiced */
        if (((RPitch->data[j + RPitch->size[0] * loop_ub] == 0.0) &&
             (RPitch->data[k + RPitch->size[0] * (loop_ub - 1)] > 0.0)) ||
            ((RPitch->data[j + RPitch->size[0] * loop_ub] > 0.0) &&
             (RPitch->data[k + RPitch->size[0] * (loop_ub - 1)] == 0.0))) {
          s = fabs(Energy->data[loop_ub - 1] - Energy->data[loop_ub]);
          if ((1.0 <= s) || rtIsNaN(s)) {
            d0 = 1.0;
          } else {
            d0 = s;
          }

          Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1]
            * loop_ub] = Parameter[29] * (1.0 - d0);
        }

        /*  both candidates are unvoiced */
        if ((RPitch->data[j + RPitch->size[0] * loop_ub] == 0.0) &&
            (RPitch->data[k + RPitch->size[0] * (loop_ub - 1)] == 0.0)) {
          Trans->data[(k + Trans->size[0] * j) + Trans->size[0] * Trans->size[1]
            * loop_ub] = Parameter[30];
        }
      }
    }
  }

  /*  Overal balance between Local and Transition costs */
  i0 = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity((emxArray__common *)Trans, i0, (int)sizeof(double));
  n = Trans->size[0];
  ix = Trans->size[1];
  iy = Trans->size[2];
  loop_ub = n * ix * iy;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Trans->data[i0] /= Parameter[31];
  }

  emxInit_real_T(&r1, 2);

  /*  Find the minimum cost path thru Pitch_Array using the Local and Trans costs */
  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = Merit->size[0];
  r1->size[1] = Merit->size[1];
  emxEnsureCapacity((emxArray__common *)r1, i0, (int)sizeof(double));
  loop_ub = Merit->size[0] * Merit->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    r1->data[i0] = 1.0 - Merit->data[i0];
  }

  emxFree_real_T(&Merit);
  path1(r1, Trans, Path_data, Path_size);

  /* extracting the pitch, using Path */
  i0 = Data_temp->size[0] * Data_temp->size[1];
  Data_temp->size[0] = 1;
  Data_temp->size[1] = RPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Data_temp, i0, (int)sizeof(double));
  loop_ub = RPitch->size[1];
  emxFree_real_T(&r1);
  emxFree_real_T(&Trans);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Data_temp->data[i0] = 0.0;
  }

  for (loop_ub = 0; loop_ub <= numframes; loop_ub++) {
    Data_temp->data[loop_ub] = RPitch->data[((int)Path_data[loop_ub] +
      RPitch->size[0] * loop_ub) - 1];
  }

  emxFree_real_T(&RPitch);
  *numfrms = Data_temp->size[1];
  *frmrate = Parameter[1];
  freqSelect(Data_temp, Energy, DataC);

  /*  Preprocess the raw data from android voice recorder */
  /*  */
  /*  Data_in = Raw data android voice recorder */
  /*  Data_out = Head and tail muted data */
  /*  The noise comes from opening mic and closing mic */
  i0 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 1;
  Pitch->size[1] = Energy->size[1];
  emxEnsureCapacity((emxArray__common *)Pitch, i0, (int)sizeof(double));
  loop_ub = Energy->size[0] * Energy->size[1];
  emxFree_real_T(&Data_temp);
  emxFree_real_T(&DataC);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Pitch->data[i0] = Energy->data[i0];
  }

  for (loop_ub = 0; loop_ub < Energy->size[1]; loop_ub++) {
    if ((loop_ub + 2U < (unsigned int)Pitch->size[1]) && (loop_ub > 0) &&
        (Pitch->data[loop_ub - 1] != Pitch->data[loop_ub]) && (Pitch->
         data[loop_ub] != Pitch->data[loop_ub + 1])) {
      Pitch->data[loop_ub] = Pitch->data[loop_ub - 1];
    }
  }

  emxFree_real_T(&Energy);
  Smooth(Pitch, Parameter[32]);
  Smooth(Pitch, Parameter[32]);
  Smooth(Pitch, Parameter[32]);

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
}

/*
 * File trailer for yaapt.c
 *
 * [EOF]
 */
