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
emlrtContext emlrtContextGlobal = { true, false, 131419U, NULL, "yaapt", NULL,
  false, { 585839548U, 4280471661U, 1452683995U, 3644522327U }, NULL };

emlrtRSInfo db_emlrtRSI = { 16, "max",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo eb_emlrtRSI = { 18, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo fb_emlrtRSI = { 97, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo gb_emlrtRSI = { 281, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo hb_emlrtRSI = { 308, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo ib_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

emlrtRSInfo lb_emlrtRSI = { 49, "power",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

emlrtRSInfo ob_emlrtRSI = { 44, "find",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo pb_emlrtRSI = { 253, "find",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo sb_emlrtRSI = { 42, "lusolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo tb_emlrtRSI = { 92, "lusolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo ub_emlrtRSI = { 90, "lusolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo xb_emlrtRSI = { 25, "xgetrf",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo yb_emlrtRSI = { 86, "xgetrf",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo ac_emlrtRSI = { 42, "infocheck",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"
};

emlrtRSInfo bc_emlrtRSI = { 45, "infocheck",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"
};

emlrtRSInfo cc_emlrtRSI = { 76, "lusolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo dc_emlrtRSI = { 68, "xtrsm",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m" };

emlrtRSInfo hc_emlrtRSI = { 54, "xaxpy",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xaxpy.m" };

emlrtRSInfo mc_emlrtRSI = { 16, "scalexpAlloc",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRSInfo bd_emlrtRSI = { 21, "colon",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo cd_emlrtRSI = { 79, "colon",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo dd_emlrtRSI = { 283, "colon",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ed_emlrtRSI = { 291, "colon",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo gd_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

emlrtRSInfo od_emlrtRSI = { 124, "allOrAny",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRSInfo pd_emlrtRSI = { 16, "abs",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

emlrtRSInfo qd_emlrtRSI = { 67, "applyScalarFunction",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"
};

emlrtRSInfo rd_emlrtRSI = { 13, "sum",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

emlrtRSInfo sd_emlrtRSI = { 46, "sumprod",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRSInfo td_emlrtRSI = { 54, "combine_vector_elements",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo ud_emlrtRSI = { 60, "combine_vector_elements",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo wd_emlrtRSI = { 36, "combine_vector_elements",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo ye_emlrtRSI = { 12, "sqrt",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" };

emlrtRSInfo pg_emlrtRSI = { 18, "max",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo qg_emlrtRSI = { 15, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo rg_emlrtRSI = { 26, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" };

emlrtRSInfo ug_emlrtRSI = { 70, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo vg_emlrtRSI = { 331, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo wg_emlrtRSI = { 356, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo xg_emlrtRSI = { 361, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo yg_emlrtRSI = { 441, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ah_emlrtRSI = { 448, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo bh_emlrtRSI = { 520, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo dh_emlrtRSI = { 528, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo eh_emlrtRSI = { 535, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo hh_emlrtRSI = { 375, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ih_emlrtRSI = { 380, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo jh_emlrtRSI = { 384, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo rh_emlrtRSI = { 40, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

emlrtRSInfo uh_emlrtRSI = { 98, "median",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

emlrtRSInfo vh_emlrtRSI = { 101, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo wh_emlrtRSI = { 292, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ai_emlrtRSI = { 34, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRSInfo bi_emlrtRSI = { 61, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRSInfo yi_emlrtRSI = { 36, "chckxy",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

emlrtRSInfo aj_emlrtRSI = { 38, "chckxy",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

emlrtRSInfo bj_emlrtRSI = { 44, "pwchcore",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m" };

emlrtRSInfo cj_emlrtRSI = { 90, "ppval",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

emlrtRSInfo dj_emlrtRSI = { 133, "ppval",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

emlrtRSInfo ej_emlrtRSI = { 59, "bsearch",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\bsearch.m" };

emlrtRSInfo xj_emlrtRSI = { 32, "xdotu",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotu.m" };

emlrtRSInfo gl_emlrtRSI = { 55, "cat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

emlrtMCInfo emlrtMCI = { 20, 5, "error",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtRTEInfo e_emlrtRTEI = { 253, 13, "find",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo g_emlrtRTEI = { 36, 6, "find",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo wb_emlrtRTEI = { 24, 10, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

emlrtRTEInfo cc_emlrtRTEI = { 38, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRTEInfo dc_emlrtRTEI = { 39, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRTEInfo ec_emlrtRTEI = { 40, 1, "path1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m" };

emlrtRTEInfo qd_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRTEInfo vd_emlrtRTEI = { 19, 15, "sumprod",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo wd_emlrtRTEI = { 39, 9, "sumprod",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo xd_emlrtRTEI = { 404, 15, "colon",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtDCInfo f_emlrtDCI = { 284, 28, "colon",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m", 4 };

emlrtRTEInfo ae_emlrtRTEI = { 39, 19, "allOrAny",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo be_emlrtRTEI = { 42, 19, "allOrAny",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo ke_emlrtRTEI = { 81, 19, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo le_emlrtRTEI = { 38, 19, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo oe_emlrtRTEI = { 53, 23, "assertValidSizeArg",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

emlrtRTEInfo pe_emlrtRTEI = { 59, 15, "assertValidSizeArg",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

emlrtBCInfo id_emlrtBCI = { -1, -1, 35, 14, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

emlrtBCInfo jd_emlrtBCI = { -1, -1, 35, 25, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

emlrtECInfo fb_emlrtECI = { -1, 38, 17, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

emlrtBCInfo kd_emlrtBCI = { -1, -1, 41, 13, "m", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

emlrtRTEInfo ue_emlrtRTEI = { 99, 1, "path1",
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

emlrtRSInfo fm_emlrtRSI = { 20, "error",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

/* End of code generation (yaapt_data.c) */
