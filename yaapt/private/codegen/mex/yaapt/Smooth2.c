/*
 * Smooth2.c
 *
 * Code generation for function 'Smooth2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Smooth2.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "all.h"
#include "mrdivide.h"
#include "isequal.h"
#include "sort1.h"
#include "diff.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo bn_emlrtRSI = { 19, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo cn_emlrtRSI = { 23, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo dn_emlrtRSI = { 24, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo en_emlrtRSI = { 25, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo fn_emlrtRSI = { 36, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo gn_emlrtRSI = { 45, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo hn_emlrtRSI = { 50, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo in_emlrtRSI = { 62, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo jn_emlrtRSI = { 63, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo kn_emlrtRSI = { 64, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo ln_emlrtRSI = { 65, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo mn_emlrtRSI = { 66, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo nn_emlrtRSI = { 67, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo on_emlrtRSI = { 69, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo pn_emlrtRSI = { 70, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo qn_emlrtRSI = { 71, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo rn_emlrtRSI = { 72, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo sn_emlrtRSI = { 73, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo tn_emlrtRSI = { 75, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo un_emlrtRSI = { 76, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo vn_emlrtRSI = { 78, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo wn_emlrtRSI = { 80, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo xn_emlrtRSI = { 81, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo yn_emlrtRSI = { 84, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo ao_emlrtRSI = { 85, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo bo_emlrtRSI = { 86, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo co_emlrtRSI = { 87, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo do_emlrtRSI = { 88, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo eo_emlrtRSI = { 90, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo fo_emlrtRSI = { 91, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo go_emlrtRSI = { 93, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo ho_emlrtRSI = { 95, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo io_emlrtRSI = { 96, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo jo_emlrtRSI = { 99, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo ko_emlrtRSI = { 100, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo lo_emlrtRSI = { 101, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo mo_emlrtRSI = { 102, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRSInfo qo_emlrtRSI = { 31, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo ke_emlrtRTEI = { 1, 18, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRTEInfo le_emlrtRTEI = { 6, 1, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRTEInfo me_emlrtRTEI = { 7, 1, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRTEInfo ne_emlrtRTEI = { 17, 1, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRTEInfo oe_emlrtRTEI = { 19, 1, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRTEInfo pe_emlrtRTEI = { 20, 1, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtRTEInfo qg_emlrtRTEI = { 29, 19, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo rg_emlrtRTEI = { 68, 1, "find",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtECInfo ic_emlrtECI = { -1, 134, 5, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtBCInfo hq_emlrtBCI = { -1, -1, 134, 5, "out", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo iq_emlrtBCI = { -1, -1, 134, 24, "tmp_headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo jq_emlrtBCI = { -1, -1, 134, 9, "tmp_headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtECInfo jc_emlrtECI = { 2, 99, 43, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtECInfo kc_emlrtECI = { 2, 90, 23, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtECInfo lc_emlrtECI = { 2, 84, 19, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m" };

static emlrtBCInfo kq_emlrtBCI = { -1, -1, 7, 15, "arr", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo lq_emlrtBCI = { -1, -1, 5, 9, "arr", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo kc_emlrtDCI = { 134, 67, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 4 };

static emlrtBCInfo mq_emlrtBCI = { -1, -1, 34, 22, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo nq_emlrtBCI = { -1, -1, 37, 5, "visited", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo oq_emlrtBCI = { -1, -1, 42, 19, "sorted_pitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo pq_emlrtBCI = { -1, -1, 43, 25, "sorted_pitcheslength",
  "Smooth2", "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m",
  0 };

static emlrtBCInfo qq_emlrtBCI = { -1, -1, 44, 17, "sorted_idx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo rq_emlrtBCI = { -1, -1, 56, 22, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo sq_emlrtBCI = { -1, -1, 57, 28, "pitcheslength", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo tq_emlrtBCI = { -1, -1, 58, 23, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo uq_emlrtBCI = { -1, -1, 59, 29, "pitcheslength", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo vq_emlrtBCI = { -1, -1, 51, 22, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo wq_emlrtBCI = { -1, -1, 52, 28, "pitcheslength", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo xq_emlrtBCI = { -1, -1, 48, 23, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo yq_emlrtBCI = { -1, -1, 49, 29, "pitcheslength", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo lc_emlrtDCI = { 100, 30, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo ar_emlrtBCI = { -1, -1, 100, 30, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo mc_emlrtDCI = { 101, 34, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo br_emlrtBCI = { -1, -1, 101, 34, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo nc_emlrtDCI = { 102, 30, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo cr_emlrtBCI = { -1, -1, 102, 30, "visited", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo dr_emlrtBCI = { -1, -1, 92, 28, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo oc_emlrtDCI = { 93, 31, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo er_emlrtBCI = { -1, -1, 93, 31, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo fr_emlrtBCI = { -1, -1, 94, 21, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo pc_emlrtDCI = { 95, 35, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo gr_emlrtBCI = { -1, -1, 95, 35, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo qc_emlrtDCI = { 96, 31, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo hr_emlrtBCI = { -1, -1, 96, 31, "visited", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo rc_emlrtDCI = { 86, 31, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo ir_emlrtBCI = { -1, -1, 86, 31, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo sc_emlrtDCI = { 87, 35, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo jr_emlrtBCI = { -1, -1, 87, 35, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo tc_emlrtDCI = { 88, 31, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo kr_emlrtBCI = { -1, -1, 88, 31, "visited", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo lr_emlrtBCI = { -1, -1, 77, 24, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo uc_emlrtDCI = { 78, 27, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo mr_emlrtBCI = { -1, -1, 78, 27, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo nr_emlrtBCI = { -1, -1, 79, 17, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo vc_emlrtDCI = { 80, 31, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo or_emlrtBCI = { -1, -1, 80, 31, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo wc_emlrtDCI = { 81, 27, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo pr_emlrtBCI = { -1, -1, 81, 27, "visited", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo xc_emlrtDCI = { 71, 27, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo qr_emlrtBCI = { -1, -1, 71, 27, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo yc_emlrtDCI = { 72, 31, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo rr_emlrtBCI = { -1, -1, 72, 31, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo ad_emlrtDCI = { 73, 27, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo sr_emlrtBCI = { -1, -1, 73, 27, "visited", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo bd_emlrtDCI = { 65, 27, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo tr_emlrtBCI = { -1, -1, 65, 27, "headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo cd_emlrtDCI = { 66, 31, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo ur_emlrtBCI = { -1, -1, 66, 31, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtDCInfo dd_emlrtDCI = { 67, 27, "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 1 };

static emlrtBCInfo vr_emlrtBCI = { -1, -1, 67, 27, "visited", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo wr_emlrtBCI = { -1, -1, 134, 67, "tmp_headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo xr_emlrtBCI = { -1, -1, 134, 84, "tmp_headidx", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo yr_emlrtBCI = { -1, -1, 134, 44, "headpitches", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo as_emlrtBCI = { -1, -1, 9, 8, "arr", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo bs_emlrtBCI = { -1, -1, 11, 36, "arr", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

static emlrtBCInfo cs_emlrtBCI = { -1, -1, 13, 11, "arr", "Smooth2",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m", 0 };

/* Function Definitions */
void Smooth2(const emlrtStack *sp, const emxArray_real_T *arr, real_T
             Prm_smooth_threshold, emxArray_real_T *out)
{
  emxArray_real_T *headidx;
  emxArray_real_T *headpitches;
  int32_T i52;
  real_T pivot;
  int32_T i;
  emxArray_real_T *prev_headidx;
  int32_T nx;
  int32_T ii;
  emxArray_real_T *b_headidx;
  emxArray_real_T *pitcheslength;
  emxArray_real_T *visited;
  emxArray_real_T *sorted_pitcheslength;
  emxArray_real_T *sorted_idx;
  emxArray_int32_T *iidx;
  emxArray_boolean_T *x;
  emxArray_boolean_T *b_visited;
  emxArray_real_T *c_headidx;
  emxArray_real_T *b_headpitches;
  emxArray_int32_T *b_pitcheslength;
  emxArray_real_T *d_headidx;
  emxArray_int32_T *c_pitcheslength;
  emxArray_real_T *c_headpitches;
  emxArray_int32_T *d_pitcheslength;
  emxArray_real_T *c_visited;
  emxArray_int32_T *e_pitcheslength;
  emxArray_real_T *e_headidx;
  emxArray_int32_T *f_pitcheslength;
  emxArray_real_T *d_headpitches;
  emxArray_int32_T *g_pitcheslength;
  emxArray_real_T *d_visited;
  emxArray_int32_T *h_pitcheslength;
  emxArray_real_T *f_headidx;
  emxArray_int32_T *i_pitcheslength;
  emxArray_real_T *e_headpitches;
  emxArray_int32_T *j_pitcheslength;
  emxArray_real_T *e_visited;
  emxArray_int32_T *k_pitcheslength;
  emxArray_real_T *g_headidx;
  emxArray_int32_T *l_pitcheslength;
  emxArray_real_T *f_headpitches;
  emxArray_int32_T *m_pitcheslength;
  emxArray_real_T *f_visited;
  emxArray_int32_T *n_pitcheslength;
  emxArray_real_T *h_headidx;
  emxArray_int32_T *o_pitcheslength;
  emxArray_real_T *g_headpitches;
  emxArray_int32_T *p_pitcheslength;
  emxArray_real_T *g_visited;
  emxArray_int32_T *q_pitcheslength;
  emxArray_real_T *i_headidx;
  emxArray_int32_T *r_pitcheslength;
  emxArray_real_T *h_headpitches;
  emxArray_int32_T *s_pitcheslength;
  emxArray_real_T *h_visited;
  int32_T exitg1;
  boolean_T guard1 = false;
  int32_T i53;
  int32_T k;
  int32_T idx;
  int32_T ii_data[1];
  boolean_T overflow;
  boolean_T exitg2;
  real_T index_data[1];
  real_T check_pitchlength_data[1];
  boolean_T check_idx_data[1];
  real_T b_check_idx_data[1];
  int32_T check_idx_size[2];
  emxArray_boolean_T c_check_idx_data;
  boolean_T d_check_idx_data[1];
  int32_T b_check_idx_size[2];
  int32_T left_pitch_size[2];
  real_T left_pitch_data[1];
  int32_T left_pitchlength_size[2];
  real_T left_pitchlength_data[1];
  emxArray_boolean_T e_check_idx_data;
  int32_T apnd;
  int32_T right_pitchlength_size[2];
  real_T right_pitch_data[1];
  real_T right_pitchlength_data[1];
  boolean_T headpitches_data[1];
  int32_T headpitches_size[2];
  real_T anew;
  emxArray_boolean_T b_headpitches_data;
  real_T b_apnd;
  boolean_T b_left_pitch_data[1];
  int32_T b_left_pitch_size[2];
  emxArray_boolean_T c_left_pitch_data;
  boolean_T b_guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  boolean_T guard13 = false;
  boolean_T b_right_pitch_data[1];
  int32_T right_pitch_size[2];
  boolean_T d_left_pitch_data[1];
  emxArray_boolean_T c_right_pitch_data;
  int32_T c_left_pitch_size[2];
  boolean_T e_left_pitch_data[1];
  int32_T d_left_pitch_size[2];
  boolean_T b_check_pitchlength_data[1];
  int32_T left_pitchlength[2];
  int32_T check_pitchlength_size[2];
  int32_T right_pitchlength[2];
  boolean_T c_check_pitchlength_data[1];
  emxArray_boolean_T f_left_pitch_data;
  int32_T b_check_pitchlength_size[2];
  boolean_T d_check_pitchlength_data[1];
  emxArray_boolean_T g_left_pitch_data;
  boolean_T e_check_pitchlength_data[1];
  int32_T c_check_pitchlength_size[2];
  emxArray_boolean_T f_check_pitchlength_data;
  int32_T d_check_pitchlength_size[2];
  boolean_T g_check_pitchlength_data[1];
  boolean_T b_left_pitchlength_data[1];
  int32_T e_check_pitchlength_size[2];
  emxArray_boolean_T h_check_pitchlength_data;
  int32_T b_left_pitchlength_size[2];
  boolean_T i_check_pitchlength_data[1];
  boolean_T d_right_pitch_data[1];
  int32_T f_check_pitchlength_size[2];
  emxArray_boolean_T j_check_pitchlength_data;
  int32_T b_right_pitch_size[2];
  emxArray_boolean_T k_check_pitchlength_data;
  boolean_T e_right_pitch_data[1];
  emxArray_boolean_T l_check_pitchlength_data;
  int32_T c_right_pitch_size[2];
  emxArray_boolean_T c_left_pitchlength_data;
  emxArray_boolean_T m_check_pitchlength_data;
  emxArray_boolean_T f_right_pitch_data;
  emxArray_boolean_T g_right_pitch_data;
  int32_T b_left_pitchlength[2];
  int32_T b_right_pitchlength[2];
  boolean_T h_left_pitch_data[1];
  boolean_T d_left_pitchlength_data[1];
  int32_T e_left_pitch_size[2];
  int32_T c_left_pitchlength_size[2];
  int32_T i54;
  boolean_T i_left_pitch_data[1];
  int32_T f_left_pitch_size[2];
  boolean_T j_left_pitch_data[1];
  int32_T i55;
  emxArray_boolean_T k_left_pitch_data;
  int32_T g_left_pitch_size[2];
  int32_T i56;
  emxArray_boolean_T e_left_pitchlength_data;
  int32_T i57;
  emxArray_boolean_T l_left_pitch_data;
  int32_T i58;
  emxArray_boolean_T m_left_pitch_data;
  int32_T i59;
  boolean_T n_check_pitchlength_data[1];
  int32_T c_left_pitchlength[2];
  int32_T g_check_pitchlength_size[2];
  int32_T c_right_pitchlength[2];
  boolean_T o_check_pitchlength_data[1];
  int32_T h_check_pitchlength_size[2];
  emxArray_boolean_T p_check_pitchlength_data;
  boolean_T q_check_pitchlength_data[1];
  boolean_T n_left_pitch_data[1];
  int32_T i_check_pitchlength_size[2];
  int32_T h_left_pitch_size[2];
  emxArray_boolean_T r_check_pitchlength_data;
  emxArray_boolean_T s_check_pitchlength_data;
  real_T f_left_pitchlength_data[1];
  int32_T d_left_pitchlength_size[2];
  emxArray_boolean_T o_left_pitch_data;
  real_T cdiff;
  uint32_T u0;
  boolean_T p_left_pitch_data[1];
  boolean_T t_check_pitchlength_data[1];
  uint32_T u1;
  int32_T i_left_pitch_size[2];
  int32_T j_check_pitchlength_size[2];
  uint32_T u2;
  uint32_T u3;
  uint32_T u4;
  uint32_T u5;
  uint32_T u6;
  emxArray_boolean_T u_check_pitchlength_data;
  uint32_T u7;
  emxArray_boolean_T q_left_pitch_data;
  uint32_T u8;
  uint32_T u9;
  uint32_T u10;
  uint32_T u11;
  boolean_T v_check_pitchlength_data[1];
  int32_T k_check_pitchlength_size[2];
  emxArray_boolean_T w_check_pitchlength_data;
  int32_T i60;
  int32_T i61;
  int32_T i62;
  int32_T i63;
  int32_T i64;
  int32_T i65;
  uint32_T u12;
  uint32_T u13;
  uint32_T u14;
  uint32_T u15;
  uint32_T u16;
  uint32_T u17;
  uint32_T u18;
  uint32_T u19;
  uint32_T u20;
  uint32_T u21;
  uint32_T u22;
  uint32_T u23;
  int32_T i66;
  int32_T i67;
  int32_T i68;
  int32_T i69;
  int32_T i70;
  int32_T i71;
  uint32_T u24;
  uint32_T u25;
  uint32_T u26;
  uint32_T u27;
  uint32_T u28;
  uint32_T u29;
  uint32_T u30;
  uint32_T u31;
  uint32_T u32;
  uint32_T u33;
  uint32_T u34;
  uint32_T u35;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &headidx, 2, &le_emlrtRTEI, true);
  emxInit_real_T(sp, &headpitches, 2, &me_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 23U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 0);
  i52 = arr->size[1];
  if (!(1 <= i52)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i52, &lq_emlrtBCI, sp);
  }

  pivot = arr->data[0];
  i52 = headidx->size[0] * headidx->size[1];
  headidx->size[0] = 1;
  headidx->size[1] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)headidx, i52, (int32_T)sizeof(real_T),
                    &ke_emlrtRTEI);
  headidx->data[0] = 1.0;
  i52 = arr->size[1];
  if (!(1 <= i52)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i52, &kq_emlrtBCI, sp);
  }

  i52 = headpitches->size[0] * headpitches->size[1];
  headpitches->size[0] = 1;
  headpitches->size[1] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)headpitches, i52, (int32_T)sizeof
                    (real_T), &ke_emlrtRTEI);
  headpitches->data[0] = arr->data[0];
  i = 1;
  while (i - 1 <= arr->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 0, 1);
    i52 = arr->size[1];
    if (!((i >= 1) && (i <= i52))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i52, &as_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 0, arr->data[i - 1] != pivot))
    {
      covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 1);
      nx = headidx->size[1];
      i52 = headidx->size[0] * headidx->size[1];
      headidx->size[1] = nx + 1;
      emxEnsureCapacity(sp, (emxArray__common *)headidx, i52, (int32_T)sizeof
                        (real_T), &ke_emlrtRTEI);
      headidx->data[nx] = 1.0 + (real_T)(i - 1);
      nx = headpitches->size[1];
      i52 = headpitches->size[0] * headpitches->size[1];
      headpitches->size[1] = nx + 1;
      emxEnsureCapacity(sp, (emxArray__common *)headpitches, i52, (int32_T)
                        sizeof(real_T), &ke_emlrtRTEI);
      i52 = arr->size[1];
      if (!((i >= 1) && (i <= i52))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i52, &bs_emlrtBCI, sp);
      }

      headpitches->data[nx] = arr->data[i - 1];
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 2);
    i52 = arr->size[1];
    if (!((i >= 1) && (i <= i52))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i52, &cs_emlrtBCI, sp);
    }

    pivot = arr->data[i - 1];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &prev_headidx, 2, &ne_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 3);

  /* idx = 1:length(arr); */
  i52 = prev_headidx->size[0] * prev_headidx->size[1];
  prev_headidx->size[0] = 1;
  prev_headidx->size[1] = headidx->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)prev_headidx, i52, (int32_T)sizeof
                    (real_T), &ke_emlrtRTEI);
  ii = headidx->size[0] * headidx->size[1];
  for (i52 = 0; i52 < ii; i52++) {
    prev_headidx->data[i52] = headidx->data[i52];
  }

  emxInit_real_T(sp, &b_headidx, 2, &ke_emlrtRTEI, true);
  i52 = b_headidx->size[0] * b_headidx->size[1];
  b_headidx->size[0] = 1;
  b_headidx->size[1] = headidx->size[1] + 1;
  emxEnsureCapacity(sp, (emxArray__common *)b_headidx, i52, (int32_T)sizeof
                    (real_T), &ke_emlrtRTEI);
  ii = headidx->size[1];
  for (i52 = 0; i52 < ii; i52++) {
    b_headidx->data[b_headidx->size[0] * i52] = headidx->data[headidx->size[0] *
      i52];
  }

  emxInit_real_T(sp, &pitcheslength, 2, &oe_emlrtRTEI, true);
  emxInit_real_T(sp, &visited, 2, &pe_emlrtRTEI, true);
  b_headidx->data[b_headidx->size[0] * headidx->size[1]] = arr->size[1];
  st.site = &bn_emlrtRSI;
  b_diff(&st, b_headidx, pitcheslength);
  i52 = visited->size[0] * visited->size[1];
  visited->size[0] = 1;
  visited->size[1] = pitcheslength->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)visited, i52, (int32_T)sizeof(real_T),
                    &ke_emlrtRTEI);
  ii = pitcheslength->size[1];
  emxFree_real_T(&b_headidx);
  for (i52 = 0; i52 < ii; i52++) {
    visited->data[i52] = 0.0;
  }

  emxInit_real_T(sp, &sorted_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &sorted_idx, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &iidx, 2, &ke_emlrtRTEI, true);
  emxInit_boolean_T(sp, &x, 2, &ke_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_visited, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &c_headidx, 2, &ke_emlrtRTEI, true);
  emxInit_real_T2(sp, &b_headpitches, 1, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &b_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &d_headidx, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &c_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &c_headpitches, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &d_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &c_visited, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &e_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &e_headidx, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &f_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &d_headpitches, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &g_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &d_visited, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &h_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &f_headidx, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &i_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &e_headpitches, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &j_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &e_visited, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &k_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &g_headidx, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &l_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &f_headpitches, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &m_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &f_visited, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &n_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &h_headidx, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &o_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &g_headpitches, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &p_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &g_visited, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &q_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &i_headidx, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &r_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &h_headpitches, 2, &ke_emlrtRTEI, true);
  emxInit_int32_T(sp, &s_pitcheslength, 2, &ke_emlrtRTEI, true);
  emxInit_real_T(sp, &h_visited, 2, &ke_emlrtRTEI, true);
  do {
    exitg1 = 0;
    covrtLogWhile(&emlrtCoverageInstance, 23U, 0U, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 4);
    i52 = c_headidx->size[0] * c_headidx->size[1];
    c_headidx->size[0] = 1;
    c_headidx->size[1] = headidx->size[1] + 1;
    emxEnsureCapacity(sp, (emxArray__common *)c_headidx, i52, (int32_T)sizeof
                      (real_T), &ke_emlrtRTEI);
    ii = headidx->size[1];
    for (i52 = 0; i52 < ii; i52++) {
      c_headidx->data[c_headidx->size[0] * i52] = headidx->data[headidx->size[0]
        * i52];
    }

    c_headidx->data[c_headidx->size[0] * headidx->size[1]] = arr->size[1];
    st.site = &cn_emlrtRSI;
    b_diff(&st, c_headidx, pitcheslength);
    st.site = &dn_emlrtRSI;
    i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
    sorted_pitcheslength->size[0] = 1;
    sorted_pitcheslength->size[1] = pitcheslength->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)sorted_pitcheslength, i52,
                      (int32_T)sizeof(real_T), &ke_emlrtRTEI);
    ii = pitcheslength->size[0] * pitcheslength->size[1];
    for (i52 = 0; i52 < ii; i52++) {
      sorted_pitcheslength->data[i52] = pitcheslength->data[i52];
    }

    b_st.site = &kj_emlrtRSI;
    g_sort(&b_st, sorted_pitcheslength, iidx);
    i52 = sorted_idx->size[0] * sorted_idx->size[1];
    sorted_idx->size[0] = 1;
    sorted_idx->size[1] = iidx->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)sorted_idx, i52, (int32_T)sizeof
                      (real_T), &ke_emlrtRTEI);
    ii = iidx->size[0] * iidx->size[1];
    for (i52 = 0; i52 < ii; i52++) {
      sorted_idx->data[i52] = iidx->data[i52];
    }

    i52 = b_visited->size[0] * b_visited->size[1];
    b_visited->size[0] = 1;
    b_visited->size[1] = visited->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_visited, i52, (int32_T)sizeof
                      (boolean_T), &ke_emlrtRTEI);
    ii = visited->size[0] * visited->size[1];
    for (i52 = 0; i52 < ii; i52++) {
      b_visited->data[i52] = (visited->data[i52] == 1.0);
    }

    guard1 = false;
    st.site = &en_emlrtRSI;
    if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 1, all(&st, b_visited))) {
      /*          if(isequal(prev_headidx,headidx)&& all((diff(tmp_headidx)>min_length | headpitches==0))) */
      if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 2, e_isequal(prev_headidx,
            headidx))) {
        exitg1 = 1;
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 6);
        i52 = visited->size[0] * visited->size[1];
        visited->size[0] = 1;
        visited->size[1] = pitcheslength->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)visited, i52, (int32_T)sizeof
                          (real_T), &ke_emlrtRTEI);
        ii = pitcheslength->size[1];
        for (i52 = 0; i52 < ii; i52++) {
          visited->data[i52] = 0.0;
        }

        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 7);
      nx = headpitches->size[1];
      ii = sorted_idx->size[0] * sorted_idx->size[1];
      for (i52 = 0; i52 < ii; i52++) {
        i53 = (int32_T)sorted_idx->data[i52];
        if (!((i53 >= 1) && (i53 <= nx))) {
          emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &mq_emlrtBCI, sp);
        }
      }

      i52 = prev_headidx->size[0] * prev_headidx->size[1];
      prev_headidx->size[0] = 1;
      prev_headidx->size[1] = headidx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)prev_headidx, i52, (int32_T)
                        sizeof(real_T), &ke_emlrtRTEI);
      ii = headidx->size[0] * headidx->size[1];
      for (i52 = 0; i52 < ii; i52++) {
        prev_headidx->data[i52] = headidx->data[i52];
      }

      st.site = &fn_emlrtRSI;
      i52 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = visited->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)x, i52, (int32_T)sizeof
                        (boolean_T), &ke_emlrtRTEI);
      ii = visited->size[0] * visited->size[1];
      for (i52 = 0; i52 < ii; i52++) {
        x->data[i52] = (visited->data[i52] == 0.0);
      }

      b_st.site = &ac_emlrtRSI;
      nx = x->size[1];
      k = muIntScalarMin_sint32(1, nx);
      if (k <= x->size[1]) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &rg_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      idx = 0;
      c_st.site = &bc_emlrtRSI;
      overflow = ((!(1 > x->size[1])) && (x->size[1] > 2147483646));
      if (overflow) {
        d_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii <= nx)) {
        if (x->data[ii - 1]) {
          idx = 1;
          ii_data[0] = ii;
          exitg2 = true;
        } else {
          ii++;
        }
      }

      if (idx <= k) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &if_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (k == 1) {
        if (idx == 0) {
          k = 0;
        }
      } else {
        k = !(1 > idx);
      }

      for (i52 = 0; i52 < k; i52++) {
        index_data[i52] = ii_data[i52];
      }

      nx = visited->size[1];
      for (i52 = 0; i52 < k; i52++) {
        i53 = (int32_T)index_data[i52];
        if (!((i53 >= 1) && (i53 <= nx))) {
          emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &nq_emlrtBCI, sp);
        }

        ii_data[i52] = i53;
      }

      for (i52 = 0; i52 < k; i52++) {
        visited->data[ii_data[i52] - 1] = 1.0;
      }

      /* sorted_headidx = headidx(sorted_idx); */
      nx = sorted_idx->size[1];
      for (i52 = 0; i52 < k; i52++) {
        i53 = (int32_T)index_data[i52];
        if (!((i53 >= 1) && (i53 <= nx))) {
          emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &oq_emlrtBCI, sp);
        }
      }

      nx = sorted_pitcheslength->size[1];
      for (i52 = 0; i52 < k; i52++) {
        i53 = (int32_T)index_data[i52];
        if (!((i53 >= 1) && (i53 <= nx))) {
          emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &pq_emlrtBCI, sp);
        }

        check_pitchlength_data[i52] = sorted_pitcheslength->data[i53 - 1];
      }

      nx = sorted_idx->size[1];
      for (i52 = 0; i52 < k; i52++) {
        i53 = (int32_T)index_data[i52];
        if (!((i53 >= 1) && (i53 <= nx))) {
          emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &qq_emlrtBCI, sp);
        }

        b_check_idx_data[i52] = sorted_idx->data[i53 - 1];
      }

      check_idx_size[0] = 1;
      check_idx_size[1] = k;
      for (i52 = 0; i52 < k; i52++) {
        check_idx_data[i52] = (b_check_idx_data[i52] == 1.0);
      }

      c_check_idx_data.data = (boolean_T *)&check_idx_data;
      c_check_idx_data.size = (int32_T *)&check_idx_size;
      c_check_idx_data.allocatedSize = 1;
      c_check_idx_data.numDimensions = 2;
      c_check_idx_data.canFreeData = false;
      st.site = &gn_emlrtRSI;
      if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 3, all(&st,
            &c_check_idx_data))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 8);
        left_pitch_size[1] = 1;
        left_pitch_data[0] = 0.0;
        left_pitchlength_size[0] = 1;
        left_pitchlength_size[1] = 1;
        left_pitchlength_data[0] = 0.0;
        idx = k;
        nx = headpitches->size[1];
        for (i52 = 0; i52 < k; i52++) {
          i53 = (int32_T)(b_check_idx_data[i52] + 1.0);
          if (!((i53 >= 1) && (i53 <= nx))) {
            emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &xq_emlrtBCI, sp);
          }

          right_pitch_data[i52] = headpitches->data[i53 - 1];
        }

        right_pitchlength_size[0] = 1;
        right_pitchlength_size[1] = k;
        nx = pitcheslength->size[1];
        for (i52 = 0; i52 < k; i52++) {
          i53 = (int32_T)(b_check_idx_data[i52] + 1.0);
          if (!((i53 >= 1) && (i53 <= nx))) {
            emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &yq_emlrtBCI, sp);
          }

          right_pitchlength_data[i52] = pitcheslength->data[i53 - 1];
        }
      } else {
        b_check_idx_size[0] = 1;
        b_check_idx_size[1] = k;
        nx = headidx->size[1];
        for (i52 = 0; i52 < k; i52++) {
          d_check_idx_data[i52] = (b_check_idx_data[i52] == nx);
        }

        e_check_idx_data.data = (boolean_T *)&d_check_idx_data;
        e_check_idx_data.size = (int32_T *)&b_check_idx_size;
        e_check_idx_data.allocatedSize = 1;
        e_check_idx_data.numDimensions = 2;
        e_check_idx_data.canFreeData = false;
        st.site = &hn_emlrtRSI;
        if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 4, all(&st,
              &e_check_idx_data))) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 9);
          left_pitch_size[1] = k;
          nx = headpitches->size[1];
          for (i52 = 0; i52 < k; i52++) {
            i53 = (int32_T)(b_check_idx_data[i52] - 1.0);
            if (!((i53 >= 1) && (i53 <= nx))) {
              emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &vq_emlrtBCI, sp);
            }

            left_pitch_data[i52] = headpitches->data[i53 - 1];
          }

          left_pitchlength_size[0] = 1;
          left_pitchlength_size[1] = k;
          nx = pitcheslength->size[1];
          for (i52 = 0; i52 < k; i52++) {
            i53 = (int32_T)(b_check_idx_data[i52] - 1.0);
            if (!((i53 >= 1) && (i53 <= nx))) {
              emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &wq_emlrtBCI, sp);
            }

            left_pitchlength_data[i52] = pitcheslength->data[i53 - 1];
          }

          idx = 1;
          right_pitch_data[0] = 0.0;
          right_pitchlength_size[0] = 1;
          right_pitchlength_size[1] = 1;
          right_pitchlength_data[0] = 0.0;
        } else {
          covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 10);
          left_pitch_size[1] = k;
          nx = headpitches->size[1];
          for (i52 = 0; i52 < k; i52++) {
            i53 = (int32_T)(b_check_idx_data[i52] - 1.0);
            if (!((i53 >= 1) && (i53 <= nx))) {
              emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &rq_emlrtBCI, sp);
            }

            left_pitch_data[i52] = headpitches->data[i53 - 1];
          }

          left_pitchlength_size[0] = 1;
          left_pitchlength_size[1] = k;
          nx = pitcheslength->size[1];
          for (i52 = 0; i52 < k; i52++) {
            i53 = (int32_T)(b_check_idx_data[i52] - 1.0);
            if (!((i53 >= 1) && (i53 <= nx))) {
              emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &sq_emlrtBCI, sp);
            }

            left_pitchlength_data[i52] = pitcheslength->data[i53 - 1];
          }

          idx = k;
          nx = headpitches->size[1];
          for (i52 = 0; i52 < k; i52++) {
            i53 = (int32_T)(b_check_idx_data[i52] + 1.0);
            if (!((i53 >= 1) && (i53 <= nx))) {
              emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &tq_emlrtBCI, sp);
            }

            right_pitch_data[i52] = headpitches->data[i53 - 1];
          }

          right_pitchlength_size[0] = 1;
          right_pitchlength_size[1] = k;
          nx = pitcheslength->size[1];
          for (i52 = 0; i52 < k; i52++) {
            i53 = (int32_T)(b_check_idx_data[i52] + 1.0);
            if (!((i53 >= 1) && (i53 <= nx))) {
              emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &uq_emlrtBCI, sp);
            }

            right_pitchlength_data[i52] = pitcheslength->data[i53 - 1];
          }
        }
      }

      /* Smooth Criteria */
      headpitches_size[0] = 1;
      headpitches_size[1] = k;
      i52 = b_headpitches->size[0];
      b_headpitches->size[0] = sorted_idx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_headpitches, i52, (int32_T)
                        sizeof(real_T), &ke_emlrtRTEI);
      ii = sorted_idx->size[1];
      for (i52 = 0; i52 < ii; i52++) {
        b_headpitches->data[i52] = headpitches->data[(int32_T)sorted_idx->
          data[i52] - 1];
      }

      for (i52 = 0; i52 < k; i52++) {
        headpitches_data[i52] = (b_headpitches->data[(int32_T)index_data[i52] -
          1] != 0.0);
      }

      b_headpitches_data.data = (boolean_T *)&headpitches_data;
      b_headpitches_data.size = (int32_T *)&headpitches_size;
      b_headpitches_data.allocatedSize = 1;
      b_headpitches_data.numDimensions = 2;
      b_headpitches_data.canFreeData = false;
      st.site = &in_emlrtRSI;
      if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 5, all(&st,
            &b_headpitches_data))) {
        b_left_pitch_size[0] = 1;
        b_left_pitch_size[1] = left_pitch_size[1];
        ii = left_pitch_size[1];
        for (i52 = 0; i52 < ii; i52++) {
          b_left_pitch_data[i52] = (left_pitch_data[i52] == 0.0);
        }

        c_left_pitch_data.data = (boolean_T *)&b_left_pitch_data;
        c_left_pitch_data.size = (int32_T *)&b_left_pitch_size;
        c_left_pitch_data.allocatedSize = 1;
        c_left_pitch_data.numDimensions = 2;
        c_left_pitch_data.canFreeData = false;
        b_guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        guard5 = false;
        guard6 = false;
        guard7 = false;
        guard8 = false;
        guard9 = false;
        guard10 = false;
        guard11 = false;
        guard12 = false;
        guard13 = false;
        st.site = &jn_emlrtRSI;
        if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 0, all(&st,
              &c_left_pitch_data))) {
          right_pitch_size[0] = 1;
          right_pitch_size[1] = idx;
          for (i52 = 0; i52 < idx; i52++) {
            b_right_pitch_data[i52] = (right_pitch_data[i52] == 0.0);
          }

          c_right_pitch_data.data = (boolean_T *)&b_right_pitch_data;
          c_right_pitch_data.size = (int32_T *)&right_pitch_size;
          c_right_pitch_data.allocatedSize = 1;
          c_right_pitch_data.numDimensions = 2;
          c_right_pitch_data.canFreeData = false;
          st.site = &jn_emlrtRSI;
          if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 1, all(&st,
                &c_right_pitch_data))) {
            covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 0, true);
            covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 6, true);
            d_check_pitchlength_size[0] = 1;
            d_check_pitchlength_size[1] = k;
            for (i52 = 0; i52 < k; i52++) {
              e_check_pitchlength_data[i52] = (check_pitchlength_data[i52] <
                Prm_smooth_threshold);
            }

            k_check_pitchlength_data.data = (boolean_T *)
              &e_check_pitchlength_data;
            k_check_pitchlength_data.size = (int32_T *)&d_check_pitchlength_size;
            k_check_pitchlength_data.allocatedSize = 1;
            k_check_pitchlength_data.numDimensions = 2;
            k_check_pitchlength_data.canFreeData = false;
            st.site = &kn_emlrtRSI;
            if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 7, all(&st,
                  &k_check_pitchlength_data))) {
              covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 11);
              st.site = &ln_emlrtRSI;
              for (i52 = 0; i52 < k; i52++) {
                left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
              }

              b_st.site = &v_emlrtRSI;
              if (k == 1) {
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                  "Coder:toolbox:colon_operandsMustBeScalars", 0);
              }

              c_st.site = &qo_emlrtRSI;
              d_st.site = &w_emlrtRSI;
              if ((int32_T)left_pitch_data[0] < 1) {
                ii = 0;
                apnd = (int32_T)left_pitch_data[0];
              } else {
                idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                  0.5);
                apnd = idx + 1;
                nx = (idx - (int32_T)left_pitch_data[0]) + 1;
                i55 = (int32_T)left_pitch_data[0];
                if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                    muIntScalarMax_sint32(1, i55)) {
                  idx++;
                  apnd = (int32_T)left_pitch_data[0];
                } else if (nx > 0) {
                  apnd = idx;
                } else {
                  idx++;
                }

                if (idx >= 0) {
                  ii = idx;
                } else {
                  ii = 0;
                }
              }

              i52 = pitcheslength->size[0] * pitcheslength->size[1];
              pitcheslength->size[0] = 1;
              pitcheslength->size[1] = ii;
              emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                                (int32_T)sizeof(real_T), &ke_emlrtRTEI);
              if (ii > 0) {
                pitcheslength->data[0] = 1.0;
                if (ii > 1) {
                  pitcheslength->data[ii - 1] = apnd;
                  nx = (ii - 1) / 2;
                  for (idx = 1; idx < nx; idx++) {
                    pitcheslength->data[idx] = 1.0 + (real_T)idx;
                    pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                  }

                  if (nx << 1 == ii - 1) {
                    pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                  } else {
                    pitcheslength->data[nx] = 1.0 + (real_T)nx;
                    pitcheslength->data[nx + 1] = apnd - nx;
                  }
                }
              }

              st.site = &ln_emlrtRSI;
              for (i52 = 0; i52 < k; i52++) {
                left_pitch_data[i52] = b_check_idx_data[i52] + 2.0;
              }

              b_st.site = &v_emlrtRSI;
              if (k == 1) {
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                  "Coder:toolbox:colon_operandsMustBeScalars", 0);
              }

              c_st.site = &qo_emlrtRSI;
              d_st.site = &w_emlrtRSI;
              if ((uint32_T)headidx->size[1] < (uint32_T)left_pitch_data[0]) {
                ii = 0;
                anew = left_pitch_data[0];
                b_apnd = headidx->size[1];
              } else {
                anew = left_pitch_data[0];
                idx = (int32_T)muDoubleScalarFloor(((real_T)headidx->size[1] -
                  left_pitch_data[0]) + 0.5);
                b_apnd = left_pitch_data[0] + (real_T)idx;
                cdiff = b_apnd - (real_T)headidx->size[1];
                nx = headidx->size[1];
                u2 = (uint32_T)left_pitch_data[0];
                u3 = (uint32_T)nx;
                if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                    muIntScalarMax_uint32(u2, u3)) {
                  idx++;
                  b_apnd = headidx->size[1];
                } else if (cdiff > 0.0) {
                  b_apnd = left_pitch_data[0] + ((real_T)idx - 1.0);
                } else {
                  idx++;
                }

                if (idx >= 0) {
                  ii = idx;
                } else {
                  ii = 0;
                }
              }

              i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
              sorted_pitcheslength->size[0] = 1;
              sorted_pitcheslength->size[1] = ii;
              emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                                i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
              if (ii > 0) {
                sorted_pitcheslength->data[0] = anew;
                if (ii > 1) {
                  sorted_pitcheslength->data[ii - 1] = b_apnd;
                  nx = (ii - 1) / 2;
                  for (idx = 1; idx < nx; idx++) {
                    sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                    sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd -
                      (real_T)idx;
                  }

                  if (nx << 1 == ii - 1) {
                    sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                  } else {
                    sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                    sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                  }
                }
              }

              nx = headidx->size[1];
              i52 = q_pitcheslength->size[0] * q_pitcheslength->size[1];
              q_pitcheslength->size[0] = 1;
              q_pitcheslength->size[1] = pitcheslength->size[1] +
                sorted_pitcheslength->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)q_pitcheslength, i52,
                                (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
              ii = pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                anew = pitcheslength->data[pitcheslength->size[0] * i52];
                if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                  emlrtIntegerCheckR2012b(anew, &bd_emlrtDCI, sp);
                }

                i53 = (int32_T)anew;
                if (!((i53 >= 1) && (i53 <= nx))) {
                  emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &tr_emlrtBCI, sp);
                }

                q_pitcheslength->data[q_pitcheslength->size[0] * i52] = i53;
              }

              ii = sorted_pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                  i52];
                if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                  emlrtIntegerCheckR2012b(anew, &bd_emlrtDCI, sp);
                }

                i53 = (int32_T)anew;
                if (!((i53 >= 1) && (i53 <= nx))) {
                  emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &tr_emlrtBCI, sp);
                }

                q_pitcheslength->data[q_pitcheslength->size[0] * (i52 +
                  pitcheslength->size[1])] = i53;
              }

              i52 = i_headidx->size[0] * i_headidx->size[1];
              i_headidx->size[0] = 1;
              i_headidx->size[1] = q_pitcheslength->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)i_headidx, i52, (int32_T)
                                sizeof(real_T), &ke_emlrtRTEI);
              ii = q_pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                i_headidx->data[i_headidx->size[0] * i52] = headidx->
                  data[q_pitcheslength->data[q_pitcheslength->size[0] * i52] - 1];
              }

              i52 = headidx->size[0] * headidx->size[1];
              headidx->size[0] = 1;
              headidx->size[1] = i_headidx->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)headidx, i52, (int32_T)
                                sizeof(real_T), &ke_emlrtRTEI);
              ii = i_headidx->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                headidx->data[headidx->size[0] * i52] = i_headidx->
                  data[i_headidx->size[0] * i52];
              }

              st.site = &mn_emlrtRSI;
              for (i52 = 0; i52 < k; i52++) {
                left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
              }

              b_st.site = &v_emlrtRSI;
              if (k == 1) {
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                  "Coder:toolbox:colon_operandsMustBeScalars", 0);
              }

              c_st.site = &qo_emlrtRSI;
              d_st.site = &w_emlrtRSI;
              if ((int32_T)left_pitch_data[0] < 1) {
                ii = 0;
                apnd = (int32_T)left_pitch_data[0];
              } else {
                idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                  0.5);
                apnd = idx + 1;
                nx = (idx - (int32_T)left_pitch_data[0]) + 1;
                i61 = (int32_T)left_pitch_data[0];
                if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                    muIntScalarMax_sint32(1, i61)) {
                  idx++;
                  apnd = (int32_T)left_pitch_data[0];
                } else if (nx > 0) {
                  apnd = idx;
                } else {
                  idx++;
                }

                if (idx >= 0) {
                  ii = idx;
                } else {
                  ii = 0;
                }
              }

              i52 = pitcheslength->size[0] * pitcheslength->size[1];
              pitcheslength->size[0] = 1;
              pitcheslength->size[1] = ii;
              emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                                (int32_T)sizeof(real_T), &ke_emlrtRTEI);
              if (ii > 0) {
                pitcheslength->data[0] = 1.0;
                if (ii > 1) {
                  pitcheslength->data[ii - 1] = apnd;
                  nx = (ii - 1) / 2;
                  for (idx = 1; idx < nx; idx++) {
                    pitcheslength->data[idx] = 1.0 + (real_T)idx;
                    pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                  }

                  if (nx << 1 == ii - 1) {
                    pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                  } else {
                    pitcheslength->data[nx] = 1.0 + (real_T)nx;
                    pitcheslength->data[nx + 1] = apnd - nx;
                  }
                }
              }

              st.site = &mn_emlrtRSI;
              for (i52 = 0; i52 < k; i52++) {
                b_check_idx_data[i52] += 2.0;
              }

              b_st.site = &v_emlrtRSI;
              if (k == 1) {
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                  "Coder:toolbox:colon_operandsMustBeScalars", 0);
              }

              c_st.site = &qo_emlrtRSI;
              d_st.site = &w_emlrtRSI;
              if ((uint32_T)headpitches->size[1] < (uint32_T)b_check_idx_data[0])
              {
                ii = 0;
                anew = b_check_idx_data[0];
                b_apnd = headpitches->size[1];
              } else {
                anew = b_check_idx_data[0];
                idx = (int32_T)muDoubleScalarFloor(((real_T)headpitches->size[1]
                  - b_check_idx_data[0]) + 0.5);
                b_apnd = b_check_idx_data[0] + (real_T)idx;
                cdiff = b_apnd - (real_T)headpitches->size[1];
                nx = headpitches->size[1];
                u14 = (uint32_T)b_check_idx_data[0];
                u15 = (uint32_T)nx;
                if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                    muIntScalarMax_uint32(u14, u15)) {
                  idx++;
                  b_apnd = headpitches->size[1];
                } else if (cdiff > 0.0) {
                  b_apnd = b_check_idx_data[0] + ((real_T)idx - 1.0);
                } else {
                  idx++;
                }

                if (idx >= 0) {
                  ii = idx;
                } else {
                  ii = 0;
                }
              }

              i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
              sorted_pitcheslength->size[0] = 1;
              sorted_pitcheslength->size[1] = ii;
              emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                                i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
              if (ii > 0) {
                sorted_pitcheslength->data[0] = anew;
                if (ii > 1) {
                  sorted_pitcheslength->data[ii - 1] = b_apnd;
                  nx = (ii - 1) / 2;
                  for (idx = 1; idx < nx; idx++) {
                    sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                    sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd -
                      (real_T)idx;
                  }

                  if (nx << 1 == ii - 1) {
                    sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                  } else {
                    sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                    sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                  }
                }
              }

              nx = headpitches->size[1];
              i52 = r_pitcheslength->size[0] * r_pitcheslength->size[1];
              r_pitcheslength->size[0] = 1;
              r_pitcheslength->size[1] = pitcheslength->size[1] +
                sorted_pitcheslength->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)r_pitcheslength, i52,
                                (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
              ii = pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                anew = pitcheslength->data[pitcheslength->size[0] * i52];
                if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                  emlrtIntegerCheckR2012b(anew, &cd_emlrtDCI, sp);
                }

                i53 = (int32_T)anew;
                if (!((i53 >= 1) && (i53 <= nx))) {
                  emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &ur_emlrtBCI, sp);
                }

                r_pitcheslength->data[r_pitcheslength->size[0] * i52] = i53;
              }

              ii = sorted_pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                  i52];
                if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                  emlrtIntegerCheckR2012b(anew, &cd_emlrtDCI, sp);
                }

                i53 = (int32_T)anew;
                if (!((i53 >= 1) && (i53 <= nx))) {
                  emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &ur_emlrtBCI, sp);
                }

                r_pitcheslength->data[r_pitcheslength->size[0] * (i52 +
                  pitcheslength->size[1])] = i53;
              }

              i52 = h_headpitches->size[0] * h_headpitches->size[1];
              h_headpitches->size[0] = 1;
              h_headpitches->size[1] = r_pitcheslength->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)h_headpitches, i52,
                                (int32_T)sizeof(real_T), &ke_emlrtRTEI);
              ii = r_pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                h_headpitches->data[h_headpitches->size[0] * i52] =
                  headpitches->data[r_pitcheslength->data[r_pitcheslength->size
                  [0] * i52] - 1];
              }

              i52 = headpitches->size[0] * headpitches->size[1];
              headpitches->size[0] = 1;
              headpitches->size[1] = h_headpitches->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)headpitches, i52,
                                (int32_T)sizeof(real_T), &ke_emlrtRTEI);
              ii = h_headpitches->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                headpitches->data[headpitches->size[0] * i52] =
                  h_headpitches->data[h_headpitches->size[0] * i52];
              }

              st.site = &nn_emlrtRSI;
              for (i52 = 0; i52 < k; i52++) {
                left_pitch_data[i52] = index_data[i52] - 1.0;
              }

              b_st.site = &v_emlrtRSI;
              if (k == 1) {
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                  "Coder:toolbox:colon_operandsMustBeScalars", 0);
              }

              c_st.site = &qo_emlrtRSI;
              d_st.site = &w_emlrtRSI;
              if ((int32_T)left_pitch_data[0] < 1) {
                ii = 0;
                apnd = (int32_T)left_pitch_data[0];
              } else {
                idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                  0.5);
                apnd = idx + 1;
                nx = (idx - (int32_T)left_pitch_data[0]) + 1;
                i67 = (int32_T)left_pitch_data[0];
                if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                    muIntScalarMax_sint32(1, i67)) {
                  idx++;
                  apnd = (int32_T)left_pitch_data[0];
                } else if (nx > 0) {
                  apnd = idx;
                } else {
                  idx++;
                }

                if (idx >= 0) {
                  ii = idx;
                } else {
                  ii = 0;
                }
              }

              i52 = pitcheslength->size[0] * pitcheslength->size[1];
              pitcheslength->size[0] = 1;
              pitcheslength->size[1] = ii;
              emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                                (int32_T)sizeof(real_T), &ke_emlrtRTEI);
              if (ii > 0) {
                pitcheslength->data[0] = 1.0;
                if (ii > 1) {
                  pitcheslength->data[ii - 1] = apnd;
                  nx = (ii - 1) / 2;
                  for (idx = 1; idx < nx; idx++) {
                    pitcheslength->data[idx] = 1.0 + (real_T)idx;
                    pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                  }

                  if (nx << 1 == ii - 1) {
                    pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                  } else {
                    pitcheslength->data[nx] = 1.0 + (real_T)nx;
                    pitcheslength->data[nx + 1] = apnd - nx;
                  }
                }
              }

              st.site = &nn_emlrtRSI;
              for (i52 = 0; i52 < k; i52++) {
                index_data[i52] += 2.0;
              }

              b_st.site = &v_emlrtRSI;
              if (k == 1) {
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                  "Coder:toolbox:colon_operandsMustBeScalars", 0);
              }

              c_st.site = &qo_emlrtRSI;
              d_st.site = &w_emlrtRSI;
              if ((uint32_T)visited->size[1] < (uint32_T)index_data[0]) {
                ii = 0;
                anew = index_data[0];
                b_apnd = visited->size[1];
              } else {
                anew = index_data[0];
                idx = (int32_T)muDoubleScalarFloor(((real_T)visited->size[1] -
                  index_data[0]) + 0.5);
                b_apnd = index_data[0] + (real_T)idx;
                cdiff = b_apnd - (real_T)visited->size[1];
                nx = visited->size[1];
                u26 = (uint32_T)index_data[0];
                u27 = (uint32_T)nx;
                if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                    muIntScalarMax_uint32(u26, u27)) {
                  idx++;
                  b_apnd = visited->size[1];
                } else if (cdiff > 0.0) {
                  b_apnd = index_data[0] + ((real_T)idx - 1.0);
                } else {
                  idx++;
                }

                if (idx >= 0) {
                  ii = idx;
                } else {
                  ii = 0;
                }
              }

              i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
              sorted_pitcheslength->size[0] = 1;
              sorted_pitcheslength->size[1] = ii;
              emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                                i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
              if (ii > 0) {
                sorted_pitcheslength->data[0] = anew;
                if (ii > 1) {
                  sorted_pitcheslength->data[ii - 1] = b_apnd;
                  nx = (ii - 1) / 2;
                  for (k = 1; k < nx; k++) {
                    sorted_pitcheslength->data[k] = anew + (real_T)k;
                    sorted_pitcheslength->data[(ii - k) - 1] = b_apnd - (real_T)
                      k;
                  }

                  if (nx << 1 == ii - 1) {
                    sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                  } else {
                    sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                    sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                  }
                }
              }

              nx = visited->size[1];
              i52 = s_pitcheslength->size[0] * s_pitcheslength->size[1];
              s_pitcheslength->size[0] = 1;
              s_pitcheslength->size[1] = pitcheslength->size[1] +
                sorted_pitcheslength->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)s_pitcheslength, i52,
                                (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
              ii = pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                anew = pitcheslength->data[pitcheslength->size[0] * i52];
                if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                  emlrtIntegerCheckR2012b(anew, &dd_emlrtDCI, sp);
                }

                i53 = (int32_T)anew;
                if (!((i53 >= 1) && (i53 <= nx))) {
                  emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &vr_emlrtBCI, sp);
                }

                s_pitcheslength->data[s_pitcheslength->size[0] * i52] = i53;
              }

              ii = sorted_pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                  i52];
                if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                  emlrtIntegerCheckR2012b(anew, &dd_emlrtDCI, sp);
                }

                i53 = (int32_T)anew;
                if (!((i53 >= 1) && (i53 <= nx))) {
                  emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &vr_emlrtBCI, sp);
                }

                s_pitcheslength->data[s_pitcheslength->size[0] * (i52 +
                  pitcheslength->size[1])] = i53;
              }

              i52 = h_visited->size[0] * h_visited->size[1];
              h_visited->size[0] = 1;
              h_visited->size[1] = s_pitcheslength->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)h_visited, i52, (int32_T)
                                sizeof(real_T), &ke_emlrtRTEI);
              ii = s_pitcheslength->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                h_visited->data[h_visited->size[0] * i52] = visited->
                  data[s_pitcheslength->data[s_pitcheslength->size[0] * i52] - 1];
              }

              i52 = visited->size[0] * visited->size[1];
              visited->size[0] = 1;
              visited->size[1] = h_visited->size[1];
              emxEnsureCapacity(sp, (emxArray__common *)visited, i52, (int32_T)
                                sizeof(real_T), &ke_emlrtRTEI);
              ii = h_visited->size[1];
              for (i52 = 0; i52 < ii; i52++) {
                visited->data[visited->size[0] * i52] = h_visited->
                  data[h_visited->size[0] * i52];
              }
            }
          } else {
            guard13 = true;
          }
        } else {
          guard13 = true;
        }

        if (guard13) {
          covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 0, false);
          covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 6, false);
          c_left_pitch_size[0] = 1;
          c_left_pitch_size[1] = left_pitch_size[1];
          ii = left_pitch_size[1];
          for (i52 = 0; i52 < ii; i52++) {
            d_left_pitch_data[i52] = (left_pitch_data[i52] != 0.0);
          }

          f_left_pitch_data.data = (boolean_T *)&d_left_pitch_data;
          f_left_pitch_data.size = (int32_T *)&c_left_pitch_size;
          f_left_pitch_data.allocatedSize = 1;
          f_left_pitch_data.numDimensions = 2;
          f_left_pitch_data.canFreeData = false;
          st.site = &on_emlrtRSI;
          if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 2, all(&st,
                &f_left_pitch_data))) {
            b_right_pitch_size[0] = 1;
            b_right_pitch_size[1] = idx;
            for (i52 = 0; i52 < idx; i52++) {
              d_right_pitch_data[i52] = (right_pitch_data[i52] == 0.0);
            }

            f_right_pitch_data.data = (boolean_T *)&d_right_pitch_data;
            f_right_pitch_data.size = (int32_T *)&b_right_pitch_size;
            f_right_pitch_data.allocatedSize = 1;
            f_right_pitch_data.numDimensions = 2;
            f_right_pitch_data.canFreeData = false;
            st.site = &on_emlrtRSI;
            if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 3, all(&st,
                  &f_right_pitch_data))) {
              covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 1, true);
              covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 8, true);
              left_pitch_size[0] = 1;
              left_pitch_size[1] = k;
              for (i52 = 0; i52 < k; i52++) {
                left_pitch_data[i52] = check_pitchlength_data[i52];
              }

              st.site = &pn_emlrtRSI;
              mrdivide(&st, left_pitch_data, left_pitch_size,
                       left_pitchlength_data, left_pitchlength_size);
              f_left_pitch_size[0] = 1;
              f_left_pitch_size[1] = left_pitch_size[1];
              ii = left_pitch_size[0] * left_pitch_size[1];
              for (i52 = 0; i52 < ii; i52++) {
                i_left_pitch_data[i52] = (left_pitch_data[i52] < 0.5);
              }

              l_left_pitch_data.data = (boolean_T *)&i_left_pitch_data;
              l_left_pitch_data.size = (int32_T *)&f_left_pitch_size;
              l_left_pitch_data.allocatedSize = 1;
              l_left_pitch_data.numDimensions = 2;
              l_left_pitch_data.canFreeData = false;
              st.site = &pn_emlrtRSI;
              if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 4, all(&st,
                    &l_left_pitch_data))) {
                guard10 = true;
              } else {
                h_check_pitchlength_size[0] = 1;
                h_check_pitchlength_size[1] = k;
                for (i52 = 0; i52 < k; i52++) {
                  o_check_pitchlength_data[i52] = (check_pitchlength_data[i52] <
                    Prm_smooth_threshold);
                }

                r_check_pitchlength_data.data = (boolean_T *)
                  &o_check_pitchlength_data;
                r_check_pitchlength_data.size = (int32_T *)
                  &h_check_pitchlength_size;
                r_check_pitchlength_data.allocatedSize = 1;
                r_check_pitchlength_data.numDimensions = 2;
                r_check_pitchlength_data.canFreeData = false;
                st.site = &pn_emlrtRSI;
                if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 5, all(&st,
                      &r_check_pitchlength_data))) {
                  guard10 = true;
                } else {
                  guard5 = true;
                }
              }
            } else {
              guard12 = true;
            }
          } else {
            guard12 = true;
          }
        }

        if (guard12) {
          covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 1, false);
          covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 8, false);
          d_left_pitch_size[0] = 1;
          d_left_pitch_size[1] = left_pitch_size[1];
          ii = left_pitch_size[1];
          for (i52 = 0; i52 < ii; i52++) {
            e_left_pitch_data[i52] = (left_pitch_data[i52] == 0.0);
          }

          g_left_pitch_data.data = (boolean_T *)&e_left_pitch_data;
          g_left_pitch_data.size = (int32_T *)&d_left_pitch_size;
          g_left_pitch_data.allocatedSize = 1;
          g_left_pitch_data.numDimensions = 2;
          g_left_pitch_data.canFreeData = false;
          st.site = &tn_emlrtRSI;
          if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 7, all(&st,
                &g_left_pitch_data))) {
            c_right_pitch_size[0] = 1;
            c_right_pitch_size[1] = idx;
            for (i52 = 0; i52 < idx; i52++) {
              e_right_pitch_data[i52] = (right_pitch_data[i52] != 0.0);
            }

            g_right_pitch_data.data = (boolean_T *)&e_right_pitch_data;
            g_right_pitch_data.size = (int32_T *)&c_right_pitch_size;
            g_right_pitch_data.allocatedSize = 1;
            g_right_pitch_data.numDimensions = 2;
            g_right_pitch_data.canFreeData = false;
            st.site = &tn_emlrtRSI;
            if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 8, all(&st,
                  &g_right_pitch_data))) {
              covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 3, true);
              covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 10, true);
              left_pitch_size[0] = 1;
              left_pitch_size[1] = k;
              for (i52 = 0; i52 < k; i52++) {
                left_pitch_data[i52] = check_pitchlength_data[i52];
              }

              st.site = &un_emlrtRSI;
              mrdivide(&st, left_pitch_data, left_pitch_size,
                       right_pitchlength_data, right_pitchlength_size);
              g_left_pitch_size[0] = 1;
              g_left_pitch_size[1] = left_pitch_size[1];
              ii = left_pitch_size[0] * left_pitch_size[1];
              for (i52 = 0; i52 < ii; i52++) {
                j_left_pitch_data[i52] = (left_pitch_data[i52] < 0.5);
              }

              m_left_pitch_data.data = (boolean_T *)&j_left_pitch_data;
              m_left_pitch_data.size = (int32_T *)&g_left_pitch_size;
              m_left_pitch_data.allocatedSize = 1;
              m_left_pitch_data.numDimensions = 2;
              m_left_pitch_data.canFreeData = false;
              st.site = &un_emlrtRSI;
              if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 9, all(&st,
                    &m_left_pitch_data))) {
                guard9 = true;
              } else {
                i_check_pitchlength_size[0] = 1;
                i_check_pitchlength_size[1] = k;
                for (i52 = 0; i52 < k; i52++) {
                  q_check_pitchlength_data[i52] = (check_pitchlength_data[i52] <
                    Prm_smooth_threshold);
                }

                s_check_pitchlength_data.data = (boolean_T *)
                  &q_check_pitchlength_data;
                s_check_pitchlength_data.size = (int32_T *)
                  &i_check_pitchlength_size;
                s_check_pitchlength_data.allocatedSize = 1;
                s_check_pitchlength_data.numDimensions = 2;
                s_check_pitchlength_data.canFreeData = false;
                st.site = &un_emlrtRSI;
                if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 10, all(&st,
                      &s_check_pitchlength_data))) {
                  guard9 = true;
                } else {
                  guard4 = true;
                }
              }
            } else {
              guard11 = true;
            }
          } else {
            guard11 = true;
          }
        }

        if (guard11) {
          covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 3, false);
          covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 10, false);
          for (i52 = 0; i52 < 2; i52++) {
            left_pitchlength[i52] = left_pitchlength_size[i52];
            right_pitchlength[i52] = right_pitchlength_size[i52];
          }

          if ((left_pitchlength[0] != right_pitchlength[0]) ||
              (left_pitchlength[1] != right_pitchlength[1])) {
            emlrtSizeEqCheckNDR2012b(&left_pitchlength[0], &right_pitchlength[0],
              &lc_emlrtECI, sp);
          }

          b_left_pitchlength_size[0] = 1;
          b_left_pitchlength_size[1] = left_pitchlength_size[1];
          ii = left_pitchlength_size[1];
          for (i52 = 0; i52 < ii; i52++) {
            b_left_pitchlength_data[i52] = (left_pitchlength_data[i52] >
              right_pitchlength_data[i52]);
          }

          c_left_pitchlength_data.data = (boolean_T *)&b_left_pitchlength_data;
          c_left_pitchlength_data.size = (int32_T *)&b_left_pitchlength_size;
          c_left_pitchlength_data.allocatedSize = 1;
          c_left_pitchlength_data.numDimensions = 2;
          c_left_pitchlength_data.canFreeData = false;
          st.site = &yn_emlrtRSI;
          if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 12, all(&st,
                &c_left_pitchlength_data))) {
            left_pitch_size[0] = 1;
            left_pitch_size[1] = k;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = check_pitchlength_data[i52];
            }

            st.site = &ao_emlrtRSI;
            mrdivide(&st, left_pitch_data, left_pitch_size,
                     left_pitchlength_data, left_pitchlength_size);
            e_left_pitch_size[0] = 1;
            e_left_pitch_size[1] = left_pitch_size[1];
            ii = left_pitch_size[0] * left_pitch_size[1];
            for (i52 = 0; i52 < ii; i52++) {
              h_left_pitch_data[i52] = (left_pitch_data[i52] < 0.5);
            }

            k_left_pitch_data.data = (boolean_T *)&h_left_pitch_data;
            k_left_pitch_data.size = (int32_T *)&e_left_pitch_size;
            k_left_pitch_data.allocatedSize = 1;
            k_left_pitch_data.numDimensions = 2;
            k_left_pitch_data.canFreeData = false;
            st.site = &ao_emlrtRSI;
            if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 12, all(&st,
                  &k_left_pitch_data))) {
              guard8 = true;
            } else {
              g_check_pitchlength_size[0] = 1;
              g_check_pitchlength_size[1] = k;
              for (i52 = 0; i52 < k; i52++) {
                n_check_pitchlength_data[i52] = (check_pitchlength_data[i52] <
                  Prm_smooth_threshold);
              }

              p_check_pitchlength_data.data = (boolean_T *)
                &n_check_pitchlength_data;
              p_check_pitchlength_data.size = (int32_T *)
                &g_check_pitchlength_size;
              p_check_pitchlength_data.allocatedSize = 1;
              p_check_pitchlength_data.numDimensions = 2;
              p_check_pitchlength_data.canFreeData = false;
              st.site = &ao_emlrtRSI;
              if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 13, all(&st,
                    &p_check_pitchlength_data))) {
                guard8 = true;
              } else {
                guard3 = true;
              }
            }
          } else {
            for (i52 = 0; i52 < 2; i52++) {
              b_left_pitchlength[i52] = left_pitchlength_size[i52];
              b_right_pitchlength[i52] = right_pitchlength_size[i52];
            }

            if ((b_left_pitchlength[0] != b_right_pitchlength[0]) ||
                (b_left_pitchlength[1] != b_right_pitchlength[1])) {
              emlrtSizeEqCheckNDR2012b(&b_left_pitchlength[0],
                &b_right_pitchlength[0], &kc_emlrtECI, sp);
            }

            c_left_pitchlength_size[0] = 1;
            c_left_pitchlength_size[1] = left_pitchlength_size[1];
            ii = left_pitchlength_size[1];
            for (i52 = 0; i52 < ii; i52++) {
              d_left_pitchlength_data[i52] = (left_pitchlength_data[i52] <
                right_pitchlength_data[i52]);
            }

            e_left_pitchlength_data.data = (boolean_T *)&d_left_pitchlength_data;
            e_left_pitchlength_data.size = (int32_T *)&c_left_pitchlength_size;
            e_left_pitchlength_data.allocatedSize = 1;
            e_left_pitchlength_data.numDimensions = 2;
            e_left_pitchlength_data.canFreeData = false;
            st.site = &eo_emlrtRSI;
            if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 14, all(&st,
                  &e_left_pitchlength_data))) {
              left_pitch_size[0] = 1;
              left_pitch_size[1] = k;
              for (i52 = 0; i52 < k; i52++) {
                left_pitch_data[i52] = check_pitchlength_data[i52];
              }

              st.site = &fo_emlrtRSI;
              mrdivide(&st, left_pitch_data, left_pitch_size,
                       left_pitchlength_data, left_pitchlength_size);
              h_left_pitch_size[0] = 1;
              h_left_pitch_size[1] = left_pitch_size[1];
              ii = left_pitch_size[0] * left_pitch_size[1];
              for (i52 = 0; i52 < ii; i52++) {
                n_left_pitch_data[i52] = (left_pitch_data[i52] < 0.5);
              }

              o_left_pitch_data.data = (boolean_T *)&n_left_pitch_data;
              o_left_pitch_data.size = (int32_T *)&h_left_pitch_size;
              o_left_pitch_data.allocatedSize = 1;
              o_left_pitch_data.numDimensions = 2;
              o_left_pitch_data.canFreeData = false;
              st.site = &fo_emlrtRSI;
              if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 15, all(&st,
                    &o_left_pitch_data))) {
                guard7 = true;
              } else {
                j_check_pitchlength_size[0] = 1;
                j_check_pitchlength_size[1] = k;
                for (i52 = 0; i52 < k; i52++) {
                  t_check_pitchlength_data[i52] = (check_pitchlength_data[i52] <
                    Prm_smooth_threshold);
                }

                u_check_pitchlength_data.data = (boolean_T *)
                  &t_check_pitchlength_data;
                u_check_pitchlength_data.size = (int32_T *)
                  &j_check_pitchlength_size;
                u_check_pitchlength_data.allocatedSize = 1;
                u_check_pitchlength_data.numDimensions = 2;
                u_check_pitchlength_data.canFreeData = false;
                st.site = &fo_emlrtRSI;
                if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 16, all(&st,
                      &u_check_pitchlength_data))) {
                  guard7 = true;
                } else {
                  guard2 = true;
                }
              }
            } else {
              for (i52 = 0; i52 < 2; i52++) {
                c_left_pitchlength[i52] = left_pitchlength_size[i52];
                c_right_pitchlength[i52] = right_pitchlength_size[i52];
              }

              if ((c_left_pitchlength[0] != c_right_pitchlength[0]) ||
                  (c_left_pitchlength[1] != c_right_pitchlength[1])) {
                emlrtSizeEqCheckNDR2012b(&c_left_pitchlength[0],
                  &c_right_pitchlength[0], &jc_emlrtECI, sp);
              }

              left_pitch_size[0] = 1;
              left_pitch_size[1] = k;
              for (i52 = 0; i52 < k; i52++) {
                left_pitch_data[i52] = check_pitchlength_data[i52];
              }

              d_left_pitchlength_size[0] = 1;
              d_left_pitchlength_size[1] = left_pitchlength_size[1];
              ii = left_pitchlength_size[1];
              for (i52 = 0; i52 < ii; i52++) {
                f_left_pitchlength_data[i52] = left_pitchlength_data[i52] +
                  right_pitchlength_data[i52];
              }

              st.site = &jo_emlrtRSI;
              mrdivide(&st, left_pitch_data, left_pitch_size,
                       f_left_pitchlength_data, d_left_pitchlength_size);
              i_left_pitch_size[0] = 1;
              i_left_pitch_size[1] = left_pitch_size[1];
              ii = left_pitch_size[0] * left_pitch_size[1];
              for (i52 = 0; i52 < ii; i52++) {
                p_left_pitch_data[i52] = (left_pitch_data[i52] < 0.5);
              }

              q_left_pitch_data.data = (boolean_T *)&p_left_pitch_data;
              q_left_pitch_data.size = (int32_T *)&i_left_pitch_size;
              q_left_pitch_data.allocatedSize = 1;
              q_left_pitch_data.numDimensions = 2;
              q_left_pitch_data.canFreeData = false;
              st.site = &jo_emlrtRSI;
              if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 18, all(&st,
                    &q_left_pitch_data))) {
                guard6 = true;
              } else {
                k_check_pitchlength_size[0] = 1;
                k_check_pitchlength_size[1] = k;
                for (i52 = 0; i52 < k; i52++) {
                  v_check_pitchlength_data[i52] = (check_pitchlength_data[i52] <
                    Prm_smooth_threshold);
                }

                w_check_pitchlength_data.data = (boolean_T *)
                  &v_check_pitchlength_data;
                w_check_pitchlength_data.size = (int32_T *)
                  &k_check_pitchlength_size;
                w_check_pitchlength_data.allocatedSize = 1;
                w_check_pitchlength_data.numDimensions = 2;
                w_check_pitchlength_data.canFreeData = false;
                st.site = &jo_emlrtRSI;
                if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 19, all(&st,
                      &w_check_pitchlength_data))) {
                  guard6 = true;
                } else {
                  b_guard1 = true;
                }
              }
            }
          }
        }

        if (guard10) {
          check_pitchlength_size[0] = 1;
          check_pitchlength_size[1] = k;
          for (i52 = 0; i52 < k; i52++) {
            b_check_pitchlength_data[i52] = (check_pitchlength_data[i52] < 50.0);
          }

          f_check_pitchlength_data.data = (boolean_T *)&b_check_pitchlength_data;
          f_check_pitchlength_data.size = (int32_T *)&check_pitchlength_size;
          f_check_pitchlength_data.allocatedSize = 1;
          f_check_pitchlength_data.numDimensions = 2;
          f_check_pitchlength_data.canFreeData = false;
          st.site = &pn_emlrtRSI;
          if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 6, all(&st,
                &f_check_pitchlength_data))) {
            covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 2, true);
            covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 9, true);
            covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 12);
            st.site = &qn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i54 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i54)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &qn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] + 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headidx->size[1] < (uint32_T)left_pitch_data[0]) {
              ii = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headidx->size[1] -
                left_pitch_data[0]) + 0.5);
              b_apnd = left_pitch_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headidx->size[1];
              nx = headidx->size[1];
              u0 = (uint32_T)left_pitch_data[0];
              u1 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u0, u1)) {
                idx++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headidx->size[1];
            i52 = n_pitcheslength->size[0] * n_pitcheslength->size[1];
            n_pitcheslength->size[0] = 1;
            n_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)n_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &xc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &qr_emlrtBCI, sp);
              }

              n_pitcheslength->data[n_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &xc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &qr_emlrtBCI, sp);
              }

              n_pitcheslength->data[n_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = h_headidx->size[0] * h_headidx->size[1];
            h_headidx->size[0] = 1;
            h_headidx->size[1] = n_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)h_headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = n_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              h_headidx->data[h_headidx->size[0] * i52] = headidx->
                data[n_pitcheslength->data[n_pitcheslength->size[0] * i52] - 1];
            }

            i52 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = h_headidx->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = h_headidx->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headidx->data[headidx->size[0] * i52] = h_headidx->data
                [h_headidx->size[0] * i52];
            }

            st.site = &rn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i60 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i60)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &rn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              b_check_idx_data[i52]++;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headpitches->size[1] < (uint32_T)b_check_idx_data[0])
            {
              ii = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headpitches->size[1] -
                b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headpitches->size[1];
              nx = headpitches->size[1];
              u12 = (uint32_T)b_check_idx_data[0];
              u13 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u12, u13)) {
                idx++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headpitches->size[1];
            i52 = o_pitcheslength->size[0] * o_pitcheslength->size[1];
            o_pitcheslength->size[0] = 1;
            o_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)o_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &yc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &rr_emlrtBCI, sp);
              }

              o_pitcheslength->data[o_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &yc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &rr_emlrtBCI, sp);
              }

              o_pitcheslength->data[o_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = g_headpitches->size[0] * g_headpitches->size[1];
            g_headpitches->size[0] = 1;
            g_headpitches->size[1] = o_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)g_headpitches, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            ii = o_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              g_headpitches->data[g_headpitches->size[0] * i52] =
                headpitches->data[o_pitcheslength->data[o_pitcheslength->size[0]
                * i52] - 1];
            }

            i52 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = g_headpitches->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headpitches, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = g_headpitches->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headpitches->data[headpitches->size[0] * i52] =
                g_headpitches->data[g_headpitches->size[0] * i52];
            }

            st.site = &sn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = index_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i66 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i66)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &sn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              index_data[i52]++;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)visited->size[1] < (uint32_T)index_data[0]) {
              ii = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)visited->size[1] -
                index_data[0]) + 0.5);
              b_apnd = index_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)visited->size[1];
              nx = visited->size[1];
              u24 = (uint32_T)index_data[0];
              u25 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u24, u25)) {
                idx++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (k = 1; k < nx; k++) {
                  sorted_pitcheslength->data[k] = anew + (real_T)k;
                  sorted_pitcheslength->data[(ii - k) - 1] = b_apnd - (real_T)k;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = visited->size[1];
            i52 = p_pitcheslength->size[0] * p_pitcheslength->size[1];
            p_pitcheslength->size[0] = 1;
            p_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)p_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &ad_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &sr_emlrtBCI, sp);
              }

              p_pitcheslength->data[p_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &ad_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &sr_emlrtBCI, sp);
              }

              p_pitcheslength->data[p_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = g_visited->size[0] * g_visited->size[1];
            g_visited->size[0] = 1;
            g_visited->size[1] = p_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)g_visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = p_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              g_visited->data[g_visited->size[0] * i52] = visited->
                data[p_pitcheslength->data[p_pitcheslength->size[0] * i52] - 1];
            }

            i52 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = g_visited->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = g_visited->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              visited->data[visited->size[0] * i52] = g_visited->data
                [g_visited->size[0] * i52];
            }
          } else {
            guard5 = true;
          }
        }

        if (guard9) {
          b_check_pitchlength_size[0] = 1;
          b_check_pitchlength_size[1] = k;
          for (i52 = 0; i52 < k; i52++) {
            c_check_pitchlength_data[i52] = (check_pitchlength_data[i52] < 50.0);
          }

          h_check_pitchlength_data.data = (boolean_T *)&c_check_pitchlength_data;
          h_check_pitchlength_data.size = (int32_T *)&b_check_pitchlength_size;
          h_check_pitchlength_data.allocatedSize = 1;
          h_check_pitchlength_data.numDimensions = 2;
          h_check_pitchlength_data.canFreeData = false;
          st.site = &un_emlrtRSI;
          if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 11, all(&st,
                &h_check_pitchlength_data))) {
            covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 4, true);
            covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 11, true);
            covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 13);
            nx = headidx->size[1];
            for (i52 = 0; i52 < k; i52++) {
              i53 = (int32_T)b_check_idx_data[i52];
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &lr_emlrtBCI, sp);
              }

              right_pitch_data[i52] = headidx->data[i53 - 1];
            }

            st.site = &vn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i57 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i57)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &vn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] + 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headidx->size[1] < (uint32_T)left_pitch_data[0]) {
              ii = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headidx->size[1] -
                left_pitch_data[0]) + 0.5);
              b_apnd = left_pitch_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headidx->size[1];
              nx = headidx->size[1];
              u6 = (uint32_T)left_pitch_data[0];
              u7 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u6, u7)) {
                idx++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headidx->size[1];
            i52 = k_pitcheslength->size[0] * k_pitcheslength->size[1];
            k_pitcheslength->size[0] = 1;
            k_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)k_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &uc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &mr_emlrtBCI, sp);
              }

              k_pitcheslength->data[k_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &uc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &mr_emlrtBCI, sp);
              }

              k_pitcheslength->data[k_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = g_headidx->size[0] * g_headidx->size[1];
            g_headidx->size[0] = 1;
            g_headidx->size[1] = k_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)g_headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = k_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              g_headidx->data[g_headidx->size[0] * i52] = headidx->
                data[k_pitcheslength->data[k_pitcheslength->size[0] * i52] - 1];
            }

            i52 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = g_headidx->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = g_headidx->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headidx->data[headidx->size[0] * i52] = g_headidx->data
                [g_headidx->size[0] * i52];
            }

            nx = headidx->size[1];
            for (i52 = 0; i52 < k; i52++) {
              i53 = (int32_T)b_check_idx_data[i52];
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &nr_emlrtBCI, sp);
              }

              ii_data[i52] = i53;
            }

            for (i52 = 0; i52 < k; i52++) {
              headidx->data[ii_data[i52] - 1] = right_pitch_data[i52];
            }

            st.site = &wn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i64 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i64)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &wn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              b_check_idx_data[i52]++;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headpitches->size[1] < (uint32_T)b_check_idx_data[0])
            {
              ii = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headpitches->size[1] -
                b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headpitches->size[1];
              nx = headpitches->size[1];
              u20 = (uint32_T)b_check_idx_data[0];
              u21 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u20, u21)) {
                idx++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headpitches->size[1];
            i52 = l_pitcheslength->size[0] * l_pitcheslength->size[1];
            l_pitcheslength->size[0] = 1;
            l_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)l_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &vc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &or_emlrtBCI, sp);
              }

              l_pitcheslength->data[l_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &vc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &or_emlrtBCI, sp);
              }

              l_pitcheslength->data[l_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = f_headpitches->size[0] * f_headpitches->size[1];
            f_headpitches->size[0] = 1;
            f_headpitches->size[1] = l_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)f_headpitches, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            ii = l_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              f_headpitches->data[f_headpitches->size[0] * i52] =
                headpitches->data[l_pitcheslength->data[l_pitcheslength->size[0]
                * i52] - 1];
            }

            i52 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = f_headpitches->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headpitches, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = f_headpitches->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headpitches->data[headpitches->size[0] * i52] =
                f_headpitches->data[f_headpitches->size[0] * i52];
            }

            st.site = &xn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = index_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i70 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i70)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &xn_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              index_data[i52]++;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)visited->size[1] < (uint32_T)index_data[0]) {
              ii = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)visited->size[1] -
                index_data[0]) + 0.5);
              b_apnd = index_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)visited->size[1];
              nx = visited->size[1];
              u32 = (uint32_T)index_data[0];
              u33 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u32, u33)) {
                idx++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (k = 1; k < nx; k++) {
                  sorted_pitcheslength->data[k] = anew + (real_T)k;
                  sorted_pitcheslength->data[(ii - k) - 1] = b_apnd - (real_T)k;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = visited->size[1];
            i52 = m_pitcheslength->size[0] * m_pitcheslength->size[1];
            m_pitcheslength->size[0] = 1;
            m_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)m_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &wc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &pr_emlrtBCI, sp);
              }

              m_pitcheslength->data[m_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &wc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &pr_emlrtBCI, sp);
              }

              m_pitcheslength->data[m_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = f_visited->size[0] * f_visited->size[1];
            f_visited->size[0] = 1;
            f_visited->size[1] = m_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)f_visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = m_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              f_visited->data[f_visited->size[0] * i52] = visited->
                data[m_pitcheslength->data[m_pitcheslength->size[0] * i52] - 1];
            }

            i52 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = f_visited->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = f_visited->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              visited->data[visited->size[0] * i52] = f_visited->data
                [f_visited->size[0] * i52];
            }
          } else {
            guard4 = true;
          }
        }

        if (guard8) {
          c_check_pitchlength_size[0] = 1;
          c_check_pitchlength_size[1] = k;
          for (i52 = 0; i52 < k; i52++) {
            d_check_pitchlength_data[i52] = (check_pitchlength_data[i52] < 50.0);
          }

          j_check_pitchlength_data.data = (boolean_T *)&d_check_pitchlength_data;
          j_check_pitchlength_data.size = (int32_T *)&c_check_pitchlength_size;
          j_check_pitchlength_data.allocatedSize = 1;
          j_check_pitchlength_data.numDimensions = 2;
          j_check_pitchlength_data.canFreeData = false;
          st.site = &ao_emlrtRSI;
          if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 14, all(&st,
                &j_check_pitchlength_data))) {
            covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 5, true);
            covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 13, true);
            covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 14);
            st.site = &bo_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i56 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i56)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &bo_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] + 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headidx->size[1] < (uint32_T)left_pitch_data[0]) {
              ii = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headidx->size[1] -
                left_pitch_data[0]) + 0.5);
              b_apnd = left_pitch_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headidx->size[1];
              nx = headidx->size[1];
              u4 = (uint32_T)left_pitch_data[0];
              u5 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u4, u5)) {
                idx++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headidx->size[1];
            i52 = h_pitcheslength->size[0] * h_pitcheslength->size[1];
            h_pitcheslength->size[0] = 1;
            h_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)h_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &rc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &ir_emlrtBCI, sp);
              }

              h_pitcheslength->data[h_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &rc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &ir_emlrtBCI, sp);
              }

              h_pitcheslength->data[h_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = f_headidx->size[0] * f_headidx->size[1];
            f_headidx->size[0] = 1;
            f_headidx->size[1] = h_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)f_headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = h_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              f_headidx->data[f_headidx->size[0] * i52] = headidx->
                data[h_pitcheslength->data[h_pitcheslength->size[0] * i52] - 1];
            }

            i52 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = f_headidx->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = f_headidx->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headidx->data[headidx->size[0] * i52] = f_headidx->data
                [f_headidx->size[0] * i52];
            }

            st.site = &co_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i62 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i62)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &co_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              b_check_idx_data[i52]++;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headpitches->size[1] < (uint32_T)b_check_idx_data[0])
            {
              ii = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headpitches->size[1] -
                b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headpitches->size[1];
              nx = headpitches->size[1];
              u16 = (uint32_T)b_check_idx_data[0];
              u17 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u16, u17)) {
                idx++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headpitches->size[1];
            i52 = i_pitcheslength->size[0] * i_pitcheslength->size[1];
            i_pitcheslength->size[0] = 1;
            i_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)i_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &sc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &jr_emlrtBCI, sp);
              }

              i_pitcheslength->data[i_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &sc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &jr_emlrtBCI, sp);
              }

              i_pitcheslength->data[i_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = e_headpitches->size[0] * e_headpitches->size[1];
            e_headpitches->size[0] = 1;
            e_headpitches->size[1] = i_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)e_headpitches, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            ii = i_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              e_headpitches->data[e_headpitches->size[0] * i52] =
                headpitches->data[i_pitcheslength->data[i_pitcheslength->size[0]
                * i52] - 1];
            }

            i52 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = e_headpitches->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headpitches, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = e_headpitches->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headpitches->data[headpitches->size[0] * i52] =
                e_headpitches->data[e_headpitches->size[0] * i52];
            }

            st.site = &do_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = index_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i68 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i68)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &do_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              index_data[i52]++;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)visited->size[1] < (uint32_T)index_data[0]) {
              ii = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)visited->size[1] -
                index_data[0]) + 0.5);
              b_apnd = index_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)visited->size[1];
              nx = visited->size[1];
              u28 = (uint32_T)index_data[0];
              u29 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u28, u29)) {
                idx++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (k = 1; k < nx; k++) {
                  sorted_pitcheslength->data[k] = anew + (real_T)k;
                  sorted_pitcheslength->data[(ii - k) - 1] = b_apnd - (real_T)k;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = visited->size[1];
            i52 = j_pitcheslength->size[0] * j_pitcheslength->size[1];
            j_pitcheslength->size[0] = 1;
            j_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)j_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &tc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &kr_emlrtBCI, sp);
              }

              j_pitcheslength->data[j_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &tc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &kr_emlrtBCI, sp);
              }

              j_pitcheslength->data[j_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = e_visited->size[0] * e_visited->size[1];
            e_visited->size[0] = 1;
            e_visited->size[1] = j_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)e_visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = j_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              e_visited->data[e_visited->size[0] * i52] = visited->
                data[j_pitcheslength->data[j_pitcheslength->size[0] * i52] - 1];
            }

            i52 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = e_visited->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = e_visited->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              visited->data[visited->size[0] * i52] = e_visited->data
                [e_visited->size[0] * i52];
            }
          } else {
            guard3 = true;
          }
        }

        if (guard7) {
          e_check_pitchlength_size[0] = 1;
          e_check_pitchlength_size[1] = k;
          for (i52 = 0; i52 < k; i52++) {
            g_check_pitchlength_data[i52] = (check_pitchlength_data[i52] < 50.0);
          }

          l_check_pitchlength_data.data = (boolean_T *)&g_check_pitchlength_data;
          l_check_pitchlength_data.size = (int32_T *)&e_check_pitchlength_size;
          l_check_pitchlength_data.allocatedSize = 1;
          l_check_pitchlength_data.numDimensions = 2;
          l_check_pitchlength_data.canFreeData = false;
          st.site = &fo_emlrtRSI;
          if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 17, all(&st,
                &l_check_pitchlength_data))) {
            covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 6, true);
            covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 15, true);
            covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 15);
            nx = headidx->size[1];
            for (i52 = 0; i52 < k; i52++) {
              i53 = (int32_T)b_check_idx_data[i52];
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &dr_emlrtBCI, sp);
              }

              right_pitch_data[i52] = headidx->data[i53 - 1];
            }

            st.site = &go_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i59 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i59)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &go_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] + 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headidx->size[1] < (uint32_T)left_pitch_data[0]) {
              ii = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headidx->size[1] -
                left_pitch_data[0]) + 0.5);
              b_apnd = left_pitch_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headidx->size[1];
              nx = headidx->size[1];
              u10 = (uint32_T)left_pitch_data[0];
              u11 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u10, u11)) {
                idx++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headidx->size[1];
            i52 = e_pitcheslength->size[0] * e_pitcheslength->size[1];
            e_pitcheslength->size[0] = 1;
            e_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)e_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &oc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &er_emlrtBCI, sp);
              }

              e_pitcheslength->data[e_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &oc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &er_emlrtBCI, sp);
              }

              e_pitcheslength->data[e_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = e_headidx->size[0] * e_headidx->size[1];
            e_headidx->size[0] = 1;
            e_headidx->size[1] = e_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)e_headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = e_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              e_headidx->data[e_headidx->size[0] * i52] = headidx->
                data[e_pitcheslength->data[e_pitcheslength->size[0] * i52] - 1];
            }

            i52 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = e_headidx->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = e_headidx->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headidx->data[headidx->size[0] * i52] = e_headidx->data
                [e_headidx->size[0] * i52];
            }

            nx = headidx->size[1];
            for (i52 = 0; i52 < k; i52++) {
              i53 = (int32_T)b_check_idx_data[i52];
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &fr_emlrtBCI, sp);
              }

              ii_data[i52] = i53;
            }

            for (i52 = 0; i52 < k; i52++) {
              headidx->data[ii_data[i52] - 1] = right_pitch_data[i52];
            }

            st.site = &ho_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i65 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i65)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &ho_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              b_check_idx_data[i52]++;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headpitches->size[1] < (uint32_T)b_check_idx_data[0])
            {
              ii = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headpitches->size[1] -
                b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headpitches->size[1];
              nx = headpitches->size[1];
              u22 = (uint32_T)b_check_idx_data[0];
              u23 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u22, u23)) {
                idx++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headpitches->size[1];
            i52 = f_pitcheslength->size[0] * f_pitcheslength->size[1];
            f_pitcheslength->size[0] = 1;
            f_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)f_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &pc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &gr_emlrtBCI, sp);
              }

              f_pitcheslength->data[f_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &pc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &gr_emlrtBCI, sp);
              }

              f_pitcheslength->data[f_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = d_headpitches->size[0] * d_headpitches->size[1];
            d_headpitches->size[0] = 1;
            d_headpitches->size[1] = f_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)d_headpitches, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            ii = f_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              d_headpitches->data[d_headpitches->size[0] * i52] =
                headpitches->data[f_pitcheslength->data[f_pitcheslength->size[0]
                * i52] - 1];
            }

            i52 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = d_headpitches->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headpitches, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = d_headpitches->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headpitches->data[headpitches->size[0] * i52] =
                d_headpitches->data[d_headpitches->size[0] * i52];
            }

            st.site = &io_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = index_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i71 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i71)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &io_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              index_data[i52]++;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)visited->size[1] < (uint32_T)index_data[0]) {
              ii = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)visited->size[1] -
                index_data[0]) + 0.5);
              b_apnd = index_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)visited->size[1];
              nx = visited->size[1];
              u34 = (uint32_T)index_data[0];
              u35 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u34, u35)) {
                idx++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (k = 1; k < nx; k++) {
                  sorted_pitcheslength->data[k] = anew + (real_T)k;
                  sorted_pitcheslength->data[(ii - k) - 1] = b_apnd - (real_T)k;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = visited->size[1];
            i52 = g_pitcheslength->size[0] * g_pitcheslength->size[1];
            g_pitcheslength->size[0] = 1;
            g_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)g_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &qc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &hr_emlrtBCI, sp);
              }

              g_pitcheslength->data[g_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &qc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &hr_emlrtBCI, sp);
              }

              g_pitcheslength->data[g_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = d_visited->size[0] * d_visited->size[1];
            d_visited->size[0] = 1;
            d_visited->size[1] = g_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)d_visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = g_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              d_visited->data[d_visited->size[0] * i52] = visited->
                data[g_pitcheslength->data[g_pitcheslength->size[0] * i52] - 1];
            }

            i52 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = d_visited->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = d_visited->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              visited->data[visited->size[0] * i52] = d_visited->data
                [d_visited->size[0] * i52];
            }
          } else {
            guard2 = true;
          }
        }

        if (guard6) {
          f_check_pitchlength_size[0] = 1;
          f_check_pitchlength_size[1] = k;
          for (i52 = 0; i52 < k; i52++) {
            i_check_pitchlength_data[i52] = (check_pitchlength_data[i52] < 50.0);
          }

          m_check_pitchlength_data.data = (boolean_T *)&i_check_pitchlength_data;
          m_check_pitchlength_data.size = (int32_T *)&f_check_pitchlength_size;
          m_check_pitchlength_data.allocatedSize = 1;
          m_check_pitchlength_data.numDimensions = 2;
          m_check_pitchlength_data.canFreeData = false;
          st.site = &jo_emlrtRSI;
          if (covrtLogCond(&emlrtCoverageInstance, 23U, 0U, 20, all(&st,
                &m_check_pitchlength_data))) {
            covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 7, true);
            covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 16, true);
            covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 16);
            st.site = &ko_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i58 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i58)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &ko_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] + 2.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headidx->size[1] < (uint32_T)left_pitch_data[0]) {
              ii = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headidx->size[1] -
                left_pitch_data[0]) + 0.5);
              b_apnd = left_pitch_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headidx->size[1];
              nx = headidx->size[1];
              u8 = (uint32_T)left_pitch_data[0];
              u9 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u8, u9)) {
                idx++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headidx->size[1];
            i52 = b_pitcheslength->size[0] * b_pitcheslength->size[1];
            b_pitcheslength->size[0] = 1;
            b_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)b_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &lc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &ar_emlrtBCI, sp);
              }

              b_pitcheslength->data[b_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &lc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &ar_emlrtBCI, sp);
              }

              b_pitcheslength->data[b_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = d_headidx->size[0] * d_headidx->size[1];
            d_headidx->size[0] = 1;
            d_headidx->size[1] = b_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)d_headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = b_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              d_headidx->data[d_headidx->size[0] * i52] = headidx->
                data[b_pitcheslength->data[b_pitcheslength->size[0] * i52] - 1];
            }

            i52 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = d_headidx->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headidx, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = d_headidx->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headidx->data[headidx->size[0] * i52] = d_headidx->data
                [d_headidx->size[0] * i52];
            }

            st.site = &lo_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = b_check_idx_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i63 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i63)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &lo_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              b_check_idx_data[i52] += 2.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)headpitches->size[1] < (uint32_T)b_check_idx_data[0])
            {
              ii = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)headpitches->size[1] -
                b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)headpitches->size[1];
              nx = headpitches->size[1];
              u18 = (uint32_T)b_check_idx_data[0];
              u19 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u18, u19)) {
                idx++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  sorted_pitcheslength->data[idx] = anew + (real_T)idx;
                  sorted_pitcheslength->data[(ii - idx) - 1] = b_apnd - (real_T)
                    idx;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = headpitches->size[1];
            i52 = c_pitcheslength->size[0] * c_pitcheslength->size[1];
            c_pitcheslength->size[0] = 1;
            c_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)c_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &mc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &br_emlrtBCI, sp);
              }

              c_pitcheslength->data[c_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &mc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &br_emlrtBCI, sp);
              }

              c_pitcheslength->data[c_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = c_headpitches->size[0] * c_headpitches->size[1];
            c_headpitches->size[0] = 1;
            c_headpitches->size[1] = c_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)c_headpitches, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            ii = c_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              c_headpitches->data[c_headpitches->size[0] * i52] =
                headpitches->data[c_pitcheslength->data[c_pitcheslength->size[0]
                * i52] - 1];
            }

            i52 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = c_headpitches->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)headpitches, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = c_headpitches->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              headpitches->data[headpitches->size[0] * i52] =
                c_headpitches->data[c_headpitches->size[0] * i52];
            }

            st.site = &mo_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              left_pitch_data[i52] = index_data[i52] - 1.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((int32_T)left_pitch_data[0] < 1) {
              ii = 0;
              apnd = (int32_T)left_pitch_data[0];
            } else {
              idx = (int32_T)muDoubleScalarFloor((left_pitch_data[0] - 1.0) +
                0.5);
              apnd = idx + 1;
              nx = (idx - (int32_T)left_pitch_data[0]) + 1;
              i69 = (int32_T)left_pitch_data[0];
              if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_sint32(1, i69)) {
                idx++;
                apnd = (int32_T)left_pitch_data[0];
              } else if (nx > 0) {
                apnd = idx;
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)pitcheslength, i52,
                              (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              pitcheslength->data[0] = 1.0;
              if (ii > 1) {
                pitcheslength->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 1; idx < nx; idx++) {
                  pitcheslength->data[idx] = 1.0 + (real_T)idx;
                  pitcheslength->data[(ii - idx) - 1] = apnd - idx;
                }

                if (nx << 1 == ii - 1) {
                  pitcheslength->data[nx] = (1.0 + (real_T)apnd) / 2.0;
                } else {
                  pitcheslength->data[nx] = 1.0 + (real_T)nx;
                  pitcheslength->data[nx + 1] = apnd - nx;
                }
              }
            }

            st.site = &mo_emlrtRSI;
            for (i52 = 0; i52 < k; i52++) {
              index_data[i52] += 2.0;
            }

            b_st.site = &v_emlrtRSI;
            if (k == 1) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &qg_emlrtRTEI,
                "Coder:toolbox:colon_operandsMustBeScalars", 0);
            }

            c_st.site = &qo_emlrtRSI;
            d_st.site = &w_emlrtRSI;
            if ((uint32_T)visited->size[1] < (uint32_T)index_data[0]) {
              ii = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              idx = (int32_T)muDoubleScalarFloor(((real_T)visited->size[1] -
                index_data[0]) + 0.5);
              b_apnd = index_data[0] + (real_T)idx;
              cdiff = b_apnd - (real_T)visited->size[1];
              nx = visited->size[1];
              u30 = (uint32_T)index_data[0];
              u31 = (uint32_T)nx;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
                  muIntScalarMax_uint32(u30, u31)) {
                idx++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((real_T)idx - 1.0);
              } else {
                idx++;
              }

              if (idx >= 0) {
                ii = idx;
              } else {
                ii = 0;
              }
            }

            i52 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ii;
            emxEnsureCapacity(&d_st, (emxArray__common *)sorted_pitcheslength,
                              i52, (int32_T)sizeof(real_T), &ke_emlrtRTEI);
            if (ii > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ii > 1) {
                sorted_pitcheslength->data[ii - 1] = b_apnd;
                nx = (ii - 1) / 2;
                for (k = 1; k < nx; k++) {
                  sorted_pitcheslength->data[k] = anew + (real_T)k;
                  sorted_pitcheslength->data[(ii - k) - 1] = b_apnd - (real_T)k;
                }

                if (nx << 1 == ii - 1) {
                  sorted_pitcheslength->data[nx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[nx] = anew + (real_T)nx;
                  sorted_pitcheslength->data[nx + 1] = b_apnd - (real_T)nx;
                }
              }
            }

            nx = visited->size[1];
            i52 = d_pitcheslength->size[0] * d_pitcheslength->size[1];
            d_pitcheslength->size[0] = 1;
            d_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)d_pitcheslength, i52,
                              (int32_T)sizeof(int32_T), &ke_emlrtRTEI);
            ii = pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = pitcheslength->data[pitcheslength->size[0] * i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &nc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &cr_emlrtBCI, sp);
              }

              d_pitcheslength->data[d_pitcheslength->size[0] * i52] = i53;
            }

            ii = sorted_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              anew = sorted_pitcheslength->data[sorted_pitcheslength->size[0] *
                i52];
              if (anew != (int32_T)muDoubleScalarFloor(anew)) {
                emlrtIntegerCheckR2012b(anew, &nc_emlrtDCI, sp);
              }

              i53 = (int32_T)anew;
              if (!((i53 >= 1) && (i53 <= nx))) {
                emlrtDynamicBoundsCheckR2012b(i53, 1, nx, &cr_emlrtBCI, sp);
              }

              d_pitcheslength->data[d_pitcheslength->size[0] * (i52 +
                pitcheslength->size[1])] = i53;
            }

            i52 = c_visited->size[0] * c_visited->size[1];
            c_visited->size[0] = 1;
            c_visited->size[1] = d_pitcheslength->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)c_visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = d_pitcheslength->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              c_visited->data[c_visited->size[0] * i52] = visited->
                data[d_pitcheslength->data[d_pitcheslength->size[0] * i52] - 1];
            }

            i52 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = c_visited->size[1];
            emxEnsureCapacity(sp, (emxArray__common *)visited, i52, (int32_T)
                              sizeof(real_T), &ke_emlrtRTEI);
            ii = c_visited->size[1];
            for (i52 = 0; i52 < ii; i52++) {
              visited->data[visited->size[0] * i52] = c_visited->data
                [c_visited->size[0] * i52];
            }
          } else {
            b_guard1 = true;
          }
        }

        if (guard5) {
          covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 2, false);
          covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 9, false);
        }

        if (guard4) {
          covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 4, false);
          covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 11, false);
        }

        if (guard3) {
          covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 5, false);
          covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 13, false);
        }

        if (guard2) {
          covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 6, false);
          covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 15, false);
        }

        if (b_guard1) {
          covrtLogMcdc(&emlrtCoverageInstance, 23U, 0U, 7, false);
          covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 16, false);
        }

        /*      elseif(check_idx~=1&&check_idx~=length(headidx)) */
        /*             if(left_pitchlength>right_pitchlength) */
        /*                 if(((check_pitchlength/left_pitchlength<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length) */
        /*                      headidx = headidx([1:check_idx-1, check_idx+1:end]); */
        /*                      headpitches = headpitches([1:check_idx-1, check_idx+1:end]); */
        /*                      visited = visited([1:index-1, index+1:end]);              */
        /*                 end */
        /*             elseif(left_pitchlength < right_pitchlength) */
        /*                 if(((check_pitchlength/left_pitchlength<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length) */
        /*                      temp = headidx(check_idx); */
        /*                      headidx = headidx([1:check_idx-1, check_idx+1:end]); */
        /*                      headidx(check_idx) = temp; */
        /*                      headpitches = headpitches([1:check_idx-1, check_idx+1:end]); */
        /*                      visited = visited([1:index-1, index+1:end]);                    */
        /*                 end */
        /*             else */
        /*                 if(((check_pitchlength/(left_pitchlength+right_pitchlength)<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length) */
        /*                     headidx = headidx([1:check_idx-1, check_idx+2:end]); */
        /*                     headpitches = headpitches([1:check_idx-1, check_idx+2:end]); */
        /*                     visited = visited([1:index-1, index+2:end]); */
        /*                 end */
        /*             end */
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  } while (exitg1 == 0);

  emxFree_real_T(&h_visited);
  emxFree_int32_T(&s_pitcheslength);
  emxFree_real_T(&h_headpitches);
  emxFree_int32_T(&r_pitcheslength);
  emxFree_real_T(&i_headidx);
  emxFree_int32_T(&q_pitcheslength);
  emxFree_real_T(&g_visited);
  emxFree_int32_T(&p_pitcheslength);
  emxFree_real_T(&g_headpitches);
  emxFree_int32_T(&o_pitcheslength);
  emxFree_real_T(&h_headidx);
  emxFree_int32_T(&n_pitcheslength);
  emxFree_real_T(&f_visited);
  emxFree_int32_T(&m_pitcheslength);
  emxFree_real_T(&f_headpitches);
  emxFree_int32_T(&l_pitcheslength);
  emxFree_real_T(&g_headidx);
  emxFree_int32_T(&k_pitcheslength);
  emxFree_real_T(&e_visited);
  emxFree_int32_T(&j_pitcheslength);
  emxFree_real_T(&e_headpitches);
  emxFree_int32_T(&i_pitcheslength);
  emxFree_real_T(&f_headidx);
  emxFree_int32_T(&h_pitcheslength);
  emxFree_real_T(&d_visited);
  emxFree_int32_T(&g_pitcheslength);
  emxFree_real_T(&d_headpitches);
  emxFree_int32_T(&f_pitcheslength);
  emxFree_real_T(&e_headidx);
  emxFree_int32_T(&e_pitcheslength);
  emxFree_real_T(&c_visited);
  emxFree_int32_T(&d_pitcheslength);
  emxFree_real_T(&c_headpitches);
  emxFree_int32_T(&c_pitcheslength);
  emxFree_real_T(&d_headidx);
  emxFree_int32_T(&b_pitcheslength);
  emxFree_real_T(&b_headpitches);
  emxFree_real_T(&c_headidx);
  emxFree_boolean_T(&b_visited);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&sorted_idx);
  emxFree_real_T(&visited);
  emxFree_real_T(&prev_headidx);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 5);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 17);
  i52 = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = arr->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)out, i52, (int32_T)sizeof(real_T),
                    &ke_emlrtRTEI);
  ii = arr->size[1];
  for (i52 = 0; i52 < ii; i52++) {
    out->data[i52] = 0.0;
  }

  i52 = pitcheslength->size[0] * pitcheslength->size[1];
  pitcheslength->size[0] = 1;
  pitcheslength->size[1] = headidx->size[1] + 1;
  emxEnsureCapacity(sp, (emxArray__common *)pitcheslength, i52, (int32_T)sizeof
                    (real_T), &ke_emlrtRTEI);
  ii = headidx->size[1];
  for (i52 = 0; i52 < ii; i52++) {
    pitcheslength->data[pitcheslength->size[0] * i52] = headidx->data
      [headidx->size[0] * i52];
  }

  pitcheslength->data[pitcheslength->size[0] * headidx->size[1]] = arr->size[1];
  i = 0;
  while (i <= headidx->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 18);
    i52 = pitcheslength->size[1];
    i53 = i + 1;
    if (!((i53 >= 1) && (i53 <= i52))) {
      emlrtDynamicBoundsCheckR2012b(i53, 1, i52, &jq_emlrtBCI, sp);
    }

    i52 = pitcheslength->size[1];
    i53 = (int32_T)((1.0 + (real_T)i) + 1.0);
    if (!((i53 >= 1) && (i53 <= i52))) {
      emlrtDynamicBoundsCheckR2012b(i53, 1, i52, &iq_emlrtBCI, sp);
    }

    if ((int32_T)pitcheslength->data[i] > (int32_T)pitcheslength->data[(int32_T)
        ((1.0 + (real_T)i) + 1.0) - 1]) {
      i52 = 0;
      apnd = 0;
    } else {
      i52 = out->size[1];
      i53 = (int32_T)pitcheslength->data[i];
      if (!((i53 >= 1) && (i53 <= i52))) {
        emlrtDynamicBoundsCheckR2012b(i53, 1, i52, &hq_emlrtBCI, sp);
      }

      i52 = i53 - 1;
      i53 = out->size[1];
      apnd = (int32_T)pitcheslength->data[(int32_T)((1.0 + (real_T)i) + 1.0) - 1];
      if (!((apnd >= 1) && (apnd <= i53))) {
        emlrtDynamicBoundsCheckR2012b(apnd, 1, i53, &hq_emlrtBCI, sp);
      }
    }

    i53 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
    sorted_pitcheslength->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)sorted_pitcheslength, i53,
                      (int32_T)sizeof(real_T), &ke_emlrtRTEI);
    i53 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
    nx = pitcheslength->size[1];
    idx = (int32_T)((1.0 + (real_T)i) + 1.0);
    if (!((idx >= 1) && (idx <= nx))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, nx, &wr_emlrtBCI, sp);
    }

    nx = pitcheslength->size[1];
    ii = 1 + i;
    if (!((ii >= 1) && (ii <= nx))) {
      emlrtDynamicBoundsCheckR2012b(ii, 1, nx, &xr_emlrtBCI, sp);
    }

    anew = (pitcheslength->data[idx - 1] - pitcheslength->data[ii - 1]) + 1.0;
    if (!(anew >= 0.0)) {
      emlrtNonNegativeCheckR2012b(anew, &kc_emlrtDCI, sp);
    }

    sorted_pitcheslength->size[1] = (int32_T)anew;
    emxEnsureCapacity(sp, (emxArray__common *)sorted_pitcheslength, i53,
                      (int32_T)sizeof(real_T), &ke_emlrtRTEI);
    i53 = headpitches->size[1];
    nx = 1 + i;
    if (!((nx >= 1) && (nx <= i53))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, i53, &yr_emlrtBCI, sp);
    }

    b_apnd = headpitches->data[nx - 1];
    i53 = pitcheslength->size[1];
    nx = (int32_T)((1.0 + (real_T)i) + 1.0);
    if (!((nx >= 1) && (nx <= i53))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, i53, &wr_emlrtBCI, sp);
    }

    i53 = pitcheslength->size[1];
    idx = 1 + i;
    if (!((idx >= 1) && (idx <= i53))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i53, &xr_emlrtBCI, sp);
    }

    anew = (pitcheslength->data[nx - 1] - pitcheslength->data[idx - 1]) + 1.0;
    if (!(anew >= 0.0)) {
      emlrtNonNegativeCheckR2012b(anew, &kc_emlrtDCI, sp);
    }

    ii = (int32_T)anew;
    for (i53 = 0; i53 < ii; i53++) {
      sorted_pitcheslength->data[i53] = b_apnd;
    }

    i53 = apnd - i52;
    apnd = sorted_pitcheslength->size[1];
    if (i53 != apnd) {
      emlrtSizeEqCheck1DR2012b(i53, apnd, &ic_emlrtECI, sp);
    }

    ii = sorted_pitcheslength->size[1];
    for (i53 = 0; i53 < ii; i53++) {
      out->data[i52 + i53] = sorted_pitcheslength->data
        [sorted_pitcheslength->size[0] * i53];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&sorted_pitcheslength);
  emxFree_real_T(&pitcheslength);
  emxFree_real_T(&headpitches);
  emxFree_real_T(&headidx);
  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 1, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Smooth2.c) */
