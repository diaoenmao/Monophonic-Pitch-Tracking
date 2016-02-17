/*
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xgetrf.h"
#include "yaapt_emxutil.h"
#include "error1.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wc_emlrtRSI = { 53, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

static emlrtRTEInfo y_emlrtRTEI = { 1, 26, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

static emlrtRTEInfo pe_emlrtRTEI = { 53, 5, "xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

/* Function Definitions */

/*
 *
 */
void xgetrf(const emlrtStack *sp, int32_T m, int32_T n, emxArray_real_T *A,
            int32_T lda, emxArray_int32_T *ipiv, int32_T *info)
{
  int32_T i54;
  int32_T b_info;
  int32_T k;
  emxArray_ptrdiff_t *ipiv_t;
  ptrdiff_t info_t;
  int32_T NPIV;
  boolean_T p;
  int32_T loop_ub;
  int32_T i55;
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
  st.site = &vc_emlrtRSI;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    i54 = ipiv->size[0] * ipiv->size[1];
    ipiv->size[0] = 1;
    ipiv->size[1] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)ipiv, i54, (int32_T)sizeof
                      (int32_T), &y_emlrtRTEI);
    b_info = 0;
  } else {
    k = muIntScalarMin_sint32(m, n);
    if (k < 1) {
      k = 1;
    }

    b_st.site = &wc_emlrtRSI;
    emxInit_ptrdiff_t(&b_st, &ipiv_t, 1, &pe_emlrtRTEI, true);
    i54 = ipiv_t->size[0];
    ipiv_t->size[0] = k;
    emxEnsureCapacity(&st, (emxArray__common *)ipiv_t, i54, (int32_T)sizeof
                      (ptrdiff_t), &y_emlrtRTEI);
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)m, (ptrdiff_t)n, &A->data[0],
      (ptrdiff_t)lda, &ipiv_t->data[0]);
    b_info = (int32_T)info_t;
    i54 = ipiv->size[0] * ipiv->size[1];
    ipiv->size[0] = 1;
    ipiv->size[1] = ipiv_t->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)ipiv, i54, (int32_T)sizeof
                      (int32_T), &y_emlrtRTEI);
    NPIV = ipiv->size[1] - 1;
    b_st.site = &xc_emlrtRSI;
    if (b_info < 0) {
      if (b_info == -1010) {
        c_st.site = &cd_emlrtRSI;
        e_error(&c_st);
      } else {
        c_st.site = &dd_emlrtRSI;
        f_error(&c_st, b_info);
      }

      p = true;
    } else {
      p = false;
    }

    if (p) {
      i54 = A->size[0] * A->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)A, i54, (int32_T)sizeof(real_T),
                        &y_emlrtRTEI);
      k = A->size[1];
      for (i54 = 0; i54 < k; i54++) {
        loop_ub = A->size[0];
        for (i55 = 0; i55 < loop_ub; i55++) {
          A->data[i55 + A->size[0] * i54] = rtNaN;
        }
      }

      b_st.site = &yc_emlrtRSI;
      for (k = 0; k <= NPIV; k++) {
        ipiv->data[k] = k + 1;
      }
    } else {
      b_st.site = &ad_emlrtRSI;
      for (k = 0; k <= NPIV; k++) {
        ipiv->data[k] = (int32_T)ipiv_t->data[k];
      }
    }

    emxFree_ptrdiff_t(&ipiv_t);
  }

  *info = b_info;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgetrf.c) */
