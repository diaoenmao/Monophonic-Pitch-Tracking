/*
 * nlfer.c
 *
 * Code generation for function 'nlfer'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "nlfer.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "mean.h"
#include "isequal.h"
#include "Myspecgram.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ge_emlrtRSI = { 48, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo he_emlrtRSI = { 52, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo ie_emlrtRSI = { 53, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 1, 30, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo gb_emlrtRTEI = { 48, 1, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 52, 30, "SpecData", "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m", 0 };

static emlrtDCInfo j_emlrtDCI = { 52, 30, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m", 1 };

/* Function Definitions */
void nlfer(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs, real_T
           Prm_frame_length, real_T Prm_frame_space, real_T Prm_f0_min, real_T
           Prm_f0_max, real_T Prm_fft_length, real_T Prm_nlfer_thresh1,
           emxArray_real_T *Energy, emxArray_boolean_T *VUVEnergy)
{
  real_T s;
  real_T nframesize;
  emxArray_real_T *b_Data;
  real_T N_F0_min;
  real_T N_F0_max;
  int32_T n;
  int32_T i;
  emxArray_creal_T *SpecData;
  real_T b_s;
  int32_T k;
  int32_T xoffset;
  emxArray_creal_T *x;
  emxArray_creal_T *b_SpecData;
  int32_T loop_ub;
  int32_T i12;
  uint32_T uv1[2];
  emxArray_real_T *b_x;
  boolean_T overflow;
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
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 0);

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
  s = Prm_frame_length * Fs / 1000.0;
  if (s < 0.0) {
    nframesize = muDoubleScalarCeil(s);
  } else {
    nframesize = muDoubleScalarFloor(s);
  }

  s = Prm_frame_space * Fs / 1000.0;
  emxInit_real_T(sp, &b_Data, 2, &fb_emlrtRTEI, true);

  /*  If normalized low-frequency energy is below this, assume unvoiced frame */
  /*  Low freqeuncy range for NLFER */
  /*  N_F0_min = round ((Prm.f0_min*2/Fs) * nfftlength ); */
  N_F0_min = muDoubleScalarRound(Prm_f0_min / Fs * Prm_fft_length);
  N_F0_max = muDoubleScalarRound(Prm_f0_max / Fs * Prm_fft_length);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Spectrogram of the data */
  /*    B = SPECGRAM(A,NFFT,Fs,WINDOW,NOVERLAP) */
  n = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, n, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  i = Data->size[0] * Data->size[1];
  for (n = 0; n < i; n++) {
    b_Data->data[n] = Data->data[n];
  }

  emxInit_creal_T(sp, &SpecData, 2, &gb_emlrtRTEI, true);
  if (s < 0.0) {
    b_s = muDoubleScalarCeil(s);
  } else {
    b_s = muDoubleScalarFloor(s);
  }

  st.site = &ge_emlrtRSI;
  Myspecgram(&st, b_Data, Prm_fft_length, nframesize, nframesize - b_s, SpecData);

  /*  SpecData_test = specgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  /*  Compute normalize low-frequency energy ratio  */
  /*  FrmEnergy = sum(abs(SpecData(N_F0_min:N_F0_max,:)).^2); PSD??? */
  emxFree_real_T(&b_Data);
  if (N_F0_min > N_F0_max) {
    n = 0;
    k = 0;
  } else {
    n = SpecData->size[0];
    if (N_F0_min != (int32_T)muDoubleScalarFloor(N_F0_min)) {
      emlrtIntegerCheckR2012b(N_F0_min, &j_emlrtDCI, sp);
    }

    xoffset = (int32_T)N_F0_min;
    if (!((xoffset >= 1) && (xoffset <= n))) {
      emlrtDynamicBoundsCheckR2012b(xoffset, 1, n, &bc_emlrtBCI, sp);
    }

    n = xoffset - 1;
    xoffset = SpecData->size[0];
    if (N_F0_max != (int32_T)muDoubleScalarFloor(N_F0_max)) {
      emlrtIntegerCheckR2012b(N_F0_max, &j_emlrtDCI, sp);
    }

    k = (int32_T)N_F0_max;
    if (!((k >= 1) && (k <= xoffset))) {
      emlrtDynamicBoundsCheckR2012b(k, 1, xoffset, &bc_emlrtBCI, sp);
    }
  }

  emxInit_creal_T(sp, &x, 2, &fb_emlrtRTEI, true);
  st.site = &he_emlrtRSI;
  i = SpecData->size[1];
  xoffset = x->size[0] * x->size[1];
  x->size[0] = k - n;
  x->size[1] = i;
  emxEnsureCapacity(&st, (emxArray__common *)x, xoffset, (int32_T)sizeof(creal_T),
                    &fb_emlrtRTEI);
  for (xoffset = 0; xoffset < i; xoffset++) {
    loop_ub = k - n;
    for (i12 = 0; i12 < loop_ub; i12++) {
      x->data[i12 + x->size[0] * xoffset] = SpecData->data[(n + i12) +
        SpecData->size[0] * xoffset];
    }
  }

  emxInit_creal_T(&st, &b_SpecData, 2, &fb_emlrtRTEI, true);
  b_st.site = &mg_emlrtRSI;
  i = SpecData->size[1];
  xoffset = b_SpecData->size[0] * b_SpecData->size[1];
  b_SpecData->size[0] = k - n;
  b_SpecData->size[1] = i;
  emxEnsureCapacity(&b_st, (emxArray__common *)b_SpecData, xoffset, (int32_T)
                    sizeof(creal_T), &fb_emlrtRTEI);
  for (xoffset = 0; xoffset < i; xoffset++) {
    loop_ub = k - n;
    for (i12 = 0; i12 < loop_ub; i12++) {
      b_SpecData->data[i12 + b_SpecData->size[0] * xoffset] = SpecData->data[(n
        + i12) + SpecData->size[0] * xoffset];
    }
  }

  for (xoffset = 0; xoffset < 2; xoffset++) {
    uv1[xoffset] = (uint32_T)b_SpecData->size[xoffset];
  }

  emxFree_creal_T(&b_SpecData);
  emxInit_real_T(&b_st, &b_x, 2, &fb_emlrtRTEI, true);
  xoffset = b_x->size[0] * b_x->size[1];
  b_x->size[0] = (int32_T)uv1[0];
  b_x->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)b_x, xoffset, (int32_T)sizeof
                    (real_T), &fb_emlrtRTEI);
  xoffset = SpecData->size[1];
  n = (k - n) * xoffset;
  c_st.site = &ng_emlrtRSI;
  if ((!(1 > n)) && (n > 2147483646)) {
    d_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    b_x->data[k] = muDoubleScalarHypot(x->data[k].re, x->data[k].im);
  }

  emxFree_creal_T(&x);
  emxFree_creal_T(&SpecData);
  st.site = &he_emlrtRSI;
  b_st.site = &og_emlrtRSI;
  if (((b_x->size[0] == 1) && (b_x->size[1] == 1)) || (b_x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &nf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = !b_isequal(b_x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &mf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  c_st.site = &pg_emlrtRSI;
  n = Energy->size[0] * Energy->size[1];
  Energy->size[0] = 1;
  Energy->size[1] = b_x->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)Energy, n, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  if ((b_x->size[0] == 0) || (b_x->size[1] == 0)) {
    n = Energy->size[0] * Energy->size[1];
    Energy->size[0] = 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)Energy, n, (int32_T)sizeof
                      (real_T), &fb_emlrtRTEI);
    i = Energy->size[1];
    for (n = 0; n < i; n++) {
      Energy->data[Energy->size[0] * n] = 0.0;
    }
  } else {
    n = b_x->size[0];
    d_st.site = &qg_emlrtRSI;
    overflow = (b_x->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (i = 0; i + 1 <= b_x->size[1]; i++) {
      xoffset = i * n;
      s = b_x->data[xoffset];
      d_st.site = &rg_emlrtRSI;
      if ((!(2 > n)) && (n > 2147483646)) {
        e_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (k = 2; k <= n; k++) {
        s += b_x->data[(xoffset + k) - 1];
      }

      Energy->data[i] = s;
    }
  }

  emxFree_real_T(&b_x);
  st.site = &ie_emlrtRSI;
  s = mean(&st, Energy);
  n = Energy->size[0] * Energy->size[1];
  Energy->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)Energy, n, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  n = Energy->size[0];
  i = Energy->size[1];
  i *= n;
  for (n = 0; n < i; n++) {
    Energy->data[n] /= s;
  }

  /*  The frame is voiced if NLFER enery > threshold, otherwise is unvoiced. */
  n = VUVEnergy->size[0] * VUVEnergy->size[1];
  VUVEnergy->size[0] = 1;
  VUVEnergy->size[1] = Energy->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVEnergy, n, (int32_T)sizeof
                    (boolean_T), &fb_emlrtRTEI);
  i = Energy->size[0] * Energy->size[1];
  for (n = 0; n < i; n++) {
    VUVEnergy->data[n] = (Energy->data[n] > Prm_nlfer_thresh1);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nlfer.c) */
