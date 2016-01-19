/*
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

emlrtRSInfo eb_emlrtRSI = { 16, "max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo fb_emlrtRSI = { 18, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo gb_emlrtRSI = { 97, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo hb_emlrtRSI = { 281, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo ib_emlrtRSI = { 308, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo jb_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

emlrtRSInfo mb_emlrtRSI = { 49, "power",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

emlrtRSInfo pb_emlrtRSI = { 44, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo qb_emlrtRSI = { 253, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo tb_emlrtRSI = { 42, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo ub_emlrtRSI = { 92, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo vb_emlrtRSI = { 90, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo yb_emlrtRSI = { 25, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo ac_emlrtRSI = { 86, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo bc_emlrtRSI = { 42, "infocheck",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m" };

emlrtRSInfo cc_emlrtRSI = { 45, "infocheck",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m" };

emlrtRSInfo dc_emlrtRSI = { 76, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo ec_emlrtRSI = { 68, "xtrsm",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m" };

emlrtRSInfo ic_emlrtRSI = { 54, "xaxpy",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xaxpy.m" };

emlrtRSInfo nc_emlrtRSI = { 16, "scalexpAlloc",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRSInfo cd_emlrtRSI = { 21, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo dd_emlrtRSI = { 79, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ed_emlrtRSI = { 283, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo fd_emlrtRSI = { 291, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo hd_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

emlrtRSInfo pd_emlrtRSI = { 124, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRSInfo qd_emlrtRSI = { 16, "abs",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

emlrtRSInfo rd_emlrtRSI = { 67, "applyScalarFunction",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m" };

emlrtRSInfo sd_emlrtRSI = { 13, "sum",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

emlrtRSInfo td_emlrtRSI = { 46, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRSInfo ud_emlrtRSI = { 54, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo vd_emlrtRSI = { 60, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo xd_emlrtRSI = { 36, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo af_emlrtRSI = { 12, "sqrt",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" };

emlrtRSInfo qg_emlrtRSI = { 18, "max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo rg_emlrtRSI = { 15, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo sg_emlrtRSI = { 26, "sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" };

emlrtRSInfo vg_emlrtRSI = { 70, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo wg_emlrtRSI = { 331, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo xg_emlrtRSI = { 356, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo yg_emlrtRSI = { 361, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ah_emlrtRSI = { 441, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo bh_emlrtRSI = { 448, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ch_emlrtRSI = { 520, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo eh_emlrtRSI = { 528, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo fh_emlrtRSI = { 535, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ih_emlrtRSI = { 375, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo jh_emlrtRSI = { 380, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo kh_emlrtRSI = { 384, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo sh_emlrtRSI = { 40, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

emlrtRSInfo uh_emlrtRSI = { 54, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

emlrtRSInfo vh_emlrtRSI = { 98, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

emlrtRSInfo wh_emlrtRSI = { 101, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo xh_emlrtRSI = { 292, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo bi_emlrtRSI = { 34, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRSInfo ci_emlrtRSI = { 61, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRSInfo si_emlrtRSI = { 267, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

emlrtRSInfo aj_emlrtRSI = { 36, "chckxy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

emlrtRSInfo bj_emlrtRSI = { 38, "chckxy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

emlrtRSInfo cj_emlrtRSI = { 44, "pwchcore",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m" };

emlrtRSInfo dj_emlrtRSI = { 90, "ppval",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

emlrtRSInfo ej_emlrtRSI = { 133, "ppval",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

emlrtRSInfo fj_emlrtRSI = { 59, "bsearch",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\bsearch.m" };

emlrtRSInfo yj_emlrtRSI = { 32, "xdotu",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotu.m" };

emlrtRSInfo hl_emlrtRSI = { 55, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

emlrtMCInfo emlrtMCI = { 20, 5, "error",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtRTEInfo f_emlrtRTEI = { 253, 13, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo h_emlrtRTEI = { 36, 6, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo yb_emlrtRTEI = { 24, 10, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

emlrtRTEInfo ec_emlrtRTEI = { 38, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRTEInfo fc_emlrtRTEI = { 39, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRTEInfo gc_emlrtRTEI = { 40, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRTEInfo wd_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRTEInfo ce_emlrtRTEI = { 19, 15, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo de_emlrtRTEI = { 39, 9, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo ee_emlrtRTEI = { 404, 15, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtDCInfo f_emlrtDCI = { 284, 28, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m", 4 };

emlrtRTEInfo ge_emlrtRTEI = { 39, 19, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo he_emlrtRTEI = { 42, 19, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo qe_emlrtRTEI = { 81, 19, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo re_emlrtRTEI = { 38, 19, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo ue_emlrtRTEI = { 53, 23, "assertValidSizeArg",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m" };

emlrtRTEInfo ve_emlrtRTEI = { 59, 15, "assertValidSizeArg",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m" };

emlrtBCInfo id_emlrtBCI = { -1, -1, 35, 14, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

emlrtBCInfo jd_emlrtBCI = { -1, -1, 35, 25, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

emlrtECInfo fb_emlrtECI = { -1, 38, 17, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

emlrtBCInfo kd_emlrtBCI = { -1, -1, 41, 13, "m", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

emlrtRTEInfo bf_emlrtRTEI = { 99, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtBCInfo ld_emlrtBCI = { -1, -1, 46, 22, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo od_emlrtBCI = { -1, -1, 97, 6, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo pd_emlrtBCI = { -1, -1, 97, 1, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo vd_emlrtBCI = { -1, -1, 100, 14, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo wd_emlrtBCI = { -1, -1, 100, 21, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo xd_emlrtBCI = { -1, -1, 100, 4, "P", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo yd_emlrtBCI = { -1, -1, 72, 5, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo ae_emlrtBCI = { -1, -1, 75, 31, "p", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo be_emlrtBCI = { -1, -1, 64, 35, "Local", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo ce_emlrtBCI = { -1, -1, 54, 35, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo de_emlrtBCI = { -1, -1, 55, 45, "Trans", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtBCInfo ee_emlrtBCI = { -1, -1, 56, 24, "PRED", "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m", 0 };

emlrtRSInfo mm_emlrtRSI = { 20, "error",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

/* End of code generation (yaapt_data.c) */
