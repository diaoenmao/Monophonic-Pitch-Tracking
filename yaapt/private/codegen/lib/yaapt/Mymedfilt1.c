/*
 * File: Mymedfilt1.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Jan-2016 05:43:25
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
 *                emxArray_real_T *m
 * Return Type  : void
 */
void Mymedfilt1(emxArray_real_T *s, emxArray_real_T *m)
{
  emxArray_real_T *b_s;
  int c_s;
  int i13;
  emxArray_real_T *b_m;
  int i;
  double d_s;
  double e_s;
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
  c_s = s->size[1];
  i13 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity((emxArray__common *)b_s, i13, (int)sizeof(double));
  for (i13 = 0; i13 < c_s; i13++) {
    b_s->data[b_s->size[0] * i13] = s->data[i13];
  }

  i13 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity((emxArray__common *)s, i13, (int)sizeof(double));
  c_s = b_s->size[1];
  for (i13 = 0; i13 < c_s; i13++) {
    s->data[s->size[0] * i13] = b_s->data[b_s->size[0] * i13];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&b_m, 2);
  i13 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  b_m->size[1] = (int)(((double)s->size[1] + 5.0) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i13, (int)sizeof(double));
  c_s = 5 * (int)(((double)s->size[1] + 5.0) - 1.0);
  for (i13 = 0; i13 < c_s; i13++) {
    b_m->data[i13] = 0.0;
  }

  for (i = 0; i < 5; i++) {
    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    for (i13 = 0; i13 < i; i13++) {
      b_m->data[i + b_m->size[0] * i13] = d_s;
    }

    c_s = s->size[1];
    for (i13 = 0; i13 < c_s; i13++) {
      b_m->data[i + b_m->size[0] * (i13 + i)] = s->data[s->size[0] * i13];
    }

    c_s = 4 - i;
    for (i13 = 0; i13 < c_s; i13++) {
      b_m->data[i + b_m->size[0] * ((i13 + i) + s->size[1])] = e_s;
    }
  }

  median(b_m, m);
  emxFree_real_T(&b_m);
  if (3U > 2U + s->size[1]) {
    i13 = 0;
    i14 = 0;
  } else {
    i13 = 2;
    i14 = (int)(2U + s->size[1]);
  }

  emxInit_real_T(&c_m, 2);
  c_s = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = i14 - i13;
  emxEnsureCapacity((emxArray__common *)c_m, c_s, (int)sizeof(double));
  c_s = i14 - i13;
  for (i14 = 0; i14 < c_s; i14++) {
    c_m->data[c_m->size[0] * i14] = m->data[i13 + i14];
  }

  i13 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i13, (int)sizeof(double));
  c_s = c_m->size[1];
  for (i13 = 0; i13 < c_s; i13++) {
    m->data[m->size[0] * i13] = c_m->data[c_m->size[0] * i13];
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
  int i15;
  emxArray_real_T *b_m;
  int i;
  double c_s;
  double d_s;
  int i16;
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
  i15 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity((emxArray__common *)b_s, i15, (int)sizeof(double));
  for (i15 = 0; i15 < s_idx_0; i15++) {
    b_s->data[b_s->size[0] * i15] = s->data[i15];
  }

  emxInit_real_T(&b_m, 2);
  i15 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  b_m->size[1] = (int)(((double)b_s->size[1] + 5.0) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i15, (int)sizeof(double));
  s_idx_0 = 5 * (int)(((double)b_s->size[1] + 5.0) - 1.0);
  for (i15 = 0; i15 < s_idx_0; i15++) {
    b_m->data[i15] = 0.0;
  }

  for (i = 0; i < 5; i++) {
    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    for (i15 = 0; i15 < i; i15++) {
      b_m->data[i + b_m->size[0] * i15] = c_s;
    }

    s_idx_0 = b_s->size[1];
    for (i15 = 0; i15 < s_idx_0; i15++) {
      b_m->data[i + b_m->size[0] * (i15 + i)] = b_s->data[b_s->size[0] * i15];
    }

    s_idx_0 = 4 - i;
    for (i15 = 0; i15 < s_idx_0; i15++) {
      b_m->data[i + b_m->size[0] * ((i15 + i) + b_s->size[1])] = d_s;
    }
  }

  median(b_m, m);
  emxFree_real_T(&b_m);
  if (3U > 2U + b_s->size[1]) {
    i15 = 0;
    i16 = 0;
  } else {
    i15 = 2;
    i16 = (int)(2U + b_s->size[1]);
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&c_m, 2);
  s_idx_0 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = i16 - i15;
  emxEnsureCapacity((emxArray__common *)c_m, s_idx_0, (int)sizeof(double));
  s_idx_0 = i16 - i15;
  for (i16 = 0; i16 < s_idx_0; i16++) {
    c_m->data[c_m->size[0] * i16] = m->data[i15 + i16];
  }

  i15 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i15, (int)sizeof(double));
  s_idx_0 = c_m->size[1];
  for (i15 = 0; i15 < s_idx_0; i15++) {
    m->data[m->size[0] * i15] = c_m->data[c_m->size[0] * i15];
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
  int c_s;
  int i22;
  emxArray_real_T *b_m;
  int n;
  int i;
  double d_s;
  double e_s;
  int b_i;
  int c_i;
  int idx[7];
  int d_i;
  int iwork[7];
  int k;
  boolean_T p;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  double c_m;
  int i23;
  emxArray_real_T *d_m;
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
  i22 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity((emxArray__common *)b_s, i22, (int)sizeof(double));
  for (i22 = 0; i22 < c_s; i22++) {
    b_s->data[b_s->size[0] * i22] = s->data[i22];
  }

  i22 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity((emxArray__common *)s, i22, (int)sizeof(double));
  c_s = b_s->size[1];
  for (i22 = 0; i22 < c_s; i22++) {
    s->data[s->size[0] * i22] = b_s->data[b_s->size[0] * i22];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&b_m, 2);
  n = s->size[1];
  i22 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 7;
  b_m->size[1] = (int)(((double)s->size[1] + 7.0) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i22, (int)sizeof(double));
  c_s = 7 * (int)(((double)s->size[1] + 7.0) - 1.0);
  for (i22 = 0; i22 < c_s; i22++) {
    b_m->data[i22] = 0.0;
  }

  for (i = 0; i < 7; i++) {
    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    for (i22 = 0; i22 < i; i22++) {
      b_m->data[i + b_m->size[0] * i22] = d_s;
    }

    c_s = s->size[1];
    for (i22 = 0; i22 < c_s; i22++) {
      b_m->data[i + b_m->size[0] * (i22 + i)] = s->data[s->size[0] * i22];
    }

    c_s = 6 - i;
    for (i22 = 0; i22 < c_s; i22++) {
      b_m->data[i + b_m->size[0] * ((i22 + i) + s->size[1])] = e_s;
    }
  }

  i22 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = b_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i22, (int)sizeof(double));
  c_s = b_m->size[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_i,d_i,k,p,i2,j,pEnd,b_p,q,qEnd,kEnd,c_m) \
 firstprivate(idx,iwork)

  for (b_i = 1; b_i <= c_s; b_i++) {
    c_i = b_i;
    for (d_i = 0; d_i < 7; d_i++) {
      idx[d_i] = 0;
    }

    for (k = 0; k <= 4; k += 2) {
      if ((b_m->data[k + b_m->size[0] * (c_i - 1)] <= b_m->data[(k + b_m->size[0]
            * (c_i - 1)) + 1]) || rtIsNaN(b_m->data[(k + b_m->size[0] * (c_i - 1))
           + 1])) {
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
               b_m->data[(idx[q] + b_m->size[0] * (c_i - 1)) - 1]) || rtIsNaN
              (b_m->data[(idx[q] + b_m->size[0] * (c_i - 1)) - 1])) {
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

    if (rtIsNaN(b_m->data[(idx[6] + b_m->size[0] * (c_i - 1)) - 1])) {
      c_m = b_m->data[(idx[6] + b_m->size[0] * (c_i - 1)) - 1];
    } else {
      c_m = b_m->data[(idx[3] + b_m->size[0] * (c_i - 1)) - 1];
    }

    m->data[c_i - 1] = c_m;
  }

  emxFree_real_T(&b_m);
  if (4U > 3U + n) {
    i22 = 0;
    i23 = 0;
  } else {
    i22 = 3;
    i23 = (int)(3U + n);
  }

  emxInit_real_T(&d_m, 2);
  c_s = d_m->size[0] * d_m->size[1];
  d_m->size[0] = 1;
  d_m->size[1] = i23 - i22;
  emxEnsureCapacity((emxArray__common *)d_m, c_s, (int)sizeof(double));
  c_s = i23 - i22;
  for (i23 = 0; i23 < c_s; i23++) {
    d_m->data[d_m->size[0] * i23] = m->data[i22 + i23];
  }

  i22 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = d_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i22, (int)sizeof(double));
  c_s = d_m->size[1];
  for (i22 = 0; i22 < c_s; i22++) {
    m->data[m->size[0] * i22] = d_m->data[d_m->size[0] * i22];
  }

  emxFree_real_T(&d_m);
}

/*
 * File trailer for Mymedfilt1.c
 *
 * [EOF]
 */
