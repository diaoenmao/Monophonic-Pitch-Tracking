/*
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
#include "indexShapeCheck.h"
#include "mean.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo bm_emlrtRSI = { 49, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo cm_emlrtRSI = { 51, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo dm_emlrtRSI = { 52, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo em_emlrtRSI = { 57, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo fm_emlrtRSI = { 58, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo gm_emlrtRSI = { 61, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo hm_emlrtRSI = { 68, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo im_emlrtRSI = { 61, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRTEInfo be_emlrtRTEI = { 1, 17, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo ce_emlrtRTEI = { 51, 1, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo de_emlrtRTEI = { 57, 5, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtBCInfo ui_emlrtBCI = { -1, -1, 57, 12, "Data", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo fd_emlrtDCI = { 57, 12, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtRTEInfo tg_emlrtRTEI = { 54, 1, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtBCInfo vi_emlrtBCI = { -1, -1, 51, 8, "Data", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo gd_emlrtDCI = { 51, 8, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtBCInfo wi_emlrtBCI = { -1, -1, 68, 5, "Phi", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo hd_emlrtDCI = { 68, 5, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

/* Function Definitions */

/*
 * function[Phi] = crs_corr(Data, lag_min, lag_max)
 */
void crs_corr(const emlrtStack *sp, emxArray_real_T *Data, real_T lag_min,
              real_T lag_max, emxArray_real_T *Phi)
{
  real_T N;
  int32_T i42;
  int32_T loop_ub;
  real_T d2;
  emxArray_real_T *x_j;
  int32_T iv55[2];
  emxArray_real_T *a;
  int32_T b_loop_ub;
  boolean_T innerDimOk;
  real_T p;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  int32_T k;
  emxArray_real_T *x_jr;
  real_T b_k;
  int32_T i43;
  int32_T i44;
  int32_T iv56[2];
  real_T formula_nume;
  real_T q;
  real_T formula_denom;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
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
  i42 = Phi->size[0] * Phi->size[1];
  Phi->size[0] = 1;
  Phi->size[1] = Data->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Phi, i42, (int32_T)sizeof(real_T),
                    &be_emlrtRTEI);
  loop_ub = Data->size[0];
  for (i42 = 0; i42 < loop_ub; i42++) {
    Phi->data[i42] = 0.0;
  }

  /*  Remove DC level */
  /* 'crs_corr:49' Data = Data- mean(Data); */
  st.site = &bm_emlrtRSI;
  d2 = c_mean(&st, Data);
  i42 = Data->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Data, i42, (int32_T)sizeof(real_T),
                    &be_emlrtRTEI);
  loop_ub = Data->size[0];
  for (i42 = 0; i42 < loop_ub; i42++) {
    Data->data[i42] -= d2;
  }

  /* 'crs_corr:51' x_j =  Data(1:N); */
  if (1.0 > N) {
    loop_ub = 0;
  } else {
    i42 = Data->size[0];
    if (!(1 <= i42)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i42, &vi_emlrtBCI, sp);
    }

    i42 = Data->size[0];
    if (N != (int32_T)muDoubleScalarFloor(N)) {
      emlrtIntegerCheckR2012b(N, &gd_emlrtDCI, sp);
    }

    loop_ub = (int32_T)N;
    if (!((loop_ub >= 1) && (loop_ub <= i42))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i42, &vi_emlrtBCI, sp);
    }
  }

  emxInit_real_T1(sp, &x_j, 1, &ce_emlrtRTEI, true);
  iv55[0] = 1;
  iv55[1] = loop_ub;
  st.site = &cm_emlrtRSI;
  indexShapeCheck(&st, Data->size[0], iv55);
  i42 = x_j->size[0];
  x_j->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)x_j, i42, (int32_T)sizeof(real_T),
                    &be_emlrtRTEI);
  for (i42 = 0; i42 < loop_ub; i42++) {
    x_j->data[i42] = Data->data[i42];
  }

  emxInit_real_T(sp, &a, 2, &be_emlrtRTEI, true);

  /*  s[j]   1 <= j <= N. */
  /* 'crs_corr:52' p = x_j' * x_j; */
  st.site = &dm_emlrtRSI;
  i42 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = x_j->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i42, (int32_T)sizeof(real_T),
                    &be_emlrtRTEI);
  b_loop_ub = x_j->size[0];
  for (i42 = 0; i42 < b_loop_ub; i42++) {
    a->data[a->size[0] * i42] = x_j->data[i42];
  }

  b_st.site = &fe_emlrtRSI;
  innerDimOk = (a->size[1] == loop_ub);
  if (!innerDimOk) {
    if ((a->size[1] == 1) || (loop_ub == 1)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &af_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &bf_emlrtRTEI,
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((a->size[1] == 1) || (loop_ub == 1)) {
    d2 = 0.0;
    for (i42 = 0; i42 < a->size[1]; i42++) {
      d2 += a->data[a->size[0] * i42] * x_j->data[i42];
    }

    p = d2;
  } else {
    b_st.site = &im_emlrtRSI;
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
  i42 = (int32_T)(lag_max + (1.0 - lag_min));
  emlrtForLoopVectorCheckR2012b(lag_min, 1.0, lag_max, mxDOUBLE_CLASS, i42,
    &tg_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T1(sp, &x_jr, 1, &de_emlrtRTEI, true);
  while (k <= i42 - 1) {
    b_k = lag_min + (real_T)k;

    /*   to calculate the dot product of the signal and displaced version. */
    /* 'crs_corr:57' x_jr = Data(k:k+N-1); */
    d2 = (b_k + N) - 1.0;
    if (b_k > d2) {
      b_loop_ub = 0;
      i43 = 0;
    } else {
      b_loop_ub = Data->size[0];
      if (b_k != (int32_T)muDoubleScalarFloor(b_k)) {
        emlrtIntegerCheckR2012b(b_k, &fd_emlrtDCI, sp);
      }

      i44 = (int32_T)b_k;
      if (!((i44 >= 1) && (i44 <= b_loop_ub))) {
        emlrtDynamicBoundsCheckR2012b(i44, 1, b_loop_ub, &ui_emlrtBCI, sp);
      }

      b_loop_ub = i44 - 1;
      i44 = Data->size[0];
      if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
        emlrtIntegerCheckR2012b(d2, &fd_emlrtDCI, sp);
      }

      i43 = (int32_T)d2;
      if (!((i43 >= 1) && (i43 <= i44))) {
        emlrtDynamicBoundsCheckR2012b(i43, 1, i44, &ui_emlrtBCI, sp);
      }
    }

    iv56[0] = 1;
    iv56[1] = i43 - b_loop_ub;
    st.site = &em_emlrtRSI;
    indexShapeCheck(&st, Data->size[0], iv56);
    i44 = x_jr->size[0];
    x_jr->size[0] = i43 - b_loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)x_jr, i44, (int32_T)sizeof(real_T),
                      &be_emlrtRTEI);
    loop_ub = i43 - b_loop_ub;
    for (i44 = 0; i44 < loop_ub; i44++) {
      x_jr->data[i44] = Data->data[b_loop_ub + i44];
    }

    /*  s[j]   -k <= j <= N+K-k-1. */
    /* 'crs_corr:58' formula_nume = x_j' * x_jr; */
    st.site = &fm_emlrtRSI;
    i44 = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_j->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i44, (int32_T)sizeof(real_T),
                      &be_emlrtRTEI);
    loop_ub = x_j->size[0];
    for (i44 = 0; i44 < loop_ub; i44++) {
      a->data[a->size[0] * i44] = x_j->data[i44];
    }

    b_st.site = &fe_emlrtRSI;
    innerDimOk = (a->size[1] == i43 - b_loop_ub);
    if (!innerDimOk) {
      if ((a->size[1] == 1) || (i43 - b_loop_ub == 1)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &af_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &bf_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }
    }

    if ((a->size[1] == 1) || (i43 - b_loop_ub == 1)) {
      d2 = 0.0;
      for (i44 = 0; i44 < a->size[1]; i44++) {
        d2 += a->data[a->size[0] * i44] * x_jr->data[i44];
      }

      formula_nume = d2;
    } else {
      b_st.site = &im_emlrtRSI;
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
    st.site = &gm_emlrtRSI;
    i44 = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_jr->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i44, (int32_T)sizeof(real_T),
                      &be_emlrtRTEI);
    loop_ub = x_jr->size[0];
    for (i44 = 0; i44 < loop_ub; i44++) {
      a->data[a->size[0] * i44] = x_jr->data[i44];
    }

    b_st.site = &fe_emlrtRSI;
    innerDimOk = (a->size[1] == i43 - b_loop_ub);
    if (!innerDimOk) {
      if ((a->size[1] == 1) || (i43 - b_loop_ub == 1)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &af_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &bf_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }
    }

    if ((a->size[1] == 1) || (i43 - b_loop_ub == 1)) {
      d2 = 0.0;
      for (b_loop_ub = 0; b_loop_ub < a->size[1]; b_loop_ub++) {
        d2 += a->data[a->size[0] * b_loop_ub] * x_jr->data[b_loop_ub];
      }

      q = d2;
    } else {
      b_st.site = &im_emlrtRSI;
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
    st.site = &hm_emlrtRSI;
    if (formula_denom < 0.0) {
      b_st.site = &td_emlrtRSI;
      error(&b_st);
    }

    b_loop_ub = Phi->size[1];
    if (b_k != (int32_T)muDoubleScalarFloor(b_k)) {
      emlrtIntegerCheckR2012b(b_k, &hd_emlrtDCI, sp);
    }

    i44 = (int32_T)b_k;
    if (!((i44 >= 1) && (i44 <= b_loop_ub))) {
      emlrtDynamicBoundsCheckR2012b(i44, 1, b_loop_ub, &wi_emlrtBCI, sp);
    }

    Phi->data[i44 - 1] = formula_nume / muDoubleScalarSqrt(formula_denom);
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
