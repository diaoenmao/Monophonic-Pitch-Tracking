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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo gd_emlrtRSI = { 75, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo hd_emlrtRSI = { 112, "colon",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo pd_emlrtRSI = { 14, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRSInfo qd_emlrtRSI = { 40, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRSInfo rd_emlrtRSI = { 75, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRSInfo sd_emlrtRSI = { 78, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRTEInfo bb_emlrtRTEI = { 1, 25, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtRTEInfo qe_emlrtRTEI = { 44, 5, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m" };

static emlrtDCInfo rd_emlrtDCI = { 42, 32, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m", 4 };

static emlrtDCInfo sd_emlrtDCI = { 44, 57, "xgeqp3",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m", 4 };

/* Function Definitions */

/*
 *
 */
void b_xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
              emxArray_int32_T *jpvt)
{
  int32_T n;
  int32_T i57;
  emxArray_ptrdiff_t *jpvt_t;
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
  st.site = &pd_emlrtRSI;
  n = A->size[1];
  if (A->size[1] == 0) {
    i57 = tau->size[0];
    tau->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)tau, i57, (int32_T)sizeof(real_T),
                      &bb_emlrtRTEI);
    b_st.site = &qd_emlrtRSI;
    c_st.site = &x_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    e_st.site = &hd_emlrtRSI;
    eml_signed_integer_colon(&e_st, A->size[1], jpvt);
  } else {
    emxInit_ptrdiff_t(&st, &jpvt_t, 1, &qe_emlrtRTEI, true);
    i57 = muIntScalarMin_sint32(1, n);
    if (!(i57 > 0)) {
      emlrtNonNegativeCheckR2012b(i57, &rd_emlrtDCI, &st);
    }

    i57 = tau->size[0];
    tau->size[0] = muIntScalarMin_sint32(1, n);
    emxEnsureCapacity(&st, (emxArray__common *)tau, i57, (int32_T)sizeof(real_T),
                      &bb_emlrtRTEI);
    i57 = jpvt_t->size[0];
    loop_ub = A->size[1];
    if (!(loop_ub > 0)) {
      emlrtNonNegativeCheckR2012b(loop_ub, &sd_emlrtDCI, &st);
    }

    jpvt_t->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, i57, (int32_T)sizeof
                      (ptrdiff_t), &bb_emlrtRTEI);
    loop_ub = A->size[1];
    if (!(loop_ub > 0)) {
      emlrtNonNegativeCheckR2012b(loop_ub, &sd_emlrtDCI, &st);
    }

    for (i57 = 0; i57 < loop_ub; i57++) {
      jpvt_t->data[i57] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)1;
    m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                         &jpvt_t->data[0], &tau->data[0]);
    b_st.site = &rd_emlrtRSI;
    if (infocheck(&b_st, (int32_T)m_t)) {
      i57 = A->size[0] * A->size[1];
      A->size[0] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)A, i57, (int32_T)sizeof(real_T),
                        &bb_emlrtRTEI);
      loop_ub = A->size[1];
      for (i57 = 0; i57 < loop_ub; i57++) {
        A->data[A->size[0] * i57] = rtNaN;
      }

      loop_ub = tau->size[0];
      i57 = tau->size[0];
      tau->size[0] = loop_ub;
      emxEnsureCapacity(&st, (emxArray__common *)tau, i57, (int32_T)sizeof
                        (real_T), &bb_emlrtRTEI);
      for (i57 = 0; i57 < loop_ub; i57++) {
        tau->data[i57] = rtNaN;
      }

      b_st.site = &sd_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      d_st.site = &gd_emlrtRSI;
      e_st.site = &hd_emlrtRSI;
      eml_signed_integer_colon(&e_st, n, jpvt);
    } else {
      i57 = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = jpvt_t->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)jpvt, i57, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      loop_ub = jpvt_t->size[0];
      for (i57 = 0; i57 < loop_ub; i57++) {
        jpvt->data[jpvt->size[0] * i57] = (int32_T)jpvt_t->data[i57];
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
  int32_T i56;
  emxArray_ptrdiff_t *jpvt_t;
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
  st.site = &pd_emlrtRSI;
  m = A->size[0];
  n = A->size[1];
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    i56 = tau->size[0];
    tau->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)tau, i56, (int32_T)sizeof(real_T),
                      &bb_emlrtRTEI);
    b_st.site = &qd_emlrtRSI;
    c_st.site = &x_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    e_st.site = &hd_emlrtRSI;
    eml_signed_integer_colon(&e_st, A->size[1], jpvt);
  } else {
    emxInit_ptrdiff_t(&st, &jpvt_t, 1, &qe_emlrtRTEI, true);
    i56 = muIntScalarMin_sint32(m, n);
    if (!(i56 > 0)) {
      emlrtNonNegativeCheckR2012b(i56, &rd_emlrtDCI, &st);
    }

    i56 = tau->size[0];
    tau->size[0] = muIntScalarMin_sint32(m, n);
    emxEnsureCapacity(&st, (emxArray__common *)tau, i56, (int32_T)sizeof(real_T),
                      &bb_emlrtRTEI);
    i56 = jpvt_t->size[0];
    m = A->size[1];
    if (!(m > 0)) {
      emlrtNonNegativeCheckR2012b(m, &sd_emlrtDCI, &st);
    }

    jpvt_t->size[0] = m;
    emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, i56, (int32_T)sizeof
                      (ptrdiff_t), &bb_emlrtRTEI);
    loop_ub = A->size[1];
    if (!(loop_ub > 0)) {
      emlrtNonNegativeCheckR2012b(loop_ub, &sd_emlrtDCI, &st);
    }

    for (i56 = 0; i56 < loop_ub; i56++) {
      jpvt_t->data[i56] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)A->size[0];
    m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                         &jpvt_t->data[0], &tau->data[0]);
    b_st.site = &rd_emlrtRSI;
    if (infocheck(&b_st, (int32_T)m_t)) {
      i56 = A->size[0] * A->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)A, i56, (int32_T)sizeof(real_T),
                        &bb_emlrtRTEI);
      loop_ub = A->size[1];
      for (i56 = 0; i56 < loop_ub; i56++) {
        b_loop_ub = A->size[0];
        for (m = 0; m < b_loop_ub; m++) {
          A->data[m + A->size[0] * i56] = rtNaN;
        }
      }

      m = tau->size[0];
      i56 = tau->size[0];
      tau->size[0] = m;
      emxEnsureCapacity(&st, (emxArray__common *)tau, i56, (int32_T)sizeof
                        (real_T), &bb_emlrtRTEI);
      for (i56 = 0; i56 < m; i56++) {
        tau->data[i56] = rtNaN;
      }

      b_st.site = &sd_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      d_st.site = &gd_emlrtRSI;
      e_st.site = &hd_emlrtRSI;
      eml_signed_integer_colon(&e_st, n, jpvt);
    } else {
      i56 = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = jpvt_t->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)jpvt, i56, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      loop_ub = jpvt_t->size[0];
      for (i56 = 0; i56 < loop_ub; i56++) {
        jpvt->data[jpvt->size[0] * i56] = (int32_T)jpvt_t->data[i56];
      }
    }

    emxFree_ptrdiff_t(&jpvt_t);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgeqp3.c) */
