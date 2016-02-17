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
#include "rdivide.h"
#include "Mymedfilt1.h"
#include "sort1.h"
#include "cat.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo om_emlrtRSI = { 45, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo pm_emlrtRSI = { 46, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo qm_emlrtRSI = { 51, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo rm_emlrtRSI = { 57, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo fe_emlrtRTEI = { 1, 26, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo ge_emlrtRTEI = { 57, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtECInfo fc_emlrtECI = { -1, 107, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo bj_emlrtBCI = { -1, -1, 107, 7, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo gc_emlrtECI = { -1, 106, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo cj_emlrtBCI = { -1, -1, 106, 7, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo dj_emlrtBCI = { -1, -1, 101, 40, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ej_emlrtBCI = { -1, -1, 99, 37, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo fj_emlrtBCI = { -1, -1, 86, 30, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo gj_emlrtBCI = { -1, -1, 86, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hj_emlrtBCI = { -1, -1, 86, 45, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ij_emlrtBCI = { -1, -1, 85, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jj_emlrtBCI = { -1, -1, 85, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kj_emlrtBCI = { -1, -1, 81, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lj_emlrtBCI = { -1, -1, 81, 33, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mj_emlrtBCI = { -1, -1, 80, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo nj_emlrtBCI = { -1, -1, 71, 44, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo oj_emlrtBCI = { -1, -1, 65, 17, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo pj_emlrtBCI = { -1, -1, 67, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qj_emlrtBCI = { -1, -1, 64, 17, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo hc_emlrtECI = { 2, 57, 13, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo rj_emlrtBCI = { -1, -1, 57, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo ic_emlrtECI = { -1, 53, 5, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo sj_emlrtBCI = { -1, -1, 53, 13, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo tj_emlrtBCI = { -1, -1, 53, 33, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo uj_emlrtBCI = { -1, -1, 53, 30, "Idx", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo vj_emlrtBCI = { -1, -1, 94, 39, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo wj_emlrtBCI = { -1, -1, 94, 11, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo xj_emlrtBCI = { -1, -1, 94, 22, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo yj_emlrtBCI = { -1, -1, 98, 21, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ak_emlrtBCI = { -1, -1, 101, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bk_emlrtBCI = { -1, -1, 101, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ck_emlrtBCI = { -1, -1, 99, 39, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo dk_emlrtBCI = { -1, -1, 99, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ek_emlrtBCI = { -1, -1, 99, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo fk_emlrtBCI = { -1, -1, 62, 9, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo gk_emlrtBCI = { -1, -1, 67, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hk_emlrtBCI = { -1, -1, 80, 27, "SPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ik_emlrtBCI = { -1, -1, 80, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jk_emlrtBCI = { -1, -1, 81, 21, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kk_emlrtBCI = { -1, -1, 86, 47, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lk_emlrtBCI = { -1, -1, 70, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mk_emlrtBCI = { -1, -1, 70, 28, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo nk_emlrtBCI = { -1, -1, 71, 46, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ok_emlrtBCI = { -1, -1, 71, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo pk_emlrtBCI = { -1, -1, 71, 28, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qk_emlrtBCI = { -1, -1, 73, 27, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo rk_emlrtBCI = { -1, -1, 73, 29, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo sk_emlrtBCI = { -1, -1, 74, 27, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo tk_emlrtBCI = { -1, -1, 74, 29, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo uk_emlrtBCI = { -1, -1, 53, 24, "Pitch", "refine",
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
  int32_T i48;
  int32_T loop_ub;
  int32_T n;
  emxArray_real_T *r45;
  emxArray_int32_T *r46;
  emxArray_real_T *b_Pitch;
  int32_T i49;
  int32_T BestPitch;
  int32_T i50;
  int32_T b_BestPitch;
  int32_T iv57[1];
  int32_T c_Pitch[1];
  emxArray_real_T *d_Pitch;
  emxArray_real_T *c_BestPitch;
  int32_T d_BestPitch[2];
  int32_T b_VUVEnergy[2];
  int32_T i;
  int32_T j;
  real_T b_Merit;
  int32_T iv58[2];
  int32_T iv59[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Idx, 2, &fe_emlrtRTEI, true);
  emxInit_int32_T(sp, &iidx, 2, &fe_emlrtRTEI, true);

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
  st.site = &om_emlrtRSI;
  cat(&st, TPitch1, TPitch2, Pitch);

  /* 'refine:46' Merit = cat(1,TMerit1, TMerit2); */
  st.site = &pm_emlrtRSI;
  cat(&st, TMerit1, TMerit2, Merit);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  /* 'refine:50' [maxcands, numframes] = size(Pitch); */
  numframes = Pitch->size[1] - 1;
  maxcands = Pitch->size[0];

  /* 'refine:51' [Merit, Idx] = sort(Merit, 'descend'); */
  st.site = &qm_emlrtRSI;
  b_st.site = &bj_emlrtRSI;
  e_sort(&b_st, Merit, iidx);
  i48 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Idx, i48, (int32_T)sizeof(real_T),
                    &fe_emlrtRTEI);
  loop_ub = iidx->size[0] * iidx->size[1];
  for (i48 = 0; i48 < loop_ub; i48++) {
    Idx->data[i48] = iidx->data[i48];
  }

  emxFree_int32_T(&iidx);

  /* 'refine:52' for n=1:numframes */
  n = 0;
  emxInit_real_T1(sp, &r45, 1, &fe_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r46, 1, &fe_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_Pitch, 1, &fe_emlrtRTEI, true);
  while (n <= numframes) {
    /* 'refine:53' Pitch(:,n) = Pitch(Idx(:,n),n); */
    loop_ub = Pitch->size[0];
    i48 = r46->size[0];
    r46->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r46, i48, (int32_T)sizeof(int32_T),
                      &fe_emlrtRTEI);
    for (i48 = 0; i48 < loop_ub; i48++) {
      r46->data[i48] = i48;
    }

    i48 = Pitch->size[1];
    i49 = n + 1;
    if (!((i49 >= 1) && (i49 <= i48))) {
      emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &sj_emlrtBCI, sp);
    }

    loop_ub = Idx->size[0];
    i48 = Idx->size[1];
    i49 = 1 + n;
    if (!((i49 >= 1) && (i49 <= i48))) {
      emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &uj_emlrtBCI, sp);
    }

    BestPitch = Pitch->size[0];
    i48 = Pitch->size[1];
    i50 = 1 + n;
    if (!((i50 >= 1) && (i50 <= i48))) {
      emlrtDynamicBoundsCheckR2012b(i50, 1, i48, &tj_emlrtBCI, sp);
    }

    i48 = r45->size[0];
    r45->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r45, i48, (int32_T)sizeof(real_T),
                      &fe_emlrtRTEI);
    for (i48 = 0; i48 < loop_ub; i48++) {
      b_BestPitch = (int32_T)Idx->data[i48 + Idx->size[0] * (i49 - 1)];
      if (!((b_BestPitch >= 1) && (b_BestPitch <= BestPitch))) {
        emlrtDynamicBoundsCheckR2012b(b_BestPitch, 1, BestPitch, &uk_emlrtBCI,
          sp);
      }

      r45->data[i48] = Pitch->data[(b_BestPitch + Pitch->size[0] * (i50 - 1)) -
        1];
    }

    iv57[0] = r46->size[0];
    loop_ub = Idx->size[0];
    i48 = b_Pitch->size[0];
    b_Pitch->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i48, (int32_T)sizeof
                      (real_T), &fe_emlrtRTEI);
    for (i48 = 0; i48 < loop_ub; i48++) {
      b_Pitch->data[i48] = Pitch->data[((int32_T)Idx->data[i48 + Idx->size[0] *
        n] + Pitch->size[0] * n) - 1];
    }

    c_Pitch[0] = b_Pitch->size[0];
    emlrtSubAssignSizeCheckR2012b(iv57, 1, c_Pitch, 1, &ic_emlrtECI, sp);
    loop_ub = r45->size[0];
    for (i48 = 0; i48 < loop_ub; i48++) {
      Pitch->data[r46->data[i48] + Pitch->size[0] * n] = r45->data[i48];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Pitch);
  emxFree_real_T(&r45);
  emxFree_real_T(&Idx);
  emxInit_real_T(sp, &d_Pitch, 2, &fe_emlrtRTEI, true);

  /*  A best pitch track is generated from the best candidates */
  /* 'refine:57' BestPitch = Mymedfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  i48 = Pitch->size[0];
  if (!(1 <= i48)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i48, &rj_emlrtBCI, sp);
  }

  loop_ub = Pitch->size[1];
  i48 = d_Pitch->size[0] * d_Pitch->size[1];
  d_Pitch->size[0] = 1;
  d_Pitch->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)d_Pitch, i48, (int32_T)sizeof(real_T),
                    &fe_emlrtRTEI);
  for (i48 = 0; i48 < loop_ub; i48++) {
    d_Pitch->data[d_Pitch->size[0] * i48] = Pitch->data[Pitch->size[0] * i48];
  }

  emxInit_real_T(sp, &c_BestPitch, 2, &ge_emlrtRTEI, true);
  st.site = &rm_emlrtRSI;
  Mymedfilt1(&st, d_Pitch, Prm_median_value, c_BestPitch);
  emxFree_real_T(&d_Pitch);
  for (i48 = 0; i48 < 2; i48++) {
    d_BestPitch[i48] = c_BestPitch->size[i48];
  }

  for (i48 = 0; i48 < 2; i48++) {
    b_VUVEnergy[i48] = VUVEnergy->size[i48];
  }

  if ((d_BestPitch[0] != b_VUVEnergy[0]) || (d_BestPitch[1] != b_VUVEnergy[1]))
  {
    emlrtSizeEqCheckNDR2012b(&d_BestPitch[0], &b_VUVEnergy[0], &hc_emlrtECI, sp);
  }

  i48 = c_BestPitch->size[0] * c_BestPitch->size[1];
  c_BestPitch->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)c_BestPitch, i48, (int32_T)sizeof
                    (real_T), &fe_emlrtRTEI);
  b_BestPitch = c_BestPitch->size[0];
  BestPitch = c_BestPitch->size[1];
  loop_ub = b_BestPitch * BestPitch;
  for (i48 = 0; i48 < loop_ub; i48++) {
    c_BestPitch->data[i48] *= (real_T)VUVEnergy->data[i48];
  }

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  /* 'refine:61' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'refine:62' if (Energy(i)<=nlfer_thresh2) */
    i48 = Energy->size[1];
    if (!((i >= 1) && (i <= i48))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i48, &fk_emlrtBCI, sp);
    }

    if (Energy->data[i - 1] <= Prm_nlfer_thresh2) {
      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      /* 'refine:64' Pitch(:,i) = 0; */
      loop_ub = Pitch->size[0];
      BestPitch = Pitch->size[1];
      if (!((i >= 1) && (i <= BestPitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, BestPitch, &qj_emlrtBCI, sp);
      }

      for (i48 = 0; i48 < loop_ub; i48++) {
        Pitch->data[i48 + Pitch->size[0] * (i - 1)] = 0.0;
      }

      /* 'refine:65' Merit(:,i) = Merit_pivot; */
      loop_ub = Merit->size[0];
      b_BestPitch = Merit->size[1];
      if (!((i >= 1) && (i <= b_BestPitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, b_BestPitch, &oj_emlrtBCI, sp);
      }

      for (i48 = 0; i48 < loop_ub; i48++) {
        Merit->data[i48 + Merit->size[0] * (i - 1)] = Prm_merit_pivot;
      }
    } else {
      /* 'refine:66' else */
      /* 'refine:67' if (Pitch(1,i) > 0) */
      i48 = Pitch->size[0];
      if (!(1 <= i48)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i48, &pj_emlrtBCI, sp);
      }

      i48 = Pitch->size[1];
      if (!((i >= 1) && (i <= i48))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i48, &gk_emlrtBCI, sp);
      }

      if (Pitch->data[Pitch->size[0] * (i - 1)] > 0.0) {
        /*  already have the voiced candidate, Want to have at */
        /*  least one unvoiced candidate */
        /* 'refine:70' Pitch(maxcands,i) = 0.0; */
        i48 = Pitch->size[0];
        if (!((maxcands >= 1) && (maxcands <= i48))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i48, &lk_emlrtBCI, sp);
        }

        i48 = Pitch->size[1];
        if (!((i >= 1) && (i <= i48))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i48, &mk_emlrtBCI, sp);
        }

        Pitch->data[(maxcands + Pitch->size[0] * (i - 1)) - 1] = 0.0;

        /* 'refine:71' Merit(maxcands,i) = (1 - Merit(1,i)) ; */
        i48 = Merit->size[0];
        if (!(1 <= i48)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i48, &nj_emlrtBCI, sp);
        }

        i48 = Merit->size[1];
        if (!((i >= 1) && (i <= i48))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i48, &nk_emlrtBCI, sp);
        }

        i48 = Merit->size[0];
        if (!((maxcands >= 1) && (maxcands <= i48))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i48, &ok_emlrtBCI, sp);
        }

        i48 = Merit->size[1];
        if (!((i >= 1) && (i <= i48))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i48, &pk_emlrtBCI, sp);
        }

        Merit->data[(maxcands + Merit->size[0] * (i - 1)) - 1] = 1.0 -
          Merit->data[Merit->size[0] * (i - 1)];

        /* 'refine:72' for j = 2:maxcands-1 */
        j = 2;
        while (j - 2 <= maxcands - 3) {
          /* 'refine:73' if (Pitch(j,i) == 0) */
          i48 = Pitch->size[0];
          if (!((j >= 1) && (j <= i48))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i48, &qk_emlrtBCI, sp);
          }

          i48 = Pitch->size[1];
          if (!((i >= 1) && (i <= i48))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i48, &rk_emlrtBCI, sp);
          }

          if (Pitch->data[(j + Pitch->size[0] * (i - 1)) - 1] == 0.0) {
            /* 'refine:74' Merit(j,i) = 0.0; */
            i48 = Merit->size[0];
            if (!((j >= 1) && (j <= i48))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i48, &sk_emlrtBCI, sp);
            }

            i48 = Merit->size[1];
            if (!((i >= 1) && (i <= i48))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i48, &tk_emlrtBCI, sp);
            }

            Merit->data[(j + Merit->size[0] * (i - 1)) - 1] = 0.0;
          }

          j++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }
      } else {
        /* 'refine:77' else */
        /*  there was no voiced candidate from nccf fill in */
        /*  option for F0 from spectrogram */
        /* 'refine:80' Pitch(1,i)  = SPitch(i); */
        i48 = Pitch->size[0];
        if (!(1 <= i48)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i48, &mj_emlrtBCI, sp);
        }

        i48 = SPitch->size[1];
        if (!((i >= 1) && (i <= i48))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i48, &hk_emlrtBCI, sp);
        }

        i48 = Pitch->size[1];
        if (!((i >= 1) && (i <= i48))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i48, &ik_emlrtBCI, sp);
        }

        Pitch->data[Pitch->size[0] * (i - 1)] = SPitch->data[i - 1];

        /* 'refine:81' Merit(1,i) = min(1, Energy(i)/2); */
        i48 = Energy->size[1];
        i49 = (i - 1) + 1;
        if (!((i49 >= 1) && (i49 <= i48))) {
          emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &lj_emlrtBCI, sp);
        }

        i48 = Merit->size[0];
        if (!(1 <= i48)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i48, &kj_emlrtBCI, sp);
        }

        i48 = Merit->size[1];
        if (!((i >= 1) && (i <= i48))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i48, &jk_emlrtBCI, sp);
        }

        Merit->data[Merit->size[0] * (i - 1)] = muDoubleScalarMin(1.0,
          Energy->data[i - 1] / 2.0);

        /*  all other candidates will be unvoiced */
        /*  with low merit */
        /* 'refine:85' Pitch(2:maxcands,i) = 0.0; */
        if (2 > maxcands) {
          i48 = 0;
          i49 = 0;
        } else {
          i48 = Pitch->size[0];
          if (!(2 <= i48)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i48, &jj_emlrtBCI, sp);
          }

          i48 = 1;
          i49 = Pitch->size[0];
          if (!(maxcands <= i49)) {
            emlrtDynamicBoundsCheckR2012b(maxcands, 1, i49, &jj_emlrtBCI, sp);
          }

          i49 = maxcands;
        }

        BestPitch = Pitch->size[1];
        if (!((i >= 1) && (i <= BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, BestPitch, &ij_emlrtBCI, sp);
        }

        loop_ub = i49 - i48;
        for (i49 = 0; i49 < loop_ub; i49++) {
          Pitch->data[(i48 + i49) + Pitch->size[0] * (i - 1)] = 0.0;
        }

        /* 'refine:86' Merit(2:maxcands,i) = 1 - Merit(1,i); */
        if (2 > maxcands) {
          i48 = 0;
          i49 = 0;
        } else {
          i48 = Merit->size[0];
          if (!(2 <= i48)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i48, &gj_emlrtBCI, sp);
          }

          i48 = 1;
          i49 = Merit->size[0];
          if (!(maxcands <= i49)) {
            emlrtDynamicBoundsCheckR2012b(maxcands, 1, i49, &gj_emlrtBCI, sp);
          }

          i49 = maxcands;
        }

        i50 = Merit->size[0];
        if (!(1 <= i50)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i50, &hj_emlrtBCI, sp);
        }

        b_BestPitch = Merit->size[1];
        if (!((i >= 1) && (i <= b_BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, b_BestPitch, &kk_emlrtBCI, sp);
        }

        b_Merit = Merit->data[Merit->size[0] * (i - 1)];
        b_BestPitch = Merit->size[1];
        if (!((i >= 1) && (i <= b_BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, b_BestPitch, &fj_emlrtBCI, sp);
        }

        loop_ub = i49 - i48;
        for (i49 = 0; i49 < loop_ub; i49++) {
          Merit->data[(i48 + i49) + Merit->size[0] * (i - 1)] = 1.0 - b_Merit;
        }
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  /* 'refine:93' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'refine:94' Pitch(maxcands-1,i) = BestPitch(1,i); */
    i48 = c_BestPitch->size[1];
    if (!((i >= 1) && (i <= i48))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i48, &vj_emlrtBCI, sp);
    }

    i48 = Pitch->size[0];
    i49 = maxcands - 1;
    if (!((i49 >= 1) && (i49 <= i48))) {
      emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &wj_emlrtBCI, sp);
    }

    i48 = Pitch->size[1];
    if (!((i >= 1) && (i <= i48))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i48, &xj_emlrtBCI, sp);
    }

    Pitch->data[(i49 + Pitch->size[0] * (i - 1)) - 1] = c_BestPitch->
      data[c_BestPitch->size[0] * (i - 1)];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    /* 'refine:98' if (BestPitch(1,i) > 0) */
    i48 = c_BestPitch->size[1];
    if (!((i >= 1) && (i <= i48))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i48, &yj_emlrtBCI, sp);
    }

    if (c_BestPitch->data[c_BestPitch->size[0] * (i - 1)] > 0.0) {
      /*  voiced */
      /* 'refine:99' Merit(maxcands-1,i) = Merit(1,i); */
      i48 = Merit->size[0];
      if (!(1 <= i48)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i48, &ej_emlrtBCI, sp);
      }

      i48 = Merit->size[1];
      if (!((i >= 1) && (i <= i48))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i48, &ck_emlrtBCI, sp);
      }

      i48 = Merit->size[0];
      i49 = maxcands - 1;
      if (!((i49 >= 1) && (i49 <= i48))) {
        emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &dk_emlrtBCI, sp);
      }

      i48 = Merit->size[1];
      if (!((i >= 1) && (i <= i48))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i48, &ek_emlrtBCI, sp);
      }

      Merit->data[(i49 + Merit->size[0] * (i - 1)) - 1] = Merit->data
        [Merit->size[0] * (i - 1)];
    } else {
      /* 'refine:100' else */
      /*  unvoiced */
      /* 'refine:101' Merit(maxcands-1,i) = 1-min(1, Energy(i)/2); */
      i48 = Energy->size[1];
      i49 = (i - 1) + 1;
      if (!((i49 >= 1) && (i49 <= i48))) {
        emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &dj_emlrtBCI, sp);
      }

      i48 = Merit->size[0];
      i49 = maxcands - 1;
      if (!((i49 >= 1) && (i49 <= i48))) {
        emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &ak_emlrtBCI, sp);
      }

      i48 = Merit->size[1];
      if (!((i >= 1) && (i <= i48))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i48, &bk_emlrtBCI, sp);
      }

      Merit->data[(i49 + Merit->size[0] * (i - 1)) - 1] = 1.0 -
        muDoubleScalarMin(1.0, Energy->data[i - 1] / 2.0);
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*   Copy over the SPitch array */
  /* 'refine:106' Pitch(maxcands-2,:) = SPitch; */
  i48 = Pitch->size[0];
  i49 = (int32_T)((real_T)maxcands - 2.0);
  if (!((i49 >= 1) && (i49 <= i48))) {
    emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &cj_emlrtBCI, sp);
  }

  loop_ub = Pitch->size[1];
  i48 = r46->size[0];
  r46->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r46, i48, (int32_T)sizeof(int32_T),
                    &fe_emlrtRTEI);
  for (i48 = 0; i48 < loop_ub; i48++) {
    r46->data[i48] = i48;
  }

  iv58[0] = 1;
  iv58[1] = r46->size[0];
  emlrtSubAssignSizeCheckR2012b(iv58, 2, *(int32_T (*)[2])SPitch->size, 2,
    &gc_emlrtECI, sp);
  loop_ub = SPitch->size[1];
  for (i48 = 0; i48 < loop_ub; i48++) {
    Pitch->data[(maxcands + Pitch->size[0] * r46->data[i48]) - 3] = SPitch->
      data[SPitch->size[0] * i48];
  }

  /* 'refine:107' Merit(maxcands-2,:) = Energy/5; */
  i48 = Merit->size[0];
  i49 = (int32_T)((real_T)maxcands - 2.0);
  if (!((i49 >= 1) && (i49 <= i48))) {
    emlrtDynamicBoundsCheckR2012b(i49, 1, i48, &bj_emlrtBCI, sp);
  }

  loop_ub = Merit->size[1];
  i48 = r46->size[0];
  r46->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r46, i48, (int32_T)sizeof(int32_T),
                    &fe_emlrtRTEI);
  for (i48 = 0; i48 < loop_ub; i48++) {
    r46->data[i48] = i48;
  }

  c_rdivide(sp, Energy, 5.0, c_BestPitch);
  iv59[0] = 1;
  iv59[1] = r46->size[0];
  emlrtSubAssignSizeCheckR2012b(iv59, 2, *(int32_T (*)[2])c_BestPitch->size, 2,
    &fc_emlrtECI, sp);
  loop_ub = c_BestPitch->size[1];
  for (i48 = 0; i48 < loop_ub; i48++) {
    Merit->data[(maxcands + Merit->size[0] * r46->data[i48]) - 3] =
      c_BestPitch->data[c_BestPitch->size[0] * i48];
  }

  emxFree_int32_T(&r46);
  emxFree_real_T(&c_BestPitch);

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (refine.c) */
