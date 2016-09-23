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
static emlrtRSInfo vm_emlrtRSI = { 16, "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m" };

static emlrtRTEInfo he_emlrtRTEI = { 1, 24, "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m" };

static emlrtRTEInfo ie_emlrtRTEI = { 16, 1, "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m" };

static emlrtBCInfo kk_emlrtBCI = { -1, -1, 21, 9, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo lk_emlrtBCI = { -1, -1, 21, 26, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mk_emlrtBCI = { -1, -1, 139, 13, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo nk_emlrtBCI = { -1, -1, 139, 31, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ok_emlrtBCI = { -1, -1, 258, 9, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pk_emlrtBCI = { -1, -1, 140, 13, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qk_emlrtBCI = { -1, -1, 199, 17, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rk_emlrtBCI = { -1, -1, 228, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sk_emlrtBCI = { -1, -1, 242, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tk_emlrtBCI = { -1, -1, 246, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo uk_emlrtBCI = { -1, -1, 250, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vk_emlrtBCI = { -1, -1, 251, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wk_emlrtBCI = { -1, -1, 247, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xk_emlrtBCI = { -1, -1, 248, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yk_emlrtBCI = { -1, -1, 243, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo al_emlrtBCI = { -1, -1, 244, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bl_emlrtBCI = { -1, -1, 229, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cl_emlrtBCI = { -1, -1, 233, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dl_emlrtBCI = { -1, -1, 237, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo el_emlrtBCI = { -1, -1, 238, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fl_emlrtBCI = { -1, -1, 234, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gl_emlrtBCI = { -1, -1, 235, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hl_emlrtBCI = { -1, -1, 230, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo il_emlrtBCI = { -1, -1, 231, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jl_emlrtBCI = { -1, -1, 200, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo kl_emlrtBCI = { -1, -1, 214, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ll_emlrtBCI = { -1, -1, 218, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ml_emlrtBCI = { -1, -1, 222, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo nl_emlrtBCI = { -1, -1, 223, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ol_emlrtBCI = { -1, -1, 219, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pl_emlrtBCI = { -1, -1, 220, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ql_emlrtBCI = { -1, -1, 215, 26, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rl_emlrtBCI = { -1, -1, 216, 26, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sl_emlrtBCI = { -1, -1, 201, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tl_emlrtBCI = { -1, -1, 205, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ul_emlrtBCI = { -1, -1, 209, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vl_emlrtBCI = { -1, -1, 210, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wl_emlrtBCI = { -1, -1, 206, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xl_emlrtBCI = { -1, -1, 207, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yl_emlrtBCI = { -1, -1, 202, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo am_emlrtBCI = { -1, -1, 203, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bm_emlrtBCI = { -1, -1, 141, 17, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cm_emlrtBCI = { -1, -1, 170, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dm_emlrtBCI = { -1, -1, 184, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo em_emlrtBCI = { -1, -1, 188, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fm_emlrtBCI = { -1, -1, 192, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gm_emlrtBCI = { -1, -1, 193, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hm_emlrtBCI = { -1, -1, 189, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo im_emlrtBCI = { -1, -1, 190, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jm_emlrtBCI = { -1, -1, 185, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo km_emlrtBCI = { -1, -1, 186, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo lm_emlrtBCI = { -1, -1, 171, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mm_emlrtBCI = { -1, -1, 175, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo nm_emlrtBCI = { -1, -1, 179, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo om_emlrtBCI = { -1, -1, 180, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pm_emlrtBCI = { -1, -1, 176, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qm_emlrtBCI = { -1, -1, 177, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rm_emlrtBCI = { -1, -1, 172, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sm_emlrtBCI = { -1, -1, 173, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tm_emlrtBCI = { -1, -1, 142, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo um_emlrtBCI = { -1, -1, 156, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vm_emlrtBCI = { -1, -1, 160, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wm_emlrtBCI = { -1, -1, 164, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xm_emlrtBCI = { -1, -1, 165, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ym_emlrtBCI = { -1, -1, 161, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo an_emlrtBCI = { -1, -1, 162, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bn_emlrtBCI = { -1, -1, 157, 24, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cn_emlrtBCI = { -1, -1, 158, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dn_emlrtBCI = { -1, -1, 143, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo en_emlrtBCI = { -1, -1, 147, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fn_emlrtBCI = { -1, -1, 151, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gn_emlrtBCI = { -1, -1, 152, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hn_emlrtBCI = { -1, -1, 148, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo in_emlrtBCI = { -1, -1, 149, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jn_emlrtBCI = { -1, -1, 144, 24, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo kn_emlrtBCI = { -1, -1, 145, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ln_emlrtBCI = { -1, -1, 22, 13, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mn_emlrtBCI = { -1, -1, 81, 17, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo nn_emlrtBCI = { -1, -1, 110, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo on_emlrtBCI = { -1, -1, 124, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pn_emlrtBCI = { -1, -1, 128, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qn_emlrtBCI = { -1, -1, 132, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rn_emlrtBCI = { -1, -1, 133, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sn_emlrtBCI = { -1, -1, 129, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tn_emlrtBCI = { -1, -1, 130, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo un_emlrtBCI = { -1, -1, 125, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vn_emlrtBCI = { -1, -1, 126, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wn_emlrtBCI = { -1, -1, 111, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xn_emlrtBCI = { -1, -1, 115, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yn_emlrtBCI = { -1, -1, 119, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ao_emlrtBCI = { -1, -1, 120, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bo_emlrtBCI = { -1, -1, 116, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo co_emlrtBCI = { -1, -1, 117, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo do_emlrtBCI = { -1, -1, 112, 24, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo eo_emlrtBCI = { -1, -1, 113, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fo_emlrtBCI = { -1, -1, 82, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo go_emlrtBCI = { -1, -1, 96, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ho_emlrtBCI = { -1, -1, 100, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo io_emlrtBCI = { -1, -1, 104, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jo_emlrtBCI = { -1, -1, 105, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ko_emlrtBCI = { -1, -1, 101, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo lo_emlrtBCI = { -1, -1, 102, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mo_emlrtBCI = { -1, -1, 97, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo no_emlrtBCI = { -1, -1, 98, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo oo_emlrtBCI = { -1, -1, 83, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo po_emlrtBCI = { -1, -1, 87, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qo_emlrtBCI = { -1, -1, 91, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ro_emlrtBCI = { -1, -1, 92, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo so_emlrtBCI = { -1, -1, 88, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo to_emlrtBCI = { -1, -1, 89, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo uo_emlrtBCI = { -1, -1, 84, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vo_emlrtBCI = { -1, -1, 85, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wo_emlrtBCI = { -1, -1, 23, 17, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xo_emlrtBCI = { -1, -1, 52, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yo_emlrtBCI = { -1, -1, 66, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ap_emlrtBCI = { -1, -1, 70, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bp_emlrtBCI = { -1, -1, 74, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cp_emlrtBCI = { -1, -1, 75, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dp_emlrtBCI = { -1, -1, 71, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ep_emlrtBCI = { -1, -1, 72, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fp_emlrtBCI = { -1, -1, 67, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gp_emlrtBCI = { -1, -1, 68, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo hp_emlrtBCI = { -1, -1, 53, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo ip_emlrtBCI = { -1, -1, 57, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo jp_emlrtBCI = { -1, -1, 61, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo kp_emlrtBCI = { -1, -1, 62, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo lp_emlrtBCI = { -1, -1, 58, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo mp_emlrtBCI = { -1, -1, 59, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo np_emlrtBCI = { -1, -1, 54, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo op_emlrtBCI = { -1, -1, 55, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo pp_emlrtBCI = { -1, -1, 24, 21, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo qp_emlrtBCI = { -1, -1, 38, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo rp_emlrtBCI = { -1, -1, 42, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo sp_emlrtBCI = { -1, -1, 46, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo tp_emlrtBCI = { -1, -1, 47, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo up_emlrtBCI = { -1, -1, 43, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo vp_emlrtBCI = { -1, -1, 44, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo wp_emlrtBCI = { -1, -1, 39, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo xp_emlrtBCI = { -1, -1, 40, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo yp_emlrtBCI = { -1, -1, 25, 25, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo aq_emlrtBCI = { -1, -1, 34, 25, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo bq_emlrtBCI = { -1, -1, 35, 25, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo cq_emlrtBCI = { -1, -1, 26, 29, "cnt", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo dq_emlrtBCI = { -1, -1, 30, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo eq_emlrtBCI = { -1, -1, 31, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo fq_emlrtBCI = { -1, -1, 27, 29, "freq", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

static emlrtBCInfo gq_emlrtBCI = { -1, -1, 28, 29, "cent", "freqSelect",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m", 0 };

/* Function Definitions */
void freqSelect(const emlrtStack *sp, const emxArray_real_T *fq, emxArray_real_T
                *freq, emxArray_real_T *cent)
{
  emxArray_real_T *cnt;
  int32_T i51;
  int32_T loop_ub;
  int32_T i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &cnt, 2, &ie_emlrtRTEI, true);
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
  st.site = &vm_emlrtRSI;
  fq2cnt(&st, fq, cnt);

  /*  key = cell(1,length(cnt)); */
  i51 = cent->size[0] * cent->size[1];
  cent->size[0] = 1;
  cent->size[1] = cnt->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)cent, i51, (int32_T)sizeof(real_T),
                    &he_emlrtRTEI);
  loop_ub = cnt->size[1];
  for (i51 = 0; i51 < loop_ub; i51++) {
    cent->data[i51] = 0.0;
  }

  i51 = freq->size[0] * freq->size[1];
  freq->size[0] = 1;
  freq->size[1] = cnt->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)freq, i51, (int32_T)sizeof(real_T),
                    &he_emlrtRTEI);
  loop_ub = cnt->size[1];
  for (i51 = 0; i51 < loop_ub; i51++) {
    freq->data[i51] = 0.0;
  }

  i = 1;
  while (i - 1 <= cnt->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 0, 1);
    i51 = cnt->size[1];
    if (!((i >= 1) && (i <= i51))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &kk_emlrtBCI, sp);
    }

    guard1 = false;
    guard2 = false;
    if (covrtLogCond(&emlrtCoverageInstance, 21U, 0U, 0, cnt->data[i - 1] >
                     5050.0)) {
      i51 = cnt->size[1];
      if (!((i >= 1) && (i <= i51))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i51, &lk_emlrtBCI, sp);
      }

      if (covrtLogCond(&emlrtCoverageInstance, 21U, 0U, 1, cnt->data[i - 1] <=
                       7450.0)) {
        covrtLogMcdc(&emlrtCoverageInstance, 21U, 0U, 0, true);
        covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 0, true);
        i51 = cnt->size[1];
        if (!((i >= 1) && (i <= i51))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ln_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 1, cnt->data[i - 1] >
                       6250.0)) {
          i51 = cnt->size[1];
          if (!((i >= 1) && (i <= i51))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i51, &wo_emlrtBCI, sp);
          }

          if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 2, cnt->data[i - 1] >
                         6850.0)) {
            i51 = cnt->size[1];
            if (!((i >= 1) && (i <= i51))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i51, &pp_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 3, cnt->data[i - 1] >
                           7150.0)) {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &yp_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 4, cnt->data[i - 1]
                             > 7250.0)) {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &cq_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 5, cnt->data[i -
                               1] > 7350.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 1);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &fq_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 987.767;

                  /*  7400 */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &gq_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 7400.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 2);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &dq_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 932.328;

                  /*  7300   */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &eq_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 7300.0;
                }
              } else {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 3);
                i51 = freq->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &aq_emlrtBCI, sp);
                }

                freq->data[i - 1] = 880.0;

                /*  7200    */
                i51 = cent->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &bq_emlrtBCI, sp);
                }

                cent->data[i - 1] = 7200.0;
              }
            } else {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &qp_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 6, cnt->data[i - 1]
                             > 7050.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 4);
                i51 = freq->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &wp_emlrtBCI, sp);
                }

                freq->data[i - 1] = 830.609;

                /*  7100  */
                i51 = cent->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &xp_emlrtBCI, sp);
                }

                cent->data[i - 1] = 7100.0;
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &rp_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 7, cnt->data[i -
                               1] > 6950.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 5);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &up_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 783.991;

                  /*  7000     */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &vp_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 7000.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 6);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &sp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 739.989;

                  /*  6900     */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &tp_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6900.0;
                }
              }
            }
          } else {
            i51 = cnt->size[1];
            if (!((i >= 1) && (i <= i51))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i51, &xo_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 8, cnt->data[i - 1] >
                           6550.0)) {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &hp_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 9, cnt->data[i - 1]
                             > 6750.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 7);
                i51 = freq->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &np_emlrtBCI, sp);
                }

                freq->data[i - 1] = 698.456;

                /*  6800 */
                i51 = cent->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &op_emlrtBCI, sp);
                }

                cent->data[i - 1] = 6800.0;
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ip_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 10, cnt->data[i
                               - 1] > 6650.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 8);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &lp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 659.255;

                  /*  6700 */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &mp_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6700.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 9);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &jp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 622.254;

                  /*  6600        */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &kp_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6600.0;
                }
              }
            } else {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &yo_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 11, cnt->data[i -
                             1] > 6450.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 10);
                i51 = freq->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &fp_emlrtBCI, sp);
                }

                freq->data[i - 1] = 587.33;

                /*  6500     */
                i51 = cent->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &gp_emlrtBCI, sp);
                }

                cent->data[i - 1] = 6500.0;
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ap_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 12, cnt->data[i
                               - 1] > 6350.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 11);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &dp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 554.365;

                  /*  6400   */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ep_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6400.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 12);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &bp_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 523.251;

                  /*  6300       */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &cp_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6300.0;
                }
              }
            }
          }
        } else {
          i51 = cnt->size[1];
          if (!((i >= 1) && (i <= i51))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i51, &mn_emlrtBCI, sp);
          }

          if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 13, cnt->data[i - 1] >
                         5650.0)) {
            i51 = cnt->size[1];
            if (!((i >= 1) && (i <= i51))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i51, &fo_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 14, cnt->data[i - 1]
                           > 5950.0)) {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &oo_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 15, cnt->data[i -
                             1] > 6150.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 13);
                i51 = freq->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &uo_emlrtBCI, sp);
                }

                freq->data[i - 1] = 493.883;

                /*  6200  */
                i51 = cent->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &vo_emlrtBCI, sp);
                }

                cent->data[i - 1] = 6200.0;
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &po_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 16, cnt->data[i
                               - 1] > 6050.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 14);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &so_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 466.164;

                  /*  6100  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &to_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6100.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 15);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &qo_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 440.0;

                  /*  6000 */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ro_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 6000.0;
                }
              }
            } else {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &go_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 17, cnt->data[i -
                             1] > 5850.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 16);
                i51 = freq->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &mo_emlrtBCI, sp);
                }

                freq->data[i - 1] = 415.305;

                /*  5900  */
                i51 = cent->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &no_emlrtBCI, sp);
                }

                cent->data[i - 1] = 5900.0;
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ho_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 18, cnt->data[i
                               - 1] > 5750.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 17);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ko_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 391.995;

                  /*  5800  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &lo_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5800.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 18);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &io_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 369.994;

                  /*  5700 */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &jo_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5700.0;
                }
              }
            }
          } else {
            i51 = cnt->size[1];
            if (!((i >= 1) && (i <= i51))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i51, &nn_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 19, cnt->data[i - 1]
                           > 5350.0)) {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &wn_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 20, cnt->data[i -
                             1] > 5550.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 19);
                i51 = freq->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &do_emlrtBCI, sp);
                }

                freq->data[i - 1] = 349.228;

                /*  5600  */
                i51 = cent->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &eo_emlrtBCI, sp);
                }

                cent->data[i - 1] = 5600.0;
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &xn_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 21, cnt->data[i
                               - 1] > 5450.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 20);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &bo_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 329.628;

                  /*  5500  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &co_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5500.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 21);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &yn_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 311.127;

                  /*  5400  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ao_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5400.0;
                }
              }
            } else {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &on_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 22, cnt->data[i -
                             1] > 5250.0)) {
                covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 22);
                i51 = freq->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &un_emlrtBCI, sp);
                }

                freq->data[i - 1] = 293.665;

                /*  5300  */
                i51 = cent->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &vn_emlrtBCI, sp);
                }

                cent->data[i - 1] = 5300.0;
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &pn_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 23, cnt->data[i
                               - 1] > 5150.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 23);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &sn_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 277.183;

                  /*  5200  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &tn_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5200.0;
                } else {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 24);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &qn_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 261.626;

                  /*  5100   */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &rn_emlrtBCI, sp);
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
      i51 = cnt->size[1];
      if (!((i >= 1) && (i <= i51))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i51, &mk_emlrtBCI, sp);
      }

      if (covrtLogCond(&emlrtCoverageInstance, 21U, 0U, 2, cnt->data[i - 1] <=
                       5050.0)) {
        i51 = cnt->size[1];
        if (!((i >= 1) && (i <= i51))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i51, &nk_emlrtBCI, sp);
        }

        if (covrtLogCond(&emlrtCoverageInstance, 21U, 0U, 3, cnt->data[i - 1] >
                         2650.0)) {
          covrtLogMcdc(&emlrtCoverageInstance, 21U, 0U, 1, true);
          covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 24, true);
          i51 = cnt->size[1];
          if (!((i >= 1) && (i <= i51))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i51, &pk_emlrtBCI, sp);
          }

          if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 25, cnt->data[i - 1] >
                         3850.0)) {
            i51 = cnt->size[1];
            if (!((i >= 1) && (i <= i51))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i51, &bm_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 26, cnt->data[i - 1]
                           > 4450.0)) {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &tm_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 27, cnt->data[i -
                             1] > 4750.0)) {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &dn_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 28, cnt->data[i
                               - 1] > 4950.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 25);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &jn_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 246.942;

                  /*  5000   */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &kn_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 5000.0;
                } else {
                  i51 = cnt->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &en_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 29, cnt->
                                 data[i - 1] > 4850.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 26);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &hn_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 233.082;

                    /*  4900 */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &in_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4900.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 27);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &fn_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 220.0;

                    /*  4800   */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &gn_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4800.0;
                  }
                }
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &um_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 30, cnt->data[i
                               - 1] > 4650.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 28);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &bn_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 207.652;

                  /*  4700  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &cn_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 4700.0;
                } else {
                  i51 = cnt->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &vm_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 31, cnt->
                                 data[i - 1] > 4550.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 29);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ym_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 195.998;

                    /*  4600  */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &an_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4600.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 30);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &wm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 184.997;

                    /*  4500 */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &xm_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4500.0;
                  }
                }
              }
            } else {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &cm_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 32, cnt->data[i -
                             1] > 4150.0)) {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &lm_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 33, cnt->data[i
                               - 1] > 4350.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 31);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &rm_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 174.614;

                  /*  4400  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &sm_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 4400.0;
                } else {
                  i51 = cnt->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &mm_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 34, cnt->
                                 data[i - 1] > 4250.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 32);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &pm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 164.814;

                    /*  4300 */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &qm_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4300.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 33);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &nm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 155.563;

                    /*  4200 */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &om_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4200.0;
                  }
                }
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &dm_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 35, cnt->data[i
                               - 1] > 4050.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 34);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &jm_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 146.832;

                  /*  4100  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &km_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 4100.0;
                } else {
                  i51 = cnt->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &em_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 36, cnt->
                                 data[i - 1] > 3950.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 35);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &hm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 138.591;

                    /*  4000  */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &im_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 4000.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 36);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &fm_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 130.813;

                    /*  3900 */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &gm_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3900.0;
                  }
                }
              }
            }
          } else {
            i51 = cnt->size[1];
            if (!((i >= 1) && (i <= i51))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i51, &qk_emlrtBCI, sp);
            }

            if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 37, cnt->data[i - 1]
                           > 3250.0)) {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &jl_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 38, cnt->data[i -
                             1] > 3550.0)) {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &sl_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 39, cnt->data[i
                               - 1] > 3750.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 37);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &yl_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 123.471;

                  /*  3800 */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &am_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 3800.0;
                } else {
                  i51 = cnt->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &tl_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 40, cnt->
                                 data[i - 1] > 3650.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 38);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &wl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 116.541;

                    /*  3700     */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &xl_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3700.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 39);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ul_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 110.0;

                    /*  3600 */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &vl_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3600.0;
                  }
                }
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &kl_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 41, cnt->data[i
                               - 1] > 3450.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 40);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ql_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 103.826;

                  /*  3500  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &rl_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 3500.0;
                } else {
                  i51 = cnt->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ll_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 42, cnt->
                                 data[i - 1] > 3350.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 41);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ol_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 97.9989;

                    /*  3400 */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &pl_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3400.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 42);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ml_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 92.4986;

                    /*  3300  */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &nl_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3300.0;
                  }
                }
              }
            } else {
              i51 = cnt->size[1];
              if (!((i >= 1) && (i <= i51))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i51, &rk_emlrtBCI, sp);
              }

              if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 43, cnt->data[i -
                             1] > 2950.0)) {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &bl_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 44, cnt->data[i
                               - 1] > 3150.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 43);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &hl_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 87.3071;

                  /*  3200  */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &il_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 3200.0;
                } else {
                  i51 = cnt->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &cl_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 45, cnt->
                                 data[i - 1] > 3050.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 44);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &fl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 82.4069;

                    /*  3100    */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &gl_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3100.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 45);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &dl_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 77.7817;

                    /*  3000  */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &el_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 3000.0;
                  }
                }
              } else {
                i51 = cnt->size[1];
                if (!((i >= 1) && (i <= i51))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, i51, &sk_emlrtBCI, sp);
                }

                if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 46, cnt->data[i
                               - 1] > 2850.0)) {
                  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 46);
                  i51 = freq->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &yk_emlrtBCI, sp);
                  }

                  freq->data[i - 1] = 73.4162;

                  /*  2900 */
                  i51 = cent->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &al_emlrtBCI, sp);
                  }

                  cent->data[i - 1] = 2900.0;
                } else {
                  i51 = cnt->size[1];
                  if (!((i >= 1) && (i <= i51))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, i51, &tk_emlrtBCI, sp);
                  }

                  if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 47, cnt->
                                 data[i - 1] > 2750.0)) {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 47);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &wk_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 69.2957;

                    /*  2800   */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &xk_emlrtBCI, sp);
                    }

                    cent->data[i - 1] = 2800.0;
                  } else {
                    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 48);
                    i51 = freq->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &uk_emlrtBCI, sp);
                    }

                    freq->data[i - 1] = 65.4064;

                    /*  2700   */
                    i51 = cent->size[1];
                    if (!((i >= 1) && (i <= i51))) {
                      emlrtDynamicBoundsCheckR2012b(i, 1, i51, &vk_emlrtBCI, sp);
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
      i51 = cent->size[1];
      if (!((i >= 1) && (i <= i51))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i51, &ok_emlrtBCI, sp);
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
