/*
 * cmp_rate.c
 *
 * Code generation for function 'cmp_rate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cmp_rate.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sl_emlrtRSI = { 69, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRSInfo tl_emlrtRSI = { 93, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRSInfo ul_emlrtRSI = { 115, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo be_emlrtRTEI = { 1, 27, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtBCInfo li_emlrtBCI = { 1, 20, 73, 9, "Pitch", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

static emlrtBCInfo mi_emlrtBCI = { -1, -1, 69, 21, "Phi", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

static emlrtDCInfo hc_emlrtDCI = { 69, 21, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtRTEInfo og_emlrtRTEI = { 68, 1, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtDCInfo ic_emlrtDCI = { 108, 33, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 4 };

static emlrtDCInfo jc_emlrtDCI = { 107, 28, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 4 };

static emlrtBCInfo ni_emlrtBCI = { 1, 20, 94, 9, "Pitch", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

/* Function Definitions */
void cmp_rate(const emlrtStack *sp, const emxArray_real_T *Phi, real_T Fs,
              real_T maxcands, real_T lag_min, real_T lag_max, real_T
              Prm_nccf_thresh1, real_T Prm_nccf_thresh2, real_T Prm_nccf_pwidth,
              emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  real_T center;
  real_T numpeaks;
  real_T b_Pitch[20];
  real_T b_Merit[20];
  real_T d1;
  int32_T i47;
  int32_T n;
  int32_T exitg2;
  real_T b_n;
  real_T mtmp;
  int32_T i48;
  int32_T i49;
  int32_T iidx[20];
  int32_T ixstart;
  real_T c_Pitch[20];
  boolean_T overflow;
  int32_T c_n;
  int32_T itmp;
  boolean_T guard1 = false;
  int32_T ix;
  boolean_T exitg3;
  emxArray_real_T *r35;
  boolean_T exitg1;
  emxArray_real_T *b;
  emxArray_real_T *r36;
  emxArray_real_T *r37;
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
  covrtLogFcn(&emlrtCoverageInstance, 18U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 0);

  /*  CMP_RATE compute rate and merit from the autocorrelation sequence */
  /*  */
  /*  [Pitch, Merit] = cmp_rate(Phi,Fs,maxcands,lag_min,lag_max,Prm); */
  /*   This routine computes Pitch estimates and the corresponding Merit values  */
  /*   associated with the peaks found in each frame based on the correlation sequence. */
  /*  */
  /*   INPUTS: */
  /*    Phi     : The input signal(either auto correlated/normalized cross correlated). */
  /*    Fs      : The sampling frequency. */
  /*    lag_min : The lowest lag(== 1/F0_max) involved in the F0 estimation. */
  /*    F0_max  : The highest lag(== 1/F0_min)  involved in the F0 estimation. */
  /*              greater than the peak at F0 during the first pass of search. */
  /*    maxcands: The maximum number of top candidates to be considered. */
  /*  */
  /*   OUTPUTS: */
  /*     Pitch  : The Rate/Pitch values for the peaks found for each frame. */
  /*     Merit  : The Merit values of the peaks found in each frame. */
  /*   Creation date:   2002 */
  /*   Revision dates:   March 26, 2002, December 24, 2005 */
  /*   Programmer: S.A.Zahorian,Kasi Kavita */
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
  /* Width of the window used in first pass of peak picking. */
  /*  The center of the window is defined as the peak location. */
  center = muDoubleScalarRound(Prm_nccf_pwidth / 2.0);

  /*  The threshold value used for the first pass of */
  /*  peak picking for each frame.any peaks found greater than this */
  /*  are chosen in the first pass. */
  /*   The threshold value used to limit peak searching. */
  /*   If a peak is found at least this great, no further  searching is */
  /*   done increased from prev. value of 0.85. */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  numpeaks = 0.0;

  /*  Pitch     = zeros(1, maxcands); */
  /*  Merit     = zeros(1, maxcands); */
  memset(&b_Pitch[0], 0, 20U * sizeof(real_T));
  memset(&b_Merit[0], 0, 20U * sizeof(real_T));

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  d1 = lag_min - center;
  i47 = (int32_T)(lag_max + (1.0 - d1));
  emlrtForLoopVectorCheckR2012b(d1, 1.0, lag_max, mxDOUBLE_CLASS, i47,
    &og_emlrtRTEI, sp);
  n = 0;
  do {
    exitg2 = 0;
    if (n <= i47 - 1) {
      b_n = d1 + (real_T)n;
      covrtLogFor(&emlrtCoverageInstance, 18U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 1);
      mtmp = (b_n + Prm_nccf_pwidth) - 1.0;
      if (b_n > mtmp) {
        i48 = 0;
        i49 = 0;
      } else {
        i48 = Phi->size[1];
        if (b_n != (int32_T)muDoubleScalarFloor(b_n)) {
          emlrtIntegerCheckR2012b(b_n, &hc_emlrtDCI, sp);
        }

        ixstart = (int32_T)b_n;
        if (!((ixstart >= 1) && (ixstart <= i48))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, i48, &mi_emlrtBCI, sp);
        }

        i48 = ixstart - 1;
        ixstart = Phi->size[1];
        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &hc_emlrtDCI, sp);
        }

        i49 = (int32_T)mtmp;
        if (!((i49 >= 1) && (i49 <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(i49, 1, ixstart, &mi_emlrtBCI, sp);
        }
      }

      st.site = &sl_emlrtRSI;
      b_st.site = &ij_emlrtRSI;
      c_st.site = &jj_emlrtRSI;
      if ((i49 - i48 == 1) || (i49 - i48 != 1)) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (i49 - i48 > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &vf_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &mi_emlrtRSI;
      ixstart = 2;
      c_n = i49 - i48;
      mtmp = Phi->data[i48];
      itmp = 1;
      if (i49 - i48 > 1) {
        if (muDoubleScalarIsNaN(mtmp)) {
          e_st.site = &oi_emlrtRSI;
          if ((!(2 > i49 - i48)) && (i49 - i48 > 2147483646)) {
            f_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          ix = 2;
          exitg3 = false;
          while ((!exitg3) && (ix <= c_n)) {
            ixstart = ix + 1;
            if (!muDoubleScalarIsNaN(Phi->data[(i48 + ix) - 1])) {
              mtmp = Phi->data[(i48 + ix) - 1];
              itmp = ix;
              exitg3 = true;
            } else {
              ix++;
            }
          }
        }

        if (ixstart - 1 < i49 - i48) {
          e_st.site = &ni_emlrtRSI;
          if ((!(ixstart > i49 - i48)) && (i49 - i48 > 2147483646)) {
            f_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while (ixstart <= c_n) {
            if (Phi->data[(i48 + ixstart) - 1] > mtmp) {
              mtmp = Phi->data[(i48 + ixstart) - 1];
              itmp = ixstart;
            }

            ixstart++;
          }
        }
      }

      guard1 = false;
      if (covrtLogCond(&emlrtCoverageInstance, 18U, 0U, 0, itmp == center) &&
          covrtLogCond(&emlrtCoverageInstance, 18U, 0U, 1, mtmp >
                       Prm_nccf_thresh1)) {
        covrtLogMcdc(&emlrtCoverageInstance, 18U, 0U, 0, true);
        covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 0, true);
        covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 2);
        numpeaks++;
        i48 = (int32_T)numpeaks;
        if (!((i48 >= 1) && (i48 <= 20))) {
          emlrtDynamicBoundsCheckR2012b(i48, 1, 20, &li_emlrtBCI, sp);
        }

        b_Pitch[i48 - 1] = Fs / ((b_n + (real_T)itmp) - 1.0);
        b_Merit[(int32_T)numpeaks - 1] = mtmp;

        /*          if(numpeaks > length(Pitch)) */
        /*              tempPitch = [tempPitch Fs/(n+lag-1)]; */
        /*              tempMerit = [Merit y]; */
        /*              Pitch = tempPitch; */
        /*              Merit = tempMerit; */
        /*          else */
        /*              Pitch(numpeaks) = Fs/(n+lag-1); */
        /*              Merit(numpeaks) = y; */
        /*          end */
        if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 1, mtmp >
                       Prm_nccf_thresh2)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 3);
          exitg2 = 1;
        } else {
          guard1 = true;
        }
      } else {
        covrtLogMcdc(&emlrtCoverageInstance, 18U, 0U, 0, false);
        covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 0, false);
        guard1 = true;
      }

      if (guard1) {
        n++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else {
      covrtLogFor(&emlrtCoverageInstance, 18U, 0U, 0, 0);
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 4);

  /*  consider the case when the number of peaks are more than the maxcands. */
  /*  Then take only the best maxcands peaks based on the Merit values . */
  st.site = &tl_emlrtRSI;
  b_st.site = &kj_emlrtRSI;
  c_sort(&b_st, b_Merit, iidx);
  for (i47 = 0; i47 < 20; i47++) {
    if (!((iidx[i47] >= 1) && (iidx[i47] <= 20))) {
      emlrtDynamicBoundsCheckR2012b(iidx[i47], 1, 20, &ni_emlrtBCI, sp);
    }

    c_Pitch[i47] = b_Pitch[iidx[i47] - 1];
  }

  memcpy(&b_Pitch[0], &c_Pitch[0], 20U * sizeof(real_T));
  numpeaks = muDoubleScalarMin(numpeaks, maxcands);
  if (1.0 > numpeaks) {
    ixstart = 0;
  } else {
    ixstart = (int32_T)numpeaks;
  }

  i47 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 1;
  Merit->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i47, (int32_T)sizeof(real_T),
                    &be_emlrtRTEI);
  for (i47 = 0; i47 < ixstart; i47++) {
    Merit->data[Merit->size[0] * i47] = b_Merit[i47];
  }

  if (1.0 > numpeaks) {
    ixstart = 0;
  } else {
    ixstart = (int32_T)numpeaks;
  }

  i47 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 1;
  Pitch->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i47, (int32_T)sizeof(real_T),
                    &be_emlrtRTEI);
  for (i47 = 0; i47 < ixstart; i47++) {
    Pitch->data[Pitch->size[0] * i47] = b_Pitch[i47];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 2, numpeaks < maxcands)) {
    if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 3, ixstart == 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 5);
      i47 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = (int32_T)maxcands;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i47, (int32_T)sizeof
                        (real_T), &be_emlrtRTEI);
      ixstart = (int32_T)maxcands;
      for (i47 = 0; i47 < ixstart; i47++) {
        Pitch->data[i47] = 0.0;
      }

      i47 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = (int32_T)maxcands;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i47, (int32_T)sizeof
                        (real_T), &be_emlrtRTEI);
      ixstart = (int32_T)maxcands;
      for (i47 = 0; i47 < ixstart; i47++) {
        Merit->data[i47] = 0.001;
      }
    } else {
      emxInit_real_T(sp, &r35, 2, &be_emlrtRTEI, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 6);
      d1 = maxcands - numpeaks;
      if (!(d1 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(d1, &jc_emlrtDCI, sp);
      }

      c_n = (int32_T)d1;
      itmp = Pitch->size[1];
      i47 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[1] = itmp + c_n;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i47, (int32_T)sizeof
                        (real_T), &be_emlrtRTEI);
      d1 = maxcands - numpeaks;
      if (!(d1 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(d1, &jc_emlrtDCI, sp);
      }

      ixstart = (int32_T)d1;
      i47 = r35->size[0] * r35->size[1];
      r35->size[0] = 1;
      r35->size[1] = ixstart;
      emxEnsureCapacity(sp, (emxArray__common *)r35, i47, (int32_T)sizeof(real_T),
                        &be_emlrtRTEI);
      for (i47 = 0; i47 < ixstart; i47++) {
        r35->data[r35->size[0] * i47] = 0.0;
      }

      for (i47 = 0; i47 < c_n; i47++) {
        Pitch->data[itmp + i47] = r35->data[i47];
      }

      emxFree_real_T(&r35);
      emxInit_real_T(sp, &b, 2, &be_emlrtRTEI, true);
      i47 = b->size[0] * b->size[1];
      b->size[0] = 1;
      d1 = maxcands - numpeaks;
      if (!(d1 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(d1, &ic_emlrtDCI, sp);
      }

      b->size[1] = (int32_T)d1;
      emxEnsureCapacity(sp, (emxArray__common *)b, i47, (int32_T)sizeof(real_T),
                        &be_emlrtRTEI);
      d1 = maxcands - numpeaks;
      if (!(d1 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(d1, &ic_emlrtDCI, sp);
      }

      ixstart = (int32_T)d1;
      for (i47 = 0; i47 < ixstart; i47++) {
        b->data[i47] = 1.0;
      }

      emxInit_real_T(sp, &r36, 2, &be_emlrtRTEI, true);
      i47 = r36->size[0] * r36->size[1];
      r36->size[0] = 1;
      r36->size[1] = b->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r36, i47, (int32_T)sizeof(real_T),
                        &be_emlrtRTEI);
      ixstart = b->size[0] * b->size[1];
      for (i47 = 0; i47 < ixstart; i47++) {
        r36->data[i47] = 0.001 * b->data[i47];
      }

      emxInit_real_T(sp, &r37, 2, &be_emlrtRTEI, true);
      itmp = Merit->size[1];
      c_n = r36->size[1];
      i47 = Merit->size[0] * Merit->size[1];
      Merit->size[1] = itmp + c_n;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i47, (int32_T)sizeof
                        (real_T), &be_emlrtRTEI);
      i47 = r37->size[0] * r37->size[1];
      r37->size[0] = 1;
      r37->size[1] = b->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r37, i47, (int32_T)sizeof(real_T),
                        &be_emlrtRTEI);
      ixstart = b->size[1];
      emxFree_real_T(&r36);
      for (i47 = 0; i47 < ixstart; i47++) {
        r37->data[r37->size[0] * i47] = 0.001 * b->data[b->size[0] * i47];
      }

      emxFree_real_T(&b);
      for (i47 = 0; i47 < c_n; i47++) {
        Merit->data[itmp + i47] = r37->data[i47];
      }

      emxFree_real_T(&r37);

      /*      Pitch(numpeaks+1:maxcands) = 0; */
      /*      Merit(numpeaks+1:maxcands) = 0.001; */
    }
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 7);

  /*  Normlize merits */
  st.site = &ul_emlrtRSI;
  b_st.site = &ki_emlrtRSI;
  c_st.site = &li_emlrtRSI;
  if ((Merit->size[1] == 1) || (Merit->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (Merit->size[1] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &vf_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &mi_emlrtRSI;
  ixstart = 1;
  n = Merit->size[1];
  mtmp = Merit->data[0];
  if (Merit->size[1] > 1) {
    if (muDoubleScalarIsNaN(Merit->data[0])) {
      e_st.site = &oi_emlrtRSI;
      overflow = (Merit->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(Merit->data[ix - 1])) {
          mtmp = Merit->data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < Merit->size[1]) {
      e_st.site = &ni_emlrtRSI;
      overflow = ((!(ixstart + 1 > Merit->size[1])) && (Merit->size[1] >
        2147483646));
      if (overflow) {
        f_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (ixstart + 1 <= n) {
        if (Merit->data[ixstart] > mtmp) {
          mtmp = Merit->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 4, mtmp > 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 8);
    i47 = Merit->size[0] * Merit->size[1];
    Merit->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)Merit, i47, (int32_T)sizeof(real_T),
                      &be_emlrtRTEI);
    ixstart = Merit->size[0];
    c_n = Merit->size[1];
    ixstart *= c_n;
    for (i47 = 0; i47 < ixstart; i47++) {
      Merit->data[i47] /= mtmp;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (cmp_rate.c) */
