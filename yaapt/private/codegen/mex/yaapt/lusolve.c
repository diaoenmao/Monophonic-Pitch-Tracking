/*
 * lusolve.c
 *
 * Code generation for function 'lusolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "lusolve.h"
#include "yaapt_emxutil.h"
#include "warning.h"
#include "xgetrf.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sc_emlrtRSI = { 117, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

static emlrtRSInfo tc_emlrtRSI = { 128, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

static emlrtRSInfo uc_emlrtRSI = { 130, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

static emlrtRTEInfo x_emlrtRTEI = { 1, 19, "lusolve",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" };

/* Function Definitions */

/*
 *
 */
void lusolve(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *B)
{
  emxArray_real_T *b_A;
  int32_T info;
  int32_T loop_ub;
  emxArray_int32_T *ipiv;
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
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_A, 2, &x_emlrtRTEI, true);
  st.site = &pc_emlrtRSI;
  info = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_A, info, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  loop_ub = A->size[0] * A->size[1];
  for (info = 0; info < loop_ub; info++) {
    b_A->data[info] = A->data[info];
  }

  emxInit_int32_T(&st, &ipiv, 2, &x_emlrtRTEI, true);
  b_st.site = &rc_emlrtRSI;
  xgetrf(&b_st, A->size[1], A->size[1], b_A, A->size[1], ipiv, &info);
  if (info > 0) {
    b_st.site = &qc_emlrtRSI;
    if (!emlrtSetWarningFlag(&b_st)) {
      c_st.site = &kd_emlrtRSI;
      warning(&c_st);
    }
  }

  b_st.site = &sc_emlrtRSI;
  for (info = 0; info + 1 < A->size[1]; info++) {
    if (ipiv->data[info] != info + 1) {
      temp = B->data[info];
      B->data[info] = B->data[ipiv->data[info] - 1];
      B->data[ipiv->data[info] - 1] = temp;
    }
  }

  emxFree_int32_T(&ipiv);
  b_st.site = &tc_emlrtRSI;
  if (A->size[1] < 1) {
  } else {
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
  }

  b_st.site = &uc_emlrtRSI;
  if (A->size[1] < 1) {
  } else {
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
  }

  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (lusolve.c) */
