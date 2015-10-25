/*
 * File: spec_trk.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 25-Oct-2015 03:48:36
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
 *                emxArray_real_T *pAvg
 *                emxArray_real_T *pStd
 * Return Type  : void
 */
void spec_trk(emxArray_real_T *Data, double Fs, const emxArray_boolean_T
              *VUVEnergy, emxArray_real_T *SPitch, emxArray_real_T *VUVSPitch,
              emxArray_real_T *pAvg, emxArray_real_T *pStd)
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
  double d1;
  int ixstart;
  emxArray_int32_T *iindx;
  int nm1d2;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  int ix;
  double SPitch_temp_end;
  double apnd;
  double ndbl;
  double cdiff;
  emxArray_real_T *VPeak_minmrt;
  int cindx;
  emxArray_real_T *winix;
  emxArray_real_T *rowix;
  emxArray_real_T *Magnit;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  int Signal_size[2];
  double Signal_data[1];
  emxArray_real_T b_Signal_data;
  static creal_T dcv0[8192];
  double dv6[8192];
  int tmp_size[2];
  double tmp_data[4];
  int b_tmp_size[2];
  double b_tmp_data[4];
  emxArray_boolean_T *Idx_voiced;
  emxArray_real_T *VCandsMerit;
  emxArray_real_T *b_rowix;
  emxArray_real_T *c_rowix;
  emxArray_real_T *d_rowix;
  unsigned int outsz[2];
  unsigned int b_outsz;
  int b_ix;
  boolean_T exitg2;
  emxArray_real_T *VMerit_minmrt;
  emxArray_real_T *b_VPeak_minmrt;
  emxArray_real_T *VPitch;
  emxArray_boolean_T *b_SPitch;
  emxArray_boolean_T *b_SPitch_temp_end;
  emxArray_int32_T *jj;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_int32_T *b_jj;
  emxArray_real_T *c_SHC;
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

  /*  Zero padding */
  d1 = (numframes - 1.0) * nframejump + nframesize;
  if (Data->size[1] > d1) {
    itmp = 0;
    ixstart = 0;
  } else {
    itmp = Data->size[1] - 1;
    ixstart = (int)d1;
  }

  emxInit_int32_T(&iindx, 2);
  nm1d2 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = ixstart - itmp;
  emxEnsureCapacity((emxArray__common *)iindx, nm1d2, (int)sizeof(int));
  loop_ub = ixstart - itmp;
  for (ixstart = 0; ixstart < loop_ub; ixstart++) {
    iindx->data[iindx->size[0] * ixstart] = itmp + ixstart;
  }

  loop_ub = iindx->size[0] * iindx->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    Data->data[iindx->data[itmp]] = 0.0;
  }

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
    SPitch_temp_end = rtNaN;
    apnd = window_length;
  } else if (window_length < 1.0) {
    ix = -1;
    SPitch_temp_end = 1.0;
    apnd = window_length;
  } else if (rtIsInf(window_length)) {
    ix = 0;
    SPitch_temp_end = rtNaN;
    apnd = window_length;
  } else {
    SPitch_temp_end = 1.0;
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

  emxInit_real_T(&VPeak_minmrt, 2);
  itmp = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  VPeak_minmrt->size[1] = ix + 1;
  emxEnsureCapacity((emxArray__common *)VPeak_minmrt, itmp, (int)sizeof(double));
  if (ix + 1 > 0) {
    VPeak_minmrt->data[0] = SPitch_temp_end;
    if (ix + 1 > 1) {
      VPeak_minmrt->data[ix] = apnd;
      nm1d2 = ix / 2;
      for (cindx = 1; cindx < nm1d2; cindx++) {
        VPeak_minmrt->data[cindx] = SPitch_temp_end + (double)cindx;
        VPeak_minmrt->data[ix - cindx] = apnd - (double)cindx;
      }

      if (nm1d2 << 1 == ix) {
        VPeak_minmrt->data[nm1d2] = (SPitch_temp_end + apnd) / 2.0;
      } else {
        VPeak_minmrt->data[nm1d2] = SPitch_temp_end + (double)nm1d2;
        VPeak_minmrt->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_real_T(&winix, 2);
  emxInit_real_T(&rowix, 2);
  repmat(VPeak_minmrt, winix);
  b_repmat(window_length, rowix);
  ix = 0;
  b_emxInit_real_T(&Magnit, 1);
  emxInit_real_T(&b_SHC, 2);
  emxInit_real_T(&b_Magnit, 2);
  while (ix <= (int)numframes - 1) {
    if ((int)VUVEnergy->data[ix] > 0) {
      SPitch_temp_end = 1.0 + ((1.0 + (double)ix) - 1.0) * nframejump;
      d1 = (SPitch_temp_end + nframesize) - 1.0;
      if (SPitch_temp_end > d1) {
        itmp = 0;
        ixstart = 0;
      } else {
        itmp = (int)SPitch_temp_end - 1;
        ixstart = (int)d1;
      }

      Signal_size[0] = 1;
      Signal_size[1] = ixstart - itmp;
      loop_ub = ixstart - itmp;
      for (ixstart = 0; ixstart < loop_ub; ixstart++) {
        Signal_data[Signal_size[0] * ixstart] = Data->data[itmp + ixstart] *
          Kaiser_window->data[Kaiser_window->size[0] * ixstart];
      }

      b_Signal_data.data = (double *)&Signal_data;
      b_Signal_data.size = (int *)&Signal_size;
      b_Signal_data.allocatedSize = 1;
      b_Signal_data.numDimensions = 2;
      b_Signal_data.canFreeData = false;
      d1 = mean(&b_Signal_data);
      Signal_size[0] = 1;
      Signal_size[1] = 1;
      Signal_data[0] -= d1;

      /*              Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      fft(Signal_data, dcv0);
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
        SPitch_temp_end = min_SHC + (double)cindx;
        ixstart = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = 4;
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity((emxArray__common *)b_Magnit, ixstart, (int)sizeof
                          (double));
        loop_ub = winix->size[0] * winix->size[1];
        for (ixstart = 0; ixstart < loop_ub; ixstart++) {
          b_Magnit->data[ixstart] = Magnit->data[(int)(winix->data[ixstart] +
            SPitch_temp_end * rowix->data[ixstart]) - 1];
        }

        prod(b_Magnit, VPeak_minmrt);
        SHC->data[(int)SPitch_temp_end - 1] = sum(VPeak_minmrt);
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
        CandsPitch->data[itmp + CandsPitch->size[0] * ix] = b_tmp_data[itmp];
      }

      for (itmp = 0; itmp < 4; itmp++) {
        CandsMerit->data[itmp + CandsMerit->size[0] * ix] = tmp_data[itmp];
      }
    } else {
      /*  if energy is low,  let frame be considered as unvoiced */
      for (itmp = 0; itmp < 4; itmp++) {
        CandsPitch->data[itmp + CandsPitch->size[0] * ix] = 0.0;
      }

      for (itmp = 0; itmp < 4; itmp++) {
        CandsMerit->data[itmp + CandsMerit->size[0] * ix] = 1.0;
      }
    }

    ix++;
  }

  emxFree_real_T(&b_Magnit);
  emxFree_real_T(&b_SHC);
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

  eml_li_find(Idx_voiced, iindx);
  itmp = rowix->size[0] * rowix->size[1];
  rowix->size[0] = 4;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)rowix, itmp, (int)sizeof(double));
  loop_ub = iindx->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    for (ixstart = 0; ixstart < 4; ixstart++) {
      rowix->data[ixstart + rowix->size[0] * itmp] = CandsPitch->data[ixstart +
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
    for (ixstart = 0; ixstart < 4; ixstart++) {
      VCandsMerit->data[ixstart + VCandsMerit->size[0] * itmp] =
        CandsMerit->data[ixstart + CandsMerit->size[0] * (iindx->data
        [iindx->size[0] * itmp] - 1)];
    }
  }

  emxFree_real_T(&CandsMerit);
  emxInit_real_T(&b_rowix, 2);
  ndbl = b_sum(Idx_voiced);

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
  apnd = mean(b_rowix);
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
  cdiff = b_std(c_rowix);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  itmp = d_rowix->size[0] * d_rowix->size[1];
  d_rowix->size[0] = 4;
  d_rowix->size[1] = rowix->size[1];
  emxEnsureCapacity((emxArray__common *)d_rowix, itmp, (int)sizeof(double));
  d1 = 0.8 * apnd;
  loop_ub = rowix->size[0] * rowix->size[1];
  emxFree_real_T(&c_rowix);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    d_rowix->data[itmp] = rowix->data[itmp] - d1;
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
  for (loop_ub = 1; loop_ub <= winix->size[1]; loop_ub++) {
    ixstart = ix - 3;
    SPitch_temp_end = winix->data[ix - 4];
    itmp = 1;
    cindx = 1;
    if (rtIsNaN(winix->data[ix - 4])) {
      b_ix = ix - 2;
      exitg2 = false;
      while ((!exitg2) && (b_ix <= ix)) {
        cindx++;
        ixstart = b_ix;
        if (!rtIsNaN(winix->data[b_ix - 1])) {
          SPitch_temp_end = winix->data[b_ix - 1];
          itmp = cindx;
          exitg2 = true;
        } else {
          b_ix++;
        }
      }
    }

    if (ixstart < ix) {
      while (ixstart + 1 <= ix) {
        cindx++;
        if (winix->data[ixstart] < SPitch_temp_end) {
          SPitch_temp_end = winix->data[ixstart];
          itmp = cindx;
        }

        ixstart++;
      }
    }

    nm1d2++;
    iindx->data[nm1d2] = itmp;
    ix += 4;
  }

  emxFree_real_T(&winix);
  itmp = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
  loop_ub = iindx->size[0] * iindx->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    SHC->data[itmp] = iindx->data[itmp];
  }

  itmp = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)VPeak_minmrt, itmp, (int)sizeof(double));
  ix = SHC->size[1];
  itmp = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)VPeak_minmrt, itmp, (int)sizeof(double));
  loop_ub = SHC->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    VPeak_minmrt->data[itmp] = 0.0;
  }

  emxInit_real_T(&VMerit_minmrt, 2);
  itmp = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)VMerit_minmrt, itmp, (int)sizeof(double));
  ix = SHC->size[1];
  itmp = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[1] = ix;
  emxEnsureCapacity((emxArray__common *)VMerit_minmrt, itmp, (int)sizeof(double));
  loop_ub = SHC->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    VMerit_minmrt->data[itmp] = 0.0;
  }

  for (ix = 0; ix < SHC->size[1]; ix++) {
    VPeak_minmrt->data[ix] = rowix->data[((int)SHC->data[ix] + rowix->size[0] *
      ix) - 1];
    VMerit_minmrt->data[ix] = VCandsMerit->data[((int)SHC->data[ix] +
      VCandsMerit->size[0] * ix) - 1];
  }

  emxInit_real_T(&b_VPeak_minmrt, 2);
  itmp = b_VPeak_minmrt->size[0] * b_VPeak_minmrt->size[1];
  b_VPeak_minmrt->size[0] = 1;
  b_VPeak_minmrt->size[1] = VPeak_minmrt->size[1];
  emxEnsureCapacity((emxArray__common *)b_VPeak_minmrt, itmp, (int)sizeof(double));
  loop_ub = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    b_VPeak_minmrt->data[itmp] = VPeak_minmrt->data[itmp];
  }

  Mymedfilt1(b_VPeak_minmrt, VPeak_minmrt);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  ix = 0;
  emxFree_real_T(&b_VPeak_minmrt);
  while (ix <= SHC->size[1] - 1) {
    rowix->data[((int)SHC->data[ix] + rowix->size[0] * ix) - 1] =
      VPeak_minmrt->data[ix];

    /*  Assign merit for the smoothed peaks */
    VCandsMerit->data[((int)SHC->data[ix] + VCandsMerit->size[0] * ix) - 1] =
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
  if (ndbl > 2.0) {
    dynamic5(rowix, VCandsMerit, 11.0 * cdiff / apnd, VPeak_minmrt);
    itmp = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VPeak_minmrt->size[1];
    emxEnsureCapacity((emxArray__common *)VPitch, itmp, (int)sizeof(double));
    loop_ub = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
    for (itmp = 0; itmp < loop_ub; itmp++) {
      VPitch->data[itmp] = VPeak_minmrt->data[itmp];
    }

    b_Mymedfilt1(VPitch, VPeak_minmrt);
    itmp = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VPeak_minmrt->size[1];
    emxEnsureCapacity((emxArray__common *)VPitch, itmp, (int)sizeof(double));
    loop_ub = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
    for (itmp = 0; itmp < loop_ub; itmp++) {
      VPitch->data[itmp] = VPeak_minmrt->data[itmp];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else if (ndbl > 0.0) {
    for (loop_ub = 0; loop_ub < (int)ndbl; loop_ub++) {
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
  b_mean(VPitch, pAvg);
  c_std(VPitch, pStd);

  /*  Streching out the smoothed pitch track */
  eml_li_find(Idx_voiced, iindx);
  loop_ub = iindx->size[0] * iindx->size[1];
  emxFree_boolean_T(&Idx_voiced);
  emxFree_real_T(&CandsPitch);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    SPitch->data[iindx->data[itmp] - 1] = VPitch->data[itmp];
  }

  emxFree_real_T(&VPitch);
  emxInit_boolean_T(&b_SPitch, 2);

  /*  Interpolating thru unvoiced frames */
  SPitch_temp_end = SPitch->data[SPitch->size[1] - 1];
  c_rdivide(pAvg, 2.0, VPeak_minmrt);
  itmp = b_SPitch->size[0] * b_SPitch->size[1];
  b_SPitch->size[0] = 1;
  b_SPitch->size[1] = VPeak_minmrt->size[1];
  emxEnsureCapacity((emxArray__common *)b_SPitch, itmp, (int)sizeof(boolean_T));
  ndbl = SPitch->data[0];
  loop_ub = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    b_SPitch->data[itmp] = (ndbl < VPeak_minmrt->data[itmp]);
  }

  if (all(b_SPitch)) {
    SPitch->data[0] = pAvg->data[0];
  }

  emxFree_boolean_T(&b_SPitch);
  emxInit_boolean_T(&b_SPitch_temp_end, 2);
  c_rdivide(pAvg, 2.0, VPeak_minmrt);
  itmp = b_SPitch_temp_end->size[0] * b_SPitch_temp_end->size[1];
  b_SPitch_temp_end->size[0] = 1;
  b_SPitch_temp_end->size[1] = VPeak_minmrt->size[1];
  emxEnsureCapacity((emxArray__common *)b_SPitch_temp_end, itmp, (int)sizeof
                    (boolean_T));
  loop_ub = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  for (itmp = 0; itmp < loop_ub; itmp++) {
    b_SPitch_temp_end->data[itmp] = (SPitch_temp_end < VPeak_minmrt->data[itmp]);
  }

  if (all(b_SPitch_temp_end)) {
    SPitch->data[SPitch->size[1] - 1] = pAvg->data[0];
  }

  emxFree_boolean_T(&b_SPitch_temp_end);
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

      emxInit_real_T(&c_SHC, 2);
      itmp = c_SHC->size[0] * c_SHC->size[1];
      c_SHC->size[0] = 1;
      c_SHC->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)c_SHC, itmp, (int)sizeof(double));
      for (itmp = 0; itmp < loop_ub; itmp++) {
        c_SHC->data[c_SHC->size[0] * itmp] = SHC->data[itmp];
      }

      itmp = SHC->size[0] * SHC->size[1];
      SHC->size[0] = 1;
      SHC->size[1] = c_SHC->size[1];
      emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
      loop_ub = c_SHC->size[1];
      for (itmp = 0; itmp < loop_ub; itmp++) {
        SHC->data[SHC->size[0] * itmp] = c_SHC->data[c_SHC->size[0] * itmp];
      }

      emxFree_real_T(&c_SHC);
    }
  }

  if (numframes < 1.0) {
    ix = -1;
    SPitch_temp_end = 1.0;
    apnd = 0.0;
  } else if (rtIsInf(numframes)) {
    ix = 0;
    SPitch_temp_end = rtNaN;
    apnd = numframes;
  } else {
    SPitch_temp_end = 1.0;
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

  itmp = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  VPeak_minmrt->size[1] = ix + 1;
  emxEnsureCapacity((emxArray__common *)VPeak_minmrt, itmp, (int)sizeof(double));
  if (ix + 1 > 0) {
    VPeak_minmrt->data[0] = SPitch_temp_end;
    if (ix + 1 > 1) {
      VPeak_minmrt->data[ix] = apnd;
      nm1d2 = ix / 2;
      for (cindx = 1; cindx < nm1d2; cindx++) {
        VPeak_minmrt->data[cindx] = SPitch_temp_end + (double)cindx;
        VPeak_minmrt->data[ix - cindx] = apnd - (double)cindx;
      }

      if (nm1d2 << 1 == ix) {
        VPeak_minmrt->data[nm1d2] = (SPitch_temp_end + apnd) / 2.0;
      } else {
        VPeak_minmrt->data[nm1d2] = SPitch_temp_end + (double)nm1d2;
        VPeak_minmrt->data[nm1d2 + 1] = apnd - (double)nm1d2;
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
  interp1(c_jj, SHC, VPeak_minmrt, SPitch);
  itmp = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)SHC, itmp, (int)sizeof(double));
  loop_ub = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&c_jj);
  emxFree_real_T(&VPeak_minmrt);
  for (itmp = 0; itmp < loop_ub; itmp++) {
    SHC->data[itmp] = SPitch->data[itmp];
  }

  for (itmp = 0; itmp < 2; itmp++) {
    outsz[itmp] = (unsigned int)SPitch->size[itmp];
  }

  itmp = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = (int)outsz[1];
  emxEnsureCapacity((emxArray__common *)SPitch, itmp, (int)sizeof(double));
  if (SHC->size[1] >= 6) {
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
      nm1d2 = (cindx + SHC->size[1]) - cindx;
      for (ix = cindx; ix + 1 <= nm1d2; ix++) {
        SPitch->data[ix] += 0.33333333333333331 * SHC->data[ix - cindx];
      }
    }
  } else {
    for (cindx = 0; cindx < 2; cindx++) {
      dbuffer[cindx + 1] = 0.0;
    }

    for (ix = 0; ix + 1 <= SHC->size[1]; ix++) {
      for (cindx = 0; cindx < 2; cindx++) {
        dbuffer[cindx] = dbuffer[cindx + 1];
      }

      dbuffer[2] = 0.0;
      for (cindx = 0; cindx < 3; cindx++) {
        SPitch_temp_end = dbuffer[cindx] + SHC->data[ix] * 0.33333333333333331;
        dbuffer[cindx] = SPitch_temp_end;
      }

      SPitch->data[ix] = dbuffer[0];
    }
  }

  emxFree_real_T(&SHC);

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
