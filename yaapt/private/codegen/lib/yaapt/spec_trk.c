/*
 * File: spec_trk.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
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
#include "dynamic.h"
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
  int itmp;
  int loop_ub;
  emxArray_real_T *CandsMerit;
  emxArray_real_T *b_Data;
  int ix;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  double Num_VCands;
  double apnd;
  double ndbl;
  double cdiff;
  emxArray_real_T *Signal;
  int nm1d2;
  int cindx;
  emxArray_real_T *winix;
  emxArray_real_T *rowix;
  emxArray_real_T *Magnit;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  int i;
  static creal_T dcv0[8192];
  double dv6[8192];
  int tmp_size[2];
  double tmp_data[15];
  int b_tmp_size[2];
  double b_tmp_data[15];
  emxArray_boolean_T *Idx_voiced;
  emxArray_int32_T *iindx;
  emxArray_real_T *VCandsMerit;
  emxArray_real_T *b_rowix;
  emxArray_real_T *c_rowix;
  emxArray_real_T *d_rowix;
  unsigned int outsz[2];
  unsigned int b_outsz;
  int b_ix;
  boolean_T exitg2;
  emxArray_real_T *VMerit_minmrt;
  emxArray_real_T *c_SHC;
  emxArray_real_T *VPitch;
  emxArray_boolean_T *b_SPitch;
  emxArray_real_T b_pAvg_data;
  emxArray_boolean_T *SPitch_temp_end;
  emxArray_real_T c_pAvg_data;
  emxArray_int32_T *jj;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_int32_T *b_jj;
  emxArray_real_T *d_SHC;
  emxArray_real_T *c_jj;
  double dbuffer[3];
  emxArray_boolean_T *b_VUVEnergy;

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
  itmp = CandsPitch->size[0] * CandsPitch->size[1];
  CandsPitch->size[0] = 4;
  CandsPitch->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)CandsPitch, itmp, (int)sizeof(double));
  loop_ub = (int)numframes << 2;
  for (itmp = 0; itmp < loop_ub; itmp++) {
    CandsPitch->data[itmp] = 0.0;
  }

  emxInit_real_T(&CandsMerit, 2);
  itmp = CandsMerit->size[0] * CandsMerit->size[1];
  CandsMerit->size[0] = 4;
  CandsMerit->size[1] = (int)numframes;
  emxEnsureCapacity((emxArray__common *)CandsMerit, itmp, (int)sizeof(double));
  loop_ub = (int)numframes << 2;
  for (itmp = 0; itmp < loop_ub; itmp++) {
    CandsMerit->data[itmp] = 1.0;
  }

  emxInit_real_T(&b_Data, 2);

  /*  Zero paddinga */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  Data->data[Data->size[1] - 1] = 0.0;
  ix = Data->size[1];
  ix = (int)(((numframes - 1.0) * nframejump + nframesize) - (double)ix);
  itmp = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1] + ix;
  emxEnsureCapacity((emxArray__common *)b_Data, itmp, (int)sizeof(double));
  loop_ub = Data->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    b_Data->data[b_Data->size[0] * itmp] = Data->data[Data->size[0] * itmp];
  }

  for (itmp = 0; itmp < ix; itmp++) {
    b_Data->data[b_Data->size[0] * (itmp + Data->size[1])] = 0.0;
  }

  itmp = Data->size[0] * Data->size[1];
  Data->size[0] = 1;
  Data->size[1] = b_Data->size[1];
  emxEnsureCapacity((emxArray__common *)Data, itmp, (int)sizeof(double));
  loop_ub = b_Data->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    Data->data[Data->size[0] * itmp] = b_Data->data[b_Data->size[0] * itmp];
  }

  emxFree_real_T(&b_Data);
  emxInit_real_T(&Kaiser_window, 2);
  emxInit_real_T(&SHC, 2);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Compute SHC for voiced frame */
  Mykaiser(nframesize, Kaiser_window);

  /*  Kaiser_window_test = kaiser(nframesize); */
  itmp = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = (int)max_SHC;
  emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
  loop_ub = (int)max_SHC;
  for (itmp = 0; itmp < loop_ub; itmp++) {
    SHC->data[itmp] = 0.0;
  }

  if (rtIsNaN(window_length)) {
    ix = 0;
    Num_VCands = rtNaN;
    apnd = window_length;
  } else if (window_length < 1.0) {
    ix = -1;
    Num_VCands = 1.0;
    apnd = window_length;
  } else if (rtIsInf(window_length)) {
    ix = 0;
    Num_VCands = rtNaN;
    apnd = window_length;
  } else {
    Num_VCands = 1.0;
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
      ix = (int)ndbl - 1;
    } else {
      ix = -1;
    }
  }

  emxInit_real_T(&Signal, 2);
  itmp = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = ix + 1;
  emxEnsureCapacity((emxArray__common *)Signal, itmp, (int)sizeof(double));
  if (ix + 1 > 0) {
    Signal->data[0] = Num_VCands;
    if (ix + 1 > 1) {
      Signal->data[ix] = apnd;
      nm1d2 = ix / 2;
      for (cindx = 1; cindx < nm1d2; cindx++) {
        Signal->data[cindx] = Num_VCands + (double)cindx;
        Signal->data[ix - cindx] = apnd - (double)cindx;
      }

      if (nm1d2 << 1 == ix) {
        Signal->data[nm1d2] = (Num_VCands + apnd) / 2.0;
      } else {
        Signal->data[nm1d2] = Num_VCands + (double)nm1d2;
        Signal->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T(&winix, 2);
  emxInit_real_T(&rowix, 2);
  repmat(Signal, winix);
  b_repmat(window_length, rowix);
  nm1d2 = 0;
  b_emxInit_real_T(&Magnit, 1);
  emxInit_real_T(&b_SHC, 2);
  emxInit_real_T(&b_Magnit, 2);
  while (nm1d2 <= (int)numframes - 1) {
    if ((int)VUVEnergy->data[nm1d2] > 0) {
      window_length = 1.0 + ((1.0 + (double)nm1d2) - 1.0) * nframejump;
      cdiff = (window_length + nframesize) - 1.0;
      if (window_length > cdiff) {
        itmp = 0;
        i = 0;
      } else {
        itmp = (int)window_length - 1;
        i = (int)cdiff;
      }

      ix = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      Signal->size[1] = i - itmp;
      emxEnsureCapacity((emxArray__common *)Signal, ix, (int)sizeof(double));
      loop_ub = i - itmp;
      for (i = 0; i < loop_ub; i++) {
        Signal->data[Signal->size[0] * i] = Data->data[itmp + i] *
          Kaiser_window->data[i];
      }

      cdiff = mean(Signal);
      itmp = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      emxEnsureCapacity((emxArray__common *)Signal, itmp, (int)sizeof(double));
      loop_ub = Signal->size[1];
      for (itmp = 0; itmp < loop_ub; itmp++) {
        Signal->data[Signal->size[0] * itmp] -= cdiff;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      fft(Signal, dcv0);
      b_abs(dcv0, dv6);
      itmp = Magnit->size[0];
      Magnit->size[0] = (int)half_winlen + 8192;
      emxEnsureCapacity((emxArray__common *)Magnit, itmp, (int)sizeof(double));
      loop_ub = (int)half_winlen;
      for (itmp = 0; itmp < loop_ub; itmp++) {
        Magnit->data[itmp] = 0.0;
      }

      for (itmp = 0; itmp < 8192; itmp++) {
        Magnit->data[itmp + (int)half_winlen] = dv6[itmp];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      itmp = (int)(max_SHC + (1.0 - min_SHC));
      for (cindx = 0; cindx < itmp; cindx++) {
        window_length = min_SHC + (double)cindx;
        i = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = 4;
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity((emxArray__common *)b_Magnit, i, (int)sizeof(double));
        loop_ub = winix->size[0] * winix->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_Magnit->data[i] = Magnit->data[(int)(winix->data[i] + window_length *
            rowix->data[i]) - 1];
        }

        prod(b_Magnit, Signal);
        SHC->data[(int)window_length - 1] = sum(Signal);
      }

      itmp = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity((emxArray__common *)b_SHC, itmp, (int)sizeof(double));
      loop_ub = SHC->size[0] * SHC->size[1];
      for (itmp = 0; itmp < loop_ub; itmp++) {
        b_SHC->data[itmp] = SHC->data[itmp];
      }

      peaks(b_SHC, delta, b_tmp_data, b_tmp_size, tmp_data, tmp_size);
      for (itmp = 0; itmp < 4; itmp++) {
        CandsPitch->data[itmp + CandsPitch->size[0] * nm1d2] = b_tmp_data[itmp];
      }

      for (itmp = 0; itmp < 4; itmp++) {
        CandsMerit->data[itmp + CandsMerit->size[0] * nm1d2] = tmp_data[itmp];
      }
    } else {
      /*  if energy is low,  let frame be considered as unvoiced */
      for (itmp = 0; itmp < 4; itmp++) {
        CandsPitch->data[itmp + CandsPitch->size[0] * nm1d2] = 0.0;
      }

      for (itmp = 0; itmp < 4; itmp++) {
        CandsMerit->data[itmp + CandsMerit->size[0] * nm1d2] = 1.0;
      }
    }

    nm1d2++;
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
  loop_ub = CandsPitch->size[1];
  itmp = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)SPitch, itmp, (int)sizeof(double));
  for (itmp = 0; itmp < loop_ub; itmp++) {
    SPitch->data[SPitch->size[0] * itmp] = CandsPitch->data[CandsPitch->size[0] *
      itmp];
  }

  emxInit_boolean_T(&Idx_voiced, 2);
  itmp = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Idx_voiced, itmp, (int)sizeof(boolean_T));
  loop_ub = SPitch->size[0] * SPitch->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    Idx_voiced->data[itmp] = (SPitch->data[itmp] > 0.0);
  }

  emxInit_int32_T(&iindx, 2);
  eml_li_find(Idx_voiced, iindx);
  itmp = rowix->size[0] * rowix->size[1];
  rowix->size[0] = 4;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)rowix, itmp, (int)sizeof(double));
  loop_ub = iindx->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    for (i = 0; i < 4; i++) {
      rowix->data[i + rowix->size[0] * itmp] = CandsPitch->data[i +
        CandsPitch->size[0] * (iindx->data[iindx->size[0] * itmp] - 1)];
    }
  }

  emxInit_real_T(&VCandsMerit, 2);
  eml_li_find(Idx_voiced, iindx);
  itmp = VCandsMerit->size[0] * VCandsMerit->size[1];
  VCandsMerit->size[0] = 4;
  VCandsMerit->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)VCandsMerit, itmp, (int)sizeof(double));
  loop_ub = iindx->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    for (i = 0; i < 4; i++) {
      VCandsMerit->data[i + VCandsMerit->size[0] * itmp] = CandsMerit->data[i +
        CandsMerit->size[0] * (iindx->data[iindx->size[0] * itmp] - 1)];
    }
  }

  emxFree_real_T(&CandsMerit);
  emxInit_real_T(&b_rowix, 2);
  Num_VCands = b_sum(Idx_voiced);

  /*  Average, STD of the first choice candidates */
  loop_ub = rowix->size[1];
  itmp = b_rowix->size[0] * b_rowix->size[1];
  b_rowix->size[0] = 1;
  b_rowix->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_rowix, itmp, (int)sizeof(double));
  for (itmp = 0; itmp < loop_ub; itmp++) {
    b_rowix->data[b_rowix->size[0] * itmp] = rowix->data[rowix->size[0] * itmp];
  }

  emxInit_real_T(&c_rowix, 2);
  ndbl = mean(b_rowix);
  loop_ub = rowix->size[1];
  itmp = c_rowix->size[0] * c_rowix->size[1];
  c_rowix->size[0] = 1;
  c_rowix->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)c_rowix, itmp, (int)sizeof(double));
  emxFree_real_T(&b_rowix);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    c_rowix->data[c_rowix->size[0] * itmp] = rowix->data[rowix->size[0] * itmp];
  }

  emxInit_real_T(&d_rowix, 2);
  apnd = b_std(c_rowix);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  itmp = d_rowix->size[0] * d_rowix->size[1];
  d_rowix->size[0] = 4;
  d_rowix->size[1] = rowix->size[1];
  emxEnsureCapacity((emxArray__common *)d_rowix, itmp, (int)sizeof(double));
  cdiff = 0.8 * ndbl;
  loop_ub = rowix->size[0] * rowix->size[1];
  emxFree_real_T(&c_rowix);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    d_rowix->data[itmp] = rowix->data[itmp] - cdiff;
  }

  c_abs(d_rowix, winix);
  itmp = winix->size[0] * winix->size[1];
  winix->size[0] = 4;
  emxEnsureCapacity((emxArray__common *)winix, itmp, (int)sizeof(double));
  ix = winix->size[0];
  nm1d2 = winix->size[1];
  loop_ub = ix * nm1d2;
  emxFree_real_T(&d_rowix);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    winix->data[itmp] *= 3.0 - VCandsMerit->data[itmp];
  }

  /*  Interpolation of the weigthed candidates */
  for (itmp = 0; itmp < 2; itmp++) {
    outsz[itmp] = (unsigned int)winix->size[itmp];
  }

  b_outsz = outsz[1];
  outsz[1] = outsz[1];
  itmp = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)iindx, itmp, (int)sizeof(int));
  itmp = iindx->size[0] * iindx->size[1];
  iindx->size[1] = (int)outsz[1];
  emxEnsureCapacity((emxArray__common *)iindx, itmp, (int)sizeof(int));
  loop_ub = (int)b_outsz;
  for (itmp = 0; itmp < loop_ub; itmp++) {
    iindx->data[itmp] = 1;
  }

  ix = 4;
  nm1d2 = -1;
  for (i = 1; i <= winix->size[1]; i++) {
    loop_ub = ix - 3;
    window_length = winix->data[ix - 4];
    itmp = 1;
    cindx = 1;
    if (rtIsNaN(winix->data[ix - 4])) {
      b_ix = ix - 2;
      exitg2 = false;
      while ((!exitg2) && (b_ix <= ix)) {
        cindx++;
        loop_ub = b_ix;
        if (!rtIsNaN(winix->data[b_ix - 1])) {
          window_length = winix->data[b_ix - 1];
          itmp = cindx;
          exitg2 = true;
        } else {
          b_ix++;
        }
      }
    }

    if (loop_ub < ix) {
      while (loop_ub + 1 <= ix) {
        cindx++;
        if (winix->data[loop_ub] < window_length) {
          window_length = winix->data[loop_ub];
          itmp = cindx;
        }

        loop_ub++;
      }
    }

    nm1d2++;
    iindx->data[nm1d2] = itmp;
    ix += 4;
  }

  emxFree_real_T(&winix);
  itmp = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)Signal, itmp, (int)sizeof(double));
  loop_ub = iindx->size[0] * iindx->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    Signal->data[itmp] = iindx->data[itmp];
  }

  itmp = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
  ix = Signal->size[1];
  itmp = SHC->size[0] * SHC->size[1];
  SHC->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
  loop_ub = Signal->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    SHC->data[itmp] = 0.0;
  }

  emxInit_real_T(&VMerit_minmrt, 2);
  itmp = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)VMerit_minmrt, itmp, (int)sizeof(double));
  ix = Signal->size[1];
  itmp = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)VMerit_minmrt, itmp, (int)sizeof(double));
  loop_ub = Signal->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    VMerit_minmrt->data[itmp] = 0.0;
  }

  for (ix = 0; ix < Signal->size[1]; ix++) {
    SHC->data[ix] = rowix->data[((int)Signal->data[ix] + rowix->size[0] * ix) -
      1];
    VMerit_minmrt->data[ix] = VCandsMerit->data[((int)Signal->data[ix] +
      VCandsMerit->size[0] * ix) - 1];
  }

  emxInit_real_T(&c_SHC, 2);
  itmp = c_SHC->size[0] * c_SHC->size[1];
  c_SHC->size[0] = 1;
  c_SHC->size[1] = SHC->size[1];
  emxEnsureCapacity((emxArray__common *)c_SHC, itmp, (int)sizeof(double));
  loop_ub = SHC->size[0] * SHC->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    c_SHC->data[itmp] = SHC->data[itmp];
  }

  Mymedfilt1(c_SHC, SHC);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  ix = 0;
  emxFree_real_T(&c_SHC);
  while (ix <= Signal->size[1] - 1) {
    rowix->data[((int)Signal->data[ix] + rowix->size[0] * ix) - 1] = SHC->
      data[ix];

    /*  Assign merit for the smoothed peaks */
    VCandsMerit->data[((int)Signal->data[ix] + VCandsMerit->size[0] * ix) - 1] =
      VMerit_minmrt->data[ix];
    ix++;
  }

  emxFree_real_T(&VMerit_minmrt);
  emxInit_real_T(&VPitch, 2);

  /*  Use dynamic programming to find best overal path among pitch candidates */
  /*  Dynamic weight for transition costs */
  /*  balance between local and transition costs */
  itmp = VPitch->size[0] * VPitch->size[1];
  VPitch->size[0] = 0;
  VPitch->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)VPitch, itmp, (int)sizeof(double));
  if (Num_VCands > 2.0) {
    dynamic5(rowix, VCandsMerit, 11.0 * apnd / ndbl, Signal);
    itmp = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = Signal->size[1];
    emxEnsureCapacity((emxArray__common *)VPitch, itmp, (int)sizeof(double));
    loop_ub = Signal->size[0] * Signal->size[1];
    for (itmp = 0; itmp < loop_ub; itmp++) {
      VPitch->data[itmp] = Signal->data[itmp];
    }

    b_Mymedfilt1(VPitch, Signal);
    itmp = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = Signal->size[1];
    emxEnsureCapacity((emxArray__common *)VPitch, itmp, (int)sizeof(double));
    loop_ub = Signal->size[0] * Signal->size[1];
    for (itmp = 0; itmp < loop_ub; itmp++) {
      VPitch->data[itmp] = Signal->data[itmp];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else if (Num_VCands > 0.0) {
    for (i = 0; i < (int)Num_VCands; i++) {
      /*  assume at least 1 voiced candidate */
      VPitch->data[0] = 150.0;

      /*    Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates */
    }

    /*    This should only occur for very short pitch tracks, and even then rarely */
  } else {
    VPitch->data[0] = 150.0;

    /*  to handle when no real voiced candidates */
    Idx_voiced->data[0] = true;
  }

  emxFree_real_T(&VCandsMerit);
  emxFree_real_T(&rowix);

  /*  Computing some statistics from the voiced frames */
  b_mean(VPitch, pAvg_data, pAvg_size);
  c_std(VPitch, pStd_data, pStd_size);

  /*  Streching out the smoothed pitch track */
  eml_li_find(Idx_voiced, iindx);
  loop_ub = iindx->size[0] * iindx->size[1];
  emxFree_boolean_T(&Idx_voiced);
  emxFree_real_T(&CandsPitch);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    SPitch->data[iindx->data[itmp] - 1] = VPitch->data[itmp];
  }

  emxFree_real_T(&VPitch);
  b_emxInit_boolean_T(&b_SPitch, 1);

  /*  Interpolating thru unvoiced frames */
  window_length = SPitch->data[SPitch->size[1] - 1];
  b_pAvg_data.data = (double *)pAvg_data;
  b_pAvg_data.size = (int *)pAvg_size;
  b_pAvg_data.allocatedSize = -1;
  b_pAvg_data.numDimensions = 1;
  b_pAvg_data.canFreeData = false;
  c_rdivide(&b_pAvg_data, 2.0, Magnit);
  Num_VCands = SPitch->data[0];
  itmp = b_SPitch->size[0];
  b_SPitch->size[0] = Magnit->size[0];
  emxEnsureCapacity((emxArray__common *)b_SPitch, itmp, (int)sizeof(boolean_T));
  loop_ub = Magnit->size[0];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    b_SPitch->data[itmp] = (Num_VCands < Magnit->data[itmp]);
  }

  if (all(b_SPitch)) {
    SPitch->data[0] = pAvg_data[0];
  }

  emxFree_boolean_T(&b_SPitch);
  b_emxInit_boolean_T(&SPitch_temp_end, 1);
  c_pAvg_data.data = (double *)pAvg_data;
  c_pAvg_data.size = (int *)pAvg_size;
  c_pAvg_data.allocatedSize = -1;
  c_pAvg_data.numDimensions = 1;
  c_pAvg_data.canFreeData = false;
  c_rdivide(&c_pAvg_data, 2.0, Magnit);
  itmp = SPitch_temp_end->size[0];
  SPitch_temp_end->size[0] = Magnit->size[0];
  emxEnsureCapacity((emxArray__common *)SPitch_temp_end, itmp, (int)sizeof
                    (boolean_T));
  loop_ub = Magnit->size[0];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    SPitch_temp_end->data[itmp] = (window_length < Magnit->data[itmp]);
  }

  emxFree_real_T(&Magnit);
  if (all(SPitch_temp_end)) {
    SPitch->data[SPitch->size[1] - 1] = pAvg_data[0];
  }

  emxFree_boolean_T(&SPitch_temp_end);
  emxInit_int32_T(&jj, 2);
  nm1d2 = 0;
  itmp = jj->size[0] * jj->size[1];
  jj->size[0] = 1;
  jj->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)jj, itmp, (int)sizeof(int));
  ix = SPitch->size[1];
  itmp = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
  if (SPitch->size[1] == 0) {
    itmp = jj->size[0] * jj->size[1];
    jj->size[0] = 1;
    jj->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)jj, itmp, (int)sizeof(int));
    itmp = SHC->size[0] * SHC->size[1];
    SHC->size[0] = 1;
    SHC->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
  } else {
    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix <= SPitch->size[1])) {
      guard1 = false;
      if (SPitch->data[SPitch->size[0] * (ix - 1)] != 0.0) {
        nm1d2++;
        jj->data[nm1d2 - 1] = ix;
        SHC->data[nm1d2 - 1] = SPitch->data[SPitch->size[0] * (ix - 1)];
        if (nm1d2 >= SPitch->size[1]) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ix++;
      }
    }

    if (SPitch->size[1] == 1) {
      if (nm1d2 == 0) {
        itmp = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)jj, itmp, (int)sizeof(int));
        itmp = SHC->size[0] * SHC->size[1];
        SHC->size[0] = 1;
        SHC->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
      }
    } else {
      if (1 > nm1d2) {
        loop_ub = 0;
      } else {
        loop_ub = nm1d2;
      }

      emxInit_int32_T(&b_jj, 2);
      itmp = b_jj->size[0] * b_jj->size[1];
      b_jj->size[0] = 1;
      b_jj->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)b_jj, itmp, (int)sizeof(int));
      for (itmp = 0; itmp < loop_ub; itmp++) {
        b_jj->data[b_jj->size[0] * itmp] = jj->data[itmp];
      }

      itmp = jj->size[0] * jj->size[1];
      jj->size[0] = 1;
      jj->size[1] = b_jj->size[1];
      emxEnsureCapacity((emxArray__common *)jj, itmp, (int)sizeof(int));
      loop_ub = b_jj->size[1];
      for (itmp = 0; itmp < loop_ub; itmp++) {
        jj->data[jj->size[0] * itmp] = b_jj->data[b_jj->size[0] * itmp];
      }

      emxFree_int32_T(&b_jj);
      if (1 > nm1d2) {
        loop_ub = 0;
      } else {
        loop_ub = nm1d2;
      }

      emxInit_real_T(&d_SHC, 2);
      itmp = d_SHC->size[0] * d_SHC->size[1];
      d_SHC->size[0] = 1;
      d_SHC->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)d_SHC, itmp, (int)sizeof(double));
      for (itmp = 0; itmp < loop_ub; itmp++) {
        d_SHC->data[d_SHC->size[0] * itmp] = SHC->data[itmp];
      }

      itmp = SHC->size[0] * SHC->size[1];
      SHC->size[0] = 1;
      SHC->size[1] = d_SHC->size[1];
      emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
      loop_ub = d_SHC->size[1];
      for (itmp = 0; itmp < loop_ub; itmp++) {
        SHC->data[SHC->size[0] * itmp] = d_SHC->data[d_SHC->size[0] * itmp];
      }

      emxFree_real_T(&d_SHC);
    }
  }

  if (numframes < 1.0) {
    ix = -1;
    Num_VCands = 1.0;
    apnd = 0.0;
  } else if (rtIsInf(numframes)) {
    ix = 0;
    Num_VCands = rtNaN;
    apnd = numframes;
  } else {
    Num_VCands = 1.0;
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

    ix = (int)ndbl - 1;
  }

  itmp = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = ix + 1;
  emxEnsureCapacity((emxArray__common *)Signal, itmp, (int)sizeof(double));
  if (ix + 1 > 0) {
    Signal->data[0] = Num_VCands;
    if (ix + 1 > 1) {
      Signal->data[ix] = apnd;
      nm1d2 = ix / 2;
      for (cindx = 1; cindx < nm1d2; cindx++) {
        Signal->data[cindx] = Num_VCands + (double)cindx;
        Signal->data[ix - cindx] = apnd - (double)cindx;
      }

      if (nm1d2 << 1 == ix) {
        Signal->data[nm1d2] = (Num_VCands + apnd) / 2.0;
      } else {
        Signal->data[nm1d2] = Num_VCands + (double)nm1d2;
        Signal->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T(&c_jj, 2);
  itmp = c_jj->size[0] * c_jj->size[1];
  c_jj->size[0] = 1;
  c_jj->size[1] = jj->size[1];
  emxEnsureCapacity((emxArray__common *)c_jj, itmp, (int)sizeof(double));
  loop_ub = jj->size[0] * jj->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    c_jj->data[itmp] = jj->data[itmp];
  }

  emxFree_int32_T(&jj);
  interp1(c_jj, SHC, Signal, SPitch);
  itmp = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Signal, itmp, (int)sizeof(double));
  loop_ub = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&c_jj);
  emxFree_real_T(&SHC);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    Signal->data[itmp] = SPitch->data[itmp];
  }

  for (itmp = 0; itmp < 2; itmp++) {
    outsz[itmp] = (unsigned int)SPitch->size[itmp];
  }

  itmp = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = (int)outsz[1];
  emxEnsureCapacity((emxArray__common *)SPitch, itmp, (int)sizeof(double));
  if (Signal->size[1] >= 6) {
    itmp = SPitch->size[0] * SPitch->size[1];
    SPitch->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)SPitch, itmp, (int)sizeof(double));
    itmp = SPitch->size[0] * SPitch->size[1];
    SPitch->size[1] = (int)outsz[1];
    emxEnsureCapacity((emxArray__common *)SPitch, itmp, (int)sizeof(double));
    loop_ub = (int)outsz[1];
    for (itmp = 0; itmp < loop_ub; itmp++) {
      SPitch->data[itmp] = 0.0;
    }

    for (cindx = 0; cindx < 3; cindx++) {
      nm1d2 = (cindx + Signal->size[1]) - cindx;
      for (ix = cindx; ix + 1 <= nm1d2; ix++) {
        SPitch->data[ix] += 0.33333333333333331 * Signal->data[ix - cindx];
      }
    }
  } else {
    for (cindx = 0; cindx < 2; cindx++) {
      dbuffer[cindx + 1] = 0.0;
    }

    for (ix = 0; ix + 1 <= Signal->size[1]; ix++) {
      for (cindx = 0; cindx < 2; cindx++) {
        dbuffer[cindx] = dbuffer[cindx + 1];
      }

      dbuffer[2] = 0.0;
      for (cindx = 0; cindx < 3; cindx++) {
        window_length = dbuffer[cindx] + Signal->data[ix] * 0.33333333333333331;
        dbuffer[cindx] = window_length;
      }

      SPitch->data[ix] = dbuffer[0];
    }
  }

  emxFree_real_T(&Signal);

  /*   above messes up  first few values of SPitch  ---  simple fix up */
  /*   Note--   this fix up should be based on above filter order */
  SPitch->data[0] = SPitch->data[2];
  SPitch->data[1] = SPitch->data[3];

  /*  Create pitch track with Voiced/Unvoiced decision */
  itmp = VUVSPitch->size[0] * VUVSPitch->size[1];
  VUVSPitch->size[0] = 1;
  VUVSPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)VUVSPitch, itmp, (int)sizeof(double));
  loop_ub = SPitch->size[0] * SPitch->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    VUVSPitch->data[itmp] = SPitch->data[itmp];
  }

  emxInit_boolean_T(&b_VUVEnergy, 2);
  itmp = b_VUVEnergy->size[0] * b_VUVEnergy->size[1];
  b_VUVEnergy->size[0] = 1;
  b_VUVEnergy->size[1] = VUVEnergy->size[1];
  emxEnsureCapacity((emxArray__common *)b_VUVEnergy, itmp, (int)sizeof(boolean_T));
  loop_ub = VUVEnergy->size[0] * VUVEnergy->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    b_VUVEnergy->data[itmp] = (VUVEnergy->data[itmp] == 0);
  }

  eml_li_find(b_VUVEnergy, iindx);
  loop_ub = iindx->size[0] * iindx->size[1];
  emxFree_boolean_T(&b_VUVEnergy);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    VUVSPitch->data[iindx->data[itmp] - 1] = 0.0;
  }

  emxFree_int32_T(&iindx);

  /*  SPitch = SPitch - delta; */
}

/*
 * File trailer for spec_trk.c
 *
 * [EOF]
 */
