/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nonlinear.c
 *
 * Code generation for function 'nonlinear'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "nonlinear.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "Myfirls.h"
#include "filter.h"
#include "scalexpAlloc.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 54, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo k_emlrtRSI = { 63, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo l_emlrtRSI = { 75, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo m_emlrtRSI = { 79, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo n_emlrtRSI = { 146, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo o_emlrtRSI = { 149, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo p_emlrtRSI = { 156, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo tb_emlrtRSI = { 49, "power",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo ub_emlrtRSI = { 58, "power",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo vb_emlrtRSI = { 73, "applyScalarFunction",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m" };

static emlrtRSInfo wb_emlrtRSI = { 132, "applyScalarFunction",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m" };

static emlrtRTEInfo c_emlrtRTEI = { 1, 40, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRTEInfo e_emlrtRTEI = { 63, 1, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 65, 9, "tempData", "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 82, 9, "tempData", "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 0 };

/* Function Definitions */

/*
 * function[DataB, DataC, DataD, newFs] = nonlinear(DataA, Fs, Prm)
 */
void nonlinear(yaaptStackData *SD, const emlrtStack *sp, const emxArray_real_T
               *DataA, real_T Fs, emxArray_real_T *DataB, emxArray_real_T *DataC,
               emxArray_real_T *DataD, real_T *newFs)
{
  int32_T lenDataA;
  real_T w[2];
  boolean_T overflow;
  int32_T k;
  boolean_T exitg1;
  static const char_T varargin_1[47] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'm', 'u', 's', 't', ' ', 'f', 'a', 'l', 'l', ' ', 'i',
    'n', ' ', 'r', 'a', 'n', 'g', 'e', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n',
    ' ', '0', ' ', 'a', 'n', 'd', ' ', '1', '.' };

  char_T u[47];
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 47 };

  const mxArray *m1;
  static const char_T b_varargin_1[30] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n',
    'c', 'i', 'e', 's', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 'i', 'n',
    'c', 'r', 'e', 'a', 's', 'i', 'n', 'g' };

  char_T b_u[30];
  const mxArray *b_y;
  static const int32_T iv6[2] = { 1, 30 };

  real_T ff[6];
  real_T b_ff[6];
  real_T hh[151];
  static const real_T dv0[151] = { 0.080000000000000016, 0.080403498154525133,
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

  real_T f0;
  real_T r;
  creal_T x[151];
  real_T y_re;
  emxArray_real_T *tempData;
  int32_T loop_ub;
  int32_T b_k;
  int32_T c_k;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

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
  /* 'nonlinear:33' Fs_min = 1000; */
  /*  Do not decimate if Fs less than this */
  /*   Parameters for filtering original signal, with a broader band */
  /* 'nonlinear:36' Filter_order = Prm.bp_forder; */
  /* 'nonlinear:37' F_hp = Prm.bp_low; */
  /* 'nonlinear:38' F_lp = Prm.bp_high; */
  /* 'nonlinear:40' if (Fs > Fs_min) */
  /*  Creates the bandpass filters */
  /* 'nonlinear:48' lenDataA = length(DataA); */
  lenDataA = DataA->size[1];

  /*  filter F1 */
  /* 'nonlinear:51' w1  = (F_hp / (Fs/2)); */
  /* 'nonlinear:52' w2  = (F_lp / (Fs/2)); */
  /* 'nonlinear:53' w   = [w1 w2]; */
  w[0] = 50.0 / (Fs / 2.0);
  w[1] = 1500.0 / (Fs / 2.0);

  /* 'nonlinear:54' b_F1 = Myfir1(Filter_order,w); */
  st.site = &j_emlrtRSI;

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
  /* 'Myfir1:60' Wind = []; */
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
  /* 'Myfir1:99' SCALING = 1; */
  /*  otherwise  */
  /*      error('Scaling option must be ''noscale'' or ''scale''.')  */
  /*  end  */
  /* 'Myfir1:104' if isempty(N) | ~isnumeric(N) | ~isreal(N) | N~=round(N) | N<=0 */
  /*  Ftype = upper(Ftype);  */
  /*  if ~strncmp(Ftype,'HIGH',1) & ~strncmp(Ftype,'STOP',1) & ...  */
  /*     ~strncmp(Ftype,'DC-0',4) & ~strncmp(Ftype,'DC-1',4) & ...  */
  /*     ~isempty(Ftype)  */
  /*      error('Filter type must be ''high'',''stop'',''DC-0'', or ''DC-1''.')  */
  /*  end  */
  /* 'Myfir1:115' nw = length(Wind); */
  /* 'Myfir1:117' nbands = length(Wn) + 1; */
  /*  if (nbands > 2) & isempty(Ftype)  */
  /* 'Myfir1:119' if (nbands > 2) */
  /* 'Myfir1:120' Ftype = 'DC-0'; */
  /*  make sure default 3 band filter is bandpass  */
  /* 'Myfir1:122' First_Band = isempty(strfind('DC-0',Ftype)) & isempty(strfind('HIGH',Ftype)); */
  /* 'Myfir1:123' mags = rem( First_Band + (0:nbands-1), 2); */
  /* 'Myfir1:125' L = N + 1; */
  /* 'Myfir1:126' odd = rem(L, 2); */
  /*  if (mags(nbands) & ~odd)  */
  /*        disp('For highpass and bandstop filters, order must be even.')  */
  /*        disp('Order is being increased by 1.')  */
  /*        N = N + 1;  L = L + 1;  */
  /*        odd = 1;  */
  /*  end  */
  /* 'Myfir1:133' if nw ~= 0 & nw ~= L */
  /* 'Myfir1:136' if nw == 0 */
  /*  replace the following with the default window of your choice.  */
  /* 'Myfir1:137' Window = hamming(L); */
  /*   */
  /*  to use Kaiser window, beta must be supplied  */
  /*  att = 60; % dB of attenuation desired in sidelobe  */
  /*  beta = 0.1102*(att-8.7);  */
  /*  wind = kaiser(L,beta);  */
  /* 'Myfir1:145' if  any( Wn<0 | Wn>1 ) */
  overflow = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!!((w[k] < 0.0) || (w[k] > 1.0))) {
      overflow = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (overflow) {
    b_st.site = &n_emlrtRSI;
    for (k = 0; k < 47; k++) {
      u[k] = varargin_1[k];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv5);
    emlrtInitCharArrayR2013a(&b_st, 47, m1, &u[0]);
    emlrtAssign(&y, m1);
    c_st.site = &dk_emlrtRSI;
    m_error(&c_st, y, &emlrtMCI);
  }

  /* 'Myfir1:148' if  any(diff(Wn)<0) */
  if (!!(w[1] - w[0] < 0.0)) {
    b_st.site = &o_emlrtRSI;
    for (k = 0; k < 30; k++) {
      b_u[k] = b_varargin_1[k];
    }

    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(&b_st, 30, m1, &b_u[0]);
    emlrtAssign(&b_y, m1);
    c_st.site = &dk_emlrtRSI;
    m_error(&c_st, b_y, &emlrtMCI);
  }

  /* 'Myfir1:152' Wn = Wn(:)'; */
  /* 'Myfir1:153' ff = [0,Wn(1:nbands-1); Wn(1:nbands-1),1]; */
  ff[0] = 0.0;
  for (k = 0; k < 2; k++) {
    ff[(k + 1) << 1] = w[k];
    ff[1 + (k << 1)] = w[k];
  }

  ff[5] = 1.0;

  /* 'Myfir1:154' mags = [mags(:)'; mags(:)']; */
  /*  hh_test = firls(L-1,ff(:),mags(:));  */
  /* 'Myfir1:156' hh = Myfirls(L-1,ff(:),mags(:)); */
  for (k = 0; k < 6; k++) {
    b_ff[k] = ff[k];
  }

  b_st.site = &p_emlrtRSI;
  Myfirls(SD, &b_st, b_ff, hh);

  /* 'Myfir1:159' b = hh.*Window(:)'; */
  for (k = 0; k < 151; k++) {
    hh[k] *= dv0[k];
  }

  /* 'Myfir1:160' a = 1; */
  /* 'Myfir1:162' if SCALING */
  /* 'Myfir1:163' if First_Band */
  /* 'Myfir1:165' else */
  /* 'Myfir1:166' if ff(4)==1 */
  if (ff[3] == 1.0) {
    /*  unity gain at Fs/2  */
    /* 'Myfir1:168' f0 = 1; */
    f0 = 1.0;
  } else {
    /* 'Myfir1:169' else */
    /*  unity gain at center of first passband  */
    /* 'Myfir1:171' f0 = mean(ff(3:4)); */
    f0 = (ff[2] + ff[3]) / 2.0;
  }

  /* 'Myfir1:173' b = b / abs( exp(-j*2*pi*(0:L-1)*(f0/2))*(b.') ); */
  r = f0 / 2.0;
  for (k = 0; k < 151; k++) {
    x[k].re = r * -0.0;
    x[k].im = r * (-6.2831853071795862 * (real_T)k);
  }

  for (k = 0; k < 151; k++) {
    if (muDoubleScalarIsInf(x[k].im) && muDoubleScalarIsInf(x[k].re) && (x[k].re
         < 0.0)) {
      y_re = 0.0;
      r = 0.0;
    } else {
      r = muDoubleScalarExp(x[k].re / 2.0);
      y_re = r * (r * muDoubleScalarCos(x[k].im));
      r *= r * muDoubleScalarSin(x[k].im);
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

  r = muDoubleScalarHypot(y_re, r);
  for (k = 0; k < 151; k++) {
    hh[k] /= r;
  }

  emxInit_real_T(&st, &tempData, 2, &e_emlrtRTEI, true);

  /*   b_F1_test = fir1(Filter_order,w); */
  /* 'nonlinear:56' a   = 1; */
  /* filtering the original data with the bandpass filter, */
  /*  DataA   is original acoustic signal */
  /*  Original signal filtered with F1 */
  /* 'nonlinear:63' tempData = filter(b_F1,a,DataA); */
  st.site = &k_emlrtRSI;
  filter(&st, hh, DataA, tempData);

  /*  LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  /* 'nonlinear:65' DataB = tempData(1:dec_factor:lenDataA); */
  if (1 > DataA->size[1]) {
    loop_ub = 0;
  } else {
    k = tempData->size[1];
    if (!(1 <= k)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, k, &nb_emlrtBCI, sp);
    }

    k = tempData->size[1];
    loop_ub = DataA->size[1];
    if (!((loop_ub >= 1) && (loop_ub <= k))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, k, &nb_emlrtBCI, sp);
    }
  }

  k = DataB->size[0] * DataB->size[1];
  DataB->size[0] = 1;
  DataB->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)DataB, k, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  for (k = 0; k < loop_ub; k++) {
    DataB->data[DataB->size[0] * k] = tempData->data[k];
  }

  /*    Create nonlinear version of signal */
  /*    Original signal */
  /*    DataC =  DataA; */
  /*    Absoulte value of the signal */
  /*    DataC =  abs(DataA); */
  /*    Squared value of the signal */
  /* 'nonlinear:75' DataC =  DataA .^2; */
  st.site = &l_emlrtRSI;
  b_st.site = &tb_emlrtRSI;
  c_st.site = &ub_emlrtRSI;
  k = tempData->size[0] * tempData->size[1];
  tempData->size[0] = 1;
  tempData->size[1] = DataA->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)tempData, k, (int32_T)sizeof
                    (real_T), &c_emlrtRTEI);
  loop_ub = DataA->size[0] * DataA->size[1];
  for (k = 0; k < loop_ub; k++) {
    tempData->data[k] = DataA->data[k];
  }

  d_st.site = &vb_emlrtRSI;
  k = DataC->size[0] * DataC->size[1];
  DataC->size[0] = 1;
  DataC->size[1] = DataA->size[1];
  emxEnsureCapacity(&d_st, (emxArray__common *)DataC, k, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  if (dimagree(DataC, DataA)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &md_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  k = DataA->size[1];
  d_st.site = &wb_emlrtRSI;
  if (1 > DataA->size[1]) {
    overflow = false;
  } else {
    overflow = (DataA->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  emlrtEnterParallelRegion(&c_st, omp_in_parallel());
  emlrtPushJmpBuf(&c_st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(c_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(c_k)

  for (b_k = 1; b_k <= k; b_k++) {
    c_k = b_k;
    DataC->data[c_k - 1] = tempData->data[c_k - 1] * tempData->data[c_k - 1];
  }

  emlrtPopJmpBuf(&c_st, &emlrtJBStack);
  emlrtExitParallelRegion(&c_st, omp_in_parallel());

  /*    Nonlinear version filtered with F1 */
  /* 'nonlinear:79' tempData = filter(b_F1,a,DataC); */
  st.site = &m_emlrtRSI;
  filter(&st, hh, DataC, tempData);

  /* 'nonlinear:80' LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  /* 'nonlinear:81' DataD = zeros(1, LenData_dec); */
  /* 'nonlinear:82' DataD = tempData(1:dec_factor:lenDataA); */
  if (1 > lenDataA) {
    loop_ub = 0;
  } else {
    k = tempData->size[1];
    if (!(1 <= k)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, k, &ob_emlrtBCI, sp);
    }

    k = tempData->size[1];
    if (!(lenDataA <= k)) {
      emlrtDynamicBoundsCheckR2012b(lenDataA, 1, k, &ob_emlrtBCI, sp);
    }

    loop_ub = lenDataA;
  }

  k = DataD->size[0] * DataD->size[1];
  DataD->size[0] = 1;
  DataD->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)DataD, k, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  for (k = 0; k < loop_ub; k++) {
    DataD->data[DataD->size[0] * k] = tempData->data[k];
  }

  emxFree_real_T(&tempData);

  /* 'nonlinear:84' newFs = Fs/dec_factor; */
  *newFs = Fs;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nonlinear.c) */
