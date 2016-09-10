/*
 * freqSelect.c
 *
 * Code generation for function 'freqSelect'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "freqSelect.h"
#include "yaapt_emxutil.h"
#include "fq2cnt.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo kp_emlrtRSI = { 16, "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m" };

static emlrtRTEInfo ve_emlrtRTEI = { 1, 24, "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m" };

static emlrtRTEInfo we_emlrtRTEI = { 16, 1, "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m" };

static emlrtBCInfo uk_emlrtBCI = { -1, -1, 21, 9, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vk_emlrtBCI = { -1, -1, 21, 26, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wk_emlrtBCI = { -1, -1, 139, 13, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xk_emlrtBCI = { -1, -1, 139, 31, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yk_emlrtBCI = { -1, -1, 258, 9, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo al_emlrtBCI = { -1, -1, 140, 13, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bl_emlrtBCI = { -1, -1, 199, 17, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cl_emlrtBCI = { -1, -1, 228, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dl_emlrtBCI = { -1, -1, 242, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo el_emlrtBCI = { -1, -1, 246, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fl_emlrtBCI = { -1, -1, 250, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gl_emlrtBCI = { -1, -1, 251, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hl_emlrtBCI = { -1, -1, 247, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo il_emlrtBCI = { -1, -1, 248, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jl_emlrtBCI = { -1, -1, 243, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo kl_emlrtBCI = { -1, -1, 244, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ll_emlrtBCI = { -1, -1, 229, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ml_emlrtBCI = { -1, -1, 233, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo nl_emlrtBCI = { -1, -1, 237, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ol_emlrtBCI = { -1, -1, 238, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pl_emlrtBCI = { -1, -1, 234, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ql_emlrtBCI = { -1, -1, 235, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rl_emlrtBCI = { -1, -1, 230, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sl_emlrtBCI = { -1, -1, 231, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tl_emlrtBCI = { -1, -1, 200, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ul_emlrtBCI = { -1, -1, 214, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vl_emlrtBCI = { -1, -1, 218, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wl_emlrtBCI = { -1, -1, 222, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xl_emlrtBCI = { -1, -1, 223, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yl_emlrtBCI = { -1, -1, 219, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo am_emlrtBCI = { -1, -1, 220, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bm_emlrtBCI = { -1, -1, 215, 26, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cm_emlrtBCI = { -1, -1, 216, 26, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dm_emlrtBCI = { -1, -1, 201, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo em_emlrtBCI = { -1, -1, 205, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fm_emlrtBCI = { -1, -1, 209, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gm_emlrtBCI = { -1, -1, 210, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hm_emlrtBCI = { -1, -1, 206, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo im_emlrtBCI = { -1, -1, 207, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jm_emlrtBCI = { -1, -1, 202, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo km_emlrtBCI = { -1, -1, 203, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo lm_emlrtBCI = { -1, -1, 141, 17, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mm_emlrtBCI = { -1, -1, 170, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo nm_emlrtBCI = { -1, -1, 184, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo om_emlrtBCI = { -1, -1, 188, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pm_emlrtBCI = { -1, -1, 192, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qm_emlrtBCI = { -1, -1, 193, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rm_emlrtBCI = { -1, -1, 189, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sm_emlrtBCI = { -1, -1, 190, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tm_emlrtBCI = { -1, -1, 185, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo um_emlrtBCI = { -1, -1, 186, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vm_emlrtBCI = { -1, -1, 171, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wm_emlrtBCI = { -1, -1, 175, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xm_emlrtBCI = { -1, -1, 179, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ym_emlrtBCI = { -1, -1, 180, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo an_emlrtBCI = { -1, -1, 176, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bn_emlrtBCI = { -1, -1, 177, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cn_emlrtBCI = { -1, -1, 172, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dn_emlrtBCI = { -1, -1, 173, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo en_emlrtBCI = { -1, -1, 142, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fn_emlrtBCI = { -1, -1, 156, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gn_emlrtBCI = { -1, -1, 160, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hn_emlrtBCI = { -1, -1, 164, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo in_emlrtBCI = { -1, -1, 165, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jn_emlrtBCI = { -1, -1, 161, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo kn_emlrtBCI = { -1, -1, 162, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ln_emlrtBCI = { -1, -1, 157, 24, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mn_emlrtBCI = { -1, -1, 158, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo nn_emlrtBCI = { -1, -1, 143, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo on_emlrtBCI = { -1, -1, 147, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pn_emlrtBCI = { -1, -1, 151, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qn_emlrtBCI = { -1, -1, 152, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rn_emlrtBCI = { -1, -1, 148, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sn_emlrtBCI = { -1, -1, 149, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tn_emlrtBCI = { -1, -1, 144, 24, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo un_emlrtBCI = { -1, -1, 145, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vn_emlrtBCI = { -1, -1, 22, 13, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wn_emlrtBCI = { -1, -1, 81, 17, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xn_emlrtBCI = { -1, -1, 110, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yn_emlrtBCI = { -1, -1, 124, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ao_emlrtBCI = { -1, -1, 128, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bo_emlrtBCI = { -1, -1, 132, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo co_emlrtBCI = { -1, -1, 133, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo do_emlrtBCI = { -1, -1, 129, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo eo_emlrtBCI = { -1, -1, 130, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fo_emlrtBCI = { -1, -1, 125, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo go_emlrtBCI = { -1, -1, 126, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ho_emlrtBCI = { -1, -1, 111, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo io_emlrtBCI = { -1, -1, 115, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jo_emlrtBCI = { -1, -1, 119, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ko_emlrtBCI = { -1, -1, 120, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo lo_emlrtBCI = { -1, -1, 116, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mo_emlrtBCI = { -1, -1, 117, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo no_emlrtBCI = { -1, -1, 112, 24, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo oo_emlrtBCI = { -1, -1, 113, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo po_emlrtBCI = { -1, -1, 82, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qo_emlrtBCI = { -1, -1, 96, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ro_emlrtBCI = { -1, -1, 100, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo so_emlrtBCI = { -1, -1, 104, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo to_emlrtBCI = { -1, -1, 105, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo uo_emlrtBCI = { -1, -1, 101, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vo_emlrtBCI = { -1, -1, 102, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wo_emlrtBCI = { -1, -1, 97, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xo_emlrtBCI = { -1, -1, 98, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yo_emlrtBCI = { -1, -1, 83, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ap_emlrtBCI = { -1, -1, 87, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bp_emlrtBCI = { -1, -1, 91, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cp_emlrtBCI = { -1, -1, 92, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dp_emlrtBCI = { -1, -1, 88, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ep_emlrtBCI = { -1, -1, 89, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fp_emlrtBCI = { -1, -1, 84, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gp_emlrtBCI = { -1, -1, 85, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hp_emlrtBCI = { -1, -1, 23, 17, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ip_emlrtBCI = { -1, -1, 52, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jp_emlrtBCI = { -1, -1, 66, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo kp_emlrtBCI = { -1, -1, 70, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo lp_emlrtBCI = { -1, -1, 74, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mp_emlrtBCI = { -1, -1, 75, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo np_emlrtBCI = { -1, -1, 71, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo op_emlrtBCI = { -1, -1, 72, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pp_emlrtBCI = { -1, -1, 67, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qp_emlrtBCI = { -1, -1, 68, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rp_emlrtBCI = { -1, -1, 53, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sp_emlrtBCI = { -1, -1, 57, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tp_emlrtBCI = { -1, -1, 61, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo up_emlrtBCI = { -1, -1, 62, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vp_emlrtBCI = { -1, -1, 58, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wp_emlrtBCI = { -1, -1, 59, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xp_emlrtBCI = { -1, -1, 54, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yp_emlrtBCI = { -1, -1, 55, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo aq_emlrtBCI = { -1, -1, 24, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bq_emlrtBCI = { -1, -1, 38, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cq_emlrtBCI = { -1, -1, 42, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dq_emlrtBCI = { -1, -1, 46, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo eq_emlrtBCI = { -1, -1, 47, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fq_emlrtBCI = { -1, -1, 43, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gq_emlrtBCI = { -1, -1, 44, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hq_emlrtBCI = { -1, -1, 39, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo iq_emlrtBCI = { -1, -1, 40, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jq_emlrtBCI = { -1, -1, 25, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo kq_emlrtBCI = { -1, -1, 34, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo lq_emlrtBCI = { -1, -1, 35, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mq_emlrtBCI = { -1, -1, 26, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo nq_emlrtBCI = { -1, -1, 30, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo oq_emlrtBCI = { -1, -1, 31, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pq_emlrtBCI = { -1, -1, 27, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qq_emlrtBCI = { -1, -1, 28, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

/* Function Definitions */

/*
 * function [freq,cent] = freqSelect(fq)
 */
void freqSelect(const emlrtStack *sp, const emxArray_real_T *fq, emxArray_real_T
                *freq, emxArray_real_T *cent)
{
  emxArray_real_T *cnt;
  int32_T i59;
  int32_T loop_ub;
  int32_T i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &cnt, 2, &we_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 21U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 0);

  /*  KEYSELECT Determine input fq as piano key */
  /*  */
  /*  fq = input frequency */
  /*  key{i} = output string denotes piano key, a cell array */
  /*   */
  /*  upper limit is 1000 Hz, 7450 cents, B4 at 7400 cents */
  /*  lower limit is 65.4064 Hz, 2650 cents, C2 at 2700 cents */
  /*  key example format: */
  /*  ... B2 C3 C#3Db3 D3 D#3Eb3 E3 F3 F#3Gb3 G3 G#3Ab3 A3 A#3Bb3 B3 C4 ... */
  /*  Ex: */
  /*  >> key = keySelect(200) */
  /*  cnt = 4.6350e+03 */
  /*  key = 'G3' (1x1 cell) */
  /*  */
  /* 'freqSelect:16' cnt = fq2cnt(fq); */
  st.site = &kp_emlrtRSI;
  fq2cnt(&st, fq, cnt);

  /*  key = cell(1,length(cnt)); */
  /* 'freqSelect:18' cent = zeros(1,length(cnt)); */
  i59 = cent->size[0] * cent->size[1];
  cent->size[0] = 1;
  cent->size[1] = cnt->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)cent, i59, (int32_T)sizeof(real_T),
                    &ve_emlrtRTEI);
  loop_ub = cnt->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    cent->data[i59] = 0.0;
  }

  /* 'freqSelect:19' freq = zeros(1,length(cnt)); */
  i59 = freq->size[0] * freq->size[1];
  freq->size[0] = 1;
  freq->size[1] = cnt->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)freq, i59, (int32_T)sizeof(real_T),
                    &ve_emlrtRTEI);
  loop_ub = cnt->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    freq->data[i59] = 0.0;
  }

  /* 'freqSelect:20' for i = 1:length(cnt) */
  i = 1;
  while (i - 1 <= cnt->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 0, 1);

    /* 'freqSelect:21' if (cnt(i) > 5050 && cnt(i) <= 7450) */
    i59 = cnt->size[1];
    if (!((i >= 1) && (i <= i59))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &uk_emlrtBCI, sp);
    }

    guard1 = false;
    guard2 = false;
    if (covrtLogCond(&emlrtCoverageInstance, 21U, 0U, 0, cnt->data[i - 1] >
                     5050.0)) {
      i59 = cnt->size[1];
      if (!((i >= 1) && (i <= i59))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i59, &vk_emlrtBCI, sp);
      }

      if (covrtLogCond(&emlrtCoverageInstance, 21U, 0U, 1, cnt->data[i - 1] <=
                       7450.0)) {
        covrtLogMcdc(&emlrtCoverageInstance, 21U, 0U, 0, true);
        covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 0, true);

        /* 'freqSelect:22' if (cnt(i) > 6250) */
        i59 = cnt->size[1];
        if (!((i >= 1) && (i <= i59))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i59, &vn_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 1, cnt->data[i - 1] >
                       6250.0)) {
          /* 'freqSelect:23' if (cnt(i) > 6850) */
          i59 = cnt->size[1];
          if (!((i >= 1) && (i <= i59))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i59, &hp_emlrtBCI, sp);
          }

          if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 2, cnt->data[i - 1] >
                         6850.0)) {
            /* 'freqSelect:24' if (cnt(i) > 7150) */
            i59 = cnt->size[1];
            if (!((i >= 1) && (i <= i59))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i59, &aq_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 3, cnt->data[i - 1] >
                           7150.0)) {
              /* 'freqSelect:25' if (cnt(i) > 7250) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &jq_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 4, cnt->data[i - 1]
                             > 7250.0)) {
                /* 'freqSelect:26' if (cnt(i) > 7350) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &mq_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 5, cnt->data[i -
                               1] > 7350.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 1);

                  /* 'freqSelect:27' freq(i) = 987.767; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &pq_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 987.767;

                  /*  7400 */
                  /* 'freqSelect:28' cent(i) = 7400; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &qq_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 7400.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 2);

                  /* 'freqSelect:29' else */
                  /* 'freqSelect:30' freq(i) = 932.328; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &nq_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 932.328;

                  /*  7300   */
                  /* 'freqSelect:31' cent(i) = 7300; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &oq_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 7300.0;
                }
              } else {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 3);

                /* 'freqSelect:33' else */
                /* 'freqSelect:34' freq(i) = 880.000; */
                i59 = freq->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &kq_emlrtBCI, sp);
                }

                freq->data[i - 1] = 880.0;

                /*  7200    */
                /* 'freqSelect:35' cent(i) = 7200; */
                i59 = cent->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &lq_emlrtBCI, sp);
                }

                cent->data[i - 1] = 7200.0;
              }
            } else {
              /* 'freqSelect:37' else */
              /* 'freqSelect:38' if (cnt(i) > 7050) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &bq_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 6, cnt->data[i - 1]
                             > 7050.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 4);

                /* 'freqSelect:39' freq(i) = 830.609; */
                i59 = freq->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &hq_emlrtBCI, sp);
                }

                freq->data[i - 1] = 830.609;

                /*  7100  */
                /* 'freqSelect:40' cent(i) = 7100; */
                i59 = cent->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &iq_emlrtBCI, sp);
                }

                cent->data[i - 1] = 7100.0;
              } else {
                /* 'freqSelect:41' else */
                /* 'freqSelect:42' if (cnt(i) > 6950) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &cq_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 7, cnt->data[i -
                               1] > 6950.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 5);

                  /* 'freqSelect:43' freq(i) = 783.991; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &fq_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 783.991;

                  /*  7000     */
                  /* 'freqSelect:44' cent(i) = 7000; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &gq_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 7000.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 6);

                  /* 'freqSelect:45' else */
                  /* 'freqSelect:46' freq(i) = 739.989; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &dq_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 739.989;

                  /*  6900     */
                  /* 'freqSelect:47' cent(i) = 6900; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &eq_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6900.0;
                }
              }
            }
          } else {
            /* 'freqSelect:51' else */
            /* 'freqSelect:52' if (cnt(i) > 6550) */
            i59 = cnt->size[1];
            if (!((i >= 1) && (i <= i59))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ip_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 8, cnt->data[i - 1] >
                           6550.0)) {
              /* 'freqSelect:53' if (cnt(i) > 6750) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &rp_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 9, cnt->data[i - 1]
                             > 6750.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 7);

                /* 'freqSelect:54' freq(i) = 698.456; */
                i59 = freq->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &xp_emlrtBCI, sp);
                }

                freq->data[i - 1] = 698.456;

                /*  6800 */
                /* 'freqSelect:55' cent(i) = 6800; */
                i59 = cent->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &yp_emlrtBCI, sp);
                }

                cent->data[i - 1] = 6800.0;
              } else {
                /* 'freqSelect:56' else */
                /* 'freqSelect:57' if (cnt(i) > 6650) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &sp_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 10, cnt->data[i
                               - 1] > 6650.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 8);

                  /* 'freqSelect:58' freq(i) = 659.255; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &vp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 659.255;

                  /*  6700 */
                  /* 'freqSelect:59' cent(i) = 6700; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &wp_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6700.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 9);

                  /* 'freqSelect:60' else */
                  /* 'freqSelect:61' freq(i) = 622.254; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &tp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 622.254;

                  /*  6600        */
                  /* 'freqSelect:62' cent(i) = 6600; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &up_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6600.0;
                }
              }
            } else {
              /* 'freqSelect:65' else */
              /* 'freqSelect:66' if (cnt(i) > 6450) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &jp_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 11, cnt->data[i -
                             1] > 6450.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 10);

                /* 'freqSelect:67' freq(i) = 587.33; */
                i59 = freq->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &pp_emlrtBCI, sp);
                }

                freq->data[i - 1] = 587.33;

                /*  6500     */
                /* 'freqSelect:68' cent(i) = 6500; */
                i59 = cent->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &qp_emlrtBCI, sp);
                }

                cent->data[i - 1] = 6500.0;
              } else {
                /* 'freqSelect:69' else */
                /* 'freqSelect:70' if (cnt(i) > 6350) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &kp_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 12, cnt->data[i
                               - 1] > 6350.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 11);

                  /* 'freqSelect:71' freq(i) = 554.365; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &np_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 554.365;

                  /*  6400   */
                  /* 'freqSelect:72' cent(i) = 6400; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &op_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6400.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 12);

                  /* 'freqSelect:73' else */
                  /* 'freqSelect:74' freq(i) = 523.251; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &lp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 523.251;

                  /*  6300       */
                  /* 'freqSelect:75' cent(i) = 6300; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &mp_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6300.0;
                }
              }
            }
          }
        } else {
          /* 'freqSelect:80' else */
          /* 'freqSelect:81' if (cnt(i) > 5650) */
          i59 = cnt->size[1];
          if (!((i >= 1) && (i <= i59))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i59, &wn_emlrtBCI, sp);
          }

          if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 13, cnt->data[i - 1] >
                         5650.0)) {
            /* 'freqSelect:82' if (cnt(i) > 5950) */
            i59 = cnt->size[1];
            if (!((i >= 1) && (i <= i59))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i59, &po_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 14, cnt->data[i - 1]
                           > 5950.0)) {
              /* 'freqSelect:83' if (cnt(i) > 6150) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &yo_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 15, cnt->data[i -
                             1] > 6150.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 13);

                /* 'freqSelect:84' freq(i) = 493.883; */
                i59 = freq->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &fp_emlrtBCI, sp);
                }

                freq->data[i - 1] = 493.883;

                /*  6200  */
                /* 'freqSelect:85' cent(i) = 6200; */
                i59 = cent->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &gp_emlrtBCI, sp);
                }

                cent->data[i - 1] = 6200.0;
              } else {
                /* 'freqSelect:86' else */
                /* 'freqSelect:87' if (cnt(i) > 6050) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ap_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 16, cnt->data[i
                               - 1] > 6050.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 14);

                  /* 'freqSelect:88' freq(i) = 466.164; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &dp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 466.164;

                  /*  6100  */
                  /* 'freqSelect:89' cent(i) = 6100; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ep_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6100.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 15);

                  /* 'freqSelect:90' else */
                  /* 'freqSelect:91' freq(i) = 440; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &bp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 440.0;

                  /*  6000 */
                  /* 'freqSelect:92' cent(i) = 6000; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &cp_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6000.0;
                }
              }
            } else {
              /* 'freqSelect:95' else */
              /* 'freqSelect:96' if (cnt(i) > 5850) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &qo_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 17, cnt->data[i -
                             1] > 5850.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 16);

                /* 'freqSelect:97' freq(i) = 415.305; */
                i59 = freq->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &wo_emlrtBCI, sp);
                }

                freq->data[i - 1] = 415.305;

                /*  5900  */
                /* 'freqSelect:98' cent(i) = 5900; */
                i59 = cent->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &xo_emlrtBCI, sp);
                }

                cent->data[i - 1] = 5900.0;
              } else {
                /* 'freqSelect:99' else */
                /* 'freqSelect:100' if (cnt(i) > 5750) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ro_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 18, cnt->data[i
                               - 1] > 5750.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 17);

                  /* 'freqSelect:101' freq(i) = 391.995; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &uo_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 391.995;

                  /*  5800  */
                  /* 'freqSelect:102' cent(i) = 5800; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &vo_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5800.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 18);

                  /* 'freqSelect:103' else */
                  /* 'freqSelect:104' freq(i) = 369.994; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &so_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 369.994;

                  /*  5700 */
                  /* 'freqSelect:105' cent(i) = 5700; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &to_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5700.0;
                }
              }
            }
          } else {
            /* 'freqSelect:109' else */
            /* 'freqSelect:110' if (cnt(i) > 5350) */
            i59 = cnt->size[1];
            if (!((i >= 1) && (i <= i59))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i59, &xn_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 19, cnt->data[i - 1]
                           > 5350.0)) {
              /* 'freqSelect:111' if (cnt(i) > 5550) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ho_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 20, cnt->data[i -
                             1] > 5550.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 19);

                /* 'freqSelect:112' freq(i) = 349.228; */
                i59 = freq->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &no_emlrtBCI, sp);
                }

                freq->data[i - 1] = 349.228;

                /*  5600  */
                /* 'freqSelect:113' cent(i) = 5600; */
                i59 = cent->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &oo_emlrtBCI, sp);
                }

                cent->data[i - 1] = 5600.0;
              } else {
                /* 'freqSelect:114' else */
                /* 'freqSelect:115' if (cnt(i) > 5450) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &io_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 21, cnt->data[i
                               - 1] > 5450.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 20);

                  /* 'freqSelect:116' freq(i) = 329.628; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &lo_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 329.628;

                  /*  5500  */
                  /* 'freqSelect:117' cent(i) = 5500; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &mo_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5500.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 21);

                  /* 'freqSelect:118' else */
                  /* 'freqSelect:119' freq(i) = 311.127; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &jo_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 311.127;

                  /*  5400  */
                  /* 'freqSelect:120' cent(i) = 5400; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ko_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5400.0;
                }
              }
            } else {
              /* 'freqSelect:123' else */
              /* 'freqSelect:124' if (cnt(i) > 5250) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &yn_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 22, cnt->data[i -
                             1] > 5250.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 22);

                /* 'freqSelect:125' freq(i) = 293.665; */
                i59 = freq->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &fo_emlrtBCI, sp);
                }

                freq->data[i - 1] = 293.665;

                /*  5300  */
                /* 'freqSelect:126' cent(i) = 5300; */
                i59 = cent->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &go_emlrtBCI, sp);
                }

                cent->data[i - 1] = 5300.0;
              } else {
                /* 'freqSelect:127' else */
                /* 'freqSelect:128' if (cnt(i) > 5150) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ao_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 23, cnt->data[i
                               - 1] > 5150.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 23);

                  /* 'freqSelect:129' freq(i) = 277.183; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &do_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 277.183;

                  /*  5200  */
                  /* 'freqSelect:130' cent(i) = 5200; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &eo_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5200.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 24);

                  /* 'freqSelect:131' else */
                  /* 'freqSelect:132' freq(i) = 261.626; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &bo_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 261.626;

                  /*  5100   */
                  /* 'freqSelect:133' cent(i) = 5100; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &co_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5100.0;
                }
              }
            }
          }
        }
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      covrtLogMcdc(&emlrtCoverageInstance, 21U, 0U, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 0, false);
      i59 = cnt->size[1];
      if (!((i >= 1) && (i <= i59))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i59, &wk_emlrtBCI, sp);
      }

      if (covrtLogCond(&emlrtCoverageInstance, 21U, 0U, 2, cnt->data[i - 1] <=
                       5050.0)) {
        i59 = cnt->size[1];
        if (!((i >= 1) && (i <= i59))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i59, &xk_emlrtBCI, sp);
        }

        if (covrtLogCond(&emlrtCoverageInstance, 21U, 0U, 3, cnt->data[i - 1] >
                         2650.0)) {
          covrtLogMcdc(&emlrtCoverageInstance, 21U, 0U, 1, true);
          covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 24, true);

          /* 'freqSelect:139' elseif (cnt(i) <= 5050 && cnt(i) > 2650) */
          /* 'freqSelect:140' if (cnt(i) > 3850) */
          i59 = cnt->size[1];
          if (!((i >= 1) && (i <= i59))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i59, &al_emlrtBCI, sp);
          }

          if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 25, cnt->data[i - 1] >
                         3850.0)) {
            /* 'freqSelect:141' if (cnt(i) > 4450) */
            i59 = cnt->size[1];
            if (!((i >= 1) && (i <= i59))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i59, &lm_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 26, cnt->data[i - 1]
                           > 4450.0)) {
              /* 'freqSelect:142' if (cnt(i) > 4750) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &en_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 27, cnt->data[i -
                             1] > 4750.0)) {
                /* 'freqSelect:143' if (cnt(i) > 4950) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &nn_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 28, cnt->data[i
                               - 1] > 4950.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 25);

                  /* 'freqSelect:144' freq(i) = 246.942; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &tn_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 246.942;

                  /*  5000   */
                  /* 'freqSelect:145' cent(i) = 5000; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &un_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5000.0;
                } else {
                  /* 'freqSelect:146' else */
                  /* 'freqSelect:147' if (cnt(i) > 4850) */
                  i59 = cnt->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &on_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 29, cnt->
                                 data[i - 1] > 4850.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 26);

                    /* 'freqSelect:148' freq(i) = 233.082; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &rn_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 233.082;

                    /*  4900 */
                    /* 'freqSelect:149' cent(i) = 4900; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &sn_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4900.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 27);

                    /* 'freqSelect:150' else */
                    /* 'freqSelect:151' freq(i) = 220; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &pn_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 220.0;

                    /*  4800   */
                    /* 'freqSelect:152' cent(i) = 4800; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &qn_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4800.0;
                  }
                }
              } else {
                /* 'freqSelect:155' else */
                /* 'freqSelect:156' if (cnt(i) > 4650) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &fn_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 30, cnt->data[i
                               - 1] > 4650.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 28);

                  /* 'freqSelect:157' freq(i) = 207.652; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ln_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 207.652;

                  /*  4700  */
                  /* 'freqSelect:158' cent(i) = 4700; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &mn_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 4700.0;
                } else {
                  /* 'freqSelect:159' else */
                  /* 'freqSelect:160' if (cnt(i) > 4550) */
                  i59 = cnt->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &gn_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 31, cnt->
                                 data[i - 1] > 4550.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 29);

                    /* 'freqSelect:161' freq(i) = 195.998; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &jn_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 195.998;

                    /*  4600  */
                    /* 'freqSelect:162' cent(i) = 4600; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &kn_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4600.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 30);

                    /* 'freqSelect:163' else */
                    /* 'freqSelect:164' freq(i) = 184.997; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &hn_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 184.997;

                    /*  4500 */
                    /* 'freqSelect:165' cent(i) = 4500; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &in_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4500.0;
                  }
                }
              }
            } else {
              /* 'freqSelect:169' else */
              /* 'freqSelect:170' if (cnt(i) > 4150) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &mm_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 32, cnt->data[i -
                             1] > 4150.0)) {
                /* 'freqSelect:171' if (cnt(i) > 4350) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &vm_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 33, cnt->data[i
                               - 1] > 4350.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 31);

                  /* 'freqSelect:172' freq(i) = 174.614; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &cn_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 174.614;

                  /*  4400  */
                  /* 'freqSelect:173' cent(i) = 4400; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &dn_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 4400.0;
                } else {
                  /* 'freqSelect:174' else */
                  /* 'freqSelect:175' if (cnt(i) > 4250) */
                  i59 = cnt->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &wm_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 34, cnt->
                                 data[i - 1] > 4250.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 32);

                    /* 'freqSelect:176' freq(i) = 164.814; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &an_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 164.814;

                    /*  4300 */
                    /* 'freqSelect:177' cent(i) = 4300; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &bn_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4300.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 33);

                    /* 'freqSelect:178' else */
                    /* 'freqSelect:179' freq(i) = 155.563; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &xm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 155.563;

                    /*  4200 */
                    /* 'freqSelect:180' cent(i) = 4200; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ym_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4200.0;
                  }
                }
              } else {
                /* 'freqSelect:183' else */
                /* 'freqSelect:184' if (cnt(i) > 4050) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &nm_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 35, cnt->data[i
                               - 1] > 4050.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 34);

                  /* 'freqSelect:185' freq(i) = 146.832; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &tm_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 146.832;

                  /*  4100  */
                  /* 'freqSelect:186' cent(i) = 4100; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &um_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 4100.0;
                } else {
                  /* 'freqSelect:187' else */
                  /* 'freqSelect:188' if (cnt(i) > 3950) */
                  i59 = cnt->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &om_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 36, cnt->
                                 data[i - 1] > 3950.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 35);

                    /* 'freqSelect:189' freq(i) = 138.591; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &rm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 138.591;

                    /*  4000  */
                    /* 'freqSelect:190' cent(i) = 4000; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &sm_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4000.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 36);

                    /* 'freqSelect:191' else */
                    /* 'freqSelect:192' freq(i) = 130.813; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &pm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 130.813;

                    /*  3900 */
                    /* 'freqSelect:193' cent(i) = 3900; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &qm_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3900.0;
                  }
                }
              }
            }
          } else {
            /* 'freqSelect:198' else */
            /* 'freqSelect:199' if (cnt(i) > 3250) */
            i59 = cnt->size[1];
            if (!((i >= 1) && (i <= i59))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i59, &bl_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 37, cnt->data[i - 1]
                           > 3250.0)) {
              /* 'freqSelect:200' if (cnt(i) > 3550) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &tl_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 38, cnt->data[i -
                             1] > 3550.0)) {
                /* 'freqSelect:201' if (cnt(i) > 3750) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &dm_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 39, cnt->data[i
                               - 1] > 3750.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 37);

                  /* 'freqSelect:202' freq(i) = 123.471; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &jm_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 123.471;

                  /*  3800 */
                  /* 'freqSelect:203' cent(i) = 3800; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &km_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 3800.0;
                } else {
                  /* 'freqSelect:204' else */
                  /* 'freqSelect:205' if (cnt(i) > 3650) */
                  i59 = cnt->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &em_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 40, cnt->
                                 data[i - 1] > 3650.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 38);

                    /* 'freqSelect:206' freq(i) = 116.541; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &hm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 116.541;

                    /*  3700     */
                    /* 'freqSelect:207' cent(i) = 3700; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &im_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3700.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 39);

                    /* 'freqSelect:208' else */
                    /* 'freqSelect:209' freq(i) = 110; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &fm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 110.0;

                    /*  3600 */
                    /* 'freqSelect:210' cent(i) = 3600; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &gm_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3600.0;
                  }
                }
              } else {
                /* 'freqSelect:213' else */
                /* 'freqSelect:214' if (cnt(i) > 3450) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ul_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 41, cnt->data[i
                               - 1] > 3450.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 40);

                  /* 'freqSelect:215' freq(i) = 103.826; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &bm_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 103.826;

                  /*  3500  */
                  /* 'freqSelect:216' cent(i) = 3500; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &cm_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 3500.0;
                } else {
                  /* 'freqSelect:217' else */
                  /* 'freqSelect:218' if (cnt(i) > 3350) */
                  i59 = cnt->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &vl_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 42, cnt->
                                 data[i - 1] > 3350.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 41);

                    /* 'freqSelect:219' freq(i) = 97.9989; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &yl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 97.9989;

                    /*  3400 */
                    /* 'freqSelect:220' cent(i) = 3400; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &am_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3400.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 42);

                    /* 'freqSelect:221' else */
                    /* 'freqSelect:222' freq(i) = 92.4986; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &wl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 92.4986;

                    /*  3300  */
                    /* 'freqSelect:223' cent(i) = 3300; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &xl_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3300.0;
                  }
                }
              }
            } else {
              /* 'freqSelect:227' else */
              /* 'freqSelect:228' if (cnt(i) > 2950) */
              i59 = cnt->size[1];
              if (!((i >= 1) && (i <= i59))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i59, &cl_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 43, cnt->data[i -
                             1] > 2950.0)) {
                /* 'freqSelect:229' if (cnt(i) > 3150) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ll_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 44, cnt->data[i
                               - 1] > 3150.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 43);

                  /* 'freqSelect:230' freq(i) = 87.3071; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &rl_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 87.3071;

                  /*  3200  */
                  /* 'freqSelect:231' cent(i) = 3200; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &sl_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 3200.0;
                } else {
                  /* 'freqSelect:232' else */
                  /* 'freqSelect:233' if (cnt(i) > 3050) */
                  i59 = cnt->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ml_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 45, cnt->
                                 data[i - 1] > 3050.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 44);

                    /* 'freqSelect:234' freq(i) = 82.4069; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &pl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 82.4069;

                    /*  3100    */
                    /* 'freqSelect:235' cent(i) = 3100; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ql_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3100.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 45);

                    /* 'freqSelect:236' else */
                    /* 'freqSelect:237' freq(i) = 77.7817; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &nl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 77.7817;

                    /*  3000  */
                    /* 'freqSelect:238' cent(i) = 3000; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &ol_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3000.0;
                  }
                }
              } else {
                /* 'freqSelect:241' else */
                /* 'freqSelect:242' if (cnt(i) > 2850) */
                i59 = cnt->size[1];
                if (!((i >= 1) && (i <= i59))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i59, &dl_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 46, cnt->data[i
                               - 1] > 2850.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 46);

                  /* 'freqSelect:243' freq(i) = 73.4162; */
                  i59 = freq->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &jl_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 73.4162;

                  /*  2900 */
                  /* 'freqSelect:244' cent(i) = 2900; */
                  i59 = cent->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &kl_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 2900.0;
                } else {
                  /* 'freqSelect:245' else */
                  /* 'freqSelect:246' if (cnt(i) > 2750) */
                  i59 = cnt->size[1];
                  if (!((i >= 1) && (i <= i59))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i59, &el_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 47, cnt->
                                 data[i - 1] > 2750.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 47);

                    /* 'freqSelect:247' freq(i) = 69.2957; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &hl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 69.2957;

                    /*  2800   */
                    /* 'freqSelect:248' cent(i) = 2800; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &il_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 2800.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 48);

                    /* 'freqSelect:249' else */
                    /* 'freqSelect:250' freq(i) = 65.4064; */
                    i59 = freq->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &fl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 65.4064;

                    /*  2700   */
                    /* 'freqSelect:251' cent(i) = 2700; */
                    i59 = cent->size[1];
                    if (!((i >= 1) && (i <= i59))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i59, &gl_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 2700.0;
                  }
                }
              }
            }
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      covrtLogMcdc(&emlrtCoverageInstance, 21U, 0U, 1, false);
      covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 24, false);
      covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 49);

      /* 'freqSelect:257' else */
      /* 'freqSelect:258' cent(i) = 0; */
      i59 = cent->size[1];
      if (!((i >= 1) && (i <= i59))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i59, &yk_emlrtBCI, sp);
      }

      cent->data[i - 1] = 0.0;

      /*          display('input frequency out of range, range is from 65 Hz to 1000 Hz'); */
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&cnt);
  covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (freqSelect.c) */
