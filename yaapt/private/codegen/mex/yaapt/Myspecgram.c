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
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "any.h"
#include "fft.h"
#include "Myhanning.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo bc_emlrtRSI = { 53, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo cc_emlrtRSI = { 64, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo dc_emlrtRSI = { 65, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo ec_emlrtRSI = { 91, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo fc_emlrtRSI = { 92, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo l_emlrtRTEI = { 1, 23, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo n_emlrtRTEI = { 64, 1, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo o_emlrtRTEI = { 65, 1, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo p_emlrtRTEI = { 80, 5, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo q_emlrtRTEI = { 1, 44, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo r_emlrtRTEI = { 1, 34, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo f_emlrtECI = { 2, 84, 14, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo g_emlrtECI = { -1, 84, 5, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo h_emlrtECI = { 2, 87, 9, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 58, 5, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 66, 21, "colindex", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo f_emlrtDCI = { 66, 21, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 67, 5, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 67, 5, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 67, 13, "colindex", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 84, 12, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 84, 12, "Myspecgram",
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
  int32_T nwind;
  int32_T i6;
  int32_T i7;
  emxArray_real_T *b_x;
  int32_T apnd;
  int32_T i;
  real_T y;
  real_T ncol;
  int32_T n;
  real_T b_apnd;
  boolean_T n_too_large;
  real_T ndbl;
  real_T cdiff;
  const mxArray *b_y;
  static const int32_T iv15[2] = { 1, 21 };

  const mxArray *m7;
  char_T cv25[21];
  static const char_T cv26[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *colindex;
  emxArray_real_T *c_y;
  emxArray_real_T *rowindex;
  emxArray_creal_T *d_y;
  emxArray_real_T *b_rowindex;
  int32_T c_rowindex[2];
  emxArray_real_T *b_colindex;
  int32_T c_colindex[2];
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  emxArray_real_T *c_window;
  emxArray_creal_T *r4;
  emxArray_real_T *c_x;
  int16_T tmp_data[4097];
  emxArray_creal_T *e_y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  b_emxInit_real_T(sp, &b_window, 1, &q_emlrtRTEI, true);

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
  st.site = &bc_emlrtRSI;
  Myhanning(&st, window, b_window);

  /*  window = hanning(window); */
  /* 'Myspecgram:55' nx = length(x); */
  nx = x->size[1];

  /* 'Myspecgram:56' nwind = length(window); */
  nwind = b_window->size[0];

  /* 'Myspecgram:57' if nx < nwind */
  if (x->size[1] < b_window->size[0]) {
    /*  zero-pad x if it has length less than the window length */
    /* 'Myspecgram:58' x(nwind)=0; */
    i6 = x->size[1];
    i7 = b_window->size[0];
    x->data[emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &tb_emlrtBCI, sp) - 1] =
      0.0;

    /* 'Myspecgram:58' nx=nwind; */
    nx = b_window->size[0];
  }

  b_emxInit_real_T(sp, &b_x, 1, &r_emlrtRTEI, true);

  /* 'Myspecgram:60' x = x(:); */
  i6 = b_x->size[0];
  b_x->size[0] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_x, i6, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  apnd = x->size[1];
  for (i6 = 0; i6 < apnd; i6++) {
    b_x->data[i6] = x->data[i6];
  }

  /*  make a column vector for ease later */
  /* 'Myspecgram:61' window = window(:); */
  i = b_window->size[0];
  i6 = b_window->size[0];
  b_window->size[0] = i;
  emxEnsureCapacity(sp, (emxArray__common *)b_window, i6, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);

  /*  be consistent with data set */
  /* 'Myspecgram:63' ncol = fix((nx-noverlap)/(nwind-noverlap)); */
  y = ((real_T)nx - noverlap) / ((real_T)nwind - noverlap);
  if (y < 0.0) {
    ncol = muDoubleScalarCeil(y);
  } else {
    ncol = muDoubleScalarFloor(y);
  }

  /* 'Myspecgram:64' colindex = 1 + (0:(ncol-1))*(nwind-noverlap); */
  st.site = &cc_emlrtRSI;
  b_st.site = &ic_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsNaN(ncol - 1.0)) {
    n = 0;
    y = rtNaN;
    b_apnd = ncol - 1.0;
    n_too_large = false;
  } else if (ncol - 1.0 < 0.0) {
    n = -1;
    y = 0.0;
    b_apnd = ncol - 1.0;
    n_too_large = false;
  } else if (muDoubleScalarIsInf(ncol - 1.0)) {
    n = 0;
    y = rtNaN;
    b_apnd = ncol - 1.0;
    n_too_large = !(0.0 == ncol - 1.0);
  } else {
    y = 0.0;
    ndbl = muDoubleScalarFloor((ncol - 1.0) + 0.5);
    b_apnd = ndbl;
    cdiff = ndbl - (ncol - 1.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarAbs
        (ncol - 1.0)) {
      ndbl++;
      b_apnd = ncol - 1.0;
    } else if (cdiff > 0.0) {
      b_apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    n_too_large = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl - 1;
    } else {
      n = -1;
    }
  }

  d_st.site = &kc_emlrtRSI;
  if (!n_too_large) {
  } else {
    b_y = NULL;
    m7 = emlrtCreateCharArray(2, iv15);
    for (i = 0; i < 21; i++) {
      cv25[i] = cv26[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m7, cv25);
    emlrtAssign(&b_y, m7);
    e_st.site = &wk_emlrtRSI;
    f_st.site = &bk_emlrtRSI;
    f_error(&e_st, b_message(&f_st, b_y, &h_emlrtMCI), &i_emlrtMCI);
  }

  emxInit_real_T(&d_st, &colindex, 2, &n_emlrtRTEI, true);
  i6 = colindex->size[0] * colindex->size[1];
  colindex->size[0] = 1;
  colindex->size[1] = n + 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)colindex, i6, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  if (n + 1 > 0) {
    colindex->data[0] = y;
    if (n + 1 > 1) {
      colindex->data[n] = b_apnd;
      i6 = n + (n < 0);
      if (i6 >= 0) {
        i = (int32_T)((uint32_T)i6 >> 1);
      } else {
        i = ~(int32_T)((uint32_T)~i6 >> 1);
      }

      d_st.site = &lc_emlrtRSI;
      for (nx = 1; nx < i; nx++) {
        colindex->data[nx] = y + (real_T)nx;
        colindex->data[n - nx] = b_apnd - (real_T)nx;
      }

      if (i << 1 == n) {
        colindex->data[i] = (y + b_apnd) / 2.0;
      } else {
        colindex->data[i] = y + (real_T)i;
        colindex->data[i + 1] = b_apnd - (real_T)i;
      }
    }
  }

  y = (real_T)nwind - noverlap;
  i6 = colindex->size[0] * colindex->size[1];
  colindex->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)colindex, i6, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  i = colindex->size[0];
  nx = colindex->size[1];
  apnd = i * nx;
  for (i6 = 0; i6 < apnd; i6++) {
    colindex->data[i6] = 1.0 + colindex->data[i6] * y;
  }

  /* 'Myspecgram:65' rowindex = (1:nwind)'; */
  st.site = &dc_emlrtRSI;
  b_st.site = &ic_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  if (nwind < 1) {
    n = -1;
    apnd = 0;
  } else {
    i = (int32_T)muDoubleScalarFloor(((real_T)nwind - 1.0) + 0.5);
    apnd = i + 1;
    nx = (i - nwind) + 1;
    if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)nwind) {
      i++;
      apnd = nwind;
    } else if (nx > 0) {
      apnd = i;
    } else {
      i++;
    }

    n = i - 1;
  }

  emxInit_real_T(&c_st, &c_y, 2, &l_emlrtRTEI, true);
  d_st.site = &kc_emlrtRSI;
  i6 = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = n + 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)c_y, i6, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  if (n + 1 > 0) {
    c_y->data[0] = 1.0;
    if (n + 1 > 1) {
      c_y->data[n] = apnd;
      i6 = n + (n < 0);
      if (i6 >= 0) {
        i = (int32_T)((uint32_T)i6 >> 1);
      } else {
        i = ~(int32_T)((uint32_T)~i6 >> 1);
      }

      d_st.site = &lc_emlrtRSI;
      for (nx = 1; nx < i; nx++) {
        c_y->data[nx] = 1.0 + (real_T)nx;
        c_y->data[n - nx] = apnd - nx;
      }

      if (i << 1 == n) {
        c_y->data[i] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        c_y->data[i] = 1.0 + (real_T)i;
        c_y->data[i + 1] = apnd - i;
      }
    }
  }

  b_emxInit_real_T(&c_st, &rowindex, 1, &o_emlrtRTEI, true);
  i6 = rowindex->size[0];
  rowindex->size[0] = c_y->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowindex, i6, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  apnd = c_y->size[1];
  for (i6 = 0; i6 < apnd; i6++) {
    rowindex->data[i6] = c_y->data[c_y->size[0] * i6];
  }

  emxFree_real_T(&c_y);

  /* 'Myspecgram:66' if length(x)<(nwind+colindex(ncol)-1) */
  i = x->size[1];
  i6 = colindex->size[1];
  i7 = (int32_T)emlrtIntegerCheckFastR2012b(ncol, &f_emlrtDCI, sp);
  if (i < ((real_T)nwind + colindex->data[emlrtDynamicBoundsCheckFastR2012b(i7,
        1, i6, &ub_emlrtBCI, sp) - 1]) - 1.0) {
    /* 'Myspecgram:67' x(nwind+colindex(ncol)-1) = 0; */
    i = x->size[1];
    i6 = colindex->size[1];
    i7 = (int32_T)ncol;
    y = ((real_T)nwind + colindex->data[emlrtDynamicBoundsCheckFastR2012b(i7, 1,
          i6, &wb_emlrtBCI, sp) - 1]) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(y, &g_emlrtDCI, sp);
    b_x->data[emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &vb_emlrtBCI, sp) - 1]
      = 0.0;

    /*  zero-pad x */
  }

  emxInit_creal_T(sp, &d_y, 2, &p_emlrtRTEI, true);

  /* 'Myspecgram:70' if length(nfft)>1 */
  /* 'Myspecgram:74' else */
  /* 'Myspecgram:75' evenly_spaced = 1; */
  /* 'Myspecgram:76' use_chirp = 0; */
  /* 'Myspecgram:79' if (length(nfft)==1) | use_chirp */
  /* 'Myspecgram:80' y = complex(zeros(nwind,ncol)); */
  i6 = d_y->size[0] * d_y->size[1];
  d_y->size[0] = nwind;
  d_y->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)d_y, i6, (int32_T)sizeof(creal_T),
                    &l_emlrtRTEI);
  apnd = nwind * (int32_T)ncol;
  for (i6 = 0; i6 < apnd; i6++) {
    d_y->data[i6].re = 0.0;
    d_y->data[i6].im = 0.0;
  }

  emxInit_real_T(sp, &b_rowindex, 2, &l_emlrtRTEI, true);

  /*  put x into columns of y with the proper offset */
  /*  should be able to do this with fancy indexing! */
  /* 'Myspecgram:84' y(:) = x(rowindex(:,ones(1,ncol))+colindex(ones(nwind,1),:)-1); */
  apnd = rowindex->size[0];
  i6 = b_rowindex->size[0] * b_rowindex->size[1];
  b_rowindex->size[0] = apnd;
  b_rowindex->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)b_rowindex, i6, (int32_T)sizeof
                    (real_T), &l_emlrtRTEI);
  n = (int32_T)ncol;
  for (i6 = 0; i6 < n; i6++) {
    for (i7 = 0; i7 < apnd; i7++) {
      b_rowindex->data[i7 + b_rowindex->size[0] * i6] = rowindex->data[i7];
    }
  }

  for (i6 = 0; i6 < 2; i6++) {
    c_rowindex[i6] = b_rowindex->size[i6];
  }

  emxFree_real_T(&b_rowindex);
  emxInit_real_T(sp, &b_colindex, 2, &l_emlrtRTEI, true);
  apnd = colindex->size[1];
  i6 = b_colindex->size[0] * b_colindex->size[1];
  b_colindex->size[0] = nwind;
  b_colindex->size[1] = apnd;
  emxEnsureCapacity(sp, (emxArray__common *)b_colindex, i6, (int32_T)sizeof
                    (real_T), &l_emlrtRTEI);
  for (i6 = 0; i6 < apnd; i6++) {
    for (i7 = 0; i7 < nwind; i7++) {
      b_colindex->data[i7 + b_colindex->size[0] * i6] = colindex->data
        [colindex->size[0] * i6];
    }
  }

  for (i6 = 0; i6 < 2; i6++) {
    c_colindex[i6] = b_colindex->size[i6];
  }

  emxFree_real_T(&b_colindex);
  emxInit_real_T(sp, &r2, 2, &l_emlrtRTEI, true);
  emlrtSizeEqCheck2DFastR2012b(c_rowindex, c_colindex, &f_emlrtECI, sp);
  apnd = rowindex->size[0];
  i6 = r2->size[0] * r2->size[1];
  r2->size[0] = apnd;
  r2->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)r2, i6, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  n = (int32_T)ncol;
  for (i6 = 0; i6 < n; i6++) {
    for (i7 = 0; i7 < apnd; i7++) {
      i = b_x->size[0];
      y = (rowindex->data[i7] + colindex->data[colindex->size[0] * i6]) - 1.0;
      nx = (int32_T)emlrtIntegerCheckFastR2012b(y, &h_emlrtDCI, sp);
      r2->data[i7 + r2->size[0] * i6] = b_x->
        data[emlrtDynamicBoundsCheckFastR2012b(nx, 1, i, &xb_emlrtBCI, sp) - 1];
    }
  }

  emxFree_real_T(&colindex);
  b_emxInit_real_T(sp, &r3, 1, &l_emlrtRTEI, true);
  i6 = rowindex->size[0];
  i7 = r3->size[0];
  r3->size[0] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i7, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  apnd = (int32_T)ncol;
  emxFree_real_T(&rowindex);
  for (i7 = 0; i7 < apnd; i7++) {
    r3->data[i7] = 1.0;
  }

  i7 = d_y->size[0] * d_y->size[1];
  i6 *= r3->size[0];
  emlrtSizeEqCheck1DFastR2012b(i7, i6, &g_emlrtECI, sp);
  i6 = d_y->size[0] * d_y->size[1];
  d_y->size[0] = r2->size[0];
  d_y->size[1] = r2->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_y, i6, (int32_T)sizeof(creal_T),
                    &l_emlrtRTEI);
  apnd = r2->size[0] * r2->size[1];
  emxFree_real_T(&r3);
  for (i6 = 0; i6 < apnd; i6++) {
    d_y->data[i6].re = r2->data[i6];
    d_y->data[i6].im = 0.0;
  }

  emxFree_real_T(&r2);
  emxInit_real_T(sp, &c_window, 2, &l_emlrtRTEI, true);

  /*  Apply the window to the array of offset signal segments. */
  /* 'Myspecgram:87' y = window(:,ones(1,ncol)).*y; */
  apnd = b_window->size[0];
  i6 = c_window->size[0] * c_window->size[1];
  c_window->size[0] = apnd;
  c_window->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)c_window, i6, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  n = (int32_T)ncol;
  for (i6 = 0; i6 < n; i6++) {
    for (i7 = 0; i7 < apnd; i7++) {
      c_window->data[i7 + c_window->size[0] * i6] = b_window->data[i7];
    }
  }

  for (i6 = 0; i6 < 2; i6++) {
    c_rowindex[i6] = c_window->size[i6];
  }

  emxFree_real_T(&c_window);
  for (i6 = 0; i6 < 2; i6++) {
    c_colindex[i6] = d_y->size[i6];
  }

  emlrtSizeEqCheck2DFastR2012b(c_rowindex, c_colindex, &h_emlrtECI, sp);
  apnd = b_window->size[0];
  i6 = d_y->size[0] * d_y->size[1];
  d_y->size[0] = apnd;
  d_y->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)d_y, i6, (int32_T)sizeof(creal_T),
                    &l_emlrtRTEI);
  n = (int32_T)ncol;
  for (i6 = 0; i6 < n; i6++) {
    for (i7 = 0; i7 < apnd; i7++) {
      d_y->data[i7 + d_y->size[0] * i6].re *= b_window->data[i7];
      d_y->data[i7 + d_y->size[0] * i6].im *= b_window->data[i7];
    }
  }

  emxFree_real_T(&b_window);
  emxInit_creal_T(sp, &r4, 2, &l_emlrtRTEI, true);

  /* 'Myspecgram:88' select=[]; */
  /* 'Myspecgram:89' if ~use_chirp */
  /*  USE FFT */
  /*  now fft y which does the columns */
  /* 'Myspecgram:91' y = fft(y,nfft); */
  st.site = &ec_emlrtRSI;
  fft(&st, d_y, r4);
  i6 = d_y->size[0] * d_y->size[1];
  d_y->size[0] = 8192;
  d_y->size[1] = r4->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_y, i6, (int32_T)sizeof(creal_T),
                    &l_emlrtRTEI);
  apnd = r4->size[0] * r4->size[1];
  for (i6 = 0; i6 < apnd; i6++) {
    d_y->data[i6] = r4->data[i6];
  }

  emxFree_creal_T(&r4);
  b_emxInit_real_T(sp, &c_x, 1, &l_emlrtRTEI, true);

  /* 'Myspecgram:92' if ~any(any(imag(x))) */
  i6 = c_x->size[0];
  c_x->size[0] = b_x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_x, i6, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  apnd = b_x->size[0];
  for (i6 = 0; i6 < apnd; i6++) {
    c_x->data[i6] = 0.0;
  }

  emxFree_real_T(&b_x);
  st.site = &fc_emlrtRSI;
  n_too_large = b_any(&st, c_x);
  emxFree_real_T(&c_x);
  if (!!(n_too_large == 0)) {
    /*  x purely real */
    /* 'Myspecgram:93' if rem(nfft,2) */
    /* 'Myspecgram:95' else */
    /* 'Myspecgram:96' select = 1:nfft/2+1; */
    /* 'Myspecgram:98' y = y(select,:); */
    for (i6 = 0; i6 < 4097; i6++) {
      tmp_data[i6] = (int16_T)(1 + i6);
    }

    emxInit_creal_T(sp, &e_y, 2, &l_emlrtRTEI, true);
    i = d_y->size[1];
    i6 = e_y->size[0] * e_y->size[1];
    e_y->size[0] = 4097;
    e_y->size[1] = i;
    emxEnsureCapacity(sp, (emxArray__common *)e_y, i6, (int32_T)sizeof(creal_T),
                      &l_emlrtRTEI);
    for (i6 = 0; i6 < i; i6++) {
      for (i7 = 0; i7 < 4097; i7++) {
        e_y->data[i7 + e_y->size[0] * i6] = d_y->data[(tmp_data[i7] + d_y->size
          [0] * i6) - 1];
      }
    }

    i6 = d_y->size[0] * d_y->size[1];
    d_y->size[0] = e_y->size[0];
    d_y->size[1] = e_y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)d_y, i6, (int32_T)sizeof(creal_T),
                      &l_emlrtRTEI);
    apnd = e_y->size[1];
    for (i6 = 0; i6 < apnd; i6++) {
      n = e_y->size[0];
      for (i7 = 0; i7 < n; i7++) {
        d_y->data[i7 + d_y->size[0] * i6] = e_y->data[i7 + e_y->size[0] * i6];
      }
    }

    emxFree_creal_T(&e_y);
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
  i6 = yo->size[0] * yo->size[1];
  yo->size[0] = d_y->size[0];
  yo->size[1] = d_y->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)yo, i6, (int32_T)sizeof(creal_T),
                    &l_emlrtRTEI);
  apnd = d_y->size[0] * d_y->size[1];
  for (i6 = 0; i6 < apnd; i6++) {
    yo->data[i6] = d_y->data[i6];
  }

  emxFree_creal_T(&d_y);

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
