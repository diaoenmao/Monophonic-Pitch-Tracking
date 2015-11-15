/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ah_emlrtRSI = { 40, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo xb_emlrtRTEI = { 24, 14, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo yb_emlrtRTEI = { 24, 10, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo fc_emlrtRTEI = { 24, 25, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 35, 14, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 35, 25, "s", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

static emlrtECInfo jb_emlrtECI = { -1, 38, 17, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 41, 13, "m", "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m", 0 };

/* Function Definitions */

/*
 * function m = Mymedfilt1(s, w)
 */
void Mymedfilt1(const emlrtStack *sp, emxArray_real_T *s, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int32_T c_s;
  int32_T i19;
  int32_T loop_ub;
  emxArray_real_T *b_m;
  int32_T i20;
  int32_T i;
  emxArray_int32_T *r10;
  emxArray_real_T *r11;
  real_T d_s;
  real_T e_s;
  int32_T iv24[2];
  emxArray_real_T *c_m;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &xb_emlrtRTEI, true);

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
  i19 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i19, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  for (i19 = 0; i19 < c_s; i19++) {
    b_s->data[b_s->size[0] * i19] = s->data[i19];
  }

  i19 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)s, i19, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = b_s->size[1];
  for (i19 = 0; i19 < loop_ub; i19++) {
    s->data[s->size[0] * i19] = b_s->data[b_s->size[0] * i19];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &b_m, 2, &yb_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i19 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  b_m->size[1] = (int32_T)(((real_T)s->size[1] + 5.0) - 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i19, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = 5 * (int32_T)(((real_T)s->size[1] + 5.0) - 1.0);
  for (i19 = 0; i19 < loop_ub; i19++) {
    b_m->data[i19] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i19 = s->size[1];
  if (!(1 <= i19)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i19, &ue_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:35' sl = s(n); */
  i19 = s->size[1];
  i20 = s->size[1];
  if (!((i20 >= 1) && (i20 <= i19))) {
    emlrtDynamicBoundsCheckR2012b(i20, 1, i19, &ve_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  i = 0;
  emxInit_int32_T(sp, &r10, 1, &xb_emlrtRTEI, true);
  emxInit_real_T(sp, &r11, 2, &xb_emlrtRTEI, true);
  while (i < 5) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = b_m->size[1];
    i19 = r10->size[0];
    r10->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r10, i19, (int32_T)sizeof(int32_T),
                      &xb_emlrtRTEI);
    for (i19 = 0; i19 < loop_ub; i19++) {
      r10->data[i19] = i19;
    }

    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    c_s = 4 - i;
    i19 = r11->size[0] * r11->size[1];
    r11->size[0] = 1;
    r11->size[1] = (i + s->size[1]) + c_s;
    emxEnsureCapacity(sp, (emxArray__common *)r11, i19, (int32_T)sizeof(real_T),
                      &xb_emlrtRTEI);
    for (i19 = 0; i19 < i; i19++) {
      r11->data[r11->size[0] * i19] = d_s;
    }

    loop_ub = s->size[1];
    for (i19 = 0; i19 < loop_ub; i19++) {
      r11->data[r11->size[0] * (i19 + i)] = s->data[s->size[0] * i19];
    }

    for (i19 = 0; i19 < c_s; i19++) {
      r11->data[r11->size[0] * ((i19 + i) + s->size[1])] = e_s;
    }

    iv24[0] = 1;
    iv24[1] = r10->size[0];
    emlrtSubAssignSizeCheckR2012b(iv24, 2, *(int32_T (*)[2])r11->size, 2,
      &jb_emlrtECI, sp);
    loop_ub = r11->size[1];
    for (i19 = 0; i19 < loop_ub; i19++) {
      b_m->data[i + b_m->size[0] * r10->data[i19]] = r11->data[r11->size[0] *
        i19];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r11);
  emxFree_int32_T(&r10);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &ah_emlrtRSI;
  median(&st, b_m, m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  emxFree_real_T(&b_m);
  if (3U > 2U + s->size[1]) {
    i19 = 0;
    c_s = 0;
  } else {
    i19 = 2;
    i20 = m->size[1];
    c_s = (int32_T)(2U + s->size[1]);
    if (!((c_s >= 1) && (c_s <= i20))) {
      emlrtDynamicBoundsCheckR2012b(c_s, 1, i20, &we_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &c_m, 2, &xb_emlrtRTEI, true);
  i20 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = c_s - i19;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, i20, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = c_s - i19;
  for (i20 = 0; i20 < loop_ub; i20++) {
    c_m->data[c_m->size[0] * i20] = m->data[i19 + i20];
  }

  i19 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i19, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i19 = 0; i19 < loop_ub; i19++) {
    m->data[m->size[0] * i19] = c_m->data[c_m->size[0] * i19];
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
  int32_T i24;
  emxArray_real_T *b_m;
  int32_T loop_ub;
  int32_T i25;
  int32_T i;
  emxArray_int32_T *r12;
  emxArray_real_T *r13;
  real_T c_s;
  real_T d_s;
  int32_T iv27[2];
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
  s_idx_0 = s->size[1];
  i24 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i24, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  for (i24 = 0; i24 < s_idx_0; i24++) {
    b_s->data[b_s->size[0] * i24] = s->data[i24];
  }

  emxInit_real_T(sp, &b_m, 2, &yb_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i24 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  b_m->size[1] = (int32_T)(((real_T)b_s->size[1] + 5.0) - 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i24, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = 5 * (int32_T)(((real_T)b_s->size[1] + 5.0) - 1.0);
  for (i24 = 0; i24 < loop_ub; i24++) {
    b_m->data[i24] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i24 = b_s->size[1];
  if (!(1 <= i24)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i24, &ue_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:35' sl = s(n); */
  i24 = b_s->size[1];
  i25 = b_s->size[1];
  if (!((i25 >= 1) && (i25 <= i24))) {
    emlrtDynamicBoundsCheckR2012b(i25, 1, i24, &ve_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  i = 0;
  emxInit_int32_T(sp, &r12, 1, &xb_emlrtRTEI, true);
  emxInit_real_T(sp, &r13, 2, &xb_emlrtRTEI, true);
  while (i < 5) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = b_m->size[1];
    i24 = r12->size[0];
    r12->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r12, i24, (int32_T)sizeof(int32_T),
                      &xb_emlrtRTEI);
    for (i24 = 0; i24 < loop_ub; i24++) {
      r12->data[i24] = i24;
    }

    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    s_idx_0 = 4 - i;
    i24 = r13->size[0] * r13->size[1];
    r13->size[0] = 1;
    r13->size[1] = (i + b_s->size[1]) + s_idx_0;
    emxEnsureCapacity(sp, (emxArray__common *)r13, i24, (int32_T)sizeof(real_T),
                      &xb_emlrtRTEI);
    for (i24 = 0; i24 < i; i24++) {
      r13->data[r13->size[0] * i24] = c_s;
    }

    loop_ub = b_s->size[1];
    for (i24 = 0; i24 < loop_ub; i24++) {
      r13->data[r13->size[0] * (i24 + i)] = b_s->data[b_s->size[0] * i24];
    }

    for (i24 = 0; i24 < s_idx_0; i24++) {
      r13->data[r13->size[0] * ((i24 + i) + b_s->size[1])] = d_s;
    }

    iv27[0] = 1;
    iv27[1] = r12->size[0];
    emlrtSubAssignSizeCheckR2012b(iv27, 2, *(int32_T (*)[2])r13->size, 2,
      &jb_emlrtECI, sp);
    loop_ub = r13->size[1];
    for (i24 = 0; i24 < loop_ub; i24++) {
      b_m->data[i + b_m->size[0] * r12->data[i24]] = r13->data[r13->size[0] *
        i24];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r13);
  emxFree_int32_T(&r12);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &ah_emlrtRSI;
  median(&st, b_m, m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  emxFree_real_T(&b_m);
  if (3U > 2U + b_s->size[1]) {
    i24 = 0;
    s_idx_0 = 0;
  } else {
    i24 = 2;
    i25 = m->size[1];
    s_idx_0 = (int32_T)(2U + b_s->size[1]);
    if (!((s_idx_0 >= 1) && (s_idx_0 <= i25))) {
      emlrtDynamicBoundsCheckR2012b(s_idx_0, 1, i25, &we_emlrtBCI, sp);
    }
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &c_m, 2, &xb_emlrtRTEI, true);
  i25 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = s_idx_0 - i24;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, i25, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = s_idx_0 - i24;
  for (i25 = 0; i25 < loop_ub; i25++) {
    c_m->data[c_m->size[0] * i25] = m->data[i24 + i25];
  }

  i24 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i24, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i24 = 0; i24 < loop_ub; i24++) {
    m->data[m->size[0] * i24] = c_m->data[c_m->size[0] * i24];
  }

  emxFree_real_T(&c_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * function m = Mymedfilt1(s, w)
 */
void c_Mymedfilt1(const emlrtStack *sp, emxArray_real_T *s, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int32_T c_s;
  int32_T i36;
  int32_T loop_ub;
  emxArray_real_T *b_m;
  int32_T n;
  int32_T i37;
  int32_T i;
  emxArray_int32_T *r20;
  emxArray_real_T *r21;
  real_T d_s;
  real_T e_s;
  int32_T iv33[2];
  boolean_T overflow;
  int32_T b_i;
  int32_T c_i;
  int32_T idx[7];
  int32_T d_i;
  int32_T iwork[7];
  int32_T k;
  boolean_T p;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  real_T c_m;
  emxArray_real_T *d_m;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  jmp_buf b_emlrtJBEnviron;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &xb_emlrtRTEI, true);

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
  i36 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i36, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  for (i36 = 0; i36 < c_s; i36++) {
    b_s->data[b_s->size[0] * i36] = s->data[i36];
  }

  i36 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)s, i36, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = b_s->size[1];
  for (i36 = 0; i36 < loop_ub; i36++) {
    s->data[s->size[0] * i36] = b_s->data[b_s->size[0] * i36];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &b_m, 2, &yb_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  n = s->size[1];

  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i36 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 7;
  b_m->size[1] = (int32_T)(((real_T)s->size[1] + 7.0) - 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i36, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = 7 * (int32_T)(((real_T)s->size[1] + 7.0) - 1.0);
  for (i36 = 0; i36 < loop_ub; i36++) {
    b_m->data[i36] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i36 = s->size[1];
  if (!(1 <= i36)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i36, &ue_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:35' sl = s(n); */
  i36 = s->size[1];
  i37 = s->size[1];
  if (!((i37 >= 1) && (i37 <= i36))) {
    emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &ve_emlrtBCI, sp);
  }

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  i = 0;
  emxInit_int32_T(sp, &r20, 1, &xb_emlrtRTEI, true);
  emxInit_real_T(sp, &r21, 2, &xb_emlrtRTEI, true);
  while (i < 7) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = b_m->size[1];
    i36 = r20->size[0];
    r20->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r20, i36, (int32_T)sizeof(int32_T),
                      &xb_emlrtRTEI);
    for (i36 = 0; i36 < loop_ub; i36++) {
      r20->data[i36] = i36;
    }

    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    c_s = 6 - i;
    i36 = r21->size[0] * r21->size[1];
    r21->size[0] = 1;
    r21->size[1] = (i + s->size[1]) + c_s;
    emxEnsureCapacity(sp, (emxArray__common *)r21, i36, (int32_T)sizeof(real_T),
                      &xb_emlrtRTEI);
    for (i36 = 0; i36 < i; i36++) {
      r21->data[r21->size[0] * i36] = d_s;
    }

    loop_ub = s->size[1];
    for (i36 = 0; i36 < loop_ub; i36++) {
      r21->data[r21->size[0] * (i36 + i)] = s->data[s->size[0] * i36];
    }

    for (i36 = 0; i36 < c_s; i36++) {
      r21->data[r21->size[0] * ((i36 + i) + s->size[1])] = e_s;
    }

    iv33[0] = 1;
    iv33[1] = r20->size[0];
    emlrtSubAssignSizeCheckR2012b(iv33, 2, *(int32_T (*)[2])r21->size, 2,
      &jb_emlrtECI, sp);
    loop_ub = r21->size[1];
    for (i36 = 0; i36 < loop_ub; i36++) {
      b_m->data[i + b_m->size[0] * r20->data[i36]] = r21->data[r21->size[0] *
        i36];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r21);
  emxFree_int32_T(&r20);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &ah_emlrtRSI;
  i36 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = b_m->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)m, i36, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  c_s = b_m->size[1];
  b_st.site = &ch_emlrtRSI;
  if (1 > b_m->size[1]) {
    overflow = false;
  } else {
    overflow = (b_m->size[1] > 2147483646);
  }

  if (overflow) {
    c_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  emlrtEnterParallelRegion(&st, omp_in_parallel());
  emlrtPushJmpBuf(&st, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(c_i,d_i,k,p,i2,j,pEnd,b_p,q,qEnd,kEnd,c_m,b_emlrtJBEnviron) \
 firstprivate(d_st,st,idx,emlrtHadParallelError,iwork)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      d_st.prev = &st;
      d_st.tls = emlrtAllocTLS(&st, omp_get_thread_num());
      d_st.site = NULL;
      emlrtSetJmpBuf(&d_st, &b_emlrtJBEnviron);
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (b_i = 1; b_i <= c_s; b_i++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        c_i = b_i;
        for (d_i = 0; d_i < 7; d_i++) {
          idx[d_i] = 0;
        }

        for (k = 0; k <= 4; k += 2) {
          if ((b_m->data[k + b_m->size[0] * (c_i - 1)] <= b_m->data[(k +
                b_m->size[0] * (c_i - 1)) + 1]) || muDoubleScalarIsNaN(b_m->
               data[(k + b_m->size[0] * (c_i - 1)) + 1])) {
            p = true;
          } else {
            p = false;
          }

          if (p) {
            idx[k] = k + 1;
            idx[k + 1] = k + 2;
          } else {
            idx[k] = k + 2;
            idx[k + 1] = k + 1;
          }
        }

        idx[6] = 7;
        d_i = 2;
        while (d_i < 7) {
          i2 = d_i << 1;
          j = 1;
          for (pEnd = 1 + d_i; pEnd < 8; pEnd = qEnd + d_i) {
            b_p = j;
            q = pEnd - 1;
            qEnd = j + i2;
            if (qEnd > 8) {
              qEnd = 8;
            }

            k = 0;
            kEnd = qEnd - j;
            while (k + 1 <= kEnd) {
              if ((b_m->data[(idx[b_p - 1] + b_m->size[0] * (c_i - 1)) - 1] <=
                   b_m->data[(idx[q] + b_m->size[0] * (c_i - 1)) - 1]) ||
                  muDoubleScalarIsNaN(b_m->data[(idx[q] + b_m->size[0] * (c_i -
                     1)) - 1])) {
                p = true;
              } else {
                p = false;
              }

              if (p) {
                iwork[k] = idx[b_p - 1];
                b_p++;
                if (b_p == pEnd) {
                  while (q + 1 < qEnd) {
                    k++;
                    iwork[k] = idx[q];
                    q++;
                  }
                }
              } else {
                iwork[k] = idx[q];
                q++;
                if (q + 1 == qEnd) {
                  while (b_p < pEnd) {
                    k++;
                    iwork[k] = idx[b_p - 1];
                    b_p++;
                  }
                }
              }

              k++;
            }

            for (k = 0; k + 1 <= kEnd; k++) {
              idx[(j + k) - 1] = iwork[k];
            }

            j = qEnd;
          }

          d_i = i2;
        }

        if (muDoubleScalarIsNaN(b_m->data[(idx[6] + b_m->size[0] * (c_i - 1)) -
                                1])) {
          c_m = b_m->data[(idx[6] + b_m->size[0] * (c_i - 1)) - 1];
        } else {
          c_m = b_m->data[(idx[3] + b_m->size[0] * (c_i - 1)) - 1];
        }

        m->data[c_i - 1] = c_m;
      } else {
        emlrtHadParallelError = true;
      }
    }
  }

  emlrtPopJmpBuf(&st, &emlrtJBStack);
  emlrtExitParallelRegion(&st, omp_in_parallel());
  emxFree_real_T(&b_m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  if (4U > 3U + n) {
    i36 = 0;
    c_s = 0;
  } else {
    i36 = 3;
    i37 = m->size[1];
    c_s = (int32_T)(3U + n);
    if (!((c_s >= 1) && (c_s <= i37))) {
      emlrtDynamicBoundsCheckR2012b(c_s, 1, i37, &we_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &d_m, 2, &xb_emlrtRTEI, true);
  i37 = d_m->size[0] * d_m->size[1];
  d_m->size[0] = 1;
  d_m->size[1] = c_s - i36;
  emxEnsureCapacity(sp, (emxArray__common *)d_m, i37, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = c_s - i36;
  for (i37 = 0; i37 < loop_ub; i37++) {
    d_m->data[d_m->size[0] * i37] = m->data[i36 + i37];
  }

  i36 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = d_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i36, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  loop_ub = d_m->size[1];
  for (i36 = 0; i36 < loop_ub; i36++) {
    m->data[m->size[0] * i36] = d_m->data[d_m->size[0] * i36];
  }

  emxFree_real_T(&d_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mymedfilt1.c) */
