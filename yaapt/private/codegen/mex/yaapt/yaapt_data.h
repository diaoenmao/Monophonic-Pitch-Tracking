/*
 * yaapt_data.h
 *
 * Code generation for function 'yaapt_data'
 *
 */

#ifndef YAAPT_DATA_H
#define YAAPT_DATA_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern covrtInstance emlrtCoverageInstance;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo x_emlrtRSI;
extern emlrtRSInfo y_emlrtRSI;
extern emlrtRSInfo ab_emlrtRSI;
extern emlrtRSInfo bb_emlrtRSI;
extern emlrtRSInfo cb_emlrtRSI;
extern emlrtRSInfo eb_emlrtRSI;
extern emlrtRSInfo fb_emlrtRSI;
extern emlrtRSInfo gb_emlrtRSI;
extern emlrtRSInfo hb_emlrtRSI;
extern emlrtRSInfo ib_emlrtRSI;
extern emlrtRSInfo jb_emlrtRSI;
extern emlrtRSInfo kb_emlrtRSI;
extern emlrtRSInfo gc_emlrtRSI;
extern emlrtRSInfo kc_emlrtRSI;
extern emlrtRSInfo lc_emlrtRSI;
extern emlrtRSInfo mc_emlrtRSI;
extern emlrtRSInfo pc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo rc_emlrtRSI;
extern emlrtRSInfo vc_emlrtRSI;
extern emlrtRSInfo xc_emlrtRSI;
extern emlrtRSInfo yc_emlrtRSI;
extern emlrtRSInfo bd_emlrtRSI;
extern emlrtRSInfo cd_emlrtRSI;
extern emlrtRSInfo dd_emlrtRSI;
extern emlrtRSInfo ed_emlrtRSI;
extern emlrtRSInfo jd_emlrtRSI;
extern emlrtRSInfo kd_emlrtRSI;
extern emlrtRSInfo ld_emlrtRSI;
extern emlrtRSInfo md_emlrtRSI;
extern emlrtRSInfo nd_emlrtRSI;
extern emlrtRSInfo sd_emlrtRSI;
extern emlrtRSInfo td_emlrtRSI;
extern emlrtRSInfo ud_emlrtRSI;
extern emlrtRSInfo de_emlrtRSI;
extern emlrtRSInfo ee_emlrtRSI;
extern emlrtRSInfo oe_emlrtRSI;
extern emlrtRSInfo te_emlrtRSI;
extern emlrtRSInfo rf_emlrtRSI;
extern emlrtRSInfo sf_emlrtRSI;
extern emlrtRSInfo tf_emlrtRSI;
extern emlrtRSInfo uf_emlrtRSI;
extern emlrtRSInfo vf_emlrtRSI;
extern emlrtRSInfo ag_emlrtRSI;
extern emlrtRSInfo bg_emlrtRSI;
extern emlrtRSInfo cg_emlrtRSI;
extern emlrtRSInfo dg_emlrtRSI;
extern emlrtRSInfo eg_emlrtRSI;
extern emlrtRSInfo fg_emlrtRSI;
extern emlrtRSInfo gg_emlrtRSI;
extern emlrtRSInfo hg_emlrtRSI;
extern emlrtRSInfo lh_emlrtRSI;
extern emlrtRSInfo mh_emlrtRSI;
extern emlrtRSInfo nh_emlrtRSI;
extern emlrtRSInfo oh_emlrtRSI;
extern emlrtRSInfo ph_emlrtRSI;
extern emlrtRSInfo qh_emlrtRSI;
extern emlrtRSInfo rh_emlrtRSI;
extern emlrtRSInfo th_emlrtRSI;
extern emlrtRSInfo mk_emlrtRSI;
extern emlrtRSInfo nk_emlrtRSI;
extern emlrtRSInfo ok_emlrtRSI;
extern emlrtRSInfo rk_emlrtRSI;
extern emlrtRSInfo sk_emlrtRSI;
extern emlrtRSInfo tk_emlrtRSI;
extern emlrtRSInfo uk_emlrtRSI;
extern emlrtRSInfo vk_emlrtRSI;
extern emlrtRSInfo wk_emlrtRSI;
extern emlrtRSInfo xk_emlrtRSI;
extern emlrtRSInfo al_emlrtRSI;
extern emlrtRSInfo bl_emlrtRSI;
extern emlrtRSInfo el_emlrtRSI;
extern emlrtRSInfo fl_emlrtRSI;
extern emlrtRSInfo gl_emlrtRSI;
extern emlrtRSInfo ll_emlrtRSI;
extern emlrtRSInfo ol_emlrtRSI;
extern emlrtRSInfo pl_emlrtRSI;
extern emlrtRSInfo cm_emlrtRSI;
extern emlrtRSInfo wm_emlrtRSI;
extern emlrtRSInfo en_emlrtRSI;
extern emlrtRSInfo fn_emlrtRSI;
extern emlrtRSInfo gn_emlrtRSI;
extern emlrtRSInfo hn_emlrtRSI;
extern emlrtRSInfo in_emlrtRSI;
extern emlrtRSInfo jn_emlrtRSI;
extern emlrtRSInfo co_emlrtRSI;
extern emlrtRSInfo tp_emlrtRSI;
extern emlrtRSInfo up_emlrtRSI;
extern emlrtRSInfo vp_emlrtRSI;
extern emlrtRSInfo wp_emlrtRSI;
extern emlrtRSInfo xp_emlrtRSI;
extern emlrtRSInfo yp_emlrtRSI;
extern emlrtRSInfo aq_emlrtRSI;
extern emlrtRSInfo bq_emlrtRSI;
extern emlrtRSInfo cq_emlrtRSI;
extern emlrtRSInfo dq_emlrtRSI;
extern emlrtRSInfo eq_emlrtRSI;
extern emlrtMCInfo emlrtMCI;
extern emlrtMCInfo e_emlrtMCI;
extern emlrtRTEInfo v_emlrtRTEI;
extern emlrtRTEInfo x_emlrtRTEI;
extern emlrtRTEInfo jf_emlrtRTEI;
extern emlrtRTEInfo kf_emlrtRTEI;
extern emlrtRTEInfo lf_emlrtRTEI;
extern emlrtRTEInfo mf_emlrtRTEI;
extern emlrtDCInfo e_emlrtDCI;
extern emlrtRTEInfo qf_emlrtRTEI;
extern emlrtRTEInfo rf_emlrtRTEI;
extern emlrtRTEInfo wf_emlrtRTEI;
extern emlrtRTEInfo xf_emlrtRTEI;
extern emlrtRTEInfo bg_emlrtRTEI;
extern emlrtRTEInfo cg_emlrtRTEI;
extern emlrtRTEInfo hg_emlrtRTEI;
extern emlrtRTEInfo ig_emlrtRTEI;
extern emlrtRTEInfo ng_emlrtRTEI;
extern emlrtRTEInfo og_emlrtRTEI;
extern emlrtRSInfo fq_emlrtRSI;
extern emlrtRSInfo iq_emlrtRSI;

#endif

/* End of code generation (yaapt_data.h) */
