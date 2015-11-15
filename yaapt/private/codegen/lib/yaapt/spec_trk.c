/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: spec_trk.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:14:51
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
#include "rdivide.h"
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
 *                emxArray_real_T *SPitch
 *                emxArray_real_T *VUVSPitch
 *                double pAvg_data[]
 *                int pAvg_size[1]
 *                double pStd_data[]
 *                int pStd_size[1]
 * Return Type  : void
 */
void spec_trk(emxArray_real_T *Data, double Fs, const emxArray_boolean_T
              *VUVEnergy, emxArray_real_T *SPitch, emxArray_real_T *VUVSPitch,
              double pAvg_data[], int pAvg_size[1], double pStd_data[], int
              pStd_size[1])
{
  double nframesize;
  double nframejump;
  double numframes;
  double delta;
  double window_length;
  emxArray_real_T *CandsPitch;
  double half_winlen;
  double max_SHC;
  double min_SHC;
  int ix;
  int iy;
  emxArray_real_T *CandsMerit;
  emxArray_real_T *b_Data;
  int nm1d2;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  int cindx;
  double anew;
  double apnd;
  double ndbl;
  double cdiff;
  emxArray_real_T *VMerit_minmrt;
  int k;
  emxArray_real_T *winix;
  emxArray_real_T *rowix;
  int frame;
  emxArray_real_T *Signal;
  emxArray_real_T *Magnit;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  double firstp;
  static creal_T dcv0[8192];
  double dv7[8192];
  double b_k;
  int tmp_size[2];
  double tmp_data[15];
  int b_tmp_size[2];
  double b_tmp_data[15];
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
  emxArray_real_T *r3;
  emxArray_real_T *delta1;
  unsigned int uv1[2];
  int b_ix;
  boolean_T exitg2;
  emxArray_real_T *c_SHC;
  emxArray_real_T *VPitch;
  emxArray_boolean_T *c_SPitch;
  double SPitch_temp_end;
  emxArray_real_T b_pAvg_data;
  emxArray_boolean_T *b_SPitch_temp_end;
  emxArray_real_T c_pAvg_data;
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
  nframesize = 25.0 * Fs / 1000.0;
  b_fix(&nframesize);
  nframejump = 10.0 * Fs / 1000.0;
  b_fix(&nframejump);

  /*  overlap width in sample  */
  numframes = ((double)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /*  use larger frame size */
  nframesize *= 2.0;

  /*  Max number of peak candidates found */
  /*  FFT length */
  /*  Resolution of spectrum */
  delta = Fs / 8192.0;

  /*  Window width in sample */
  window_length = 40.0 / delta;
  b_fix(&window_length);
  if (b_mod(window_length) == 0.0) {
    window_length++;
  }

  emxInit_real_T(&CandsPitch, 2);

  /*  Half window width */
  half_winlen = 40.0 / (delta * 2.0);
  b_fix(&half_winlen);

  /*  Max range of SHC  */
  max_SHC = 500.0 / delta;
  b_fix(&max_SHC);

  /*  Min range of SHC  */
  min_SHC = ceil(60.0 / delta);

  /*  Number of harmomics considered */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  ix = CandsPitch->size[0] * CandsPitch->size[1];
  CandsPitch->size[0] = 4;
  CandsPitch->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)CandsPitch, ix, (int)sizeof(double));
  iy = (int)numframes << 2;
  for (ix = 0; ix < iy; ix++) {
    CandsPitch->data[ix] = 0.0;
  }

  emxInit_real_T(&CandsMerit, 2);
  ix = CandsMerit->size[0] * CandsMerit->size[1];
  CandsMerit->size[0] = 4;
  CandsMerit->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)CandsMerit, ix, (int)sizeof(double));
  iy = (int)numframes << 2;
  for (ix = 0; ix < iy; ix++) {
    CandsMerit->data[ix] = 1.0;
  }

  emxInit_real_T(&b_Data, 2);

  /*  Zero paddinga */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  Data->data[Data->size[1] - 1] = 0.0;
  nm1d2 = Data->size[1];
  nm1d2 = (int)(((numframes - 1.0) * nframejump + nframesize) - (double)nm1d2);
  ix = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1] + nm1d2;
  emxEnsureCapacity((emxArray__common *)b_Data, ix, (int)sizeof(double));
  iy = Data->size[1];
  for (ix = 0; ix < iy; ix++) {
    b_Data->data[b_Data->size[0] * ix] = Data->data[Data->size[0] * ix];
  }

  for (ix = 0; ix < nm1d2; ix++) {
    b_Data->data[b_Data->size[0] * (ix + Data->size[1])] = 0.0;
  }

  ix = Data->size[0] * Data->size[1];
  Data->size[0] = 1;
  Data->size[1] = b_Data->size[1];
  emxEnsureCapacity((emxArray__common *)Data, ix, (int)sizeof(double));
  iy = b_Data->size[1];
  for (ix = 0; ix < iy; ix++) {
    Data->data[Data->size[0] * ix] = b_Data->data[b_Data->size[0] * ix];
  }

  emxFree_real_T(&b_Data);
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
  iy = (int)max_SHC;
  for (ix = 0; ix < iy; ix++) {
    SHC->data[ix] = 0.0;
  }

  if (rtIsNaN(window_length)) {
    cindx = 1;
    anew = rtNaN;
    apnd = window_length;
  } else if (window_length < 1.0) {
    cindx = 0;
    anew = 1.0;
    apnd = window_length;
  } else if (rtIsInf(window_length)) {
    cindx = 1;
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
      cindx = (int)ndbl;
    } else {
      cindx = 0;
    }
  }

  emxInit_real_T(&VMerit_minmrt, 2);
  ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = cindx;
  emxEnsureCapacity((emxArray__common *)VMerit_minmrt, ix, (int)sizeof(double));
  if (cindx > 0) {
    VMerit_minmrt->data[0] = anew;
    if (cindx > 1) {
      VMerit_minmrt->data[cindx - 1] = apnd;
      ix = cindx - 1;
      nm1d2 = ix / 2;
      for (k = 1; k < nm1d2; k++) {
        VMerit_minmrt->data[k] = anew + (double)k;
        VMerit_minmrt->data[(cindx - k) - 1] = apnd - (double)k;
      }

      if (nm1d2 << 1 == cindx - 1) {
        VMerit_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VMerit_minmrt->data[nm1d2] = anew + (double)nm1d2;
        VMerit_minmrt->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T(&winix, 2);
  emxInit_real_T(&rowix, 2);
  repmat(VMerit_minmrt, winix);
  b_repmat(window_length, rowix);
  frame = 0;
  emxInit_real_T(&Signal, 2);
  emxInit_real_T1(&Magnit, 1);
  emxInit_real_T(&b_SHC, 2);
  emxInit_real_T(&b_Magnit, 2);
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
      iy = cindx - ix;
      for (cindx = 0; cindx < iy; cindx++) {
        Signal->data[Signal->size[0] * cindx] = Data->data[ix + cindx] *
          Kaiser_window->data[cindx];
      }

      anew = mean(Signal);
      ix = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
      iy = Signal->size[1];
      for (ix = 0; ix < iy; ix++) {
        Signal->data[Signal->size[0] * ix] -= anew;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      fft(Signal, dcv0);
      b_abs(dcv0, dv7);
      ix = Magnit->size[0];
      Magnit->size[0] = (int)half_winlen + 8192;
      emxEnsureCapacity((emxArray__common *)Magnit, ix, (int)sizeof(double));
      iy = (int)half_winlen;
      for (ix = 0; ix < iy; ix++) {
        Magnit->data[ix] = 0.0;
      }

      for (ix = 0; ix < 8192; ix++) {
        Magnit->data[ix + (int)half_winlen] = dv7[ix];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      ix = (int)(max_SHC + (1.0 - min_SHC));
      for (k = 0; k < ix; k++) {
        b_k = min_SHC + (double)k;
        cindx = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = 4;
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity((emxArray__common *)b_Magnit, cindx, (int)sizeof
                          (double));
        iy = winix->size[0] * winix->size[1];
        for (cindx = 0; cindx < iy; cindx++) {
          b_Magnit->data[cindx] = Magnit->data[(int)(winix->data[cindx] + b_k *
            rowix->data[cindx]) - 1];
        }

        prod(b_Magnit, Signal);
        SHC->data[(int)b_k - 1] = sum(Signal);
      }

      ix = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity((emxArray__common *)b_SHC, ix, (int)sizeof(double));
      iy = SHC->size[0] * SHC->size[1];
      for (ix = 0; ix < iy; ix++) {
        b_SHC->data[ix] = SHC->data[ix];
      }

      peaks(b_SHC, delta, b_tmp_data, b_tmp_size, tmp_data, tmp_size);
      for (ix = 0; ix < 4; ix++) {
        CandsPitch->data[ix + CandsPitch->size[0] * frame] = b_tmp_data[ix];
      }

      for (ix = 0; ix < 4; ix++) {
        CandsMerit->data[ix + CandsMerit->size[0] * frame] = tmp_data[ix];
      }
    } else {
      /*  if energy is low,  let frame be considered as unvoiced */
      for (ix = 0; ix < 4; ix++) {
        CandsPitch->data[ix + CandsPitch->size[0] * frame] = 0.0;
      }

      for (ix = 0; ix < 4; ix++) {
        CandsMerit->data[ix + CandsMerit->size[0] * frame] = 1.0;
      }
    }

    frame++;
  }

  emxFree_real_T(&b_Magnit);
  emxFree_real_T(&b_SHC);
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
  iy = CandsPitch->size[1];
  ix = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = iy;
  emxEnsureCapacity((emxArray__common *)SPitch, ix, (int)sizeof(double));
  for (ix = 0; ix < iy; ix++) {
    SPitch->data[SPitch->size[0] * ix] = CandsPitch->data[CandsPitch->size[0] *
      ix];
  }

  emxInit_boolean_T(&Idx_voiced, 2);
  ix = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Idx_voiced, ix, (int)sizeof(boolean_T));
  iy = SPitch->size[0] * SPitch->size[1];
  for (ix = 0; ix < iy; ix++) {
    Idx_voiced->data[ix] = (SPitch->data[ix] > 0.0);
  }

  emxInit_int32_T(&iindx, 2);
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  ix = winix->size[0] * winix->size[1];
  winix->size[0] = 4;
  winix->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)winix, ix, (int)sizeof(double));
  iy = iindx->size[1];
  for (ix = 0; ix < iy; ix++) {
    for (cindx = 0; cindx < 4; cindx++) {
      winix->data[cindx + winix->size[0] * ix] = CandsPitch->data[cindx +
        CandsPitch->size[0] * (iindx->data[iindx->size[0] * ix] - 1)];
    }
  }

  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  ix = rowix->size[0] * rowix->size[1];
  rowix->size[0] = 4;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)rowix, ix, (int)sizeof(double));
  iy = iindx->size[1];
  for (ix = 0; ix < iy; ix++) {
    for (cindx = 0; cindx < 4; cindx++) {
      rowix->data[cindx + rowix->size[0] * ix] = CandsMerit->data[cindx +
        CandsMerit->size[0] * (iindx->data[iindx->size[0] * ix] - 1)];
    }
  }

  emxInit_boolean_T(&b_SPitch, 2);
  ix = b_SPitch->size[0] * b_SPitch->size[1];
  b_SPitch->size[0] = 1;
  b_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)b_SPitch, ix, (int)sizeof(boolean_T));
  iy = SPitch->size[0] * SPitch->size[1];
  for (ix = 0; ix < iy; ix++) {
    b_SPitch->data[ix] = (SPitch->data[ix] > 0.0);
  }

  Num_VCands = b_sum(b_SPitch);

  /*  Average, STD of the first choice candidates */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_boolean_T(&b_SPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(&b_CandsPitch, 2);
  emxInit_int32_T1(&b_iindx, 1);
  ix = b_iindx->size[0];
  b_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)b_iindx, ix, (int)sizeof(int));
  iy = iindx->size[1];
  for (ix = 0; ix < iy; ix++) {
    b_iindx->data[ix] = iindx->data[iindx->size[0] * ix];
  }

  emxInit_real_T(&c_CandsPitch, 2);
  iy = b_iindx->size[0];
  ix = c_CandsPitch->size[0] * c_CandsPitch->size[1];
  c_CandsPitch->size[0] = 4;
  c_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)c_CandsPitch, ix, (int)sizeof(double));
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&b_iindx);
  for (ix = 0; ix < nm1d2; ix++) {
    for (cindx = 0; cindx < 4; cindx++) {
      c_CandsPitch->data[cindx + c_CandsPitch->size[0] * ix] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * ix] - 1)];
    }
  }

  ix = b_CandsPitch->size[0] * b_CandsPitch->size[1];
  b_CandsPitch->size[0] = 1;
  b_CandsPitch->size[1] = iy;
  emxEnsureCapacity((emxArray__common *)b_CandsPitch, ix, (int)sizeof(double));
  for (ix = 0; ix < iy; ix++) {
    b_CandsPitch->data[b_CandsPitch->size[0] * ix] = c_CandsPitch->
      data[c_CandsPitch->size[0] * ix];
  }

  emxFree_real_T(&c_CandsPitch);
  avg_voiced = mean(b_CandsPitch);
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&b_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(&d_CandsPitch, 2);
  emxInit_int32_T1(&c_iindx, 1);
  ix = c_iindx->size[0];
  c_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)c_iindx, ix, (int)sizeof(int));
  iy = iindx->size[1];
  for (ix = 0; ix < iy; ix++) {
    c_iindx->data[ix] = iindx->data[iindx->size[0] * ix];
  }

  emxInit_real_T(&e_CandsPitch, 2);
  iy = c_iindx->size[0];
  ix = e_CandsPitch->size[0] * e_CandsPitch->size[1];
  e_CandsPitch->size[0] = 4;
  e_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)e_CandsPitch, ix, (int)sizeof(double));
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&c_iindx);
  for (ix = 0; ix < nm1d2; ix++) {
    for (cindx = 0; cindx < 4; cindx++) {
      e_CandsPitch->data[cindx + e_CandsPitch->size[0] * ix] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * ix] - 1)];
    }
  }

  ix = d_CandsPitch->size[0] * d_CandsPitch->size[1];
  d_CandsPitch->size[0] = 1;
  d_CandsPitch->size[1] = iy;
  emxEnsureCapacity((emxArray__common *)d_CandsPitch, ix, (int)sizeof(double));
  for (ix = 0; ix < iy; ix++) {
    d_CandsPitch->data[d_CandsPitch->size[0] * ix] = e_CandsPitch->
      data[e_CandsPitch->size[0] * ix];
  }

  emxFree_real_T(&e_CandsPitch);
  std_voiced = b_std(d_CandsPitch);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&d_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(&f_CandsPitch, 2);
  anew = 0.8 * avg_voiced;
  ix = f_CandsPitch->size[0] * f_CandsPitch->size[1];
  f_CandsPitch->size[0] = 4;
  f_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)f_CandsPitch, ix, (int)sizeof(double));
  iy = iindx->size[1];
  for (ix = 0; ix < iy; ix++) {
    for (cindx = 0; cindx < 4; cindx++) {
      f_CandsPitch->data[cindx + f_CandsPitch->size[0] * ix] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * ix] - 1)]
        - anew;
    }
  }

  emxInit_real_T(&r3, 2);
  c_abs(f_CandsPitch, r3);
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&f_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(&delta1, 2);
  ix = delta1->size[0] * delta1->size[1];
  delta1->size[0] = 4;
  delta1->size[1] = r3->size[1];
  emxEnsureCapacity((emxArray__common *)delta1, ix, (int)sizeof(double));
  iy = r3->size[1];
  for (ix = 0; ix < iy; ix++) {
    for (cindx = 0; cindx < 4; cindx++) {
      delta1->data[cindx + delta1->size[0] * ix] = r3->data[cindx + r3->size[0] *
        ix] * (3.0 - CandsMerit->data[cindx + CandsMerit->size[0] * (iindx->
                data[iindx->size[0] * ix] - 1)]);
    }
  }

  emxFree_real_T(&r3);

  /*  Interpolation of the weigthed candidates */
  ix = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = delta1->size[1];
  emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
  for (ix = 0; ix < 2; ix++) {
    uv1[ix] = (unsigned int)Signal->size[ix];
  }

  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = (int)uv1[1];
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  iy = (int)uv1[1];
  for (ix = 0; ix < iy; ix++) {
    iindx->data[ix] = 1;
  }

  nm1d2 = 4;
  iy = -1;
  for (i = 1; i <= delta1->size[1]; i++) {
    b_ix = nm1d2 - 3;
    anew = delta1->data[nm1d2 - 4];
    k = 1;
    cindx = 1;
    if (rtIsNaN(delta1->data[nm1d2 - 4])) {
      ix = nm1d2 - 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= nm1d2)) {
        cindx++;
        b_ix = ix;
        if (!rtIsNaN(delta1->data[ix - 1])) {
          anew = delta1->data[ix - 1];
          k = cindx;
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (b_ix < nm1d2) {
      while (b_ix + 1 <= nm1d2) {
        cindx++;
        if (delta1->data[b_ix] < anew) {
          anew = delta1->data[b_ix];
          k = cindx;
        }

        b_ix++;
      }
    }

    iy++;
    iindx->data[iy] = k;
    nm1d2 += 4;
  }

  emxFree_real_T(&delta1);
  ix = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
  iy = iindx->size[0] * iindx->size[1];
  for (ix = 0; ix < iy; ix++) {
    Signal->data[ix] = iindx->data[ix];
  }

  ix = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = Signal->size[1];
  emxEnsureCapacity((emxArray__common *)SHC, ix, (int)sizeof(double));
  iy = Signal->size[1];
  for (ix = 0; ix < iy; ix++) {
    SHC->data[ix] = 0.0;
  }

  ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = Signal->size[1];
  emxEnsureCapacity((emxArray__common *)VMerit_minmrt, ix, (int)sizeof(double));
  iy = Signal->size[1];
  for (ix = 0; ix < iy; ix++) {
    VMerit_minmrt->data[ix] = 0.0;
  }

  for (cindx = 0; cindx < Signal->size[1]; cindx++) {
    iy = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    ix = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    SHC->data[cindx] = CandsPitch->data[((int)Signal->data[cindx] +
      CandsPitch->size[0] * (iindx->data[iindx->size[0] * cindx] - 1)) - 1];
    iy = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    ix = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    VMerit_minmrt->data[cindx] = CandsMerit->data[((int)Signal->data[cindx] +
      CandsMerit->size[0] * (iindx->data[iindx->size[0] * cindx] - 1)) - 1];
  }

  emxFree_int32_T(&iindx);
  emxFree_real_T(&CandsMerit);
  emxInit_real_T(&c_SHC, 2);
  ix = c_SHC->size[0] * c_SHC->size[1];
  c_SHC->size[0] = 1;
  c_SHC->size[1] = SHC->size[1];
  emxEnsureCapacity((emxArray__common *)c_SHC, ix, (int)sizeof(double));
  iy = SHC->size[0] * SHC->size[1];
  for (ix = 0; ix < iy; ix++) {
    c_SHC->data[ix] = SHC->data[ix];
  }

  Mymedfilt1(c_SHC, SHC);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  cindx = 0;
  emxFree_real_T(&c_SHC);
  while (cindx <= Signal->size[1] - 1) {
    winix->data[((int)Signal->data[cindx] + winix->size[0] * cindx) - 1] =
      SHC->data[cindx];

    /*  Assign merit for the smoothed peaks */
    rowix->data[((int)Signal->data[cindx] + rowix->size[0] * cindx) - 1] =
      VMerit_minmrt->data[cindx];
    cindx++;
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
    dynamic5(winix, rowix, 11.0 * std_voiced / avg_voiced, Signal);
    ix = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = Signal->size[1];
    emxEnsureCapacity((emxArray__common *)VPitch, ix, (int)sizeof(double));
    iy = Signal->size[0] * Signal->size[1];
    for (ix = 0; ix < iy; ix++) {
      VPitch->data[ix] = Signal->data[ix];
    }

    b_Mymedfilt1(VPitch, Signal);
    ix = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = Signal->size[1];
    emxEnsureCapacity((emxArray__common *)VPitch, ix, (int)sizeof(double));
    iy = Signal->size[0] * Signal->size[1];
    for (ix = 0; ix < iy; ix++) {
      VPitch->data[ix] = Signal->data[ix];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else if (Num_VCands > 0.0) {
    /*        for i = 1:Num_VCands   % assume at least 1 voiced candidate */
    /*         VPitch (i) = 150;   %   Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates */
    /*        end;  */
    VPitch->data[0] = 150.0;

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
  iy = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < iy; i++) {
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
  b_pAvg_data.data = (double *)pAvg_data;
  b_pAvg_data.size = (int *)pAvg_size;
  b_pAvg_data.allocatedSize = -1;
  b_pAvg_data.numDimensions = 1;
  b_pAvg_data.canFreeData = false;
  c_rdivide(&b_pAvg_data, 2.0, Magnit);
  anew = SPitch->data[0];
  ix = c_SPitch->size[0];
  c_SPitch->size[0] = Magnit->size[0];
  emxEnsureCapacity((emxArray__common *)c_SPitch, ix, (int)sizeof(boolean_T));
  iy = Magnit->size[0];
  for (ix = 0; ix < iy; ix++) {
    c_SPitch->data[ix] = (anew < Magnit->data[ix]);
  }

  if (all(c_SPitch)) {
    SPitch->data[0] = pAvg_data[0];
  }

  emxFree_boolean_T(&c_SPitch);
  emxInit_boolean_T1(&b_SPitch_temp_end, 1);
  c_pAvg_data.data = (double *)pAvg_data;
  c_pAvg_data.size = (int *)pAvg_size;
  c_pAvg_data.allocatedSize = -1;
  c_pAvg_data.numDimensions = 1;
  c_pAvg_data.canFreeData = false;
  c_rdivide(&c_pAvg_data, 2.0, Magnit);
  ix = b_SPitch_temp_end->size[0];
  b_SPitch_temp_end->size[0] = Magnit->size[0];
  emxEnsureCapacity((emxArray__common *)b_SPitch_temp_end, ix, (int)sizeof
                    (boolean_T));
  iy = Magnit->size[0];
  for (ix = 0; ix < iy; ix++) {
    b_SPitch_temp_end->data[ix] = (SPitch_temp_end < Magnit->data[ix]);
  }

  emxFree_real_T(&Magnit);
  if (all(b_SPitch_temp_end)) {
    SPitch->data[SPitch->size[1] - 1] = pAvg_data[0];
  }

  emxFree_boolean_T(&b_SPitch_temp_end);
  emxInit_int32_T(&jj, 2);
  iy = 0;
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
        iy++;
        jj->data[iy - 1] = nm1d2;
        Signal->data[iy - 1] = SPitch->data[SPitch->size[0] * (nm1d2 - 1)];
        if (iy >= SPitch->size[1]) {
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
      if (iy == 0) {
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
      if (1 > iy) {
        jj->size[1] = 0;
      } else {
        jj->size[1] = iy;
      }

      emxEnsureCapacity((emxArray__common *)jj, ix, (int)sizeof(int));
      ix = Signal->size[0] * Signal->size[1];
      if (1 > iy) {
        Signal->size[1] = 0;
      } else {
        Signal->size[1] = iy;
      }

      emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
    }
  }

  if (numframes < 1.0) {
    cindx = 0;
    anew = 1.0;
    apnd = 0.0;
  } else if (rtIsInf(numframes)) {
    cindx = 1;
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

    cindx = (int)ndbl;
  }

  ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = cindx;
  emxEnsureCapacity((emxArray__common *)VMerit_minmrt, ix, (int)sizeof(double));
  if (cindx > 0) {
    VMerit_minmrt->data[0] = anew;
    if (cindx > 1) {
      VMerit_minmrt->data[cindx - 1] = apnd;
      ix = cindx - 1;
      nm1d2 = ix / 2;
      for (k = 1; k < nm1d2; k++) {
        VMerit_minmrt->data[k] = anew + (double)k;
        VMerit_minmrt->data[(cindx - k) - 1] = apnd - (double)k;
      }

      if (nm1d2 << 1 == cindx - 1) {
        VMerit_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VMerit_minmrt->data[nm1d2] = anew + (double)nm1d2;
        VMerit_minmrt->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T(&b_jj, 2);
  ix = b_jj->size[0] * b_jj->size[1];
  b_jj->size[0] = 1;
  b_jj->size[1] = jj->size[1];
  emxEnsureCapacity((emxArray__common *)b_jj, ix, (int)sizeof(double));
  iy = jj->size[0] * jj->size[1];
  for (ix = 0; ix < iy; ix++) {
    b_jj->data[ix] = jj->data[ix];
  }

  emxFree_int32_T(&jj);
  emxInit_real_T(&d_SPitch, 2);
  interp1(b_jj, Signal, VMerit_minmrt, SPitch);
  ix = d_SPitch->size[0] * d_SPitch->size[1];
  d_SPitch->size[0] = 1;
  d_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)d_SPitch, ix, (int)sizeof(double));
  iy = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&b_jj);
  emxFree_real_T(&VMerit_minmrt);
  emxFree_real_T(&Signal);
  for (ix = 0; ix < iy; ix++) {
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
  iy = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&d_SPitch);
  for (ix = 0; ix < iy; ix++) {
    VUVSPitch->data[ix] = SPitch->data[ix];
  }

  iy = VUVEnergy->size[1];
  for (i = 0; i < iy; i++) {
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
