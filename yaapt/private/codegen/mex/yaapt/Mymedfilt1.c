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

/* Variable Definitions */
static emlrtRTEInfo ec_emlrtRTEI = { 24, 14, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

static emlrtRTEInfo kc_emlrtRTEI = { 24, 25, "Mymedfilt1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m" };

/* Function Definitions */

/*
 * function m = Mymedfilt1(s, w)
 */
void Mymedfilt1(const emlrtStack *sp, emxArray_real_T *s, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int32_T c_s;
  int32_T i22;
  int32_T loop_ub;
  emxArray_real_T *b_m;
  emxArray_int32_T *r11;
  emxArray_real_T *r12;
  int32_T i;
  real_T d_s;
  real_T e_s;
  int32_T iv55[2];
  emxArray_real_T *c_m;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &ec_emlrtRTEI, true);

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
  i22 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i22, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  for (i22 = 0; i22 < c_s; i22++) {
    b_s->data[b_s->size[0] * i22] = s->data[i22];
  }

  i22 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)s, i22, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  loop_ub = b_s->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    s->data[s->size[0] * i22] = b_s->data[b_s->size[0] * i22];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &b_m, 2, &d_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i22 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i22, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  c_s = (int32_T)(((real_T)s->size[1] + 5.0) - 1.0);
  i22 = b_m->size[0] * b_m->size[1];
  b_m->size[1] = c_s;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i22, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  loop_ub = 5 * (int32_T)(((real_T)s->size[1] + 5.0) - 1.0);
  for (i22 = 0; i22 < loop_ub; i22++) {
    b_m->data[i22] = 0.0;
  }

  emxInit_int32_T(sp, &r11, 1, &ec_emlrtRTEI, true);
  emxInit_real_T(sp, &r12, 2, &ec_emlrtRTEI, true);

  /* 'Mymedfilt1:35' s0 = s(1); */
  i22 = s->size[1];
  emlrtDynamicBoundsCheckFastR2012b(1, 1, i22, &c_emlrtBCI, sp);

  /* 'Mymedfilt1:35' sl = s(n); */
  i22 = s->size[1];
  i = s->size[1];
  emlrtDynamicBoundsCheckFastR2012b(i, 1, i22, &b_emlrtBCI, sp);

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  for (i = 0; i < 5; i++) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = b_m->size[1];
    i22 = r11->size[0];
    r11->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r11, i22, (int32_T)sizeof(int32_T),
                      &ec_emlrtRTEI);
    for (i22 = 0; i22 < loop_ub; i22++) {
      r11->data[i22] = i22;
    }

    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    c_s = 4 - i;
    i22 = r12->size[0] * r12->size[1];
    r12->size[0] = 1;
    r12->size[1] = (i + s->size[1]) + c_s;
    emxEnsureCapacity(sp, (emxArray__common *)r12, i22, (int32_T)sizeof(real_T),
                      &ec_emlrtRTEI);
    for (i22 = 0; i22 < i; i22++) {
      r12->data[r12->size[0] * i22] = d_s;
    }

    loop_ub = s->size[1];
    for (i22 = 0; i22 < loop_ub; i22++) {
      r12->data[r12->size[0] * (i22 + i)] = s->data[s->size[0] * i22];
    }

    for (i22 = 0; i22 < c_s; i22++) {
      r12->data[r12->size[0] * ((i22 + i) + s->size[1])] = e_s;
    }

    iv55[0] = 1;
    iv55[1] = r11->size[0];
    emlrtSubAssignSizeCheckR2012b(iv55, 2, *(int32_T (*)[2])r12->size, 2,
      &emlrtECI, sp);
    loop_ub = r12->size[1];
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_m->data[i + b_m->size[0] * r11->data[i22]] = r12->data[r12->size[0] *
        i22];
    }

    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&r12);
  emxFree_int32_T(&r11);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &ig_emlrtRSI;
  median(&st, b_m, m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  emxFree_real_T(&b_m);
  if (3U > 2U + s->size[1]) {
    i22 = 0;
    i = 0;
  } else {
    i22 = 2;
    i = m->size[1];
    c_s = (int32_T)(2U + s->size[1]);
    i = emlrtDynamicBoundsCheckFastR2012b(c_s, 1, i, &emlrtBCI, sp);
  }

  emxInit_real_T(sp, &c_m, 2, &ec_emlrtRTEI, true);
  c_s = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = i - i22;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, c_s, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  loop_ub = i - i22;
  for (i = 0; i < loop_ub; i++) {
    c_m->data[c_m->size[0] * i] = m->data[i22 + i];
  }

  i22 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i22, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    m->data[m->size[0] * i22] = c_m->data[c_m->size[0] * i22];
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
  int32_T i26;
  emxArray_real_T *b_m;
  int32_T loop_ub;
  emxArray_int32_T *r13;
  emxArray_real_T *r14;
  int32_T i;
  real_T c_s;
  real_T d_s;
  int32_T iv58[2];
  emxArray_real_T *c_m;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_s, 2, &kc_emlrtRTEI, true);

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
  i26 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)b_s, i26, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  for (i26 = 0; i26 < s_idx_0; i26++) {
    b_s->data[b_s->size[0] * i26] = s->data[i26];
  }

  emxInit_real_T(sp, &b_m, 2, &d_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i26 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i26, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  s_idx_0 = (int32_T)(((real_T)b_s->size[1] + 5.0) - 1.0);
  i26 = b_m->size[0] * b_m->size[1];
  b_m->size[1] = s_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i26, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  loop_ub = 5 * (int32_T)(((real_T)b_s->size[1] + 5.0) - 1.0);
  for (i26 = 0; i26 < loop_ub; i26++) {
    b_m->data[i26] = 0.0;
  }

  emxInit_int32_T(sp, &r13, 1, &ec_emlrtRTEI, true);
  emxInit_real_T(sp, &r14, 2, &ec_emlrtRTEI, true);

  /* 'Mymedfilt1:35' s0 = s(1); */
  i26 = b_s->size[1];
  emlrtDynamicBoundsCheckFastR2012b(1, 1, i26, &c_emlrtBCI, sp);

  /* 'Mymedfilt1:35' sl = s(n); */
  i26 = b_s->size[1];
  i = b_s->size[1];
  emlrtDynamicBoundsCheckFastR2012b(i, 1, i26, &b_emlrtBCI, sp);

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  for (i = 0; i < 5; i++) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = b_m->size[1];
    i26 = r13->size[0];
    r13->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r13, i26, (int32_T)sizeof(int32_T),
                      &ec_emlrtRTEI);
    for (i26 = 0; i26 < loop_ub; i26++) {
      r13->data[i26] = i26;
    }

    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    s_idx_0 = 4 - i;
    i26 = r14->size[0] * r14->size[1];
    r14->size[0] = 1;
    r14->size[1] = (i + b_s->size[1]) + s_idx_0;
    emxEnsureCapacity(sp, (emxArray__common *)r14, i26, (int32_T)sizeof(real_T),
                      &ec_emlrtRTEI);
    for (i26 = 0; i26 < i; i26++) {
      r14->data[r14->size[0] * i26] = c_s;
    }

    loop_ub = b_s->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      r14->data[r14->size[0] * (i26 + i)] = b_s->data[b_s->size[0] * i26];
    }

    for (i26 = 0; i26 < s_idx_0; i26++) {
      r14->data[r14->size[0] * ((i26 + i) + b_s->size[1])] = d_s;
    }

    iv58[0] = 1;
    iv58[1] = r13->size[0];
    emlrtSubAssignSizeCheckR2012b(iv58, 2, *(int32_T (*)[2])r14->size, 2,
      &emlrtECI, sp);
    loop_ub = r14->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      b_m->data[i + b_m->size[0] * r13->data[i26]] = r14->data[r14->size[0] *
        i26];
    }

    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&r14);
  emxFree_int32_T(&r13);

  /* 'Mymedfilt1:40' m = median(m); */
  st.site = &ig_emlrtRSI;
  median(&st, b_m, m);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  emxFree_real_T(&b_m);
  if (3U > 2U + b_s->size[1]) {
    i26 = 0;
    i = 0;
  } else {
    i26 = 2;
    i = m->size[1];
    s_idx_0 = (int32_T)(2U + b_s->size[1]);
    i = emlrtDynamicBoundsCheckFastR2012b(s_idx_0, 1, i, &emlrtBCI, sp);
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(sp, &c_m, 2, &ec_emlrtRTEI, true);
  s_idx_0 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = i - i26;
  emxEnsureCapacity(sp, (emxArray__common *)c_m, s_idx_0, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  loop_ub = i - i26;
  for (i = 0; i < loop_ub; i++) {
    c_m->data[c_m->size[0] * i] = m->data[i26 + i];
  }

  i26 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)m, i26, (int32_T)sizeof(real_T),
                    &ec_emlrtRTEI);
  loop_ub = c_m->size[1];
  for (i26 = 0; i26 < loop_ub; i26++) {
    m->data[m->size[0] * i26] = c_m->data[c_m->size[0] * i26];
  }

  emxFree_real_T(&c_m);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Mymedfilt1.c) */
