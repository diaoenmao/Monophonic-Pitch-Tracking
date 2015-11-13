/*
 * File: yaapt.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_emxutil.h"
#include "dynamic.h"
#include "Mymedfilt1.h"
#include "eml_sort.h"
#include "cat.h"
#include "tm_trk.h"
#include "spec_trk.h"
#include "mean.h"
#include "Myspecgram.h"
#include "Myhanning.h"
#include "filter.h"
#include "Myfirls.h"
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
  double w[2];
  double ff[6];
  int i0;
  double b_ff[6];
  double hh[151];
  static const double dv0[151] = { 0.080000000000000016, 0.080403498154525133,
    0.081613284745228, 0.08362723739534017, 0.086441822947567748,
    0.090052103662449423, 0.094451745880829718, 0.099633031135249073,
    0.10558686969075876, 0.11230281649140433, 0.11976908948440362,
    0.12797259028987007, 0.13689892717982277, 0.14653244032616691,
    0.1568562292733543, 0.16785218258752421, 0.17950100963011367,
    0.19178227440019208, 0.20467443138615071, 0.21815486336385193,
    0.23219992107492521, 0.24678496471560279, 0.26188440716330758,
    0.2774717588651614, 0.29351967430966164, 0.30999999999999994,
    0.32688382384486359, 0.34414152588006663, 0.36174283023203269,
    0.379656858231965, 0.39785218258752419, 0.41629688251697783,
    0.4349585997490984, 0.45380459529056666, 0.4728018068612907,
    0.49191690689687945, 0.51111636101651581, 0.53036648685365584,
    0.54963351314634423, 0.56888363898348415, 0.58808309310312057,
    0.60719819313870937, 0.62619540470943347, 0.64504140025090173,
    0.66370311748302224, 0.68214781741247577, 0.70034314176803492,
    0.71825716976796738, 0.73585847411993344, 0.75311617615513637,
    0.76999999999999991, 0.78648032569033854, 0.80252824113483856,
    0.81811559283669255, 0.83321503528439733, 0.8478000789250747,
    0.86184513663614815, 0.87532556861384925, 0.88821772559980794,
    0.90049899036988634, 0.91214781741247575, 0.92314377072664577,
    0.9334675596738331, 0.94310107282017719, 0.95202740971013,
    0.9602309105155965, 0.96769718350859568, 0.97441313030924137,
    0.98036696886475094, 0.98554825411917035, 0.98994789633755065,
    0.99355817705243232, 0.9963727626046599, 0.99838671525477207,
    0.99959650184547488, 1.0, 0.99959650184547488, 0.99838671525477207,
    0.9963727626046599, 0.99355817705243232, 0.98994789633755065,
    0.98554825411917035, 0.98036696886475094, 0.97441313030924137,
    0.96769718350859568, 0.9602309105155965, 0.95202740971013,
    0.94310107282017719, 0.9334675596738331, 0.92314377072664577,
    0.91214781741247575, 0.90049899036988634, 0.88821772559980794,
    0.87532556861384925, 0.86184513663614815, 0.8478000789250747,
    0.83321503528439733, 0.81811559283669255, 0.80252824113483856,
    0.78648032569033854, 0.76999999999999991, 0.75311617615513637,
    0.73585847411993344, 0.71825716976796738, 0.70034314176803492,
    0.68214781741247577, 0.66370311748302224, 0.64504140025090173,
    0.62619540470943347, 0.60719819313870937, 0.58808309310312057,
    0.56888363898348415, 0.54963351314634423, 0.53036648685365584,
    0.51111636101651581, 0.49191690689687945, 0.4728018068612907,
    0.45380459529056666, 0.4349585997490984, 0.41629688251697783,
    0.39785218258752419, 0.379656858231965, 0.36174283023203269,
    0.34414152588006663, 0.32688382384486359, 0.30999999999999994,
    0.29351967430966164, 0.2774717588651614, 0.26188440716330758,
    0.24678496471560279, 0.23219992107492521, 0.21815486336385193,
    0.20467443138615071, 0.19178227440019208, 0.17950100963011367,
    0.16785218258752421, 0.1568562292733543, 0.14653244032616691,
    0.13689892717982277, 0.12797259028987007, 0.11976908948440362,
    0.11230281649140433, 0.10558686969075876, 0.099633031135249073,
    0.094451745880829718, 0.090052103662449423, 0.086441822947567748,
    0.08362723739534017, 0.081613284745228, 0.080403498154525133,
    0.080000000000000016 };

  double f0;
  double y;
  creal_T x[151];
  double N_F0_min;
  emxArray_real_T *tempData;
  int loop_ub;
  emxArray_real_T *DataB;
  int k;
  emxArray_real_T *b_tempData;
  emxArray_real_T *DataD;
  emxArray_real_T *b_DataB;
  double N_F0_max;
  emxArray_creal_T *SpecData;
  double b_y;
  int ixstart;
  emxArray_creal_T *b_x;
  int ix;
  int iy;
  emxArray_creal_T *b_SpecData;
  emxArray_real_T *c_y;
  emxArray_real_T *FrmEnergy;
  int i;
  emxArray_boolean_T *VUVEnergy;
  emxArray_real_T *b_DataD;
  emxArray_real_T *SPitch;
  emxArray_real_T *TPitch1;
  emxArray_real_T *TMerit1;
  emxArray_real_T *TPitch2;
  emxArray_real_T *TMerit2;
  emxArray_real_T *RPitch;
  emxArray_real_T *Merit;
  emxArray_real_T *b_Merit;
  int pStd_size[1];
  double pStd_data[1];
  int pAvg_size[1];
  double pAvg_data[1];
  emxArray_real_T *Idx;
  emxArray_int32_T *iidx;
  emxArray_real_T *r0;
  emxArray_real_T *b_RPitch;
  double d0;

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
  /* NONLINEAR Create the nonlinear processed signal */
  /*  */
  /*    [DataB, DataC, DataD, newFs] = nonlinear(DataA, Fs, Prm) creates */
  /*    nonlinear signal (squared signal) and applys filtering. */
  /*  */
  /*  INPUTS:  */
  /*    DataA: The original signal from read_audio.m  */
  /*    Fs:    The sampling rate for the signal */
  /*    Prm:   Array of parameters used to control performance */
  /*  */
  /*  OUTPUTS: */
  /*    DataB: The original signal, bandpass filtered with F1. */
  /*    DataC: The nonlinear signal, no filtering */
  /*    DataD: The nonlinear signal, bandpass filtered with F1. */
  /*    newFs: The sampling rate of the new signal  */
  /*    Creation date:  Jun. 30, 2006 */
  /*    Programers:     Hongbing Hu, Princy, Zahorian */
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
  /*  Do not decimate if Fs less than this */
  /*   Parameters for filtering original signal, with a broader band */
  /*  Creates the bandpass filters */
  /*  filter F1 */
  w[0] = 50.0 / (Fs / 2.0);
  w[1] = 1500.0 / (Fs / 2.0);

  /* FIR1   FIR filter design using the window method.  */
  /*    B = FIR1(N,Wn) designs an N'th order lowpass FIR digital filter  */
  /*    and returns the filter coefficients in length N+1 vector B.  */
  /*    The cut-off frequency Wn must be between 0 < Wn < 1.0, with 1.0   */
  /*    corresponding to half the sample rate.  The filter B is real and  */
  /*    has linear phase, i.e., even symmetric coefficients obeying B(k) =  */
  /*    B(N+2-k), k = 1,2,...,N+1.  */
  /*   */
  /*    If Wn is a two-element vector, Wn = [W1 W2], FIR1 returns an  */
  /*    order N bandpass filter with passband  W1 < W < W2.  */
  /*    B = FIR1(N,Wn,'high') designs a highpass filter.  */
  /*    B = FIR1(N,Wn,'stop') is a bandstop filter if Wn = [W1 W2].  */
  /*   */
  /*    If Wn is a multi-element vector,   */
  /*           Wn = [W1 W2 W3 W4 W5 ... WN],  */
  /*    FIR1 returns an order N multiband filter with bands  */
  /*     0 < W < W1, W1 < W < W2, ..., WN < W < 1.  */
  /*    B = FIR1(N,Wn,'DC-1') makes the first band a passband.  */
  /*    B = FIR1(N,Wn,'DC-0') makes the first band a stopband.  */
  /*   */
  /*    For filters with a passband near Fs/2, e.g., highpass  */
  /*    and bandstop filters, N must be even.  */
  /*      */
  /*    By default FIR1 uses a Hamming window.  Other available windows,  */
  /*    including Boxcar, Hanning, Bartlett, Blackman, Kaiser and Chebwin  */
  /*    can be specified with an optional trailing argument.  For example,  */
  /*    B = FIR1(N,Wn,kaiser(N+1,4)) uses a Kaiser window with beta=4.  */
  /*    B = FIR1(N,Wn,'high',chebwin(N+1,R)) uses a Chebyshev window.  */
  /*   */
  /*    By default, the filter is scaled so the center of the first pass band   */
  /*    has magnitude exactly one after windowing. Use a trailing 'noscale'   */
  /*    argument to prevent this scaling, e.g. B = FIR1(N,Wn,'noscale'),   */
  /*    B = FIR1(N,Wn,'high','noscale'), B = FIR1(N,Wn,wind,'noscale').  */
  /*   */
  /*    See also KAISERORD, FIRCLS1, FIR2, FIRLS, FIRCLS, CREMEZ,  */
  /*             REMEZ, FREQZ, FILTER.  */
  /*    FIR1 is an M-file implementation of program 5.2 in the IEEE  */
  /*    Programs for Digital Signal Processing tape.   */
  /*    Author(s): L. Shure  */
  /*               L. Shure, 4-5-90, revised  */
  /*               T. Krauss, 3-5-96, revised  */
  /*    Copyright (c) 1988-98 by The MathWorks, Inc.  */
  /*    $Revision: 1.20 $  $Date: 1997/12/02 18:36:03 $  */
  /*    Reference(s):  */
  /*      [1] "Programs for Digital Signal Processing", IEEE Press  */
  /*          John Wiley & Sons, 1979, pg. 5.2-1.  */
  /*  nargchk(2,5,nargin);  */
  /*  Up to 3 optional input arguments, always in this order:  */
  /*    1 - Filter type flag, can be 'high', 'stop', '', 'DC-0', or 'DC-1'  */
  /*    2 - Window vector  */
  /*    3 - 'noscale' flag  */
  /*  default optional parameter values:  */
  /*  Ftype = '';  */
  /*  Wind = [];  */
  /*  Scale = 'scale';  */
  /*  switch length(varargin)  */
  /*  case 1  */
  /*      if isstr(varargin{1})&(length(varargin{1})>0)  */
  /*          s = upper(varargin{1});  */
  /*          switch upper(s)  */
  /*          case {'SCALE','NOSCALE'}  */
  /*              Scale = s;  */
  /*          otherwise  */
  /*              Ftype = s;  */
  /*          end  */
  /*      else  */
  /*          Wind = varargin{1};  */
  /*      end  */
  /*  case 2  */
  /*      if isstr(varargin{1})  */
  /*          Ftype = varargin{1};  */
  /*      else  */
  /*          Wind = varargin{1};  */
  /*      end  */
  /*      if isstr(varargin{2})  */
  /*          Scale = varargin{2};  */
  /*      else  */
  /*          Wind = varargin{2};  */
  /*      end  */
  /*  case 3  */
  /*      Ftype = varargin{1};  */
  /*      Wind = varargin{2};  */
  /*      Scale = varargin{3};  */
  /*  end  */
  /*  switch upper(Scale)  */
  /*  case 'NOSCALE'  */
  /*      SCALING = 0;  */
  /*  case 'SCALE'  */
  /*  otherwise  */
  /*      error('Scaling option must be ''noscale'' or ''scale''.')  */
  /*  end  */
  /*  Ftype = upper(Ftype);  */
  /*  if ~strncmp(Ftype,'HIGH',1) & ~strncmp(Ftype,'STOP',1) & ...  */
  /*     ~strncmp(Ftype,'DC-0',4) & ~strncmp(Ftype,'DC-1',4) & ...  */
  /*     ~isempty(Ftype)  */
  /*      error('Filter type must be ''high'',''stop'',''DC-0'', or ''DC-1''.')  */
  /*  end  */
  /*  if (nbands > 2) & isempty(Ftype)  */
  /*  make sure default 3 band filter is bandpass  */
  /*  if (mags(nbands) & ~odd)  */
  /*        disp('For highpass and bandstop filters, order must be even.')  */
  /*        disp('Order is being increased by 1.')  */
  /*        N = N + 1;  L = L + 1;  */
  /*        odd = 1;  */
  /*  end  */
  /*  replace the following with the default window of your choice.  */
  /*   */
  /*  to use Kaiser window, beta must be supplied  */
  /*  att = 60; % dB of attenuation desired in sidelobe  */
  /*  beta = 0.1102*(att-8.7);  */
  /*  wind = kaiser(L,beta);  */
  ff[0] = 0.0;
  for (i0 = 0; i0 < 2; i0++) {
    ff[(i0 + 1) << 1] = w[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    ff[1 + (i0 << 1)] = w[i0];
  }

  ff[5] = 1.0;

  /*  hh_test = firls(L-1,ff(:),mags(:));  */
  for (i0 = 0; i0 < 6; i0++) {
    b_ff[i0] = ff[i0];
  }

  Myfirls(b_ff, hh);
  for (i0 = 0; i0 < 151; i0++) {
    hh[i0] *= dv0[i0];
  }

  if (ff[3] == 1.0) {
    /*  unity gain at Fs/2  */
    f0 = 1.0;
  } else {
    /*  unity gain at center of first passband  */
    f0 = (ff[2] + ff[3]) / 2.0;
  }

  y = f0 / 2.0;
  for (i0 = 0; i0 < 151; i0++) {
    x[i0].re = y * -0.0;
    x[i0].im = y * (-6.2831853071795862 * (double)i0);
    f0 = exp(x[i0].re / 2.0);
    N_F0_min = x[i0].im;
    x[i0].re = f0 * (f0 * cos(x[i0].im));
    x[i0].im = f0 * (f0 * sin(N_F0_min));
  }

  f0 = 0.0;
  N_F0_min = 0.0;
  for (i0 = 0; i0 < 151; i0++) {
    f0 += x[i0].re * hh[i0] - x[i0].im * 0.0;
    N_F0_min += x[i0].re * 0.0 + x[i0].im * hh[i0];
  }

  y = rt_hypotd_snf(f0, N_F0_min);
  for (i0 = 0; i0 < 151; i0++) {
    hh[i0] /= y;
  }

  emxInit_real_T(&tempData, 2);

  /*   b_F1_test = fir1(Filter_order,w); */
  /* filtering the original data with the bandpass filter, */
  /*  DataA   is original acoustic signal */
  /*  Original signal filtered with F1 */
  filter(hh, Data, tempData);

  /*  LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  if (1 > Data->size[1]) {
    loop_ub = 0;
  } else {
    loop_ub = Data->size[1];
  }

  emxInit_real_T(&DataB, 2);
  i0 = DataB->size[0] * DataB->size[1];
  DataB->size[0] = 1;
  DataB->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)DataB, i0, (int)sizeof(double));
  for (i0 = 0; i0 < loop_ub; i0++) {
    DataB->data[DataB->size[0] * i0] = tempData->data[i0];
  }

  /*    Create nonlinear version of signal */
  /*    Original signal */
  /*    DataC =  DataA; */
  /*    Absoulte value of the signal */
  /*    DataC =  abs(DataA); */
  /*    Squared value of the signal */
  for (i0 = 0; i0 < 2; i0++) {
    w[i0] = Data->size[i0];
  }

  i0 = tempData->size[0] * tempData->size[1];
  tempData->size[0] = 1;
  tempData->size[1] = (int)w[1];
  emxEnsureCapacity((emxArray__common *)tempData, i0, (int)sizeof(double));
  for (k = 0; k < (int)w[1]; k++) {
    tempData->data[k] = Data->data[k] * Data->data[k];
  }

  emxInit_real_T(&b_tempData, 2);

  /*    Nonlinear version filtered with F1 */
  i0 = b_tempData->size[0] * b_tempData->size[1];
  b_tempData->size[0] = 1;
  b_tempData->size[1] = tempData->size[1];
  emxEnsureCapacity((emxArray__common *)b_tempData, i0, (int)sizeof(double));
  loop_ub = tempData->size[0] * tempData->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_tempData->data[i0] = tempData->data[i0];
  }

  filter(hh, b_tempData, tempData);
  emxFree_real_T(&b_tempData);
  if (1 > Data->size[1]) {
    loop_ub = 0;
  } else {
    loop_ub = Data->size[1];
  }

  emxInit_real_T(&DataD, 2);
  i0 = DataD->size[0] * DataD->size[1];
  DataD->size[0] = 1;
  DataD->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)DataD, i0, (int)sizeof(double));
  for (i0 = 0; i0 < loop_ub; i0++) {
    DataD->data[DataD->size[0] * i0] = tempData->data[i0];
  }

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
  y = 25.0 * Fs / 1000.0;
  if (y < 0.0) {
    f0 = ceil(y);
  } else {
    f0 = floor(y);
  }

  y = 10.0 * Fs / 1000.0;
  emxInit_real_T(&b_DataB, 2);

  /*  If normalized low-frequency energy is below this, assume unvoiced frame */
  /*  Low freqeuncy range for NLFER */
  N_F0_min = rt_roundd_snf(120.0 / Fs * 8192.0);
  N_F0_max = rt_roundd_snf(400.0 / Fs * 8192.0);

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
  if (y < 0.0) {
    b_y = ceil(y);
  } else {
    b_y = floor(y);
  }

  Myspecgram(b_DataB, f0, f0 - b_y, SpecData);

  /*  SpecData_test = specgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  /*  Compute normalize low-frequency energy ratio  */
  emxFree_real_T(&b_DataB);
  if (N_F0_min > N_F0_max) {
    i0 = 0;
    ixstart = 0;
  } else {
    i0 = (int)N_F0_min - 1;
    ixstart = (int)N_F0_max;
  }

  emxInit_creal_T(&b_x, 2);
  loop_ub = SpecData->size[1];
  k = b_x->size[0] * b_x->size[1];
  b_x->size[0] = ixstart - i0;
  b_x->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_x, k, (int)sizeof(creal_T));
  for (k = 0; k < loop_ub; k++) {
    ix = ixstart - i0;
    for (iy = 0; iy < ix; iy++) {
      b_x->data[iy + b_x->size[0] * k] = SpecData->data[(i0 + iy) +
        SpecData->size[0] * k];
    }
  }

  emxInit_creal_T(&b_SpecData, 2);
  loop_ub = SpecData->size[1];
  k = b_SpecData->size[0] * b_SpecData->size[1];
  b_SpecData->size[0] = ixstart - i0;
  b_SpecData->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_SpecData, k, (int)sizeof(creal_T));
  for (k = 0; k < loop_ub; k++) {
    ix = ixstart - i0;
    for (iy = 0; iy < ix; iy++) {
      b_SpecData->data[iy + b_SpecData->size[0] * k] = SpecData->data[(i0 + iy)
        + SpecData->size[0] * k];
    }
  }

  for (k = 0; k < 2; k++) {
    w[k] = b_SpecData->size[k];
  }

  emxFree_creal_T(&b_SpecData);
  emxInit_real_T(&c_y, 2);
  k = c_y->size[0] * c_y->size[1];
  c_y->size[0] = (int)w[0];
  c_y->size[1] = (int)w[1];
  emxEnsureCapacity((emxArray__common *)c_y, k, (int)sizeof(double));
  k = SpecData->size[1];
  i0 = (ixstart - i0) * k;
  for (k = 0; k < i0; k++) {
    c_y->data[k] = rt_hypotd_snf(b_x->data[k].re, b_x->data[k].im);
  }

  emxFree_creal_T(&b_x);
  emxFree_creal_T(&SpecData);
  for (i0 = 0; i0 < 2; i0++) {
    w[i0] = c_y->size[i0];
  }

  emxInit_real_T(&FrmEnergy, 2);
  i0 = FrmEnergy->size[0] * FrmEnergy->size[1];
  FrmEnergy->size[0] = 1;
  FrmEnergy->size[1] = (int)w[1];
  emxEnsureCapacity((emxArray__common *)FrmEnergy, i0, (int)sizeof(double));
  if ((c_y->size[0] == 0) || (c_y->size[1] == 0)) {
    i0 = FrmEnergy->size[0] * FrmEnergy->size[1];
    FrmEnergy->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)FrmEnergy, i0, (int)sizeof(double));
    i0 = FrmEnergy->size[0] * FrmEnergy->size[1];
    FrmEnergy->size[1] = (int)w[1];
    emxEnsureCapacity((emxArray__common *)FrmEnergy, i0, (int)sizeof(double));
    loop_ub = (int)w[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      FrmEnergy->data[i0] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (i = 1; i <= c_y->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      f0 = c_y->data[ixstart];
      for (k = 2; k <= c_y->size[0]; k++) {
        ix++;
        f0 += c_y->data[ix];
      }

      iy++;
      FrmEnergy->data[iy] = f0;
    }
  }

  emxFree_real_T(&c_y);
  f0 = mean(FrmEnergy);
  i0 = FrmEnergy->size[0] * FrmEnergy->size[1];
  FrmEnergy->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)FrmEnergy, i0, (int)sizeof(double));
  ixstart = FrmEnergy->size[0];
  k = FrmEnergy->size[1];
  loop_ub = ixstart * k;
  for (i0 = 0; i0 < loop_ub; i0++) {
    FrmEnergy->data[i0] /= f0;
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
  emxInit_real_T(&b_Merit, 2);
  spec_trk(b_DataD, Fs, VUVEnergy, SPitch, tempData, pAvg_data, pAvg_size,
           pStd_data, pStd_size);

  /*   Step 3. Temporal pitch tracking based on NCCF */
  /*   Calculate a pitch track based on time-domain processing */
  /*   Pitch tracking from the filterd original signal  */
  tm_trk(DataB, Fs, SPitch, pStd_data, pStd_size, TPitch1, TMerit1);

  /*   Pitch tracking from the filterd nonlinear signal  */
  tm_trk(DataD, Fs, SPitch, pStd_data, pStd_size, TPitch2, TMerit2);

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
  ix = RPitch->size[0] - 1;
  iy = RPitch->size[1] - 1;
  i0 = b_Merit->size[0] * b_Merit->size[1];
  b_Merit->size[0] = Merit->size[0];
  b_Merit->size[1] = Merit->size[1];
  emxEnsureCapacity((emxArray__common *)b_Merit, i0, (int)sizeof(double));
  loop_ub = Merit->size[0] * Merit->size[1];
  emxFree_real_T(&b_DataD);
  emxFree_real_T(&TMerit2);
  emxFree_real_T(&TPitch2);
  emxFree_real_T(&TMerit1);
  emxFree_real_T(&TPitch1);
  emxFree_real_T(&DataD);
  emxFree_real_T(&DataB);
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_Merit->data[i0] = Merit->data[i0];
  }

  emxInit_real_T(&Idx, 2);
  emxInit_int32_T(&iidx, 2);
  e_eml_sort(b_Merit, Merit, iidx);
  i0 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity((emxArray__common *)Idx, i0, (int)sizeof(double));
  loop_ub = iidx->size[0] * iidx->size[1];
  emxFree_real_T(&b_Merit);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Idx->data[i0] = iidx->data[i0];
  }

  emxFree_int32_T(&iidx);
  ixstart = 0;
  b_emxInit_real_T(&r0, 1);
  while (ixstart <= iy) {
    loop_ub = Idx->size[0];
    i0 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
    for (i0 = 0; i0 < loop_ub; i0++) {
      r0->data[i0] = RPitch->data[((int)Idx->data[i0 + Idx->size[0] * ixstart] +
        RPitch->size[0] * ixstart) - 1];
    }

    loop_ub = r0->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      RPitch->data[i0 + RPitch->size[0] * ixstart] = r0->data[i0];
    }

    ixstart++;
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

  c_Mymedfilt1(b_RPitch, tempData);
  i0 = tempData->size[0] * tempData->size[1];
  tempData->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)tempData, i0, (int)sizeof(double));
  k = tempData->size[0];
  ixstart = tempData->size[1];
  loop_ub = k * ixstart;
  emxFree_real_T(&b_RPitch);
  for (i0 = 0; i0 < loop_ub; i0++) {
    tempData->data[i0] *= (double)VUVEnergy->data[i0];
  }

  emxFree_boolean_T(&VUVEnergy);

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  for (i = 0; i <= iy; i++) {
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
      RPitch->data[ix + RPitch->size[0] * i] = 0.0;
      Merit->data[ix + Merit->size[0] * i] = 1.0 - Merit->data[Merit->size[0] *
        i];
      for (k = 1; k - 1 <= ix - 2; k++) {
        if (RPitch->data[k + RPitch->size[0] * i] == 0.0) {
          Merit->data[k + Merit->size[0] * i] = 0.0;
        }
      }
    } else {
      /*  there was no voiced candidate from nccf fill in */
      /*  option for F0 from spectrogram */
      RPitch->data[RPitch->size[0] * i] = SPitch->data[i];
      y = FrmEnergy->data[i] / 2.0;
      if ((1.0 <= y) || rtIsNaN(y)) {
        Merit->data[Merit->size[0] * i] = 1.0;
      } else {
        Merit->data[Merit->size[0] * i] = y;
      }

      /*  all other candidates will be unvoiced */
      /*  with low merit */
      for (i0 = 0; i0 < ix; i0++) {
        RPitch->data[(i0 + RPitch->size[0] * i) + 1] = 0.0;
      }

      f0 = Merit->data[Merit->size[0] * i];
      for (i0 = 0; i0 < ix; i0++) {
        Merit->data[(i0 + Merit->size[0] * i) + 1] = 1.0 - f0;
      }
    }
  }

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  for (i = 0; i <= iy; i++) {
    RPitch->data[(ix + RPitch->size[0] * i) - 1] = tempData->data[tempData->
      size[0] * i];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    if (tempData->data[tempData->size[0] * i] > 0.0) {
      /*  voiced */
      Merit->data[(ix + Merit->size[0] * i) - 1] = Merit->data[Merit->size[0] *
        i];
    } else {
      /*  unvoiced */
      y = FrmEnergy->data[i] / 2.0;
      if ((1.0 <= y) || rtIsNaN(y)) {
        d0 = 1.0;
      } else {
        d0 = y;
      }

      Merit->data[(ix + Merit->size[0] * i) - 1] = 1.0 - d0;
    }
  }

  emxFree_real_T(&tempData);

  /*   Copy over the SPitch array */
  loop_ub = SPitch->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    RPitch->data[(ix + RPitch->size[0] * i0) - 2] = SPitch->data[SPitch->size[0]
      * i0];
  }

  emxFree_real_T(&SPitch);
  loop_ub = FrmEnergy->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Merit->data[(ix + Merit->size[0] * i0) - 2] = FrmEnergy->data
      [FrmEnergy->size[0] * i0] / 5.0;
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
  emxFree_real_T(&Merit);
  emxFree_real_T(&FrmEnergy);
  emxFree_real_T(&RPitch);
}

/*
 * File trailer for yaapt.c
 *
 * [EOF]
 */
