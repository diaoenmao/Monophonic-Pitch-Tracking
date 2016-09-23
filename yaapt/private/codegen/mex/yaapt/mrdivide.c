/*
 * mrdivide.c
 *
 * Code generation for function 'mrdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mrdivide.h"
#include "error1.h"
#include "warning.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo ug_emlrtRTEI = { 1, 1, "mrdivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p" };

/* Function Definitions */
void mrdivide(const emlrtStack *sp, real_T A_data[], int32_T A_size[2], const
              real_T B_data[], const int32_T B_size[2])
{
  int32_T info;
  int32_T i78;
  ptrdiff_t ipiv_t;
  real_T b_A_data[1];
  ptrdiff_t info_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  if (B_size[1] == A_size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ug_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  if ((A_size[1] == 0) || (B_size[1] == 0)) {
    A_size[0] = 1;
    A_size[1] = 1;
    A_data[0] = 0.0;
  } else {
    st.site = &vl_emlrtRSI;
    b_st.site = &fc_emlrtRSI;
    c_st.site = &hc_emlrtRSI;
    d_st.site = &lc_emlrtRSI;
    info = B_size[0] * B_size[1];
    for (i78 = 0; i78 < info; i78++) {
      b_A_data[i78] = B_data[i78];
    }

    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)1, (ptrdiff_t)1, &b_A_data[0],
      (ptrdiff_t)1, &ipiv_t);
    info = (int32_T)info_t;
    e_st.site = &mc_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        f_st.site = &pc_emlrtRSI;
        d_error(&f_st);
      } else {
        f_st.site = &qc_emlrtRSI;
        e_error(&f_st, info);
      }
    }

    if (info > 0) {
      c_st.site = &gc_emlrtRSI;
      if (!emlrtSetWarningFlag(&c_st)) {
        d_st.site = &xc_emlrtRSI;
        warning(&d_st);
      }
    }

    if (A_size[1] == 0) {
    } else {
      A_data[0] *= 1.0 / b_A_data[0];
    }
  }
}

/* End of code generation (mrdivide.c) */
