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

emlrtRSInfo v_emlrtRSI = { 21, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo w_emlrtRSI = { 79, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo x_emlrtRSI = { 283, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo y_emlrtRSI = { 291, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ab_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

emlrtRSInfo cb_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

emlrtRSInfo vb_emlrtRSI = { 37, "mpower",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m" };

emlrtRSInfo ac_emlrtRSI = { 44, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo bc_emlrtRSI = { 234, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo cc_emlrtRSI = { 253, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRSInfo fc_emlrtRSI = { 42, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo gc_emlrtRSI = { 101, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo hc_emlrtRSI = { 99, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo lc_emlrtRSI = { 25, "xgetrf",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

emlrtRSInfo mc_emlrtRSI = { 88, "xgetrf",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

emlrtRSInfo oc_emlrtRSI = { 18, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

emlrtRSInfo pc_emlrtRSI = { 45, "infocheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"
};

emlrtRSInfo qc_emlrtRSI = { 48, "infocheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"
};

emlrtRSInfo rc_emlrtRSI = { 241, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo sc_emlrtRSI = { 268, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo xc_emlrtRSI = { 76, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

emlrtRSInfo yc_emlrtRSI = { 68, "xtrsm",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m" };

emlrtRSInfo hd_emlrtRSI = { 12, "sqrt",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" };

emlrtRSInfo qd_emlrtRSI = { 9, "exp",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" };

emlrtRSInfo rd_emlrtRSI = { 21, "eml_mtimes_helper",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtRSInfo ce_emlrtRSI = { 54, "xaxpy",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xaxpy.m" };

emlrtRSInfo ff_emlrtRSI = { 482, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo gf_emlrtRSI = { 485, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo hf_emlrtRSI = { 511, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo if_emlrtRSI = { 514, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo jf_emlrtRSI = { 517, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo kf_emlrtRSI = { 521, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo lf_emlrtRSI = { 536, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo mf_emlrtRSI = { 540, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

emlrtRSInfo lg_emlrtRSI = { 124, "allOrAny",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRSInfo mg_emlrtRSI = { 16, "abs",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

emlrtRSInfo ng_emlrtRSI = { 67, "applyScalarFunction",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"
};

emlrtRSInfo og_emlrtRSI = { 9, "sum",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

emlrtRSInfo pg_emlrtRSI = { 58, "sumprod",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRSInfo qg_emlrtRSI = { 99, "combine_vector_elements",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo rg_emlrtRSI = { 113, "combine_vector_elements",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo sg_emlrtRSI = { 40, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

emlrtRSInfo tg_emlrtRSI = { 69, "combine_vector_elements",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

emlrtRSInfo ki_emlrtRSI = { 13, "max",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo li_emlrtRSI = { 19, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo mi_emlrtRSI = { 140, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo ni_emlrtRSI = { 375, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo oi_emlrtRSI = { 347, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo ti_emlrtRSI = { 114, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

emlrtRSInfo ui_emlrtRSI = { 117, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

emlrtRSInfo ij_emlrtRSI = { 15, "max",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

emlrtRSInfo jj_emlrtRSI = { 16, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRSInfo kj_emlrtRSI = { 26, "sort",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" };

emlrtRSInfo nj_emlrtRSI = { 70, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo oj_emlrtRSI = { 331, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo pj_emlrtRSI = { 356, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo qj_emlrtRSI = { 361, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo rj_emlrtRSI = { 441, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo sj_emlrtRSI = { 448, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo tj_emlrtRSI = { 520, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo vj_emlrtRSI = { 528, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo wj_emlrtRSI = { 535, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo ak_emlrtRSI = { 375, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo bk_emlrtRSI = { 384, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

emlrtRSInfo rk_emlrtRSI = { 49, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

emlrtRSInfo vl_emlrtRSI = { 1, "mrdivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p" };

emlrtMCInfo emlrtMCI = { 27, 5, "error",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

emlrtMCInfo b_emlrtMCI = { 37, 5, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

emlrtRTEInfo e_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRTEInfo u_emlrtRTEI = { 253, 13, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo w_emlrtRTEI = { 36, 6, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo af_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m" };

emlrtRTEInfo bf_emlrtRTEI = { 98, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtRTEInfo cf_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m" };

emlrtRTEInfo df_emlrtRTEI = { 404, 15, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRTEInfo hf_emlrtRTEI = { 13, 15, "rdivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

emlrtRTEInfo if_emlrtRTEI = { 243, 9, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

emlrtRTEInfo mf_emlrtRTEI = { 48, 9, "sumprod",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo nf_emlrtRTEI = { 20, 15, "sumprod",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

emlrtRTEInfo qf_emlrtRTEI = { 39, 19, "allOrAny",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo rf_emlrtRTEI = { 42, 19, "allOrAny",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" };

emlrtRTEInfo sf_emlrtRTEI = { 17, 15, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

emlrtRTEInfo tf_emlrtRTEI = { 21, 5, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

emlrtRTEInfo uf_emlrtRTEI = { 30, 5, "mean",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" };

emlrtRTEInfo vf_emlrtRTEI = { 121, 27, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo wf_emlrtRTEI = { 39, 27, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

emlrtRTEInfo cg_emlrtRTEI = { 53, 23, "assertValidSizeArg",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

emlrtRTEInfo dg_emlrtRTEI = { 59, 15, "assertValidSizeArg",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

emlrtRSInfo so_emlrtRSI = { 37, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

emlrtRSInfo to_emlrtRSI = { 27, "error",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\lang\\error.m" };

/* End of code generation (yaapt_data.c) */
