/*
 * File: yaapt.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_emxutil.h"
#include "Smooth.h"
#include "freqSelect.h"
#include "path1.h"
#include "mean.h"
#include "Mymedfilt1.h"
#include "sort1.h"
#include "cat.h"
#include "tm_trk.h"
#include "spec_trk.h"
#include "nlfer.h"
#include "nonlinear.h"
#include "Preprocess.h"

/* Function Definitions */

/*
 * YAAPT Fundamental Frequency (Pitch) tracking
 *
 *  [Pitch, numfrms, frmrate] = yaapt(Data, Fs, VU, ExtrPrm, fig)
 *    , the function is to check input parameters and invoke a number of associated routines
 *    for the YAAPT pitch tracking.
 *
 *  INPUTS:
 *    Data:       Input speech raw data
 *    Fs:         Sampling rate of the input data
 *    VU:         Whether to use voiced/unvoiced decision with 1 for True and 0 for
 *                False.The default is 1.
 *    ExtrPrm:    Extra parameters in a struct type for performance control.
 *                See available parameters defined in yaapt.m
 *                e.g.,
 *                ExtrPrm.f0_min = 60;         % Change minimum search F0 to 60Hz
 *                ExtrmPrm.fft_length = 8192;  % Change FFT length to 8192
 *    fig:        Whether to plot pitch tracks, spectrum, engergy, etc. The parameter
 *                is 1 for True and 0 for False. The default is 0.
 *
 *  OUTPUTS:
 *    Pitch:      Final pitch track in Hz. Unvoiced frames are assigned to 0s.
 *    numfrms:    Total number of calculated frames, or the length of
 *                output pitch track
 *    frmrate:    Frame rate of output pitch track in ms
 * Arguments    : const emxArray_real_T *Data
 *                double Fs
 *                const double Parameter[34]
 *                emxArray_real_T *Pitch
 *                double *numfrms
 *                double *frmrate
 * Return Type  : void
 */
void yaapt(const emxArray_real_T *Data, double Fs, const double Parameter[34],
           emxArray_real_T *Pitch, double *numfrms, double *frmrate)
{
  emxArray_real_T *Data_after;
  emxArray_real_T *DataB;
  emxArray_real_T *DataC;
  emxArray_real_T *DataD;
  emxArray_boolean_T *VUVEnergy;
  emxArray_real_T *b_DataD;
  double nFs;
  struct_T expl_temp;
  int Trans;
  int loop_ub;
  emxArray_real_T *SPitch;
  emxArray_real_T *TPitch1;
  emxArray_real_T *TMerit1;
  emxArray_real_T *TPitch2;
  emxArray_real_T *TMerit2;
  emxArray_real_T *RPitch;
  emxArray_int32_T *iidx;
  double pAvg_data[1];
  int pAvg_size[1];
  double pStd_data[1];
  int pStd_size[1];
  int numframes;
  int maxcands;
  int n;
  emxArray_real_T *r0;
  emxArray_real_T *b_RPitch;
  int b_Data_after;
  int i;
  double varargin_2;
  int j;
  double d0;
  int numcands;
  emxArray_int32_T *r1;
  emxArray_real_T *c_Data_after;
  emxArray_real_T *b_Trans;
  double mean_pitch;
  int k;
  emxArray_real_T *r2;
  double d1;
  double Path_data[4999];
  int Path_size[2];
  emxInit_real_T(&Data_after, 2);
  emxInit_real_T(&DataB, 2);
  emxInit_real_T(&DataC, 2);
  emxInit_real_T(&DataD, 2);
  emxInit_boolean_T(&VUVEnergy, 2);
  emxInit_real_T(&b_DataD, 2);

  /*   Creation Date:  June 2000 */
  /*   Revision date:  Jan 2, 2002 , Jan 13, 2002 Feb 19, 2002, Mar 3, 2002 */
  /*                   June 11, 2002, Jun 30, 2006, July 27, 2007 */
  /*                   May 20, 2012: Add the VU parameter for whether to use */
  /*                   voiced/unvoiced decision.  */
  /*   Authors:        Hongbing Hu, Stephen A.Zahorian */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*      This file is a part of the YAAPT program, designed for a fundamental  */
  /*    frequency tracking algorithm that is extermely robust for both high quality  */
  /*    and telephone speech.   */
  /*      The YAAPT program was created by the Speech Communication Laboratory of */
  /*    the state university of New York at Binghamton. The program is available  */
  /*    at http://www.ws.binghamton.edu/zahorian as free software. Further  */
  /*    information about the program can be found at "A spectral/temporal  */
  /*    method for robust fundamental frequency tracking," J.Acosut.Soc.Am. 123(6),  */
  /*    June 2008. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* -- PARAMETERS ---------------------------------------------------------------- */
  /*  Preliminary input arguments check */
  /*  Default values for the tracking with voiced/unvoiced decision */
  /*  % Length of each analysis frame (ms) */
  /*  % Spacing between analysis frame (ms) */
  /*  % Minimum F0 searched (Hz) */
  /*  % Maximum F0 searached (Hz) */
  /*  % FFT length */
  /*  % Order of bandpass filter (even) */
  /*  % Low frequency of filter passband (Hz) */
  /*  % High frequency of filter passband (Hz) */
  /*  % NLFER boundary for voiced/unvoiced decisions */
  /*  % Threshold for NLFER definitely unvocied */
  /*  % Number of harmonics in SHC calculation */
  /*  % SHC window length (Hz) */
  /*  % Maximum number of SHC peaks to be found */
  /*  % Window width in SHC peak picking (Hz) */
  /*  % Threshold 1 for SHC peak picking */
  /*  % Threshold 2 for SHC peak picking */
  /*  % F0 doubling decision threshold (Hz) */
  /*  % F0 halving decision threshold (Hz) */
  /*  % Weight used in dynaimc program */
  /*  % Factor for signal resampling */
  /*  % Threshold for considering a peak in NCCF */
  /*  % Threshold for terminating serach in NCCF */
  /*  % Maximum number of candidates found */
  /*  % Window width in NCCF peak picking */
  /*  % Boost merit */
  /*  % Merit assigned to unvoiced candidates in */
  /*  % defintely unvoiced frames */
  /*  % Merit assigned to extra candidates */
  /*  % in reducing F0 doubling/halving errors */
  /*  % Order of medial filter */
  /*  % DP weight factor for V-V transitions */
  /*  % DP weight factor for V-UV or UV-V transitions */
  /*  % DP weight factor of UV-UV transitions */
  /*  % Weight factor for local costs */
  /*  % Threshold of smoothing chunks */
  /*  Select parameter set  */
  /*  if (nargin > 2 && ~isempty(VU) && VU == 0) */
  /*      Prm = Prm_aV; */
  /*  else  */
  /*      Prm = Prm_VU; */
  /*  end */
  /*  Not needed if ignoring gross error minimization */
  /*  Overwrite parameters if they are passed from command line(ExtrPar)   */
  /*  if ((nargin > 3) && isstruct(ExtrPrm)) */
  /*      fdNames = fieldnames(ExtrPrm); */
  /*      for n = 1:length(fdNames) */
  /*          pName = char(fdNames(n)); */
  /*          Prm.(pName) = ExtrPrm.(pName); */
  /*          %message('PT:det', 'Parameter %s replaced: %d', pName,Prm.(pName)); */
  /*      end */
  /*  end */
  /* Prm */
  /*  Whether to plot pitch tracks, spectrum, engergy, etc. */
  /*  GraphPar = 0; */
  /*  if (nargin > 4 && ~isempty(fig)) */
  /*      GraphPar = fig; */
  /*  end */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Step 1. Preprocessing */
  /*   Create the squared or absolute values of filtered speech data */
  Preprocess(Data, Data_after);
  nonlinear(Data_after, Fs, Parameter[5], Parameter[6], Parameter[7], Parameter
            [19], DataB, DataC, DataD, &nFs);

  /*   Check frame size, frame jump and the number of frames for nonlinear singal */
  /*   Step 2. Spectral pitch tracking */
  /*   Calculate NLFER and determine voiced/unvoiced frames with NLFER */
  nlfer(DataB, nFs, Parameter[0], Parameter[1], Parameter[2], Parameter[3],
        Parameter[4], Parameter[8], DataC, VUVEnergy);

  /*   Calculate an approximate pitch track from the spectrum. */
  /*   At this point, SPitch is best estimate of pitch track from spectrum */
  expl_temp.end = Parameter[33];
  expl_temp.smooth_threshold = Parameter[32];
  expl_temp.dp_w4 = Parameter[31];
  expl_temp.dp_w3 = Parameter[30];
  expl_temp.dp_w2 = Parameter[29];
  expl_temp.dp_w1 = Parameter[28];
  expl_temp.median_value = Parameter[27];
  expl_temp.merit_extra = Parameter[26];
  expl_temp.merit_pivot = Parameter[25];
  expl_temp.merit_boost = Parameter[24];
  expl_temp.nccf_pwidth = Parameter[23];
  expl_temp.nccf_maxcands = Parameter[22];
  expl_temp.nccf_thresh2 = Parameter[21];
  expl_temp.nccf_thresh1 = Parameter[20];
  expl_temp.dec_factor = Parameter[19];
  expl_temp.dp5_k1 = Parameter[18];
  expl_temp.f0_half = Parameter[17];
  expl_temp.f0_double = Parameter[16];
  expl_temp.shc_thresh2 = Parameter[15];
  expl_temp.shc_thresh1 = Parameter[14];
  expl_temp.shc_pwidth = Parameter[13];
  expl_temp.shc_maxpeaks = Parameter[12];
  expl_temp.shc_window = Parameter[11];
  expl_temp.shc_numharms = Parameter[10];
  expl_temp.nlfer_thresh2 = Parameter[9];
  expl_temp.nlfer_thresh1 = Parameter[8];
  expl_temp.bp_high = Parameter[7];
  expl_temp.bp_low = Parameter[6];
  expl_temp.bp_forder = Parameter[5];
  expl_temp.fft_length = Parameter[4];
  expl_temp.f0_max = Parameter[3];
  expl_temp.f0_min = Parameter[2];
  expl_temp.frame_space = Parameter[1];
  expl_temp.frame_length = Parameter[0];
  Trans = b_DataD->size[0] * b_DataD->size[1];
  b_DataD->size[0] = 1;
  b_DataD->size[1] = DataD->size[1];
  emxEnsureCapacity((emxArray__common *)b_DataD, Trans, (int)sizeof(double));
  loop_ub = DataD->size[0] * DataD->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_DataD->data[Trans] = DataD->data[Trans];
  }

  emxInit_real_T(&SPitch, 2);
  emxInit_real_T(&TPitch1, 2);
  emxInit_real_T(&TMerit1, 2);
  emxInit_real_T(&TPitch2, 2);
  emxInit_real_T(&TMerit2, 2);
  emxInit_real_T(&RPitch, 2);
  emxInit_int32_T(&iidx, 2);
  spec_trk(b_DataD, nFs, VUVEnergy, &expl_temp, SPitch, Data_after, pAvg_data,
           pAvg_size, pStd_data, pStd_size);

  /*   Step 3. Temporal pitch tracking based on NCCF */
  /*   Calculate a pitch track based on time-domain processing */
  /*   Pitch tracking from the filterd original signal  */
  tm_trk(DataB, nFs, SPitch, pStd_data, pStd_size, Parameter[0], Parameter[1],
         Parameter[2], Parameter[3], Parameter[20], Parameter[21], Parameter[22],
         Parameter[23], Parameter[24], TPitch1, TMerit1);

  /*   Pitch tracking from the filterd nonlinear signal  */
  tm_trk(DataD, nFs, SPitch, pStd_data, pStd_size, Parameter[0], Parameter[1],
         Parameter[2], Parameter[3], Parameter[20], Parameter[21], Parameter[22],
         Parameter[23], Parameter[24], TPitch2, TMerit2);

  /*  Refine pitch candidates  */
  /*  REFINE Refine pitch candidates for YAAPT Pitch tracking */
  /*  */
  /*  [Pitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, Energy, VUVEnergy, Prm) */
  /*    refins pitch cadidates obtained from NCCF using spectral pitch */
  /*    track and NLFER energy information. */
  /*  */
  /*  INPUTS:  */
  /*    TPitch1:  Pitch candidates array 1 */
  /*    TMerti1:  Merits for pitch candidates array 1 */
  /*    TPitch2:  Pitch candidates array 2 */
  /*    TMerti2:  Merits for pitch candidates array 2 */
  /*    SPitch:   Smoothed spectral pitch track */
  /*    Energy:   NLFER Energy information */
  /*    VUVEnergy: Voiced/Unvoiced information determined by NLFER energy */
  /*    Prm:      Parameters */
  /*  */
  /*  OUTPUTS: */
  /*    Pitch:   Refined overall pitch candidates */
  /*    Merit:   Merit for overall pitch candidates */
  /*    Creation: July 27 2007 */
  /*    Author:   Hongbing Hu */
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
  /* -- PARAMETERS ---------------------------------------------------------------- */
  /*  Threshold for NLFER energy */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Merge pitch candidates and their merits from two types of the signal */
  cat(TPitch1, TPitch2, RPitch);
  cat(TMerit1, TMerit2, TPitch2);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  numframes = RPitch->size[1] - 1;
  maxcands = RPitch->size[0];
  e_sort(TPitch2, iidx);
  Trans = TPitch1->size[0] * TPitch1->size[1];
  TPitch1->size[0] = iidx->size[0];
  TPitch1->size[1] = iidx->size[1];
  emxEnsureCapacity((emxArray__common *)TPitch1, Trans, (int)sizeof(double));
  loop_ub = iidx->size[0] * iidx->size[1];
  emxFree_real_T(&b_DataD);
  emxFree_real_T(&TMerit2);
  emxFree_real_T(&TMerit1);
  emxFree_real_T(&DataD);
  emxFree_real_T(&DataB);
  for (Trans = 0; Trans < loop_ub; Trans++) {
    TPitch1->data[Trans] = iidx->data[Trans];
  }

  emxFree_int32_T(&iidx);
  n = 0;
  emxInit_real_T1(&r0, 1);
  while (n <= numframes) {
    loop_ub = TPitch1->size[0];
    Trans = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)r0, Trans, (int)sizeof(double));
    for (Trans = 0; Trans < loop_ub; Trans++) {
      r0->data[Trans] = RPitch->data[((int)TPitch1->data[Trans + TPitch1->size[0]
        * n] + RPitch->size[0] * n) - 1];
    }

    loop_ub = r0->size[0];
    for (Trans = 0; Trans < loop_ub; Trans++) {
      RPitch->data[Trans + RPitch->size[0] * n] = r0->data[Trans];
    }

    n++;
  }

  emxFree_real_T(&r0);
  emxFree_real_T(&TPitch1);
  emxInit_real_T(&b_RPitch, 2);

  /*  A best pitch track is generated from the best candidates */
  loop_ub = RPitch->size[1];
  Trans = b_RPitch->size[0] * b_RPitch->size[1];
  b_RPitch->size[0] = 1;
  b_RPitch->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_RPitch, Trans, (int)sizeof(double));
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_RPitch->data[b_RPitch->size[0] * Trans] = RPitch->data[RPitch->size[0] *
      Trans];
  }

  Mymedfilt1(b_RPitch, Parameter[27], Data_after);
  Trans = Data_after->size[0] * Data_after->size[1];
  Data_after->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)Data_after, Trans, (int)sizeof(double));
  b_Data_after = Data_after->size[0];
  loop_ub = Data_after->size[1];
  loop_ub *= b_Data_after;
  emxFree_real_T(&b_RPitch);
  for (Trans = 0; Trans < loop_ub; Trans++) {
    Data_after->data[Trans] *= (double)VUVEnergy->data[Trans];
  }

  emxFree_boolean_T(&VUVEnergy);

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  for (i = 0; i <= numframes; i++) {
    if (DataC->data[i] <= Parameter[9]) {
      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      loop_ub = RPitch->size[0];
      for (Trans = 0; Trans < loop_ub; Trans++) {
        RPitch->data[Trans + RPitch->size[0] * i] = 0.0;
      }

      loop_ub = TPitch2->size[0];
      for (Trans = 0; Trans < loop_ub; Trans++) {
        TPitch2->data[Trans + TPitch2->size[0] * i] = Parameter[25];
      }
    } else if (RPitch->data[RPitch->size[0] * i] > 0.0) {
      /*  already have the voiced candidate, Want to have at */
      /*  least one unvoiced candidate */
      RPitch->data[(maxcands + RPitch->size[0] * i) - 1] = 0.0;
      TPitch2->data[(maxcands + TPitch2->size[0] * i) - 1] = 1.0 - TPitch2->
        data[TPitch2->size[0] * i];
      for (j = 1; j - 1 <= maxcands - 3; j++) {
        if (RPitch->data[j + RPitch->size[0] * i] == 0.0) {
          TPitch2->data[j + TPitch2->size[0] * i] = 0.0;
        }
      }
    } else {
      /*  there was no voiced candidate from nccf fill in */
      /*  option for F0 from spectrogram */
      RPitch->data[RPitch->size[0] * i] = SPitch->data[i];
      varargin_2 = DataC->data[i] / 2.0;
      if ((1.0 <= varargin_2) || rtIsNaN(varargin_2)) {
        TPitch2->data[TPitch2->size[0] * i] = 1.0;
      } else {
        TPitch2->data[TPitch2->size[0] * i] = varargin_2;
      }

      /*  all other candidates will be unvoiced */
      /*  with low merit */
      if (2 > maxcands) {
        Trans = 0;
        b_Data_after = 1;
      } else {
        Trans = 1;
        b_Data_after = maxcands + 1;
      }

      loop_ub = (b_Data_after - Trans) - 1;
      for (b_Data_after = 0; b_Data_after < loop_ub; b_Data_after++) {
        RPitch->data[(Trans + b_Data_after) + RPitch->size[0] * i] = 0.0;
      }

      if (2 > maxcands) {
        Trans = 0;
        b_Data_after = 1;
      } else {
        Trans = 1;
        b_Data_after = maxcands + 1;
      }

      varargin_2 = TPitch2->data[TPitch2->size[0] * i];
      loop_ub = (b_Data_after - Trans) - 1;
      for (b_Data_after = 0; b_Data_after < loop_ub; b_Data_after++) {
        TPitch2->data[(Trans + b_Data_after) + TPitch2->size[0] * i] = 1.0 -
          varargin_2;
      }
    }
  }

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  for (i = 0; i <= numframes; i++) {
    RPitch->data[(maxcands + RPitch->size[0] * i) - 2] = Data_after->
      data[Data_after->size[0] * i];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    if (Data_after->data[Data_after->size[0] * i] > 0.0) {
      /*  voiced */
      TPitch2->data[(maxcands + TPitch2->size[0] * i) - 2] = TPitch2->
        data[TPitch2->size[0] * i];
    } else {
      /*  unvoiced */
      varargin_2 = DataC->data[i] / 2.0;
      if ((1.0 <= varargin_2) || rtIsNaN(varargin_2)) {
        d0 = 1.0;
      } else {
        d0 = varargin_2;
      }

      TPitch2->data[(maxcands + TPitch2->size[0] * i) - 2] = 1.0 - d0;
    }
  }

  /*   Copy over the SPitch array */
  loop_ub = SPitch->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    RPitch->data[(maxcands + RPitch->size[0] * Trans) - 3] = SPitch->data
      [SPitch->size[0] * Trans];
  }

  loop_ub = DataC->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    TPitch2->data[(maxcands + TPitch2->size[0] * Trans) - 3] = DataC->data
      [DataC->size[0] * Trans] / 5.0;
  }

  /* ============================================================================== */
  /*  Step 5. Use dyanamic programming to determine the final pitch */
  /* DYNAMIC Dynamic programming for YAAPT pitch tracking */
  /*  */
  /*  [FinPitch] = dynamic(Pitch, Merit, Energy, Prm) is used */
  /*  to compute Local and Transition cost matrices */
  /*  to enable lowest cost tracking of pitch candidates; */
  /*  It uses NFLER from the spectrogram and the highly robust */
  /*  spectral F0 track, plus the merits, for */
  /*  computation of the cost matrices. */
  /*  */
  /* INPUTS:  */
  /*    Pitch:  Pitch array with elements arranged so that lowest */
  /*                       index correponds to  highest merit */
  /*    Merit:  Merit array with elements arranged as for pitch */
  /*    Energy: NLFER energy ratio from the low frequency regions of spectrogram. */
  /*    Prm:    Array of parameters used to control performance */
  /*  */
  /* OUTPUTS:   */
  /*    FinPitch: The final pitch track for the entire utterance pitch */
  /*    values are in HZ.Unvoiced frames are assigned 0. */
  /*  Note:   This routine is intended for more through testing of */
  /*     some thresholds used in dynamic6.   All the dp constants are */
  /*     set to fixed values that worked well in testing */
  /*     then the dp constants are used to specify the thresholds and other */
  /*      constants */
  /*    Creation date:   Spring 2001 */
  /*    Revision date:   January 3, 2002   June 16, 2007, July 27, 2007 */
  /*    Programmers: S. Zahorian,Kavita Kasi, Lingyun Gu, Hongbing Hu */
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
  /* -- INITIALIZATION ----------------------------------------------------------- */
  numframes = RPitch->size[1] - 1;
  numcands = RPitch->size[0] - 1;

  /* Copy some arrays */
  loop_ub = RPitch->size[1];
  b_Data_after = RPitch->size[0];
  Trans = Data_after->size[0] * Data_after->size[1];
  Data_after->size[0] = 1;
  Data_after->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)Data_after, Trans, (int)sizeof(double));
  for (Trans = 0; Trans < loop_ub; Trans++) {
    Data_after->data[Data_after->size[0] * Trans] = RPitch->data[(b_Data_after +
      RPitch->size[0] * Trans) - 2];
  }

  emxInit_int32_T(&r1, 2);
  loop_ub = RPitch->size[1] - 1;
  b_Data_after = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (Data_after->data[i] > 0.0) {
      b_Data_after++;
    }
  }

  Trans = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = b_Data_after;
  emxEnsureCapacity((emxArray__common *)r1, Trans, (int)sizeof(int));
  b_Data_after = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (Data_after->data[i] > 0.0) {
      r1->data[b_Data_after] = i + 1;
      b_Data_after++;
    }
  }

  emxInit_real_T(&c_Data_after, 2);
  Trans = c_Data_after->size[0] * c_Data_after->size[1];
  c_Data_after->size[0] = 1;
  c_Data_after->size[1] = r1->size[1];
  emxEnsureCapacity((emxArray__common *)c_Data_after, Trans, (int)sizeof(double));
  loop_ub = r1->size[0] * r1->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    c_Data_after->data[Trans] = Data_after->data[r1->data[Trans] - 1];
  }

  emxFree_int32_T(&r1);
  emxInit_real_T2(&b_Trans, 3);
  mean_pitch = mean(c_Data_after);

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Forming the local cost matrix */
  /*  Initialization for the formation of the transition cost matrix */
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  b_Trans->size[0] = RPitch->size[0];
  b_Trans->size[1] = RPitch->size[0];
  b_Trans->size[2] = RPitch->size[1];
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  loop_ub = RPitch->size[0] * RPitch->size[0] * RPitch->size[1];
  emxFree_real_T(&c_Data_after);
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] = 1.0;
  }

  /*  The transition cost matrix is proportional to frequency differences */
  /*  between successive candidates. */
  for (i = 1; i - 1 < numframes; i++) {
    for (j = 0; j <= numcands; j++) {
      for (k = 0; k <= numcands; k++) {
        /*  both candidates voiced */
        if ((RPitch->data[j + RPitch->size[0] * i] > 0.0) && (RPitch->data[k +
             RPitch->size[0] * (i - 1)] > 0.0)) {
          b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
            b_Trans->size[1] * i] = Parameter[28] * (fabs(RPitch->data[j +
            RPitch->size[0] * i] - RPitch->data[k + RPitch->size[0] * (i - 1)]) /
            mean_pitch);
        }

        /*  one candiate is unvoiced */
        if (((RPitch->data[j + RPitch->size[0] * i] == 0.0) && (RPitch->data[k +
              RPitch->size[0] * (i - 1)] > 0.0)) || ((RPitch->data[j +
              RPitch->size[0] * i] > 0.0) && (RPitch->data[k + RPitch->size[0] *
              (i - 1)] == 0.0))) {
          varargin_2 = fabs(DataC->data[i - 1] - DataC->data[i]);
          if ((1.0 <= varargin_2) || rtIsNaN(varargin_2)) {
            d1 = 1.0;
          } else {
            d1 = varargin_2;
          }

          b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
            b_Trans->size[1] * i] = Parameter[29] * (1.0 - d1);
        }

        /*  both candidates are unvoiced */
        if ((RPitch->data[j + RPitch->size[0] * i] == 0.0) && (RPitch->data[k +
             RPitch->size[0] * (i - 1)] == 0.0)) {
          b_Trans->data[(k + b_Trans->size[0] * j) + b_Trans->size[0] *
            b_Trans->size[1] * i] = Parameter[30];
        }
      }
    }
  }

  /*  Overal balance between Local and Transition costs */
  Trans = b_Trans->size[0] * b_Trans->size[1] * b_Trans->size[2];
  emxEnsureCapacity((emxArray__common *)b_Trans, Trans, (int)sizeof(double));
  b_Data_after = b_Trans->size[0];
  loop_ub = b_Trans->size[1];
  Trans = b_Trans->size[2];
  loop_ub = b_Data_after * loop_ub * Trans;
  for (Trans = 0; Trans < loop_ub; Trans++) {
    b_Trans->data[Trans] /= Parameter[31];
  }

  emxInit_real_T(&r2, 2);

  /*  Find the minimum cost path thru Pitch_Array using the Local and Trans costs */
  Trans = r2->size[0] * r2->size[1];
  r2->size[0] = TPitch2->size[0];
  r2->size[1] = TPitch2->size[1];
  emxEnsureCapacity((emxArray__common *)r2, Trans, (int)sizeof(double));
  loop_ub = TPitch2->size[0] * TPitch2->size[1];
  for (Trans = 0; Trans < loop_ub; Trans++) {
    r2->data[Trans] = 1.0 - TPitch2->data[Trans];
  }

  emxFree_real_T(&TPitch2);
  path1(r2, b_Trans, Path_data, Path_size);

  /* extracting the pitch, using Path */
  Trans = Data_after->size[0] * Data_after->size[1];
  Data_after->size[0] = 1;
  Data_after->size[1] = RPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Data_after, Trans, (int)sizeof(double));
  loop_ub = RPitch->size[1];
  emxFree_real_T(&r2);
  emxFree_real_T(&b_Trans);
  for (Trans = 0; Trans < loop_ub; Trans++) {
    Data_after->data[Trans] = 0.0;
  }

  for (i = 0; i <= numframes; i++) {
    Data_after->data[i] = RPitch->data[((int)Path_data[i] + RPitch->size[0] * i)
      - 1];
  }

  emxFree_real_T(&RPitch);
  *numfrms = Data_after->size[1];
  *frmrate = Parameter[1];
  freqSelect(Data_after, SPitch, DataC);

  /*  Preprocess the raw data from android voice recorder */
  /*  */
  /*  Data_in = Raw data android voice recorder */
  /*  Data_out = Head and tail muted data */
  /*  The noise comes from opening mic and closing mic */
  Trans = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 1;
  Pitch->size[1] = SPitch->size[1];
  emxEnsureCapacity((emxArray__common *)Pitch, Trans, (int)sizeof(double));
  loop_ub = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&DataC);
  emxFree_real_T(&Data_after);
  for (Trans = 0; Trans < loop_ub; Trans++) {
    Pitch->data[Trans] = SPitch->data[Trans];
  }

  for (i = 0; i < SPitch->size[1]; i++) {
    if ((i + 2U < (unsigned int)Pitch->size[1]) && (i > 0) && (Pitch->data[i - 1]
         != Pitch->data[i]) && (Pitch->data[i] != Pitch->data[i + 1])) {
      Pitch->data[i] = Pitch->data[i - 1];
    }
  }

  emxFree_real_T(&SPitch);
  Smooth(Pitch, Parameter[32]);
  Smooth(Pitch, Parameter[32]);
  Smooth(Pitch, Parameter[32]);

  /*  Pitch_out = Pitch_temp; */
  /* figure(3) */
  /*  plot(SPitch, 'b') */
  /*  hold on */
  /*  plot(Pitch, 'r') */
  /*  hold off */
  /*  title ('spectral pitch track') */
  /*  pause */
  /*   If VU = 0,  be sure entire track is voiced */
  /*      if (VU == 0)      %  Only applies if we want all voiced track     */
  /*         IDX_unvoiced = (Pitch < 1); */
  /*           Num_UV       = sum (IDX_unvoiced);    % Total number unvoiced frames */
  /*            if (Num_UV > 0)  */
  /*              for n = 1:numfrms;    %  there should be a more efficient way to do this */
  /*                 if (IDX_unvoiced(n) == 1); */
  /*                   Pitch(n) = SPitch(n); */
  /*                  end;   */
  /*              end;  */
  /*            end;   */
  /*       end; */
  /*  Replace above VU = 0 section for new ptch_fix() function */
  /*  if (VU==0) */
  /*      Pitch = ptch_fix(Pitch); */
  /*  end */
  /*  Pitch = SPitch;   % to see how good spectral track is */
  /* == FIGURE ==================================================================== */
  /*   Several plots to illustrate processing and performance */
  /*  if (GraphPar)      */
  /*      pt_figs(DataB, DataD, nFs, SPitch, Energy, VUVEnergy, RPitch, Pitch, Prm); */
  /*  end */
  /* ============================================================================== */
}

/*
 * File trailer for yaapt.c
 *
 * [EOF]
 */
