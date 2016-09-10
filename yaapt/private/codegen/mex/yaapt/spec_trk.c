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
#include "yaapt_emxutil.h"
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
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo uh_emlrtRSI = { 80, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo vh_emlrtRSI = { 84, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo wh_emlrtRSI = { 85, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo xh_emlrtRSI = { 91, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo yh_emlrtRSI = { 93, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ai_emlrtRSI = { 97, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo bi_emlrtRSI = { 99, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ci_emlrtRSI = { 146, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo di_emlrtRSI = { 149, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ei_emlrtRSI = { 150, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo fi_emlrtRSI = { 154, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo gi_emlrtRSI = { 157, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo hi_emlrtRSI = { 164, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ii_emlrtRSI = { 180, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ji_emlrtRSI = { 181, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ki_emlrtRSI = { 201, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo li_emlrtRSI = { 202, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo mi_emlrtRSI = { 210, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ni_emlrtRSI = { 213, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo oi_emlrtRSI = { 217, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo pi_emlrtRSI = { 218, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo qi_emlrtRSI = { 224, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ql_emlrtRSI = { 15, "min",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo rl_emlrtRSI = { 210, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo sl_emlrtRSI = { 214, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo km_emlrtRSI = { 36, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo cc_emlrtRTEI = { 1, 42, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo dc_emlrtRTEI = { 187, 13, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo ec_emlrtRTEI = { 188, 13, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo fc_emlrtRTEI = { 68, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo gc_emlrtRTEI = { 69, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo hc_emlrtRTEI = { 80, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ic_emlrtRTEI = { 82, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo jc_emlrtRTEI = { 84, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo kc_emlrtRTEI = { 85, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo lc_emlrtRTEI = { 90, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo mc_emlrtRTEI = { 93, 14, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo nc_emlrtRTEI = { 143, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo oc_emlrtRTEI = { 159, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo gg_emlrtRTEI = { 172, 9, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 231, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 231, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 230, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 230, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 214, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo o_emlrtECI = { -1, 214, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 211, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo p_emlrtECI = { -1, 211, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 211, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 208, 21, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo q_emlrtECI = { -1, 205, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 193, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 190, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo bb_emlrtDCI = { 190, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 194, 9, "Idx_voiced", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 162, 44, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 162, 36, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 161, 44, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 161, 36, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo r_emlrtECI = { 2, 154, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 150, 30, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 149, 31, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo s_emlrtECI = { -1, 103, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 103, 22, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo t_emlrtECI = { -1, 99, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 99, 44, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 142, 21, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo u_emlrtECI = { -1, 102, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 102, 22, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo v_emlrtECI = { -1, 99, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 99, 23, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 102, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo db_emlrtDCI = { 102, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtECInfo w_emlrtECI = { 2, 97, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo jg_emlrtRTEI = { 96, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtECInfo x_emlrtECI = { 2, 90, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 90, 18, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo eb_emlrtDCI = { 90, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtRTEInfo kg_emlrtRTEI = { 87, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo fb_emlrtDCI = { 68, 20, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo gb_emlrtDCI = { 68, 20, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo hb_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo ib_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo jb_emlrtDCI = { 69, 19, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo kb_emlrtDCI = { 69, 19, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo lb_emlrtDCI = { 82, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo mb_emlrtDCI = { 82, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo nb_emlrtDCI = { 76, 26, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 144, 29, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 145, 28, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 209, 19, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 214, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 235, 1, "VUVSPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 205, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 169, 30, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 169, 17, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 169, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 169, 25, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 171, 30, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 171, 17, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 171, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 171, 25, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 161, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 161, 5, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 162, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 162, 5, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 88, 9, "VUVEnergy", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo ob_emlrtDCI = { 93, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo pb_emlrtDCI = { 93, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 97, 31, "Magnit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo qb_emlrtDCI = { 97, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 97, 13, "SHC", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo rb_emlrtDCI = { 97, 13, "spec_trk",
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
  int32_T i26;
  real_T ndbl;
  real_T anew;
  int32_T ix;
  emxArray_real_T *CandsMerit;
  real_T zero_padded;
  emxArray_real_T *r17;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  int32_T nm1d2;
  int32_T idx;
  int32_T n;
  real_T apnd;
  boolean_T overflow;
  real_T cdiff;
  emxArray_real_T *VMerit_minmrt;
  emxArray_real_T *winix;
  real_T absb;
  emxArray_real_T *Signal;
  emxArray_real_T *b_Signal;
  emxArray_real_T *rowix;
  int32_T frame;
  emxArray_real_T *Magnit;
  emxArray_int32_T *r18;
  emxArray_real_T *r19;
  emxArray_creal_T *r20;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  emxArray_real_T *r21;
  emxArray_real_T *r22;
  emxArray_real_T *b_Kaiser_window;
  real_T firstp;
  int32_T itmp;
  int32_T cindx;
  int32_T iv28[2];
  int32_T iv29[1];
  int32_T c_Kaiser_window[2];
  int32_T iv30[2];
  int32_T iv31[1];
  int32_T iv32[2];
  emxArray_boolean_T *Idx_voiced;
  emxArray_int32_T *iindx;
  int32_T i;
  real_T k;
  int32_T b_winix[2];
  int32_T iv33[2];
  int32_T iv34[1];
  int32_T iv35[1];
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
  boolean_T exitg2;
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
  covrtLogFcn(&emlrtCoverageInstance, 9U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0);

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
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, b_mod(window_length, 2.0) ==
                 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1);

    /* 'spec_trk:55' window_length = window_length + 1; */
    window_length++;
  }

  emxInit_real_T(sp, &CandsPitch, 2, &fc_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2);

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
  i26 = CandsPitch->size[0] * CandsPitch->size[1];
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &gb_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &fb_emlrtDCI, sp);
  }

  CandsPitch->size[0] = (int32_T)ndbl;
  if (!(numframes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &ib_emlrtDCI, sp);
  }

  ndbl = numframes;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &hb_emlrtDCI, sp);
  }

  CandsPitch->size[1] = (int32_T)ndbl;
  emxEnsureCapacity(sp, (emxArray__common *)CandsPitch, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &gb_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &fb_emlrtDCI, sp);
  }

  if (!(numframes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &ib_emlrtDCI, sp);
  }

  anew = numframes;
  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &hb_emlrtDCI, sp);
  }

  ix = (int32_T)ndbl * (int32_T)anew;
  for (i26 = 0; i26 < ix; i26++) {
    CandsPitch->data[i26] = 0.0;
  }

  emxInit_real_T(sp, &CandsMerit, 2, &gc_emlrtRTEI, true);

  /* 'spec_trk:69' CandsMerit = ones(maxpeaks, numframes); */
  i26 = CandsMerit->size[0] * CandsMerit->size[1];
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &kb_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &jb_emlrtDCI, sp);
  }

  CandsMerit->size[0] = (int32_T)ndbl;
  CandsMerit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)CandsMerit, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &kb_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &jb_emlrtDCI, sp);
  }

  ix = (int32_T)ndbl * (int32_T)numframes;
  for (i26 = 0; i26 < ix; i26++) {
    CandsMerit->data[i26] = 1.0;
  }

  /*  Zero padding a */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  /*  Data(end) = 0; */
  /* 'spec_trk:74' zero_padded = (numframes-1)*nframejump+nframesize-length(Data); */
  zero_padded = ((numframes - 1.0) * nframejump + nframesize) - (real_T)
    Data->size[1];

  /* 'spec_trk:75' if(zero_padded > 0) */
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 1, zero_padded > 0.0)) {
    emxInit_real_T(sp, &r17, 2, &cc_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3);

    /* 'spec_trk:76' Data = [Data zeros(1,zero_padded)]; */
    if (zero_padded != (int32_T)muDoubleScalarFloor(zero_padded)) {
      emlrtIntegerCheckR2012b(zero_padded, &nb_emlrtDCI, sp);
    }

    nm1d2 = Data->size[1];
    idx = (int32_T)zero_padded;
    i26 = Data->size[0] * Data->size[1];
    Data->size[1] = nm1d2 + (int32_T)zero_padded;
    emxEnsureCapacity(sp, (emxArray__common *)Data, i26, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    if (zero_padded != (int32_T)muDoubleScalarFloor(zero_padded)) {
      emlrtIntegerCheckR2012b(zero_padded, &nb_emlrtDCI, sp);
    }

    i26 = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    r17->size[1] = (int32_T)zero_padded;
    emxEnsureCapacity(sp, (emxArray__common *)r17, i26, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    ix = (int32_T)zero_padded;
    for (i26 = 0; i26 < ix; i26++) {
      r17->data[r17->size[0] * i26] = 0.0;
    }

    for (i26 = 0; i26 < idx; i26++) {
      Data->data[nm1d2 + i26] = r17->data[i26];
    }

    emxFree_real_T(&r17);
  }

  emxInit_real_T(sp, &Kaiser_window, 2, &hc_emlrtRTEI, true);
  emxInit_real_T(sp, &SHC, 2, &ic_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 4);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Compute SHC for voiced frame */
  /* 'spec_trk:80' Kaiser_window = Mykaiser(nframesize); */
  st.site = &uh_emlrtRSI;
  Mykaiser(&st, nframesize, Kaiser_window);

  /*  Kaiser_window_test = kaiser(nframesize); */
  /* 'spec_trk:82' SHC = zeros(1,max_SHC); */
  i26 = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  if (!(max_SHC >= 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &mb_emlrtDCI, sp);
  }

  ndbl = max_SHC;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &lb_emlrtDCI, sp);
  }

  SHC->size[1] = (int32_T)ndbl;
  emxEnsureCapacity(sp, (emxArray__common *)SHC, i26, (int32_T)sizeof(real_T),
                    &cc_emlrtRTEI);
  if (!(max_SHC >= 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &mb_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &lb_emlrtDCI, sp);
  }

  ix = (int32_T)ndbl;
  for (i26 = 0; i26 < ix; i26++) {
    SHC->data[i26] = 0.0;
  }

  /* 'spec_trk:84' winix = repmat([1:window_length], numharmonics+1,1); */
  st.site = &vh_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&d_st, &mf_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &VMerit_minmrt, 2, &oc_emlrtRTEI, true);
  i26 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  if (!(n >= 0)) {
    emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
  }

  VMerit_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, i26, (int32_T)
                    sizeof(real_T), &cc_emlrtRTEI);
  if (n > 0) {
    VMerit_minmrt->data[0] = anew;
    if (n > 1) {
      VMerit_minmrt->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      d_st.site = &bb_emlrtRSI;
      for (idx = 1; idx < nm1d2; idx++) {
        VMerit_minmrt->data[idx] = anew + (real_T)idx;
        VMerit_minmrt->data[(n - idx) - 1] = apnd - (real_T)idx;
      }

      if (nm1d2 << 1 == n - 1) {
        VMerit_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VMerit_minmrt->data[nm1d2] = anew + (real_T)nm1d2;
        VMerit_minmrt->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T(&c_st, &winix, 2, &jc_emlrtRTEI, true);
  st.site = &vh_emlrtRSI;
  repmat(&st, VMerit_minmrt, Prm->shc_numharms + 1.0, winix);

  /* 'spec_trk:85' rowix = repmat([1:numharmonics+1]', 1, window_length); */
  st.site = &wh_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&d_st, &mf_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &Signal, 2, &lc_emlrtRTEI, true);
  i26 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  if (!(n >= 0)) {
    emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
  }

  Signal->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)Signal, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  if (n > 0) {
    Signal->data[0] = anew;
    if (n > 1) {
      Signal->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      d_st.site = &bb_emlrtRSI;
      for (idx = 1; idx < nm1d2; idx++) {
        Signal->data[idx] = anew + (real_T)idx;
        Signal->data[(n - idx) - 1] = apnd - (real_T)idx;
      }

      if (nm1d2 << 1 == n - 1) {
        Signal->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        Signal->data[nm1d2] = anew + (real_T)nm1d2;
        Signal->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T1(&c_st, &b_Signal, 1, &cc_emlrtRTEI, true);
  i26 = b_Signal->size[0];
  b_Signal->size[0] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Signal, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  ix = Signal->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    b_Signal->data[i26] = Signal->data[Signal->size[0] * i26];
  }

  emxInit_real_T(sp, &rowix, 2, &kc_emlrtRTEI, true);
  st.site = &wh_emlrtRSI;
  b_repmat(&st, b_Signal, window_length, rowix);

  /* 'spec_trk:87' for frame = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &kg_emlrtRTEI, sp);
  frame = 0;
  emxFree_real_T(&b_Signal);
  emxInit_real_T1(sp, &Magnit, 1, &mc_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r18, 1, &cc_emlrtRTEI, true);
  emxInit_real_T(sp, &r19, 2, &cc_emlrtRTEI, true);
  emxInit_creal_T(sp, &r20, 2, &cc_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SHC, 2, &cc_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Magnit, 2, &cc_emlrtRTEI, true);
  emxInit_real_T(sp, &r21, 2, &cc_emlrtRTEI, true);
  emxInit_real_T(sp, &r22, 2, &cc_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Kaiser_window, 2, &cc_emlrtRTEI, true);
  while (frame <= (int32_T)numframes - 1) {
    covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 0, 1);

    /* 'spec_trk:88' if (VUVEnergy(frame) > 0) */
    i26 = VUVEnergy->size[1];
    if (!((frame + 1 >= 1) && (frame + 1 <= i26))) {
      emlrtDynamicBoundsCheckR2012b(frame + 1, 1, i26, &fe_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 2, (int32_T)VUVEnergy->
                   data[frame] > 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 5);

      /* 'spec_trk:89' firstp = 1+(frame-1)*(nframejump); */
      firstp = 1.0 + ((1.0 + (real_T)frame) - 1.0) * nframejump;

      /* 'spec_trk:90' Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window'; */
      ndbl = (firstp + nframesize) - 1.0;
      if (firstp > ndbl) {
        i26 = 0;
        itmp = 0;
      } else {
        i26 = Data->size[1];
        if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
          emlrtIntegerCheckR2012b(firstp, &eb_emlrtDCI, sp);
        }

        cindx = (int32_T)firstp;
        if (!((cindx >= 1) && (cindx <= i26))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &ld_emlrtBCI, sp);
        }

        i26 = cindx - 1;
        cindx = Data->size[1];
        if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
          emlrtIntegerCheckR2012b(ndbl, &eb_emlrtDCI, sp);
        }

        itmp = (int32_T)ndbl;
        if (!((itmp >= 1) && (itmp <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &ld_emlrtBCI, sp);
        }
      }

      iv28[0] = 1;
      iv28[1] = itmp - i26;
      cindx = b_Kaiser_window->size[0] * b_Kaiser_window->size[1];
      b_Kaiser_window->size[0] = Kaiser_window->size[1];
      b_Kaiser_window->size[1] = Kaiser_window->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_Kaiser_window, cindx, (int32_T)
                        sizeof(real_T), &cc_emlrtRTEI);
      ix = Kaiser_window->size[0];
      for (cindx = 0; cindx < ix; cindx++) {
        idx = Kaiser_window->size[1];
        for (nm1d2 = 0; nm1d2 < idx; nm1d2++) {
          b_Kaiser_window->data[nm1d2 + b_Kaiser_window->size[0] * cindx] =
            Kaiser_window->data[cindx + Kaiser_window->size[0] * nm1d2];
        }
      }

      for (cindx = 0; cindx < 2; cindx++) {
        c_Kaiser_window[cindx] = b_Kaiser_window->size[cindx];
      }

      if ((iv28[0] != c_Kaiser_window[0]) || (iv28[1] != c_Kaiser_window[1])) {
        emlrtSizeEqCheckNDR2012b(&iv28[0], &c_Kaiser_window[0], &x_emlrtECI, sp);
      }

      cindx = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      Signal->size[1] = itmp - i26;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, cindx, (int32_T)sizeof
                        (real_T), &cc_emlrtRTEI);
      ix = itmp - i26;
      for (cindx = 0; cindx < ix; cindx++) {
        Signal->data[Signal->size[0] * cindx] = Data->data[i26 + cindx] *
          Kaiser_window->data[cindx];
      }

      /* 'spec_trk:91' Signal = Signal - mean(Signal); */
      st.site = &xh_emlrtRSI;
      ndbl = mean(&st, Signal);
      i26 = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, i26, (int32_T)sizeof
                        (real_T), &cc_emlrtRTEI);
      ix = Signal->size[1];
      for (i26 = 0; i26 < ix; i26++) {
        Signal->data[Signal->size[0] * i26] -= ndbl;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      /* 'spec_trk:93' Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))']; */
      st.site = &yh_emlrtRSI;
      b_fft(&st, Signal, Prm->fft_length, r20);
      st.site = &yh_emlrtRSI;
      b_abs(&st, r20, VMerit_minmrt);
      if (!(half_winlen >= 0.0)) {
        emlrtNonNegativeCheckR2012b(half_winlen, &pb_emlrtDCI, sp);
      }

      ndbl = half_winlen;
      if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
        emlrtIntegerCheckR2012b(ndbl, &ob_emlrtDCI, sp);
      }

      i26 = Magnit->size[0];
      Magnit->size[0] = (int32_T)half_winlen + VMerit_minmrt->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)Magnit, i26, (int32_T)sizeof
                        (real_T), &cc_emlrtRTEI);
      ix = (int32_T)half_winlen;
      for (i26 = 0; i26 < ix; i26++) {
        Magnit->data[i26] = 0.0;
      }

      ix = VMerit_minmrt->size[1];
      for (i26 = 0; i26 < ix; i26++) {
        Magnit->data[i26 + (int32_T)half_winlen] = VMerit_minmrt->
          data[VMerit_minmrt->size[0] * i26];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      /* 'spec_trk:96' for k=min_SHC:max_SHC */
      i26 = (int32_T)(max_SHC + (1.0 - min_SHC));
      emlrtForLoopVectorCheckR2012b(min_SHC, 1.0, max_SHC, mxDOUBLE_CLASS, i26,
        &jg_emlrtRTEI, sp);
      idx = 0;
      while (idx <= i26 - 1) {
        k = min_SHC + (real_T)idx;
        covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 1, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 6);

        /* 'spec_trk:97' SHC(k) = sum(prod(Magnit( winix + k*rowix ))); */
        cindx = r19->size[0] * r19->size[1];
        r19->size[0] = rowix->size[0];
        r19->size[1] = rowix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)r19, cindx, (int32_T)sizeof
                          (real_T), &cc_emlrtRTEI);
        ix = rowix->size[0] * rowix->size[1];
        for (cindx = 0; cindx < ix; cindx++) {
          r19->data[cindx] = k * rowix->data[cindx];
        }

        for (cindx = 0; cindx < 2; cindx++) {
          b_winix[cindx] = winix->size[cindx];
        }

        for (cindx = 0; cindx < 2; cindx++) {
          iv33[cindx] = r19->size[cindx];
        }

        if ((b_winix[0] != iv33[0]) || (b_winix[1] != iv33[1])) {
          emlrtSizeEqCheckNDR2012b(&b_winix[0], &iv33[0], &w_emlrtECI, sp);
        }

        st.site = &ai_emlrtRSI;
        b_indexShapeCheck(&st, Magnit->size[0], *(int32_T (*)[2])winix->size);
        cindx = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = winix->size[0];
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)b_Magnit, cindx, (int32_T)
                          sizeof(real_T), &cc_emlrtRTEI);
        nm1d2 = Magnit->size[0];
        ix = winix->size[0] * winix->size[1];
        for (cindx = 0; cindx < ix; cindx++) {
          ndbl = winix->data[cindx] + r19->data[cindx];
          if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
            emlrtIntegerCheckR2012b(ndbl, &qb_emlrtDCI, sp);
          }

          itmp = (int32_T)ndbl;
          if (!((itmp >= 1) && (itmp <= nm1d2))) {
            emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &ge_emlrtBCI, sp);
          }

          b_Magnit->data[cindx] = Magnit->data[itmp - 1];
        }

        st.site = &ai_emlrtRSI;
        prod(&st, b_Magnit, VMerit_minmrt);
        cindx = SHC->size[1];
        if (k != (int32_T)k) {
          emlrtIntegerCheckR2012b(k, &rb_emlrtDCI, sp);
        }

        itmp = (int32_T)k;
        if (!((itmp >= 1) && (itmp <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &he_emlrtBCI, sp);
        }

        st.site = &ai_emlrtRSI;
        SHC->data[itmp - 1] = sum(&st, VMerit_minmrt);
        idx++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 1, 0);
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 7);

      /* 'spec_trk:99' [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm); */
      i26 = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_SHC, i26, (int32_T)sizeof
                        (real_T), &cc_emlrtRTEI);
      ix = SHC->size[0] * SHC->size[1];
      for (i26 = 0; i26 < ix; i26++) {
        b_SHC->data[i26] = SHC->data[i26];
      }

      st.site = &bi_emlrtRSI;
      peaks(&st, b_SHC, delta, maxpeaks, Prm->f0_min, Prm->f0_max,
            Prm->shc_pwidth, Prm->shc_thresh1, Prm->shc_thresh2, Prm->f0_double,
            Prm->f0_half, Prm->merit_extra, VMerit_minmrt, Signal);
      ix = CandsPitch->size[0];
      i26 = r18->size[0];
      r18->size[0] = ix;
      emxEnsureCapacity(sp, (emxArray__common *)r18, i26, (int32_T)sizeof
                        (int32_T), &cc_emlrtRTEI);
      for (i26 = 0; i26 < ix; i26++) {
        r18->data[i26] = i26;
      }

      i26 = CandsPitch->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i26))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &kd_emlrtBCI, sp);
      }

      iv34[0] = r18->size[0];
      emlrtSubAssignSizeCheckR2012b(iv34, 1, *(int32_T (*)[2])
        VMerit_minmrt->size, 2, &v_emlrtECI, sp);
      nm1d2 = r18->size[0];
      for (i26 = 0; i26 < nm1d2; i26++) {
        CandsPitch->data[r18->data[i26] + CandsPitch->size[0] * frame] =
          VMerit_minmrt->data[i26];
      }

      ix = CandsMerit->size[0];
      i26 = r18->size[0];
      r18->size[0] = ix;
      emxEnsureCapacity(sp, (emxArray__common *)r18, i26, (int32_T)sizeof
                        (int32_T), &cc_emlrtRTEI);
      for (i26 = 0; i26 < ix; i26++) {
        r18->data[i26] = i26;
      }

      i26 = CandsMerit->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i26))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &hd_emlrtBCI, sp);
      }

      iv35[0] = r18->size[0];
      emlrtSubAssignSizeCheckR2012b(iv35, 1, *(int32_T (*)[2])Signal->size, 2,
        &t_emlrtECI, sp);
      nm1d2 = r18->size[0];
      for (i26 = 0; i26 < nm1d2; i26++) {
        CandsMerit->data[r18->data[i26] + CandsMerit->size[0] * frame] =
          Signal->data[i26];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 8);

      /* 'spec_trk:100' else */
      /*  if energy is low,  let frame be considered as unvoiced */
      /* 'spec_trk:102' CandsPitch(:,frame) = zeros(1,maxpeaks); */
      ix = CandsPitch->size[0];
      i26 = r18->size[0];
      r18->size[0] = ix;
      emxEnsureCapacity(sp, (emxArray__common *)r18, i26, (int32_T)sizeof
                        (int32_T), &cc_emlrtRTEI);
      for (i26 = 0; i26 < ix; i26++) {
        r18->data[i26] = i26;
      }

      i26 = CandsPitch->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i26))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &jd_emlrtBCI, sp);
      }

      if (!(maxpeaks >= 0.0)) {
        emlrtNonNegativeCheckR2012b(maxpeaks, &db_emlrtDCI, sp);
      }

      ndbl = maxpeaks;
      if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
        emlrtIntegerCheckR2012b(ndbl, &cb_emlrtDCI, sp);
      }

      iv29[0] = r18->size[0];
      iv30[0] = 1;
      iv30[1] = (int32_T)maxpeaks;
      emlrtSubAssignSizeCheckR2012b(iv29, 1, iv30, 2, &u_emlrtECI, sp);
      i26 = r21->size[0] * r21->size[1];
      r21->size[0] = 1;
      r21->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r21, i26, (int32_T)sizeof(real_T),
                        &cc_emlrtRTEI);
      ix = (int32_T)maxpeaks;
      for (i26 = 0; i26 < ix; i26++) {
        r21->data[r21->size[0] * i26] = 0.0;
      }

      nm1d2 = r18->size[0];
      for (i26 = 0; i26 < nm1d2; i26++) {
        CandsPitch->data[r18->data[i26] + CandsPitch->size[0] * frame] =
          r21->data[i26];
      }

      /* 'spec_trk:103' CandsMerit(:,frame) = ones(1, maxpeaks); */
      ix = CandsMerit->size[0];
      i26 = r18->size[0];
      r18->size[0] = ix;
      emxEnsureCapacity(sp, (emxArray__common *)r18, i26, (int32_T)sizeof
                        (int32_T), &cc_emlrtRTEI);
      for (i26 = 0; i26 < ix; i26++) {
        r18->data[i26] = i26;
      }

      i26 = CandsMerit->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i26))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &gd_emlrtBCI, sp);
      }

      iv31[0] = r18->size[0];
      iv32[0] = 1;
      iv32[1] = (int32_T)maxpeaks;
      emlrtSubAssignSizeCheckR2012b(iv31, 1, iv32, 2, &s_emlrtECI, sp);
      i26 = r22->size[0] * r22->size[1];
      r22->size[0] = 1;
      r22->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r22, i26, (int32_T)sizeof(real_T),
                        &cc_emlrtRTEI);
      ix = (int32_T)maxpeaks;
      for (i26 = 0; i26 < ix; i26++) {
        r22->data[r22->size[0] * i26] = 1.0;
      }

      nm1d2 = r18->size[0];
      for (i26 = 0; i26 < nm1d2; i26++) {
        CandsMerit->data[r18->data[i26] + CandsMerit->size[0] * frame] =
          r22->data[i26];
      }
    }

    frame++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Kaiser_window);
  emxFree_real_T(&r22);
  emxFree_real_T(&r21);
  emxFree_real_T(&b_Magnit);
  emxFree_real_T(&b_SHC);
  emxFree_creal_T(&r20);
  emxFree_int32_T(&r18);
  emxFree_real_T(&Magnit);
  covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 9);

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
  i26 = CandsPitch->size[0];
  if (!(1 <= i26)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i26, &id_emlrtBCI, sp);
  }

  ix = CandsPitch->size[1];
  i26 = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = ix;
  emxEnsureCapacity(sp, (emxArray__common *)SPitch, i26, (int32_T)sizeof(real_T),
                    &cc_emlrtRTEI);
  for (i26 = 0; i26 < ix; i26++) {
    SPitch->data[SPitch->size[0] * i26] = CandsPitch->data[CandsPitch->size[0] *
      i26];
  }

  emxInit_boolean_T(sp, &Idx_voiced, 2, &nc_emlrtRTEI, true);

  /* 'spec_trk:143' Idx_voiced = SPitch > 0; */
  i26 = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Idx_voiced, i26, (int32_T)sizeof
                    (boolean_T), &cc_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    Idx_voiced->data[i26] = (SPitch->data[i26] > 0.0);
  }

  emxInit_int32_T(sp, &iindx, 2, &cc_emlrtRTEI, true);

  /* 'spec_trk:144' VCandsPitch  = CandsPitch(:,Idx_voiced); */
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      nm1d2++;
    }
  }

  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof(int32_T),
                    &cc_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  ix = CandsPitch->size[0];
  nm1d2 = CandsPitch->size[1];
  i26 = winix->size[0] * winix->size[1];
  winix->size[0] = ix;
  winix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)winix, i26, (int32_T)sizeof(real_T),
                    &cc_emlrtRTEI);
  idx = iindx->size[1];
  for (i26 = 0; i26 < idx; i26++) {
    for (cindx = 0; cindx < ix; cindx++) {
      itmp = iindx->data[iindx->size[0] * i26];
      if (!((itmp >= 1) && (itmp <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &md_emlrtBCI, sp);
      }

      winix->data[cindx + winix->size[0] * i26] = CandsPitch->data[cindx +
        CandsPitch->size[0] * (itmp - 1)];
    }
  }

  /* 'spec_trk:145' VCandsMerit = CandsMerit(:,Idx_voiced); */
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      nm1d2++;
    }
  }

  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof(int32_T),
                    &cc_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  ix = CandsMerit->size[0];
  nm1d2 = CandsMerit->size[1];
  i26 = rowix->size[0] * rowix->size[1];
  rowix->size[0] = ix;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowix, i26, (int32_T)sizeof(real_T),
                    &cc_emlrtRTEI);
  idx = iindx->size[1];
  for (i26 = 0; i26 < idx; i26++) {
    for (cindx = 0; cindx < ix; cindx++) {
      itmp = iindx->data[iindx->size[0] * i26];
      if (!((itmp >= 1) && (itmp <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &nd_emlrtBCI, sp);
      }

      rowix->data[cindx + rowix->size[0] * i26] = CandsMerit->data[cindx +
        CandsMerit->size[0] * (itmp - 1)];
    }
  }

  emxInit_boolean_T(sp, &b_SPitch, 2, &cc_emlrtRTEI, true);

  /* 'spec_trk:146' Num_VCands = sum(Idx_voiced); */
  i26 = b_SPitch->size[0] * b_SPitch->size[1];
  b_SPitch->size[0] = 1;
  b_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i26, (int32_T)sizeof
                    (boolean_T), &cc_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    b_SPitch->data[i26] = (SPitch->data[i26] > 0.0);
  }

  st.site = &ci_emlrtRSI;
  Num_VCands = b_sum(&st, b_SPitch);

  /*  Average, STD of the first choice candidates */
  /* 'spec_trk:149' avg_voiced = mean(VCandsPitch(1,:)); */
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_boolean_T(&b_SPitch);
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      nm1d2++;
    }
  }

  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof(int32_T),
                    &cc_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &b_CandsPitch, 2, &cc_emlrtRTEI, true);
  emxInit_int32_T1(sp, &b_iindx, 1, &cc_emlrtRTEI, true);
  i26 = CandsPitch->size[0];
  if (!(1 <= i26)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i26, &fd_emlrtBCI, sp);
  }

  ix = CandsPitch->size[0];
  i26 = b_iindx->size[0];
  b_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_iindx, i26, (int32_T)sizeof
                    (int32_T), &cc_emlrtRTEI);
  idx = iindx->size[1];
  for (i26 = 0; i26 < idx; i26++) {
    b_iindx->data[i26] = iindx->data[iindx->size[0] * i26];
  }

  emxInit_real_T(sp, &c_CandsPitch, 2, &cc_emlrtRTEI, true);
  idx = b_iindx->size[0];
  i26 = c_CandsPitch->size[0] * c_CandsPitch->size[1];
  c_CandsPitch->size[0] = ix;
  c_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_CandsPitch, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&b_iindx);
  for (i26 = 0; i26 < nm1d2; i26++) {
    for (cindx = 0; cindx < ix; cindx++) {
      c_CandsPitch->data[cindx + c_CandsPitch->size[0] * i26] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i26] -
        1)];
    }
  }

  i26 = b_CandsPitch->size[0] * b_CandsPitch->size[1];
  b_CandsPitch->size[0] = 1;
  b_CandsPitch->size[1] = idx;
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsPitch, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  for (i26 = 0; i26 < idx; i26++) {
    b_CandsPitch->data[b_CandsPitch->size[0] * i26] = c_CandsPitch->
      data[c_CandsPitch->size[0] * i26];
  }

  emxFree_real_T(&c_CandsPitch);
  st.site = &di_emlrtRSI;
  avg_voiced = mean(&st, b_CandsPitch);

  /* 'spec_trk:150' std_voiced = std(VCandsPitch(1,:)); */
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&b_CandsPitch);
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      nm1d2++;
    }
  }

  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof(int32_T),
                    &cc_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &d_CandsPitch, 2, &cc_emlrtRTEI, true);
  emxInit_int32_T1(sp, &c_iindx, 1, &cc_emlrtRTEI, true);
  i26 = CandsPitch->size[0];
  if (!(1 <= i26)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i26, &ed_emlrtBCI, sp);
  }

  ix = CandsPitch->size[0];
  i26 = c_iindx->size[0];
  c_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_iindx, i26, (int32_T)sizeof
                    (int32_T), &cc_emlrtRTEI);
  idx = iindx->size[1];
  for (i26 = 0; i26 < idx; i26++) {
    c_iindx->data[i26] = iindx->data[iindx->size[0] * i26];
  }

  emxInit_real_T(sp, &e_CandsPitch, 2, &cc_emlrtRTEI, true);
  idx = c_iindx->size[0];
  i26 = e_CandsPitch->size[0] * e_CandsPitch->size[1];
  e_CandsPitch->size[0] = ix;
  e_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)e_CandsPitch, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&c_iindx);
  for (i26 = 0; i26 < nm1d2; i26++) {
    for (cindx = 0; cindx < ix; cindx++) {
      e_CandsPitch->data[cindx + e_CandsPitch->size[0] * i26] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i26] -
        1)];
    }
  }

  i26 = d_CandsPitch->size[0] * d_CandsPitch->size[1];
  d_CandsPitch->size[0] = 1;
  d_CandsPitch->size[1] = idx;
  emxEnsureCapacity(sp, (emxArray__common *)d_CandsPitch, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  for (i26 = 0; i26 < idx; i26++) {
    d_CandsPitch->data[d_CandsPitch->size[0] * i26] = e_CandsPitch->
      data[e_CandsPitch->size[0] * i26];
  }

  emxFree_real_T(&e_CandsPitch);
  st.site = &ei_emlrtRSI;
  std_voiced = b_std(&st, d_CandsPitch);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  /* 'spec_trk:154' delta1 = abs((VCandsPitch - 0.8*avg_voiced)).*(3-VCandsMerit); */
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&d_CandsPitch);
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      nm1d2++;
    }
  }

  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof(int32_T),
                    &cc_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &f_CandsPitch, 2, &cc_emlrtRTEI, true);
  ix = CandsPitch->size[0];
  ndbl = 0.8 * avg_voiced;
  i26 = f_CandsPitch->size[0] * f_CandsPitch->size[1];
  f_CandsPitch->size[0] = ix;
  f_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_CandsPitch, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  idx = iindx->size[1];
  for (i26 = 0; i26 < idx; i26++) {
    for (cindx = 0; cindx < ix; cindx++) {
      f_CandsPitch->data[cindx + f_CandsPitch->size[0] * i26] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i26] -
        1)] - ndbl;
    }
  }

  st.site = &fi_emlrtRSI;
  c_abs(&st, f_CandsPitch, r19);
  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&f_CandsPitch);
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      nm1d2++;
    }
  }

  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof(int32_T),
                    &cc_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  for (i26 = 0; i26 < 2; i26++) {
    iv36[i26] = r19->size[i26];
  }

  emxInit_real_T(sp, &b_CandsMerit, 2, &cc_emlrtRTEI, true);
  ix = CandsMerit->size[0];
  i26 = b_CandsMerit->size[0] * b_CandsMerit->size[1];
  b_CandsMerit->size[0] = ix;
  b_CandsMerit->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsMerit, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  idx = iindx->size[1];
  for (i26 = 0; i26 < idx; i26++) {
    for (cindx = 0; cindx < ix; cindx++) {
      b_CandsMerit->data[cindx + b_CandsMerit->size[0] * i26] = CandsMerit->
        data[cindx + CandsMerit->size[0] * (iindx->data[iindx->size[0] * i26] -
        1)];
    }
  }

  for (i26 = 0; i26 < 2; i26++) {
    c_CandsMerit[i26] = b_CandsMerit->size[i26];
  }

  emxFree_real_T(&b_CandsMerit);
  if ((iv36[0] != c_CandsMerit[0]) || (iv36[1] != c_CandsMerit[1])) {
    emlrtSizeEqCheckNDR2012b(&iv36[0], &c_CandsMerit[0], &r_emlrtECI, sp);
  }

  idx = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      nm1d2++;
    }
  }

  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof(int32_T),
                    &cc_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= idx; i++) {
    if (SPitch->data[i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  i26 = Kaiser_window->size[0] * Kaiser_window->size[1];
  Kaiser_window->size[0] = r19->size[0];
  Kaiser_window->size[1] = r19->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  ix = r19->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    idx = r19->size[0];
    for (cindx = 0; cindx < idx; cindx++) {
      Kaiser_window->data[cindx + Kaiser_window->size[0] * i26] = r19->
        data[cindx + r19->size[0] * i26] * (3.0 - CandsMerit->data[cindx +
        CandsMerit->size[0] * (iindx->data[iindx->size[0] * i26] - 1)]);
    }
  }

  emxFree_real_T(&r19);

  /*  Interpolation of the weigthed candidates */
  /* 'spec_trk:157' [VR, Idx] = min(delta1); */
  st.site = &gi_emlrtRSI;
  b_st.site = &ql_emlrtRSI;
  c_st.site = &nk_emlrtRSI;
  if (((Kaiser_window->size[0] == 1) && (Kaiser_window->size[1] == 1)) ||
      (Kaiser_window->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &ig_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (Kaiser_window->size[0] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &hg_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  for (i26 = 0; i26 < 2; i26++) {
    outsz[i26] = (uint32_T)Kaiser_window->size[i26];
  }

  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i26, (int32_T)sizeof
                    (int32_T), &cc_emlrtRTEI);
  ix = (int32_T)outsz[1];
  for (i26 = 0; i26 < ix; i26++) {
    iindx->data[i26] = 1;
  }

  n = Kaiser_window->size[0];
  d_st.site = &rl_emlrtRSI;
  overflow = ((!(1 > Kaiser_window->size[1])) && (Kaiser_window->size[1] >
    2147483646));
  if (overflow) {
    e_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&e_st, true);
  }

  for (i = 0; i + 1 <= Kaiser_window->size[1]; i++) {
    nm1d2 = i * n;
    d_st.site = &sl_emlrtRSI;
    ix = i * n + 1;
    idx = nm1d2 + n;
    anew = Kaiser_window->data[nm1d2];
    itmp = 1;
    if (n > 1) {
      cindx = 1;
      if (muDoubleScalarIsNaN(Kaiser_window->data[nm1d2])) {
        e_st.site = &ib_emlrtRSI;
        if ((!(ix + 1 > idx)) && (idx > 2147483646)) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        nm1d2 = ix;
        exitg2 = false;
        while ((!exitg2) && (nm1d2 + 1 <= idx)) {
          cindx++;
          ix = nm1d2 + 1;
          if (!muDoubleScalarIsNaN(Kaiser_window->data[nm1d2])) {
            anew = Kaiser_window->data[nm1d2];
            itmp = cindx;
            exitg2 = true;
          } else {
            nm1d2++;
          }
        }
      }

      if (ix < idx) {
        e_st.site = &jb_emlrtRSI;
        if ((!(ix + 1 > idx)) && (idx > 2147483646)) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        while (ix + 1 <= idx) {
          cindx++;
          if (Kaiser_window->data[ix] < anew) {
            anew = Kaiser_window->data[ix];
            itmp = cindx;
          }

          ix++;
        }
      }
    }

    iindx->data[i] = itmp;
  }

  i26 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  ix = iindx->size[0] * iindx->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    Signal->data[i26] = iindx->data[i26];
  }

  /* 'spec_trk:158' VPeak_minmrt  = zeros(1, length(Idx)); */
  i26 = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SHC, i26, (int32_T)sizeof(real_T),
                    &cc_emlrtRTEI);
  ix = Signal->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    SHC->data[i26] = 0.0;
  }

  /* 'spec_trk:159' VMerit_minmrt = zeros(1, length(Idx)); */
  i26 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VMerit_minmrt, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  ix = Signal->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    VMerit_minmrt->data[i26] = 0.0;
  }

  /* 'spec_trk:160' for n=1: length(Idx) */
  n = 1;
  emxInit_int32_T1(sp, &d_iindx, 1, &cc_emlrtRTEI, true);
  emxInit_int32_T1(sp, &e_iindx, 1, &cc_emlrtRTEI, true);
  while (n - 1 <= Signal->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 10);

    /* 'spec_trk:161' VPeak_minmrt(n)  = VCandsPitch(Idx(n), n); */
    idx = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= idx; i++) {
      if (SPitch->data[i] > 0.0) {
        nm1d2++;
      }
    }

    i26 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof
                      (int32_T), &cc_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= idx; i++) {
      if (SPitch->data[i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    i26 = CandsPitch->size[0];
    cindx = d_iindx->size[0];
    d_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)d_iindx, cindx, (int32_T)sizeof
                      (int32_T), &cc_emlrtRTEI);
    ix = iindx->size[1];
    for (cindx = 0; cindx < ix; cindx++) {
      d_iindx->data[cindx] = iindx->data[iindx->size[0] * cindx];
    }

    cindx = Signal->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &be_emlrtBCI, sp);
    }

    cindx = (int32_T)Signal->data[n - 1];
    if (!((cindx >= 1) && (cindx <= i26))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &dd_emlrtBCI, sp);
    }

    i26 = d_iindx->size[0];
    if (!((n >= 1) && (n <= i26))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i26, &cd_emlrtBCI, sp);
    }

    i26 = n;
    itmp = SHC->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &ce_emlrtBCI, sp);
    }

    SHC->data[n - 1] = CandsPitch->data[(cindx + CandsPitch->size[0] *
      (iindx->data[iindx->size[0] * (i26 - 1)] - 1)) - 1];

    /* 'spec_trk:162' VMerit_minmrt(n) = VCandsMerit(Idx(n), n); */
    idx = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= idx; i++) {
      if (SPitch->data[i] > 0.0) {
        nm1d2++;
      }
    }

    i26 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof
                      (int32_T), &cc_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= idx; i++) {
      if (SPitch->data[i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    i26 = CandsMerit->size[0];
    cindx = e_iindx->size[0];
    e_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)e_iindx, cindx, (int32_T)sizeof
                      (int32_T), &cc_emlrtRTEI);
    ix = iindx->size[1];
    for (cindx = 0; cindx < ix; cindx++) {
      e_iindx->data[cindx] = iindx->data[iindx->size[0] * cindx];
    }

    cindx = Signal->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &de_emlrtBCI, sp);
    }

    cindx = (int32_T)Signal->data[n - 1];
    if (!((cindx >= 1) && (cindx <= i26))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &bd_emlrtBCI, sp);
    }

    i26 = e_iindx->size[0];
    if (!((n >= 1) && (n <= i26))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i26, &ad_emlrtBCI, sp);
    }

    i26 = n;
    itmp = VMerit_minmrt->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &ee_emlrtBCI, sp);
    }

    VMerit_minmrt->data[n - 1] = CandsMerit->data[(cindx + CandsMerit->size[0] *
      (iindx->data[iindx->size[0] * (i26 - 1)] - 1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&e_iindx);
  emxFree_int32_T(&d_iindx);
  emxFree_real_T(&CandsMerit);
  emxInit_real_T(sp, &c_SHC, 2, &cc_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 11);

  /* 'spec_trk:164' VPeak_minmrt = Mymedfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  i26 = c_SHC->size[0] * c_SHC->size[1];
  c_SHC->size[0] = 1;
  c_SHC->size[1] = SHC->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_SHC, i26, (int32_T)sizeof(real_T),
                    &cc_emlrtRTEI);
  ix = SHC->size[0] * SHC->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    c_SHC->data[i26] = SHC->data[i26];
  }

  st.site = &hi_emlrtRSI;
  Mymedfilt1(&st, c_SHC, muDoubleScalarMax(1.0, Prm->median_value - 2.0), SHC);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  /* 'spec_trk:168' for n=1: length(Idx) */
  n = 1;
  emxFree_real_T(&c_SHC);
  while (n - 1 <= Signal->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 12);

    /* 'spec_trk:169' VCandsPitch(Idx(n), n) = VPeak_minmrt(n); */
    i26 = SHC->size[1];
    if (!((n >= 1) && (n <= i26))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i26, &sd_emlrtBCI, sp);
    }

    i26 = winix->size[0];
    cindx = Signal->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &ud_emlrtBCI, sp);
    }

    cindx = (int32_T)Signal->data[n - 1];
    if (!((cindx >= 1) && (cindx <= i26))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &td_emlrtBCI, sp);
    }

    i26 = winix->size[1];
    if (!((n >= 1) && (n <= i26))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i26, &vd_emlrtBCI, sp);
    }

    winix->data[(cindx + winix->size[0] * (n - 1)) - 1] = SHC->data[n - 1];

    /*  Assign merit for the smoothed peaks */
    /* 'spec_trk:171' VCandsMerit(Idx(n), n) = VMerit_minmrt(n); */
    i26 = VMerit_minmrt->size[1];
    if (!((n >= 1) && (n <= i26))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i26, &wd_emlrtBCI, sp);
    }

    i26 = rowix->size[0];
    cindx = Signal->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &yd_emlrtBCI, sp);
    }

    cindx = (int32_T)Signal->data[n - 1];
    if (!((cindx >= 1) && (cindx <= i26))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &xd_emlrtBCI, sp);
    }

    i26 = rowix->size[1];
    if (!((n >= 1) && (n <= i26))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i26, &ae_emlrtBCI, sp);
    }

    rowix->data[(cindx + rowix->size[0] * (n - 1)) - 1] = VMerit_minmrt->data[n
      - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&SHC);
  covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 13);

  /*  Use dynamic programming to find best overal path among pitch candidates */
  /*  Dynamic weight for transition costs */
  /*  balance between local and transition costs */
  /* 'spec_trk:177' weight_trans = Prm.dp5_k1*std_voiced/avg_voiced; */
  /* 'spec_trk:178' VPitch = []; */
  i26 = Kaiser_window->size[0] * Kaiser_window->size[1];
  Kaiser_window->size[0] = 0;
  Kaiser_window->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);

  /* 'spec_trk:179' if (Num_VCands >2) */
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 3, Num_VCands > 2.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 14);

    /* 'spec_trk:180' [VPitch] = dynamic5(VCandsPitch, VCandsMerit,weight_trans); */
    st.site = &ii_emlrtRSI;
    dynamic5(&st, winix, rowix, Prm->dp5_k1 * std_voiced / avg_voiced,
             VMerit_minmrt);
    i26 = Kaiser_window->size[0] * Kaiser_window->size[1];
    Kaiser_window->size[0] = 1;
    Kaiser_window->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, i26, (int32_T)
                      sizeof(real_T), &cc_emlrtRTEI);
    ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (i26 = 0; i26 < ix; i26++) {
      Kaiser_window->data[i26] = VMerit_minmrt->data[i26];
    }

    /* 'spec_trk:181' VPitch = Mymedfilt1(VPitch, max(Prm.median_value-2, 1)); */
    st.site = &ji_emlrtRSI;
    b_Mymedfilt1(&st, Kaiser_window, muDoubleScalarMax(Prm->median_value - 2.0,
      1.0), VMerit_minmrt);
    i26 = Kaiser_window->size[0] * Kaiser_window->size[1];
    Kaiser_window->size[0] = 1;
    Kaiser_window->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, i26, (int32_T)
                      sizeof(real_T), &cc_emlrtRTEI);
    ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (i26 = 0; i26 < ix; i26++) {
      Kaiser_window->data[i26] = VMerit_minmrt->data[i26];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else {
    /* 'spec_trk:184' else */
    /* 'spec_trk:186' if (Num_VCands > 0) */
    if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 4, Num_VCands > 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 15);

      /*        for i = 1:Num_VCands   % assume at least 1 voiced candidate */
      /*         VPitch (i) = 150;   %   Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates */
      /*        end;  */
      /* 'spec_trk:190' VPitch(1:Num_VCands) = 150; */
      if (1.0 > Num_VCands) {
      } else {
        emlrtDynamicBoundsCheckR2012b(1, 1, 0, &xc_emlrtBCI, sp);
        if (Num_VCands != muDoubleScalarFloor(Num_VCands)) {
          emlrtIntegerCheckR2012b(Num_VCands, &bb_emlrtDCI, sp);
        }

        i26 = (int32_T)Num_VCands;
        emlrtDynamicBoundsCheckR2012b(i26, 1, 0, &xc_emlrtBCI, sp);
      }

      i26 = iindx->size[0] * iindx->size[1];
      iindx->size[0] = 1;
      iindx->size[1] = 0;
      emxEnsureCapacity(sp, (emxArray__common *)iindx, i26, (int32_T)sizeof
                        (int32_T), &cc_emlrtRTEI);
      ix = iindx->size[0] * iindx->size[1];
      for (i26 = 0; i26 < ix; i26++) {
        Kaiser_window->data[iindx->data[i26]] = 150.0;
      }

      /*    This should only occur for very short pitch tracks, and even then rarely */
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 16);

      /* 'spec_trk:192' else */
      /* 'spec_trk:193' VPitch(1) = 150; */
      emlrtDynamicBoundsCheckR2012b(1, 1, 0, &wc_emlrtBCI, sp);
      Kaiser_window->data[0] = 150.0;

      /*  to handle when no real voiced candidates */
      /* 'spec_trk:194' Idx_voiced(1) = 1; */
      i26 = CandsPitch->size[1];
      if (!(1 <= i26)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i26, &yc_emlrtBCI, sp);
      }

      Idx_voiced->data[0] = true;
    }
  }

  emxFree_real_T(&rowix);
  emxFree_real_T(&winix);
  emxFree_real_T(&CandsPitch);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 17);

  /*  Computing some statistics from the voiced frames */
  /* 'spec_trk:201' pAvg = mean(VPitch,2); */
  st.site = &ki_emlrtRSI;
  b_mean(&st, Kaiser_window, pAvg);

  /* 'spec_trk:202' pStd = std(VPitch,0,2); */
  st.site = &li_emlrtRSI;
  c_std(&st, Kaiser_window, pStd);

  /*  Streching out the smoothed pitch track */
  /* 'spec_trk:205' SPitch(Idx_voiced) = VPitch; */
  idx = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < idx; i++) {
    if (Idx_voiced->data[i]) {
      nm1d2++;
    }
  }

  i26 = Kaiser_window->size[0] * Kaiser_window->size[1];
  if (nm1d2 != i26) {
    emlrtSizeEqCheck1DR2012b(nm1d2, i26, &q_emlrtECI, sp);
  }

  idx = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < idx; i++) {
    if (Idx_voiced->data[i]) {
      i26 = SPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i26))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i26, &rd_emlrtBCI, sp);
      }

      SPitch->data[i] = Kaiser_window->data[nm1d2];
      nm1d2++;
    }
  }

  emxFree_boolean_T(&Idx_voiced);
  emxFree_real_T(&Kaiser_window);
  emxInit_boolean_T1(sp, &c_SPitch, 1, &cc_emlrtRTEI, true);

  /*  Interpolating thru unvoiced frames */
  /* 'spec_trk:208' SPitch_temp_first = SPitch(1); */
  i26 = SPitch->size[1];
  if (!(1 <= i26)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i26, &vc_emlrtBCI, sp);
  }

  /* 'spec_trk:209' SPitch_temp_end = SPitch(end); */
  i26 = SPitch->size[1];
  cindx = SPitch->size[1];
  if (!((cindx >= 1) && (cindx <= i26))) {
    emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &od_emlrtBCI, sp);
  }

  SPitch_temp_end = SPitch->data[cindx - 1];

  /* 'spec_trk:210' if all(SPitch_temp_first < (pAvg/2)) */
  anew = SPitch->data[0];
  i26 = c_SPitch->size[0];
  c_SPitch->size[0] = pAvg->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_SPitch, i26, (int32_T)sizeof
                    (boolean_T), &cc_emlrtRTEI);
  ix = pAvg->size[0];
  for (i26 = 0; i26 < ix; i26++) {
    c_SPitch->data[i26] = (anew < pAvg->data[i26] / 2.0);
  }

  st.site = &mi_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 5, all(&st, c_SPitch))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 18);

    /* 'spec_trk:211' SPitch(1)   = pAvg; */
    i26 = pAvg->size[0];
    if (1 != i26) {
      emlrtSizeEqCheck1DR2012b(1, i26, &p_emlrtECI, sp);
    }

    i26 = SPitch->size[1];
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, &uc_emlrtBCI, sp);
    }

    i26 = pAvg->size[0];
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, &tc_emlrtBCI, sp);
    }

    SPitch->data[0] = pAvg->data[0];
  }

  emxFree_boolean_T(&c_SPitch);
  emxInit_boolean_T1(sp, &b_SPitch_temp_end, 1, &cc_emlrtRTEI, true);

  /* 'spec_trk:213' if all(SPitch_temp_end < (pAvg/2)) */
  i26 = b_SPitch_temp_end->size[0];
  b_SPitch_temp_end->size[0] = pAvg->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch_temp_end, i26, (int32_T)
                    sizeof(boolean_T), &cc_emlrtRTEI);
  ix = pAvg->size[0];
  for (i26 = 0; i26 < ix; i26++) {
    b_SPitch_temp_end->data[i26] = (SPitch_temp_end < pAvg->data[i26] / 2.0);
  }

  st.site = &ni_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 6, all(&st, b_SPitch_temp_end)))
  {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 19);

    /* 'spec_trk:214' SPitch(end) = pAvg; */
    i26 = pAvg->size[0];
    if (1 != i26) {
      emlrtSizeEqCheck1DR2012b(1, i26, &o_emlrtECI, sp);
    }

    i26 = pAvg->size[0];
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, &sc_emlrtBCI, sp);
    }

    i26 = SPitch->size[1];
    cindx = SPitch->size[1];
    if (!((cindx >= 1) && (cindx <= i26))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i26, &pd_emlrtBCI, sp);
    }

    SPitch->data[cindx - 1] = pAvg->data[0];
  }

  emxFree_boolean_T(&b_SPitch_temp_end);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 20);

  /* 'spec_trk:217' [Indrows, Indcols, Vals] = find(SPitch); */
  st.site = &oi_emlrtRSI;
  b_st.site = &km_emlrtRSI;
  idx = 0;
  i26 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = SPitch->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i26, (int32_T)sizeof
                    (int32_T), &cc_emlrtRTEI);
  nm1d2 = SPitch->size[1];
  i26 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = nm1d2;
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  if (SPitch->size[1] == 0) {
    i26 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i26, (int32_T)sizeof
                      (int32_T), &cc_emlrtRTEI);
    i26 = Signal->size[0] * Signal->size[1];
    Signal->size[0] = 1;
    Signal->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i26, (int32_T)sizeof
                      (real_T), &cc_emlrtRTEI);
  } else {
    nm1d2 = 1;
    exitg1 = false;
    while ((!exitg1) && (nm1d2 <= SPitch->size[1])) {
      guard1 = false;
      if (SPitch->data[SPitch->size[0] * (nm1d2 - 1)] != 0.0) {
        idx++;
        iindx->data[idx - 1] = nm1d2;
        Signal->data[idx - 1] = SPitch->data[SPitch->size[0] * (nm1d2 - 1)];
        if (idx >= SPitch->size[1]) {
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

    if (idx <= SPitch->size[1]) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &gg_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (SPitch->size[1] == 1) {
      if (idx == 0) {
        i26 = iindx->size[0] * iindx->size[1];
        iindx->size[0] = 1;
        iindx->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i26, (int32_T)sizeof
                          (int32_T), &cc_emlrtRTEI);
        i26 = Signal->size[0] * Signal->size[1];
        Signal->size[0] = 1;
        Signal->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i26, (int32_T)
                          sizeof(real_T), &cc_emlrtRTEI);
      }
    } else {
      i26 = iindx->size[0] * iindx->size[1];
      if (1 > idx) {
        iindx->size[1] = 0;
      } else {
        iindx->size[1] = idx;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i26, (int32_T)sizeof
                        (int32_T), &dc_emlrtRTEI);
      i26 = Signal->size[0] * Signal->size[1];
      if (1 > idx) {
        Signal->size[1] = 0;
      } else {
        Signal->size[1] = idx;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i26, (int32_T)sizeof
                        (real_T), &ec_emlrtRTEI);
    }
  }

  /* 'spec_trk:218' SPitch = interp1(Indcols, Vals, [1:numframes], 'pchip'); */
  st.site = &pi_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&d_st, &mf_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  i26 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  if (!(n >= 0)) {
    emlrtNonNegativeCheckR2012b(n, &e_emlrtDCI, &c_st);
  }

  VMerit_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, i26, (int32_T)
                    sizeof(real_T), &cc_emlrtRTEI);
  if (n > 0) {
    VMerit_minmrt->data[0] = anew;
    if (n > 1) {
      VMerit_minmrt->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      d_st.site = &bb_emlrtRSI;
      for (idx = 1; idx < nm1d2; idx++) {
        VMerit_minmrt->data[idx] = anew + (real_T)idx;
        VMerit_minmrt->data[(n - idx) - 1] = apnd - (real_T)idx;
      }

      if (nm1d2 << 1 == n - 1) {
        VMerit_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VMerit_minmrt->data[nm1d2] = anew + (real_T)nm1d2;
        VMerit_minmrt->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T(&c_st, &f_iindx, 2, &cc_emlrtRTEI, true);
  i26 = f_iindx->size[0] * f_iindx->size[1];
  f_iindx->size[0] = 1;
  f_iindx->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_iindx, i26, (int32_T)sizeof(real_T),
                    &cc_emlrtRTEI);
  ix = iindx->size[0] * iindx->size[1];
  for (i26 = 0; i26 < ix; i26++) {
    f_iindx->data[i26] = iindx->data[i26];
  }

  emxFree_int32_T(&iindx);
  emxInit_real_T(sp, &d_SPitch, 2, &cc_emlrtRTEI, true);
  st.site = &pi_emlrtRSI;
  interp1(&st, f_iindx, Signal, VMerit_minmrt, SPitch);

  /* 'spec_trk:220' FILTER_ORDER = 3; */
  /* 'spec_trk:221' flt_b = (ones(1,FILTER_ORDER))/FILTER_ORDER ; */
  /* 'spec_trk:222' flt_a = 1; */
  /* 'spec_trk:224' SPitch = filter(flt_b, flt_a, SPitch); */
  i26 = d_SPitch->size[0] * d_SPitch->size[1];
  d_SPitch->size[0] = 1;
  d_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_SPitch, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&f_iindx);
  emxFree_real_T(&VMerit_minmrt);
  emxFree_real_T(&Signal);
  for (i26 = 0; i26 < ix; i26++) {
    d_SPitch->data[i26] = SPitch->data[i26];
  }

  st.site = &qi_emlrtRSI;
  b_filter(&st, d_SPitch, SPitch);

  /*   above messes up  first few values of SPitch  ---  simple fix up */
  /*   Note--   this fix up should be based on above filter order */
  /* 'spec_trk:230' SPitch(1) = SPitch(3); */
  i26 = SPitch->size[1];
  if (!(1 <= i26)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i26, &qc_emlrtBCI, sp);
  }

  i26 = SPitch->size[1];
  if (!(3 <= i26)) {
    emlrtDynamicBoundsCheckR2012b(3, 1, i26, &rc_emlrtBCI, sp);
  }

  SPitch->data[0] = SPitch->data[2];

  /* 'spec_trk:231' SPitch(2) = SPitch (4); */
  i26 = SPitch->size[1];
  if (!(2 <= i26)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i26, &oc_emlrtBCI, sp);
  }

  i26 = SPitch->size[1];
  if (!(4 <= i26)) {
    emlrtDynamicBoundsCheckR2012b(4, 1, i26, &pc_emlrtBCI, sp);
  }

  SPitch->data[1] = SPitch->data[3];

  /*  Create pitch track with Voiced/Unvoiced decision */
  /* 'spec_trk:234' VUVSPitch = SPitch; */
  i26 = VUVSPitch->size[0] * VUVSPitch->size[1];
  VUVSPitch->size[0] = 1;
  VUVSPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVSPitch, i26, (int32_T)sizeof
                    (real_T), &cc_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&d_SPitch);
  for (i26 = 0; i26 < ix; i26++) {
    VUVSPitch->data[i26] = SPitch->data[i26];
  }

  /* 'spec_trk:235' VUVSPitch(VUVEnergy==0) = 0; */
  idx = VUVEnergy->size[1];
  for (i = 0; i < idx; i++) {
    if (!VUVEnergy->data[i]) {
      i26 = VUVSPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i26))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i26, &qd_emlrtBCI, sp);
      }

      VUVSPitch->data[i] = 0.0;
    }
  }

  /*  SPitch = SPitch - delta; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (spec_trk.c) */
