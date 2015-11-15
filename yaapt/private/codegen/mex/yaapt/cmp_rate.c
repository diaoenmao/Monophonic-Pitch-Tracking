/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo bj_emlrtRSI = { 68, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRSInfo cj_emlrtRSI = { 104, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo yc_emlrtRTEI = { 1, 27, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo bf_emlrtRTEI = { 67, 1, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtDCInfo mb_emlrtDCI = { 68, 21, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 68, 21, "Phi", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { 1, 3, 72, 9, "Pitch", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

/* Function Definitions */

/*
 * function [Pitch, Merit] = cmp_rate(Phi, Fs, maxcands, lag_min, lag_max,Prm)
 */
void cmp_rate(const emlrtStack *sp, const emxArray_real_T *Phi, real_T Fs,
              real_T lag_min, real_T lag_max, real_T Pitch_data[], int32_T
              Pitch_size[2], real_T Merit_data[], int32_T Merit_size[2])
{
  int32_T numpeaks;
  real_T Pitch[3];
  real_T Merit[3];
  int32_T i33;
  int32_T n;
  boolean_T exitg2;
  real_T b_n;
  int32_T i34;
  int32_T i35;
  int32_T ixstart;
  boolean_T b14;
  int32_T c_n;
  real_T mtmp;
  int32_T itmp;
  boolean_T b15;
  int32_T ix;
  boolean_T exitg3;
  boolean_T b_ixstart;
  boolean_T guard1 = false;
  int32_T iidx[3];
  real_T b_Pitch[3];
  emxArray_real_T *r18;
  emxArray_real_T *r19;
  boolean_T exitg1;
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
  numpeaks = 0;

  /* 'cmp_rate:55' Pitch     = zeros(1, maxcands); */
  /* 'cmp_rate:56' Merit     = zeros(1, maxcands); */
  for (i33 = 0; i33 < 3; i33++) {
    Pitch[i33] = 0.0;
    Merit[i33] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  /* 'cmp_rate:67' for n = lag_min-center:lag_max */
  i33 = (int32_T)(lag_max + (1.0 - (lag_min - 3.0)));
  emlrtForLoopVectorCheckR2012b(lag_min - 3.0, 1.0, lag_max, mxDOUBLE_CLASS, i33,
    &bf_emlrtRTEI, sp);
  n = 0;
  exitg2 = false;
  while ((!exitg2) && (n <= i33 - 1)) {
    b_n = (lag_min - 3.0) + (real_T)n;

    /* 'cmp_rate:68' [y, lag]  = max(Phi(n:n+width-1)); */
    if (b_n > (b_n + 5.0) - 1.0) {
      i34 = 1;
      i35 = 1;
    } else {
      if (b_n != (int32_T)muDoubleScalarFloor(b_n)) {
        emlrtIntegerCheckR2012b(b_n, &mb_emlrtDCI, sp);
      }

      i35 = Phi->size[1];
      i34 = (int32_T)b_n;
      if (!((i34 >= 1) && (i34 <= i35))) {
        emlrtDynamicBoundsCheckR2012b(i34, 1, i35, &rg_emlrtBCI, sp);
      }

      i35 = Phi->size[1];
      ixstart = (int32_T)((uint32_T)b_n + 4U);
      if (!((ixstart >= 1) && (ixstart <= i35))) {
        emlrtDynamicBoundsCheckR2012b(ixstart, 1, i35, &rg_emlrtBCI, sp);
      }

      i35 = ixstart + 1;
    }

    st.site = &bj_emlrtRSI;
    b_st.site = &yf_emlrtRSI;
    c_st.site = &ag_emlrtRSI;
    if ((i35 - i34 == 1) || (i35 - i34 != 1)) {
      b14 = true;
    } else {
      b14 = false;
    }

    if (b14) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &ie_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (i35 - i34 > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &he_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &ff_emlrtRSI;
    ixstart = 2;
    c_n = i35 - i34;
    mtmp = Phi->data[i34 - 1];
    itmp = 1;
    if (i35 - i34 > 1) {
      if (muDoubleScalarIsNaN(mtmp)) {
        e_st.site = &hf_emlrtRSI;
        if (2 > i35 - i34) {
          b15 = false;
        } else {
          b15 = (i35 - i34 > 2147483646);
        }

        if (b15) {
          f_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix <= c_n)) {
          ixstart = ix + 1;
          if (!muDoubleScalarIsNaN(Phi->data[(i34 + ix) - 2])) {
            mtmp = Phi->data[(i34 + ix) - 2];
            itmp = ix;
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart - 1 < i35 - i34) {
        e_st.site = &gf_emlrtRSI;
        if (ixstart > i35 - i34) {
          b_ixstart = false;
        } else {
          b_ixstart = (i35 - i34 > 2147483646);
        }

        if (b_ixstart) {
          f_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (ixstart <= c_n) {
          if (Phi->data[(i34 + ixstart) - 2] > mtmp) {
            mtmp = Phi->data[(i34 + ixstart) - 2];
            itmp = ixstart;
          }

          ixstart++;
        }
      }
    }

    /* 'cmp_rate:69' if (lag == center) && (y > Merit_thresh1) */
    guard1 = false;
    if ((itmp == 3) && (mtmp > 0.25)) {
      /* 'cmp_rate:71' numpeaks = numpeaks + 1; */
      numpeaks++;

      /* 'cmp_rate:72' Pitch(numpeaks) = Fs/(n+lag-1); */
      if (!((numpeaks >= 1) && (numpeaks <= 3))) {
        emlrtDynamicBoundsCheckR2012b(numpeaks, 1, 3, &sg_emlrtBCI, sp);
      }

      Pitch[numpeaks - 1] = Fs / ((b_n + 3.0) - 1.0);

      /* 'cmp_rate:73' Merit(numpeaks) = y; */
      Merit[numpeaks - 1] = mtmp;

      /* 'cmp_rate:75' if (y > Merit_thresh2) */
      if (mtmp > 0.9) {
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
  /* 'cmp_rate:83' [Merit,Idx]=sort(Merit, 'descend'); */
  c_sort(Merit, iidx);

  /* 'cmp_rate:84' Pitch = Pitch(Idx); */
  for (i33 = 0; i33 < 3; i33++) {
    b_Pitch[i33] = Pitch[iidx[i33] - 1];
  }

  for (i33 = 0; i33 < 3; i33++) {
    Pitch[i33] = b_Pitch[i33];
  }

  /* 'cmp_rate:85' numpeaks = min(numpeaks, maxcands); */
  /* 'cmp_rate:86' Merit = Merit(1:numpeaks); */
  if (1 > numpeaks) {
    c_n = 0;
  } else {
    c_n = numpeaks;
  }

  Merit_size[0] = 1;
  Merit_size[1] = c_n;
  for (i33 = 0; i33 < c_n; i33++) {
    Merit_data[i33] = Merit[i33];
  }

  /* 'cmp_rate:87' Pitch  = Pitch(1:numpeaks); */
  if (1 > numpeaks) {
    ixstart = 0;
  } else {
    ixstart = numpeaks;
  }

  Pitch_size[0] = 1;
  Pitch_size[1] = ixstart;
  for (i33 = 0; i33 < ixstart; i33++) {
    Pitch_data[i33] = Pitch[i33];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  /* 'cmp_rate:91' if (numpeaks < maxcands) */
  if (numpeaks < 3) {
    /* 'cmp_rate:92' if(isempty(Pitch)) */
    if (ixstart == 0) {
      /* 'cmp_rate:93' Pitch=zeros(1,maxcands); */
      Pitch_size[0] = 1;
      Pitch_size[1] = 3;

      /* 'cmp_rate:94' Merit=0.001*ones(1,maxcands); */
      Merit_size[0] = 1;
      Merit_size[1] = 3;
      for (i33 = 0; i33 < 3; i33++) {
        Pitch_data[i33] = 0.0;
        Merit_data[i33] = 0.001;
      }
    } else {
      /* 'cmp_rate:95' else */
      /* 'cmp_rate:96' Pitch = [Pitch zeros(1,maxcands-numpeaks)]; */
      itmp = 3 - numpeaks;
      Pitch_size[1] = (ixstart - numpeaks) + 3;
      for (i33 = 0; i33 < itmp; i33++) {
        Pitch_data[ixstart + i33] = 0.0;
      }

      emxInit_real_T(sp, &r18, 2, &yc_emlrtRTEI, true);

      /* 'cmp_rate:97' Merit = [Merit 0.001*ones(1,maxcands-numpeaks)]; */
      i33 = r18->size[0] * r18->size[1];
      r18->size[0] = 1;
      r18->size[1] = 3 - numpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r18, i33, (int32_T)sizeof(real_T),
                        &yc_emlrtRTEI);
      ixstart = 3 - numpeaks;
      for (i33 = 0; i33 < ixstart; i33++) {
        r18->data[i33] = 0.001;
      }

      emxInit_real_T(sp, &r19, 2, &yc_emlrtRTEI, true);
      itmp = r18->size[1];
      Merit_size[1] = c_n + itmp;
      ixstart = 3 - numpeaks;
      i33 = r19->size[0] * r19->size[1];
      r19->size[0] = 1;
      r19->size[1] = ixstart;
      emxEnsureCapacity(sp, (emxArray__common *)r19, i33, (int32_T)sizeof(real_T),
                        &yc_emlrtRTEI);
      emxFree_real_T(&r18);
      for (i33 = 0; i33 < ixstart; i33++) {
        r19->data[r19->size[0] * i33] = 0.001;
      }

      for (i33 = 0; i33 < itmp; i33++) {
        Merit_data[c_n + i33] = r19->data[i33];
      }

      emxFree_real_T(&r19);

      /*      Pitch(numpeaks+1:maxcands) = 0; */
      /*      Merit(numpeaks+1:maxcands) = 0.001; */
    }
  }

  /*  Normlize merits */
  /* 'cmp_rate:104' Max_Merit = max(Merit); */
  st.site = &cj_emlrtRSI;
  b_st.site = &df_emlrtRSI;
  c_st.site = &ef_emlrtRSI;
  if ((Merit_size[1] == 1) || (Merit_size[1] != 1)) {
    b14 = true;
  } else {
    b14 = false;
  }

  if (b14) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &ie_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (Merit_size[1] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &he_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &ff_emlrtRSI;
  ixstart = 1;
  n = Merit_size[1];
  mtmp = Merit_data[0];
  if (Merit_size[1] > 1) {
    if (muDoubleScalarIsNaN(Merit_data[0])) {
      e_st.site = &hf_emlrtRSI;
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(Merit_data[ix - 1])) {
          mtmp = Merit_data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < Merit_size[1]) {
      e_st.site = &gf_emlrtRSI;
      while (ixstart + 1 <= n) {
        if (Merit_data[ixstart] > mtmp) {
          mtmp = Merit_data[ixstart];
        }

        ixstart++;
      }
    }
  }

  /* 'cmp_rate:105' if (Max_Merit > 1.0) */
  if (mtmp > 1.0) {
    /* 'cmp_rate:106' Merit = Merit/Max_Merit; */
    Merit_size[0] = 1;
    c_n = Merit_size[1];
    for (i33 = 0; i33 < c_n; i33++) {
      Merit_data[i33] /= mtmp;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (cmp_rate.c) */
