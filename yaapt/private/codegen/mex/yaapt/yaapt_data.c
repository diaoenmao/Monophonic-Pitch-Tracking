/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * yaapt_data.c
 *
 * Code generation for function 'yaapt_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true, false, 131419U, NULL, "yaapt", NULL,
  false, { 585839548U, 4280471661U, 1452683995U, 3644522327U }, NULL };

emlrtRSInfo y_emlrtRSI = { 44, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo ab_emlrtRSI = { 253, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo db_emlrtRSI = { 42, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo eb_emlrtRSI = { 92, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo fb_emlrtRSI = { 90, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo ib_emlrtRSI = { 25, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo jb_emlrtRSI = { 86, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo kb_emlrtRSI = { 42, "infocheck",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m" };

emlrtRSInfo lb_emlrtRSI = { 45, "infocheck",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m" };

emlrtRSInfo mb_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

emlrtRSInfo nb_emlrtRSI = { 76, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo ob_emlrtRSI = { 68, "xtrsm",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m" };

emlrtRSInfo sb_emlrtRSI = { 54, "xaxpy",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xaxpy.m" };

emlrtRSInfo kc_emlrtRSI = { 21, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo lc_emlrtRSI = { 79, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo mc_emlrtRSI = { 283, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo nc_emlrtRSI = { 291, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo pc_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

emlrtRSInfo qc_emlrtRSI = { 14, "fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" };

emlrtRSInfo rc_emlrtRSI = { 47, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo sc_emlrtRSI = { 102, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo tc_emlrtRSI = { 107, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo uc_emlrtRSI = { 120, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo wc_emlrtRSI = { 124, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRSInfo xc_emlrtRSI = { 16, "abs",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

emlrtRSInfo yc_emlrtRSI = { 67, "applyScalarFunction",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m" };

emlrtRSInfo ad_emlrtRSI = { 13, "sum",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

emlrtRSInfo bd_emlrtRSI = { 46, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRSInfo cd_emlrtRSI = { 54, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo dd_emlrtRSI = { 60, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo ed_emlrtRSI = { 34, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

emlrtRSInfo fd_emlrtRSI = { 36, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo ge_emlrtRSI = { 12, "sqrt",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" };

emlrtRSInfo df_emlrtRSI = { 16, "max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo ef_emlrtRSI = { 18, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo ff_emlrtRSI = { 97, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo gf_emlrtRSI = { 308, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo hf_emlrtRSI = { 281, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo yf_emlrtRSI = { 18, "max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo ag_emlrtRSI = { 15, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo bg_emlrtRSI = { 26, "sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" };

emlrtRSInfo eg_emlrtRSI = { 70, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo fg_emlrtRSI = { 331, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo gg_emlrtRSI = { 356, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo hg_emlrtRSI = { 361, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ig_emlrtRSI = { 441, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo jg_emlrtRSI = { 448, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo lg_emlrtRSI = { 527, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo qg_emlrtRSI = { 375, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo rg_emlrtRSI = { 384, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo bh_emlrtRSI = { 54, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

emlrtRSInfo ch_emlrtRSI = { 53, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

emlrtRSInfo dh_emlrtRSI = { 98, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

emlrtRSInfo eh_emlrtRSI = { 101, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo fh_emlrtRSI = { 292, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo hh_emlrtRSI = { 34, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRSInfo ih_emlrtRSI = { 61, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRSInfo fi_emlrtRSI = { 44, "pwchcore",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m" };

emlrtMCInfo emlrtMCI = { 20, 5, "error",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtRTEInfo d_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRTEInfo ec_emlrtRTEI = { 38, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRTEInfo md_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRTEInfo rd_emlrtRTEI = { 19, 15, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo sd_emlrtRTEI = { 39, 9, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo td_emlrtRTEI = { 404, 15, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRTEInfo ud_emlrtRTEI = { 18, 19, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRTEInfo vd_emlrtRTEI = { 39, 19, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo wd_emlrtRTEI = { 42, 19, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo xd_emlrtRTEI = { 29, 5, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

emlrtRTEInfo yd_emlrtRTEI = { 20, 5, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

emlrtRTEInfo ae_emlrtRTEI = { 16, 15, "mean",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

emlrtBCInfo qd_emlrtBCI = { 1, 1, 258, 14, "b", "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m", 0 };

emlrtRTEInfo ee_emlrtRTEI = { 231, 13, "Mybesseli",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m" };

emlrtRTEInfo he_emlrtRTEI = { 81, 19, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo ie_emlrtRTEI = { 38, 19, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo ke_emlrtRTEI = { 53, 23, "assertValidSizeArg",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m" };

emlrtRTEInfo pe_emlrtRTEI = { 99, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtBCInfo xe_emlrtBCI = { -1, -1, 46, 22, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo cf_emlrtBCI = { -1, -1, 97, 6, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo df_emlrtBCI = { -1, -1, 97, 1, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo jf_emlrtBCI = { -1, -1, 100, 14, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo kf_emlrtBCI = { -1, -1, 100, 21, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo lf_emlrtBCI = { -1, -1, 100, 4, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo mf_emlrtBCI = { -1, -1, 72, 5, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo nf_emlrtBCI = { -1, -1, 75, 31, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo of_emlrtBCI = { -1, -1, 64, 35, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo pf_emlrtBCI = { -1, -1, 54, 35, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo qf_emlrtBCI = { -1, -1, 55, 45, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo rf_emlrtBCI = { -1, -1, 56, 24, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtRSInfo dk_emlrtRSI = { 20, "error",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtRSInfo hk_emlrtRSI = { 18, "indexDivide",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\indexDivide.m" };

/* End of code generation (yaapt_data.c) */
