/*
 * Mymedfilt1.c
 *
 * Code generation for function 'Mymedfilt1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Mymedfilt1.h"
#include "yaapt_emxutil.h"
#include "median.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo kk_emlrtRSI = { 40, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo dd_emlrtRTEI = { 24, 14, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo ed_emlrtRTEI = { 24, 10, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo nd_emlrtRTEI = { 24, 25, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 35, 14, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 35, 25, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtRTEInfo hg_emlrtRTEI = { 37, 9, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 38, 19, "m", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtECInfo qb_emlrtECI = { -1, 38, 17, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtDCInfo ub_emlrtDCI = { 34, 19, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 4 };

static emlrtDCInfo vb_emlrtDCI = { 34, 21, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 4 };

static emlrtDCInfo wb_emlrtDCI = { 38, 54, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 4 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 41, 13, "m", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtDCInfo xb_emlrtDCI = { 41, 13, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 1 };

/* Function Definitions */
void Mymedfilt1(const emlrtStack *sp, emxArray_real_T *s, real_T w,
                emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int32_T c_s;
  int32_T i31;
  int32_T loop_ub;
  emxArray_real_T *b_m;
  real_T w2;
  real_T d_s;
  int32_T i32;
  int32_T i;
  emxArray_int32_T *r27;
  emxArray_real_T *r28;
  emxArray_real_T *b;
  emxArray_real_T *c_m;
  real_T e_s;
  int32_T iv38[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &dd_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 13U, 0);

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
  covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 1);
  c_s = s->size[1];
  i31 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i31, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  for (i31 = 0; i31 < c_s; i31++) {
    b_s->data[b_s->size[0] * i31] = s->data[i31];
  }

  i31 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)s, i31, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  loop_ub = b_s->size[1];
  for (i31 = 0; i31 < loop_ub; i31++) {
    s->data[s->size[0] * i31] = b_s->data[b_s->size[0] * i31];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &b_m, 2, &ed_emlrtRTEI, true);
  w2 = muDoubleScalarFloor(w / 2.0);
  w = 2.0 * w2 + 1.0;
  i31 = b_m->size[0] * b_m->size[1];
  if (!(w >= 0.0)) {
    emlrtNonNegativeCheckR2012b(w, &ub_emlrtDCI, sp);
  }

  b_m->size[0] = (int32_T)w;
  d_s = ((real_T)s->size[1] + w) - 1.0;
  if (!(d_s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d_s, &vb_emlrtDCI, sp);
  }

  b_m->size[1] = (int32_T)d_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i31, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  if (!(w >= 0.0)) {
    emlrtNonNegativeCheckR2012b(w, &ub_emlrtDCI, sp);
  }

  d_s = ((real_T)s->size[1] + w) - 1.0;
  if (!(d_s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d_s, &vb_emlrtDCI, sp);
  }

  loop_ub = (int32_T)w * (int32_T)d_s;
  for (i31 = 0; i31 < loop_ub; i31++) {
    b_m->data[i31] = 0.0;
  }

  i31 = s->size[1];
  if (!(1 <= i31)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i31, &af_emlrtBCI, sp);
  }

  i31 = s->size[1];
  i32 = s->size[1];
  if (!((i32 >= 1) && (i32 <= i31))) {
    emlrtDynamicBoundsCheckR2012b(i32, 1, i31, &bf_emlrtBCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(0.0, 1.0, w - 1.0, mxDOUBLE_CLASS, (int32_T)((w
    - 1.0) + 1.0), &hg_emlrtRTEI, sp);
  i = 0;
  emxInit_int32_T1(sp, &r27, 1, &dd_emlrtRTEI, true);
  emxInit_real_T(sp, &r28, 2, &dd_emlrtRTEI, true);
  emxInit_real_T(sp, &b, 2, &dd_emlrtRTEI, true);
  while (i <= (int32_T)((w - 1.0) + 1.0) - 1) {
    covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 2);
    i31 = b_m->size[0];
    i32 = i + 1;
    if (!((i32 >= 1) && (i32 <= i31))) {
      emlrtDynamicBoundsCheckR2012b(i32, 1, i31, &cf_emlrtBCI, sp);
    }

    loop_ub = b_m->size[1];
    i31 = r27->size[0];
    r27->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r27, i31, (int32_T)sizeof(int32_T),
                      &dd_emlrtRTEI);
    for (i31 = 0; i31 < loop_ub; i31++) {
      r27->data[i31] = i31;
    }

    i31 = b->size[0] * b->size[1];
    b->size[0] = 1;
    d_s = (w - (real_T)i) - 1.0;
    if (!(d_s >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d_s, &wb_emlrtDCI, sp);
    }

    b->size[1] = (int32_T)d_s;
    emxEnsureCapacity(sp, (emxArray__common *)b, i31, (int32_T)sizeof(real_T),
                      &dd_emlrtRTEI);
    d_s = (w - (real_T)i) - 1.0;
    if (!(d_s >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d_s, &wb_emlrtDCI, sp);
    }

    loop_ub = (int32_T)d_s;
    for (i31 = 0; i31 < loop_ub; i31++) {
      b->data[i31] = 1.0;
    }

    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    i31 = r28->size[0] * r28->size[1];
    r28->size[0] = 1;
    r28->size[1] = (i + s->size[1]) + b->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r28, i31, (int32_T)sizeof(real_T),
                      &dd_emlrtRTEI);
    for (i31 = 0; i31 < i; i31++) {
      r28->data[r28->size[0] * i31] = d_s;
    }

    loop_ub = s->size[1];
    for (i31 = 0; i31 < loop_ub; i31++) {
      r28->data[r28->size[0] * (i31 + i)] = s->data[s->size[0] * i31];
    }

    loop_ub = b->size[1];
    for (i31 = 0; i31 < loop_ub; i31++) {
      r28->data[r28->size[0] * ((i31 + i) + s->size[1])] = e_s * b->data[b->
        size[0] * i31];
    }

    iv38[0] = 1;
    iv38[1] = r27->size[0];
    emlrtSubAssignSizeCheckR2012b(iv38, 2, *(int32_T (*)[2])r28->size, 2,
      &qb_emlrtECI, sp);
    loop_ub = r28->size[1];
    for (i31 = 0; i31 < loop_ub; i31++) {
      b_m->data[i + b_m->size[0] * r27->data[i31]] = r28->data[r28->size[0] *
        i31];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b);
  emxFree_real_T(&r28);
  emxFree_int32_T(&r27);
  emxInit_real_T(sp, &c_m, 2, &dd_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 3);
  st.site = &kk_emlrtRSI;
  median(&st, b_m, m);
  i31 = s->size[1];
  c_s = m->size[1];
  i32 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = (int32_T)((real_T)i31 - 1.0) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, i32, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  loop_ub = (int32_T)((real_T)i31 - 1.0);
  emxFree_real_T(&b_m);
  for (i31 = 0; i31 <= loop_ub; i31++) {
    d_s = w2 + (real_T)(i31 + 1);
    if (d_s != (int32_T)d_s) {
      emlrtIntegerCheckR2012b(d_s, &xb_emlrtDCI, sp);
    }

    i32 = (int32_T)d_s;
    if (!((i32 >= 1) && (i32 <= c_s))) {
      emlrtDynamicBoundsCheckR2012b(i32, 1, c_s, &df_emlrtBCI, sp);
    }

    c_m->data[c_m->size[0] * i31] = m->data[i32 - 1];
  }

  i31 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i31, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i31 = 0; i31 < loop_ub; i31++) {
    m->data[m->size[0] * i31] = c_m->data[c_m->size[0] * i31];
  }

  emxFree_real_T(&c_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_Mymedfilt1(const emlrtStack *sp, const emxArray_real_T *s, real_T w,
                  emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int32_T s_idx_0;
  int32_T i38;
  emxArray_real_T *b_m;
  real_T w2;
  real_T c_s;
  int32_T loop_ub;
  int32_T i39;
  int32_T i;
  emxArray_int32_T *r30;
  emxArray_real_T *r31;
  emxArray_real_T *b;
  emxArray_real_T *c_m;
  real_T d_s;
  int32_T iv42[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &nd_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 13U, 0);

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
  covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 1);
  s_idx_0 = s->size[1];
  i38 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i38, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  for (i38 = 0; i38 < s_idx_0; i38++) {
    b_s->data[b_s->size[0] * i38] = s->data[i38];
  }

  emxInit_real_T(sp, &b_m, 2, &ed_emlrtRTEI, true);
  w2 = muDoubleScalarFloor(w / 2.0);
  w = 2.0 * w2 + 1.0;
  i38 = b_m->size[0] * b_m->size[1];
  if (!(w >= 0.0)) {
    emlrtNonNegativeCheckR2012b(w, &ub_emlrtDCI, sp);
  }

  b_m->size[0] = (int32_T)w;
  c_s = ((real_T)b_s->size[1] + w) - 1.0;
  if (!(c_s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c_s, &vb_emlrtDCI, sp);
  }

  b_m->size[1] = (int32_T)c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i38, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  if (!(w >= 0.0)) {
    emlrtNonNegativeCheckR2012b(w, &ub_emlrtDCI, sp);
  }

  c_s = ((real_T)b_s->size[1] + w) - 1.0;
  if (!(c_s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c_s, &vb_emlrtDCI, sp);
  }

  loop_ub = (int32_T)w * (int32_T)c_s;
  for (i38 = 0; i38 < loop_ub; i38++) {
    b_m->data[i38] = 0.0;
  }

  i38 = b_s->size[1];
  if (!(1 <= i38)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i38, &af_emlrtBCI, sp);
  }

  i38 = b_s->size[1];
  i39 = b_s->size[1];
  if (!((i39 >= 1) && (i39 <= i38))) {
    emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &bf_emlrtBCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(0.0, 1.0, w - 1.0, mxDOUBLE_CLASS, (int32_T)((w
    - 1.0) + 1.0), &hg_emlrtRTEI, sp);
  i = 0;
  emxInit_int32_T1(sp, &r30, 1, &dd_emlrtRTEI, true);
  emxInit_real_T(sp, &r31, 2, &dd_emlrtRTEI, true);
  emxInit_real_T(sp, &b, 2, &dd_emlrtRTEI, true);
  while (i <= (int32_T)((w - 1.0) + 1.0) - 1) {
    covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 2);
    i38 = b_m->size[0];
    i39 = i + 1;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &cf_emlrtBCI, sp);
    }

    loop_ub = b_m->size[1];
    i38 = r30->size[0];
    r30->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r30, i38, (int32_T)sizeof(int32_T),
                      &dd_emlrtRTEI);
    for (i38 = 0; i38 < loop_ub; i38++) {
      r30->data[i38] = i38;
    }

    i38 = b->size[0] * b->size[1];
    b->size[0] = 1;
    c_s = (w - (real_T)i) - 1.0;
    if (!(c_s >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c_s, &wb_emlrtDCI, sp);
    }

    b->size[1] = (int32_T)c_s;
    emxEnsureCapacity(sp, (emxArray__common *)b, i38, (int32_T)sizeof(real_T),
                      &dd_emlrtRTEI);
    c_s = (w - (real_T)i) - 1.0;
    if (!(c_s >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c_s, &wb_emlrtDCI, sp);
    }

    loop_ub = (int32_T)c_s;
    for (i38 = 0; i38 < loop_ub; i38++) {
      b->data[i38] = 1.0;
    }

    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    i38 = r31->size[0] * r31->size[1];
    r31->size[0] = 1;
    r31->size[1] = (i + b_s->size[1]) + b->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r31, i38, (int32_T)sizeof(real_T),
                      &dd_emlrtRTEI);
    for (i38 = 0; i38 < i; i38++) {
      r31->data[r31->size[0] * i38] = c_s;
    }

    loop_ub = b_s->size[1];
    for (i38 = 0; i38 < loop_ub; i38++) {
      r31->data[r31->size[0] * (i38 + i)] = b_s->data[b_s->size[0] * i38];
    }

    loop_ub = b->size[1];
    for (i38 = 0; i38 < loop_ub; i38++) {
      r31->data[r31->size[0] * ((i38 + i) + b_s->size[1])] = d_s * b->data
        [b->size[0] * i38];
    }

    iv42[0] = 1;
    iv42[1] = r30->size[0];
    emlrtSubAssignSizeCheckR2012b(iv42, 2, *(int32_T (*)[2])r31->size, 2,
      &qb_emlrtECI, sp);
    loop_ub = r31->size[1];
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_m->data[i + b_m->size[0] * r30->data[i38]] = r31->data[r31->size[0] *
        i38];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b);
  emxFree_real_T(&r31);
  emxFree_int32_T(&r30);
  emxInit_real_T(sp, &c_m, 2, &dd_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 3);
  st.site = &kk_emlrtRSI;
  median(&st, b_m, m);
  i38 = b_s->size[1];
  s_idx_0 = m->size[1];
  i39 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = (int32_T)((real_T)i38 - 1.0) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, i39, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  loop_ub = (int32_T)((real_T)i38 - 1.0);
  emxFree_real_T(&b_m);
  emxFree_real_T(&b_s);
  for (i38 = 0; i38 <= loop_ub; i38++) {
    c_s = w2 + (real_T)(i38 + 1);
    if (c_s != (int32_T)c_s) {
      emlrtIntegerCheckR2012b(c_s, &xb_emlrtDCI, sp);
    }

    i39 = (int32_T)c_s;
    if (!((i39 >= 1) && (i39 <= s_idx_0))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, s_idx_0, &df_emlrtBCI, sp);
    }

    c_m->data[c_m->size[0] * i38] = m->data[i39 - 1];
  }

  i38 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i38, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i38 = 0; i38 < loop_ub; i38++) {
    m->data[m->size[0] * i38] = c_m->data[c_m->size[0] * i38];
  }

  emxFree_real_T(&c_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mymedfilt1.c) */
