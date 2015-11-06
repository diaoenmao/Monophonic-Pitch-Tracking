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
#include "eml_warning.h"
#include "mean.h"
#include "eml_int_forloop_overflow_check.h"
#include "Myspecgram.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo xb_emlrtRSI = { 46, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo yb_emlrtRSI = { 49, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo ac_emlrtRSI = { 50, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRSInfo vc_emlrtRSI = { 70, "sum",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

static emlrtRTEInfo h_emlrtRTEI = { 1, 30, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtRTEInfo j_emlrtRTEI = { 55, 1, "sum",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

static emlrtRTEInfo k_emlrtRTEI = { 46, 1, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m" };

static emlrtDCInfo e_emlrtDCI = { 49, 30, "nlfer",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m", 1 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 49, 30, "SpecData", "nlfer",
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
  int32_T i5;
  int32_T ixstart;
  emxArray_creal_T *SpecData;
  real_T b_s;
  int32_T k;
  int32_T i;
  emxArray_creal_T *x;
  int32_T ix;
  int32_T iy;
  emxArray_creal_T *b_SpecData;
  uint32_T sz[2];
  emxArray_real_T *b_x;
  boolean_T overflow;
  boolean_T p;
  int32_T exitg1;
  const mxArray *y;
  static const int32_T iv13[2] = { 1, 30 };

  const mxArray *m6;
  char_T cv21[30];
  static const char_T cv22[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 's', 'u', 'm', '_', 's', 'p', 'e', 'c', 'i', 'a',
    'l', 'E', 'm', 'p', 't', 'y' };

  const mxArray *b_y;
  static const int32_T iv14[2] = { 1, 36 };

  char_T cv23[36];
  static const char_T cv24[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
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
  s = 25.0 * Fs / 1000.0;
  if (s < 0.0) {
    nframesize = muDoubleScalarCeil(s);
  } else {
    nframesize = muDoubleScalarFloor(s);
  }

  /* 'nlfer:34' nframejump = fix(Prm.frame_space*Fs/1000); */
  s = 10.0 * Fs / 1000.0;
  emxInit_real_T(sp, &b_Data, 2, &h_emlrtRTEI, true);

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
  i5 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, i5, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  ixstart = Data->size[0] * Data->size[1];
  for (i5 = 0; i5 < ixstart; i5++) {
    b_Data->data[i5] = Data->data[i5];
  }

  emxInit_creal_T(sp, &SpecData, 2, &k_emlrtRTEI, true);
  if (s < 0.0) {
    b_s = muDoubleScalarCeil(s);
  } else {
    b_s = muDoubleScalarFloor(s);
  }

  st.site = &xb_emlrtRSI;
  Myspecgram(&st, b_Data, nframesize, nframesize - b_s, SpecData);

  /*  SpecData_test = specgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  /*  Compute normalize low-frequency energy ratio  */
  /* 'nlfer:49' FrmEnergy = sum(abs(SpecData(N_F0_min:N_F0_max,:))); */
  emxFree_real_T(&b_Data);
  if (N_F0_min > N_F0_max) {
    i5 = 1;
    k = 1;
  } else {
    i5 = SpecData->size[0];
    k = (int32_T)emlrtIntegerCheckFastR2012b(N_F0_min, &e_emlrtDCI, sp);
    i5 = emlrtDynamicBoundsCheckFastR2012b(k, 1, i5, &sb_emlrtBCI, sp);
    k = SpecData->size[0];
    i = (int32_T)emlrtIntegerCheckFastR2012b(N_F0_max, &e_emlrtDCI, sp);
    k = emlrtDynamicBoundsCheckFastR2012b(i, 1, k, &sb_emlrtBCI, sp) + 1;
  }

  emxInit_creal_T(sp, &x, 2, &h_emlrtRTEI, true);
  ixstart = SpecData->size[1];
  i = x->size[0] * x->size[1];
  x->size[0] = k - i5;
  x->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)x, i, (int32_T)sizeof(creal_T),
                    &h_emlrtRTEI);
  for (i = 0; i < ixstart; i++) {
    ix = k - i5;
    for (iy = 0; iy < ix; iy++) {
      x->data[iy + x->size[0] * i] = SpecData->data[((i5 + iy) + SpecData->size
        [0] * i) - 1];
    }
  }

  emxInit_creal_T(sp, &b_SpecData, 2, &h_emlrtRTEI, true);
  ixstart = SpecData->size[1];
  i = b_SpecData->size[0] * b_SpecData->size[1];
  b_SpecData->size[0] = k - i5;
  b_SpecData->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)b_SpecData, i, (int32_T)sizeof
                    (creal_T), &h_emlrtRTEI);
  for (i = 0; i < ixstart; i++) {
    ix = k - i5;
    for (iy = 0; iy < ix; iy++) {
      b_SpecData->data[iy + b_SpecData->size[0] * i] = SpecData->data[((i5 + iy)
        + SpecData->size[0] * i) - 1];
    }
  }

  for (i = 0; i < 2; i++) {
    sz[i] = (uint32_T)b_SpecData->size[i];
  }

  emxFree_creal_T(&b_SpecData);
  emxInit_real_T(sp, &b_x, 2, &h_emlrtRTEI, true);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = (int32_T)sz[0];
  b_x->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_x, i, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  i = SpecData->size[1];
  i5 = (k - i5) * i;
  for (k = 0; k < i5; k++) {
    b_x->data[k] = muDoubleScalarHypot(x->data[k].re, x->data[k].im);
  }

  emxFree_creal_T(&x);
  emxFree_creal_T(&SpecData);
  st.site = &yb_emlrtRSI;
  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (b_x->size[k] != 0) {
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
    y = NULL;
    m6 = emlrtCreateCharArray(2, iv13);
    for (i = 0; i < 30; i++) {
      cv21[i] = cv22[i];
    }

    emlrtInitCharArrayR2013a(&st, 30, m6, cv21);
    emlrtAssign(&y, m6);
    b_st.site = &mk_emlrtRSI;
    c_st.site = &uj_emlrtRSI;
    f_error(&b_st, b_message(&c_st, y, &m_emlrtMCI), &n_emlrtMCI);
  }

  if (((b_x->size[0] == 1) && (b_x->size[1] == 1)) || (b_x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    b_y = NULL;
    m6 = emlrtCreateCharArray(2, iv14);
    for (i = 0; i < 36; i++) {
      cv23[i] = cv24[i];
    }

    emlrtInitCharArrayR2013a(&st, 36, m6, cv23);
    emlrtAssign(&b_y, m6);
    b_st.site = &lk_emlrtRSI;
    c_st.site = &tj_emlrtRSI;
    f_error(&b_st, b_message(&c_st, b_y, &o_emlrtMCI), &p_emlrtMCI);
  }

  for (i5 = 0; i5 < 2; i5++) {
    sz[i5] = (uint32_T)b_x->size[i5];
  }

  i5 = Energy->size[0] * Energy->size[1];
  Energy->size[0] = 1;
  Energy->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(&st, (emxArray__common *)Energy, i5, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  if ((b_x->size[0] == 0) || (b_x->size[1] == 0)) {
    i5 = Energy->size[0] * Energy->size[1];
    Energy->size[0] = 1;
    emxEnsureCapacity(&st, (emxArray__common *)Energy, i5, (int32_T)sizeof
                      (real_T), &h_emlrtRTEI);
    i5 = Energy->size[0] * Energy->size[1];
    Energy->size[1] = (int32_T)sz[1];
    emxEnsureCapacity(&st, (emxArray__common *)Energy, i5, (int32_T)sizeof
                      (real_T), &h_emlrtRTEI);
    ixstart = (int32_T)sz[1];
    for (i5 = 0; i5 < ixstart; i5++) {
      Energy->data[i5] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    b_st.site = &vc_emlrtRSI;
    overflow = (b_x->size[1] > 2147483646);
    if (overflow) {
      d_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (i = 1; i <= b_x->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      s = b_x->data[ixstart];
      b_st.site = &wc_emlrtRSI;
      for (k = 2; k <= b_x->size[0]; k++) {
        ix++;
        s += b_x->data[ix];
      }

      iy++;
      Energy->data[iy] = s;
    }
  }

  emxFree_real_T(&b_x);

  /* 'nlfer:50' avgEnergy = mean(FrmEnergy); */
  st.site = &ac_emlrtRSI;
  s = mean(&st, Energy);

  /* 'nlfer:52' Energy = FrmEnergy/avgEnergy; */
  i5 = Energy->size[0] * Energy->size[1];
  Energy->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)Energy, i5, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  ixstart = Energy->size[0];
  k = Energy->size[1];
  ixstart *= k;
  for (i5 = 0; i5 < ixstart; i5++) {
    Energy->data[i5] /= s;
  }

  /*  The frame is voiced if NLFER enery > threshold, otherwise is unvoiced. */
  /* 'nlfer:54' VUVEnergy = (Energy > nlfer_thersh1); */
  i5 = VUVEnergy->size[0] * VUVEnergy->size[1];
  VUVEnergy->size[0] = 1;
  VUVEnergy->size[1] = Energy->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVEnergy, i5, (int32_T)sizeof
                    (boolean_T), &h_emlrtRTEI);
  ixstart = Energy->size[0] * Energy->size[1];
  for (i5 = 0; i5 < ixstart; i5++) {
    VUVEnergy->data[i5] = (Energy->data[i5] > 0.75);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nlfer.c) */
