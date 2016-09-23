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
#include "yaapt_emxutil.h"
#include "error1.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "any.h"
#include "indexShapeCheck.h"
#include "exp.h"
#include "sqrt.h"
#include "fix.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo qh_emlrtRSI = { 361, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo rh_emlrtRSI = { 350, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo sh_emlrtRSI = { 349, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo th_emlrtRSI = { 322, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo uh_emlrtRSI = { 321, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo vh_emlrtRSI = { 315, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo wh_emlrtRSI = { 313, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo xh_emlrtRSI = { 242, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo yh_emlrtRSI = { 238, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ai_emlrtRSI = { 201, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo bi_emlrtRSI = { 197, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ci_emlrtRSI = { 190, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo di_emlrtRSI = { 116, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ei_emlrtRSI = { 102, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo fi_emlrtRSI = { 100, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo gi_emlrtRSI = { 99, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo hi_emlrtRSI = { 85, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ii_emlrtRSI = { 84, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo pi_emlrtRSI = { 39, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo qi_emlrtRSI = { 61, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo ri_emlrtRSI = { 108, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo si_emlrtRSI = { 131, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRTEInfo oc_emlrtRTEI = { 1, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo pc_emlrtRTEI = { 63, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo qc_emlrtRTEI = { 84, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo rc_emlrtRTEI = { 86, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo sc_emlrtRTEI = { 110, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo tc_emlrtRTEI = { 188, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo uc_emlrtRTEI = { 212, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo vc_emlrtRTEI = { 236, 20, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo x_emlrtECI = { -1, 353, 22, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo y_emlrtECI = { -1, 352, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ab_emlrtECI = { -1, 330, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo bb_emlrtECI = { -1, 330, 16, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo cb_emlrtECI = { -1, 330, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo db_emlrtECI = { -1, 321, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo eb_emlrtECI = { -1, 315, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo fb_emlrtECI = { -1, 313, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo gb_emlrtECI = { -1, 258, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtBCInfo td_emlrtBCI = { 1, 1, 258, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtDCInfo ib_emlrtDCI = { 258, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtECInfo hb_emlrtECI = { -1, 222, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ib_emlrtECI = { -1, 220, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtBCInfo ud_emlrtBCI = { 1, 1, 220, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtDCInfo jb_emlrtDCI = { 220, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtECInfo jb_emlrtECI = { -1, 93, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo kb_emlrtECI = { -1, 260, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo lb_emlrtECI = { -1, 252, 23, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo mb_emlrtECI = { -1, 238, 28, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo ag_emlrtRTEI = { 231, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo nb_emlrtECI = { -1, 201, 18, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ob_emlrtECI = { -1, 197, 17, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo pb_emlrtECI = { -1, 99, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo bg_emlrtRTEI = { 71, 15, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 86, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 93, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 101, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 258, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 220, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 222, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 315, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 315, 21, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 323, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 330, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 352, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 353, 24, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

/* Function Definitions */
void Mybesseli(const emlrtStack *sp, emxArray_real_T *xx, emxArray_real_T
               *output)
{
  emxArray_real_T *b;
  int32_T i21;
  int32_T nx;
  uint32_T resize_idx_0;
  int32_T ixstart;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T idx;
  boolean_T overflow;
  boolean_T exitg8;
  boolean_T guard4 = false;
  int32_T iv32[2];
  emxArray_real_T *v;
  emxArray_real_T *tempc;
  emxArray_boolean_T *r22;
  int32_T b_ii[1];
  boolean_T exitg7;
  boolean_T guard3 = false;
  int32_T iv33[2];
  emxArray_real_T *b_x;
  real_T mtmp;
  emxArray_real_T *p;
  boolean_T exitg6;
  real_T n;
  boolean_T exitg2;
  real_T en;
  boolean_T guard2 = false;
  real_T test;
  int32_T iv34[2];
  emxArray_real_T *a;
  boolean_T exitg5;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv35[2];
  int32_T c_ii[1];
  int32_T b_v[1];
  emxArray_real_T *b_b;
  int32_T d_ii[1];
  int32_T c_v[1];
  int32_T count;
  emxArray_boolean_T *b_p;
  int32_T e_ii[1];
  emxArray_real_T *b_en;
  int32_T d_v[1];
  emxArray_real_T *c_en;
  int32_T exitg4;
  uint32_T b_idx_0;
  emxArray_real_T *tempa;
  real_T em;
  real_T empal;
  real_T emp2al;
  real_T nend;
  int32_T skip;
  int32_T count2;
  int32_T f_ii[1];
  int32_T l;
  emxArray_real_T *d_en;
  emxArray_real_T *e_en;
  int32_T exitg3;
  emxArray_int32_T *r23;
  int32_T g_ii[2];
  int32_T e_v[2];
  emxArray_real_T *c_b;
  int32_T h_ii[1];
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
  emxInit_real_T2(sp, &b, 1, &pc_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 11U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 0);

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
  /*  */
  /*   Break alpha into integer and fractional parts, */
  /*   and initialize result array. */
  /*  */
  i21 = b->size[0];
  b->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  nx = xx->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    b->data[i21] = rtNaN;
  }

  covrtLogCond(&emlrtCoverageInstance, 11U, 0U, 0, true);
  covrtLogMcdc(&emlrtCoverageInstance, 11U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 1, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1);

  /*     resize = (length(alpha) == 1); */
  /*     if resize, resize = size(xx); end */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2);
  resize_idx_0 = (uint32_T)xx->size[0];
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3);
  ixstart = xx->size[0];
  i21 = xx->size[0];
  xx->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)xx, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  emxInit_boolean_T1(sp, &x, 1, &oc_emlrtRTEI, true);

  /*     b = NaN*ones(length(xx),nb); */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  st.site = &ii_emlrtRSI;
  i21 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i21, (int32_T)sizeof(boolean_T),
                    &oc_emlrtRTEI);
  nx = xx->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    x->data[i21] = (1000.0 < xx->data[i21]);
  }

  emxInit_int32_T1(&st, &ii, 1, &w_emlrtRTEI, true);
  b_st.site = &ac_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i21 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                    &oc_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &if_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i21 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i21, (int32_T)sizeof
                        (int32_T), &oc_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i21 = 0;
    } else {
      i21 = idx;
    }

    iv32[0] = 1;
    iv32[1] = i21;
    c_st.site = &cc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv32);
    idx = ii->size[0];
    ii->size[0] = i21;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &u_emlrtRTEI);
  }

  emxInit_real_T2(&b_st, &v, 1, &qc_emlrtRTEI, true);
  i21 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  nx = ii->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    v->data[i21] = ii->data[i21];
  }

  emxInit_real_T2(sp, &tempc, 1, &vc_emlrtRTEI, true);
  st.site = &hi_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 4, c_any(&st, v))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 4);
    ixstart = xx->size[0];
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &vd_emlrtBCI, sp);
      }
    }

    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 5, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 6);
    ixstart = b->size[0];
    i21 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &wd_emlrtBCI, sp);
      }

      ii->data[i21] = idx - 1;
    }

    i21 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      tempc->data[i21] = rtInf;
    }

    b_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(b_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &jb_emlrtECI, sp);
    nx = tempc->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      b->data[ii->data[i21]] = tempc->data[i21];
    }
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 7);

  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  i21 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, i21, (int32_T)sizeof(boolean_T),
                    &oc_emlrtRTEI);
  nx = xx->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    x->data[i21] = (0.0001 <= xx->data[i21]);
  }

  emxInit_boolean_T1(sp, &r22, 1, &oc_emlrtRTEI, true);
  i21 = r22->size[0];
  r22->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r22, i21, (int32_T)sizeof(boolean_T),
                    &oc_emlrtRTEI);
  nx = xx->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    r22->data[i21] = (xx->data[i21] <= 1000.0);
  }

  i21 = x->size[0];
  idx = r22->size[0];
  if (i21 != idx) {
    emlrtSizeEqCheck1DR2012b(i21, idx, &pb_emlrtECI, sp);
  }

  st.site = &gi_emlrtRSI;
  i21 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i21, (int32_T)sizeof(boolean_T),
                    &oc_emlrtRTEI);
  nx = x->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    x->data[i21] = (x->data[i21] && r22->data[i21]);
  }

  b_st.site = &ac_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i21 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                    &oc_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &if_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i21 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i21, (int32_T)sizeof
                        (int32_T), &oc_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i21 = 0;
    } else {
      i21 = idx;
    }

    iv33[0] = 1;
    iv33[1] = i21;
    c_st.site = &cc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv33);
    idx = ii->size[0];
    ii->size[0] = i21;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &u_emlrtRTEI);
  }

  i21 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  nx = ii->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    v->data[i21] = ii->data[i21];
  }

  st.site = &fi_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 6, c_any(&st, v))) {
    emxInit_real_T2(sp, &b_x, 1, &rc_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 8);
    ixstart = xx->size[0];
    i21 = b_x->size[0];
    b_x->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &xd_emlrtBCI, sp);
      }

      b_x->data[i21] = xx->data[idx - 1];
    }

    i21 = tempc->size[0];
    tempc->size[0] = b_x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = b_x->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      tempc->data[i21] = b_x->data[i21];
    }

    st.site = &ei_emlrtRSI;
    c_fix(&st, tempc);
    st.site = &ei_emlrtRSI;
    b_st.site = &ki_emlrtRSI;
    c_st.site = &li_emlrtRSI;
    if ((tempc->size[0] == 1) || (tempc->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (tempc->size[0] > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &vf_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &mi_emlrtRSI;
    ixstart = 1;
    nx = tempc->size[0];
    mtmp = tempc->data[0];
    if (tempc->size[0] > 1) {
      if (muDoubleScalarIsNaN(tempc->data[0])) {
        e_st.site = &oi_emlrtRSI;
        overflow = (tempc->size[0] > 2147483646);
        if (overflow) {
          f_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        idx = 2;
        exitg6 = false;
        while ((!exitg6) && (idx <= nx)) {
          ixstart = idx;
          if (!muDoubleScalarIsNaN(tempc->data[idx - 1])) {
            mtmp = tempc->data[idx - 1];
            exitg6 = true;
          } else {
            idx++;
          }
        }
      }

      if (ixstart < tempc->size[0]) {
        e_st.site = &ni_emlrtRSI;
        overflow = ((!(ixstart + 1 > tempc->size[0])) && (tempc->size[0] >
          2147483646));
        if (overflow) {
          f_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (ixstart + 1 <= nx) {
          if (tempc->data[ixstart] > mtmp) {
            mtmp = tempc->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    emxInit_real_T2(&d_st, &p, 1, &sc_emlrtRTEI, true);

    /*  */
    /*      Initialize the forward sweep, the p-sequence of Olver. */
    /*  */
    n = mtmp + 1.0;
    en = (mtmp + 1.0) + (mtmp + 1.0);
    b_rdivide(sp, en, b_x, p);

    /*  */
    /*      Calculate general significance test. */
    /*  */
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 7, 2.0 * mtmp > 80.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 9);
      st.site = &di_emlrtRSI;
      b_st.site = &ki_emlrtRSI;
      c_st.site = &li_emlrtRSI;
      if ((p->size[0] == 1) || (p->size[0] != 1)) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (p->size[0] > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &vf_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &mi_emlrtRSI;
      ixstart = 1;
      nx = p->size[0];
      mtmp = p->data[0];
      if (p->size[0] > 1) {
        if (muDoubleScalarIsNaN(p->data[0])) {
          e_st.site = &oi_emlrtRSI;
          overflow = (p->size[0] > 2147483646);
          if (overflow) {
            f_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          idx = 2;
          exitg5 = false;
          while ((!exitg5) && (idx <= nx)) {
            ixstart = idx;
            if (!muDoubleScalarIsNaN(p->data[idx - 1])) {
              mtmp = p->data[idx - 1];
              exitg5 = true;
            } else {
              idx++;
            }
          }
        }

        if (ixstart < p->size[0]) {
          e_st.site = &ni_emlrtRSI;
          overflow = ((!(ixstart + 1 > p->size[0])) && (p->size[0] > 2147483646));
          if (overflow) {
            f_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while (ixstart + 1 <= nx) {
            if (p->data[ixstart] > mtmp) {
              mtmp = p->data[ixstart];
            }

            ixstart++;
          }
        }
      }

      test = 9.007199254740992E+15 * mtmp;
      st.site = &di_emlrtRSI;
      b_sqrt(&st, &test);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 10);
      test = 9.007199254740992E+15 / muDoubleScalarPower(1.585, mtmp);
    }

    emxInit_real_T2(sp, &a, 1, &tc_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 11);

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
    i21 = a->size[0];
    a->size[0] = p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = p->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      a->data[i21] = p->data[i21];
    }

    count = 0;
    emxInit_boolean_T1(sp, &b_p, 1, &oc_emlrtRTEI, true);
    emxInit_real_T2(sp, &b_en, 1, &oc_emlrtRTEI, true);
    emxInit_real_T2(sp, &c_en, 1, &oc_emlrtRTEI, true);
    do {
      exitg4 = 0;
      i21 = b_p->size[0];
      b_p->size[0] = p->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_p, i21, (int32_T)sizeof
                        (boolean_T), &oc_emlrtRTEI);
      nx = p->size[0];
      for (i21 = 0; i21 < nx; i21++) {
        b_p->data[i21] = (p->data[i21] < test);
      }

      st.site = &ci_emlrtRSI;
      if (covrtLogWhile(&emlrtCoverageInstance, 11U, 0U, 0, d_any(&st, b_p))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 12);
        n++;
        en += 2.0;
        if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 8, count == 1)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 13);
          i21 = tempc->size[0];
          tempc->size[0] = a->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)tempc, i21, (int32_T)sizeof
                            (real_T), &oc_emlrtRTEI);
          nx = a->size[0];
          for (i21 = 0; i21 < nx; i21++) {
            tempc->data[i21] = a->data[i21];
          }

          i21 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i21, (int32_T)sizeof
                            (real_T), &oc_emlrtRTEI);
          nx = p->size[0];
          for (i21 = 0; i21 < nx; i21++) {
            a->data[i21] = p->data[i21];
          }

          i21 = c_en->size[0];
          c_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)c_en, i21, (int32_T)sizeof
                            (real_T), &oc_emlrtRTEI);
          nx = p->size[0];
          for (i21 = 0; i21 < nx; i21++) {
            c_en->data[i21] = en * p->data[i21];
          }

          st.site = &bi_emlrtRSI;
          rdivide(&st, c_en, b_x, p);
          i21 = p->size[0];
          idx = tempc->size[0];
          if (i21 != idx) {
            emlrtSizeEqCheck1DR2012b(i21, idx, &ob_emlrtECI, sp);
          }

          i21 = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i21, (int32_T)sizeof
                            (real_T), &oc_emlrtRTEI);
          nx = p->size[0];
          for (i21 = 0; i21 < nx; i21++) {
            p->data[i21] += tempc->data[i21];
          }
        } else {
          covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 14);
          count = 1;
          i21 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i21, (int32_T)sizeof
                            (real_T), &oc_emlrtRTEI);
          nx = p->size[0];
          for (i21 = 0; i21 < nx; i21++) {
            a->data[i21] = p->data[i21];
          }

          i21 = b_en->size[0];
          b_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)b_en, i21, (int32_T)sizeof
                            (real_T), &oc_emlrtRTEI);
          nx = p->size[0];
          for (i21 = 0; i21 < nx; i21++) {
            b_en->data[i21] = en * p->data[i21];
          }

          st.site = &ai_emlrtRSI;
          rdivide(&st, b_en, b_x, tempc);
          ixstart = p->size[0];
          i21 = tempc->size[0];
          if (i21 != ixstart) {
            emlrtSizeEqCheck1DR2012b(i21, ixstart, &nb_emlrtECI, sp);
          }

          i21 = p->size[0];
          p->size[0] = tempc->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i21, (int32_T)sizeof
                            (real_T), &oc_emlrtRTEI);
          nx = tempc->size[0];
          for (i21 = 0; i21 < nx; i21++) {
            p->data[i21] = tempc->data[i21] + 1.0;
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
    emxInit_real_T2(sp, &tempa, 1, &uc_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 15);

    /*  */
    /*      Initialize the backward recursion and the normalization sum. */
    /*  */
    n++;
    en += 2.0;
    c_rdivide(sp, p, tempa);
    em = n - 1.0;
    empal = n - 1.0;
    emp2al = (n - 1.0) - 1.0;
    i21 = a->size[0];
    a->size[0] = tempa->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = tempa->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      a->data[i21] = tempa->data[i21] * (n - 1.0) * ((n - 1.0) - 1.0) / (n - 1.0);
    }

    nend = n - 1.0;
    skip = 0;
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 9, n - 1.0 < 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 16);
      ixstart = b->size[0];
      i21 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                        &oc_emlrtRTEI);
      nx = v->size[0];
      for (i21 = 0; i21 < nx; i21++) {
        idx = (int32_T)v->data[i21];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ae_emlrtBCI, sp);
        }

        ii->data[i21] = idx - 1;
      }

      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &jb_emlrtDCI, sp);
      }

      i21 = (int32_T)n;
      if (!((i21 >= 1) && (i21 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, 1, &ud_emlrtBCI, sp);
      }

      f_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(f_ii, 1, *(int32_T (*)[1])tempa->size, 1,
        &ib_emlrtECI, sp);
      nx = tempa->size[0];
      for (i21 = 0; i21 < nx; i21++) {
        b->data[ii->data[i21]] = tempa->data[i21];
      }

      ixstart = b->size[0];
      i21 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                        &oc_emlrtRTEI);
      nx = v->size[0];
      for (i21 = 0; i21 < nx; i21++) {
        idx = (int32_T)v->data[i21];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &be_emlrtBCI, sp);
        }

        ii->data[i21] = idx - 1;
      }

      emxInit_int32_T1(sp, &r23, 1, &oc_emlrtRTEI, true);
      i21 = r23->size[0];
      r23->size[0] = 0;
      emxEnsureCapacity(sp, (emxArray__common *)r23, i21, (int32_T)sizeof
                        (int32_T), &oc_emlrtRTEI);
      g_ii[0] = ii->size[0];
      g_ii[1] = 0;
      e_v[0] = v->size[0];
      e_v[1] = 0;
      emlrtSubAssignSizeCheckR2012b(g_ii, 2, e_v, 2, &hb_emlrtECI, sp);
      emxFree_int32_T(&r23);
    } else {
      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 10, n - 1.0 > 0.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 17);

        /*  */
        /*            Recur backward via difference equation, calculating  */
        /*            (but not storing) b(n), until n = nb. */
        /*  */
        i21 = p->size[0];
        p->size[0] = tempa->size[0];
        emxEnsureCapacity(sp, (emxArray__common *)p, i21, (int32_T)sizeof(real_T),
                          &oc_emlrtRTEI);
        nx = tempa->size[0];
        for (i21 = 0; i21 < nx; i21++) {
          p->data[i21] = tempa->data[i21];
        }

        count2 = 0;
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, n - 1.0, mxDOUBLE_CLASS,
          (int32_T)(n - 1.0), &ag_emlrtRTEI, sp);
        l = 0;
        emxInit_real_T2(sp, &d_en, 1, &oc_emlrtRTEI, true);
        emxInit_real_T2(sp, &e_en, 1, &oc_emlrtRTEI, true);
        do {
          exitg3 = 0;
          if (l <= (int32_T)nend - 1) {
            covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 0, 1);
            covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 18);
            n--;
            en -= 2.0;
            if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 11, count2 == 1)) {
              covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 19);
              i21 = tempc->size[0];
              tempc->size[0] = p->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)tempc, i21, (int32_T)
                                sizeof(real_T), &oc_emlrtRTEI);
              nx = p->size[0];
              for (i21 = 0; i21 < nx; i21++) {
                tempc->data[i21] = p->data[i21];
              }

              i21 = p->size[0];
              p->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)p, i21, (int32_T)sizeof
                                (real_T), &oc_emlrtRTEI);
              nx = tempa->size[0];
              for (i21 = 0; i21 < nx; i21++) {
                p->data[i21] = tempa->data[i21];
              }

              i21 = e_en->size[0];
              e_en->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)e_en, i21, (int32_T)
                                sizeof(real_T), &oc_emlrtRTEI);
              nx = tempa->size[0];
              for (i21 = 0; i21 < nx; i21++) {
                e_en->data[i21] = en * tempa->data[i21];
              }

              st.site = &yh_emlrtRSI;
              rdivide(&st, e_en, b_x, tempa);
              i21 = tempa->size[0];
              idx = tempc->size[0];
              if (i21 != idx) {
                emlrtSizeEqCheck1DR2012b(i21, idx, &mb_emlrtECI, sp);
              }

              i21 = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)tempa, i21, (int32_T)
                                sizeof(real_T), &oc_emlrtRTEI);
              nx = tempa->size[0];
              for (i21 = 0; i21 < nx; i21++) {
                tempa->data[i21] += tempc->data[i21];
              }
            } else {
              covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 20);
              count2 = 1;
              i21 = p->size[0];
              p->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)p, i21, (int32_T)sizeof
                                (real_T), &oc_emlrtRTEI);
              nx = tempa->size[0];
              for (i21 = 0; i21 < nx; i21++) {
                p->data[i21] = tempa->data[i21];
              }

              i21 = d_en->size[0];
              d_en->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)d_en, i21, (int32_T)
                                sizeof(real_T), &oc_emlrtRTEI);
              nx = tempa->size[0];
              for (i21 = 0; i21 < nx; i21++) {
                d_en->data[i21] = en * tempa->data[i21];
              }

              st.site = &xh_emlrtRSI;
              rdivide(&st, d_en, b_x, tempa);
            }

            covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 21);

            /*                 tempc = tempb; */
            /*                 kk = tempa; */
            /*                 tempa = (en*kk) ./ x + tempc; */
            em--;
            emp2al--;
            if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 12, n == 1.0)) {
              covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 22);
              exitg3 = 1;
            } else {
              if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 13, n == 2.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 23);
                emp2al = 1.0;
              }

              covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 24);
              empal--;
              i21 = tempc->size[0];
              tempc->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)tempc, i21, (int32_T)
                                sizeof(real_T), &oc_emlrtRTEI);
              nx = tempa->size[0];
              for (i21 = 0; i21 < nx; i21++) {
                tempc->data[i21] = tempa->data[i21] * empal;
              }

              i21 = a->size[0];
              idx = tempc->size[0];
              if (i21 != idx) {
                emlrtSizeEqCheck1DR2012b(i21, idx, &lb_emlrtECI, sp);
              }

              i21 = a->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)a, i21, (int32_T)sizeof
                                (real_T), &oc_emlrtRTEI);
              nx = a->size[0];
              for (i21 = 0; i21 < nx; i21++) {
                a->data[i21] = (a->data[i21] + tempc->data[i21]) * emp2al / em;
              }

              l++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(sp);
              }
            }
          } else {
            covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 0, 0);
            exitg3 = 1;
          }
        } while (exitg3 == 0);

        emxFree_real_T(&e_en);
        emxFree_real_T(&d_en);
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 25);

      /*  */
      /*         Store b(nb). */
      /*  */
      ixstart = b->size[0];
      i21 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                        &oc_emlrtRTEI);
      nx = v->size[0];
      for (i21 = 0; i21 < nx; i21++) {
        idx = (int32_T)v->data[i21];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &yd_emlrtBCI, sp);
        }

        ii->data[i21] = idx - 1;
      }

      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &ib_emlrtDCI, sp);
      }

      i21 = (int32_T)n;
      if (!((i21 >= 1) && (i21 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, 1, &td_emlrtBCI, sp);
      }

      f_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(f_ii, 1, *(int32_T (*)[1])tempa->size, 1,
        &gb_emlrtECI, sp);
      nx = tempa->size[0];
      for (i21 = 0; i21 < nx; i21++) {
        b->data[ii->data[i21]] = tempa->data[i21];
      }

      covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 14, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 26);
      i21 = a->size[0];
      idx = tempa->size[0];
      if (i21 != idx) {
        emlrtSizeEqCheck1DR2012b(i21, idx, &kb_emlrtECI, sp);
      }

      i21 = a->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)a, i21, (int32_T)sizeof(real_T),
                        &oc_emlrtRTEI);
      nx = a->size[0];
      for (i21 = 0; i21 < nx; i21++) {
        a->data[i21] = (a->data[i21] + a->data[i21]) + tempa->data[i21];
      }

      skip = -1;
    }

    emxFree_real_T(&tempa);
    emxFree_real_T(&p);
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 17, skip == 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 32);
      covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 18, false);
    }

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
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 20, false);
    covrtLogCond(&emlrtCoverageInstance, 11U, 0U, 1, false);
    covrtLogMcdc(&emlrtCoverageInstance, 11U, 0U, 1, true);
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 21, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 37);
    i21 = b_x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = b_x->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      b_x->data[i21] = -b_x->data[i21];
    }

    st.site = &wh_emlrtRSI;
    b_exp(&st, b_x);
    i21 = a->size[0];
    idx = b_x->size[0];
    if (i21 != idx) {
      emlrtSizeEqCheck1DR2012b(i21, idx, &fb_emlrtECI, sp);
    }

    i21 = a->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = a->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      a->data[i21] *= b_x->data[i21];
    }

    emxFree_real_T(&b_x);
    covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 38);
    ixstart = b->size[0];
    i21 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ce_emlrtBCI, sp);
      }

      ii->data[i21] = idx - 1;
    }

    emxInit_real_T2(sp, &c_b, 1, &oc_emlrtRTEI, true);
    ixstart = b->size[0];
    i21 = c_b->size[0];
    c_b->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)c_b, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &de_emlrtBCI, sp);
      }

      c_b->data[i21] = b->data[idx - 1];
    }

    st.site = &vh_emlrtRSI;
    rdivide(&st, c_b, a, tempc);
    h_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(h_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &eb_emlrtECI, sp);
    nx = tempc->size[0];
    emxFree_real_T(&c_b);
    emxFree_real_T(&a);
    for (i21 = 0; i21 < nx; i21++) {
      b->data[ii->data[i21]] = tempc->data[i21];
    }

    covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 0);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 39);

  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  i21 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, i21, (int32_T)sizeof(boolean_T),
                    &oc_emlrtRTEI);
  nx = xx->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    x->data[i21] = (0.0 < xx->data[i21]);
  }

  i21 = r22->size[0];
  r22->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r22, i21, (int32_T)sizeof(boolean_T),
                    &oc_emlrtRTEI);
  nx = xx->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    r22->data[i21] = (xx->data[i21] < 0.0001);
  }

  i21 = x->size[0];
  idx = r22->size[0];
  if (i21 != idx) {
    emlrtSizeEqCheck1DR2012b(i21, idx, &db_emlrtECI, sp);
  }

  st.site = &uh_emlrtRSI;
  i21 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i21, (int32_T)sizeof(boolean_T),
                    &oc_emlrtRTEI);
  nx = x->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    x->data[i21] = (x->data[i21] && r22->data[i21]);
  }

  emxFree_boolean_T(&r22);
  b_st.site = &ac_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i21 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                    &oc_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &if_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i21 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i21, (int32_T)sizeof
                        (int32_T), &oc_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i21 = 0;
    } else {
      i21 = idx;
    }

    iv34[0] = 1;
    iv34[1] = i21;
    c_st.site = &cc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv34);
    idx = ii->size[0];
    ii->size[0] = i21;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &u_emlrtRTEI);
  }

  i21 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  nx = ii->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    v->data[i21] = ii->data[i21];
  }

  st.site = &th_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 22, c_any(&st, v))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 40);
    ixstart = xx->size[0];
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ee_emlrtBCI, sp);
      }
    }

    i21 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      tempc->data[i21] = 0.5 * xx->data[(int32_T)v->data[i21] - 1];
    }

    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 23, false);
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 24, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 43);
    i21 = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    nx = tempc->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      tempc->data[i21] *= tempc->data[i21];
    }

    ixstart = v->size[0];
    i21 = tempc->size[0];
    if (ixstart != i21) {
      emlrtSizeEqCheck1DR2012b(ixstart, i21, &cb_emlrtECI, sp);
    }

    i21 = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i21, (int32_T)sizeof(real_T),
                      &oc_emlrtRTEI);
    ixstart = v->size[0];
    i21 = tempc->size[0];
    if (ixstart != i21) {
      emlrtSizeEqCheck1DR2012b(ixstart, i21, &bb_emlrtECI, sp);
    }

    ixstart = b->size[0];
    i21 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &fe_emlrtBCI, sp);
      }

      ii->data[i21] = idx - 1;
    }

    c_ii[0] = ii->size[0];
    b_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(c_ii, 1, b_v, 1, &ab_emlrtECI, sp);
    ixstart = v->size[0];
    for (i21 = 0; i21 < ixstart; i21++) {
      b->data[ii->data[i21]] = 1.0 + tempc->data[i21];
    }

    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 25, false);
  }

  emxFree_real_T(&tempc);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 46);

  /*  */
  /*   x == 0 */
  /*  */
  st.site = &sh_emlrtRSI;
  i21 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i21, (int32_T)sizeof(boolean_T),
                    &oc_emlrtRTEI);
  nx = xx->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    x->data[i21] = (xx->data[i21] == 0.0);
  }

  b_st.site = &ac_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i21 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                    &oc_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &if_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i21 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i21, (int32_T)sizeof
                        (int32_T), &oc_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i21 = 0;
    } else {
      i21 = idx;
    }

    iv35[0] = 1;
    iv35[1] = i21;
    c_st.site = &cc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv35);
    idx = ii->size[0];
    ii->size[0] = i21;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &u_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  i21 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  nx = ii->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    v->data[i21] = ii->data[i21];
  }

  st.site = &rh_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 26, c_any(&st, v))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 47);

    /*  if alpha>0, I(alpha,0) = 0; I(0,0) = 1. */
    ixstart = b->size[0];
    i21 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ge_emlrtBCI, sp);
      }

      ii->data[i21] = idx - 1;
    }

    d_ii[0] = ii->size[0];
    c_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(d_ii, 1, c_v, 1, &y_emlrtECI, sp);
    ixstart = v->size[0];
    for (i21 = 0; i21 < ixstart; i21++) {
      b->data[ii->data[i21]] = 0.0;
    }

    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 27, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 48);
    ixstart = b->size[0];
    i21 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i21, (int32_T)sizeof(int32_T),
                      &oc_emlrtRTEI);
    nx = v->size[0];
    for (i21 = 0; i21 < nx; i21++) {
      idx = (int32_T)v->data[i21];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &he_emlrtBCI, sp);
      }

      ii->data[i21] = idx - 1;
    }

    e_ii[0] = ii->size[0];
    d_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(e_ii, 1, d_v, 1, &x_emlrtECI, sp);
    ixstart = v->size[0];
    for (i21 = 0; i21 < ixstart; i21++) {
      b->data[ii->data[i21]] = 1.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&v);
  emxInit_real_T2(sp, &b_b, 1, &oc_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 49);

  /*  */
  /*   Return the requested index range */
  /*  */
  ixstart = b->size[0];
  i21 = b_b->size[0];
  b_b->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)b_b, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  for (i21 = 0; i21 < ixstart; i21++) {
    b_b->data[i21] = b->data[i21];
  }

  i21 = b->size[0];
  b->size[0] = b_b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  nx = b_b->size[0];
  for (i21 = 0; i21 < nx; i21++) {
    b->data[i21] = b_b->data[i21];
  }

  emxFree_real_T(&b_b);

  /*     if resize */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 28, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 50);
  st.site = &qh_emlrtRSI;
  b_st.site = &pi_emlrtRSI;
  c_st.site = &si_emlrtRSI;
  assertValidSizeArg(&c_st, resize_idx_0);
  c_st.site = &si_emlrtRSI;
  assertValidSizeArg(&c_st, 1.0);
  b_idx_0 = (uint32_T)b->size[0];
  ixstart = (int32_T)b_idx_0;
  if (1 > (int32_T)b_idx_0) {
    ixstart = 1;
  }

  ixstart = muIntScalarMax_sint32(b->size[0], ixstart);
  if ((int32_T)resize_idx_0 > ixstart) {
    b_st.site = &qi_emlrtRSI;
    h_error(&b_st);
  }

  if (1 > ixstart) {
    b_st.site = &qi_emlrtRSI;
    h_error(&b_st);
  }

  i21 = output->size[0] * output->size[1];
  output->size[0] = (int32_T)resize_idx_0;
  output->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)output, i21, (int32_T)sizeof(real_T),
                    &oc_emlrtRTEI);
  if (b->size[0] == output->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &bg_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_st.site = &ri_emlrtRSI;
  overflow = ((!(1 > b->size[0])) && (b->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (ixstart = 0; ixstart + 1 <= b->size[0]; ixstart++) {
    output->data[ixstart] = b->data[ixstart];
  }

  emxFree_real_T(&b);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

real_T b_Mybesseli(const emlrtStack *sp)
{
  real_T n;
  real_T en;
  real_T p;
  real_T a;
  int32_T count;
  real_T pold;
  real_T tempa;
  real_T em;
  real_T empal;
  real_T emp2al;
  real_T c_sum;
  real_T nend;
  real_T kk;
  int32_T count2;
  int32_T l;
  int32_T exitg1;
  real_T tempc;
  int32_T i25;
  covrtLogFcn(&emlrtCoverageInstance, 11U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 0);

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
  /*  */
  /*   Break alpha into integer and fractional parts, */
  /*   and initialize result array. */
  /*  */
  covrtLogCond(&emlrtCoverageInstance, 11U, 0U, 0, true);
  covrtLogMcdc(&emlrtCoverageInstance, 11U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 1, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1);

  /*     resize = (length(alpha) == 1); */
  /*     if resize, resize = size(xx); end */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3);

  /*     b = NaN*ones(length(xx),nb); */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 4, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 7);

  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 6, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 8);

  /*  */
  /*      Initialize the forward sweep, the p-sequence of Olver. */
  /*  */
  n = 1.0;
  en = 2.0;
  p = 4.0;

  /*  */
  /*      Calculate general significance test. */
  /*  */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 7, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 10);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 11);

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
  a = 4.0;
  count = 0;
  while (covrtLogWhile(&emlrtCoverageInstance, 11U, 0U, 0, !!(p <
           9.007199254740992E+15))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 12);
    n++;
    en += 2.0;
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 8, count == 1)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 13);
      pold = a;
      a = p;
      p = en * p / 0.5 + pold;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 14);
      count = 1;
      a = p;
      p = en * p / 0.5 + 1.0;
    }

    /*           a = p; */
    /*           p = en * a./x + pold; */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 15);

  /*  */
  /*      Initialize the backward recursion and the normalization sum. */
  /*  */
  n++;
  en += 2.0;
  tempa = 1.0 / p;
  em = n - 1.0;
  empal = n - 1.0;
  emp2al = (n - 1.0) - 1.0;
  c_sum = tempa * (n - 1.0) * ((n - 1.0) - 1.0) / (n - 1.0);
  nend = n - 1.0;
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 9, false);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 10, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 17);

  /*  */
  /*            Recur backward via difference equation, calculating  */
  /*            (but not storing) b(n), until n = nb. */
  /*  */
  kk = tempa;
  count2 = 0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n - 1.0, mxDOUBLE_CLASS, (int32_T)(n -
    1.0), &ag_emlrtRTEI, sp);
  l = 0;
  do {
    exitg1 = 0;
    if (l <= (int32_T)nend - 1) {
      covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 18);
      n--;
      en -= 2.0;
      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 11, count2 == 1)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 19);
        tempc = kk;
        kk = tempa;
        tempa = en * tempa / 0.5 + tempc;
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 20);
        count2 = 1;
        kk = tempa;
        tempa = en * tempa / 0.5;
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 21);

      /*                 tempc = tempb; */
      /*                 kk = tempa; */
      /*                 tempa = (en*kk) ./ x + tempc; */
      em--;
      emp2al--;
      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 12, n == 1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 22);
        exitg1 = 1;
      } else {
        if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 13, n == 2.0)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 23);
          emp2al = 1.0;
        }

        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 24);
        empal--;
        c_sum = (c_sum + tempa * empal) * emp2al / em;
        l++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else {
      covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 25);

  /*  */
  /*         Store b(nb). */
  /*  */
  i25 = (int32_T)n;
  if (!((i25 >= 1) && (i25 <= 1))) {
    emlrtDynamicBoundsCheckR2012b(i25, 1, 1, &td_emlrtBCI, sp);
  }

  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 14, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 26);
  c_sum = (c_sum + c_sum) + tempa;
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 17, false);

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
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 20, false);
  covrtLogCond(&emlrtCoverageInstance, 11U, 0U, 1, false);
  covrtLogMcdc(&emlrtCoverageInstance, 11U, 0U, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 21, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 37);
  c_sum *= 0.60653065971263342;
  covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 38);
  covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 39);

  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 22, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 46);

  /*  */
  /*   x == 0 */
  /*  */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 26, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 49);

  /*  */
  /*   Return the requested index range */
  /*  */
  /*     if resize */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 28, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 50);
  return tempa / c_sum;
}

/* End of code generation (Mybesseli.c) */
