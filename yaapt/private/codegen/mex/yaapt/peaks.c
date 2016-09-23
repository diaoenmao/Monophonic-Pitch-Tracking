/*
 * peaks.c
 *
 * Code generation for function 'peaks'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "peaks.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "mean.h"
#include "fix.h"
#include "mod.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ej_emlrtRSI = { 75, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo fj_emlrtRSI = { 81, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo gj_emlrtRSI = { 99, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRSInfo hj_emlrtRSI = { 122, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtRTEInfo cd_emlrtRTEI = { 1, 26, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 160, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 160, 38, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 159, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 159, 39, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 151, 31, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 145, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 139, 27, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 133, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { 1, 100, 106, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 99, 21, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo lb_emlrtDCI = { 99, 21, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtRTEInfo eg_emlrtRTEI = { 98, 1, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m" };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 81, 17, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo mb_emlrtDCI = { 81, 17, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 75, 16, "Data", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo nb_emlrtDCI = { 75, 16, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 1 };

static emlrtDCInfo ob_emlrtDCI = { 136, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo pb_emlrtDCI = { 137, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo qb_emlrtDCI = { 157, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo rb_emlrtDCI = { 158, 32, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo ue_emlrtBCI = { 1, 100, 123, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 139, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 141, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtDCInfo sb_emlrtDCI = { 148, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtDCInfo tb_emlrtDCI = { 149, 36, "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 4 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 151, 9, "Pitch", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 152, 9, "Merit", "peaks",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m", 0 };

/* Function Definitions */
void peaks(const emlrtStack *sp, emxArray_real_T *Data, real_T delta, real_T
           maxpeaks, real_T Prm_f0_min, real_T Prm_f0_max, real_T Prm_shc_pwidth,
           real_T Prm_shc_thresh1, real_T Prm_shc_thresh2, real_T Prm_f0_double,
           real_T Prm_f0_half, real_T Prm_merit_extra, emxArray_real_T *Pitch,
           emxArray_real_T *Merit)
{
  real_T width;
  real_T center;
  real_T min_lag;
  real_T max_lag;
  real_T b_Pitch[100];
  real_T b_Merit[100];
  int32_T i27;
  int32_T n;
  int32_T i28;
  boolean_T b3;
  int32_T ixstart;
  int32_T b_n;
  real_T mtmp;
  int32_T ix;
  boolean_T exitg2;
  int32_T itmp;
  emxArray_real_T *b_Data;
  real_T avg_data;
  real_T numpeaks;
  real_T c_n;
  int32_T i29;
  int32_T iidx[100];
  real_T c_Pitch[100];
  boolean_T exitg1;
  emxArray_real_T *d_Pitch;
  emxArray_real_T *r24;
  emxArray_real_T *e_Pitch;
  emxArray_real_T *r25;
  emxArray_real_T *c_Merit;
  emxArray_int32_T *r26;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 12U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 0);

  /* PEAKS  find peaks in SHC  */
  /*  */
  /*    [Pitch,Merit] = peaks(Data, delta, maxpeaks, Prm) */
  /*    computes peaks in a frequency domain function */
  /*    associated with the peaks found in each frame based on the */
  /*    correlation sequence. */
  /*  */
  /* INPUTS: */
  /*    Data:  The input signal(either autocorrelated/normalized cross correlated). */
  /*    delta: The resolution of spectrum */
  /*    maxpeaks: The max number of peaks picked  */
  /*    Prm:   Parameters */
  /*  */
  /* OUTPUTS:  */
  /*    Pitch:  The Pitch/Pitch values for the peaks found for each frame. */
  /*    Merit:  The Merit values of the peaks found in each frame. */
  /*   Creation date:   March 1, 2006 */
  /*   Revision dates:  March 11, 2006,  Jun 26, 2006, July 27, 2007 */
  /*   Programmer: S.A.Zahorian, Princy  Dikshit, Hongbing Hu */
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
  /*  Threshold for max avaliable peak */
  /*  Threshold for available peaks */
  /* -- COMPUTED VARIABLES -------------------------------------------------------- */
  /*  Length in Hz of range(must be largest to be a peak) */
  width = Prm_shc_pwidth / delta;
  b_fix(&width);

  /*  Window width in sample */
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 0, b_mod(width) == 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 1);
    width++;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 2);

  /*  The center of the window is defined as the peak location. */
  center = muDoubleScalarCeil(width / 2.0);

  /*  Lowest frequency at which F0 is allowed */
  min_lag = Prm_f0_min / delta - width / 4.0;
  b_fix(&min_lag);

  /*  Highest frequency at which F0 is allowed */
  max_lag = Prm_f0_max / delta + width / 4.0;
  b_fix(&max_lag);

  /*  if (min_lag < 1) */
  /*      min_lag = 1; */
  /*      disp('min_lag is too low and adjusted (%d)', min_lag);  */
  /*  end */
  /*  if max_lag > (length(Data) - width) */
  /*      max_lag = length(Data) - width; */
  /*      disp('max_lag is too high and adjusted (%d)', max_lag); */
  /*  end */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  /*  Peak(Pitch) candidates */
  memset(&b_Pitch[0], 0, 100U * sizeof(real_T));
  memset(&b_Merit[0], 0, 100U * sizeof(real_T));

  /*  Merits for peaks */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Normalize the signal so that peak value = 1 */
  if (min_lag > max_lag) {
    i27 = 0;
    n = 0;
  } else {
    i27 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &nb_emlrtDCI, sp);
    }

    i28 = (int32_T)min_lag;
    if (!((i28 >= 1) && (i28 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &te_emlrtBCI, sp);
    }

    i27 = i28 - 1;
    i28 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &nb_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i28))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i28, &te_emlrtBCI, sp);
    }
  }

  st.site = &ej_emlrtRSI;
  b_st.site = &ki_emlrtRSI;
  c_st.site = &li_emlrtRSI;
  if ((n - i27 == 1) || (n - i27 != 1)) {
    b3 = true;
  } else {
    b3 = false;
  }

  if (b3) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (n - i27 > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &vf_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &mi_emlrtRSI;
  ixstart = 1;
  b_n = n - i27;
  mtmp = Data->data[i27];
  if (n - i27 > 1) {
    if (muDoubleScalarIsNaN(mtmp)) {
      e_st.site = &oi_emlrtRSI;
      if ((!(2 > n - i27)) && (n - i27 > 2147483646)) {
        f_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= b_n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(Data->data[(i27 + ix) - 1])) {
          mtmp = Data->data[(i27 + ix) - 1];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < n - i27) {
      e_st.site = &ni_emlrtRSI;
      if ((!(ixstart + 1 > n - i27)) && (n - i27 > 2147483646)) {
        f_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (ix = ixstart - 1; ix + 2 <= b_n; ix++) {
        if (Data->data[(i27 + ix) + 1] > mtmp) {
          mtmp = Data->data[(i27 + ix) + 1];
        }
      }
    }
  }

  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 1, mtmp > 1.0E-14)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 3);
    i27 = Data->size[0] * Data->size[1];
    Data->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)Data, i27, (int32_T)sizeof(real_T),
                      &cd_emlrtRTEI);
    n = Data->size[0];
    itmp = Data->size[1];
    itmp *= n;
    for (i27 = 0; i27 < itmp; i27++) {
      Data->data[i27] /= mtmp;
    }
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 4);

  /*  If true there are no large peaks and we assume that signal is unvoiced */
  if (min_lag > max_lag) {
    i27 = 0;
    n = 0;
  } else {
    i27 = Data->size[1];
    if (min_lag != (int32_T)muDoubleScalarFloor(min_lag)) {
      emlrtIntegerCheckR2012b(min_lag, &mb_emlrtDCI, sp);
    }

    i28 = (int32_T)min_lag;
    if (!((i28 >= 1) && (i28 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &se_emlrtBCI, sp);
    }

    i27 = i28 - 1;
    i28 = Data->size[1];
    if (max_lag != (int32_T)muDoubleScalarFloor(max_lag)) {
      emlrtIntegerCheckR2012b(max_lag, &mb_emlrtDCI, sp);
    }

    n = (int32_T)max_lag;
    if (!((n >= 1) && (n <= i28))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i28, &se_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &b_Data, 2, &cd_emlrtRTEI, true);
  i28 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = n - i27;
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, i28, (int32_T)sizeof(real_T),
                    &cd_emlrtRTEI);
  itmp = n - i27;
  for (i28 = 0; i28 < itmp; i28++) {
    b_Data->data[b_Data->size[0] * i28] = Data->data[i27 + i28];
  }

  st.site = &fj_emlrtRSI;
  avg_data = mean(&st, b_Data);
  emxFree_real_T(&b_Data);
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 2, avg_data > 1.0 /
                 Prm_shc_thresh1)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 5);

    /*     numpeaks = 0; */
    i27 = Pitch->size[0] * Pitch->size[1];
    Pitch->size[0] = 1;
    Pitch->size[1] = (int32_T)maxpeaks;
    emxEnsureCapacity(sp, (emxArray__common *)Pitch, i27, (int32_T)sizeof(real_T),
                      &cd_emlrtRTEI);
    itmp = (int32_T)maxpeaks;
    for (i27 = 0; i27 < itmp; i27++) {
      Pitch->data[i27] = 0.0;
    }

    i27 = Merit->size[0] * Merit->size[1];
    Merit->size[0] = 1;
    Merit->size[1] = (int32_T)maxpeaks;
    emxEnsureCapacity(sp, (emxArray__common *)Merit, i27, (int32_T)sizeof(real_T),
                      &cd_emlrtRTEI);
    itmp = (int32_T)maxpeaks;
    for (i27 = 0; i27 < itmp; i27++) {
      Merit->data[i27] = 1.0;
    }

    /*  force an early end for unoviced frame  */
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 6);

    /*  Step 1 */
    /*  Find all peaks for search range */
    /*  a "peak" must be the higher than a specfied number of */
    /*  points on either side of point.  Peaks are further "cleaned" */
    /*  up, to retain only best peaks i.e. peaks which do not meet certain */
    /*  criteria are eliminated. */
    numpeaks = 0.0;
    i27 = (int32_T)(max_lag + (1.0 - min_lag));
    emlrtForLoopVectorCheckR2012b(min_lag, 1.0, max_lag, mxDOUBLE_CLASS, i27,
      &eg_emlrtRTEI, sp);
    b_n = 0;
    while (b_n <= i27 - 1) {
      c_n = min_lag + (real_T)b_n;
      covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 7);
      mtmp = (c_n + width) - 1.0;
      if (c_n > mtmp) {
        i28 = 0;
        i29 = 0;
      } else {
        i28 = Data->size[1];
        if (c_n != (int32_T)muDoubleScalarFloor(c_n)) {
          emlrtIntegerCheckR2012b(c_n, &lb_emlrtDCI, sp);
        }

        n = (int32_T)c_n;
        if (!((n >= 1) && (n <= i28))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, i28, &re_emlrtBCI, sp);
        }

        i28 = n - 1;
        n = Data->size[1];
        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &lb_emlrtDCI, sp);
        }

        i29 = (int32_T)mtmp;
        if (!((i29 >= 1) && (i29 <= n))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, n, &re_emlrtBCI, sp);
        }
      }

      st.site = &gj_emlrtRSI;
      b_st.site = &ij_emlrtRSI;
      c_st.site = &jj_emlrtRSI;
      if ((i29 - i28 == 1) || (i29 - i28 != 1)) {
        b3 = true;
      } else {
        b3 = false;
      }

      if (b3) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (i29 - i28 > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &vf_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &mi_emlrtRSI;
      ixstart = 2;
      n = i29 - i28;
      mtmp = Data->data[i28];
      itmp = 1;
      if (i29 - i28 > 1) {
        if (muDoubleScalarIsNaN(mtmp)) {
          e_st.site = &oi_emlrtRSI;
          if ((!(2 > i29 - i28)) && (i29 - i28 > 2147483646)) {
            f_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          ix = 2;
          exitg1 = false;
          while ((!exitg1) && (ix <= n)) {
            ixstart = ix + 1;
            if (!muDoubleScalarIsNaN(Data->data[(i28 + ix) - 1])) {
              mtmp = Data->data[(i28 + ix) - 1];
              itmp = ix;
              exitg1 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart - 1 < i29 - i28) {
          e_st.site = &ni_emlrtRSI;
          if ((!(ixstart > i29 - i28)) && (i29 - i28 > 2147483646)) {
            f_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while (ixstart <= n) {
            if (Data->data[(i28 + ixstart) - 1] > mtmp) {
              mtmp = Data->data[(i28 + ixstart) - 1];
              itmp = ixstart;
            }

            ixstart++;
          }
        }
      }

      /*  find peaks which are larger than threshold    */
      if (covrtLogCond(&emlrtCoverageInstance, 12U, 0U, 0, itmp == center) &&
          covrtLogCond(&emlrtCoverageInstance, 12U, 0U, 1, mtmp >
                       Prm_shc_thresh2 * avg_data)) {
        covrtLogMcdc(&emlrtCoverageInstance, 12U, 0U, 0, true);
        covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 3, true);
        covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 8);

        /*  Note Pitch(1) = delta, Pitch(2) = 2*delta */
        /*  Convert FFT indices to Pitch in Hz */
        numpeaks++;
        i28 = (int32_T)numpeaks;
        if (!((i28 >= 1) && (i28 <= 100))) {
          emlrtDynamicBoundsCheckR2012b(i28, 1, 100, &qe_emlrtBCI, sp);
        }

        b_Pitch[i28 - 1] = ((c_n + center) - 1.0) * delta;
        b_Merit[(int32_T)numpeaks - 1] = mtmp;
      } else {
        covrtLogMcdc(&emlrtCoverageInstance, 12U, 0U, 0, false);
        covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 3, false);
      }

      b_n++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 0, 0);

    /*  Step 2 */
    /*  Be sure there is large peak */
    mtmp = b_Merit[0];
    for (ix = 1; ix + 1 < 101; ix++) {
      if (b_Merit[ix] > mtmp) {
        mtmp = b_Merit[ix];
      }
    }

    if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 4, mtmp / avg_data <
                   Prm_shc_thresh1)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 9);

      /*    numpeaks = 0; */
      i27 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i27, (int32_T)sizeof
                        (real_T), &cd_emlrtRTEI);
      itmp = (int32_T)maxpeaks;
      for (i27 = 0; i27 < itmp; i27++) {
        Pitch->data[i27] = 0.0;
      }

      i27 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i27, (int32_T)sizeof
                        (real_T), &cd_emlrtRTEI);
      itmp = (int32_T)maxpeaks;
      for (i27 = 0; i27 < itmp; i27++) {
        Merit->data[i27] = 1.0;
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 10);

      /*  Step 3     */
      /*  Order the peaks according to size,  considering at most maxpeaks */
      st.site = &hj_emlrtRSI;
      b_st.site = &kj_emlrtRSI;
      sort(&b_st, b_Merit, iidx);
      for (i27 = 0; i27 < 100; i27++) {
        if (!((iidx[i27] >= 1) && (iidx[i27] <= 100))) {
          emlrtDynamicBoundsCheckR2012b(iidx[i27], 1, 100, &ue_emlrtBCI, sp);
        }

        c_Pitch[i27] = b_Pitch[iidx[i27] - 1];
      }

      memcpy(&b_Pitch[0], &c_Pitch[0], 100U * sizeof(real_T));

      /*  keep the number of peaks not greater than max number */
      numpeaks = muDoubleScalarMin(numpeaks, maxpeaks);
      if (1.0 > numpeaks) {
        itmp = 0;
      } else {
        itmp = (int32_T)numpeaks;
      }

      i27 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = itmp;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i27, (int32_T)sizeof
                        (real_T), &cd_emlrtRTEI);
      for (i27 = 0; i27 < itmp; i27++) {
        Pitch->data[Pitch->size[0] * i27] = b_Pitch[i27];
      }

      if (1.0 > numpeaks) {
        n = 0;
      } else {
        n = (int32_T)numpeaks;
      }

      i27 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = n;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i27, (int32_T)sizeof
                        (real_T), &cd_emlrtRTEI);
      for (i27 = 0; i27 < n; i27++) {
        Merit->data[Merit->size[0] * i27] = b_Merit[i27];
      }

      /*  Step 4 */
      /*  Insert candidates to reduce pitch doubling and pitch halving, if needed */
      if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 5, numpeaks > 0.0)) {
        emxInit_real_T(sp, &d_Pitch, 2, &cd_emlrtRTEI, true);

        /*  if best peak has F < this, insert peak at 2F */
        if (!(1 <= itmp)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, itmp, &pe_emlrtBCI, sp);
        }

        i27 = d_Pitch->size[0] * d_Pitch->size[1];
        d_Pitch->size[0] = 1;
        d_Pitch->size[1] = itmp;
        emxEnsureCapacity(sp, (emxArray__common *)d_Pitch, i27, (int32_T)sizeof
                          (real_T), &cd_emlrtRTEI);
        for (i27 = 0; i27 < itmp; i27++) {
          d_Pitch->data[d_Pitch->size[0] * i27] = b_Pitch[i27];
        }

        if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 6, d_Pitch->data[0] >
                       Prm_f0_double)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 11);
          numpeaks = muDoubleScalarMin(numpeaks + 1.0, maxpeaks);
          if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 7, numpeaks > itmp)) {
            covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 12);
            mtmp = numpeaks - (real_T)itmp;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &ob_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            b_n = Pitch->size[1];
            i27 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[1] = b_n + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)Pitch, i27, (int32_T)
                              sizeof(real_T), &cd_emlrtRTEI);
            mtmp = numpeaks - (real_T)itmp;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &ob_emlrtDCI, sp);
            }

            for (i27 = 0; i27 < ixstart; i27++) {
              Pitch->data[b_n + i27] = 0.0;
            }

            mtmp = numpeaks - (real_T)n;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &pb_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            b_n = Merit->size[1];
            i27 = Merit->size[0] * Merit->size[1];
            Merit->size[1] = b_n + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)Merit, i27, (int32_T)
                              sizeof(real_T), &cd_emlrtRTEI);
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &pb_emlrtDCI, sp);
            }

            for (i27 = 0; i27 < ixstart; i27++) {
              Merit->data[b_n + i27] = 0.0;
            }
          }

          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 13);
          i27 = Pitch->size[1];
          if (!(1 <= i27)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i27, &oe_emlrtBCI, sp);
          }

          i27 = Pitch->size[1];
          i28 = (int32_T)numpeaks;
          if (!((i28 >= 1) && (i28 <= i27))) {
            emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &ve_emlrtBCI, sp);
          }

          Pitch->data[i28 - 1] = Pitch->data[0] / 2.0;

          /*  Set merit for inserted peaks */
          i27 = Merit->size[1];
          i28 = (int32_T)numpeaks;
          if (!((i28 >= 1) && (i28 <= i27))) {
            emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &we_emlrtBCI, sp);
          }

          Merit->data[i28 - 1] = Prm_merit_extra;
        }

        emxFree_real_T(&d_Pitch);

        /*  If best peak has F > this, insert peak at half F */
        i27 = Pitch->size[1];
        if (!(1 <= i27)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i27, &ne_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 8, Pitch->data[0] <
                       Prm_f0_half)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 14);
          numpeaks = muDoubleScalarMin(numpeaks + 1.0, maxpeaks);
          if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 9, numpeaks >
                         Pitch->size[1])) {
            emxInit_real_T(sp, &e_Pitch, 2, &cd_emlrtRTEI, true);
            covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 15);
            n = Pitch->size[1];
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &sb_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            i27 = e_Pitch->size[0] * e_Pitch->size[1];
            e_Pitch->size[0] = 1;
            e_Pitch->size[1] = Pitch->size[1] + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)e_Pitch, i27, (int32_T)
                              sizeof(real_T), &cd_emlrtRTEI);
            itmp = Pitch->size[1];
            for (i27 = 0; i27 < itmp; i27++) {
              e_Pitch->data[e_Pitch->size[0] * i27] = Pitch->data[Pitch->size[0]
                * i27];
            }

            for (i27 = 0; i27 < ixstart; i27++) {
              e_Pitch->data[e_Pitch->size[0] * (i27 + Pitch->size[1])] = 0.0;
            }

            i27 = Pitch->size[0] * Pitch->size[1];
            Pitch->size[0] = 1;
            Pitch->size[1] = e_Pitch->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)Pitch, i27, (int32_T)
                              sizeof(real_T), &cd_emlrtRTEI);
            itmp = e_Pitch->size[1];
            for (i27 = 0; i27 < itmp; i27++) {
              Pitch->data[Pitch->size[0] * i27] = e_Pitch->data[e_Pitch->size[0]
                * i27];
            }

            emxFree_real_T(&e_Pitch);
            emxInit_real_T(sp, &c_Merit, 2, &cd_emlrtRTEI, true);
            n = Merit->size[1];
            mtmp = numpeaks - (real_T)n;
            if (!(mtmp >= 0.0)) {
              emlrtNonNegativeCheckR2012b(mtmp, &tb_emlrtDCI, sp);
            }

            ixstart = (int32_T)mtmp;
            i27 = c_Merit->size[0] * c_Merit->size[1];
            c_Merit->size[0] = 1;
            c_Merit->size[1] = Merit->size[1] + ixstart;
            emxEnsureCapacity(sp, (emxArray__common *)c_Merit, i27, (int32_T)
                              sizeof(real_T), &cd_emlrtRTEI);
            itmp = Merit->size[1];
            for (i27 = 0; i27 < itmp; i27++) {
              c_Merit->data[c_Merit->size[0] * i27] = Merit->data[Merit->size[0]
                * i27];
            }

            for (i27 = 0; i27 < ixstart; i27++) {
              c_Merit->data[c_Merit->size[0] * (i27 + Merit->size[1])] = 0.0;
            }

            i27 = Merit->size[0] * Merit->size[1];
            Merit->size[0] = 1;
            Merit->size[1] = c_Merit->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)Merit, i27, (int32_T)
                              sizeof(real_T), &cd_emlrtRTEI);
            itmp = c_Merit->size[1];
            for (i27 = 0; i27 < itmp; i27++) {
              Merit->data[Merit->size[0] * i27] = c_Merit->data[c_Merit->size[0]
                * i27];
            }

            emxFree_real_T(&c_Merit);
          }

          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 16);
          i27 = Pitch->size[1];
          if (!(1 <= i27)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i27, &me_emlrtBCI, sp);
          }

          i27 = Pitch->size[1];
          i28 = (int32_T)numpeaks;
          if (!((i28 >= 1) && (i28 <= i27))) {
            emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &xe_emlrtBCI, sp);
          }

          Pitch->data[i28 - 1] = 2.0 * Pitch->data[0];
          i27 = Merit->size[1];
          i28 = (int32_T)numpeaks;
          if (!((i28 >= 1) && (i28 <= i27))) {
            emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &ye_emlrtBCI, sp);
          }

          Merit->data[i28 - 1] = Prm_merit_extra;
        }

        /*  Fill in  frames with less than maxpeaks with best choice */
        if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 10, numpeaks < maxpeaks))
        {
          emxInit_real_T(sp, &r24, 2, &cd_emlrtRTEI, true);
          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 17);
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp >= 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &qb_emlrtDCI, sp);
          }

          ixstart = (int32_T)mtmp;
          b_n = Pitch->size[1];
          i27 = Pitch->size[0] * Pitch->size[1];
          Pitch->size[1] = b_n + ixstart;
          emxEnsureCapacity(sp, (emxArray__common *)Pitch, i27, (int32_T)sizeof
                            (real_T), &cd_emlrtRTEI);
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp >= 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &qb_emlrtDCI, sp);
          }

          n = (int32_T)mtmp;
          i27 = r24->size[0] * r24->size[1];
          r24->size[0] = 1;
          r24->size[1] = n;
          emxEnsureCapacity(sp, (emxArray__common *)r24, i27, (int32_T)sizeof
                            (real_T), &cd_emlrtRTEI);
          for (i27 = 0; i27 < n; i27++) {
            r24->data[r24->size[0] * i27] = 0.0;
          }

          for (i27 = 0; i27 < ixstart; i27++) {
            Pitch->data[b_n + i27] = r24->data[i27];
          }

          emxFree_real_T(&r24);
          emxInit_real_T(sp, &r25, 2, &cd_emlrtRTEI, true);
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp >= 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &rb_emlrtDCI, sp);
          }

          ixstart = (int32_T)mtmp;
          b_n = Merit->size[1];
          i27 = Merit->size[0] * Merit->size[1];
          Merit->size[1] = b_n + ixstart;
          emxEnsureCapacity(sp, (emxArray__common *)Merit, i27, (int32_T)sizeof
                            (real_T), &cd_emlrtRTEI);
          mtmp = maxpeaks - numpeaks;
          if (!(mtmp >= 0.0)) {
            emlrtNonNegativeCheckR2012b(mtmp, &rb_emlrtDCI, sp);
          }

          n = (int32_T)mtmp;
          i27 = r25->size[0] * r25->size[1];
          r25->size[0] = 1;
          r25->size[1] = n;
          emxEnsureCapacity(sp, (emxArray__common *)r25, i27, (int32_T)sizeof
                            (real_T), &cd_emlrtRTEI);
          for (i27 = 0; i27 < n; i27++) {
            r25->data[r25->size[0] * i27] = 0.0;
          }

          for (i27 = 0; i27 < ixstart; i27++) {
            Merit->data[b_n + i27] = r25->data[i27];
          }

          emxFree_real_T(&r25);
          if (numpeaks + 1.0 > maxpeaks) {
            i27 = 0;
            n = 0;
          } else {
            i27 = Pitch->size[1];
            i28 = (int32_T)(numpeaks + 1.0);
            if (!((i28 >= 1) && (i28 <= i27))) {
              emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &ke_emlrtBCI, sp);
            }

            i27 = i28 - 1;
            i28 = Pitch->size[1];
            n = (int32_T)maxpeaks;
            if (!((n >= 1) && (n <= i28))) {
              emlrtDynamicBoundsCheckR2012b(n, 1, i28, &ke_emlrtBCI, sp);
            }
          }

          emxInit_int32_T(sp, &r26, 2, &cd_emlrtRTEI, true);
          i28 = r26->size[0] * r26->size[1];
          r26->size[0] = 1;
          r26->size[1] = n - i27;
          emxEnsureCapacity(sp, (emxArray__common *)r26, i28, (int32_T)sizeof
                            (int32_T), &cd_emlrtRTEI);
          itmp = n - i27;
          for (i28 = 0; i28 < itmp; i28++) {
            r26->data[r26->size[0] * i28] = i27 + i28;
          }

          i27 = Pitch->size[1];
          if (!(1 <= i27)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i27, &le_emlrtBCI, sp);
          }

          mtmp = Pitch->data[0];
          itmp = r26->size[0] * r26->size[1];
          for (i27 = 0; i27 < itmp; i27++) {
            Pitch->data[r26->data[i27]] = mtmp;
          }

          if (numpeaks + 1.0 > maxpeaks) {
            i27 = 0;
            n = 0;
          } else {
            i27 = Merit->size[1];
            i28 = (int32_T)(numpeaks + 1.0);
            if (!((i28 >= 1) && (i28 <= i27))) {
              emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &ie_emlrtBCI, sp);
            }

            i27 = i28 - 1;
            i28 = Merit->size[1];
            n = (int32_T)maxpeaks;
            if (!((n >= 1) && (n <= i28))) {
              emlrtDynamicBoundsCheckR2012b(n, 1, i28, &ie_emlrtBCI, sp);
            }
          }

          i28 = r26->size[0] * r26->size[1];
          r26->size[0] = 1;
          r26->size[1] = n - i27;
          emxEnsureCapacity(sp, (emxArray__common *)r26, i28, (int32_T)sizeof
                            (int32_T), &cd_emlrtRTEI);
          itmp = n - i27;
          for (i28 = 0; i28 < itmp; i28++) {
            r26->data[r26->size[0] * i28] = i27 + i28;
          }

          i27 = Merit->size[1];
          if (!(1 <= i27)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i27, &je_emlrtBCI, sp);
          }

          mtmp = Merit->data[0];
          itmp = r26->size[0] * r26->size[1];
          for (i27 = 0; i27 < itmp; i27++) {
            Merit->data[r26->data[i27]] = mtmp;
          }

          emxFree_int32_T(&r26);
        }
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 18);
        i27 = Pitch->size[0] * Pitch->size[1];
        Pitch->size[0] = 1;
        Pitch->size[1] = (int32_T)maxpeaks;
        emxEnsureCapacity(sp, (emxArray__common *)Pitch, i27, (int32_T)sizeof
                          (real_T), &cd_emlrtRTEI);
        itmp = (int32_T)maxpeaks;
        for (i27 = 0; i27 < itmp; i27++) {
          Pitch->data[i27] = 0.0;
        }

        i27 = Merit->size[0] * Merit->size[1];
        Merit->size[0] = 1;
        Merit->size[1] = (int32_T)maxpeaks;
        emxEnsureCapacity(sp, (emxArray__common *)Merit, i27, (int32_T)sizeof
                          (real_T), &cd_emlrtRTEI);
        itmp = (int32_T)maxpeaks;
        for (i27 = 0; i27 < itmp; i27++) {
          Merit->data[i27] = 1.0;
        }
      }
    }
  }

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (peaks.c) */
