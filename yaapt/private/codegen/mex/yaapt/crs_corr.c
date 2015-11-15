/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * crs_corr.c
 *
 * Code generation for function 'crs_corr'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "crs_corr.h"
#include "error1.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "isequal.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo qi_emlrtRSI = { 49, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo ri_emlrtRSI = { 51, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo si_emlrtRSI = { 52, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo ti_emlrtRSI = { 57, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo ui_emlrtRSI = { 58, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo vi_emlrtRSI = { 61, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo wi_emlrtRSI = { 68, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo xi_emlrtRSI = { 61, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRSInfo yi_emlrtRSI = { 21, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRSInfo aj_emlrtRSI = { 32, "xdotu",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotu.m" };

static emlrtRTEInfo vc_emlrtRTEI = { 1, 17, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo wc_emlrtRTEI = { 51, 1, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo xc_emlrtRTEI = { 57, 5, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 51, 8, "Data", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo jb_emlrtDCI = { 51, 8, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtRTEInfo xe_emlrtRTEI = { 54, 1, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtDCInfo kb_emlrtDCI = { 57, 12, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 57, 12, "Data", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtRTEInfo ye_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRTEInfo af_emlrtRTEI = { 98, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 68, 5, "Phi", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo lb_emlrtDCI = { 68, 5, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

/* Function Definitions */

/*
 * function[Phi] = crs_corr(Data, lag_min, lag_max)
 */
void crs_corr(const emlrtStack *sp, emxArray_real_T *Data, real_T lag_min,
              real_T lag_max, emxArray_real_T *Phi)
{
  real_T N;
  int32_T i29;
  int32_T loop_ub;
  boolean_T overflow;
  real_T y;
  int32_T k;
  emxArray_real_T *x_j;
  int32_T iv31[2];
  emxArray_real_T *a;
  real_T p;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  emxArray_real_T *x_jr;
  real_T b_k;
  int32_T i30;
  int32_T i31;
  int32_T i32;
  int32_T iv32[2];
  real_T formula_nume;
  real_T q;
  real_T formula_denom;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  CRS_CORR compute NCCF (Normalized cross correlation Function)  */
  /*  */
  /*    [Phi] = crs_corr(Data, lag_min, lag_max) computes the */
  /*    normalized cross correlation sequence based on the RAPT algorithm  */
  /*    discussed by DAVID TALKIN. */
  /*    "Assume that "S" is the input signal sequence, "Phi" is correlation sequence, */
  /*        Phi(k)=SUM((S[j])*(S[j+k]))/sqrt((SUM(s[j]^2)*(S[j+k]^2))) */
  /*        where 1 <= k <= Lag_max and 1 <= j <= N. Summation is based on j only */
  /*        Phi(k) should range from -1 to 1". */
  /*  */
  /*  INPUTS:    */
  /*    Data:     Data array of signal values. */
  /*    lag_min:  minimum value of lag to consider */
  /*    lag_max:  maximum value of lag to consider */
  /*    Note that calculations will be based on (len-----lag_max)  points */
  /*  */
  /*  OUTPUTS: */
  /*    Phi     : The normalized cross correlated */
  /*  */
  /*    Note: The index of the first reasonable peak value of Phi is considered */
  /*    to be the period of the input signal. */
  /*   Programmer: S.A.Zahorian,Kasi Kavita. */
  /*   Creation date:  2000 */
  /*   Revision date:  March 26, 2002 */
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
  /*  Some initialization */
  /* 'crs_corr:41' eps1 = 0.0; */
  /* 'crs_corr:43' len  = length(Data); */
  /*  The length of data */
  /* 'crs_corr:44' N = len-lag_max; */
  N = (real_T)Data->size[0] - lag_max;

  /*  range */
  /* 'crs_corr:46' Phi = zeros(1,len)  ; */
  i29 = Phi->size[0] * Phi->size[1];
  Phi->size[0] = 1;
  Phi->size[1] = Data->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Phi, i29, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  loop_ub = Data->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    Phi->data[i29] = 0.0;
  }

  /*  Remove DC level */
  /* 'crs_corr:49' Data = Data- mean(Data); */
  st.site = &qi_emlrtRSI;
  if ((Data->size[0] == 1) || (Data->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ae_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = !isequal(Data);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &yd_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  overflow = !isequal(Data);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &xd_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &ed_emlrtRSI;
  if (Data->size[0] == 0) {
    y = 0.0;
  } else {
    y = Data->data[0];
    c_st.site = &fd_emlrtRSI;
    if (2 > Data->size[0]) {
      overflow = false;
    } else {
      overflow = (Data->size[0] > 2147483646);
    }

    if (overflow) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= Data->size[0]; k++) {
      y += Data->data[k - 1];
    }
  }

  y /= (real_T)Data->size[0];
  i29 = Data->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Data, i29, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  loop_ub = Data->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    Data->data[i29] -= y;
  }

  /* 'crs_corr:51' x_j =  Data(1:N); */
  if (1.0 > N) {
    loop_ub = 0;
  } else {
    i29 = Data->size[0];
    if (!(1 <= i29)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i29, &og_emlrtBCI, sp);
    }

    if (N != (int32_T)muDoubleScalarFloor(N)) {
      emlrtIntegerCheckR2012b(N, &jb_emlrtDCI, sp);
    }

    i29 = Data->size[0];
    loop_ub = (int32_T)N;
    if (!((loop_ub >= 1) && (loop_ub <= i29))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i29, &og_emlrtBCI, sp);
    }
  }

  emxInit_real_T1(sp, &x_j, 1, &wc_emlrtRTEI, true);
  iv31[0] = 1;
  iv31[1] = loop_ub;
  st.site = &ri_emlrtRSI;
  indexShapeCheck(&st, Data->size[0], iv31);
  i29 = x_j->size[0];
  x_j->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)x_j, i29, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  for (i29 = 0; i29 < loop_ub; i29++) {
    x_j->data[i29] = Data->data[i29];
  }

  emxInit_real_T(sp, &a, 2, &vc_emlrtRTEI, true);

  /*  s[j]   1 <= j <= N. */
  /* 'crs_corr:52' p = x_j' * x_j; */
  st.site = &si_emlrtRSI;
  i29 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = x_j->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i29, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  k = x_j->size[0];
  for (i29 = 0; i29 < k; i29++) {
    a->data[a->size[0] * i29] = x_j->data[i29];
  }

  b_st.site = &yi_emlrtRSI;
  if (!(a->size[1] == loop_ub)) {
    if ((a->size[1] == 1) || (loop_ub == 1)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &af_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &ye_emlrtRTEI,
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((a->size[1] == 1) || (loop_ub == 1)) {
    y = 0.0;
    for (i29 = 0; i29 < a->size[1]; i29++) {
      y += a->data[a->size[0] * i29] * x_j->data[i29];
    }

    p = y;
  } else {
    b_st.site = &xi_emlrtRSI;
    c_st.site = &aj_emlrtRSI;
    if (a->size[1] < 1) {
      p = 0.0;
    } else {
      n_t = (ptrdiff_t)a->size[1];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      p = ddot(&n_t, &a->data[0], &incx_t, &x_j->data[0], &incy_t);
    }
  }

  /* 'crs_corr:54' for k = lag_min:lag_max */
  i29 = (int32_T)(lag_max + (1.0 - lag_min));
  emlrtForLoopVectorCheckR2012b(lag_min, 1.0, lag_max, mxDOUBLE_CLASS, i29,
    &xe_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T1(sp, &x_jr, 1, &xc_emlrtRTEI, true);
  while (k <= i29 - 1) {
    b_k = lag_min + (real_T)k;

    /*   to calculate the dot product of the signal and displaced version. */
    /* 'crs_corr:57' x_jr = Data(k:k+N-1); */
    y = (b_k + N) - 1.0;
    if (b_k > y) {
      i30 = 1;
      i31 = 1;
    } else {
      if (b_k != (int32_T)muDoubleScalarFloor(b_k)) {
        emlrtIntegerCheckR2012b(b_k, &kb_emlrtDCI, sp);
      }

      i31 = Data->size[0];
      i30 = (int32_T)b_k;
      if (!((i30 >= 1) && (i30 <= i31))) {
        emlrtDynamicBoundsCheckR2012b(i30, 1, i31, &pg_emlrtBCI, sp);
      }

      if (y != (int32_T)muDoubleScalarFloor(y)) {
        emlrtIntegerCheckR2012b(y, &kb_emlrtDCI, sp);
      }

      i31 = Data->size[0];
      i32 = (int32_T)y;
      if (!((i32 >= 1) && (i32 <= i31))) {
        emlrtDynamicBoundsCheckR2012b(i32, 1, i31, &pg_emlrtBCI, sp);
      }

      i31 = i32 + 1;
    }

    iv32[0] = 1;
    iv32[1] = i31 - i30;
    st.site = &ti_emlrtRSI;
    indexShapeCheck(&st, Data->size[0], iv32);
    i32 = x_jr->size[0];
    x_jr->size[0] = i31 - i30;
    emxEnsureCapacity(sp, (emxArray__common *)x_jr, i32, (int32_T)sizeof(real_T),
                      &vc_emlrtRTEI);
    loop_ub = i31 - i30;
    for (i32 = 0; i32 < loop_ub; i32++) {
      x_jr->data[i32] = Data->data[(i30 + i32) - 1];
    }

    /*  s[j]   -k <= j <= N+K-k-1. */
    /* 'crs_corr:58' formula_nume = x_j' * x_jr; */
    st.site = &ui_emlrtRSI;
    i32 = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_j->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i32, (int32_T)sizeof(real_T),
                      &vc_emlrtRTEI);
    loop_ub = x_j->size[0];
    for (i32 = 0; i32 < loop_ub; i32++) {
      a->data[a->size[0] * i32] = x_j->data[i32];
    }

    b_st.site = &yi_emlrtRSI;
    if (!(a->size[1] == i31 - i30)) {
      if ((a->size[1] == 1) || (i31 - i30 == 1)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &af_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &ye_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }
    }

    if ((a->size[1] == 1) || (i31 - i30 == 1)) {
      y = 0.0;
      for (i32 = 0; i32 < a->size[1]; i32++) {
        y += a->data[a->size[0] * i32] * x_jr->data[i32];
      }

      formula_nume = y;
    } else {
      b_st.site = &xi_emlrtRSI;
      c_st.site = &aj_emlrtRSI;
      if (a->size[1] < 1) {
        formula_nume = 0.0;
      } else {
        n_t = (ptrdiff_t)a->size[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        formula_nume = ddot(&n_t, &a->data[0], &incx_t, &x_jr->data[0], &incy_t);
      }
    }

    /*  the normalization factor for the denominator. */
    /* 'crs_corr:61' q = x_jr' * x_jr; */
    st.site = &vi_emlrtRSI;
    i32 = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_jr->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i32, (int32_T)sizeof(real_T),
                      &vc_emlrtRTEI);
    loop_ub = x_jr->size[0];
    for (i32 = 0; i32 < loop_ub; i32++) {
      a->data[a->size[0] * i32] = x_jr->data[i32];
    }

    b_st.site = &yi_emlrtRSI;
    if (!(a->size[1] == i31 - i30)) {
      if ((a->size[1] == 1) || (i31 - i30 == 1)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &af_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &ye_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }
    }

    if ((a->size[1] == 1) || (i31 - i30 == 1)) {
      y = 0.0;
      for (i31 = 0; i31 < a->size[1]; i31++) {
        y += a->data[a->size[0] * i31] * x_jr->data[i31];
      }

      q = y;
    } else {
      b_st.site = &xi_emlrtRSI;
      c_st.site = &aj_emlrtRSI;
      if (a->size[1] < 1) {
        q = 0.0;
      } else {
        n_t = (ptrdiff_t)a->size[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        q = ddot(&n_t, &a->data[0], &incx_t, &x_jr->data[0], &incy_t);
      }
    }

    /* 'crs_corr:63' formula_denom= p*q; */
    formula_denom = p * q;

    /* 'crs_corr:65' formula_denom = formula_denom+ eps1; */
    /*  calculate the normalized crosscorrelation value using the TALKIN FORMULA. */
    /* 'crs_corr:68' Phi(k)=((formula_nume)/(sqrt(formula_denom))); */
    st.site = &wi_emlrtRSI;
    if (formula_denom < 0.0) {
      b_st.site = &ge_emlrtRSI;
      error(&b_st);
    }

    i31 = Phi->size[1];
    if (b_k != (int32_T)muDoubleScalarFloor(b_k)) {
      emlrtIntegerCheckR2012b(b_k, &lb_emlrtDCI, sp);
    }

    i30 = (int32_T)b_k;
    if (!((i30 >= 1) && (i30 <= i31))) {
      emlrtDynamicBoundsCheckR2012b(i30, 1, i31, &qg_emlrtBCI, sp);
    }

    Phi->data[i30 - 1] = formula_nume / muDoubleScalarSqrt(formula_denom);
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&a);
  emxFree_real_T(&x_jr);
  emxFree_real_T(&x_j);

  /*    To test using autocorrelation */
  /*     Phi = xcorr(s); */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (crs_corr.c) */
