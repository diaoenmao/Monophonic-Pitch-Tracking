/*
 * File: Mymedfilt1.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 18-Feb-2016 02:50:10
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
  int i20;
  emxArray_real_T *b_m;
  double w2;
  int i;
  emxArray_real_T *b;
  double d_s;
  double e_s;
  emxArray_real_T *c_m;
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
  i20 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity((emxArray__common *)b_s, i20, (int)sizeof(double));
  for (i20 = 0; i20 < c_s; i20++) {
    b_s->data[b_s->size[0] * i20] = s->data[i20];
  }

  i20 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity((emxArray__common *)s, i20, (int)sizeof(double));
  c_s = b_s->size[1];
  for (i20 = 0; i20 < c_s; i20++) {
    s->data[s->size[0] * i20] = b_s->data[b_s->size[0] * i20];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&b_m, 2);
  w2 = floor(w / 2.0);
  w = 2.0 * w2 + 1.0;
  i20 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = (int)w;
  b_m->size[1] = (int)(((double)s->size[1] + w) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i20, (int)sizeof(double));
  c_s = (int)w * (int)(((double)s->size[1] + w) - 1.0);
  for (i20 = 0; i20 < c_s; i20++) {
    b_m->data[i20] = 0.0;
  }

  i = 0;
  emxInit_real_T(&b, 2);
  while (i <= (int)((w - 1.0) + 1.0) - 1) {
    i20 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = (int)((w - (double)i) - 1.0);
    emxEnsureCapacity((emxArray__common *)b, i20, (int)sizeof(double));
    c_s = (int)((w - (double)i) - 1.0);
    for (i20 = 0; i20 < c_s; i20++) {
      b->data[i20] = 1.0;
    }

    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    for (i20 = 0; i20 < i; i20++) {
      b_m->data[i + b_m->size[0] * i20] = d_s;
    }

    c_s = s->size[1];
    for (i20 = 0; i20 < c_s; i20++) {
      b_m->data[i + b_m->size[0] * (i20 + i)] = s->data[s->size[0] * i20];
    }

    c_s = b->size[1];
    for (i20 = 0; i20 < c_s; i20++) {
      b_m->data[i + b_m->size[0] * ((i20 + i) + s->size[1])] = e_s * b->data
        [b->size[0] * i20];
    }

    i++;
  }

  emxFree_real_T(&b);
  emxInit_real_T(&c_m, 2);
  median(b_m, m);
  i20 = s->size[1];
  c_s = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = (int)((double)i20 - 1.0) + 1;
  emxEnsureCapacity((emxArray__common *)c_m, c_s, (int)sizeof(double));
  c_s = (int)((double)i20 - 1.0);
  emxFree_real_T(&b_m);
  for (i20 = 0; i20 <= c_s; i20++) {
    c_m->data[c_m->size[0] * i20] = m->data[(int)(w2 + (double)(i20 + 1)) - 1];
  }

  i20 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i20, (int)sizeof(double));
  c_s = c_m->size[1];
  for (i20 = 0; i20 < c_s; i20++) {
    m->data[m->size[0] * i20] = c_m->data[c_m->size[0] * i20];
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
  int i23;
  emxArray_real_T *b_m;
  double w2;
  int i;
  emxArray_real_T *b;
  double c_s;
  double d_s;
  emxArray_real_T *c_m;
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
  i23 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity((emxArray__common *)b_s, i23, (int)sizeof(double));
  for (i23 = 0; i23 < s_idx_0; i23++) {
    b_s->data[b_s->size[0] * i23] = s->data[i23];
  }

  emxInit_real_T(&b_m, 2);
  w2 = floor(w / 2.0);
  w = 2.0 * w2 + 1.0;
  i23 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = (int)w;
  b_m->size[1] = (int)(((double)b_s->size[1] + w) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i23, (int)sizeof(double));
  s_idx_0 = (int)w * (int)(((double)b_s->size[1] + w) - 1.0);
  for (i23 = 0; i23 < s_idx_0; i23++) {
    b_m->data[i23] = 0.0;
  }

  i = 0;
  emxInit_real_T(&b, 2);
  while (i <= (int)((w - 1.0) + 1.0) - 1) {
    i23 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = (int)((w - (double)i) - 1.0);
    emxEnsureCapacity((emxArray__common *)b, i23, (int)sizeof(double));
    s_idx_0 = (int)((w - (double)i) - 1.0);
    for (i23 = 0; i23 < s_idx_0; i23++) {
      b->data[i23] = 1.0;
    }

    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    for (i23 = 0; i23 < i; i23++) {
      b_m->data[i + b_m->size[0] * i23] = c_s;
    }

    s_idx_0 = b_s->size[1];
    for (i23 = 0; i23 < s_idx_0; i23++) {
      b_m->data[i + b_m->size[0] * (i23 + i)] = b_s->data[b_s->size[0] * i23];
    }

    s_idx_0 = b->size[1];
    for (i23 = 0; i23 < s_idx_0; i23++) {
      b_m->data[i + b_m->size[0] * ((i23 + i) + b_s->size[1])] = d_s * b->data
        [b->size[0] * i23];
    }

    i++;
  }

  emxFree_real_T(&b);
  emxInit_real_T(&c_m, 2);
  median(b_m, m);
  i23 = b_s->size[1];
  s_idx_0 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = (int)((double)i23 - 1.0) + 1;
  emxEnsureCapacity((emxArray__common *)c_m, s_idx_0, (int)sizeof(double));
  s_idx_0 = (int)((double)i23 - 1.0);
  emxFree_real_T(&b_m);
  emxFree_real_T(&b_s);
  for (i23 = 0; i23 <= s_idx_0; i23++) {
    c_m->data[c_m->size[0] * i23] = m->data[(int)(w2 + (double)(i23 + 1)) - 1];
  }

  i23 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i23, (int)sizeof(double));
  s_idx_0 = c_m->size[1];
  for (i23 = 0; i23 < s_idx_0; i23++) {
    m->data[m->size[0] * i23] = c_m->data[c_m->size[0] * i23];
  }

  emxFree_real_T(&c_m);
}

/*
 * File trailer for Mymedfilt1.c
 *
 * [EOF]
 */
