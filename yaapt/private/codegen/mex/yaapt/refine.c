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
#include "median.h"
#include "sort1.h"
#include "cat.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo bl_emlrtRSI = { 45, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo cl_emlrtRSI = { 46, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo dl_emlrtRSI = { 51, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo el_emlrtRSI = { 57, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo bd_emlrtRTEI = { 1, 26, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo cd_emlrtRTEI = { 57, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtECInfo rb_emlrtECI = { -1, 107, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 107, 7, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo sb_emlrtECI = { -1, 106, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 106, 7, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 101, 40, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 99, 37, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 86, 30, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 86, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 86, 45, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 85, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 85, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 81, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 81, 33, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 80, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 71, 44, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 65, 17, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 67, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 64, 17, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo tb_emlrtECI = { 2, 57, 13, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 57, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo ub_emlrtECI = { -1, 53, 5, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 53, 13, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 53, 33, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 53, 30, "Idx", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 94, 39, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 94, 11, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 94, 22, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 98, 21, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 101, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 101, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 99, 39, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 99, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 99, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 62, 9, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 67, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 80, 27, "SPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 80, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 81, 21, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 86, 47, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 70, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 70, 28, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 71, 46, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 71, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 71, 28, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 73, 27, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 73, 29, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 74, 27, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 74, 29, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 53, 24, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

/* Function Definitions */

/*
 * function[Pitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, Energy, VUVEnergy, Prm)
 */
void refine(const emlrtStack *sp, const emxArray_real_T *TPitch1, const
            emxArray_real_T *TMerit1, const emxArray_real_T *TPitch2, const
            emxArray_real_T *TMerit2, const emxArray_real_T *SPitch, const
            emxArray_real_T *Energy, const emxArray_boolean_T *VUVEnergy,
            emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  emxArray_real_T *Idx;
  emxArray_int32_T *iidx;
  int32_T numframes;
  int32_T maxcands;
  int32_T i38;
  int32_T loop_ub;
  int32_T n;
  emxArray_real_T *r25;
  emxArray_int32_T *r26;
  emxArray_real_T *b_Pitch;
  int32_T i39;
  int32_T c_Pitch;
  int32_T b_loop_ub;
  int32_T BestPitch;
  int32_T iv38[1];
  int32_T d_Pitch[1];
  emxArray_real_T *e_Pitch;
  emxArray_real_T *s;
  emxArray_real_T *m;
  int32_T i;
  emxArray_real_T *b_BestPitch;
  real_T b_Merit;
  real_T b_s;
  int32_T iv39[2];
  emxArray_real_T *c_BestPitch;
  int32_T d_BestPitch[2];
  int32_T b_VUVEnergy[2];
  int32_T j;
  int32_T iv40[2];
  int32_T iv41[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Idx, 2, &bd_emlrtRTEI, true);
  emxInit_int32_T1(sp, &iidx, 2, &bd_emlrtRTEI, true);

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
  st.site = &bl_emlrtRSI;
  cat(&st, TPitch1, TPitch2, Pitch);

  /* 'refine:46' Merit = cat(1,TMerit1, TMerit2); */
  st.site = &cl_emlrtRSI;
  cat(&st, TMerit1, TMerit2, Merit);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  /* 'refine:50' [maxcands, numframes] = size(Pitch); */
  numframes = Pitch->size[1] - 1;
  maxcands = Pitch->size[0];

  /* 'refine:51' [Merit, Idx] = sort(Merit, 'descend'); */
  st.site = &dl_emlrtRSI;
  b_st.site = &rg_emlrtRSI;
  e_sort(&b_st, Merit, iidx);
  i38 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Idx, i38, (int32_T)sizeof(real_T),
                    &bd_emlrtRTEI);
  loop_ub = iidx->size[0] * iidx->size[1];
  for (i38 = 0; i38 < loop_ub; i38++) {
    Idx->data[i38] = iidx->data[i38];
  }

  emxFree_int32_T(&iidx);

  /* 'refine:52' for n=1:numframes */
  n = 0;
  emxInit_real_T1(sp, &r25, 1, &bd_emlrtRTEI, true);
  emxInit_int32_T(sp, &r26, 1, &bd_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_Pitch, 1, &bd_emlrtRTEI, true);
  while (n <= numframes) {
    /* 'refine:53' Pitch(:,n) = Pitch(Idx(:,n),n); */
    loop_ub = Pitch->size[0];
    i38 = r26->size[0];
    r26->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r26, i38, (int32_T)sizeof(int32_T),
                      &bd_emlrtRTEI);
    for (i38 = 0; i38 < loop_ub; i38++) {
      r26->data[i38] = i38;
    }

    i38 = Pitch->size[1];
    i39 = n + 1;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &ag_emlrtBCI, sp);
    }

    loop_ub = Idx->size[0];
    i38 = Idx->size[1];
    i39 = 1 + n;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &cg_emlrtBCI, sp);
    }

    c_Pitch = Pitch->size[0];
    i38 = Pitch->size[1];
    b_loop_ub = 1 + n;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i38))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i38, &bg_emlrtBCI, sp);
    }

    i38 = r25->size[0];
    r25->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r25, i38, (int32_T)sizeof(real_T),
                      &bd_emlrtRTEI);
    for (i38 = 0; i38 < loop_ub; i38++) {
      BestPitch = (int32_T)Idx->data[i38 + Idx->size[0] * (i39 - 1)];
      if (!((BestPitch >= 1) && (BestPitch <= c_Pitch))) {
        emlrtDynamicBoundsCheckR2012b(BestPitch, 1, c_Pitch, &ch_emlrtBCI, sp);
      }

      r25->data[i38] = Pitch->data[(BestPitch + Pitch->size[0] * (b_loop_ub - 1))
        - 1];
    }

    iv38[0] = r26->size[0];
    loop_ub = Idx->size[0];
    i38 = b_Pitch->size[0];
    b_Pitch->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i38, (int32_T)sizeof
                      (real_T), &bd_emlrtRTEI);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_Pitch->data[i38] = Pitch->data[((int32_T)Idx->data[i38 + Idx->size[0] *
        n] + Pitch->size[0] * n) - 1];
    }

    d_Pitch[0] = b_Pitch->size[0];
    emlrtSubAssignSizeCheckR2012b(iv38, 1, d_Pitch, 1, &ub_emlrtECI, sp);
    loop_ub = r25->size[0];
    for (i38 = 0; i38 < loop_ub; i38++) {
      Pitch->data[r26->data[i38] + Pitch->size[0] * n] = r25->data[i38];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_Pitch);
  emxFree_real_T(&r25);
  emxFree_real_T(&Idx);
  emxInit_real_T(sp, &e_Pitch, 2, &bd_emlrtRTEI, true);

  /*  A best pitch track is generated from the best candidates */
  /* 'refine:57' BestPitch = Mymedfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  st.site = &el_emlrtRSI;
  i38 = Pitch->size[0];
  if (!(1 <= i38)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i38, &yf_emlrtBCI, &st);
  }

  /* MEDFILT1       One-dimensional median filter */
  /*  */
  /*        y = MEDFILT(x) */
  /*        y = MEDFILT(x, w) */
  /*  */
  /*        median filter the signal with window of width W (default is 5). */
  /*  Copyright (C) 1995-2009, by Peter I. Corke */
  /*  */
  /*  This file is part of The Machine Vision Toolbox for Matlab (MVTB). */
  /*   */
  /*  MVTB is free software: you can redistribute it and/or modify */
  /*  it under the terms of the GNU Lesser General Public License as published by */
  /*  the Free Software Foundation, either version 3 of the License, or */
  /*  (at your option) any later version. */
  /*   */
  /*  MVTB is distributed in the hope that it will be useful, */
  /*  but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*  GNU Lesser General Public License for more details. */
  /*   */
  /*  You should have received a copy of the GNU Leser General Public License */
  /*  along with MVTB.  If not, see <http://www.gnu.org/licenses/>. */
  /* 'Mymedfilt1:25' if nargin == 1 */
  /* 'Mymedfilt1:29' s = s(:)'; */
  loop_ub = Pitch->size[1];
  b_loop_ub = Pitch->size[1];
  i38 = e_Pitch->size[0] * e_Pitch->size[1];
  e_Pitch->size[0] = 1;
  e_Pitch->size[1] = b_loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)e_Pitch, i38, (int32_T)sizeof
                    (real_T), &bd_emlrtRTEI);
  for (i38 = 0; i38 < b_loop_ub; i38++) {
    e_Pitch->data[e_Pitch->size[0] * i38] = Pitch->data[Pitch->size[0] * i38];
  }

  emxInit_real_T(&st, &s, 2, &bd_emlrtRTEI, true);
  i38 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)s, i38, (int32_T)sizeof(real_T),
                    &bd_emlrtRTEI);
  for (i38 = 0; i38 < loop_ub; i38++) {
    s->data[s->size[0] * i38] = e_Pitch->data[i38];
  }

  emxFree_real_T(&e_Pitch);
  emxInit_real_T(&st, &m, 2, &wb_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i38 = m->size[0] * m->size[1];
  m->size[0] = 7;
  m->size[1] = (int32_T)(((real_T)s->size[1] + 7.0) - 1.0);
  emxEnsureCapacity(&st, (emxArray__common *)m, i38, (int32_T)sizeof(real_T),
                    &bd_emlrtRTEI);
  loop_ub = 7 * (int32_T)(((real_T)s->size[1] + 7.0) - 1.0);
  for (i38 = 0; i38 < loop_ub; i38++) {
    m->data[i38] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i38 = s->size[1];
  if (!(1 <= i38)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i38, &id_emlrtBCI, &st);
  }

  /* 'Mymedfilt1:35' sl = s(n); */
  i38 = s->size[1];
  i39 = s->size[1];
  if (!((i39 >= 1) && (i39 <= i38))) {
    emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &jd_emlrtBCI, &st);
  }

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  i = 0;
  emxInit_real_T(&st, &b_BestPitch, 2, &cd_emlrtRTEI, true);
  while (i < 7) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = m->size[1];
    i38 = r26->size[0];
    r26->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)r26, i38, (int32_T)sizeof(int32_T),
                      &bd_emlrtRTEI);
    for (i38 = 0; i38 < loop_ub; i38++) {
      r26->data[i38] = i38;
    }

    b_Merit = s->data[0];
    b_s = s->data[s->size[1] - 1];
    BestPitch = 6 - i;
    i38 = b_BestPitch->size[0] * b_BestPitch->size[1];
    b_BestPitch->size[0] = 1;
    b_BestPitch->size[1] = (i + s->size[1]) + BestPitch;
    emxEnsureCapacity(&st, (emxArray__common *)b_BestPitch, i38, (int32_T)sizeof
                      (real_T), &bd_emlrtRTEI);
    for (i38 = 0; i38 < i; i38++) {
      b_BestPitch->data[b_BestPitch->size[0] * i38] = b_Merit;
    }

    loop_ub = s->size[1];
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_BestPitch->data[b_BestPitch->size[0] * (i38 + i)] = s->data[s->size[0] *
        i38];
    }

    for (i38 = 0; i38 < BestPitch; i38++) {
      b_BestPitch->data[b_BestPitch->size[0] * ((i38 + i) + s->size[1])] = b_s;
    }

    iv39[0] = 1;
    iv39[1] = r26->size[0];
    emlrtSubAssignSizeCheckR2012b(iv39, 2, *(int32_T (*)[2])b_BestPitch->size, 2,
      &fb_emlrtECI, &st);
    loop_ub = b_BestPitch->size[1];
    for (i38 = 0; i38 < loop_ub; i38++) {
      m->data[i + m->size[0] * r26->data[i38]] = b_BestPitch->data
        [b_BestPitch->size[0] * i38];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* 'Mymedfilt1:40' m = median(m); */
  b_st.site = &rh_emlrtRSI;
  b_median(&b_st, m, b_BestPitch);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  emxFree_real_T(&m);
  if (4U > 3U + s->size[1]) {
    i38 = 0;
    b_loop_ub = 0;
  } else {
    i38 = b_BestPitch->size[1];
    if (!(4 <= i38)) {
      emlrtDynamicBoundsCheckR2012b(4, 1, i38, &kd_emlrtBCI, &st);
    }

    i38 = 3;
    i39 = b_BestPitch->size[1];
    b_loop_ub = (int32_T)(3U + s->size[1]);
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i39))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i39, &kd_emlrtBCI, &st);
    }
  }

  emxFree_real_T(&s);
  emxInit_real_T(&st, &c_BestPitch, 2, &bd_emlrtRTEI, true);
  i39 = c_BestPitch->size[0] * c_BestPitch->size[1];
  c_BestPitch->size[0] = 1;
  c_BestPitch->size[1] = b_loop_ub - i38;
  emxEnsureCapacity(&st, (emxArray__common *)c_BestPitch, i39, (int32_T)sizeof
                    (real_T), &bd_emlrtRTEI);
  loop_ub = b_loop_ub - i38;
  for (i39 = 0; i39 < loop_ub; i39++) {
    c_BestPitch->data[c_BestPitch->size[0] * i39] = b_BestPitch->data[i38 + i39];
  }

  i38 = b_BestPitch->size[0] * b_BestPitch->size[1];
  b_BestPitch->size[0] = 1;
  b_BestPitch->size[1] = c_BestPitch->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_BestPitch, i38, (int32_T)sizeof
                    (real_T), &bd_emlrtRTEI);
  loop_ub = c_BestPitch->size[1];
  for (i38 = 0; i38 < loop_ub; i38++) {
    b_BestPitch->data[b_BestPitch->size[0] * i38] = c_BestPitch->
      data[c_BestPitch->size[0] * i38];
  }

  emxFree_real_T(&c_BestPitch);
  for (i38 = 0; i38 < 2; i38++) {
    d_BestPitch[i38] = b_BestPitch->size[i38];
  }

  for (i38 = 0; i38 < 2; i38++) {
    b_VUVEnergy[i38] = VUVEnergy->size[i38];
  }

  if ((d_BestPitch[0] != b_VUVEnergy[0]) || (d_BestPitch[1] != b_VUVEnergy[1]))
  {
    emlrtSizeEqCheckNDR2012b(&d_BestPitch[0], &b_VUVEnergy[0], &tb_emlrtECI, sp);
  }

  i38 = b_BestPitch->size[0] * b_BestPitch->size[1];
  b_BestPitch->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)b_BestPitch, i38, (int32_T)sizeof
                    (real_T), &bd_emlrtRTEI);
  b_loop_ub = b_BestPitch->size[0];
  BestPitch = b_BestPitch->size[1];
  loop_ub = b_loop_ub * BestPitch;
  for (i38 = 0; i38 < loop_ub; i38++) {
    b_BestPitch->data[i38] *= (real_T)VUVEnergy->data[i38];
  }

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  /* 'refine:61' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'refine:62' if (Energy(i)<=nlfer_thresh2) */
    i38 = Energy->size[1];
    if (!((i >= 1) && (i <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i38, &mg_emlrtBCI, sp);
    }

    if (Energy->data[i - 1] <= 0.1) {
      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      /* 'refine:64' Pitch(:,i) = 0; */
      loop_ub = Pitch->size[0];
      c_Pitch = Pitch->size[1];
      if (!((i >= 1) && (i <= c_Pitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, c_Pitch, &xf_emlrtBCI, sp);
      }

      for (i38 = 0; i38 < loop_ub; i38++) {
        Pitch->data[i38 + Pitch->size[0] * (i - 1)] = 0.0;
      }

      /* 'refine:65' Merit(:,i) = Merit_pivot; */
      loop_ub = Merit->size[0];
      BestPitch = Merit->size[1];
      if (!((i >= 1) && (i <= BestPitch))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, BestPitch, &vf_emlrtBCI, sp);
      }

      for (i38 = 0; i38 < loop_ub; i38++) {
        Merit->data[i38 + Merit->size[0] * (i - 1)] = 0.99;
      }
    } else {
      /* 'refine:66' else */
      /* 'refine:67' if (Pitch(1,i) > 0) */
      i38 = Pitch->size[0];
      if (!(1 <= i38)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i38, &wf_emlrtBCI, sp);
      }

      i38 = Pitch->size[1];
      if (!((i >= 1) && (i <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i38, &ng_emlrtBCI, sp);
      }

      if (Pitch->data[Pitch->size[0] * (i - 1)] > 0.0) {
        /*  already have the voiced candidate, Want to have at */
        /*  least one unvoiced candidate */
        /* 'refine:70' Pitch(maxcands,i) = 0.0; */
        i38 = Pitch->size[0];
        if (!((maxcands >= 1) && (maxcands <= i38))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i38, &sg_emlrtBCI, sp);
        }

        i38 = Pitch->size[1];
        if (!((i >= 1) && (i <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i38, &tg_emlrtBCI, sp);
        }

        Pitch->data[(maxcands + Pitch->size[0] * (i - 1)) - 1] = 0.0;

        /* 'refine:71' Merit(maxcands,i) = (1 - Merit(1,i)) ; */
        i38 = Merit->size[0];
        if (!(1 <= i38)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i38, &uf_emlrtBCI, sp);
        }

        i38 = Merit->size[1];
        if (!((i >= 1) && (i <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i38, &ug_emlrtBCI, sp);
        }

        i38 = Merit->size[0];
        if (!((maxcands >= 1) && (maxcands <= i38))) {
          emlrtDynamicBoundsCheckR2012b(maxcands, 1, i38, &vg_emlrtBCI, sp);
        }

        i38 = Merit->size[1];
        if (!((i >= 1) && (i <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i38, &wg_emlrtBCI, sp);
        }

        Merit->data[(maxcands + Merit->size[0] * (i - 1)) - 1] = 1.0 -
          Merit->data[Merit->size[0] * (i - 1)];

        /* 'refine:72' for j = 2:maxcands-1 */
        j = 2;
        while (j - 2 <= maxcands - 3) {
          /* 'refine:73' if (Pitch(j,i) == 0) */
          i38 = Pitch->size[0];
          if (!((j >= 1) && (j <= i38))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i38, &xg_emlrtBCI, sp);
          }

          i38 = Pitch->size[1];
          if (!((i >= 1) && (i <= i38))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i38, &yg_emlrtBCI, sp);
          }

          if (Pitch->data[(j + Pitch->size[0] * (i - 1)) - 1] == 0.0) {
            /* 'refine:74' Merit(j,i) = 0.0; */
            i38 = Merit->size[0];
            if (!((j >= 1) && (j <= i38))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i38, &ah_emlrtBCI, sp);
            }

            i38 = Merit->size[1];
            if (!((i >= 1) && (i <= i38))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i38, &bh_emlrtBCI, sp);
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
        i38 = Pitch->size[0];
        if (!(1 <= i38)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i38, &tf_emlrtBCI, sp);
        }

        i38 = SPitch->size[1];
        if (!((i >= 1) && (i <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i38, &og_emlrtBCI, sp);
        }

        i38 = Pitch->size[1];
        if (!((i >= 1) && (i <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i38, &pg_emlrtBCI, sp);
        }

        Pitch->data[Pitch->size[0] * (i - 1)] = SPitch->data[i - 1];

        /* 'refine:81' Merit(1,i) = min(1, Energy(i)/2); */
        i38 = Energy->size[1];
        i39 = (i - 1) + 1;
        if (!((i39 >= 1) && (i39 <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &sf_emlrtBCI, sp);
        }

        i38 = Merit->size[0];
        if (!(1 <= i38)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i38, &rf_emlrtBCI, sp);
        }

        i38 = Merit->size[1];
        if (!((i >= 1) && (i <= i38))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i38, &qg_emlrtBCI, sp);
        }

        Merit->data[Merit->size[0] * (i - 1)] = muDoubleScalarMin(1.0,
          Energy->data[i - 1] / 2.0);

        /*  all other candidates will be unvoiced */
        /*  with low merit */
        /* 'refine:85' Pitch(2:maxcands,i) = 0.0; */
        if (2 > maxcands) {
          i38 = 0;
          i39 = 0;
        } else {
          i38 = Pitch->size[0];
          if (!(2 <= i38)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i38, &qf_emlrtBCI, sp);
          }

          i38 = 1;
          i39 = Pitch->size[0];
          if (!(maxcands <= i39)) {
            emlrtDynamicBoundsCheckR2012b(maxcands, 1, i39, &qf_emlrtBCI, sp);
          }

          i39 = maxcands;
        }

        c_Pitch = Pitch->size[1];
        if (!((i >= 1) && (i <= c_Pitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, c_Pitch, &pf_emlrtBCI, sp);
        }

        loop_ub = i39 - i38;
        for (i39 = 0; i39 < loop_ub; i39++) {
          Pitch->data[(i38 + i39) + Pitch->size[0] * (i - 1)] = 0.0;
        }

        /* 'refine:86' Merit(2:maxcands,i) = 1 - Merit(1,i); */
        if (2 > maxcands) {
          i38 = 0;
          i39 = 0;
        } else {
          i38 = Merit->size[0];
          if (!(2 <= i38)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i38, &nf_emlrtBCI, sp);
          }

          i38 = 1;
          i39 = Merit->size[0];
          if (!(maxcands <= i39)) {
            emlrtDynamicBoundsCheckR2012b(maxcands, 1, i39, &nf_emlrtBCI, sp);
          }

          i39 = maxcands;
        }

        b_loop_ub = Merit->size[0];
        if (!(1 <= b_loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, b_loop_ub, &of_emlrtBCI, sp);
        }

        BestPitch = Merit->size[1];
        if (!((i >= 1) && (i <= BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, BestPitch, &rg_emlrtBCI, sp);
        }

        b_Merit = Merit->data[Merit->size[0] * (i - 1)];
        BestPitch = Merit->size[1];
        if (!((i >= 1) && (i <= BestPitch))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, BestPitch, &mf_emlrtBCI, sp);
        }

        loop_ub = i39 - i38;
        for (i39 = 0; i39 < loop_ub; i39++) {
          Merit->data[(i38 + i39) + Merit->size[0] * (i - 1)] = 1.0 - b_Merit;
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
    i38 = b_BestPitch->size[1];
    if (!((i >= 1) && (i <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i38, &dg_emlrtBCI, sp);
    }

    i38 = Pitch->size[0];
    i39 = maxcands - 1;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &eg_emlrtBCI, sp);
    }

    i38 = Pitch->size[1];
    if (!((i >= 1) && (i <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i38, &fg_emlrtBCI, sp);
    }

    Pitch->data[(i39 + Pitch->size[0] * (i - 1)) - 1] = b_BestPitch->
      data[b_BestPitch->size[0] * (i - 1)];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    /* 'refine:98' if (BestPitch(1,i) > 0) */
    i38 = b_BestPitch->size[1];
    if (!((i >= 1) && (i <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i38, &gg_emlrtBCI, sp);
    }

    if (b_BestPitch->data[b_BestPitch->size[0] * (i - 1)] > 0.0) {
      /*  voiced */
      /* 'refine:99' Merit(maxcands-1,i) = Merit(1,i); */
      i38 = Merit->size[0];
      if (!(1 <= i38)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i38, &lf_emlrtBCI, sp);
      }

      i38 = Merit->size[1];
      if (!((i >= 1) && (i <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i38, &jg_emlrtBCI, sp);
      }

      i38 = Merit->size[0];
      i39 = maxcands - 1;
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &kg_emlrtBCI, sp);
      }

      i38 = Merit->size[1];
      if (!((i >= 1) && (i <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i38, &lg_emlrtBCI, sp);
      }

      Merit->data[(i39 + Merit->size[0] * (i - 1)) - 1] = Merit->data
        [Merit->size[0] * (i - 1)];
    } else {
      /* 'refine:100' else */
      /*  unvoiced */
      /* 'refine:101' Merit(maxcands-1,i) = 1-min(1, Energy(i)/2); */
      i38 = Energy->size[1];
      i39 = (i - 1) + 1;
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &kf_emlrtBCI, sp);
      }

      i38 = Merit->size[0];
      i39 = maxcands - 1;
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &hg_emlrtBCI, sp);
      }

      i38 = Merit->size[1];
      if (!((i >= 1) && (i <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i38, &ig_emlrtBCI, sp);
      }

      Merit->data[(i39 + Merit->size[0] * (i - 1)) - 1] = 1.0 -
        muDoubleScalarMin(1.0, Energy->data[i - 1] / 2.0);
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*   Copy over the SPitch array */
  /* 'refine:106' Pitch(maxcands-2,:) = SPitch; */
  i38 = Pitch->size[0];
  i39 = (int32_T)((real_T)maxcands - 2.0);
  if (!((i39 >= 1) && (i39 <= i38))) {
    emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &jf_emlrtBCI, sp);
  }

  loop_ub = Pitch->size[1];
  i38 = r26->size[0];
  r26->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r26, i38, (int32_T)sizeof(int32_T),
                    &bd_emlrtRTEI);
  for (i38 = 0; i38 < loop_ub; i38++) {
    r26->data[i38] = i38;
  }

  iv40[0] = 1;
  iv40[1] = r26->size[0];
  emlrtSubAssignSizeCheckR2012b(iv40, 2, *(int32_T (*)[2])SPitch->size, 2,
    &sb_emlrtECI, sp);
  loop_ub = SPitch->size[1];
  for (i38 = 0; i38 < loop_ub; i38++) {
    Pitch->data[(maxcands + Pitch->size[0] * r26->data[i38]) - 3] = SPitch->
      data[SPitch->size[0] * i38];
  }

  /* 'refine:107' Merit(maxcands-2,:) = Energy/5; */
  i38 = Merit->size[0];
  i39 = (int32_T)((real_T)maxcands - 2.0);
  if (!((i39 >= 1) && (i39 <= i38))) {
    emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &if_emlrtBCI, sp);
  }

  loop_ub = Merit->size[1];
  i38 = r26->size[0];
  r26->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r26, i38, (int32_T)sizeof(int32_T),
                    &bd_emlrtRTEI);
  for (i38 = 0; i38 < loop_ub; i38++) {
    r26->data[i38] = i38;
  }

  i38 = b_BestPitch->size[0] * b_BestPitch->size[1];
  b_BestPitch->size[0] = 1;
  b_BestPitch->size[1] = Energy->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_BestPitch, i38, (int32_T)sizeof
                    (real_T), &bd_emlrtRTEI);
  loop_ub = Energy->size[0] * Energy->size[1];
  for (i38 = 0; i38 < loop_ub; i38++) {
    b_BestPitch->data[i38] = Energy->data[i38] / 5.0;
  }

  iv41[0] = 1;
  iv41[1] = r26->size[0];
  emlrtSubAssignSizeCheckR2012b(iv41, 2, *(int32_T (*)[2])b_BestPitch->size, 2,
    &rb_emlrtECI, sp);
  loop_ub = b_BestPitch->size[1];
  for (i38 = 0; i38 < loop_ub; i38++) {
    Merit->data[(maxcands + Merit->size[0] * r26->data[i38]) - 3] =
      b_BestPitch->data[b_BestPitch->size[0] * i38];
  }

  emxFree_int32_T(&r26);
  emxFree_real_T(&b_BestPitch);

  /* ============================================================================== */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (refine.c) */
