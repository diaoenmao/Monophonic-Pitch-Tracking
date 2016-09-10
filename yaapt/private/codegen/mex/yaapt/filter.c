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
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo fe_emlrtRSI = { 158, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo ge_emlrtRSI = { 167, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo he_emlrtRSI = { 171, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo ie_emlrtRSI = { 191, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo je_emlrtRSI = { 195, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo ke_emlrtRSI = { 197, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo le_emlrtRSI = { 206, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo me_emlrtRSI = { 210, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo ne_emlrtRSI = { 227, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 1, 19, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo gb_emlrtRTEI = { 181, 9, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo uf_emlrtRTEI = { 16, 15, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo vf_emlrtRTEI = { 42, 19, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

/* Function Definitions */

/*
 *
 */
void b_filter(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T b6;
  uint32_T uv7[2];
  int32_T n;
  int32_T nx;
  real_T dbuffer[3];
  int32_T k;
  real_T b_dbuffer;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b6 = true;
  } else {
    b6 = false;
  }

  if (b6) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &vf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  for (n = 0; n < 2; n++) {
    uv7[n] = (uint32_T)x->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)uv7[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  nx = x->size[1];
  if (x->size[1] >= 6) {
    n = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                      &fb_emlrtRTEI);
    k = y->size[1];
    for (n = 0; n < k; n++) {
      y->data[y->size[0] * n] = 0.0;
    }

    for (k = 0; k < 3; k++) {
      n = nx - k;
      if (n < 23) {
        st.site = &ge_emlrtRSI;
        if ((!(k + 1 > nx)) && (nx > 2147483646)) {
          b_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (n = k; n + 1 <= nx; n++) {
          y->data[n] += 0.33333333333333331 * x->data[n - k];
        }
      } else {
        st.site = &he_emlrtRSI;
        xaxpy(n, 0.33333333333333331, x, 1, y, k + 1);
      }
    }
  } else {
    for (k = 0; k < 2; k++) {
      dbuffer[k + 1] = 0.0;
    }

    st.site = &je_emlrtRSI;
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
void filter(const emlrtStack *sp, const emxArray_real_T *b, const
            emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T nb;
  boolean_T overflow;
  uint32_T uv2[2];
  int32_T n;
  int32_T nx;
  emxArray_real_T *dbuffer;
  int32_T k;
  real_T a;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (!(b->size[1] == 0)) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &uf_emlrtRTEI,
      "Coder:toolbox:filter_notVectorInputB", 0);
  }

  nb = b->size[1];
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &vf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  for (n = 0; n < 2; n++) {
    uv2[n] = (uint32_T)x->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)uv2[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  nx = x->size[1];
  if (x->size[1] >= (b->size[1] << 1)) {
    n = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                      &fb_emlrtRTEI);
    k = y->size[1];
    for (n = 0; n < k; n++) {
      y->data[y->size[0] * n] = 0.0;
    }

    st.site = &fe_emlrtRSI;
    overflow = (b->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (k = 1; k <= nb; k++) {
      n = (nx - k) + 1;
      if ((b->data[k - 1] == 0.0) || (n < 23)) {
        st.site = &ge_emlrtRSI;
        if ((!(k > nx)) && (nx > 2147483646)) {
          b_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (n = k; n <= nx; n++) {
          y->data[n - 1] += b->data[k - 1] * x->data[n - k];
        }
      } else {
        st.site = &he_emlrtRSI;
        xaxpy(n, b->data[k - 1], x, 1, y, k);
      }
    }
  } else {
    emxInit_real_T1(sp, &dbuffer, 1, &gb_emlrtRTEI, true);
    n = dbuffer->size[0];
    dbuffer->size[0] = nb;
    emxEnsureCapacity(sp, (emxArray__common *)dbuffer, n, (int32_T)sizeof(real_T),
                      &fb_emlrtRTEI);
    st.site = &ie_emlrtRSI;
    for (k = 1; k < nb; k++) {
      dbuffer->data[k] = 0.0;
    }

    st.site = &je_emlrtRSI;
    for (n = 0; n + 1 <= nx; n++) {
      st.site = &ke_emlrtRSI;
      for (k = 1; k < nb; k++) {
        dbuffer->data[k - 1] = dbuffer->data[k];
      }

      dbuffer->data[nb - 1] = 0.0;
      if ((x->data[n] == 0.0) || (nb < 23)) {
        st.site = &le_emlrtRSI;
        if (nb > 2147483646) {
          b_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (k = 0; k + 1 <= nb; k++) {
          dbuffer->data[k] += x->data[n] * b->data[k];
        }
      } else {
        st.site = &me_emlrtRSI;
        a = x->data[n];
        n_t = (ptrdiff_t)nb;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, &a, &b->data[0], &incx_t, &dbuffer->data[0], &incy_t);
      }

      y->data[n] = dbuffer->data[0];
    }

    emxFree_real_T(&dbuffer);
    st.site = &ne_emlrtRSI;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (filter.c) */
