/*
 * filter.c
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "filter.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "spec_trk.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRTEInfo g_emlrtRTEI = { 1, 19, "filter",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

/* Function Definitions */

/*
 *
 */
void filter(const emlrtStack *sp, const real_T b[151], const emxArray_real_T *x,
            emxArray_real_T *y)
{
  boolean_T b0;
  const mxArray *b_y;
  static const int32_T iv12[2] = { 1, 36 };

  const mxArray *m5;
  char_T cv19[36];
  int32_T i;
  static const char_T cv20[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  uint32_T uv0[2];
  int32_T k;
  int32_T jend;
  boolean_T b_k;
  real_T dbuffer[151];
  real_T b_dbuffer;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (b0) {
  } else {
    b_y = NULL;
    m5 = emlrtCreateCharArray(2, iv12);
    for (i = 0; i < 36; i++) {
      cv19[i] = cv20[i];
    }

    emlrtInitCharArrayR2013a(sp, 36, m5, cv19);
    emlrtAssign(&b_y, m5);
    st.site = &xk_emlrtRSI;
    b_st.site = &ck_emlrtRSI;
    f_error(&st, b_message(&b_st, b_y, &f_emlrtMCI), &g_emlrtMCI);
  }

  for (i = 0; i < 2; i++) {
    uv0[i] = (uint32_T)x->size[i];
  }

  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                    &f_emlrtRTEI);
  if (x->size[1] >= 302) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
    i = y->size[0] * y->size[1];
    y->size[1] = (int32_T)uv0[1];
    emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
    k = (int32_T)uv0[1];
    for (i = 0; i < k; i++) {
      y->data[i] = 0.0;
    }

    for (k = 0; k < 151; k++) {
      if (b[k] == 0.0) {
        jend = (k + x->size[1]) - k;
        st.site = &ub_emlrtRSI;
        if (k + 1 > jend) {
          b_k = false;
        } else {
          b_k = (jend > 2147483646);
        }

        if (b_k) {
          c_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (i = k; i + 1 <= jend; i++) {
          y->data[i] += b[k] * x->data[i - k];
        }
      } else {
        st.site = &tb_emlrtRSI;
        eml_xaxpy(&st, x->size[1] - k, b[k], x, y, k + 1);
      }
    }
  } else {
    memset(&dbuffer[1], 0, 150U * sizeof(real_T));
    st.site = &sb_emlrtRSI;
    for (i = 0; i + 1 <= x->size[1]; i++) {
      for (k = 0; k < 150; k++) {
        dbuffer[k] = dbuffer[k + 1];
      }

      dbuffer[150] = 0.0;
      if (x->data[i] == 0.0) {
        for (k = 0; k < 151; k++) {
          b_dbuffer = dbuffer[k] + x->data[i] * b[k];
          dbuffer[k] = b_dbuffer;
        }
      } else if (x->data[i] == 0.0) {
      } else {
        for (k = 0; k < 151; k++) {
          b_dbuffer = dbuffer[k] + x->data[i] * b[k];
          dbuffer[k] = b_dbuffer;
        }
      }

      y->data[i] = dbuffer[0];
    }
  }
}

/* End of code generation (filter.c) */
