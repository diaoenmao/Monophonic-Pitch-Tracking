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
#include "eml_warning.h"
#include "eml_sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo mi_emlrtRSI = { 68, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRSInfo ni_emlrtRSI = { 104, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo bd_emlrtRTEI = { 1, 27, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtRTEInfo xd_emlrtRTEI = { 67, 1, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m" };

static emlrtDCInfo nb_emlrtDCI = { 68, 21, "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 1 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 68, 21, "Phi", "cmp_rate",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { 1, 3, 72, 9, "Pitch", "cmp_rate",
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
  int32_T i34;
  int32_T n;
  boolean_T exitg2;
  real_T b_n;
  int32_T i35;
  int32_T i36;
  int32_T i;
  boolean_T b8;
  const mxArray *y;
  static const int32_T iv78[2] = { 1, 36 };

  const mxArray *m35;
  char_T cv118[36];
  static const char_T cv119[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *b_y;
  static const int32_T iv79[2] = { 1, 39 };

  char_T cv120[39];
  static const char_T cv121[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  real_T mtmp;
  int32_T itmp;
  boolean_T b9;
  int32_T ix;
  boolean_T exitg3;
  boolean_T b_i;
  boolean_T guard1 = false;
  real_T b_Merit[3];
  int32_T iidx[3];
  emxArray_real_T *r19;
  emxArray_real_T *r20;
  const mxArray *c_y;
  static const int32_T iv80[2] = { 1, 36 };

  const mxArray *d_y;
  static const int32_T iv81[2] = { 1, 39 };

  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
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
  for (i34 = 0; i34 < 3; i34++) {
    Pitch[i34] = 0.0;

    /* 'cmp_rate:56' Merit     = zeros(1, maxcands); */
    Merit[i34] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Find all peaks for a (lag_min--to--lag_max) search range */
  /*    a "peak" must be the higher than a specfied number of */
  /*    points on either side of point.  Peaks are later "cleaned" */
  /*    up, to retain only best peaks i.e. peaks which do not meet certain */
  /*    criteria are eliminated. */
  /*    and allowing only the peaks which are a certain amplitude over the rest. */
  /* 'cmp_rate:67' for n = lag_min-center:lag_max */
  i34 = (int32_T)(lag_max + (1.0 - (lag_min - 3.0)));
  emlrtForLoopVectorCheckR2012b(lag_min - 3.0, 1.0, lag_max, mxDOUBLE_CLASS, i34,
    &xd_emlrtRTEI, sp);
  n = 0;
  exitg2 = false;
  while ((!exitg2) && (n <= i34 - 1)) {
    b_n = (lag_min - 3.0) + (real_T)n;

    /* 'cmp_rate:68' [y, lag]  = max(Phi(n:n+width-1)); */
    if (b_n > (b_n + 5.0) - 1.0) {
      i35 = 1;
      i36 = 1;
    } else {
      i35 = Phi->size[1];
      i36 = (int32_T)emlrtIntegerCheckFastR2012b(b_n, &nb_emlrtDCI, sp);
      i35 = emlrtDynamicBoundsCheckFastR2012b(i36, 1, i35, &qg_emlrtBCI, sp);
      i36 = Phi->size[1];
      i = (int32_T)((uint32_T)b_n + 4U);
      i36 = emlrtDynamicBoundsCheckFastR2012b(i, 1, i36, &qg_emlrtBCI, sp) + 1;
    }

    st.site = &mi_emlrtRSI;
    b_st.site = &uf_emlrtRSI;
    c_st.site = &vf_emlrtRSI;
    if ((i36 - i35 == 1) || (i36 - i35 != 1)) {
      b8 = true;
    } else {
      b8 = false;
    }

    if (b8) {
    } else {
      y = NULL;
      m35 = emlrtCreateCharArray(2, iv78);
      for (i = 0; i < 36; i++) {
        cv118[i] = cv119[i];
      }

      emlrtInitCharArrayR2013a(&c_st, 36, m35, cv118);
      emlrtAssign(&y, m35);
      d_st.site = &gk_emlrtRSI;
      e_st.site = &mj_emlrtRSI;
      f_error(&d_st, b_message(&e_st, y, &r_emlrtMCI), &s_emlrtMCI);
    }

    if (i36 - i35 > 0) {
    } else {
      b_y = NULL;
      m35 = emlrtCreateCharArray(2, iv79);
      for (i = 0; i < 39; i++) {
        cv120[i] = cv121[i];
      }

      emlrtInitCharArrayR2013a(&c_st, 39, m35, cv120);
      emlrtAssign(&b_y, m35);
      d_st.site = &fk_emlrtRSI;
      e_st.site = &lj_emlrtRSI;
      f_error(&d_st, b_message(&e_st, b_y, &t_emlrtMCI), &u_emlrtMCI);
    }

    d_st.site = &bf_emlrtRSI;
    i = 2;
    mtmp = Phi->data[i35 - 1];
    itmp = 1;
    if (i36 - i35 > 1) {
      if (muDoubleScalarIsNaN(mtmp)) {
        f_st.site = &df_emlrtRSI;
        if (2 > i36 - i35) {
          b9 = false;
        } else {
          b9 = (i36 - i35 > 2147483646);
        }

        if (b9) {
          g_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix <= i36 - i35)) {
          i = ix + 1;
          if (!muDoubleScalarIsNaN(Phi->data[(i35 + ix) - 2])) {
            mtmp = Phi->data[(i35 + ix) - 2];
            itmp = ix;
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      if (i - 1 < i36 - i35) {
        f_st.site = &cf_emlrtRSI;
        if (i > i36 - i35) {
          b_i = false;
        } else {
          b_i = (i36 - i35 > 2147483646);
        }

        if (b_i) {
          g_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        while (i <= i36 - i35) {
          if (Phi->data[(i35 + i) - 2] > mtmp) {
            mtmp = Phi->data[(i35 + i) - 2];
            itmp = i;
          }

          i++;
        }
      }
    }

    /* 'cmp_rate:69' if (lag == center) && (y > Merit_thresh1) */
    guard1 = false;
    if ((itmp == 3) && (mtmp > 0.25)) {
      /* 'cmp_rate:71' numpeaks = numpeaks + 1; */
      numpeaks++;

      /* 'cmp_rate:72' Pitch(numpeaks) = Fs/(n+lag-1); */
      Pitch[emlrtDynamicBoundsCheckFastR2012b(numpeaks, 1, 3, &rg_emlrtBCI, sp)
        - 1] = Fs / ((b_n + 3.0) - 1.0);

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
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }
  }

  /*  consider the case when the number of peaks are more than the maxcands. */
  /*  Then take only the best maxcands peaks based on the Merit values . */
  /* 'cmp_rate:83' [Merit,Idx]=sort(Merit, 'descend'); */
  for (i34 = 0; i34 < 3; i34++) {
    b_Merit[i34] = Merit[i34];
  }

  c_eml_sort(b_Merit, Merit, iidx);

  /* 'cmp_rate:84' Pitch = Pitch(Idx); */
  for (i34 = 0; i34 < 3; i34++) {
    b_Merit[i34] = Pitch[iidx[i34] - 1];
  }

  for (i34 = 0; i34 < 3; i34++) {
    Pitch[i34] = b_Merit[i34];
  }

  /* 'cmp_rate:85' numpeaks = min(numpeaks, maxcands); */
  numpeaks = (int32_T)muDoubleScalarMin(numpeaks, 3.0);

  /* 'cmp_rate:86' Merit = Merit(1:numpeaks); */
  if (1 > numpeaks) {
    itmp = 0;
  } else {
    itmp = numpeaks;
  }

  Merit_size[0] = 1;
  Merit_size[1] = itmp;
  for (i34 = 0; i34 < itmp; i34++) {
    Merit_data[i34] = Merit[i34];
  }

  /* 'cmp_rate:87' Pitch  = Pitch(1:numpeaks); */
  if (1 > numpeaks) {
    i = 0;
  } else {
    i = numpeaks;
  }

  Pitch_size[0] = 1;
  Pitch_size[1] = i;
  for (i34 = 0; i34 < i; i34++) {
    Pitch_data[i34] = Pitch[i34];
  }

  /*  if the number of peaks in the frame are less than the maxcands, then we  */
  /*  assign "null" values to remainder of peak and merit values in arrays */
  /* 'cmp_rate:91' if (numpeaks < maxcands) */
  if (numpeaks < 3) {
    /* 'cmp_rate:92' if(isempty(Pitch)) */
    if (i == 0) {
      /* 'cmp_rate:93' Pitch=zeros(1,maxcands); */
      Pitch_size[0] = 1;
      Pitch_size[1] = 3;

      /* 'cmp_rate:94' Merit=0.001*ones(1,maxcands); */
      Merit_size[0] = 1;
      Merit_size[1] = 3;
      for (i34 = 0; i34 < 3; i34++) {
        Pitch_data[i34] = 0.0;
        Merit_data[i34] = 0.001;
      }
    } else {
      /* 'cmp_rate:95' else */
      /* 'cmp_rate:96' Pitch = [Pitch zeros(1,maxcands-numpeaks)]; */
      ix = 3 - numpeaks;
      Pitch_size[1] = (i - numpeaks) + 3;
      for (i34 = 0; i34 < ix; i34++) {
        Pitch_data[i + i34] = 0.0;
      }

      emxInit_real_T(sp, &r19, 2, &bd_emlrtRTEI, true);

      /* 'cmp_rate:97' Merit = [Merit 0.001*ones(1,maxcands-numpeaks)]; */
      i34 = r19->size[0] * r19->size[1];
      r19->size[0] = 1;
      r19->size[1] = 3 - numpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r19, i34, (int32_T)sizeof(real_T),
                        &bd_emlrtRTEI);
      i = 3 - numpeaks;
      for (i34 = 0; i34 < i; i34++) {
        r19->data[i34] = 0.001;
      }

      emxInit_real_T(sp, &r20, 2, &bd_emlrtRTEI, true);
      ix = r19->size[1];
      Merit_size[1] = itmp + ix;
      i = 3 - numpeaks;
      i34 = r20->size[0] * r20->size[1];
      r20->size[0] = 1;
      r20->size[1] = i;
      emxEnsureCapacity(sp, (emxArray__common *)r20, i34, (int32_T)sizeof(real_T),
                        &bd_emlrtRTEI);
      emxFree_real_T(&r19);
      for (i34 = 0; i34 < i; i34++) {
        r20->data[r20->size[0] * i34] = 0.001;
      }

      for (i34 = 0; i34 < ix; i34++) {
        Merit_data[itmp + i34] = r20->data[i34];
      }

      emxFree_real_T(&r20);

      /*      Pitch(numpeaks+1:maxcands) = 0; */
      /*      Merit(numpeaks+1:maxcands) = 0.001; */
    }
  }

  /*  Normlize merits */
  /* 'cmp_rate:104' Max_Merit = max(Merit); */
  st.site = &ni_emlrtRSI;
  b_st.site = &ye_emlrtRSI;
  c_st.site = &af_emlrtRSI;
  if ((Merit_size[1] == 1) || (Merit_size[1] != 1)) {
    b8 = true;
  } else {
    b8 = false;
  }

  if (b8) {
  } else {
    c_y = NULL;
    m35 = emlrtCreateCharArray(2, iv80);
    for (i = 0; i < 36; i++) {
      cv118[i] = cv119[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m35, cv118);
    emlrtAssign(&c_y, m35);
    d_st.site = &gk_emlrtRSI;
    e_st.site = &mj_emlrtRSI;
    f_error(&d_st, b_message(&e_st, c_y, &r_emlrtMCI), &s_emlrtMCI);
  }

  if (Merit_size[1] > 0) {
  } else {
    d_y = NULL;
    m35 = emlrtCreateCharArray(2, iv81);
    for (i = 0; i < 39; i++) {
      cv120[i] = cv121[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m35, cv120);
    emlrtAssign(&d_y, m35);
    d_st.site = &fk_emlrtRSI;
    e_st.site = &lj_emlrtRSI;
    f_error(&d_st, b_message(&e_st, d_y, &t_emlrtMCI), &u_emlrtMCI);
  }

  d_st.site = &bf_emlrtRSI;
  i = 1;
  mtmp = Merit_data[0];
  if (Merit_size[1] > 1) {
    if (muDoubleScalarIsNaN(Merit_data[0])) {
      f_st.site = &df_emlrtRSI;
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= Merit_size[1])) {
        i = ix;
        if (!muDoubleScalarIsNaN(Merit_data[ix - 1])) {
          mtmp = Merit_data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (i < Merit_size[1]) {
      f_st.site = &cf_emlrtRSI;
      while (i + 1 <= Merit_size[1]) {
        if (Merit_data[i] > mtmp) {
          mtmp = Merit_data[i];
        }

        i++;
      }
    }
  }

  /* 'cmp_rate:105' if (Max_Merit > 1.0) */
  if (mtmp > 1.0) {
    /* 'cmp_rate:106' Merit = Merit/Max_Merit; */
    Merit_size[0] = 1;
    itmp = Merit_size[1];
    for (i34 = 0; i34 < itmp; i34++) {
      Merit_data[i34] /= mtmp;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (cmp_rate.c) */
