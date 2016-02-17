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
#include "median.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"
#include "sum.h"
#include "prod.h"
#include "indexShapeCheck.h"
#include "peaks.h"
#include "abs.h"
#include "fft.h"
#include "mean.h"
#include "eml_int_forloop_overflow_check.h"
#include "filter.h"
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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo jg_emlrtRSI = { 80, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo kg_emlrtRSI = { 84, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo lg_emlrtRSI = { 85, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo mg_emlrtRSI = { 91, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ng_emlrtRSI = { 93, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo og_emlrtRSI = { 97, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo pg_emlrtRSI = { 99, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo qg_emlrtRSI = { 146, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo rg_emlrtRSI = { 149, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo sg_emlrtRSI = { 150, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo tg_emlrtRSI = { 154, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ug_emlrtRSI = { 157, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo vg_emlrtRSI = { 164, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo wg_emlrtRSI = { 180, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo xg_emlrtRSI = { 181, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo yg_emlrtRSI = { 201, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ah_emlrtRSI = { 202, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo bh_emlrtRSI = { 210, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ch_emlrtRSI = { 213, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo dh_emlrtRSI = { 217, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo eh_emlrtRSI = { 218, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo fh_emlrtRSI = { 224, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo xj_emlrtRSI = { 18, "min",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo yj_emlrtRSI = { 160, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo ak_emlrtRSI = { 163, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo rk_emlrtRSI = { 36, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo rb_emlrtRTEI = { 1, 42, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo sb_emlrtRTEI = { 187, 13, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo tb_emlrtRTEI = { 188, 13, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo ub_emlrtRTEI = { 68, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo vb_emlrtRTEI = { 69, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo wb_emlrtRTEI = { 80, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo xb_emlrtRTEI = { 82, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo yb_emlrtRTEI = { 84, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ac_emlrtRTEI = { 85, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo bc_emlrtRTEI = { 90, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo cc_emlrtRTEI = { 93, 14, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo dc_emlrtRTEI = { 143, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ec_emlrtRTEI = { 159, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo v_emlrtDCI = { 68, 20, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo w_emlrtDCI = { 68, 20, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo x_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo y_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo ab_emlrtDCI = { 69, 19, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo bb_emlrtDCI = { 69, 19, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo cb_emlrtDCI = { 82, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo db_emlrtDCI = { 82, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtRTEInfo uf_emlrtRTEI = { 87, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo eb_emlrtDCI = { 90, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 90, 18, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo o_emlrtECI = { 2, 90, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo vf_emlrtRTEI = { 96, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtECInfo p_emlrtECI = { 2, 97, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo fb_emlrtDCI = { 102, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo gb_emlrtDCI = { 102, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 99, 23, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo q_emlrtECI = { -1, 99, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 102, 22, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo r_emlrtECI = { -1, 102, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 142, 21, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 99, 44, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo s_emlrtECI = { -1, 99, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 103, 22, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo t_emlrtECI = { -1, 103, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 149, 31, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 150, 30, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo u_emlrtECI = { 2, 154, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 161, 36, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 161, 44, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 162, 36, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 162, 44, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 194, 9, "Idx_voiced", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 190, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo hb_emlrtDCI = { 190, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 193, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo v_emlrtECI = { -1, 205, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 208, 21, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 211, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo w_emlrtECI = { -1, 211, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 211, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo x_emlrtECI = { -1, 214, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 214, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 230, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 230, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 231, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 231, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtRTEInfo yf_emlrtRTEI = { 172, 9, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 73, 1, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 144, 29, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 145, 28, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 209, 19, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 214, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 235, 1, "VUVSPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 205, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 169, 30, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 169, 17, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 169, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 169, 25, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 171, 30, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 171, 17, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 171, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 171, 25, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 161, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 161, 5, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 162, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 162, 5, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 88, 9, "VUVEnergy", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo ib_emlrtDCI = { 93, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo jb_emlrtDCI = { 93, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 97, 31, "Magnit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo kb_emlrtDCI = { 97, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 97, 13, "SHC", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo lb_emlrtDCI = { 97, 13, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

/* Function Definitions */

/*
 * function[SPitch, VUVSPitch, pAvg, pStd]= spec_trk(Data, Fs, VUVEnergy, Prm)
 */
void spec_trk(const emlrtStack *sp, emxArray_real_T *Data, real_T Fs, const
              emxArray_boolean_T *VUVEnergy, const struct_T *Prm,
              emxArray_real_T *SPitch, emxArray_real_T *VUVSPitch,
              emxArray_real_T *pAvg, emxArray_real_T *pStd)
{
  real_T nframesize;
  real_T nframejump;
  real_T numframes;
  real_T maxpeaks;
  real_T delta;
  real_T window_length;
  emxArray_real_T *CandsPitch;
  real_T half_winlen;
  real_T max_SHC;
  real_T min_SHC;
  int32_T cindx;
  real_T ndbl;
  real_T anew;
  int32_T ixstop;
  emxArray_real_T *CandsMerit;
  int32_T itmp;
  real_T zero_padded;
  int32_T nm1d2;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  int32_T n;
  real_T apnd;
  boolean_T overflow;
  real_T cdiff;
  emxArray_real_T *VMerit_minmrt;
  int32_T iy;
  emxArray_real_T *winix;
  real_T absb;
  emxArray_real_T *Signal;
  emxArray_real_T *b_Signal;
  emxArray_real_T *rowix;
  int32_T frame;
  emxArray_real_T *Magnit;
  emxArray_int32_T *r21;
  emxArray_real_T *r22;
  emxArray_creal_T *r23;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  emxArray_real_T *r24;
  emxArray_real_T *r25;
  emxArray_real_T *b_Kaiser_window;
  real_T firstp;
  int32_T ixstart;
  int32_T iv28[2];
  int32_T c_Kaiser_window[2];
  real_T k;
  int32_T b_winix[2];
  int32_T iv29[2];
  int32_T iv30[1];
  int32_T iv31[1];
  int32_T iv32[1];
  int32_T iv33[2];
  int32_T iv34[1];
  int32_T iv35[2];
  emxArray_boolean_T *Idx_voiced;
  emxArray_int32_T *iindx;
  int32_T i;
  emxArray_boolean_T *b_SPitch;
  real_T Num_VCands;
  emxArray_real_T *b_CandsPitch;
  emxArray_int32_T *b_iindx;
  emxArray_real_T *c_CandsPitch;
  real_T avg_voiced;
  emxArray_real_T *d_CandsPitch;
  emxArray_int32_T *c_iindx;
  emxArray_real_T *e_CandsPitch;
  real_T std_voiced;
  emxArray_real_T *f_CandsPitch;
  int32_T iv36[2];
  emxArray_real_T *b_CandsMerit;
  int32_T c_CandsMerit[2];
  uint32_T outsz[2];
  boolean_T b_nm1d2;
  int32_T ix;
  boolean_T exitg2;
  boolean_T b_ixstart;
  emxArray_int32_T *d_iindx;
  emxArray_int32_T *e_iindx;
  emxArray_real_T *c_SHC;
  emxArray_boolean_T *c_SPitch;
  real_T SPitch_temp_end;
  emxArray_boolean_T *b_SPitch_temp_end;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *f_iindx;
  emxArray_real_T *d_SPitch;
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
  nframesize = Prm->frame_length * Fs / 1000.0;
  b_fix(&nframesize);

  /* 'spec_trk:40' nframejump = fix(Prm.frame_space*Fs/1000); */
  nframejump = Prm->frame_space * Fs / 1000.0;
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
  maxpeaks = Prm->shc_maxpeaks;

  /* 'spec_trk:49' nfftlength = Prm.fft_length; */
  /*  FFT length */
  /*  Resolution of spectrum */
  /* 'spec_trk:51' delta         = Fs/nfftlength; */
  delta = Fs / Prm->fft_length;

  /*  Window width in sample */
  /* 'spec_trk:53' window_length = fix(Prm.shc_window/delta); */
  window_length = Prm->shc_window / delta;
  b_fix(&window_length);

  /* 'spec_trk:54' if (mod(window_length,2)==0) */
  if (b_mod(window_length, 2.0) == 0.0) {
    /* 'spec_trk:55' window_length = window_length + 1; */
    window_length++;
  }

  emxInit_real_T(sp, &CandsPitch, 2, &ub_emlrtRTEI, true);

  /*  Half window width */
  /* 'spec_trk:58' half_winlen   = fix(Prm.shc_window/(delta*2)); */
  half_winlen = Prm->shc_window / (delta * 2.0);
  b_fix(&half_winlen);

  /*  Max range of SHC  */
  /* 'spec_trk:60' max_SHC   = fix((Prm.f0_max+Prm.shc_pwidth*2)/delta); */
  max_SHC = (Prm->f0_max + Prm->shc_pwidth * 2.0) / delta;
  b_fix(&max_SHC);

  /*  Min range of SHC  */
  /* 'spec_trk:62' min_SHC   = ceil(Prm.f0_min/delta); */
  min_SHC = muDoubleScalarCeil(Prm->f0_min / delta);

  /*  Number of harmomics considered */
  /* 'spec_trk:64' numharmonics = Prm.shc_numharms; */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'spec_trk:68' CandsPitch = zeros(maxpeaks, numframes); */
  cindx = CandsPitch->size[0] * CandsPitch->size[1];
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl > 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &v_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &w_emlrtDCI, sp);
  }

  CandsPitch->size[0] = (int32_T)ndbl;
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &x_emlrtDCI, sp);
  }

  if (numframes != (int32_T)muDoubleScalarFloor(numframes)) {
    emlrtIntegerCheckR2012b(numframes, &y_emlrtDCI, sp);
  }

  CandsPitch->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)CandsPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl > 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &v_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &w_emlrtDCI, sp);
  }

  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &x_emlrtDCI, sp);
  }

  anew = numframes;
  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &y_emlrtDCI, sp);
  }

  ixstop = (int32_T)ndbl * (int32_T)anew;
  for (cindx = 0; cindx < ixstop; cindx++) {
    CandsPitch->data[cindx] = 0.0;
  }

  emxInit_real_T(sp, &CandsMerit, 2, &vb_emlrtRTEI, true);

  /* 'spec_trk:69' CandsMerit = ones(maxpeaks, numframes); */
  cindx = CandsMerit->size[0] * CandsMerit->size[1];
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl > 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &ab_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &bb_emlrtDCI, sp);
  }

  CandsMerit->size[0] = (int32_T)ndbl;
  CandsMerit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)CandsMerit, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl > 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &ab_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &bb_emlrtDCI, sp);
  }

  ixstop = (int32_T)ndbl * (int32_T)numframes;
  for (cindx = 0; cindx < ixstop; cindx++) {
    CandsMerit->data[cindx] = 1.0;
  }

  /*  Zero paddinga */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  /* 'spec_trk:73' Data(end) = 0; */
  cindx = Data->size[1];
  itmp = Data->size[1];
  if (!((itmp >= 1) && (itmp <= cindx))) {
    emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &md_emlrtBCI, sp);
  }

  Data->data[itmp - 1] = 0.0;

  /* 'spec_trk:74' zero_padded = (numframes-1)*nframejump+nframesize-length(Data); */
  zero_padded = ((numframes - 1.0) * nframejump + nframesize) - (real_T)
    Data->size[1];

  /* 'spec_trk:75' if(zero_padded >0) */
  if (zero_padded > 0.0) {
    /* 'spec_trk:76' Data = [Data zero_padded]; */
    nm1d2 = Data->size[1];
    cindx = Data->size[0] * Data->size[1];
    Data->size[1] = nm1d2 + 1;
    emxEnsureCapacity(sp, (emxArray__common *)Data, cindx, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    Data->data[nm1d2] = zero_padded;
  }

  emxInit_real_T(sp, &Kaiser_window, 2, &wb_emlrtRTEI, true);
  emxInit_real_T(sp, &SHC, 2, &xb_emlrtRTEI, true);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Compute SHC for voiced frame */
  /* 'spec_trk:80' Kaiser_window = Mykaiser(nframesize); */
  st.site = &jg_emlrtRSI;
  Mykaiser(&st, nframesize, Kaiser_window);

  /*  Kaiser_window_test = kaiser(nframesize); */
  /* 'spec_trk:82' SHC = zeros(1,max_SHC); */
  cindx = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  if (!(max_SHC > 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &cb_emlrtDCI, sp);
  }

  if (max_SHC != (int32_T)muDoubleScalarFloor(max_SHC)) {
    emlrtIntegerCheckR2012b(max_SHC, &db_emlrtDCI, sp);
  }

  SHC->size[1] = (int32_T)max_SHC;
  emxEnsureCapacity(sp, (emxArray__common *)SHC, cindx, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  if (!(max_SHC > 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &cb_emlrtDCI, sp);
  }

  ndbl = max_SHC;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &db_emlrtDCI, sp);
  }

  ixstop = (int32_T)ndbl;
  for (cindx = 0; cindx < ixstop; cindx++) {
    SHC->data[cindx] = 0.0;
  }

  /* 'spec_trk:84' winix = repmat([1:window_length], numharmonics+1,1); */
  st.site = &kg_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if (muDoubleScalarIsNaN(window_length)) {
    n = 1;
    anew = rtNaN;
    apnd = window_length;
    overflow = false;
  } else if (window_length < 1.0) {
    n = 0;
    anew = 1.0;
    apnd = window_length;
    overflow = false;
  } else if (muDoubleScalarIsInf(window_length)) {
    n = 1;
    anew = rtNaN;
    apnd = window_length;
    overflow = !(1.0 == window_length);
  } else {
    anew = 1.0;
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
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }
  }

  d_st.site = &ab_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &ye_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &VMerit_minmrt, 2, &ec_emlrtRTEI, true);
  cindx = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  if (!(n > 0)) {
    emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
  }

  VMerit_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, cindx, (int32_T)
                    sizeof(real_T), &rb_emlrtRTEI);
  if (n > 0) {
    VMerit_minmrt->data[0] = anew;
    if (n > 1) {
      VMerit_minmrt->data[n - 1] = apnd;
      cindx = n - 1;
      nm1d2 = asr_s32(cindx, 1U);
      d_st.site = &bb_emlrtRSI;
      for (iy = 1; iy < nm1d2; iy++) {
        VMerit_minmrt->data[iy] = anew + (real_T)iy;
        VMerit_minmrt->data[(n - iy) - 1] = apnd - (real_T)iy;
      }

      if (nm1d2 << 1 == n - 1) {
        VMerit_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VMerit_minmrt->data[nm1d2] = anew + (real_T)nm1d2;
        VMerit_minmrt->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T(&c_st, &winix, 2, &yb_emlrtRTEI, true);
  st.site = &kg_emlrtRSI;
  repmat(&st, VMerit_minmrt, Prm->shc_numharms + 1.0, winix);

  /* 'spec_trk:85' rowix = repmat([1:numharmonics+1]', 1, window_length); */
  st.site = &lg_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if (muDoubleScalarIsNaN(Prm->shc_numharms + 1.0)) {
    n = 1;
    anew = rtNaN;
    apnd = Prm->shc_numharms + 1.0;
    overflow = false;
  } else if (Prm->shc_numharms + 1.0 < 1.0) {
    n = 0;
    anew = 1.0;
    apnd = Prm->shc_numharms + 1.0;
    overflow = false;
  } else if (muDoubleScalarIsInf(Prm->shc_numharms + 1.0)) {
    n = 1;
    anew = rtNaN;
    apnd = Prm->shc_numharms + 1.0;
    overflow = !(1.0 == Prm->shc_numharms + 1.0);
  } else {
    anew = 1.0;
    ndbl = muDoubleScalarFloor(((Prm->shc_numharms + 1.0) - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - (Prm->shc_numharms + 1.0);
    absb = muDoubleScalarAbs(Prm->shc_numharms + 1.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
        (1.0, absb)) {
      ndbl++;
      apnd = Prm->shc_numharms + 1.0;
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }
  }

  d_st.site = &ab_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &ye_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &Signal, 2, &bc_emlrtRTEI, true);
  cindx = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  if (!(n > 0)) {
    emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
  }

  Signal->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)Signal, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  if (n > 0) {
    Signal->data[0] = anew;
    if (n > 1) {
      Signal->data[n - 1] = apnd;
      cindx = n - 1;
      nm1d2 = asr_s32(cindx, 1U);
      d_st.site = &bb_emlrtRSI;
      for (iy = 1; iy < nm1d2; iy++) {
        Signal->data[iy] = anew + (real_T)iy;
        Signal->data[(n - iy) - 1] = apnd - (real_T)iy;
      }

      if (nm1d2 << 1 == n - 1) {
        Signal->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        Signal->data[nm1d2] = anew + (real_T)nm1d2;
        Signal->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T1(&c_st, &b_Signal, 1, &rb_emlrtRTEI, true);
  cindx = b_Signal->size[0];
  b_Signal->size[0] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Signal, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  ixstop = Signal->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    b_Signal->data[cindx] = Signal->data[Signal->size[0] * cindx];
  }

  emxInit_real_T(sp, &rowix, 2, &ac_emlrtRTEI, true);
  st.site = &lg_emlrtRSI;
  b_repmat(&st, b_Signal, window_length, rowix);

  /* 'spec_trk:87' for frame = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &uf_emlrtRTEI, sp);
  frame = 0;
  emxFree_real_T(&b_Signal);
  emxInit_real_T1(sp, &Magnit, 1, &cc_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r21, 1, &rb_emlrtRTEI, true);
  emxInit_real_T(sp, &r22, 2, &rb_emlrtRTEI, true);
  emxInit_creal_T(sp, &r23, 2, &rb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SHC, 2, &rb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Magnit, 2, &rb_emlrtRTEI, true);
  emxInit_real_T(sp, &r24, 2, &rb_emlrtRTEI, true);
  emxInit_real_T(sp, &r25, 2, &rb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Kaiser_window, 2, &rb_emlrtRTEI, true);
  while (frame <= (int32_T)numframes - 1) {
    /* 'spec_trk:88' if (VUVEnergy(frame) > 0) */
    cindx = VUVEnergy->size[1];
    if (!((frame + 1 >= 1) && (frame + 1 <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(frame + 1, 1, cindx, &ge_emlrtBCI, sp);
    }

    if ((int32_T)VUVEnergy->data[frame] > 0) {
      /* 'spec_trk:89' firstp = 1+(frame-1)*(nframejump); */
      firstp = 1.0 + ((1.0 + (real_T)frame) - 1.0) * nframejump;

      /* 'spec_trk:90' Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window'; */
      ndbl = (firstp + nframesize) - 1.0;
      if (firstp > ndbl) {
        itmp = 1;
        cindx = 1;
      } else {
        if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
          emlrtIntegerCheckR2012b(firstp, &eb_emlrtDCI, sp);
        }

        cindx = Data->size[1];
        itmp = (int32_T)firstp;
        if (!((itmp >= 1) && (itmp <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &oc_emlrtBCI, sp);
        }

        if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
          emlrtIntegerCheckR2012b(ndbl, &eb_emlrtDCI, sp);
        }

        cindx = Data->size[1];
        ixstart = (int32_T)ndbl;
        if (!((ixstart >= 1) && (ixstart <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, cindx, &oc_emlrtBCI, sp);
        }

        cindx = ixstart + 1;
      }

      iv28[0] = 1;
      iv28[1] = cindx - itmp;
      ixstart = b_Kaiser_window->size[0] * b_Kaiser_window->size[1];
      b_Kaiser_window->size[0] = Kaiser_window->size[1];
      b_Kaiser_window->size[1] = Kaiser_window->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_Kaiser_window, ixstart,
                        (int32_T)sizeof(real_T), &rb_emlrtRTEI);
      ixstop = Kaiser_window->size[0];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        iy = Kaiser_window->size[1];
        for (nm1d2 = 0; nm1d2 < iy; nm1d2++) {
          b_Kaiser_window->data[nm1d2 + b_Kaiser_window->size[0] * ixstart] =
            Kaiser_window->data[ixstart + Kaiser_window->size[0] * nm1d2];
        }
      }

      for (ixstart = 0; ixstart < 2; ixstart++) {
        c_Kaiser_window[ixstart] = b_Kaiser_window->size[ixstart];
      }

      if ((iv28[0] != c_Kaiser_window[0]) || (iv28[1] != c_Kaiser_window[1])) {
        emlrtSizeEqCheckNDR2012b(&iv28[0], &c_Kaiser_window[0], &o_emlrtECI, sp);
      }

      ixstart = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      Signal->size[1] = cindx - itmp;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, ixstart, (int32_T)sizeof
                        (real_T), &rb_emlrtRTEI);
      ixstop = cindx - itmp;
      for (cindx = 0; cindx < ixstop; cindx++) {
        Signal->data[Signal->size[0] * cindx] = Data->data[(itmp + cindx) - 1] *
          Kaiser_window->data[cindx];
      }

      /* 'spec_trk:91' Signal = Signal - mean(Signal); */
      st.site = &mg_emlrtRSI;
      ndbl = mean(&st, Signal);
      cindx = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, cindx, (int32_T)sizeof
                        (real_T), &rb_emlrtRTEI);
      ixstop = Signal->size[1];
      for (cindx = 0; cindx < ixstop; cindx++) {
        Signal->data[Signal->size[0] * cindx] -= ndbl;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      /* 'spec_trk:93' Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))']; */
      st.site = &ng_emlrtRSI;
      b_fft(&st, Signal, Prm->fft_length, r23);
      st.site = &ng_emlrtRSI;
      b_abs(&st, r23, VMerit_minmrt);
      if (!(half_winlen > 0.0)) {
        emlrtNonNegativeCheckR2012b(half_winlen, &jb_emlrtDCI, sp);
      }

      ndbl = half_winlen;
      if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
        emlrtIntegerCheckR2012b(ndbl, &ib_emlrtDCI, sp);
      }

      cindx = Magnit->size[0];
      Magnit->size[0] = (int32_T)half_winlen + VMerit_minmrt->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)Magnit, cindx, (int32_T)sizeof
                        (real_T), &rb_emlrtRTEI);
      ixstop = (int32_T)half_winlen;
      for (cindx = 0; cindx < ixstop; cindx++) {
        Magnit->data[cindx] = 0.0;
      }

      ixstop = VMerit_minmrt->size[1];
      for (cindx = 0; cindx < ixstop; cindx++) {
        Magnit->data[cindx + (int32_T)half_winlen] = VMerit_minmrt->
          data[VMerit_minmrt->size[0] * cindx];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      /* 'spec_trk:96' for k=min_SHC:max_SHC */
      cindx = (int32_T)(max_SHC + (1.0 - min_SHC));
      emlrtForLoopVectorCheckR2012b(min_SHC, 1.0, max_SHC, mxDOUBLE_CLASS, cindx,
        &vf_emlrtRTEI, sp);
      iy = 0;
      while (iy <= cindx - 1) {
        k = min_SHC + (real_T)iy;

        /* 'spec_trk:97' SHC(k) = sum(prod(Magnit( winix + k*rowix ))); */
        itmp = r22->size[0] * r22->size[1];
        r22->size[0] = rowix->size[0];
        r22->size[1] = rowix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)r22, itmp, (int32_T)sizeof
                          (real_T), &rb_emlrtRTEI);
        ixstop = rowix->size[0] * rowix->size[1];
        for (itmp = 0; itmp < ixstop; itmp++) {
          r22->data[itmp] = k * rowix->data[itmp];
        }

        for (itmp = 0; itmp < 2; itmp++) {
          b_winix[itmp] = winix->size[itmp];
        }

        for (itmp = 0; itmp < 2; itmp++) {
          iv29[itmp] = r22->size[itmp];
        }

        if ((b_winix[0] != iv29[0]) || (b_winix[1] != iv29[1])) {
          emlrtSizeEqCheckNDR2012b(&b_winix[0], &iv29[0], &p_emlrtECI, sp);
        }

        st.site = &og_emlrtRSI;
        b_indexShapeCheck(&st, Magnit->size[0], *(int32_T (*)[2])winix->size);
        itmp = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = winix->size[0];
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)b_Magnit, itmp, (int32_T)
                          sizeof(real_T), &rb_emlrtRTEI);
        nm1d2 = Magnit->size[0];
        ixstop = winix->size[0] * winix->size[1];
        for (itmp = 0; itmp < ixstop; itmp++) {
          ndbl = winix->data[itmp] + r22->data[itmp];
          if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
            emlrtIntegerCheckR2012b(ndbl, &kb_emlrtDCI, sp);
          }

          ixstart = (int32_T)ndbl;
          if (!((ixstart >= 1) && (ixstart <= nm1d2))) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, nm1d2, &he_emlrtBCI, sp);
          }

          b_Magnit->data[itmp] = Magnit->data[ixstart - 1];
        }

        st.site = &og_emlrtRSI;
        prod(&st, b_Magnit, VMerit_minmrt);
        itmp = SHC->size[1];
        if (k != (int32_T)k) {
          emlrtIntegerCheckR2012b(k, &lb_emlrtDCI, sp);
        }

        ixstart = (int32_T)k;
        if (!((ixstart >= 1) && (ixstart <= itmp))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, itmp, &ie_emlrtBCI, sp);
        }

        st.site = &og_emlrtRSI;
        SHC->data[ixstart - 1] = sum(&st, VMerit_minmrt);
        iy++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* 'spec_trk:99' [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm); */
      cindx = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_SHC, cindx, (int32_T)sizeof
                        (real_T), &rb_emlrtRTEI);
      ixstop = SHC->size[0] * SHC->size[1];
      for (cindx = 0; cindx < ixstop; cindx++) {
        b_SHC->data[cindx] = SHC->data[cindx];
      }

      st.site = &pg_emlrtRSI;
      peaks(&st, b_SHC, delta, maxpeaks, Prm->f0_min, Prm->f0_max,
            Prm->shc_pwidth, Prm->shc_thresh1, Prm->shc_thresh2, Prm->f0_double,
            Prm->f0_half, Prm->merit_extra, VMerit_minmrt, Signal);
      ixstop = CandsPitch->size[0];
      cindx = r21->size[0];
      r21->size[0] = ixstop;
      emxEnsureCapacity(sp, (emxArray__common *)r21, cindx, (int32_T)sizeof
                        (int32_T), &rb_emlrtRTEI);
      for (cindx = 0; cindx < ixstop; cindx++) {
        r21->data[cindx] = cindx;
      }

      cindx = CandsPitch->size[1];
      itmp = frame + 1;
      if (!((itmp >= 1) && (itmp <= cindx))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &pc_emlrtBCI, sp);
      }

      iv30[0] = r21->size[0];
      emlrtSubAssignSizeCheckR2012b(iv30, 1, *(int32_T (*)[2])
        VMerit_minmrt->size, 2, &q_emlrtECI, sp);
      nm1d2 = r21->size[0];
      for (cindx = 0; cindx < nm1d2; cindx++) {
        CandsPitch->data[r21->data[cindx] + CandsPitch->size[0] * frame] =
          VMerit_minmrt->data[cindx];
      }

      ixstop = CandsMerit->size[0];
      cindx = r21->size[0];
      r21->size[0] = ixstop;
      emxEnsureCapacity(sp, (emxArray__common *)r21, cindx, (int32_T)sizeof
                        (int32_T), &rb_emlrtRTEI);
      for (cindx = 0; cindx < ixstop; cindx++) {
        r21->data[cindx] = cindx;
      }

      cindx = CandsMerit->size[1];
      itmp = frame + 1;
      if (!((itmp >= 1) && (itmp <= cindx))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &sc_emlrtBCI, sp);
      }

      iv31[0] = r21->size[0];
      emlrtSubAssignSizeCheckR2012b(iv31, 1, *(int32_T (*)[2])Signal->size, 2,
        &s_emlrtECI, sp);
      nm1d2 = r21->size[0];
      for (cindx = 0; cindx < nm1d2; cindx++) {
        CandsMerit->data[r21->data[cindx] + CandsMerit->size[0] * frame] =
          Signal->data[cindx];
      }
    } else {
      /* 'spec_trk:100' else */
      /*  if energy is low,  let frame be considered as unvoiced */
      /* 'spec_trk:102' CandsPitch(:,frame) = zeros(1,maxpeaks); */
      ixstop = CandsPitch->size[0];
      cindx = r21->size[0];
      r21->size[0] = ixstop;
      emxEnsureCapacity(sp, (emxArray__common *)r21, cindx, (int32_T)sizeof
                        (int32_T), &rb_emlrtRTEI);
      for (cindx = 0; cindx < ixstop; cindx++) {
        r21->data[cindx] = cindx;
      }

      cindx = CandsPitch->size[1];
      itmp = frame + 1;
      if (!((itmp >= 1) && (itmp <= cindx))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &qc_emlrtBCI, sp);
      }

      if (!(maxpeaks > 0.0)) {
        emlrtNonNegativeCheckR2012b(maxpeaks, &fb_emlrtDCI, sp);
      }

      if (maxpeaks != (int32_T)muDoubleScalarFloor(maxpeaks)) {
        emlrtIntegerCheckR2012b(maxpeaks, &gb_emlrtDCI, sp);
      }

      iv32[0] = r21->size[0];
      iv33[0] = 1;
      iv33[1] = (int32_T)maxpeaks;
      emlrtSubAssignSizeCheckR2012b(iv32, 1, iv33, 2, &r_emlrtECI, sp);
      cindx = r24->size[0] * r24->size[1];
      r24->size[0] = 1;
      r24->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r24, cindx, (int32_T)sizeof
                        (real_T), &rb_emlrtRTEI);
      ixstop = (int32_T)maxpeaks;
      for (cindx = 0; cindx < ixstop; cindx++) {
        r24->data[r24->size[0] * cindx] = 0.0;
      }

      nm1d2 = r21->size[0];
      for (cindx = 0; cindx < nm1d2; cindx++) {
        CandsPitch->data[r21->data[cindx] + CandsPitch->size[0] * frame] =
          r24->data[cindx];
      }

      /* 'spec_trk:103' CandsMerit(:,frame) = ones(1, maxpeaks); */
      ixstop = CandsMerit->size[0];
      cindx = r21->size[0];
      r21->size[0] = ixstop;
      emxEnsureCapacity(sp, (emxArray__common *)r21, cindx, (int32_T)sizeof
                        (int32_T), &rb_emlrtRTEI);
      for (cindx = 0; cindx < ixstop; cindx++) {
        r21->data[cindx] = cindx;
      }

      cindx = CandsMerit->size[1];
      itmp = frame + 1;
      if (!((itmp >= 1) && (itmp <= cindx))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &tc_emlrtBCI, sp);
      }

      iv34[0] = r21->size[0];
      iv35[0] = 1;
      iv35[1] = (int32_T)maxpeaks;
      emlrtSubAssignSizeCheckR2012b(iv34, 1, iv35, 2, &t_emlrtECI, sp);
      cindx = r25->size[0] * r25->size[1];
      r25->size[0] = 1;
      r25->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r25, cindx, (int32_T)sizeof
                        (real_T), &rb_emlrtRTEI);
      ixstop = (int32_T)maxpeaks;
      for (cindx = 0; cindx < ixstop; cindx++) {
        r25->data[r25->size[0] * cindx] = 1.0;
      }

      nm1d2 = r21->size[0];
      for (cindx = 0; cindx < nm1d2; cindx++) {
        CandsMerit->data[r21->data[cindx] + CandsMerit->size[0] * frame] =
          r25->data[cindx];
      }
    }

    frame++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Kaiser_window);
  emxFree_real_T(&r25);
  emxFree_real_T(&r24);
  emxFree_real_T(&b_Magnit);
  emxFree_real_T(&b_SHC);
  emxFree_creal_T(&r23);
  emxFree_int32_T(&r21);

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
  /* 'spec_trk:142' SPitch = CandsPitch(1,:); */
  cindx = CandsPitch->size[0];
  if (!(1 <= cindx)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &rc_emlrtBCI, sp);
  }

  ixstop = CandsPitch->size[1];
  cindx = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = ixstop;
  emxEnsureCapacity(sp, (emxArray__common *)SPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  for (cindx = 0; cindx < ixstop; cindx++) {
    SPitch->data[SPitch->size[0] * cindx] = CandsPitch->data[CandsPitch->size[0]
      * cindx];
  }

  emxInit_boolean_T(sp, &Idx_voiced, 2, &dc_emlrtRTEI, true);

  /* 'spec_trk:143' Idx_voiced = SPitch > 0; */
  cindx = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Idx_voiced, cindx, (int32_T)sizeof
                    (boolean_T), &rb_emlrtRTEI);
  ixstop = SPitch->size[0] * SPitch->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    Idx_voiced->data[cindx] = (SPitch->data[cindx] > 0.0);
  }

  emxInit_int32_T(sp, &iindx, 2, &rb_emlrtRTEI, true);

  /* 'spec_trk:144' VCandsPitch  = CandsPitch(:,Idx_voiced); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  ixstop = CandsPitch->size[0];
  nm1d2 = CandsPitch->size[1];
  cindx = winix->size[0] * winix->size[1];
  winix->size[0] = ixstop;
  winix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)winix, cindx, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  iy = iindx->size[1];
  for (cindx = 0; cindx < iy; cindx++) {
    for (itmp = 0; itmp < ixstop; itmp++) {
      ixstart = iindx->data[iindx->size[0] * cindx];
      if (!((ixstart >= 1) && (ixstart <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(ixstart, 1, nm1d2, &nd_emlrtBCI, sp);
      }

      winix->data[itmp + winix->size[0] * cindx] = CandsPitch->data[itmp +
        CandsPitch->size[0] * (ixstart - 1)];
    }
  }

  /* 'spec_trk:145' VCandsMerit = CandsMerit(:,Idx_voiced); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  ixstop = CandsMerit->size[0];
  nm1d2 = CandsMerit->size[1];
  cindx = rowix->size[0] * rowix->size[1];
  rowix->size[0] = ixstop;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowix, cindx, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  iy = iindx->size[1];
  for (cindx = 0; cindx < iy; cindx++) {
    for (itmp = 0; itmp < ixstop; itmp++) {
      ixstart = iindx->data[iindx->size[0] * cindx];
      if (!((ixstart >= 1) && (ixstart <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(ixstart, 1, nm1d2, &od_emlrtBCI, sp);
      }

      rowix->data[itmp + rowix->size[0] * cindx] = CandsMerit->data[itmp +
        CandsMerit->size[0] * (ixstart - 1)];
    }
  }

  emxInit_boolean_T(sp, &b_SPitch, 2, &rb_emlrtRTEI, true);

  /* 'spec_trk:146' Num_VCands = sum(Idx_voiced); */
  cindx = b_SPitch->size[0] * b_SPitch->size[1];
  b_SPitch->size[0] = 1;
  b_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, cindx, (int32_T)sizeof
                    (boolean_T), &rb_emlrtRTEI);
  ixstop = SPitch->size[0] * SPitch->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    b_SPitch->data[cindx] = (SPitch->data[cindx] > 0.0);
  }

  st.site = &qg_emlrtRSI;
  Num_VCands = b_sum(&st, b_SPitch);

  /*  Average, STD of the first choice candidates */
  /* 'spec_trk:149' avg_voiced = mean(VCandsPitch(1,:)); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_boolean_T(&b_SPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &b_CandsPitch, 2, &rb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &b_iindx, 1, &rb_emlrtRTEI, true);
  cindx = CandsPitch->size[0];
  if (!(1 <= cindx)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &uc_emlrtBCI, sp);
  }

  ixstop = CandsPitch->size[0];
  cindx = b_iindx->size[0];
  b_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  iy = iindx->size[1];
  for (cindx = 0; cindx < iy; cindx++) {
    b_iindx->data[cindx] = iindx->data[iindx->size[0] * cindx];
  }

  emxInit_real_T(sp, &c_CandsPitch, 2, &rb_emlrtRTEI, true);
  iy = b_iindx->size[0];
  cindx = c_CandsPitch->size[0] * c_CandsPitch->size[1];
  c_CandsPitch->size[0] = ixstop;
  c_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_CandsPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&b_iindx);
  for (cindx = 0; cindx < nm1d2; cindx++) {
    for (itmp = 0; itmp < ixstop; itmp++) {
      c_CandsPitch->data[itmp + c_CandsPitch->size[0] * cindx] =
        CandsPitch->data[itmp + CandsPitch->size[0] * (iindx->data[iindx->size[0]
        * cindx] - 1)];
    }
  }

  cindx = b_CandsPitch->size[0] * b_CandsPitch->size[1];
  b_CandsPitch->size[0] = 1;
  b_CandsPitch->size[1] = iy;
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  for (cindx = 0; cindx < iy; cindx++) {
    b_CandsPitch->data[b_CandsPitch->size[0] * cindx] = c_CandsPitch->
      data[c_CandsPitch->size[0] * cindx];
  }

  emxFree_real_T(&c_CandsPitch);
  st.site = &rg_emlrtRSI;
  avg_voiced = mean(&st, b_CandsPitch);

  /* 'spec_trk:150' std_voiced = std(VCandsPitch(1,:)); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&b_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &d_CandsPitch, 2, &rb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &c_iindx, 1, &rb_emlrtRTEI, true);
  cindx = CandsPitch->size[0];
  if (!(1 <= cindx)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &vc_emlrtBCI, sp);
  }

  ixstop = CandsPitch->size[0];
  cindx = c_iindx->size[0];
  c_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  iy = iindx->size[1];
  for (cindx = 0; cindx < iy; cindx++) {
    c_iindx->data[cindx] = iindx->data[iindx->size[0] * cindx];
  }

  emxInit_real_T(sp, &e_CandsPitch, 2, &rb_emlrtRTEI, true);
  iy = c_iindx->size[0];
  cindx = e_CandsPitch->size[0] * e_CandsPitch->size[1];
  e_CandsPitch->size[0] = ixstop;
  e_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)e_CandsPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&c_iindx);
  for (cindx = 0; cindx < nm1d2; cindx++) {
    for (itmp = 0; itmp < ixstop; itmp++) {
      e_CandsPitch->data[itmp + e_CandsPitch->size[0] * cindx] =
        CandsPitch->data[itmp + CandsPitch->size[0] * (iindx->data[iindx->size[0]
        * cindx] - 1)];
    }
  }

  cindx = d_CandsPitch->size[0] * d_CandsPitch->size[1];
  d_CandsPitch->size[0] = 1;
  d_CandsPitch->size[1] = iy;
  emxEnsureCapacity(sp, (emxArray__common *)d_CandsPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  for (cindx = 0; cindx < iy; cindx++) {
    d_CandsPitch->data[d_CandsPitch->size[0] * cindx] = e_CandsPitch->
      data[e_CandsPitch->size[0] * cindx];
  }

  emxFree_real_T(&e_CandsPitch);
  st.site = &sg_emlrtRSI;
  std_voiced = b_std(&st, d_CandsPitch);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  /* 'spec_trk:154' delta1 = abs((VCandsPitch - 0.8*avg_voiced)).*(3-VCandsMerit); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&d_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &f_CandsPitch, 2, &rb_emlrtRTEI, true);
  ixstop = CandsPitch->size[0];
  ndbl = 0.8 * avg_voiced;
  cindx = f_CandsPitch->size[0] * f_CandsPitch->size[1];
  f_CandsPitch->size[0] = ixstop;
  f_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_CandsPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  iy = iindx->size[1];
  for (cindx = 0; cindx < iy; cindx++) {
    for (itmp = 0; itmp < ixstop; itmp++) {
      f_CandsPitch->data[itmp + f_CandsPitch->size[0] * cindx] =
        CandsPitch->data[itmp + CandsPitch->size[0] * (iindx->data[iindx->size[0]
        * cindx] - 1)] - ndbl;
    }
  }

  st.site = &tg_emlrtRSI;
  c_abs(&st, f_CandsPitch, r22);
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&f_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  for (cindx = 0; cindx < 2; cindx++) {
    iv36[cindx] = r22->size[cindx];
  }

  emxInit_real_T(sp, &b_CandsMerit, 2, &rb_emlrtRTEI, true);
  ixstop = CandsMerit->size[0];
  cindx = b_CandsMerit->size[0] * b_CandsMerit->size[1];
  b_CandsMerit->size[0] = ixstop;
  b_CandsMerit->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsMerit, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  iy = iindx->size[1];
  for (cindx = 0; cindx < iy; cindx++) {
    for (itmp = 0; itmp < ixstop; itmp++) {
      b_CandsMerit->data[itmp + b_CandsMerit->size[0] * cindx] =
        CandsMerit->data[itmp + CandsMerit->size[0] * (iindx->data[iindx->size[0]
        * cindx] - 1)];
    }
  }

  for (cindx = 0; cindx < 2; cindx++) {
    c_CandsMerit[cindx] = b_CandsMerit->size[cindx];
  }

  emxFree_real_T(&b_CandsMerit);
  if ((iv36[0] != c_CandsMerit[0]) || (iv36[1] != c_CandsMerit[1])) {
    emlrtSizeEqCheckNDR2012b(&iv36[0], &c_CandsMerit[0], &u_emlrtECI, sp);
  }

  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  cindx = Kaiser_window->size[0] * Kaiser_window->size[1];
  Kaiser_window->size[0] = r22->size[0];
  Kaiser_window->size[1] = r22->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, cindx, (int32_T)
                    sizeof(real_T), &rb_emlrtRTEI);
  ixstop = r22->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    iy = r22->size[0];
    for (itmp = 0; itmp < iy; itmp++) {
      Kaiser_window->data[itmp + Kaiser_window->size[0] * cindx] = r22->
        data[itmp + r22->size[0] * cindx] * (3.0 - CandsMerit->data[itmp +
        CandsMerit->size[0] * (iindx->data[iindx->size[0] * cindx] - 1)]);
    }
  }

  emxFree_real_T(&r22);

  /*  Interpolation of the weigthed candidates */
  /* 'spec_trk:157' [VR, Idx] = min(delta1); */
  st.site = &ug_emlrtRSI;
  b_st.site = &xj_emlrtRSI;
  c_st.site = &aj_emlrtRSI;
  if (((Kaiser_window->size[0] == 1) && (Kaiser_window->size[1] == 1)) ||
      (Kaiser_window->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (Kaiser_window->size[0] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &xf_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  for (cindx = 0; cindx < 2; cindx++) {
    outsz[cindx] = (uint32_T)Kaiser_window->size[cindx];
  }

  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  ixstop = (int32_T)outsz[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    iindx->data[cindx] = 1;
  }

  n = Kaiser_window->size[0];
  nm1d2 = 0;
  iy = -1;
  d_st.site = &yj_emlrtRSI;
  if (1 > Kaiser_window->size[1]) {
    overflow = false;
  } else {
    overflow = (Kaiser_window->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&e_st, true);
  }

  for (i = 1; i <= Kaiser_window->size[1]; i++) {
    d_st.site = &ak_emlrtRSI;
    ixstart = nm1d2;
    ixstop = nm1d2 + n;
    anew = Kaiser_window->data[nm1d2];
    itmp = 1;
    if (n > 1) {
      cindx = 1;
      if (muDoubleScalarIsNaN(Kaiser_window->data[nm1d2])) {
        e_st.site = &ib_emlrtRSI;
        if (nm1d2 + 2 > ixstop) {
          b_nm1d2 = false;
        } else {
          b_nm1d2 = (ixstop > 2147483646);
        }

        if (b_nm1d2) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        ix = nm1d2 + 1;
        exitg2 = false;
        while ((!exitg2) && (ix + 1 <= ixstop)) {
          cindx++;
          ixstart = ix;
          if (!muDoubleScalarIsNaN(Kaiser_window->data[ix])) {
            anew = Kaiser_window->data[ix];
            itmp = cindx;
            exitg2 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart + 1 < ixstop) {
        e_st.site = &jb_emlrtRSI;
        if (ixstart + 2 > ixstop) {
          b_ixstart = false;
        } else {
          b_ixstart = (ixstop > 2147483646);
        }

        if (b_ixstart) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        for (ix = ixstart + 1; ix + 1 <= ixstop; ix++) {
          cindx++;
          if (Kaiser_window->data[ix] < anew) {
            anew = Kaiser_window->data[ix];
            itmp = cindx;
          }
        }
      }
    }

    iy++;
    iindx->data[iy] = itmp;
    nm1d2 += n;
  }

  cindx = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  ixstop = iindx->size[0] * iindx->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    Signal->data[cindx] = iindx->data[cindx];
  }

  /* 'spec_trk:158' VPeak_minmrt  = zeros(1, length(Idx)); */
  cindx = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SHC, cindx, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  ixstop = Signal->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    SHC->data[cindx] = 0.0;
  }

  /* 'spec_trk:159' VMerit_minmrt = zeros(1, length(Idx)); */
  cindx = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VMerit_minmrt, cindx, (int32_T)
                    sizeof(real_T), &rb_emlrtRTEI);
  ixstop = Signal->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    VMerit_minmrt->data[cindx] = 0.0;
  }

  /* 'spec_trk:160' for n=1: length(Idx) */
  n = 1;
  emxInit_int32_T1(sp, &d_iindx, 1, &rb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &e_iindx, 1, &rb_emlrtRTEI, true);
  while (n - 1 <= Signal->size[1] - 1) {
    /* 'spec_trk:161' VPeak_minmrt(n)  = VCandsPitch(Idx(n), n); */
    iy = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    cindx = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                      (int32_T), &rb_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    cindx = CandsPitch->size[0];
    itmp = d_iindx->size[0];
    d_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)d_iindx, itmp, (int32_T)sizeof
                      (int32_T), &rb_emlrtRTEI);
    ixstop = iindx->size[1];
    for (itmp = 0; itmp < ixstop; itmp++) {
      d_iindx->data[itmp] = iindx->data[iindx->size[0] * itmp];
    }

    itmp = Signal->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &ce_emlrtBCI, sp);
    }

    itmp = (int32_T)Signal->data[n - 1];
    if (!((itmp >= 1) && (itmp <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &wc_emlrtBCI, sp);
    }

    cindx = d_iindx->size[0];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &xc_emlrtBCI, sp);
    }

    cindx = n;
    ixstart = SHC->size[1];
    if (!((n >= 1) && (n <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, ixstart, &de_emlrtBCI, sp);
    }

    SHC->data[n - 1] = CandsPitch->data[(itmp + CandsPitch->size[0] *
      (iindx->data[iindx->size[0] * (cindx - 1)] - 1)) - 1];

    /* 'spec_trk:162' VMerit_minmrt(n) = VCandsMerit(Idx(n), n); */
    iy = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    cindx = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                      (int32_T), &rb_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    cindx = CandsMerit->size[0];
    itmp = e_iindx->size[0];
    e_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)e_iindx, itmp, (int32_T)sizeof
                      (int32_T), &rb_emlrtRTEI);
    ixstop = iindx->size[1];
    for (itmp = 0; itmp < ixstop; itmp++) {
      e_iindx->data[itmp] = iindx->data[iindx->size[0] * itmp];
    }

    itmp = Signal->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &ee_emlrtBCI, sp);
    }

    itmp = (int32_T)Signal->data[n - 1];
    if (!((itmp >= 1) && (itmp <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &yc_emlrtBCI, sp);
    }

    cindx = e_iindx->size[0];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &ad_emlrtBCI, sp);
    }

    cindx = n;
    ixstart = VMerit_minmrt->size[1];
    if (!((n >= 1) && (n <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, ixstart, &fe_emlrtBCI, sp);
    }

    VMerit_minmrt->data[n - 1] = CandsMerit->data[(itmp + CandsMerit->size[0] *
      (iindx->data[iindx->size[0] * (cindx - 1)] - 1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&e_iindx);
  emxFree_int32_T(&d_iindx);
  emxFree_real_T(&CandsMerit);
  emxInit_real_T(sp, &c_SHC, 2, &rb_emlrtRTEI, true);

  /* 'spec_trk:164' VPeak_minmrt = Mymedfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  cindx = c_SHC->size[0] * c_SHC->size[1];
  c_SHC->size[0] = 1;
  c_SHC->size[1] = SHC->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_SHC, cindx, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  ixstop = SHC->size[0] * SHC->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    c_SHC->data[cindx] = SHC->data[cindx];
  }

  st.site = &vg_emlrtRSI;
  Mymedfilt1(&st, c_SHC, muDoubleScalarMax(1.0, Prm->median_value - 2.0), SHC);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  /* 'spec_trk:168' for n=1: length(Idx) */
  n = 1;
  emxFree_real_T(&c_SHC);
  while (n - 1 <= Signal->size[1] - 1) {
    /* 'spec_trk:169' VCandsPitch(Idx(n), n) = VPeak_minmrt(n); */
    cindx = SHC->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &td_emlrtBCI, sp);
    }

    cindx = winix->size[0];
    itmp = Signal->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &vd_emlrtBCI, sp);
    }

    itmp = (int32_T)Signal->data[n - 1];
    if (!((itmp >= 1) && (itmp <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &ud_emlrtBCI, sp);
    }

    cindx = winix->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &wd_emlrtBCI, sp);
    }

    winix->data[(itmp + winix->size[0] * (n - 1)) - 1] = SHC->data[n - 1];

    /*  Assign merit for the smoothed peaks */
    /* 'spec_trk:171' VCandsMerit(Idx(n), n) = VMerit_minmrt(n); */
    cindx = VMerit_minmrt->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &xd_emlrtBCI, sp);
    }

    cindx = rowix->size[0];
    itmp = Signal->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &ae_emlrtBCI, sp);
    }

    itmp = (int32_T)Signal->data[n - 1];
    if (!((itmp >= 1) && (itmp <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &yd_emlrtBCI, sp);
    }

    cindx = rowix->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &be_emlrtBCI, sp);
    }

    rowix->data[(itmp + rowix->size[0] * (n - 1)) - 1] = VMerit_minmrt->data[n -
      1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&SHC);

  /*  Use dynamic programming to find best overal path among pitch candidates */
  /*  Dynamic weight for transition costs */
  /*  balance between local and transition costs */
  /* 'spec_trk:177' weight_trans = Prm.dp5_k1*std_voiced/avg_voiced; */
  /* 'spec_trk:178' VPitch = []; */
  cindx = Kaiser_window->size[0] * Kaiser_window->size[1];
  Kaiser_window->size[0] = 0;
  Kaiser_window->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, cindx, (int32_T)
                    sizeof(real_T), &rb_emlrtRTEI);

  /* 'spec_trk:179' if (Num_VCands >2) */
  if (Num_VCands > 2.0) {
    /* 'spec_trk:180' [VPitch] = dynamic5(VCandsPitch, VCandsMerit,weight_trans); */
    st.site = &wg_emlrtRSI;
    dynamic5(&st, winix, rowix, Prm->dp5_k1 * std_voiced / avg_voiced,
             VMerit_minmrt);
    cindx = Kaiser_window->size[0] * Kaiser_window->size[1];
    Kaiser_window->size[0] = 1;
    Kaiser_window->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, cindx, (int32_T)
                      sizeof(real_T), &rb_emlrtRTEI);
    ixstop = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (cindx = 0; cindx < ixstop; cindx++) {
      Kaiser_window->data[cindx] = VMerit_minmrt->data[cindx];
    }

    /* 'spec_trk:181' VPitch = Mymedfilt1(VPitch, max(Prm.median_value-2, 1)); */
    st.site = &xg_emlrtRSI;
    b_Mymedfilt1(&st, Kaiser_window, muDoubleScalarMax(Prm->median_value - 2.0,
      1.0), VMerit_minmrt);
    cindx = Kaiser_window->size[0] * Kaiser_window->size[1];
    Kaiser_window->size[0] = 1;
    Kaiser_window->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, cindx, (int32_T)
                      sizeof(real_T), &rb_emlrtRTEI);
    ixstop = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (cindx = 0; cindx < ixstop; cindx++) {
      Kaiser_window->data[cindx] = VMerit_minmrt->data[cindx];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else {
    /* 'spec_trk:184' else */
    /* 'spec_trk:186' if (Num_VCands > 0) */
    if (Num_VCands > 0.0) {
      /*        for i = 1:Num_VCands   % assume at least 1 voiced candidate */
      /*         VPitch (i) = 150;   %   Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates */
      /*        end;  */
      /* 'spec_trk:190' VPitch(1:Num_VCands) = 150; */
      if (1.0 > Num_VCands) {
        ixstop = -1;
      } else {
        emlrtDynamicBoundsCheckR2012b(1, 1, 0, &cd_emlrtBCI, sp);
        if (Num_VCands != muDoubleScalarFloor(Num_VCands)) {
          emlrtIntegerCheckR2012b(Num_VCands, &hb_emlrtDCI, sp);
        }

        cindx = (int32_T)Num_VCands;
        emlrtDynamicBoundsCheckR2012b(cindx, 1, 0, &cd_emlrtBCI, sp);
        ixstop = 0;
      }

      cindx = iindx->size[0] * iindx->size[1];
      iindx->size[0] = 1;
      iindx->size[1] = ixstop + 1;
      emxEnsureCapacity(sp, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                        (int32_T), &rb_emlrtRTEI);
      for (cindx = 0; cindx <= ixstop; cindx++) {
        iindx->data[iindx->size[0] * cindx] = cindx;
      }

      ixstop = iindx->size[0] * iindx->size[1];
      for (cindx = 0; cindx < ixstop; cindx++) {
        Kaiser_window->data[iindx->data[cindx]] = 150.0;
      }

      /*    This should only occur for very short pitch tracks, and even then rarely */
    } else {
      /* 'spec_trk:192' else */
      /* 'spec_trk:193' VPitch(1) = 150; */
      emlrtDynamicBoundsCheckR2012b(1, 1, 0, &dd_emlrtBCI, sp);
      Kaiser_window->data[0] = 150.0;

      /*  to handle when no real voiced candidates */
      /* 'spec_trk:194' Idx_voiced(1) = 1; */
      cindx = CandsPitch->size[1];
      if (!(1 <= cindx)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &bd_emlrtBCI, sp);
      }

      Idx_voiced->data[0] = true;
    }
  }

  emxFree_real_T(&rowix);
  emxFree_real_T(&winix);
  emxFree_real_T(&CandsPitch);

  /*  Computing some statistics from the voiced frames */
  /* 'spec_trk:201' pAvg = mean(VPitch,2); */
  st.site = &yg_emlrtRSI;
  b_mean(&st, Kaiser_window, pAvg);

  /* 'spec_trk:202' pStd = std(VPitch,0,2); */
  st.site = &ah_emlrtRSI;
  c_std(&st, Kaiser_window, pStd);

  /*  Streching out the smoothed pitch track */
  /* 'spec_trk:205' SPitch(Idx_voiced) = VPitch; */
  iy = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < iy; i++) {
    if (Idx_voiced->data[i]) {
      nm1d2++;
    }
  }

  cindx = Kaiser_window->size[0] * Kaiser_window->size[1];
  if (nm1d2 != cindx) {
    emlrtSizeEqCheck1DR2012b(nm1d2, cindx, &v_emlrtECI, sp);
  }

  iy = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < iy; i++) {
    if (Idx_voiced->data[i]) {
      cindx = SPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= cindx))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, cindx, &sd_emlrtBCI, sp);
      }

      SPitch->data[i] = Kaiser_window->data[nm1d2];
      nm1d2++;
    }
  }

  emxFree_boolean_T(&Idx_voiced);
  emxFree_real_T(&Kaiser_window);
  emxInit_boolean_T1(sp, &c_SPitch, 1, &rb_emlrtRTEI, true);

  /*  Interpolating thru unvoiced frames */
  /* 'spec_trk:208' SPitch_temp_first = SPitch(1); */
  cindx = SPitch->size[1];
  if (!(1 <= cindx)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &ed_emlrtBCI, sp);
  }

  /* 'spec_trk:209' SPitch_temp_end = SPitch(end); */
  cindx = SPitch->size[1];
  itmp = SPitch->size[1];
  if (!((itmp >= 1) && (itmp <= cindx))) {
    emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &pd_emlrtBCI, sp);
  }

  SPitch_temp_end = SPitch->data[itmp - 1];

  /* 'spec_trk:210' if all(SPitch_temp_first < (pAvg/2)) */
  rdivide(sp, pAvg, 2.0, Magnit);
  anew = SPitch->data[0];
  cindx = c_SPitch->size[0];
  c_SPitch->size[0] = Magnit->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_SPitch, cindx, (int32_T)sizeof
                    (boolean_T), &rb_emlrtRTEI);
  ixstop = Magnit->size[0];
  for (cindx = 0; cindx < ixstop; cindx++) {
    c_SPitch->data[cindx] = (anew < Magnit->data[cindx]);
  }

  st.site = &bh_emlrtRSI;
  if (all(&st, c_SPitch)) {
    /* 'spec_trk:211' SPitch(1)   = pAvg; */
    cindx = pAvg->size[0];
    if (1 != cindx) {
      emlrtSizeEqCheck1DR2012b(1, cindx, &w_emlrtECI, sp);
    }

    cindx = SPitch->size[1];
    if (!(1 <= cindx)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &fd_emlrtBCI, sp);
    }

    cindx = pAvg->size[0];
    if (!(1 <= cindx)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &gd_emlrtBCI, sp);
    }

    SPitch->data[0] = pAvg->data[0];
  }

  emxFree_boolean_T(&c_SPitch);
  emxInit_boolean_T1(sp, &b_SPitch_temp_end, 1, &rb_emlrtRTEI, true);

  /* 'spec_trk:213' if all(SPitch_temp_end < (pAvg/2)) */
  rdivide(sp, pAvg, 2.0, Magnit);
  cindx = b_SPitch_temp_end->size[0];
  b_SPitch_temp_end->size[0] = Magnit->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch_temp_end, cindx, (int32_T)
                    sizeof(boolean_T), &rb_emlrtRTEI);
  ixstop = Magnit->size[0];
  for (cindx = 0; cindx < ixstop; cindx++) {
    b_SPitch_temp_end->data[cindx] = (SPitch_temp_end < Magnit->data[cindx]);
  }

  emxFree_real_T(&Magnit);
  st.site = &ch_emlrtRSI;
  if (all(&st, b_SPitch_temp_end)) {
    /* 'spec_trk:214' SPitch(end) = pAvg; */
    cindx = pAvg->size[0];
    if (1 != cindx) {
      emlrtSizeEqCheck1DR2012b(1, cindx, &x_emlrtECI, sp);
    }

    cindx = pAvg->size[0];
    if (!(1 <= cindx)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &hd_emlrtBCI, sp);
    }

    cindx = SPitch->size[1];
    itmp = SPitch->size[1];
    if (!((itmp >= 1) && (itmp <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &qd_emlrtBCI, sp);
    }

    SPitch->data[itmp - 1] = pAvg->data[0];
  }

  emxFree_boolean_T(&b_SPitch_temp_end);

  /* 'spec_trk:217' [Indrows, Indcols, Vals] = find(SPitch); */
  st.site = &dh_emlrtRSI;
  b_st.site = &rk_emlrtRSI;
  iy = 0;
  cindx = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = SPitch->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                    (int32_T), &rb_emlrtRTEI);
  nm1d2 = SPitch->size[1];
  cindx = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = nm1d2;
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  if (SPitch->size[1] == 0) {
    cindx = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                      (int32_T), &rb_emlrtRTEI);
    cindx = Signal->size[0] * Signal->size[1];
    Signal->size[0] = 1;
    Signal->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)Signal, cindx, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
  } else {
    nm1d2 = 1;
    exitg1 = false;
    while ((!exitg1) && (nm1d2 <= SPitch->size[1])) {
      guard1 = false;
      if (SPitch->data[SPitch->size[0] * (nm1d2 - 1)] != 0.0) {
        iy++;
        iindx->data[iy - 1] = nm1d2;
        Signal->data[iy - 1] = SPitch->data[SPitch->size[0] * (nm1d2 - 1)];
        if (iy >= SPitch->size[1]) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        nm1d2++;
      }
    }

    if (iy <= SPitch->size[1]) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &yf_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (SPitch->size[1] == 1) {
      if (iy == 0) {
        cindx = iindx->size[0] * iindx->size[1];
        iindx->size[0] = 1;
        iindx->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)iindx, cindx, (int32_T)
                          sizeof(int32_T), &rb_emlrtRTEI);
        cindx = Signal->size[0] * Signal->size[1];
        Signal->size[0] = 1;
        Signal->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)Signal, cindx, (int32_T)
                          sizeof(real_T), &rb_emlrtRTEI);
      }
    } else {
      cindx = iindx->size[0] * iindx->size[1];
      if (1 > iy) {
        iindx->size[1] = 0;
      } else {
        iindx->size[1] = iy;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)iindx, cindx, (int32_T)sizeof
                        (int32_T), &sb_emlrtRTEI);
      cindx = Signal->size[0] * Signal->size[1];
      if (1 > iy) {
        Signal->size[1] = 0;
      } else {
        Signal->size[1] = iy;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)Signal, cindx, (int32_T)
                        sizeof(real_T), &tb_emlrtRTEI);
    }
  }

  /* 'spec_trk:218' SPitch = interp1(Indcols, Vals, [1:numframes], 'pchip'); */
  st.site = &eh_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if (numframes < 1.0) {
    n = 0;
    anew = 1.0;
    apnd = 0.0;
    overflow = false;
  } else if (muDoubleScalarIsInf(numframes)) {
    n = 1;
    anew = rtNaN;
    apnd = numframes;
    overflow = !(1.0 == numframes);
  } else {
    anew = 1.0;
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
    n = (int32_T)ndbl;
  }

  d_st.site = &ab_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &ye_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  cindx = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  if (!(n > 0)) {
    emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
  }

  VMerit_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, cindx, (int32_T)
                    sizeof(real_T), &rb_emlrtRTEI);
  if (n > 0) {
    VMerit_minmrt->data[0] = anew;
    if (n > 1) {
      VMerit_minmrt->data[n - 1] = apnd;
      cindx = n - 1;
      nm1d2 = asr_s32(cindx, 1U);
      d_st.site = &bb_emlrtRSI;
      for (iy = 1; iy < nm1d2; iy++) {
        VMerit_minmrt->data[iy] = anew + (real_T)iy;
        VMerit_minmrt->data[(n - iy) - 1] = apnd - (real_T)iy;
      }

      if (nm1d2 << 1 == n - 1) {
        VMerit_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VMerit_minmrt->data[nm1d2] = anew + (real_T)nm1d2;
        VMerit_minmrt->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T(&c_st, &f_iindx, 2, &rb_emlrtRTEI, true);
  cindx = f_iindx->size[0] * f_iindx->size[1];
  f_iindx->size[0] = 1;
  f_iindx->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_iindx, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  ixstop = iindx->size[0] * iindx->size[1];
  for (cindx = 0; cindx < ixstop; cindx++) {
    f_iindx->data[cindx] = iindx->data[cindx];
  }

  emxFree_int32_T(&iindx);
  emxInit_real_T(sp, &d_SPitch, 2, &rb_emlrtRTEI, true);
  st.site = &eh_emlrtRSI;
  interp1(&st, f_iindx, Signal, VMerit_minmrt, SPitch);

  /* 'spec_trk:220' FILTER_ORDER = 3; */
  /* 'spec_trk:221' flt_b = (ones(1,FILTER_ORDER))/FILTER_ORDER ; */
  /* 'spec_trk:222' flt_a = 1; */
  /* 'spec_trk:224' SPitch = filter(flt_b, flt_a, SPitch); */
  cindx = d_SPitch->size[0] * d_SPitch->size[1];
  d_SPitch->size[0] = 1;
  d_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_SPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  ixstop = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&f_iindx);
  emxFree_real_T(&VMerit_minmrt);
  emxFree_real_T(&Signal);
  for (cindx = 0; cindx < ixstop; cindx++) {
    d_SPitch->data[cindx] = SPitch->data[cindx];
  }

  st.site = &fh_emlrtRSI;
  b_filter(&st, d_SPitch, SPitch);

  /*   above messes up  first few values of SPitch  ---  simple fix up */
  /*   Note--   this fix up should be based on above filter order */
  /* 'spec_trk:230' SPitch(1) = SPitch(3); */
  cindx = SPitch->size[1];
  if (!(1 <= cindx)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, cindx, &jd_emlrtBCI, sp);
  }

  cindx = SPitch->size[1];
  if (!(3 <= cindx)) {
    emlrtDynamicBoundsCheckR2012b(3, 1, cindx, &id_emlrtBCI, sp);
  }

  SPitch->data[0] = SPitch->data[2];

  /* 'spec_trk:231' SPitch(2) = SPitch (4); */
  cindx = SPitch->size[1];
  if (!(2 <= cindx)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, cindx, &ld_emlrtBCI, sp);
  }

  cindx = SPitch->size[1];
  if (!(4 <= cindx)) {
    emlrtDynamicBoundsCheckR2012b(4, 1, cindx, &kd_emlrtBCI, sp);
  }

  SPitch->data[1] = SPitch->data[3];

  /*  Create pitch track with Voiced/Unvoiced decision */
  /* 'spec_trk:234' VUVSPitch = SPitch; */
  cindx = VUVSPitch->size[0] * VUVSPitch->size[1];
  VUVSPitch->size[0] = 1;
  VUVSPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVSPitch, cindx, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  ixstop = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&d_SPitch);
  for (cindx = 0; cindx < ixstop; cindx++) {
    VUVSPitch->data[cindx] = SPitch->data[cindx];
  }

  /* 'spec_trk:235' VUVSPitch(VUVEnergy==0) = 0; */
  iy = VUVEnergy->size[1];
  for (i = 0; i < iy; i++) {
    if (!VUVEnergy->data[i]) {
      cindx = VUVSPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= cindx))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, cindx, &rd_emlrtBCI, sp);
      }

      VUVSPitch->data[i] = 0.0;
    }
  }

  /*  SPitch = SPitch - delta; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (spec_trk.c) */
