/*
 * File: Mymedfilt1.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 12-Jan-2016 01:25:12
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
  int i12;
  emxArray_real_T *b_m;
  int i;
  double d_s;
  double e_s;
  int i13;
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
  i12 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = c_s;
  emxEnsureCapacity((emxArray__common *)b_s, i12, (int)sizeof(double));
  for (i12 = 0; i12 < c_s; i12++) {
    b_s->data[b_s->size[0] * i12] = s->data[i12];
  }

  i12 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity((emxArray__common *)s, i12, (int)sizeof(double));
  c_s = b_s->size[1];
  for (i12 = 0; i12 < c_s; i12++) {
    s->data[s->size[0] * i12] = b_s->data[b_s->size[0] * i12];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&b_m, 2);
  i12 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  b_m->size[1] = (int)(((double)s->size[1] + 5.0) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i12, (int)sizeof(double));
  c_s = 5 * (int)(((double)s->size[1] + 5.0) - 1.0);
  for (i12 = 0; i12 < c_s; i12++) {
    b_m->data[i12] = 0.0;
  }

  for (i = 0; i < 5; i++) {
    d_s = s->data[0];
    e_s = s->data[s->size[1] - 1];
    for (i12 = 0; i12 < i; i12++) {
      b_m->data[i + b_m->size[0] * i12] = d_s;
    }

    c_s = s->size[1];
    for (i12 = 0; i12 < c_s; i12++) {
      b_m->data[i + b_m->size[0] * (i12 + i)] = s->data[s->size[0] * i12];
    }

    c_s = 4 - i;
    for (i12 = 0; i12 < c_s; i12++) {
      b_m->data[i + b_m->size[0] * ((i12 + i) + s->size[1])] = e_s;
    }
  }

  median(b_m, m);
  emxFree_real_T(&b_m);
  if (3U > 2U + s->size[1]) {
    i12 = 0;
    i13 = 0;
  } else {
    i12 = 2;
    i13 = (int)(2U + s->size[1]);
  }

  emxInit_real_T(&c_m, 2);
  c_s = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = i13 - i12;
  emxEnsureCapacity((emxArray__common *)c_m, c_s, (int)sizeof(double));
  c_s = i13 - i12;
  for (i13 = 0; i13 < c_s; i13++) {
    c_m->data[c_m->size[0] * i13] = m->data[i12 + i13];
  }

  i12 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i12, (int)sizeof(double));
  c_s = c_m->size[1];
  for (i12 = 0; i12 < c_s; i12++) {
    m->data[m->size[0] * i12] = c_m->data[c_m->size[0] * i12];
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
  int i14;
  emxArray_real_T *b_m;
  int i;
  double c_s;
  double d_s;
  int i15;
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
  i14 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s_idx_0;
  emxEnsureCapacity((emxArray__common *)b_s, i14, (int)sizeof(double));
  for (i14 = 0; i14 < s_idx_0; i14++) {
    b_s->data[b_s->size[0] * i14] = s->data[i14];
  }

  emxInit_real_T(&b_m, 2);
  i14 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 5;
  b_m->size[1] = (int)(((double)b_s->size[1] + 5.0) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i14, (int)sizeof(double));
  s_idx_0 = 5 * (int)(((double)b_s->size[1] + 5.0) - 1.0);
  for (i14 = 0; i14 < s_idx_0; i14++) {
    b_m->data[i14] = 0.0;
  }

  for (i = 0; i < 5; i++) {
    c_s = b_s->data[0];
    d_s = b_s->data[b_s->size[1] - 1];
    for (i14 = 0; i14 < i; i14++) {
      b_m->data[i + b_m->size[0] * i14] = c_s;
    }

    s_idx_0 = b_s->size[1];
    for (i14 = 0; i14 < s_idx_0; i14++) {
      b_m->data[i + b_m->size[0] * (i14 + i)] = b_s->data[b_s->size[0] * i14];
    }

    s_idx_0 = 4 - i;
    for (i14 = 0; i14 < s_idx_0; i14++) {
      b_m->data[i + b_m->size[0] * ((i14 + i) + b_s->size[1])] = d_s;
    }
  }

  median(b_m, m);
  emxFree_real_T(&b_m);
  if (3U > 2U + b_s->size[1]) {
    i14 = 0;
    i15 = 0;
  } else {
    i14 = 2;
    i15 = (int)(2U + b_s->size[1]);
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&c_m, 2);
  s_idx_0 = c_m->size[0] * c_m->size[1];
  c_m->size[0] = 1;
  c_m->size[1] = i15 - i14;
  emxEnsureCapacity((emxArray__common *)c_m, s_idx_0, (int)sizeof(double));
  s_idx_0 = i15 - i14;
  for (i15 = 0; i15 < s_idx_0; i15++) {
    c_m->data[c_m->size[0] * i15] = m->data[i14 + i15];
  }

  i14 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = c_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i14, (int)sizeof(double));
  s_idx_0 = c_m->size[1];
  for (i14 = 0; i14 < s_idx_0; i14++) {
    m->data[m->size[0] * i14] = c_m->data[c_m->size[0] * i14];
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
  int i;
  int i2;
  emxArray_real_T *b_m;
  int b_i;
  double c_m;
  double c_s;
  int idx[7];
  int iwork[7];
  int k;
  boolean_T p;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
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
  i = s->size[1];
  i2 = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = i;
  emxEnsureCapacity((emxArray__common *)b_s, i2, (int)sizeof(double));
  for (i2 = 0; i2 < i; i2++) {
    b_s->data[b_s->size[0] * i2] = s->data[i2];
  }

  i2 = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = b_s->size[1];
  emxEnsureCapacity((emxArray__common *)s, i2, (int)sizeof(double));
  i = b_s->size[1];
  for (i2 = 0; i2 < i; i2++) {
    s->data[s->size[0] * i2] = b_s->data[b_s->size[0] * i2];
  }

  emxFree_real_T(&b_s);
  emxInit_real_T(&b_m, 2);
  i2 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = 7;
  b_m->size[1] = (int)(((double)s->size[1] + 7.0) - 1.0);
  emxEnsureCapacity((emxArray__common *)b_m, i2, (int)sizeof(double));
  i = 7 * (int)(((double)s->size[1] + 7.0) - 1.0);
  for (i2 = 0; i2 < i; i2++) {
    b_m->data[i2] = 0.0;
  }

  for (b_i = 0; b_i < 7; b_i++) {
    c_m = s->data[0];
    c_s = s->data[s->size[1] - 1];
    for (i2 = 0; i2 < b_i; i2++) {
      b_m->data[b_i + b_m->size[0] * i2] = c_m;
    }

    i = s->size[1];
    for (i2 = 0; i2 < i; i2++) {
      b_m->data[b_i + b_m->size[0] * (i2 + b_i)] = s->data[s->size[0] * i2];
    }

    i = 6 - b_i;
    for (i2 = 0; i2 < i; i2++) {
      b_m->data[b_i + b_m->size[0] * ((i2 + b_i) + s->size[1])] = c_s;
    }
  }

  i2 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = b_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i2, (int)sizeof(double));
  for (b_i = 0; b_i + 1 <= b_m->size[1]; b_i++) {
    for (i = 0; i < 7; i++) {
      idx[i] = 0;
    }

    for (k = 0; k <= 4; k += 2) {
      if ((b_m->data[k + b_m->size[0] * b_i] <= b_m->data[(k + b_m->size[0] *
            b_i) + 1]) || rtIsNaN(b_m->data[(k + b_m->size[0] * b_i) + 1])) {
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
    i = 2;
    while (i < 7) {
      i2 = i << 1;
      j = 1;
      for (pEnd = 1 + i; pEnd < 8; pEnd = qEnd + i) {
        b_p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > 8) {
          qEnd = 8;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((b_m->data[(idx[b_p - 1] + b_m->size[0] * b_i) - 1] <= b_m->data
               [(idx[q] + b_m->size[0] * b_i) - 1]) || rtIsNaN(b_m->data[(idx[q]
                + b_m->size[0] * b_i) - 1])) {
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

      i = i2;
    }

    if (rtIsNaN(b_m->data[(idx[6] + b_m->size[0] * b_i) - 1])) {
      c_m = b_m->data[(idx[6] + b_m->size[0] * b_i) - 1];
    } else {
      c_m = b_m->data[(idx[3] + b_m->size[0] * b_i) - 1];
    }

    m->data[b_i] = c_m;
  }

  emxFree_real_T(&b_m);
  if (4U > 3U + s->size[1]) {
    i2 = 0;
    k = 0;
  } else {
    i2 = 3;
    k = (int)(3U + s->size[1]);
  }

  emxInit_real_T(&d_m, 2);
  i = d_m->size[0] * d_m->size[1];
  d_m->size[0] = 1;
  d_m->size[1] = k - i2;
  emxEnsureCapacity((emxArray__common *)d_m, i, (int)sizeof(double));
  i = k - i2;
  for (k = 0; k < i; k++) {
    d_m->data[d_m->size[0] * k] = m->data[i2 + k];
  }

  i2 = m->size[0] * m->size[1];
  m->size[0] = 1;
  m->size[1] = d_m->size[1];
  emxEnsureCapacity((emxArray__common *)m, i2, (int)sizeof(double));
  i = d_m->size[1];
  for (i2 = 0; i2 < i; i2++) {
    m->data[m->size[0] * i2] = d_m->data[d_m->size[0] * i2];
  }

  emxFree_real_T(&d_m);
}

/*
 * File trailer for Mymedfilt1.c
 *
 * [EOF]
 */
