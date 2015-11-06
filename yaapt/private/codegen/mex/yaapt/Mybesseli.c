/*
 * Mybesseli.c
 *
 * Code generation for function 'Mybesseli'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Mybesseli.h"
#include "rdivide.h"
#include "eml_error.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "pchip.h"
#include "any.h"
#include "exp.h"
#include "sqrt.h"
#include "fix.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo fe_emlrtRSI = { 361, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ge_emlrtRSI = { 350, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo he_emlrtRSI = { 349, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ie_emlrtRSI = { 322, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo je_emlrtRSI = { 321, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ke_emlrtRSI = { 315, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo le_emlrtRSI = { 242, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo me_emlrtRSI = { 238, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ne_emlrtRSI = { 201, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo oe_emlrtRSI = { 197, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo pe_emlrtRSI = { 190, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo qe_emlrtRSI = { 116, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo re_emlrtRSI = { 102, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo se_emlrtRSI = { 100, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo te_emlrtRSI = { 99, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ue_emlrtRSI = { 85, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ve_emlrtRSI = { 84, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo we_emlrtRSI = { 41, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRSInfo xe_emlrtRSI = { 230, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRSInfo gf_emlrtRSI = { 33, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo hf_emlrtRSI = { 47, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo if_emlrtRSI = { 54, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo jf_emlrtRSI = { 69, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtMCInfo q_emlrtMCI = { 239, 9, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtMCInfo x_emlrtMCI = { 53, 5, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtMCInfo y_emlrtMCI = { 52, 15, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRTEInfo e_emlrtRTEI = { 127, 5, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo ob_emlrtRTEI = { 1, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo pb_emlrtRTEI = { 51, 1, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRTEInfo qb_emlrtRTEI = { 63, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo rb_emlrtRTEI = { 84, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo sb_emlrtRTEI = { 86, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo tb_emlrtRTEI = { 110, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo ub_emlrtRTEI = { 188, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo vb_emlrtRTEI = { 229, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo wb_emlrtRTEI = { 236, 20, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo xb_emlrtRTEI = { 33, 6, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtECInfo u_emlrtECI = { -1, 99, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo v_emlrtECI = { -1, 197, 17, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo w_emlrtECI = { -1, 201, 18, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo x_emlrtECI = { -1, 238, 28, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo y_emlrtECI = { -1, 252, 23, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ab_emlrtECI = { -1, 260, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo bb_emlrtECI = { -1, 93, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtDCInfo t_emlrtDCI = { 220, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtBCInfo vd_emlrtBCI = { 1, 1, 220, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtECInfo cb_emlrtECI = { -1, 220, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo db_emlrtECI = { -1, 222, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtDCInfo u_emlrtDCI = { 258, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtECInfo eb_emlrtECI = { -1, 258, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo fb_emlrtECI = { -1, 313, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo gb_emlrtECI = { -1, 315, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo hb_emlrtECI = { -1, 321, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ib_emlrtECI = { -1, 330, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo jb_emlrtECI = { -1, 330, 16, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo kb_emlrtECI = { -1, 330, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo lb_emlrtECI = { -1, 352, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo mb_emlrtECI = { -1, 353, 22, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 86, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 93, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 101, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 258, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 220, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 222, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 315, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 315, 21, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 323, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 330, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 352, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 353, 24, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtRSInfo ak_emlrtRSI = { 53, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo uk_emlrtRSI = { 52, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo vk_emlrtRSI = { 239, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

/* Function Declarations */
static void eml_assert_valid_size_arg(const emlrtStack *sp, real_T varargin_1);

/* Function Definitions */

/*
 *
 */
static void eml_assert_valid_size_arg(const emlrtStack *sp, real_T varargin_1)
{
  boolean_T p;
  boolean_T guard1 = false;
  const mxArray *y;
  static const int32_T iv37[2] = { 1, 28 };

  const mxArray *m17;
  char_T cv57[28];
  int32_T i;
  static const char_T cv58[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I',
    'n', 'p', 'u', 't' };

  const mxArray *b_y;
  const mxArray *c_y;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) || muDoubleScalarIsInf
      (varargin_1)) {
    p = false;
  } else {
    p = true;
  }

  guard1 = false;
  if (p) {
    if ((-2.147483648E+9 > varargin_1) || (2.147483647E+9 < varargin_1)) {
      p = false;
    } else {
      p = true;
    }

    if (p) {
      p = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    p = false;
  }

  if (p) {
  } else {
    y = NULL;
    m17 = emlrtCreateCharArray(2, iv37);
    for (i = 0; i < 28; i++) {
      cv57[i] = cv58[i];
    }

    emlrtInitCharArrayR2013a(sp, 28, m17, cv57);
    emlrtAssign(&y, m17);
    b_y = NULL;
    m17 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)mxGetData(m17) = MIN_int32_T;
    emlrtAssign(&b_y, m17);
    c_y = NULL;
    m17 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)mxGetData(m17) = MAX_int32_T;
    emlrtAssign(&c_y, m17);
    st.site = &rk_emlrtRSI;
    b_st.site = &fl_emlrtRSI;
    f_error(&st, c_message(&b_st, y, b_y, c_y, &ab_emlrtMCI), &bb_emlrtMCI);
  }
}

/*
 * function output = Mybesseli(alpha,xx,scale)
 */
void Mybesseli(const emlrtStack *sp, emxArray_real_T *xx, emxArray_real_T
               *output)
{
  emxArray_real_T *b;
  int32_T i13;
  int32_T loop_ub;
  uint32_T resize_idx_0;
  int32_T i;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T idx;
  boolean_T overflow;
  boolean_T exitg8;
  boolean_T guard4 = false;
  const mxArray *y;
  const mxArray *m14;
  emxArray_int32_T *b_ii;
  emxArray_real_T *v;
  emxArray_real_T *tempc;
  int32_T i14;
  int32_T c_ii[1];
  emxArray_boolean_T *r8;
  boolean_T exitg7;
  boolean_T guard3 = false;
  const mxArray *b_y;
  emxArray_int32_T *d_ii;
  emxArray_real_T *b_x;
  const mxArray *c_y;
  static const int32_T iv29[2] = { 1, 36 };

  char_T cv45[36];
  static const char_T cv46[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *d_y;
  static const int32_T iv30[2] = { 1, 39 };

  char_T cv47[39];
  static const char_T cv48[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  real_T test;
  boolean_T exitg6;
  emxArray_real_T *p;
  real_T n;
  real_T en;
  const mxArray *e_y;
  static const int32_T iv31[2] = { 1, 36 };

  const mxArray *f_y;
  static const int32_T iv32[2] = { 1, 39 };

  boolean_T exitg5;
  emxArray_real_T *a;
  emxArray_boolean_T *b_p;
  emxArray_real_T *b_en;
  emxArray_real_T *c_en;
  int32_T exitg4;
  emxArray_real_T *c_p;
  emxArray_real_T *d_p;
  real_T empal;
  real_T emp2al;
  real_T nend;
  int32_T e_ii[1];
  emxArray_int32_T *r9;
  int32_T f_ii[2];
  int32_T b_v[2];
  emxArray_real_T *kk;
  emxArray_real_T *d_en;
  emxArray_real_T *e_en;
  emxArray_real_T *b_a;
  boolean_T exitg3;
  emxArray_real_T *b_b;
  int32_T g_ii[1];
  boolean_T exitg2;
  boolean_T guard2 = false;
  const mxArray *g_y;
  emxArray_int32_T *h_ii;
  emxArray_real_T *r10;
  int32_T i_ii[1];
  int32_T b_n[1];
  boolean_T exitg1;
  boolean_T guard1 = false;
  const mxArray *h_y;
  emxArray_int32_T *j_ii;
  int32_T k_ii[1];
  int32_T c_v[1];
  int32_T l_ii[1];
  int32_T d_v[1];
  emxArray_real_T *c_b;
  const mxArray *i_y;
  static const int32_T iv33[2] = { 1, 40 };

  char_T cv49[40];
  static const char_T cv50[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
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
  h_st.prev = &st;
  h_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  b_emxInit_real_T(sp, &b, 1, &qb_emlrtRTEI, true);

  /* BESSELI Modified Bessel functions of the first kind. */
  /* 	I = BESSELI(ALPHA,X) computes modified Bessel functions of the */
  /* 	first kind, I_sub_alpha(X) for real, non-negative order ALPHA */
  /* 	and argument X.  In general, both ALPHA and X may be vectors. */
  /* 	The output I is m-by-n with m = length(X), n = length(ALPHA) and */
  /* 	    I(k,j) = I_sub_alpha(j)(X(k)). */
  /* 	The elements of X can be any nonnegative real values in any order. */
  /* 	For ALPHA there are two important restrictions: the increment */
  /* 	in ALPHA must be one, i.e. ALPHA = alpha:1:alpha+n-1, and the */
  /* 	elements must also be in the range 0 <= ALPHA(j) <= 1000. */
  /*  */
  /* 	E = BESSELI(ALPHA,X,1) computes I_sub_alpha(X)*EXP(-X). */
  /*  */
  /* 	The relationship between the Bessel functions of the first kind is */
  /*  */
  /* 	    I_sub_alpha(x) = i^(-alpha) * J_sub_alpha(i*x) */
  /*  */
  /* 	Examples: */
  /*  */
  /* 	    besseli(3:9,[0:.2:9.8 10:.5:20],1) generates the entire  */
  /* 	    71-by-7 table on page 423 of Abramowitz and Stegun, */
  /* 	    "Handbook of Mathematical Functions." */
  /*  */
  /* 	See also: BESSELJ, BESSELY, BESSELK. */
  /*    Acknowledgement: */
  /*  */
  /* 	This program is based on a Fortran program by W. J. Cody and */
  /* 	L. Stoltz, Applied Mathematics Division, Argonne National */
  /* 	Laboratory, dated May 30, 1989.  Their references include: */
  /*  */
  /* 	   "A Note on backward recurrence algorithms," Olver, F. W. J., */
  /* 	   and Sookne, D. J., Math. Comp. 26, 1972, pp 941-947. */
  /*  */
  /* 	   "Bessel functions of real argument and integer order," */
  /* 	   Sookne, D. J., NBS Jour. of Res. B. 77b, 1973, pp. 125-132. */
  /*  */
  /* 	   "Algorithm 597, Sequence of modified Bessel functions of the */
  /* 	   "first kind," Cody, W. J., Trans. Math. Soft., 1983, pp. 242-245. */
  /*  */
  /* 	MATLAB version: C. Moler, 10/6/92. */
  /* 	Copyright (c) 1984-94 by The MathWorks, Inc. */
  /*  */
  /*   Check for real, non-negative arguments. */
  /*  */
  /*     if nargin < 3, scale = 0; end */
  /*     if any(imag(xx)) | any(xx < 0) | any(imag(alpha)) | any(alpha < 0) */
  /*        error('Input arguments must be real and nonnegative.') */
  /*     end */
  /*     if isempty(alpha) | isempty(xx) */
  /*        bk = [];  */
  /*        return */
  /*     end */
  /* 'Mybesseli:56' scale = 0; */
  /*  */
  /*   Break alpha into integer and fractional parts, */
  /*   and initialize result array. */
  /*  */
  /* 'Mybesseli:61' nfirst = fix(alpha(1)); */
  /* 'Mybesseli:62' nb = fix(alpha(length(alpha))) + 1; */
  /* 'Mybesseli:63' b = NaN*ones(length(xx),nb); */
  i13 = b->size[0];
  b->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i13, (int32_T)sizeof(real_T),
                    &ob_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    b->data[i13] = rtNaN;
  }

  /* 'Mybesseli:64' if ~(nb <= 1001) */
  /* 'Mybesseli:67' if length(alpha) > 1 */
  /*     resize = (length(alpha) == 1); */
  /* 'Mybesseli:73' resize_flag = (length(alpha) == 1); */
  /*     if resize, resize = size(xx); end */
  /* 'Mybesseli:75' if resize_flag */
  /* 'Mybesseli:76' resize = size(xx); */
  resize_idx_0 = (uint32_T)xx->size[0];

  /* 'Mybesseli:78' xx = xx(:); */
  i = xx->size[0];
  i13 = xx->size[0];
  xx->size[0] = i;
  emxEnsureCapacity(sp, (emxArray__common *)xx, i13, (int32_T)sizeof(real_T),
                    &ob_emlrtRTEI);
  b_emxInit_boolean_T(sp, &x, 1, &ob_emlrtRTEI, true);

  /*     b = NaN*ones(length(xx),nb); */
  /* 'Mybesseli:80' alpha = alpha(1) - nfirst; */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  /* 'Mybesseli:84' v = find(1.e3 < xx); */
  st.site = &ve_emlrtRSI;
  i13 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &ob_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    x->data[i13] = (1000.0 < xx->data[i13]);
  }

  emxInit_int32_T(&st, &ii, 1, &xb_emlrtRTEI, true);
  b_st.site = &we_emlrtRSI;
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  c_st.site = &xe_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  i = 1;
  exitg8 = false;
  while ((!exitg8) && (i <= x->size[0])) {
    guard4 = false;
    if (x->data[i - 1]) {
      idx++;
      ii->data[idx - 1] = i;
      if (idx >= x->size[0]) {
        exitg8 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4) {
      i++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    y = NULL;
    m14 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&y, m14);
    c_st.site = &vk_emlrtRSI;
    f_error(&c_st, y, &q_emlrtMCI);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &ob_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    emxInit_int32_T(&b_st, &b_ii, 1, &ob_emlrtRTEI, true);
    i13 = b_ii->size[0];
    b_ii->size[0] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i13, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    for (i13 = 0; i13 < loop_ub; i13++) {
      b_ii->data[i13] = ii->data[i13];
    }

    i13 = ii->size[0];
    ii->size[0] = b_ii->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    loop_ub = b_ii->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      ii->data[i13] = b_ii->data[i13];
    }

    emxFree_int32_T(&b_ii);
  }

  b_emxInit_real_T(&b_st, &v, 1, &rb_emlrtRTEI, true);
  i13 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i13, (int32_T)sizeof(real_T),
                    &ob_emlrtRTEI);
  loop_ub = ii->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    v->data[i13] = ii->data[i13];
  }

  /* 'Mybesseli:85' if any(v) */
  b_emxInit_real_T(sp, &tempc, 1, &wb_emlrtRTEI, true);
  st.site = &ue_emlrtRSI;
  if (b_any(&st, v)) {
    /* 'Mybesseli:86' x = xx(v); */
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = xx->size[0];
      i = (int32_T)v->data[i13];
      emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &wd_emlrtBCI, sp);
    }

    /* 'Mybesseli:87' if scale */
    /* 'Mybesseli:92' else */
    /* 'Mybesseli:93' b(v,:) = Inf*ones(length(v),nb); */
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = b->size[0];
      i = (int32_T)v->data[i13];
      ii->data[i13] = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &xd_emlrtBCI,
        sp) - 1;
    }

    i13 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      tempc->data[i13] = rtInf;
    }

    c_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(c_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &bb_emlrtECI, sp);
    loop_ub = tempc->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      b->data[ii->data[i13]] = tempc->data[i13];
    }
  }

  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  /* 'Mybesseli:99' v = find((1.e-4 <= xx) & (xx <= 1.e3)); */
  i13 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &ob_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    x->data[i13] = (0.0001 <= xx->data[i13]);
  }

  b_emxInit_boolean_T(sp, &r8, 1, &ob_emlrtRTEI, true);
  i13 = r8->size[0];
  r8->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r8, i13, (int32_T)sizeof(boolean_T),
                    &ob_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    r8->data[i13] = (xx->data[i13] <= 1000.0);
  }

  i13 = x->size[0];
  i14 = r8->size[0];
  emlrtSizeEqCheck1DFastR2012b(i13, i14, &u_emlrtECI, sp);
  st.site = &te_emlrtRSI;
  i13 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &ob_emlrtRTEI);
  loop_ub = x->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    x->data[i13] = (x->data[i13] && r8->data[i13]);
  }

  b_st.site = &we_emlrtRSI;
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  c_st.site = &xe_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  i = 1;
  exitg7 = false;
  while ((!exitg7) && (i <= x->size[0])) {
    guard3 = false;
    if (x->data[i - 1]) {
      idx++;
      ii->data[idx - 1] = i;
      if (idx >= x->size[0]) {
        exitg7 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3) {
      i++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    b_y = NULL;
    m14 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&b_y, m14);
    c_st.site = &vk_emlrtRSI;
    f_error(&c_st, b_y, &q_emlrtMCI);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &ob_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    emxInit_int32_T(&b_st, &d_ii, 1, &ob_emlrtRTEI, true);
    i13 = d_ii->size[0];
    d_ii->size[0] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)d_ii, i13, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    for (i13 = 0; i13 < loop_ub; i13++) {
      d_ii->data[i13] = ii->data[i13];
    }

    i13 = ii->size[0];
    ii->size[0] = d_ii->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    loop_ub = d_ii->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      ii->data[i13] = d_ii->data[i13];
    }

    emxFree_int32_T(&d_ii);
  }

  i13 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i13, (int32_T)sizeof(real_T),
                    &ob_emlrtRTEI);
  loop_ub = ii->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    v->data[i13] = ii->data[i13];
  }

  /* 'Mybesseli:100' if any(v) */
  st.site = &se_emlrtRSI;
  if (b_any(&st, v)) {
    b_emxInit_real_T(sp, &b_x, 1, &sb_emlrtRTEI, true);

    /* 'Mybesseli:101' x = xx(v); */
    i13 = b_x->size[0];
    b_x->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = xx->size[0];
      i = (int32_T)v->data[i13];
      b_x->data[i13] = xx->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i14,
        &yd_emlrtBCI, sp) - 1];
    }

    /* 'Mybesseli:102' magx = max(fix(x)); */
    i13 = tempc->size[0];
    tempc->size[0] = b_x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = b_x->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      tempc->data[i13] = b_x->data[i13];
    }

    c_fix(tempc);
    st.site = &re_emlrtRSI;
    b_st.site = &ye_emlrtRSI;
    c_st.site = &af_emlrtRSI;
    if ((tempc->size[0] == 1) || (tempc->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      c_y = NULL;
      m14 = emlrtCreateCharArray(2, iv29);
      for (i = 0; i < 36; i++) {
        cv45[i] = cv46[i];
      }

      emlrtInitCharArrayR2013a(&c_st, 36, m14, cv45);
      emlrtAssign(&c_y, m14);
      d_st.site = &gk_emlrtRSI;
      e_st.site = &mj_emlrtRSI;
      f_error(&d_st, b_message(&e_st, c_y, &r_emlrtMCI), &s_emlrtMCI);
    }

    if (tempc->size[0] > 0) {
    } else {
      d_y = NULL;
      m14 = emlrtCreateCharArray(2, iv30);
      for (i = 0; i < 39; i++) {
        cv47[i] = cv48[i];
      }

      emlrtInitCharArrayR2013a(&c_st, 39, m14, cv47);
      emlrtAssign(&d_y, m14);
      d_st.site = &fk_emlrtRSI;
      e_st.site = &lj_emlrtRSI;
      f_error(&d_st, b_message(&e_st, d_y, &t_emlrtMCI), &u_emlrtMCI);
    }

    d_st.site = &bf_emlrtRSI;
    i = 1;
    test = tempc->data[0];
    if (tempc->size[0] > 1) {
      if (muDoubleScalarIsNaN(tempc->data[0])) {
        f_st.site = &df_emlrtRSI;
        overflow = (tempc->size[0] > 2147483646);
        if (overflow) {
          g_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        idx = 2;
        exitg6 = false;
        while ((!exitg6) && (idx <= tempc->size[0])) {
          i = idx;
          if (!muDoubleScalarIsNaN(tempc->data[idx - 1])) {
            test = tempc->data[idx - 1];
            exitg6 = true;
          } else {
            idx++;
          }
        }
      }

      if (i < tempc->size[0]) {
        f_st.site = &cf_emlrtRSI;
        if (i + 1 > tempc->size[0]) {
          overflow = false;
        } else {
          overflow = (tempc->size[0] > 2147483646);
        }

        if (overflow) {
          g_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        while (i + 1 <= tempc->size[0]) {
          if (tempc->data[i] > test) {
            test = tempc->data[i];
          }

          i++;
        }
      }
    }

    b_emxInit_real_T(&d_st, &p, 1, &tb_emlrtRTEI, true);

    /*  */
    /*      Initialize the forward sweep, the p-sequence of Olver. */
    /*  */
    /* 'Mybesseli:106' nbmx = nb-magx; */
    /* 'Mybesseli:107' n = magx+1; */
    n = test + 1.0;

    /* 'Mybesseli:108' en = (n+n) + (alpha+alpha); */
    en = (test + 1.0) + (test + 1.0);

    /* 'Mybesseli:109' plast = 1; */
    /* 'Mybesseli:110' p = en ./ x; */
    d_rdivide(sp, en, b_x, p);

    /*  */
    /*      Calculate general significance test. */
    /*  */
    /* 'Mybesseli:114' test = 2/eps; */
    /* 'Mybesseli:115' if (2*magx > 80) */
    if (2.0 * test > 80.0) {
      /* 'Mybesseli:116' test = sqrt(test*max(p)); */
      st.site = &qe_emlrtRSI;
      b_st.site = &ye_emlrtRSI;
      c_st.site = &af_emlrtRSI;
      if ((p->size[0] == 1) || (p->size[0] != 1)) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        e_y = NULL;
        m14 = emlrtCreateCharArray(2, iv31);
        for (i = 0; i < 36; i++) {
          cv45[i] = cv46[i];
        }

        emlrtInitCharArrayR2013a(&c_st, 36, m14, cv45);
        emlrtAssign(&e_y, m14);
        d_st.site = &gk_emlrtRSI;
        e_st.site = &mj_emlrtRSI;
        f_error(&d_st, b_message(&e_st, e_y, &r_emlrtMCI), &s_emlrtMCI);
      }

      if (p->size[0] > 0) {
      } else {
        f_y = NULL;
        m14 = emlrtCreateCharArray(2, iv32);
        for (i = 0; i < 39; i++) {
          cv47[i] = cv48[i];
        }

        emlrtInitCharArrayR2013a(&c_st, 39, m14, cv47);
        emlrtAssign(&f_y, m14);
        d_st.site = &fk_emlrtRSI;
        e_st.site = &lj_emlrtRSI;
        f_error(&d_st, b_message(&e_st, f_y, &t_emlrtMCI), &u_emlrtMCI);
      }

      d_st.site = &bf_emlrtRSI;
      i = 1;
      test = p->data[0];
      if (p->size[0] > 1) {
        if (muDoubleScalarIsNaN(p->data[0])) {
          f_st.site = &df_emlrtRSI;
          overflow = (p->size[0] > 2147483646);
          if (overflow) {
            g_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }

          idx = 2;
          exitg5 = false;
          while ((!exitg5) && (idx <= p->size[0])) {
            i = idx;
            if (!muDoubleScalarIsNaN(p->data[idx - 1])) {
              test = p->data[idx - 1];
              exitg5 = true;
            } else {
              idx++;
            }
          }
        }

        if (i < p->size[0]) {
          f_st.site = &cf_emlrtRSI;
          if (i + 1 > p->size[0]) {
            overflow = false;
          } else {
            overflow = (p->size[0] > 2147483646);
          }

          if (overflow) {
            g_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }

          while (i + 1 <= p->size[0]) {
            if (p->data[i] > test) {
              test = p->data[i];
            }

            i++;
          }
        }
      }

      test *= 9.007199254740992E+15;
      st.site = &qe_emlrtRSI;
      c_sqrt(&st, &test);
    } else {
      /* 'Mybesseli:117' else */
      /* 'Mybesseli:118' test = test / 1.585^magx; */
      test = 9.007199254740992E+15 / muDoubleScalarPower(1.585, test);
    }

    b_emxInit_real_T(sp, &a, 1, &ub_emlrtRTEI, true);

    /*        if (nbmx >= 3) */
    /*  % */
    /*  %     Calculate p-sequence until n = nb-1. */
    /*  % */
    /*           tover = eps*realmax; */
    /*           nstart = magx+2; */
    /*           nend = nb - 1; */
    /*           for k = nstart:nend */
    /*              n = k; */
    /*              en = en + 2; */
    /*              pold = plast; */
    /*              plast = p; */
    /*              p = en * plast./x + pold; */
    /*              if any(p > tover) */
    /*  % */
    /*  %           To avoid overflow, divide p-sequence by tover. */
    /*  %           Calculate p-sequence until abs(p) > 1. */
    /*  % */
    /*                 tover = realmax; */
    /*                 p = p / tover; */
    /*                 plast = plast / tover; */
    /*                 psave = p; */
    /*                 psavel = plast; */
    /*                 nstart = n + 1; */
    /*                 while any(p <= 1); */
    /*                    n = n + 1; */
    /*                    en = en + 2; */
    /*                    pold = plast; */
    /*                    plast = p; */
    /*                    p = en * plast./x + pold; */
    /*                 end */
    /*                 tempb = en ./ x; */
    /*  % */
    /*  %              Calculate backward test, and find ncalc, */
    /*  %              the highest n such that the test is passed. */
    /*  % */
    /*                 test = pold*plast*eps; */
    /*                 test = test*(0.5-0.5/min(tempb*tempb)); */
    /*                 p = plast * tover; */
    /*                 n = n - 1; */
    /*                 en = en - 2; */
    /*                 nend = min(nb,n); */
    /*                 ncalc = nend + 1; */
    /*                 for l = nstart:nend */
    /*                    pold = psavel; */
    /*                    psavel = psave; */
    /*                    psave = en * psavel./x + pold; */
    /*                    if any(psave.*psavel > test); */
    /*                       ncalc = l-1; */
    /*                       test = 0; */
    /*                       break */
    /*                    end */
    /*                 end */
    /*                 break */
    /*              end */
    /*           end */
    /*           if ~test */
    /*              n = nend; */
    /*              en = (n+n) + (alpha+alpha); */
    /*  % */
    /*  %           Calculate special significance test for nbmx > 2. */
    /*  % */
    /*              test = max(test,max(sqrt(plast/eps).*sqrt(p+p))); */
    /*           end */
    /*        end */
    /*  */
    /*      Calculate p-sequence until significance test passed. */
    /*  */
    /* 'Mybesseli:188' a = p; */
    i13 = a->size[0];
    a->size[0] = p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = p->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      a->data[i13] = p->data[i13];
    }

    /* 'Mybesseli:189' count = 0; */
    idx = 0;

    /* 'Mybesseli:190' while any(p < test) */
    b_emxInit_boolean_T(sp, &b_p, 1, &ob_emlrtRTEI, true);
    b_emxInit_real_T(sp, &b_en, 1, &ob_emlrtRTEI, true);
    b_emxInit_real_T(sp, &c_en, 1, &ob_emlrtRTEI, true);
    do {
      exitg4 = 0;
      i13 = b_p->size[0];
      b_p->size[0] = p->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_p, i13, (int32_T)sizeof
                        (boolean_T), &ob_emlrtRTEI);
      loop_ub = p->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        b_p->data[i13] = (p->data[i13] < test);
      }

      st.site = &pe_emlrtRSI;
      if (c_any(&st, b_p)) {
        /* 'Mybesseli:191' n = n + 1; */
        n++;

        /* 'Mybesseli:192' en = en + 2; */
        en += 2.0;

        /* 'Mybesseli:193' if count == 1 */
        if (idx == 1) {
          /* 'Mybesseli:194' plast = a; */
          /* 'Mybesseli:195' pold = plast; */
          i13 = tempc->size[0];
          tempc->size[0] = a->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof
                            (real_T), &ob_emlrtRTEI);
          loop_ub = a->size[0];
          for (i13 = 0; i13 < loop_ub; i13++) {
            tempc->data[i13] = a->data[i13];
          }

          /* 'Mybesseli:196' a = p; */
          i13 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof
                            (real_T), &ob_emlrtRTEI);
          loop_ub = p->size[0];
          for (i13 = 0; i13 < loop_ub; i13++) {
            a->data[i13] = p->data[i13];
          }

          /* 'Mybesseli:197' p = en * a./x + pold; */
          i13 = c_en->size[0];
          c_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)c_en, i13, (int32_T)sizeof
                            (real_T), &ob_emlrtRTEI);
          loop_ub = p->size[0];
          for (i13 = 0; i13 < loop_ub; i13++) {
            c_en->data[i13] = en * p->data[i13];
          }

          st.site = &oe_emlrtRSI;
          e_rdivide(&st, c_en, b_x, p);
          i13 = p->size[0];
          i14 = tempc->size[0];
          emlrtSizeEqCheck1DFastR2012b(i13, i14, &v_emlrtECI, sp);
          i13 = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i13, (int32_T)sizeof
                            (real_T), &ob_emlrtRTEI);
          loop_ub = p->size[0];
          for (i13 = 0; i13 < loop_ub; i13++) {
            p->data[i13] += tempc->data[i13];
          }
        } else {
          /* 'Mybesseli:198' else */
          /* 'Mybesseli:199' count = 1; */
          idx = 1;

          /* 'Mybesseli:200' a = p; */
          i13 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof
                            (real_T), &ob_emlrtRTEI);
          loop_ub = p->size[0];
          for (i13 = 0; i13 < loop_ub; i13++) {
            a->data[i13] = p->data[i13];
          }

          /* 'Mybesseli:201' p = en * a./x + ones(length(a),1); */
          i13 = b_en->size[0];
          b_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)b_en, i13, (int32_T)sizeof
                            (real_T), &ob_emlrtRTEI);
          loop_ub = p->size[0];
          for (i13 = 0; i13 < loop_ub; i13++) {
            b_en->data[i13] = en * p->data[i13];
          }

          st.site = &ne_emlrtRSI;
          e_rdivide(&st, b_en, b_x, tempc);
          i = p->size[0];
          i13 = tempc->size[0];
          emlrtSizeEqCheck1DFastR2012b(i13, i, &w_emlrtECI, sp);
          i13 = p->size[0];
          p->size[0] = tempc->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i13, (int32_T)sizeof
                            (real_T), &ob_emlrtRTEI);
          loop_ub = tempc->size[0];
          for (i13 = 0; i13 < loop_ub; i13++) {
            p->data[i13] = tempc->data[i13] + 1.0;
          }
        }

        /*           a = p; */
        /*           p = en * a./x + pold; */
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
      } else {
        exitg4 = 1;
      }
    } while (exitg4 == 0);

    emxFree_real_T(&c_en);
    emxFree_real_T(&b_en);
    emxFree_boolean_T(&b_p);
    b_emxInit_real_T(sp, &c_p, 1, &ob_emlrtRTEI, true);

    /*  */
    /*      Initialize the backward recursion and the normalization sum. */
    /*  */
    /* 'Mybesseli:209' n = n + 1; */
    n++;

    /* 'Mybesseli:210' en = en + 2; */
    en += 2.0;

    /* 'Mybesseli:211' tempb = 0; */
    /* 'Mybesseli:212' tempa = 1 ./ p; */
    i13 = c_p->size[0];
    c_p->size[0] = p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)c_p, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = p->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      c_p->data[i13] = p->data[i13];
    }

    b_emxInit_real_T(sp, &d_p, 1, &ob_emlrtRTEI, true);
    d_rdivide(sp, 1.0, c_p, p);

    /* 'Mybesseli:213' em = n - 1; */
    test = n - 1.0;

    /* 'Mybesseli:214' empal = em + alpha; */
    empal = n - 1.0;

    /* 'Mybesseli:215' emp2al = (em - 1) + (alpha + alpha); */
    emp2al = (n - 1.0) - 1.0;

    /* 'Mybesseli:216' sum = tempa * empal * emp2al / em; */
    i13 = d_p->size[0];
    d_p->size[0] = p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)d_p, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = p->size[0];
    emxFree_real_T(&c_p);
    for (i13 = 0; i13 < loop_ub; i13++) {
      d_p->data[i13] = p->data[i13] * (n - 1.0) * ((n - 1.0) - 1.0);
    }

    c_rdivide(sp, d_p, n - 1.0, a);

    /* 'Mybesseli:217' nend = n - nb; */
    nend = n - 1.0;

    /* 'Mybesseli:218' skip = 0; */
    /* 'Mybesseli:219' if (nend < 0) */
    emxFree_real_T(&d_p);
    if (n - 1.0 < 0.0) {
      /* 'Mybesseli:220' b(v,n) = tempa; */
      i13 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                        &ob_emlrtRTEI);
      loop_ub = v->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        i14 = b->size[0];
        i = (int32_T)v->data[i13];
        ii->data[i13] = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14,
          &be_emlrtBCI, sp) - 1;
      }

      i13 = (int32_T)emlrtIntegerCheckFastR2012b(n, &t_emlrtDCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(i13, 1, 1, &vd_emlrtBCI, sp);
      e_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(e_ii, 1, *(int32_T (*)[1])p->size, 1,
        &cb_emlrtECI, sp);
      loop_ub = p->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        b->data[ii->data[i13]] = p->data[i13];
      }

      /* 'Mybesseli:221' nend = -nend; */
      /* 'Mybesseli:222' b(v,n+1:n+nend) = zeros(length(v),nend); */
      i13 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                        &ob_emlrtRTEI);
      loop_ub = v->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        i14 = b->size[0];
        i = (int32_T)v->data[i13];
        ii->data[i13] = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14,
          &ce_emlrtBCI, sp) - 1;
      }

      emxInit_int32_T(sp, &r9, 1, &ob_emlrtRTEI, true);
      i13 = r9->size[0];
      r9->size[0] = 0;
      emxEnsureCapacity(sp, (emxArray__common *)r9, i13, (int32_T)sizeof(int32_T),
                        &ob_emlrtRTEI);
      f_ii[0] = ii->size[0];
      f_ii[1] = 0;
      b_v[0] = v->size[0];
      b_v[1] = 0;
      emlrtSubAssignSizeCheckR2012b(f_ii, 2, b_v, 2, &db_emlrtECI, sp);
      emxFree_int32_T(&r9);
    } else {
      /* 'Mybesseli:223' else */
      /* 'Mybesseli:224' if (nend > 0) */
      if (n - 1.0 > 0.0) {
        b_emxInit_real_T(sp, &kk, 1, &vb_emlrtRTEI, true);

        /*  */
        /*            Recur backward via difference equation, calculating  */
        /*            (but not storing) b(n), until n = nb. */
        /*  */
        /* 'Mybesseli:229' kk= tempa; */
        i13 = kk->size[0];
        kk->size[0] = p->size[0];
        emxEnsureCapacity(sp, (emxArray__common *)kk, i13, (int32_T)sizeof
                          (real_T), &ob_emlrtRTEI);
        loop_ub = p->size[0];
        for (i13 = 0; i13 < loop_ub; i13++) {
          kk->data[i13] = p->data[i13];
        }

        /* 'Mybesseli:230' count2 = 0; */
        i = 0;

        /* 'Mybesseli:231' for l = 1:nend */
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, n - 1.0, mxDOUBLE_CLASS,
          (int32_T)(n - 1.0), &sd_emlrtRTEI, sp);
        idx = 0;
        b_emxInit_real_T(sp, &d_en, 1, &ob_emlrtRTEI, true);
        b_emxInit_real_T(sp, &e_en, 1, &ob_emlrtRTEI, true);
        b_emxInit_real_T(sp, &b_a, 1, &ob_emlrtRTEI, true);
        exitg3 = false;
        while ((!exitg3) && (idx <= (int32_T)nend - 1)) {
          /* 'Mybesseli:232' n = n - 1; */
          n--;

          /* 'Mybesseli:233' en = en - 2; */
          en -= 2.0;

          /* 'Mybesseli:234' if count2 == 1 */
          if (i == 1) {
            /* 'Mybesseli:235' tempb = kk; */
            /* 'Mybesseli:236' tempc = tempb; */
            i13 = tempc->size[0];
            tempc->size[0] = kk->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)
                              sizeof(real_T), &ob_emlrtRTEI);
            loop_ub = kk->size[0];
            for (i13 = 0; i13 < loop_ub; i13++) {
              tempc->data[i13] = kk->data[i13];
            }

            /* 'Mybesseli:237' kk = tempa; */
            i13 = kk->size[0];
            kk->size[0] = p->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)kk, i13, (int32_T)sizeof
                              (real_T), &ob_emlrtRTEI);
            loop_ub = p->size[0];
            for (i13 = 0; i13 < loop_ub; i13++) {
              kk->data[i13] = p->data[i13];
            }

            /* 'Mybesseli:238' tempa = (en*kk) ./ x + tempc; */
            i13 = e_en->size[0];
            e_en->size[0] = p->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)e_en, i13, (int32_T)sizeof
                              (real_T), &ob_emlrtRTEI);
            loop_ub = p->size[0];
            for (i13 = 0; i13 < loop_ub; i13++) {
              e_en->data[i13] = en * p->data[i13];
            }

            st.site = &me_emlrtRSI;
            e_rdivide(&st, e_en, b_x, p);
            i13 = p->size[0];
            i14 = tempc->size[0];
            emlrtSizeEqCheck1DFastR2012b(i13, i14, &x_emlrtECI, sp);
            i13 = p->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)p, i13, (int32_T)sizeof
                              (real_T), &ob_emlrtRTEI);
            loop_ub = p->size[0];
            for (i13 = 0; i13 < loop_ub; i13++) {
              p->data[i13] += tempc->data[i13];
            }
          } else {
            /* 'Mybesseli:239' else */
            /* 'Mybesseli:240' count2 = 1; */
            i = 1;

            /* 'Mybesseli:241' kk = tempa; */
            i13 = kk->size[0];
            kk->size[0] = p->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)kk, i13, (int32_T)sizeof
                              (real_T), &ob_emlrtRTEI);
            loop_ub = p->size[0];
            for (i13 = 0; i13 < loop_ub; i13++) {
              kk->data[i13] = p->data[i13];
            }

            /* 'Mybesseli:242' tempa = (en*kk) ./ x; */
            i13 = d_en->size[0];
            d_en->size[0] = p->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)d_en, i13, (int32_T)sizeof
                              (real_T), &ob_emlrtRTEI);
            loop_ub = p->size[0];
            for (i13 = 0; i13 < loop_ub; i13++) {
              d_en->data[i13] = en * p->data[i13];
            }

            st.site = &le_emlrtRSI;
            e_rdivide(&st, d_en, b_x, p);
          }

          /*                 tempc = tempb; */
          /*                 kk = tempa; */
          /*                 tempa = (en*kk) ./ x + tempc; */
          /* 'Mybesseli:247' em = em - 1; */
          test--;

          /* 'Mybesseli:248' emp2al = emp2al - 1; */
          emp2al--;

          /* 'Mybesseli:249' if (n == 1) */
          if (n == 1.0) {
            exitg3 = true;
          } else {
            /* 'Mybesseli:250' if (n == 2) */
            if (n == 2.0) {
              /* 'Mybesseli:250' emp2al = 1; */
              emp2al = 1.0;
            }

            /* 'Mybesseli:251' empal = empal - 1; */
            empal--;

            /* 'Mybesseli:252' sum = (sum + tempa*empal) * emp2al / em; */
            i13 = tempc->size[0];
            tempc->size[0] = p->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)
                              sizeof(real_T), &ob_emlrtRTEI);
            loop_ub = p->size[0];
            for (i13 = 0; i13 < loop_ub; i13++) {
              tempc->data[i13] = p->data[i13] * empal;
            }

            i13 = a->size[0];
            i14 = tempc->size[0];
            emlrtSizeEqCheck1DFastR2012b(i13, i14, &y_emlrtECI, sp);
            i13 = b_a->size[0];
            b_a->size[0] = a->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)b_a, i13, (int32_T)sizeof
                              (real_T), &ob_emlrtRTEI);
            loop_ub = a->size[0];
            for (i13 = 0; i13 < loop_ub; i13++) {
              b_a->data[i13] = (a->data[i13] + tempc->data[i13]) * emp2al;
            }

            c_rdivide(sp, b_a, test, a);
            idx++;
            emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
          }
        }

        emxFree_real_T(&b_a);
        emxFree_real_T(&e_en);
        emxFree_real_T(&d_en);
        emxFree_real_T(&kk);
      }

      /*  */
      /*         Store b(nb). */
      /*  */
      /* 'Mybesseli:258' b(v,n) = tempa; */
      i13 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                        &ob_emlrtRTEI);
      loop_ub = v->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        i14 = b->size[0];
        i = (int32_T)v->data[i13];
        ii->data[i13] = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14,
          &ae_emlrtBCI, sp) - 1;
      }

      i13 = (int32_T)emlrtIntegerCheckFastR2012b(n, &u_emlrtDCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(i13, 1, 1, &ud_emlrtBCI, sp);
      e_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(e_ii, 1, *(int32_T (*)[1])p->size, 1,
        &eb_emlrtECI, sp);
      loop_ub = p->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        b->data[ii->data[i13]] = p->data[i13];
      }

      /* 'Mybesseli:259' if (nb <= 1) */
      /* 'Mybesseli:260' sum = (sum + sum) + tempa; */
      i13 = a->size[0];
      i14 = p->size[0];
      emlrtSizeEqCheck1DFastR2012b(i13, i14, &ab_emlrtECI, sp);
      i13 = a->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof(real_T),
                        &ob_emlrtRTEI);
      loop_ub = a->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        a->data[i13] = (a->data[i13] + a->data[i13]) + p->data[i13];
      }

      /* 'Mybesseli:261' skip = -1; */
    }

    emxFree_real_T(&p);

    /* 'Mybesseli:280' if skip == 0 */
    /*  */
    /*      Calculate b(1) */
    /*  */
    /*        if skip == 0 */
    /*            b(v,1) = 2*empal*b(v,2) ./ x + b(v,3);  */
    /*        end */
    /*        if skip >= 0 */
    /*            sum = (sum + sum) + b(v,1);  */
    /*        end */
    /*  */
    /*      Normalize.  Divide all b(n) by sum. */
    /*  */
    /* 'Mybesseli:310' if (alpha ~= 0) */
    /* 'Mybesseli:313' if ~scale */
    /* 'Mybesseli:313' sum = sum .* exp(-x); */
    i13 = b_x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = b_x->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      b_x->data[i13] = -b_x->data[i13];
    }

    b_exp(b_x);
    i13 = a->size[0];
    i14 = b_x->size[0];
    emlrtSizeEqCheck1DFastR2012b(i13, i14, &fb_emlrtECI, sp);
    i13 = a->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = a->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      a->data[i13] *= b_x->data[i13];
    }

    emxFree_real_T(&b_x);

    /* 'Mybesseli:314' for n = 1:nb */
    /* 'Mybesseli:315' b(v,n) = b(v,n) ./ sum; */
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = b->size[0];
      i = (int32_T)v->data[i13];
      ii->data[i13] = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &de_emlrtBCI,
        sp) - 1;
    }

    b_emxInit_real_T(sp, &b_b, 1, &ob_emlrtRTEI, true);
    i13 = b_b->size[0];
    b_b->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_b, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = b->size[0];
      i = (int32_T)v->data[i13];
      b_b->data[i13] = b->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i14,
        &ee_emlrtBCI, sp) - 1];
    }

    st.site = &ke_emlrtRSI;
    e_rdivide(&st, b_b, a, tempc);
    g_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(g_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &gb_emlrtECI, sp);
    loop_ub = tempc->size[0];
    emxFree_real_T(&b_b);
    emxFree_real_T(&a);
    for (i13 = 0; i13 < loop_ub; i13++) {
      b->data[ii->data[i13]] = tempc->data[i13];
    }
  }

  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  /* 'Mybesseli:321' v = find((0 < xx) & (xx < 1.e-4)); */
  i13 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &ob_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    x->data[i13] = (0.0 < xx->data[i13]);
  }

  i13 = r8->size[0];
  r8->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r8, i13, (int32_T)sizeof(boolean_T),
                    &ob_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    r8->data[i13] = (xx->data[i13] < 0.0001);
  }

  i13 = x->size[0];
  i14 = r8->size[0];
  emlrtSizeEqCheck1DFastR2012b(i13, i14, &hb_emlrtECI, sp);
  st.site = &je_emlrtRSI;
  i13 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &ob_emlrtRTEI);
  loop_ub = x->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    x->data[i13] = (x->data[i13] && r8->data[i13]);
  }

  emxFree_boolean_T(&r8);
  b_st.site = &we_emlrtRSI;
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  c_st.site = &xe_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  i = 1;
  exitg2 = false;
  while ((!exitg2) && (i <= x->size[0])) {
    guard2 = false;
    if (x->data[i - 1]) {
      idx++;
      ii->data[idx - 1] = i;
      if (idx >= x->size[0]) {
        exitg2 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      i++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    g_y = NULL;
    m14 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&g_y, m14);
    c_st.site = &vk_emlrtRSI;
    f_error(&c_st, g_y, &q_emlrtMCI);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &ob_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    emxInit_int32_T(&b_st, &h_ii, 1, &ob_emlrtRTEI, true);
    i13 = h_ii->size[0];
    h_ii->size[0] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)h_ii, i13, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    for (i13 = 0; i13 < loop_ub; i13++) {
      h_ii->data[i13] = ii->data[i13];
    }

    i13 = ii->size[0];
    ii->size[0] = h_ii->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    loop_ub = h_ii->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      ii->data[i13] = h_ii->data[i13];
    }

    emxFree_int32_T(&h_ii);
  }

  i13 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i13, (int32_T)sizeof(real_T),
                    &ob_emlrtRTEI);
  loop_ub = ii->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    v->data[i13] = ii->data[i13];
  }

  /* 'Mybesseli:322' if any(v) */
  st.site = &ie_emlrtRSI;
  if (b_any(&st, v)) {
    /* 'Mybesseli:323' x = xx(v); */
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = xx->size[0];
      i = (int32_T)v->data[i13];
      emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &fe_emlrtBCI, sp);
    }

    /* 'Mybesseli:324' tempa = ones(length(x),1); */
    idx = v->size[0];

    /* 'Mybesseli:325' empal = 1 + alpha; */
    /* 'Mybesseli:326' halfx = 0.5 * x; */
    i13 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      tempc->data[i13] = 0.5 * xx->data[(int32_T)v->data[i13] - 1];
    }

    /* 'Mybesseli:327' if (alpha ~= 0) */
    /* 'Mybesseli:328' if scale */
    /* 'Mybesseli:329' tempb = halfx .* halfx; */
    i13 = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = tempc->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      tempc->data[i13] *= tempc->data[i13];
    }

    b_emxInit_real_T(sp, &r10, 1, &ob_emlrtRTEI, true);

    /* 'Mybesseli:330' b(v,1) = tempa + tempa.*tempb / empal; */
    i13 = tempc->size[0];
    emlrtSizeEqCheck1DFastR2012b(idx, i13, &ib_emlrtECI, sp);
    i13 = r10->size[0];
    r10->size[0] = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r10, i13, (int32_T)sizeof(real_T),
                      &ob_emlrtRTEI);
    loop_ub = tempc->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      r10->data[i13] = tempc->data[i13];
    }

    c_rdivide(sp, r10, 1.0, tempc);
    i13 = tempc->size[0];
    emlrtSizeEqCheck1DFastR2012b(idx, i13, &jb_emlrtECI, sp);
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    emxFree_real_T(&r10);
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = b->size[0];
      i = (int32_T)v->data[i13];
      ii->data[i13] = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &ge_emlrtBCI,
        sp) - 1;
    }

    i_ii[0] = ii->size[0];
    b_n[0] = idx;
    emlrtSubAssignSizeCheckR2012b(i_ii, 1, b_n, 1, &kb_emlrtECI, sp);
    for (i13 = 0; i13 < idx; i13++) {
      b->data[ii->data[i13]] = 1.0 + tempc->data[i13];
    }

    /* 'Mybesseli:331' if (nb > 1) */
  }

  emxFree_real_T(&tempc);

  /*  */
  /*   x == 0 */
  /*  */
  /* 'Mybesseli:349' v = find(xx == 0); */
  st.site = &he_emlrtRSI;
  i13 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &ob_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    x->data[i13] = (xx->data[i13] == 0.0);
  }

  b_st.site = &we_emlrtRSI;
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  c_st.site = &xe_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  i = 1;
  exitg1 = false;
  while ((!exitg1) && (i <= x->size[0])) {
    guard1 = false;
    if (x->data[i - 1]) {
      idx++;
      ii->data[idx - 1] = i;
      if (idx >= x->size[0]) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      i++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    h_y = NULL;
    m14 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&h_y, m14);
    c_st.site = &vk_emlrtRSI;
    f_error(&c_st, h_y, &q_emlrtMCI);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &ob_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    emxInit_int32_T(&b_st, &j_ii, 1, &ob_emlrtRTEI, true);
    i13 = j_ii->size[0];
    j_ii->size[0] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)j_ii, i13, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    for (i13 = 0; i13 < loop_ub; i13++) {
      j_ii->data[i13] = ii->data[i13];
    }

    i13 = ii->size[0];
    ii->size[0] = j_ii->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    loop_ub = j_ii->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      ii->data[i13] = j_ii->data[i13];
    }

    emxFree_int32_T(&j_ii);
  }

  emxFree_boolean_T(&x);
  i13 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i13, (int32_T)sizeof(real_T),
                    &ob_emlrtRTEI);
  loop_ub = ii->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    v->data[i13] = ii->data[i13];
  }

  /* 'Mybesseli:350' if any(v) */
  st.site = &ge_emlrtRSI;
  if (b_any(&st, v)) {
    /*  if alpha>0, I(alpha,0) = 0; I(0,0) = 1. */
    /* 'Mybesseli:352' b(v,:) = zeros(length(v),nb); */
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = b->size[0];
      i = (int32_T)v->data[i13];
      ii->data[i13] = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &he_emlrtBCI,
        sp) - 1;
    }

    k_ii[0] = ii->size[0];
    c_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(k_ii, 1, c_v, 1, &lb_emlrtECI, sp);
    i = v->size[0];
    for (i13 = 0; i13 < i; i13++) {
      b->data[ii->data[i13]] = 0.0;
    }

    /* 'Mybesseli:353' if alpha == 0 */
    /* 'Mybesseli:353' b(v,1) = ones(length(v),1); */
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &ob_emlrtRTEI);
    loop_ub = v->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      i14 = b->size[0];
      i = (int32_T)v->data[i13];
      ii->data[i13] = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &ie_emlrtBCI,
        sp) - 1;
    }

    l_ii[0] = ii->size[0];
    d_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(l_ii, 1, d_v, 1, &mb_emlrtECI, sp);
    i = v->size[0];
    for (i13 = 0; i13 < i; i13++) {
      b->data[ii->data[i13]] = 1.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&v);
  b_emxInit_real_T(sp, &c_b, 1, &ob_emlrtRTEI, true);

  /*  */
  /*   Return the requested index range */
  /*  */
  /* 'Mybesseli:358' b = b(:,nfirst+1:nb); */
  i = b->size[0];
  i13 = c_b->size[0];
  c_b->size[0] = i;
  emxEnsureCapacity(sp, (emxArray__common *)c_b, i13, (int32_T)sizeof(real_T),
                    &ob_emlrtRTEI);
  for (i13 = 0; i13 < i; i13++) {
    c_b->data[i13] = b->data[i13];
  }

  i13 = b->size[0];
  b->size[0] = c_b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i13, (int32_T)sizeof(real_T),
                    &ob_emlrtRTEI);
  loop_ub = c_b->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    b->data[i13] = c_b->data[i13];
  }

  emxFree_real_T(&c_b);

  /*     if resize */
  /* 'Mybesseli:360' if resize_flag */
  /* 'Mybesseli:361' output = reshape(b,resize(1),resize(2)); */
  st.site = &fe_emlrtRSI;
  b_st.site = &gf_emlrtRSI;
  c_st.site = &jf_emlrtRSI;
  eml_assert_valid_size_arg(&c_st, resize_idx_0);
  c_st.site = &jf_emlrtRSI;
  eml_assert_valid_size_arg(&c_st, 1.0);
  i = b->size[0];
  if (1 > i) {
    i = 1;
  }

  if (b->size[0] < i) {
  } else {
    i = b->size[0];
  }

  if ((int32_T)resize_idx_0 > i) {
    b_st.site = &hf_emlrtRSI;
    b_eml_error(&b_st);
  }

  if (1 > i) {
    b_st.site = &hf_emlrtRSI;
    b_eml_error(&b_st);
  }

  i13 = output->size[0] * output->size[1];
  output->size[0] = (int32_T)resize_idx_0;
  output->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)output, i13, (int32_T)sizeof(real_T),
                    &pb_emlrtRTEI);
  if (b->size[0] == (int32_T)resize_idx_0) {
  } else {
    i_y = NULL;
    m14 = emlrtCreateCharArray(2, iv33);
    for (i = 0; i < 40; i++) {
      cv49[i] = cv50[i];
    }

    emlrtInitCharArrayR2013a(&st, 40, m14, cv49);
    emlrtAssign(&i_y, m14);
    b_st.site = &uk_emlrtRSI;
    h_st.site = &ak_emlrtRSI;
    f_error(&b_st, b_message(&h_st, i_y, &x_emlrtMCI), &y_emlrtMCI);
  }

  b_st.site = &if_emlrtRSI;
  if (1 > b->size[0]) {
    overflow = false;
  } else {
    overflow = (b->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 0; i + 1 <= b->size[0]; i++) {
    output->data[i] = b->data[i];
  }

  emxFree_real_T(&b);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mybesseli.c) */
