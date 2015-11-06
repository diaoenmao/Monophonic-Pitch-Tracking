/*
 * spec_trk.c
 *
 * Code generation for function 'spec_trk'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "spec_trk.h"
#include "abs.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"
#include "eml_warning.h"
#include "fft.h"
#include "sum.h"
#include "prod.h"
#include "peaks.h"
#include "mean.h"
#include "eml_int_forloop_overflow_check.h"
#include "interp1.h"
#include "all.h"
#include "std.h"
#include "Mymedfilt1.h"
#include "dynamic5.h"
#include "repmat.h"
#include "Mykaiser.h"
#include "fix.h"
#include "mod.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo vb_emlrtRSI = { 42, "eml_xaxpy",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\blas\\eml_xaxpy.m" };

static emlrtRSInfo wb_emlrtRSI = { 1, "xaxpy",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\xaxpy.p" };

static emlrtRSInfo cd_emlrtRSI = { 77, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo dd_emlrtRSI = { 81, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ed_emlrtRSI = { 82, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo fd_emlrtRSI = { 88, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo gd_emlrtRSI = { 90, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo hd_emlrtRSI = { 94, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo id_emlrtRSI = { 96, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo jd_emlrtRSI = { 141, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo kd_emlrtRSI = { 142, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ld_emlrtRSI = { 143, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo md_emlrtRSI = { 146, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo nd_emlrtRSI = { 147, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo od_emlrtRSI = { 154, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo pd_emlrtRSI = { 161, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo qd_emlrtRSI = { 177, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo rd_emlrtRSI = { 178, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo sd_emlrtRSI = { 197, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo td_emlrtRSI = { 198, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ud_emlrtRSI = { 201, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo vd_emlrtRSI = { 206, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo wd_emlrtRSI = { 209, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo xd_emlrtRSI = { 213, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo yd_emlrtRSI = { 214, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ae_emlrtRSI = { 220, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo be_emlrtRSI = { 231, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo bg_emlrtRSI = { 11, "eml_li_find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_li_find.m" };

static emlrtRSInfo cg_emlrtRSI = { 26, "eml_li_find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_li_find.m" };

static emlrtRSInfo dg_emlrtRSI = { 39, "eml_li_find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_li_find.m" };

static emlrtRSInfo fg_emlrtRSI = { 18, "min",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo gg_emlrtRSI = { 105, "eml_min_or_max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m" };

static emlrtRSInfo hg_emlrtRSI = { 108, "eml_min_or_max",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m" };

static emlrtRSInfo rg_emlrtRSI = { 33, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtMCInfo jb_emlrtMCI = { 14, 5, "eml_li_find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_li_find.m" };

static emlrtMCInfo ob_emlrtMCI = { 168, 9, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo w_emlrtRTEI = { 1, 42, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo x_emlrtRTEI = { 113, 5, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo y_emlrtRTEI = { 115, 5, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo ab_emlrtRTEI = { 68, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo bb_emlrtRTEI = { 69, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo cb_emlrtRTEI = { 77, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo db_emlrtRTEI = { 79, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo eb_emlrtRTEI = { 81, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 82, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo gb_emlrtRTEI = { 90, 14, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo hb_emlrtRTEI = { 140, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ib_emlrtRTEI = { 142, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo jb_emlrtRTEI = { 155, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo kb_emlrtRTEI = { 156, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo lb_emlrtRTEI = { 175, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo dc_emlrtRTEI = { 17, 9, "eml_li_find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_li_find.m" };

static emlrtRTEInfo qd_emlrtRTEI = { 84, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo i_emlrtDCI = { 87, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 87, 18, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo k_emlrtECI = { 2, 87, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo rd_emlrtRTEI = { 93, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtECInfo l_emlrtECI = { 2, 94, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtECInfo m_emlrtECI = { -1, 94, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 96, 23, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo n_emlrtECI = { -1, 96, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 99, 22, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 96, 44, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo o_emlrtECI = { -1, 96, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 100, 22, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo p_emlrtECI = { 2, 151, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 190, 9, "Idx_voiced", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 185, 8, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 189, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo q_emlrtECI = { -1, 201, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 204, 21, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 207, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo r_emlrtECI = { -1, 207, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 207, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo s_emlrtECI = { -1, 210, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 210, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 226, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 226, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 227, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 227, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo j_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo k_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo l_emlrtDCI = { 79, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo m_emlrtDCI = { 79, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 73, 1, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo n_emlrtDCI = { 74, 22, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo o_emlrtDCI = { 74, 22, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 141, 29, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 142, 28, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 201, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 205, 19, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 210, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 231, 1, "VUVSPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { 1, 4, 166, 17, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 166, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 166, 25, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 166, 30, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { 1, 4, 168, 17, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 168, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 168, 25, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 168, 30, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 158, 5, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { 1, 4, 158, 36, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 158, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 158, 44, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 159, 5, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo od_emlrtBCI = { 1, 4, 159, 36, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 159, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 159, 44, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 85, 9, "VUVEnergy", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 90, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo q_emlrtDCI = { 90, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 94, 31, "Magnit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 94, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 94, 13, "SHC", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo s_emlrtDCI = { 94, 13, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo eb_emlrtDCI = { 17, 37, "eml_li_find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_li_find.m", 4 };

static emlrtBCInfo dj_emlrtBCI = { -1, -1, 1, 1, "", "xaxpy",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\xaxpy.p", 0 };

static emlrtRSInfo nk_emlrtRSI = { 14, "eml_li_find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_li_find.m" };

static emlrtRSInfo yk_emlrtRSI = { 168, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

/* Function Definitions */

/*
 *
 */
void eml_li_find(const emlrtStack *sp, const emxArray_boolean_T *x,
                 emxArray_int32_T *y)
{
  int32_T k;
  boolean_T overflow;
  int32_T i;
  const mxArray *b_y;
  const mxArray *m24;
  int32_T j;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  k = 0;
  b_st.site = &dg_emlrtRSI;
  if (1 > x->size[1]) {
    overflow = false;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    c_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 1; i <= x->size[1]; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  if (k <= x->size[1]) {
  } else {
    b_y = NULL;
    m24 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&b_y, m24);
    st.site = &nk_emlrtRSI;
    f_error(&st, b_y, &jb_emlrtMCI);
  }

  emlrtNonNegativeCheckFastR2012b(k, &eb_emlrtDCI, sp);
  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = k;
  emxEnsureCapacity(sp, (emxArray__common *)y, j, (int32_T)sizeof(int32_T),
                    &dc_emlrtRTEI);
  j = 0;
  st.site = &cg_emlrtRSI;
  for (i = 1; i <= x->size[1]; i++) {
    if (x->data[i - 1]) {
      y->data[j] = i;
      j++;
    }
  }
}

/*
 *
 */
void eml_xaxpy(const emlrtStack *sp, int32_T n, real_T a, const emxArray_real_T *
               x, emxArray_real_T *y, int32_T iy0)
{
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * a_t;
  int32_T i41;
  double * yiy0_t;
  double * xix0_t;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &wb_emlrtRSI;
  n_t = (ptrdiff_t)(n);
  incx_t = (ptrdiff_t)(1);
  incy_t = (ptrdiff_t)(1);
  a_t = (double *)(&a);
  i41 = y->size[1];
  yiy0_t = (double *)(&y->data[emlrtDynamicBoundsCheckFastR2012b(iy0, 1, i41,
    &dj_emlrtBCI, &b_st) - 1]);
  i41 = x->size[1];
  emlrtDynamicBoundsCheckFastR2012b(1, 1, i41, &dj_emlrtBCI, &b_st);
  xix0_t = (double *)(&x->data[0]);
  daxpy(&n_t, a_t, xix0_t, &incx_t, yiy0_t, &incy_t);
}

/*
 * function[SPitch, VUVSPitch, pAvg, pStd]= spec_trk(Data, Fs, VUVEnergy, Prm)
 */
void spec_trk(yaaptStackData *SD, const emlrtStack *sp, emxArray_real_T *Data,
              real_T Fs, const emxArray_boolean_T *VUVEnergy, emxArray_real_T
              *SPitch, emxArray_real_T *VUVSPitch, real_T pAvg_data[], int32_T
              pAvg_size[1], real_T pStd_data[], int32_T pStd_size[1])
{
  real_T nframesize;
  real_T nframejump;
  real_T numframes;
  real_T delta;
  real_T window_length;
  emxArray_real_T *CandsPitch;
  real_T half_winlen;
  real_T max_SHC;
  real_T min_SHC;
  int32_T ix;
  real_T d0;
  int32_T cindx;
  emxArray_real_T *CandsMerit;
  emxArray_real_T *b_Data;
  int32_T ixstart;
  int32_T b_ix;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  real_T SPitch_temp_end;
  real_T apnd;
  boolean_T overflow;
  real_T ndbl;
  real_T cdiff;
  const mxArray *y;
  static const int32_T iv23[2] = { 1, 21 };

  const mxArray *m12;
  char_T cv39[21];
  int32_T i;
  static const char_T cv40[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *VMerit_minmrt;
  int32_T nm1d2;
  emxArray_real_T *winix;
  emxArray_real_T *rowix;
  emxArray_real_T *Magnit;
  emxArray_real_T *VCandsMerit;
  emxArray_real_T *VPeak_minmrt;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  int32_T itmp;
  int32_T iv24[2];
  int32_T b_winix[2];
  real_T dv12[8192];
  int32_T b_VCandsMerit[2];
  real_T tmp_data[15];
  real_T b_tmp_data[15];
  static const int32_T iv25[1] = { 4 };

  emxArray_boolean_T *Idx_voiced;
  emxArray_int32_T *iindx;
  emxArray_real_T *b_rowix;
  emxArray_real_T *c_rowix;
  emxArray_real_T *d_rowix;
  uint32_T outsz[2];
  uint32_T b_outsz;
  boolean_T c_ix;
  boolean_T exitg2;
  boolean_T b_ixstart;
  emxArray_real_T *b_VPeak_minmrt;
  emxArray_real_T *VPitch;
  emxArray_boolean_T *b_SPitch;
  emxArray_real_T b_pAvg_data;
  emxArray_boolean_T *b_SPitch_temp_end;
  emxArray_real_T c_pAvg_data;
  boolean_T exitg1;
  boolean_T guard1 = false;
  const mxArray *b_y;
  emxArray_int32_T *b_iindx;
  emxArray_real_T *c_SHC;
  const mxArray *c_y;
  static const int32_T iv26[2] = { 1, 21 };

  emxArray_real_T *c_iindx;
  emxArray_real_T *r7;
  const mxArray *d_y;
  static const int32_T iv27[2] = { 1, 36 };

  char_T cv41[36];
  static const char_T cv42[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T b_i;
  real_T dbuffer[3];
  emxArray_boolean_T *b_VUVEnergy;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
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
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  g_st.prev = &st;
  g_st.tls = st.tls;
  h_st.prev = &e_st;
  h_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* SPEC_TRK  Spectral pitch tracking for YAAPT pitch tracking */
  /*  */
  /*    [SPitch, VUVSPitch, pAvg, pStd]=spec_trk(Data, Fs, VUVEnergy, Prm)  */
  /*    computes estimates of pitch  using nonlinearly processed */
  /*    speech (typically square or absolute value) and frequency domain processing */
  /*    Search for frequencies which have energy at multiplies of that frequency */
  /*  */
  /* INPUTS: */
  /*    Data:      Nonlinearly processed signal, filtered with F1. (~50 to 1500Hz) */
  /*    Fs:        The sampling frequency. */
  /*    VUVEnergy: Voiced/ unvoiced decision, depending on nlfer */
  /*    Prm:       Parameters */
  /*  */
  /* OUTPUTS: */
  /*    SPitch:    The spectral Pitch track, with the unvoiced regions filled using interpolation. */
  /*    VUVSPitch: The spectral Pitch track, with  unvoiced regions set at zero */
  /*    pAvg:      The average of the Pitch track value. */
  /*    pStd:      The standard deviation in the track. */
  /*    Creation date:  Feb 20, 2006 */
  /*    Revision dates: Feb 22, 2006,  March 11, 2006, April 5, 2006, */
  /*                    Jun 25, 2006,  June 13, 2007 */
  /*    Programers:     Hongbing Hu, Princy, Zahorian */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*      This file is a part of the YAAPT program, designed for a fundamental  */
  /*    frequency tracking algorithm that is extermely robust for both high quality  */
  /*    and telephone speech.   */
  /*      The YAAPT program was created by the Speech Communication Laboratory of */
  /*    the state university of New York at Binghamton. The program is available  */
  /*    at http://www.ws.binghamton.edu/zahorian as free software. Further  */
  /*    information about the program could be found at "A spectral/temporal  */
  /*    method for robust fundamental frequency tracking," J.Acosut.Soc.Am. 123(6),  */
  /*    June 2008. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* -- PARAMETERS: set up all of these parameters -------------------------------- */
  /* 'spec_trk:39' nframesize = fix(Prm.frame_length*Fs/1000); */
  nframesize = 25.0 * Fs / 1000.0;
  b_fix(&nframesize);

  /* 'spec_trk:40' nframejump = fix(Prm.frame_space*Fs/1000); */
  nframejump = 10.0 * Fs / 1000.0;
  b_fix(&nframejump);

  /* 'spec_trk:41' noverlap= nframesize-nframejump; */
  /*  overlap width in sample  */
  /* 'spec_trk:42' numframes = fix((length(Data)-noverlap)/nframejump); */
  numframes = ((real_T)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /*  use larger frame size */
  /* 'spec_trk:45' nframesize = nframesize*2; */
  nframesize *= 2.0;

  /*  Max number of peak candidates found */
  /* 'spec_trk:48' maxpeaks = Prm.shc_maxpeaks; */
  /* 'spec_trk:49' nfftlength = Prm.fft_length; */
  /*  FFT length */
  /*  Resolution of spectrum */
  /* 'spec_trk:51' delta         = Fs/nfftlength; */
  delta = Fs / 8192.0;

  /*  Window width in sample */
  /* 'spec_trk:53' window_length = fix(Prm.shc_window/delta); */
  window_length = 40.0 / delta;
  b_fix(&window_length);

  /* 'spec_trk:54' if (mod(window_length,2)==0) */
  if (b_mod(window_length) == 0.0) {
    /* 'spec_trk:55' window_length = window_length + 1; */
    window_length++;
  }

  emxInit_real_T(sp, &CandsPitch, 2, &ab_emlrtRTEI, true);

  /*  Half window width */
  /* 'spec_trk:58' half_winlen   = fix(Prm.shc_window/(delta*2)); */
  half_winlen = 40.0 / (delta * 2.0);
  b_fix(&half_winlen);

  /*  Max range of SHC  */
  /* 'spec_trk:60' max_SHC   = fix((Prm.f0_max+Prm.shc_pwidth*2)/delta); */
  max_SHC = 500.0 / delta;
  b_fix(&max_SHC);

  /*  Min range of SHC  */
  /* 'spec_trk:62' min_SHC   = ceil(Prm.f0_min/delta); */
  min_SHC = muDoubleScalarCeil(60.0 / delta);

  /*  Number of harmomics considered */
  /* 'spec_trk:64' numharmonics = Prm.shc_numharms; */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'spec_trk:68' CandsPitch = zeros(maxpeaks, numframes); */
  ix = CandsPitch->size[0] * CandsPitch->size[1];
  CandsPitch->size[0] = 4;
  d0 = emlrtNonNegativeCheckFastR2012b(numframes, &k_emlrtDCI, sp);
  CandsPitch->size[1] = (int32_T)emlrtIntegerCheckFastR2012b(d0, &j_emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)CandsPitch, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  d0 = emlrtNonNegativeCheckFastR2012b(numframes, &k_emlrtDCI, sp);
  cindx = (int32_T)emlrtIntegerCheckFastR2012b(d0, &j_emlrtDCI, sp) << 2;
  for (ix = 0; ix < cindx; ix++) {
    CandsPitch->data[ix] = 0.0;
  }

  emxInit_real_T(sp, &CandsMerit, 2, &bb_emlrtRTEI, true);

  /* 'spec_trk:69' CandsMerit = ones(maxpeaks, numframes); */
  ix = CandsMerit->size[0] * CandsMerit->size[1];
  CandsMerit->size[0] = 4;
  CandsMerit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)CandsMerit, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  cindx = (int32_T)numframes << 2;
  for (ix = 0; ix < cindx; ix++) {
    CandsMerit->data[ix] = 1.0;
  }

  emxInit_real_T(sp, &b_Data, 2, &w_emlrtRTEI, true);

  /*  Zero paddinga */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  /* 'spec_trk:73' Data(end) = 0; */
  ix = Data->size[1];
  ixstart = Data->size[1];
  Data->data[emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, ix, &tc_emlrtBCI, sp)
    - 1] = 0.0;

  /* 'spec_trk:74' Data = [Data zeros(1,(numframes-1)*nframejump+nframesize-length(Data))]; */
  b_ix = Data->size[1];
  d0 = ((numframes - 1.0) * nframejump + nframesize) - (real_T)b_ix;
  d0 = emlrtNonNegativeCheckFastR2012b(d0, &o_emlrtDCI, sp);
  b_ix = (int32_T)emlrtIntegerCheckFastR2012b(d0, &n_emlrtDCI, sp);
  ix = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1] + b_ix;
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  cindx = Data->size[1];
  for (ix = 0; ix < cindx; ix++) {
    b_Data->data[b_Data->size[0] * ix] = Data->data[Data->size[0] * ix];
  }

  for (ix = 0; ix < b_ix; ix++) {
    b_Data->data[b_Data->size[0] * (ix + Data->size[1])] = 0.0;
  }

  ix = Data->size[0] * Data->size[1];
  Data->size[0] = 1;
  Data->size[1] = b_Data->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Data, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  cindx = b_Data->size[1];
  for (ix = 0; ix < cindx; ix++) {
    Data->data[Data->size[0] * ix] = b_Data->data[b_Data->size[0] * ix];
  }

  emxFree_real_T(&b_Data);
  emxInit_real_T(sp, &Kaiser_window, 2, &cb_emlrtRTEI, true);
  emxInit_real_T(sp, &SHC, 2, &db_emlrtRTEI, true);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Compute SHC for voiced frame */
  /* 'spec_trk:77' Kaiser_window = Mykaiser(nframesize); */
  st.site = &cd_emlrtRSI;
  Mykaiser(&st, nframesize, Kaiser_window);

  /*  Kaiser_window_test = kaiser(nframesize); */
  /* 'spec_trk:79' SHC = zeros(1,max_SHC); */
  ix = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  d0 = emlrtNonNegativeCheckFastR2012b(max_SHC, &m_emlrtDCI, sp);
  SHC->size[1] = (int32_T)emlrtIntegerCheckFastR2012b(d0, &l_emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)SHC, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  d0 = emlrtNonNegativeCheckFastR2012b(max_SHC, &m_emlrtDCI, sp);
  cindx = (int32_T)emlrtIntegerCheckFastR2012b(d0, &l_emlrtDCI, sp);
  for (ix = 0; ix < cindx; ix++) {
    SHC->data[ix] = 0.0;
  }

  /* 'spec_trk:81' winix = repmat([1:window_length], numharmonics+1,1); */
  st.site = &dd_emlrtRSI;
  b_st.site = &ic_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsNaN(window_length)) {
    b_ix = 0;
    SPitch_temp_end = rtNaN;
    apnd = window_length;
    overflow = false;
  } else if (window_length < 1.0) {
    b_ix = -1;
    SPitch_temp_end = 1.0;
    apnd = window_length;
    overflow = false;
  } else if (muDoubleScalarIsInf(window_length)) {
    b_ix = 0;
    SPitch_temp_end = rtNaN;
    apnd = window_length;
    overflow = !(1.0 == window_length);
  } else {
    SPitch_temp_end = 1.0;
    ndbl = muDoubleScalarFloor((window_length - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - window_length;
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * window_length) {
      ndbl++;
      apnd = window_length;
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      b_ix = (int32_T)ndbl - 1;
    } else {
      b_ix = -1;
    }
  }

  d_st.site = &kc_emlrtRSI;
  if (!overflow) {
  } else {
    y = NULL;
    m12 = emlrtCreateCharArray(2, iv23);
    for (i = 0; i < 21; i++) {
      cv39[i] = cv40[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m12, cv39);
    emlrtAssign(&y, m12);
    e_st.site = &wk_emlrtRSI;
    f_st.site = &bk_emlrtRSI;
    f_error(&e_st, b_message(&f_st, y, &h_emlrtMCI), &i_emlrtMCI);
  }

  emxInit_real_T(&d_st, &VMerit_minmrt, 2, &kb_emlrtRTEI, true);
  ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = b_ix + 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, ix, (int32_T)
                    sizeof(real_T), &m_emlrtRTEI);
  if (b_ix + 1 > 0) {
    VMerit_minmrt->data[0] = SPitch_temp_end;
    if (b_ix + 1 > 1) {
      VMerit_minmrt->data[b_ix] = apnd;
      ix = b_ix + (b_ix < 0);
      if (ix >= 0) {
        nm1d2 = (int32_T)((uint32_T)ix >> 1);
      } else {
        nm1d2 = ~(int32_T)((uint32_T)~ix >> 1);
      }

      d_st.site = &lc_emlrtRSI;
      for (i = 1; i < nm1d2; i++) {
        VMerit_minmrt->data[i] = SPitch_temp_end + (real_T)i;
        VMerit_minmrt->data[b_ix - i] = apnd - (real_T)i;
      }

      if (nm1d2 << 1 == b_ix) {
        VMerit_minmrt->data[nm1d2] = (SPitch_temp_end + apnd) / 2.0;
      } else {
        VMerit_minmrt->data[nm1d2] = SPitch_temp_end + (real_T)nm1d2;
        VMerit_minmrt->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T(&c_st, &winix, 2, &eb_emlrtRTEI, true);
  emxInit_real_T(&c_st, &rowix, 2, &fb_emlrtRTEI, true);
  st.site = &dd_emlrtRSI;
  repmat(&st, VMerit_minmrt, winix);

  /* 'spec_trk:82' rowix = repmat([1:numharmonics+1]', 1, window_length); */
  st.site = &ed_emlrtRSI;
  b_repmat(&st, window_length, rowix);

  /* 'spec_trk:84' for frame = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &qd_emlrtRTEI, sp);
  b_ix = 0;
  b_emxInit_real_T(sp, &Magnit, 1, &gb_emlrtRTEI, true);
  emxInit_real_T(sp, &VCandsMerit, 2, &ib_emlrtRTEI, true);
  emxInit_real_T(sp, &VPeak_minmrt, 2, &jb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SHC, 2, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Magnit, 2, &w_emlrtRTEI, true);
  while (b_ix <= (int32_T)numframes - 1) {
    /* 'spec_trk:85' if (VUVEnergy(frame) > 0) */
    ix = VUVEnergy->size[1];
    if ((int32_T)VUVEnergy->data[emlrtDynamicBoundsCheckFastR2012b(b_ix + 1, 1,
         ix, &rd_emlrtBCI, sp) - 1] > 0) {
      /* 'spec_trk:86' firstp = 1+(frame-1)*(nframejump); */
      SPitch_temp_end = 1.0 + ((1.0 + (real_T)b_ix) - 1.0) * nframejump;

      /* 'spec_trk:87' Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window'; */
      d0 = (SPitch_temp_end + nframesize) - 1.0;
      if (SPitch_temp_end > d0) {
        ix = 1;
        ixstart = 1;
      } else {
        ix = Data->size[1];
        ixstart = (int32_T)emlrtIntegerCheckFastR2012b(SPitch_temp_end,
          &i_emlrtDCI, sp);
        ix = emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, ix, &dc_emlrtBCI, sp);
        ixstart = Data->size[1];
        itmp = (int32_T)emlrtIntegerCheckFastR2012b(d0, &i_emlrtDCI, sp);
        ixstart = emlrtDynamicBoundsCheckFastR2012b(itmp, 1, ixstart,
          &dc_emlrtBCI, sp) + 1;
      }

      itmp = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
      VMerit_minmrt->size[0] = 1;
      VMerit_minmrt->size[1] = Kaiser_window->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)VMerit_minmrt, itmp, (int32_T)
                        sizeof(real_T), &w_emlrtRTEI);
      cindx = Kaiser_window->size[0];
      for (itmp = 0; itmp < cindx; itmp++) {
        VMerit_minmrt->data[VMerit_minmrt->size[0] * itmp] = Kaiser_window->
          data[itmp];
      }

      iv24[0] = 1;
      iv24[1] = ixstart - ix;
      for (itmp = 0; itmp < 2; itmp++) {
        b_winix[itmp] = VMerit_minmrt->size[itmp];
      }

      emlrtSizeEqCheck2DFastR2012b(iv24, b_winix, &k_emlrtECI, sp);
      itmp = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
      VPeak_minmrt->size[0] = 1;
      VPeak_minmrt->size[1] = ixstart - ix;
      emxEnsureCapacity(sp, (emxArray__common *)VPeak_minmrt, itmp, (int32_T)
                        sizeof(real_T), &w_emlrtRTEI);
      cindx = ixstart - ix;
      for (ixstart = 0; ixstart < cindx; ixstart++) {
        VPeak_minmrt->data[VPeak_minmrt->size[0] * ixstart] = Data->data[(ix +
          ixstart) - 1] * VMerit_minmrt->data[VMerit_minmrt->size[0] * ixstart];
      }

      /* 'spec_trk:88' Signal = Signal - mean(Signal); */
      st.site = &fd_emlrtRSI;
      d0 = mean(&st, VPeak_minmrt);
      ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
      VPeak_minmrt->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)VPeak_minmrt, ix, (int32_T)
                        sizeof(real_T), &w_emlrtRTEI);
      cindx = VPeak_minmrt->size[1];
      for (ix = 0; ix < cindx; ix++) {
        VPeak_minmrt->data[VPeak_minmrt->size[0] * ix] -= d0;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      /* 'spec_trk:90' Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))']; */
      st.site = &gd_emlrtRSI;
      b_fft(SD, &st, VPeak_minmrt, SD->f2.dcv0);
      b_abs(SD->f2.dcv0, dv12);
      ix = Magnit->size[0];
      d0 = emlrtNonNegativeCheckFastR2012b(half_winlen, &q_emlrtDCI, sp);
      Magnit->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(d0, &p_emlrtDCI, sp)
        + 8192;
      emxEnsureCapacity(sp, (emxArray__common *)Magnit, ix, (int32_T)sizeof
                        (real_T), &w_emlrtRTEI);
      d0 = emlrtNonNegativeCheckFastR2012b(half_winlen, &q_emlrtDCI, sp);
      cindx = (int32_T)emlrtIntegerCheckFastR2012b(d0, &p_emlrtDCI, sp);
      for (ix = 0; ix < cindx; ix++) {
        Magnit->data[ix] = 0.0;
      }

      for (ix = 0; ix < 8192; ix++) {
        d0 = emlrtNonNegativeCheckFastR2012b(half_winlen, &q_emlrtDCI, sp);
        Magnit->data[ix + (int32_T)emlrtIntegerCheckFastR2012b(d0, &p_emlrtDCI,
          sp)] = dv12[ix];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      /* 'spec_trk:93' for k=min_SHC:max_SHC */
      ix = (int32_T)(max_SHC + (1.0 - min_SHC));
      emlrtForLoopVectorCheckR2012b(min_SHC, 1.0, max_SHC, mxDOUBLE_CLASS, ix,
        &rd_emlrtRTEI, sp);
      i = 0;
      while (i <= ix - 1) {
        SPitch_temp_end = min_SHC + (real_T)i;

        /* 'spec_trk:94' SHC(k) = sum(prod(Magnit( winix + k*rowix ))); */
        ixstart = VCandsMerit->size[0] * VCandsMerit->size[1];
        VCandsMerit->size[0] = 4;
        VCandsMerit->size[1] = rowix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)VCandsMerit, ixstart, (int32_T)
                          sizeof(real_T), &w_emlrtRTEI);
        cindx = rowix->size[0] * rowix->size[1];
        for (ixstart = 0; ixstart < cindx; ixstart++) {
          VCandsMerit->data[ixstart] = SPitch_temp_end * rowix->data[ixstart];
        }

        for (ixstart = 0; ixstart < 2; ixstart++) {
          b_winix[ixstart] = winix->size[ixstart];
        }

        for (ixstart = 0; ixstart < 2; ixstart++) {
          b_VCandsMerit[ixstart] = VCandsMerit->size[ixstart];
        }

        emlrtSizeEqCheck2DFastR2012b(b_winix, b_VCandsMerit, &l_emlrtECI, sp);
        emlrtMatrixMatrixIndexCheckR2012b(*(int32_T (*)[1])Magnit->size, 1,
          *(int32_T (*)[2])winix->size, 2, &m_emlrtECI, sp);
        ixstart = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = 4;
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)b_Magnit, ixstart, (int32_T)
                          sizeof(real_T), &w_emlrtRTEI);
        cindx = winix->size[0] * winix->size[1];
        for (ixstart = 0; ixstart < cindx; ixstart++) {
          itmp = Magnit->size[0];
          d0 = winix->data[ixstart] + VCandsMerit->data[ixstart];
          nm1d2 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &r_emlrtDCI, sp);
          b_Magnit->data[ixstart] = Magnit->
            data[emlrtDynamicBoundsCheckFastR2012b(nm1d2, 1, itmp, &sd_emlrtBCI,
            sp) - 1];
        }

        st.site = &hd_emlrtRSI;
        prod(&st, b_Magnit, VMerit_minmrt);
        ixstart = SHC->size[1];
        itmp = (int32_T)emlrtIntegerCheckFastR2012b(SPitch_temp_end, &s_emlrtDCI,
          sp);
        st.site = &hd_emlrtRSI;
        SHC->data[emlrtDynamicBoundsCheckFastR2012b(itmp, 1, ixstart,
          &td_emlrtBCI, sp) - 1] = sum(&st, VMerit_minmrt);
        i++;
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
      }

      /* 'spec_trk:96' [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm); */
      ix = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_SHC, ix, (int32_T)sizeof
                        (real_T), &w_emlrtRTEI);
      cindx = SHC->size[0] * SHC->size[1];
      for (ix = 0; ix < cindx; ix++) {
        b_SHC->data[ix] = SHC->data[ix];
      }

      st.site = &id_emlrtRSI;
      peaks(&st, b_SHC, delta, b_tmp_data, b_winix, tmp_data, b_VCandsMerit);
      ix = CandsPitch->size[1];
      ixstart = b_ix + 1;
      emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, ix, &ec_emlrtBCI, sp);
      emlrtSubAssignSizeCheckR2012b(iv25, 1, b_winix, 2, &n_emlrtECI, sp);
      for (ix = 0; ix < 4; ix++) {
        CandsPitch->data[ix + CandsPitch->size[0] * b_ix] = b_tmp_data[ix];
      }

      ix = CandsMerit->size[1];
      ixstart = b_ix + 1;
      emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, ix, &gc_emlrtBCI, sp);
      emlrtSubAssignSizeCheckR2012b(iv25, 1, b_VCandsMerit, 2, &o_emlrtECI, sp);
      for (ix = 0; ix < 4; ix++) {
        CandsMerit->data[ix + CandsMerit->size[0] * b_ix] = tmp_data[ix];
      }
    } else {
      /* 'spec_trk:97' else */
      /*  if energy is low,  let frame be considered as unvoiced */
      /* 'spec_trk:99' CandsPitch(:,frame) = zeros(1,maxpeaks); */
      nm1d2 = CandsPitch->size[1];
      emlrtDynamicBoundsCheckFastR2012b(b_ix + 1, 1, nm1d2, &fc_emlrtBCI, sp);
      for (ix = 0; ix < 4; ix++) {
        CandsPitch->data[ix + CandsPitch->size[0] * b_ix] = 0.0;
      }

      /* 'spec_trk:100' CandsMerit(:,frame) = ones(1, maxpeaks); */
      nm1d2 = CandsMerit->size[1];
      emlrtDynamicBoundsCheckFastR2012b(b_ix + 1, 1, nm1d2, &hc_emlrtBCI, sp);
      for (ix = 0; ix < 4; ix++) {
        CandsMerit->data[ix + CandsMerit->size[0] * b_ix] = 1.0;
      }
    }

    b_ix++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&b_Magnit);
  emxFree_real_T(&b_SHC);
  emxFree_real_T(&Kaiser_window);

  /*  display('Running new code'); */
  /*  for frame = 1:numframes */
  /*      if (VUVEnergy(frame) > 0) */
  /*          firstp = 1+(frame-1)*(nframejump); */
  /*          Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window; */
  /*          Signal = Signal - mean(Signal); */
  /*          Magnit = abs(fft(Signal , nfftlength)); */
  /*           */
  /*          % Compute SHC (Spectral Harmonic Correlation) */
  /*          for k=min_SHC:max_SHC; */
  /*              MultHarms = ones(1, window_length); */
  /*   */
  /*              % Set each harmonics, 1=f0 2=2*f0 etc */
  /*              for n=1:numharmonics+1  % Number of harmomics considered */
  /*                  nstart = n*k-half_winlen; */
  /*                  if nstart < 0 */
  /*                      Harm =  zeros(1, window_length); */
  /*                      Harm(abs(nstart)+1:window_length)=Magnit(1:nstart+window_length); */
  /*                  else */
  /*                      Harm(1:window_length)=Magnit(nstart+1:nstart+window_length); */
  /*                  end */
  /*                  MultHarms = MultHarms .* Harm; */
  /*              end */
  /*              SHC(k) = sum(MultHarms); */
  /*          end */
  /*          [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm); */
  /*      else  */
  /*          % if energy is low,  let frame be considered as unvoiced */
  /*          CandsPitch(:,frame) = zeros(1,maxpeaks); */
  /*          CandsMerit(:,frame) = ones(1, maxpeaks); */
  /*      end */
  /*  end */
  /*  Extract the Pitch candidates of voiced frames for the future Pitch selection  */
  /* 'spec_trk:139' SPitch = CandsPitch(1,:); */
  cindx = CandsPitch->size[1];
  ix = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = cindx;
  emxEnsureCapacity(sp, (emxArray__common *)SPitch, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  for (ix = 0; ix < cindx; ix++) {
    SPitch->data[SPitch->size[0] * ix] = CandsPitch->data[CandsPitch->size[0] *
      ix];
  }

  emxInit_boolean_T(sp, &Idx_voiced, 2, &hb_emlrtRTEI, true);

  /* 'spec_trk:140' Idx_voiced = SPitch > 0; */
  ix = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Idx_voiced, ix, (int32_T)sizeof
                    (boolean_T), &w_emlrtRTEI);
  cindx = SPitch->size[0] * SPitch->size[1];
  for (ix = 0; ix < cindx; ix++) {
    Idx_voiced->data[ix] = (SPitch->data[ix] > 0.0);
  }

  b_emxInit_int32_T(sp, &iindx, 2, &w_emlrtRTEI, true);

  /* 'spec_trk:141' VCandsPitch  = CandsPitch(:,Idx_voiced); */
  st.site = &jd_emlrtRSI;
  eml_li_find(&st, Idx_voiced, iindx);
  ix = rowix->size[0] * rowix->size[1];
  rowix->size[0] = 4;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowix, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  cindx = iindx->size[1];
  for (ix = 0; ix < cindx; ix++) {
    for (ixstart = 0; ixstart < 4; ixstart++) {
      itmp = CandsPitch->size[1];
      nm1d2 = iindx->data[iindx->size[0] * ix];
      rowix->data[ixstart + rowix->size[0] * ix] = CandsPitch->data[ixstart +
        CandsPitch->size[0] * (emlrtDynamicBoundsCheckFastR2012b(nm1d2, 1, itmp,
        &uc_emlrtBCI, sp) - 1)];
    }
  }

  /* 'spec_trk:142' VCandsMerit = CandsMerit(:,Idx_voiced); */
  st.site = &kd_emlrtRSI;
  eml_li_find(&st, Idx_voiced, iindx);
  ix = VCandsMerit->size[0] * VCandsMerit->size[1];
  VCandsMerit->size[0] = 4;
  VCandsMerit->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VCandsMerit, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  cindx = iindx->size[1];
  for (ix = 0; ix < cindx; ix++) {
    for (ixstart = 0; ixstart < 4; ixstart++) {
      itmp = CandsMerit->size[1];
      nm1d2 = iindx->data[iindx->size[0] * ix];
      VCandsMerit->data[ixstart + VCandsMerit->size[0] * ix] = CandsMerit->
        data[ixstart + CandsMerit->size[0] * (emlrtDynamicBoundsCheckFastR2012b
        (nm1d2, 1, itmp, &vc_emlrtBCI, sp) - 1)];
    }
  }

  emxFree_real_T(&CandsMerit);
  emxInit_real_T(sp, &b_rowix, 2, &w_emlrtRTEI, true);

  /* 'spec_trk:143' Num_VCands = sum(Idx_voiced); */
  st.site = &ld_emlrtRSI;
  ndbl = b_sum(&st, Idx_voiced);

  /*  Average, STD of the first choice candidates */
  /* 'spec_trk:146' avg_voiced = mean(VCandsPitch(1,:)); */
  cindx = rowix->size[1];
  ix = b_rowix->size[0] * b_rowix->size[1];
  b_rowix->size[0] = 1;
  b_rowix->size[1] = cindx;
  emxEnsureCapacity(sp, (emxArray__common *)b_rowix, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  for (ix = 0; ix < cindx; ix++) {
    b_rowix->data[b_rowix->size[0] * ix] = rowix->data[rowix->size[0] * ix];
  }

  emxInit_real_T(sp, &c_rowix, 2, &w_emlrtRTEI, true);
  st.site = &md_emlrtRSI;
  apnd = mean(&st, b_rowix);

  /* 'spec_trk:147' std_voiced = std(VCandsPitch(1,:)); */
  cindx = rowix->size[1];
  ix = c_rowix->size[0] * c_rowix->size[1];
  c_rowix->size[0] = 1;
  c_rowix->size[1] = cindx;
  emxEnsureCapacity(sp, (emxArray__common *)c_rowix, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  emxFree_real_T(&b_rowix);
  for (ix = 0; ix < cindx; ix++) {
    c_rowix->data[c_rowix->size[0] * ix] = rowix->data[rowix->size[0] * ix];
  }

  emxInit_real_T(sp, &d_rowix, 2, &w_emlrtRTEI, true);
  st.site = &nd_emlrtRSI;
  cdiff = b_std(&st, c_rowix);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  /* 'spec_trk:151' delta1 = abs((VCandsPitch - 0.8*avg_voiced)).*(3-VCandsMerit); */
  ix = d_rowix->size[0] * d_rowix->size[1];
  d_rowix->size[0] = 4;
  d_rowix->size[1] = rowix->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_rowix, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  d0 = 0.8 * apnd;
  cindx = rowix->size[0] * rowix->size[1];
  emxFree_real_T(&c_rowix);
  for (ix = 0; ix < cindx; ix++) {
    d_rowix->data[ix] = rowix->data[ix] - d0;
  }

  c_abs(sp, d_rowix, winix);
  emxFree_real_T(&d_rowix);
  for (ix = 0; ix < 2; ix++) {
    b_winix[ix] = winix->size[ix];
  }

  for (ix = 0; ix < 2; ix++) {
    b_VCandsMerit[ix] = VCandsMerit->size[ix];
  }

  emlrtSizeEqCheck2DFastR2012b(b_winix, b_VCandsMerit, &p_emlrtECI, sp);
  ix = winix->size[0] * winix->size[1];
  winix->size[0] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)winix, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  b_ix = winix->size[0];
  nm1d2 = winix->size[1];
  cindx = b_ix * nm1d2;
  for (ix = 0; ix < cindx; ix++) {
    winix->data[ix] *= 3.0 - VCandsMerit->data[ix];
  }

  /*  Interpolation of the weigthed candidates */
  /* 'spec_trk:154' [VR, Idx] = min(delta1); */
  st.site = &od_emlrtRSI;
  b_st.site = &fg_emlrtRSI;
  c_st.site = &vf_emlrtRSI;
  for (ix = 0; ix < 2; ix++) {
    outsz[ix] = (uint32_T)winix->size[ix];
  }

  b_outsz = outsz[1];
  outsz[1] = outsz[1];
  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, ix, (int32_T)sizeof
                    (int32_T), &w_emlrtRTEI);
  ix = iindx->size[0] * iindx->size[1];
  iindx->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, ix, (int32_T)sizeof
                    (int32_T), &w_emlrtRTEI);
  cindx = (int32_T)b_outsz;
  for (ix = 0; ix < cindx; ix++) {
    iindx->data[ix] = 1;
  }

  b_ix = 4;
  nm1d2 = -1;
  d_st.site = &gg_emlrtRSI;
  if (1 > winix->size[1]) {
    overflow = false;
  } else {
    overflow = (winix->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (i = 1; i <= winix->size[1]; i++) {
    d_st.site = &hg_emlrtRSI;
    ixstart = b_ix - 3;
    SPitch_temp_end = winix->data[b_ix - 4];
    itmp = 1;
    cindx = 1;
    if (muDoubleScalarIsNaN(winix->data[b_ix - 4])) {
      e_st.site = &df_emlrtRSI;
      if (b_ix - 2 > b_ix) {
        c_ix = false;
      } else {
        c_ix = (b_ix > 2147483646);
      }

      if (c_ix) {
        h_st.site = &jb_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      ix = b_ix - 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= b_ix)) {
        cindx++;
        ixstart = ix;
        if (!muDoubleScalarIsNaN(winix->data[ix - 1])) {
          SPitch_temp_end = winix->data[ix - 1];
          itmp = cindx;
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < b_ix) {
      e_st.site = &cf_emlrtRSI;
      if (ixstart + 1 > b_ix) {
        b_ixstart = false;
      } else {
        b_ixstart = (b_ix > 2147483646);
      }

      if (b_ixstart) {
        h_st.site = &jb_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      while (ixstart + 1 <= b_ix) {
        cindx++;
        if (winix->data[ixstart] < SPitch_temp_end) {
          SPitch_temp_end = winix->data[ixstart];
          itmp = cindx;
        }

        ixstart++;
      }
    }

    nm1d2++;
    iindx->data[nm1d2] = itmp;
    b_ix += 4;
  }

  emxFree_real_T(&winix);
  ix = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)SHC, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  cindx = iindx->size[0] * iindx->size[1];
  for (ix = 0; ix < cindx; ix++) {
    SHC->data[ix] = iindx->data[ix];
  }

  /* 'spec_trk:155' VPeak_minmrt  = zeros(1, length(Idx)); */
  ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)VPeak_minmrt, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  b_ix = SHC->size[1];
  ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[1] = b_ix;
  emxEnsureCapacity(sp, (emxArray__common *)VPeak_minmrt, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  cindx = SHC->size[1];
  for (ix = 0; ix < cindx; ix++) {
    VPeak_minmrt->data[ix] = 0.0;
  }

  /* 'spec_trk:156' VMerit_minmrt = zeros(1, length(Idx)); */
  ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)VMerit_minmrt, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  b_ix = SHC->size[1];
  ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[1] = b_ix;
  emxEnsureCapacity(sp, (emxArray__common *)VMerit_minmrt, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  cindx = SHC->size[1];
  for (ix = 0; ix < cindx; ix++) {
    VMerit_minmrt->data[ix] = 0.0;
  }

  /* 'spec_trk:157' for n=1: length(Idx) */
  b_ix = 1;
  while (b_ix - 1 <= SHC->size[1] - 1) {
    /* 'spec_trk:158' VPeak_minmrt(n)  = VCandsPitch(Idx(n), n); */
    ix = VPeak_minmrt->size[1];
    ixstart = SHC->size[1];
    ixstart = (int32_T)SHC->data[emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
      ixstart, &ld_emlrtBCI, sp) - 1];
    itmp = rowix->size[1];
    VPeak_minmrt->data[emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, ix,
      &jd_emlrtBCI, sp) - 1] = rowix->data[(emlrtDynamicBoundsCheckFastR2012b
      (ixstart, 1, 4, &kd_emlrtBCI, sp) + rowix->size[0] *
      (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, itmp, &md_emlrtBCI, sp) - 1))
      - 1];

    /* 'spec_trk:159' VMerit_minmrt(n) = VCandsMerit(Idx(n), n); */
    ix = VMerit_minmrt->size[1];
    ixstart = SHC->size[1];
    ixstart = (int32_T)SHC->data[emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
      ixstart, &pd_emlrtBCI, sp) - 1];
    itmp = VCandsMerit->size[1];
    VMerit_minmrt->data[emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, ix,
      &nd_emlrtBCI, sp) - 1] = VCandsMerit->data
      [(emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, 4, &od_emlrtBCI, sp) +
        VCandsMerit->size[0] * (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, itmp,
          &qd_emlrtBCI, sp) - 1)) - 1];
    b_ix++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxInit_real_T(sp, &b_VPeak_minmrt, 2, &w_emlrtRTEI, true);

  /* 'spec_trk:161' VPeak_minmrt = Mymedfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  ix = b_VPeak_minmrt->size[0] * b_VPeak_minmrt->size[1];
  b_VPeak_minmrt->size[0] = 1;
  b_VPeak_minmrt->size[1] = VPeak_minmrt->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_VPeak_minmrt, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  cindx = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  for (ix = 0; ix < cindx; ix++) {
    b_VPeak_minmrt->data[ix] = VPeak_minmrt->data[ix];
  }

  st.site = &pd_emlrtRSI;
  Mymedfilt1(&st, b_VPeak_minmrt, VPeak_minmrt);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  /* 'spec_trk:165' for n=1: length(Idx) */
  b_ix = 1;
  emxFree_real_T(&b_VPeak_minmrt);
  while (b_ix - 1 <= SHC->size[1] - 1) {
    /* 'spec_trk:166' VCandsPitch(Idx(n), n) = VPeak_minmrt(n); */
    ix = SHC->size[1];
    ix = (int32_T)SHC->data[emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, ix,
      &cd_emlrtBCI, sp) - 1];
    ixstart = rowix->size[1];
    itmp = VPeak_minmrt->size[1];
    rowix->data[(emlrtDynamicBoundsCheckFastR2012b(ix, 1, 4, &bd_emlrtBCI, sp) +
                 rowix->size[0] * (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
      ixstart, &dd_emlrtBCI, sp) - 1)) - 1] = VPeak_minmrt->
      data[emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, itmp, &ed_emlrtBCI, sp) -
      1];

    /*  Assign merit for the smoothed peaks */
    /* 'spec_trk:168' VCandsMerit(Idx(n), n) = VMerit_minmrt(n); */
    ix = SHC->size[1];
    ix = (int32_T)SHC->data[emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, ix,
      &gd_emlrtBCI, sp) - 1];
    ixstart = VCandsMerit->size[1];
    itmp = VMerit_minmrt->size[1];
    VCandsMerit->data[(emlrtDynamicBoundsCheckFastR2012b(ix, 1, 4, &fd_emlrtBCI,
      sp) + VCandsMerit->size[0] * (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
      ixstart, &hd_emlrtBCI, sp) - 1)) - 1] = VMerit_minmrt->
      data[emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, itmp, &id_emlrtBCI, sp) -
      1];
    b_ix++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&VPeak_minmrt);
  emxInit_real_T(sp, &VPitch, 2, &lb_emlrtRTEI, true);

  /*  Use dynamic programming to find best overal path among pitch candidates */
  /*  Dynamic weight for transition costs */
  /*  balance between local and transition costs */
  /* 'spec_trk:174' weight_trans = Prm.dp5_k1*std_voiced/avg_voiced; */
  /* 'spec_trk:175' VPitch = []; */
  ix = VPitch->size[0] * VPitch->size[1];
  VPitch->size[0] = 0;
  VPitch->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)VPitch, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);

  /* 'spec_trk:176' if (Num_VCands >2) */
  if (ndbl > 2.0) {
    /* 'spec_trk:177' [VPitch] = dynamic5(VCandsPitch, VCandsMerit,weight_trans); */
    st.site = &qd_emlrtRSI;
    dynamic5(&st, rowix, VCandsMerit, 11.0 * cdiff / apnd, VMerit_minmrt);
    ix = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)VPitch, ix, (int32_T)sizeof(real_T),
                      &w_emlrtRTEI);
    cindx = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (ix = 0; ix < cindx; ix++) {
      VPitch->data[ix] = VMerit_minmrt->data[ix];
    }

    /* 'spec_trk:178' VPitch = Mymedfilt1(VPitch, max(Prm.median_value-2, 1)); */
    st.site = &rd_emlrtRSI;
    b_Mymedfilt1(&st, VPitch, VMerit_minmrt);
    ix = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)VPitch, ix, (int32_T)sizeof(real_T),
                      &w_emlrtRTEI);
    cindx = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (ix = 0; ix < cindx; ix++) {
      VPitch->data[ix] = VMerit_minmrt->data[ix];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else {
    /* 'spec_trk:181' else */
    /* 'spec_trk:183' if (Num_VCands > 0) */
    if (ndbl > 0.0) {
      /* 'spec_trk:184' for i = 1:Num_VCands */
      i = 0;
      while (i <= (int32_T)ndbl - 1) {
        /*  assume at least 1 voiced candidate */
        /* 'spec_trk:185' VPitch (i) = 150; */
        ix = 1 + i;
        emlrtDynamicBoundsCheckFastR2012b(ix, 1, 0, &jc_emlrtBCI, sp);
        VPitch->data[0] = 150.0;

        /*    Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates */
        i++;
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
      }

      /*    This should only occur for very short pitch tracks, and even then rarely */
    } else {
      /* 'spec_trk:188' else */
      /* 'spec_trk:189' VPitch(1) = 150; */
      emlrtDynamicBoundsCheckFastR2012b(1, 1, 0, &kc_emlrtBCI, sp);
      VPitch->data[0] = 150.0;

      /*  to handle when no real voiced candidates */
      /* 'spec_trk:190' Idx_voiced(1) = 1; */
      ix = Idx_voiced->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, ix, &ic_emlrtBCI, sp);
      Idx_voiced->data[0] = true;
    }
  }

  emxFree_real_T(&VCandsMerit);
  emxFree_real_T(&rowix);

  /*  Computing some statistics from the voiced frames */
  /* 'spec_trk:197' pAvg = mean(VPitch,2); */
  st.site = &sd_emlrtRSI;
  b_mean(&st, VPitch, pAvg_data, pAvg_size);

  /* 'spec_trk:198' pStd = std(VPitch,0,2); */
  st.site = &td_emlrtRSI;
  c_std(&st, VPitch, pStd_data, pStd_size);

  /*  Streching out the smoothed pitch track */
  /* 'spec_trk:201' SPitch(Idx_voiced) = VPitch; */
  st.site = &ud_emlrtRSI;
  eml_li_find(&st, Idx_voiced, iindx);
  ix = iindx->size[1];
  ixstart = VPitch->size[0] * VPitch->size[1];
  emlrtSizeEqCheck1DFastR2012b(ix, ixstart, &q_emlrtECI, sp);
  ix = CandsPitch->size[1];
  cindx = iindx->size[0] * iindx->size[1];
  emxFree_boolean_T(&Idx_voiced);
  emxFree_real_T(&CandsPitch);
  for (ixstart = 0; ixstart < cindx; ixstart++) {
    itmp = iindx->data[ixstart];
    SPitch->data[emlrtDynamicBoundsCheckFastR2012b(itmp, 1, ix, &wc_emlrtBCI, sp)
      - 1] = VPitch->data[ixstart];
  }

  emxFree_real_T(&VPitch);
  b_emxInit_boolean_T(sp, &b_SPitch, 1, &w_emlrtRTEI, true);

  /*  Interpolating thru unvoiced frames */
  /* 'spec_trk:204' SPitch_temp_first = SPitch(1); */
  ix = SPitch->size[1];
  emlrtDynamicBoundsCheckFastR2012b(1, 1, ix, &lc_emlrtBCI, sp);

  /* 'spec_trk:205' SPitch_temp_end = SPitch(end); */
  ix = SPitch->size[1];
  ixstart = SPitch->size[1];
  SPitch_temp_end = SPitch->data[emlrtDynamicBoundsCheckFastR2012b(ixstart, 1,
    ix, &xc_emlrtBCI, sp) - 1];

  /* 'spec_trk:206' if all(SPitch_temp_first < (pAvg/2)) */
  b_pAvg_data.data = (real_T *)pAvg_data;
  b_pAvg_data.size = (int32_T *)pAvg_size;
  b_pAvg_data.allocatedSize = -1;
  b_pAvg_data.numDimensions = 1;
  b_pAvg_data.canFreeData = false;
  c_rdivide(sp, &b_pAvg_data, 2.0, Magnit);
  ndbl = SPitch->data[0];
  ix = b_SPitch->size[0];
  b_SPitch->size[0] = Magnit->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, ix, (int32_T)sizeof
                    (boolean_T), &w_emlrtRTEI);
  cindx = Magnit->size[0];
  for (ix = 0; ix < cindx; ix++) {
    b_SPitch->data[ix] = (ndbl < Magnit->data[ix]);
  }

  st.site = &vd_emlrtRSI;
  if (all(&st, b_SPitch)) {
    /* 'spec_trk:207' SPitch(1)   = pAvg; */
    ix = pAvg_size[0];
    emlrtSizeEqCheck1DFastR2012b(1, ix, &r_emlrtECI, sp);
    ix = SPitch->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, ix, &mc_emlrtBCI, sp);
    ix = pAvg_size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, ix, &nc_emlrtBCI, sp);
    SPitch->data[0] = pAvg_data[0];
  }

  emxFree_boolean_T(&b_SPitch);
  b_emxInit_boolean_T(sp, &b_SPitch_temp_end, 1, &w_emlrtRTEI, true);

  /* 'spec_trk:209' if all(SPitch_temp_end < (pAvg/2)) */
  c_pAvg_data.data = (real_T *)pAvg_data;
  c_pAvg_data.size = (int32_T *)pAvg_size;
  c_pAvg_data.allocatedSize = -1;
  c_pAvg_data.numDimensions = 1;
  c_pAvg_data.canFreeData = false;
  c_rdivide(sp, &c_pAvg_data, 2.0, Magnit);
  ix = b_SPitch_temp_end->size[0];
  b_SPitch_temp_end->size[0] = Magnit->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch_temp_end, ix, (int32_T)
                    sizeof(boolean_T), &w_emlrtRTEI);
  cindx = Magnit->size[0];
  for (ix = 0; ix < cindx; ix++) {
    b_SPitch_temp_end->data[ix] = (SPitch_temp_end < Magnit->data[ix]);
  }

  emxFree_real_T(&Magnit);
  st.site = &wd_emlrtRSI;
  if (all(&st, b_SPitch_temp_end)) {
    /* 'spec_trk:210' SPitch(end) = pAvg; */
    ix = pAvg_size[0];
    emlrtSizeEqCheck1DFastR2012b(1, ix, &s_emlrtECI, sp);
    ix = pAvg_size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, ix, &oc_emlrtBCI, sp);
    ix = SPitch->size[1];
    ixstart = SPitch->size[1];
    SPitch->data[emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, ix, &yc_emlrtBCI,
      sp) - 1] = pAvg_data[0];
  }

  emxFree_boolean_T(&b_SPitch_temp_end);

  /* 'spec_trk:213' [Indrows, Indcols, Vals] = find(SPitch); */
  st.site = &xd_emlrtRSI;
  b_st.site = &rg_emlrtRSI;
  nm1d2 = 0;
  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = SPitch->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)iindx, ix, (int32_T)sizeof
                    (int32_T), &x_emlrtRTEI);
  b_ix = SPitch->size[1];
  ix = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = b_ix;
  emxEnsureCapacity(&b_st, (emxArray__common *)SHC, ix, (int32_T)sizeof(real_T),
                    &y_emlrtRTEI);
  if (SPitch->size[1] == 0) {
    ix = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)iindx, ix, (int32_T)sizeof
                      (int32_T), &w_emlrtRTEI);
    ix = SHC->size[0] * SHC->size[1];
    SHC->size[0] = 1;
    SHC->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)SHC, ix, (int32_T)sizeof(real_T),
                      &w_emlrtRTEI);
  } else {
    b_ix = 1;
    exitg1 = false;
    while ((!exitg1) && (b_ix <= SPitch->size[1])) {
      guard1 = false;
      if (SPitch->data[SPitch->size[0] * (b_ix - 1)] != 0.0) {
        nm1d2++;
        iindx->data[nm1d2 - 1] = b_ix;
        SHC->data[nm1d2 - 1] = SPitch->data[SPitch->size[0] * (b_ix - 1)];
        if (nm1d2 >= SPitch->size[1]) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        b_ix++;
      }
    }

    if (nm1d2 <= SPitch->size[1]) {
    } else {
      b_y = NULL;
      m12 = emlrtCreateString("Assertion failed.");
      emlrtAssign(&b_y, m12);
      c_st.site = &yk_emlrtRSI;
      f_error(&c_st, b_y, &ob_emlrtMCI);
    }

    if (SPitch->size[1] == 1) {
      if (nm1d2 == 0) {
        ix = iindx->size[0] * iindx->size[1];
        iindx->size[0] = 1;
        iindx->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)iindx, ix, (int32_T)sizeof
                          (int32_T), &w_emlrtRTEI);
        ix = SHC->size[0] * SHC->size[1];
        SHC->size[0] = 1;
        SHC->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)SHC, ix, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
      }
    } else {
      if (1 > nm1d2) {
        cindx = 0;
      } else {
        cindx = nm1d2;
      }

      b_emxInit_int32_T(&b_st, &b_iindx, 2, &w_emlrtRTEI, true);
      ix = b_iindx->size[0] * b_iindx->size[1];
      b_iindx->size[0] = 1;
      b_iindx->size[1] = cindx;
      emxEnsureCapacity(&b_st, (emxArray__common *)b_iindx, ix, (int32_T)sizeof
                        (int32_T), &w_emlrtRTEI);
      for (ix = 0; ix < cindx; ix++) {
        b_iindx->data[b_iindx->size[0] * ix] = iindx->data[ix];
      }

      ix = iindx->size[0] * iindx->size[1];
      iindx->size[0] = 1;
      iindx->size[1] = b_iindx->size[1];
      emxEnsureCapacity(&b_st, (emxArray__common *)iindx, ix, (int32_T)sizeof
                        (int32_T), &w_emlrtRTEI);
      cindx = b_iindx->size[1];
      for (ix = 0; ix < cindx; ix++) {
        iindx->data[iindx->size[0] * ix] = b_iindx->data[b_iindx->size[0] * ix];
      }

      emxFree_int32_T(&b_iindx);
      if (1 > nm1d2) {
        cindx = 0;
      } else {
        cindx = nm1d2;
      }

      emxInit_real_T(&b_st, &c_SHC, 2, &w_emlrtRTEI, true);
      ix = c_SHC->size[0] * c_SHC->size[1];
      c_SHC->size[0] = 1;
      c_SHC->size[1] = cindx;
      emxEnsureCapacity(&b_st, (emxArray__common *)c_SHC, ix, (int32_T)sizeof
                        (real_T), &w_emlrtRTEI);
      for (ix = 0; ix < cindx; ix++) {
        c_SHC->data[c_SHC->size[0] * ix] = SHC->data[ix];
      }

      ix = SHC->size[0] * SHC->size[1];
      SHC->size[0] = 1;
      SHC->size[1] = c_SHC->size[1];
      emxEnsureCapacity(&b_st, (emxArray__common *)SHC, ix, (int32_T)sizeof
                        (real_T), &w_emlrtRTEI);
      cindx = c_SHC->size[1];
      for (ix = 0; ix < cindx; ix++) {
        SHC->data[SHC->size[0] * ix] = c_SHC->data[c_SHC->size[0] * ix];
      }

      emxFree_real_T(&c_SHC);
    }
  }

  /* 'spec_trk:214' SPitch = interp1(Indcols, Vals, [1:numframes], 'pchip'); */
  st.site = &yd_emlrtRSI;
  b_st.site = &ic_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  if (numframes < 1.0) {
    b_ix = -1;
    SPitch_temp_end = 1.0;
    apnd = 0.0;
    overflow = false;
  } else if (muDoubleScalarIsInf(numframes)) {
    b_ix = 0;
    SPitch_temp_end = rtNaN;
    apnd = numframes;
    overflow = !(1.0 == numframes);
  } else {
    SPitch_temp_end = 1.0;
    ndbl = muDoubleScalarFloor((numframes - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - numframes;
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * numframes) {
      ndbl++;
      apnd = numframes;
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    b_ix = (int32_T)ndbl - 1;
  }

  d_st.site = &kc_emlrtRSI;
  if (!overflow) {
  } else {
    c_y = NULL;
    m12 = emlrtCreateCharArray(2, iv26);
    for (i = 0; i < 21; i++) {
      cv39[i] = cv40[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m12, cv39);
    emlrtAssign(&c_y, m12);
    e_st.site = &wk_emlrtRSI;
    f_st.site = &bk_emlrtRSI;
    f_error(&e_st, b_message(&f_st, c_y, &h_emlrtMCI), &i_emlrtMCI);
  }

  ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = b_ix + 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, ix, (int32_T)
                    sizeof(real_T), &m_emlrtRTEI);
  if (b_ix + 1 > 0) {
    VMerit_minmrt->data[0] = SPitch_temp_end;
    if (b_ix + 1 > 1) {
      VMerit_minmrt->data[b_ix] = apnd;
      ix = b_ix + (b_ix < 0);
      if (ix >= 0) {
        nm1d2 = (int32_T)((uint32_T)ix >> 1);
      } else {
        nm1d2 = ~(int32_T)((uint32_T)~ix >> 1);
      }

      d_st.site = &lc_emlrtRSI;
      for (i = 1; i < nm1d2; i++) {
        VMerit_minmrt->data[i] = SPitch_temp_end + (real_T)i;
        VMerit_minmrt->data[b_ix - i] = apnd - (real_T)i;
      }

      if (nm1d2 << 1 == b_ix) {
        VMerit_minmrt->data[nm1d2] = (SPitch_temp_end + apnd) / 2.0;
      } else {
        VMerit_minmrt->data[nm1d2] = SPitch_temp_end + (real_T)nm1d2;
        VMerit_minmrt->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T(&c_st, &c_iindx, 2, &w_emlrtRTEI, true);
  ix = c_iindx->size[0] * c_iindx->size[1];
  c_iindx->size[0] = 1;
  c_iindx->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_iindx, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  cindx = iindx->size[0] * iindx->size[1];
  for (ix = 0; ix < cindx; ix++) {
    c_iindx->data[ix] = iindx->data[ix];
  }

  emxInit_real_T(sp, &r7, 2, &w_emlrtRTEI, true);
  st.site = &yd_emlrtRSI;
  interp1(&st, c_iindx, SHC, VMerit_minmrt, r7);
  ix = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = r7->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SPitch, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  cindx = r7->size[0] * r7->size[1];
  emxFree_real_T(&c_iindx);
  emxFree_real_T(&VMerit_minmrt);
  for (ix = 0; ix < cindx; ix++) {
    SPitch->data[ix] = r7->data[ix];
  }

  emxFree_real_T(&r7);

  /* 'spec_trk:216' FILTER_ORDER = 3; */
  /* 'spec_trk:217' flt_b = (ones(1,FILTER_ORDER))/FILTER_ORDER ; */
  /* 'spec_trk:218' flt_a = 1; */
  /* 'spec_trk:220' SPitch = filter(flt_b, flt_a, SPitch); */
  st.site = &ae_emlrtRSI;
  ix = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = SPitch->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)SHC, ix, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  cindx = SPitch->size[0] * SPitch->size[1];
  for (ix = 0; ix < cindx; ix++) {
    SHC->data[ix] = SPitch->data[ix];
  }

  if ((SPitch->size[1] == 1) || (SPitch->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    d_y = NULL;
    m12 = emlrtCreateCharArray(2, iv27);
    for (i = 0; i < 36; i++) {
      cv41[i] = cv42[i];
    }

    emlrtInitCharArrayR2013a(&st, 36, m12, cv41);
    emlrtAssign(&d_y, m12);
    b_st.site = &xk_emlrtRSI;
    g_st.site = &ck_emlrtRSI;
    f_error(&b_st, b_message(&g_st, d_y, &f_emlrtMCI), &g_emlrtMCI);
  }

  for (ix = 0; ix < 2; ix++) {
    outsz[ix] = (uint32_T)SPitch->size[ix];
  }

  ix = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity(&st, (emxArray__common *)SPitch, ix, (int32_T)sizeof(real_T),
                    &f_emlrtRTEI);
  if (SHC->size[1] >= 6) {
    ix = SPitch->size[0] * SPitch->size[1];
    SPitch->size[0] = 1;
    emxEnsureCapacity(&st, (emxArray__common *)SPitch, ix, (int32_T)sizeof
                      (real_T), &w_emlrtRTEI);
    ix = SPitch->size[0] * SPitch->size[1];
    SPitch->size[1] = (int32_T)outsz[1];
    emxEnsureCapacity(&st, (emxArray__common *)SPitch, ix, (int32_T)sizeof
                      (real_T), &w_emlrtRTEI);
    cindx = (int32_T)outsz[1];
    for (ix = 0; ix < cindx; ix++) {
      SPitch->data[ix] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      nm1d2 = SHC->size[1] - i;
      if (nm1d2 < 23) {
        nm1d2 = (i + SHC->size[1]) - i;
        b_st.site = &ub_emlrtRSI;
        if (i + 1 > nm1d2) {
          b_i = false;
        } else {
          b_i = (nm1d2 > 2147483646);
        }

        if (b_i) {
          c_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (b_ix = i; b_ix + 1 <= nm1d2; b_ix++) {
          SPitch->data[b_ix] += 0.33333333333333331 * SHC->data[b_ix - i];
        }
      } else {
        b_st.site = &tb_emlrtRSI;
        eml_xaxpy(&b_st, nm1d2, 0.33333333333333331, SHC, SPitch, i + 1);
      }
    }
  } else {
    for (i = 0; i < 2; i++) {
      dbuffer[i + 1] = 0.0;
    }

    b_st.site = &sb_emlrtRSI;
    for (b_ix = 0; b_ix + 1 <= SHC->size[1]; b_ix++) {
      for (i = 0; i < 2; i++) {
        dbuffer[i] = dbuffer[i + 1];
      }

      dbuffer[2] = 0.0;
      for (i = 0; i < 3; i++) {
        SPitch_temp_end = dbuffer[i] + SHC->data[b_ix] * 0.33333333333333331;
        dbuffer[i] = SPitch_temp_end;
      }

      SPitch->data[b_ix] = dbuffer[0];
    }
  }

  emxFree_real_T(&SHC);

  /*   above messes up  first few values of SPitch  ---  simple fix up */
  /*   Note--   this fix up should be based on above filter order */
  /* 'spec_trk:226' SPitch(1) = SPitch(3); */
  ix = SPitch->size[1];
  emlrtDynamicBoundsCheckFastR2012b(1, 1, ix, &qc_emlrtBCI, sp);
  ix = SPitch->size[1];
  emlrtDynamicBoundsCheckFastR2012b(3, 1, ix, &pc_emlrtBCI, sp);
  SPitch->data[0] = SPitch->data[2];

  /* 'spec_trk:227' SPitch(2) = SPitch (4); */
  ix = SPitch->size[1];
  emlrtDynamicBoundsCheckFastR2012b(2, 1, ix, &sc_emlrtBCI, sp);
  ix = SPitch->size[1];
  emlrtDynamicBoundsCheckFastR2012b(4, 1, ix, &rc_emlrtBCI, sp);
  SPitch->data[1] = SPitch->data[3];

  /*  Create pitch track with Voiced/Unvoiced decision */
  /* 'spec_trk:230' VUVSPitch = SPitch; */
  ix = VUVSPitch->size[0] * VUVSPitch->size[1];
  VUVSPitch->size[0] = 1;
  VUVSPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVSPitch, ix, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  cindx = SPitch->size[0] * SPitch->size[1];
  for (ix = 0; ix < cindx; ix++) {
    VUVSPitch->data[ix] = SPitch->data[ix];
  }

  emxInit_boolean_T(sp, &b_VUVEnergy, 2, &w_emlrtRTEI, true);

  /* 'spec_trk:231' VUVSPitch(VUVEnergy==0) = 0; */
  ix = b_VUVEnergy->size[0] * b_VUVEnergy->size[1];
  b_VUVEnergy->size[0] = 1;
  b_VUVEnergy->size[1] = VUVEnergy->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_VUVEnergy, ix, (int32_T)sizeof
                    (boolean_T), &w_emlrtRTEI);
  cindx = VUVEnergy->size[0] * VUVEnergy->size[1];
  for (ix = 0; ix < cindx; ix++) {
    b_VUVEnergy->data[ix] = (VUVEnergy->data[ix] == 0);
  }

  st.site = &be_emlrtRSI;
  eml_li_find(&st, b_VUVEnergy, iindx);
  cindx = iindx->size[0] * iindx->size[1];
  emxFree_boolean_T(&b_VUVEnergy);
  for (ix = 0; ix < cindx; ix++) {
    ixstart = SPitch->size[1];
    itmp = iindx->data[ix];
    VUVSPitch->data[emlrtDynamicBoundsCheckFastR2012b(itmp, 1, ixstart,
      &ad_emlrtBCI, sp) - 1] = 0.0;
  }

  emxFree_int32_T(&iindx);

  /*  SPitch = SPitch - delta; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (spec_trk.c) */
