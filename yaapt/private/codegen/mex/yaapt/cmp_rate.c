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
#include "sort1.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo bk_emlrtRSI = { 69, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRSInfo ck_emlrtRSI = { 93, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRSInfo dk_emlrtRSI = { 115, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo bd_emlrtRTEI = { 1, 27, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo mf_emlrtRTEI = { 68, 1, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtDCInfo ob_emlrtDCI = { 69, 21, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 69, 21, "Phi", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { 1, 20, 73, 9, "Pitch", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

static emlrtBCInfo of_emlrtBCI = { 1, 20, 94, 9, "Pitch", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

/* Function Definitions */

/*
 * function [Pitch, Merit] = cmp_rate(Phi, Fs, maxcands, lag_min, lag_max,Prm)
 */
void cmp_rate(const emlrtStack *sp, const emxArray_real_T *Phi, real_T Fs,
              real_T lag_min, real_T lag_max, emxArray_real_T *Pitch,
              emxArray_real_T *Merit)
{
  int32_T numpeaks;
  real_T b_Pitch[20];
  real_T b_Merit[20];
  int32_T i37;
  int32_T n;
  boolean_T exitg2;
  real_T b_n;
  int32_T i38;
  int32_T i39;
  int32_T ixstart;
  boolean_T b15;
  int32_T c_n;
  real_T mtmp;
  int32_T itmp;
  boolean_T b16;
  int32_T ix;
  boolean_T exitg3;
  boolean_T b_ixstart;
  boolean_T guard1 = false;
  int32_T iidx[20];
  real_T c_Pitch[20];
  emxArray_real_T *r22;
  emxArray_real_T *r23;
  emxArray_real_T *r24;
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

  /*  Pitch     = zeros(1, maxcands); */
  /*  Merit     = zeros(1, maxcands); */
  /* 'cmp_rate:57' Pitch     = zeros(1, 20); */
  /* 'cmp_rate:58' Merit     = zeros(1, 20); */
  for (i37 = 0; i37 < 20; i37++) {
    b_Pitch[i37] = 0.0;
    b_Merit[i37] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  /* 'cmp_rate:68' for n = lag_min-center:lag_max */
  i37 = (int32_T)(lag_max + (1.0 - (lag_min - 3.0)));
  emlrtForLoopVectorCheckR2012b(lag_min - 3.0, 1.0, lag_max, mxDOUBLE_CLASS, i37,
    &mf_emlrtRTEI, sp);
  n = 0;
  exitg2 = false;
  while ((!exitg2) && (n <= i37 - 1)) {
    b_n = (lag_min - 3.0) + (real_T)n;

    /* 'cmp_rate:69' [y, lag]  = max(Phi(n:n+width-1)); */
    if (b_n > (b_n + 5.0) - 1.0) {
      i38 = 1;
      i39 = 1;
    } else {
      if (b_n != (int32_T)muDoubleScalarFloor(b_n)) {
        emlrtIntegerCheckR2012b(b_n, &ob_emlrtDCI, sp);
      }

      i39 = Phi->size[1];
      i38 = (int32_T)b_n;
      if (!((i38 >= 1) && (i38 <= i39))) {
        emlrtDynamicBoundsCheckR2012b(i38, 1, i39, &mf_emlrtBCI, sp);
      }

      i39 = Phi->size[1];
      ixstart = (int32_T)((uint32_T)b_n + 4U);
      if (!((ixstart >= 1) && (ixstart <= i39))) {
        emlrtDynamicBoundsCheckR2012b(ixstart, 1, i39, &mf_emlrtBCI, sp);
      }

      i39 = ixstart + 1;
    }

    st.site = &bk_emlrtRSI;
    b_st.site = &rg_emlrtRSI;
    c_st.site = &sg_emlrtRSI;
    if ((i39 - i38 == 1) || (i39 - i38 != 1)) {
      b15 = true;
    } else {
      b15 = false;
    }

    if (b15) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &re_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (i39 - i38 > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &qe_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &hb_emlrtRSI;
    ixstart = 2;
    c_n = i39 - i38;
    mtmp = Phi->data[i38 - 1];
    itmp = 1;
    if (i39 - i38 > 1) {
      if (muDoubleScalarIsNaN(mtmp)) {
        e_st.site = &ib_emlrtRSI;
        if (2 > i39 - i38) {
          b16 = false;
        } else {
          b16 = (i39 - i38 > 2147483646);
        }

        if (b16) {
          f_st.site = &kb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix <= c_n)) {
          ixstart = ix + 1;
          if (!muDoubleScalarIsNaN(Phi->data[(i38 + ix) - 2])) {
            mtmp = Phi->data[(i38 + ix) - 2];
            itmp = ix;
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart - 1 < i39 - i38) {
        e_st.site = &jb_emlrtRSI;
        if (ixstart > i39 - i38) {
          b_ixstart = false;
        } else {
          b_ixstart = (i39 - i38 > 2147483646);
        }

        if (b_ixstart) {
          f_st.site = &kb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        while (ixstart <= c_n) {
          if (Phi->data[(i38 + ixstart) - 2] > mtmp) {
            mtmp = Phi->data[(i38 + ixstart) - 2];
            itmp = ixstart;
          }

          ixstart++;
        }
      }
    }

    /* 'cmp_rate:70' if (lag == center) && (y > Merit_thresh1) */
    guard1 = false;
    if ((itmp == 3) && (mtmp > 0.25)) {
      /* 'cmp_rate:72' numpeaks = numpeaks + 1; */
      numpeaks++;

      /* 'cmp_rate:73' Pitch(numpeaks) = Fs/(n+lag-1); */
      if (!((numpeaks >= 1) && (numpeaks <= 20))) {
        emlrtDynamicBoundsCheckR2012b(numpeaks, 1, 20, &nf_emlrtBCI, sp);
      }

      b_Pitch[numpeaks - 1] = Fs / ((b_n + 3.0) - 1.0);

      /* 'cmp_rate:74' Merit(numpeaks) = y; */
      b_Merit[numpeaks - 1] = mtmp;

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
  /* 'cmp_rate:93' [Merit,Idx]=sort(Merit, 'descend'); */
  st.site = &ck_emlrtRSI;
  b_st.site = &tg_emlrtRSI;
  c_sort(&b_st, b_Merit, iidx);

  /* 'cmp_rate:94' Pitch = Pitch(Idx); */
  for (i37 = 0; i37 < 20; i37++) {
    if (!((iidx[i37] >= 1) && (iidx[i37] <= 20))) {
      emlrtDynamicBoundsCheckR2012b(iidx[i37], 1, 20, &of_emlrtBCI, sp);
    }

    c_Pitch[i37] = b_Pitch[iidx[i37] - 1];
  }

  memcpy(&b_Pitch[0], &c_Pitch[0], 20U * sizeof(real_T));

  /* 'cmp_rate:95' numpeaks = min(numpeaks, maxcands); */
  numpeaks = (int32_T)muDoubleScalarMin(numpeaks, 3.0);

  /* 'cmp_rate:96' Merit = Merit(1:numpeaks); */
  if (1 > numpeaks) {
    ixstart = 0;
  } else {
    ixstart = numpeaks;
  }

  i37 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 1;
  Merit->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i37, (int32_T)sizeof(real_T),
                    &bd_emlrtRTEI);
  for (i37 = 0; i37 < ixstart; i37++) {
    Merit->data[Merit->size[0] * i37] = b_Merit[i37];
  }

  /* 'cmp_rate:97' Pitch  = Pitch(1:numpeaks); */
  if (1 > numpeaks) {
    ixstart = 0;
  } else {
    ixstart = numpeaks;
  }

  i37 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 1;
  Pitch->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i37, (int32_T)sizeof(real_T),
                    &bd_emlrtRTEI);
  for (i37 = 0; i37 < ixstart; i37++) {
    Pitch->data[Pitch->size[0] * i37] = b_Pitch[i37];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  /* 'cmp_rate:102' if (numpeaks < maxcands) */
  if (numpeaks < 3) {
    /* 'cmp_rate:103' if(isempty(Pitch)) */
    if (ixstart == 0) {
      /* 'cmp_rate:104' Pitch=zeros(1,maxcands); */
      i37 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[0] = 1;
      Pitch->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i37, (int32_T)sizeof
                        (real_T), &bd_emlrtRTEI);
      for (i37 = 0; i37 < 3; i37++) {
        Pitch->data[i37] = 0.0;
      }

      /* 'cmp_rate:105' Merit=0.001*ones(1,maxcands); */
      i37 = Merit->size[0] * Merit->size[1];
      Merit->size[0] = 1;
      Merit->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i37, (int32_T)sizeof
                        (real_T), &bd_emlrtRTEI);
      for (i37 = 0; i37 < 3; i37++) {
        Merit->data[i37] = 0.001;
      }
    } else {
      emxInit_real_T(sp, &r22, 2, &bd_emlrtRTEI, true);

      /* 'cmp_rate:106' else */
      /* 'cmp_rate:107' Pitch = [Pitch zeros(1,maxcands-numpeaks)]; */
      ixstart = Pitch->size[1];
      c_n = 3 - numpeaks;
      i37 = Pitch->size[0] * Pitch->size[1];
      Pitch->size[1] = (ixstart - numpeaks) + 3;
      emxEnsureCapacity(sp, (emxArray__common *)Pitch, i37, (int32_T)sizeof
                        (real_T), &bd_emlrtRTEI);
      itmp = 3 - numpeaks;
      i37 = r22->size[0] * r22->size[1];
      r22->size[0] = 1;
      r22->size[1] = itmp;
      emxEnsureCapacity(sp, (emxArray__common *)r22, i37, (int32_T)sizeof(real_T),
                        &bd_emlrtRTEI);
      for (i37 = 0; i37 < itmp; i37++) {
        r22->data[r22->size[0] * i37] = 0.0;
      }

      for (i37 = 0; i37 < c_n; i37++) {
        Pitch->data[ixstart + i37] = r22->data[i37];
      }

      emxFree_real_T(&r22);
      emxInit_real_T(sp, &r23, 2, &bd_emlrtRTEI, true);

      /* 'cmp_rate:108' Merit = [Merit 0.001*ones(1,maxcands-numpeaks)]; */
      i37 = r23->size[0] * r23->size[1];
      r23->size[0] = 1;
      r23->size[1] = 3 - numpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r23, i37, (int32_T)sizeof(real_T),
                        &bd_emlrtRTEI);
      ixstart = 3 - numpeaks;
      for (i37 = 0; i37 < ixstart; i37++) {
        r23->data[i37] = 0.001;
      }

      emxInit_real_T(sp, &r24, 2, &bd_emlrtRTEI, true);
      ixstart = Merit->size[1];
      c_n = r23->size[1];
      i37 = Merit->size[0] * Merit->size[1];
      Merit->size[1] = ixstart + c_n;
      emxEnsureCapacity(sp, (emxArray__common *)Merit, i37, (int32_T)sizeof
                        (real_T), &bd_emlrtRTEI);
      itmp = 3 - numpeaks;
      i37 = r24->size[0] * r24->size[1];
      r24->size[0] = 1;
      r24->size[1] = itmp;
      emxEnsureCapacity(sp, (emxArray__common *)r24, i37, (int32_T)sizeof(real_T),
                        &bd_emlrtRTEI);
      emxFree_real_T(&r23);
      for (i37 = 0; i37 < itmp; i37++) {
        r24->data[r24->size[0] * i37] = 0.001;
      }

      for (i37 = 0; i37 < c_n; i37++) {
        Merit->data[ixstart + i37] = r24->data[i37];
      }

      emxFree_real_T(&r24);

      /*      Pitch(numpeaks+1:maxcands) = 0; */
      /*      Merit(numpeaks+1:maxcands) = 0.001; */
    }
  }

  /*  Normlize merits */
  /* 'cmp_rate:115' Max_Merit = max(Merit); */
  st.site = &dk_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  if ((Merit->size[1] == 1) || (Merit->size[1] != 1)) {
    b15 = true;
  } else {
    b15 = false;
  }

  if (b15) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &re_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (Merit->size[1] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &qe_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &hb_emlrtRSI;
  ixstart = 1;
  n = Merit->size[1];
  mtmp = Merit->data[0];
  if (Merit->size[1] > 1) {
    if (muDoubleScalarIsNaN(Merit->data[0])) {
      e_st.site = &ib_emlrtRSI;
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
    emxInit_real_T(sp, &c_Merit, 2, &bd_emlrtRTEI, true);

    /* 'cmp_rate:117' Merit = Merit/Max_Merit; */
    i37 = c_Merit->size[0] * c_Merit->size[1];
    c_Merit->size[0] = 1;
    c_Merit->size[1] = Merit->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)c_Merit, i37, (int32_T)sizeof
                      (real_T), &bd_emlrtRTEI);
    ixstart = Merit->size[0] * Merit->size[1];
    for (i37 = 0; i37 < ixstart; i37++) {
      c_Merit->data[i37] = Merit->data[i37];
    }

    c_rdivide(sp, c_Merit, mtmp, Merit);
    emxFree_real_T(&c_Merit);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (cmp_rate.c) */
