/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: yaapt.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:14:51
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_emxutil.h"
#include "dynamic.h"
#include "Mymedfilt1.h"
#include "sort1.h"
#include "cat.h"
#include "tm_trk.h"
#include "spec_trk.h"
#include "mean.h"
#include "Myspecgram.h"
#include "Myhanning.h"
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
 *                emxArray_real_T *Pitch
 *                double *numfrms
 *                double *frmrate
 * Return Type  : void
 */
void yaapt(const emxArray_real_T *Data, double Fs, emxArray_real_T *Pitch,
           double *numfrms, double *frmrate)
{
  emxArray_real_T *DataB;
  emxArray_real_T *DataD;
  emxArray_real_T *BestPitch;
  double nFs;
  double s;
  double nframesize;
  emxArray_real_T *b_DataB;
  double N_F0_min;
  double N_F0_max;
  int i0;
  int loop_ub;
  emxArray_creal_T *SpecData;
  double b_s;
  int n;
  emxArray_creal_T *x;
  int k;
  int ix;
  int iy;
  emxArray_creal_T *b_SpecData;
  unsigned int uv0[2];
  emxArray_real_T *y;
  emxArray_real_T *FrmEnergy;
  int i;
  double avgEnergy;
  emxArray_boolean_T *VUVEnergy;
  emxArray_real_T *b_DataD;
  emxArray_real_T *SPitch;
  emxArray_real_T *TPitch1;
  emxArray_real_T *TMerit1;
  emxArray_real_T *TPitch2;
  emxArray_real_T *TMerit2;
  emxArray_real_T *RPitch;
  emxArray_real_T *Merit;
  emxArray_real_T *Idx;
  emxArray_int32_T *iidx;
  int pStd_size[1];
  double pStd_data[1];
  int pAvg_size[1];
  double pAvg_data[1];
  int numframes;
  int maxcands;
  emxArray_real_T *r0;
  emxArray_real_T *b_RPitch;
  int j;
  double d0;
  emxInit_real_T(&DataB, 2);
  emxInit_real_T(&DataD, 2);
  emxInit_real_T(&BestPitch, 2);

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
  nonlinear(Data, Fs, DataB, BestPitch, DataD, &nFs);

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
  s = 25.0 * nFs / 1000.0;
  if (s < 0.0) {
    nframesize = ceil(s);
  } else {
    nframesize = floor(s);
  }

  s = 10.0 * nFs / 1000.0;
  emxInit_real_T(&b_DataB, 2);

  /*  If normalized low-frequency energy is below this, assume unvoiced frame */
  /*  Low freqeuncy range for NLFER */
  N_F0_min = rt_roundd_snf(120.0 / nFs * 8192.0);
  N_F0_max = rt_roundd_snf(400.0 / nFs * 8192.0);

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

  Myspecgram(b_DataB, nframesize, nframesize - b_s, SpecData);

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
  k = x->size[0] * x->size[1];
  x->size[0] = n - i0;
  x->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)x, k, (int)sizeof(creal_T));
  for (k = 0; k < loop_ub; k++) {
    ix = n - i0;
    for (iy = 0; iy < ix; iy++) {
      x->data[iy + x->size[0] * k] = SpecData->data[(i0 + iy) + SpecData->size[0]
        * k];
    }
  }

  emxInit_creal_T(&b_SpecData, 2);
  loop_ub = SpecData->size[1];
  k = b_SpecData->size[0] * b_SpecData->size[1];
  b_SpecData->size[0] = n - i0;
  b_SpecData->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_SpecData, k, (int)sizeof(creal_T));
  for (k = 0; k < loop_ub; k++) {
    ix = n - i0;
    for (iy = 0; iy < ix; iy++) {
      b_SpecData->data[iy + b_SpecData->size[0] * k] = SpecData->data[(i0 + iy)
        + SpecData->size[0] * k];
    }
  }

  for (k = 0; k < 2; k++) {
    uv0[k] = (unsigned int)b_SpecData->size[k];
  }

  emxFree_creal_T(&b_SpecData);
  emxInit_real_T(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = (int)uv0[0];
  y->size[1] = (int)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(double));
  k = SpecData->size[1];
  n = (n - i0) * k;
  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = rt_hypotd_snf(x->data[k].re, x->data[k].im);
  }

  emxFree_creal_T(&x);
  emxFree_creal_T(&SpecData);
  emxInit_real_T(&FrmEnergy, 2);
  i0 = FrmEnergy->size[0] * FrmEnergy->size[1];
  FrmEnergy->size[0] = 1;
  FrmEnergy->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)FrmEnergy, i0, (int)sizeof(double));
  if ((y->size[0] == 0) || (y->size[1] == 0)) {
    i0 = FrmEnergy->size[0] * FrmEnergy->size[1];
    FrmEnergy->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)FrmEnergy, i0, (int)sizeof(double));
    loop_ub = FrmEnergy->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      FrmEnergy->data[FrmEnergy->size[0] * i0] = 0.0;
    }
  } else {
    ix = 0;
    iy = -1;
    for (i = 1; i <= y->size[1]; i++) {
      n = ix;
      ix++;
      s = y->data[n];
      for (k = 2; k <= y->size[0]; k++) {
        ix++;
        s += y->data[ix - 1];
      }

      iy++;
      FrmEnergy->data[iy] = s;
    }
  }

  emxFree_real_T(&y);
  avgEnergy = mean(FrmEnergy);
  i0 = FrmEnergy->size[0] * FrmEnergy->size[1];
  FrmEnergy->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)FrmEnergy, i0, (int)sizeof(double));
  n = FrmEnergy->size[0];
  k = FrmEnergy->size[1];
  loop_ub = n * k;
  for (i0 = 0; i0 < loop_ub; i0++) {
    FrmEnergy->data[i0] /= avgEnergy;
  }

  emxInit_boolean_T(&VUVEnergy, 2);

  /*  The frame is voiced if NLFER enery > threshold, otherwise is unvoiced. */
  i0 = VUVEnergy->size[0] * VUVEnergy->size[1];
  VUVEnergy->size[0] = 1;
  VUVEnergy->size[1] = FrmEnergy->size[1];
  emxEnsureCapacity((emxArray__common *)VUVEnergy, i0, (int)sizeof(boolean_T));
  loop_ub = FrmEnergy->size[0] * FrmEnergy->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    VUVEnergy->data[i0] = (FrmEnergy->data[i0] > 0.75);
  }

  emxInit_real_T(&b_DataD, 2);

  /*   Calculate an approximate pitch track from the spectrum. */
  /*   At this point, SPitch is best estimate of pitch track from spectrum */
  i0 = b_DataD->size[0] * b_DataD->size[1];
  b_DataD->size[0] = 1;
  b_DataD->size[1] = DataD->size[1];
  emxEnsureCapacity((emxArray__common *)b_DataD, i0, (int)sizeof(double));
  loop_ub = DataD->size[0] * DataD->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_DataD->data[i0] = DataD->data[i0];
  }

  emxInit_real_T(&SPitch, 2);
  emxInit_real_T(&TPitch1, 2);
  emxInit_real_T(&TMerit1, 2);
  emxInit_real_T(&TPitch2, 2);
  emxInit_real_T(&TMerit2, 2);
  emxInit_real_T(&RPitch, 2);
  emxInit_real_T(&Merit, 2);
  emxInit_real_T(&Idx, 2);
  emxInit_int32_T(&iidx, 2);
  spec_trk(b_DataD, nFs, VUVEnergy, SPitch, BestPitch, pAvg_data, pAvg_size,
           pStd_data, pStd_size);

  /*   Step 3. Temporal pitch tracking based on NCCF */
  /*   Calculate a pitch track based on time-domain processing */
  /*   Pitch tracking from the filterd original signal  */
  tm_trk(DataB, nFs, SPitch, pStd_data, pStd_size, TPitch1, TMerit1);

  /*   Pitch tracking from the filterd nonlinear signal  */
  tm_trk(DataD, nFs, SPitch, pStd_data, pStd_size, TPitch2, TMerit2);

  /*  Refine pitch candidates  */
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
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Merge pitch candidates and their merits from two types of the signal */
  cat(TPitch1, TPitch2, RPitch);
  cat(TMerit1, TMerit2, Merit);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  numframes = RPitch->size[1] - 1;
  maxcands = RPitch->size[0] - 1;
  e_sort(Merit, iidx);
  i0 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity((emxArray__common *)Idx, i0, (int)sizeof(double));
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
  n = 0;
  emxInit_real_T1(&r0, 1);
  while (n <= numframes) {
    loop_ub = Idx->size[0];
    i0 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
    for (i0 = 0; i0 < loop_ub; i0++) {
      r0->data[i0] = RPitch->data[((int)Idx->data[i0 + Idx->size[0] * n] +
        RPitch->size[0] * n) - 1];
    }

    loop_ub = r0->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      RPitch->data[i0 + RPitch->size[0] * n] = r0->data[i0];
    }

    n++;
  }

  emxFree_real_T(&r0);
  emxFree_real_T(&Idx);
  emxInit_real_T(&b_RPitch, 2);

  /*  A best pitch track is generated from the best candidates */
  loop_ub = RPitch->size[1];
  i0 = b_RPitch->size[0] * b_RPitch->size[1];
  b_RPitch->size[0] = 1;
  b_RPitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_RPitch, i0, (int)sizeof(double));
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_RPitch->data[b_RPitch->size[0] * i0] = RPitch->data[RPitch->size[0] * i0];
  }

  c_Mymedfilt1(b_RPitch, BestPitch);
  i0 = BestPitch->size[0] * BestPitch->size[1];
  BestPitch->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)BestPitch, i0, (int)sizeof(double));
  k = BestPitch->size[0];
  n = BestPitch->size[1];
  loop_ub = k * n;
  emxFree_real_T(&b_RPitch);
  for (i0 = 0; i0 < loop_ub; i0++) {
    BestPitch->data[i0] *= (double)VUVEnergy->data[i0];
  }

  emxFree_boolean_T(&VUVEnergy);

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  for (i = 0; i <= numframes; i++) {
    if (FrmEnergy->data[i] <= 0.1) {
      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      loop_ub = RPitch->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        RPitch->data[i0 + RPitch->size[0] * i] = 0.0;
      }

      loop_ub = Merit->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        Merit->data[i0 + Merit->size[0] * i] = 0.99;
      }
    } else if (RPitch->data[RPitch->size[0] * i] > 0.0) {
      /*  already have the voiced candidate, Want to have at */
      /*  least one unvoiced candidate */
      RPitch->data[maxcands + RPitch->size[0] * i] = 0.0;
      Merit->data[maxcands + Merit->size[0] * i] = 1.0 - Merit->data[Merit->
        size[0] * i];
      for (j = 1; j - 1 <= maxcands - 2; j++) {
        if (RPitch->data[j + RPitch->size[0] * i] == 0.0) {
          Merit->data[j + Merit->size[0] * i] = 0.0;
        }
      }
    } else {
      /*  there was no voiced candidate from nccf fill in */
      /*  option for F0 from spectrogram */
      RPitch->data[RPitch->size[0] * i] = SPitch->data[i];
      s = FrmEnergy->data[i] / 2.0;
      if ((1.0 <= s) || rtIsNaN(s)) {
        Merit->data[Merit->size[0] * i] = 1.0;
      } else {
        Merit->data[Merit->size[0] * i] = s;
      }

      /*  all other candidates will be unvoiced */
      /*  with low merit */
      for (i0 = 0; i0 < maxcands; i0++) {
        RPitch->data[(i0 + RPitch->size[0] * i) + 1] = 0.0;
      }

      s = Merit->data[Merit->size[0] * i];
      for (i0 = 0; i0 < maxcands; i0++) {
        Merit->data[(i0 + Merit->size[0] * i) + 1] = 1.0 - s;
      }
    }
  }

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  for (i = 0; i <= numframes; i++) {
    RPitch->data[(maxcands + RPitch->size[0] * i) - 1] = BestPitch->
      data[BestPitch->size[0] * i];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    if (BestPitch->data[BestPitch->size[0] * i] > 0.0) {
      /*  voiced */
      Merit->data[(maxcands + Merit->size[0] * i) - 1] = Merit->data[Merit->
        size[0] * i];
    } else {
      /*  unvoiced */
      s = FrmEnergy->data[i] / 2.0;
      if ((1.0 <= s) || rtIsNaN(s)) {
        d0 = 1.0;
      } else {
        d0 = s;
      }

      Merit->data[(maxcands + Merit->size[0] * i) - 1] = 1.0 - d0;
    }
  }

  emxFree_real_T(&BestPitch);

  /*   Copy over the SPitch array */
  loop_ub = SPitch->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    RPitch->data[(maxcands + RPitch->size[0] * i0) - 2] = SPitch->data
      [SPitch->size[0] * i0];
  }

  emxFree_real_T(&SPitch);
  loop_ub = FrmEnergy->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Merit->data[(maxcands + Merit->size[0] * i0) - 2] = FrmEnergy->
      data[FrmEnergy->size[0] * i0] / 5.0;
  }

  /* ============================================================================== */
  /*  Step 5. Use dyanamic programming to determine the final pitch */
  dynamic(RPitch, Merit, FrmEnergy, Pitch);
  *numfrms = Pitch->size[1];
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
  emxFree_real_T(&FrmEnergy);
  emxFree_real_T(&Merit);
  emxFree_real_T(&RPitch);
}

/*
 * File trailer for yaapt.c
 *
 * [EOF]
 */
