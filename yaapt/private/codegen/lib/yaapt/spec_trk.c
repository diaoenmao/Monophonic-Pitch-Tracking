/*
 * File: spec_trk.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "spec_trk.h"
#include "sum.h"
#include "prod.h"
#include "yaapt_emxutil.h"
#include "peaks.h"
#include "abs.h"
#include "fft.h"
#include "mean.h"
#include "filter.h"
#include "interp1.h"
#include "all.h"
#include "std.h"
#include "Mymedfilt1.h"
#include "dynamic5.h"
#include "repmat.h"
#include "Mykaiser.h"
#include "fix.h"
#include "mod.h"

/* Function Definitions */

/*
 * SPEC_TRK  Spectral pitch tracking for YAAPT pitch tracking
 *
 *    [SPitch, VUVSPitch, pAvg, pStd]=spec_trk(Data, Fs, VUVEnergy, Prm)
 *    computes estimates of pitch  using nonlinearly processed
 *    speech (typically square or absolute value) and frequency domain processing
 *    Search for frequencies which have energy at multiplies of that frequency
 *
 * INPUTS:
 *    Data:      Nonlinearly processed signal, filtered with F1. (~50 to 1500Hz)
 *    Fs:        The sampling frequency.
 *    VUVEnergy: Voiced/ unvoiced decision, depending on nlfer
 *    Prm:       Parameters
 *
 * OUTPUTS:
 *    SPitch:    The spectral Pitch track, with the unvoiced regions filled using interpolation.
 *    VUVSPitch: The spectral Pitch track, with  unvoiced regions set at zero
 *    pAvg:      The average of the Pitch track value.
 *    pStd:      The standard deviation in the track.
 * Arguments    : emxArray_real_T *Data
 *                double Fs
 *                const emxArray_boolean_T *VUVEnergy
 *                const struct_T *Prm
 *                emxArray_real_T *SPitch
 *                emxArray_real_T *VUVSPitch
 *                double pAvg_data[]
 *                int pAvg_size[1]
 *                double pStd_data[]
 *                int pStd_size[1]
 * Return Type  : void
 */
void spec_trk(emxArray_real_T *Data, double Fs, const emxArray_boolean_T
              *VUVEnergy, const struct_T *Prm, emxArray_real_T *SPitch,
              emxArray_real_T *VUVSPitch, double pAvg_data[], int pAvg_size[1],
              double pStd_data[], int pStd_size[1])
{
  double nframesize;
  double nframejump;
  double numframes;
  double maxpeaks;
  double delta;
  double window_length;
  emxArray_real_T *CandsPitch;
  double half_winlen;
  double max_SHC;
  double min_SHC;
  int ix;
  int itmp;
  emxArray_real_T *CandsMerit;
  double zero_padded;
  int nm1d2;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  int n;
  double anew;
  double apnd;
  double ndbl;
  emxArray_real_T *VPeak_minmrt;
  double cdiff;
  emxArray_real_T *winix;
  int idx;
  double absb;
  emxArray_real_T *b_VPeak_minmrt;
  emxArray_real_T *rowix;
  int frame;
  emxArray_real_T *Signal;
  emxArray_real_T *Magnit;
  emxArray_int32_T *r16;
  emxArray_creal_T *r17;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  emxArray_real_T *r18;
  emxArray_real_T *r19;
  double firstp;
  int cindx;
  double k;
  emxArray_boolean_T *Idx_voiced;
  emxArray_int32_T *iindx;
  int i;
  emxArray_boolean_T *b_SPitch;
  double Num_VCands;
  emxArray_real_T *b_CandsPitch;
  emxArray_int32_T *b_iindx;
  emxArray_real_T *c_CandsPitch;
  double avg_voiced;
  emxArray_real_T *d_CandsPitch;
  emxArray_int32_T *c_iindx;
  emxArray_real_T *e_CandsPitch;
  double std_voiced;
  emxArray_real_T *f_CandsPitch;
  emxArray_real_T *r20;
  emxArray_real_T *delta1;
  unsigned int uv2[2];
  boolean_T exitg2;
  emxArray_real_T *c_VPeak_minmrt;
  double d2;
  emxArray_real_T *VPitch;
  signed char tmp_data[1];
  double b_Prm;
  emxArray_boolean_T *c_SPitch;
  double SPitch_temp_end;
  emxArray_boolean_T *b_SPitch_temp_end;
  emxArray_int32_T *jj;
  unsigned int unnamed_idx_1;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *b_jj;
  emxArray_real_T *d_SPitch;

  /*    Creation date:  Feb 20, 2006 */
  /*    Revision dates: Feb 22, 2006,  March 11, 2006, April 5, 2006, */
  /*                    Jun 25, 2006,  June 13, 2007 */
  /*    Programers:     Hongbing Hu, Princy, Zahorian */
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
  nframesize = Prm->frame_length * Fs / 1000.0;
  b_fix(&nframesize);
  nframejump = Prm->frame_space * Fs / 1000.0;
  b_fix(&nframejump);

  /*  overlap width in sample  */
  numframes = ((double)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /*  use larger frame size */
  nframesize *= 2.0;

  /*  Max number of peak candidates found */
  maxpeaks = Prm->shc_maxpeaks;

  /*  FFT length */
  /*  Resolution of spectrum */
  delta = Fs / Prm->fft_length;

  /*  Window width in sample */
  window_length = Prm->shc_window / delta;
  b_fix(&window_length);
  if (b_mod(window_length) == 0.0) {
    window_length++;
  }

  emxInit_real_T(&CandsPitch, 2);

  /*  Half window width */
  half_winlen = Prm->shc_window / (delta * 2.0);
  b_fix(&half_winlen);

  /*  Max range of SHC  */
  max_SHC = (Prm->f0_max + Prm->shc_pwidth * 2.0) / delta;
  b_fix(&max_SHC);

  /*  Min range of SHC  */
  min_SHC = ceil(Prm->f0_min / delta);

  /*  Number of harmomics considered */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  ix = CandsPitch->size[0] * CandsPitch->size[1];
  CandsPitch->size[0] = (int)Prm->shc_maxpeaks;
  CandsPitch->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)CandsPitch, ix, (int)sizeof(double));
  itmp = (int)Prm->shc_maxpeaks * (int)numframes;
  for (ix = 0; ix < itmp; ix++) {
    CandsPitch->data[ix] = 0.0;
  }

  emxInit_real_T(&CandsMerit, 2);
  ix = CandsMerit->size[0] * CandsMerit->size[1];
  CandsMerit->size[0] = (int)Prm->shc_maxpeaks;
  CandsMerit->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)CandsMerit, ix, (int)sizeof(double));
  itmp = (int)Prm->shc_maxpeaks * (int)numframes;
  for (ix = 0; ix < itmp; ix++) {
    CandsMerit->data[ix] = 1.0;
  }

  /*  Zero paddinga */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  Data->data[Data->size[1] - 1] = 0.0;
  zero_padded = ((numframes - 1.0) * nframejump + nframesize) - (double)
    Data->size[1];
  if (zero_padded > 0.0) {
    nm1d2 = Data->size[1];
    ix = Data->size[0] * Data->size[1];
    Data->size[1] = nm1d2 + 1;
    emxEnsureCapacity((emxArray__common *)Data, ix, (int)sizeof(double));
    Data->data[nm1d2] = zero_padded;
  }

  emxInit_real_T(&Kaiser_window, 2);
  emxInit_real_T(&SHC, 2);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Compute SHC for voiced frame */
  Mykaiser(nframesize, Kaiser_window);

  /*  Kaiser_window_test = kaiser(nframesize); */
  ix = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = (int)max_SHC;
  emxEnsureCapacity((emxArray__common *)SHC, ix, (int)sizeof(double));
  itmp = (int)max_SHC;
  for (ix = 0; ix < itmp; ix++) {
    SHC->data[ix] = 0.0;
  }

  if (rtIsNaN(window_length)) {
    n = 1;
    anew = rtNaN;
    apnd = window_length;
  } else if (window_length < 1.0) {
    n = 0;
    anew = 1.0;
    apnd = window_length;
  } else if (rtIsInf(window_length)) {
    n = 1;
    anew = rtNaN;
    apnd = window_length;
  } else {
    anew = 1.0;
    ndbl = floor((window_length - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - window_length;
    if (fabs(cdiff) < 4.4408920985006262E-16 * window_length) {
      ndbl++;
      apnd = window_length;
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }
  }

  emxInit_real_T(&VPeak_minmrt, 2);
  ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  VPeak_minmrt->size[1] = n;
  emxEnsureCapacity((emxArray__common *)VPeak_minmrt, ix, (int)sizeof(double));
  if (n > 0) {
    VPeak_minmrt->data[0] = anew;
    if (n > 1) {
      VPeak_minmrt->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (idx = 1; idx < nm1d2; idx++) {
        VPeak_minmrt->data[idx] = anew + (double)idx;
        VPeak_minmrt->data[(n - idx) - 1] = apnd - (double)idx;
      }

      if (nm1d2 << 1 == n - 1) {
        VPeak_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VPeak_minmrt->data[nm1d2] = anew + (double)nm1d2;
        VPeak_minmrt->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T(&winix, 2);
  repmat(VPeak_minmrt, Prm->shc_numharms + 1.0, winix);
  if (rtIsNaN(Prm->shc_numharms + 1.0)) {
    n = 1;
    anew = rtNaN;
    apnd = Prm->shc_numharms + 1.0;
  } else if (Prm->shc_numharms + 1.0 < 1.0) {
    n = 0;
    anew = 1.0;
    apnd = Prm->shc_numharms + 1.0;
  } else if (rtIsInf(Prm->shc_numharms + 1.0)) {
    n = 1;
    anew = rtNaN;
    apnd = Prm->shc_numharms + 1.0;
  } else {
    anew = 1.0;
    ndbl = floor(((Prm->shc_numharms + 1.0) - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - (Prm->shc_numharms + 1.0);
    absb = fabs(Prm->shc_numharms + 1.0);
    if ((1.0 >= absb) || rtIsNaN(absb)) {
      absb = 1.0;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
      ndbl++;
      apnd = Prm->shc_numharms + 1.0;
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }
  }

  ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  VPeak_minmrt->size[1] = n;
  emxEnsureCapacity((emxArray__common *)VPeak_minmrt, ix, (int)sizeof(double));
  if (n > 0) {
    VPeak_minmrt->data[0] = anew;
    if (n > 1) {
      VPeak_minmrt->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (idx = 1; idx < nm1d2; idx++) {
        VPeak_minmrt->data[idx] = anew + (double)idx;
        VPeak_minmrt->data[(n - idx) - 1] = apnd - (double)idx;
      }

      if (nm1d2 << 1 == n - 1) {
        VPeak_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VPeak_minmrt->data[nm1d2] = anew + (double)nm1d2;
        VPeak_minmrt->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T1(&b_VPeak_minmrt, 1);
  ix = b_VPeak_minmrt->size[0];
  b_VPeak_minmrt->size[0] = VPeak_minmrt->size[1];
  emxEnsureCapacity((emxArray__common *)b_VPeak_minmrt, ix, (int)sizeof(double));
  itmp = VPeak_minmrt->size[1];
  for (ix = 0; ix < itmp; ix++) {
    b_VPeak_minmrt->data[ix] = VPeak_minmrt->data[VPeak_minmrt->size[0] * ix];
  }

  emxInit_real_T(&rowix, 2);
  b_repmat(b_VPeak_minmrt, window_length, rowix);
  frame = 0;
  emxFree_real_T(&b_VPeak_minmrt);
  emxInit_real_T(&Signal, 2);
  emxInit_real_T1(&Magnit, 1);
  emxInit_int32_T1(&r16, 1);
  emxInit_creal_T(&r17, 2);
  emxInit_real_T(&b_SHC, 2);
  emxInit_real_T(&b_Magnit, 2);
  emxInit_real_T(&r18, 2);
  emxInit_real_T(&r19, 2);
  while (frame <= (int)numframes - 1) {
    if ((int)VUVEnergy->data[frame] > 0) {
      firstp = 1.0 + ((1.0 + (double)frame) - 1.0) * nframejump;
      anew = (firstp + nframesize) - 1.0;
      if (firstp > anew) {
        ix = 0;
        cindx = 0;
      } else {
        ix = (int)firstp - 1;
        cindx = (int)anew;
      }

      nm1d2 = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      Signal->size[1] = cindx - ix;
      emxEnsureCapacity((emxArray__common *)Signal, nm1d2, (int)sizeof(double));
      itmp = cindx - ix;
      for (cindx = 0; cindx < itmp; cindx++) {
        Signal->data[Signal->size[0] * cindx] = Data->data[ix + cindx] *
          Kaiser_window->data[cindx];
      }

      anew = mean(Signal);
      ix = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
      itmp = Signal->size[1];
      for (ix = 0; ix < itmp; ix++) {
        Signal->data[Signal->size[0] * ix] -= anew;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      b_fft(Signal, Prm->fft_length, r17);
      b_abs(r17, VPeak_minmrt);
      ix = Magnit->size[0];
      Magnit->size[0] = (int)half_winlen + VPeak_minmrt->size[1];
      emxEnsureCapacity((emxArray__common *)Magnit, ix, (int)sizeof(double));
      itmp = (int)half_winlen;
      for (ix = 0; ix < itmp; ix++) {
        Magnit->data[ix] = 0.0;
      }

      itmp = VPeak_minmrt->size[1];
      for (ix = 0; ix < itmp; ix++) {
        Magnit->data[ix + (int)half_winlen] = VPeak_minmrt->data
          [VPeak_minmrt->size[0] * ix];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      ix = (int)(max_SHC + (1.0 - min_SHC));
      for (idx = 0; idx < ix; idx++) {
        k = min_SHC + (double)idx;
        cindx = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = winix->size[0];
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity((emxArray__common *)b_Magnit, cindx, (int)sizeof
                          (double));
        itmp = winix->size[0] * winix->size[1];
        for (cindx = 0; cindx < itmp; cindx++) {
          b_Magnit->data[cindx] = Magnit->data[(int)(winix->data[cindx] + k *
            rowix->data[cindx]) - 1];
        }

        prod(b_Magnit, VPeak_minmrt);
        SHC->data[(int)k - 1] = sum(VPeak_minmrt);
      }

      ix = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity((emxArray__common *)b_SHC, ix, (int)sizeof(double));
      itmp = SHC->size[0] * SHC->size[1];
      for (ix = 0; ix < itmp; ix++) {
        b_SHC->data[ix] = SHC->data[ix];
      }

      peaks(b_SHC, delta, maxpeaks, Prm->f0_min, Prm->f0_max, Prm->shc_pwidth,
            Prm->shc_thresh1, Prm->shc_thresh2, Prm->f0_double, Prm->f0_half,
            Prm->merit_extra, VPeak_minmrt, Signal);
      itmp = CandsPitch->size[0];
      ix = r16->size[0];
      r16->size[0] = itmp;
      emxEnsureCapacity((emxArray__common *)r16, ix, (int)sizeof(int));
      for (ix = 0; ix < itmp; ix++) {
        r16->data[ix] = ix;
      }

      nm1d2 = r16->size[0];
      for (ix = 0; ix < nm1d2; ix++) {
        CandsPitch->data[r16->data[ix] + CandsPitch->size[0] * frame] =
          VPeak_minmrt->data[ix];
      }

      itmp = CandsMerit->size[0];
      ix = r16->size[0];
      r16->size[0] = itmp;
      emxEnsureCapacity((emxArray__common *)r16, ix, (int)sizeof(int));
      for (ix = 0; ix < itmp; ix++) {
        r16->data[ix] = ix;
      }

      nm1d2 = r16->size[0];
      for (ix = 0; ix < nm1d2; ix++) {
        CandsMerit->data[r16->data[ix] + CandsMerit->size[0] * frame] =
          Signal->data[ix];
      }
    } else {
      /*  if energy is low,  let frame be considered as unvoiced */
      itmp = CandsPitch->size[0];
      ix = r16->size[0];
      r16->size[0] = itmp;
      emxEnsureCapacity((emxArray__common *)r16, ix, (int)sizeof(int));
      for (ix = 0; ix < itmp; ix++) {
        r16->data[ix] = ix;
      }

      ix = r18->size[0] * r18->size[1];
      r18->size[0] = 1;
      r18->size[1] = (int)maxpeaks;
      emxEnsureCapacity((emxArray__common *)r18, ix, (int)sizeof(double));
      itmp = (int)maxpeaks;
      for (ix = 0; ix < itmp; ix++) {
        r18->data[r18->size[0] * ix] = 0.0;
      }

      nm1d2 = r16->size[0];
      for (ix = 0; ix < nm1d2; ix++) {
        CandsPitch->data[r16->data[ix] + CandsPitch->size[0] * frame] =
          r18->data[ix];
      }

      itmp = CandsMerit->size[0];
      ix = r16->size[0];
      r16->size[0] = itmp;
      emxEnsureCapacity((emxArray__common *)r16, ix, (int)sizeof(int));
      for (ix = 0; ix < itmp; ix++) {
        r16->data[ix] = ix;
      }

      ix = r19->size[0] * r19->size[1];
      r19->size[0] = 1;
      r19->size[1] = (int)maxpeaks;
      emxEnsureCapacity((emxArray__common *)r19, ix, (int)sizeof(double));
      itmp = (int)maxpeaks;
      for (ix = 0; ix < itmp; ix++) {
        r19->data[r19->size[0] * ix] = 1.0;
      }

      nm1d2 = r16->size[0];
      for (ix = 0; ix < nm1d2; ix++) {
        CandsMerit->data[r16->data[ix] + CandsMerit->size[0] * frame] =
          r19->data[ix];
      }
    }

    frame++;
  }

  emxFree_real_T(&r19);
  emxFree_real_T(&r18);
  emxFree_real_T(&b_Magnit);
  emxFree_real_T(&b_SHC);
  emxFree_creal_T(&r17);
  emxFree_int32_T(&r16);
  emxFree_real_T(&Magnit);
  emxFree_real_T(&Kaiser_window);

  /*  display('Running new code'); */
  /*  for frame = 1:numframes */
  /*      if (VUVEnergy(frame) > 0) */
  /*          firstp = 1+(frame-1)*(nframejump); */
  /*          Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window; */
  /*          Signal = Signal - mean(Signal); */
  /*          Magnit = abs(fft(Signal , nfftlength)); */
  /*           */
  /*          % Compute SHC (Spectral Harmonic Correlation) */
  /*          for k=min_SHC:max_SHC; */
  /*              MultHarms = ones(1, window_length); */
  /*   */
  /*              % Set each harmonics, 1=f0 2=2*f0 etc */
  /*              for n=1:numharmonics+1  % Number of harmomics considered */
  /*                  nstart = n*k-half_winlen; */
  /*                  if nstart < 0 */
  /*                      Harm =  zeros(1, window_length); */
  /*                      Harm(abs(nstart)+1:window_length)=Magnit(1:nstart+window_length); */
  /*                  else */
  /*                      Harm(1:window_length)=Magnit(nstart+1:nstart+window_length); */
  /*                  end */
  /*                  MultHarms = MultHarms .* Harm; */
  /*              end */
  /*              SHC(k) = sum(MultHarms); */
  /*          end */
  /*          [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm); */
  /*      else  */
  /*          % if energy is low,  let frame be considered as unvoiced */
  /*          CandsPitch(:,frame) = zeros(1,maxpeaks); */
  /*          CandsMerit(:,frame) = ones(1, maxpeaks); */
  /*      end */
  /*  end */
  /*  Extract the Pitch candidates of voiced frames for the future Pitch selection  */
  itmp = CandsPitch->size[1];
  ix = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = itmp;
  emxEnsureCapacity((emxArray__common *)SPitch, ix, (int)sizeof(double));
  for (ix = 0; ix < itmp; ix++) {
    SPitch->data[SPitch->size[0] * ix] = CandsPitch->data[CandsPitch->size[0] *
      ix];
  }

  emxInit_boolean_T(&Idx_voiced, 2);
  ix = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Idx_voiced, ix, (int)sizeof(boolean_T));
  itmp = SPitch->size[0] * SPitch->size[1];
  for (ix = 0; ix < itmp; ix++) {
    Idx_voiced->data[ix] = (SPitch->data[ix] > 0.0);
  }

  emxInit_int32_T(&iindx, 2);
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  itmp = CandsPitch->size[0];
  ix = winix->size[0] * winix->size[1];
  winix->size[0] = itmp;
  winix->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)winix, ix, (int)sizeof(double));
  nm1d2 = iindx->size[1];
  for (ix = 0; ix < nm1d2; ix++) {
    for (cindx = 0; cindx < itmp; cindx++) {
      winix->data[cindx + winix->size[0] * ix] = CandsPitch->data[cindx +
        CandsPitch->size[0] * (iindx->data[iindx->size[0] * ix] - 1)];
    }
  }

  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  itmp = CandsMerit->size[0];
  ix = rowix->size[0] * rowix->size[1];
  rowix->size[0] = itmp;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)rowix, ix, (int)sizeof(double));
  nm1d2 = iindx->size[1];
  for (ix = 0; ix < nm1d2; ix++) {
    for (cindx = 0; cindx < itmp; cindx++) {
      rowix->data[cindx + rowix->size[0] * ix] = CandsMerit->data[cindx +
        CandsMerit->size[0] * (iindx->data[iindx->size[0] * ix] - 1)];
    }
  }

  emxInit_boolean_T(&b_SPitch, 2);
  ix = b_SPitch->size[0] * b_SPitch->size[1];
  b_SPitch->size[0] = 1;
  b_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)b_SPitch, ix, (int)sizeof(boolean_T));
  itmp = SPitch->size[0] * SPitch->size[1];
  for (ix = 0; ix < itmp; ix++) {
    b_SPitch->data[ix] = (SPitch->data[ix] > 0.0);
  }

  Num_VCands = b_sum(b_SPitch);

  /*  Average, STD of the first choice candidates */
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_boolean_T(&b_SPitch);
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(&b_CandsPitch, 2);
  emxInit_int32_T1(&b_iindx, 1);
  itmp = CandsPitch->size[0];
  ix = b_iindx->size[0];
  b_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)b_iindx, ix, (int)sizeof(int));
  nm1d2 = iindx->size[1];
  for (ix = 0; ix < nm1d2; ix++) {
    b_iindx->data[ix] = iindx->data[iindx->size[0] * ix];
  }

  emxInit_real_T(&c_CandsPitch, 2);
  nm1d2 = b_iindx->size[0];
  ix = c_CandsPitch->size[0] * c_CandsPitch->size[1];
  c_CandsPitch->size[0] = itmp;
  c_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)c_CandsPitch, ix, (int)sizeof(double));
  idx = iindx->size[1];
  emxFree_int32_T(&b_iindx);
  for (ix = 0; ix < idx; ix++) {
    for (cindx = 0; cindx < itmp; cindx++) {
      c_CandsPitch->data[cindx + c_CandsPitch->size[0] * ix] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * ix] - 1)];
    }
  }

  ix = b_CandsPitch->size[0] * b_CandsPitch->size[1];
  b_CandsPitch->size[0] = 1;
  b_CandsPitch->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)b_CandsPitch, ix, (int)sizeof(double));
  for (ix = 0; ix < nm1d2; ix++) {
    b_CandsPitch->data[b_CandsPitch->size[0] * ix] = c_CandsPitch->
      data[c_CandsPitch->size[0] * ix];
  }

  emxFree_real_T(&c_CandsPitch);
  avg_voiced = mean(b_CandsPitch);
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&b_CandsPitch);
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(&d_CandsPitch, 2);
  emxInit_int32_T1(&c_iindx, 1);
  itmp = CandsPitch->size[0];
  ix = c_iindx->size[0];
  c_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)c_iindx, ix, (int)sizeof(int));
  nm1d2 = iindx->size[1];
  for (ix = 0; ix < nm1d2; ix++) {
    c_iindx->data[ix] = iindx->data[iindx->size[0] * ix];
  }

  emxInit_real_T(&e_CandsPitch, 2);
  nm1d2 = c_iindx->size[0];
  ix = e_CandsPitch->size[0] * e_CandsPitch->size[1];
  e_CandsPitch->size[0] = itmp;
  e_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)e_CandsPitch, ix, (int)sizeof(double));
  idx = iindx->size[1];
  emxFree_int32_T(&c_iindx);
  for (ix = 0; ix < idx; ix++) {
    for (cindx = 0; cindx < itmp; cindx++) {
      e_CandsPitch->data[cindx + e_CandsPitch->size[0] * ix] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * ix] - 1)];
    }
  }

  ix = d_CandsPitch->size[0] * d_CandsPitch->size[1];
  d_CandsPitch->size[0] = 1;
  d_CandsPitch->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)d_CandsPitch, ix, (int)sizeof(double));
  for (ix = 0; ix < nm1d2; ix++) {
    d_CandsPitch->data[d_CandsPitch->size[0] * ix] = e_CandsPitch->
      data[e_CandsPitch->size[0] * ix];
  }

  emxFree_real_T(&e_CandsPitch);
  std_voiced = b_std(d_CandsPitch);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&d_CandsPitch);
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(&f_CandsPitch, 2);
  itmp = CandsPitch->size[0];
  anew = 0.8 * avg_voiced;
  ix = f_CandsPitch->size[0] * f_CandsPitch->size[1];
  f_CandsPitch->size[0] = itmp;
  f_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)f_CandsPitch, ix, (int)sizeof(double));
  nm1d2 = iindx->size[1];
  for (ix = 0; ix < nm1d2; ix++) {
    for (cindx = 0; cindx < itmp; cindx++) {
      f_CandsPitch->data[cindx + f_CandsPitch->size[0] * ix] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * ix] - 1)]
        - anew;
    }
  }

  emxInit_real_T(&r20, 2);
  c_abs(f_CandsPitch, r20);
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&f_CandsPitch);
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(&delta1, 2);
  ix = delta1->size[0] * delta1->size[1];
  delta1->size[0] = r20->size[0];
  delta1->size[1] = r20->size[1];
  emxEnsureCapacity((emxArray__common *)delta1, ix, (int)sizeof(double));
  itmp = r20->size[1];
  for (ix = 0; ix < itmp; ix++) {
    nm1d2 = r20->size[0];
    for (cindx = 0; cindx < nm1d2; cindx++) {
      delta1->data[cindx + delta1->size[0] * ix] = r20->data[cindx + r20->size[0]
        * ix] * (3.0 - CandsMerit->data[cindx + CandsMerit->size[0] *
                 (iindx->data[iindx->size[0] * ix] - 1)]);
    }
  }

  emxFree_real_T(&r20);

  /*  Interpolation of the weigthed candidates */
  ix = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = delta1->size[1];
  emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
  for (ix = 0; ix < 2; ix++) {
    uv2[ix] = (unsigned int)Signal->size[ix];
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = (int)uv2[1];
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  itmp = (int)uv2[1];
  for (ix = 0; ix < itmp; ix++) {
    iindx->data[ix] = 1;
  }

  n = delta1->size[0];
  for (i = 0; i + 1 <= delta1->size[1]; i++) {
    nm1d2 = i * n;
    ix = i * n + 1;
    idx = nm1d2 + n;
    anew = delta1->data[nm1d2];
    itmp = 1;
    if (n > 1) {
      cindx = 1;
      if (rtIsNaN(delta1->data[nm1d2])) {
        nm1d2 = ix;
        exitg2 = false;
        while ((!exitg2) && (nm1d2 + 1 <= idx)) {
          cindx++;
          ix = nm1d2 + 1;
          if (!rtIsNaN(delta1->data[nm1d2])) {
            anew = delta1->data[nm1d2];
            itmp = cindx;
            exitg2 = true;
          } else {
            nm1d2++;
          }
        }
      }

      if (ix < idx) {
        while (ix + 1 <= idx) {
          cindx++;
          if (delta1->data[ix] < anew) {
            anew = delta1->data[ix];
            itmp = cindx;
          }

          ix++;
        }
      }
    }

    iindx->data[i] = itmp;
  }

  emxFree_real_T(&delta1);
  ix = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
  itmp = iindx->size[0] * iindx->size[1];
  for (ix = 0; ix < itmp; ix++) {
    Signal->data[ix] = iindx->data[ix];
  }

  ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  VPeak_minmrt->size[1] = Signal->size[1];
  emxEnsureCapacity((emxArray__common *)VPeak_minmrt, ix, (int)sizeof(double));
  itmp = Signal->size[1];
  for (ix = 0; ix < itmp; ix++) {
    VPeak_minmrt->data[ix] = 0.0;
  }

  ix = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = Signal->size[1];
  emxEnsureCapacity((emxArray__common *)SHC, ix, (int)sizeof(double));
  itmp = Signal->size[1];
  for (ix = 0; ix < itmp; ix++) {
    SHC->data[ix] = 0.0;
  }

  for (n = 0; n < Signal->size[1]; n++) {
    idx = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= idx; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    ix = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
    nm1d2 = 0;
    for (i = 0; i <= idx; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    VPeak_minmrt->data[n] = CandsPitch->data[((int)Signal->data[n] +
      CandsPitch->size[0] * (iindx->data[iindx->size[0] * n] - 1)) - 1];
    idx = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= idx; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    ix = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
    nm1d2 = 0;
    for (i = 0; i <= idx; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    SHC->data[n] = CandsMerit->data[((int)Signal->data[n] + CandsMerit->size[0] *
      (iindx->data[iindx->size[0] * n] - 1)) - 1];
  }

  emxFree_int32_T(&iindx);
  emxFree_real_T(&CandsMerit);
  emxInit_real_T(&c_VPeak_minmrt, 2);
  ix = c_VPeak_minmrt->size[0] * c_VPeak_minmrt->size[1];
  c_VPeak_minmrt->size[0] = 1;
  c_VPeak_minmrt->size[1] = VPeak_minmrt->size[1];
  emxEnsureCapacity((emxArray__common *)c_VPeak_minmrt, ix, (int)sizeof(double));
  itmp = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  for (ix = 0; ix < itmp; ix++) {
    c_VPeak_minmrt->data[ix] = VPeak_minmrt->data[ix];
  }

  if ((1.0 >= Prm->median_value - 2.0) || rtIsNaN(Prm->median_value - 2.0)) {
    d2 = 1.0;
  } else {
    d2 = Prm->median_value - 2.0;
  }

  Mymedfilt1(c_VPeak_minmrt, d2, VPeak_minmrt);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  n = 0;
  emxFree_real_T(&c_VPeak_minmrt);
  while (n <= Signal->size[1] - 1) {
    winix->data[((int)Signal->data[n] + winix->size[0] * n) - 1] =
      VPeak_minmrt->data[n];

    /*  Assign merit for the smoothed peaks */
    rowix->data[((int)Signal->data[n] + rowix->size[0] * n) - 1] = SHC->data[n];
    n++;
  }

  emxFree_real_T(&SHC);
  emxInit_real_T(&VPitch, 2);

  /*  Use dynamic programming to find best overal path among pitch candidates */
  /*  Dynamic weight for transition costs */
  /*  balance between local and transition costs */
  ix = VPitch->size[0] * VPitch->size[1];
  VPitch->size[0] = 0;
  VPitch->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)VPitch, ix, (int)sizeof(double));
  if (Num_VCands > 2.0) {
    dynamic5(winix, rowix, Prm->dp5_k1 * std_voiced / avg_voiced, VPeak_minmrt);
    ix = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VPeak_minmrt->size[1];
    emxEnsureCapacity((emxArray__common *)VPitch, ix, (int)sizeof(double));
    itmp = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
    for (ix = 0; ix < itmp; ix++) {
      VPitch->data[ix] = VPeak_minmrt->data[ix];
    }

    if (Prm->median_value - 2.0 >= 1.0) {
      b_Prm = Prm->median_value - 2.0;
    } else {
      b_Prm = 1.0;
    }

    b_Mymedfilt1(VPitch, b_Prm, VPeak_minmrt);
    ix = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VPeak_minmrt->size[1];
    emxEnsureCapacity((emxArray__common *)VPitch, ix, (int)sizeof(double));
    itmp = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
    for (ix = 0; ix < itmp; ix++) {
      VPitch->data[ix] = VPeak_minmrt->data[ix];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else if (Num_VCands > 0.0) {
    /*        for i = 1:Num_VCands   % assume at least 1 voiced candidate */
    /*         VPitch (i) = 150;   %   Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates */
    /*        end;  */
    itmp = (int)Num_VCands;
    for (ix = 0; ix < itmp; ix++) {
      tmp_data[ix] = (signed char)ix;
    }

    itmp = (int)Num_VCands;
    for (ix = 0; ix < itmp; ix++) {
      VPitch->data[tmp_data[ix]] = 150.0;
    }

    /*    This should only occur for very short pitch tracks, and even then rarely */
  } else {
    VPitch->data[0] = 150.0;

    /*  to handle when no real voiced candidates */
    Idx_voiced->data[0] = true;
  }

  emxFree_real_T(&rowix);
  emxFree_real_T(&winix);
  emxFree_real_T(&CandsPitch);

  /*  Computing some statistics from the voiced frames */
  b_mean(VPitch, pAvg_data, pAvg_size);
  c_std(VPitch, pStd_data, pStd_size);

  /*  Streching out the smoothed pitch track */
  idx = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < idx; i++) {
    if (Idx_voiced->data[i]) {
      SPitch->data[i] = VPitch->data[nm1d2];
      nm1d2++;
    }
  }

  emxFree_real_T(&VPitch);
  emxFree_boolean_T(&Idx_voiced);
  emxInit_boolean_T1(&c_SPitch, 1);

  /*  Interpolating thru unvoiced frames */
  SPitch_temp_end = SPitch->data[SPitch->size[1] - 1];
  anew = SPitch->data[0];
  ix = c_SPitch->size[0];
  c_SPitch->size[0] = pAvg_size[0];
  emxEnsureCapacity((emxArray__common *)c_SPitch, ix, (int)sizeof(boolean_T));
  itmp = pAvg_size[0];
  for (ix = 0; ix < itmp; ix++) {
    c_SPitch->data[ix] = (anew < pAvg_data[ix] / 2.0);
  }

  if (all(c_SPitch)) {
    SPitch->data[0] = pAvg_data[0];
  }

  emxFree_boolean_T(&c_SPitch);
  emxInit_boolean_T1(&b_SPitch_temp_end, 1);
  ix = b_SPitch_temp_end->size[0];
  b_SPitch_temp_end->size[0] = pAvg_size[0];
  emxEnsureCapacity((emxArray__common *)b_SPitch_temp_end, ix, (int)sizeof
                    (boolean_T));
  itmp = pAvg_size[0];
  for (ix = 0; ix < itmp; ix++) {
    b_SPitch_temp_end->data[ix] = (SPitch_temp_end < pAvg_data[ix] / 2.0);
  }

  if (all(b_SPitch_temp_end)) {
    SPitch->data[SPitch->size[1] - 1] = pAvg_data[0];
  }

  emxFree_boolean_T(&b_SPitch_temp_end);
  emxInit_int32_T(&jj, 2);
  idx = 0;
  ix = jj->size[0] * jj->size[1];
  jj->size[0] = 1;
  jj->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)jj, ix, (int)sizeof(int));
  unnamed_idx_1 = (unsigned int)SPitch->size[1];
  ix = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = (int)unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
  if (SPitch->size[1] == 0) {
    ix = jj->size[0] * jj->size[1];
    jj->size[0] = 1;
    jj->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)jj, ix, (int)sizeof(int));
    ix = Signal->size[0] * Signal->size[1];
    Signal->size[0] = 1;
    Signal->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
  } else {
    nm1d2 = 1;
    exitg1 = false;
    while ((!exitg1) && (nm1d2 <= SPitch->size[1])) {
      guard1 = false;
      if (SPitch->data[SPitch->size[0] * (nm1d2 - 1)] != 0.0) {
        idx++;
        jj->data[idx - 1] = nm1d2;
        Signal->data[idx - 1] = SPitch->data[SPitch->size[0] * (nm1d2 - 1)];
        if (idx >= SPitch->size[1]) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        nm1d2++;
      }
    }

    if (SPitch->size[1] == 1) {
      if (idx == 0) {
        ix = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)jj, ix, (int)sizeof(int));
        ix = Signal->size[0] * Signal->size[1];
        Signal->size[0] = 1;
        Signal->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
      }
    } else {
      ix = jj->size[0] * jj->size[1];
      if (1 > idx) {
        jj->size[1] = 0;
      } else {
        jj->size[1] = idx;
      }

      emxEnsureCapacity((emxArray__common *)jj, ix, (int)sizeof(int));
      ix = Signal->size[0] * Signal->size[1];
      if (1 > idx) {
        Signal->size[1] = 0;
      } else {
        Signal->size[1] = idx;
      }

      emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
    }
  }

  if (numframes < 1.0) {
    n = 0;
    anew = 1.0;
    apnd = 0.0;
  } else if (rtIsInf(numframes)) {
    n = 1;
    anew = rtNaN;
    apnd = numframes;
  } else {
    anew = 1.0;
    ndbl = floor((numframes - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - numframes;
    if (fabs(cdiff) < 4.4408920985006262E-16 * numframes) {
      ndbl++;
      apnd = numframes;
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    n = (int)ndbl;
  }

  ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  VPeak_minmrt->size[1] = n;
  emxEnsureCapacity((emxArray__common *)VPeak_minmrt, ix, (int)sizeof(double));
  if (n > 0) {
    VPeak_minmrt->data[0] = anew;
    if (n > 1) {
      VPeak_minmrt->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (idx = 1; idx < nm1d2; idx++) {
        VPeak_minmrt->data[idx] = anew + (double)idx;
        VPeak_minmrt->data[(n - idx) - 1] = apnd - (double)idx;
      }

      if (nm1d2 << 1 == n - 1) {
        VPeak_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VPeak_minmrt->data[nm1d2] = anew + (double)nm1d2;
        VPeak_minmrt->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T(&b_jj, 2);
  ix = b_jj->size[0] * b_jj->size[1];
  b_jj->size[0] = 1;
  b_jj->size[1] = jj->size[1];
  emxEnsureCapacity((emxArray__common *)b_jj, ix, (int)sizeof(double));
  itmp = jj->size[0] * jj->size[1];
  for (ix = 0; ix < itmp; ix++) {
    b_jj->data[ix] = jj->data[ix];
  }

  emxFree_int32_T(&jj);
  emxInit_real_T(&d_SPitch, 2);
  interp1(b_jj, Signal, VPeak_minmrt, SPitch);
  ix = d_SPitch->size[0] * d_SPitch->size[1];
  d_SPitch->size[0] = 1;
  d_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)d_SPitch, ix, (int)sizeof(double));
  itmp = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&b_jj);
  emxFree_real_T(&VPeak_minmrt);
  emxFree_real_T(&Signal);
  for (ix = 0; ix < itmp; ix++) {
    d_SPitch->data[ix] = SPitch->data[ix];
  }

  b_filter(d_SPitch, SPitch);

  /*   above messes up  first few values of SPitch  ---  simple fix up */
  /*   Note--   this fix up should be based on above filter order */
  SPitch->data[0] = SPitch->data[2];
  SPitch->data[1] = SPitch->data[3];

  /*  Create pitch track with Voiced/Unvoiced decision */
  ix = VUVSPitch->size[0] * VUVSPitch->size[1];
  VUVSPitch->size[0] = 1;
  VUVSPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)VUVSPitch, ix, (int)sizeof(double));
  itmp = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&d_SPitch);
  for (ix = 0; ix < itmp; ix++) {
    VUVSPitch->data[ix] = SPitch->data[ix];
  }

  idx = VUVEnergy->size[1];
  for (i = 0; i < idx; i++) {
    if (!VUVEnergy->data[i]) {
      VUVSPitch->data[i] = 0.0;
    }
  }

  /*  SPitch = SPitch - delta; */
}

/*
 * File trailer for spec_trk.c
 *
 * [EOF]
 */
