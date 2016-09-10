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
#include "any.h"
#include "fft.h"
#include "fix.h"
#include "Myhanning.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ye_emlrtRSI = { 53, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo af_emlrtRSI = { 64, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo bf_emlrtRSI = { 65, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo cf_emlrtRSI = { 91, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo df_emlrtRSI = { 92, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo ef_emlrtRSI = { 94, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo ff_emlrtRSI = { 96, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRSInfo gf_emlrtRSI = { 100, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo jb_emlrtRTEI = { 1, 23, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo kb_emlrtRTEI = { 64, 1, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo lb_emlrtRTEI = { 65, 1, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo mb_emlrtRTEI = { 1, 44, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo nb_emlrtRTEI = { 1, 34, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtRTEInfo ob_emlrtRTEI = { 88, 5, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo l_emlrtECI = { 2, 87, 9, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo m_emlrtECI = { -1, 84, 5, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtECInfo n_emlrtECI = { 2, 84, 14, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m" };

static emlrtDCInfo n_emlrtDCI = { 80, 29, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtDCInfo o_emlrtDCI = { 80, 29, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 4 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 58, 5, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 66, 21, "colindex", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 66, 21, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 67, 5, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo q_emlrtDCI = { 67, 5, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 67, 13, "colindex", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 67, 13, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 84, 12, "x", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

static emlrtDCInfo s_emlrtDCI = { 84, 12, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtDCInfo t_emlrtDCI = { 98, 19, "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 1 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 98, 19, "y", "Myspecgram",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m", 0 };

/* Function Definitions */

/*
 * function [yo,fo,to] = Myspecgram(x,nfft,Fs,window,noverlap)
 */
void Myspecgram(const emlrtStack *sp, emxArray_real_T *x, real_T nfft, real_T
                window, real_T noverlap, emxArray_creal_T *yo)
{
  emxArray_real_T *b_window;
  int32_T nx;
  int32_T varargin_1;
  int32_T nwind;
  emxArray_real_T *b_x;
  int32_T i16;
  int32_T i17;
  int32_T loop_ub;
  int32_T cdiff;
  real_T ncol;
  int32_T n;
  real_T anew;
  real_T apnd;
  real_T ndbl;
  boolean_T n_too_large;
  real_T b_cdiff;
  emxArray_real_T *colindex;
  int32_T nm1d2;
  real_T absb;
  int32_T b_apnd;
  emxArray_real_T *y;
  emxArray_real_T *rowindex;
  emxArray_real_T *b_select;
  emxArray_real_T *b_rowindex;
  int32_T c_rowindex[2];
  emxArray_real_T *b_colindex;
  int32_T c_colindex[2];
  emxArray_real_T *r15;
  emxArray_real_T *r16;
  emxArray_real_T *c_window;
  int32_T d_window[2];
  int32_T b_yo[2];
  emxArray_creal_T *c_yo;
  emxArray_real_T *c_x;
  real_T b_y;
  emxArray_real_T *c_select;
  emxArray_creal_T *d_yo;
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
  emxInit_real_T1(sp, &b_window, 1, &mb_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 7U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 0);

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
  st.site = &ye_emlrtRSI;
  Myhanning(&st, window, b_window);

  /*  window = hanning(window); */
  /* 'Myspecgram:55' nx = length(x); */
  nx = x->size[1];

  /* 'Myspecgram:56' nwind = length(window); */
  varargin_1 = b_window->size[0];
  nwind = b_window->size[0];

  /* 'Myspecgram:57' if nx < nwind */
  if (covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 0, x->size[1] < b_window->size
                 [0])) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 1);

    /*  zero-pad x if it has length less than the window length */
    /* 'Myspecgram:58' x(nwind)=0; */
    i16 = x->size[1];
    i17 = b_window->size[0];
    if (!((i17 >= 1) && (i17 <= i16))) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, i16, &ec_emlrtBCI, sp);
    }

    x->data[i17 - 1] = 0.0;

    /* 'Myspecgram:58' nx=nwind; */
    nx = b_window->size[0];
  }

  emxInit_real_T1(sp, &b_x, 1, &nb_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 2);

  /* 'Myspecgram:60' x = x(:); */
  i16 = b_x->size[0];
  b_x->size[0] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_x, i16, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  loop_ub = x->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    b_x->data[i16] = x->data[i16];
  }

  /*  make a column vector for ease later */
  /* 'Myspecgram:61' window = window(:); */
  cdiff = b_window->size[0];
  i16 = b_window->size[0];
  b_window->size[0] = cdiff;
  emxEnsureCapacity(sp, (emxArray__common *)b_window, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);

  /*  be consistent with data set */
  /* 'Myspecgram:63' ncol = fix((nx-noverlap)/(nwind-noverlap)); */
  ncol = ((real_T)nx - noverlap) / ((real_T)varargin_1 - noverlap);
  b_fix(&ncol);

  /* 'Myspecgram:64' colindex = 1 + (0:(ncol-1))*(nwind-noverlap); */
  st.site = &af_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if (muDoubleScalarIsNaN(ncol - 1.0)) {
    n = 1;
    anew = rtNaN;
    apnd = ncol - 1.0;
    n_too_large = false;
  } else if (ncol - 1.0 < 0.0) {
    n = 0;
    anew = 0.0;
    apnd = ncol - 1.0;
    n_too_large = false;
  } else if (muDoubleScalarIsInf(ncol - 1.0)) {
    n = 1;
    anew = rtNaN;
    apnd = ncol - 1.0;
    n_too_large = !(0.0 == ncol - 1.0);
  } else {
    anew = 0.0;
    ndbl = muDoubleScalarFloor((ncol - 1.0) + 0.5);
    apnd = ndbl;
    b_cdiff = ndbl - (ncol - 1.0);
    if (muDoubleScalarAbs(b_cdiff) < 4.4408920985006262E-16 * muDoubleScalarAbs
        (ncol - 1.0)) {
      ndbl++;
      apnd = ncol - 1.0;
    } else if (b_cdiff > 0.0) {
      apnd = ndbl - 1.0;
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

  d_st.site = &ab_emlrtRSI;
  if (!n_too_large) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &mf_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &colindex, 2, &kb_emlrtRTEI, true);
  i16 = colindex->size[0] * colindex->size[1];
  colindex->size[0] = 1;
  if (!(n >= 0)) {
    emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
  }

  colindex->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)colindex, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);
  if (n > 0) {
    colindex->data[0] = anew;
    if (n > 1) {
      colindex->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      d_st.site = &bb_emlrtRSI;
      for (cdiff = 1; cdiff < nm1d2; cdiff++) {
        colindex->data[cdiff] = anew + (real_T)cdiff;
        colindex->data[(n - cdiff) - 1] = apnd - (real_T)cdiff;
      }

      if (nm1d2 << 1 == n - 1) {
        colindex->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        colindex->data[nm1d2] = anew + (real_T)nm1d2;
        colindex->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  absb = (real_T)varargin_1 - noverlap;
  i16 = colindex->size[0] * colindex->size[1];
  colindex->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)colindex, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);
  cdiff = colindex->size[0];
  nm1d2 = colindex->size[1];
  loop_ub = cdiff * nm1d2;
  for (i16 = 0; i16 < loop_ub; i16++) {
    colindex->data[i16] = 1.0 + colindex->data[i16] * absb;
  }

  /* 'Myspecgram:65' rowindex = (1:nwind)'; */
  st.site = &bf_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if (varargin_1 < 1) {
    n = 0;
    b_apnd = 0;
  } else {
    nm1d2 = (int32_T)muDoubleScalarFloor(((real_T)nwind - 1.0) + 0.5);
    b_apnd = nm1d2 + 1;
    cdiff = (nm1d2 - varargin_1) + 1;
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)varargin_1)
    {
      nm1d2++;
      b_apnd = varargin_1;
    } else if (cdiff > 0) {
      b_apnd = nm1d2;
    } else {
      nm1d2++;
    }

    if (nm1d2 >= 0) {
      n = nm1d2;
    } else {
      n = 0;
    }
  }

  emxInit_real_T(&c_st, &y, 2, &jb_emlrtRTEI, true);
  d_st.site = &ab_emlrtRSI;
  i16 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)y, i16, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  if (n > 0) {
    y->data[0] = 1.0;
    if (n > 1) {
      y->data[n - 1] = b_apnd;
      nm1d2 = (n - 1) / 2;
      d_st.site = &bb_emlrtRSI;
      for (cdiff = 1; cdiff < nm1d2; cdiff++) {
        y->data[cdiff] = 1.0 + (real_T)cdiff;
        y->data[(n - cdiff) - 1] = b_apnd - cdiff;
      }

      if (nm1d2 << 1 == n - 1) {
        y->data[nm1d2] = (1.0 + (real_T)b_apnd) / 2.0;
      } else {
        y->data[nm1d2] = 1.0 + (real_T)nm1d2;
        y->data[nm1d2 + 1] = b_apnd - nm1d2;
      }
    }
  }

  emxInit_real_T1(&c_st, &rowindex, 1, &lb_emlrtRTEI, true);
  i16 = rowindex->size[0];
  rowindex->size[0] = y->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowindex, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);
  loop_ub = y->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    rowindex->data[i16] = y->data[y->size[0] * i16];
  }

  /* 'Myspecgram:66' if length(x)<(nwind+colindex(ncol)-1) */
  nm1d2 = x->size[1];
  i16 = colindex->size[1];
  if (ncol != (int32_T)muDoubleScalarFloor(ncol)) {
    emlrtIntegerCheckR2012b(ncol, &p_emlrtDCI, sp);
  }

  i17 = (int32_T)ncol;
  if (!((i17 >= 1) && (i17 <= i16))) {
    emlrtDynamicBoundsCheckR2012b(i17, 1, i16, &fc_emlrtBCI, sp);
  }

  if (covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 1, nm1d2 < ((real_T)varargin_1
        + colindex->data[i17 - 1]) - 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 3);

    /* 'Myspecgram:67' x(nwind+colindex(ncol)-1) = 0; */
    nm1d2 = x->size[1];
    i16 = colindex->size[1];
    if (ncol != (int32_T)muDoubleScalarFloor(ncol)) {
      emlrtIntegerCheckR2012b(ncol, &r_emlrtDCI, sp);
    }

    i17 = (int32_T)ncol;
    if (!((i17 >= 1) && (i17 <= i16))) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, i16, &hc_emlrtBCI, sp);
    }

    absb = ((real_T)varargin_1 + colindex->data[i17 - 1]) - 1.0;
    if (absb != (int32_T)muDoubleScalarFloor(absb)) {
      emlrtIntegerCheckR2012b(absb, &q_emlrtDCI, sp);
    }

    i16 = (int32_T)absb;
    if (!((i16 >= 1) && (i16 <= nm1d2))) {
      emlrtDynamicBoundsCheckR2012b(i16, 1, nm1d2, &gc_emlrtBCI, sp);
    }

    b_x->data[i16 - 1] = 0.0;

    /*  zero-pad x */
  }

  /* 'Myspecgram:70' if length(nfft)>1 */
  covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 2, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 5);

  /* 'Myspecgram:74' else */
  /* 'Myspecgram:75' evenly_spaced = 1; */
  /* 'Myspecgram:76' use_chirp = 0; */
  /* 'Myspecgram:79' if (length(nfft)==1) | use_chirp */
  covrtLogCond(&emlrtCoverageInstance, 7U, 0U, 0, true);
  covrtLogMcdc(&emlrtCoverageInstance, 7U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 6);

  /* 'Myspecgram:80' y = complex(zeros(nwind,ncol)); */
  i16 = yo->size[0] * yo->size[1];
  yo->size[0] = varargin_1;
  if (!(ncol >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ncol, &o_emlrtDCI, sp);
  }

  absb = ncol;
  if (absb != (int32_T)muDoubleScalarFloor(absb)) {
    emlrtIntegerCheckR2012b(absb, &n_emlrtDCI, sp);
  }

  yo->size[1] = (int32_T)absb;
  emxEnsureCapacity(sp, (emxArray__common *)yo, i16, (int32_T)sizeof(creal_T),
                    &jb_emlrtRTEI);
  if (!(ncol >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ncol, &o_emlrtDCI, sp);
  }

  if (absb != (int32_T)muDoubleScalarFloor(absb)) {
    emlrtIntegerCheckR2012b(absb, &n_emlrtDCI, sp);
  }

  loop_ub = varargin_1 * (int32_T)absb;
  for (i16 = 0; i16 < loop_ub; i16++) {
    yo->data[i16].re = 0.0;
    yo->data[i16].im = 0.0;
  }

  emxInit_real_T(sp, &b_select, 2, &ob_emlrtRTEI, true);

  /*  put x into columns of y with the proper offset */
  /*  should be able to do this with fancy indexing! */
  /* 'Myspecgram:84' y(:) = x(rowindex(:,ones(1,ncol))+colindex(ones(nwind,1),:)-1); */
  loop_ub = rowindex->size[0];
  i16 = b_select->size[0] * b_select->size[1];
  b_select->size[0] = loop_ub;
  b_select->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)b_select, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);
  b_apnd = (int32_T)ncol;
  for (i16 = 0; i16 < b_apnd; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      b_select->data[i17 + b_select->size[0] * i16] = rowindex->data[i17];
    }
  }

  emxInit_real_T(sp, &b_rowindex, 2, &jb_emlrtRTEI, true);
  loop_ub = rowindex->size[0];
  i16 = b_rowindex->size[0] * b_rowindex->size[1];
  b_rowindex->size[0] = loop_ub;
  b_rowindex->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)b_rowindex, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);
  b_apnd = (int32_T)ncol;
  for (i16 = 0; i16 < b_apnd; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      b_rowindex->data[i17 + b_rowindex->size[0] * i16] = rowindex->data[i17];
    }
  }

  for (i16 = 0; i16 < 2; i16++) {
    c_rowindex[i16] = b_rowindex->size[i16];
  }

  emxFree_real_T(&b_rowindex);
  emxInit_real_T(sp, &b_colindex, 2, &jb_emlrtRTEI, true);
  loop_ub = colindex->size[1];
  i16 = b_colindex->size[0] * b_colindex->size[1];
  b_colindex->size[0] = nwind;
  b_colindex->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)b_colindex, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);
  for (i16 = 0; i16 < loop_ub; i16++) {
    for (i17 = 0; i17 < nwind; i17++) {
      b_colindex->data[i17 + b_colindex->size[0] * i16] = colindex->
        data[colindex->size[0] * i16];
    }
  }

  for (i16 = 0; i16 < 2; i16++) {
    c_colindex[i16] = b_colindex->size[i16];
  }

  emxFree_real_T(&b_colindex);
  emxInit_real_T(sp, &r15, 2, &jb_emlrtRTEI, true);
  if ((c_rowindex[0] != c_colindex[0]) || (c_rowindex[1] != c_colindex[1])) {
    emlrtSizeEqCheckNDR2012b(&c_rowindex[0], &c_colindex[0], &n_emlrtECI, sp);
  }

  cdiff = b_x->size[0];
  i16 = r15->size[0] * r15->size[1];
  r15->size[0] = b_select->size[0];
  r15->size[1] = b_select->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r15, i16, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  loop_ub = b_select->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    b_apnd = b_select->size[0];
    for (i17 = 0; i17 < b_apnd; i17++) {
      absb = (b_select->data[i17 + b_select->size[0] * i16] + colindex->
              data[colindex->size[0] * i16]) - 1.0;
      if (absb != (int32_T)muDoubleScalarFloor(absb)) {
        emlrtIntegerCheckR2012b(absb, &s_emlrtDCI, sp);
      }

      n = (int32_T)absb;
      if (!((n >= 1) && (n <= cdiff))) {
        emlrtDynamicBoundsCheckR2012b(n, 1, cdiff, &ic_emlrtBCI, sp);
      }

      r15->data[i17 + r15->size[0] * i16] = b_x->data[n - 1];
    }
  }

  emxFree_real_T(&colindex);
  emxInit_real_T1(sp, &r16, 1, &jb_emlrtRTEI, true);
  i16 = rowindex->size[0];
  i17 = r16->size[0];
  r16->size[0] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)r16, i17, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  loop_ub = (int32_T)ncol;
  emxFree_real_T(&rowindex);
  for (i17 = 0; i17 < loop_ub; i17++) {
    r16->data[i17] = 1.0;
  }

  i17 = yo->size[0] * yo->size[1];
  i16 *= r16->size[0];
  if (i17 != i16) {
    emlrtSizeEqCheck1DR2012b(i17, i16, &m_emlrtECI, sp);
  }

  i16 = yo->size[0] * yo->size[1];
  yo->size[0] = r15->size[0];
  yo->size[1] = r15->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)yo, i16, (int32_T)sizeof(creal_T),
                    &jb_emlrtRTEI);
  loop_ub = r15->size[0] * r15->size[1];
  emxFree_real_T(&r16);
  for (i16 = 0; i16 < loop_ub; i16++) {
    yo->data[i16].re = r15->data[i16];
    yo->data[i16].im = 0.0;
  }

  emxFree_real_T(&r15);

  /*  Apply the window to the array of offset signal segments. */
  /* 'Myspecgram:87' y = window(:,ones(1,ncol)).*y; */
  loop_ub = b_window->size[0];
  i16 = b_select->size[0] * b_select->size[1];
  b_select->size[0] = loop_ub;
  b_select->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)b_select, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);
  b_apnd = (int32_T)ncol;
  for (i16 = 0; i16 < b_apnd; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      b_select->data[i17 + b_select->size[0] * i16] = b_window->data[i17];
    }
  }

  emxInit_real_T(sp, &c_window, 2, &jb_emlrtRTEI, true);
  loop_ub = b_window->size[0];
  i16 = c_window->size[0] * c_window->size[1];
  c_window->size[0] = loop_ub;
  c_window->size[1] = (int32_T)ncol;
  emxEnsureCapacity(sp, (emxArray__common *)c_window, i16, (int32_T)sizeof
                    (real_T), &jb_emlrtRTEI);
  b_apnd = (int32_T)ncol;
  for (i16 = 0; i16 < b_apnd; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      c_window->data[i17 + c_window->size[0] * i16] = b_window->data[i17];
    }
  }

  emxFree_real_T(&b_window);
  for (i16 = 0; i16 < 2; i16++) {
    d_window[i16] = c_window->size[i16];
  }

  emxFree_real_T(&c_window);
  for (i16 = 0; i16 < 2; i16++) {
    b_yo[i16] = yo->size[i16];
  }

  if ((d_window[0] != b_yo[0]) || (d_window[1] != b_yo[1])) {
    emlrtSizeEqCheckNDR2012b(&d_window[0], &b_yo[0], &l_emlrtECI, sp);
  }

  i16 = yo->size[0] * yo->size[1];
  yo->size[0] = b_select->size[0];
  yo->size[1] = b_select->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)yo, i16, (int32_T)sizeof(creal_T),
                    &jb_emlrtRTEI);
  loop_ub = b_select->size[0] * b_select->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    yo->data[i16].re *= b_select->data[i16];
    yo->data[i16].im *= b_select->data[i16];
  }

  emxInit_creal_T(sp, &c_yo, 2, &jb_emlrtRTEI, true);

  /* 'Myspecgram:88' select=[]; */
  /* 'Myspecgram:89' if ~use_chirp */
  covrtLogCond(&emlrtCoverageInstance, 7U, 0U, 2, false);
  covrtLogMcdc(&emlrtCoverageInstance, 7U, 0U, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 4, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 7);

  /*  USE FFT */
  /*  now fft y which does the columns */
  /* 'Myspecgram:91' y = fft(y,nfft); */
  i16 = c_yo->size[0] * c_yo->size[1];
  c_yo->size[0] = yo->size[0];
  c_yo->size[1] = yo->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_yo, i16, (int32_T)sizeof(creal_T),
                    &jb_emlrtRTEI);
  loop_ub = yo->size[0] * yo->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    c_yo->data[i16] = yo->data[i16];
  }

  emxInit_real_T1(sp, &c_x, 1, &jb_emlrtRTEI, true);
  st.site = &cf_emlrtRSI;
  fft(&st, c_yo, nfft, yo);

  /* 'Myspecgram:92' if ~any(any(imag(x))) */
  i16 = c_x->size[0];
  c_x->size[0] = b_x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_x, i16, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  loop_ub = b_x->size[0];
  emxFree_creal_T(&c_yo);
  for (i16 = 0; i16 < loop_ub; i16++) {
    c_x->data[i16] = 0.0;
  }

  emxFree_real_T(&b_x);
  st.site = &df_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 5, covrtLogMcdc
                 (&emlrtCoverageInstance, 7U, 0U, 2, !covrtLogCond
                  (&emlrtCoverageInstance, 7U, 0U, 3, any(c_any(&st, c_x)))))) {
    /*  x purely real */
    /* 'Myspecgram:93' if rem(nfft,2) */
    if (covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 6, muDoubleScalarRem(nfft,
          2.0) != 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 8);

      /*  nfft odd */
      /* 'Myspecgram:94' select = 1:(nfft+1)/2; */
      absb = (nfft + 1.0) / 2.0;
      st.site = &ef_emlrtRSI;
      b_st.site = &x_emlrtRSI;
      c_st.site = &y_emlrtRSI;
      if (muDoubleScalarIsNaN(absb)) {
        n = 1;
        anew = rtNaN;
        apnd = absb;
        n_too_large = false;
      } else if (absb < 1.0) {
        n = 0;
        anew = 1.0;
        apnd = absb;
        n_too_large = false;
      } else if (muDoubleScalarIsInf(absb)) {
        n = 1;
        anew = rtNaN;
        apnd = absb;
        n_too_large = !(1.0 == absb);
      } else {
        anew = 1.0;
        ndbl = muDoubleScalarFloor((absb - 1.0) + 0.5);
        apnd = 1.0 + ndbl;
        b_cdiff = (1.0 + ndbl) - absb;
        if (muDoubleScalarAbs(b_cdiff) < 4.4408920985006262E-16 * absb) {
          ndbl++;
          apnd = absb;
        } else if (b_cdiff > 0.0) {
          apnd = 1.0 + (ndbl - 1.0);
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

      d_st.site = &ab_emlrtRSI;
      if (!n_too_large) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &mf_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i16 = y->size[0] * y->size[1];
      y->size[0] = 1;
      if (!(n >= 0)) {
        emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
      }

      y->size[1] = n;
      emxEnsureCapacity(&c_st, (emxArray__common *)y, i16, (int32_T)sizeof
                        (real_T), &jb_emlrtRTEI);
      if (n > 0) {
        y->data[0] = anew;
        if (n > 1) {
          y->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          d_st.site = &bb_emlrtRSI;
          for (cdiff = 1; cdiff < nm1d2; cdiff++) {
            y->data[cdiff] = anew + (real_T)cdiff;
            y->data[(n - cdiff) - 1] = apnd - (real_T)cdiff;
          }

          if (nm1d2 << 1 == n - 1) {
            y->data[nm1d2] = (anew + apnd) / 2.0;
          } else {
            y->data[nm1d2] = anew + (real_T)nm1d2;
            y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
          }
        }
      }

      i16 = b_select->size[0] * b_select->size[1];
      b_select->size[0] = 1;
      b_select->size[1] = y->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_select, i16, (int32_T)sizeof
                        (real_T), &jb_emlrtRTEI);
      loop_ub = y->size[0] * y->size[1];
      for (i16 = 0; i16 < loop_ub; i16++) {
        b_select->data[i16] = y->data[i16];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 9);

      /* 'Myspecgram:95' else */
      /* 'Myspecgram:96' select = 1:nfft/2+1; */
      b_y = nfft / 2.0;
      st.site = &ff_emlrtRSI;
      absb = nfft / 2.0 + 1.0;
      b_st.site = &x_emlrtRSI;
      c_st.site = &y_emlrtRSI;
      if (muDoubleScalarIsNaN(absb)) {
        n = 1;
        anew = rtNaN;
        apnd = b_y + 1.0;
        n_too_large = false;
      } else if (b_y + 1.0 < 1.0) {
        n = 0;
        anew = 1.0;
        apnd = b_y + 1.0;
        n_too_large = false;
      } else if (muDoubleScalarIsInf(absb)) {
        n = 1;
        anew = rtNaN;
        apnd = b_y + 1.0;
        n_too_large = !(1.0 == b_y + 1.0);
      } else {
        anew = 1.0;
        ndbl = muDoubleScalarFloor((absb - 1.0) + 0.5);
        apnd = 1.0 + ndbl;
        b_cdiff = (1.0 + ndbl) - (b_y + 1.0);
        absb = muDoubleScalarAbs(b_y + 1.0);
        if (muDoubleScalarAbs(b_cdiff) < 4.4408920985006262E-16 *
            muDoubleScalarMax(1.0, absb)) {
          ndbl++;
          apnd = b_y + 1.0;
        } else if (b_cdiff > 0.0) {
          apnd = 1.0 + (ndbl - 1.0);
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

      d_st.site = &ab_emlrtRSI;
      if (!n_too_large) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &mf_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i16 = y->size[0] * y->size[1];
      y->size[0] = 1;
      if (!(n >= 0)) {
        emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
      }

      y->size[1] = n;
      emxEnsureCapacity(&c_st, (emxArray__common *)y, i16, (int32_T)sizeof
                        (real_T), &jb_emlrtRTEI);
      if (n > 0) {
        y->data[0] = anew;
        if (n > 1) {
          y->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          d_st.site = &bb_emlrtRSI;
          for (cdiff = 1; cdiff < nm1d2; cdiff++) {
            y->data[cdiff] = anew + (real_T)cdiff;
            y->data[(n - cdiff) - 1] = apnd - (real_T)cdiff;
          }

          if (nm1d2 << 1 == n - 1) {
            y->data[nm1d2] = (anew + apnd) / 2.0;
          } else {
            y->data[nm1d2] = anew + (real_T)nm1d2;
            y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
          }
        }
      }

      i16 = b_select->size[0] * b_select->size[1];
      b_select->size[0] = 1;
      b_select->size[1] = y->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_select, i16, (int32_T)sizeof
                        (real_T), &jb_emlrtRTEI);
      loop_ub = y->size[0] * y->size[1];
      for (i16 = 0; i16 < loop_ub; i16++) {
        b_select->data[i16] = y->data[i16];
      }
    }

    emxInit_real_T(sp, &c_select, 2, &jb_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 10);

    /* 'Myspecgram:98' y = y(select,:); */
    nm1d2 = yo->size[0];
    i16 = c_select->size[0] * c_select->size[1];
    c_select->size[0] = b_select->size[0];
    c_select->size[1] = b_select->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)c_select, i16, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    loop_ub = b_select->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      b_apnd = b_select->size[0];
      for (i17 = 0; i17 < b_apnd; i17++) {
        absb = b_select->data[i17 + b_select->size[0] * i16];
        if (absb != (int32_T)muDoubleScalarFloor(absb)) {
          emlrtIntegerCheckR2012b(absb, &t_emlrtDCI, sp);
        }

        n = (int32_T)absb;
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &jc_emlrtBCI, sp);
        }

        c_select->data[i17 + c_select->size[0] * i16] = n;
      }
    }

    emxInit_creal_T(sp, &d_yo, 2, &jb_emlrtRTEI, true);
    cdiff = b_select->size[1];
    nm1d2 = yo->size[1];
    i16 = d_yo->size[0] * d_yo->size[1];
    d_yo->size[0] = cdiff;
    d_yo->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)d_yo, i16, (int32_T)sizeof(creal_T),
                      &jb_emlrtRTEI);
    for (i16 = 0; i16 < nm1d2; i16++) {
      for (i17 = 0; i17 < cdiff; i17++) {
        d_yo->data[i17 + d_yo->size[0] * i16] = yo->data[((int32_T)
          c_select->data[i17] + yo->size[0] * i16) - 1];
      }
    }

    emxFree_real_T(&c_select);
    i16 = yo->size[0] * yo->size[1];
    yo->size[0] = d_yo->size[0];
    yo->size[1] = d_yo->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)yo, i16, (int32_T)sizeof(creal_T),
                      &jb_emlrtRTEI);
    loop_ub = d_yo->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      b_apnd = d_yo->size[0];
      for (i17 = 0; i17 < b_apnd; i17++) {
        yo->data[i17 + yo->size[0] * i16] = d_yo->data[i17 + d_yo->size[0] * i16];
      }
    }

    emxFree_creal_T(&d_yo);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 11);

    /* 'Myspecgram:99' else */
    /* 'Myspecgram:100' select = 1:nfft; */
    st.site = &gf_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    if (muDoubleScalarIsNaN(nfft)) {
      n = 1;
      n_too_large = false;
    } else if (nfft < 1.0) {
      n = 0;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(nfft)) {
      n = 1;
      n_too_large = !(1.0 == nfft);
    } else {
      ndbl = muDoubleScalarFloor((nfft - 1.0) + 0.5);
      b_cdiff = (1.0 + ndbl) - nfft;
      if (muDoubleScalarAbs(b_cdiff) < 4.4408920985006262E-16 * nfft) {
        ndbl++;
      } else if (b_cdiff > 0.0) {
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

    d_st.site = &ab_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &mf_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    if (!(n >= 0)) {
      emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
    }

    if ((n > 0) && (n > 1)) {
      d_st.site = &bb_emlrtRSI;
    }
  }

  emxFree_real_T(&c_x);
  emxFree_real_T(&y);
  emxFree_real_T(&b_select);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 12);

  /* 'Myspecgram:102' f = (select - 1)'*Fs/nfft; */
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 15);

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
  covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 7, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 16);

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
