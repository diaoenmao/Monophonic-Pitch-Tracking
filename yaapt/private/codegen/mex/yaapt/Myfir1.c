/*
 * Myfir1.c
 *
 * Code generation for function 'Myfir1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myfir1.h"
#include "yaapt_emxutil.h"
#include "path1.h"
#include "eml_int_forloop_overflow_check.h"
#include "Myfirls.h"
#include "Myhamming.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = { 105, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo r_emlrtRSI = { 138, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo s_emlrtRSI = { 147, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo t_emlrtRSI = { 150, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo u_emlrtRSI = { 157, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo v_emlrtRSI = { 174, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRTEInfo h_emlrtRTEI = { 1, 18, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRTEInfo i_emlrtRTEI = { 138, 4, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtECInfo emlrtECI = { 2, 160, 5, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

/* Function Definitions */

/*
 * function [b,a] = Myfir1(N,Wn)
 */
void Myfir1(const emlrtStack *sp, real_T N, const real_T Wn[2], emxArray_real_T *
            b)
{
  emxArray_real_T *Window;
  int32_T nm1d2;
  const mxArray *y;
  char_T u[35];
  static const char_T varargin_1[35] = { 'N', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'a', ' ', 'r', 'e', 'a', 'l', ',', ' ', 'p', 'o', 's', 'i', 't',
    'i', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', '.' };

  const mxArray *m1;
  static const int32_T iv2[2] = { 1, 35 };

  boolean_T overflow;
  int32_T k;
  boolean_T exitg1;
  const mxArray *b_y;
  char_T b_u[47];
  static const char_T b_varargin_1[47] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n',
    'c', 'i', 'e', 's', ' ', 'm', 'u', 's', 't', ' ', 'f', 'a', 'l', 'l', ' ',
    'i', 'n', ' ', 'r', 'a', 'n', 'g', 'e', ' ', 'b', 'e', 't', 'w', 'e', 'e',
    'n', ' ', '0', ' ', 'a', 'n', 'd', ' ', '1', '.' };

  static const int32_T iv3[2] = { 1, 47 };

  const mxArray *c_y;
  char_T c_u[30];
  static const char_T c_varargin_1[30] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n',
    'c', 'i', 'e', 's', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 'i', 'n',
    'c', 'r', 'e', 'a', 's', 'i', 'n', 'g' };

  real_T ff[6];
  static const int32_T iv4[2] = { 1, 30 };

  real_T b_ff[6];
  emxArray_real_T *d_y;
  int32_T b_b[2];
  int32_T e_y[2];
  real_T f0;
  int32_T n;
  real_T r;
  real_T apnd;
  real_T ndbl;
  real_T cdiff;
  emxArray_creal_T *x;
  emxArray_creal_T *a;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 3U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 0);

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
  covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 0, false);
  covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 1, true);
  covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 2, true);
  if (covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 3, N != muDoubleScalarRound(N))
      || covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 4, N <= 0.0)) {
    covrtLogMcdc(&emlrtCoverageInstance, 3U, 0U, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 0, true);
    st.site = &q_emlrtRSI;
    for (nm1d2 = 0; nm1d2 < 35; nm1d2++) {
      u[nm1d2] = varargin_1[nm1d2];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(&st, 35, m1, &u[0]);
    emlrtAssign(&y, m1);
    b_st.site = &fq_emlrtRSI;
    o_error(&b_st, y, &emlrtMCI);
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 3U, 0U, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 0, false);
  }

  emxInit_real_T1(sp, &Window, 1, &i_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 1);

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
  covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 1, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 2);

  /* 'Myfir1:120' Ftype = 'DC-0'; */
  /*  make sure default 3 band filter is bandpass  */
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 3);

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
  covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 5, false);
  covrtLogMcdc(&emlrtCoverageInstance, 3U, 0U, 1, false);
  covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 2, false);

  /* 'Myfir1:136' if nw == 0 */
  covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 4);

  /*  replace the following with the default window of your choice.  */
  /*     Window = hamming(L);  */
  /* 'Myfir1:138' Window = Myhamming(L); */
  st.site = &r_emlrtRSI;
  Myhamming(&st, N + 1.0, Window);

  /*   */
  /*  to use Kaiser window, beta must be supplied  */
  /*  att = 60; % dB of attenuation desired in sidelobe  */
  /*  beta = 0.1102*(att-8.7);  */
  /*  wind = kaiser(L,beta);  */
  /* 'Myfir1:146' if  any( Wn<0 | Wn>1 ) */
  overflow = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!!((Wn[k] < 0.0) || (Wn[k] > 1.0))) {
      overflow = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 4, overflow)) {
    st.site = &s_emlrtRSI;
    for (nm1d2 = 0; nm1d2 < 47; nm1d2++) {
      b_u[nm1d2] = b_varargin_1[nm1d2];
    }

    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(&st, 47, m1, &b_u[0]);
    emlrtAssign(&b_y, m1);
    b_st.site = &fq_emlrtRSI;
    o_error(&b_st, b_y, &emlrtMCI);
  }

  /* 'Myfir1:149' if  any(diff(Wn)<0) */
  if (covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 5, !!(Wn[1] - Wn[0] < 0.0))) {
    st.site = &t_emlrtRSI;
    for (nm1d2 = 0; nm1d2 < 30; nm1d2++) {
      c_u[nm1d2] = c_varargin_1[nm1d2];
    }

    c_y = NULL;
    m1 = emlrtCreateCharArray(2, iv4);
    emlrtInitCharArrayR2013a(&st, 30, m1, &c_u[0]);
    emlrtAssign(&c_y, m1);
    b_st.site = &fq_emlrtRSI;
    o_error(&b_st, c_y, &emlrtMCI);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 5);

  /* 'Myfir1:153' Wn = Wn(:)'; */
  /* 'Myfir1:154' ff = [0,Wn(1:nbands-1); Wn(1:nbands-1),1]; */
  ff[0] = 0.0;
  for (nm1d2 = 0; nm1d2 < 2; nm1d2++) {
    ff[(nm1d2 + 1) << 1] = Wn[nm1d2];
    ff[1 + (nm1d2 << 1)] = Wn[nm1d2];
  }

  ff[5] = 1.0;

  /* 'Myfir1:155' mags = [mags(:)'; mags(:)']; */
  /*  hh_test = firls(L-1,ff(:),mags(:));  */
  /* 'Myfir1:157' hh = Myfirls(L-1,ff(:),mags(:)); */
  for (nm1d2 = 0; nm1d2 < 6; nm1d2++) {
    b_ff[nm1d2] = ff[nm1d2];
  }

  emxInit_real_T(sp, &d_y, 2, &h_emlrtRTEI, true);
  st.site = &u_emlrtRSI;
  Myfirls(&st, (N + 1.0) - 1.0, b_ff, b);

  /* 'Myfir1:160' b = hh.*Window(:)'; */
  k = Window->size[0];
  nm1d2 = d_y->size[0] * d_y->size[1];
  d_y->size[0] = 1;
  d_y->size[1] = k;
  emxEnsureCapacity(sp, (emxArray__common *)d_y, nm1d2, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (nm1d2 = 0; nm1d2 < k; nm1d2++) {
    d_y->data[d_y->size[0] * nm1d2] = Window->data[nm1d2];
  }

  for (nm1d2 = 0; nm1d2 < 2; nm1d2++) {
    b_b[nm1d2] = b->size[nm1d2];
  }

  for (nm1d2 = 0; nm1d2 < 2; nm1d2++) {
    e_y[nm1d2] = d_y->size[nm1d2];
  }

  if ((b_b[0] != e_y[0]) || (b_b[1] != e_y[1])) {
    emlrtSizeEqCheckNDR2012b(&b_b[0], &e_y[0], &emlrtECI, sp);
  }

  nm1d2 = b->size[0] * b->size[1];
  b->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)b, nm1d2, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  k = b->size[0];
  nm1d2 = b->size[1];
  k *= nm1d2;
  for (nm1d2 = 0; nm1d2 < k; nm1d2++) {
    b->data[nm1d2] *= d_y->data[nm1d2];
  }

  /* 'Myfir1:161' a = 1; */
  /* 'Myfir1:163' if SCALING */
  covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 6, true);

  /* 'Myfir1:164' if First_Band */
  covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 7, false);

  /* 'Myfir1:166' else */
  /* 'Myfir1:167' if ff(4)==1 */
  if (covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 8, ff[3] == 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 7);

    /*  unity gain at Fs/2  */
    /* 'Myfir1:169' f0 = 1; */
    f0 = 1.0;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 8);

    /* 'Myfir1:170' else */
    /*  unity gain at center of first passband  */
    /* 'Myfir1:172' f0 = mean(ff(3:4)); */
    f0 = (ff[2] + ff[3]) / 2.0;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 9);

  /* 'Myfir1:174' b = b / abs( exp(-j*2*pi*(0:L-1)*(f0/2))*(b.') ); */
  st.site = &v_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if (muDoubleScalarIsNaN((N + 1.0) - 1.0)) {
    n = 1;
    r = rtNaN;
    apnd = (N + 1.0) - 1.0;
    overflow = false;
  } else if ((N + 1.0) - 1.0 < 0.0) {
    n = 0;
    r = 0.0;
    apnd = (N + 1.0) - 1.0;
    overflow = false;
  } else if (muDoubleScalarIsInf((N + 1.0) - 1.0)) {
    n = 1;
    r = rtNaN;
    apnd = (N + 1.0) - 1.0;
    overflow = !(0.0 == (N + 1.0) - 1.0);
  } else {
    r = 0.0;
    ndbl = muDoubleScalarFloor(((N + 1.0) - 1.0) + 0.5);
    apnd = ndbl;
    cdiff = ndbl - ((N + 1.0) - 1.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarAbs((N
          + 1.0) - 1.0)) {
      ndbl++;
      apnd = (N + 1.0) - 1.0;
    } else if (cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }
  }

  d_st.site = &ab_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &mf_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  nm1d2 = d_y->size[0] * d_y->size[1];
  d_y->size[0] = 1;
  if (!(n >= 0)) {
    emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
  }

  d_y->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)d_y, nm1d2, (int32_T)sizeof
                    (real_T), &h_emlrtRTEI);
  if (n > 0) {
    d_y->data[0] = r;
    if (n > 1) {
      d_y->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      d_st.site = &bb_emlrtRSI;
      for (k = 1; k < nm1d2; k++) {
        d_y->data[k] = r + (real_T)k;
        d_y->data[(n - k) - 1] = apnd - (real_T)k;
      }

      if (nm1d2 << 1 == n - 1) {
        d_y->data[nm1d2] = (r + apnd) / 2.0;
      } else {
        d_y->data[nm1d2] = r + (real_T)nm1d2;
        d_y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_creal_T(&c_st, &x, 2, &h_emlrtRTEI, true);
  r = f0 / 2.0;
  nm1d2 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = d_y->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)x, nm1d2, (int32_T)sizeof(creal_T),
                    &h_emlrtRTEI);
  k = d_y->size[0] * d_y->size[1];
  for (nm1d2 = 0; nm1d2 < k; nm1d2++) {
    ndbl = d_y->data[nm1d2] * -0.0;
    apnd = d_y->data[nm1d2] * -6.2831853071795862;
    x->data[nm1d2].re = r * ndbl;
    x->data[nm1d2].im = r * apnd;
  }

  emxFree_real_T(&d_y);
  emxInit_creal_T(sp, &a, 2, &h_emlrtRTEI, true);
  st.site = &v_emlrtRSI;
  b_st.site = &de_emlrtRSI;
  nm1d2 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = x->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)a, nm1d2, (int32_T)sizeof(creal_T),
                    &h_emlrtRTEI);
  k = x->size[0] * x->size[1];
  for (nm1d2 = 0; nm1d2 < k; nm1d2++) {
    a->data[nm1d2] = x->data[nm1d2];
  }

  c_st.site = &eb_emlrtRSI;
  overflow = ((!(1 > x->size[1])) && (x->size[1] > 2147483646));
  if (overflow) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  for (k = 0; k + 1 <= x->size[1]; k++) {
    if (muDoubleScalarIsInf(a->data[k].im) && muDoubleScalarIsInf(a->data[k].re)
        && (a->data[k].re < 0.0)) {
      cdiff = 0.0;
      ndbl = 0.0;
    } else {
      r = muDoubleScalarExp(a->data[k].re / 2.0);
      cdiff = r * (r * muDoubleScalarCos(a->data[k].im));
      ndbl = r * (r * muDoubleScalarSin(a->data[k].im));
    }

    a->data[k].re = cdiff;
    a->data[k].im = ndbl;
  }

  emxFree_creal_T(&x);
  st.site = &v_emlrtRSI;
  nm1d2 = Window->size[0];
  Window->size[0] = b->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Window, nm1d2, (int32_T)sizeof
                    (real_T), &h_emlrtRTEI);
  k = b->size[1];
  for (nm1d2 = 0; nm1d2 < k; nm1d2++) {
    Window->data[nm1d2] = b->data[b->size[0] * nm1d2];
  }

  b_st.site = &ee_emlrtRSI;
  overflow = (a->size[1] == Window->size[0]);
  if (!overflow) {
    if ((a->size[1] == 1) || (Window->size[0] == 1)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &lf_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &kf_emlrtRTEI,
        "Coder:MATLAB:innerdim", 0);
    }
  }

  cdiff = 0.0;
  ndbl = 0.0;
  for (nm1d2 = 0; nm1d2 < a->size[1]; nm1d2++) {
    r = Window->data[nm1d2];
    apnd = a->data[a->size[0] * nm1d2].re * r - a->data[a->size[0] * nm1d2].im *
      0.0;
    r = a->data[a->size[0] * nm1d2].re * 0.0 + a->data[a->size[0] * nm1d2].im *
      r;
    cdiff += apnd;
    ndbl += r;
  }

  emxFree_creal_T(&a);
  emxFree_real_T(&Window);
  r = muDoubleScalarHypot(cdiff, ndbl);
  nm1d2 = b->size[0] * b->size[1];
  b->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)b, nm1d2, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  k = b->size[0];
  nm1d2 = b->size[1];
  k *= nm1d2;
  for (nm1d2 = 0; nm1d2 < k; nm1d2++) {
    b->data[nm1d2] /= r;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Myfir1.c) */
