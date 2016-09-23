/*
 * refine.c
 *
 * Code generation for function 'refine'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "refine.h"
#include "error.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "Mymedfilt1.h"
#include "sort1.h"
#include "cat.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wl_emlrtRSI = { 45, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo xl_emlrtRSI = { 46, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo yl_emlrtRSI = { 51, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo am_emlrtRSI = { 57, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo bm_emlrtRSI = { 108, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo ce_emlrtRTEI = { 1, 26, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo de_emlrtRTEI = { 57, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtECInfo ec_emlrtECI = { -1, 107, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo oi_emlrtBCI = { -1, -1, 107, 7, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo fc_emlrtECI = { -1, 106, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo pi_emlrtBCI = { -1, -1, 106, 7, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qi_emlrtBCI = { -1, -1, 101, 40, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ri_emlrtBCI = { -1, -1, 99, 37, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo si_emlrtBCI = { -1, -1, 86, 30, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ti_emlrtBCI = { -1, -1, 86, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ui_emlrtBCI = { -1, -1, 86, 45, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo vi_emlrtBCI = { -1, -1, 85, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo wi_emlrtBCI = { -1, -1, 85, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo xi_emlrtBCI = { -1, -1, 81, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo yi_emlrtBCI = { -1, -1, 81, 33, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo aj_emlrtBCI = { -1, -1, 80, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bj_emlrtBCI = { -1, -1, 71, 44, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo cj_emlrtBCI = { -1, -1, 65, 17, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo dj_emlrtBCI = { -1, -1, 67, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ej_emlrtBCI = { -1, -1, 64, 17, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo gc_emlrtECI = { 2, 57, 13, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo fj_emlrtBCI = { -1, -1, 57, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo hc_emlrtECI = { -1, 53, 5, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo gj_emlrtBCI = { -1, -1, 53, 13, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hj_emlrtBCI = { -1, -1, 53, 33, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ij_emlrtBCI = { -1, -1, 53, 30, "Idx", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jj_emlrtBCI = { -1, -1, 108, 1, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kj_emlrtBCI = { -1, -1, 94, 39, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lj_emlrtBCI = { -1, -1, 94, 11, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mj_emlrtBCI = { -1, -1, 94, 22, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo nj_emlrtBCI = { -1, -1, 98, 21, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo oj_emlrtBCI = { -1, -1, 101, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo pj_emlrtBCI = { -1, -1, 101, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qj_emlrtBCI = { -1, -1, 99, 39, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo rj_emlrtBCI = { -1, -1, 99, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo sj_emlrtBCI = { -1, -1, 99, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo tj_emlrtBCI = { -1, -1, 62, 9, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo uj_emlrtBCI = { -1, -1, 67, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo vj_emlrtBCI = { -1, -1, 80, 27, "SPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo wj_emlrtBCI = { -1, -1, 80, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo xj_emlrtBCI = { -1, -1, 81, 21, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo yj_emlrtBCI = { -1, -1, 86, 47, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ak_emlrtBCI = { -1, -1, 70, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bk_emlrtBCI = { -1, -1, 70, 28, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ck_emlrtBCI = { -1, -1, 71, 46, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo dk_emlrtBCI = { -1, -1, 71, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ek_emlrtBCI = { -1, -1, 71, 28, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo fk_emlrtBCI = { -1, -1, 73, 27, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo gk_emlrtBCI = { -1, -1, 73, 29, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hk_emlrtBCI = { -1, -1, 74, 27, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ik_emlrtBCI = { -1, -1, 74, 29, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jk_emlrtBCI = { -1, -1, 53, 24, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

/* Function Definitions */
void refine(const emlrtStack *sp, const emxArray_real_T *TPitch1, const
            emxArray_real_T *TMerit1, const emxArray_real_T *TPitch2, const
            emxArray_real_T *TMerit2, const emxArray_real_T *SPitch, const
            emxArray_real_T *Energy, const emxArray_boolean_T *VUVEnergy, real_T
            Prm_nlfer_thresh2, real_T Prm_merit_pivot, real_T Prm_median_value,
            emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  emxArray_real_T *Idx;
  emxArray_int32_T *iidx;
  int32_T numframes;
  int32_T maxcands;
  int32_T i50;
  int32_T itilerow;
  int32_T n;
  emxArray_real_T *r38;
  emxArray_int32_T *r39;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *c_Pitch;
  int32_T Pitch_idx_0;
  int32_T d_Pitch;
  emxArray_real_T *BestPitch;
  int32_T ibmat;
  int32_T b_BestPitch[2];
  int32_T b_VUVEnergy[2];
  int32_T iv51[1];
  int32_T outsize_idx_1;
  int32_T e_Pitch[1];
  int32_T i;
  int32_T iv52[2];
  int32_T j;
  int32_T iv53[2];
  const mxArray *y;
  char_T u[15];
  static const char_T cv7[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *m11;
  static const int32_T iv54[2] = { 1, 15 };

  real_T b_Merit;
  emxArray_boolean_T *b;
  const mxArray *b_y;
  char_T b_u[15];
  static const int32_T iv55[2] = { 1, 15 };

  boolean_T overflow;
  emxArray_int32_T *r40;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Idx, 2, &ce_emlrtRTEI, true);
  emxInit_int32_T(sp, &iidx, 2, &ce_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 19U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 0);

  /*  REFINE Refine pitch candidates for YAAPT Pitch tracking */
  /*  */
  /*  [Pitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, Energy, VUVEnergy, Prm) */
  /*    refins pitch cadidates obtained from NCCF using spectral pitch */
  /*    track and NLFER energy information. */
  /*  */
  /*  INPUTS:  */
  /*    TPitch1:  Pitch candidates array 1 */
  /*    TMerti1:  Merits for pitch candidates array 1 */
  /*    TPitch2:  Pitch candidates array 2 */
  /*    TMerti2:  Merits for pitch candidates array 2 */
  /*    SPitch:   Smoothed spectral pitch track */
  /*    Energy:   NLFER Energy information */
  /*    VUVEnergy: Voiced/Unvoiced information determined by NLFER energy */
  /*    Prm:      Parameters */
  /*  */
  /*  OUTPUTS: */
  /*    Pitch:   Refined overall pitch candidates */
  /*    Merit:   Merit for overall pitch candidates */
  /*    Creation: July 27 2007 */
  /*    Author:   Hongbing Hu */
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
  /* -- PARAMETERS ---------------------------------------------------------------- */
  /*  Threshold for NLFER energy */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Merge pitch candidates and their merits from two types of the signal */
  st.site = &wl_emlrtRSI;
  cat(&st, TPitch1, TPitch2, Pitch);
  st.site = &xl_emlrtRSI;
  cat(&st, TMerit1, TMerit2, Merit);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  numframes = Pitch->size[1] - 1;
  maxcands = Pitch->size[0];
  st.site = &yl_emlrtRSI;
  b_st.site = &kj_emlrtRSI;
  e_sort(&b_st, Merit, iidx);
  i50 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Idx, i50, (int32_T)sizeof(real_T),
                    &ce_emlrtRTEI);
  itilerow = iidx->size[0] * iidx->size[1];
  for (i50 = 0; i50 < itilerow; i50++) {
    Idx->data[i50] = iidx->data[i50];
  }

  emxFree_int32_T(&iidx);
  n = 0;
  emxInit_real_T2(sp, &r38, 1, &ce_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r39, 1, &ce_emlrtRTEI, true);
  emxInit_real_T2(sp, &b_Pitch, 1, &ce_emlrtRTEI, true);
  while (n <= numframes) {
    covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 1);
    itilerow = Pitch->size[0];
    i50 = r39->size[0];
    r39->size[0] = itilerow;
    emxEnsureCapacity(sp, (emxArray__common *)r39, i50, (int32_T)sizeof(int32_T),
                      &ce_emlrtRTEI);
    for (i50 = 0; i50 < itilerow; i50++) {
      r39->data[i50] = i50;
    }

    i50 = Pitch->size[1];
    Pitch_idx_0 = n + 1;
    if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
      emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &gj_emlrtBCI, sp);
    }

    itilerow = Idx->size[0];
    i50 = Idx->size[1];
    Pitch_idx_0 = 1 + n;
    if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
      emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &ij_emlrtBCI, sp);
    }

    d_Pitch = Pitch->size[0];
    i50 = Pitch->size[1];
    ibmat = 1 + n;
    if (!((ibmat >= 1) && (ibmat <= i50))) {
      emlrtDynamicBoundsCheckR2012b(ibmat, 1, i50, &hj_emlrtBCI, sp);
    }

    i50 = r38->size[0];
    r38->size[0] = itilerow;
    emxEnsureCapacity(sp, (emxArray__common *)r38, i50, (int32_T)sizeof(real_T),
                      &ce_emlrtRTEI);
    for (i50 = 0; i50 < itilerow; i50++) {
      outsize_idx_1 = (int32_T)Idx->data[i50 + Idx->size[0] * (Pitch_idx_0 - 1)];
      if (!((outsize_idx_1 >= 1) && (outsize_idx_1 <= d_Pitch))) {
        emlrtDynamicBoundsCheckR2012b(outsize_idx_1, 1, d_Pitch, &jk_emlrtBCI,
          sp);
      }

      r38->data[i50] = Pitch->data[(outsize_idx_1 + Pitch->size[0] * (ibmat - 1))
        - 1];
    }

    iv51[0] = r39->size[0];
    itilerow = Idx->size[0];
    i50 = b_Pitch->size[0];
    b_Pitch->size[0] = itilerow;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i50, (int32_T)sizeof
                      (real_T), &ce_emlrtRTEI);
    for (i50 = 0; i50 < itilerow; i50++) {
      b_Pitch->data[i50] = Pitch->data[((int32_T)Idx->data[i50 + Idx->size[0] *
        n] + Pitch->size[0] * n) - 1];
    }

    e_Pitch[0] = b_Pitch->size[0];
    emlrtSubAssignSizeCheckR2012b(iv51, 1, e_Pitch, 1, &hc_emlrtECI, sp);
    itilerow = r38->size[0];
    for (i50 = 0; i50 < itilerow; i50++) {
      Pitch->data[r39->data[i50] + Pitch->size[0] * n] = r38->data[i50];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Pitch);
  emxFree_real_T(&r38);
  emxFree_real_T(&Idx);
  emxInit_real_T(sp, &c_Pitch, 2, &ce_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 2);

  /*  A best pitch track is generated from the best candidates */
  i50 = Pitch->size[0];
  if (!(1 <= i50)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i50, &fj_emlrtBCI, sp);
  }

  itilerow = Pitch->size[1];
  i50 = c_Pitch->size[0] * c_Pitch->size[1];
  c_Pitch->size[0] = 1;
  c_Pitch->size[1] = itilerow;
  emxEnsureCapacity(sp, (emxArray__common *)c_Pitch, i50, (int32_T)sizeof(real_T),
                    &ce_emlrtRTEI);
  for (i50 = 0; i50 < itilerow; i50++) {
    c_Pitch->data[c_Pitch->size[0] * i50] = Pitch->data[Pitch->size[0] * i50];
  }

  emxInit_real_T(sp, &BestPitch, 2, &de_emlrtRTEI, true);
  st.site = &am_emlrtRSI;
  Mymedfilt1(&st, c_Pitch, Prm_median_value, BestPitch);
  emxFree_real_T(&c_Pitch);
  for (i50 = 0; i50 < 2; i50++) {
    b_BestPitch[i50] = BestPitch->size[i50];
  }

  for (i50 = 0; i50 < 2; i50++) {
    b_VUVEnergy[i50] = VUVEnergy->size[i50];
  }

  if ((b_BestPitch[0] != b_VUVEnergy[0]) || (b_BestPitch[1] != b_VUVEnergy[1]))
  {
    emlrtSizeEqCheckNDR2012b(&b_BestPitch[0], &b_VUVEnergy[0], &gc_emlrtECI, sp);
  }

  i50 = BestPitch->size[0] * BestPitch->size[1];
  BestPitch->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)BestPitch, i50, (int32_T)sizeof
                    (real_T), &ce_emlrtRTEI);
  ibmat = BestPitch->size[0];
  outsize_idx_1 = BestPitch->size[1];
  itilerow = ibmat * outsize_idx_1;
  for (i50 = 0; i50 < itilerow; i50++) {
    BestPitch->data[i50] *= (real_T)VUVEnergy->data[i50];
  }

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  i = 1;
  while (i - 1 <= numframes) {
    covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 1, 1);
    i50 = Energy->size[1];
    if (!((i >= 1) && (i <= i50))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i50, &tj_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 19U, 0U, 0, Energy->data[i - 1] <=
                   Prm_nlfer_thresh2)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 3);

      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      itilerow = Pitch->size[0];
      d_Pitch = Pitch->size[1];
      if (!((i >= 1) && (i <= d_Pitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, d_Pitch, &ej_emlrtBCI, sp);
      }

      for (i50 = 0; i50 < itilerow; i50++) {
        Pitch->data[i50 + Pitch->size[0] * (i - 1)] = 0.0;
      }

      itilerow = Merit->size[0];
      outsize_idx_1 = Merit->size[1];
      if (!((i >= 1) && (i <= outsize_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, outsize_idx_1, &cj_emlrtBCI, sp);
      }

      for (i50 = 0; i50 < itilerow; i50++) {
        Merit->data[i50 + Merit->size[0] * (i - 1)] = Prm_merit_pivot;
      }
    } else {
      i50 = Pitch->size[0];
      if (!(1 <= i50)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i50, &dj_emlrtBCI, sp);
      }

      i50 = Pitch->size[1];
      if (!((i >= 1) && (i <= i50))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i50, &uj_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 19U, 0U, 1, Pitch->data[Pitch->
                     size[0] * (i - 1)] > 0.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 4);

        /*  already have the voiced candidate, Want to have at */
        /*  least one unvoiced candidate */
        i50 = Pitch->size[0];
        if (!((maxcands >= 1) && (maxcands <= i50))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i50, &ak_emlrtBCI, sp);
        }

        i50 = Pitch->size[1];
        if (!((i >= 1) && (i <= i50))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i50, &bk_emlrtBCI, sp);
        }

        Pitch->data[(maxcands + Pitch->size[0] * (i - 1)) - 1] = 0.0;
        i50 = Merit->size[0];
        if (!(1 <= i50)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i50, &bj_emlrtBCI, sp);
        }

        i50 = Merit->size[1];
        if (!((i >= 1) && (i <= i50))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i50, &ck_emlrtBCI, sp);
        }

        i50 = Merit->size[0];
        if (!((maxcands >= 1) && (maxcands <= i50))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i50, &dk_emlrtBCI, sp);
        }

        i50 = Merit->size[1];
        if (!((i >= 1) && (i <= i50))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i50, &ek_emlrtBCI, sp);
        }

        Merit->data[(maxcands + Merit->size[0] * (i - 1)) - 1] = 1.0 -
          Merit->data[Merit->size[0] * (i - 1)];
        j = 2;
        while (j - 2 <= maxcands - 3) {
          covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 2, 1);
          i50 = Pitch->size[0];
          if (!((j >= 1) && (j <= i50))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i50, &fk_emlrtBCI, sp);
          }

          i50 = Pitch->size[1];
          if (!((i >= 1) && (i <= i50))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i50, &gk_emlrtBCI, sp);
          }

          if (covrtLogIf(&emlrtCoverageInstance, 19U, 0U, 2, Pitch->data[(j +
                Pitch->size[0] * (i - 1)) - 1] == 0.0)) {
            covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 5);
            i50 = Merit->size[0];
            if (!((j >= 1) && (j <= i50))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i50, &hk_emlrtBCI, sp);
            }

            i50 = Merit->size[1];
            if (!((i >= 1) && (i <= i50))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i50, &ik_emlrtBCI, sp);
            }

            Merit->data[(j + Merit->size[0] * (i - 1)) - 1] = 0.0;
          }

          j++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 2, 0);
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 6);

        /*  there was no voiced candidate from nccf fill in */
        /*  option for F0 from spectrogram */
        i50 = Pitch->size[0];
        if (!(1 <= i50)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i50, &aj_emlrtBCI, sp);
        }

        i50 = SPitch->size[1];
        if (!((i >= 1) && (i <= i50))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i50, &vj_emlrtBCI, sp);
        }

        i50 = Pitch->size[1];
        if (!((i >= 1) && (i <= i50))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i50, &wj_emlrtBCI, sp);
        }

        Pitch->data[Pitch->size[0] * (i - 1)] = SPitch->data[i - 1];
        i50 = Merit->size[0];
        if (!(1 <= i50)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i50, &xi_emlrtBCI, sp);
        }

        i50 = Energy->size[1];
        Pitch_idx_0 = (i - 1) + 1;
        if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
          emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &yi_emlrtBCI, sp);
        }

        i50 = Merit->size[1];
        if (!((i >= 1) && (i <= i50))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i50, &xj_emlrtBCI, sp);
        }

        Merit->data[Merit->size[0] * (i - 1)] = muDoubleScalarMin(1.0,
          Energy->data[i - 1] / 2.0);

        /*  all other candidates will be unvoiced */
        /*  with low merit */
        if (2 > maxcands) {
          i50 = 0;
          Pitch_idx_0 = 0;
        } else {
          i50 = Pitch->size[0];
          if (!(2 <= i50)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i50, &wi_emlrtBCI, sp);
          }

          i50 = 1;
          Pitch_idx_0 = Pitch->size[0];
          if (!(maxcands <= Pitch_idx_0)) {
            emlrtDynamicBoundsCheckR2012b(maxcands, 1, Pitch_idx_0, &wi_emlrtBCI,
              sp);
          }

          Pitch_idx_0 = maxcands;
        }

        d_Pitch = Pitch->size[1];
        if (!((i >= 1) && (i <= d_Pitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, d_Pitch, &vi_emlrtBCI, sp);
        }

        itilerow = Pitch_idx_0 - i50;
        for (Pitch_idx_0 = 0; Pitch_idx_0 < itilerow; Pitch_idx_0++) {
          Pitch->data[(i50 + Pitch_idx_0) + Pitch->size[0] * (i - 1)] = 0.0;
        }

        if (2 > maxcands) {
          i50 = 0;
          Pitch_idx_0 = 0;
        } else {
          i50 = Merit->size[0];
          if (!(2 <= i50)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i50, &ti_emlrtBCI, sp);
          }

          i50 = 1;
          Pitch_idx_0 = Merit->size[0];
          if (!(maxcands <= Pitch_idx_0)) {
            emlrtDynamicBoundsCheckR2012b(maxcands, 1, Pitch_idx_0, &ti_emlrtBCI,
              sp);
          }

          Pitch_idx_0 = maxcands;
        }

        ibmat = Merit->size[0];
        if (!(1 <= ibmat)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, ibmat, &ui_emlrtBCI, sp);
        }

        outsize_idx_1 = Merit->size[1];
        if (!((i >= 1) && (i <= outsize_idx_1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, outsize_idx_1, &yj_emlrtBCI, sp);
        }

        b_Merit = Merit->data[Merit->size[0] * (i - 1)];
        outsize_idx_1 = Merit->size[1];
        if (!((i >= 1) && (i <= outsize_idx_1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, outsize_idx_1, &si_emlrtBCI, sp);
        }

        itilerow = Pitch_idx_0 - i50;
        for (Pitch_idx_0 = 0; Pitch_idx_0 < itilerow; Pitch_idx_0++) {
          Merit->data[(i50 + Pitch_idx_0) + Merit->size[0] * (i - 1)] = 1.0 -
            b_Merit;
        }
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 1, 0);

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  i = 1;
  while (i - 1 <= numframes) {
    covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 7);
    i50 = BestPitch->size[1];
    if (!((i >= 1) && (i <= i50))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i50, &kj_emlrtBCI, sp);
    }

    i50 = Pitch->size[0];
    Pitch_idx_0 = maxcands - 1;
    if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
      emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &lj_emlrtBCI, sp);
    }

    i50 = Pitch->size[1];
    if (!((i >= 1) && (i <= i50))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i50, &mj_emlrtBCI, sp);
    }

    Pitch->data[(Pitch_idx_0 + Pitch->size[0] * (i - 1)) - 1] = BestPitch->
      data[BestPitch->size[0] * (i - 1)];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    i50 = BestPitch->size[1];
    if (!((i >= 1) && (i <= i50))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i50, &nj_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 19U, 0U, 3, BestPitch->data
                   [BestPitch->size[0] * (i - 1)] > 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 8);

      /*  voiced */
      i50 = Merit->size[0];
      if (!(1 <= i50)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i50, &ri_emlrtBCI, sp);
      }

      i50 = Merit->size[1];
      if (!((i >= 1) && (i <= i50))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i50, &qj_emlrtBCI, sp);
      }

      i50 = Merit->size[0];
      Pitch_idx_0 = maxcands - 1;
      if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
        emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &rj_emlrtBCI, sp);
      }

      i50 = Merit->size[1];
      if (!((i >= 1) && (i <= i50))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i50, &sj_emlrtBCI, sp);
      }

      Merit->data[(Pitch_idx_0 + Merit->size[0] * (i - 1)) - 1] = Merit->
        data[Merit->size[0] * (i - 1)];
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 9);

      /*  unvoiced */
      i50 = Energy->size[1];
      Pitch_idx_0 = (i - 1) + 1;
      if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
        emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &qi_emlrtBCI, sp);
      }

      i50 = Merit->size[0];
      Pitch_idx_0 = maxcands - 1;
      if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
        emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &oj_emlrtBCI, sp);
      }

      i50 = Merit->size[1];
      if (!((i >= 1) && (i <= i50))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i50, &pj_emlrtBCI, sp);
      }

      Merit->data[(Pitch_idx_0 + Merit->size[0] * (i - 1)) - 1] = 1.0 -
        muDoubleScalarMin(1.0, Energy->data[i - 1] / 2.0);
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 10);

  /*   Copy over the SPitch array */
  i50 = Pitch->size[0];
  Pitch_idx_0 = (int32_T)((real_T)maxcands - 2.0);
  if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
    emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &pi_emlrtBCI, sp);
  }

  itilerow = Pitch->size[1];
  i50 = r39->size[0];
  r39->size[0] = itilerow;
  emxEnsureCapacity(sp, (emxArray__common *)r39, i50, (int32_T)sizeof(int32_T),
                    &ce_emlrtRTEI);
  for (i50 = 0; i50 < itilerow; i50++) {
    r39->data[i50] = i50;
  }

  iv52[0] = 1;
  iv52[1] = r39->size[0];
  emlrtSubAssignSizeCheckR2012b(iv52, 2, *(int32_T (*)[2])SPitch->size, 2,
    &fc_emlrtECI, sp);
  itilerow = SPitch->size[1];
  for (i50 = 0; i50 < itilerow; i50++) {
    Pitch->data[(maxcands + Pitch->size[0] * r39->data[i50]) - 3] = SPitch->
      data[SPitch->size[0] * i50];
  }

  i50 = Merit->size[0];
  Pitch_idx_0 = (int32_T)((real_T)maxcands - 2.0);
  if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= i50))) {
    emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, i50, &oi_emlrtBCI, sp);
  }

  itilerow = Merit->size[1];
  i50 = r39->size[0];
  r39->size[0] = itilerow;
  emxEnsureCapacity(sp, (emxArray__common *)r39, i50, (int32_T)sizeof(int32_T),
                    &ce_emlrtRTEI);
  for (i50 = 0; i50 < itilerow; i50++) {
    r39->data[i50] = i50;
  }

  i50 = BestPitch->size[0] * BestPitch->size[1];
  BestPitch->size[0] = 1;
  BestPitch->size[1] = Energy->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)BestPitch, i50, (int32_T)sizeof
                    (real_T), &ce_emlrtRTEI);
  itilerow = Energy->size[0] * Energy->size[1];
  for (i50 = 0; i50 < itilerow; i50++) {
    BestPitch->data[i50] = Energy->data[i50] / 5.0;
  }

  iv53[0] = 1;
  iv53[1] = r39->size[0];
  emlrtSubAssignSizeCheckR2012b(iv53, 2, *(int32_T (*)[2])BestPitch->size, 2,
    &ec_emlrtECI, sp);
  itilerow = BestPitch->size[1];
  for (i50 = 0; i50 < itilerow; i50++) {
    Merit->data[(maxcands + Merit->size[0] * r39->data[i50]) - 3] =
      BestPitch->data[BestPitch->size[0] * i50];
  }

  emxFree_int32_T(&r39);
  emxFree_real_T(&BestPitch);
  st.site = &bm_emlrtRSI;
  b_st.site = &oc_emlrtRSI;
  b_assertValidSizeArg(&b_st, Pitch->size[0]);
  Pitch_idx_0 = Pitch->size[0];
  outsize_idx_1 = Pitch->size[0];
  if (Pitch_idx_0 == outsize_idx_1) {
  } else {
    for (i50 = 0; i50 < 15; i50++) {
      u[i50] = cv7[i50];
    }

    y = NULL;
    m11 = emlrtCreateCharArray(2, iv54);
    emlrtInitCharArrayR2013a(&st, 15, m11, &u[0]);
    emlrtAssign(&y, m11);
    b_st.site = &so_emlrtRSI;
    n_error(&b_st, y, &b_emlrtMCI);
  }

  outsize_idx_1 = VUVEnergy->size[1];
  if (outsize_idx_1 == VUVEnergy->size[1]) {
  } else {
    for (i50 = 0; i50 < 15; i50++) {
      b_u[i50] = cv7[i50];
    }

    b_y = NULL;
    m11 = emlrtCreateCharArray(2, iv55);
    emlrtInitCharArrayR2013a(&st, 15, m11, &b_u[0]);
    emlrtAssign(&b_y, m11);
    b_st.site = &so_emlrtRSI;
    n_error(&b_st, b_y, &b_emlrtMCI);
  }

  emxInit_boolean_T(&st, &b, 2, &ce_emlrtRTEI, true);
  i50 = b->size[0] * b->size[1];
  b->size[0] = Pitch_idx_0;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity(&st, (emxArray__common *)b, i50, (int32_T)sizeof(boolean_T),
                    &ce_emlrtRTEI);
  if (!(VUVEnergy->size[1] == 0)) {
    if (Pitch_idx_0 == 0) {
      overflow = true;
    } else if (outsize_idx_1 == 0) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (!overflow) {
      Pitch_idx_0 = Pitch->size[0];
      b_st.site = &ti_emlrtRSI;
      overflow = (VUVEnergy->size[1] > 2147483646);
      if (overflow) {
        c_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (outsize_idx_1 = 0; outsize_idx_1 + 1 <= VUVEnergy->size[1];
           outsize_idx_1++) {
        ibmat = outsize_idx_1 * Pitch_idx_0;
        b_st.site = &ui_emlrtRSI;
        if ((!(1 > Pitch_idx_0)) && (Pitch_idx_0 > 2147483646)) {
          c_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (itilerow = 1; itilerow <= Pitch_idx_0; itilerow++) {
          b->data[(ibmat + itilerow) - 1] = VUVEnergy->data[outsize_idx_1];
        }
      }
    }
  }

  i50 = b->size[0] * b->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b, i50, (int32_T)sizeof(boolean_T),
                    &ce_emlrtRTEI);
  outsize_idx_1 = b->size[0];
  ibmat = b->size[1];
  itilerow = outsize_idx_1 * ibmat;
  for (i50 = 0; i50 < itilerow; i50++) {
    b->data[i50] = !b->data[i50];
  }

  itilerow = b->size[0] * b->size[1] - 1;
  outsize_idx_1 = 0;
  for (i = 0; i <= itilerow; i++) {
    if (b->data[i]) {
      outsize_idx_1++;
    }
  }

  emxInit_int32_T1(sp, &r40, 1, &ce_emlrtRTEI, true);
  i50 = r40->size[0];
  r40->size[0] = outsize_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)r40, i50, (int32_T)sizeof(int32_T),
                    &ce_emlrtRTEI);
  ibmat = 0;
  for (i = 0; i <= itilerow; i++) {
    if (b->data[i]) {
      r40->data[ibmat] = i + 1;
      ibmat++;
    }
  }

  emxFree_boolean_T(&b);
  d_Pitch = Pitch->size[0];
  outsize_idx_1 = Pitch->size[1];
  d_Pitch *= outsize_idx_1;
  itilerow = r40->size[0];
  for (i50 = 0; i50 < itilerow; i50++) {
    Pitch_idx_0 = r40->data[i50];
    if (!((Pitch_idx_0 >= 1) && (Pitch_idx_0 <= d_Pitch))) {
      emlrtDynamicBoundsCheckR2012b(Pitch_idx_0, 1, d_Pitch, &jj_emlrtBCI, sp);
    }

    Pitch->data[Pitch_idx_0 - 1] = 0.0;
  }

  emxFree_int32_T(&r40);

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (refine.c) */
