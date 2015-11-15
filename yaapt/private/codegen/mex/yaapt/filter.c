/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 195, "filter",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo qb_emlrtRSI = { 171, "filter",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo rb_emlrtRSI = { 167, "filter",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo g_emlrtRTEI = { 1, 19, "filter",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo qd_emlrtRTEI = { 42, 19, "filter",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

/* Function Definitions */

/*
 *
 */
void b_filter(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T b13;
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
    b13 = true;
  } else {
    b13 = false;
  }

  if (b13) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &qd_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  n = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &g_emlrtRTEI);
  nx = x->size[1];
  if (x->size[1] >= 6) {
    n = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
    k = y->size[1];
    for (n = 0; n < k; n++) {
      y->data[y->size[0] * n] = 0.0;
    }

    for (k = 0; k < 3; k++) {
      n = nx - k;
      if (n < 23) {
        st.site = &rb_emlrtRSI;
        if (k + 1 > nx) {
          b_k = false;
        } else {
          b_k = (nx > 2147483646);
        }

        if (b_k) {
          b_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (n = k; n + 1 <= nx; n++) {
          y->data[n] += 0.33333333333333331 * x->data[n - k];
        }
      } else {
        st.site = &qb_emlrtRSI;
        xaxpy(n, 0.33333333333333331, x, y, k + 1);
      }
    }
  } else {
    for (k = 0; k < 2; k++) {
      dbuffer[k + 1] = 0.0;
    }

    st.site = &pb_emlrtRSI;
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
  int32_T j;
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
    emlrtErrorWithMessageIdR2012b(sp, &qd_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                    &g_emlrtRTEI);
  nx = x->size[1];
  if (x->size[1] >= 302) {
    j = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
    k = y->size[1];
    for (j = 0; j < k; j++) {
      y->data[y->size[0] * j] = 0.0;
    }

    for (k = 0; k < 151; k++) {
      if (b[k] == 0.0) {
        st.site = &rb_emlrtRSI;
        if (k + 1 > nx) {
          b_k = false;
        } else {
          b_k = (nx > 2147483646);
        }

        if (b_k) {
          b_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (j = k; j + 1 <= nx; j++) {
          y->data[j] += b[k] * x->data[j - k];
        }
      } else {
        st.site = &qb_emlrtRSI;
        xaxpy(nx - k, b[k], x, y, k + 1);
      }
    }
  } else {
    memset(&dbuffer[1], 0, 150U * sizeof(real_T));
    st.site = &pb_emlrtRSI;
    for (j = 0; j + 1 <= nx; j++) {
      for (k = 0; k < 150; k++) {
        dbuffer[k] = dbuffer[k + 1];
      }

      dbuffer[150] = 0.0;
      if (x->data[j] == 0.0) {
        for (k = 0; k < 151; k++) {
          b_dbuffer = dbuffer[k] + x->data[j] * b[k];
          dbuffer[k] = b_dbuffer;
        }
      } else if (x->data[j] == 0.0) {
      } else {
        for (k = 0; k < 151; k++) {
          b_dbuffer = dbuffer[k] + x->data[j] * b[k];
          dbuffer[k] = b_dbuffer;
        }
      }

      y->data[j] = dbuffer[0];
    }
  }
}

/* End of code generation (filter.c) */
