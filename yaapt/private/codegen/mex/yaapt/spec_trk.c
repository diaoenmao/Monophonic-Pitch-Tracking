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
#include "eml_int_forloop_overflow_check.h"
#include "sum.h"
#include "prod.h"
#include "indexShapeCheck.h"
#include "peaks.h"
#include "abs.h"
#include "fft.h"
#include "mean.h"
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
static emlrtRSInfo ug_emlrtRSI = { 202, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo vg_emlrtRSI = { 201, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo wg_emlrtRSI = { 181, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo xg_emlrtRSI = { 180, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo yg_emlrtRSI = { 164, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ah_emlrtRSI = { 157, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo bh_emlrtRSI = { 154, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ch_emlrtRSI = { 150, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo dh_emlrtRSI = { 149, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo eh_emlrtRSI = { 146, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo fh_emlrtRSI = { 99, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo gh_emlrtRSI = { 97, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo hh_emlrtRSI = { 93, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo ih_emlrtRSI = { 91, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo jh_emlrtRSI = { 85, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo kh_emlrtRSI = { 84, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo lh_emlrtRSI = { 80, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRSInfo hk_emlrtRSI = { 15, "min",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo ik_emlrtRSI = { 210, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo jk_emlrtRSI = { 214, "minOrMax",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRTEInfo yb_emlrtRTEI = { 1, 42, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ac_emlrtRTEI = { 68, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo bc_emlrtRTEI = { 69, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo cc_emlrtRTEI = { 80, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo dc_emlrtRTEI = { 82, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ec_emlrtRTEI = { 84, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo fc_emlrtRTEI = { 85, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo gc_emlrtRTEI = { 90, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo hc_emlrtRTEI = { 93, 14, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo ic_emlrtRTEI = { 143, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo jc_emlrtRTEI = { 154, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo kc_emlrtRTEI = { 158, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo lc_emlrtRTEI = { 178, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo xf_emlrtRTEI = { 87, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo v_emlrtDCI = { 90, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 90, 18, "Data", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo o_emlrtECI = { 2, 90, 18, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtRTEInfo yf_emlrtRTEI = { 96, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtECInfo p_emlrtECI = { 2, 97, 39, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 99, 23, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo q_emlrtECI = { -1, 99, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 102, 22, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo r_emlrtECI = { -1, 102, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 142, 21, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 99, 44, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo s_emlrtECI = { -1, 99, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 103, 22, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo t_emlrtECI = { -1, 103, 9, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 149, 31, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 150, 30, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo u_emlrtECI = { 2, 154, 10, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 161, 36, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 161, 44, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 162, 36, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 162, 44, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 194, 9, "Idx_voiced", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 190, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 193, 9, "VPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtECInfo v_emlrtECI = { -1, 205, 1, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m" };

static emlrtDCInfo w_emlrtDCI = { 68, 20, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo x_emlrtDCI = { 68, 20, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo y_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo ab_emlrtDCI = { 68, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo bb_emlrtDCI = { 82, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo cb_emlrtDCI = { 82, 15, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtDCInfo db_emlrtDCI = { 76, 26, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 144, 29, "CandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 145, 28, "CandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 235, 1, "VUVSPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 205, 1, "SPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 169, 30, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 169, 17, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 169, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 169, 25, "VCandsPitch", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 171, 30, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 171, 17, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 171, 17, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 171, 25, "VCandsMerit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 161, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 161, 5, "VPeak_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 162, 36, "Idx", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 162, 5, "VMerit_minmrt", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 88, 9, "VUVEnergy", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo eb_emlrtDCI = { 93, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtDCInfo fb_emlrtDCI = { 93, 30, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 4 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 97, 31, "Magnit", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo gb_emlrtDCI = { 97, 31, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 97, 13, "SHC", "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 0 };

static emlrtDCInfo hb_emlrtDCI = { 97, 13, "spec_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m", 1 };

/* Function Definitions */
void spec_trk(const emlrtStack *sp, emxArray_real_T *Data, real_T Fs, const
              emxArray_boolean_T *VUVEnergy, const struct_T *Prm,
              emxArray_real_T *SPitch, emxArray_real_T *VUVSPitch, real_T
              pAvg_data[], int32_T pAvg_size[1], real_T pStd_data[], int32_T
              pStd_size[1])
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
  int32_T i20;
  real_T ndbl;
  real_T anew;
  int32_T ix;
  emxArray_real_T *CandsMerit;
  real_T zero_padded;
  emxArray_real_T *r16;
  emxArray_real_T *Kaiser_window;
  emxArray_real_T *SHC;
  int32_T nm1d2;
  int32_T ixstop;
  int32_T n;
  real_T apnd;
  boolean_T overflow;
  real_T cdiff;
  emxArray_real_T *VPeak_minmrt;
  emxArray_real_T *winix;
  real_T absb;
  emxArray_real_T *Signal;
  emxArray_real_T *b_Signal;
  emxArray_real_T *rowix;
  int32_T frame;
  emxArray_real_T *Magnit;
  emxArray_int32_T *r17;
  emxArray_real_T *r18;
  emxArray_creal_T *r19;
  emxArray_real_T *b_SHC;
  emxArray_real_T *b_Magnit;
  emxArray_real_T *r20;
  emxArray_real_T *r21;
  emxArray_real_T *b_Kaiser_window;
  real_T firstp;
  int32_T cindx;
  int32_T iv23[2];
  int32_T itmp;
  int32_T iv24[1];
  int32_T iv25[2];
  int32_T c_Kaiser_window[2];
  int32_T iv26[1];
  int32_T iv27[2];
  emxArray_boolean_T *Idx_voiced;
  emxArray_int32_T *iindx;
  real_T k;
  int32_T i;
  int32_T b_winix[2];
  int32_T iv28[2];
  int32_T iv29[1];
  int32_T iv30[1];
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
  int32_T iv31[2];
  emxArray_real_T *b_CandsMerit;
  int32_T c_CandsMerit[2];
  emxArray_real_T *delta1;
  uint32_T unnamed_idx_1;
  boolean_T exitg1;
  emxArray_int32_T *d_iindx;
  emxArray_int32_T *e_iindx;
  emxArray_real_T *b_VPeak_minmrt;
  emxArray_real_T *VPitch;
  int8_T tmp_data[1];
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
  nframesize = Prm->frame_length * Fs / 1000.0;
  b_fix(&nframesize);
  nframejump = Prm->frame_space * Fs / 1000.0;
  b_fix(&nframejump);

  /*  overlap width in sample  */
  numframes = ((real_T)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /*  use larger frame size */
  nframesize *= 2.0;

  /*  Max number of peak candidates found */
  maxpeaks = Prm->shc_maxpeaks;

  /*  FFT length */
  /*  Resolution of spectrum */
  delta = Fs / Prm->fft_length;

  /*  Window width in sample */
  window_length = Prm->shc_window / delta;
  b_fix(&window_length);
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, b_mod(window_length) == 0.0))
  {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1);
    window_length++;
  }

  emxInit_real_T(sp, &CandsPitch, 2, &ac_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2);

  /*  Half window width */
  half_winlen = Prm->shc_window / (delta * 2.0);
  b_fix(&half_winlen);

  /*  Max range of SHC  */
  max_SHC = (Prm->f0_max + Prm->shc_pwidth * 2.0) / delta;
  b_fix(&max_SHC);

  /*  Min range of SHC  */
  min_SHC = muDoubleScalarCeil(Prm->f0_min / delta);

  /*  Number of harmomics considered */
  /* -- INITIALIZATION ----------------------------------------------------------- */
  i20 = CandsPitch->size[0] * CandsPitch->size[1];
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &x_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &w_emlrtDCI, sp);
  }

  CandsPitch->size[0] = (int32_T)ndbl;
  if (!(numframes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &ab_emlrtDCI, sp);
  }

  ndbl = numframes;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &y_emlrtDCI, sp);
  }

  CandsPitch->size[1] = (int32_T)ndbl;
  emxEnsureCapacity(sp, (emxArray__common *)CandsPitch, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ndbl = Prm->shc_maxpeaks;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &x_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &w_emlrtDCI, sp);
  }

  if (!(numframes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &ab_emlrtDCI, sp);
  }

  anew = numframes;
  if (anew != (int32_T)muDoubleScalarFloor(anew)) {
    emlrtIntegerCheckR2012b(anew, &y_emlrtDCI, sp);
  }

  ix = (int32_T)ndbl * (int32_T)anew;
  for (i20 = 0; i20 < ix; i20++) {
    CandsPitch->data[i20] = 0.0;
  }

  emxInit_real_T(sp, &CandsMerit, 2, &bc_emlrtRTEI, true);
  i20 = CandsMerit->size[0] * CandsMerit->size[1];
  CandsMerit->size[0] = (int32_T)Prm->shc_maxpeaks;
  CandsMerit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)CandsMerit, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ix = (int32_T)Prm->shc_maxpeaks * (int32_T)numframes;
  for (i20 = 0; i20 < ix; i20++) {
    CandsMerit->data[i20] = 1.0;
  }

  /*  Zero padding a */
  /*  a = Data; */
  /*  Data(end:(numframes-1)*nframejump+nframesize) = 0; */
  /*  Data(end) = 0; */
  zero_padded = ((numframes - 1.0) * nframejump + nframesize) - (real_T)
    Data->size[1];
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 1, zero_padded > 0.0)) {
    emxInit_real_T(sp, &r16, 2, &yb_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3);
    if (zero_padded != (int32_T)muDoubleScalarFloor(zero_padded)) {
      emlrtIntegerCheckR2012b(zero_padded, &db_emlrtDCI, sp);
    }

    nm1d2 = Data->size[1];
    ixstop = (int32_T)zero_padded;
    i20 = Data->size[0] * Data->size[1];
    Data->size[1] = nm1d2 + (int32_T)zero_padded;
    emxEnsureCapacity(sp, (emxArray__common *)Data, i20, (int32_T)sizeof(real_T),
                      &yb_emlrtRTEI);
    if (zero_padded != (int32_T)muDoubleScalarFloor(zero_padded)) {
      emlrtIntegerCheckR2012b(zero_padded, &db_emlrtDCI, sp);
    }

    i20 = r16->size[0] * r16->size[1];
    r16->size[0] = 1;
    r16->size[1] = (int32_T)zero_padded;
    emxEnsureCapacity(sp, (emxArray__common *)r16, i20, (int32_T)sizeof(real_T),
                      &yb_emlrtRTEI);
    ix = (int32_T)zero_padded;
    for (i20 = 0; i20 < ix; i20++) {
      r16->data[r16->size[0] * i20] = 0.0;
    }

    for (i20 = 0; i20 < ixstop; i20++) {
      Data->data[nm1d2 + i20] = r16->data[i20];
    }

    emxFree_real_T(&r16);
  }

  emxInit_real_T(sp, &Kaiser_window, 2, &cc_emlrtRTEI, true);
  emxInit_real_T(sp, &SHC, 2, &dc_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 4);

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Compute SHC for voiced frame */
  st.site = &lh_emlrtRSI;
  Mykaiser(&st, nframesize, Kaiser_window);

  /*  Kaiser_window_test = kaiser(nframesize); */
  i20 = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  if (!(max_SHC >= 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &cb_emlrtDCI, sp);
  }

  ndbl = max_SHC;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &bb_emlrtDCI, sp);
  }

  SHC->size[1] = (int32_T)ndbl;
  emxEnsureCapacity(sp, (emxArray__common *)SHC, i20, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  if (!(max_SHC >= 0.0)) {
    emlrtNonNegativeCheckR2012b(max_SHC, &cb_emlrtDCI, sp);
  }

  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &bb_emlrtDCI, sp);
  }

  ix = (int32_T)ndbl;
  for (i20 = 0; i20 < ix; i20++) {
    SHC->data[i20] = 0.0;
  }

  st.site = &kh_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
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

  d_st.site = &x_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &df_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &VPeak_minmrt, 2, &kc_emlrtRTEI, true);
  i20 = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  VPeak_minmrt->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)VPeak_minmrt, i20, (int32_T)
                    sizeof(real_T), &yb_emlrtRTEI);
  if (n > 0) {
    VPeak_minmrt->data[0] = anew;
    if (n > 1) {
      VPeak_minmrt->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      d_st.site = &y_emlrtRSI;
      for (ixstop = 1; ixstop < nm1d2; ixstop++) {
        VPeak_minmrt->data[ixstop] = anew + (real_T)ixstop;
        VPeak_minmrt->data[(n - ixstop) - 1] = apnd - (real_T)ixstop;
      }

      if (nm1d2 << 1 == n - 1) {
        VPeak_minmrt->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        VPeak_minmrt->data[nm1d2] = anew + (real_T)nm1d2;
        VPeak_minmrt->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T(&c_st, &winix, 2, &ec_emlrtRTEI, true);
  st.site = &kh_emlrtRSI;
  repmat(&st, VPeak_minmrt, Prm->shc_numharms + 1.0, winix);
  st.site = &jh_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
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

  d_st.site = &x_emlrtRSI;
  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &df_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&d_st, &Signal, 2, &gc_emlrtRTEI, true);
  i20 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)Signal, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  if (n > 0) {
    Signal->data[0] = anew;
    if (n > 1) {
      Signal->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      d_st.site = &y_emlrtRSI;
      for (ixstop = 1; ixstop < nm1d2; ixstop++) {
        Signal->data[ixstop] = anew + (real_T)ixstop;
        Signal->data[(n - ixstop) - 1] = apnd - (real_T)ixstop;
      }

      if (nm1d2 << 1 == n - 1) {
        Signal->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        Signal->data[nm1d2] = anew + (real_T)nm1d2;
        Signal->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  emxInit_real_T2(&c_st, &b_Signal, 1, &yb_emlrtRTEI, true);
  i20 = b_Signal->size[0];
  b_Signal->size[0] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_Signal, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ix = Signal->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    b_Signal->data[i20] = Signal->data[Signal->size[0] * i20];
  }

  emxInit_real_T(sp, &rowix, 2, &fc_emlrtRTEI, true);
  st.site = &jh_emlrtRSI;
  b_repmat(&st, b_Signal, window_length, rowix);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &xf_emlrtRTEI, sp);
  frame = 0;
  emxFree_real_T(&b_Signal);
  emxInit_real_T2(sp, &Magnit, 1, &hc_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r17, 1, &yb_emlrtRTEI, true);
  emxInit_real_T(sp, &r18, 2, &yb_emlrtRTEI, true);
  emxInit_creal_T(sp, &r19, 2, &yb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SHC, 2, &yb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Magnit, 2, &yb_emlrtRTEI, true);
  emxInit_real_T(sp, &r20, 2, &yb_emlrtRTEI, true);
  emxInit_real_T(sp, &r21, 2, &yb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Kaiser_window, 2, &yb_emlrtRTEI, true);
  while (frame <= (int32_T)numframes - 1) {
    covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 0, 1);
    i20 = VUVEnergy->size[1];
    if (!((frame + 1 >= 1) && (frame + 1 <= i20))) {
      emlrtDynamicBoundsCheckR2012b(frame + 1, 1, i20, &qd_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 2, (int32_T)VUVEnergy->
                   data[frame] > 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 5);
      firstp = 1.0 + ((1.0 + (real_T)frame) - 1.0) * nframejump;
      ndbl = (firstp + nframesize) - 1.0;
      if (firstp > ndbl) {
        cindx = 1;
        i20 = 1;
      } else {
        if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
          emlrtIntegerCheckR2012b(firstp, &v_emlrtDCI, sp);
        }

        i20 = Data->size[1];
        cindx = (int32_T)firstp;
        if (!((cindx >= 1) && (cindx <= i20))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &kc_emlrtBCI, sp);
        }

        if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
          emlrtIntegerCheckR2012b(ndbl, &v_emlrtDCI, sp);
        }

        i20 = Data->size[1];
        itmp = (int32_T)ndbl;
        if (!((itmp >= 1) && (itmp <= i20))) {
          emlrtDynamicBoundsCheckR2012b(itmp, 1, i20, &kc_emlrtBCI, sp);
        }

        i20 = itmp + 1;
      }

      iv23[0] = 1;
      iv23[1] = i20 - cindx;
      itmp = b_Kaiser_window->size[0] * b_Kaiser_window->size[1];
      b_Kaiser_window->size[0] = 1;
      b_Kaiser_window->size[1] = Kaiser_window->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_Kaiser_window, itmp, (int32_T)
                        sizeof(real_T), &yb_emlrtRTEI);
      ix = Kaiser_window->size[0];
      for (itmp = 0; itmp < ix; itmp++) {
        b_Kaiser_window->data[b_Kaiser_window->size[0] * itmp] =
          Kaiser_window->data[itmp];
      }

      for (itmp = 0; itmp < 2; itmp++) {
        c_Kaiser_window[itmp] = b_Kaiser_window->size[itmp];
      }

      if ((iv23[0] != c_Kaiser_window[0]) || (iv23[1] != c_Kaiser_window[1])) {
        emlrtSizeEqCheckNDR2012b(&iv23[0], &c_Kaiser_window[0], &o_emlrtECI, sp);
      }

      itmp = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      Signal->size[1] = i20 - cindx;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, itmp, (int32_T)sizeof
                        (real_T), &yb_emlrtRTEI);
      ix = i20 - cindx;
      for (i20 = 0; i20 < ix; i20++) {
        Signal->data[Signal->size[0] * i20] = Data->data[(cindx + i20) - 1] *
          Kaiser_window->data[i20];
      }

      st.site = &ih_emlrtRSI;
      ndbl = mean(&st, Signal);
      i20 = Signal->size[0] * Signal->size[1];
      Signal->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)Signal, i20, (int32_T)sizeof
                        (real_T), &yb_emlrtRTEI);
      ix = Signal->size[1];
      for (i20 = 0; i20 < ix; i20++) {
        Signal->data[Signal->size[0] * i20] -= ndbl;
      }

      /*             Magnit = [zeros(half_winlen, 1); abs(fft(Signal , nfftlength))]; */
      st.site = &hh_emlrtRSI;
      b_fft(&st, Signal, Prm->fft_length, r19);
      st.site = &hh_emlrtRSI;
      b_abs(&st, r19, VPeak_minmrt);
      if (!(half_winlen >= 0.0)) {
        emlrtNonNegativeCheckR2012b(half_winlen, &fb_emlrtDCI, sp);
      }

      ndbl = half_winlen;
      if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
        emlrtIntegerCheckR2012b(ndbl, &eb_emlrtDCI, sp);
      }

      i20 = Magnit->size[0];
      Magnit->size[0] = (int32_T)half_winlen + VPeak_minmrt->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)Magnit, i20, (int32_T)sizeof
                        (real_T), &yb_emlrtRTEI);
      ix = (int32_T)half_winlen;
      for (i20 = 0; i20 < ix; i20++) {
        Magnit->data[i20] = 0.0;
      }

      ix = VPeak_minmrt->size[1];
      for (i20 = 0; i20 < ix; i20++) {
        Magnit->data[i20 + (int32_T)half_winlen] = VPeak_minmrt->
          data[VPeak_minmrt->size[0] * i20];
      }

      /*  Compute SHC (Spectral Harmonic Correlation) */
      i20 = (int32_T)(max_SHC + (1.0 - min_SHC));
      emlrtForLoopVectorCheckR2012b(min_SHC, 1.0, max_SHC, mxDOUBLE_CLASS, i20,
        &yf_emlrtRTEI, sp);
      ixstop = 0;
      while (ixstop <= i20 - 1) {
        k = min_SHC + (real_T)ixstop;
        covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 1, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 6);
        cindx = r18->size[0] * r18->size[1];
        r18->size[0] = rowix->size[0];
        r18->size[1] = rowix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)r18, cindx, (int32_T)sizeof
                          (real_T), &yb_emlrtRTEI);
        ix = rowix->size[0] * rowix->size[1];
        for (cindx = 0; cindx < ix; cindx++) {
          r18->data[cindx] = k * rowix->data[cindx];
        }

        for (cindx = 0; cindx < 2; cindx++) {
          b_winix[cindx] = winix->size[cindx];
        }

        for (cindx = 0; cindx < 2; cindx++) {
          iv28[cindx] = r18->size[cindx];
        }

        if ((b_winix[0] != iv28[0]) || (b_winix[1] != iv28[1])) {
          emlrtSizeEqCheckNDR2012b(&b_winix[0], &iv28[0], &p_emlrtECI, sp);
        }

        st.site = &gh_emlrtRSI;
        b_indexShapeCheck(&st, Magnit->size[0], *(int32_T (*)[2])winix->size);
        cindx = b_Magnit->size[0] * b_Magnit->size[1];
        b_Magnit->size[0] = winix->size[0];
        b_Magnit->size[1] = winix->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)b_Magnit, cindx, (int32_T)
                          sizeof(real_T), &yb_emlrtRTEI);
        nm1d2 = Magnit->size[0];
        ix = winix->size[0] * winix->size[1];
        for (cindx = 0; cindx < ix; cindx++) {
          ndbl = winix->data[cindx] + r18->data[cindx];
          if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
            emlrtIntegerCheckR2012b(ndbl, &gb_emlrtDCI, sp);
          }

          itmp = (int32_T)ndbl;
          if (!((itmp >= 1) && (itmp <= nm1d2))) {
            emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &rd_emlrtBCI, sp);
          }

          b_Magnit->data[cindx] = Magnit->data[itmp - 1];
        }

        st.site = &gh_emlrtRSI;
        prod(&st, b_Magnit, VPeak_minmrt);
        cindx = SHC->size[1];
        if (k != (int32_T)k) {
          emlrtIntegerCheckR2012b(k, &hb_emlrtDCI, sp);
        }

        itmp = (int32_T)k;
        if (!((itmp >= 1) && (itmp <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &sd_emlrtBCI, sp);
        }

        st.site = &gh_emlrtRSI;
        SHC->data[itmp - 1] = sum(&st, VPeak_minmrt);
        ixstop++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 1, 0);
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 7);
      i20 = b_SHC->size[0] * b_SHC->size[1];
      b_SHC->size[0] = 1;
      b_SHC->size[1] = SHC->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_SHC, i20, (int32_T)sizeof
                        (real_T), &yb_emlrtRTEI);
      ix = SHC->size[0] * SHC->size[1];
      for (i20 = 0; i20 < ix; i20++) {
        b_SHC->data[i20] = SHC->data[i20];
      }

      st.site = &fh_emlrtRSI;
      peaks(&st, b_SHC, delta, maxpeaks, Prm->f0_min, Prm->f0_max,
            Prm->shc_pwidth, Prm->shc_thresh1, Prm->shc_thresh2, Prm->f0_double,
            Prm->f0_half, Prm->merit_extra, VPeak_minmrt, Signal);
      ix = CandsPitch->size[0];
      i20 = r17->size[0];
      r17->size[0] = ix;
      emxEnsureCapacity(sp, (emxArray__common *)r17, i20, (int32_T)sizeof
                        (int32_T), &yb_emlrtRTEI);
      for (i20 = 0; i20 < ix; i20++) {
        r17->data[i20] = i20;
      }

      i20 = CandsPitch->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i20))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &lc_emlrtBCI, sp);
      }

      iv29[0] = r17->size[0];
      emlrtSubAssignSizeCheckR2012b(iv29, 1, *(int32_T (*)[2])VPeak_minmrt->size,
        2, &q_emlrtECI, sp);
      nm1d2 = r17->size[0];
      for (i20 = 0; i20 < nm1d2; i20++) {
        CandsPitch->data[r17->data[i20] + CandsPitch->size[0] * frame] =
          VPeak_minmrt->data[i20];
      }

      ix = CandsMerit->size[0];
      i20 = r17->size[0];
      r17->size[0] = ix;
      emxEnsureCapacity(sp, (emxArray__common *)r17, i20, (int32_T)sizeof
                        (int32_T), &yb_emlrtRTEI);
      for (i20 = 0; i20 < ix; i20++) {
        r17->data[i20] = i20;
      }

      i20 = CandsMerit->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i20))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &oc_emlrtBCI, sp);
      }

      iv30[0] = r17->size[0];
      emlrtSubAssignSizeCheckR2012b(iv30, 1, *(int32_T (*)[2])Signal->size, 2,
        &s_emlrtECI, sp);
      nm1d2 = r17->size[0];
      for (i20 = 0; i20 < nm1d2; i20++) {
        CandsMerit->data[r17->data[i20] + CandsMerit->size[0] * frame] =
          Signal->data[i20];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 8);

      /*  if energy is low,  let frame be considered as unvoiced */
      ix = CandsPitch->size[0];
      i20 = r17->size[0];
      r17->size[0] = ix;
      emxEnsureCapacity(sp, (emxArray__common *)r17, i20, (int32_T)sizeof
                        (int32_T), &yb_emlrtRTEI);
      for (i20 = 0; i20 < ix; i20++) {
        r17->data[i20] = i20;
      }

      i20 = CandsPitch->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i20))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &mc_emlrtBCI, sp);
      }

      iv24[0] = r17->size[0];
      iv25[0] = 1;
      iv25[1] = (int32_T)maxpeaks;
      emlrtSubAssignSizeCheckR2012b(iv24, 1, iv25, 2, &r_emlrtECI, sp);
      i20 = r20->size[0] * r20->size[1];
      r20->size[0] = 1;
      r20->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r20, i20, (int32_T)sizeof(real_T),
                        &yb_emlrtRTEI);
      ix = (int32_T)maxpeaks;
      for (i20 = 0; i20 < ix; i20++) {
        r20->data[r20->size[0] * i20] = 0.0;
      }

      nm1d2 = r17->size[0];
      for (i20 = 0; i20 < nm1d2; i20++) {
        CandsPitch->data[r17->data[i20] + CandsPitch->size[0] * frame] =
          r20->data[i20];
      }

      ix = CandsMerit->size[0];
      i20 = r17->size[0];
      r17->size[0] = ix;
      emxEnsureCapacity(sp, (emxArray__common *)r17, i20, (int32_T)sizeof
                        (int32_T), &yb_emlrtRTEI);
      for (i20 = 0; i20 < ix; i20++) {
        r17->data[i20] = i20;
      }

      i20 = CandsMerit->size[1];
      cindx = frame + 1;
      if (!((cindx >= 1) && (cindx <= i20))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &pc_emlrtBCI, sp);
      }

      iv26[0] = r17->size[0];
      iv27[0] = 1;
      iv27[1] = (int32_T)maxpeaks;
      emlrtSubAssignSizeCheckR2012b(iv26, 1, iv27, 2, &t_emlrtECI, sp);
      i20 = r21->size[0] * r21->size[1];
      r21->size[0] = 1;
      r21->size[1] = (int32_T)maxpeaks;
      emxEnsureCapacity(sp, (emxArray__common *)r21, i20, (int32_T)sizeof(real_T),
                        &yb_emlrtRTEI);
      ix = (int32_T)maxpeaks;
      for (i20 = 0; i20 < ix; i20++) {
        r21->data[r21->size[0] * i20] = 1.0;
      }

      nm1d2 = r17->size[0];
      for (i20 = 0; i20 < nm1d2; i20++) {
        CandsMerit->data[r17->data[i20] + CandsMerit->size[0] * frame] =
          r21->data[i20];
      }
    }

    frame++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Kaiser_window);
  emxFree_real_T(&r21);
  emxFree_real_T(&r20);
  emxFree_real_T(&b_Magnit);
  emxFree_real_T(&b_SHC);
  emxFree_creal_T(&r19);
  emxFree_int32_T(&r17);
  emxFree_real_T(&Magnit);
  emxFree_real_T(&Kaiser_window);
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
  i20 = CandsPitch->size[0];
  if (!(1 <= i20)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i20, &nc_emlrtBCI, sp);
  }

  ix = CandsPitch->size[1];
  i20 = SPitch->size[0] * SPitch->size[1];
  SPitch->size[0] = 1;
  SPitch->size[1] = ix;
  emxEnsureCapacity(sp, (emxArray__common *)SPitch, i20, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  for (i20 = 0; i20 < ix; i20++) {
    SPitch->data[SPitch->size[0] * i20] = CandsPitch->data[CandsPitch->size[0] *
      i20];
  }

  emxInit_boolean_T(sp, &Idx_voiced, 2, &ic_emlrtRTEI, true);
  i20 = Idx_voiced->size[0] * Idx_voiced->size[1];
  Idx_voiced->size[0] = 1;
  Idx_voiced->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Idx_voiced, i20, (int32_T)sizeof
                    (boolean_T), &yb_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    Idx_voiced->data[i20] = (SPitch->data[i20] > 0.0);
  }

  emxInit_int32_T(sp, &iindx, 2, &yb_emlrtRTEI, true);
  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  ix = CandsPitch->size[0];
  nm1d2 = CandsPitch->size[1];
  i20 = winix->size[0] * winix->size[1];
  winix->size[0] = ix;
  winix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)winix, i20, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  ixstop = iindx->size[1];
  for (i20 = 0; i20 < ixstop; i20++) {
    for (cindx = 0; cindx < ix; cindx++) {
      itmp = iindx->data[iindx->size[0] * i20];
      if (!((itmp >= 1) && (itmp <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &ad_emlrtBCI, sp);
      }

      winix->data[cindx + winix->size[0] * i20] = CandsPitch->data[cindx +
        CandsPitch->size[0] * (itmp - 1)];
    }
  }

  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  ix = CandsMerit->size[0];
  nm1d2 = CandsMerit->size[1];
  i20 = rowix->size[0] * rowix->size[1];
  rowix->size[0] = ix;
  rowix->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)rowix, i20, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  ixstop = iindx->size[1];
  for (i20 = 0; i20 < ixstop; i20++) {
    for (cindx = 0; cindx < ix; cindx++) {
      itmp = iindx->data[iindx->size[0] * i20];
      if (!((itmp >= 1) && (itmp <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(itmp, 1, nm1d2, &bd_emlrtBCI, sp);
      }

      rowix->data[cindx + rowix->size[0] * i20] = CandsMerit->data[cindx +
        CandsMerit->size[0] * (itmp - 1)];
    }
  }

  emxInit_boolean_T(sp, &b_SPitch, 2, &yb_emlrtRTEI, true);
  i20 = b_SPitch->size[0] * b_SPitch->size[1];
  b_SPitch->size[0] = 1;
  b_SPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i20, (int32_T)sizeof
                    (boolean_T), &yb_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    b_SPitch->data[i20] = (SPitch->data[i20] > 0.0);
  }

  st.site = &eh_emlrtRSI;
  Num_VCands = b_sum(&st, b_SPitch);

  /*  Average, STD of the first choice candidates */
  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_boolean_T(&b_SPitch);
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  i20 = CandsPitch->size[0];
  if (!(1 <= i20)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i20, &qc_emlrtBCI, sp);
  }

  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &b_CandsPitch, 2, &yb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &b_iindx, 1, &yb_emlrtRTEI, true);
  ix = CandsPitch->size[0];
  i20 = b_iindx->size[0];
  b_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_iindx, i20, (int32_T)sizeof
                    (int32_T), &yb_emlrtRTEI);
  ixstop = iindx->size[1];
  for (i20 = 0; i20 < ixstop; i20++) {
    b_iindx->data[i20] = iindx->data[iindx->size[0] * i20];
  }

  emxInit_real_T(sp, &c_CandsPitch, 2, &yb_emlrtRTEI, true);
  ixstop = b_iindx->size[0];
  i20 = c_CandsPitch->size[0] * c_CandsPitch->size[1];
  c_CandsPitch->size[0] = ix;
  c_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_CandsPitch, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&b_iindx);
  for (i20 = 0; i20 < nm1d2; i20++) {
    for (cindx = 0; cindx < ix; cindx++) {
      c_CandsPitch->data[cindx + c_CandsPitch->size[0] * i20] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i20] -
        1)];
    }
  }

  i20 = b_CandsPitch->size[0] * b_CandsPitch->size[1];
  b_CandsPitch->size[0] = 1;
  b_CandsPitch->size[1] = ixstop;
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsPitch, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  for (i20 = 0; i20 < ixstop; i20++) {
    b_CandsPitch->data[b_CandsPitch->size[0] * i20] = c_CandsPitch->
      data[c_CandsPitch->size[0] * i20];
  }

  emxFree_real_T(&c_CandsPitch);
  st.site = &dh_emlrtRSI;
  avg_voiced = mean(&st, b_CandsPitch);
  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&b_CandsPitch);
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  i20 = CandsPitch->size[0];
  if (!(1 <= i20)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i20, &rc_emlrtBCI, sp);
  }

  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &d_CandsPitch, 2, &yb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &c_iindx, 1, &yb_emlrtRTEI, true);
  ix = CandsPitch->size[0];
  i20 = c_iindx->size[0];
  c_iindx->size[0] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_iindx, i20, (int32_T)sizeof
                    (int32_T), &yb_emlrtRTEI);
  ixstop = iindx->size[1];
  for (i20 = 0; i20 < ixstop; i20++) {
    c_iindx->data[i20] = iindx->data[iindx->size[0] * i20];
  }

  emxInit_real_T(sp, &e_CandsPitch, 2, &yb_emlrtRTEI, true);
  ixstop = c_iindx->size[0];
  i20 = e_CandsPitch->size[0] * e_CandsPitch->size[1];
  e_CandsPitch->size[0] = ix;
  e_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)e_CandsPitch, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  nm1d2 = iindx->size[1];
  emxFree_int32_T(&c_iindx);
  for (i20 = 0; i20 < nm1d2; i20++) {
    for (cindx = 0; cindx < ix; cindx++) {
      e_CandsPitch->data[cindx + e_CandsPitch->size[0] * i20] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i20] -
        1)];
    }
  }

  i20 = d_CandsPitch->size[0] * d_CandsPitch->size[1];
  d_CandsPitch->size[0] = 1;
  d_CandsPitch->size[1] = ixstop;
  emxEnsureCapacity(sp, (emxArray__common *)d_CandsPitch, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  for (i20 = 0; i20 < ixstop; i20++) {
    d_CandsPitch->data[d_CandsPitch->size[0] * i20] = e_CandsPitch->
      data[e_CandsPitch->size[0] * i20];
  }

  emxFree_real_T(&e_CandsPitch);
  st.site = &ch_emlrtRSI;
  std_voiced = b_std(&st, d_CandsPitch);

  /*  Weight the deltas, so that higher merit candidates are considered */
  /*  more favorably */
  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&d_CandsPitch);
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &f_CandsPitch, 2, &yb_emlrtRTEI, true);
  ix = CandsPitch->size[0];
  ndbl = 0.8 * avg_voiced;
  i20 = f_CandsPitch->size[0] * f_CandsPitch->size[1];
  f_CandsPitch->size[0] = ix;
  f_CandsPitch->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)f_CandsPitch, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ixstop = iindx->size[1];
  for (i20 = 0; i20 < ixstop; i20++) {
    for (cindx = 0; cindx < ix; cindx++) {
      f_CandsPitch->data[cindx + f_CandsPitch->size[0] * i20] = CandsPitch->
        data[cindx + CandsPitch->size[0] * (iindx->data[iindx->size[0] * i20] -
        1)] - ndbl;
    }
  }

  st.site = &bh_emlrtRSI;
  c_abs(&st, f_CandsPitch, r18);
  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  emxFree_real_T(&f_CandsPitch);
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  for (i20 = 0; i20 < 2; i20++) {
    iv31[i20] = r18->size[i20];
  }

  emxInit_real_T(sp, &b_CandsMerit, 2, &yb_emlrtRTEI, true);
  ix = CandsMerit->size[0];
  i20 = b_CandsMerit->size[0] * b_CandsMerit->size[1];
  b_CandsMerit->size[0] = ix;
  b_CandsMerit->size[1] = iindx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_CandsMerit, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ixstop = iindx->size[1];
  for (i20 = 0; i20 < ixstop; i20++) {
    for (cindx = 0; cindx < ix; cindx++) {
      b_CandsMerit->data[cindx + b_CandsMerit->size[0] * i20] = CandsMerit->
        data[cindx + CandsMerit->size[0] * (iindx->data[iindx->size[0] * i20] -
        1)];
    }
  }

  for (i20 = 0; i20 < 2; i20++) {
    c_CandsMerit[i20] = b_CandsMerit->size[i20];
  }

  emxFree_real_T(&b_CandsMerit);
  if ((iv31[0] != c_CandsMerit[0]) || (iv31[1] != c_CandsMerit[1])) {
    emlrtSizeEqCheckNDR2012b(&iv31[0], &c_CandsMerit[0], &u_emlrtECI, sp);
  }

  ixstop = CandsPitch->size[1] - 1;
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      nm1d2++;
    }
  }

  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof(int32_T),
                    &yb_emlrtRTEI);
  nm1d2 = 0;
  for (i = 0; i <= ixstop; i++) {
    if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
      iindx->data[nm1d2] = i + 1;
      nm1d2++;
    }
  }

  emxInit_real_T(sp, &delta1, 2, &jc_emlrtRTEI, true);
  i20 = delta1->size[0] * delta1->size[1];
  delta1->size[0] = r18->size[0];
  delta1->size[1] = r18->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)delta1, i20, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  ix = r18->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    ixstop = r18->size[0];
    for (cindx = 0; cindx < ixstop; cindx++) {
      delta1->data[cindx + delta1->size[0] * i20] = r18->data[cindx + r18->size
        [0] * i20] * (3.0 - CandsMerit->data[cindx + CandsMerit->size[0] *
                      (iindx->data[iindx->size[0] * i20] - 1)]);
    }
  }

  emxFree_real_T(&r18);

  /*  Interpolation of the weigthed candidates */
  st.site = &ah_emlrtRSI;
  b_st.site = &hk_emlrtRSI;
  c_st.site = &jj_emlrtRSI;
  if (((delta1->size[0] == 1) && (delta1->size[1] == 1)) || (delta1->size[0] !=
       1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &wf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (delta1->size[0] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &vf_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  unnamed_idx_1 = (uint32_T)delta1->size[1];
  i20 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = (int32_T)unnamed_idx_1;
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i20, (int32_T)sizeof
                    (int32_T), &yb_emlrtRTEI);
  ix = (int32_T)unnamed_idx_1;
  for (i20 = 0; i20 < ix; i20++) {
    iindx->data[i20] = 1;
  }

  n = delta1->size[0];
  d_st.site = &ik_emlrtRSI;
  overflow = ((!(1 > delta1->size[1])) && (delta1->size[1] > 2147483646));
  if (overflow) {
    e_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (i = 0; i + 1 <= delta1->size[1]; i++) {
    nm1d2 = i * n;
    d_st.site = &jk_emlrtRSI;
    ix = i * n + 1;
    ixstop = nm1d2 + n;
    anew = delta1->data[nm1d2];
    itmp = 1;
    if (n > 1) {
      cindx = 1;
      if (muDoubleScalarIsNaN(delta1->data[nm1d2])) {
        e_st.site = &oi_emlrtRSI;
        if ((!(ix + 1 > ixstop)) && (ixstop > 2147483646)) {
          f_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        nm1d2 = ix;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 + 1 <= ixstop)) {
          cindx++;
          ix = nm1d2 + 1;
          if (!muDoubleScalarIsNaN(delta1->data[nm1d2])) {
            anew = delta1->data[nm1d2];
            itmp = cindx;
            exitg1 = true;
          } else {
            nm1d2++;
          }
        }
      }

      if (ix < ixstop) {
        e_st.site = &ni_emlrtRSI;
        if ((!(ix + 1 > ixstop)) && (ixstop > 2147483646)) {
          f_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (ix + 1 <= ixstop) {
          cindx++;
          if (delta1->data[ix] < anew) {
            anew = delta1->data[ix];
            itmp = cindx;
          }

          ix++;
        }
      }
    }

    iindx->data[i] = itmp;
  }

  emxFree_real_T(&delta1);
  i20 = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)Signal, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ix = iindx->size[0] * iindx->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    Signal->data[i20] = iindx->data[i20];
  }

  i20 = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  VPeak_minmrt->size[0] = 1;
  VPeak_minmrt->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VPeak_minmrt, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ix = Signal->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    VPeak_minmrt->data[i20] = 0.0;
  }

  i20 = SHC->size[0] * SHC->size[1];
  SHC->size[0] = 1;
  SHC->size[1] = Signal->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SHC, i20, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  ix = Signal->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    SHC->data[i20] = 0.0;
  }

  n = 1;
  emxInit_int32_T1(sp, &d_iindx, 1, &yb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &e_iindx, 1, &yb_emlrtRTEI, true);
  while (n - 1 <= Signal->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 10);
    ixstop = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= ixstop; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    i20 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof
                      (int32_T), &yb_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= ixstop; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    i20 = CandsPitch->size[0];
    cindx = d_iindx->size[0];
    d_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)d_iindx, cindx, (int32_T)sizeof
                      (int32_T), &yb_emlrtRTEI);
    ix = iindx->size[1];
    for (cindx = 0; cindx < ix; cindx++) {
      d_iindx->data[cindx] = iindx->data[iindx->size[0] * cindx];
    }

    cindx = Signal->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &md_emlrtBCI, sp);
    }

    cindx = (int32_T)Signal->data[n - 1];
    if (!((cindx >= 1) && (cindx <= i20))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &sc_emlrtBCI, sp);
    }

    i20 = d_iindx->size[0];
    if (!((n >= 1) && (n <= i20))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i20, &tc_emlrtBCI, sp);
    }

    i20 = n;
    itmp = VPeak_minmrt->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &nd_emlrtBCI, sp);
    }

    VPeak_minmrt->data[n - 1] = CandsPitch->data[(cindx + CandsPitch->size[0] *
      (iindx->data[iindx->size[0] * (i20 - 1)] - 1)) - 1];
    ixstop = CandsPitch->size[1] - 1;
    nm1d2 = 0;
    for (i = 0; i <= ixstop; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        nm1d2++;
      }
    }

    i20 = iindx->size[0] * iindx->size[1];
    iindx->size[0] = 1;
    iindx->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)iindx, i20, (int32_T)sizeof
                      (int32_T), &yb_emlrtRTEI);
    nm1d2 = 0;
    for (i = 0; i <= ixstop; i++) {
      if (CandsPitch->data[CandsPitch->size[0] * i] > 0.0) {
        iindx->data[nm1d2] = i + 1;
        nm1d2++;
      }
    }

    i20 = CandsMerit->size[0];
    cindx = e_iindx->size[0];
    e_iindx->size[0] = iindx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)e_iindx, cindx, (int32_T)sizeof
                      (int32_T), &yb_emlrtRTEI);
    ix = iindx->size[1];
    for (cindx = 0; cindx < ix; cindx++) {
      e_iindx->data[cindx] = iindx->data[iindx->size[0] * cindx];
    }

    cindx = Signal->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &od_emlrtBCI, sp);
    }

    cindx = (int32_T)Signal->data[n - 1];
    if (!((cindx >= 1) && (cindx <= i20))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &uc_emlrtBCI, sp);
    }

    i20 = e_iindx->size[0];
    if (!((n >= 1) && (n <= i20))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i20, &vc_emlrtBCI, sp);
    }

    i20 = n;
    itmp = SHC->size[1];
    if (!((n >= 1) && (n <= itmp))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, itmp, &pd_emlrtBCI, sp);
    }

    SHC->data[n - 1] = CandsMerit->data[(cindx + CandsMerit->size[0] *
      (iindx->data[iindx->size[0] * (i20 - 1)] - 1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&e_iindx);
  emxFree_int32_T(&d_iindx);
  emxFree_int32_T(&iindx);
  emxFree_real_T(&CandsMerit);
  emxInit_real_T(sp, &b_VPeak_minmrt, 2, &yb_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 11);
  i20 = b_VPeak_minmrt->size[0] * b_VPeak_minmrt->size[1];
  b_VPeak_minmrt->size[0] = 1;
  b_VPeak_minmrt->size[1] = VPeak_minmrt->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_VPeak_minmrt, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    b_VPeak_minmrt->data[i20] = VPeak_minmrt->data[i20];
  }

  st.site = &yg_emlrtRSI;
  Mymedfilt1(&st, b_VPeak_minmrt, muDoubleScalarMax(1.0, Prm->median_value - 2.0),
             VPeak_minmrt);

  /*  VPeak_minmrt_test = medfilt1(VPeak_minmrt, max(1,Prm.median_value-2)); */
  /*  Replace the lowest merit candidates by the median smoothed ones */
  /*  computed from highest merit peaks above ??? */
  n = 1;
  emxFree_real_T(&b_VPeak_minmrt);
  while (n - 1 <= Signal->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 12);
    i20 = VPeak_minmrt->size[1];
    if (!((n >= 1) && (n <= i20))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i20, &ed_emlrtBCI, sp);
    }

    i20 = winix->size[0];
    cindx = Signal->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &gd_emlrtBCI, sp);
    }

    cindx = (int32_T)Signal->data[n - 1];
    if (!((cindx >= 1) && (cindx <= i20))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &fd_emlrtBCI, sp);
    }

    i20 = winix->size[1];
    if (!((n >= 1) && (n <= i20))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i20, &hd_emlrtBCI, sp);
    }

    winix->data[(cindx + winix->size[0] * (n - 1)) - 1] = VPeak_minmrt->data[n -
      1];

    /*  Assign merit for the smoothed peaks */
    i20 = SHC->size[1];
    if (!((n >= 1) && (n <= i20))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i20, &id_emlrtBCI, sp);
    }

    i20 = rowix->size[0];
    cindx = Signal->size[1];
    if (!((n >= 1) && (n <= cindx))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, cindx, &kd_emlrtBCI, sp);
    }

    cindx = (int32_T)Signal->data[n - 1];
    if (!((cindx >= 1) && (cindx <= i20))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, i20, &jd_emlrtBCI, sp);
    }

    i20 = rowix->size[1];
    if (!((n >= 1) && (n <= i20))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, i20, &ld_emlrtBCI, sp);
    }

    rowix->data[(cindx + rowix->size[0] * (n - 1)) - 1] = SHC->data[n - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&Signal);
  emxFree_real_T(&SHC);
  emxInit_real_T(sp, &VPitch, 2, &lc_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 13);

  /*  Use dynamic programming to find best overal path among pitch candidates */
  /*  Dynamic weight for transition costs */
  /*  balance between local and transition costs */
  i20 = VPitch->size[0] * VPitch->size[1];
  VPitch->size[0] = 0;
  VPitch->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)VPitch, i20, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 3, Num_VCands > 2.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 14);
    st.site = &xg_emlrtRSI;
    dynamic5(&st, winix, rowix, Prm->dp5_k1 * std_voiced / avg_voiced,
             VPeak_minmrt);
    i20 = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VPeak_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)VPitch, i20, (int32_T)sizeof
                      (real_T), &yb_emlrtRTEI);
    ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
    for (i20 = 0; i20 < ix; i20++) {
      VPitch->data[i20] = VPeak_minmrt->data[i20];
    }

    st.site = &wg_emlrtRSI;
    b_Mymedfilt1(&st, VPitch, muDoubleScalarMax(Prm->median_value - 2.0, 1.0),
                 VPeak_minmrt);
    i20 = VPitch->size[0] * VPitch->size[1];
    VPitch->size[0] = 1;
    VPitch->size[1] = VPeak_minmrt->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)VPitch, i20, (int32_T)sizeof
                      (real_T), &yb_emlrtRTEI);
    ix = VPeak_minmrt->size[0] * VPeak_minmrt->size[1];
    for (i20 = 0; i20 < ix; i20++) {
      VPitch->data[i20] = VPeak_minmrt->data[i20];
    }

    /*     VPitch_test = medfilt1(VPitch, max(Prm.median_value-2, 1)); */
  } else if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 4, Num_VCands > 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 15);

    /*        for i = 1:Num_VCands   % assume at least 1 voiced candidate */
    /*         VPitch (i) = 150;   %   Not really correct,  but should prevent hang up if only  0,1,2,3 voiced candidates */
    /*        end;  */
    emlrtDynamicBoundsCheckR2012b(1, 1, 0, &xc_emlrtBCI, sp);
    i20 = (int32_T)Num_VCands;
    if (!((i20 >= 1) && (i20 <= 0))) {
      emlrtDynamicBoundsCheckR2012b(i20, 1, 0, &xc_emlrtBCI, sp);
    }

    ix = (int32_T)Num_VCands;
    for (i20 = 0; i20 < ix; i20++) {
      tmp_data[i20] = (int8_T)i20;
    }

    ix = (int32_T)Num_VCands;
    for (i20 = 0; i20 < ix; i20++) {
      VPitch->data[tmp_data[i20]] = 150.0;
    }

    /*    This should only occur for very short pitch tracks, and even then rarely */
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 16);
    emlrtDynamicBoundsCheckR2012b(1, 1, 0, &yc_emlrtBCI, sp);
    VPitch->data[0] = 150.0;

    /*  to handle when no real voiced candidates */
    i20 = CandsPitch->size[1];
    if (!(1 <= i20)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i20, &wc_emlrtBCI, sp);
    }

    Idx_voiced->data[0] = true;
  }

  emxFree_real_T(&VPeak_minmrt);
  emxFree_real_T(&rowix);
  emxFree_real_T(&winix);
  emxFree_real_T(&CandsPitch);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 17);

  /*  Computing some statistics from the voiced frames */
  st.site = &vg_emlrtRSI;
  b_mean(&st, VPitch, pAvg_data, pAvg_size);
  st.site = &ug_emlrtRSI;
  c_std(&st, VPitch, pStd_data, pStd_size);

  /*  Streching out the smoothed pitch track */
  ixstop = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < ixstop; i++) {
    if (Idx_voiced->data[i]) {
      nm1d2++;
    }
  }

  i20 = VPitch->size[0] * VPitch->size[1];
  if (nm1d2 != i20) {
    emlrtSizeEqCheck1DR2012b(nm1d2, i20, &v_emlrtECI, sp);
  }

  ixstop = Idx_voiced->size[1];
  nm1d2 = 0;
  for (i = 0; i < ixstop; i++) {
    if (Idx_voiced->data[i]) {
      i20 = SPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i20, &dd_emlrtBCI, sp);
      }

      SPitch->data[i] = VPitch->data[nm1d2];
      nm1d2++;
    }
  }

  emxFree_real_T(&VPitch);
  emxFree_boolean_T(&Idx_voiced);

  /*  Interpolating thru unvoiced frames */
  /*  SPitch_temp_first = SPitch(1); */
  /*  SPitch_temp_end = SPitch(end); */
  /*  if all(SPitch_temp_first < (pAvg/2)) */
  /*      SPitch(1)   = pAvg;    */
  /*  end */
  /*  if all(SPitch_temp_end < (pAvg/2)) */
  /*      SPitch(end) = pAvg;   */
  /*  end */
  /*   */
  /*  [Indrows, Indcols, Vals] = find(SPitch); */
  /*  SPitch = interp1(Indcols, Vals, 1:numframes, 'pchip'); */
  /*  FILTER_ORDER = 3; */
  /*  flt_b = (ones(1,FILTER_ORDER))/FILTER_ORDER ; */
  /*  flt_a = 1; */
  /*  SPitch = filter(flt_b, flt_a, SPitch); */
  /*  SPitch(Idx_voiced) = filter(flt_b, flt_a, SPitch(Idx_voiced)); */
  /*   above messes up  first few values of SPitch  ---  simple fix up */
  /*   Note--   this fix up should be based on above filter order */
  /*  SPitch(1) = SPitch(3); */
  /*  SPitch(2) = SPitch (4); */
  /*  Create pitch track with Voiced/Unvoiced decision */
  i20 = VUVSPitch->size[0] * VUVSPitch->size[1];
  VUVSPitch->size[0] = 1;
  VUVSPitch->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VUVSPitch, i20, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  ix = SPitch->size[0] * SPitch->size[1];
  for (i20 = 0; i20 < ix; i20++) {
    VUVSPitch->data[i20] = SPitch->data[i20];
  }

  ixstop = VUVEnergy->size[1];
  for (i = 0; i < ixstop; i++) {
    if (!VUVEnergy->data[i]) {
      i20 = VUVSPitch->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i20, &cd_emlrtBCI, sp);
      }

      VUVSPitch->data[i] = 0.0;
    }
  }

  /*  SPitch = SPitch - delta; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (spec_trk.c) */
