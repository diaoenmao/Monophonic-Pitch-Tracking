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
#include "xaxpy.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ec_emlrtRSI = { 167, "filter",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo fc_emlrtRSI = { 171, "filter",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo gc_emlrtRSI = { 195, "filter",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo h_emlrtRTEI = { 1, 19, "filter",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo ud_emlrtRTEI = { 42, 19, "filter",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

/* Function Definitions */

/*
 *
 */
void b_filter(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T b14;
  uint32_T uv4[2];
  int32_T n;
  int32_T nx;
  int32_T k;
  boolean_T b_k;
  real_T dbuffer[3];
  real_T b_dbuffer;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b14 = true;
  } else {
    b14 = false;
  }

  if (b14) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ud_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  for (n = 0; n < 2; n++) {
    uv4[n] = (uint32_T)x->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)uv4[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  nx = x->size[1];
  if (x->size[1] >= 6) {
    n = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                      &h_emlrtRTEI);
    k = y->size[1];
    for (n = 0; n < k; n++) {
      y->data[y->size[0] * n] = 0.0;
    }

    for (k = 0; k < 3; k++) {
      n = nx - k;
      if (n < 23) {
        st.site = &ec_emlrtRSI;
        if (k + 1 > nx) {
          b_k = false;
        } else {
          b_k = (nx > 2147483646);
        }

        if (b_k) {
          b_st.site = &ib_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (n = k; n + 1 <= nx; n++) {
          y->data[n] += 0.33333333333333331 * x->data[n - k];
        }
      } else {
        st.site = &fc_emlrtRSI;
        xaxpy(n, 0.33333333333333331, x, 1, y, k + 1);
      }
    }
  } else {
    for (k = 0; k < 2; k++) {
      dbuffer[k + 1] = 0.0;
    }

    st.site = &gc_emlrtRSI;
    for (n = 0; n + 1 <= nx; n++) {
      for (k = 0; k < 2; k++) {
        dbuffer[k] = dbuffer[k + 1];
      }

      dbuffer[2] = 0.0;
      for (k = 0; k < 3; k++) {
        b_dbuffer = dbuffer[k] + x->data[n] * 0.33333333333333331;
        dbuffer[k] = b_dbuffer;
      }

      y->data[n] = dbuffer[0];
    }
  }
}

/*
 *
 */
void filter(const emlrtStack *sp, const real_T b[151], const emxArray_real_T *x,
            emxArray_real_T *y)
{
  boolean_T b0;
  uint32_T uv0[2];
  int32_T n;
  int32_T nx;
  int32_T k;
  boolean_T b_k;
  real_T dbuffer[151];
  real_T b_dbuffer;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ud_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  for (n = 0; n < 2; n++) {
    uv0[n] = (uint32_T)x->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  nx = x->size[1];
  if (x->size[1] >= 302) {
    n = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                      &h_emlrtRTEI);
    k = y->size[1];
    for (n = 0; n < k; n++) {
      y->data[y->size[0] * n] = 0.0;
    }

    for (k = 0; k < 151; k++) {
      n = nx - k;
      if ((b[k] == 0.0) || (n < 23)) {
        st.site = &ec_emlrtRSI;
        if (k + 1 > nx) {
          b_k = false;
        } else {
          b_k = (nx > 2147483646);
        }

        if (b_k) {
          b_st.site = &ib_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (n = k; n + 1 <= nx; n++) {
          y->data[n] += b[k] * x->data[n - k];
        }
      } else {
        st.site = &fc_emlrtRSI;
        xaxpy(n, b[k], x, 1, y, k + 1);
      }
    }
  } else {
    memset(&dbuffer[1], 0, 150U * sizeof(real_T));
    st.site = &gc_emlrtRSI;
    for (n = 0; n + 1 <= nx; n++) {
      for (k = 0; k < 150; k++) {
        dbuffer[k] = dbuffer[k + 1];
      }

      dbuffer[150] = 0.0;
      if (x->data[n] == 0.0) {
        for (k = 0; k < 151; k++) {
          b_dbuffer = dbuffer[k] + x->data[n] * b[k];
          dbuffer[k] = b_dbuffer;
        }
      } else if (x->data[n] == 0.0) {
      } else {
        for (k = 0; k < 151; k++) {
          b_dbuffer = dbuffer[k] + x->data[n] * b[k];
          dbuffer[k] = b_dbuffer;
        }
      }

      y->data[n] = dbuffer[0];
    }
  }
}

/* End of code generation (filter.c) */
