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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sh_emlrtRSI = { 53, "median",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRSInfo th_emlrtRSI = { 54, "median",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo xb_emlrtRTEI = { 1, 14, "median",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

static emlrtRTEInfo te_emlrtRTEI = { 21, 19, "median",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\median.m" };

/* Function Definitions */

/*
 *
 */
void b_median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i;
  uint32_T sz[2];
  int32_T b_i;
  int32_T idx[7];
  int32_T iwork[7];
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  real_T m;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      i = x->size[k];
      if (i != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &te_emlrtRTEI,
      "Coder:toolbox:median_specialEmpty", 0);
  }

  for (i = 0; i < 2; i++) {
    sz[i] = (uint32_T)x->size[i];
  }

  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  if (x->size[1] == 0) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                      &xb_emlrtRTEI);
    b_i = y->size[1];
    for (i = 0; i < b_i; i++) {
      y->data[y->size[0] * i] = rtNaN;
    }
  } else {
    st.site = &sh_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (b_i = 0; b_i + 1 <= x->size[1]; b_i++) {
      st.site = &th_emlrtRSI;
      for (i = 0; i < 7; i++) {
        idx[i] = 0;
      }

      for (k = 0; k <= 4; k += 2) {
        if ((x->data[k + x->size[0] * b_i] <= x->data[(k + x->size[0] * b_i) + 1])
            || muDoubleScalarIsNaN(x->data[(k + x->size[0] * b_i) + 1])) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
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
            if ((x->data[(idx[b_p - 1] + x->size[0] * b_i) - 1] <= x->data
                 [(idx[q] + x->size[0] * b_i) - 1]) || muDoubleScalarIsNaN
                (x->data[(idx[q] + x->size[0] * b_i) - 1])) {
              overflow = true;
            } else {
              overflow = false;
            }

            if (overflow) {
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

      if (muDoubleScalarIsNaN(x->data[(idx[6] + x->size[0] * b_i) - 1])) {
        m = x->data[(idx[6] + x->size[0] * b_i) - 1];
      } else {
        m = x->data[(idx[3] + x->size[0] * b_i) - 1];
      }

      y->data[b_i] = m;
    }
  }
}

/*
 *
 */
void median(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i;
  uint32_T sz[2];
  int32_T b_i;
  int32_T idx[5];
  int32_T iwork[5];
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  real_T m;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      i = x->size[k];
      if (i != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &te_emlrtRTEI,
      "Coder:toolbox:median_specialEmpty", 0);
  }

  for (i = 0; i < 2; i++) {
    sz[i] = (uint32_T)x->size[i];
  }

  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                    &xb_emlrtRTEI);
  if (x->size[1] == 0) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                      &xb_emlrtRTEI);
    b_i = y->size[1];
    for (i = 0; i < b_i; i++) {
      y->data[y->size[0] * i] = rtNaN;
    }
  } else {
    st.site = &sh_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (b_i = 0; b_i + 1 <= x->size[1]; b_i++) {
      st.site = &th_emlrtRSI;
      for (i = 0; i < 5; i++) {
        idx[i] = 0;
      }

      for (k = 0; k <= 2; k += 2) {
        if ((x->data[k + x->size[0] * b_i] <= x->data[(k + x->size[0] * b_i) + 1])
            || muDoubleScalarIsNaN(x->data[(k + x->size[0] * b_i) + 1])) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
          idx[k] = k + 1;
          idx[k + 1] = k + 2;
        } else {
          idx[k] = k + 2;
          idx[k + 1] = k + 1;
        }
      }

      idx[4] = 5;
      i = 2;
      while (i < 5) {
        i2 = i << 1;
        j = 1;
        for (pEnd = 1 + i; pEnd < 6; pEnd = qEnd + i) {
          b_p = j;
          q = pEnd - 1;
          qEnd = j + i2;
          if (qEnd > 6) {
            qEnd = 6;
          }

          k = 0;
          kEnd = qEnd - j;
          while (k + 1 <= kEnd) {
            if ((x->data[(idx[b_p - 1] + x->size[0] * b_i) - 1] <= x->data
                 [(idx[q] + x->size[0] * b_i) - 1]) || muDoubleScalarIsNaN
                (x->data[(idx[q] + x->size[0] * b_i) - 1])) {
              overflow = true;
            } else {
              overflow = false;
            }

            if (overflow) {
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

      if (muDoubleScalarIsNaN(x->data[(idx[4] + x->size[0] * b_i) - 1])) {
        m = x->data[(idx[4] + x->size[0] * b_i) - 1];
      } else {
        m = x->data[(idx[2] + x->size[0] * b_i) - 1];
      }

      y->data[b_i] = m;
    }
  }
}

/* End of code generation (median.c) */
