/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "error1.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "any.h"
#include "indexShapeCheck.h"
#include "exp.h"
#include "sqrt.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ie_emlrtRSI = { 361, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo je_emlrtRSI = { 350, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ke_emlrtRSI = { 349, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo le_emlrtRSI = { 322, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo me_emlrtRSI = { 321, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ne_emlrtRSI = { 315, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo oe_emlrtRSI = { 313, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo pe_emlrtRSI = { 242, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo qe_emlrtRSI = { 238, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo re_emlrtRSI = { 201, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo se_emlrtRSI = { 197, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo te_emlrtRSI = { 190, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ue_emlrtRSI = { 116, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ve_emlrtRSI = { 102, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo we_emlrtRSI = { 100, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo xe_emlrtRSI = { 99, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ye_emlrtRSI = { 85, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo af_emlrtRSI = { 84, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo bf_emlrtRSI = { 234, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRSInfo cf_emlrtRSI = { 10, "fix",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\fix.m" };

static emlrtRSInfo jf_emlrtRSI = { 39, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo kf_emlrtRSI = { 53, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo lf_emlrtRSI = { 100, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo mf_emlrtRSI = { 123, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRTEInfo f_emlrtRTEI = { 253, 13, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo jb_emlrtRTEI = { 1, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo kb_emlrtRTEI = { 63, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo lb_emlrtRTEI = { 84, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo mb_emlrtRTEI = { 86, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo nb_emlrtRTEI = { 110, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo ob_emlrtRTEI = { 188, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo pb_emlrtRTEI = { 212, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo qb_emlrtRTEI = { 236, 20, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo rb_emlrtRTEI = { 36, 6, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo fe_emlrtRTEI = { 63, 15, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRTEInfo ge_emlrtRTEI = { 243, 9, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtECInfo q_emlrtECI = { -1, 99, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo r_emlrtECI = { -1, 197, 17, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo s_emlrtECI = { -1, 201, 18, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo t_emlrtECI = { -1, 238, 28, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo u_emlrtECI = { -1, 252, 23, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo v_emlrtECI = { -1, 260, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo w_emlrtECI = { -1, 93, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtDCInfo t_emlrtDCI = { 220, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtBCInfo rd_emlrtBCI = { 1, 1, 220, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtECInfo x_emlrtECI = { -1, 220, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo y_emlrtECI = { -1, 222, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtDCInfo u_emlrtDCI = { 258, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtECInfo ab_emlrtECI = { -1, 258, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo bb_emlrtECI = { -1, 313, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo cb_emlrtECI = { -1, 315, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo db_emlrtECI = { -1, 321, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo eb_emlrtECI = { -1, 330, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo fb_emlrtECI = { -1, 330, 16, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo gb_emlrtECI = { -1, 330, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo hb_emlrtECI = { -1, 352, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ib_emlrtECI = { -1, 353, 22, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 86, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 93, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 101, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 258, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 220, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 222, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 315, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 315, 21, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 323, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 330, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 352, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 353, 24, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

/* Function Definitions */

/*
 * function output = Mybesseli(alpha,xx,scale)
 */
void Mybesseli(const emlrtStack *sp, emxArray_real_T *xx, emxArray_real_T
               *output)
{
  emxArray_real_T *b;
  int32_T i13;
  int32_T idx;
  uint32_T resize_idx_0;
  int32_T ixstart;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T nx;
  boolean_T overflow;
  boolean_T exitg8;
  boolean_T guard4 = false;
  int32_T iv19[2];
  emxArray_real_T *v;
  emxArray_real_T *tempc;
  int32_T b_ii[1];
  emxArray_boolean_T *r7;
  boolean_T exitg7;
  boolean_T guard3 = false;
  int32_T iv20[2];
  emxArray_real_T *b_x;
  real_T mtmp;
  boolean_T exitg6;
  emxArray_real_T *p;
  real_T n;
  real_T en;
  boolean_T exitg5;
  real_T test;
  emxArray_real_T *a;
  int32_T count;
  emxArray_boolean_T *b_p;
  emxArray_real_T *b_en;
  emxArray_real_T *c_en;
  int32_T exitg4;
  emxArray_real_T *tempa;
  emxArray_real_T *b_tempa;
  real_T em;
  real_T empal;
  real_T emp2al;
  real_T nend;
  int32_T c_ii[1];
  emxArray_int32_T *r8;
  int32_T d_ii[2];
  int32_T b_v[2];
  int32_T count2;
  int32_T l;
  emxArray_real_T *d_en;
  emxArray_real_T *e_en;
  emxArray_real_T *b_a;
  boolean_T exitg3;
  emxArray_real_T *b_b;
  int32_T e_ii[1];
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv21[2];
  emxArray_real_T *r9;
  int32_T f_ii[1];
  int32_T c_v[1];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv22[2];
  int32_T g_ii[1];
  int32_T d_v[1];
  int32_T h_ii[1];
  int32_T e_v[1];
  emxArray_real_T *c_b;
  uint32_T b_idx_0;
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
  emxInit_real_T1(sp, &b, 1, &kb_emlrtRTEI, true);

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
                    &jb_emlrtRTEI);
  idx = xx->size[0];
  for (i13 = 0; i13 < idx; i13++) {
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
  ixstart = xx->size[0];
  i13 = xx->size[0];
  xx->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)xx, i13, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  emxInit_boolean_T1(sp, &x, 1, &jb_emlrtRTEI, true);

  /*     b = NaN*ones(length(xx),nb); */
  /* 'Mybesseli:80' alpha = alpha(1) - nfirst; */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  /* 'Mybesseli:84' v = find(1.e3 < xx); */
  st.site = &af_emlrtRSI;
  i13 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &jb_emlrtRTEI);
  idx = xx->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    x->data[i13] = (1000.0 < xx->data[i13]);
  }

  emxInit_int32_T(&st, &ii, 1, &rb_emlrtRTEI, true);
  b_st.site = &y_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &jb_emlrtRTEI);
  c_st.site = &bf_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  ixstart = 1;
  exitg8 = false;
  while ((!exitg8) && (ixstart <= nx)) {
    guard4 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg8 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4) {
      ixstart++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &ge_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &jb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i13 = 0;
    } else {
      i13 = idx;
    }

    iv19[0] = 1;
    iv19[1] = i13;
    c_st.site = &ab_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv19);
    nx = ii->size[0];
    ii->size[0] = i13;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &f_emlrtRTEI);
  }

  emxInit_real_T1(&b_st, &v, 1, &lb_emlrtRTEI, true);
  i13 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i13, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  idx = ii->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    v->data[i13] = ii->data[i13];
  }

  /* 'Mybesseli:85' if any(v) */
  emxInit_real_T1(sp, &tempc, 1, &qb_emlrtRTEI, true);
  st.site = &ye_emlrtRSI;
  if (c_any(&st, v)) {
    /* 'Mybesseli:86' x = xx(v); */
    ixstart = xx->size[0];
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &sd_emlrtBCI, sp);
      }
    }

    /* 'Mybesseli:87' if scale */
    /* 'Mybesseli:92' else */
    /* 'Mybesseli:93' b(v,:) = Inf*ones(length(v),nb); */
    ixstart = b->size[0];
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &td_emlrtBCI, sp);
      }

      ii->data[i13] = nx - 1;
    }

    i13 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      tempc->data[i13] = rtInf;
    }

    b_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(b_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &w_emlrtECI, sp);
    idx = tempc->size[0];
    for (i13 = 0; i13 < idx; i13++) {
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
                    &jb_emlrtRTEI);
  idx = xx->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    x->data[i13] = (0.0001 <= xx->data[i13]);
  }

  emxInit_boolean_T1(sp, &r7, 1, &jb_emlrtRTEI, true);
  i13 = r7->size[0];
  r7->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r7, i13, (int32_T)sizeof(boolean_T),
                    &jb_emlrtRTEI);
  idx = xx->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    r7->data[i13] = (xx->data[i13] <= 1000.0);
  }

  i13 = x->size[0];
  nx = r7->size[0];
  if (i13 != nx) {
    emlrtSizeEqCheck1DR2012b(i13, nx, &q_emlrtECI, sp);
  }

  st.site = &xe_emlrtRSI;
  i13 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &jb_emlrtRTEI);
  idx = x->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    x->data[i13] = (x->data[i13] && r7->data[i13]);
  }

  b_st.site = &y_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &jb_emlrtRTEI);
  c_st.site = &bf_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  ixstart = 1;
  exitg7 = false;
  while ((!exitg7) && (ixstart <= nx)) {
    guard3 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg7 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3) {
      ixstart++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &ge_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &jb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i13 = 0;
    } else {
      i13 = idx;
    }

    iv20[0] = 1;
    iv20[1] = i13;
    c_st.site = &ab_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv20);
    nx = ii->size[0];
    ii->size[0] = i13;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &f_emlrtRTEI);
  }

  i13 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i13, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  idx = ii->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    v->data[i13] = ii->data[i13];
  }

  /* 'Mybesseli:100' if any(v) */
  st.site = &we_emlrtRSI;
  if (c_any(&st, v)) {
    emxInit_real_T1(sp, &b_x, 1, &mb_emlrtRTEI, true);

    /* 'Mybesseli:101' x = xx(v); */
    ixstart = xx->size[0];
    i13 = b_x->size[0];
    b_x->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i13, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &ud_emlrtBCI, sp);
      }

      b_x->data[i13] = xx->data[nx - 1];
    }

    /* 'Mybesseli:102' magx = max(fix(x)); */
    st.site = &ve_emlrtRSI;
    b_st.site = &cf_emlrtRSI;
    i13 = tempc->size[0];
    tempc->size[0] = b_x->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)tempc, i13, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    idx = b_x->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      tempc->data[i13] = b_x->data[i13];
    }

    nx = v->size[0];
    c_st.site = &pc_emlrtRSI;
    if (1 > v->size[0]) {
      overflow = false;
    } else {
      overflow = (v->size[0] > 2147483646);
    }

    if (overflow) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (ixstart = 0; ixstart + 1 <= nx; ixstart++) {
      if (tempc->data[ixstart] < 0.0) {
        mtmp = muDoubleScalarCeil(tempc->data[ixstart]);
      } else {
        mtmp = muDoubleScalarFloor(tempc->data[ixstart]);
      }

      tempc->data[ixstart] = mtmp;
    }

    st.site = &ve_emlrtRSI;
    b_st.site = &df_emlrtRSI;
    c_st.site = &ef_emlrtRSI;
    if ((tempc->size[0] == 1) || (tempc->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &ie_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (tempc->size[0] > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &he_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &ff_emlrtRSI;
    ixstart = 1;
    idx = tempc->size[0];
    mtmp = tempc->data[0];
    if (tempc->size[0] > 1) {
      if (muDoubleScalarIsNaN(tempc->data[0])) {
        e_st.site = &hf_emlrtRSI;
        overflow = (tempc->size[0] > 2147483646);
        if (overflow) {
          f_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        nx = 2;
        exitg6 = false;
        while ((!exitg6) && (nx <= idx)) {
          ixstart = nx;
          if (!muDoubleScalarIsNaN(tempc->data[nx - 1])) {
            mtmp = tempc->data[nx - 1];
            exitg6 = true;
          } else {
            nx++;
          }
        }
      }

      if (ixstart < tempc->size[0]) {
        e_st.site = &gf_emlrtRSI;
        if (ixstart + 1 > tempc->size[0]) {
          overflow = false;
        } else {
          overflow = (tempc->size[0] > 2147483646);
        }

        if (overflow) {
          f_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (ixstart + 1 <= idx) {
          if (tempc->data[ixstart] > mtmp) {
            mtmp = tempc->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    emxInit_real_T1(&d_st, &p, 1, &nb_emlrtRTEI, true);

    /*  */
    /*      Initialize the forward sweep, the p-sequence of Olver. */
    /*  */
    /* 'Mybesseli:106' nbmx = nb-magx; */
    /* 'Mybesseli:107' n = magx+1; */
    n = mtmp + 1.0;

    /* 'Mybesseli:108' en = (n+n) + (alpha+alpha); */
    en = (mtmp + 1.0) + (mtmp + 1.0);

    /* 'Mybesseli:109' plast = 1; */
    /* 'Mybesseli:110' p = en ./ x; */
    d_rdivide(sp, en, b_x, p);

    /*  */
    /*      Calculate general significance test. */
    /*  */
    /* 'Mybesseli:114' test = 2/eps; */
    /* 'Mybesseli:115' if (2*magx > 80) */
    if (2.0 * mtmp > 80.0) {
      /* 'Mybesseli:116' test = sqrt(test*max(p)); */
      st.site = &ue_emlrtRSI;
      b_st.site = &df_emlrtRSI;
      c_st.site = &ef_emlrtRSI;
      if ((p->size[0] == 1) || (p->size[0] != 1)) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &ie_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (p->size[0] > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &he_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &ff_emlrtRSI;
      ixstart = 1;
      idx = p->size[0];
      mtmp = p->data[0];
      if (p->size[0] > 1) {
        if (muDoubleScalarIsNaN(p->data[0])) {
          e_st.site = &hf_emlrtRSI;
          overflow = (p->size[0] > 2147483646);
          if (overflow) {
            f_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          nx = 2;
          exitg5 = false;
          while ((!exitg5) && (nx <= idx)) {
            ixstart = nx;
            if (!muDoubleScalarIsNaN(p->data[nx - 1])) {
              mtmp = p->data[nx - 1];
              exitg5 = true;
            } else {
              nx++;
            }
          }
        }

        if (ixstart < p->size[0]) {
          e_st.site = &gf_emlrtRSI;
          if (ixstart + 1 > p->size[0]) {
            overflow = false;
          } else {
            overflow = (p->size[0] > 2147483646);
          }

          if (overflow) {
            f_st.site = &mb_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while (ixstart + 1 <= idx) {
            if (p->data[ixstart] > mtmp) {
              mtmp = p->data[ixstart];
            }

            ixstart++;
          }
        }
      }

      test = 9.007199254740992E+15 * mtmp;
      st.site = &ue_emlrtRSI;
      c_sqrt(&st, &test);
    } else {
      /* 'Mybesseli:117' else */
      /* 'Mybesseli:118' test = test / 1.585^magx; */
      test = 9.007199254740992E+15 / muDoubleScalarPower(1.585, mtmp);
    }

    emxInit_real_T1(sp, &a, 1, &ob_emlrtRTEI, true);

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
                      &jb_emlrtRTEI);
    idx = p->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      a->data[i13] = p->data[i13];
    }

    /* 'Mybesseli:189' count = 0; */
    count = 0;

    /* 'Mybesseli:190' while any(p < test) */
    emxInit_boolean_T1(sp, &b_p, 1, &jb_emlrtRTEI, true);
    emxInit_real_T1(sp, &b_en, 1, &jb_emlrtRTEI, true);
    emxInit_real_T1(sp, &c_en, 1, &jb_emlrtRTEI, true);
    do {
      exitg4 = 0;
      i13 = b_p->size[0];
      b_p->size[0] = p->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_p, i13, (int32_T)sizeof
                        (boolean_T), &jb_emlrtRTEI);
      idx = p->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        b_p->data[i13] = (p->data[i13] < test);
      }

      st.site = &te_emlrtRSI;
      if (d_any(&st, b_p)) {
        /* 'Mybesseli:191' n = n + 1; */
        n++;

        /* 'Mybesseli:192' en = en + 2; */
        en += 2.0;

        /* 'Mybesseli:193' if count == 1 */
        if (count == 1) {
          /* 'Mybesseli:194' plast = a; */
          /* 'Mybesseli:195' pold = plast; */
          i13 = tempc->size[0];
          tempc->size[0] = a->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof
                            (real_T), &jb_emlrtRTEI);
          idx = a->size[0];
          for (i13 = 0; i13 < idx; i13++) {
            tempc->data[i13] = a->data[i13];
          }

          /* 'Mybesseli:196' a = p; */
          i13 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof
                            (real_T), &jb_emlrtRTEI);
          idx = p->size[0];
          for (i13 = 0; i13 < idx; i13++) {
            a->data[i13] = p->data[i13];
          }

          /* 'Mybesseli:197' p = en * a./x + pold; */
          i13 = c_en->size[0];
          c_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)c_en, i13, (int32_T)sizeof
                            (real_T), &jb_emlrtRTEI);
          idx = p->size[0];
          for (i13 = 0; i13 < idx; i13++) {
            c_en->data[i13] = en * p->data[i13];
          }

          st.site = &se_emlrtRSI;
          e_rdivide(&st, c_en, b_x, p);
          i13 = p->size[0];
          nx = tempc->size[0];
          if (i13 != nx) {
            emlrtSizeEqCheck1DR2012b(i13, nx, &r_emlrtECI, sp);
          }

          i13 = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i13, (int32_T)sizeof
                            (real_T), &jb_emlrtRTEI);
          idx = p->size[0];
          for (i13 = 0; i13 < idx; i13++) {
            p->data[i13] += tempc->data[i13];
          }
        } else {
          /* 'Mybesseli:198' else */
          /* 'Mybesseli:199' count = 1; */
          count = 1;

          /* 'Mybesseli:200' a = p; */
          i13 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof
                            (real_T), &jb_emlrtRTEI);
          idx = p->size[0];
          for (i13 = 0; i13 < idx; i13++) {
            a->data[i13] = p->data[i13];
          }

          /* 'Mybesseli:201' p = en * a./x + ones(length(a),1); */
          i13 = b_en->size[0];
          b_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)b_en, i13, (int32_T)sizeof
                            (real_T), &jb_emlrtRTEI);
          idx = p->size[0];
          for (i13 = 0; i13 < idx; i13++) {
            b_en->data[i13] = en * p->data[i13];
          }

          st.site = &re_emlrtRSI;
          e_rdivide(&st, b_en, b_x, tempc);
          ixstart = p->size[0];
          i13 = tempc->size[0];
          if (i13 != ixstart) {
            emlrtSizeEqCheck1DR2012b(i13, ixstart, &s_emlrtECI, sp);
          }

          i13 = p->size[0];
          p->size[0] = tempc->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i13, (int32_T)sizeof
                            (real_T), &jb_emlrtRTEI);
          idx = tempc->size[0];
          for (i13 = 0; i13 < idx; i13++) {
            p->data[i13] = tempc->data[i13] + 1.0;
          }
        }

        /*           a = p; */
        /*           p = en * a./x + pold; */
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      } else {
        exitg4 = 1;
      }
    } while (exitg4 == 0);

    emxFree_real_T(&c_en);
    emxFree_real_T(&b_en);
    emxFree_boolean_T(&b_p);
    emxInit_real_T1(sp, &tempa, 1, &pb_emlrtRTEI, true);
    emxInit_real_T1(sp, &b_tempa, 1, &jb_emlrtRTEI, true);

    /*  */
    /*      Initialize the backward recursion and the normalization sum. */
    /*  */
    /* 'Mybesseli:209' n = n + 1; */
    n++;

    /* 'Mybesseli:210' en = en + 2; */
    en += 2.0;

    /* 'Mybesseli:211' tempb = 0; */
    /* 'Mybesseli:212' tempa = 1 ./ p; */
    d_rdivide(sp, 1.0, p, tempa);

    /* 'Mybesseli:213' em = n - 1; */
    em = n - 1.0;

    /* 'Mybesseli:214' empal = em + alpha; */
    empal = n - 1.0;

    /* 'Mybesseli:215' emp2al = (em - 1) + (alpha + alpha); */
    emp2al = (n - 1.0) - 1.0;

    /* 'Mybesseli:216' sum = tempa * empal * emp2al / em; */
    i13 = b_tempa->size[0];
    b_tempa->size[0] = tempa->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_tempa, i13, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    idx = tempa->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      b_tempa->data[i13] = tempa->data[i13] * (n - 1.0) * ((n - 1.0) - 1.0);
    }

    c_rdivide(sp, b_tempa, n - 1.0, a);

    /* 'Mybesseli:217' nend = n - nb; */
    nend = n - 1.0;

    /* 'Mybesseli:218' skip = 0; */
    /* 'Mybesseli:219' if (nend < 0) */
    emxFree_real_T(&b_tempa);
    if (n - 1.0 < 0.0) {
      /* 'Mybesseli:220' b(v,n) = tempa; */
      ixstart = b->size[0];
      i13 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                        &jb_emlrtRTEI);
      idx = v->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        nx = (int32_T)v->data[i13];
        if (!((nx >= 1) && (nx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &wd_emlrtBCI, sp);
        }

        ii->data[i13] = nx - 1;
      }

      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &t_emlrtDCI, sp);
      }

      i13 = (int32_T)n;
      if (!((i13 >= 1) && (i13 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 1, &rd_emlrtBCI, sp);
      }

      c_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(c_ii, 1, *(int32_T (*)[1])tempa->size, 1,
        &x_emlrtECI, sp);
      idx = tempa->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        b->data[ii->data[i13]] = tempa->data[i13];
      }

      /* 'Mybesseli:221' nend = -nend; */
      /* 'Mybesseli:222' b(v,n+1:n+nend) = zeros(length(v),nend); */
      ixstart = b->size[0];
      i13 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                        &jb_emlrtRTEI);
      idx = v->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        nx = (int32_T)v->data[i13];
        if (!((nx >= 1) && (nx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &xd_emlrtBCI, sp);
        }

        ii->data[i13] = nx - 1;
      }

      emxInit_int32_T(sp, &r8, 1, &jb_emlrtRTEI, true);
      i13 = r8->size[0];
      r8->size[0] = 0;
      emxEnsureCapacity(sp, (emxArray__common *)r8, i13, (int32_T)sizeof(int32_T),
                        &jb_emlrtRTEI);
      d_ii[0] = ii->size[0];
      d_ii[1] = 0;
      b_v[0] = v->size[0];
      b_v[1] = 0;
      emlrtSubAssignSizeCheckR2012b(d_ii, 2, b_v, 2, &y_emlrtECI, sp);
      emxFree_int32_T(&r8);
    } else {
      /* 'Mybesseli:223' else */
      /* 'Mybesseli:224' if (nend > 0) */
      if (n - 1.0 > 0.0) {
        /*  */
        /*            Recur backward via difference equation, calculating  */
        /*            (but not storing) b(n), until n = nb. */
        /*  */
        /* 'Mybesseli:229' kk= tempa; */
        i13 = p->size[0];
        p->size[0] = tempa->size[0];
        emxEnsureCapacity(sp, (emxArray__common *)p, i13, (int32_T)sizeof(real_T),
                          &jb_emlrtRTEI);
        idx = tempa->size[0];
        for (i13 = 0; i13 < idx; i13++) {
          p->data[i13] = tempa->data[i13];
        }

        /* 'Mybesseli:230' count2 = 0; */
        count2 = 0;

        /* 'Mybesseli:231' for l = 1:nend */
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, n - 1.0, mxDOUBLE_CLASS,
          (int32_T)(n - 1.0), &ee_emlrtRTEI, sp);
        l = 0;
        emxInit_real_T1(sp, &d_en, 1, &jb_emlrtRTEI, true);
        emxInit_real_T1(sp, &e_en, 1, &jb_emlrtRTEI, true);
        emxInit_real_T1(sp, &b_a, 1, &jb_emlrtRTEI, true);
        exitg3 = false;
        while ((!exitg3) && (l <= (int32_T)nend - 1)) {
          /* 'Mybesseli:232' n = n - 1; */
          n--;

          /* 'Mybesseli:233' en = en - 2; */
          en -= 2.0;

          /* 'Mybesseli:234' if count2 == 1 */
          if (count2 == 1) {
            /* 'Mybesseli:235' tempb = kk; */
            /* 'Mybesseli:236' tempc = tempb; */
            i13 = tempc->size[0];
            tempc->size[0] = p->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)
                              sizeof(real_T), &jb_emlrtRTEI);
            idx = p->size[0];
            for (i13 = 0; i13 < idx; i13++) {
              tempc->data[i13] = p->data[i13];
            }

            /* 'Mybesseli:237' kk = tempa; */
            i13 = p->size[0];
            p->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)p, i13, (int32_T)sizeof
                              (real_T), &jb_emlrtRTEI);
            idx = tempa->size[0];
            for (i13 = 0; i13 < idx; i13++) {
              p->data[i13] = tempa->data[i13];
            }

            /* 'Mybesseli:238' tempa = (en*kk) ./ x + tempc; */
            i13 = e_en->size[0];
            e_en->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)e_en, i13, (int32_T)sizeof
                              (real_T), &jb_emlrtRTEI);
            idx = tempa->size[0];
            for (i13 = 0; i13 < idx; i13++) {
              e_en->data[i13] = en * tempa->data[i13];
            }

            st.site = &qe_emlrtRSI;
            e_rdivide(&st, e_en, b_x, tempa);
            i13 = tempa->size[0];
            nx = tempc->size[0];
            if (i13 != nx) {
              emlrtSizeEqCheck1DR2012b(i13, nx, &t_emlrtECI, sp);
            }

            i13 = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)tempa, i13, (int32_T)
                              sizeof(real_T), &jb_emlrtRTEI);
            idx = tempa->size[0];
            for (i13 = 0; i13 < idx; i13++) {
              tempa->data[i13] += tempc->data[i13];
            }
          } else {
            /* 'Mybesseli:239' else */
            /* 'Mybesseli:240' count2 = 1; */
            count2 = 1;

            /* 'Mybesseli:241' kk = tempa; */
            i13 = p->size[0];
            p->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)p, i13, (int32_T)sizeof
                              (real_T), &jb_emlrtRTEI);
            idx = tempa->size[0];
            for (i13 = 0; i13 < idx; i13++) {
              p->data[i13] = tempa->data[i13];
            }

            /* 'Mybesseli:242' tempa = (en*kk) ./ x; */
            i13 = d_en->size[0];
            d_en->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)d_en, i13, (int32_T)sizeof
                              (real_T), &jb_emlrtRTEI);
            idx = tempa->size[0];
            for (i13 = 0; i13 < idx; i13++) {
              d_en->data[i13] = en * tempa->data[i13];
            }

            st.site = &pe_emlrtRSI;
            e_rdivide(&st, d_en, b_x, tempa);
          }

          /*                 tempc = tempb; */
          /*                 kk = tempa; */
          /*                 tempa = (en*kk) ./ x + tempc; */
          /* 'Mybesseli:247' em = em - 1; */
          em--;

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
            tempc->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)
                              sizeof(real_T), &jb_emlrtRTEI);
            idx = tempa->size[0];
            for (i13 = 0; i13 < idx; i13++) {
              tempc->data[i13] = tempa->data[i13] * empal;
            }

            i13 = a->size[0];
            nx = tempc->size[0];
            if (i13 != nx) {
              emlrtSizeEqCheck1DR2012b(i13, nx, &u_emlrtECI, sp);
            }

            i13 = b_a->size[0];
            b_a->size[0] = a->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)b_a, i13, (int32_T)sizeof
                              (real_T), &jb_emlrtRTEI);
            idx = a->size[0];
            for (i13 = 0; i13 < idx; i13++) {
              b_a->data[i13] = (a->data[i13] + tempc->data[i13]) * emp2al;
            }

            c_rdivide(sp, b_a, em, a);
            l++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }
        }

        emxFree_real_T(&b_a);
        emxFree_real_T(&e_en);
        emxFree_real_T(&d_en);
      }

      /*  */
      /*         Store b(nb). */
      /*  */
      /* 'Mybesseli:258' b(v,n) = tempa; */
      ixstart = b->size[0];
      i13 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                        &jb_emlrtRTEI);
      idx = v->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        nx = (int32_T)v->data[i13];
        if (!((nx >= 1) && (nx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &vd_emlrtBCI, sp);
        }

        ii->data[i13] = nx - 1;
      }

      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &u_emlrtDCI, sp);
      }

      i13 = (int32_T)n;
      if (!((i13 >= 1) && (i13 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, 1, &qd_emlrtBCI, sp);
      }

      c_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(c_ii, 1, *(int32_T (*)[1])tempa->size, 1,
        &ab_emlrtECI, sp);
      idx = tempa->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        b->data[ii->data[i13]] = tempa->data[i13];
      }

      /* 'Mybesseli:259' if (nb <= 1) */
      /* 'Mybesseli:260' sum = (sum + sum) + tempa; */
      i13 = a->size[0];
      nx = tempa->size[0];
      if (i13 != nx) {
        emlrtSizeEqCheck1DR2012b(i13, nx, &v_emlrtECI, sp);
      }

      i13 = a->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof(real_T),
                        &jb_emlrtRTEI);
      idx = a->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        a->data[i13] = (a->data[i13] + a->data[i13]) + tempa->data[i13];
      }

      /* 'Mybesseli:261' skip = -1; */
    }

    emxFree_real_T(&tempa);
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
                      &jb_emlrtRTEI);
    idx = b_x->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      b_x->data[i13] = -b_x->data[i13];
    }

    st.site = &oe_emlrtRSI;
    b_exp(&st, b_x);
    i13 = a->size[0];
    nx = b_x->size[0];
    if (i13 != nx) {
      emlrtSizeEqCheck1DR2012b(i13, nx, &bb_emlrtECI, sp);
    }

    i13 = a->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i13, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    idx = a->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      a->data[i13] *= b_x->data[i13];
    }

    emxFree_real_T(&b_x);

    /* 'Mybesseli:314' for n = 1:nb */
    /* 'Mybesseli:315' b(v,n) = b(v,n) ./ sum; */
    ixstart = b->size[0];
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &yd_emlrtBCI, sp);
      }

      ii->data[i13] = nx - 1;
    }

    emxInit_real_T1(sp, &b_b, 1, &jb_emlrtRTEI, true);
    ixstart = b->size[0];
    i13 = b_b->size[0];
    b_b->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_b, i13, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &ae_emlrtBCI, sp);
      }

      b_b->data[i13] = b->data[nx - 1];
    }

    st.site = &ne_emlrtRSI;
    e_rdivide(&st, b_b, a, tempc);
    e_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(e_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &cb_emlrtECI, sp);
    idx = tempc->size[0];
    emxFree_real_T(&b_b);
    emxFree_real_T(&a);
    for (i13 = 0; i13 < idx; i13++) {
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
                    &jb_emlrtRTEI);
  idx = xx->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    x->data[i13] = (0.0 < xx->data[i13]);
  }

  i13 = r7->size[0];
  r7->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r7, i13, (int32_T)sizeof(boolean_T),
                    &jb_emlrtRTEI);
  idx = xx->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    r7->data[i13] = (xx->data[i13] < 0.0001);
  }

  i13 = x->size[0];
  nx = r7->size[0];
  if (i13 != nx) {
    emlrtSizeEqCheck1DR2012b(i13, nx, &db_emlrtECI, sp);
  }

  st.site = &me_emlrtRSI;
  i13 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &jb_emlrtRTEI);
  idx = x->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    x->data[i13] = (x->data[i13] && r7->data[i13]);
  }

  emxFree_boolean_T(&r7);
  b_st.site = &y_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &jb_emlrtRTEI);
  c_st.site = &bf_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  ixstart = 1;
  exitg2 = false;
  while ((!exitg2) && (ixstart <= nx)) {
    guard2 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg2 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      ixstart++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &ge_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &jb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i13 = 0;
    } else {
      i13 = idx;
    }

    iv21[0] = 1;
    iv21[1] = i13;
    c_st.site = &ab_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv21);
    nx = ii->size[0];
    ii->size[0] = i13;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &f_emlrtRTEI);
  }

  i13 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i13, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  idx = ii->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    v->data[i13] = ii->data[i13];
  }

  /* 'Mybesseli:322' if any(v) */
  st.site = &le_emlrtRSI;
  if (c_any(&st, v)) {
    /* 'Mybesseli:323' x = xx(v); */
    ixstart = xx->size[0];
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &be_emlrtBCI, sp);
      }
    }

    /* 'Mybesseli:324' tempa = ones(length(x),1); */
    /* 'Mybesseli:325' empal = 1 + alpha; */
    /* 'Mybesseli:326' halfx = 0.5 * x; */
    i13 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      tempc->data[i13] = 0.5 * xx->data[(int32_T)v->data[i13] - 1];
    }

    /* 'Mybesseli:327' if (alpha ~= 0) */
    /* 'Mybesseli:328' if scale */
    /* 'Mybesseli:329' tempb = halfx .* halfx; */
    i13 = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i13, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    idx = tempc->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      tempc->data[i13] *= tempc->data[i13];
    }

    emxInit_real_T1(sp, &r9, 1, &jb_emlrtRTEI, true);

    /* 'Mybesseli:330' b(v,1) = tempa + tempa.*tempb / empal; */
    ixstart = v->size[0];
    i13 = tempc->size[0];
    if (ixstart != i13) {
      emlrtSizeEqCheck1DR2012b(ixstart, i13, &eb_emlrtECI, sp);
    }

    i13 = r9->size[0];
    r9->size[0] = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r9, i13, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    idx = tempc->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      r9->data[i13] = tempc->data[i13];
    }

    c_rdivide(sp, r9, 1.0, tempc);
    ixstart = v->size[0];
    i13 = tempc->size[0];
    if (ixstart != i13) {
      emlrtSizeEqCheck1DR2012b(ixstart, i13, &fb_emlrtECI, sp);
    }

    ixstart = b->size[0];
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    emxFree_real_T(&r9);
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &ce_emlrtBCI, sp);
      }

      ii->data[i13] = nx - 1;
    }

    f_ii[0] = ii->size[0];
    c_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(f_ii, 1, c_v, 1, &gb_emlrtECI, sp);
    ixstart = v->size[0];
    for (i13 = 0; i13 < ixstart; i13++) {
      b->data[ii->data[i13]] = 1.0 + tempc->data[i13];
    }

    /* 'Mybesseli:331' if (nb > 1) */
  }

  emxFree_real_T(&tempc);

  /*  */
  /*   x == 0 */
  /*  */
  /* 'Mybesseli:349' v = find(xx == 0); */
  st.site = &ke_emlrtRSI;
  i13 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(boolean_T),
                    &jb_emlrtRTEI);
  idx = xx->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    x->data[i13] = (xx->data[i13] == 0.0);
  }

  b_st.site = &y_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &jb_emlrtRTEI);
  c_st.site = &bf_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  ixstart = 1;
  exitg1 = false;
  while ((!exitg1) && (ixstart <= nx)) {
    guard1 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ixstart++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &ge_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &jb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i13 = 0;
    } else {
      i13 = idx;
    }

    iv22[0] = 1;
    iv22[1] = i13;
    c_st.site = &ab_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv22);
    nx = ii->size[0];
    ii->size[0] = i13;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &f_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  i13 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i13, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  idx = ii->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    v->data[i13] = ii->data[i13];
  }

  /* 'Mybesseli:350' if any(v) */
  st.site = &je_emlrtRSI;
  if (c_any(&st, v)) {
    /*  if alpha>0, I(alpha,0) = 0; I(0,0) = 1. */
    /* 'Mybesseli:352' b(v,:) = zeros(length(v),nb); */
    ixstart = b->size[0];
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &de_emlrtBCI, sp);
      }

      ii->data[i13] = nx - 1;
    }

    g_ii[0] = ii->size[0];
    d_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(g_ii, 1, d_v, 1, &hb_emlrtECI, sp);
    ixstart = v->size[0];
    for (i13 = 0; i13 < ixstart; i13++) {
      b->data[ii->data[i13]] = 0.0;
    }

    /* 'Mybesseli:353' if alpha == 0 */
    /* 'Mybesseli:353' b(v,1) = ones(length(v),1); */
    ixstart = b->size[0];
    i13 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                      &jb_emlrtRTEI);
    idx = v->size[0];
    for (i13 = 0; i13 < idx; i13++) {
      nx = (int32_T)v->data[i13];
      if (!((nx >= 1) && (nx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &ee_emlrtBCI, sp);
      }

      ii->data[i13] = nx - 1;
    }

    h_ii[0] = ii->size[0];
    e_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(h_ii, 1, e_v, 1, &ib_emlrtECI, sp);
    ixstart = v->size[0];
    for (i13 = 0; i13 < ixstart; i13++) {
      b->data[ii->data[i13]] = 1.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&v);
  emxInit_real_T1(sp, &c_b, 1, &jb_emlrtRTEI, true);

  /*  */
  /*   Return the requested index range */
  /*  */
  /* 'Mybesseli:358' b = b(:,nfirst+1:nb); */
  ixstart = b->size[0];
  i13 = c_b->size[0];
  c_b->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)c_b, i13, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  for (i13 = 0; i13 < ixstart; i13++) {
    c_b->data[i13] = b->data[i13];
  }

  i13 = b->size[0];
  b->size[0] = c_b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i13, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  idx = c_b->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    b->data[i13] = c_b->data[i13];
  }

  emxFree_real_T(&c_b);

  /*     if resize */
  /* 'Mybesseli:360' if resize_flag */
  /* 'Mybesseli:361' output = reshape(b,resize(1),resize(2)); */
  st.site = &ie_emlrtRSI;
  b_st.site = &jf_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  assertValidSizeArg(&c_st, resize_idx_0);
  c_st.site = &mf_emlrtRSI;
  assertValidSizeArg(&c_st, 1.0);
  b_idx_0 = (uint32_T)b->size[0];
  ixstart = (int32_T)b_idx_0;
  if (1 > (int32_T)b_idx_0) {
    ixstart = 1;
  }

  if (b->size[0] < ixstart) {
  } else {
    ixstart = b->size[0];
  }

  if ((int32_T)resize_idx_0 > ixstart) {
    b_st.site = &kf_emlrtRSI;
    f_error(&b_st);
  }

  if (1 > ixstart) {
    b_st.site = &kf_emlrtRSI;
    f_error(&b_st);
  }

  i13 = output->size[0] * output->size[1];
  output->size[0] = (int32_T)resize_idx_0;
  output->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)output, i13, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  if (b->size[0] == output->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &fe_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_st.site = &lf_emlrtRSI;
  if (1 > b->size[0]) {
    overflow = false;
  } else {
    overflow = (b->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (ixstart = 0; ixstart + 1 <= b->size[0]; ixstart++) {
    output->data[ixstart] = b->data[ixstart];
  }

  emxFree_real_T(&b);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mybesseli.c) */
