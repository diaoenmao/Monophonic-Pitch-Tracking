/*
 * File: Mymedfilt1.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Mymedfilt1.h"
#include "yaapt_emxutil.h"
#include "median.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *s
 *                double w
 *                emxArray_real_T *m
 * Return Type  : void
 */
void Mymedfilt1(emxArray_real_T *s, double w, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int c_s;
  int i21;
  emxArray_real_T *b_m;
  double w2;
  int i;
  emxArray_real_T *b;
  emxArray_real_T *c_m;
  double d_s;
  double e_s;
  emxInit_real_T(&b_s, 2);

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
  c_s = s->size[1];
  i21 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity((emxArray__common *)b_s, i21, (int)sizeof(double));
  for (i21 = 0; i21 < c_s; i21++) {
    b_s->data[b_s->size[0] * i21] = s->data[i21];
  }

  i21 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity((emxArray__common *)s, i21, (int)sizeof(double));
  c_s = b_s->size[1];
  for (i21 = 0; i21 < c_s; i21++) {
    s->data[s->size[0] * i21] = b_s->data[b_s->size[0] * i21];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&b_m, 2);
  w2 = floor(w / 2.0);
  w = 2.0 * w2 + 1.0;
  i21 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = (int)w;
  b_m->size[1] = (int)(((double)s->size[1] + w) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i21, (int)sizeof(double));
  c_s = (int)w * (int)(((double)s->size[1] + w) - 1.0);
  for (i21 = 0; i21 < c_s; i21++) {
    b_m->data[i21] = 0.0;
  }

  i = 0;
  emxInit_real_T(&b, 2);
  while (i <= (int)((w - 1.0) + 1.0) - 1) {
    i21 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = (int)((w - (double)i) - 1.0);
    emxEnsureCapacity((emxArray__common *)b, i21, (int)sizeof(double));
    c_s = (int)((w - (double)i) - 1.0);
    for (i21 = 0; i21 < c_s; i21++) {
      b->data[i21] = 1.0;
    }

    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    for (i21 = 0; i21 < i; i21++) {
      b_m->data[i + b_m->size[0] * i21] = d_s;
    }

    c_s = s->size[1];
    for (i21 = 0; i21 < c_s; i21++) {
      b_m->data[i + b_m->size[0] * (i21 + i)] = s->data[s->size[0] * i21];
    }

    c_s = b->size[1];
    for (i21 = 0; i21 < c_s; i21++) {
      b_m->data[i + b_m->size[0] * ((i21 + i) + s->size[1])] = e_s * b->data
        [b->size[0] * i21];
    }

    i++;
  }

  emxFree_real_T(&b);
  emxInit_real_T(&c_m, 2);
  median(b_m, m);
  i21 = s->size[1];
  c_s = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = (int)((double)i21 - 1.0) + 1;
  emxEnsureCapacity((emxArray__common *)c_m, c_s, (int)sizeof(double));
  c_s = (int)((double)i21 - 1.0);
  emxFree_real_T(&b_m);
  for (i21 = 0; i21 <= c_s; i21++) {
    c_m->data[c_m->size[0] * i21] = m->data[(int)(w2 + (double)(i21 + 1)) - 1];
  }

  i21 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i21, (int)sizeof(double));
  c_s = c_m->size[1];
  for (i21 = 0; i21 < c_s; i21++) {
    m->data[m->size[0] * i21] = c_m->data[c_m->size[0] * i21];
  }

  emxFree_real_T(&c_m);
}

/*
 * Arguments    : const emxArray_real_T *s
 *                double w
 *                emxArray_real_T *m
 * Return Type  : void
 */
void b_Mymedfilt1(const emxArray_real_T *s, double w, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int s_idx_0;
  int i24;
  emxArray_real_T *b_m;
  double w2;
  int i;
  emxArray_real_T *b;
  emxArray_real_T *c_m;
  double c_s;
  double d_s;
  emxInit_real_T(&b_s, 2);

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
  s_idx_0 = s->size[1];
  i24 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity((emxArray__common *)b_s, i24, (int)sizeof(double));
  for (i24 = 0; i24 < s_idx_0; i24++) {
    b_s->data[b_s->size[0] * i24] = s->data[i24];
  }

  emxInit_real_T(&b_m, 2);
  w2 = floor(w / 2.0);
  w = 2.0 * w2 + 1.0;
  i24 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = (int)w;
  b_m->size[1] = (int)(((double)b_s->size[1] + w) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i24, (int)sizeof(double));
  s_idx_0 = (int)w * (int)(((double)b_s->size[1] + w) - 1.0);
  for (i24 = 0; i24 < s_idx_0; i24++) {
    b_m->data[i24] = 0.0;
  }

  i = 0;
  emxInit_real_T(&b, 2);
  while (i <= (int)((w - 1.0) + 1.0) - 1) {
    i24 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = (int)((w - (double)i) - 1.0);
    emxEnsureCapacity((emxArray__common *)b, i24, (int)sizeof(double));
    s_idx_0 = (int)((w - (double)i) - 1.0);
    for (i24 = 0; i24 < s_idx_0; i24++) {
      b->data[i24] = 1.0;
    }

    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    for (i24 = 0; i24 < i; i24++) {
      b_m->data[i + b_m->size[0] * i24] = c_s;
    }

    s_idx_0 = b_s->size[1];
    for (i24 = 0; i24 < s_idx_0; i24++) {
      b_m->data[i + b_m->size[0] * (i24 + i)] = b_s->data[b_s->size[0] * i24];
    }

    s_idx_0 = b->size[1];
    for (i24 = 0; i24 < s_idx_0; i24++) {
      b_m->data[i + b_m->size[0] * ((i24 + i) + b_s->size[1])] = d_s * b->data
        [b->size[0] * i24];
    }

    i++;
  }

  emxFree_real_T(&b);
  emxInit_real_T(&c_m, 2);
  median(b_m, m);
  i24 = b_s->size[1];
  s_idx_0 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = (int)((double)i24 - 1.0) + 1;
  emxEnsureCapacity((emxArray__common *)c_m, s_idx_0, (int)sizeof(double));
  s_idx_0 = (int)((double)i24 - 1.0);
  emxFree_real_T(&b_m);
  emxFree_real_T(&b_s);
  for (i24 = 0; i24 <= s_idx_0; i24++) {
    c_m->data[c_m->size[0] * i24] = m->data[(int)(w2 + (double)(i24 + 1)) - 1];
  }

  i24 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i24, (int)sizeof(double));
  s_idx_0 = c_m->size[1];
  for (i24 = 0; i24 < s_idx_0; i24++) {
    m->data[m->size[0] * i24] = c_m->data[c_m->size[0] * i24];
  }

  emxFree_real_T(&c_m);
}

/*
 * File trailer for Mymedfilt1.c
 *
 * [EOF]
 */
