/*
 * Myspecgram.c
 *
 * Code generation for function 'Myspecgram'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myspecgram.h"
#include "spec_trk.h"
#include "yaapt_emxutil.h"
#include "any.h"
#include "fft.h"
#include "Myhanning.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo tc_emlrtRSI = { 53, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo uc_emlrtRSI = { 64, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo vc_emlrtRSI = { 65, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo wc_emlrtRSI = { 91, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo xc_emlrtRSI = { 92, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo m_emlrtRTEI = { 1, 23, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo n_emlrtRTEI = { 64, 1, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo o_emlrtRTEI = { 65, 1, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo p_emlrtRTEI = { 1, 44, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo q_emlrtRTEI = { 1, 34, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo emlrtECI = { 2, 84, 14, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo b_emlrtECI = { -1, 84, 5, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo c_emlrtECI = { 2, 87, 9, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 58, 5, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 66, 21, "colindex", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 66, 21, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 67, 5, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 67, 5, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 67, 13, "colindex", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 84, 12, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo i_emlrtDCI = { 84, 12, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

/* Function Definitions */

/*
 * function [yo,fo,to] = Myspecgram(x,nfft,Fs,window,noverlap)
 */
void Myspecgram(const emlrtStack *sp, emxArray_real_T *x, real_T window, real_T
                noverlap, emxArray_creal_T *yo)
{
  emxArray_real_T *b_window;
  int32_T nx;
  int32_T varargin_1;
  int32_T nwind;
  int32_T i10;
  int32_T i11;
  emxArray_real_T *b_x;
  int32_T apnd;
  int32_T cdiff;
  real_T anew;
  real_T ncol;
  int32_T n;
  real_T b_apnd;
  boolean_T n_too_large;
  real_T ndbl;
  real_T b_cdiff;
  emxArray_real_T *colindex;
  int32_T nm1d2;
  emxArray_real_T *y;
  emxArray_real_T *rowindex;
  emxArray_real_T *r0;
  emxArray_real_T *b_rowindex;
  int32_T c_rowindex[2];
  emxArray_real_T *b_colindex;
  int32_T c_colindex[2];
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  emxArray_real_T *c_window;
  int32_T d_window[2];
  int32_T b_yo[2];
  emxArray_creal_T *r3;
  emxArray_real_T *c_x;
  int16_T iv11[4097];
  emxArray_creal_T *c_yo;
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
  emxInit_real_T1(sp, &b_window, 1, &p_emlrtRTEI, true);

  /* SPECGRAM Calculate spectrogram from signal. */
  /*    B = SPECGRAM(A,NFFT,Fs,WINDOW,NOVERLAP) calculates the spectrogram for  */
  /*    the signal in vector A.  SPECGRAM splits the signal into overlapping  */
  /*    segments, windows each with the WINDOW vector and forms the columns of */
  /*    B with their zero-padded, length NFFT discrete Fourier transforms.  Thus */
  /*    each column of B contains an estimate of the short-term, time-localized */
  /*    frequency content of the signal A.  Time increases linearly across the  */
  /*    columns of B, from left to right.  Frequency increases linearly down  */
  /*    the rows, starting at 0.  If A is a length NX complex signal, B is a  */
  /*    complex matrix with NFFT rows and  */
  /*         k = fix((NX-NOVERLAP)/(length(WINDOW)-NOVERLAP))  */
  /*    columns.  If A is real, B still has k columns but the higher frequency */
  /*    components are truncated (because they are redundant); in that case, */
  /*    SPECGRAM returns B with NFFT/2+1 rows for NFFT even and (NFFT+1)/2 rows  */
  /*    for NFFT odd.  If you specify a scalar for WINDOW, SPECGRAM uses a  */
  /*    Hanning window of that length.  WINDOW must have length smaller than */
  /*    or equal to NFFT and greater than NOVERLAP.  NOVERLAP is the number of */
  /*    samples the sections of A overlap.  Fs is the sampling frequency */
  /*    which does not effect the spectrogram but is used for scaling plots. */
  /*  */
  /*    [B,F,T] = SPECGRAM(A,NFFT,Fs,WINDOW,NOVERLAP) returns a column of  */
  /*    frequencies F and one of times T at which the spectrogram is computed. */
  /*    F has length equal to the number of rows of B, T has length k. If you  */
  /*    leave Fs unspecified, SPECGRAM assumes a default of 2 Hz. */
  /*  */
  /*    B = SPECGRAM(A) produces the spectrogram of the signal A using default */
  /*    settings; the defaults are NFFT = minimum of 256 and the length of A, a */
  /*    Hanning window of length NFFT, and NOVERLAP = length(WINDOW)/2.  You  */
  /*    can tell SPECGRAM to use the default for any parameter by leaving it  */
  /*    off or using [] for that parameter, e.g. SPECGRAM(A,[],1000) */
  /*  */
  /*    SPECGRAM with no output arguments plots the absolute value of the  */
  /*    spectrogram in the current figure, using IMAGESC(T,F,20*log10(ABS(B))), */
  /*    AXIS XY, COLORMAP(JET) so the low frequency content of the first  */
  /*    portion of the signal is displayed in the lower left corner of the axes. */
  /*  */
  /*    SPECGRAM(A,F,Fs,WINDOW) where F is a vector of frequencies in Hz */
  /*    (with 2 or more elements) computes the spectrogram at those frequencies */
  /*    using either the chirp z-transform for more than 20 evenly spaced  */
  /*    frequencies or a polyphase decimation filterbank. */
  /*  */
  /*    See also PWELCH, CSD, COHERE and TFE. */
  /*    Author(s): L. Shure, 1-1-91 */
  /*               T. Krauss, 4-2-93, updated */
  /*    Copyright 1988-2002 The MathWorks, Inc. */
  /*    $Revision: 1.8 $  $Date: 2002/03/28 17:30:53 $ */
  /*  error(nargchk(1,5,nargin)) */
  /*  [msg,x,nfft,Fs,window,noverlap]=specgramchk(varargin); */
  /*  error(msg) */
  /* 'Myspecgram:53' window = Myhanning(window); */
  st.site = &tc_emlrtRSI;
  Myhanning(&st, window, b_window);

  /*  window = hanning(window); */
  /* 'Myspecgram:55' nx = length(x); */
  nx = x->size[1];

  /* 'Myspecgram:56' nwind = length(window); */
  varargin_1 = b_window->size[0];
  nwind = b_window->size[0];

  /* 'Myspecgram:57' if nx < nwind */
  if (x->size[1] < b_window->size[0]) {
    /*  zero-pad x if it has length less than the window length */
    /* 'Myspecgram:58' x(nwind)=0; */
    i10 = x->size[1];
    i11 = b_window->size[0];
    if (!((i11 >= 1) && (i11 <= i10))) {
      emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &k_emlrtBCI, sp);
    }

    x->data[i11 - 1] = 0.0;

    /* 'Myspecgram:58' nx=nwind; */
    nx = b_window->size[0];
  }

  emxInit_real_T1(sp, &b_x, 1, &q_emlrtRTEI, true);

  /* 'Myspecgram:60' x = x(:); */
  i10 = b_x->size[0];
  b_x->size[0] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_x, i10, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  apnd = x->size[1];
  for (i10 = 0; i10 < apnd; i10++) {
    b_x->data[i10] = x->data[i10];
  }

  /*  make a column vector for ease later */
  /* 'Myspecgram:61' window = window(:); */
  cdiff = b_window->size[0];
  i10 = b_window->size[0];
  b_window->size[0] = cdiff;
  emxEnsureCapacity(sp, (emxArray__common *)b_window, i10, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);

  /*  be consistent with data set */
  /* 'Myspecgram:63' ncol = fix((nx-noverlap)/(nwind-noverlap)); */
  anew = ((real_T)nx - noverlap) / ((real_T)varargin_1 - noverlap);
  if (anew < 0.0) {
    ncol = muDoubleScalarCeil(anew);
  } else {
    ncol = muDoubleScalarFloor(anew);
  }

  /* 'Myspecgram:64' colindex = 1 + (0:(ncol-1))*(nwind-noverlap); */
  st.site = &uc_emlrtRSI;
  b_st.site = &dd_emlrtRSI;
  c_st.site = &ed_emlrtRSI;
  if (muDoubleScalarIsNaN(ncol - 1.0)) {
    n = 1;
    anew = rtNaN;
    b_apnd = ncol - 1.0;
    n_too_large = false;
  } else if (ncol - 1.0 < 0.0) {
    n = 0;
    anew = 0.0;
    b_apnd = ncol - 1.0;
    n_too_large = false;
  } else if (muDoubleScalarIsInf(ncol - 1.0)) {
    n = 1;
    anew = rtNaN;
    b_apnd = ncol - 1.0;
    n_too_large = !(0.0 == ncol - 1.0);
  } else {
    anew = 0.0;
    ndbl = muDoubleScalarFloor((ncol - 1.0) + 0.5);
    b_apnd = ndbl;
    b_cdiff = ndbl - (ncol - 1.0);
    if (muDoubleScalarAbs(b_cdiff) < 4.4408920985006262E-16 * muDoubleScalarAbs
        (ncol - 1.0)) {
      ndbl++;
      b_apnd = ncol - 1.0;
    } else if (b_cdiff > 0.0) {
      b_apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    n_too_large = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }
  }

  d_st.site = &fd_emlrtRSI;
  if (!n_too_large) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &ee_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &colindex, 2, &n_emlrtRTEI, true);
  i10 = colindex->size[0] * colindex->size[1];
  colindex->size[0] = 1;
  if (!(n > 0)) {
    emlrtNonNegativeCheckR2012b(n, &f_emlrtDCI, &c_st);
  }

  colindex->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)colindex, i10, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  if (n > 0) {
    colindex->data[0] = anew;
    if (n > 1) {
      colindex->data[n - 1] = b_apnd;
      i10 = n - 1;
      nm1d2 = asr_s32(i10, 1U);
      d_st.site = &gd_emlrtRSI;
      for (cdiff = 1; cdiff < nm1d2; cdiff++) {
        colindex->data[cdiff] = anew + (real_T)cdiff;
        colindex->data[(n - cdiff) - 1] = b_apnd - (real_T)cdiff;
      }

      if (nm1d2 << 1 == n - 1) {
        colindex->data[nm1d2] = (anew + b_apnd) / 2.0;
      } else {
        colindex->data[nm1d2] = anew + (real_T)nm1d2;
        colindex->data[nm1d2 + 1] = b_apnd - (real_T)nm1d2;
      }
    }
  }

  anew = (real_T)varargin_1 - noverlap;
  i10 = colindex->size[0] * colindex->size[1];
  colindex->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)colindex, i10, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  cdiff = colindex->size[0];
  nm1d2 = colindex->size[1];
  apnd = cdiff * nm1d2;
  for (i10 = 0; i10 < apnd; i10++) {
    colindex->data[i10] = 1.0 + colindex->data[i10] * anew;
  }

  /* 'Myspecgram:65' rowindex = (1:nwind)'; */
  st.site = &vc_emlrtRSI;
  b_st.site = &dd_emlrtRSI;
  c_st.site = &ed_emlrtRSI;
  if (varargin_1 < 1) {
    n = 0;
    apnd = 0;
  } else {
    nm1d2 = (int32_T)muDoubleScalarFloor(((real_T)nwind - 1.0) + 0.5);
    apnd = nm1d2 + 1;
    cdiff = (nm1d2 - varargin_1) + 1;
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)varargin_1)
    {
      nm1d2++;
      apnd = varargin_1;
    } else if (cdiff > 0) {
      apnd = nm1d2;
    } else {
      nm1d2++;
    }

    if (nm1d2 >= 0) {
      n = nm1d2;
    } else {
      n = 0;
    }
  }

  emxInit_real_T(&c_st, &y, 2, &m_emlrtRTEI, true);
  d_st.site = &fd_emlrtRSI;
  i10 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)y, i10, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  if (n > 0) {
    y->data[0] = 1.0;
    if (n > 1) {
      y->data[n - 1] = apnd;
      i10 = n - 1;
      nm1d2 = asr_s32(i10, 1U);
      d_st.site = &gd_emlrtRSI;
      for (cdiff = 1; cdiff < nm1d2; cdiff++) {
        y->data[cdiff] = 1.0 + (real_T)cdiff;
        y->data[(n - cdiff) - 1] = apnd - cdiff;
      }

      if (nm1d2 << 1 == n - 1) {
        y->data[nm1d2] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[nm1d2] = 1.0 + (real_T)nm1d2;
        y->data[nm1d2 + 1] = apnd - nm1d2;
      }
    }
  }

  emxInit_real_T1(&c_st, &rowindex, 1, &o_emlrtRTEI, true);
  i10 = rowindex->size[0];
  rowindex->size[0] = y->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowindex, i10, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  apnd = y->size[1];
  for (i10 = 0; i10 < apnd; i10++) {
    rowindex->data[i10] = y->data[y->size[0] * i10];
  }

  emxFree_real_T(&y);

  /* 'Myspecgram:66' if length(x)<(nwind+colindex(ncol)-1) */
  nm1d2 = x->size[1];
  i10 = colindex->size[1];
  if (ncol != (int32_T)ncol) {
    emlrtIntegerCheckR2012b(ncol, &g_emlrtDCI, sp);
  }

  i11 = (int32_T)ncol;
  if (!((i11 >= 1) && (i11 <= i10))) {
    emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &l_emlrtBCI, sp);
  }

  if (nm1d2 < ((real_T)varargin_1 + colindex->data[i11 - 1]) - 1.0) {
    /* 'Myspecgram:67' x(nwind+colindex(ncol)-1) = 0; */
    nm1d2 = x->size[1];
    i10 = colindex->size[1];
    i11 = (int32_T)ncol;
    if (!((i11 >= 1) && (i11 <= i10))) {
      emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &n_emlrtBCI, sp);
    }

    anew = ((real_T)varargin_1 + colindex->data[i11 - 1]) - 1.0;
    if (anew != (int32_T)muDoubleScalarFloor(anew)) {
      emlrtIntegerCheckR2012b(anew, &h_emlrtDCI, sp);
    }

    i10 = (int32_T)anew;
    if (!((i10 >= 1) && (i10 <= nm1d2))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, nm1d2, &m_emlrtBCI, sp);
    }

    b_x->data[i10 - 1] = 0.0;

    /*  zero-pad x */
  }

  /* 'Myspecgram:70' if length(nfft)>1 */
  /* 'Myspecgram:74' else */
  /* 'Myspecgram:75' evenly_spaced = 1; */
  /* 'Myspecgram:76' use_chirp = 0; */
  /* 'Myspecgram:79' if (length(nfft)==1) | use_chirp */
  /* 'Myspecgram:80' y = complex(zeros(nwind,ncol)); */
  i10 = yo->size[0] * yo->size[1];
  yo->size[0] = varargin_1;
  yo->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)yo, i10, (int32_T)sizeof(creal_T),
                    &m_emlrtRTEI);
  apnd = varargin_1 * (int32_T)ncol;
  for (i10 = 0; i10 < apnd; i10++) {
    yo->data[i10].re = 0.0;
    yo->data[i10].im = 0.0;
  }

  emxInit_real_T(sp, &r0, 2, &m_emlrtRTEI, true);

  /*  put x into columns of y with the proper offset */
  /*  should be able to do this with fancy indexing! */
  /* 'Myspecgram:84' y(:) = x(rowindex(:,ones(1,ncol))+colindex(ones(nwind,1),:)-1); */
  apnd = rowindex->size[0];
  i10 = r0->size[0] * r0->size[1];
  r0->size[0] = apnd;
  r0->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i10, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  n = (int32_T)ncol;
  for (i10 = 0; i10 < n; i10++) {
    for (i11 = 0; i11 < apnd; i11++) {
      r0->data[i11 + r0->size[0] * i10] = rowindex->data[i11];
    }
  }

  emxInit_real_T(sp, &b_rowindex, 2, &m_emlrtRTEI, true);
  apnd = rowindex->size[0];
  i10 = b_rowindex->size[0] * b_rowindex->size[1];
  b_rowindex->size[0] = apnd;
  b_rowindex->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)b_rowindex, i10, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  n = (int32_T)ncol;
  for (i10 = 0; i10 < n; i10++) {
    for (i11 = 0; i11 < apnd; i11++) {
      b_rowindex->data[i11 + b_rowindex->size[0] * i10] = rowindex->data[i11];
    }
  }

  for (i10 = 0; i10 < 2; i10++) {
    c_rowindex[i10] = b_rowindex->size[i10];
  }

  emxFree_real_T(&b_rowindex);
  emxInit_real_T(sp, &b_colindex, 2, &m_emlrtRTEI, true);
  apnd = colindex->size[1];
  i10 = b_colindex->size[0] * b_colindex->size[1];
  b_colindex->size[0] = nwind;
  b_colindex->size[1] = apnd;
  emxEnsureCapacity(sp, (emxArray__common *)b_colindex, i10, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  for (i10 = 0; i10 < apnd; i10++) {
    for (i11 = 0; i11 < nwind; i11++) {
      b_colindex->data[i11 + b_colindex->size[0] * i10] = colindex->
        data[colindex->size[0] * i10];
    }
  }

  for (i10 = 0; i10 < 2; i10++) {
    c_colindex[i10] = b_colindex->size[i10];
  }

  emxFree_real_T(&b_colindex);
  emxInit_real_T(sp, &r1, 2, &m_emlrtRTEI, true);
  if ((c_rowindex[0] != c_colindex[0]) || (c_rowindex[1] != c_colindex[1])) {
    emlrtSizeEqCheckNDR2012b(&c_rowindex[0], &c_colindex[0], &emlrtECI, sp);
  }

  cdiff = b_x->size[0];
  i10 = r1->size[0] * r1->size[1];
  r1->size[0] = r0->size[0];
  r1->size[1] = r0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r1, i10, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  apnd = r0->size[1];
  for (i10 = 0; i10 < apnd; i10++) {
    n = r0->size[0];
    for (i11 = 0; i11 < n; i11++) {
      anew = (r0->data[i11 + r0->size[0] * i10] + colindex->data[colindex->size
              [0] * i10]) - 1.0;
      if (anew != (int32_T)muDoubleScalarFloor(anew)) {
        emlrtIntegerCheckR2012b(anew, &i_emlrtDCI, sp);
      }

      nm1d2 = (int32_T)anew;
      if (!((nm1d2 >= 1) && (nm1d2 <= cdiff))) {
        emlrtDynamicBoundsCheckR2012b(nm1d2, 1, cdiff, &o_emlrtBCI, sp);
      }

      r1->data[i11 + r1->size[0] * i10] = b_x->data[nm1d2 - 1];
    }
  }

  emxFree_real_T(&colindex);
  emxInit_real_T1(sp, &r2, 1, &m_emlrtRTEI, true);
  i10 = rowindex->size[0];
  i11 = r2->size[0];
  r2->size[0] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)r2, i11, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  apnd = (int32_T)ncol;
  emxFree_real_T(&rowindex);
  for (i11 = 0; i11 < apnd; i11++) {
    r2->data[i11] = 1.0;
  }

  i11 = yo->size[0] * yo->size[1];
  i10 *= r2->size[0];
  if (i11 != i10) {
    emlrtSizeEqCheck1DR2012b(i11, i10, &b_emlrtECI, sp);
  }

  i10 = yo->size[0] * yo->size[1];
  yo->size[0] = r1->size[0];
  yo->size[1] = r1->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)yo, i10, (int32_T)sizeof(creal_T),
                    &m_emlrtRTEI);
  apnd = r1->size[0] * r1->size[1];
  emxFree_real_T(&r2);
  for (i10 = 0; i10 < apnd; i10++) {
    yo->data[i10].re = r1->data[i10];
    yo->data[i10].im = 0.0;
  }

  emxFree_real_T(&r1);

  /*  Apply the window to the array of offset signal segments. */
  /* 'Myspecgram:87' y = window(:,ones(1,ncol)).*y; */
  apnd = b_window->size[0];
  i10 = r0->size[0] * r0->size[1];
  r0->size[0] = apnd;
  r0->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i10, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  n = (int32_T)ncol;
  for (i10 = 0; i10 < n; i10++) {
    for (i11 = 0; i11 < apnd; i11++) {
      r0->data[i11 + r0->size[0] * i10] = b_window->data[i11];
    }
  }

  emxInit_real_T(sp, &c_window, 2, &m_emlrtRTEI, true);
  apnd = b_window->size[0];
  i10 = c_window->size[0] * c_window->size[1];
  c_window->size[0] = apnd;
  c_window->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)c_window, i10, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  n = (int32_T)ncol;
  for (i10 = 0; i10 < n; i10++) {
    for (i11 = 0; i11 < apnd; i11++) {
      c_window->data[i11 + c_window->size[0] * i10] = b_window->data[i11];
    }
  }

  emxFree_real_T(&b_window);
  for (i10 = 0; i10 < 2; i10++) {
    d_window[i10] = c_window->size[i10];
  }

  emxFree_real_T(&c_window);
  for (i10 = 0; i10 < 2; i10++) {
    b_yo[i10] = yo->size[i10];
  }

  if ((d_window[0] != b_yo[0]) || (d_window[1] != b_yo[1])) {
    emlrtSizeEqCheckNDR2012b(&d_window[0], &b_yo[0], &c_emlrtECI, sp);
  }

  i10 = yo->size[0] * yo->size[1];
  yo->size[0] = r0->size[0];
  yo->size[1] = r0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)yo, i10, (int32_T)sizeof(creal_T),
                    &m_emlrtRTEI);
  apnd = r0->size[0] * r0->size[1];
  for (i10 = 0; i10 < apnd; i10++) {
    yo->data[i10].re *= r0->data[i10];
    yo->data[i10].im *= r0->data[i10];
  }

  emxFree_real_T(&r0);
  emxInit_creal_T(sp, &r3, 2, &m_emlrtRTEI, true);

  /* 'Myspecgram:88' select=[]; */
  /* 'Myspecgram:89' if ~use_chirp */
  /*  USE FFT */
  /*  now fft y which does the columns */
  /* 'Myspecgram:91' y = fft(y,nfft); */
  st.site = &wc_emlrtRSI;
  fft(&st, yo, r3);
  i10 = yo->size[0] * yo->size[1];
  yo->size[0] = 8192;
  yo->size[1] = r3->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)yo, i10, (int32_T)sizeof(creal_T),
                    &m_emlrtRTEI);
  apnd = r3->size[0] * r3->size[1];
  for (i10 = 0; i10 < apnd; i10++) {
    yo->data[i10] = r3->data[i10];
  }

  emxFree_creal_T(&r3);
  emxInit_real_T1(sp, &c_x, 1, &m_emlrtRTEI, true);

  /* 'Myspecgram:92' if ~any(any(imag(x))) */
  i10 = c_x->size[0];
  c_x->size[0] = b_x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_x, i10, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  apnd = b_x->size[0];
  for (i10 = 0; i10 < apnd; i10++) {
    c_x->data[i10] = 0.0;
  }

  emxFree_real_T(&b_x);
  st.site = &xc_emlrtRSI;
  n_too_large = b_any(&st, c_x);
  emxFree_real_T(&c_x);
  if (!!!n_too_large) {
    /*  x purely real */
    /* 'Myspecgram:93' if rem(nfft,2) */
    /* 'Myspecgram:95' else */
    /* 'Myspecgram:96' select = 1:nfft/2+1; */
    /* 'Myspecgram:98' y = y(select,:); */
    for (i10 = 0; i10 < 4097; i10++) {
      iv11[i10] = (int16_T)(1 + i10);
    }

    emxInit_creal_T(sp, &c_yo, 2, &m_emlrtRTEI, true);
    cdiff = yo->size[1];
    i10 = c_yo->size[0] * c_yo->size[1];
    c_yo->size[0] = 4097;
    c_yo->size[1] = cdiff;
    emxEnsureCapacity(sp, (emxArray__common *)c_yo, i10, (int32_T)sizeof(creal_T),
                      &m_emlrtRTEI);
    for (i10 = 0; i10 < cdiff; i10++) {
      for (i11 = 0; i11 < 4097; i11++) {
        c_yo->data[i11 + c_yo->size[0] * i10] = yo->data[(iv11[i11] + yo->size[0]
          * i10) - 1];
      }
    }

    i10 = yo->size[0] * yo->size[1];
    yo->size[0] = c_yo->size[0];
    yo->size[1] = c_yo->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)yo, i10, (int32_T)sizeof(creal_T),
                      &m_emlrtRTEI);
    apnd = c_yo->size[1];
    for (i10 = 0; i10 < apnd; i10++) {
      n = c_yo->size[0];
      for (i11 = 0; i11 < n; i11++) {
        yo->data[i11 + yo->size[0] * i10] = c_yo->data[i11 + c_yo->size[0] * i10];
      }
    }

    emxFree_creal_T(&c_yo);
  } else {
    /* 'Myspecgram:99' else */
    /* 'Myspecgram:100' select = 1:nfft; */
  }

  /* 'Myspecgram:102' f = (select - 1)'*Fs/nfft; */
  /* 'Myspecgram:124' t = (colindex-1)'/Fs; */
  /*  take abs, and use image to display results */
  /*  if nargout == 0 */
  /*      newplot; */
  /*      if length(t)==1 */
  /*          imagesc([0 1/f(2)],f,20*log10(abs(y)+eps));axis xy; colormap(jet) */
  /*      else */
  /*          imagesc(t,f,20*log10(abs(y)+eps));axis xy; colormap(jet) */
  /*      end */
  /*      xlabel('Time') */
  /*      ylabel('Frequency') */
  /* 'Myspecgram:136' if nargout == 1 */
  /* 'Myspecgram:137' yo = y; */
  /*  function [msg,x,nfft,Fs,window,noverlap] = specgramchk(P) */
  /*  %SPECGRAMCHK Helper function for SPECGRAM. */
  /*  %   SPECGRAMCHK(P) takes the cell array P and uses each cell as  */
  /*  %   an input argument.  Assumes P has between 1 and 5 elements. */
  /*   */
  /*  msg = []; */
  /*   */
  /*  x = P{1};  */
  /*  if (length(P) > 1) & ~isempty(P{2}) */
  /*      nfft = P{2}; */
  /*  else */
  /*      nfft = min(length(x),256); */
  /*  end */
  /*  if (length(P) > 2) & ~isempty(P{3}) */
  /*      Fs = P{3}; */
  /*  else */
  /*      Fs = 2; */
  /*  end */
  /*  if length(P) > 3 & ~isempty(P{4}) */
  /*      window = P{4};  */
  /*  else */
  /*      if length(nfft) == 1 */
  /*          window = hanning(nfft); */
  /*      else */
  /*          msg = 'You must specify a window function.'; */
  /*      end */
  /*  end */
  /*  if length(window) == 1, window = hanning(window); end */
  /*  if (length(P) > 4) & ~isempty(P{5}) */
  /*      noverlap = P{5}; */
  /*  else */
  /*      noverlap = ceil(length(window)/2); */
  /*  end */
  /*   */
  /*  % NOW do error checking */
  /*  if (length(nfft)==1) & (nfft<length(window)),  */
  /*      msg = 'Requires window''s length to be no greater than the FFT length.'; */
  /*  end */
  /*  if (noverlap >= length(window)), */
  /*      msg = 'Requires NOVERLAP to be strictly less than the window length.'; */
  /*  end */
  /*  if (length(nfft)==1) & (nfft ~= abs(round(nfft))) */
  /*      msg = 'Requires positive integer values for NFFT.'; */
  /*  end */
  /*  if (noverlap ~= abs(round(noverlap))), */
  /*      msg = 'Requires positive integer value for NOVERLAP.'; */
  /*  end */
  /*  if min(size(x))~=1, */
  /*      msg = 'Requires vector (either row or column) input.'; */
  /*  end */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Myspecgram.c) */
