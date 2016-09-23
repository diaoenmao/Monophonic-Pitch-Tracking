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
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "isequal.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo jl_emlrtRSI = { 49, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo kl_emlrtRSI = { 51, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo ll_emlrtRSI = { 52, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo ml_emlrtRSI = { 57, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo nl_emlrtRSI = { 58, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo ol_emlrtRSI = { 61, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo pl_emlrtRSI = { 68, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo ql_emlrtRSI = { 61, "eml_mtimes_helper",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRSInfo rl_emlrtRSI = { 32, "xdotu",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotu.m" };

static emlrtRTEInfo xd_emlrtRTEI = { 1, 17, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo yd_emlrtRTEI = { 51, 1, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo ae_emlrtRTEI = { 57, 5, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtBCInfo ii_emlrtBCI = { -1, -1, 57, 12, "Data", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo ec_emlrtDCI = { 57, 12, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtRTEInfo ng_emlrtRTEI = { 54, 1, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 51, 8, "Data", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo fc_emlrtDCI = { 51, 8, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtBCInfo ki_emlrtBCI = { -1, -1, 68, 5, "Phi", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo gc_emlrtDCI = { 68, 5, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

/* Function Definitions */
void crs_corr(const emlrtStack *sp, emxArray_real_T *Data, real_T lag_min,
              real_T lag_max, emxArray_real_T *Phi)
{
  real_T N;
  int32_T i43;
  int32_T loop_ub;
  boolean_T overflow;
  real_T y;
  int32_T k;
  emxArray_real_T *x_j;
  int32_T iv49[2];
  emxArray_real_T *a;
  ptrdiff_t n_t;
  real_T p;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  emxArray_real_T *x_jr;
  real_T b_k;
  int32_T i44;
  int32_T i45;
  int32_T i46;
  int32_T iv50[2];
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
  covrtLogFcn(&emlrtCoverageInstance, 17U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 17U, 0);

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
  /*  The length of data */
  N = (real_T)Data->size[0] - lag_max;

  /*  range */
  i43 = Phi->size[0] * Phi->size[1];
  Phi->size[0] = 1;
  Phi->size[1] = Data->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Phi, i43, (int32_T)sizeof(real_T),
                    &xd_emlrtRTEI);
  loop_ub = Data->size[0];
  for (i43 = 0; i43 < loop_ub; i43++) {
    Phi->data[i43] = 0.0;
  }

  /*  Remove DC level */
  st.site = &jl_emlrtRSI;
  if ((Data->size[0] == 1) || (Data->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &sf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = !isequal(Data);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &tf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  overflow = !isequal(Data);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &uf_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &sg_emlrtRSI;
  if (Data->size[0] == 0) {
    y = 0.0;
  } else {
    y = Data->data[0];
    c_st.site = &tg_emlrtRSI;
    overflow = ((!(2 > Data->size[0])) && (Data->size[0] > 2147483646));
    if (overflow) {
      d_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= Data->size[0]; k++) {
      y += Data->data[k - 1];
    }
  }

  y /= (real_T)Data->size[0];
  i43 = Data->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Data, i43, (int32_T)sizeof(real_T),
                    &xd_emlrtRTEI);
  loop_ub = Data->size[0];
  for (i43 = 0; i43 < loop_ub; i43++) {
    Data->data[i43] -= y;
  }

  if (1.0 > N) {
    loop_ub = 0;
  } else {
    i43 = Data->size[0];
    if (!(1 <= i43)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i43, &ji_emlrtBCI, sp);
    }

    i43 = Data->size[0];
    if (N != (int32_T)muDoubleScalarFloor(N)) {
      emlrtIntegerCheckR2012b(N, &fc_emlrtDCI, sp);
    }

    loop_ub = (int32_T)N;
    if (!((loop_ub >= 1) && (loop_ub <= i43))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i43, &ji_emlrtBCI, sp);
    }
  }

  emxInit_real_T2(sp, &x_j, 1, &yd_emlrtRTEI, true);
  iv49[0] = 1;
  iv49[1] = loop_ub;
  st.site = &kl_emlrtRSI;
  indexShapeCheck(&st, Data->size[0], iv49);
  i43 = x_j->size[0];
  x_j->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)x_j, i43, (int32_T)sizeof(real_T),
                    &xd_emlrtRTEI);
  for (i43 = 0; i43 < loop_ub; i43++) {
    x_j->data[i43] = Data->data[i43];
  }

  emxInit_real_T(sp, &a, 2, &xd_emlrtRTEI, true);

  /*  s[j]   1 <= j <= N. */
  st.site = &ll_emlrtRSI;
  i43 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = x_j->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i43, (int32_T)sizeof(real_T),
                    &xd_emlrtRTEI);
  k = x_j->size[0];
  for (i43 = 0; i43 < k; i43++) {
    a->data[a->size[0] * i43] = x_j->data[i43];
  }

  b_st.site = &rd_emlrtRSI;
  if (!(a->size[1] == loop_ub)) {
    if ((a->size[1] == 1) || (loop_ub == 1)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &bf_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &cf_emlrtRTEI,
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((a->size[1] == 1) || (loop_ub == 1)) {
    y = 0.0;
    for (i43 = 0; i43 < a->size[1]; i43++) {
      y += a->data[a->size[0] * i43] * x_j->data[i43];
    }

    p = y;
  } else {
    b_st.site = &ql_emlrtRSI;
    c_st.site = &rl_emlrtRSI;
    if (a->size[1] < 1) {
      p = 0.0;
    } else {
      n_t = (ptrdiff_t)a->size[1];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      p = ddot(&n_t, &a->data[0], &incx_t, &x_j->data[0], &incy_t);
    }
  }

  i43 = (int32_T)(lag_max + (1.0 - lag_min));
  emlrtForLoopVectorCheckR2012b(lag_min, 1.0, lag_max, mxDOUBLE_CLASS, i43,
    &ng_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T2(sp, &x_jr, 1, &ae_emlrtRTEI, true);
  while (k <= i43 - 1) {
    b_k = lag_min + (real_T)k;
    covrtLogFor(&emlrtCoverageInstance, 17U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 17U, 1);

    /*   to calculate the dot product of the signal and displaced version. */
    y = (b_k + N) - 1.0;
    if (b_k > y) {
      i44 = 0;
      i45 = 0;
    } else {
      i44 = Data->size[0];
      if (b_k != (int32_T)muDoubleScalarFloor(b_k)) {
        emlrtIntegerCheckR2012b(b_k, &ec_emlrtDCI, sp);
      }

      i46 = (int32_T)b_k;
      if (!((i46 >= 1) && (i46 <= i44))) {
        emlrtDynamicBoundsCheckR2012b(i46, 1, i44, &ii_emlrtBCI, sp);
      }

      i44 = i46 - 1;
      i46 = Data->size[0];
      if (y != (int32_T)muDoubleScalarFloor(y)) {
        emlrtIntegerCheckR2012b(y, &ec_emlrtDCI, sp);
      }

      i45 = (int32_T)y;
      if (!((i45 >= 1) && (i45 <= i46))) {
        emlrtDynamicBoundsCheckR2012b(i45, 1, i46, &ii_emlrtBCI, sp);
      }
    }

    iv50[0] = 1;
    iv50[1] = i45 - i44;
    st.site = &ml_emlrtRSI;
    indexShapeCheck(&st, Data->size[0], iv50);
    i46 = x_jr->size[0];
    x_jr->size[0] = i45 - i44;
    emxEnsureCapacity(sp, (emxArray__common *)x_jr, i46, (int32_T)sizeof(real_T),
                      &xd_emlrtRTEI);
    loop_ub = i45 - i44;
    for (i46 = 0; i46 < loop_ub; i46++) {
      x_jr->data[i46] = Data->data[i44 + i46];
    }

    /*  s[j]   -k <= j <= N+K-k-1. */
    st.site = &nl_emlrtRSI;
    i46 = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_j->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i46, (int32_T)sizeof(real_T),
                      &xd_emlrtRTEI);
    loop_ub = x_j->size[0];
    for (i46 = 0; i46 < loop_ub; i46++) {
      a->data[a->size[0] * i46] = x_j->data[i46];
    }

    b_st.site = &rd_emlrtRSI;
    if (!(a->size[1] == i45 - i44)) {
      if ((a->size[1] == 1) || (i45 - i44 == 1)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &bf_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &cf_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }
    }

    if ((a->size[1] == 1) || (i45 - i44 == 1)) {
      y = 0.0;
      for (i46 = 0; i46 < a->size[1]; i46++) {
        y += a->data[a->size[0] * i46] * x_jr->data[i46];
      }

      formula_nume = y;
    } else {
      b_st.site = &ql_emlrtRSI;
      c_st.site = &rl_emlrtRSI;
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
    st.site = &ol_emlrtRSI;
    i46 = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_jr->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i46, (int32_T)sizeof(real_T),
                      &xd_emlrtRTEI);
    loop_ub = x_jr->size[0];
    for (i46 = 0; i46 < loop_ub; i46++) {
      a->data[a->size[0] * i46] = x_jr->data[i46];
    }

    b_st.site = &rd_emlrtRSI;
    if (!(a->size[1] == i45 - i44)) {
      if ((a->size[1] == 1) || (i45 - i44 == 1)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &bf_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &cf_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }
    }

    if ((a->size[1] == 1) || (i45 - i44 == 1)) {
      y = 0.0;
      for (i44 = 0; i44 < a->size[1]; i44++) {
        y += a->data[a->size[0] * i44] * x_jr->data[i44];
      }

      q = y;
    } else {
      b_st.site = &ql_emlrtRSI;
      c_st.site = &rl_emlrtRSI;
      if (a->size[1] < 1) {
        q = 0.0;
      } else {
        n_t = (ptrdiff_t)a->size[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        q = ddot(&n_t, &a->data[0], &incx_t, &x_jr->data[0], &incy_t);
      }
    }

    formula_denom = p * q;

    /*  calculate the normalized crosscorrelation value using the TALKIN FORMULA. */
    st.site = &pl_emlrtRSI;
    if (formula_denom < 0.0) {
      b_st.site = &hd_emlrtRSI;
      error(&b_st);
    }

    i44 = Phi->size[1];
    if (b_k != (int32_T)muDoubleScalarFloor(b_k)) {
      emlrtIntegerCheckR2012b(b_k, &gc_emlrtDCI, sp);
    }

    i46 = (int32_T)b_k;
    if (!((i46 >= 1) && (i46 <= i44))) {
      emlrtDynamicBoundsCheckR2012b(i46, 1, i44, &ki_emlrtBCI, sp);
    }

    Phi->data[i46 - 1] = formula_nume / muDoubleScalarSqrt(formula_denom);
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&a);
  emxFree_real_T(&x_jr);
  emxFree_real_T(&x_j);
  covrtLogFor(&emlrtCoverageInstance, 17U, 0U, 0, 0);

  /*    To test using autocorrelation */
  /*     Phi = xcorr(s); */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (crs_corr.c) */
