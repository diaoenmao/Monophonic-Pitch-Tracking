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
  false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

emlrtRSInfo x_emlrtRSI = { 21, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo y_emlrtRSI = { 79, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ab_emlrtRSI = { 283, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo bb_emlrtRSI = { 291, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo cb_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

emlrtRSInfo eb_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

emlrtRSInfo fb_emlrtRSI = { 16, "max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo gb_emlrtRSI = { 18, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo hb_emlrtRSI = { 97, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo ib_emlrtRSI = { 281, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo jb_emlrtRSI = { 308, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo kb_emlrtRSI = { 16, "min",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

emlrtRSInfo gc_emlrtRSI = { 49, "power",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

emlrtRSInfo kc_emlrtRSI = { 44, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo lc_emlrtRSI = { 234, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo mc_emlrtRSI = { 253, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo pc_emlrtRSI = { 42, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo qc_emlrtRSI = { 92, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo rc_emlrtRSI = { 90, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo vc_emlrtRSI = { 25, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo xc_emlrtRSI = { 86, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo yc_emlrtRSI = { 88, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo ad_emlrtRSI = { 92, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

emlrtRSInfo cd_emlrtRSI = { 42, "infocheck",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m" };

emlrtRSInfo dd_emlrtRSI = { 45, "infocheck",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m" };

emlrtRSInfo ed_emlrtRSI = { 241, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo fd_emlrtRSI = { 268, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo kd_emlrtRSI = { 76, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo ld_emlrtRSI = { 68, "xtrsm",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m" };

emlrtRSInfo md_emlrtRSI = { 28, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo nd_emlrtRSI = { 32, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo od_emlrtRSI = { 39, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo td_emlrtRSI = { 12, "sqrt",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" };

emlrtRSInfo ud_emlrtRSI = { 121, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo vd_emlrtRSI = { 120, "qrsolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo ee_emlrtRSI = { 9, "exp",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" };

emlrtRSInfo fe_emlrtRSI = { 21, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtRSInfo pe_emlrtRSI = { 54, "xaxpy",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xaxpy.m" };

emlrtRSInfo ue_emlrtRSI = { 16, "scalexpAlloc",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRSInfo uf_emlrtRSI = { 248, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo vf_emlrtRSI = { 251, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo wf_emlrtRSI = { 281, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo xf_emlrtRSI = { 285, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo ag_emlrtRSI = { 124, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRSInfo bg_emlrtRSI = { 16, "abs",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

emlrtRSInfo cg_emlrtRSI = { 67, "applyScalarFunction",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m" };

emlrtRSInfo dg_emlrtRSI = { 13, "sum",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

emlrtRSInfo eg_emlrtRSI = { 46, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRSInfo fg_emlrtRSI = { 54, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo gg_emlrtRSI = { 60, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo ig_emlrtRSI = { 36, "combine_vector_elements",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo yi_emlrtRSI = { 18, "max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo aj_emlrtRSI = { 15, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo bj_emlrtRSI = { 26, "sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" };

emlrtRSInfo ej_emlrtRSI = { 70, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo fj_emlrtRSI = { 331, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo gj_emlrtRSI = { 356, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo hj_emlrtRSI = { 361, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ij_emlrtRSI = { 441, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo jj_emlrtRSI = { 448, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo kj_emlrtRSI = { 520, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo mj_emlrtRSI = { 528, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo nj_emlrtRSI = { 535, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo qj_emlrtRSI = { 375, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo rj_emlrtRSI = { 380, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo sj_emlrtRSI = { 384, "sortIdx",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo jk_emlrtRSI = { 49, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

emlrtRSInfo el_emlrtRSI = { 267, "interp1",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

emlrtRSInfo ll_emlrtRSI = { 36, "chckxy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

emlrtRSInfo ml_emlrtRSI = { 38, "chckxy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

emlrtRSInfo nl_emlrtRSI = { 44, "pwchcore",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m" };

emlrtRSInfo ol_emlrtRSI = { 90, "ppval",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

emlrtRSInfo pl_emlrtRSI = { 133, "ppval",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

emlrtRSInfo ql_emlrtRSI = { 59, "bsearch",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\bsearch.m" };

emlrtRSInfo jm_emlrtRSI = { 32, "xdotu",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotu.m" };

emlrtRSInfo bo_emlrtRSI = { 48, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo co_emlrtRSI = { 55, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo do_emlrtRSI = { 56, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo eo_emlrtRSI = { 90, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo fo_emlrtRSI = { 97, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo go_emlrtRSI = { 98, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtMCInfo emlrtMCI = { 20, 5, "error",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtMCInfo e_emlrtMCI = { 52, 19, "flt2str",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" };

emlrtRTEInfo u_emlrtRTEI = { 253, 13, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo w_emlrtRTEI = { 36, 6, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo xe_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRTEInfo ye_emlrtRTEI = { 404, 15, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRTEInfo af_emlrtRTEI = { 98, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtRTEInfo bf_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtDCInfo e_emlrtDCI = { 284, 28, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m", 4 };

emlrtRTEInfo gf_emlrtRTEI = { 13, 15, "rdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

emlrtRTEInfo hf_emlrtRTEI = { 243, 9, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo lf_emlrtRTEI = { 19, 15, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo mf_emlrtRTEI = { 39, 9, "sumprod",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo pf_emlrtRTEI = { 39, 19, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo qf_emlrtRTEI = { 42, 19, "allOrAny",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo wf_emlrtRTEI = { 38, 19, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo xf_emlrtRTEI = { 81, 19, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo cg_emlrtRTEI = { 53, 23, "assertValidSizeArg",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m" };

emlrtRTEInfo dg_emlrtRTEI = { 59, 15, "assertValidSizeArg",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m" };

emlrtRSInfo ho_emlrtRSI = { 20, "error",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtRSInfo ko_emlrtRSI = { 52, "flt2str",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" };

/* End of code generation (yaapt_data.c) */
