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
static emlrtRSInfo xd_emlrtRSI = { 77, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo yd_emlrtRSI = { 81, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ae_emlrtRSI = { 82, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo be_emlrtRSI = { 88, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ce_emlrtRSI = { 90, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo de_emlrtRSI = { 94, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ee_emlrtRSI = { 96, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo fe_emlrtRSI = { 143, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ge_emlrtRSI = { 146, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo he_emlrtRSI = { 147, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ie_emlrtRSI = { 151, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo je_emlrtRSI = { 154, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ke_emlrtRSI = { 161, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo le_emlrtRSI = { 177, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo me_emlrtRSI = { 178, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ne_emlrtRSI = { 198, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo oe_emlrtRSI = { 199, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo pe_emlrtRSI = { 207, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo qe_emlrtRSI = { 210, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo re_emlrtRSI = { 214, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo se_emlrtRSI = { 215, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo te_emlrtRSI = { 221, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo oh_emlrtRSI = { 18, "min",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo ph_emlrtRSI = { 160, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo qh_emlrtRSI = { 163, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo fi_emlrtRSI = { 36, "find",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo s_emlrtRTEI = { 1, 42, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo t_emlrtRTEI = { 187, 13, "find",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo u_emlrtRTEI = { 188, 13, "find",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRTEInfo v_emlrtRTEI = { 68, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo w_emlrtRTEI = { 69, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo x_emlrtRTEI = { 77, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo y_emlrtRTEI = { 79, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ab_emlrtRTEI = { 81, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo bb_emlrtRTEI = { 82, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo cb_emlrtRTEI = { 87, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo db_emlrtRTEI = { 90, 14, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo eb_emlrtRTEI = { 140, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 151, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo gb_emlrtRTEI = { 156, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo j_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo k_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo l_emlrtDCI = { 79, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo m_emlrtDCI = { 79, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtRTEInfo fe_emlrtRTEI = { 84, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo n_emlrtDCI = { 87, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 87, 18, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo d_emlrtECI = { 2, 87, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ge_emlrtRTEI = { 93, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtECInfo e_emlrtECI = { 2, 94, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 96, 23, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo f_emlrtECI = { -1, 96, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 99, 22, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 96, 44, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo g_emlrtECI = { -1, 96, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 100, 22, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo h_emlrtECI = { 2, 151, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo r_emlrtBCI = { 1, 4, 158, 36, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 158, 44, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo t_emlrtBCI = { 1, 4, 159, 36, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 159, 44, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 191, 9, "Idx_voiced", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 187, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo o_emlrtDCI = { 187, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 190, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo i_emlrtECI = { -1, 202, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 205, 21, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 208, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo j_emlrtECI = { -1, 208, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 208, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo k_emlrtECI = { -1, 211, 5, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 211, 5, "pAvg", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 227, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 227, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 228, 13, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 228, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtRTEInfo he_emlrtRTEI = { 172, 9, "find",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 73, 1, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 74, 22, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo q_emlrtDCI = { 74, 22, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 141, 29, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 142, 28, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 206, 19, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 211, 5, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 232, 1, "VUVSPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 202, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 166, 30, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { 1, 4, 166, 17, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 166, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 166, 25, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 168, 30, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { 1, 4, 168, 17, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 168, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 168, 25, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 158, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 158, 5, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 159, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 159, 5, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 85, 9, "VUVEnergy", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 90, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo s_emlrtDCI = { 90, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 94, 31, "Magnit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo t_emlrtDCI = { 94, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 94, 13, "SHC", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo u_emlrtDCI = { 94, 13, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

/* Function Definitions */

/*
 * function[SPitch, VUVSPitch, pAvg, pStd]= spec_trk(Data, Fs, VUVEnergy, Prm)
 */
void spec_trk(yaaptStackData *SD, const emlrtStack *sp, emxArray_real_T *Data,
              real_T Fs, const emxArray_boolean_T *VUVEnergy, emxArray_real_T
              *SPitch, emxArray_real_T *VUVSPitch, emxArray_real_T *pAvg,
              emxArray_real_T *pStd)
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
  int32_T i16;
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
  int32_T b_ix;
  int32_T iv13[2];
  int32_T c_Kaiser_window[2];
  real_T dv6[8192];
  real_T k;
  int32_T b_winix[2];
  int32_T iv14[2];
  static const int32_T iv15[1] = { 4 };

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
  int32_T iv16[2];
  emxArray_real_T *b_CandsMerit;
  int32_T c_CandsMerit[2];
  emxArray_real_T *delta1;
  uint32_T outsz[2];
  boolean_T b_nm1d2;
  boolean_T exitg2;
  boolean_T c_ix;
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
  if (b_mod(window_length, 2.0) == 0.0) {
    /* 'spec_trk:55' window_length = window_length + 1; */
    window_length++;
  }

  emxInit_real_T(sp, &CandsPitch, 2, &v_emlrtRTEI, true);

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
  i16 = CandsPitch->size[0] * CandsPitch->size[1];
  CandsPitch->size[0] = 4;
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &j_emlrtDCI, sp);
  }

  if (numframes != (int32_T)muDoubleScalarFloor(numframes)) {
    emlrtIntegerCheckR2012b(numframes, &k_emlrtDCI, sp);
  }

  CandsPitch->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)CandsPitch, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &j_emlrtDCI, sp);
  }

  anew = numframes;
  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &k_emlrtDCI, sp);
  }

  ix = (int32_T)anew << 2;
  for (i16 = 0; i16 < ix; i16++) {
    CandsPitch->data[i16] = 0.0;
  }

  emxInit_real_T(sp, &CandsMerit, 2, &w_emlrtRTEI, true);

  /* 'spec_trk:69' CandsMerit = ones(maxpeaks, numframes); */
  i16 = CandsMerit->size[0] * CandsMerit->size[1];
  CandsMerit->size[0] = 4;
  CandsMerit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)CandsMerit, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  ix = (int32_T)numframes << 2;
  for (i16 = 0; i16 < ix; i16++) {
    CandsMerit->data[i16] = 1.0;
  }

  emxInit_real_T(sp, &b_Data, 2, &s_emlrtRTEI, true);

  /*  Zero paddinga */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  /* 'spec_trk:73' Data(end) = 0; */
  i16 = Data->size[1];
  cindx = Data->size[1];
  if (!((cindx >= 1) && (cindx <= i16))) {
    emlrtDynamicBoundsCheckR2012b(cindx, 1, i16, &hb_emlrtBCI, sp);
  }

  Data->data[cindx - 1] = 0.0;

  /* 'spec_trk:74' Data = [Data zeros(1,(numframes-1)*nframejump+nframesize-length(Data))]; */
  nm1d2 = Data->size[1];
  anew = ((numframes - 1.0) * nframejump + nframesize) - (real_T)nm1d2;
  if (!(anew > 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &q_emlrtDCI, sp);
  }

  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &p_emlrtDCI, sp);
  }

  nm1d2 = (int32_T)anew;
  i16 = b_Data->size[0] * b_Data->size[1];
  b_Data->size[0] = 1;
  b_Data->size[1] = Data->size[1] + nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)b_Data, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  ix = Data->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    b_Data->data[b_Data->size[0] * i16] = Data->data[Data->size[0] * i16];
  }

  for (i16 = 0; i16 < nm1d2; i16++) {
    b_Data->data[b_Data->size[0] * (i16 + Data->size[1])] = 0.0;
  }

  i16 = Data->size[0] * Data->size[1];
  Data->size[0] = 1;
  Data->size[1] = b_Data->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Data, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  ix = b_Data->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    Data->data[Data->size[0] * i16] = b_Data->data[b_Data->size[0] * i16];
  }

  emxFree_real_T(&b_Data);
  emxInit_real_T(sp, &Kaiser_window, 2, &x_emlrtRTEI, true);
  emxInit_real_T(sp, &SHC, 2, &y_emlrtRTEI, true);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Compute SHC for voiced frame */
  /* 'spec_trk:77' Kaiser_window = Mykaiser(nframesize); */
  st.site = &xd_emlrtRSI;
  Mykaiser(&st, nframesize, Kaiser_window);

  /*  Kaiser_window_test = kaiser(nframesize); */
  /* 'spec_trk:79' SHC = zeros(1,max_SHC); */
  i16 = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  if (!(max_SHC > 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &l_emlrtDCI, sp);
  }

  if (max_SHC != (int32_T)muDoubleScalarFloor(max_SHC)) {
    emlrtIntegerCheckR2012b(max_SHC, &m_emlrtDCI, sp);
  }

  SHC->size[1] = (int32_T)max_SHC;
  emxEnsureCapacity(sp, (emxArray__common *)SHC, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  if (!(max_SHC > 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &l_emlrtDCI, sp);
  }

  anew = max_SHC;
  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &m_emlrtDCI, sp);
  }

  ix = (int32_T)anew;
  for (i16 = 0; i16 < ix; i16++) {
    SHC->data[i16] = 0.0;
  }

  /* 'spec_trk:81' winix = repmat([1:window_length], numharmonics+1,1); */
  st.site = &yd_emlrtRSI;
  b_st.site = &bd_emlrtRSI;
  c_st.site = &cd_emlrtRSI;
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

  d_st.site = &dd_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &xd_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &VMerit_minmrt, 2, &gb_emlrtRTEI, true);
  i16 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  if (!(n > 0)) {
    emlrtNonNegativeCheckR2012b(n, &f_emlrtDCI, &c_st);
  }

  VMerit_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, i16, (int32_T)
                    sizeof(real_T), &s_emlrtRTEI);
  if (n > 0) {
    VMerit_minmrt->data[0] = anew;
    if (n > 1) {
      VMerit_minmrt->data[n - 1] = apnd;
      i16 = n - 1;
      nm1d2 = asr_s32(i16, 1U);
      d_st.site = &ed_emlrtRSI;
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

  emxInit_real_T(&c_st, &winix, 2, &ab_emlrtRTEI, true);
  emxInit_real_T(&c_st, &rowix, 2, &bb_emlrtRTEI, true);
  st.site = &yd_emlrtRSI;
  repmat(&st, VMerit_minmrt, winix);

  /* 'spec_trk:82' rowix = repmat([1:numharmonics+1]', 1, window_length); */
  st.site = &ae_emlrtRSI;
  b_repmat(&st, window_length, rowix);

  /* 'spec_trk:84' for frame = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &fe_emlrtRTEI, sp);
  frame = 0;
  emxInit_real_T(sp, &Signal, 2, &cb_emlrtRTEI, true);
  emxInit_real_T1(sp, &Magnit, 1, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &r6, 2, &s_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SHC, 2, &s_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Magnit, 2, &s_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Kaiser_window, 2, &s_emlrtRTEI, true);
  while (frame <= (int32_T)numframes - 1) {
    /* 'spec_trk:85' if (VUVEnergy(frame) > 0) */
    i16 = VUVEnergy->size[1];
    if (!((frame + 1 >= 1) && (frame + 1 <= i16))) {
      emlrtDynamicBoundsCheckR2012b(frame + 1, 1, i16, &bc_emlrtBCI, sp);
    }

    if ((int32_T)VUVEnergy->data[frame] > 0) {
      /* 'spec_trk:86' firstp = 1+(frame-1)*(nframejump); */
      firstp = 1.0 + ((1.0 + (real_T)frame) - 1.0) * nframejump;

      /* 'spec_trk:87' Signal = Data(firstp:firstp+nframesize-1) .* Kaiser_window'; */
      anew = (firstp + nframesize) - 1.0;
      if (firstp > anew) {
        cindx = 1;
        i16 = 1;
      } else {
        if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
          emlrtIntegerCheckR2012b(firstp, &n_emlrtDCI, sp);
        }

        i16 = Data->size[1];
        cindx = (int32_T)firstp;
        if (!((cindx >= 1) && (cindx <= i16))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, i16, &m_emlrtBCI, sp);
        }

        if (anew != (int32_T)muDoubleScalarFloor(anew)) {
          emlrtIntegerCheckR2012b(anew, &n_emlrtDCI, sp);
        }

        i16 = Data->size[1];
        b_ix = (int32_T)anew;
        if (!((b_ix >= 1) && (b_ix <= i16))) {
          emlrtDynamicBoundsCheckR2012b(b_ix, 1, i16, &m_emlrtBCI, sp);
        }

        i16 = b_ix + 1;
      }

      iv13[0] = 1;
      iv13[1] = i16 - cindx;
      b_ix = b_Kaiser_window->size[0] * b_Kaiser_window->size[1];
      b_Kaiser_window->size[0] = Kaiser_window->size[1];
      b_Kaiser_window->size[1] = Kaiser_window->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_Kaiser_window, b_ix, (int32_T)
                        sizeof(real_T), &s_emlrtRTEI);
      ix = Kaiser_window->size[0];
      for (b_ix = 0; b_ix < ix; b_ix++) {
        nm1d2 = Kaiser_window->size[1];
        for (iy = 0; iy < nm1d2; iy++) {
          b_Kaiser_window->data[iy + b_Kaiser_window->size[0] * b_ix] =
            Kaiser_window->data[b_ix + Kaiser_window->size[0] * iy];
        }
      }

      for (b_ix = 0; b_ix < 2; b_ix++) {
        c_Kaiser_window[b_ix] = b_Kaiser_window->size[b_ix];
      }

      if ((iv13[0] != c_Kaiser_window[0]) || (iv13[1] != c_Kaiser_window[1])) {
        emlrtSizeEqCheckNDR2012b(&iv13[0], &c_Kaiser_window[0], &d_emlrtECI, sp);
      }

      b_ix = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      Signal->size[1] = i16 - cindx;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, b_ix, (int32_T)sizeof
                        (real_T), &s_emlrtRTEI);
      ix = i16 - cindx;
      for (i16 = 0; i16 < ix; i16++) {
        Signal->data[Signal->size[0] * i16] = Data->data[(cindx + i16) - 1] *
          Kaiser_window->data[i16];
      }

      /* 'spec_trk:88' Signal = Signal - mean(Signal); */
      st.site = &be_emlrtRSI;
      anew = mean(&st, Signal);
      i16 = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, i16, (int32_T)sizeof
                        (real_T), &s_emlrtRTEI);
      ix = Signal->size[1];
      for (i16 = 0; i16 < ix; i16++) {
        Signal->data[Signal->size[0] * i16] -= anew;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      /* 'spec_trk:90' Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))']; */
      st.site = &ce_emlrtRSI;
      b_fft(&st, Signal, SD->u1.f0.dcv0);
      b_abs(SD->u1.f0.dcv0, dv6);
      i16 = Magnit->size[0];
      if (!(half_winlen > 0.0)) {
        emlrtNonNegativeCheckR2012b(half_winlen, &s_emlrtDCI, sp);
      }

      anew = half_winlen;
      if (anew != (int32_T)muDoubleScalarFloor(anew)) {
        emlrtIntegerCheckR2012b(anew, &r_emlrtDCI, sp);
      }

      Magnit->size[0] = (int32_T)anew + 8192;
      emxEnsureCapacity(sp, (emxArray__common *)Magnit, i16, (int32_T)sizeof
                        (real_T), &s_emlrtRTEI);
      if (!(half_winlen > 0.0)) {
        emlrtNonNegativeCheckR2012b(half_winlen, &s_emlrtDCI, sp);
      }

      if (anew != (int32_T)muDoubleScalarFloor(anew)) {
        emlrtIntegerCheckR2012b(anew, &r_emlrtDCI, sp);
      }

      ix = (int32_T)anew;
      for (i16 = 0; i16 < ix; i16++) {
        Magnit->data[i16] = 0.0;
      }

      for (i16 = 0; i16 < 8192; i16++) {
        if (!(half_winlen > 0.0)) {
          emlrtNonNegativeCheckR2012b(half_winlen, &s_emlrtDCI, sp);
        }

        if (anew != (int32_T)muDoubleScalarFloor(anew)) {
          emlrtIntegerCheckR2012b(anew, &r_emlrtDCI, sp);
        }

        Magnit->data[i16 + (int32_T)anew] = dv6[i16];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      /* 'spec_trk:93' for k=min_SHC:max_SHC */
      i16 = (int32_T)(max_SHC + (1.0 - min_SHC));
      emlrtForLoopVectorCheckR2012b(min_SHC, 1.0, max_SHC, mxDOUBLE_CLASS, i16,
        &ge_emlrtRTEI, sp);
      iy = 0;
      while (iy <= i16 - 1) {
        k = min_SHC + (real_T)iy;

        /* 'spec_trk:94' SHC(k) = sum(prod(Magnit( winix + k*rowix ))); */
        cindx = r6->size[0] * r6->size[1];
        r6->size[0] = 4;
        r6->size[1] = rowix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)r6, cindx, (int32_T)sizeof
                          (real_T), &s_emlrtRTEI);
        ix = rowix->size[0] * rowix->size[1];
        for (cindx = 0; cindx < ix; cindx++) {
          r6->data[cindx] = k * rowix->data[cindx];
        }

        for (cindx = 0; cindx < 2; cindx++) {
          b_winix[cindx] = winix->size[cindx];
        }

        for (cindx = 0; cindx < 2; cindx++) {
          iv14[cindx] = r6->size[cindx];
        }

        if ((b_winix[0] != iv14[0]) || (b_winix[1] != iv14[1])) {
          emlrtSizeEqCheckNDR2012b(&b_winix[0], &iv14[0], &e_emlrtECI, sp);
        }

        st.site = &de_emlrtRSI;
        b_indexShapeCheck(&st, Magnit->size[0], *(int32_T (*)[2])winix->size);
        cindx = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = 4;
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)b_Magnit, cindx, (int32_T)
                          sizeof(real_T), &s_emlrtRTEI);
        nm1d2 = Magnit->size[0];
        ix = winix->size[0] * winix->size[1];
        for (cindx = 0; cindx < ix; cindx++) {
          anew = winix->data[cindx] + r6->data[cindx];
          if (anew != (int32_T)muDoubleScalarFloor(anew)) {
            emlrtIntegerCheckR2012b(anew, &t_emlrtDCI, sp);
          }

          b_ix = (int32_T)anew;
          if (!((b_ix >= 1) && (b_ix <= nm1d2))) {
            emlrtDynamicBoundsCheckR2012b(b_ix, 1, nm1d2, &cc_emlrtBCI, sp);
          }

          b_Magnit->data[cindx] = Magnit->data[b_ix - 1];
        }

        st.site = &de_emlrtRSI;
        prod(&st, b_Magnit, VMerit_minmrt);
        cindx = SHC->size[1];
        if (k != (int32_T)k) {
          emlrtIntegerCheckR2012b(k, &u_emlrtDCI, sp);
        }

        b_ix = (int32_T)k;
        if (!((b_ix >= 1) && (b_ix <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(b_ix, 1, cindx, &dc_emlrtBCI, sp);
        }

        st.site = &de_emlrtRSI;
        SHC->data[b_ix - 1] = sum(&st, VMerit_minmrt);
        iy++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* 'spec_trk:96' [CandsPitch(:,frame), CandsMerit(:,frame)]=peaks(SHC,delta, maxpeaks, Prm); */
      i16 = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_SHC, i16, (int32_T)sizeof
                        (real_T), &s_emlrtRTEI);
      ix = SHC->size[0] * SHC->size[1];
      for (i16 = 0; i16 < ix; i16++) {
        b_SHC->data[i16] = SHC->data[i16];
      }

      st.site = &ee_emlrtRSI;
      peaks(&st, b_SHC, delta, VMerit_minmrt, Signal);
      i16 = CandsPitch->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i16))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i16, &n_emlrtBCI, sp);
      }

      emlrtSubAssignSizeCheckR2012b(iv15, 1, *(int32_T (*)[2])
        VMerit_minmrt->size, 2, &f_emlrtECI, sp);
      for (i16 = 0; i16 < 4; i16++) {
        CandsPitch->data[i16 + CandsPitch->size[0] * frame] =
          VMerit_minmrt->data[i16];
      }

      i16 = CandsMerit->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i16))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i16, &p_emlrtBCI, sp);
      }

      emlrtSubAssignSizeCheckR2012b(iv15, 1, *(int32_T (*)[2])Signal->size, 2,
        &g_emlrtECI, sp);
      for (i16 = 0; i16 < 4; i16++) {
        CandsMerit->data[i16 + CandsMerit->size[0] * frame] = Signal->data[i16];
      }
    } else {
      /* 'spec_trk:97' else */
      /*  if energy is low,  let frame be considered as unvoiced */
      /* 'spec_trk:99' CandsPitch(:,frame) = zeros(1,maxpeaks); */
      nm1d2 = CandsPitch->size[1];
      if (!((frame + 1 >= 1) && (frame + 1 <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(frame + 1, 1, nm1d2, &o_emlrtBCI, sp);
      }

      for (i16 = 0; i16 < 4; i16++) {
        CandsPitch->data[i16 + CandsPitch->size[0] * frame] = 0.0;
      }

      /* 'spec_trk:100' CandsMerit(:,frame) = ones(1, maxpeaks); */
      nm1d2 = CandsMerit->size[1];
      if (!((frame + 1 >= 1) && (frame + 1 <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(frame + 1, 1, nm1d2, &q_emlrtBCI, sp);
      }

      for (i16 = 0; i16 < 4; i16++) {
        CandsMerit->data[i16 + CandsMerit->size[0] * frame] = 1.0;
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
  i16 = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = ix;
  emxEnsureCapacity(sp, (emxArray__common *)SPitch, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  for (i16 = 0; i16 < ix; i16++) {
    SPitch->data[SPitch->size[0] * i16] = CandsPitch->data[CandsPitch->size[0] *
      i16];
  }

  emxInit_boolean_T(sp, &Idx_voiced, 2, &eb_emlrtRTEI, true);

  /* 'spec_trk:140' Idx_voiced = SPitch > 0; */
  i16 = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Idx_voiced, i16, (int32_T)sizeof
                    (boolean_T), &s_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    Idx_voiced->data[i16] = (SPitch->data[i16] > 0.0);
  }

  emxInit_int32_T1(sp, &iindx, 2, &s_emlrtRTEI, true);

  /* 'spec_trk:141' VCandsPitch  = CandsPitch(:,Idx_voiced); */
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof(int32_T),
                    &s_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  nm1d2 = CandsPitch->size[1];
  i16 = winix->size[0] * winix->size[1];
  winix->size[0] = 4;
  winix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)winix, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  ix = iindx->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    for (cindx = 0; cindx < 4; cindx++) {
      b_ix = iindx->data[iindx->size[0] * i16];
      if (!((b_ix >= 1) && (b_ix <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(b_ix, 1, nm1d2, &ib_emlrtBCI, sp);
      }

      winix->data[cindx + winix->size[0] * i16] = CandsPitch->data[cindx +
        CandsPitch->size[0] * (b_ix - 1)];
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

  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof(int32_T),
                    &s_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  nm1d2 = CandsMerit->size[1];
  i16 = rowix->size[0] * rowix->size[1];
  rowix->size[0] = 4;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowix, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  ix = iindx->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    for (cindx = 0; cindx < 4; cindx++) {
      b_ix = iindx->data[iindx->size[0] * i16];
      if (!((b_ix >= 1) && (b_ix <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(b_ix, 1, nm1d2, &jb_emlrtBCI, sp);
      }

      rowix->data[cindx + rowix->size[0] * i16] = CandsMerit->data[cindx +
        CandsMerit->size[0] * (b_ix - 1)];
    }
  }

  emxInit_boolean_T(sp, &b_SPitch, 2, &s_emlrtRTEI, true);

  /* 'spec_trk:143' Num_VCands = sum(Idx_voiced); */
  i16 = b_SPitch->size[0] * b_SPitch->size[1];
  b_SPitch->size[0] = 1;
  b_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i16, (int32_T)sizeof
                    (boolean_T), &s_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    b_SPitch->data[i16] = (SPitch->data[i16] > 0.0);
  }

  st.site = &fe_emlrtRSI;
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

  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof(int32_T),
                    &s_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &b_CandsPitch, 2, &s_emlrtRTEI, true);
  emxInit_int32_T(sp, &b_iindx, 1, &s_emlrtRTEI, true);
  i16 = b_iindx->size[0];
  b_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_iindx, i16, (int32_T)sizeof
                    (int32_T), &s_emlrtRTEI);
  ix = iindx->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    b_iindx->data[i16] = iindx->data[iindx->size[0] * i16];
  }

  emxInit_real_T(sp, &c_CandsPitch, 2, &s_emlrtRTEI, true);
  ix = b_iindx->size[0];
  i16 = c_CandsPitch->size[0] * c_CandsPitch->size[1];
  c_CandsPitch->size[0] = 4;
  c_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_CandsPitch, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&b_iindx);
  for (i16 = 0; i16 < nm1d2; i16++) {
    for (cindx = 0; cindx < 4; cindx++) {
      c_CandsPitch->data[cindx + c_CandsPitch->size[0] * i16] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i16] -
        1)];
    }
  }

  i16 = b_CandsPitch->size[0] * b_CandsPitch->size[1];
  b_CandsPitch->size[0] = 1;
  b_CandsPitch->size[1] = ix;
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsPitch, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  for (i16 = 0; i16 < ix; i16++) {
    b_CandsPitch->data[b_CandsPitch->size[0] * i16] = c_CandsPitch->
      data[c_CandsPitch->size[0] * i16];
  }

  emxFree_real_T(&c_CandsPitch);
  st.site = &ge_emlrtRSI;
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

  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof(int32_T),
                    &s_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &d_CandsPitch, 2, &s_emlrtRTEI, true);
  emxInit_int32_T(sp, &c_iindx, 1, &s_emlrtRTEI, true);
  i16 = c_iindx->size[0];
  c_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_iindx, i16, (int32_T)sizeof
                    (int32_T), &s_emlrtRTEI);
  ix = iindx->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    c_iindx->data[i16] = iindx->data[iindx->size[0] * i16];
  }

  emxInit_real_T(sp, &e_CandsPitch, 2, &s_emlrtRTEI, true);
  ix = c_iindx->size[0];
  i16 = e_CandsPitch->size[0] * e_CandsPitch->size[1];
  e_CandsPitch->size[0] = 4;
  e_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)e_CandsPitch, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&c_iindx);
  for (i16 = 0; i16 < nm1d2; i16++) {
    for (cindx = 0; cindx < 4; cindx++) {
      e_CandsPitch->data[cindx + e_CandsPitch->size[0] * i16] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i16] -
        1)];
    }
  }

  i16 = d_CandsPitch->size[0] * d_CandsPitch->size[1];
  d_CandsPitch->size[0] = 1;
  d_CandsPitch->size[1] = ix;
  emxEnsureCapacity(sp, (emxArray__common *)d_CandsPitch, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  for (i16 = 0; i16 < ix; i16++) {
    d_CandsPitch->data[d_CandsPitch->size[0] * i16] = e_CandsPitch->
      data[e_CandsPitch->size[0] * i16];
  }

  emxFree_real_T(&e_CandsPitch);
  st.site = &he_emlrtRSI;
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

  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof(int32_T),
                    &s_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &f_CandsPitch, 2, &s_emlrtRTEI, true);
  anew = 0.8 * avg_voiced;
  i16 = f_CandsPitch->size[0] * f_CandsPitch->size[1];
  f_CandsPitch->size[0] = 4;
  f_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_CandsPitch, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  ix = iindx->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    for (cindx = 0; cindx < 4; cindx++) {
      f_CandsPitch->data[cindx + f_CandsPitch->size[0] * i16] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i16] -
        1)] - anew;
    }
  }

  st.site = &ie_emlrtRSI;
  c_abs(&st, f_CandsPitch, r6);
  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&f_CandsPitch);
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof(int32_T),
                    &s_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  for (i16 = 0; i16 < 2; i16++) {
    iv16[i16] = r6->size[i16];
  }

  emxInit_real_T(sp, &b_CandsMerit, 2, &s_emlrtRTEI, true);
  i16 = b_CandsMerit->size[0] * b_CandsMerit->size[1];
  b_CandsMerit->size[0] = 4;
  b_CandsMerit->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsMerit, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  ix = iindx->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    for (cindx = 0; cindx < 4; cindx++) {
      b_CandsMerit->data[cindx + b_CandsMerit->size[0] * i16] = CandsMerit->
        data[cindx + CandsMerit->size[0] * (iindx->data[iindx->size[0] * i16] -
        1)];
    }
  }

  for (i16 = 0; i16 < 2; i16++) {
    c_CandsMerit[i16] = b_CandsMerit->size[i16];
  }

  emxFree_real_T(&b_CandsMerit);
  if ((iv16[0] != c_CandsMerit[0]) || (iv16[1] != c_CandsMerit[1])) {
    emlrtSizeEqCheckNDR2012b(&iv16[0], &c_CandsMerit[0], &h_emlrtECI, sp);
  }

  iy = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof(int32_T),
                    &s_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= iy; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &delta1, 2, &fb_emlrtRTEI, true);
  i16 = delta1->size[0] * delta1->size[1];
  delta1->size[0] = 4;
  delta1->size[1] = r6->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)delta1, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  ix = r6->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    for (cindx = 0; cindx < 4; cindx++) {
      delta1->data[cindx + delta1->size[0] * i16] = r6->data[cindx + r6->size[0]
        * i16] * (3.0 - CandsMerit->data[cindx + CandsMerit->size[0] *
                  (iindx->data[iindx->size[0] * i16] - 1)]);
    }
  }

  emxFree_real_T(&r6);

  /*  Interpolation of the weigthed candidates */
  /* 'spec_trk:154' [VR, Idx] = min(delta1); */
  st.site = &je_emlrtRSI;
  b_st.site = &oh_emlrtRSI;
  c_st.site = &qg_emlrtRSI;
  for (i16 = 0; i16 < 2; i16++) {
    outsz[i16] = (uint32_T)delta1->size[i16];
  }

  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i16, (int32_T)sizeof
                    (int32_T), &s_emlrtRTEI);
  ix = (int32_T)outsz[1];
  for (i16 = 0; i16 < ix; i16++) {
    iindx->data[i16] = 1;
  }

  nm1d2 = 4;
  iy = -1;
  d_st.site = &ph_emlrtRSI;
  if (1 > delta1->size[1]) {
    overflow = false;
  } else {
    overflow = (delta1->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&e_st, true);
  }

  for (i = 1; i <= delta1->size[1]; i++) {
    d_st.site = &qh_emlrtRSI;
    ix = nm1d2 - 3;
    anew = delta1->data[nm1d2 - 4];
    n = 1;
    cindx = 1;
    if (muDoubleScalarIsNaN(delta1->data[nm1d2 - 4])) {
      e_st.site = &gb_emlrtRSI;
      if (nm1d2 - 2 > nm1d2) {
        b_nm1d2 = false;
      } else {
        b_nm1d2 = (nm1d2 > 2147483646);
      }

      if (b_nm1d2) {
        f_st.site = &ib_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      b_ix = nm1d2 - 2;
      exitg2 = false;
      while ((!exitg2) && (b_ix <= nm1d2)) {
        cindx++;
        ix = b_ix;
        if (!muDoubleScalarIsNaN(delta1->data[b_ix - 1])) {
          anew = delta1->data[b_ix - 1];
          n = cindx;
          exitg2 = true;
        } else {
          b_ix++;
        }
      }
    }

    if (ix < nm1d2) {
      e_st.site = &hb_emlrtRSI;
      if (ix + 1 > nm1d2) {
        c_ix = false;
      } else {
        c_ix = (nm1d2 > 2147483646);
      }

      if (c_ix) {
        f_st.site = &ib_emlrtRSI;
        check_forloop_overflow_error(&f_st, true);
      }

      while (ix + 1 <= nm1d2) {
        cindx++;
        if (delta1->data[ix] < anew) {
          anew = delta1->data[ix];
          n = cindx;
        }

        ix++;
      }
    }

    iy++;
    iindx->data[iy] = n;
    nm1d2 += 4;
  }

  emxFree_real_T(&delta1);
  i16 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  ix = iindx->size[0] * iindx->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    Signal->data[i16] = iindx->data[i16];
  }

  /* 'spec_trk:155' VPeak_minmrt  = zeros(1, length(Idx)); */
  i16 = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SHC, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  ix = Signal->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    SHC->data[i16] = 0.0;
  }

  /* 'spec_trk:156' VMerit_minmrt = zeros(1, length(Idx)); */
  i16 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  VMerit_minmrt->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VMerit_minmrt, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  ix = Signal->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    VMerit_minmrt->data[i16] = 0.0;
  }

  /* 'spec_trk:157' for n=1: length(Idx) */
  n = 1;
  emxInit_int32_T(sp, &d_iindx, 1, &s_emlrtRTEI, true);
  emxInit_int32_T(sp, &e_iindx, 1, &s_emlrtRTEI, true);
  while (n - 1 <= Signal->size[1] - 1) {
    /* 'spec_trk:158' VPeak_minmrt(n)  = VCandsPitch(Idx(n), n); */
    iy = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    i16 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof
                      (int32_T), &s_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    i16 = d_iindx->size[0];
    d_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)d_iindx, i16, (int32_T)sizeof
                      (int32_T), &s_emlrtRTEI);
    ix = iindx->size[1];
    for (i16 = 0; i16 < ix; i16++) {
      d_iindx->data[i16] = iindx->data[iindx->size[0] * i16];
    }

    i16 = Signal->size[1];
    if (!((n >= 1) && (n <= i16))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i16, &wb_emlrtBCI, sp);
    }

    i16 = (int32_T)Signal->data[n - 1];
    if (!((i16 >= 1) && (i16 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i16, 1, 4, &r_emlrtBCI, sp);
    }

    cindx = d_iindx->size[0];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &s_emlrtBCI, sp);
    }

    cindx = n;
    b_ix = SHC->size[1];
    if (!((n >= 1) && (n <= b_ix))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, b_ix, &xb_emlrtBCI, sp);
    }

    SHC->data[n - 1] = CandsPitch->data[(i16 + CandsPitch->size[0] *
      (iindx->data[iindx->size[0] * (cindx - 1)] - 1)) - 1];

    /* 'spec_trk:159' VMerit_minmrt(n) = VCandsMerit(Idx(n), n); */
    iy = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    i16 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof
                      (int32_T), &s_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= iy; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    i16 = e_iindx->size[0];
    e_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)e_iindx, i16, (int32_T)sizeof
                      (int32_T), &s_emlrtRTEI);
    ix = iindx->size[1];
    for (i16 = 0; i16 < ix; i16++) {
      e_iindx->data[i16] = iindx->data[iindx->size[0] * i16];
    }

    i16 = Signal->size[1];
    if (!((n >= 1) && (n <= i16))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i16, &yb_emlrtBCI, sp);
    }

    i16 = (int32_T)Signal->data[n - 1];
    if (!((i16 >= 1) && (i16 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i16, 1, 4, &t_emlrtBCI, sp);
    }

    cindx = e_iindx->size[0];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &u_emlrtBCI, sp);
    }

    cindx = n;
    b_ix = VMerit_minmrt->size[1];
    if (!((n >= 1) && (n <= b_ix))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, b_ix, &ac_emlrtBCI, sp);
    }

    VMerit_minmrt->data[n - 1] = CandsMerit->data[(i16 + CandsMerit->size[0] *
      (iindx->data[iindx->size[0] * (cindx - 1)] - 1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&e_iindx);
  emxFree_int32_T(&d_iindx);
  emxFree_real_T(&CandsMerit);
  emxInit_real_T(sp, &c_SHC, 2, &s_emlrtRTEI, true);

  /* 'spec_trk:161' VPeak_minmrt = Mymedfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  i16 = c_SHC->size[0] * c_SHC->size[1];
  c_SHC->size[0] = 1;
  c_SHC->size[1] = SHC->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_SHC, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  ix = SHC->size[0] * SHC->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    c_SHC->data[i16] = SHC->data[i16];
  }

  st.site = &ke_emlrtRSI;
  Mymedfilt1(&st, c_SHC, SHC);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above */
  /* 'spec_trk:165' for n=1: length(Idx) */
  n = 1;
  emxFree_real_T(&c_SHC);
  while (n - 1 <= Signal->size[1] - 1) {
    /* 'spec_trk:166' VCandsPitch(Idx(n), n) = VPeak_minmrt(n); */
    i16 = SHC->size[1];
    if (!((n >= 1) && (n <= i16))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i16, &ob_emlrtBCI, sp);
    }

    i16 = Signal->size[1];
    if (!((n >= 1) && (n <= i16))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i16, &qb_emlrtBCI, sp);
    }

    i16 = (int32_T)Signal->data[n - 1];
    if (!((i16 >= 1) && (i16 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i16, 1, 4, &pb_emlrtBCI, sp);
    }

    cindx = winix->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &rb_emlrtBCI, sp);
    }

    winix->data[(i16 + winix->size[0] * (n - 1)) - 1] = SHC->data[n - 1];

    /*  Assign merit for the smoothed peaks */
    /* 'spec_trk:168' VCandsMerit(Idx(n), n) = VMerit_minmrt(n); */
    i16 = VMerit_minmrt->size[1];
    if (!((n >= 1) && (n <= i16))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i16, &sb_emlrtBCI, sp);
    }

    i16 = Signal->size[1];
    if (!((n >= 1) && (n <= i16))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i16, &ub_emlrtBCI, sp);
    }

    i16 = (int32_T)Signal->data[n - 1];
    if (!((i16 >= 1) && (i16 <= 4))) {
      emlrtDynamicBoundsCheckR2012b(i16, 1, 4, &tb_emlrtBCI, sp);
    }

    cindx = rowix->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &vb_emlrtBCI, sp);
    }

    rowix->data[(i16 + rowix->size[0] * (n - 1)) - 1] = VMerit_minmrt->data[n -
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
  /* 'spec_trk:174' weight_trans = Prm.dp5_k1*std_voiced/avg_voiced; */
  /* 'spec_trk:175' VPitch = []; */
  i16 = Kaiser_window->size[0] * Kaiser_window->size[1];
  Kaiser_window->size[0] = 0;
  Kaiser_window->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);

  /* 'spec_trk:176' if (Num_VCands >2) */
  if (Num_VCands > 2.0) {
    /* 'spec_trk:177' [VPitch] = dynamic5(VCandsPitch, VCandsMerit,weight_trans); */
    st.site = &le_emlrtRSI;
    dynamic5(&st, winix, rowix, 11.0 * std_voiced / avg_voiced, VMerit_minmrt);
    i16 = Kaiser_window->size[0] * Kaiser_window->size[1];
    Kaiser_window->size[0] = 1;
    Kaiser_window->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, i16, (int32_T)
                      sizeof(real_T), &s_emlrtRTEI);
    ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (i16 = 0; i16 < ix; i16++) {
      Kaiser_window->data[i16] = VMerit_minmrt->data[i16];
    }

    /* 'spec_trk:178' VPitch = Mymedfilt1(VPitch, max(Prm.median_value-2, 1)); */
    st.site = &me_emlrtRSI;
    b_Mymedfilt1(&st, Kaiser_window, VMerit_minmrt);
    i16 = Kaiser_window->size[0] * Kaiser_window->size[1];
    Kaiser_window->size[0] = 1;
    Kaiser_window->size[1] = VMerit_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)Kaiser_window, i16, (int32_T)
                      sizeof(real_T), &s_emlrtRTEI);
    ix = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
    for (i16 = 0; i16 < ix; i16++) {
      Kaiser_window->data[i16] = VMerit_minmrt->data[i16];
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
      if (1.0 > Num_VCands) {
        ix = -1;
      } else {
        emlrtDynamicBoundsCheckR2012b(1, 1, 0, &w_emlrtBCI, sp);
        if (Num_VCands != muDoubleScalarFloor(Num_VCands)) {
          emlrtIntegerCheckR2012b(Num_VCands, &o_emlrtDCI, sp);
        }

        i16 = (int32_T)Num_VCands;
        emlrtDynamicBoundsCheckR2012b(i16, 1, 0, &w_emlrtBCI, sp);
        ix = 0;
      }

      i16 = iindx->size[0] * iindx->size[1];
      iindx->size[0] = 1;
      iindx->size[1] = ix + 1;
      emxEnsureCapacity(sp, (emxArray__common *)iindx, i16, (int32_T)sizeof
                        (int32_T), &s_emlrtRTEI);
      for (i16 = 0; i16 <= ix; i16++) {
        iindx->data[iindx->size[0] * i16] = i16;
      }

      ix = iindx->size[0] * iindx->size[1];
      for (i16 = 0; i16 < ix; i16++) {
        Kaiser_window->data[iindx->data[i16]] = 150.0;
      }

      /*    This should only occur for very short pitch tracks, and even then rarely */
    } else {
      /* 'spec_trk:189' else */
      /* 'spec_trk:190' VPitch(1) = 150; */
      emlrtDynamicBoundsCheckR2012b(1, 1, 0, &x_emlrtBCI, sp);
      Kaiser_window->data[0] = 150.0;

      /*  to handle when no real voiced candidates */
      /* 'spec_trk:191' Idx_voiced(1) = 1; */
      i16 = CandsPitch->size[1];
      if (!(1 <= i16)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i16, &v_emlrtBCI, sp);
      }

      Idx_voiced->data[0] = true;
    }
  }

  emxFree_real_T(&rowix);
  emxFree_real_T(&winix);
  emxFree_real_T(&CandsPitch);

  /*  Computing some statistics from the voiced frames */
  /* 'spec_trk:198' pAvg = mean(VPitch,2); */
  st.site = &ne_emlrtRSI;
  b_mean(&st, Kaiser_window, pAvg);

  /* 'spec_trk:199' pStd = std(VPitch,0,2); */
  st.site = &oe_emlrtRSI;
  c_std(&st, Kaiser_window, pStd);

  /*  Streching out the smoothed pitch track */
  /* 'spec_trk:202' SPitch(Idx_voiced) = VPitch; */
  iy = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < iy; i++) {
    if (Idx_voiced->data[i]) {
      nm1d2++;
    }
  }

  i16 = Kaiser_window->size[0] * Kaiser_window->size[1];
  if (nm1d2 != i16) {
    emlrtSizeEqCheck1DR2012b(nm1d2, i16, &i_emlrtECI, sp);
  }

  iy = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < iy; i++) {
    if (Idx_voiced->data[i]) {
      i16 = SPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i16, &nb_emlrtBCI, sp);
      }

      SPitch->data[i] = Kaiser_window->data[nm1d2];
      nm1d2++;
    }
  }

  emxFree_boolean_T(&Idx_voiced);
  emxFree_real_T(&Kaiser_window);
  emxInit_boolean_T1(sp, &c_SPitch, 1, &s_emlrtRTEI, true);

  /*  Interpolating thru unvoiced frames */
  /* 'spec_trk:205' SPitch_temp_first = SPitch(1); */
  i16 = SPitch->size[1];
  if (!(1 <= i16)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i16, &y_emlrtBCI, sp);
  }

  /* 'spec_trk:206' SPitch_temp_end = SPitch(end); */
  i16 = SPitch->size[1];
  cindx = SPitch->size[1];
  if (!((cindx >= 1) && (cindx <= i16))) {
    emlrtDynamicBoundsCheckR2012b(cindx, 1, i16, &kb_emlrtBCI, sp);
  }

  SPitch_temp_end = SPitch->data[cindx - 1];

  /* 'spec_trk:207' if all(SPitch_temp_first < (pAvg/2)) */
  b_rdivide(sp, pAvg, 2.0, Magnit);
  anew = SPitch->data[0];
  i16 = c_SPitch->size[0];
  c_SPitch->size[0] = Magnit->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_SPitch, i16, (int32_T)sizeof
                    (boolean_T), &s_emlrtRTEI);
  ix = Magnit->size[0];
  for (i16 = 0; i16 < ix; i16++) {
    c_SPitch->data[i16] = (anew < Magnit->data[i16]);
  }

  st.site = &pe_emlrtRSI;
  if (all(&st, c_SPitch)) {
    /* 'spec_trk:208' SPitch(1)   = pAvg; */
    i16 = pAvg->size[0];
    if (1 != i16) {
      emlrtSizeEqCheck1DR2012b(1, i16, &j_emlrtECI, sp);
    }

    i16 = SPitch->size[1];
    if (!(1 <= i16)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i16, &ab_emlrtBCI, sp);
    }

    i16 = pAvg->size[0];
    if (!(1 <= i16)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i16, &bb_emlrtBCI, sp);
    }

    SPitch->data[0] = pAvg->data[0];
  }

  emxFree_boolean_T(&c_SPitch);
  emxInit_boolean_T1(sp, &b_SPitch_temp_end, 1, &s_emlrtRTEI, true);

  /* 'spec_trk:210' if all(SPitch_temp_end < (pAvg/2)) */
  b_rdivide(sp, pAvg, 2.0, Magnit);
  i16 = b_SPitch_temp_end->size[0];
  b_SPitch_temp_end->size[0] = Magnit->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch_temp_end, i16, (int32_T)
                    sizeof(boolean_T), &s_emlrtRTEI);
  ix = Magnit->size[0];
  for (i16 = 0; i16 < ix; i16++) {
    b_SPitch_temp_end->data[i16] = (SPitch_temp_end < Magnit->data[i16]);
  }

  emxFree_real_T(&Magnit);
  st.site = &qe_emlrtRSI;
  if (all(&st, b_SPitch_temp_end)) {
    /* 'spec_trk:211' SPitch(end) = pAvg; */
    i16 = pAvg->size[0];
    if (1 != i16) {
      emlrtSizeEqCheck1DR2012b(1, i16, &k_emlrtECI, sp);
    }

    i16 = pAvg->size[0];
    if (!(1 <= i16)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i16, &cb_emlrtBCI, sp);
    }

    i16 = SPitch->size[1];
    cindx = SPitch->size[1];
    if (!((cindx >= 1) && (cindx <= i16))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i16, &lb_emlrtBCI, sp);
    }

    SPitch->data[cindx - 1] = pAvg->data[0];
  }

  emxFree_boolean_T(&b_SPitch_temp_end);

  /* 'spec_trk:214' [Indrows, Indcols, Vals] = find(SPitch); */
  st.site = &re_emlrtRSI;
  b_st.site = &fi_emlrtRSI;
  iy = 0;
  i16 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = SPitch->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i16, (int32_T)sizeof
                    (int32_T), &s_emlrtRTEI);
  nm1d2 = SPitch->size[1];
  i16 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = nm1d2;
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  if (SPitch->size[1] == 0) {
    i16 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i16, (int32_T)sizeof
                      (int32_T), &s_emlrtRTEI);
    i16 = Signal->size[0] * Signal->size[1];
    Signal->size[0] = 1;
    Signal->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i16, (int32_T)sizeof
                      (real_T), &s_emlrtRTEI);
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
      emlrtErrorWithMessageIdR2012b(&b_st, &he_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (SPitch->size[1] == 1) {
      if (iy == 0) {
        i16 = iindx->size[0] * iindx->size[1];
        iindx->size[0] = 1;
        iindx->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i16, (int32_T)sizeof
                          (int32_T), &s_emlrtRTEI);
        i16 = Signal->size[0] * Signal->size[1];
        Signal->size[0] = 1;
        Signal->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i16, (int32_T)
                          sizeof(real_T), &s_emlrtRTEI);
      }
    } else {
      i16 = iindx->size[0] * iindx->size[1];
      if (1 > iy) {
        iindx->size[1] = 0;
      } else {
        iindx->size[1] = iy;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)iindx, i16, (int32_T)sizeof
                        (int32_T), &t_emlrtRTEI);
      i16 = Signal->size[0] * Signal->size[1];
      if (1 > iy) {
        Signal->size[1] = 0;
      } else {
        Signal->size[1] = iy;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i16, (int32_T)sizeof
                        (real_T), &u_emlrtRTEI);
    }
  }

  /* 'spec_trk:215' SPitch = interp1(Indcols, Vals, [1:numframes], 'pchip'); */
  st.site = &se_emlrtRSI;
  b_st.site = &bd_emlrtRSI;
  c_st.site = &cd_emlrtRSI;
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

  d_st.site = &dd_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &xd_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  i16 = VMerit_minmrt->size[0] * VMerit_minmrt->size[1];
  VMerit_minmrt->size[0] = 1;
  if (!(n > 0)) {
    emlrtNonNegativeCheckR2012b(n, &f_emlrtDCI, &c_st);
  }

  VMerit_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VMerit_minmrt, i16, (int32_T)
                    sizeof(real_T), &s_emlrtRTEI);
  if (n > 0) {
    VMerit_minmrt->data[0] = anew;
    if (n > 1) {
      VMerit_minmrt->data[n - 1] = apnd;
      i16 = n - 1;
      nm1d2 = asr_s32(i16, 1U);
      d_st.site = &ed_emlrtRSI;
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

  emxInit_real_T(&c_st, &f_iindx, 2, &s_emlrtRTEI, true);
  i16 = f_iindx->size[0] * f_iindx->size[1];
  f_iindx->size[0] = 1;
  f_iindx->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_iindx, i16, (int32_T)sizeof(real_T),
                    &s_emlrtRTEI);
  ix = iindx->size[0] * iindx->size[1];
  for (i16 = 0; i16 < ix; i16++) {
    f_iindx->data[i16] = iindx->data[i16];
  }

  emxFree_int32_T(&iindx);
  emxInit_real_T(sp, &d_SPitch, 2, &s_emlrtRTEI, true);
  st.site = &se_emlrtRSI;
  interp1(&st, f_iindx, Signal, VMerit_minmrt, SPitch);

  /* 'spec_trk:217' FILTER_ORDER = 3; */
  /* 'spec_trk:218' flt_b = (ones(1,FILTER_ORDER))/FILTER_ORDER ; */
  /* 'spec_trk:219' flt_a = 1; */
  /* 'spec_trk:221' SPitch = filter(flt_b, flt_a, SPitch); */
  i16 = d_SPitch->size[0] * d_SPitch->size[1];
  d_SPitch->size[0] = 1;
  d_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_SPitch, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&f_iindx);
  emxFree_real_T(&VMerit_minmrt);
  emxFree_real_T(&Signal);
  for (i16 = 0; i16 < ix; i16++) {
    d_SPitch->data[i16] = SPitch->data[i16];
  }

  st.site = &te_emlrtRSI;
  b_filter(&st, d_SPitch, SPitch);

  /*   above messes up  first few values of SPitch  ---  simple fix up */
  /*   Note--   this fix up should be based on above filter order */
  /* 'spec_trk:227' SPitch(1) = SPitch(3); */
  i16 = SPitch->size[1];
  if (!(1 <= i16)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i16, &eb_emlrtBCI, sp);
  }

  i16 = SPitch->size[1];
  if (!(3 <= i16)) {
    emlrtDynamicBoundsCheckR2012b(3, 1, i16, &db_emlrtBCI, sp);
  }

  SPitch->data[0] = SPitch->data[2];

  /* 'spec_trk:228' SPitch(2) = SPitch (4); */
  i16 = SPitch->size[1];
  if (!(2 <= i16)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i16, &gb_emlrtBCI, sp);
  }

  i16 = SPitch->size[1];
  if (!(4 <= i16)) {
    emlrtDynamicBoundsCheckR2012b(4, 1, i16, &fb_emlrtBCI, sp);
  }

  SPitch->data[1] = SPitch->data[3];

  /*  Create pitch track with Voiced/Unvoiced decision */
  /* 'spec_trk:231' VUVSPitch = SPitch; */
  i16 = VUVSPitch->size[0] * VUVSPitch->size[1];
  VUVSPitch->size[0] = 1;
  VUVSPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVSPitch, i16, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  emxFree_real_T(&d_SPitch);
  for (i16 = 0; i16 < ix; i16++) {
    VUVSPitch->data[i16] = SPitch->data[i16];
  }

  /* 'spec_trk:232' VUVSPitch(VUVEnergy==0) = 0; */
  iy = VUVEnergy->size[1];
  for (i = 0; i < iy; i++) {
    if (!VUVEnergy->data[i]) {
      i16 = VUVSPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i16, &mb_emlrtBCI, sp);
      }

      VUVSPitch->data[i] = 0.0;
    }
  }

  /*  SPitch = SPitch - delta; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (spec_trk.c) */
