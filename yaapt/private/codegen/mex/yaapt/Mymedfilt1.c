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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo bk_emlrtRSI = { 40, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo vc_emlrtRTEI = { 24, 14, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo wc_emlrtRTEI = { 24, 10, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo kd_emlrtRTEI = { 24, 25, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtECInfo sb_emlrtECI = { -1, 38, 17, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 38, 19, "m", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtDCInfo rc_emlrtDCI = { 38, 54, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 4 };

static emlrtDCInfo sc_emlrtDCI = { 38, 39, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 4 };

static emlrtRTEInfo hg_emlrtRTEI = { 37, 9, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 35, 25, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 35, 14, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtDCInfo tc_emlrtDCI = { 34, 21, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 4 };

static emlrtDCInfo uc_emlrtDCI = { 34, 19, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 4 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 41, 13, "m", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtDCInfo vc_emlrtDCI = { 41, 13, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 1 };

/* Function Definitions */

/*
 * function m = Mymedfilt1(s, w)
 */
void Mymedfilt1(const emlrtStack *sp, emxArray_real_T *s, real_T w,
                emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int32_T c_s;
  int32_T i33;
  int32_T loop_ub;
  emxArray_real_T *b_m;
  real_T w2;
  real_T d_s;
  int32_T i34;
  int32_T i;
  emxArray_int32_T *r34;
  emxArray_real_T *r35;
  emxArray_real_T *b;
  real_T e_s;
  int32_T iv43[2];
  emxArray_real_T *c_m;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &vc_emlrtRTEI, true);

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
  c_s = s->size[1];
  i33 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i33, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  for (i33 = 0; i33 < c_s; i33++) {
    b_s->data[b_s->size[0] * i33] = s->data[i33];
  }

  i33 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)s, i33, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  loop_ub = b_s->size[1];
  for (i33 = 0; i33 < loop_ub; i33++) {
    s->data[s->size[0] * i33] = b_s->data[b_s->size[0] * i33];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &b_m, 2, &wc_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  w2 = muDoubleScalarFloor(w / 2.0);

  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  w = 2.0 * w2 + 1.0;

  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i33 = b_m->size[0] * b_m->size[1];
  if (!(w > 0.0)) {
    emlrtNonNegativeCheckR2012b(w, &uc_emlrtDCI, sp);
  }

  b_m->size[0] = (int32_T)w;
  d_s = ((real_T)s->size[1] + w) - 1.0;
  if (!(d_s > 0.0)) {
    emlrtNonNegativeCheckR2012b(d_s, &tc_emlrtDCI, sp);
  }

  b_m->size[1] = (int32_T)d_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i33, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  if (!(w > 0.0)) {
    emlrtNonNegativeCheckR2012b(w, &uc_emlrtDCI, sp);
  }

  d_s = ((real_T)s->size[1] + w) - 1.0;
  if (!(d_s > 0.0)) {
    emlrtNonNegativeCheckR2012b(d_s, &tc_emlrtDCI, sp);
  }

  loop_ub = (int32_T)w * (int32_T)d_s;
  for (i33 = 0; i33 < loop_ub; i33++) {
    b_m->data[i33] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i33 = s->size[1];
  if (!(1 <= i33)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i33, &rf_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:35' sl = s(n); */
  i33 = s->size[1];
  i34 = s->size[1];
  if (!((i34 >= 1) && (i34 <= i33))) {
    emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &qf_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  emlrtForLoopVectorCheckR2012b(0.0, 1.0, w - 1.0, mxDOUBLE_CLASS, (int32_T)((w
    - 1.0) + 1.0), &hg_emlrtRTEI, sp);
  i = 0;
  emxInit_int32_T1(sp, &r34, 1, &vc_emlrtRTEI, true);
  emxInit_real_T(sp, &r35, 2, &vc_emlrtRTEI, true);
  emxInit_real_T(sp, &b, 2, &vc_emlrtRTEI, true);
  while (i <= (int32_T)((w - 1.0) + 1.0) - 1) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    i33 = b_m->size[0];
    i34 = i + 1;
    if (!((i34 >= 1) && (i34 <= i33))) {
      emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &pf_emlrtBCI, sp);
    }

    loop_ub = b_m->size[1];
    i33 = r34->size[0];
    r34->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r34, i33, (int32_T)sizeof(int32_T),
                      &vc_emlrtRTEI);
    for (i33 = 0; i33 < loop_ub; i33++) {
      r34->data[i33] = i33;
    }

    i33 = i;
    if (!(i33 > 0)) {
      emlrtNonNegativeCheckR2012b(i33, &sc_emlrtDCI, sp);
    }

    i33 = b->size[0] * b->size[1];
    b->size[0] = 1;
    d_s = (w - (real_T)i) - 1.0;
    if (!(d_s > 0.0)) {
      emlrtNonNegativeCheckR2012b(d_s, &rc_emlrtDCI, sp);
    }

    b->size[1] = (int32_T)d_s;
    emxEnsureCapacity(sp, (emxArray__common *)b, i33, (int32_T)sizeof(real_T),
                      &vc_emlrtRTEI);
    d_s = (w - (real_T)i) - 1.0;
    if (!(d_s > 0.0)) {
      emlrtNonNegativeCheckR2012b(d_s, &rc_emlrtDCI, sp);
    }

    loop_ub = (int32_T)d_s;
    for (i33 = 0; i33 < loop_ub; i33++) {
      b->data[i33] = 1.0;
    }

    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    i33 = r35->size[0] * r35->size[1];
    r35->size[0] = 1;
    r35->size[1] = (i + s->size[1]) + b->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r35, i33, (int32_T)sizeof(real_T),
                      &vc_emlrtRTEI);
    for (i33 = 0; i33 < i; i33++) {
      r35->data[r35->size[0] * i33] = d_s;
    }

    loop_ub = s->size[1];
    for (i33 = 0; i33 < loop_ub; i33++) {
      r35->data[r35->size[0] * (i33 + i)] = s->data[s->size[0] * i33];
    }

    loop_ub = b->size[1];
    for (i33 = 0; i33 < loop_ub; i33++) {
      r35->data[r35->size[0] * ((i33 + i) + s->size[1])] = e_s * b->data[b->
        size[0] * i33];
    }

    iv43[0] = 1;
    iv43[1] = r34->size[0];
    emlrtSubAssignSizeCheckR2012b(iv43, 2, *(int32_T (*)[2])r35->size, 2,
      &sb_emlrtECI, sp);
    loop_ub = r35->size[1];
    for (i33 = 0; i33 < loop_ub; i33++) {
      b_m->data[i + b_m->size[0] * r34->data[i33]] = r35->data[r35->size[0] *
        i33];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b);
  emxFree_real_T(&r35);
  emxFree_int32_T(&r34);
  emxInit_real_T(sp, &c_m, 2, &vc_emlrtRTEI, true);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &bk_emlrtRSI;
  median(&st, b_m, m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  i33 = s->size[1];
  c_s = m->size[1];
  i34 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = (int32_T)((real_T)i33 - 1.0) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, i34, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  loop_ub = (int32_T)((real_T)i33 - 1.0);
  emxFree_real_T(&b_m);
  for (i33 = 0; i33 <= loop_ub; i33++) {
    d_s = w2 + (real_T)(i33 + 1);
    if (d_s != (int32_T)d_s) {
      emlrtIntegerCheckR2012b(d_s, &vc_emlrtDCI, sp);
    }

    i34 = (int32_T)d_s;
    if (!((i34 >= 1) && (i34 <= c_s))) {
      emlrtDynamicBoundsCheckR2012b(i34, 1, c_s, &sf_emlrtBCI, sp);
    }

    c_m->data[c_m->size[0] * i33] = m->data[i34 - 1];
  }

  i33 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i33, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i33 = 0; i33 < loop_ub; i33++) {
    m->data[m->size[0] * i33] = c_m->data[c_m->size[0] * i33];
  }

  emxFree_real_T(&c_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * function m = Mymedfilt1(s, w)
 */
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
  emxArray_int32_T *r37;
  emxArray_real_T *r38;
  emxArray_real_T *b;
  real_T d_s;
  int32_T iv47[2];
  emxArray_real_T *c_m;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &kd_emlrtRTEI, true);

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
  s_idx_0 = s->size[0] * s->size[1];
  i38 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i38, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  for (i38 = 0; i38 < s_idx_0; i38++) {
    b_s->data[b_s->size[0] * i38] = s->data[i38];
  }

  emxInit_real_T(sp, &b_m, 2, &wc_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  w2 = muDoubleScalarFloor(w / 2.0);

  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  w = 2.0 * w2 + 1.0;

  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i38 = b_m->size[0] * b_m->size[1];
  if (!(w > 0.0)) {
    emlrtNonNegativeCheckR2012b(w, &uc_emlrtDCI, sp);
  }

  b_m->size[0] = (int32_T)w;
  c_s = ((real_T)b_s->size[1] + w) - 1.0;
  if (!(c_s > 0.0)) {
    emlrtNonNegativeCheckR2012b(c_s, &tc_emlrtDCI, sp);
  }

  b_m->size[1] = (int32_T)c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i38, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  if (!(w > 0.0)) {
    emlrtNonNegativeCheckR2012b(w, &uc_emlrtDCI, sp);
  }

  c_s = ((real_T)b_s->size[1] + w) - 1.0;
  if (!(c_s > 0.0)) {
    emlrtNonNegativeCheckR2012b(c_s, &tc_emlrtDCI, sp);
  }

  loop_ub = (int32_T)w * (int32_T)c_s;
  for (i38 = 0; i38 < loop_ub; i38++) {
    b_m->data[i38] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i38 = b_s->size[1];
  if (!(1 <= i38)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i38, &rf_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:35' sl = s(n); */
  i38 = b_s->size[1];
  i39 = b_s->size[1];
  if (!((i39 >= 1) && (i39 <= i38))) {
    emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &qf_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  emlrtForLoopVectorCheckR2012b(0.0, 1.0, w - 1.0, mxDOUBLE_CLASS, (int32_T)((w
    - 1.0) + 1.0), &hg_emlrtRTEI, sp);
  i = 0;
  emxInit_int32_T1(sp, &r37, 1, &vc_emlrtRTEI, true);
  emxInit_real_T(sp, &r38, 2, &vc_emlrtRTEI, true);
  emxInit_real_T(sp, &b, 2, &vc_emlrtRTEI, true);
  while (i <= (int32_T)((w - 1.0) + 1.0) - 1) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    i38 = b_m->size[0];
    i39 = i + 1;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &pf_emlrtBCI, sp);
    }

    loop_ub = b_m->size[1];
    i38 = r37->size[0];
    r37->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r37, i38, (int32_T)sizeof(int32_T),
                      &vc_emlrtRTEI);
    for (i38 = 0; i38 < loop_ub; i38++) {
      r37->data[i38] = i38;
    }

    i38 = i;
    if (!(i38 > 0)) {
      emlrtNonNegativeCheckR2012b(i38, &sc_emlrtDCI, sp);
    }

    i38 = b->size[0] * b->size[1];
    b->size[0] = 1;
    c_s = (w - (real_T)i) - 1.0;
    if (!(c_s > 0.0)) {
      emlrtNonNegativeCheckR2012b(c_s, &rc_emlrtDCI, sp);
    }

    b->size[1] = (int32_T)c_s;
    emxEnsureCapacity(sp, (emxArray__common *)b, i38, (int32_T)sizeof(real_T),
                      &vc_emlrtRTEI);
    c_s = (w - (real_T)i) - 1.0;
    if (!(c_s > 0.0)) {
      emlrtNonNegativeCheckR2012b(c_s, &rc_emlrtDCI, sp);
    }

    loop_ub = (int32_T)c_s;
    for (i38 = 0; i38 < loop_ub; i38++) {
      b->data[i38] = 1.0;
    }

    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    i38 = r38->size[0] * r38->size[1];
    r38->size[0] = 1;
    r38->size[1] = (i + b_s->size[1]) + b->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r38, i38, (int32_T)sizeof(real_T),
                      &vc_emlrtRTEI);
    for (i38 = 0; i38 < i; i38++) {
      r38->data[r38->size[0] * i38] = c_s;
    }

    loop_ub = b_s->size[1];
    for (i38 = 0; i38 < loop_ub; i38++) {
      r38->data[r38->size[0] * (i38 + i)] = b_s->data[b_s->size[0] * i38];
    }

    loop_ub = b->size[1];
    for (i38 = 0; i38 < loop_ub; i38++) {
      r38->data[r38->size[0] * ((i38 + i) + b_s->size[1])] = d_s * b->data
        [b->size[0] * i38];
    }

    iv47[0] = 1;
    iv47[1] = r37->size[0];
    emlrtSubAssignSizeCheckR2012b(iv47, 2, *(int32_T (*)[2])r38->size, 2,
      &sb_emlrtECI, sp);
    loop_ub = r38->size[1];
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_m->data[i + b_m->size[0] * r37->data[i38]] = r38->data[r38->size[0] *
        i38];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b);
  emxFree_real_T(&r38);
  emxFree_int32_T(&r37);
  emxInit_real_T(sp, &c_m, 2, &vc_emlrtRTEI, true);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &bk_emlrtRSI;
  median(&st, b_m, m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  i38 = b_s->size[1];
  s_idx_0 = m->size[1];
  i39 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = (int32_T)((real_T)i38 - 1.0) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, i39, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  loop_ub = (int32_T)((real_T)i38 - 1.0);
  emxFree_real_T(&b_m);
  emxFree_real_T(&b_s);
  for (i38 = 0; i38 <= loop_ub; i38++) {
    c_s = w2 + (real_T)(i38 + 1);
    if (c_s != (int32_T)c_s) {
      emlrtIntegerCheckR2012b(c_s, &vc_emlrtDCI, sp);
    }

    i39 = (int32_T)c_s;
    if (!((i39 >= 1) && (i39 <= s_idx_0))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, s_idx_0, &sf_emlrtBCI, sp);
    }

    c_m->data[c_m->size[0] * i38] = m->data[i39 - 1];
  }

  i38 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i38, (int32_T)sizeof(real_T),
                    &vc_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i38 = 0; i38 < loop_ub; i38++) {
    m->data[m->size[0] * i38] = c_m->data[c_m->size[0] * i38];
  }

  emxFree_real_T(&c_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mymedfilt1.c) */
