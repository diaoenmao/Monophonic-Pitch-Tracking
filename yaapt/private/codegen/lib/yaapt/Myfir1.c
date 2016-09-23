/*
 * File: Myfir1.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myfir1.h"
#include "yaapt_emxutil.h"
#include "Myfirls.h"
#include "cos.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * FIR1   FIR filter design using the window method.
 *    B = FIR1(N,Wn) designs an N'th order lowpass FIR digital filter
 *    and returns the filter coefficients in length N+1 vector B.
 *    The cut-off frequency Wn must be between 0 < Wn < 1.0, with 1.0
 *    corresponding to half the sample rate.  The filter B is real and
 *    has linear phase, i.e., even symmetric coefficients obeying B(k) =
 *    B(N+2-k), k = 1,2,...,N+1.
 *
 *    If Wn is a two-element vector, Wn = [W1 W2], FIR1 returns an
 *    order N bandpass filter with passband  W1 < W < W2.
 *    B = FIR1(N,Wn,'high') designs a highpass filter.
 *    B = FIR1(N,Wn,'stop') is a bandstop filter if Wn = [W1 W2].
 *
 *    If Wn is a multi-element vector,
 *           Wn = [W1 W2 W3 W4 W5 ... WN],
 *    FIR1 returns an order N multiband filter with bands
 *     0 < W < W1, W1 < W < W2, ..., WN < W < 1.
 *    B = FIR1(N,Wn,'DC-1') makes the first band a passband.
 *    B = FIR1(N,Wn,'DC-0') makes the first band a stopband.
 *
 *    For filters with a passband near Fs/2, e.g., highpass
 *    and bandstop filters, N must be even.
 *
 *    By default FIR1 uses a Hamming window.  Other available windows,
 *    including Boxcar, Hanning, Bartlett, Blackman, Kaiser and Chebwin
 *    can be specified with an optional trailing argument.  For example,
 *    B = FIR1(N,Wn,kaiser(N+1,4)) uses a Kaiser window with beta=4.
 *    B = FIR1(N,Wn,'high',chebwin(N+1,R)) uses a Chebyshev window.
 *
 *    By default, the filter is scaled so the center of the first pass band
 *    has magnitude exactly one after windowing. Use a trailing 'noscale'
 *    argument to prevent this scaling, e.g. B = FIR1(N,Wn,'noscale'),
 *    B = FIR1(N,Wn,'high','noscale'), B = FIR1(N,Wn,wind,'noscale').
 *
 *    See also KAISERORD, FIRCLS1, FIR2, FIRLS, FIRCLS, CREMEZ,
 *             REMEZ, FREQZ, FILTER.
 * Arguments    : double N
 *                const double Wn[2]
 *                emxArray_real_T *b
 * Return Type  : void
 */
void Myfir1(double N, const double Wn[2], emxArray_real_T *b)
{
  int n;
  double r;
  double apnd;
  double ndbl;
  emxArray_real_T *hh;
  double cdiff;
  int k;
  emxArray_real_T *Window;
  int nm1d2;
  double ff[6];
  double b_ff[6];
  double f0;
  emxArray_creal_T *y;
  emxArray_creal_T *x;

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
  /*     Window = hamming(L);  */
  /* HAMMING HAMMING(N) returns the N-point Hamming window. */
  /* 	Copyright (c) 1984-94 by The MathWorks, Inc. */
  /*        $Revision: 1.4 $  $Date: 1994/01/25 17:59:14 $ */
  if (rtIsNaN((N + 1.0) - 1.0)) {
    n = 1;
    r = rtNaN;
    apnd = (N + 1.0) - 1.0;
  } else if ((N + 1.0) - 1.0 < 0.0) {
    n = 0;
    r = 0.0;
    apnd = (N + 1.0) - 1.0;
  } else if (rtIsInf((N + 1.0) - 1.0)) {
    n = 1;
    r = rtNaN;
    apnd = (N + 1.0) - 1.0;
  } else {
    r = 0.0;
    ndbl = floor(((N + 1.0) - 1.0) + 0.5);
    apnd = ndbl;
    cdiff = ndbl - ((N + 1.0) - 1.0);
    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs((N + 1.0) - 1.0)) {
      ndbl++;
      apnd = (N + 1.0) - 1.0;
    } else if (cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }
  }

  emxInit_real_T(&hh, 2);
  k = hh->size[0] * hh->size[1];
  hh->size[0] = 1;
  hh->size[1] = n;
  emxEnsureCapacity((emxArray__common *)hh, k, (int)sizeof(double));
  if (n > 0) {
    hh->data[0] = r;
    if (n > 1) {
      hh->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 1; k < nm1d2; k++) {
        hh->data[k] = r + (double)k;
        hh->data[(n - k) - 1] = apnd - (double)k;
      }

      if (nm1d2 << 1 == n - 1) {
        hh->data[nm1d2] = (r + apnd) / 2.0;
      } else {
        hh->data[nm1d2] = r + (double)nm1d2;
        hh->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T2(&Window, 1);
  k = Window->size[0];
  Window->size[0] = hh->size[1];
  emxEnsureCapacity((emxArray__common *)Window, k, (int)sizeof(double));
  nm1d2 = hh->size[1];
  for (k = 0; k < nm1d2; k++) {
    Window->data[k] = 6.2831853071795862 * hh->data[hh->size[0] * k] / ((N + 1.0)
      - 1.0);
  }

  b_cos(Window);
  k = Window->size[0];
  emxEnsureCapacity((emxArray__common *)Window, k, (int)sizeof(double));
  nm1d2 = Window->size[0];
  for (k = 0; k < nm1d2; k++) {
    Window->data[k] = 0.54 - 0.46 * Window->data[k];
  }

  /*   */
  /*  to use Kaiser window, beta must be supplied  */
  /*  att = 60; % dB of attenuation desired in sidelobe  */
  /*  beta = 0.1102*(att-8.7);  */
  /*  wind = kaiser(L,beta);  */
  ff[0] = 0.0;
  for (k = 0; k < 2; k++) {
    ff[(k + 1) << 1] = Wn[k];
    ff[1 + (k << 1)] = Wn[k];
  }

  ff[5] = 1.0;

  /*  hh_test = firls(L-1,ff(:),mags(:));  */
  for (k = 0; k < 6; k++) {
    b_ff[k] = ff[k];
  }

  Myfirls((N + 1.0) - 1.0, b_ff, hh);
  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = hh->size[1];
  emxEnsureCapacity((emxArray__common *)b, k, (int)sizeof(double));
  nm1d2 = hh->size[1];
  for (k = 0; k < nm1d2; k++) {
    b->data[b->size[0] * k] = hh->data[hh->size[0] * k] * Window->data[k];
  }

  emxFree_real_T(&Window);
  if (ff[3] == 1.0) {
    /*  unity gain at Fs/2  */
    f0 = 1.0;
  } else {
    /*  unity gain at center of first passband  */
    f0 = (ff[2] + ff[3]) / 2.0;
  }

  if (rtIsNaN((N + 1.0) - 1.0)) {
    n = 1;
    r = rtNaN;
    apnd = (N + 1.0) - 1.0;
  } else if ((N + 1.0) - 1.0 < 0.0) {
    n = 0;
    r = 0.0;
    apnd = (N + 1.0) - 1.0;
  } else if (rtIsInf((N + 1.0) - 1.0)) {
    n = 1;
    r = rtNaN;
    apnd = (N + 1.0) - 1.0;
  } else {
    r = 0.0;
    ndbl = floor(((N + 1.0) - 1.0) + 0.5);
    apnd = ndbl;
    cdiff = ndbl - ((N + 1.0) - 1.0);
    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs((N + 1.0) - 1.0)) {
      ndbl++;
      apnd = (N + 1.0) - 1.0;
    } else if (cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }
  }

  k = hh->size[0] * hh->size[1];
  hh->size[0] = 1;
  hh->size[1] = n;
  emxEnsureCapacity((emxArray__common *)hh, k, (int)sizeof(double));
  if (n > 0) {
    hh->data[0] = r;
    if (n > 1) {
      hh->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 1; k < nm1d2; k++) {
        hh->data[k] = r + (double)k;
        hh->data[(n - k) - 1] = apnd - (double)k;
      }

      if (nm1d2 << 1 == n - 1) {
        hh->data[nm1d2] = (r + apnd) / 2.0;
      } else {
        hh->data[nm1d2] = r + (double)nm1d2;
        hh->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_creal_T(&y, 2);
  r = f0 / 2.0;
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = hh->size[1];
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(creal_T));
  nm1d2 = hh->size[0] * hh->size[1];
  for (k = 0; k < nm1d2; k++) {
    ndbl = hh->data[k] * -0.0;
    apnd = hh->data[k] * -6.2831853071795862;
    y->data[k].re = r * ndbl;
    y->data[k].im = r * apnd;
  }

  emxFree_real_T(&hh);
  emxInit_creal_T(&x, 2);
  k = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)x, k, (int)sizeof(creal_T));
  nm1d2 = y->size[0] * y->size[1];
  for (k = 0; k < nm1d2; k++) {
    x->data[k] = y->data[k];
  }

  for (k = 0; k + 1 <= y->size[1]; k++) {
    if (rtIsInf(x->data[k].im) && rtIsInf(x->data[k].re) && (x->data[k].re < 0.0))
    {
      cdiff = 0.0;
      ndbl = 0.0;
    } else {
      r = exp(x->data[k].re / 2.0);
      cdiff = r * (r * cos(x->data[k].im));
      ndbl = r * (r * sin(x->data[k].im));
    }

    x->data[k].re = cdiff;
    x->data[k].im = ndbl;
  }

  emxFree_creal_T(&y);
  cdiff = 0.0;
  ndbl = 0.0;
  for (k = 0; k < x->size[1]; k++) {
    r = b->data[b->size[0] * k];
    apnd = x->data[x->size[0] * k].re * r - x->data[x->size[0] * k].im * 0.0;
    r = x->data[x->size[0] * k].re * 0.0 + x->data[x->size[0] * k].im * r;
    cdiff += apnd;
    ndbl += r;
  }

  emxFree_creal_T(&x);
  r = rt_hypotd_snf(cdiff, ndbl);
  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)b, k, (int)sizeof(double));
  nm1d2 = b->size[0];
  k = b->size[1];
  nm1d2 *= k;
  for (k = 0; k < nm1d2; k++) {
    b->data[k] /= r;
  }
}

/*
 * File trailer for Myfir1.c
 *
 * [EOF]
 */
