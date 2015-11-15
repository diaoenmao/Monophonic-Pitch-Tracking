/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "rdivide.h"
#include "eml_int_forloop_overflow_check.h"
#include "sum.h"
#include "prod.h"
#include "indexShapeCheck.h"
#include "peaks.h"
#include "abs.h"
#include "fft.h"
#include "mean.h"
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
static emlrtRSInfo gd_emlrtRSI = { 221, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo hd_emlrtRSI = { 215, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo id_emlrtRSI = { 214, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo jd_emlrtRSI = { 210, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo kd_emlrtRSI = { 207, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ld_emlrtRSI = { 199, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo md_emlrtRSI = { 198, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo nd_emlrtRSI = { 178, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo od_emlrtRSI = { 177, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo pd_emlrtRSI = { 161, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo qd_emlrtRSI = { 154, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo rd_emlrtRSI = { 151, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo sd_emlrtRSI = { 147, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo td_emlrtRSI = { 146, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ud_emlrtRSI = { 143, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo vd_emlrtRSI = { 96, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo wd_emlrtRSI = { 94, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo xd_emlrtRSI = { 90, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo yd_emlrtRSI = { 88, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ae_emlrtRSI = { 82, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo be_emlrtRSI = { 81, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ce_emlrtRSI = { 77, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo wg_emlrtRSI = { 18, "min",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo xg_emlrtRSI = { 160, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo yg_emlrtRSI = { 163, "minOrMax",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo mh_emlrtRSI = { 36, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo r_emlrtRTEI = { 1, 42, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo s_emlrtRTEI = { 187, 13, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo t_emlrtRTEI = { 188, 13, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo u_emlrtRTEI = { 68, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo v_emlrtRTEI = { 69, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo w_emlrtRTEI = { 77, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo x_emlrtRTEI = { 79, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo y_emlrtRTEI = { 81, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ab_emlrtRTEI = { 82, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo bb_emlrtRTEI = { 87, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo cb_emlrtRTEI = { 90, 14, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo db_emlrtRTEI = { 140, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo eb_emlrtRTEI = { 151, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 156, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo gb_emlrtRTEI = { 175, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 228, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 228, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 227, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 227, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 211, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo h_emlrtECI = { -1, 211, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 208, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo i_emlrtECI = { -1, 208, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 208, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 205, 21, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo j_emlrtECI = { -1, 202, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 190, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 187, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 191, 9, "Idx_voiced", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 159, 44, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { 1, 4, 159, 36, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 158, 44, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { 1, 4, 158, 36, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo k_emlrtECI = { 2, 151, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 100, 22, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo l_emlrtECI = { -1, 96, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 96, 44, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 99, 22, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo m_emlrtECI = { -1, 96, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 96, 23, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo n_emlrtECI = { 2, 94, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo be_emlrtRTEI = { 93, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtECInfo o_emlrtECI = { 2, 87, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 87, 18, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo i_emlrtDCI = { 87, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtRTEInfo ce_emlrtRTEI = { 84, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo j_emlrtDCI = { 79, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo k_emlrtDCI = { 79, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo l_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo m_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtRTEInfo de_emlrtRTEI = { 172, 9, "find",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

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

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 206, 19, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 211, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 232, 1, "VUVSPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 202, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 166, 30, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { 1, 4, 166, 17, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 166, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 166, 25, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 168, 30, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { 1, 4, 168, 17, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 168, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 168, 25, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 158, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 158, 5, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 159, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 159, 5, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 85, 9, "VUVEnergy", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 90, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo q_emlrtDCI = { 90, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 94, 31, "Magnit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 94, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 94, 13, "SHC", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo s_emlrtDCI = { 94, 13, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

/* Function Definitions */

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
  int32_T i12;
  real_T anew;
  int32_T ix;
  emxArray_real_T *CandsMerit;
  emxArray_real_T *b_Data;
  int32_T cindx;
  int32_T nm1d2;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  int32_T n;
  real_T apnd;
  boolean_T overflow;
  real_T ndbl;
  real_T cdiff;
  emxArray_real_T *VMerit_minmrt;
  int32_T iy;
  emxArray_real_T *winix;
  emxArray_real_T *rowix;
  int32_T frame;
  emxArray_real_T *Signal;
  emxArray_real_T *Magnit;
  emxArray_real_T *r6;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  emxArray_real_T *b_Kaiser_window;
  real_T firstp;
  int32_T itmp;
  int32_T iv15[2];
  int32_T c_Kaiser_window[2];
  real_T dv8[8192];
  real_T k;
  int32_T b_winix[2];
  int32_T iv16[2];
  int32_T tmp_size[2];
  real_T tmp_data[15];
  int32_T b_tmp_size[2];
  real_T b_tmp_data[15];
  static const int32_T iv17[1] = { 4 };

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
  int32_T iv18[2];
  emxArray_real_T *b_CandsMerit;
  int32_T c_CandsMerit[2];
  emxArray_real_T *delta1;
  uint32_T unnamed_idx_1;
  boolean_T b_nm1d2;
  boolean_T exitg2;
  boolean_T b_ix;
  emxArray_int32_T *d_iindx;
  emxArray_int32_T *e_iindx;
  emxArray_real_T *c_SHC;
  emxArray_real_T *VPitch;
  emxArray_boolean_T *c_SPitch;
  real_T SPitch_temp_end;
  emxArray_real_T b_pAvg_data;
  emxArray_boolean_T *b_SPitch_temp_end;
  emxArray_real_T c_pAvg_data;
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

  emxInit_real_T(sp, &CandsPitch, 2, &u_emlrtRTEI, true);

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
  i12 = CandsPitch->size[0] * CandsPitch->size[1];
  CandsPitch->size[0] = 4;
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &m_emlrtDCI, sp);
  }

  anew = numframes;
  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &l_emlrtDCI, sp);
  }

  CandsPitch->size[1] = (int32_T)anew;
  emxEnsureCapacity(sp, (emxArray__common *)CandsPitch, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &m_emlrtDCI, sp);
  }

  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &l_emlrtDCI, sp);
  }

  ix = (int32_T)anew << 2;
  for (i12 = 0; i12 < ix; i12++) {
    CandsPitch->data[i12] = 0.0;
  }

  emxInit_real_T(sp, &CandsMerit, 2, &v_emlrtRTEI, true);

  /* 'spec_trk:69' CandsMerit = ones(maxpeaks, numframes); */
  i12 = CandsMerit->size[0] * CandsMerit->size[1];
  CandsMerit->size[0] = 4;
  CandsMerit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)CandsMerit, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  ix = (int32_T)numframes << 2;
  for (i12 = 0; i12 < ix; i12++) {
    CandsMerit->data[i12] = 1.0;
  }

  emxInit_real_T(sp, &b_Data, 2, &r_emlrtRTEI, true);

  /*  Zero paddinga */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  /* 'spec_trk:73' Data(end) = 0; */
  i12 = Data->size[1];
  cindx = Data->size[1];
  if (!((cindx >= 1) && (cindx <= i12))) {
    emlrtDynamicBoundsCheckR2012b(cindx, 1, i12, &tc_emlrtBCI, sp);
  }

  Data->data[cindx - 1] = 0.0;

  /* 'spec_trk:74' Data = [Data zeros(1,(numframes-1)*nframejump+nframesize-length(Data))]; */
  nm1d2 = Data->size[1];
  anew = ((numframes - 1.0) * nframejump + nframesize) - (real_T)nm1d2;
  if (!(anew > 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &o_emlrtDCI, sp);
  }

  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &n_emlrtDCI, sp);
  }

  nm1d2 = (int32_T)anew;
  i12 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1] + nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  ix = Data->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    b_Data->data[b_Data->size[0] * i12] = Data->data[Data->size[0] * i12];
  }

  for (i12 = 0; i12 < nm1d2; i12++) {
    b_Data->data[b_Data->size[0] * (i12 + Data->size[1])] = 0.0;
  }

  i12 = Data->size[0] * Data->size[1];
  Data->size[0] = 1;
  Data->size[1] = b_Data->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Data, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  ix = b_Data->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    Data->data[Data->size[0] * i12] = b_Data->data[b_Data->size[0] * i12];
  }

  emxFree_real_T(&b_Data);
  emxInit_real_T(sp, &Kaiser_window, 2, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &SHC, 2, &x_emlrtRTEI, true);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Compute SHC for voiced frame */
  /* 'spec_trk:77' Kaiser_window = Mykaiser(nframesize); */
  st.site = &ce_emlrtRSI;
  Mykaiser(&st, nframesize, Kaiser_window);

  /*  Kaiser_window_test = kaiser(nframesize); */
  /* 'spec_trk:79' SHC = zeros(1,max_SHC); */
  i12 = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  if (!(max_SHC > 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &k_emlrtDCI, sp);
  }

  anew = max_SHC;
  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &j_emlrtDCI, sp);
  }

  SHC->size[1] = (int32_T)anew;
  emxEnsureCapacity(sp, (emxArray__common *)SHC, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  if (!(max_SHC > 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &k_emlrtDCI, sp);
  }

  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &j_emlrtDCI, sp);
  }

  ix = (int32_T)anew;
  for (i12 = 0; i12 < ix; i12++) {
    SHC->data[i12] = 0.0;
  }

  /* 'spec_trk:81' winix = repmat([1:window_length], numharmonics+1,1); */
  st.site = &be_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
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

  d_st.site = &mc_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &td_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &VMerit_minmrt, 2, &fb_emlrtRTEI, true);
  i12 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, i12, (int32_T)
                    sizeof(real_T), &r_emlrtRTEI);
  if (n > 0) {
    VMerit_minmrt->data[0] = anew;
    if (n > 1) {
      VMerit_minmrt->data[n - 1] = apnd;
      i12 = n - 1;
      nm1d2 = asr_s32(i12, 1U);
      d_st.site = &nc_emlrtRSI;
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

  emxInit_real_T(&c_st, &winix, 2, &y_emlrtRTEI, true);
  emxInit_real_T(&c_st, &rowix, 2, &ab_emlrtRTEI, true);
  st.site = &be_emlrtRSI;
  repmat(&st, VMerit_minmrt, winix);

  /* 'spec_trk:82' rowix = repmat([1:numharmonics+1]', 1, window_length); */
  st.site = &ae_emlrtRSI;
  b_repmat(&st, window_length, rowix);

  /* 'spec_trk:84' for frame = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &ce_emlrtRTEI, sp);
  frame = 0;
  emxInit_real_T(sp, &Signal, 2, &bb_emlrtRTEI, true);
  emxInit_real_T1(sp, &Magnit, 1, &cb_emlrtRTEI, true);
  emxInit_real_T(sp, &r6, 2, &r_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SHC, 2, &r_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Magnit, 2, &r_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Kaiser_window, 2, &r_emlrtRTEI, true);
  while (frame <= (int32_T)numframes - 1) {
    /* 'spec_trk:85' if (VUVEnergy(frame) > 0) */
    i12 = VUVEnergy->size[1];
    if (!((frame + 1 >= 1) && (frame + 1 <= i12))) {
      emlrtDynamicBoundsCheckR2012b(frame + 1, 1, i12, &nd_emlrtBCI, sp);
    }

    if ((int32_T)VUVEnergy->data[frame] > 0) {
      /* 'spec_trk:86' firstp = 1+(frame-1)*(nframejump); */
      firstp = 1.0 + ((1.0 + (real_T)frame) - 1.0) * nframejump;

      /* 'spec_trk:87' Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window'; */
      anew = (firstp + nframesize) - 1.0;
      if (firstp > anew) {
        i12 = 0;
        itmp = 0;
      } else {
        i12 = Data->size[1];
        if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
          emlrtIntegerCheckR2012b(firstp, &i_emlrtDCI, sp);
        }

        cindx = (int32_T)firstp;
        if (!((cindx >= 1) && (cindx <= i12))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, i12, &sc_emlrtBCI, sp);
        }

        i12 = cindx - 1;
        cindx = Data->size[1];
        if (anew != (int32_T)muDoubleScalarFloor(anew)) {
          emlrtIntegerCheckR2012b(anew, &i_emlrtDCI, sp);
        }

        itmp = (int32_T)anew;
        if (!((itmp >= 1) && (itmp <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &sc_emlrtBCI, sp);
        }
      }

      iv15[0] = 1;
      iv15[1] = itmp - i12;
      cindx = b_Kaiser_window->size[0] * b_Kaiser_window->size[1];
      b_Kaiser_window->size[0] = 1;
      b_Kaiser_window->size[1] = Kaiser_window->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_Kaiser_window, cindx, (int32_T)
                        sizeof(real_T), &r_emlrtRTEI);
      ix = Kaiser_window->size[0];
      for (cindx = 0; cindx < ix; cindx++) {
        b_Kaiser_window->data[b_Kaiser_window->size[0] * cindx] =
          Kaiser_window->data[cindx];
      }

      for (cindx = 0; cindx < 2; cindx++) {
        c_Kaiser_window[cindx] = b_Kaiser_window->size[cindx];
      }

      if ((iv15[0] != c_Kaiser_window[0]) || (iv15[1] != c_Kaiser_window[1])) {
        emlrtSizeEqCheckNDR2012b(&iv15[0], &c_Kaiser_window[0], &o_emlrtECI, sp);
      }

      cindx = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      Signal->size[1] = itmp - i12;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, cindx, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      ix = itmp - i12;
      for (cindx = 0; cindx < ix; cindx++) {
        Signal->data[Signal->size[0] * cindx] = Data->data[i12 + cindx] *
          Kaiser_window->data[cindx];
      }

      /* 'spec_trk:88' Signal = Signal - mean(Signal); */
      st.site = &yd_emlrtRSI;
      anew = mean(&st, Signal);
      i12 = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, i12, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      ix = Signal->size[1];
      for (i12 = 0; i12 < ix; i12++) {
        Signal->data[Signal->size[0] * i12] -= anew;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      /* 'spec_trk:90' Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))']; */
      st.site = &xd_emlrtRSI;
      fft(&st, Signal, SD->u1.f0.dcv0);
      b_abs(SD->u1.f0.dcv0, dv8);
      i12 = Magnit->size[0];
      if (!(half_winlen > 0.0)) {
        emlrtNonNegativeCheckR2012b(half_winlen, &q_emlrtDCI, sp);
      }

      anew = half_winlen;
      if (anew != (int32_T)muDoubleScalarFloor(anew)) {
        emlrtIntegerCheckR2012b(anew, &p_emlrtDCI, sp);
      }

      Magnit->size[0] = (int32_T)anew + 8192;
      emxEnsureCapacity(sp, (emxArray__common *)Magnit, i12, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      if (!(half_winlen > 0.0)) {
        emlrtNonNegativeCheckR2012b(half_winlen, &q_emlrtDCI, sp);
      }

      if (anew != (int32_T)muDoubleScalarFloor(anew)) {
        emlrtIntegerCheckR2012b(anew, &p_emlrtDCI, sp);
      }

      ix = (int32_T)anew;
      for (i12 = 0; i12 < ix; i12++) {
        Magnit->data[i12] = 0.0;
      }

      for (i12 = 0; i12 < 8192; i12++) {
        if (!(half_winlen > 0.0)) {
          emlrtNonNegativeCheckR2012b(half_winlen, &q_emlrtDCI, sp);
        }

        if (anew != (int32_T)muDoubleScalarFloor(anew)) {
          emlrtIntegerCheckR2012b(anew, &p_emlrtDCI, sp);
        }

        Magnit->data[i12 + (int32_T)anew] = dv8[i12];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      /* 'spec_trk:93' for k=min_SHC:max_SHC */
      i12 = (int32_T)(max_SHC + (1.0 - min_SHC));
      emlrtForLoopVectorCheckR2012b(min_SHC, 1.0, max_SHC, mxDOUBLE_CLASS, i12,
        &be_emlrtRTEI, sp);
      iy = 0;
      while (iy <= i12 - 1) {
        k = min_SHC + (real_T)iy;

        /* 'spec_trk:94' SHC(k) = sum(prod(Magnit( winix + k*rowix ))); */
        cindx = r6->size[0] * r6->size[1];
        r6->size[0] = 4;
        r6->size[1] = rowix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)r6, cindx, (int32_T)sizeof
                          (real_T), &r_emlrtRTEI);
        ix = rowix->size[0] * rowix->size[1];
        for (cindx = 0; cindx < ix; cindx++) {
          r6->data[cindx] = k * rowix->data[cindx];
        }

        for (cindx = 0; cindx < 2; cindx++) {
          b_winix[cindx] = winix->size[cindx];
        }

        for (cindx = 0; cindx < 2; cindx++) {
          iv16[cindx] = r6->size[cindx];
        }

        if ((b_winix[0] != iv16[0]) || (b_winix[1] != iv16[1])) {
          emlrtSizeEqCheckNDR2012b(&b_winix[0], &iv16[0], &n_emlrtECI, sp);
        }

        st.site = &wd_emlrtRSI;
        b_indexShapeCheck(&st, *(int32_T (*)[2])winix->size);
        cindx = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = 4;
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)b_Magnit, cindx, (int32_T)
                          sizeof(real_T), &r_emlrtRTEI);
        nm1d2 = Magnit->size[0];
        ix = winix->size[0] * winix->size[1];
        for (cindx = 0; cindx < ix; cindx++) {
          anew = winix->data[cindx] + r6->data[cindx];
          if (anew != (int32_T)muDoubleScalarFloor(anew)) {
            emlrtIntegerCheckR2012b(anew, &r_emlrtDCI, sp);
          }

          itmp = (int32_T)anew;
          if (!((itmp >= 1) && (itmp <= nm1d2))) {
            emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &od_emlrtBCI, sp);
          }

          b_Magnit->data[cindx] = Magnit->data[itmp - 1];
        }

        st.site = &wd_emlrtRSI;
        prod(&st, b_Magnit, VMerit_minmrt);
        cindx = SHC->size[1];
        if (k != (int32_T)k) {
          emlrtIntegerCheckR2012b(k, &s_emlrtDCI, sp);
        }

        itmp = (int32_T)k;
        if (!((itmp >= 1) && (itmp <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &pd_emlrtBCI, sp);
        }

        st.site = &wd_emlrtRSI;
        SHC->data[itmp - 1] = sum(&st, VMerit_minmrt);
        iy++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* 'spec_trk:96' [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm); */
      i12 = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_SHC, i12, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      ix = SHC->size[0] * SHC->size[1];
      for (i12 = 0; i12 < ix; i12++) {
        b_SHC->data[i12] = SHC->data[i12];
      }

      st.site = &vd_emlrtRSI;
      peaks(&st, b_SHC, delta, b_tmp_data, b_tmp_size, tmp_data, tmp_size);
      i12 = CandsPitch->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i12))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i12, &rc_emlrtBCI, sp);
      }

      emlrtSubAssignSizeCheckR2012b(iv17, 1, b_tmp_size, 2, &m_emlrtECI, sp);
      for (i12 = 0; i12 < 4; i12++) {
        CandsPitch->data[i12 + CandsPitch->size[0] * frame] = b_tmp_data[i12];
      }

      i12 = CandsMerit->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i12))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i12, &pc_emlrtBCI, sp);
      }

      emlrtSubAssignSizeCheckR2012b(iv17, 1, tmp_size, 2, &l_emlrtECI, sp);
      for (i12 = 0; i12 < 4; i12++) {
        CandsMerit->data[i12 + CandsMerit->size[0] * frame] = tmp_data[i12];
      }
    } else {
      /* 'spec_trk:97' else */
      /*  if energy is low,  let frame be considered as unvoiced */
      /* 'spec_trk:99' CandsPitch(:,frame) = zeros(1,maxpeaks); */
      nm1d2 = CandsPitch->size[1];
      if (!((frame + 1 >= 1) && (frame + 1 <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(frame + 1, 1, nm1d2, &qc_emlrtBCI, sp);
      }

      for (i12 = 0; i12 < 4; i12++) {
        CandsPitch->data[i12 + CandsPitch->size[0] * frame] = 0.0;
      }

      /* 'spec_trk:100' CandsMerit(:,frame) = ones(1, maxpeaks); */
      nm1d2 = CandsMerit->size[1];
      if (!((frame + 1 >= 1) && (frame + 1 <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(frame + 1, 1, nm1d2, &oc_emlrtBCI, sp);
      }

      for (i12 = 0; i12 < 4; i12++) {
        CandsMerit->data[i12 + CandsMerit->size[0] * frame] = 1.0;
      }
    }

    frame++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Kaiser_window);
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
  ix = CandsPitch->size[1];
  i12 = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = ix;
  emxEnsureCapacity(sp, (emxArray__common *)SPitch, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  for (i12 = 0; i12 < ix; i12++) {
    SPitch->data[SPitch->size[0] * i12] = CandsPitch->data[CandsPitch->size[0] *
      i12];
  }

  emxInit_boolean_T(sp, &Idx_voiced, 2, &db_emlrtRTEI, true);

  /* 'spec_trk:140' Idx_voiced = SPitch > 0; */
  i12 = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Idx_voiced, i12, (int32_T)sizeof
                    (boolean_T), &r_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    Idx_voiced->data[i12] = (SPitch->data[i12] > 0.0);
  }

  emxInit_int32_T1(sp, &iindx, 2, &r_emlrtRTEI, true);

  /* 'spec_trk:141' VCandsPitch  = CandsPitch(:,Idx_voiced); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof(int32_T),
                    &r_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  nm1d2 = CandsPitch->size[1];
  i12 = winix->size[0] * winix->size[1];
  winix->size[0] = 4;
  winix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)winix, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  ix = iindx->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    for (cindx = 0; cindx < 4; cindx++) {
      itmp = iindx->data[iindx->size[0] * i12];
      if (!((itmp >= 1) && (itmp <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &uc_emlrtBCI, sp);
      }

      winix->data[cindx + winix->size[0] * i12] = CandsPitch->data[cindx +
        CandsPitch->size[0] * (itmp - 1)];
    }
  }

  /* 'spec_trk:142' VCandsMerit = CandsMerit(:,Idx_voiced); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof(int32_T),
                    &r_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  nm1d2 = CandsMerit->size[1];
  i12 = rowix->size[0] * rowix->size[1];
  rowix->size[0] = 4;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowix, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  ix = iindx->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    for (cindx = 0; cindx < 4; cindx++) {
      itmp = iindx->data[iindx->size[0] * i12];
      if (!((itmp >= 1) && (itmp <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &vc_emlrtBCI, sp);
      }

      rowix->data[cindx + rowix->size[0] * i12] = CandsMerit->data[cindx +
        CandsMerit->size[0] * (itmp - 1)];
    }
  }

  emxInit_boolean_T(sp, &b_SPitch, 2, &r_emlrtRTEI, true);

  /* 'spec_trk:143' Num_VCands = sum(Idx_voiced); */
  i12 = b_SPitch->size[0] * b_SPitch->size[1];
  b_SPitch->size[0] = 1;
  b_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i12, (int32_T)sizeof
                    (boolean_T), &r_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    b_SPitch->data[i12] = (SPitch->data[i12] > 0.0);
  }

  st.site = &ud_emlrtRSI;
  Num_VCands = b_sum(&st, b_SPitch);

  /*  Average, STD of the first choice candidates */
  /* 'spec_trk:146' avg_voiced = mean(VCandsPitch(1,:)); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_boolean_T(&b_SPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof(int32_T),
                    &r_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &b_CandsPitch, 2, &r_emlrtRTEI, true);
  emxInit_int32_T(sp, &b_iindx, 1, &r_emlrtRTEI, true);
  i12 = b_iindx->size[0];
  b_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_iindx, i12, (int32_T)sizeof
                    (int32_T), &r_emlrtRTEI);
  ix = iindx->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    b_iindx->data[i12] = iindx->data[iindx->size[0] * i12];
  }

  emxInit_real_T(sp, &c_CandsPitch, 2, &r_emlrtRTEI, true);
  ix = b_iindx->size[0];
  i12 = c_CandsPitch->size[0] * c_CandsPitch->size[1];
  c_CandsPitch->size[0] = 4;
  c_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_CandsPitch, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&b_iindx);
  for (i12 = 0; i12 < nm1d2; i12++) {
    for (cindx = 0; cindx < 4; cindx++) {
      c_CandsPitch->data[cindx + c_CandsPitch->size[0] * i12] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i12] -
        1)];
    }
  }

  i12 = b_CandsPitch->size[0] * b_CandsPitch->size[1];
  b_CandsPitch->size[0] = 1;
  b_CandsPitch->size[1] = ix;
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsPitch, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  for (i12 = 0; i12 < ix; i12++) {
    b_CandsPitch->data[b_CandsPitch->size[0] * i12] = c_CandsPitch->
      data[c_CandsPitch->size[0] * i12];
  }

  emxFree_real_T(&c_CandsPitch);
  st.site = &td_emlrtRSI;
  avg_voiced = mean(&st, b_CandsPitch);

  /* 'spec_trk:147' std_voiced = std(VCandsPitch(1,:)); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&b_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof(int32_T),
                    &r_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &d_CandsPitch, 2, &r_emlrtRTEI, true);
  emxInit_int32_T(sp, &c_iindx, 1, &r_emlrtRTEI, true);
  i12 = c_iindx->size[0];
  c_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_iindx, i12, (int32_T)sizeof
                    (int32_T), &r_emlrtRTEI);
  ix = iindx->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    c_iindx->data[i12] = iindx->data[iindx->size[0] * i12];
  }

  emxInit_real_T(sp, &e_CandsPitch, 2, &r_emlrtRTEI, true);
  ix = c_iindx->size[0];
  i12 = e_CandsPitch->size[0] * e_CandsPitch->size[1];
  e_CandsPitch->size[0] = 4;
  e_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)e_CandsPitch, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&c_iindx);
  for (i12 = 0; i12 < nm1d2; i12++) {
    for (cindx = 0; cindx < 4; cindx++) {
      e_CandsPitch->data[cindx + e_CandsPitch->size[0] * i12] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i12] -
        1)];
    }
  }

  i12 = d_CandsPitch->size[0] * d_CandsPitch->size[1];
  d_CandsPitch->size[0] = 1;
  d_CandsPitch->size[1] = ix;
  emxEnsureCapacity(sp, (emxArray__common *)d_CandsPitch, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  for (i12 = 0; i12 < ix; i12++) {
    d_CandsPitch->data[d_CandsPitch->size[0] * i12] = e_CandsPitch->
      data[e_CandsPitch->size[0] * i12];
  }

  emxFree_real_T(&e_CandsPitch);
  st.site = &sd_emlrtRSI;
  std_voiced = b_std(&st, d_CandsPitch);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  /* 'spec_trk:151' delta1 = abs((VCandsPitch - 0.8*avg_voiced)).*(3-VCandsMerit); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&d_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof(int32_T),
                    &r_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &f_CandsPitch, 2, &r_emlrtRTEI, true);
  anew = 0.8 * avg_voiced;
  i12 = f_CandsPitch->size[0] * f_CandsPitch->size[1];
  f_CandsPitch->size[0] = 4;
  f_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_CandsPitch, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  ix = iindx->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    for (cindx = 0; cindx < 4; cindx++) {
      f_CandsPitch->data[cindx + f_CandsPitch->size[0] * i12] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i12] -
        1)] - anew;
    }
  }

  st.site = &rd_emlrtRSI;
  c_abs(&st, f_CandsPitch, r6);
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&f_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof(int32_T),
                    &r_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  for (i12 = 0; i12 < 2; i12++) {
    iv18[i12] = r6->size[i12];
  }

  emxInit_real_T(sp, &b_CandsMerit, 2, &r_emlrtRTEI, true);
  i12 = b_CandsMerit->size[0] * b_CandsMerit->size[1];
  b_CandsMerit->size[0] = 4;
  b_CandsMerit->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsMerit, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  ix = iindx->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    for (cindx = 0; cindx < 4; cindx++) {
      b_CandsMerit->data[cindx + b_CandsMerit->size[0] * i12] = CandsMerit->
        data[cindx + CandsMerit->size[0] * (iindx->data[iindx->size[0] * i12] -
        1)];
    }
  }

  for (i12 = 0; i12 < 2; i12++) {
    c_CandsMerit[i12] = b_CandsMerit->size[i12];
  }

  emxFree_real_T(&b_CandsMerit);
  if ((iv18[0] != c_CandsMerit[0]) || (iv18[1] != c_CandsMerit[1])) {
    emlrtSizeEqCheckNDR2012b(&iv18[0], &c_CandsMerit[0], &k_emlrtECI, sp);
  }

  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof(int32_T),
                    &r_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &delta1, 2, &eb_emlrtRTEI, true);
  i12 = delta1->size[0] * delta1->size[1];
  delta1->size[0] = 4;
  delta1->size[1] = r6->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)delta1, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  ix = r6->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    for (cindx = 0; cindx < 4; cindx++) {
      delta1->data[cindx + delta1->size[0] * i12] = r6->data[cindx + r6->size[0]
        * i12] * (3.0 - CandsMerit->data[cindx + CandsMerit->size[0] *
                  (iindx->data[iindx->size[0] * i12] - 1)]);
    }
  }

  emxFree_real_T(&r6);

  /*  Interpolation of the weigthed candidates */
  /* 'spec_trk:154' [VR, Idx] = min(delta1); */
  st.site = &qd_emlrtRSI;
  b_st.site = &wg_emlrtRSI;
  c_st.site = &ag_emlrtRSI;
  unnamed_idx_1 = (uint32_T)delta1->size[1];
  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = (int32_T)unnamed_idx_1;
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i12, (int32_T)sizeof
                    (int32_T), &r_emlrtRTEI);
  ix = (int32_T)unnamed_idx_1;
  for (i12 = 0; i12 < ix; i12++) {
    iindx->data[i12] = 1;
  }

  nm1d2 = 4;
  iy = -1;
  d_st.site = &xg_emlrtRSI;
  if (1 > delta1->size[1]) {
    overflow = false;
  } else {
    overflow = (delta1->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (i = 1; i <= delta1->size[1]; i++) {
    d_st.site = &yg_emlrtRSI;
    ix = nm1d2 - 3;
    anew = delta1->data[nm1d2 - 4];
    itmp = 1;
    cindx = 1;
    if (muDoubleScalarIsNaN(delta1->data[nm1d2 - 4])) {
      e_st.site = &hf_emlrtRSI;
      if (nm1d2 - 2 > nm1d2) {
        b_nm1d2 = false;
      } else {
        b_nm1d2 = (nm1d2 > 2147483646);
      }

      if (b_nm1d2) {
        f_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      n = nm1d2 - 2;
      exitg2 = false;
      while ((!exitg2) && (n <= nm1d2)) {
        cindx++;
        ix = n;
        if (!muDoubleScalarIsNaN(delta1->data[n - 1])) {
          anew = delta1->data[n - 1];
          itmp = cindx;
          exitg2 = true;
        } else {
          n++;
        }
      }
    }

    if (ix < nm1d2) {
      e_st.site = &gf_emlrtRSI;
      if (ix + 1 > nm1d2) {
        b_ix = false;
      } else {
        b_ix = (nm1d2 > 2147483646);
      }

      if (b_ix) {
        f_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (ix + 1 <= nm1d2) {
        cindx++;
        if (delta1->data[ix] < anew) {
          anew = delta1->data[ix];
          itmp = cindx;
        }

        ix++;
      }
    }

    iy++;
    iindx->data[iy] = itmp;
    nm1d2 += 4;
  }

  emxFree_real_T(&delta1);
  i12 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  ix = iindx->size[0] * iindx->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    Signal->data[i12] = iindx->data[i12];
  }

  /* 'spec_trk:155' VPeak_minmrt  = zeros(1, length(Idx)); */
  i12 = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SHC, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  ix = Signal->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    SHC->data[i12] = 0.0;
  }

  /* 'spec_trk:156' VMerit_minmrt = zeros(1, length(Idx)); */
  i12 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VMerit_minmrt, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  ix = Signal->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    VMerit_minmrt->data[i12] = 0.0;
  }

  /* 'spec_trk:157' for n=1: length(Idx) */
  n = 1;
  emxInit_int32_T(sp, &d_iindx, 1, &r_emlrtRTEI, true);
  emxInit_int32_T(sp, &e_iindx, 1, &r_emlrtRTEI, true);
  while (n - 1 <= Signal->size[1] - 1) {
    /* 'spec_trk:158' VPeak_minmrt(n)  = VCandsPitch(Idx(n), n); */
    iy = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    i12 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof
                      (int32_T), &r_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    i12 = d_iindx->size[0];
    d_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)d_iindx, i12, (int32_T)sizeof
                      (int32_T), &r_emlrtRTEI);
    ix = iindx->size[1];
    for (i12 = 0; i12 < ix; i12++) {
      d_iindx->data[i12] = iindx->data[iindx->size[0] * i12];
    }

    i12 = Signal->size[1];
    if (!((n >= 1) && (n <= i12))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i12, &jd_emlrtBCI, sp);
    }

    i12 = (int32_T)Signal->data[n - 1];
    if (!((i12 >= 1) && (i12 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, 4, &nc_emlrtBCI, sp);
    }

    cindx = d_iindx->size[0];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &mc_emlrtBCI, sp);
    }

    cindx = n;
    itmp = SHC->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &kd_emlrtBCI, sp);
    }

    SHC->data[n - 1] = CandsPitch->data[(i12 + CandsPitch->size[0] *
      (iindx->data[iindx->size[0] * (cindx - 1)] - 1)) - 1];

    /* 'spec_trk:159' VMerit_minmrt(n) = VCandsMerit(Idx(n), n); */
    iy = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    i12 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, i12, (int32_T)sizeof
                      (int32_T), &r_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    i12 = e_iindx->size[0];
    e_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)e_iindx, i12, (int32_T)sizeof
                      (int32_T), &r_emlrtRTEI);
    ix = iindx->size[1];
    for (i12 = 0; i12 < ix; i12++) {
      e_iindx->data[i12] = iindx->data[iindx->size[0] * i12];
    }

    i12 = Signal->size[1];
    if (!((n >= 1) && (n <= i12))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i12, &ld_emlrtBCI, sp);
    }

    i12 = (int32_T)Signal->data[n - 1];
    if (!((i12 >= 1) && (i12 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, 4, &lc_emlrtBCI, sp);
    }

    cindx = e_iindx->size[0];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &kc_emlrtBCI, sp);
    }

    cindx = n;
    itmp = VMerit_minmrt->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &md_emlrtBCI, sp);
    }

    VMerit_minmrt->data[n - 1] = CandsMerit->data[(i12 + CandsMerit->size[0] *
      (iindx->data[iindx->size[0] * (cindx - 1)] - 1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&e_iindx);
  emxFree_int32_T(&d_iindx);
  emxFree_real_T(&CandsMerit);
  emxInit_real_T(sp, &c_SHC, 2, &r_emlrtRTEI, true);

  /* 'spec_trk:161' VPeak_minmrt = Mymedfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  i12 = c_SHC->size[0] * c_SHC->size[1];
  c_SHC->size[0] = 1;
  c_SHC->size[1] = SHC->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_SHC, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  ix = SHC->size[0] * SHC->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    c_SHC->data[i12] = SHC->data[i12];
  }

  st.site = &pd_emlrtRSI;
  Mymedfilt1(&st, c_SHC, SHC);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  /* 'spec_trk:165' for n=1: length(Idx) */
  n = 1;
  emxFree_real_T(&c_SHC);
  while (n - 1 <= Signal->size[1] - 1) {
    /* 'spec_trk:166' VCandsPitch(Idx(n), n) = VPeak_minmrt(n); */
    i12 = SHC->size[1];
    if (!((n >= 1) && (n <= i12))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i12, &bd_emlrtBCI, sp);
    }

    i12 = Signal->size[1];
    if (!((n >= 1) && (n <= i12))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i12, &dd_emlrtBCI, sp);
    }

    i12 = (int32_T)Signal->data[n - 1];
    if (!((i12 >= 1) && (i12 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, 4, &cd_emlrtBCI, sp);
    }

    cindx = winix->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &ed_emlrtBCI, sp);
    }

    winix->data[(i12 + winix->size[0] * (n - 1)) - 1] = SHC->data[n - 1];

    /*  Assign merit for the smoothed peaks */
    /* 'spec_trk:168' VCandsMerit(Idx(n), n) = VMerit_minmrt(n); */
    i12 = VMerit_minmrt->size[1];
    if (!((n >= 1) && (n <= i12))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i12, &fd_emlrtBCI, sp);
    }

    i12 = Signal->size[1];
    if (!((n >= 1) && (n <= i12))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i12, &hd_emlrtBCI, sp);
    }

    i12 = (int32_T)Signal->data[n - 1];
    if (!((i12 >= 1) && (i12 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, 4, &gd_emlrtBCI, sp);
    }

    cindx = rowix->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &id_emlrtBCI, sp);
    }

    rowix->data[(i12 + rowix->size[0] * (n - 1)) - 1] = VMerit_minmrt->data[n -
      1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&SHC);
  emxInit_real_T(sp, &VPitch, 2, &gb_emlrtRTEI, true);

  /*  Use dynamic programming to find best overal path among pitch candidates */
  /*  Dynamic weight for transition costs */
  /*  balance between local and transition costs */
  /* 'spec_trk:174' weight_trans = Prm.dp5_k1*std_voiced/avg_voiced; */
  /* 'spec_trk:175' VPitch = []; */
  i12 = VPitch->size[0] * VPitch->size[1];
  VPitch->size[0] = 0;
  VPitch->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)VPitch, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);

  /* 'spec_trk:176' if (Num_VCands >2) */
  if (Num_VCands > 2.0) {
    /* 'spec_trk:177' [VPitch] = dynamic5(VCandsPitch, VCandsMerit,weight_trans); */
    st.site = &od_emlrtRSI;
    dynamic5(&st, winix, rowix, 11.0 * std_voiced / avg_voiced, VMerit_minmrt);
    i12 = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)VPitch, i12, (int32_T)sizeof
                      (real_T), &r_emlrtRTEI);
    ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (i12 = 0; i12 < ix; i12++) {
      VPitch->data[i12] = VMerit_minmrt->data[i12];
    }

    /* 'spec_trk:178' VPitch = Mymedfilt1(VPitch, max(Prm.median_value-2, 1)); */
    st.site = &nd_emlrtRSI;
    b_Mymedfilt1(&st, VPitch, VMerit_minmrt);
    i12 = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)VPitch, i12, (int32_T)sizeof
                      (real_T), &r_emlrtRTEI);
    ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (i12 = 0; i12 < ix; i12++) {
      VPitch->data[i12] = VMerit_minmrt->data[i12];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else {
    /* 'spec_trk:181' else */
    /* 'spec_trk:183' if (Num_VCands > 0) */
    if (Num_VCands > 0.0) {
      /*        for i = 1:Num_VCands   % assume at least 1 voiced candidate */
      /*         VPitch (i) = 150;   %   Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates */
      /*        end;  */
      /* 'spec_trk:187' VPitch(1:Num_VCands) = 150; */
      emlrtDynamicBoundsCheckR2012b(1, 1, 0, &ic_emlrtBCI, sp);
      i12 = (int32_T)Num_VCands;
      if (!((i12 >= 1) && (i12 <= 0))) {
        emlrtDynamicBoundsCheckR2012b(i12, 1, 0, &ic_emlrtBCI, sp);
      }

      VPitch->data[0] = 150.0;

      /*    This should only occur for very short pitch tracks, and even then rarely */
    } else {
      /* 'spec_trk:189' else */
      /* 'spec_trk:190' VPitch(1) = 150; */
      emlrtDynamicBoundsCheckR2012b(1, 1, 0, &hc_emlrtBCI, sp);
      VPitch->data[0] = 150.0;

      /*  to handle when no real voiced candidates */
      /* 'spec_trk:191' Idx_voiced(1) = 1; */
      i12 = CandsPitch->size[1];
      if (!(1 <= i12)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i12, &jc_emlrtBCI, sp);
      }

      Idx_voiced->data[0] = true;
    }
  }

  emxFree_real_T(&rowix);
  emxFree_real_T(&winix);
  emxFree_real_T(&CandsPitch);

  /*  Computing some statistics from the voiced frames */
  /* 'spec_trk:198' pAvg = mean(VPitch,2); */
  st.site = &md_emlrtRSI;
  b_mean(&st, VPitch, pAvg_data, pAvg_size);

  /* 'spec_trk:199' pStd = std(VPitch,0,2); */
  st.site = &ld_emlrtRSI;
  c_std(&st, VPitch, pStd_data, pStd_size);

  /*  Streching out the smoothed pitch track */
  /* 'spec_trk:202' SPitch(Idx_voiced) = VPitch; */
  iy = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < iy; i++) {
    if (Idx_voiced->data[i]) {
      nm1d2++;
    }
  }

  i12 = VPitch->size[0] * VPitch->size[1];
  if (nm1d2 != i12) {
    emlrtSizeEqCheck1DR2012b(nm1d2, i12, &j_emlrtECI, sp);
  }

  iy = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < iy; i++) {
    if (Idx_voiced->data[i]) {
      i12 = SPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i12))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i12, &ad_emlrtBCI, sp);
      }

      SPitch->data[i] = VPitch->data[nm1d2];
      nm1d2++;
    }
  }

  emxFree_real_T(&VPitch);
  emxFree_boolean_T(&Idx_voiced);
  emxInit_boolean_T1(sp, &c_SPitch, 1, &r_emlrtRTEI, true);

  /*  Interpolating thru unvoiced frames */
  /* 'spec_trk:205' SPitch_temp_first = SPitch(1); */
  i12 = SPitch->size[1];
  if (!(1 <= i12)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i12, &gc_emlrtBCI, sp);
  }

  /* 'spec_trk:206' SPitch_temp_end = SPitch(end); */
  i12 = SPitch->size[1];
  cindx = SPitch->size[1];
  if (!((cindx >= 1) && (cindx <= i12))) {
    emlrtDynamicBoundsCheckR2012b(cindx, 1, i12, &wc_emlrtBCI, sp);
  }

  SPitch_temp_end = SPitch->data[cindx - 1];

  /* 'spec_trk:207' if all(SPitch_temp_first < (pAvg/2)) */
  b_pAvg_data.data = (real_T *)pAvg_data;
  b_pAvg_data.size = (int32_T *)pAvg_size;
  b_pAvg_data.allocatedSize = -1;
  b_pAvg_data.numDimensions = 1;
  b_pAvg_data.canFreeData = false;
  c_rdivide(sp, &b_pAvg_data, 2.0, Magnit);
  anew = SPitch->data[0];
  i12 = c_SPitch->size[0];
  c_SPitch->size[0] = Magnit->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_SPitch, i12, (int32_T)sizeof
                    (boolean_T), &r_emlrtRTEI);
  ix = Magnit->size[0];
  for (i12 = 0; i12 < ix; i12++) {
    c_SPitch->data[i12] = (anew < Magnit->data[i12]);
  }

  st.site = &kd_emlrtRSI;
  if (all(&st, c_SPitch)) {
    /* 'spec_trk:208' SPitch(1)   = pAvg; */
    i12 = pAvg_size[0];
    if (1 != i12) {
      emlrtSizeEqCheck1DR2012b(1, i12, &i_emlrtECI, sp);
    }

    i12 = SPitch->size[1];
    if (!(1 <= i12)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i12, &fc_emlrtBCI, sp);
    }

    i12 = pAvg_size[0];
    if (!(1 <= i12)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i12, &ec_emlrtBCI, sp);
    }

    SPitch->data[0] = pAvg_data[0];
  }

  emxFree_boolean_T(&c_SPitch);
  emxInit_boolean_T1(sp, &b_SPitch_temp_end, 1, &r_emlrtRTEI, true);

  /* 'spec_trk:210' if all(SPitch_temp_end < (pAvg/2)) */
  c_pAvg_data.data = (real_T *)pAvg_data;
  c_pAvg_data.size = (int32_T *)pAvg_size;
  c_pAvg_data.allocatedSize = -1;
  c_pAvg_data.numDimensions = 1;
  c_pAvg_data.canFreeData = false;
  c_rdivide(sp, &c_pAvg_data, 2.0, Magnit);
  i12 = b_SPitch_temp_end->size[0];
  b_SPitch_temp_end->size[0] = Magnit->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch_temp_end, i12, (int32_T)
                    sizeof(boolean_T), &r_emlrtRTEI);
  ix = Magnit->size[0];
  for (i12 = 0; i12 < ix; i12++) {
    b_SPitch_temp_end->data[i12] = (SPitch_temp_end < Magnit->data[i12]);
  }

  emxFree_real_T(&Magnit);
  st.site = &jd_emlrtRSI;
  if (all(&st, b_SPitch_temp_end)) {
    /* 'spec_trk:211' SPitch(end) = pAvg; */
    i12 = pAvg_size[0];
    if (1 != i12) {
      emlrtSizeEqCheck1DR2012b(1, i12, &h_emlrtECI, sp);
    }

    i12 = pAvg_size[0];
    if (!(1 <= i12)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i12, &dc_emlrtBCI, sp);
    }

    i12 = SPitch->size[1];
    cindx = SPitch->size[1];
    if (!((cindx >= 1) && (cindx <= i12))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i12, &xc_emlrtBCI, sp);
    }

    SPitch->data[cindx - 1] = pAvg_data[0];
  }

  emxFree_boolean_T(&b_SPitch_temp_end);

  /* 'spec_trk:214' [Indrows, Indcols, Vals] = find(SPitch); */
  st.site = &id_emlrtRSI;
  b_st.site = &mh_emlrtRSI;
  iy = 0;
  i12 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = SPitch->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i12, (int32_T)sizeof
                    (int32_T), &r_emlrtRTEI);
  unnamed_idx_1 = (uint32_T)SPitch->size[1];
  i12 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = (int32_T)unnamed_idx_1;
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  if (SPitch->size[1] == 0) {
    i12 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i12, (int32_T)sizeof
                      (int32_T), &r_emlrtRTEI);
    i12 = Signal->size[0] * Signal->size[1];
    Signal->size[0] = 1;
    Signal->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i12, (int32_T)sizeof
                      (real_T), &r_emlrtRTEI);
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
      emlrtErrorWithMessageIdR2012b(&b_st, &de_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (SPitch->size[1] == 1) {
      if (iy == 0) {
        i12 = iindx->size[0] * iindx->size[1];
        iindx->size[0] = 1;
        iindx->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i12, (int32_T)sizeof
                          (int32_T), &r_emlrtRTEI);
        i12 = Signal->size[0] * Signal->size[1];
        Signal->size[0] = 1;
        Signal->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i12, (int32_T)
                          sizeof(real_T), &r_emlrtRTEI);
      }
    } else {
      i12 = iindx->size[0] * iindx->size[1];
      if (1 > iy) {
        iindx->size[1] = 0;
      } else {
        iindx->size[1] = iy;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i12, (int32_T)sizeof
                        (int32_T), &s_emlrtRTEI);
      i12 = Signal->size[0] * Signal->size[1];
      if (1 > iy) {
        Signal->size[1] = 0;
      } else {
        Signal->size[1] = iy;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i12, (int32_T)sizeof
                        (real_T), &t_emlrtRTEI);
    }
  }

  /* 'spec_trk:215' SPitch = interp1(Indcols, Vals, [1:numframes], 'pchip'); */
  st.site = &hd_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
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

  d_st.site = &mc_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &td_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  i12 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, i12, (int32_T)
                    sizeof(real_T), &r_emlrtRTEI);
  if (n > 0) {
    VMerit_minmrt->data[0] = anew;
    if (n > 1) {
      VMerit_minmrt->data[n - 1] = apnd;
      i12 = n - 1;
      nm1d2 = asr_s32(i12, 1U);
      d_st.site = &nc_emlrtRSI;
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

  emxInit_real_T(&c_st, &f_iindx, 2, &r_emlrtRTEI, true);
  i12 = f_iindx->size[0] * f_iindx->size[1];
  f_iindx->size[0] = 1;
  f_iindx->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_iindx, i12, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  ix = iindx->size[0] * iindx->size[1];
  for (i12 = 0; i12 < ix; i12++) {
    f_iindx->data[i12] = iindx->data[i12];
  }

  emxFree_int32_T(&iindx);
  emxInit_real_T(sp, &d_SPitch, 2, &r_emlrtRTEI, true);
  st.site = &hd_emlrtRSI;
  interp1(&st, f_iindx, Signal, VMerit_minmrt, SPitch);

  /* 'spec_trk:217' FILTER_ORDER = 3; */
  /* 'spec_trk:218' flt_b = (ones(1,FILTER_ORDER))/FILTER_ORDER ; */
  /* 'spec_trk:219' flt_a = 1; */
  /* 'spec_trk:221' SPitch = filter(flt_b, flt_a, SPitch); */
  i12 = d_SPitch->size[0] * d_SPitch->size[1];
  d_SPitch->size[0] = 1;
  d_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_SPitch, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&f_iindx);
  emxFree_real_T(&VMerit_minmrt);
  emxFree_real_T(&Signal);
  for (i12 = 0; i12 < ix; i12++) {
    d_SPitch->data[i12] = SPitch->data[i12];
  }

  st.site = &gd_emlrtRSI;
  b_filter(&st, d_SPitch, SPitch);

  /*   above messes up  first few values of SPitch  ---  simple fix up */
  /*   Note--   this fix up should be based on above filter order */
  /* 'spec_trk:227' SPitch(1) = SPitch(3); */
  i12 = SPitch->size[1];
  if (!(1 <= i12)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i12, &bc_emlrtBCI, sp);
  }

  i12 = SPitch->size[1];
  if (!(3 <= i12)) {
    emlrtDynamicBoundsCheckR2012b(3, 1, i12, &cc_emlrtBCI, sp);
  }

  SPitch->data[0] = SPitch->data[2];

  /* 'spec_trk:228' SPitch(2) = SPitch (4); */
  i12 = SPitch->size[1];
  if (!(2 <= i12)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i12, &yb_emlrtBCI, sp);
  }

  i12 = SPitch->size[1];
  if (!(4 <= i12)) {
    emlrtDynamicBoundsCheckR2012b(4, 1, i12, &ac_emlrtBCI, sp);
  }

  SPitch->data[1] = SPitch->data[3];

  /*  Create pitch track with Voiced/Unvoiced decision */
  /* 'spec_trk:231' VUVSPitch = SPitch; */
  i12 = VUVSPitch->size[0] * VUVSPitch->size[1];
  VUVSPitch->size[0] = 1;
  VUVSPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVSPitch, i12, (int32_T)sizeof
                    (real_T), &r_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&d_SPitch);
  for (i12 = 0; i12 < ix; i12++) {
    VUVSPitch->data[i12] = SPitch->data[i12];
  }

  /* 'spec_trk:232' VUVSPitch(VUVEnergy==0) = 0; */
  iy = VUVEnergy->size[1];
  for (i = 0; i < iy; i++) {
    if (!VUVEnergy->data[i]) {
      i12 = VUVSPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i12))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i12, &yc_emlrtBCI, sp);
      }

      VUVSPitch->data[i] = 0.0;
    }
  }

  /*  SPitch = SPitch - delta; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (spec_trk.c) */
