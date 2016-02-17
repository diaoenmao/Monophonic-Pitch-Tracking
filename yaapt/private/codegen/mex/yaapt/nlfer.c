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
#include "rdivide.h"
#include "mean.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "Myspecgram.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo we_emlrtRSI = { 46, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo xe_emlrtRSI = { 49, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo ye_emlrtRSI = { 50, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 1, 30, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo gb_emlrtRTEI = { 46, 1, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo hb_emlrtRTEI = { 49, 1, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtDCInfo m_emlrtDCI = { 49, 30, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m", 1 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 49, 30, "SpecData", "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m", 0 };

/* Function Definitions */

/*
 * function[Energy, VUVEnergy]= nlfer(Data, Fs, Prm)
 */
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
  int32_T k;
  emxArray_creal_T *SpecData;
  real_T b_s;
  int32_T vlen;
  int32_T ix;
  emxArray_creal_T *x;
  int32_T iy;
  int32_T i;
  emxArray_creal_T *b_SpecData;
  uint32_T sz[2];
  emxArray_real_T *b_x;
  boolean_T b5;
  boolean_T overflow;
  emxArray_real_T *FrmEnergy;
  boolean_T b6;
  real_T avgEnergy;
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
  /* 'nlfer:32' nfftlength = Prm.fft_length; */
  /*  FFT length */
  /* 'nlfer:33' nframesize = fix(Prm.frame_length*Fs/1000); */
  s = Prm_frame_length * Fs / 1000.0;
  if (s < 0.0) {
    nframesize = muDoubleScalarCeil(s);
  } else {
    nframesize = muDoubleScalarFloor(s);
  }

  /* 'nlfer:34' nframejump = fix(Prm.frame_space*Fs/1000); */
  s = Prm_frame_space * Fs / 1000.0;
  emxInit_real_T(sp, &b_Data, 2, &fb_emlrtRTEI, true);

  /*  If normalized low-frequency energy is below this, assume unvoiced frame */
  /* 'nlfer:37' nlfer_thersh1  = Prm.nlfer_thresh1; */
  /*  Low freqeuncy range for NLFER */
  /* 'nlfer:40' N_F0_min = round ((Prm.f0_min*2/Fs) * nfftlength ); */
  N_F0_min = muDoubleScalarRound(Prm_f0_min * 2.0 / Fs * Prm_fft_length);

  /* 'nlfer:41' N_F0_max = round ((Prm.f0_max/Fs) * nfftlength ); */
  N_F0_max = muDoubleScalarRound(Prm_f0_max / Fs * Prm_fft_length);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Spectrogram of the data */
  /* 'nlfer:46' SpecData = Myspecgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  n = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, n, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  k = Data->size[0] * Data->size[1];
  for (n = 0; n < k; n++) {
    b_Data->data[n] = Data->data[n];
  }

  emxInit_creal_T(sp, &SpecData, 2, &gb_emlrtRTEI, true);
  if (s < 0.0) {
    b_s = muDoubleScalarCeil(s);
  } else {
    b_s = muDoubleScalarFloor(s);
  }

  st.site = &we_emlrtRSI;
  Myspecgram(&st, b_Data, Prm_fft_length, nframesize, nframesize - b_s, SpecData);

  /*  SpecData_test = specgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  /*  Compute normalize low-frequency energy ratio  */
  /* 'nlfer:49' FrmEnergy = sum(abs(SpecData(N_F0_min:N_F0_max,:))); */
  emxFree_real_T(&b_Data);
  if (N_F0_min > N_F0_max) {
    vlen = 1;
    n = 1;
  } else {
    if (N_F0_min != (int32_T)muDoubleScalarFloor(N_F0_min)) {
      emlrtIntegerCheckR2012b(N_F0_min, &m_emlrtDCI, sp);
    }

    n = SpecData->size[0];
    vlen = (int32_T)N_F0_min;
    if (!((vlen >= 1) && (vlen <= n))) {
      emlrtDynamicBoundsCheckR2012b(vlen, 1, n, &dc_emlrtBCI, sp);
    }

    if (N_F0_max != (int32_T)muDoubleScalarFloor(N_F0_max)) {
      emlrtIntegerCheckR2012b(N_F0_max, &m_emlrtDCI, sp);
    }

    n = SpecData->size[0];
    ix = (int32_T)N_F0_max;
    if (!((ix >= 1) && (ix <= n))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, n, &dc_emlrtBCI, sp);
    }

    n = ix + 1;
  }

  emxInit_creal_T(sp, &x, 2, &fb_emlrtRTEI, true);
  st.site = &xe_emlrtRSI;
  k = SpecData->size[1];
  ix = x->size[0] * x->size[1];
  x->size[0] = n - vlen;
  x->size[1] = k;
  emxEnsureCapacity(&st, (emxArray__common *)x, ix, (int32_T)sizeof(creal_T),
                    &fb_emlrtRTEI);
  for (ix = 0; ix < k; ix++) {
    iy = n - vlen;
    for (i = 0; i < iy; i++) {
      x->data[i + x->size[0] * ix] = SpecData->data[((vlen + i) + SpecData->
        size[0] * ix) - 1];
    }
  }

  emxInit_creal_T(&st, &b_SpecData, 2, &fb_emlrtRTEI, true);
  b_st.site = &bg_emlrtRSI;
  k = SpecData->size[1];
  ix = b_SpecData->size[0] * b_SpecData->size[1];
  b_SpecData->size[0] = n - vlen;
  b_SpecData->size[1] = k;
  emxEnsureCapacity(&b_st, (emxArray__common *)b_SpecData, ix, (int32_T)sizeof
                    (creal_T), &fb_emlrtRTEI);
  for (ix = 0; ix < k; ix++) {
    iy = n - vlen;
    for (i = 0; i < iy; i++) {
      b_SpecData->data[i + b_SpecData->size[0] * ix] = SpecData->data[((vlen + i)
        + SpecData->size[0] * ix) - 1];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    sz[ix] = (uint32_T)b_SpecData->size[ix];
  }

  emxFree_creal_T(&b_SpecData);
  emxInit_real_T(&b_st, &b_x, 2, &fb_emlrtRTEI, true);
  ix = b_x->size[0] * b_x->size[1];
  b_x->size[0] = (int32_T)sz[0];
  b_x->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)b_x, ix, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  ix = SpecData->size[1];
  n = (n - vlen) * ix;
  c_st.site = &cg_emlrtRSI;
  if (1 > n) {
    b5 = false;
  } else {
    b5 = (n > 2147483646);
  }

  if (b5) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  for (k = 0; k + 1 <= n; k++) {
    b_x->data[k] = muDoubleScalarHypot(x->data[k].re, x->data[k].im);
  }

  emxFree_creal_T(&x);
  emxFree_creal_T(&SpecData);
  st.site = &xe_emlrtRSI;
  b_st.site = &dg_emlrtRSI;
  if (((b_x->size[0] == 1) && (b_x->size[1] == 1)) || (b_x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &lf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = !c_isequal(b_x);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &mf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  c_st.site = &eg_emlrtRSI;
  for (n = 0; n < 2; n++) {
    sz[n] = (uint32_T)b_x->size[n];
  }

  emxInit_real_T(&c_st, &FrmEnergy, 2, &hb_emlrtRTEI, true);
  n = FrmEnergy->size[0] * FrmEnergy->size[1];
  FrmEnergy->size[0] = 1;
  FrmEnergy->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)FrmEnergy, n, (int32_T)sizeof
                    (real_T), &fb_emlrtRTEI);
  if ((b_x->size[0] == 0) || (b_x->size[1] == 0)) {
    n = FrmEnergy->size[0] * FrmEnergy->size[1];
    FrmEnergy->size[0] = 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)FrmEnergy, n, (int32_T)sizeof
                      (real_T), &fb_emlrtRTEI);
    k = FrmEnergy->size[1];
    for (n = 0; n < k; n++) {
      FrmEnergy->data[FrmEnergy->size[0] * n] = 0.0;
    }
  } else {
    vlen = b_x->size[0];
    ix = -1;
    iy = -1;
    d_st.site = &fg_emlrtRSI;
    overflow = (b_x->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (i = 1; i <= b_x->size[1]; i++) {
      n = ix + 1;
      ix++;
      s = b_x->data[n];
      d_st.site = &gg_emlrtRSI;
      if (2 > vlen) {
        b6 = false;
      } else {
        b6 = (vlen > 2147483646);
      }

      if (b6) {
        e_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&e_st, true);
      }

      for (k = 2; k <= vlen; k++) {
        ix++;
        s += b_x->data[ix];
      }

      iy++;
      FrmEnergy->data[iy] = s;
    }
  }

  emxFree_real_T(&b_x);

  /* 'nlfer:50' avgEnergy = mean(FrmEnergy); */
  st.site = &ye_emlrtRSI;
  avgEnergy = mean(&st, FrmEnergy);

  /* 'nlfer:52' Energy = FrmEnergy/avgEnergy; */
  c_rdivide(sp, FrmEnergy, avgEnergy, Energy);

  /*  The frame is voiced if NLFER enery > threshold, otherwise is unvoiced. */
  /* 'nlfer:54' VUVEnergy = (Energy > nlfer_thersh1); */
  n = VUVEnergy->size[0] * VUVEnergy->size[1];
  VUVEnergy->size[0] = 1;
  VUVEnergy->size[1] = Energy->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVEnergy, n, (int32_T)sizeof
                    (boolean_T), &fb_emlrtRTEI);
  k = Energy->size[0] * Energy->size[1];
  emxFree_real_T(&FrmEnergy);
  for (n = 0; n < k; n++) {
    VUVEnergy->data[n] = (Energy->data[n] > Prm_nlfer_thresh1);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nlfer.c) */
