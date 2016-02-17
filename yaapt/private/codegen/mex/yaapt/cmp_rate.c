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
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo km_emlrtRSI = { 69, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRSInfo lm_emlrtRSI = { 93, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRSInfo mm_emlrtRSI = { 115, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo ee_emlrtRTEI = { 1, 27, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo ug_emlrtRTEI = { 68, 1, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtDCInfo id_emlrtDCI = { 69, 21, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtBCInfo xi_emlrtBCI = { -1, -1, 69, 21, "Phi", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

static emlrtBCInfo yi_emlrtBCI = { 1, 20, 73, 9, "Pitch", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

static emlrtDCInfo jd_emlrtDCI = { 96, 9, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtDCInfo kd_emlrtDCI = { 97, 10, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtDCInfo ld_emlrtDCI = { 104, 23, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 4 };

static emlrtDCInfo md_emlrtDCI = { 104, 23, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtDCInfo nd_emlrtDCI = { 108, 33, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 4 };

static emlrtDCInfo od_emlrtDCI = { 108, 33, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtDCInfo pd_emlrtDCI = { 107, 28, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtDCInfo qd_emlrtDCI = { 107, 28, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 4 };

static emlrtBCInfo aj_emlrtBCI = { 1, 20, 94, 9, "Pitch", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

/* Function Definitions */

/*
 * function [Pitch, Merit] = cmp_rate(Phi, Fs, maxcands, lag_min, lag_max,Prm)
 */
void cmp_rate(const emlrtStack *sp, const emxArray_real_T *Phi, real_T Fs,
              real_T maxcands, real_T lag_min, real_T lag_max, real_T
              Prm_nccf_thresh1, real_T Prm_nccf_thresh2, real_T Prm_nccf_pwidth,
              emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  real_T center;
  real_T numpeaks;
  real_T b_Pitch[20];
  real_T b_Merit[20];
  int32_T i45;
  real_T d3;
  int32_T n;
  boolean_T exitg2;
  real_T b_n;
  real_T mtmp;
  int32_T i46;
  int32_T i47;
  int32_T ixstart;
  boolean_T overflow;
  int32_T c_n;
  int32_T itmp;
  boolean_T b22;
  int32_T ix;
  boolean_T exitg3;
  boolean_T b_ixstart;
  boolean_T guard1 = false;
  int32_T iidx[20];
  real_T c_Pitch[20];
  emxArray_real_T *r42;
  emxArray_real_T *b;
  emxArray_real_T *r43;
  emxArray_real_T *r44;
  boolean_T exitg1;
  emxArray_real_T *c_Merit;
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
  /* 'cmp_rate:38' width = Prm.nccf_pwidth; */
  /*  The center of the window is defined as the peak location. */
  /* 'cmp_rate:40' center = round(width/2); */
  center = muDoubleScalarRound(Prm_nccf_pwidth / 2.0);

  /*  The threshold value used for the first pass of */
  /*  peak picking for each frame.any peaks found greater than this */
  /*  are chosen in the first pass. */
  /* 'cmp_rate:46' Merit_thresh1 = Prm.nccf_thresh1; */
  /*   The threshold value used to limit peak searching. */
  /*   If a peak is found at least this great, no further  searching is */
  /*   done increased from prev. value of 0.85. */
  /* 'cmp_rate:51' Merit_thresh2 = Prm.nccf_thresh2; */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'cmp_rate:54' numpeaks  = 0; */
  numpeaks = 0.0;

  /*  Pitch     = zeros(1, maxcands); */
  /*  Merit     = zeros(1, maxcands); */
  /* 'cmp_rate:57' Pitch     = zeros(1, 20); */
  /* 'cmp_rate:58' Merit     = zeros(1, 20); */
  for (i45 = 0; i45 < 20; i45++) {
    b_Pitch[i45] = 0.0;
    b_Merit[i45] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  /* 'cmp_rate:68' for n = lag_min-center:lag_max */
  d3 = lag_min - center;
  i45 = (int32_T)(lag_max + (1.0 - d3));
  emlrtForLoopVectorCheckR2012b(d3, 1.0, lag_max, mxDOUBLE_CLASS, i45,
    &ug_emlrtRTEI, sp);
  n = 0;
  exitg2 = false;
  while ((!exitg2) && (n <= i45 - 1)) {
    b_n = d3 + (real_T)n;

    /* 'cmp_rate:69' [y, lag]  = max(Phi(n:n+width-1)); */
    mtmp = (b_n + Prm_nccf_pwidth) - 1.0;
    if (b_n > mtmp) {
      i46 = 1;
      i47 = 1;
    } else {
      if (b_n != (int32_T)muDoubleScalarFloor(b_n)) {
        emlrtIntegerCheckR2012b(b_n, &id_emlrtDCI, sp);
      }

      i47 = Phi->size[1];
      i46 = (int32_T)b_n;
      if (!((i46 >= 1) && (i46 <= i47))) {
        emlrtDynamicBoundsCheckR2012b(i46, 1, i47, &xi_emlrtBCI, sp);
      }

      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
        emlrtIntegerCheckR2012b(mtmp, &id_emlrtDCI, sp);
      }

      i47 = Phi->size[1];
      ixstart = (int32_T)mtmp;
      if (!((ixstart >= 1) && (ixstart <= i47))) {
        emlrtDynamicBoundsCheckR2012b(ixstart, 1, i47, &xi_emlrtBCI, sp);
      }

      i47 = ixstart + 1;
    }

    st.site = &km_emlrtRSI;
    b_st.site = &yi_emlrtRSI;
    c_st.site = &aj_emlrtRSI;
    if ((i47 - i46 == 1) || (i47 - i46 != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (i47 - i46 > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &xf_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &hb_emlrtRSI;
    ixstart = 2;
    c_n = i47 - i46;
    mtmp = Phi->data[i46 - 1];
    itmp = 1;
    if (i47 - i46 > 1) {
      if (muDoubleScalarIsNaN(mtmp)) {
        e_st.site = &ib_emlrtRSI;
        if (2 > i47 - i46) {
          b22 = false;
        } else {
          b22 = (i47 - i46 > 2147483646);
        }

        if (b22) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix <= c_n)) {
          ixstart = ix + 1;
          if (!muDoubleScalarIsNaN(Phi->data[(i46 + ix) - 2])) {
            mtmp = Phi->data[(i46 + ix) - 2];
            itmp = ix;
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart - 1 < i47 - i46) {
        e_st.site = &jb_emlrtRSI;
        if (ixstart > i47 - i46) {
          b_ixstart = false;
        } else {
          b_ixstart = (i47 - i46 > 2147483646);
        }

        if (b_ixstart) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        while (ixstart <= c_n) {
          if (Phi->data[(i46 + ixstart) - 2] > mtmp) {
            mtmp = Phi->data[(i46 + ixstart) - 2];
            itmp = ixstart;
          }

          ixstart++;
        }
      }
    }

    /* 'cmp_rate:70' if (lag == center) && (y > Merit_thresh1) */
    guard1 = false;
    if ((itmp == center) && (mtmp > Prm_nccf_thresh1)) {
      /* 'cmp_rate:72' numpeaks = numpeaks + 1; */
      numpeaks++;

      /* 'cmp_rate:73' Pitch(numpeaks) = Fs/(n+lag-1); */
      i47 = (int32_T)numpeaks;
      if (!((i47 >= 1) && (i47 <= 20))) {
        emlrtDynamicBoundsCheckR2012b(i47, 1, 20, &yi_emlrtBCI, sp);
      }

      b_Pitch[i47 - 1] = Fs / ((b_n + (real_T)itmp) - 1.0);

      /* 'cmp_rate:74' Merit(numpeaks) = y; */
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
      /* 'cmp_rate:85' if (y > Merit_thresh2) */
      if (mtmp > Prm_nccf_thresh2) {
        exitg2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      n++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  /*  consider the case when the number of peaks are more than the maxcands. */
  /*  Then take only the best maxcands peaks based on the Merit values . */
  /* 'cmp_rate:93' [Merit,Idx]=sort(Merit, 'descend'); */
  st.site = &lm_emlrtRSI;
  b_st.site = &bj_emlrtRSI;
  c_sort(&b_st, b_Merit, iidx);

  /* 'cmp_rate:94' Pitch = Pitch(Idx); */
  for (i45 = 0; i45 < 20; i45++) {
    if (!((iidx[i45] >= 1) && (iidx[i45] <= 20))) {
      emlrtDynamicBoundsCheckR2012b(iidx[i45], 1, 20, &aj_emlrtBCI, sp);
    }

    c_Pitch[i45] = b_Pitch[iidx[i45] - 1];
  }

  memcpy(&b_Pitch[0], &c_Pitch[0], 20U * sizeof(real_T));

  /* 'cmp_rate:95' numpeaks = min(numpeaks, maxcands); */
  numpeaks = muDoubleScalarMin(numpeaks, maxcands);

  /* 'cmp_rate:96' Merit = Merit(1:numpeaks); */
  if (1.0 > numpeaks) {
    ixstart = 0;
  } else {
    if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
      emlrtIntegerCheckR2012b(numpeaks, &jd_emlrtDCI, sp);
    }

    ixstart = (int32_T)numpeaks;
  }

  i45 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 1;
  Merit->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i45, (int32_T)sizeof(real_T),
                    &ee_emlrtRTEI);
  for (i45 = 0; i45 < ixstart; i45++) {
    Merit->data[Merit->size[0] * i45] = b_Merit[i45];
  }

  /* 'cmp_rate:97' Pitch  = Pitch(1:numpeaks); */
  if (1.0 > numpeaks) {
    ixstart = 0;
  } else {
    if (numpeaks != (int32_T)muDoubleScalarFloor(numpeaks)) {
      emlrtIntegerCheckR2012b(numpeaks, &kd_emlrtDCI, sp);
    }

    ixstart = (int32_T)numpeaks;
  }

  i45 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 1;
  Pitch->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i45, (int32_T)sizeof(real_T),
                    &ee_emlrtRTEI);
  for (i45 = 0; i45 < ixstart; i45++) {
    Pitch->data[Pitch->size[0] * i45] = b_Pitch[i45];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  /* 'cmp_rate:102' if (numpeaks < maxcands) */
  if (numpeaks < maxcands) {
    /* 'cmp_rate:103' if(isempty(Pitch)) */
    if (ixstart == 0) {
      /* 'cmp_rate:104' Pitch=zeros(1,maxcands); */
      i45 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      if (!(maxcands > 0.0)) {
        emlrtNonNegativeCheckR2012b(maxcands, &ld_emlrtDCI, sp);
      }

      if (maxcands != (int32_T)muDoubleScalarFloor(maxcands)) {
        emlrtIntegerCheckR2012b(maxcands, &md_emlrtDCI, sp);
      }

      Pitch->size[1] = (int32_T)maxcands;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i45, (int32_T)sizeof
                        (real_T), &ee_emlrtRTEI);
      if (!(maxcands > 0.0)) {
        emlrtNonNegativeCheckR2012b(maxcands, &ld_emlrtDCI, sp);
      }

      d3 = maxcands;
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, &md_emlrtDCI, sp);
      }

      ixstart = (int32_T)d3;
      for (i45 = 0; i45 < ixstart; i45++) {
        Pitch->data[i45] = 0.0;
      }

      /* 'cmp_rate:105' Merit=0.001*ones(1,maxcands); */
      i45 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = (int32_T)maxcands;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i45, (int32_T)sizeof
                        (real_T), &ee_emlrtRTEI);
      ixstart = (int32_T)maxcands;
      for (i45 = 0; i45 < ixstart; i45++) {
        Merit->data[i45] = 0.001;
      }
    } else {
      emxInit_real_T(sp, &r42, 2, &ee_emlrtRTEI, true);

      /* 'cmp_rate:106' else */
      /* 'cmp_rate:107' Pitch = [Pitch zeros(1,maxcands-numpeaks)]; */
      d3 = maxcands - numpeaks;
      if (!(d3 > 0.0)) {
        emlrtNonNegativeCheckR2012b(d3, &qd_emlrtDCI, sp);
      }

      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, &pd_emlrtDCI, sp);
      }

      ixstart = (int32_T)d3;
      itmp = Pitch->size[1];
      i45 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[1] = itmp + ixstart;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i45, (int32_T)sizeof
                        (real_T), &ee_emlrtRTEI);
      d3 = maxcands - numpeaks;
      if (!(d3 > 0.0)) {
        emlrtNonNegativeCheckR2012b(d3, &qd_emlrtDCI, sp);
      }

      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, &pd_emlrtDCI, sp);
      }

      c_n = (int32_T)d3;
      i45 = r42->size[0] * r42->size[1];
      r42->size[0] = 1;
      r42->size[1] = c_n;
      emxEnsureCapacity(sp, (emxArray__common *)r42, i45, (int32_T)sizeof(real_T),
                        &ee_emlrtRTEI);
      for (i45 = 0; i45 < c_n; i45++) {
        r42->data[r42->size[0] * i45] = 0.0;
      }

      for (i45 = 0; i45 < ixstart; i45++) {
        Pitch->data[itmp + i45] = r42->data[i45];
      }

      emxFree_real_T(&r42);
      emxInit_real_T(sp, &b, 2, &ee_emlrtRTEI, true);

      /* 'cmp_rate:108' Merit = [Merit 0.001*ones(1,maxcands-numpeaks)]; */
      i45 = b->size[0] * b->size[1];
      b->size[0] = 1;
      d3 = maxcands - numpeaks;
      if (!(d3 > 0.0)) {
        emlrtNonNegativeCheckR2012b(d3, &nd_emlrtDCI, sp);
      }

      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, &od_emlrtDCI, sp);
      }

      b->size[1] = (int32_T)d3;
      emxEnsureCapacity(sp, (emxArray__common *)b, i45, (int32_T)sizeof(real_T),
                        &ee_emlrtRTEI);
      d3 = maxcands - numpeaks;
      if (!(d3 > 0.0)) {
        emlrtNonNegativeCheckR2012b(d3, &nd_emlrtDCI, sp);
      }

      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, &od_emlrtDCI, sp);
      }

      ixstart = (int32_T)d3;
      for (i45 = 0; i45 < ixstart; i45++) {
        b->data[i45] = 1.0;
      }

      emxInit_real_T(sp, &r43, 2, &ee_emlrtRTEI, true);
      i45 = r43->size[0] * r43->size[1];
      r43->size[0] = 1;
      r43->size[1] = b->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r43, i45, (int32_T)sizeof(real_T),
                        &ee_emlrtRTEI);
      ixstart = b->size[0] * b->size[1];
      for (i45 = 0; i45 < ixstart; i45++) {
        r43->data[i45] = 0.001 * b->data[i45];
      }

      emxInit_real_T(sp, &r44, 2, &ee_emlrtRTEI, true);
      itmp = Merit->size[1];
      c_n = r43->size[1];
      i45 = Merit->size[0] * Merit->size[1];
      Merit->size[1] = itmp + c_n;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i45, (int32_T)sizeof
                        (real_T), &ee_emlrtRTEI);
      i45 = r44->size[0] * r44->size[1];
      r44->size[0] = 1;
      r44->size[1] = b->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r44, i45, (int32_T)sizeof(real_T),
                        &ee_emlrtRTEI);
      ixstart = b->size[1];
      emxFree_real_T(&r43);
      for (i45 = 0; i45 < ixstart; i45++) {
        r44->data[r44->size[0] * i45] = 0.001 * b->data[b->size[0] * i45];
      }

      emxFree_real_T(&b);
      for (i45 = 0; i45 < c_n; i45++) {
        Merit->data[itmp + i45] = r44->data[i45];
      }

      emxFree_real_T(&r44);

      /*      Pitch(numpeaks+1:maxcands) = 0; */
      /*      Merit(numpeaks+1:maxcands) = 0.001; */
    }
  }

  /*  Normlize merits */
  /* 'cmp_rate:115' Max_Merit = max(Merit); */
  st.site = &mm_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&c_st, &xf_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &hb_emlrtRSI;
  ixstart = 1;
  n = Merit->size[1];
  mtmp = Merit->data[0];
  if (Merit->size[1] > 1) {
    if (muDoubleScalarIsNaN(Merit->data[0])) {
      e_st.site = &ib_emlrtRSI;
      overflow = (Merit->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
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
      e_st.site = &jb_emlrtRSI;
      if (ixstart + 1 > Merit->size[1]) {
        overflow = false;
      } else {
        overflow = (Merit->size[1] > 2147483646);
      }

      if (overflow) {
        f_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      while (ixstart + 1 <= n) {
        if (Merit->data[ixstart] > mtmp) {
          mtmp = Merit->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  /* 'cmp_rate:116' if (Max_Merit > 1.0) */
  if (mtmp > 1.0) {
    emxInit_real_T(sp, &c_Merit, 2, &ee_emlrtRTEI, true);

    /* 'cmp_rate:117' Merit = Merit/Max_Merit; */
    i45 = c_Merit->size[0] * c_Merit->size[1];
    c_Merit->size[0] = 1;
    c_Merit->size[1] = Merit->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)c_Merit, i45, (int32_T)sizeof
                      (real_T), &ee_emlrtRTEI);
    ixstart = Merit->size[0] * Merit->size[1];
    for (i45 = 0; i45 < ixstart; i45++) {
      c_Merit->data[i45] = Merit->data[i45];
    }

    c_rdivide(sp, c_Merit, mtmp, Merit);
    emxFree_real_T(&c_Merit);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (cmp_rate.c) */
