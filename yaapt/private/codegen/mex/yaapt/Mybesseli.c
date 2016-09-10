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
#include "error1.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "any.h"
#include "indexShapeCheck.h"
#include "exp.h"
#include "sqrt.h"
#include "mpower.h"
#include "fix.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wi_emlrtRSI = { 84, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo xi_emlrtRSI = { 85, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo yi_emlrtRSI = { 99, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo aj_emlrtRSI = { 100, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo bj_emlrtRSI = { 102, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo cj_emlrtRSI = { 116, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo dj_emlrtRSI = { 118, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ej_emlrtRSI = { 190, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo fj_emlrtRSI = { 197, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo gj_emlrtRSI = { 201, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo hj_emlrtRSI = { 238, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ij_emlrtRSI = { 242, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo jj_emlrtRSI = { 313, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo kj_emlrtRSI = { 315, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo lj_emlrtRSI = { 321, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo mj_emlrtRSI = { 322, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo nj_emlrtRSI = { 349, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo oj_emlrtRSI = { 350, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo pj_emlrtRSI = { 361, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo rj_emlrtRSI = { 39, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo sj_emlrtRSI = { 58, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo tj_emlrtRSI = { 61, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo uj_emlrtRSI = { 108, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo vj_emlrtRSI = { 131, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRTEInfo rc_emlrtRTEI = { 1, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo sc_emlrtRTEI = { 63, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo tc_emlrtRTEI = { 84, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo uc_emlrtRTEI = { 86, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo vc_emlrtRTEI = { 110, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo wc_emlrtRTEI = { 188, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo xc_emlrtRTEI = { 212, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo yc_emlrtRTEI = { 236, 20, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ab_emlrtECI = { -1, 99, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo bb_emlrtECI = { -1, 197, 17, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo cb_emlrtECI = { -1, 201, 18, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo lg_emlrtRTEI = { 231, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo db_emlrtECI = { -1, 238, 28, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo eb_emlrtECI = { -1, 252, 23, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo fb_emlrtECI = { -1, 260, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo gb_emlrtECI = { -1, 93, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtDCInfo sb_emlrtDCI = { 220, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtBCInfo ie_emlrtBCI = { 1, 1, 220, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtECInfo hb_emlrtECI = { -1, 220, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ib_emlrtECI = { -1, 222, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtDCInfo tb_emlrtDCI = { 258, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtBCInfo je_emlrtBCI = { 1, 1, 258, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtECInfo jb_emlrtECI = { -1, 258, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo kb_emlrtECI = { -1, 313, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo lb_emlrtECI = { -1, 315, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo mb_emlrtECI = { -1, 321, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo nb_emlrtECI = { -1, 330, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ob_emlrtECI = { -1, 330, 16, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo pb_emlrtECI = { -1, 330, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo qb_emlrtECI = { -1, 352, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo rb_emlrtECI = { -1, 353, 22, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo mg_emlrtRTEI = { 71, 15, "reshape",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 86, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 93, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 101, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 258, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 220, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 222, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 315, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 315, 21, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 323, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 330, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 352, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 353, 24, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

/* Function Definitions */

/*
 * function output = Mybesseli(alpha,xx,scale)
 */
void Mybesseli(const emlrtStack *sp, emxArray_real_T *xx, emxArray_real_T
               *output)
{
  emxArray_real_T *b;
  int32_T i27;
  int32_T nx;
  uint32_T resize_idx_0;
  int32_T ixstart;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T idx;
  boolean_T overflow;
  boolean_T exitg8;
  boolean_T guard4 = false;
  int32_T iv37[2];
  emxArray_real_T *v;
  emxArray_real_T *tempc;
  emxArray_boolean_T *r23;
  int32_T b_ii[1];
  boolean_T exitg7;
  boolean_T guard3 = false;
  int32_T iv38[2];
  emxArray_real_T *b_x;
  real_T mtmp;
  emxArray_real_T *p;
  boolean_T exitg6;
  boolean_T exitg2;
  real_T n;
  boolean_T guard2 = false;
  real_T en;
  int32_T iv39[2];
  real_T test;
  emxArray_real_T *a;
  boolean_T exitg5;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv40[2];
  int32_T c_ii[1];
  int32_T b_v[1];
  emxArray_real_T *b_b;
  int32_T d_ii[1];
  int32_T c_v[1];
  int32_T e_ii[1];
  int32_T d_v[1];
  int32_T count;
  emxArray_boolean_T *b_p;
  emxArray_real_T *b_en;
  emxArray_real_T *c_en;
  int32_T exitg4;
  emxArray_real_T *tempa;
  real_T em;
  real_T empal;
  real_T emp2al;
  real_T nend;
  int32_T skip;
  int32_T f_ii[1];
  int32_T count2;
  int32_T l;
  emxArray_real_T *d_en;
  emxArray_real_T *e_en;
  int32_T exitg3;
  emxArray_int32_T *r24;
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
  emxInit_real_T1(sp, &b, 1, &sc_emlrtRTEI, true);
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
  /* 'Mybesseli:56' scale = 0; */
  /*  */
  /*   Break alpha into integer and fractional parts, */
  /*   and initialize result array. */
  /*  */
  /* 'Mybesseli:61' nfirst = fix(alpha(1)); */
  /* 'Mybesseli:62' nb = fix(alpha(length(alpha))) + 1; */
  /* 'Mybesseli:63' b = NaN*ones(length(xx),nb); */
  i27 = b->size[0];
  b->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  nx = xx->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    b->data[i27] = rtNaN;
  }

  /* 'Mybesseli:64' if ~(nb <= 1001) */
  covrtLogCond(&emlrtCoverageInstance, 11U, 0U, 0, true);
  covrtLogMcdc(&emlrtCoverageInstance, 11U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, false);

  /* 'Mybesseli:67' if length(alpha) > 1 */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 1, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1);

  /*     resize = (length(alpha) == 1); */
  /* 'Mybesseli:73' resize_flag = (length(alpha) == 1); */
  /*     if resize, resize = size(xx); end */
  /* 'Mybesseli:75' if resize_flag */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2);

  /* 'Mybesseli:76' resize = size(xx); */
  resize_idx_0 = (uint32_T)xx->size[0];
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3);

  /* 'Mybesseli:78' xx = xx(:); */
  ixstart = xx->size[0];
  i27 = xx->size[0];
  xx->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)xx, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  emxInit_boolean_T1(sp, &x, 1, &rc_emlrtRTEI, true);

  /*     b = NaN*ones(length(xx),nb); */
  /* 'Mybesseli:80' alpha = alpha(1) - nfirst; */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  /* 'Mybesseli:84' v = find(1.e3 < xx); */
  st.site = &wi_emlrtRSI;
  i27 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i27, (int32_T)sizeof(boolean_T),
                    &rc_emlrtRTEI);
  nx = xx->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    x->data[i27] = (1000.0 < xx->data[i27]);
  }

  emxInit_int32_T1(&st, &ii, 1, &x_emlrtRTEI, true);
  b_st.site = &kc_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i27 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                    &rc_emlrtRTEI);
  c_st.site = &lc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
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
    emlrtErrorWithMessageIdR2012b(&b_st, &rf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i27 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i27, (int32_T)sizeof
                        (int32_T), &rc_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i27 = 0;
    } else {
      i27 = idx;
    }

    iv37[0] = 1;
    iv37[1] = i27;
    c_st.site = &mc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv37);
    idx = ii->size[0];
    ii->size[0] = i27;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &v_emlrtRTEI);
  }

  emxInit_real_T1(&b_st, &v, 1, &tc_emlrtRTEI, true);
  i27 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  nx = ii->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    v->data[i27] = ii->data[i27];
  }

  /* 'Mybesseli:85' if any(v) */
  emxInit_real_T1(sp, &tempc, 1, &yc_emlrtRTEI, true);
  st.site = &xi_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 4, c_any(&st, v))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 4);

    /* 'Mybesseli:86' x = xx(v); */
    ixstart = xx->size[0];
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ke_emlrtBCI, sp);
      }
    }

    /* 'Mybesseli:87' if scale */
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 5, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 6);

    /* 'Mybesseli:92' else */
    /* 'Mybesseli:93' b(v,:) = Inf*ones(length(v),nb); */
    ixstart = b->size[0];
    i27 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &le_emlrtBCI, sp);
      }

      ii->data[i27] = idx - 1;
    }

    i27 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      tempc->data[i27] = rtInf;
    }

    b_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(b_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &gb_emlrtECI, sp);
    nx = tempc->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      b->data[ii->data[i27]] = tempc->data[i27];
    }
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 7);

  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  /* 'Mybesseli:99' v = find((1.e-4 <= xx) & (xx <= 1.e3)); */
  i27 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, i27, (int32_T)sizeof(boolean_T),
                    &rc_emlrtRTEI);
  nx = xx->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    x->data[i27] = (0.0001 <= xx->data[i27]);
  }

  emxInit_boolean_T1(sp, &r23, 1, &rc_emlrtRTEI, true);
  i27 = r23->size[0];
  r23->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r23, i27, (int32_T)sizeof(boolean_T),
                    &rc_emlrtRTEI);
  nx = xx->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    r23->data[i27] = (xx->data[i27] <= 1000.0);
  }

  i27 = x->size[0];
  idx = r23->size[0];
  if (i27 != idx) {
    emlrtSizeEqCheck1DR2012b(i27, idx, &ab_emlrtECI, sp);
  }

  st.site = &yi_emlrtRSI;
  i27 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i27, (int32_T)sizeof(boolean_T),
                    &rc_emlrtRTEI);
  nx = x->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    x->data[i27] = (x->data[i27] && r23->data[i27]);
  }

  b_st.site = &kc_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i27 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                    &rc_emlrtRTEI);
  c_st.site = &lc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
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
    emlrtErrorWithMessageIdR2012b(&b_st, &rf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i27 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i27, (int32_T)sizeof
                        (int32_T), &rc_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i27 = 0;
    } else {
      i27 = idx;
    }

    iv38[0] = 1;
    iv38[1] = i27;
    c_st.site = &mc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv38);
    idx = ii->size[0];
    ii->size[0] = i27;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &v_emlrtRTEI);
  }

  i27 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  nx = ii->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    v->data[i27] = ii->data[i27];
  }

  /* 'Mybesseli:100' if any(v) */
  st.site = &aj_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 6, c_any(&st, v))) {
    emxInit_real_T1(sp, &b_x, 1, &uc_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 8);

    /* 'Mybesseli:101' x = xx(v); */
    ixstart = xx->size[0];
    i27 = b_x->size[0];
    b_x->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &me_emlrtBCI, sp);
      }

      b_x->data[i27] = xx->data[idx - 1];
    }

    /* 'Mybesseli:102' magx = max(fix(x)); */
    i27 = tempc->size[0];
    tempc->size[0] = b_x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = b_x->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      tempc->data[i27] = b_x->data[i27];
    }

    st.site = &bj_emlrtRSI;
    c_fix(&st, tempc);
    st.site = &bj_emlrtRSI;
    b_st.site = &fb_emlrtRSI;
    c_st.site = &gb_emlrtRSI;
    if ((tempc->size[0] == 1) || (tempc->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &ig_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (tempc->size[0] > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &hg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &hb_emlrtRSI;
    ixstart = 1;
    nx = tempc->size[0];
    mtmp = tempc->data[0];
    if (tempc->size[0] > 1) {
      if (muDoubleScalarIsNaN(tempc->data[0])) {
        e_st.site = &ib_emlrtRSI;
        overflow = (tempc->size[0] > 2147483646);
        if (overflow) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
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
        e_st.site = &jb_emlrtRSI;
        overflow = ((!(ixstart + 1 > tempc->size[0])) && (tempc->size[0] >
          2147483646));
        if (overflow) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        while (ixstart + 1 <= nx) {
          if (tempc->data[ixstart] > mtmp) {
            mtmp = tempc->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    emxInit_real_T1(&d_st, &p, 1, &vc_emlrtRTEI, true);

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
    b_rdivide(sp, en, b_x, p);

    /*  */
    /*      Calculate general significance test. */
    /*  */
    /* 'Mybesseli:114' test = 2/eps; */
    /* 'Mybesseli:115' if (2*magx > 80) */
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 7, 2.0 * mtmp > 80.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 9);

      /* 'Mybesseli:116' test = sqrt(test*max(p)); */
      st.site = &cj_emlrtRSI;
      b_st.site = &fb_emlrtRSI;
      c_st.site = &gb_emlrtRSI;
      if ((p->size[0] == 1) || (p->size[0] != 1)) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &ig_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (p->size[0] > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &hg_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &hb_emlrtRSI;
      ixstart = 1;
      nx = p->size[0];
      mtmp = p->data[0];
      if (p->size[0] > 1) {
        if (muDoubleScalarIsNaN(p->data[0])) {
          e_st.site = &ib_emlrtRSI;
          overflow = (p->size[0] > 2147483646);
          if (overflow) {
            f_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&f_st, true);
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
          e_st.site = &jb_emlrtRSI;
          overflow = ((!(ixstart + 1 > p->size[0])) && (p->size[0] > 2147483646));
          if (overflow) {
            f_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&f_st, true);
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
      st.site = &cj_emlrtRSI;
      b_sqrt(&st, &test);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 10);

      /* 'Mybesseli:117' else */
      /* 'Mybesseli:118' test = test / 1.585^magx; */
      st.site = &dj_emlrtRSI;
      mtmp = b_mpower(&st, 1.585, mtmp);
      test = 9.007199254740992E+15 / mtmp;
    }

    emxInit_real_T1(sp, &a, 1, &wc_emlrtRTEI, true);
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
    /* 'Mybesseli:188' a = p; */
    i27 = a->size[0];
    a->size[0] = p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = p->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      a->data[i27] = p->data[i27];
    }

    /* 'Mybesseli:189' count = 0; */
    count = 0;

    /* 'Mybesseli:190' while any(p < test) */
    emxInit_boolean_T1(sp, &b_p, 1, &rc_emlrtRTEI, true);
    emxInit_real_T1(sp, &b_en, 1, &rc_emlrtRTEI, true);
    emxInit_real_T1(sp, &c_en, 1, &rc_emlrtRTEI, true);
    do {
      exitg4 = 0;
      i27 = b_p->size[0];
      b_p->size[0] = p->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_p, i27, (int32_T)sizeof
                        (boolean_T), &rc_emlrtRTEI);
      nx = p->size[0];
      for (i27 = 0; i27 < nx; i27++) {
        b_p->data[i27] = (p->data[i27] < test);
      }

      st.site = &ej_emlrtRSI;
      if (covrtLogWhile(&emlrtCoverageInstance, 11U, 0U, 0, d_any(&st, b_p))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 12);

        /* 'Mybesseli:191' n = n + 1; */
        n++;

        /* 'Mybesseli:192' en = en + 2; */
        en += 2.0;

        /* 'Mybesseli:193' if count == 1 */
        if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 8, count == 1)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 13);

          /* 'Mybesseli:194' plast = a; */
          /* 'Mybesseli:195' pold = plast; */
          i27 = tempc->size[0];
          tempc->size[0] = a->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)tempc, i27, (int32_T)sizeof
                            (real_T), &rc_emlrtRTEI);
          nx = a->size[0];
          for (i27 = 0; i27 < nx; i27++) {
            tempc->data[i27] = a->data[i27];
          }

          /* 'Mybesseli:196' a = p; */
          i27 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i27, (int32_T)sizeof
                            (real_T), &rc_emlrtRTEI);
          nx = p->size[0];
          for (i27 = 0; i27 < nx; i27++) {
            a->data[i27] = p->data[i27];
          }

          /* 'Mybesseli:197' p = en * a./x + pold; */
          i27 = c_en->size[0];
          c_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)c_en, i27, (int32_T)sizeof
                            (real_T), &rc_emlrtRTEI);
          nx = p->size[0];
          for (i27 = 0; i27 < nx; i27++) {
            c_en->data[i27] = en * p->data[i27];
          }

          st.site = &fj_emlrtRSI;
          rdivide(&st, c_en, b_x, p);
          i27 = p->size[0];
          idx = tempc->size[0];
          if (i27 != idx) {
            emlrtSizeEqCheck1DR2012b(i27, idx, &bb_emlrtECI, sp);
          }

          i27 = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i27, (int32_T)sizeof
                            (real_T), &rc_emlrtRTEI);
          nx = p->size[0];
          for (i27 = 0; i27 < nx; i27++) {
            p->data[i27] += tempc->data[i27];
          }
        } else {
          covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 14);

          /* 'Mybesseli:198' else */
          /* 'Mybesseli:199' count = 1; */
          count = 1;

          /* 'Mybesseli:200' a = p; */
          i27 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i27, (int32_T)sizeof
                            (real_T), &rc_emlrtRTEI);
          nx = p->size[0];
          for (i27 = 0; i27 < nx; i27++) {
            a->data[i27] = p->data[i27];
          }

          /* 'Mybesseli:201' p = en * a./x + ones(length(a),1); */
          i27 = b_en->size[0];
          b_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)b_en, i27, (int32_T)sizeof
                            (real_T), &rc_emlrtRTEI);
          nx = p->size[0];
          for (i27 = 0; i27 < nx; i27++) {
            b_en->data[i27] = en * p->data[i27];
          }

          st.site = &gj_emlrtRSI;
          rdivide(&st, b_en, b_x, tempc);
          ixstart = p->size[0];
          i27 = tempc->size[0];
          if (i27 != ixstart) {
            emlrtSizeEqCheck1DR2012b(i27, ixstart, &cb_emlrtECI, sp);
          }

          i27 = p->size[0];
          p->size[0] = tempc->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i27, (int32_T)sizeof
                            (real_T), &rc_emlrtRTEI);
          nx = tempc->size[0];
          for (i27 = 0; i27 < nx; i27++) {
            p->data[i27] = tempc->data[i27] + 1.0;
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
    emxInit_real_T1(sp, &tempa, 1, &xc_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 15);

    /*  */
    /*      Initialize the backward recursion and the normalization sum. */
    /*  */
    /* 'Mybesseli:209' n = n + 1; */
    n++;

    /* 'Mybesseli:210' en = en + 2; */
    en += 2.0;

    /* 'Mybesseli:211' tempb = 0; */
    /* 'Mybesseli:212' tempa = 1 ./ p; */
    c_rdivide(sp, p, tempa);

    /* 'Mybesseli:213' em = n - 1; */
    em = n - 1.0;

    /* 'Mybesseli:214' empal = em + alpha; */
    empal = n - 1.0;

    /* 'Mybesseli:215' emp2al = (em - 1) + (alpha + alpha); */
    emp2al = (n - 1.0) - 1.0;

    /* 'Mybesseli:216' sum = tempa * empal * emp2al / em; */
    i27 = a->size[0];
    a->size[0] = tempa->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = tempa->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      a->data[i27] = tempa->data[i27] * (n - 1.0) * ((n - 1.0) - 1.0) / (n - 1.0);
    }

    /* 'Mybesseli:217' nend = n - nb; */
    nend = n - 1.0;

    /* 'Mybesseli:218' skip = 0; */
    skip = 0;

    /* 'Mybesseli:219' if (nend < 0) */
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 9, n - 1.0 < 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 16);

      /* 'Mybesseli:220' b(v,n) = tempa; */
      ixstart = b->size[0];
      i27 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                        &rc_emlrtRTEI);
      nx = v->size[0];
      for (i27 = 0; i27 < nx; i27++) {
        idx = (int32_T)v->data[i27];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &oe_emlrtBCI, sp);
        }

        ii->data[i27] = idx - 1;
      }

      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &sb_emlrtDCI, sp);
      }

      i27 = (int32_T)n;
      if (!((i27 >= 1) && (i27 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i27, 1, 1, &ie_emlrtBCI, sp);
      }

      f_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(f_ii, 1, *(int32_T (*)[1])tempa->size, 1,
        &hb_emlrtECI, sp);
      nx = tempa->size[0];
      for (i27 = 0; i27 < nx; i27++) {
        b->data[ii->data[i27]] = tempa->data[i27];
      }

      /* 'Mybesseli:221' nend = -nend; */
      /* 'Mybesseli:222' b(v,n+1:n+nend) = zeros(length(v),nend); */
      ixstart = b->size[0];
      i27 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                        &rc_emlrtRTEI);
      nx = v->size[0];
      for (i27 = 0; i27 < nx; i27++) {
        idx = (int32_T)v->data[i27];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &pe_emlrtBCI, sp);
        }

        ii->data[i27] = idx - 1;
      }

      emxInit_int32_T1(sp, &r24, 1, &rc_emlrtRTEI, true);
      i27 = r24->size[0];
      r24->size[0] = 0;
      emxEnsureCapacity(sp, (emxArray__common *)r24, i27, (int32_T)sizeof
                        (int32_T), &rc_emlrtRTEI);
      g_ii[0] = ii->size[0];
      g_ii[1] = 0;
      e_v[0] = v->size[0];
      e_v[1] = 0;
      emlrtSubAssignSizeCheckR2012b(g_ii, 2, e_v, 2, &ib_emlrtECI, sp);
      emxFree_int32_T(&r24);
    } else {
      /* 'Mybesseli:223' else */
      /* 'Mybesseli:224' if (nend > 0) */
      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 10, n - 1.0 > 0.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 17);

        /*  */
        /*            Recur backward via difference equation, calculating  */
        /*            (but not storing) b(n), until n = nb. */
        /*  */
        /* 'Mybesseli:229' kk= tempa; */
        i27 = p->size[0];
        p->size[0] = tempa->size[0];
        emxEnsureCapacity(sp, (emxArray__common *)p, i27, (int32_T)sizeof(real_T),
                          &rc_emlrtRTEI);
        nx = tempa->size[0];
        for (i27 = 0; i27 < nx; i27++) {
          p->data[i27] = tempa->data[i27];
        }

        /* 'Mybesseli:230' count2 = 0; */
        count2 = 0;

        /* 'Mybesseli:231' for l = 1:nend */
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, n - 1.0, mxDOUBLE_CLASS,
          (int32_T)(n - 1.0), &lg_emlrtRTEI, sp);
        l = 0;
        emxInit_real_T1(sp, &d_en, 1, &rc_emlrtRTEI, true);
        emxInit_real_T1(sp, &e_en, 1, &rc_emlrtRTEI, true);
        do {
          exitg3 = 0;
          if (l <= (int32_T)nend - 1) {
            covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 0, 1);
            covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 18);

            /* 'Mybesseli:232' n = n - 1; */
            n--;

            /* 'Mybesseli:233' en = en - 2; */
            en -= 2.0;

            /* 'Mybesseli:234' if count2 == 1 */
            if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 11, count2 == 1)) {
              covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 19);

              /* 'Mybesseli:235' tempb = kk; */
              /* 'Mybesseli:236' tempc = tempb; */
              i27 = tempc->size[0];
              tempc->size[0] = p->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)tempc, i27, (int32_T)
                                sizeof(real_T), &rc_emlrtRTEI);
              nx = p->size[0];
              for (i27 = 0; i27 < nx; i27++) {
                tempc->data[i27] = p->data[i27];
              }

              /* 'Mybesseli:237' kk = tempa; */
              i27 = p->size[0];
              p->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)p, i27, (int32_T)sizeof
                                (real_T), &rc_emlrtRTEI);
              nx = tempa->size[0];
              for (i27 = 0; i27 < nx; i27++) {
                p->data[i27] = tempa->data[i27];
              }

              /* 'Mybesseli:238' tempa = (en*kk) ./ x + tempc; */
              i27 = e_en->size[0];
              e_en->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)e_en, i27, (int32_T)
                                sizeof(real_T), &rc_emlrtRTEI);
              nx = tempa->size[0];
              for (i27 = 0; i27 < nx; i27++) {
                e_en->data[i27] = en * tempa->data[i27];
              }

              st.site = &hj_emlrtRSI;
              rdivide(&st, e_en, b_x, tempa);
              i27 = tempa->size[0];
              idx = tempc->size[0];
              if (i27 != idx) {
                emlrtSizeEqCheck1DR2012b(i27, idx, &db_emlrtECI, sp);
              }

              i27 = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)tempa, i27, (int32_T)
                                sizeof(real_T), &rc_emlrtRTEI);
              nx = tempa->size[0];
              for (i27 = 0; i27 < nx; i27++) {
                tempa->data[i27] += tempc->data[i27];
              }
            } else {
              covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 20);

              /* 'Mybesseli:239' else */
              /* 'Mybesseli:240' count2 = 1; */
              count2 = 1;

              /* 'Mybesseli:241' kk = tempa; */
              i27 = p->size[0];
              p->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)p, i27, (int32_T)sizeof
                                (real_T), &rc_emlrtRTEI);
              nx = tempa->size[0];
              for (i27 = 0; i27 < nx; i27++) {
                p->data[i27] = tempa->data[i27];
              }

              /* 'Mybesseli:242' tempa = (en*kk) ./ x; */
              i27 = d_en->size[0];
              d_en->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)d_en, i27, (int32_T)
                                sizeof(real_T), &rc_emlrtRTEI);
              nx = tempa->size[0];
              for (i27 = 0; i27 < nx; i27++) {
                d_en->data[i27] = en * tempa->data[i27];
              }

              st.site = &ij_emlrtRSI;
              rdivide(&st, d_en, b_x, tempa);
            }

            covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 21);

            /*                 tempc = tempb; */
            /*                 kk = tempa; */
            /*                 tempa = (en*kk) ./ x + tempc; */
            /* 'Mybesseli:247' em = em - 1; */
            em--;

            /* 'Mybesseli:248' emp2al = emp2al - 1; */
            emp2al--;

            /* 'Mybesseli:249' if (n == 1) */
            if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 12, n == 1.0)) {
              covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 22);
              exitg3 = 1;
            } else {
              /* 'Mybesseli:250' if (n == 2) */
              if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 13, n == 2.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 23);

                /* 'Mybesseli:250' emp2al = 1; */
                emp2al = 1.0;
              }

              covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 24);

              /* 'Mybesseli:251' empal = empal - 1; */
              empal--;

              /* 'Mybesseli:252' sum = (sum + tempa*empal) * emp2al / em; */
              i27 = tempc->size[0];
              tempc->size[0] = tempa->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)tempc, i27, (int32_T)
                                sizeof(real_T), &rc_emlrtRTEI);
              nx = tempa->size[0];
              for (i27 = 0; i27 < nx; i27++) {
                tempc->data[i27] = tempa->data[i27] * empal;
              }

              i27 = a->size[0];
              idx = tempc->size[0];
              if (i27 != idx) {
                emlrtSizeEqCheck1DR2012b(i27, idx, &eb_emlrtECI, sp);
              }

              i27 = a->size[0];
              emxEnsureCapacity(sp, (emxArray__common *)a, i27, (int32_T)sizeof
                                (real_T), &rc_emlrtRTEI);
              nx = a->size[0];
              for (i27 = 0; i27 < nx; i27++) {
                a->data[i27] = (a->data[i27] + tempc->data[i27]) * emp2al / em;
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
      /* 'Mybesseli:258' b(v,n) = tempa; */
      ixstart = b->size[0];
      i27 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                        &rc_emlrtRTEI);
      nx = v->size[0];
      for (i27 = 0; i27 < nx; i27++) {
        idx = (int32_T)v->data[i27];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ne_emlrtBCI, sp);
        }

        ii->data[i27] = idx - 1;
      }

      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &tb_emlrtDCI, sp);
      }

      i27 = (int32_T)n;
      if (!((i27 >= 1) && (i27 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i27, 1, 1, &je_emlrtBCI, sp);
      }

      f_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(f_ii, 1, *(int32_T (*)[1])tempa->size, 1,
        &jb_emlrtECI, sp);
      nx = tempa->size[0];
      for (i27 = 0; i27 < nx; i27++) {
        b->data[ii->data[i27]] = tempa->data[i27];
      }

      /* 'Mybesseli:259' if (nb <= 1) */
      covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 14, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 26);

      /* 'Mybesseli:260' sum = (sum + sum) + tempa; */
      i27 = a->size[0];
      idx = tempa->size[0];
      if (i27 != idx) {
        emlrtSizeEqCheck1DR2012b(i27, idx, &fb_emlrtECI, sp);
      }

      i27 = a->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)a, i27, (int32_T)sizeof(real_T),
                        &rc_emlrtRTEI);
      nx = a->size[0];
      for (i27 = 0; i27 < nx; i27++) {
        a->data[i27] = (a->data[i27] + a->data[i27]) + tempa->data[i27];
      }

      /* 'Mybesseli:261' skip = -1; */
      skip = -1;
    }

    emxFree_real_T(&tempa);
    emxFree_real_T(&p);

    /* 'Mybesseli:280' if skip == 0 */
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 17, skip == 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 32);

      /* 'Mybesseli:281' nend = n - 2; */
      /* 'Mybesseli:282' if (nend > 0) */
      covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 18, n - 2.0 > 0.0);
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
    /* 'Mybesseli:310' if (alpha ~= 0) */
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 20, false);

    /* 'Mybesseli:313' if ~scale */
    covrtLogCond(&emlrtCoverageInstance, 11U, 0U, 1, false);
    covrtLogMcdc(&emlrtCoverageInstance, 11U, 0U, 1, true);
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 21, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 37);

    /* 'Mybesseli:313' sum = sum .* exp(-x); */
    i27 = b_x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = b_x->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      b_x->data[i27] = -b_x->data[i27];
    }

    st.site = &jj_emlrtRSI;
    b_exp(&st, b_x);
    i27 = a->size[0];
    idx = b_x->size[0];
    if (i27 != idx) {
      emlrtSizeEqCheck1DR2012b(i27, idx, &kb_emlrtECI, sp);
    }

    i27 = a->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = a->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      a->data[i27] *= b_x->data[i27];
    }

    emxFree_real_T(&b_x);

    /* 'Mybesseli:314' for n = 1:nb */
    covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 38);

    /* 'Mybesseli:315' b(v,n) = b(v,n) ./ sum; */
    ixstart = b->size[0];
    i27 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &qe_emlrtBCI, sp);
      }

      ii->data[i27] = idx - 1;
    }

    emxInit_real_T1(sp, &c_b, 1, &rc_emlrtRTEI, true);
    ixstart = b->size[0];
    i27 = c_b->size[0];
    c_b->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)c_b, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &re_emlrtBCI, sp);
      }

      c_b->data[i27] = b->data[idx - 1];
    }

    st.site = &kj_emlrtRSI;
    rdivide(&st, c_b, a, tempc);
    h_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(h_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &lb_emlrtECI, sp);
    nx = tempc->size[0];
    emxFree_real_T(&c_b);
    emxFree_real_T(&a);
    for (i27 = 0; i27 < nx; i27++) {
      b->data[ii->data[i27]] = tempc->data[i27];
    }

    covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 0);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 39);

  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  /* 'Mybesseli:321' v = find((0 < xx) & (xx < 1.e-4)); */
  i27 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, i27, (int32_T)sizeof(boolean_T),
                    &rc_emlrtRTEI);
  nx = xx->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    x->data[i27] = (0.0 < xx->data[i27]);
  }

  i27 = r23->size[0];
  r23->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r23, i27, (int32_T)sizeof(boolean_T),
                    &rc_emlrtRTEI);
  nx = xx->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    r23->data[i27] = (xx->data[i27] < 0.0001);
  }

  i27 = x->size[0];
  idx = r23->size[0];
  if (i27 != idx) {
    emlrtSizeEqCheck1DR2012b(i27, idx, &mb_emlrtECI, sp);
  }

  st.site = &lj_emlrtRSI;
  i27 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i27, (int32_T)sizeof(boolean_T),
                    &rc_emlrtRTEI);
  nx = x->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    x->data[i27] = (x->data[i27] && r23->data[i27]);
  }

  emxFree_boolean_T(&r23);
  b_st.site = &kc_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i27 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                    &rc_emlrtRTEI);
  c_st.site = &lc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
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
    emlrtErrorWithMessageIdR2012b(&b_st, &rf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i27 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i27, (int32_T)sizeof
                        (int32_T), &rc_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i27 = 0;
    } else {
      i27 = idx;
    }

    iv39[0] = 1;
    iv39[1] = i27;
    c_st.site = &mc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv39);
    idx = ii->size[0];
    ii->size[0] = i27;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &v_emlrtRTEI);
  }

  i27 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  nx = ii->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    v->data[i27] = ii->data[i27];
  }

  /* 'Mybesseli:322' if any(v) */
  st.site = &mj_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 22, c_any(&st, v))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 40);

    /* 'Mybesseli:323' x = xx(v); */
    ixstart = xx->size[0];
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &se_emlrtBCI, sp);
      }
    }

    /* 'Mybesseli:324' tempa = ones(length(x),1); */
    /* 'Mybesseli:325' empal = 1 + alpha; */
    /* 'Mybesseli:326' halfx = 0.5 * x; */
    i27 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      tempc->data[i27] = 0.5 * xx->data[(int32_T)v->data[i27] - 1];
    }

    /* 'Mybesseli:327' if (alpha ~= 0) */
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 23, false);

    /* 'Mybesseli:328' if scale */
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 24, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 43);

    /* 'Mybesseli:329' tempb = halfx .* halfx; */
    i27 = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    nx = tempc->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      tempc->data[i27] *= tempc->data[i27];
    }

    /* 'Mybesseli:330' b(v,1) = tempa + tempa.*tempb / empal; */
    ixstart = v->size[0];
    i27 = tempc->size[0];
    if (ixstart != i27) {
      emlrtSizeEqCheck1DR2012b(ixstart, i27, &nb_emlrtECI, sp);
    }

    i27 = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i27, (int32_T)sizeof(real_T),
                      &rc_emlrtRTEI);
    ixstart = v->size[0];
    i27 = tempc->size[0];
    if (ixstart != i27) {
      emlrtSizeEqCheck1DR2012b(ixstart, i27, &ob_emlrtECI, sp);
    }

    ixstart = b->size[0];
    i27 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &te_emlrtBCI, sp);
      }

      ii->data[i27] = idx - 1;
    }

    c_ii[0] = ii->size[0];
    b_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(c_ii, 1, b_v, 1, &pb_emlrtECI, sp);
    ixstart = v->size[0];
    for (i27 = 0; i27 < ixstart; i27++) {
      b->data[ii->data[i27]] = 1.0 + tempc->data[i27];
    }

    /* 'Mybesseli:331' if (nb > 1) */
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 25, false);
  }

  emxFree_real_T(&tempc);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 46);

  /*  */
  /*   x == 0 */
  /*  */
  /* 'Mybesseli:349' v = find(xx == 0); */
  st.site = &nj_emlrtRSI;
  i27 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i27, (int32_T)sizeof(boolean_T),
                    &rc_emlrtRTEI);
  nx = xx->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    x->data[i27] = (xx->data[i27] == 0.0);
  }

  b_st.site = &kc_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i27 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                    &rc_emlrtRTEI);
  c_st.site = &lc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
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
    emlrtErrorWithMessageIdR2012b(&b_st, &rf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i27 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i27, (int32_T)sizeof
                        (int32_T), &rc_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i27 = 0;
    } else {
      i27 = idx;
    }

    iv40[0] = 1;
    iv40[1] = i27;
    c_st.site = &mc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv40);
    idx = ii->size[0];
    ii->size[0] = i27;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &v_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  i27 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  nx = ii->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    v->data[i27] = ii->data[i27];
  }

  /* 'Mybesseli:350' if any(v) */
  st.site = &oj_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 26, c_any(&st, v))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 47);

    /*  if alpha>0, I(alpha,0) = 0; I(0,0) = 1. */
    /* 'Mybesseli:352' b(v,:) = zeros(length(v),nb); */
    ixstart = b->size[0];
    i27 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ue_emlrtBCI, sp);
      }

      ii->data[i27] = idx - 1;
    }

    d_ii[0] = ii->size[0];
    c_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(d_ii, 1, c_v, 1, &qb_emlrtECI, sp);
    ixstart = v->size[0];
    for (i27 = 0; i27 < ixstart; i27++) {
      b->data[ii->data[i27]] = 0.0;
    }

    /* 'Mybesseli:353' if alpha == 0 */
    covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 27, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 48);

    /* 'Mybesseli:353' b(v,1) = ones(length(v),1); */
    ixstart = b->size[0];
    i27 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i27, (int32_T)sizeof(int32_T),
                      &rc_emlrtRTEI);
    nx = v->size[0];
    for (i27 = 0; i27 < nx; i27++) {
      idx = (int32_T)v->data[i27];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ve_emlrtBCI, sp);
      }

      ii->data[i27] = idx - 1;
    }

    e_ii[0] = ii->size[0];
    d_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(e_ii, 1, d_v, 1, &rb_emlrtECI, sp);
    ixstart = v->size[0];
    for (i27 = 0; i27 < ixstart; i27++) {
      b->data[ii->data[i27]] = 1.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&v);
  emxInit_real_T1(sp, &b_b, 1, &rc_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 49);

  /*  */
  /*   Return the requested index range */
  /*  */
  /* 'Mybesseli:358' b = b(:,nfirst+1:nb); */
  ixstart = b->size[0];
  i27 = b_b->size[0];
  b_b->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)b_b, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  for (i27 = 0; i27 < ixstart; i27++) {
    b_b->data[i27] = b->data[i27];
  }

  i27 = b->size[0];
  b->size[0] = b_b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  nx = b_b->size[0];
  for (i27 = 0; i27 < nx; i27++) {
    b->data[i27] = b_b->data[i27];
  }

  emxFree_real_T(&b_b);

  /*     if resize */
  /* 'Mybesseli:360' if resize_flag */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 28, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 50);

  /* 'Mybesseli:361' output = reshape(b,resize(1),resize(2)); */
  st.site = &pj_emlrtRSI;
  b_st.site = &rj_emlrtRSI;
  c_st.site = &vj_emlrtRSI;
  assertValidSizeArg(&c_st, resize_idx_0);
  c_st.site = &vj_emlrtRSI;
  assertValidSizeArg(&c_st, 1.0);
  nx = (int32_T)resize_idx_0;
  b_st.site = &sj_emlrtRSI;
  resize_idx_0 = (uint32_T)b->size[0];
  c_st.site = &fb_emlrtRSI;
  d_st.site = &gb_emlrtRSI;
  e_st.site = &hb_emlrtRSI;
  ixstart = (int32_T)resize_idx_0;
  if (1 > (int32_T)resize_idx_0) {
    ixstart = 1;
  }

  ixstart = muIntScalarMax_sint32(b->size[0], ixstart);
  if (nx > ixstart) {
    b_st.site = &tj_emlrtRSI;
    i_error(&b_st);
  }

  if (1 > ixstart) {
    b_st.site = &tj_emlrtRSI;
    i_error(&b_st);
  }

  i27 = output->size[0] * output->size[1];
  output->size[0] = nx;
  output->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)output, i27, (int32_T)sizeof(real_T),
                    &rc_emlrtRTEI);
  if (b->size[0] == output->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &mg_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_st.site = &uj_emlrtRSI;
  overflow = ((!(1 > b->size[0])) && (b->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (ixstart = 0; ixstart + 1 <= b->size[0]; ixstart++) {
    output->data[ixstart] = b->data[ixstart];
  }

  emxFree_real_T(&b);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * function output = Mybesseli(alpha,xx,scale)
 */
real_T b_Mybesseli(const emlrtStack *sp)
{
  real_T n;
  real_T en;
  real_T p;
  real_T a;
  int32_T count;
  real_T tempa;
  real_T pold;
  real_T em;
  real_T empal;
  real_T emp2al;
  real_T c_sum;
  real_T nend;
  real_T kk;
  int32_T count2;
  int32_T l;
  int32_T exitg1;
  int32_T i31;
  real_T tempc;
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
  /* 'Mybesseli:56' scale = 0; */
  /*  */
  /*   Break alpha into integer and fractional parts, */
  /*   and initialize result array. */
  /*  */
  /* 'Mybesseli:61' nfirst = fix(alpha(1)); */
  /* 'Mybesseli:62' nb = fix(alpha(length(alpha))) + 1; */
  /* 'Mybesseli:63' b = NaN*ones(length(xx),nb); */
  /* 'Mybesseli:64' if ~(nb <= 1001) */
  covrtLogCond(&emlrtCoverageInstance, 11U, 0U, 0, true);
  covrtLogMcdc(&emlrtCoverageInstance, 11U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, false);

  /* 'Mybesseli:67' if length(alpha) > 1 */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 1, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1);

  /*     resize = (length(alpha) == 1); */
  /* 'Mybesseli:73' resize_flag = (length(alpha) == 1); */
  /*     if resize, resize = size(xx); end */
  /* 'Mybesseli:75' if resize_flag */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2);

  /* 'Mybesseli:76' resize = size(xx); */
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3);

  /* 'Mybesseli:78' xx = xx(:); */
  /*     b = NaN*ones(length(xx),nb); */
  /* 'Mybesseli:80' alpha = alpha(1) - nfirst; */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  /* 'Mybesseli:84' v = find(1.e3 < xx); */
  /* 'Mybesseli:85' if any(v) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 4, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 7);

  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  /* 'Mybesseli:99' v = find((1.e-4 <= xx) & (xx <= 1.e3)); */
  /* 'Mybesseli:100' if any(v) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 6, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 8);

  /* 'Mybesseli:101' x = xx(v); */
  /* 'Mybesseli:102' magx = max(fix(x)); */
  /*  */
  /*      Initialize the forward sweep, the p-sequence of Olver. */
  /*  */
  /* 'Mybesseli:106' nbmx = nb-magx; */
  /* 'Mybesseli:107' n = magx+1; */
  n = 1.0;

  /* 'Mybesseli:108' en = (n+n) + (alpha+alpha); */
  en = 2.0;

  /* 'Mybesseli:109' plast = 1; */
  /* 'Mybesseli:110' p = en ./ x; */
  p = 4.0;

  /*  */
  /*      Calculate general significance test. */
  /*  */
  /* 'Mybesseli:114' test = 2/eps; */
  /* 'Mybesseli:115' if (2*magx > 80) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 7, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 10);

  /* 'Mybesseli:117' else */
  /* 'Mybesseli:118' test = test / 1.585^magx; */
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
  /* 'Mybesseli:188' a = p; */
  a = 4.0;

  /* 'Mybesseli:189' count = 0; */
  count = 0;

  /* 'Mybesseli:190' while any(p < test) */
  while (covrtLogWhile(&emlrtCoverageInstance, 11U, 0U, 0, !!(p <
           9.007199254740992E+15))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 12);

    /* 'Mybesseli:191' n = n + 1; */
    n++;

    /* 'Mybesseli:192' en = en + 2; */
    en += 2.0;

    /* 'Mybesseli:193' if count == 1 */
    if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 8, count == 1)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 13);

      /* 'Mybesseli:194' plast = a; */
      /* 'Mybesseli:195' pold = plast; */
      pold = a;

      /* 'Mybesseli:196' a = p; */
      a = p;

      /* 'Mybesseli:197' p = en * a./x + pold; */
      p = en * p / 0.5 + pold;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 14);

      /* 'Mybesseli:198' else */
      /* 'Mybesseli:199' count = 1; */
      count = 1;

      /* 'Mybesseli:200' a = p; */
      a = p;

      /* 'Mybesseli:201' p = en * a./x + ones(length(a),1); */
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
  /* 'Mybesseli:209' n = n + 1; */
  n++;

  /* 'Mybesseli:210' en = en + 2; */
  en += 2.0;

  /* 'Mybesseli:211' tempb = 0; */
  /* 'Mybesseli:212' tempa = 1 ./ p; */
  tempa = 1.0 / p;

  /* 'Mybesseli:213' em = n - 1; */
  em = n - 1.0;

  /* 'Mybesseli:214' empal = em + alpha; */
  empal = n - 1.0;

  /* 'Mybesseli:215' emp2al = (em - 1) + (alpha + alpha); */
  emp2al = (n - 1.0) - 1.0;

  /* 'Mybesseli:216' sum = tempa * empal * emp2al / em; */
  c_sum = tempa * (n - 1.0) * ((n - 1.0) - 1.0) / (n - 1.0);

  /* 'Mybesseli:217' nend = n - nb; */
  nend = n - 1.0;

  /* 'Mybesseli:218' skip = 0; */
  /* 'Mybesseli:219' if (nend < 0) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 9, false);

  /* 'Mybesseli:223' else */
  /* 'Mybesseli:224' if (nend > 0) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 10, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 17);

  /*  */
  /*            Recur backward via difference equation, calculating  */
  /*            (but not storing) b(n), until n = nb. */
  /*  */
  /* 'Mybesseli:229' kk= tempa; */
  kk = tempa;

  /* 'Mybesseli:230' count2 = 0; */
  count2 = 0;

  /* 'Mybesseli:231' for l = 1:nend */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n - 1.0, mxDOUBLE_CLASS, (int32_T)(n -
    1.0), &lg_emlrtRTEI, sp);
  l = 0;
  do {
    exitg1 = 0;
    if (l <= (int32_T)nend - 1) {
      covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 18);

      /* 'Mybesseli:232' n = n - 1; */
      n--;

      /* 'Mybesseli:233' en = en - 2; */
      en -= 2.0;

      /* 'Mybesseli:234' if count2 == 1 */
      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 11, count2 == 1)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 19);

        /* 'Mybesseli:235' tempb = kk; */
        /* 'Mybesseli:236' tempc = tempb; */
        tempc = kk;

        /* 'Mybesseli:237' kk = tempa; */
        kk = tempa;

        /* 'Mybesseli:238' tempa = (en*kk) ./ x + tempc; */
        tempa = en * tempa / 0.5 + tempc;
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 20);

        /* 'Mybesseli:239' else */
        /* 'Mybesseli:240' count2 = 1; */
        count2 = 1;

        /* 'Mybesseli:241' kk = tempa; */
        kk = tempa;

        /* 'Mybesseli:242' tempa = (en*kk) ./ x; */
        tempa = en * tempa / 0.5;
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 21);

      /*                 tempc = tempb; */
      /*                 kk = tempa; */
      /*                 tempa = (en*kk) ./ x + tempc; */
      /* 'Mybesseli:247' em = em - 1; */
      em--;

      /* 'Mybesseli:248' emp2al = emp2al - 1; */
      emp2al--;

      /* 'Mybesseli:249' if (n == 1) */
      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 12, n == 1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 22);
        exitg1 = 1;
      } else {
        /* 'Mybesseli:250' if (n == 2) */
        if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 13, n == 2.0)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 23);

          /* 'Mybesseli:250' emp2al = 1; */
          emp2al = 1.0;
        }

        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 24);

        /* 'Mybesseli:251' empal = empal - 1; */
        empal--;

        /* 'Mybesseli:252' sum = (sum + tempa*empal) * emp2al / em; */
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
  /* 'Mybesseli:258' b(v,n) = tempa; */
  i31 = (int32_T)n;
  if (!((i31 >= 1) && (i31 <= 1))) {
    emlrtDynamicBoundsCheckR2012b(i31, 1, 1, &je_emlrtBCI, sp);
  }

  /* 'Mybesseli:259' if (nb <= 1) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 14, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 26);

  /* 'Mybesseli:260' sum = (sum + sum) + tempa; */
  c_sum = (c_sum + c_sum) + tempa;

  /* 'Mybesseli:261' skip = -1; */
  /* 'Mybesseli:280' if skip == 0 */
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
  /* 'Mybesseli:310' if (alpha ~= 0) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 20, false);

  /* 'Mybesseli:313' if ~scale */
  covrtLogCond(&emlrtCoverageInstance, 11U, 0U, 1, false);
  covrtLogMcdc(&emlrtCoverageInstance, 11U, 0U, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 21, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 37);

  /* 'Mybesseli:313' sum = sum .* exp(-x); */
  c_sum *= 0.60653065971263342;

  /* 'Mybesseli:314' for n = 1:nb */
  covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 38);

  /* 'Mybesseli:315' b(v,n) = b(v,n) ./ sum; */
  covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 39);

  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  /* 'Mybesseli:321' v = find((0 < xx) & (xx < 1.e-4)); */
  /* 'Mybesseli:322' if any(v) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 22, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 46);

  /*  */
  /*   x == 0 */
  /*  */
  /* 'Mybesseli:349' v = find(xx == 0); */
  /* 'Mybesseli:350' if any(v) */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 26, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 49);

  /*  */
  /*   Return the requested index range */
  /*  */
  /* 'Mybesseli:358' b = b(:,nfirst+1:nb); */
  /*     if resize */
  /* 'Mybesseli:360' if resize_flag */
  covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 28, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 50);

  /* 'Mybesseli:361' output = reshape(b,resize(1),resize(2)); */
  return tempa / c_sum;
}

/* End of code generation (Mybesseli.c) */
