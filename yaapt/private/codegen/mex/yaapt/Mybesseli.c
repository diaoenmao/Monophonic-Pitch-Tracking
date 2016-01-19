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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo cf_emlrtRSI = { 84, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo df_emlrtRSI = { 85, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ef_emlrtRSI = { 99, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo ff_emlrtRSI = { 100, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo gf_emlrtRSI = { 102, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo hf_emlrtRSI = { 116, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo if_emlrtRSI = { 118, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo jf_emlrtRSI = { 190, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo kf_emlrtRSI = { 197, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo lf_emlrtRSI = { 201, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo mf_emlrtRSI = { 238, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo nf_emlrtRSI = { 242, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo of_emlrtRSI = { 313, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo pf_emlrtRSI = { 315, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo qf_emlrtRSI = { 321, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo rf_emlrtRSI = { 322, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo sf_emlrtRSI = { 349, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo tf_emlrtRSI = { 350, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo uf_emlrtRSI = { 361, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRSInfo vf_emlrtRSI = { 234, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRSInfo yf_emlrtRSI = { 39, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo ag_emlrtRSI = { 50, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo bg_emlrtRSI = { 53, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo cg_emlrtRSI = { 100, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRSInfo dg_emlrtRSI = { 123, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRTEInfo lb_emlrtRTEI = { 1, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo mb_emlrtRTEI = { 63, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo nb_emlrtRTEI = { 84, 4, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo ob_emlrtRTEI = { 86, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo pb_emlrtRTEI = { 110, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo qb_emlrtRTEI = { 188, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo rb_emlrtRTEI = { 212, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo sb_emlrtRTEI = { 236, 20, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo oe_emlrtRTEI = { 63, 15, "reshape",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m" };

static emlrtRTEInfo pe_emlrtRTEI = { 243, 9, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtECInfo m_emlrtECI = { -1, 353, 22, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo n_emlrtECI = { -1, 352, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo o_emlrtECI = { -1, 330, 7, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo p_emlrtECI = { -1, 330, 16, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo q_emlrtECI = { -1, 330, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo r_emlrtECI = { -1, 321, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo s_emlrtECI = { -1, 315, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo t_emlrtECI = { -1, 313, 24, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo u_emlrtECI = { -1, 258, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtBCInfo ec_emlrtBCI = { 1, 1, 258, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtDCInfo v_emlrtDCI = { 258, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtECInfo v_emlrtECI = { -1, 222, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo w_emlrtECI = { -1, 220, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtBCInfo fc_emlrtBCI = { 1, 1, 220, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 220, 14, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 1 };

static emlrtECInfo x_emlrtECI = { -1, 93, 10, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo y_emlrtECI = { -1, 260, 19, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo ab_emlrtECI = { -1, 252, 23, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo bb_emlrtECI = { -1, 238, 28, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtRTEInfo se_emlrtRTEI = { 231, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo cb_emlrtECI = { -1, 201, 18, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo db_emlrtECI = { -1, 197, 17, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtECInfo eb_emlrtECI = { -1, 99, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 86, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 93, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 101, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 258, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 220, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 222, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 315, 12, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 315, 21, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 323, 11, "xx", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 330, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 352, 9, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 353, 24, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

/* Function Definitions */

/*
 * function output = Mybesseli(alpha,xx,scale)
 */
void Mybesseli(const emlrtStack *sp, emxArray_real_T *xx, emxArray_real_T
               *output)
{
  emxArray_real_T *b;
  int32_T i18;
  int32_T nx;
  uint32_T resize_idx_0;
  int32_T ixstart;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T idx;
  boolean_T overflow;
  boolean_T exitg8;
  boolean_T guard4 = false;
  int32_T iv17[2];
  emxArray_real_T *v;
  emxArray_real_T *tempc;
  int32_T b_ii[1];
  emxArray_boolean_T *r7;
  boolean_T exitg7;
  boolean_T guard3 = false;
  int32_T iv18[2];
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
  int32_T iv19[2];
  emxArray_real_T *r9;
  int32_T f_ii[1];
  int32_T c_v[1];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv20[2];
  int32_T g_ii[1];
  int32_T d_v[1];
  int32_T h_ii[1];
  int32_T e_v[1];
  emxArray_real_T *c_b;
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
  emxInit_real_T1(sp, &b, 1, &mb_emlrtRTEI, true);

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
  i18 = b->size[0];
  b->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  nx = xx->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    b->data[i18] = rtNaN;
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
  i18 = xx->size[0];
  xx->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)xx, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  emxInit_boolean_T1(sp, &x, 1, &lb_emlrtRTEI, true);

  /*     b = NaN*ones(length(xx),nb); */
  /* 'Mybesseli:80' alpha = alpha(1) - nfirst; */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  /* 'Mybesseli:84' v = find(1.e3 < xx); */
  st.site = &cf_emlrtRSI;
  i18 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i18, (int32_T)sizeof(boolean_T),
                    &lb_emlrtRTEI);
  nx = xx->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    x->data[i18] = (1000.0 < xx->data[i18]);
  }

  emxInit_int32_T(&st, &ii, 1, &h_emlrtRTEI, true);
  b_st.site = &pb_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i18 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                    &lb_emlrtRTEI);
  c_st.site = &vf_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &pe_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i18 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof
                        (int32_T), &lb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i18 = 0;
    } else {
      i18 = idx;
    }

    iv17[0] = 1;
    iv17[1] = i18;
    c_st.site = &qb_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv17);
    idx = ii->size[0];
    ii->size[0] = i18;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &f_emlrtRTEI);
  }

  emxInit_real_T1(&b_st, &v, 1, &nb_emlrtRTEI, true);
  i18 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  nx = ii->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    v->data[i18] = ii->data[i18];
  }

  /* 'Mybesseli:85' if any(v) */
  emxInit_real_T1(sp, &tempc, 1, &sb_emlrtRTEI, true);
  st.site = &df_emlrtRSI;
  if (b_any(&st, v)) {
    /* 'Mybesseli:86' x = xx(v); */
    ixstart = xx->size[0];
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &gc_emlrtBCI, sp);
      }
    }

    /* 'Mybesseli:87' if scale */
    /* 'Mybesseli:92' else */
    /* 'Mybesseli:93' b(v,:) = Inf*ones(length(v),nb); */
    ixstart = b->size[0];
    i18 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &hc_emlrtBCI, sp);
      }

      ii->data[i18] = idx - 1;
    }

    i18 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      tempc->data[i18] = rtInf;
    }

    b_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(b_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &x_emlrtECI, sp);
    nx = tempc->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      b->data[ii->data[i18]] = tempc->data[i18];
    }
  }

  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  /* 'Mybesseli:99' v = find((1.e-4 <= xx) & (xx <= 1.e3)); */
  i18 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, i18, (int32_T)sizeof(boolean_T),
                    &lb_emlrtRTEI);
  nx = xx->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    x->data[i18] = (0.0001 <= xx->data[i18]);
  }

  emxInit_boolean_T1(sp, &r7, 1, &lb_emlrtRTEI, true);
  i18 = r7->size[0];
  r7->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r7, i18, (int32_T)sizeof(boolean_T),
                    &lb_emlrtRTEI);
  nx = xx->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    r7->data[i18] = (xx->data[i18] <= 1000.0);
  }

  i18 = x->size[0];
  idx = r7->size[0];
  if (i18 != idx) {
    emlrtSizeEqCheck1DR2012b(i18, idx, &eb_emlrtECI, sp);
  }

  st.site = &ef_emlrtRSI;
  i18 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i18, (int32_T)sizeof(boolean_T),
                    &lb_emlrtRTEI);
  nx = x->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    x->data[i18] = (x->data[i18] && r7->data[i18]);
  }

  b_st.site = &pb_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i18 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                    &lb_emlrtRTEI);
  c_st.site = &vf_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &pe_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i18 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof
                        (int32_T), &lb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i18 = 0;
    } else {
      i18 = idx;
    }

    iv18[0] = 1;
    iv18[1] = i18;
    c_st.site = &qb_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv18);
    idx = ii->size[0];
    ii->size[0] = i18;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &f_emlrtRTEI);
  }

  i18 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  nx = ii->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    v->data[i18] = ii->data[i18];
  }

  /* 'Mybesseli:100' if any(v) */
  st.site = &ff_emlrtRSI;
  if (b_any(&st, v)) {
    emxInit_real_T1(sp, &b_x, 1, &ob_emlrtRTEI, true);

    /* 'Mybesseli:101' x = xx(v); */
    ixstart = xx->size[0];
    i18 = b_x->size[0];
    b_x->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &ic_emlrtBCI, sp);
      }

      b_x->data[i18] = xx->data[idx - 1];
    }

    /* 'Mybesseli:102' magx = max(fix(x)); */
    i18 = tempc->size[0];
    tempc->size[0] = b_x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = b_x->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      tempc->data[i18] = b_x->data[i18];
    }

    st.site = &gf_emlrtRSI;
    c_fix(&st, tempc);
    st.site = &gf_emlrtRSI;
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    if ((tempc->size[0] == 1) || (tempc->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &re_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (tempc->size[0] > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &qe_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &gb_emlrtRSI;
    ixstart = 1;
    nx = tempc->size[0];
    mtmp = tempc->data[0];
    if (tempc->size[0] > 1) {
      if (muDoubleScalarIsNaN(tempc->data[0])) {
        e_st.site = &hb_emlrtRSI;
        overflow = (tempc->size[0] > 2147483646);
        if (overflow) {
          f_st.site = &jb_emlrtRSI;
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
        e_st.site = &ib_emlrtRSI;
        if (ixstart + 1 > tempc->size[0]) {
          overflow = false;
        } else {
          overflow = (tempc->size[0] > 2147483646);
        }

        if (overflow) {
          f_st.site = &jb_emlrtRSI;
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

    emxInit_real_T1(&d_st, &p, 1, &pb_emlrtRTEI, true);

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
      st.site = &hf_emlrtRSI;
      b_st.site = &eb_emlrtRSI;
      c_st.site = &fb_emlrtRSI;
      if ((p->size[0] == 1) || (p->size[0] != 1)) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &re_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (p->size[0] > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &qe_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &gb_emlrtRSI;
      ixstart = 1;
      nx = p->size[0];
      mtmp = p->data[0];
      if (p->size[0] > 1) {
        if (muDoubleScalarIsNaN(p->data[0])) {
          e_st.site = &hb_emlrtRSI;
          overflow = (p->size[0] > 2147483646);
          if (overflow) {
            f_st.site = &jb_emlrtRSI;
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
          e_st.site = &ib_emlrtRSI;
          if (ixstart + 1 > p->size[0]) {
            overflow = false;
          } else {
            overflow = (p->size[0] > 2147483646);
          }

          if (overflow) {
            f_st.site = &jb_emlrtRSI;
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
      st.site = &hf_emlrtRSI;
      c_sqrt(&st, &test);
    } else {
      /* 'Mybesseli:117' else */
      /* 'Mybesseli:118' test = test / 1.585^magx; */
      st.site = &if_emlrtRSI;
      mtmp = b_mpower(&st, 1.585, mtmp);
      test = 9.007199254740992E+15 / mtmp;
    }

    emxInit_real_T1(sp, &a, 1, &qb_emlrtRTEI, true);

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
    i18 = a->size[0];
    a->size[0] = p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = p->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      a->data[i18] = p->data[i18];
    }

    /* 'Mybesseli:189' count = 0; */
    count = 0;

    /* 'Mybesseli:190' while any(p < test) */
    emxInit_boolean_T1(sp, &b_p, 1, &lb_emlrtRTEI, true);
    emxInit_real_T1(sp, &b_en, 1, &lb_emlrtRTEI, true);
    emxInit_real_T1(sp, &c_en, 1, &lb_emlrtRTEI, true);
    do {
      exitg4 = 0;
      i18 = b_p->size[0];
      b_p->size[0] = p->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_p, i18, (int32_T)sizeof
                        (boolean_T), &lb_emlrtRTEI);
      nx = p->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        b_p->data[i18] = (p->data[i18] < test);
      }

      st.site = &jf_emlrtRSI;
      if (c_any(&st, b_p)) {
        /* 'Mybesseli:191' n = n + 1; */
        n++;

        /* 'Mybesseli:192' en = en + 2; */
        en += 2.0;

        /* 'Mybesseli:193' if count == 1 */
        if (count == 1) {
          /* 'Mybesseli:194' plast = a; */
          /* 'Mybesseli:195' pold = plast; */
          i18 = tempc->size[0];
          tempc->size[0] = a->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)tempc, i18, (int32_T)sizeof
                            (real_T), &lb_emlrtRTEI);
          nx = a->size[0];
          for (i18 = 0; i18 < nx; i18++) {
            tempc->data[i18] = a->data[i18];
          }

          /* 'Mybesseli:196' a = p; */
          i18 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i18, (int32_T)sizeof
                            (real_T), &lb_emlrtRTEI);
          nx = p->size[0];
          for (i18 = 0; i18 < nx; i18++) {
            a->data[i18] = p->data[i18];
          }

          /* 'Mybesseli:197' p = en * a./x + pold; */
          i18 = c_en->size[0];
          c_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)c_en, i18, (int32_T)sizeof
                            (real_T), &lb_emlrtRTEI);
          nx = p->size[0];
          for (i18 = 0; i18 < nx; i18++) {
            c_en->data[i18] = en * p->data[i18];
          }

          st.site = &kf_emlrtRSI;
          e_rdivide(&st, c_en, b_x, p);
          i18 = p->size[0];
          idx = tempc->size[0];
          if (i18 != idx) {
            emlrtSizeEqCheck1DR2012b(i18, idx, &db_emlrtECI, sp);
          }

          i18 = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i18, (int32_T)sizeof
                            (real_T), &lb_emlrtRTEI);
          nx = p->size[0];
          for (i18 = 0; i18 < nx; i18++) {
            p->data[i18] += tempc->data[i18];
          }
        } else {
          /* 'Mybesseli:198' else */
          /* 'Mybesseli:199' count = 1; */
          count = 1;

          /* 'Mybesseli:200' a = p; */
          i18 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)a, i18, (int32_T)sizeof
                            (real_T), &lb_emlrtRTEI);
          nx = p->size[0];
          for (i18 = 0; i18 < nx; i18++) {
            a->data[i18] = p->data[i18];
          }

          /* 'Mybesseli:201' p = en * a./x + ones(length(a),1); */
          i18 = b_en->size[0];
          b_en->size[0] = p->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)b_en, i18, (int32_T)sizeof
                            (real_T), &lb_emlrtRTEI);
          nx = p->size[0];
          for (i18 = 0; i18 < nx; i18++) {
            b_en->data[i18] = en * p->data[i18];
          }

          st.site = &lf_emlrtRSI;
          e_rdivide(&st, b_en, b_x, tempc);
          ixstart = p->size[0];
          i18 = tempc->size[0];
          if (i18 != ixstart) {
            emlrtSizeEqCheck1DR2012b(i18, ixstart, &cb_emlrtECI, sp);
          }

          i18 = p->size[0];
          p->size[0] = tempc->size[0];
          emxEnsureCapacity(sp, (emxArray__common *)p, i18, (int32_T)sizeof
                            (real_T), &lb_emlrtRTEI);
          nx = tempc->size[0];
          for (i18 = 0; i18 < nx; i18++) {
            p->data[i18] = tempc->data[i18] + 1.0;
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
    emxInit_real_T1(sp, &tempa, 1, &rb_emlrtRTEI, true);
    emxInit_real_T1(sp, &b_tempa, 1, &lb_emlrtRTEI, true);

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
    i18 = b_tempa->size[0];
    b_tempa->size[0] = tempa->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_tempa, i18, (int32_T)sizeof
                      (real_T), &lb_emlrtRTEI);
    nx = tempa->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      b_tempa->data[i18] = tempa->data[i18] * (n - 1.0) * ((n - 1.0) - 1.0);
    }

    b_rdivide(sp, b_tempa, n - 1.0, a);

    /* 'Mybesseli:217' nend = n - nb; */
    nend = n - 1.0;

    /* 'Mybesseli:218' skip = 0; */
    /* 'Mybesseli:219' if (nend < 0) */
    emxFree_real_T(&b_tempa);
    if (n - 1.0 < 0.0) {
      /* 'Mybesseli:220' b(v,n) = tempa; */
      ixstart = b->size[0];
      i18 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                        &lb_emlrtRTEI);
      nx = v->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        idx = (int32_T)v->data[i18];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &kc_emlrtBCI, sp);
        }

        ii->data[i18] = idx - 1;
      }

      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &w_emlrtDCI, sp);
      }

      i18 = (int32_T)n;
      if (!((i18 >= 1) && (i18 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 1, &fc_emlrtBCI, sp);
      }

      c_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(c_ii, 1, *(int32_T (*)[1])tempa->size, 1,
        &w_emlrtECI, sp);
      nx = tempa->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        b->data[ii->data[i18]] = tempa->data[i18];
      }

      /* 'Mybesseli:221' nend = -nend; */
      /* 'Mybesseli:222' b(v,n+1:n+nend) = zeros(length(v),nend); */
      ixstart = b->size[0];
      i18 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                        &lb_emlrtRTEI);
      nx = v->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        idx = (int32_T)v->data[i18];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &lc_emlrtBCI, sp);
        }

        ii->data[i18] = idx - 1;
      }

      emxInit_int32_T(sp, &r8, 1, &lb_emlrtRTEI, true);
      i18 = r8->size[0];
      r8->size[0] = 0;
      emxEnsureCapacity(sp, (emxArray__common *)r8, i18, (int32_T)sizeof(int32_T),
                        &lb_emlrtRTEI);
      d_ii[0] = ii->size[0];
      d_ii[1] = 0;
      b_v[0] = v->size[0];
      b_v[1] = 0;
      emlrtSubAssignSizeCheckR2012b(d_ii, 2, b_v, 2, &v_emlrtECI, sp);
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
        i18 = p->size[0];
        p->size[0] = tempa->size[0];
        emxEnsureCapacity(sp, (emxArray__common *)p, i18, (int32_T)sizeof(real_T),
                          &lb_emlrtRTEI);
        nx = tempa->size[0];
        for (i18 = 0; i18 < nx; i18++) {
          p->data[i18] = tempa->data[i18];
        }

        /* 'Mybesseli:230' count2 = 0; */
        count2 = 0;

        /* 'Mybesseli:231' for l = 1:nend */
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, n - 1.0, mxDOUBLE_CLASS,
          (int32_T)(n - 1.0), &se_emlrtRTEI, sp);
        l = 0;
        emxInit_real_T1(sp, &d_en, 1, &lb_emlrtRTEI, true);
        emxInit_real_T1(sp, &e_en, 1, &lb_emlrtRTEI, true);
        emxInit_real_T1(sp, &b_a, 1, &lb_emlrtRTEI, true);
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
            i18 = tempc->size[0];
            tempc->size[0] = p->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)tempc, i18, (int32_T)
                              sizeof(real_T), &lb_emlrtRTEI);
            nx = p->size[0];
            for (i18 = 0; i18 < nx; i18++) {
              tempc->data[i18] = p->data[i18];
            }

            /* 'Mybesseli:237' kk = tempa; */
            i18 = p->size[0];
            p->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)p, i18, (int32_T)sizeof
                              (real_T), &lb_emlrtRTEI);
            nx = tempa->size[0];
            for (i18 = 0; i18 < nx; i18++) {
              p->data[i18] = tempa->data[i18];
            }

            /* 'Mybesseli:238' tempa = (en*kk) ./ x + tempc; */
            i18 = e_en->size[0];
            e_en->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)e_en, i18, (int32_T)sizeof
                              (real_T), &lb_emlrtRTEI);
            nx = tempa->size[0];
            for (i18 = 0; i18 < nx; i18++) {
              e_en->data[i18] = en * tempa->data[i18];
            }

            st.site = &mf_emlrtRSI;
            e_rdivide(&st, e_en, b_x, tempa);
            i18 = tempa->size[0];
            idx = tempc->size[0];
            if (i18 != idx) {
              emlrtSizeEqCheck1DR2012b(i18, idx, &bb_emlrtECI, sp);
            }

            i18 = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)tempa, i18, (int32_T)
                              sizeof(real_T), &lb_emlrtRTEI);
            nx = tempa->size[0];
            for (i18 = 0; i18 < nx; i18++) {
              tempa->data[i18] += tempc->data[i18];
            }
          } else {
            /* 'Mybesseli:239' else */
            /* 'Mybesseli:240' count2 = 1; */
            count2 = 1;

            /* 'Mybesseli:241' kk = tempa; */
            i18 = p->size[0];
            p->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)p, i18, (int32_T)sizeof
                              (real_T), &lb_emlrtRTEI);
            nx = tempa->size[0];
            for (i18 = 0; i18 < nx; i18++) {
              p->data[i18] = tempa->data[i18];
            }

            /* 'Mybesseli:242' tempa = (en*kk) ./ x; */
            i18 = d_en->size[0];
            d_en->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)d_en, i18, (int32_T)sizeof
                              (real_T), &lb_emlrtRTEI);
            nx = tempa->size[0];
            for (i18 = 0; i18 < nx; i18++) {
              d_en->data[i18] = en * tempa->data[i18];
            }

            st.site = &nf_emlrtRSI;
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
            i18 = tempc->size[0];
            tempc->size[0] = tempa->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)tempc, i18, (int32_T)
                              sizeof(real_T), &lb_emlrtRTEI);
            nx = tempa->size[0];
            for (i18 = 0; i18 < nx; i18++) {
              tempc->data[i18] = tempa->data[i18] * empal;
            }

            i18 = a->size[0];
            idx = tempc->size[0];
            if (i18 != idx) {
              emlrtSizeEqCheck1DR2012b(i18, idx, &ab_emlrtECI, sp);
            }

            i18 = b_a->size[0];
            b_a->size[0] = a->size[0];
            emxEnsureCapacity(sp, (emxArray__common *)b_a, i18, (int32_T)sizeof
                              (real_T), &lb_emlrtRTEI);
            nx = a->size[0];
            for (i18 = 0; i18 < nx; i18++) {
              b_a->data[i18] = (a->data[i18] + tempc->data[i18]) * emp2al;
            }

            b_rdivide(sp, b_a, em, a);
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
      i18 = ii->size[0];
      ii->size[0] = v->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                        &lb_emlrtRTEI);
      nx = v->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        idx = (int32_T)v->data[i18];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &jc_emlrtBCI, sp);
        }

        ii->data[i18] = idx - 1;
      }

      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &v_emlrtDCI, sp);
      }

      i18 = (int32_T)n;
      if (!((i18 >= 1) && (i18 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 1, &ec_emlrtBCI, sp);
      }

      c_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(c_ii, 1, *(int32_T (*)[1])tempa->size, 1,
        &u_emlrtECI, sp);
      nx = tempa->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        b->data[ii->data[i18]] = tempa->data[i18];
      }

      /* 'Mybesseli:259' if (nb <= 1) */
      /* 'Mybesseli:260' sum = (sum + sum) + tempa; */
      i18 = a->size[0];
      idx = tempa->size[0];
      if (i18 != idx) {
        emlrtSizeEqCheck1DR2012b(i18, idx, &y_emlrtECI, sp);
      }

      i18 = a->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)a, i18, (int32_T)sizeof(real_T),
                        &lb_emlrtRTEI);
      nx = a->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        a->data[i18] = (a->data[i18] + a->data[i18]) + tempa->data[i18];
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
    i18 = b_x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = b_x->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      b_x->data[i18] = -b_x->data[i18];
    }

    st.site = &of_emlrtRSI;
    b_exp(&st, b_x);
    i18 = a->size[0];
    idx = b_x->size[0];
    if (i18 != idx) {
      emlrtSizeEqCheck1DR2012b(i18, idx, &t_emlrtECI, sp);
    }

    i18 = a->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = a->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      a->data[i18] *= b_x->data[i18];
    }

    emxFree_real_T(&b_x);

    /* 'Mybesseli:314' for n = 1:nb */
    /* 'Mybesseli:315' b(v,n) = b(v,n) ./ sum; */
    ixstart = b->size[0];
    i18 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &mc_emlrtBCI, sp);
      }

      ii->data[i18] = idx - 1;
    }

    emxInit_real_T1(sp, &b_b, 1, &lb_emlrtRTEI, true);
    ixstart = b->size[0];
    i18 = b_b->size[0];
    b_b->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_b, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &nc_emlrtBCI, sp);
      }

      b_b->data[i18] = b->data[idx - 1];
    }

    st.site = &pf_emlrtRSI;
    e_rdivide(&st, b_b, a, tempc);
    e_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(e_ii, 1, *(int32_T (*)[1])tempc->size, 1,
      &s_emlrtECI, sp);
    nx = tempc->size[0];
    emxFree_real_T(&b_b);
    emxFree_real_T(&a);
    for (i18 = 0; i18 < nx; i18++) {
      b->data[ii->data[i18]] = tempc->data[i18];
    }
  }

  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  /* 'Mybesseli:321' v = find((0 < xx) & (xx < 1.e-4)); */
  i18 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, i18, (int32_T)sizeof(boolean_T),
                    &lb_emlrtRTEI);
  nx = xx->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    x->data[i18] = (0.0 < xx->data[i18]);
  }

  i18 = r7->size[0];
  r7->size[0] = xx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r7, i18, (int32_T)sizeof(boolean_T),
                    &lb_emlrtRTEI);
  nx = xx->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    r7->data[i18] = (xx->data[i18] < 0.0001);
  }

  i18 = x->size[0];
  idx = r7->size[0];
  if (i18 != idx) {
    emlrtSizeEqCheck1DR2012b(i18, idx, &r_emlrtECI, sp);
  }

  st.site = &qf_emlrtRSI;
  i18 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i18, (int32_T)sizeof(boolean_T),
                    &lb_emlrtRTEI);
  nx = x->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    x->data[i18] = (x->data[i18] && r7->data[i18]);
  }

  emxFree_boolean_T(&r7);
  b_st.site = &pb_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i18 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                    &lb_emlrtRTEI);
  c_st.site = &vf_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &pe_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i18 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof
                        (int32_T), &lb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i18 = 0;
    } else {
      i18 = idx;
    }

    iv19[0] = 1;
    iv19[1] = i18;
    c_st.site = &qb_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv19);
    idx = ii->size[0];
    ii->size[0] = i18;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &f_emlrtRTEI);
  }

  i18 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  nx = ii->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    v->data[i18] = ii->data[i18];
  }

  /* 'Mybesseli:322' if any(v) */
  st.site = &rf_emlrtRSI;
  if (b_any(&st, v)) {
    /* 'Mybesseli:323' x = xx(v); */
    ixstart = xx->size[0];
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &oc_emlrtBCI, sp);
      }
    }

    /* 'Mybesseli:324' tempa = ones(length(x),1); */
    /* 'Mybesseli:325' empal = 1 + alpha; */
    /* 'Mybesseli:326' halfx = 0.5 * x; */
    i18 = tempc->size[0];
    tempc->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      tempc->data[i18] = 0.5 * xx->data[(int32_T)v->data[i18] - 1];
    }

    /* 'Mybesseli:327' if (alpha ~= 0) */
    /* 'Mybesseli:328' if scale */
    /* 'Mybesseli:329' tempb = halfx .* halfx; */
    i18 = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tempc, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = tempc->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      tempc->data[i18] *= tempc->data[i18];
    }

    emxInit_real_T1(sp, &r9, 1, &lb_emlrtRTEI, true);

    /* 'Mybesseli:330' b(v,1) = tempa + tempa.*tempb / empal; */
    ixstart = v->size[0];
    i18 = tempc->size[0];
    if (ixstart != i18) {
      emlrtSizeEqCheck1DR2012b(ixstart, i18, &q_emlrtECI, sp);
    }

    i18 = r9->size[0];
    r9->size[0] = tempc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r9, i18, (int32_T)sizeof(real_T),
                      &lb_emlrtRTEI);
    nx = tempc->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      r9->data[i18] = tempc->data[i18];
    }

    b_rdivide(sp, r9, 1.0, tempc);
    ixstart = v->size[0];
    i18 = tempc->size[0];
    if (ixstart != i18) {
      emlrtSizeEqCheck1DR2012b(ixstart, i18, &p_emlrtECI, sp);
    }

    ixstart = b->size[0];
    i18 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    emxFree_real_T(&r9);
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &pc_emlrtBCI, sp);
      }

      ii->data[i18] = idx - 1;
    }

    f_ii[0] = ii->size[0];
    c_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(f_ii, 1, c_v, 1, &o_emlrtECI, sp);
    ixstart = v->size[0];
    for (i18 = 0; i18 < ixstart; i18++) {
      b->data[ii->data[i18]] = 1.0 + tempc->data[i18];
    }

    /* 'Mybesseli:331' if (nb > 1) */
  }

  emxFree_real_T(&tempc);

  /*  */
  /*   x == 0 */
  /*  */
  /* 'Mybesseli:349' v = find(xx == 0); */
  st.site = &sf_emlrtRSI;
  i18 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i18, (int32_T)sizeof(boolean_T),
                    &lb_emlrtRTEI);
  nx = xx->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    x->data[i18] = (xx->data[i18] == 0.0);
  }

  b_st.site = &pb_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i18 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                    &lb_emlrtRTEI);
  c_st.site = &vf_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &jb_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &pe_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i18 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof
                        (int32_T), &lb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i18 = 0;
    } else {
      i18 = idx;
    }

    iv20[0] = 1;
    iv20[1] = i18;
    c_st.site = &qb_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv20);
    idx = ii->size[0];
    ii->size[0] = i18;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &f_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  i18 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)v, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  nx = ii->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    v->data[i18] = ii->data[i18];
  }

  /* 'Mybesseli:350' if any(v) */
  st.site = &tf_emlrtRSI;
  if (b_any(&st, v)) {
    /*  if alpha>0, I(alpha,0) = 0; I(0,0) = 1. */
    /* 'Mybesseli:352' b(v,:) = zeros(length(v),nb); */
    ixstart = b->size[0];
    i18 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &qc_emlrtBCI, sp);
      }

      ii->data[i18] = idx - 1;
    }

    g_ii[0] = ii->size[0];
    d_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(g_ii, 1, d_v, 1, &n_emlrtECI, sp);
    ixstart = v->size[0];
    for (i18 = 0; i18 < ixstart; i18++) {
      b->data[ii->data[i18]] = 0.0;
    }

    /* 'Mybesseli:353' if alpha == 0 */
    /* 'Mybesseli:353' b(v,1) = ones(length(v),1); */
    ixstart = b->size[0];
    i18 = ii->size[0];
    ii->size[0] = v->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                      &lb_emlrtRTEI);
    nx = v->size[0];
    for (i18 = 0; i18 < nx; i18++) {
      idx = (int32_T)v->data[i18];
      if (!((idx >= 1) && (idx <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &rc_emlrtBCI, sp);
      }

      ii->data[i18] = idx - 1;
    }

    h_ii[0] = ii->size[0];
    e_v[0] = v->size[0];
    emlrtSubAssignSizeCheckR2012b(h_ii, 1, e_v, 1, &m_emlrtECI, sp);
    ixstart = v->size[0];
    for (i18 = 0; i18 < ixstart; i18++) {
      b->data[ii->data[i18]] = 1.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&v);
  emxInit_real_T1(sp, &c_b, 1, &lb_emlrtRTEI, true);

  /*  */
  /*   Return the requested index range */
  /*  */
  /* 'Mybesseli:358' b = b(:,nfirst+1:nb); */
  ixstart = b->size[0];
  i18 = c_b->size[0];
  c_b->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)c_b, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  for (i18 = 0; i18 < ixstart; i18++) {
    c_b->data[i18] = b->data[i18];
  }

  i18 = b->size[0];
  b->size[0] = c_b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  nx = c_b->size[0];
  for (i18 = 0; i18 < nx; i18++) {
    b->data[i18] = c_b->data[i18];
  }

  emxFree_real_T(&c_b);

  /*     if resize */
  /* 'Mybesseli:360' if resize_flag */
  /* 'Mybesseli:361' output = reshape(b,resize(1),resize(2)); */
  st.site = &uf_emlrtRSI;
  b_st.site = &yf_emlrtRSI;
  c_st.site = &dg_emlrtRSI;
  assertValidSizeArg(&c_st, resize_idx_0);
  c_st.site = &dg_emlrtRSI;
  assertValidSizeArg(&c_st, 1.0);
  nx = (int32_T)resize_idx_0;
  b_st.site = &ag_emlrtRSI;
  resize_idx_0 = (uint32_T)b->size[0];
  c_st.site = &eb_emlrtRSI;
  d_st.site = &fb_emlrtRSI;
  e_st.site = &gb_emlrtRSI;
  ixstart = (int32_T)resize_idx_0;
  if (1 > (int32_T)resize_idx_0) {
    ixstart = 1;
  }

  if (b->size[0] < ixstart) {
  } else {
    ixstart = b->size[0];
  }

  if (nx > ixstart) {
    b_st.site = &bg_emlrtRSI;
    g_error(&b_st);
  }

  if (1 > ixstart) {
    b_st.site = &bg_emlrtRSI;
    g_error(&b_st);
  }

  i18 = output->size[0] * output->size[1];
  output->size[0] = nx;
  output->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)output, i18, (int32_T)sizeof(real_T),
                    &lb_emlrtRTEI);
  if (b->size[0] == output->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &oe_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_st.site = &cg_emlrtRSI;
  if (1 > b->size[0]) {
    overflow = false;
  } else {
    overflow = (b->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &jb_emlrtRSI;
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
  boolean_T exitg1;
  real_T tempc;
  int32_T i21;

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
  /* 'Mybesseli:67' if length(alpha) > 1 */
  /*     resize = (length(alpha) == 1); */
  /* 'Mybesseli:73' resize_flag = (length(alpha) == 1); */
  /*     if resize, resize = size(xx); end */
  /* 'Mybesseli:75' if resize_flag */
  /* 'Mybesseli:76' resize = size(xx); */
  /* 'Mybesseli:78' xx = xx(:); */
  /*     b = NaN*ones(length(xx),nb); */
  /* 'Mybesseli:80' alpha = alpha(1) - nfirst; */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  /* 'Mybesseli:84' v = find(1.e3 < xx); */
  /* 'Mybesseli:85' if any(v) */
  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  /* 'Mybesseli:99' v = find((1.e-4 <= xx) & (xx <= 1.e3)); */
  /* 'Mybesseli:100' if any(v) */
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
  /* 'Mybesseli:117' else */
  /* 'Mybesseli:118' test = test / 1.585^magx; */
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
  while (!!(p < 9.007199254740992E+15)) {
    /* 'Mybesseli:191' n = n + 1; */
    n++;

    /* 'Mybesseli:192' en = en + 2; */
    en += 2.0;

    /* 'Mybesseli:193' if count == 1 */
    if (count == 1) {
      /* 'Mybesseli:194' plast = a; */
      /* 'Mybesseli:195' pold = plast; */
      pold = a;

      /* 'Mybesseli:196' a = p; */
      a = p;

      /* 'Mybesseli:197' p = en * a./x + pold; */
      p = en * p / 0.5 + pold;
    } else {
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
  /* 'Mybesseli:223' else */
  /* 'Mybesseli:224' if (nend > 0) */
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
    1.0), &se_emlrtRTEI, sp);
  l = 0;
  exitg1 = false;
  while ((!exitg1) && (l <= (int32_T)nend - 1)) {
    /* 'Mybesseli:232' n = n - 1; */
    n--;

    /* 'Mybesseli:233' en = en - 2; */
    en -= 2.0;

    /* 'Mybesseli:234' if count2 == 1 */
    if (count2 == 1) {
      /* 'Mybesseli:235' tempb = kk; */
      /* 'Mybesseli:236' tempc = tempb; */
      tempc = kk;

      /* 'Mybesseli:237' kk = tempa; */
      kk = tempa;

      /* 'Mybesseli:238' tempa = (en*kk) ./ x + tempc; */
      tempa = en * tempa / 0.5 + tempc;
    } else {
      /* 'Mybesseli:239' else */
      /* 'Mybesseli:240' count2 = 1; */
      count2 = 1;

      /* 'Mybesseli:241' kk = tempa; */
      kk = tempa;

      /* 'Mybesseli:242' tempa = (en*kk) ./ x; */
      tempa = en * tempa / 0.5;
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
      exitg1 = true;
    } else {
      /* 'Mybesseli:250' if (n == 2) */
      if (n == 2.0) {
        /* 'Mybesseli:250' emp2al = 1; */
        emp2al = 1.0;
      }

      /* 'Mybesseli:251' empal = empal - 1; */
      empal--;

      /* 'Mybesseli:252' sum = (sum + tempa*empal) * emp2al / em; */
      c_sum = (c_sum + tempa * empal) * emp2al / em;
      l++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  /*  */
  /*         Store b(nb). */
  /*  */
  /* 'Mybesseli:258' b(v,n) = tempa; */
  i21 = (int32_T)n;
  if (!((i21 >= 1) && (i21 <= 1))) {
    emlrtDynamicBoundsCheckR2012b(i21, 1, 1, &ec_emlrtBCI, sp);
  }

  /* 'Mybesseli:259' if (nb <= 1) */
  /* 'Mybesseli:260' sum = (sum + sum) + tempa; */
  c_sum = (c_sum + c_sum) + tempa;

  /* 'Mybesseli:261' skip = -1; */
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
  c_sum *= 0.60653065971263342;

  /* 'Mybesseli:314' for n = 1:nb */
  /* 'Mybesseli:315' b(v,n) = b(v,n) ./ sum; */
  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  /* 'Mybesseli:321' v = find((0 < xx) & (xx < 1.e-4)); */
  /* 'Mybesseli:322' if any(v) */
  /*  */
  /*   x == 0 */
  /*  */
  /* 'Mybesseli:349' v = find(xx == 0); */
  /* 'Mybesseli:350' if any(v) */
  /*  */
  /*   Return the requested index range */
  /*  */
  /* 'Mybesseli:358' b = b(:,nfirst+1:nb); */
  /*     if resize */
  /* 'Mybesseli:360' if resize_flag */
  /* 'Mybesseli:361' output = reshape(b,resize(1),resize(2)); */
  return tempa / c_sum;
}

/* End of code generation (Mybesseli.c) */
