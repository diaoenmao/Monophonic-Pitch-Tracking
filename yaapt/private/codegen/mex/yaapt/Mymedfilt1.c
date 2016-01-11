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
static emlrtRTEInfo vb_emlrtRTEI = { 24, 14, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo fc_emlrtRTEI = { 24, 25, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

/* Function Definitions */

/*
 * function m = Mymedfilt1(s, w)
 */
void Mymedfilt1(const emlrtStack *sp, emxArray_real_T *s, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int32_T c_s;
  int32_T i25;
  int32_T loop_ub;
  emxArray_real_T *b_m;
  int32_T i26;
  int32_T i;
  emxArray_int32_T *r15;
  emxArray_real_T *r16;
  real_T d_s;
  real_T e_s;
  int32_T iv22[2];
  emxArray_real_T *c_m;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &vb_emlrtRTEI, true);

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
  i25 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i25, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  for (i25 = 0; i25 < c_s; i25++) {
    b_s->data[b_s->size[0] * i25] = s->data[i25];
  }

  i25 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)s, i25, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  loop_ub = b_s->size[1];
  for (i25 = 0; i25 < loop_ub; i25++) {
    s->data[s->size[0] * i25] = b_s->data[b_s->size[0] * i25];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &b_m, 2, &wb_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i25 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  b_m->size[1] = (int32_T)(((real_T)s->size[1] + 5.0) - 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i25, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  loop_ub = 5 * (int32_T)(((real_T)s->size[1] + 5.0) - 1.0);
  for (i25 = 0; i25 < loop_ub; i25++) {
    b_m->data[i25] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i25 = s->size[1];
  if (!(1 <= i25)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i25, &id_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:35' sl = s(n); */
  i25 = s->size[1];
  i26 = s->size[1];
  if (!((i26 >= 1) && (i26 <= i25))) {
    emlrtDynamicBoundsCheckR2012b(i26, 1, i25, &jd_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  i = 0;
  emxInit_int32_T(sp, &r15, 1, &vb_emlrtRTEI, true);
  emxInit_real_T(sp, &r16, 2, &vb_emlrtRTEI, true);
  while (i < 5) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = b_m->size[1];
    i25 = r15->size[0];
    r15->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r15, i25, (int32_T)sizeof(int32_T),
                      &vb_emlrtRTEI);
    for (i25 = 0; i25 < loop_ub; i25++) {
      r15->data[i25] = i25;
    }

    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    c_s = 4 - i;
    i25 = r16->size[0] * r16->size[1];
    r16->size[0] = 1;
    r16->size[1] = (i + s->size[1]) + c_s;
    emxEnsureCapacity(sp, (emxArray__common *)r16, i25, (int32_T)sizeof(real_T),
                      &vb_emlrtRTEI);
    for (i25 = 0; i25 < i; i25++) {
      r16->data[r16->size[0] * i25] = d_s;
    }

    loop_ub = s->size[1];
    for (i25 = 0; i25 < loop_ub; i25++) {
      r16->data[r16->size[0] * (i25 + i)] = s->data[s->size[0] * i25];
    }

    for (i25 = 0; i25 < c_s; i25++) {
      r16->data[r16->size[0] * ((i25 + i) + s->size[1])] = e_s;
    }

    iv22[0] = 1;
    iv22[1] = r15->size[0];
    emlrtSubAssignSizeCheckR2012b(iv22, 2, *(int32_T (*)[2])r16->size, 2,
      &fb_emlrtECI, sp);
    loop_ub = r16->size[1];
    for (i25 = 0; i25 < loop_ub; i25++) {
      b_m->data[i + b_m->size[0] * r15->data[i25]] = r16->data[r16->size[0] *
        i25];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r16);
  emxFree_int32_T(&r15);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &rh_emlrtRSI;
  median(&st, b_m, m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  emxFree_real_T(&b_m);
  if (3U > 2U + s->size[1]) {
    i25 = 0;
    c_s = 0;
  } else {
    i25 = m->size[1];
    if (!(3 <= i25)) {
      emlrtDynamicBoundsCheckR2012b(3, 1, i25, &kd_emlrtBCI, sp);
    }

    i25 = 2;
    i26 = m->size[1];
    c_s = (int32_T)(2U + s->size[1]);
    if (!((c_s >= 1) && (c_s <= i26))) {
      emlrtDynamicBoundsCheckR2012b(c_s, 1, i26, &kd_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &c_m, 2, &vb_emlrtRTEI, true);
  i26 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = c_s - i25;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, i26, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  loop_ub = c_s - i25;
  for (i26 = 0; i26 < loop_ub; i26++) {
    c_m->data[c_m->size[0] * i26] = m->data[i25 + i26];
  }

  i25 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i25, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i25 = 0; i25 < loop_ub; i25++) {
    m->data[m->size[0] * i25] = c_m->data[c_m->size[0] * i25];
  }

  emxFree_real_T(&c_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * function m = Mymedfilt1(s, w)
 */
void b_Mymedfilt1(const emlrtStack *sp, const emxArray_real_T *s,
                  emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int32_T s_idx_0;
  int32_T i27;
  emxArray_real_T *b_m;
  int32_T loop_ub;
  int32_T i28;
  int32_T i;
  emxArray_int32_T *r17;
  emxArray_real_T *r18;
  real_T c_s;
  real_T d_s;
  int32_T iv25[2];
  emxArray_real_T *c_m;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &fc_emlrtRTEI, true);

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
  i27 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i27, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  for (i27 = 0; i27 < s_idx_0; i27++) {
    b_s->data[b_s->size[0] * i27] = s->data[i27];
  }

  emxInit_real_T(sp, &b_m, 2, &wb_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i27 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  b_m->size[1] = (int32_T)(((real_T)b_s->size[1] + 5.0) - 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i27, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  loop_ub = 5 * (int32_T)(((real_T)b_s->size[1] + 5.0) - 1.0);
  for (i27 = 0; i27 < loop_ub; i27++) {
    b_m->data[i27] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i27 = b_s->size[1];
  if (!(1 <= i27)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i27, &id_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:35' sl = s(n); */
  i27 = b_s->size[1];
  i28 = b_s->size[1];
  if (!((i28 >= 1) && (i28 <= i27))) {
    emlrtDynamicBoundsCheckR2012b(i28, 1, i27, &jd_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  i = 0;
  emxInit_int32_T(sp, &r17, 1, &vb_emlrtRTEI, true);
  emxInit_real_T(sp, &r18, 2, &vb_emlrtRTEI, true);
  while (i < 5) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = b_m->size[1];
    i27 = r17->size[0];
    r17->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r17, i27, (int32_T)sizeof(int32_T),
                      &vb_emlrtRTEI);
    for (i27 = 0; i27 < loop_ub; i27++) {
      r17->data[i27] = i27;
    }

    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    s_idx_0 = 4 - i;
    i27 = r18->size[0] * r18->size[1];
    r18->size[0] = 1;
    r18->size[1] = (i + b_s->size[1]) + s_idx_0;
    emxEnsureCapacity(sp, (emxArray__common *)r18, i27, (int32_T)sizeof(real_T),
                      &vb_emlrtRTEI);
    for (i27 = 0; i27 < i; i27++) {
      r18->data[r18->size[0] * i27] = c_s;
    }

    loop_ub = b_s->size[1];
    for (i27 = 0; i27 < loop_ub; i27++) {
      r18->data[r18->size[0] * (i27 + i)] = b_s->data[b_s->size[0] * i27];
    }

    for (i27 = 0; i27 < s_idx_0; i27++) {
      r18->data[r18->size[0] * ((i27 + i) + b_s->size[1])] = d_s;
    }

    iv25[0] = 1;
    iv25[1] = r17->size[0];
    emlrtSubAssignSizeCheckR2012b(iv25, 2, *(int32_T (*)[2])r18->size, 2,
      &fb_emlrtECI, sp);
    loop_ub = r18->size[1];
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_m->data[i + b_m->size[0] * r17->data[i27]] = r18->data[r18->size[0] *
        i27];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r18);
  emxFree_int32_T(&r17);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &rh_emlrtRSI;
  median(&st, b_m, m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  emxFree_real_T(&b_m);
  if (3U > 2U + b_s->size[1]) {
    i27 = 0;
    s_idx_0 = 0;
  } else {
    i27 = m->size[1];
    if (!(3 <= i27)) {
      emlrtDynamicBoundsCheckR2012b(3, 1, i27, &kd_emlrtBCI, sp);
    }

    i27 = 2;
    i28 = m->size[1];
    s_idx_0 = (int32_T)(2U + b_s->size[1]);
    if (!((s_idx_0 >= 1) && (s_idx_0 <= i28))) {
      emlrtDynamicBoundsCheckR2012b(s_idx_0, 1, i28, &kd_emlrtBCI, sp);
    }
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &c_m, 2, &vb_emlrtRTEI, true);
  i28 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = s_idx_0 - i27;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, i28, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  loop_ub = s_idx_0 - i27;
  for (i28 = 0; i28 < loop_ub; i28++) {
    c_m->data[c_m->size[0] * i28] = m->data[i27 + i28];
  }

  i27 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i27, (int32_T)sizeof(real_T),
                    &vb_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i27 = 0; i27 < loop_ub; i27++) {
    m->data[m->size[0] * i27] = c_m->data[c_m->size[0] * i27];
  }

  emxFree_real_T(&c_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mymedfilt1.c) */
