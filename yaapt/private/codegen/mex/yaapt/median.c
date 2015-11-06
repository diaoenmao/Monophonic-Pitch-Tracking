/*
 * median.c
 *
 * Code generation for function 'median'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "median.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo jg_emlrtRSI = { 71, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRSInfo kg_emlrtRSI = { 57, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo fc_emlrtRTEI = { 40, 1, "median",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

/* Function Definitions */

/*
 *
 */
void b_median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T i1;
  int32_T i2;
  int32_T iy;
  boolean_T overflow;
  int32_T i;
  real_T vwork[7];
  int32_T k;
  int8_T idx[7];
  int8_T idx0[7];
  int32_T b_i2;
  int32_T j;
  int32_T pEnd;
  int32_T p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i1 = 0; i1 < 2; i1++) {
    sz[i1] = (uint32_T)x->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i1, (int32_T)sizeof(real_T),
                    &fc_emlrtRTEI);
  i2 = 1;
  iy = -1;
  st.site = &kg_emlrtRSI;
  if (1 > x->size[1]) {
    overflow = false;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    b_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (i = 1; i <= x->size[1]; i++) {
    i1 = i2;
    i2 += 7;
    for (k = 0; k < 7; k++) {
      vwork[k] = x->data[i1 - 1];
      i1++;
    }

    iy++;
    st.site = &jg_emlrtRSI;
    for (k = 0; k < 7; k++) {
      idx[k] = (int8_T)(k + 1);
    }

    for (k = 0; k < 5; k += 2) {
      if ((vwork[k] <= vwork[k + 1]) || muDoubleScalarIsNaN(vwork[k + 1])) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        idx[k] = (int8_T)(k + 2);
        idx[k + 1] = (int8_T)(k + 1);
      }
    }

    for (i1 = 0; i1 < 7; i1++) {
      idx0[i1] = 1;
    }

    i1 = 2;
    while (i1 < 7) {
      b_i2 = i1 << 1;
      j = 1;
      for (pEnd = 1 + i1; pEnd < 8; pEnd = qEnd + i1) {
        p = j;
        q = pEnd - 1;
        qEnd = j + b_i2;
        if (qEnd > 8) {
          qEnd = 8;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((vwork[idx[p - 1] - 1] <= vwork[idx[q] - 1]) ||
              muDoubleScalarIsNaN(vwork[idx[q] - 1])) {
            overflow = true;
          } else {
            overflow = false;
          }

          if (overflow) {
            idx0[k] = idx[p - 1];
            p++;
            if (p == pEnd) {
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
              while (p < pEnd) {
                k++;
                idx0[k] = idx[p - 1];
                p++;
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

      i1 = b_i2;
    }

    if (muDoubleScalarIsNaN(vwork[idx[6] - 1])) {
      y->data[iy] = vwork[idx[6] - 1];
    } else {
      y->data[iy] = vwork[idx[3] - 1];
    }
  }
}

/*
 *
 */
void median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T i1;
  int32_T i2;
  int32_T iy;
  boolean_T overflow;
  int32_T i;
  real_T vwork[5];
  int32_T k;
  int8_T idx[5];
  int8_T idx0[5];
  int32_T b_i2;
  int32_T j;
  int32_T pEnd;
  int32_T p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i1 = 0; i1 < 2; i1++) {
    sz[i1] = (uint32_T)x->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i1, (int32_T)sizeof(real_T),
                    &fc_emlrtRTEI);
  i2 = 1;
  iy = -1;
  st.site = &kg_emlrtRSI;
  if (1 > x->size[1]) {
    overflow = false;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    b_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (i = 1; i <= x->size[1]; i++) {
    i1 = i2;
    i2 += 5;
    for (k = 0; k < 5; k++) {
      vwork[k] = x->data[i1 - 1];
      i1++;
    }

    iy++;
    st.site = &jg_emlrtRSI;
    for (k = 0; k < 5; k++) {
      idx[k] = (int8_T)(k + 1);
    }

    for (k = 0; k < 3; k += 2) {
      if ((vwork[k] <= vwork[k + 1]) || muDoubleScalarIsNaN(vwork[k + 1])) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        idx[k] = (int8_T)(k + 2);
        idx[k + 1] = (int8_T)(k + 1);
      }
    }

    for (i1 = 0; i1 < 5; i1++) {
      idx0[i1] = 1;
    }

    i1 = 2;
    while (i1 < 5) {
      b_i2 = i1 << 1;
      j = 1;
      for (pEnd = 1 + i1; pEnd < 6; pEnd = qEnd + i1) {
        p = j;
        q = pEnd - 1;
        qEnd = j + b_i2;
        if (qEnd > 6) {
          qEnd = 6;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if ((vwork[idx[p - 1] - 1] <= vwork[idx[q] - 1]) ||
              muDoubleScalarIsNaN(vwork[idx[q] - 1])) {
            overflow = true;
          } else {
            overflow = false;
          }

          if (overflow) {
            idx0[k] = idx[p - 1];
            p++;
            if (p == pEnd) {
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
              while (p < pEnd) {
                k++;
                idx0[k] = idx[p - 1];
                p++;
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

      i1 = b_i2;
    }

    if (muDoubleScalarIsNaN(vwork[idx[4] - 1])) {
      y->data[iy] = vwork[idx[4] - 1];
    } else {
      y->data[iy] = vwork[idx[2] - 1];
    }
  }
}

/* End of code generation (median.c) */
