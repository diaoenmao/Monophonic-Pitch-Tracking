/*
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mldivide.h"
#include "yaapt_emxutil.h"
#include "warning.h"
#include "xgetrf.h"
#include "qrsolve.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ec_emlrtRSI = { 1, "mldivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

static emlrtRSInfo ic_emlrtRSI = { 131, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

static emlrtRSInfo jc_emlrtRSI = { 142, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

static emlrtRSInfo kc_emlrtRSI = { 144, "lusolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

static emlrtRTEInfo x_emlrtRTEI = { 1, 2, "mldivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

static emlrtRTEInfo tg_emlrtRTEI = { 1, 1, "mldivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

/* Function Definitions */
void mldivide(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *B)
{
  emxArray_real_T *b_A;
  emxArray_int32_T *ipiv;
  emxArray_real_T *b_B;
  uint32_T unnamed_idx_0;
  int32_T info;
  int32_T loop_ub;
  real_T temp;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_A, 2, &x_emlrtRTEI, true);
  if (B->size[0] == A->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &tg_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  emxInit_int32_T(sp, &ipiv, 2, &x_emlrtRTEI, true);
  emxInit_real_T2(sp, &b_B, 1, &x_emlrtRTEI, true);
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0)) {
    unnamed_idx_0 = (uint32_T)A->size[1];
    info = B->size[0];
    B->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity(sp, (emxArray__common *)B, info, (int32_T)sizeof(real_T),
                      &x_emlrtRTEI);
    loop_ub = (int32_T)unnamed_idx_0;
    for (info = 0; info < loop_ub; info++) {
      B->data[info] = 0.0;
    }
  } else if (A->size[0] == A->size[1]) {
    st.site = &ec_emlrtRSI;
    b_st.site = &fc_emlrtRSI;
    info = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_A, info, (int32_T)sizeof
                      (real_T), &x_emlrtRTEI);
    loop_ub = A->size[0] * A->size[1];
    for (info = 0; info < loop_ub; info++) {
      b_A->data[info] = A->data[info];
    }

    c_st.site = &hc_emlrtRSI;
    xgetrf(&c_st, A->size[1], A->size[1], b_A, A->size[1], ipiv, &info);
    if (info > 0) {
      c_st.site = &gc_emlrtRSI;
      if (!emlrtSetWarningFlag(&c_st)) {
        d_st.site = &xc_emlrtRSI;
        warning(&d_st);
      }
    }

    c_st.site = &ic_emlrtRSI;
    for (info = 0; info + 1 < A->size[1]; info++) {
      if (ipiv->data[info] != info + 1) {
        temp = B->data[info];
        B->data[info] = B->data[ipiv->data[info] - 1];
        B->data[ipiv->data[info] - 1] = temp;
      }
    }

    c_st.site = &jc_emlrtRSI;
    temp = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'L';
    m_t = (ptrdiff_t)A->size[1];
    n_t = (ptrdiff_t)1;
    lda_t = (ptrdiff_t)A->size[1];
    ldb_t = (ptrdiff_t)A->size[1];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A->data[0],
          &lda_t, &B->data[0], &ldb_t);
    c_st.site = &kc_emlrtRSI;
    temp = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'L';
    m_t = (ptrdiff_t)A->size[1];
    n_t = (ptrdiff_t)1;
    lda_t = (ptrdiff_t)A->size[1];
    ldb_t = (ptrdiff_t)A->size[1];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A->data[0],
          &lda_t, &B->data[0], &ldb_t);
  } else {
    info = b_B->size[0];
    b_B->size[0] = B->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_B, info, (int32_T)sizeof(real_T),
                      &x_emlrtRTEI);
    loop_ub = B->size[0];
    for (info = 0; info < loop_ub; info++) {
      b_B->data[info] = B->data[info];
    }

    st.site = &ec_emlrtRSI;
    qrsolve(&st, A, b_B, B);
  }

  emxFree_real_T(&b_B);
  emxFree_int32_T(&ipiv);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mldivide.c) */
