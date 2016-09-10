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
#include "colon.h"
#include "infocheck.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo fd_emlrtRSI = { 75, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo gd_emlrtRSI = { 112, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo od_emlrtRSI = { 14, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo pd_emlrtRSI = { 41, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo qd_emlrtRSI = { 76, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo rd_emlrtRSI = { 79, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo db_emlrtRTEI = { 1, 25, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo cf_emlrtRTEI = { 45, 5, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtDCInfo yd_emlrtDCI = { 43, 32, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m",
  4 };

static emlrtDCInfo ae_emlrtDCI = { 45, 57, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m",
  4 };

/* Function Definitions */

/*
 *
 */
void b_xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
              emxArray_int32_T *jpvt)
{
  int32_T n;
  emxArray_ptrdiff_t *jpvt_t;
  int32_T i61;
  int32_T loop_ub;
  ptrdiff_t m_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &od_emlrtRSI;
  n = A->size[1];
  if (A->size[1] == 0) {
    i61 = tau->size[0];
    tau->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)tau, i61, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    b_st.site = &pd_emlrtRSI;
    c_st.site = &x_emlrtRSI;
    d_st.site = &fd_emlrtRSI;
    e_st.site = &gd_emlrtRSI;
    eml_signed_integer_colon(&e_st, A->size[1], jpvt);
  } else {
    emxInit_ptrdiff_t(&st, &jpvt_t, 1, &cf_emlrtRTEI, true);
    i61 = muIntScalarMin_sint32(1, n);
    if (!(i61 >= 0)) {
      emlrtNonNegativeCheckR2012b(i61, &yd_emlrtDCI, &st);
    }

    i61 = tau->size[0];
    tau->size[0] = muIntScalarMin_sint32(1, n);
    emxEnsureCapacity(&st, (emxArray__common *)tau, i61, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    i61 = jpvt_t->size[0];
    loop_ub = A->size[1];
    if (!(loop_ub >= 0)) {
      emlrtNonNegativeCheckR2012b(loop_ub, &ae_emlrtDCI, &st);
    }

    jpvt_t->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, i61, (int32_T)sizeof
                      (ptrdiff_t), &db_emlrtRTEI);
    loop_ub = A->size[1];
    if (!(loop_ub >= 0)) {
      emlrtNonNegativeCheckR2012b(loop_ub, &ae_emlrtDCI, &st);
    }

    for (i61 = 0; i61 < loop_ub; i61++) {
      jpvt_t->data[i61] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)1;
    m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                         &jpvt_t->data[0], &tau->data[0]);
    b_st.site = &qd_emlrtRSI;
    if (infocheck(&b_st, (int32_T)m_t)) {
      i61 = A->size[0] * A->size[1];
      A->size[0] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)A, i61, (int32_T)sizeof(real_T),
                        &db_emlrtRTEI);
      loop_ub = A->size[1];
      for (i61 = 0; i61 < loop_ub; i61++) {
        A->data[A->size[0] * i61] = rtNaN;
      }

      loop_ub = tau->size[0];
      i61 = tau->size[0];
      tau->size[0] = loop_ub;
      emxEnsureCapacity(&st, (emxArray__common *)tau, i61, (int32_T)sizeof
                        (real_T), &db_emlrtRTEI);
      for (i61 = 0; i61 < loop_ub; i61++) {
        tau->data[i61] = rtNaN;
      }

      b_st.site = &rd_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      d_st.site = &fd_emlrtRSI;
      e_st.site = &gd_emlrtRSI;
      eml_signed_integer_colon(&e_st, n, jpvt);
    } else {
      i61 = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = jpvt_t->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)jpvt, i61, (int32_T)sizeof
                        (int32_T), &db_emlrtRTEI);
      loop_ub = jpvt_t->size[0];
      for (i61 = 0; i61 < loop_ub; i61++) {
        jpvt->data[jpvt->size[0] * i61] = (int32_T)jpvt_t->data[i61];
      }
    }

    emxFree_ptrdiff_t(&jpvt_t);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
            emxArray_int32_T *jpvt)
{
  int32_T m;
  int32_T n;
  emxArray_ptrdiff_t *jpvt_t;
  int32_T i60;
  int32_T loop_ub;
  ptrdiff_t m_t;
  int32_T b_loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &od_emlrtRSI;
  m = A->size[0];
  n = A->size[1];
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    i60 = tau->size[0];
    tau->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)tau, i60, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    b_st.site = &pd_emlrtRSI;
    c_st.site = &x_emlrtRSI;
    d_st.site = &fd_emlrtRSI;
    e_st.site = &gd_emlrtRSI;
    eml_signed_integer_colon(&e_st, A->size[1], jpvt);
  } else {
    emxInit_ptrdiff_t(&st, &jpvt_t, 1, &cf_emlrtRTEI, true);
    i60 = muIntScalarMin_sint32(m, n);
    if (!(i60 >= 0)) {
      emlrtNonNegativeCheckR2012b(i60, &yd_emlrtDCI, &st);
    }

    i60 = tau->size[0];
    tau->size[0] = muIntScalarMin_sint32(m, n);
    emxEnsureCapacity(&st, (emxArray__common *)tau, i60, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    i60 = jpvt_t->size[0];
    m = A->size[1];
    if (!(m >= 0)) {
      emlrtNonNegativeCheckR2012b(m, &ae_emlrtDCI, &st);
    }

    jpvt_t->size[0] = m;
    emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, i60, (int32_T)sizeof
                      (ptrdiff_t), &db_emlrtRTEI);
    loop_ub = A->size[1];
    if (!(loop_ub >= 0)) {
      emlrtNonNegativeCheckR2012b(loop_ub, &ae_emlrtDCI, &st);
    }

    for (i60 = 0; i60 < loop_ub; i60++) {
      jpvt_t->data[i60] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)A->size[0];
    m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                         &jpvt_t->data[0], &tau->data[0]);
    b_st.site = &qd_emlrtRSI;
    if (infocheck(&b_st, (int32_T)m_t)) {
      i60 = A->size[0] * A->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)A, i60, (int32_T)sizeof(real_T),
                        &db_emlrtRTEI);
      loop_ub = A->size[1];
      for (i60 = 0; i60 < loop_ub; i60++) {
        b_loop_ub = A->size[0];
        for (m = 0; m < b_loop_ub; m++) {
          A->data[m + A->size[0] * i60] = rtNaN;
        }
      }

      m = tau->size[0];
      i60 = tau->size[0];
      tau->size[0] = m;
      emxEnsureCapacity(&st, (emxArray__common *)tau, i60, (int32_T)sizeof
                        (real_T), &db_emlrtRTEI);
      for (i60 = 0; i60 < m; i60++) {
        tau->data[i60] = rtNaN;
      }

      b_st.site = &rd_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      d_st.site = &fd_emlrtRSI;
      e_st.site = &gd_emlrtRSI;
      eml_signed_integer_colon(&e_st, n, jpvt);
    } else {
      i60 = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = jpvt_t->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)jpvt, i60, (int32_T)sizeof
                        (int32_T), &db_emlrtRTEI);
      loop_ub = jpvt_t->size[0];
      for (i60 = 0; i60 < loop_ub; i60++) {
        jpvt->data[jpvt->size[0] * i60] = (int32_T)jpvt_t->data[i60];
      }
    }

    emxFree_ptrdiff_t(&jpvt_t);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgeqp3.c) */
