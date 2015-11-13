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
#include "eml_error.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "mean.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo ci_emlrtRSI = { 49, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo di_emlrtRSI = { 52, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo ei_emlrtRSI = { 58, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo fi_emlrtRSI = { 61, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo gi_emlrtRSI = { 68, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRSInfo hi_emlrtRSI = { 61, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRSInfo ii_emlrtRSI = { 21, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRSInfo ji_emlrtRSI = { 30, "eml_xdotu",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\blas\\eml_xdotu.m" };

static emlrtRSInfo ki_emlrtRSI = { 1, "xdotu",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\xdotu.p" };

static emlrtRSInfo li_emlrtRSI = { 1, "xdot",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\xdot.p" };

static emlrtMCInfo qb_emlrtMCI = { 99, 13, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtMCInfo rb_emlrtMCI = { 98, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtMCInfo sb_emlrtMCI = { 104, 13, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtMCInfo tb_emlrtMCI = { 103, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRTEInfo ad_emlrtRTEI = { 1, 17, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo bd_emlrtRTEI = { 51, 1, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo cd_emlrtRTEI = { 57, 5, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 51, 8, "Data", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo kb_emlrtDCI = { 51, 8, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtECInfo ac_emlrtECI = { -1, 51, 8, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtRTEInfo yd_emlrtRTEI = { 54, 1, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtDCInfo lb_emlrtDCI = { 57, 12, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 57, 12, "Data", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtECInfo bc_emlrtECI = { -1, 57, 12, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m" };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 1, 1, "", "xdot",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\xdot.p", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 68, 5, "Phi", "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 0 };

static emlrtDCInfo mb_emlrtDCI = { 68, 5, "crs_corr",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m", 1 };

static emlrtRSInfo oj_emlrtRSI = { 99, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRSInfo pj_emlrtRSI = { 104, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRSInfo hk_emlrtRSI = { 98, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

static emlrtRSInfo ik_emlrtRSI = { 103, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

/* Function Definitions */

/*
 * function[Phi] = crs_corr(Data, lag_min, lag_max)
 */
void crs_corr(const emlrtStack *sp, emxArray_real_T *Data, real_T lag_min,
              real_T lag_max, emxArray_real_T *Phi)
{
  real_T N;
  int32_T i31;
  int32_T i;
  int32_T loop_ub;
  real_T q;
  int32_T i32;
  emxArray_real_T *x_j;
  emxArray_real_T *a;
  const mxArray *y;
  static const int32_T iv69[2] = { 1, 45 };

  const mxArray *m32;
  char_T cv108[45];
  static const char_T cv109[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D',
    'y', 'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p',
    'a', 'n', 's', 'i', 'o', 'n' };

  const mxArray *b_y;
  static const int32_T iv70[2] = { 1, 21 };

  char_T cv110[21];
  static const char_T cv111[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  real_T p;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * xix0_t;
  double * yiy0_t;
  int32_T k;
  emxArray_real_T *x_jr;
  real_T b_k;
  int32_T i33;
  const mxArray *c_y;
  static const int32_T iv71[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv72[2] = { 1, 21 };

  real_T formula_nume;
  const mxArray *e_y;
  static const int32_T iv73[2] = { 1, 45 };

  const mxArray *f_y;
  static const int32_T iv74[2] = { 1, 21 };

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
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
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
  i31 = Phi->size[0] * Phi->size[1];
  Phi->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)Phi, i31, (int32_T)sizeof(real_T),
                    &ad_emlrtRTEI);
  i = Data->size[0];
  i31 = Phi->size[0] * Phi->size[1];
  Phi->size[1] = i;
  emxEnsureCapacity(sp, (emxArray__common *)Phi, i31, (int32_T)sizeof(real_T),
                    &ad_emlrtRTEI);
  loop_ub = Data->size[0];
  for (i31 = 0; i31 < loop_ub; i31++) {
    Phi->data[i31] = 0.0;
  }

  /*  Remove DC level */
  /* 'crs_corr:49' Data = Data- mean(Data); */
  st.site = &ci_emlrtRSI;
  q = c_mean(&st, Data);
  i31 = Data->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Data, i31, (int32_T)sizeof(real_T),
                    &ad_emlrtRTEI);
  loop_ub = Data->size[0];
  for (i31 = 0; i31 < loop_ub; i31++) {
    Data->data[i31] -= q;
  }

  /* 'crs_corr:51' x_j =  Data(1:N); */
  if (1.0 > N) {
    loop_ub = 0;
  } else {
    i31 = Data->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i31, &qg_emlrtBCI, sp);
    i31 = Data->size[0];
    i32 = (int32_T)emlrtIntegerCheckFastR2012b(N, &kb_emlrtDCI, sp);
    loop_ub = emlrtDynamicBoundsCheckFastR2012b(i32, 1, i31, &qg_emlrtBCI, sp);
  }

  b_emxInit_real_T(sp, &x_j, 1, &bd_emlrtRTEI, true);
  emlrtVectorVectorIndexCheckR2012b(Data->size[0], 1, 1, loop_ub, &ac_emlrtECI,
    sp);
  i31 = x_j->size[0];
  x_j->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)x_j, i31, (int32_T)sizeof(real_T),
                    &ad_emlrtRTEI);
  for (i31 = 0; i31 < loop_ub; i31++) {
    x_j->data[i31] = Data->data[i31];
  }

  emxInit_real_T(sp, &a, 2, &ad_emlrtRTEI, true);

  /*  s[j]   1 <= j <= N. */
  /* 'crs_corr:52' p = x_j' * x_j; */
  st.site = &di_emlrtRSI;
  i31 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = x_j->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i31, (int32_T)sizeof(real_T),
                    &ad_emlrtRTEI);
  i = x_j->size[0];
  for (i31 = 0; i31 < i; i31++) {
    a->data[a->size[0] * i31] = x_j->data[i31];
  }

  b_st.site = &ii_emlrtRSI;
  if (!(a->size[1] == loop_ub)) {
    if ((a->size[1] == 1) || (loop_ub == 1)) {
      y = NULL;
      m32 = emlrtCreateCharArray(2, iv69);
      for (i = 0; i < 45; i++) {
        cv108[i] = cv109[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 45, m32, cv108);
      emlrtAssign(&y, m32);
      c_st.site = &hk_emlrtRSI;
      d_st.site = &oj_emlrtRSI;
      f_error(&c_st, b_message(&d_st, y, &qb_emlrtMCI), &rb_emlrtMCI);
    } else {
      b_y = NULL;
      m32 = emlrtCreateCharArray(2, iv70);
      for (i = 0; i < 21; i++) {
        cv110[i] = cv111[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 21, m32, cv110);
      emlrtAssign(&b_y, m32);
      c_st.site = &ik_emlrtRSI;
      d_st.site = &pj_emlrtRSI;
      f_error(&c_st, b_message(&d_st, b_y, &sb_emlrtMCI), &tb_emlrtMCI);
    }
  }

  if ((a->size[1] == 1) || (loop_ub == 1)) {
    p = 0.0;
    for (i31 = 0; i31 < a->size[1]; i31++) {
      p += a->data[a->size[0] * i31] * x_j->data[i31];
    }
  } else {
    b_st.site = &hi_emlrtRSI;
    c_st.site = &ji_emlrtRSI;
    e_st.site = &ki_emlrtRSI;
    if (a->size[1] < 1) {
      p = 0.0;
    } else {
      f_st.site = &li_emlrtRSI;
      n_t = (ptrdiff_t)(a->size[1]);
      incx_t = (ptrdiff_t)(1);
      incy_t = (ptrdiff_t)(1);
      xix0_t = (double *)(&a->data[0]);
      emlrtDynamicBoundsCheckFastR2012b(1, 1, loop_ub, &sg_emlrtBCI, &f_st);
      yiy0_t = (double *)(&x_j->data[0]);
      p = ddot(&n_t, xix0_t, &incx_t, yiy0_t, &incy_t);
    }
  }

  /* 'crs_corr:54' for k = lag_min:lag_max */
  i31 = (int32_T)(lag_max + (1.0 - lag_min));
  emlrtForLoopVectorCheckR2012b(lag_min, 1.0, lag_max, mxDOUBLE_CLASS, i31,
    &yd_emlrtRTEI, sp);
  k = 0;
  b_emxInit_real_T(sp, &x_jr, 1, &cd_emlrtRTEI, true);
  while (k <= i31 - 1) {
    b_k = lag_min + (real_T)k;

    /*   to calculate the dot product of the signal and displaced version. */
    /* 'crs_corr:57' x_jr = Data(k:k+N-1); */
    q = (b_k + N) - 1.0;
    if (b_k > q) {
      i32 = 1;
      i33 = 1;
    } else {
      i32 = Data->size[0];
      i33 = (int32_T)emlrtIntegerCheckFastR2012b(b_k, &lb_emlrtDCI, sp);
      i32 = emlrtDynamicBoundsCheckFastR2012b(i33, 1, i32, &rg_emlrtBCI, sp);
      i33 = Data->size[0];
      i = (int32_T)emlrtIntegerCheckFastR2012b(q, &lb_emlrtDCI, sp);
      i33 = emlrtDynamicBoundsCheckFastR2012b(i, 1, i33, &rg_emlrtBCI, sp) + 1;
    }

    emlrtVectorVectorIndexCheckR2012b(Data->size[0], 1, 1, i33 - i32,
      &bc_emlrtECI, sp);
    i = x_jr->size[0];
    x_jr->size[0] = i33 - i32;
    emxEnsureCapacity(sp, (emxArray__common *)x_jr, i, (int32_T)sizeof(real_T),
                      &ad_emlrtRTEI);
    loop_ub = i33 - i32;
    for (i = 0; i < loop_ub; i++) {
      x_jr->data[i] = Data->data[(i32 + i) - 1];
    }

    /*  s[j]   -k <= j <= N+K-k-1. */
    /* 'crs_corr:58' formula_nume = x_j' * x_jr; */
    st.site = &ei_emlrtRSI;
    i = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_j->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i, (int32_T)sizeof(real_T),
                      &ad_emlrtRTEI);
    loop_ub = x_j->size[0];
    for (i = 0; i < loop_ub; i++) {
      a->data[a->size[0] * i] = x_j->data[i];
    }

    b_st.site = &ii_emlrtRSI;
    if (!(a->size[1] == i33 - i32)) {
      if ((a->size[1] == 1) || (i33 - i32 == 1)) {
        c_y = NULL;
        m32 = emlrtCreateCharArray(2, iv71);
        for (i = 0; i < 45; i++) {
          cv108[i] = cv109[i];
        }

        emlrtInitCharArrayR2013a(&b_st, 45, m32, cv108);
        emlrtAssign(&c_y, m32);
        c_st.site = &hk_emlrtRSI;
        d_st.site = &oj_emlrtRSI;
        f_error(&c_st, b_message(&d_st, c_y, &qb_emlrtMCI), &rb_emlrtMCI);
      } else {
        d_y = NULL;
        m32 = emlrtCreateCharArray(2, iv72);
        for (i = 0; i < 21; i++) {
          cv110[i] = cv111[i];
        }

        emlrtInitCharArrayR2013a(&b_st, 21, m32, cv110);
        emlrtAssign(&d_y, m32);
        c_st.site = &ik_emlrtRSI;
        d_st.site = &pj_emlrtRSI;
        f_error(&c_st, b_message(&d_st, d_y, &sb_emlrtMCI), &tb_emlrtMCI);
      }
    }

    if ((a->size[1] == 1) || (i33 - i32 == 1)) {
      formula_nume = 0.0;
      for (i = 0; i < a->size[1]; i++) {
        formula_nume += a->data[a->size[0] * i] * x_jr->data[i];
      }
    } else {
      b_st.site = &hi_emlrtRSI;
      c_st.site = &ji_emlrtRSI;
      e_st.site = &ki_emlrtRSI;
      if (a->size[1] < 1) {
        formula_nume = 0.0;
      } else {
        f_st.site = &li_emlrtRSI;
        n_t = (ptrdiff_t)(a->size[1]);
        incx_t = (ptrdiff_t)(1);
        incy_t = (ptrdiff_t)(1);
        xix0_t = (double *)(&a->data[0]);
        i = i33 - i32;
        emlrtDynamicBoundsCheckFastR2012b(1, 1, i, &sg_emlrtBCI, &f_st);
        yiy0_t = (double *)(&x_jr->data[0]);
        formula_nume = ddot(&n_t, xix0_t, &incx_t, yiy0_t, &incy_t);
      }
    }

    /*  the normalization factor for the denominator. */
    /* 'crs_corr:61' q = x_jr' * x_jr; */
    st.site = &fi_emlrtRSI;
    i = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = x_jr->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i, (int32_T)sizeof(real_T),
                      &ad_emlrtRTEI);
    loop_ub = x_jr->size[0];
    for (i = 0; i < loop_ub; i++) {
      a->data[a->size[0] * i] = x_jr->data[i];
    }

    b_st.site = &ii_emlrtRSI;
    if (!(a->size[1] == i33 - i32)) {
      if ((a->size[1] == 1) || (i33 - i32 == 1)) {
        e_y = NULL;
        m32 = emlrtCreateCharArray(2, iv73);
        for (i = 0; i < 45; i++) {
          cv108[i] = cv109[i];
        }

        emlrtInitCharArrayR2013a(&b_st, 45, m32, cv108);
        emlrtAssign(&e_y, m32);
        c_st.site = &hk_emlrtRSI;
        d_st.site = &oj_emlrtRSI;
        f_error(&c_st, b_message(&d_st, e_y, &qb_emlrtMCI), &rb_emlrtMCI);
      } else {
        f_y = NULL;
        m32 = emlrtCreateCharArray(2, iv74);
        for (i = 0; i < 21; i++) {
          cv110[i] = cv111[i];
        }

        emlrtInitCharArrayR2013a(&b_st, 21, m32, cv110);
        emlrtAssign(&f_y, m32);
        c_st.site = &ik_emlrtRSI;
        d_st.site = &pj_emlrtRSI;
        f_error(&c_st, b_message(&d_st, f_y, &sb_emlrtMCI), &tb_emlrtMCI);
      }
    }

    if ((a->size[1] == 1) || (i33 - i32 == 1)) {
      q = 0.0;
      for (i32 = 0; i32 < a->size[1]; i32++) {
        q += a->data[a->size[0] * i32] * x_jr->data[i32];
      }
    } else {
      b_st.site = &hi_emlrtRSI;
      c_st.site = &ji_emlrtRSI;
      e_st.site = &ki_emlrtRSI;
      if (a->size[1] < 1) {
        q = 0.0;
      } else {
        f_st.site = &li_emlrtRSI;
        n_t = (ptrdiff_t)(a->size[1]);
        incx_t = (ptrdiff_t)(1);
        incy_t = (ptrdiff_t)(1);
        xix0_t = (double *)(&a->data[0]);
        i32 = i33 - i32;
        emlrtDynamicBoundsCheckFastR2012b(1, 1, i32, &sg_emlrtBCI, &f_st);
        yiy0_t = (double *)(&x_jr->data[0]);
        q = ddot(&n_t, xix0_t, &incx_t, yiy0_t, &incy_t);
      }
    }

    /* 'crs_corr:63' formula_denom= p*q; */
    q *= p;

    /* 'crs_corr:65' formula_denom = formula_denom+ eps1; */
    /*  calculate the normalized crosscorrelation value using the TALKIN FORMULA. */
    /* 'crs_corr:68' Phi(k)=((formula_nume)/(sqrt(formula_denom))); */
    st.site = &gi_emlrtRSI;
    if (q < 0.0) {
      b_st.site = &p_emlrtRSI;
      eml_error(&b_st);
    }

    i32 = Phi->size[1];
    i33 = (int32_T)emlrtIntegerCheckFastR2012b(b_k, &mb_emlrtDCI, sp);
    Phi->data[emlrtDynamicBoundsCheckFastR2012b(i33, 1, i32, &tg_emlrtBCI, sp) -
      1] = formula_nume / muDoubleScalarSqrt(q);
    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&a);
  emxFree_real_T(&x_jr);
  emxFree_real_T(&x_j);

  /*    To test using autocorrelation */
  /*     Phi = xcorr(s); */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (crs_corr.c) */
