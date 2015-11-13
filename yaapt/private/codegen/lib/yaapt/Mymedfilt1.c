/*
 * File: Mymedfilt1.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Mymedfilt1.h"
#include "yaapt_emxutil.h"
#include "median.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *s
 *                emxArray_real_T *m
 * Return Type  : void
 */
void Mymedfilt1(emxArray_real_T *s, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int c_s;
  int i11;
  int loop_ub;
  emxArray_real_T *b_m;
  double d_s;
  double e_s;
  int i12;
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
  i11 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity((emxArray__common *)b_s, i11, (int)sizeof(double));
  for (i11 = 0; i11 < c_s; i11++) {
    b_s->data[b_s->size[0] * i11] = s->data[i11];
  }

  i11 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity((emxArray__common *)s, i11, (int)sizeof(double));
  loop_ub = b_s->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    s->data[s->size[0] * i11] = b_s->data[b_s->size[0] * i11];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&b_m, 2);
  i11 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  emxEnsureCapacity((emxArray__common *)b_m, i11, (int)sizeof(double));
  c_s = (int)(((double)s->size[1] + 5.0) - 1.0);
  i11 = b_m->size[0] * b_m->size[1];
  b_m->size[1] = c_s;
  emxEnsureCapacity((emxArray__common *)b_m, i11, (int)sizeof(double));
  loop_ub = 5 * (int)(((double)s->size[1] + 5.0) - 1.0);
  for (i11 = 0; i11 < loop_ub; i11++) {
    b_m->data[i11] = 0.0;
  }

  for (c_s = 0; c_s < 5; c_s++) {
    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    for (i11 = 0; i11 < c_s; i11++) {
      b_m->data[c_s + b_m->size[0] * i11] = d_s;
    }

    loop_ub = s->size[1];
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_m->data[c_s + b_m->size[0] * (i11 + c_s)] = s->data[s->size[0] * i11];
    }

    loop_ub = 4 - c_s;
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_m->data[c_s + b_m->size[0] * ((i11 + c_s) + s->size[1])] = e_s;
    }
  }

  median(b_m, m);
  emxFree_real_T(&b_m);
  if (3U > 2U + s->size[1]) {
    i11 = 0;
    i12 = 0;
  } else {
    i11 = 2;
    i12 = (int)(2U + s->size[1]);
  }

  emxInit_real_T(&c_m, 2);
  c_s = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = i12 - i11;
  emxEnsureCapacity((emxArray__common *)c_m, c_s, (int)sizeof(double));
  loop_ub = i12 - i11;
  for (i12 = 0; i12 < loop_ub; i12++) {
    c_m->data[c_m->size[0] * i12] = m->data[i11 + i12];
  }

  i11 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i11, (int)sizeof(double));
  loop_ub = c_m->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    m->data[m->size[0] * i11] = c_m->data[c_m->size[0] * i11];
  }

  emxFree_real_T(&c_m);
}

/*
 * Arguments    : const emxArray_real_T *s
 *                emxArray_real_T *m
 * Return Type  : void
 */
void b_Mymedfilt1(const emxArray_real_T *s, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int s_idx_0;
  int i13;
  emxArray_real_T *b_m;
  int loop_ub;
  double c_s;
  double d_s;
  int i14;
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
  i13 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity((emxArray__common *)b_s, i13, (int)sizeof(double));
  for (i13 = 0; i13 < s_idx_0; i13++) {
    b_s->data[b_s->size[0] * i13] = s->data[i13];
  }

  emxInit_real_T(&b_m, 2);
  i13 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  emxEnsureCapacity((emxArray__common *)b_m, i13, (int)sizeof(double));
  s_idx_0 = (int)(((double)b_s->size[1] + 5.0) - 1.0);
  i13 = b_m->size[0] * b_m->size[1];
  b_m->size[1] = s_idx_0;
  emxEnsureCapacity((emxArray__common *)b_m, i13, (int)sizeof(double));
  loop_ub = 5 * (int)(((double)b_s->size[1] + 5.0) - 1.0);
  for (i13 = 0; i13 < loop_ub; i13++) {
    b_m->data[i13] = 0.0;
  }

  for (s_idx_0 = 0; s_idx_0 < 5; s_idx_0++) {
    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    for (i13 = 0; i13 < s_idx_0; i13++) {
      b_m->data[s_idx_0 + b_m->size[0] * i13] = c_s;
    }

    loop_ub = b_s->size[1];
    for (i13 = 0; i13 < loop_ub; i13++) {
      b_m->data[s_idx_0 + b_m->size[0] * (i13 + s_idx_0)] = b_s->data[b_s->size
        [0] * i13];
    }

    loop_ub = 4 - s_idx_0;
    for (i13 = 0; i13 < loop_ub; i13++) {
      b_m->data[s_idx_0 + b_m->size[0] * ((i13 + s_idx_0) + b_s->size[1])] = d_s;
    }
  }

  median(b_m, m);
  emxFree_real_T(&b_m);
  if (3U > 2U + b_s->size[1]) {
    i13 = 0;
    i14 = 0;
  } else {
    i13 = 2;
    i14 = (int)(2U + b_s->size[1]);
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&c_m, 2);
  s_idx_0 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = i14 - i13;
  emxEnsureCapacity((emxArray__common *)c_m, s_idx_0, (int)sizeof(double));
  loop_ub = i14 - i13;
  for (i14 = 0; i14 < loop_ub; i14++) {
    c_m->data[c_m->size[0] * i14] = m->data[i13 + i14];
  }

  i13 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i13, (int)sizeof(double));
  loop_ub = c_m->size[1];
  for (i13 = 0; i13 < loop_ub; i13++) {
    m->data[m->size[0] * i13] = c_m->data[c_m->size[0] * i13];
  }

  emxFree_real_T(&c_m);
}

/*
 * Arguments    : emxArray_real_T *s
 *                emxArray_real_T *m
 * Return Type  : void
 */
void c_Mymedfilt1(emxArray_real_T *s, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int i1;
  int j;
  emxArray_real_T *b_m;
  int i;
  double c_s;
  double d_s;
  unsigned int sz[2];
  int i2;
  int iy;
  double vwork[7];
  int k;
  signed char idx[7];
  boolean_T p;
  signed char idx0[7];
  int b_i;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
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
  i1 = s->size[1];
  j = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = i1;
  emxEnsureCapacity((emxArray__common *)b_s, j, (int)sizeof(double));
  for (j = 0; j < i1; j++) {
    b_s->data[b_s->size[0] * j] = s->data[j];
  }

  j = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity((emxArray__common *)s, j, (int)sizeof(double));
  i1 = b_s->size[1];
  for (j = 0; j < i1; j++) {
    s->data[s->size[0] * j] = b_s->data[b_s->size[0] * j];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&b_m, 2);
  j = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 7;
  emxEnsureCapacity((emxArray__common *)b_m, j, (int)sizeof(double));
  i1 = (int)(((double)s->size[1] + 7.0) - 1.0);
  j = b_m->size[0] * b_m->size[1];
  b_m->size[1] = i1;
  emxEnsureCapacity((emxArray__common *)b_m, j, (int)sizeof(double));
  i1 = 7 * (int)(((double)s->size[1] + 7.0) - 1.0);
  for (j = 0; j < i1; j++) {
    b_m->data[j] = 0.0;
  }

  for (i = 0; i < 7; i++) {
    c_s = s->data[0];
    d_s = s->data[s->size[1] - 1];
    for (j = 0; j < i; j++) {
      b_m->data[i + b_m->size[0] * j] = c_s;
    }

    i1 = s->size[1];
    for (j = 0; j < i1; j++) {
      b_m->data[i + b_m->size[0] * (j + i)] = s->data[s->size[0] * j];
    }

    i1 = 6 - i;
    for (j = 0; j < i1; j++) {
      b_m->data[i + b_m->size[0] * ((j + i) + s->size[1])] = d_s;
    }
  }

  for (j = 0; j < 2; j++) {
    sz[j] = (unsigned int)b_m->size[j];
  }

  j = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = (int)sz[1];
  emxEnsureCapacity((emxArray__common *)m, j, (int)sizeof(double));
  i2 = 0;
  iy = -1;
  for (i = 1; i <= b_m->size[1]; i++) {
    i1 = i2;
    i2 += 7;
    for (k = 0; k < 7; k++) {
      vwork[k] = b_m->data[i1];
      i1++;
    }

    iy++;
    for (k = 0; k < 7; k++) {
      idx[k] = (signed char)(k + 1);
    }

    for (k = 0; k < 5; k += 2) {
      if ((vwork[k] <= vwork[k + 1]) || rtIsNaN(vwork[k + 1])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
      } else {
        idx[k] = (signed char)(k + 2);
        idx[k + 1] = (signed char)(k + 1);
      }
    }

    for (b_i = 0; b_i < 7; b_i++) {
      idx0[b_i] = 1;
    }

    b_i = 2;
    while (b_i < 7) {
      i1 = b_i << 1;
      j = 1;
      for (pEnd = 1 + b_i; pEnd < 8; pEnd = qEnd + b_i) {
        b_p = j;
        q = pEnd - 1;
        qEnd = j + i1;
        if (qEnd > 8) {
          qEnd = 8;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((vwork[idx[b_p - 1] - 1] <= vwork[idx[q] - 1]) || rtIsNaN
              (vwork[idx[q] - 1])) {
            p = true;
          } else {
            p = false;
          }

          if (p) {
            idx0[k] = idx[b_p - 1];
            b_p++;
            if (b_p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                idx0[k] = idx[q];
                q++;
              }
            }
          } else {
            idx0[k] = idx[q];
            q++;
            if (q + 1 == qEnd) {
              while (b_p < pEnd) {
                k++;
                idx0[k] = idx[b_p - 1];
                b_p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k + 1 <= kEnd; k++) {
          idx[(j + k) - 1] = idx0[k];
        }

        j = qEnd;
      }

      b_i = i1;
    }

    if (rtIsNaN(vwork[idx[6] - 1])) {
      m->data[iy] = vwork[idx[6] - 1];
    } else {
      m->data[iy] = vwork[idx[3] - 1];
    }
  }

  emxFree_real_T(&b_m);
  if (4U > 3U + s->size[1]) {
    j = 0;
    b_i = 0;
  } else {
    j = 3;
    b_i = (int)(3U + s->size[1]);
  }

  emxInit_real_T(&c_m, 2);
  i1 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = b_i - j;
  emxEnsureCapacity((emxArray__common *)c_m, i1, (int)sizeof(double));
  i1 = b_i - j;
  for (b_i = 0; b_i < i1; b_i++) {
    c_m->data[c_m->size[0] * b_i] = m->data[j + b_i];
  }

  j = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, j, (int)sizeof(double));
  i1 = c_m->size[1];
  for (j = 0; j < i1; j++) {
    m->data[m->size[0] * j] = c_m->data[c_m->size[0] * j];
  }

  emxFree_real_T(&c_m);
}

/*
 * File trailer for Mymedfilt1.c
 *
 * [EOF]
 */
