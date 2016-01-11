/*
 * File: nonlinear.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 12-Jan-2016 01:25:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "nonlinear.h"
#include "yaapt_emxutil.h"
#include "filter.h"
#include "Myfirls.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * NONLINEAR Create the nonlinear processed signal
 *
 *    [DataB, DataC, DataD, newFs] = nonlinear(DataA, Fs, Prm) creates
 *    nonlinear signal (squared signal) and applys filtering.
 *
 *  INPUTS:
 *    DataA: The original signal from read_audio.m
 *    Fs:    The sampling rate for the signal
 *    Prm:   Array of parameters used to control performance
 *
 *  OUTPUTS:
 *    DataB: The original signal, bandpass filtered with F1.
 *    DataC: The nonlinear signal, no filtering
 *    DataD: The nonlinear signal, bandpass filtered with F1.
 *    newFs: The sampling rate of the new signal
 * Arguments    : const emxArray_real_T *DataA
 *                double Fs
 *                emxArray_real_T *DataB
 *                emxArray_real_T *DataC
 *                emxArray_real_T *DataD
 *                double *newFs
 * Return Type  : void
 */
void nonlinear(const emxArray_real_T *DataA, double Fs, emxArray_real_T *DataB,
               emxArray_real_T *DataC, emxArray_real_T *DataD, double *newFs)
{
  double w[2];
  double ff[6];
  int k;
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
  double r;
  creal_T x[151];
  double y_re;
  emxArray_real_T *tempData;
  int loop_ub;

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
  for (k = 0; k < 2; k++) {
    ff[(k + 1) << 1] = w[k];
    ff[1 + (k << 1)] = w[k];
  }

  ff[5] = 1.0;

  /*  hh_test = firls(L-1,ff(:),mags(:));  */
  for (k = 0; k < 6; k++) {
    b_ff[k] = ff[k];
  }

  Myfirls(b_ff, hh);
  for (k = 0; k < 151; k++) {
    hh[k] *= dv0[k];
  }

  if (ff[3] == 1.0) {
    /*  unity gain at Fs/2  */
    f0 = 1.0;
  } else {
    /*  unity gain at center of first passband  */
    f0 = (ff[2] + ff[3]) / 2.0;
  }

  r = f0 / 2.0;
  for (k = 0; k < 151; k++) {
    x[k].re = r * -0.0;
    x[k].im = r * (-6.2831853071795862 * (double)k);
  }

  for (k = 0; k < 151; k++) {
    if (rtIsInf(x[k].im) && rtIsInf(x[k].re) && (x[k].re < 0.0)) {
      y_re = 0.0;
      r = 0.0;
    } else {
      r = exp(x[k].re / 2.0);
      y_re = r * (r * cos(x[k].im));
      r *= r * sin(x[k].im);
    }

    x[k].re = y_re;
    x[k].im = r;
  }

  y_re = 0.0;
  r = 0.0;
  for (k = 0; k < 151; k++) {
    y_re += x[k].re * hh[k] - x[k].im * 0.0;
    r += x[k].re * 0.0 + x[k].im * hh[k];
  }

  r = rt_hypotd_snf(y_re, r);
  for (k = 0; k < 151; k++) {
    hh[k] /= r;
  }

  emxInit_real_T(&tempData, 2);

  /*   b_F1_test = fir1(Filter_order,w); */
  /* filtering the original data with the bandpass filter, */
  /*  DataA   is original acoustic signal */
  /*  Original signal filtered with F1 */
  filter(hh, DataA, tempData);

  /*  LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  if (1 > DataA->size[1]) {
    loop_ub = 0;
  } else {
    loop_ub = DataA->size[1];
  }

  k = DataB->size[0] * DataB->size[1];
  DataB->size[0] = 1;
  DataB->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)DataB, k, (int)sizeof(double));
  for (k = 0; k < loop_ub; k++) {
    DataB->data[DataB->size[0] * k] = tempData->data[k];
  }

  /*    Create nonlinear version of signal */
  /*    Original signal */
  /*    DataC =  DataA; */
  /*    Absoulte value of the signal */
  /*    DataC =  abs(DataA); */
  /*    Squared value of the signal */
  k = DataC->size[0] * DataC->size[1];
  DataC->size[0] = 1;
  DataC->size[1] = DataA->size[1];
  emxEnsureCapacity((emxArray__common *)DataC, k, (int)sizeof(double));
  for (k = 0; k + 1 <= DataA->size[1]; k++) {
    DataC->data[k] = DataA->data[k] * DataA->data[k];
  }

  /*    Nonlinear version filtered with F1 */
  filter(hh, DataC, tempData);
  if (1 > DataA->size[1]) {
    loop_ub = 0;
  } else {
    loop_ub = DataA->size[1];
  }

  k = DataD->size[0] * DataD->size[1];
  DataD->size[0] = 1;
  DataD->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)DataD, k, (int)sizeof(double));
  for (k = 0; k < loop_ub; k++) {
    DataD->data[DataD->size[0] * k] = tempData->data[k];
  }

  emxFree_real_T(&tempData);
  *newFs = Fs;
}

/*
 * File trailer for nonlinear.c
 *
 * [EOF]
 */
