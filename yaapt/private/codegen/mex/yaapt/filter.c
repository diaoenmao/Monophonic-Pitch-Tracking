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
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sd_emlrtRSI = { 158, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo td_emlrtRSI = { 167, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo ud_emlrtRSI = { 171, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo vd_emlrtRSI = { 191, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo wd_emlrtRSI = { 195, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo xd_emlrtRSI = { 197, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo yd_emlrtRSI = { 206, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo ae_emlrtRSI = { 210, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRSInfo be_emlrtRSI = { 227, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo db_emlrtRTEI = { 1, 19, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo eb_emlrtRTEI = { 181, 9, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo kf_emlrtRTEI = { 16, 15, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

static emlrtRTEInfo lf_emlrtRTEI = { 42, 19, "filter",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" };

/* Function Definitions */
void filter(const emlrtStack *sp, const emxArray_real_T *b, const
            emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T nb;
  boolean_T overflow;
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
    emlrtErrorWithMessageIdR2012b(sp, &kf_emlrtRTEI,
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
    emlrtErrorWithMessageIdR2012b(sp, &lf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  n = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &db_emlrtRTEI);
  nx = x->size[1];
  if (x->size[1] >= (b->size[1] << 1)) {
    n = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    k = y->size[1];
    for (n = 0; n < k; n++) {
      y->data[y->size[0] * n] = 0.0;
    }

    st.site = &sd_emlrtRSI;
    overflow = (b->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k + 1 <= nb; k++) {
      n = nx - k;
      if ((b->data[k] == 0.0) || (n < 23)) {
        st.site = &td_emlrtRSI;
        if ((!(k + 1 > nx)) && (nx > 2147483646)) {
          b_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (n = k; n + 1 <= nx; n++) {
          y->data[n] += b->data[k] * x->data[n - k];
        }
      } else {
        st.site = &ud_emlrtRSI;
        a = b->data[k];
        n_t = (ptrdiff_t)n;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, &a, &x->data[0], &incx_t, &y->data[k], &incy_t);
      }
    }
  } else {
    emxInit_real_T2(sp, &dbuffer, 1, &eb_emlrtRTEI, true);
    n = dbuffer->size[0];
    dbuffer->size[0] = nb;
    emxEnsureCapacity(sp, (emxArray__common *)dbuffer, n, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    st.site = &vd_emlrtRSI;
    for (k = 1; k < nb; k++) {
      dbuffer->data[k] = 0.0;
    }

    st.site = &wd_emlrtRSI;
    for (n = 0; n + 1 <= nx; n++) {
      st.site = &xd_emlrtRSI;
      for (k = 1; k < nb; k++) {
        dbuffer->data[k - 1] = dbuffer->data[k];
      }

      dbuffer->data[nb - 1] = 0.0;
      if ((x->data[n] == 0.0) || (nb < 23)) {
        st.site = &yd_emlrtRSI;
        if (nb > 2147483646) {
          b_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (k = 0; k + 1 <= nb; k++) {
          dbuffer->data[k] += x->data[n] * b->data[k];
        }
      } else {
        st.site = &ae_emlrtRSI;
        a = x->data[n];
        n_t = (ptrdiff_t)nb;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, &a, &b->data[0], &incx_t, &dbuffer->data[0], &incy_t);
      }

      y->data[n] = dbuffer->data[0];
    }

    emxFree_real_T(&dbuffer);
    st.site = &be_emlrtRSI;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (filter.c) */
