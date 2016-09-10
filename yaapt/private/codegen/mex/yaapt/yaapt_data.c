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
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
covrtInstance emlrtCoverageInstance;
emlrtContext emlrtContextGlobal = { true, false, 131434U, NULL, "yaapt", NULL,
  false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

emlrtRSInfo x_emlrtRSI = { 21, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo y_emlrtRSI = { 79, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ab_emlrtRSI = { 283, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo bb_emlrtRSI = { 291, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo cb_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

emlrtRSInfo eb_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

emlrtRSInfo fb_emlrtRSI = { 13, "max",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo gb_emlrtRSI = { 19, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo hb_emlrtRSI = { 140, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo ib_emlrtRSI = { 347, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo jb_emlrtRSI = { 375, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo kb_emlrtRSI = { 13, "min",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

emlrtRSInfo gc_emlrtRSI = { 49, "power",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

emlrtRSInfo kc_emlrtRSI = { 44, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo lc_emlrtRSI = { 234, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo mc_emlrtRSI = { 253, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo pc_emlrtRSI = { 42, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo qc_emlrtRSI = { 101, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo rc_emlrtRSI = { 99, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo vc_emlrtRSI = { 25, "xgetrf",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

emlrtRSInfo xc_emlrtRSI = { 88, "xgetrf",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

emlrtRSInfo yc_emlrtRSI = { 94, "xgetrf",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

emlrtRSInfo bd_emlrtRSI = { 45, "infocheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"
};

emlrtRSInfo cd_emlrtRSI = { 48, "infocheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"
};

emlrtRSInfo dd_emlrtRSI = { 241, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ed_emlrtRSI = { 268, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo jd_emlrtRSI = { 76, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo kd_emlrtRSI = { 68, "xtrsm",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m" };

emlrtRSInfo ld_emlrtRSI = { 28, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo md_emlrtRSI = { 32, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo nd_emlrtRSI = { 39, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo sd_emlrtRSI = { 12, "sqrt",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" };

emlrtRSInfo td_emlrtRSI = { 121, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo ud_emlrtRSI = { 120, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

emlrtRSInfo de_emlrtRSI = { 9, "exp",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" };

emlrtRSInfo ee_emlrtRSI = { 21, "eml_mtimes_helper",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtRSInfo oe_emlrtRSI = { 54, "xaxpy",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xaxpy.m" };

emlrtRSInfo te_emlrtRSI = { 16, "scalexpAlloc",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRSInfo rf_emlrtRSI = { 105, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo sf_emlrtRSI = { 11, "nextpow2",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\nextpow2.m" };

emlrtRSInfo tf_emlrtRSI = { 15, "applyScalarFunctionInPlace",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

emlrtRSInfo uf_emlrtRSI = { 9, "nextpow2",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+scalar\\nextpow2.m"
};

emlrtRSInfo vf_emlrtRSI = { 61, "bitshift",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\bitshift.m" };

emlrtRSInfo ag_emlrtRSI = { 482, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo bg_emlrtRSI = { 485, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo cg_emlrtRSI = { 511, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo dg_emlrtRSI = { 514, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo eg_emlrtRSI = { 517, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo fg_emlrtRSI = { 521, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo gg_emlrtRSI = { 536, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo hg_emlrtRSI = { 540, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo lh_emlrtRSI = { 124, "allOrAny",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRSInfo mh_emlrtRSI = { 16, "abs",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

emlrtRSInfo nh_emlrtRSI = { 67, "applyScalarFunction",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"
};

emlrtRSInfo oh_emlrtRSI = { 9, "sum",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

emlrtRSInfo ph_emlrtRSI = { 58, "sumprod",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRSInfo qh_emlrtRSI = { 99, "combine_vector_elements",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo rh_emlrtRSI = { 113, "combine_vector_elements",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo th_emlrtRSI = { 69, "combine_vector_elements",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo mk_emlrtRSI = { 15, "max",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo nk_emlrtRSI = { 16, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo ok_emlrtRSI = { 26, "sort",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" };

emlrtRSInfo rk_emlrtRSI = { 70, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo sk_emlrtRSI = { 331, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo tk_emlrtRSI = { 356, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo uk_emlrtRSI = { 361, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo vk_emlrtRSI = { 441, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo wk_emlrtRSI = { 448, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo xk_emlrtRSI = { 520, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo al_emlrtRSI = { 528, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo bl_emlrtRSI = { 535, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo el_emlrtRSI = { 375, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo fl_emlrtRSI = { 380, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo gl_emlrtRSI = { 384, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ll_emlrtRSI = { 149, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

emlrtRSInfo ol_emlrtRSI = { 182, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

emlrtRSInfo pl_emlrtRSI = { 189, "var",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" };

emlrtRSInfo cm_emlrtRSI = { 49, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

emlrtRSInfo wm_emlrtRSI = { 267, "interp1",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" };

emlrtRSInfo en_emlrtRSI = { 36, "chckxy",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

emlrtRSInfo fn_emlrtRSI = { 38, "chckxy",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

emlrtRSInfo gn_emlrtRSI = { 44, "pwchcore",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m"
};

emlrtRSInfo hn_emlrtRSI = { 90, "ppval",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

emlrtRSInfo in_emlrtRSI = { 133, "ppval",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" };

emlrtRSInfo jn_emlrtRSI = { 59, "bsearch",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\bsearch.m" };

emlrtRSInfo co_emlrtRSI = { 32, "xdotu",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotu.m" };

emlrtRSInfo tp_emlrtRSI = { 27, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo up_emlrtRSI = { 36, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo vp_emlrtRSI = { 44, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo wp_emlrtRSI = { 48, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo xp_emlrtRSI = { 55, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo yp_emlrtRSI = { 56, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo aq_emlrtRSI = { 90, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo bq_emlrtRSI = { 97, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo cq_emlrtRSI = { 98, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

emlrtRSInfo dq_emlrtRSI = { 23, "cat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" };

emlrtRSInfo eq_emlrtRSI = { 101, "cat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" };

emlrtMCInfo emlrtMCI = { 27, 5, "error",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtMCInfo e_emlrtMCI = { 52, 19, "flt2str",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" };

emlrtRTEInfo v_emlrtRTEI = { 253, 13, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo x_emlrtRTEI = { 36, 6, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo jf_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRTEInfo kf_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtRTEInfo lf_emlrtRTEI = { 98, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtRTEInfo mf_emlrtRTEI = { 404, 15, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtDCInfo e_emlrtDCI = { 284, 28, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m", 4 };

emlrtRTEInfo qf_emlrtRTEI = { 13, 15, "rdivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

emlrtRTEInfo rf_emlrtRTEI = { 243, 9, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo wf_emlrtRTEI = { 48, 9, "sumprod",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo xf_emlrtRTEI = { 20, 15, "sumprod",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo bg_emlrtRTEI = { 39, 19, "allOrAny",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo cg_emlrtRTEI = { 42, 19, "allOrAny",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo hg_emlrtRTEI = { 121, 27, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo ig_emlrtRTEI = { 39, 27, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo ng_emlrtRTEI = { 53, 23, "assertValidSizeArg",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

emlrtRTEInfo og_emlrtRTEI = { 59, 15, "assertValidSizeArg",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

emlrtRSInfo fq_emlrtRSI = { 27, "error",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtRSInfo iq_emlrtRSI = { 52, "flt2str",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" };

/* End of code generation (yaapt_data.c) */
