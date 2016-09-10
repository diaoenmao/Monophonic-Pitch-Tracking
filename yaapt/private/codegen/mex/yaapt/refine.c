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
#include "yaapt_emxutil.h"
#include "Mymedfilt1.h"
#include "sort1.h"
#include "cat.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ho_emlrtRSI = { 45, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo io_emlrtRSI = { 46, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo jo_emlrtRSI = { 51, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo ko_emlrtRSI = { 57, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo qe_emlrtRTEI = { 1, 26, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo re_emlrtRTEI = { 57, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo aj_emlrtBCI = { -1, -1, 53, 30, "Idx", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bj_emlrtBCI = { -1, -1, 53, 33, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo cj_emlrtBCI = { -1, -1, 53, 13, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo fc_emlrtECI = { -1, 53, 5, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo dj_emlrtBCI = { -1, -1, 57, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo gc_emlrtECI = { 2, 57, 13, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo ej_emlrtBCI = { -1, -1, 64, 17, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo fj_emlrtBCI = { -1, -1, 67, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo gj_emlrtBCI = { -1, -1, 65, 17, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hj_emlrtBCI = { -1, -1, 71, 44, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ij_emlrtBCI = { -1, -1, 80, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jj_emlrtBCI = { -1, -1, 81, 33, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kj_emlrtBCI = { -1, -1, 81, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lj_emlrtBCI = { -1, -1, 85, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mj_emlrtBCI = { -1, -1, 85, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo nj_emlrtBCI = { -1, -1, 86, 45, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo oj_emlrtBCI = { -1, -1, 86, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo pj_emlrtBCI = { -1, -1, 86, 30, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qj_emlrtBCI = { -1, -1, 99, 37, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo rj_emlrtBCI = { -1, -1, 101, 40, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo sj_emlrtBCI = { -1, -1, 106, 7, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo hc_emlrtECI = { -1, 106, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo tj_emlrtBCI = { -1, -1, 107, 7, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo ic_emlrtECI = { -1, 107, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo uj_emlrtBCI = { -1, -1, 94, 39, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo vj_emlrtBCI = { -1, -1, 94, 11, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo wj_emlrtBCI = { -1, -1, 94, 22, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo xj_emlrtBCI = { -1, -1, 98, 21, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo yj_emlrtBCI = { -1, -1, 101, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ak_emlrtBCI = { -1, -1, 101, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bk_emlrtBCI = { -1, -1, 99, 39, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ck_emlrtBCI = { -1, -1, 99, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo dk_emlrtBCI = { -1, -1, 99, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ek_emlrtBCI = { -1, -1, 62, 9, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo fk_emlrtBCI = { -1, -1, 67, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo gk_emlrtBCI = { -1, -1, 80, 27, "SPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hk_emlrtBCI = { -1, -1, 80, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ik_emlrtBCI = { -1, -1, 81, 21, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jk_emlrtBCI = { -1, -1, 86, 47, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kk_emlrtBCI = { -1, -1, 70, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lk_emlrtBCI = { -1, -1, 70, 28, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mk_emlrtBCI = { -1, -1, 71, 46, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo nk_emlrtBCI = { -1, -1, 71, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ok_emlrtBCI = { -1, -1, 71, 28, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo pk_emlrtBCI = { -1, -1, 73, 27, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qk_emlrtBCI = { -1, -1, 73, 29, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo rk_emlrtBCI = { -1, -1, 74, 27, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo sk_emlrtBCI = { -1, -1, 74, 29, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo tk_emlrtBCI = { -1, -1, 53, 24, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

/* Function Definitions */

/*
 * function[Pitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, Energy, VUVEnergy, Prm)
 */
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
  int32_T i54;
  int32_T loop_ub;
  int32_T n;
  emxArray_real_T *r41;
  emxArray_int32_T *r42;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *c_Pitch;
  int32_T i55;
  int32_T BestPitch;
  emxArray_real_T *b_BestPitch;
  int32_T i56;
  int32_T c_BestPitch[2];
  int32_T b_VUVEnergy[2];
  int32_T iv57[1];
  int32_T d_BestPitch;
  int32_T d_Pitch[1];
  int32_T i;
  int32_T iv58[2];
  int32_T j;
  int32_T iv59[2];
  real_T b_Merit;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Idx, 2, &qe_emlrtRTEI, true);
  emxInit_int32_T(sp, &iidx, 2, &qe_emlrtRTEI, true);
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
  /* 'refine:39' nlfer_thresh2  = Prm.nlfer_thresh2; */
  /* 'refine:40' Merit_pivot = Prm.merit_pivot; */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Merge pitch candidates and their merits from two types of the signal */
  /* 'refine:45' Pitch = cat(1,TPitch1, TPitch2); */
  st.site = &ho_emlrtRSI;
  cat(&st, TPitch1, TPitch2, Pitch);

  /* 'refine:46' Merit = cat(1,TMerit1, TMerit2); */
  st.site = &io_emlrtRSI;
  cat(&st, TMerit1, TMerit2, Merit);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  /* 'refine:50' [maxcands, numframes] = size(Pitch); */
  numframes = Pitch->size[1] - 1;
  maxcands = Pitch->size[0];

  /* 'refine:51' [Merit, Idx] = sort(Merit, 'descend'); */
  st.site = &jo_emlrtRSI;
  b_st.site = &ok_emlrtRSI;
  e_sort(&b_st, Merit, iidx);
  i54 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Idx, i54, (int32_T)sizeof(real_T),
                    &qe_emlrtRTEI);
  loop_ub = iidx->size[0] * iidx->size[1];
  for (i54 = 0; i54 < loop_ub; i54++) {
    Idx->data[i54] = iidx->data[i54];
  }

  emxFree_int32_T(&iidx);

  /* 'refine:52' for n=1:numframes */
  n = 0;
  emxInit_real_T1(sp, &r41, 1, &qe_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r42, 1, &qe_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_Pitch, 1, &qe_emlrtRTEI, true);
  while (n <= numframes) {
    covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 1);

    /* 'refine:53' Pitch(:,n) = Pitch(Idx(:,n),n); */
    loop_ub = Pitch->size[0];
    i54 = r42->size[0];
    r42->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r42, i54, (int32_T)sizeof(int32_T),
                      &qe_emlrtRTEI);
    for (i54 = 0; i54 < loop_ub; i54++) {
      r42->data[i54] = i54;
    }

    i54 = Pitch->size[1];
    i55 = n + 1;
    if (!((i55 >= 1) && (i55 <= i54))) {
      emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &cj_emlrtBCI, sp);
    }

    loop_ub = Idx->size[0];
    i54 = Idx->size[1];
    i55 = 1 + n;
    if (!((i55 >= 1) && (i55 <= i54))) {
      emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &aj_emlrtBCI, sp);
    }

    BestPitch = Pitch->size[0];
    i54 = Pitch->size[1];
    i56 = 1 + n;
    if (!((i56 >= 1) && (i56 <= i54))) {
      emlrtDynamicBoundsCheckR2012b(i56, 1, i54, &bj_emlrtBCI, sp);
    }

    i54 = r41->size[0];
    r41->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r41, i54, (int32_T)sizeof(real_T),
                      &qe_emlrtRTEI);
    for (i54 = 0; i54 < loop_ub; i54++) {
      d_BestPitch = (int32_T)Idx->data[i54 + Idx->size[0] * (i55 - 1)];
      if (!((d_BestPitch >= 1) && (d_BestPitch <= BestPitch))) {
        emlrtDynamicBoundsCheckR2012b(d_BestPitch, 1, BestPitch, &tk_emlrtBCI,
          sp);
      }

      r41->data[i54] = Pitch->data[(d_BestPitch + Pitch->size[0] * (i56 - 1)) -
        1];
    }

    iv57[0] = r42->size[0];
    loop_ub = Idx->size[0];
    i54 = b_Pitch->size[0];
    b_Pitch->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i54, (int32_T)sizeof
                      (real_T), &qe_emlrtRTEI);
    for (i54 = 0; i54 < loop_ub; i54++) {
      b_Pitch->data[i54] = Pitch->data[((int32_T)Idx->data[i54 + Idx->size[0] *
        n] + Pitch->size[0] * n) - 1];
    }

    d_Pitch[0] = b_Pitch->size[0];
    emlrtSubAssignSizeCheckR2012b(iv57, 1, d_Pitch, 1, &fc_emlrtECI, sp);
    loop_ub = r41->size[0];
    for (i54 = 0; i54 < loop_ub; i54++) {
      Pitch->data[r42->data[i54] + Pitch->size[0] * n] = r41->data[i54];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Pitch);
  emxFree_real_T(&r41);
  emxFree_real_T(&Idx);
  emxInit_real_T(sp, &c_Pitch, 2, &qe_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 2);

  /*  A best pitch track is generated from the best candidates */
  /* 'refine:57' BestPitch = Mymedfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  i54 = Pitch->size[0];
  if (!(1 <= i54)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i54, &dj_emlrtBCI, sp);
  }

  loop_ub = Pitch->size[1];
  i54 = c_Pitch->size[0] * c_Pitch->size[1];
  c_Pitch->size[0] = 1;
  c_Pitch->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)c_Pitch, i54, (int32_T)sizeof(real_T),
                    &qe_emlrtRTEI);
  for (i54 = 0; i54 < loop_ub; i54++) {
    c_Pitch->data[c_Pitch->size[0] * i54] = Pitch->data[Pitch->size[0] * i54];
  }

  emxInit_real_T(sp, &b_BestPitch, 2, &re_emlrtRTEI, true);
  st.site = &ko_emlrtRSI;
  Mymedfilt1(&st, c_Pitch, Prm_median_value, b_BestPitch);
  emxFree_real_T(&c_Pitch);
  for (i54 = 0; i54 < 2; i54++) {
    c_BestPitch[i54] = b_BestPitch->size[i54];
  }

  for (i54 = 0; i54 < 2; i54++) {
    b_VUVEnergy[i54] = VUVEnergy->size[i54];
  }

  if ((c_BestPitch[0] != b_VUVEnergy[0]) || (c_BestPitch[1] != b_VUVEnergy[1]))
  {
    emlrtSizeEqCheckNDR2012b(&c_BestPitch[0], &b_VUVEnergy[0], &gc_emlrtECI, sp);
  }

  i54 = b_BestPitch->size[0] * b_BestPitch->size[1];
  b_BestPitch->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)b_BestPitch, i54, (int32_T)sizeof
                    (real_T), &qe_emlrtRTEI);
  d_BestPitch = b_BestPitch->size[0];
  BestPitch = b_BestPitch->size[1];
  loop_ub = d_BestPitch * BestPitch;
  for (i54 = 0; i54 < loop_ub; i54++) {
    b_BestPitch->data[i54] *= (real_T)VUVEnergy->data[i54];
  }

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  /* 'refine:61' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 1, 1);

    /* 'refine:62' if (Energy(i)<=nlfer_thresh2) */
    i54 = Energy->size[1];
    if (!((i >= 1) && (i <= i54))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i54, &ek_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 19U, 0U, 0, Energy->data[i - 1] <=
                   Prm_nlfer_thresh2)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 3);

      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      /* 'refine:64' Pitch(:,i) = 0; */
      loop_ub = Pitch->size[0];
      BestPitch = Pitch->size[1];
      if (!((i >= 1) && (i <= BestPitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, BestPitch, &ej_emlrtBCI, sp);
      }

      for (i54 = 0; i54 < loop_ub; i54++) {
        Pitch->data[i54 + Pitch->size[0] * (i - 1)] = 0.0;
      }

      /* 'refine:65' Merit(:,i) = Merit_pivot; */
      loop_ub = Merit->size[0];
      d_BestPitch = Merit->size[1];
      if (!((i >= 1) && (i <= d_BestPitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, d_BestPitch, &gj_emlrtBCI, sp);
      }

      for (i54 = 0; i54 < loop_ub; i54++) {
        Merit->data[i54 + Merit->size[0] * (i - 1)] = Prm_merit_pivot;
      }
    } else {
      /* 'refine:66' else */
      /* 'refine:67' if (Pitch(1,i) > 0) */
      i54 = Pitch->size[0];
      if (!(1 <= i54)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i54, &fj_emlrtBCI, sp);
      }

      i54 = Pitch->size[1];
      if (!((i >= 1) && (i <= i54))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i54, &fk_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 19U, 0U, 1, Pitch->data[Pitch->
                     size[0] * (i - 1)] > 0.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 4);

        /*  already have the voiced candidate, Want to have at */
        /*  least one unvoiced candidate */
        /* 'refine:70' Pitch(maxcands,i) = 0.0; */
        i54 = Pitch->size[0];
        if (!((maxcands >= 1) && (maxcands <= i54))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i54, &kk_emlrtBCI, sp);
        }

        i54 = Pitch->size[1];
        if (!((i >= 1) && (i <= i54))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i54, &lk_emlrtBCI, sp);
        }

        Pitch->data[(maxcands + Pitch->size[0] * (i - 1)) - 1] = 0.0;

        /* 'refine:71' Merit(maxcands,i) = (1 - Merit(1,i)) ; */
        i54 = Merit->size[0];
        if (!(1 <= i54)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i54, &hj_emlrtBCI, sp);
        }

        i54 = Merit->size[1];
        if (!((i >= 1) && (i <= i54))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i54, &mk_emlrtBCI, sp);
        }

        i54 = Merit->size[0];
        if (!((maxcands >= 1) && (maxcands <= i54))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i54, &nk_emlrtBCI, sp);
        }

        i54 = Merit->size[1];
        if (!((i >= 1) && (i <= i54))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i54, &ok_emlrtBCI, sp);
        }

        Merit->data[(maxcands + Merit->size[0] * (i - 1)) - 1] = 1.0 -
          Merit->data[Merit->size[0] * (i - 1)];

        /* 'refine:72' for j = 2:maxcands-1 */
        j = 2;
        while (j - 2 <= maxcands - 3) {
          covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 2, 1);

          /* 'refine:73' if (Pitch(j,i) == 0) */
          i54 = Pitch->size[0];
          if (!((j >= 1) && (j <= i54))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i54, &pk_emlrtBCI, sp);
          }

          i54 = Pitch->size[1];
          if (!((i >= 1) && (i <= i54))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i54, &qk_emlrtBCI, sp);
          }

          if (covrtLogIf(&emlrtCoverageInstance, 19U, 0U, 2, Pitch->data[(j +
                Pitch->size[0] * (i - 1)) - 1] == 0.0)) {
            covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 5);

            /* 'refine:74' Merit(j,i) = 0.0; */
            i54 = Merit->size[0];
            if (!((j >= 1) && (j <= i54))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i54, &rk_emlrtBCI, sp);
            }

            i54 = Merit->size[1];
            if (!((i >= 1) && (i <= i54))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i54, &sk_emlrtBCI, sp);
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

        /* 'refine:77' else */
        /*  there was no voiced candidate from nccf fill in */
        /*  option for F0 from spectrogram */
        /* 'refine:80' Pitch(1,i)  = SPitch(i); */
        i54 = Pitch->size[0];
        if (!(1 <= i54)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i54, &ij_emlrtBCI, sp);
        }

        i54 = SPitch->size[1];
        if (!((i >= 1) && (i <= i54))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i54, &gk_emlrtBCI, sp);
        }

        i54 = Pitch->size[1];
        if (!((i >= 1) && (i <= i54))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i54, &hk_emlrtBCI, sp);
        }

        Pitch->data[Pitch->size[0] * (i - 1)] = SPitch->data[i - 1];

        /* 'refine:81' Merit(1,i) = min(1, Energy(i)/2); */
        i54 = Energy->size[1];
        i55 = (i - 1) + 1;
        if (!((i55 >= 1) && (i55 <= i54))) {
          emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &jj_emlrtBCI, sp);
        }

        i54 = Merit->size[0];
        if (!(1 <= i54)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i54, &kj_emlrtBCI, sp);
        }

        i54 = Merit->size[1];
        if (!((i >= 1) && (i <= i54))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i54, &ik_emlrtBCI, sp);
        }

        Merit->data[Merit->size[0] * (i - 1)] = muDoubleScalarMin(1.0,
          Energy->data[i - 1] / 2.0);

        /*  all other candidates will be unvoiced */
        /*  with low merit */
        /* 'refine:85' Pitch(2:maxcands,i) = 0.0; */
        if (2 > maxcands) {
          i54 = 0;
          i55 = 1;
        } else {
          i54 = Pitch->size[0];
          if (!(2 <= i54)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i54, &lj_emlrtBCI, sp);
          }

          i54 = 1;
          i55 = Pitch->size[0];
          if (!(maxcands <= i55)) {
            emlrtDynamicBoundsCheckR2012b(maxcands, 1, i55, &lj_emlrtBCI, sp);
          }

          i55 = maxcands + 1;
        }

        BestPitch = Pitch->size[1];
        if (!((i >= 1) && (i <= BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, BestPitch, &mj_emlrtBCI, sp);
        }

        loop_ub = (i55 - i54) - 1;
        for (i55 = 0; i55 < loop_ub; i55++) {
          Pitch->data[(i54 + i55) + Pitch->size[0] * (i - 1)] = 0.0;
        }

        /* 'refine:86' Merit(2:maxcands,i) = 1 - Merit(1,i); */
        if (2 > maxcands) {
          i54 = 0;
          i55 = 1;
        } else {
          i54 = Merit->size[0];
          if (!(2 <= i54)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i54, &oj_emlrtBCI, sp);
          }

          i54 = 1;
          i55 = Merit->size[0];
          if (!(maxcands <= i55)) {
            emlrtDynamicBoundsCheckR2012b(maxcands, 1, i55, &oj_emlrtBCI, sp);
          }

          i55 = maxcands + 1;
        }

        i56 = Merit->size[0];
        if (!(1 <= i56)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i56, &nj_emlrtBCI, sp);
        }

        d_BestPitch = Merit->size[1];
        if (!((i >= 1) && (i <= d_BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, d_BestPitch, &jk_emlrtBCI, sp);
        }

        b_Merit = Merit->data[Merit->size[0] * (i - 1)];
        d_BestPitch = Merit->size[1];
        if (!((i >= 1) && (i <= d_BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, d_BestPitch, &pj_emlrtBCI, sp);
        }

        loop_ub = (i55 - i54) - 1;
        for (i55 = 0; i55 < loop_ub; i55++) {
          Merit->data[(i54 + i55) + Merit->size[0] * (i - 1)] = 1.0 - b_Merit;
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
  /* 'refine:93' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    covrtLogFor(&emlrtCoverageInstance, 19U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 7);

    /* 'refine:94' Pitch(maxcands-1,i) = BestPitch(1,i); */
    i54 = b_BestPitch->size[1];
    if (!((i >= 1) && (i <= i54))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i54, &uj_emlrtBCI, sp);
    }

    i54 = Pitch->size[0];
    i55 = maxcands - 1;
    if (!((i55 >= 1) && (i55 <= i54))) {
      emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &vj_emlrtBCI, sp);
    }

    i54 = Pitch->size[1];
    if (!((i >= 1) && (i <= i54))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i54, &wj_emlrtBCI, sp);
    }

    Pitch->data[(i55 + Pitch->size[0] * (i - 1)) - 1] = b_BestPitch->
      data[b_BestPitch->size[0] * (i - 1)];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    /* 'refine:98' if (BestPitch(1,i) > 0) */
    i54 = b_BestPitch->size[1];
    if (!((i >= 1) && (i <= i54))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i54, &xj_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 19U, 0U, 3, b_BestPitch->
                   data[b_BestPitch->size[0] * (i - 1)] > 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 8);

      /*  voiced */
      /* 'refine:99' Merit(maxcands-1,i) = Merit(1,i); */
      i54 = Merit->size[0];
      if (!(1 <= i54)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i54, &qj_emlrtBCI, sp);
      }

      i54 = Merit->size[1];
      if (!((i >= 1) && (i <= i54))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i54, &bk_emlrtBCI, sp);
      }

      i54 = Merit->size[0];
      i55 = maxcands - 1;
      if (!((i55 >= 1) && (i55 <= i54))) {
        emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &ck_emlrtBCI, sp);
      }

      i54 = Merit->size[1];
      if (!((i >= 1) && (i <= i54))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i54, &dk_emlrtBCI, sp);
      }

      Merit->data[(i55 + Merit->size[0] * (i - 1)) - 1] = Merit->data
        [Merit->size[0] * (i - 1)];
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 19U, 9);

      /* 'refine:100' else */
      /*  unvoiced */
      /* 'refine:101' Merit(maxcands-1,i) = 1-min(1, Energy(i)/2); */
      i54 = Energy->size[1];
      i55 = (i - 1) + 1;
      if (!((i55 >= 1) && (i55 <= i54))) {
        emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &rj_emlrtBCI, sp);
      }

      i54 = Merit->size[0];
      i55 = maxcands - 1;
      if (!((i55 >= 1) && (i55 <= i54))) {
        emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &yj_emlrtBCI, sp);
      }

      i54 = Merit->size[1];
      if (!((i >= 1) && (i <= i54))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i54, &ak_emlrtBCI, sp);
      }

      Merit->data[(i55 + Merit->size[0] * (i - 1)) - 1] = 1.0 -
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
  /* 'refine:106' Pitch(maxcands-2,:) = SPitch; */
  i54 = Pitch->size[0];
  i55 = (int32_T)((real_T)maxcands - 2.0);
  if (!((i55 >= 1) && (i55 <= i54))) {
    emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &sj_emlrtBCI, sp);
  }

  loop_ub = Pitch->size[1];
  i54 = r42->size[0];
  r42->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r42, i54, (int32_T)sizeof(int32_T),
                    &qe_emlrtRTEI);
  for (i54 = 0; i54 < loop_ub; i54++) {
    r42->data[i54] = i54;
  }

  iv58[0] = 1;
  iv58[1] = r42->size[0];
  emlrtSubAssignSizeCheckR2012b(iv58, 2, *(int32_T (*)[2])SPitch->size, 2,
    &hc_emlrtECI, sp);
  loop_ub = SPitch->size[1];
  for (i54 = 0; i54 < loop_ub; i54++) {
    Pitch->data[(maxcands + Pitch->size[0] * r42->data[i54]) - 3] = SPitch->
      data[SPitch->size[0] * i54];
  }

  /* 'refine:107' Merit(maxcands-2,:) = Energy/5; */
  i54 = Merit->size[0];
  i55 = (int32_T)((real_T)maxcands - 2.0);
  if (!((i55 >= 1) && (i55 <= i54))) {
    emlrtDynamicBoundsCheckR2012b(i55, 1, i54, &tj_emlrtBCI, sp);
  }

  loop_ub = Merit->size[1];
  i54 = r42->size[0];
  r42->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r42, i54, (int32_T)sizeof(int32_T),
                    &qe_emlrtRTEI);
  for (i54 = 0; i54 < loop_ub; i54++) {
    r42->data[i54] = i54;
  }

  i54 = b_BestPitch->size[0] * b_BestPitch->size[1];
  b_BestPitch->size[0] = 1;
  b_BestPitch->size[1] = Energy->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_BestPitch, i54, (int32_T)sizeof
                    (real_T), &qe_emlrtRTEI);
  loop_ub = Energy->size[0] * Energy->size[1];
  for (i54 = 0; i54 < loop_ub; i54++) {
    b_BestPitch->data[i54] = Energy->data[i54] / 5.0;
  }

  iv59[0] = 1;
  iv59[1] = r42->size[0];
  emlrtSubAssignSizeCheckR2012b(iv59, 2, *(int32_T (*)[2])b_BestPitch->size, 2,
    &ic_emlrtECI, sp);
  loop_ub = b_BestPitch->size[1];
  for (i54 = 0; i54 < loop_ub; i54++) {
    Merit->data[(maxcands + Merit->size[0] * r42->data[i54]) - 3] =
      b_BestPitch->data[b_BestPitch->size[0] * i54];
  }

  emxFree_int32_T(&r42);
  emxFree_real_T(&b_BestPitch);

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (refine.c) */
