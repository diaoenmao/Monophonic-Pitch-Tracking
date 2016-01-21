/*
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xgeqp3.h"
#include "yaapt_emxutil.h"
#include "error1.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo hk_emlrtRSI = { 241, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo ik_emlrtRSI = { 268, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo mk_emlrtRSI = { 14, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRSInfo nk_emlrtRSI = { 40, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRSInfo ok_emlrtRSI = { 75, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRSInfo pk_emlrtRSI = { 78, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRSInfo qk_emlrtRSI = { 75, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo rk_emlrtRSI = { 112, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo sk_emlrtRSI = { 151, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo tk_emlrtRSI = { 156, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo cd_emlrtRTEI = { 1, 25, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRTEInfo sd_emlrtRTEI = { 44, 5, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtDCInfo pb_emlrtDCI = { 42, 32, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m", 4 };

static emlrtDCInfo qb_emlrtDCI = { 44, 57, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m", 4 };

static emlrtDCInfo rb_emlrtDCI = { 152, 28, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m", 4 };

/* Function Definitions */

/*
 *
 */
void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
            emxArray_int32_T *jpvt)
{
  int32_T n;
  int32_T k;
  boolean_T p;
  int32_T info;
  boolean_T b20;
  emxArray_ptrdiff_t *jpvt_t;
  ptrdiff_t m_t;
  boolean_T b21;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &mk_emlrtRSI;
  n = A->size[1];
  if (A->size[1] == 0) {
    k = tau->size[0];
    tau->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)tau, k, (int32_T)sizeof(real_T),
                      &cd_emlrtRTEI);
    b_st.site = &nk_emlrtRSI;
    c_st.site = &dd_emlrtRSI;
    d_st.site = &qk_emlrtRSI;
    e_st.site = &rk_emlrtRSI;
    f_st.site = &sk_emlrtRSI;
    g_st.site = &hk_emlrtRSI;
    if (A->size[1] < 1) {
      n = 0;
    } else {
      p = (A->size[1] - 1 < MAX_int32_T);
      h_st.site = &ik_emlrtRSI;
      if (p) {
      } else {
        emlrtErrorWithMessageIdR2012b(&h_st, &ee_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      n = A->size[1];
    }

    k = jpvt->size[0] * jpvt->size[1];
    jpvt->size[0] = 1;
    if (!(n > 0)) {
      emlrtNonNegativeCheckR2012b(n, &rb_emlrtDCI, &e_st);
    }

    jpvt->size[1] = n;
    emxEnsureCapacity(&e_st, (emxArray__common *)jpvt, k, (int32_T)sizeof
                      (int32_T), &cd_emlrtRTEI);
    if (n > 0) {
      jpvt->data[0] = 1;
      info = 1;
      f_st.site = &tk_emlrtRSI;
      if (2 > n) {
        b20 = false;
      } else {
        b20 = (n > 2147483646);
      }

      if (b20) {
        g_st.site = &kb_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      for (k = 2; k <= n; k++) {
        info++;
        jpvt->data[k - 1] = info;
      }
    }
  } else {
    emxInit_ptrdiff_t(&st, &jpvt_t, 1, &sd_emlrtRTEI, true);
    k = muIntScalarMin_sint32(1, n);
    if (!(k > 0)) {
      emlrtNonNegativeCheckR2012b(k, &pb_emlrtDCI, &st);
    }

    k = tau->size[0];
    tau->size[0] = muIntScalarMin_sint32(1, n);
    emxEnsureCapacity(&st, (emxArray__common *)tau, k, (int32_T)sizeof(real_T),
                      &cd_emlrtRTEI);
    k = jpvt_t->size[0];
    info = A->size[1];
    if (!(info > 0)) {
      emlrtNonNegativeCheckR2012b(info, &qb_emlrtDCI, &st);
    }

    jpvt_t->size[0] = info;
    emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, k, (int32_T)sizeof
                      (ptrdiff_t), &cd_emlrtRTEI);
    info = A->size[1];
    if (!(info > 0)) {
      emlrtNonNegativeCheckR2012b(info, &qb_emlrtDCI, &st);
    }

    for (k = 0; k < info; k++) {
      jpvt_t->data[k] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)1;
    m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                         &jpvt_t->data[0], &tau->data[0]);
    info = (int32_T)m_t;
    b_st.site = &ok_emlrtRSI;
    if (info != 0) {
      p = false;
      if (info == -4) {
        p = true;
      }

      if (!p) {
        if (info == -1010) {
          c_st.site = &cc_emlrtRSI;
          e_error(&c_st);
        } else {
          c_st.site = &dc_emlrtRSI;
          j_error(&c_st, info);
        }
      }

      p = true;
    } else {
      p = false;
    }

    if (p) {
      k = A->size[0] * A->size[1];
      A->size[0] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)A, k, (int32_T)sizeof(real_T),
                        &cd_emlrtRTEI);
      info = A->size[1];
      for (k = 0; k < info; k++) {
        A->data[A->size[0] * k] = rtNaN;
      }

      info = tau->size[0];
      k = tau->size[0];
      tau->size[0] = info;
      emxEnsureCapacity(&st, (emxArray__common *)tau, k, (int32_T)sizeof(real_T),
                        &cd_emlrtRTEI);
      for (k = 0; k < info; k++) {
        tau->data[k] = rtNaN;
      }

      b_st.site = &pk_emlrtRSI;
      c_st.site = &dd_emlrtRSI;
      d_st.site = &qk_emlrtRSI;
      e_st.site = &rk_emlrtRSI;
      f_st.site = &sk_emlrtRSI;
      g_st.site = &hk_emlrtRSI;
      if (n < 1) {
        n = 0;
      } else {
        h_st.site = &ik_emlrtRSI;
      }

      k = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = n;
      emxEnsureCapacity(&e_st, (emxArray__common *)jpvt, k, (int32_T)sizeof
                        (int32_T), &cd_emlrtRTEI);
      if (n > 0) {
        jpvt->data[0] = 1;
        info = 1;
        f_st.site = &tk_emlrtRSI;
        if (2 > n) {
          b21 = false;
        } else {
          b21 = (n > 2147483646);
        }

        if (b21) {
          g_st.site = &kb_emlrtRSI;
          check_forloop_overflow_error(&g_st, true);
        }

        for (k = 2; k <= n; k++) {
          info++;
          jpvt->data[k - 1] = info;
        }
      }
    } else {
      k = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = jpvt_t->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)jpvt, k, (int32_T)sizeof
                        (int32_T), &cd_emlrtRTEI);
      info = jpvt_t->size[0];
      for (k = 0; k < info; k++) {
        jpvt->data[jpvt->size[0] * k] = (int32_T)jpvt_t->data[k];
      }
    }

    emxFree_ptrdiff_t(&jpvt_t);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgeqp3.c) */
