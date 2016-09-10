/*
 * File: nlfer.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "nlfer.h"
#include "abs.h"
#include "yaapt_emxutil.h"
#include "mean.h"
#include "Myspecgram.h"
#include "cmp_rate.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * NLFER  Normalized Low Frequency Energy Ratio
 *
 *    [Energy, VUVEnergy]= nlfer(Data, Fs, Prm) computes the
 *    nromlized low frequency energy ratio.
 *
 *  INPUTS:
 *    Data:  Nonlinear, filtered signal for NLFER caculation
 *    Fs:    The sampling frequency.
 *    Prm:   Array of parameters used to control performance
 *
 *  OUTPUTS:
 *    Energy:     NLFER Energy of the data
 *    VUVEnergy:  Voiced/Unvoiced decisions (optimum??)
 * Arguments    : const emxArray_real_T *Data
 *                double Fs
 *                double Prm_frame_length
 *                double Prm_frame_space
 *                double Prm_f0_min
 *                double Prm_f0_max
 *                double Prm_fft_length
 *                double Prm_nlfer_thresh1
 *                emxArray_real_T *Energy
 *                emxArray_boolean_T *VUVEnergy
 * Return Type  : void
 */
void nlfer(const emxArray_real_T *Data, double Fs, double Prm_frame_length,
           double Prm_frame_space, double Prm_f0_min, double Prm_f0_max, double
           Prm_fft_length, double Prm_nlfer_thresh1, emxArray_real_T *Energy,
           emxArray_boolean_T *VUVEnergy)
{
  double s;
  double nframesize;
  emxArray_real_T *b_Data;
  double N_F0_min;
  double N_F0_max;
  int n;
  int i;
  emxArray_creal_T *SpecData;
  double b_s;
  int xoffset;
  emxArray_creal_T *x;
  int k;
  emxArray_creal_T *b_SpecData;
  int loop_ub;
  int i11;
  unsigned int uv1[2];
  emxArray_real_T *y;

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
    nframesize = ceil(s);
  } else {
    nframesize = floor(s);
  }

  s = Prm_frame_space * Fs / 1000.0;
  emxInit_real_T(&b_Data, 2);

  /*  If normalized low-frequency energy is below this, assume unvoiced frame */
  /*  Low freqeuncy range for NLFER */
  N_F0_min = rt_roundd_snf(Prm_f0_min * 2.0 / Fs * Prm_fft_length);
  N_F0_max = rt_roundd_snf(Prm_f0_max / Fs * Prm_fft_length);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Spectrogram of the data */
  n = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1];
  emxEnsureCapacity((emxArray__common *)b_Data, n, (int)sizeof(double));
  i = Data->size[0] * Data->size[1];
  for (n = 0; n < i; n++) {
    b_Data->data[n] = Data->data[n];
  }

  emxInit_creal_T(&SpecData, 2);
  if (s < 0.0) {
    b_s = ceil(s);
  } else {
    b_s = floor(s);
  }

  Myspecgram(b_Data, Prm_fft_length, nframesize, nframesize - b_s, SpecData);

  /*  SpecData_test = specgram(Data,nfftlength,Fs,(nframesize),(nframesize-nframejump)); */
  /*  Compute normalize low-frequency energy ratio  */
  emxFree_real_T(&b_Data);
  if (N_F0_min > N_F0_max) {
    n = 1;
    xoffset = 1;
  } else {
    n = (int)N_F0_min;
    xoffset = (int)N_F0_max + 1;
  }

  emxInit_creal_T(&x, 2);
  i = SpecData->size[1];
  k = x->size[0] * x->size[1];
  x->size[0] = xoffset - n;
  x->size[1] = i;
  emxEnsureCapacity((emxArray__common *)x, k, (int)sizeof(creal_T));
  for (k = 0; k < i; k++) {
    loop_ub = xoffset - n;
    for (i11 = 0; i11 < loop_ub; i11++) {
      x->data[i11 + x->size[0] * k] = SpecData->data[((n + i11) + SpecData->
        size[0] * k) - 1];
    }
  }

  emxInit_creal_T(&b_SpecData, 2);
  i = SpecData->size[1];
  k = b_SpecData->size[0] * b_SpecData->size[1];
  b_SpecData->size[0] = xoffset - n;
  b_SpecData->size[1] = i;
  emxEnsureCapacity((emxArray__common *)b_SpecData, k, (int)sizeof(creal_T));
  for (k = 0; k < i; k++) {
    loop_ub = xoffset - n;
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_SpecData->data[i11 + b_SpecData->size[0] * k] = SpecData->data[((n + i11)
        + SpecData->size[0] * k) - 1];
    }
  }

  for (k = 0; k < 2; k++) {
    uv1[k] = (unsigned int)b_SpecData->size[k];
  }

  emxFree_creal_T(&b_SpecData);
  emxInit_real_T(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = (int)uv1[0];
  y->size[1] = (int)uv1[1];
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(double));
  k = SpecData->size[1];
  n = (xoffset - n) * k;
  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = rt_hypotd_snf(x->data[k].re, x->data[k].im);
  }

  emxFree_creal_T(&x);
  emxFree_creal_T(&SpecData);
  n = Energy->size[0] * Energy->size[1];
  Energy->size[0] = 1;
  Energy->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)Energy, n, (int)sizeof(double));
  if (y->size[0] == 0) {
    n = Energy->size[0] * Energy->size[1];
    Energy->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)Energy, n, (int)sizeof(double));
    i = Energy->size[1];
    for (n = 0; n < i; n++) {
      Energy->data[Energy->size[0] * n] = 0.0;
    }
  } else {
    n = y->size[0];
    for (i = 0; i + 1 <= y->size[1]; i++) {
      xoffset = i * n;
      s = y->data[xoffset];
      for (k = 2; k <= n; k++) {
        s += y->data[(xoffset + k) - 1];
      }

      Energy->data[i] = s;
    }
  }

  emxFree_real_T(&y);
  s = mean(Energy);
  n = Energy->size[0] * Energy->size[1];
  Energy->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)Energy, n, (int)sizeof(double));
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
  emxEnsureCapacity((emxArray__common *)VUVEnergy, n, (int)sizeof(boolean_T));
  i = Energy->size[0] * Energy->size[1];
  for (n = 0; n < i; n++) {
    VUVEnergy->data[n] = (Energy->data[n] > Prm_nlfer_thresh1);
  }
}

/*
 * File trailer for nlfer.c
 *
 * [EOF]
 */
