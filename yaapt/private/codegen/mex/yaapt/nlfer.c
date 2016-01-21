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
#include "Myspecgram.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo qc_emlrtRSI = { 46, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo rc_emlrtRSI = { 49, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo sc_emlrtRSI = { 50, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo j_emlrtRTEI = { 1, 30, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo k_emlrtRTEI = { 46, 1, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo l_emlrtRTEI = { 49, 1, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtDCInfo e_emlrtDCI = { 49, 30, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m", 1 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 49, 30, "SpecData", "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m", 0 };

/* Function Definitions */

/*
 * function[Energy, VUVEnergy]= nlfer(Data, Fs, Prm)
 */
void nlfer(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs,
           emxArray_real_T *Energy, emxArray_boolean_T *VUVEnergy)
{
  real_T s;
  real_T nframesize;
  emxArray_real_T *b_Data;
  real_T N_F0_min;
  real_T N_F0_max;
  int32_T i9;
  int32_T n;
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
  boolean_T b1;
  int32_T k;
  boolean_T overflow;
  boolean_T p;
  int32_T exitg1;
  emxArray_real_T *FrmEnergy;
  boolean_T b2;
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
  s = 20.0 * Fs / 1000.0;
  if (s < 0.0) {
    nframesize = muDoubleScalarCeil(s);
  } else {
    nframesize = muDoubleScalarFloor(s);
  }

  /* 'nlfer:34' nframejump = fix(Prm.frame_space*Fs/1000); */
  s = 30.0 * Fs / 1000.0;
  emxInit_real_T(sp, &b_Data, 2, &j_emlrtRTEI, true);

  /*  If normalized low-frequency energy is below this, assume unvoiced frame */
  /* 'nlfer:37' nlfer_thersh1  = Prm.nlfer_thresh1; */
  /*  Low freqeuncy range for NLFER */
  /* 'nlfer:40' N_F0_min = round ((Prm.f0_min*2/Fs) * nfftlength ); */
  N_F0_min = muDoubleScalarRound(120.0 / Fs * 8192.0);

  /* 'nlfer:41' N_F0_max = round ((Prm.f0_max/Fs) * nfftlength ); */
  N_F0_max = muDoubleScalarRound(400.0 / Fs * 8192.0);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Spectrogram of the data */
  /* 'nlfer:46' SpecData = Myspecgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  i9 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, i9, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  n = Data->size[0] * Data->size[1];
  for (i9 = 0; i9 < n; i9++) {
    b_Data->data[i9] = Data->data[i9];
  }

  emxInit_creal_T(sp, &SpecData, 2, &k_emlrtRTEI, true);
  if (s < 0.0) {
    b_s = muDoubleScalarCeil(s);
  } else {
    b_s = muDoubleScalarFloor(s);
  }

  st.site = &qc_emlrtRSI;
  Myspecgram(&st, b_Data, nframesize, nframesize - b_s, SpecData);

  /*  SpecData_test = specgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  /*  Compute normalize low-frequency energy ratio  */
  /* 'nlfer:49' FrmEnergy = sum(abs(SpecData(N_F0_min:N_F0_max,:))); */
  emxFree_real_T(&b_Data);
  if (N_F0_min > N_F0_max) {
    vlen = 1;
    i9 = 1;
  } else {
    if (N_F0_min != (int32_T)muDoubleScalarFloor(N_F0_min)) {
      emlrtIntegerCheckR2012b(N_F0_min, &e_emlrtDCI, sp);
    }

    i9 = SpecData->size[0];
    vlen = (int32_T)N_F0_min;
    if (!((vlen >= 1) && (vlen <= i9))) {
      emlrtDynamicBoundsCheckR2012b(vlen, 1, i9, &j_emlrtBCI, sp);
    }

    if (N_F0_max != (int32_T)muDoubleScalarFloor(N_F0_max)) {
      emlrtIntegerCheckR2012b(N_F0_max, &e_emlrtDCI, sp);
    }

    i9 = SpecData->size[0];
    ix = (int32_T)N_F0_max;
    if (!((ix >= 1) && (ix <= i9))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i9, &j_emlrtBCI, sp);
    }

    i9 = ix + 1;
  }

  emxInit_creal_T(sp, &x, 2, &j_emlrtRTEI, true);
  st.site = &rc_emlrtRSI;
  n = SpecData->size[1];
  ix = x->size[0] * x->size[1];
  x->size[0] = i9 - vlen;
  x->size[1] = n;
  emxEnsureCapacity(&st, (emxArray__common *)x, ix, (int32_T)sizeof(creal_T),
                    &j_emlrtRTEI);
  for (ix = 0; ix < n; ix++) {
    iy = i9 - vlen;
    for (i = 0; i < iy; i++) {
      x->data[i + x->size[0] * ix] = SpecData->data[((vlen + i) + SpecData->
        size[0] * ix) - 1];
    }
  }

  emxInit_creal_T(&st, &b_SpecData, 2, &j_emlrtRTEI, true);
  b_st.site = &rd_emlrtRSI;
  n = SpecData->size[1];
  ix = b_SpecData->size[0] * b_SpecData->size[1];
  b_SpecData->size[0] = i9 - vlen;
  b_SpecData->size[1] = n;
  emxEnsureCapacity(&b_st, (emxArray__common *)b_SpecData, ix, (int32_T)sizeof
                    (creal_T), &j_emlrtRTEI);
  for (ix = 0; ix < n; ix++) {
    iy = i9 - vlen;
    for (i = 0; i < iy; i++) {
      b_SpecData->data[i + b_SpecData->size[0] * ix] = SpecData->data[((vlen + i)
        + SpecData->size[0] * ix) - 1];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    sz[ix] = (uint32_T)b_SpecData->size[ix];
  }

  emxFree_creal_T(&b_SpecData);
  emxInit_real_T(&b_st, &b_x, 2, &j_emlrtRTEI, true);
  ix = b_x->size[0] * b_x->size[1];
  b_x->size[0] = (int32_T)sz[0];
  b_x->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)b_x, ix, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  ix = SpecData->size[1];
  n = (i9 - vlen) * ix;
  c_st.site = &sd_emlrtRSI;
  if (1 > n) {
    b1 = false;
  } else {
    b1 = (n > 2147483646);
  }

  if (b1) {
    d_st.site = &kb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  for (k = 0; k + 1 <= n; k++) {
    b_x->data[k] = muDoubleScalarHypot(x->data[k].re, x->data[k].im);
  }

  emxFree_creal_T(&x);
  emxFree_creal_T(&SpecData);
  st.site = &rc_emlrtRSI;
  b_st.site = &td_emlrtRSI;
  if (((b_x->size[0] == 1) && (b_x->size[1] == 1)) || (b_x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &ce_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      i9 = b_x->size[k];
      if (i9 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &de_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  c_st.site = &ud_emlrtRSI;
  for (i9 = 0; i9 < 2; i9++) {
    sz[i9] = (uint32_T)b_x->size[i9];
  }

  emxInit_real_T(&c_st, &FrmEnergy, 2, &l_emlrtRTEI, true);
  i9 = FrmEnergy->size[0] * FrmEnergy->size[1];
  FrmEnergy->size[0] = 1;
  FrmEnergy->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)FrmEnergy, i9, (int32_T)sizeof
                    (real_T), &j_emlrtRTEI);
  if ((b_x->size[0] == 0) || (b_x->size[1] == 0)) {
    i9 = FrmEnergy->size[0] * FrmEnergy->size[1];
    FrmEnergy->size[0] = 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)FrmEnergy, i9, (int32_T)sizeof
                      (real_T), &j_emlrtRTEI);
    n = FrmEnergy->size[1];
    for (i9 = 0; i9 < n; i9++) {
      FrmEnergy->data[FrmEnergy->size[0] * i9] = 0.0;
    }
  } else {
    vlen = b_x->size[0];
    ix = -1;
    iy = -1;
    d_st.site = &vd_emlrtRSI;
    overflow = (b_x->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &kb_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (i = 1; i <= b_x->size[1]; i++) {
      n = ix + 1;
      ix++;
      s = b_x->data[n];
      d_st.site = &wd_emlrtRSI;
      if (2 > vlen) {
        b2 = false;
      } else {
        b2 = (vlen > 2147483646);
      }

      if (b2) {
        e_st.site = &kb_emlrtRSI;
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
  st.site = &sc_emlrtRSI;
  avgEnergy = mean(&st, FrmEnergy);

  /* 'nlfer:52' Energy = FrmEnergy/avgEnergy; */
  c_rdivide(sp, FrmEnergy, avgEnergy, Energy);

  /*  The frame is voiced if NLFER enery > threshold, otherwise is unvoiced. */
  /* 'nlfer:54' VUVEnergy = (Energy > nlfer_thersh1); */
  i9 = VUVEnergy->size[0] * VUVEnergy->size[1];
  VUVEnergy->size[0] = 1;
  VUVEnergy->size[1] = Energy->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVEnergy, i9, (int32_T)sizeof
                    (boolean_T), &j_emlrtRTEI);
  n = Energy->size[0] * Energy->size[1];
  emxFree_real_T(&FrmEnergy);
  for (i9 = 0; i9 < n; i9++) {
    VUVEnergy->data[i9] = (Energy->data[i9] > 0.75);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nlfer.c) */
