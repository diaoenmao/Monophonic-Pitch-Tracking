/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xgetrf.h"
#include "error1.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void xgetrf(const emlrtStack *sp, real_T A[5776], int32_T ipiv[76], int32_T
            *info)
{
  ptrdiff_t ipiv_t[76];
  ptrdiff_t info_t;
  boolean_T p;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ib_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)76, (ptrdiff_t)76, &A[0],
    (ptrdiff_t)76, &ipiv_t[0]);
  *info = (int32_T)info_t;
  b_st.site = &jb_emlrtRSI;
  if (*info < 0) {
    if (*info == -1010) {
      c_st.site = &kb_emlrtRSI;
      d_error(&c_st);
    } else {
      c_st.site = &lb_emlrtRSI;
      e_error(&c_st, *info);
    }

    p = true;
  } else {
    p = false;
  }

  if (p) {
    for (k = 0; k < 5776; k++) {
      A[k] = rtNaN;
    }

    for (k = 0; k < 76; k++) {
      ipiv[k] = k + 1;
    }
  } else {
    for (k = 0; k < 76; k++) {
      ipiv[k] = (int32_T)ipiv_t[k];
    }
  }
}

/* End of code generation (xgetrf.c) */
