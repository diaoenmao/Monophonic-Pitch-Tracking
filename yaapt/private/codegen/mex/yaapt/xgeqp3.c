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
#include "error1.h"
#include "yaapt_emxutil.h"
#include "colon.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo tc_emlrtRSI = { 75, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo uc_emlrtRSI = { 112, "colon",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo dd_emlrtRSI = { 14, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo ed_emlrtRSI = { 41, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo fd_emlrtRSI = { 76, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo gd_emlrtRSI = { 79, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo cb_emlrtRTEI = { 1, 25, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo te_emlrtRTEI = { 45, 5, "xgeqp3",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
            emxArray_int32_T *jpvt)
{
  int32_T m;
  int32_T n;
  emxArray_ptrdiff_t *jpvt_t;
  int32_T i72;
  ptrdiff_t m_t;
  boolean_T p;
  boolean_T b_p;
  int32_T loop_ub;
  int32_T i73;
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
  st.site = &dd_emlrtRSI;
  m = A->size[0];
  n = A->size[1];
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    i72 = tau->size[0];
    tau->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)tau, i72, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
    b_st.site = &ed_emlrtRSI;
    c_st.site = &v_emlrtRSI;
    d_st.site = &tc_emlrtRSI;
    e_st.site = &uc_emlrtRSI;
    eml_signed_integer_colon(&e_st, A->size[1], jpvt);
  } else {
    emxInit_ptrdiff_t(&st, &jpvt_t, 1, &te_emlrtRTEI, true);
    i72 = tau->size[0];
    tau->size[0] = muIntScalarMin_sint32(m, n);
    emxEnsureCapacity(&st, (emxArray__common *)tau, i72, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
    i72 = jpvt_t->size[0];
    jpvt_t->size[0] = A->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, i72, (int32_T)sizeof
                      (ptrdiff_t), &cb_emlrtRTEI);
    m = A->size[1];
    for (i72 = 0; i72 < m; i72++) {
      jpvt_t->data[i72] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)A->size[0];
    m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                         &jpvt_t->data[0], &tau->data[0]);
    m = (int32_T)m_t;
    b_st.site = &fd_emlrtRSI;
    if (m != 0) {
      p = true;
      b_p = false;
      if (m == -4) {
        b_p = true;
      }

      if (!b_p) {
        if (m == -1010) {
          c_st.site = &pc_emlrtRSI;
          d_error(&c_st);
        } else {
          c_st.site = &qc_emlrtRSI;
          f_error(&c_st, m);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      i72 = A->size[0] * A->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)A, i72, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      m = A->size[1];
      for (i72 = 0; i72 < m; i72++) {
        loop_ub = A->size[0];
        for (i73 = 0; i73 < loop_ub; i73++) {
          A->data[i73 + A->size[0] * i72] = rtNaN;
        }
      }

      m = tau->size[0];
      i72 = tau->size[0];
      tau->size[0] = m;
      emxEnsureCapacity(&st, (emxArray__common *)tau, i72, (int32_T)sizeof
                        (real_T), &cb_emlrtRTEI);
      for (i72 = 0; i72 < m; i72++) {
        tau->data[i72] = rtNaN;
      }

      b_st.site = &gd_emlrtRSI;
      c_st.site = &v_emlrtRSI;
      d_st.site = &tc_emlrtRSI;
      e_st.site = &uc_emlrtRSI;
      eml_signed_integer_colon(&e_st, n, jpvt);
    } else {
      i72 = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = jpvt_t->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)jpvt, i72, (int32_T)sizeof
                        (int32_T), &cb_emlrtRTEI);
      m = jpvt_t->size[0];
      for (i72 = 0; i72 < m; i72++) {
        jpvt->data[jpvt->size[0] * i72] = (int32_T)jpvt_t->data[i72];
      }
    }

    emxFree_ptrdiff_t(&jpvt_t);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgeqp3.c) */
