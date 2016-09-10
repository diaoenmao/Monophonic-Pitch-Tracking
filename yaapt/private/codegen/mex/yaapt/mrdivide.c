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
#include "yaapt_emxutil.h"
#include "warning.h"
#include "qrsolve.h"
#include "xgeqp3.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo go_emlrtRSI = { 1, "mrdivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p" };

static emlrtRTEInfo pe_emlrtRTEI = { 1, 2, "mrdivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p" };

/* Function Definitions */

/*
 *
 */
void mrdivide(const emlrtStack *sp, real_T A, const emxArray_real_T *B,
              emxArray_real_T *y)
{
  emxArray_real_T *b_A;
  emxArray_real_T *tau;
  int32_T maxmn;
  int32_T minmn;
  emxArray_int32_T *jpvt;
  ptrdiff_t ipiv_t;
  int32_T rankR;
  ptrdiff_t info_t;
  real_T tol;
  emxArray_real_T *Y;
  const mxArray *b_y;
  char_T u[6];
  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *m10;
  static const int32_T iv56[2] = { 1, 6 };

  char_T cv9[14];
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_A, 2, &pe_emlrtRTEI, true);
  if (B->size[0] == 0) {
    maxmn = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)y, maxmn, (int32_T)sizeof(real_T),
                      &pe_emlrtRTEI);
  } else {
    emxInit_real_T1(sp, &tau, 1, &pe_emlrtRTEI, true);
    if (B->size[0] == 1) {
      st.site = &go_emlrtRSI;
      b_st.site = &pc_emlrtRSI;
      c_st.site = &rc_emlrtRSI;
      d_st.site = &vc_emlrtRSI;
      maxmn = tau->size[0];
      tau->size[0] = B->size[0];
      emxEnsureCapacity(&d_st, (emxArray__common *)tau, maxmn, (int32_T)sizeof
                        (real_T), &pe_emlrtRTEI);
      minmn = B->size[0];
      for (maxmn = 0; maxmn < minmn; maxmn++) {
        tau->data[maxmn] = B->data[maxmn];
      }

      info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)1, (ptrdiff_t)1, &tau->data[0],
        (ptrdiff_t)1, &ipiv_t);
      minmn = (int32_T)info_t;
      e_st.site = &xc_emlrtRSI;
      if (minmn < 0) {
        if (minmn == -1010) {
          f_st.site = &bd_emlrtRSI;
          e_error(&f_st);
        } else {
          f_st.site = &cd_emlrtRSI;
          f_error(&f_st, minmn);
        }
      }

      e_st.site = &yc_emlrtRSI;
      if (minmn > 0) {
        c_st.site = &qc_emlrtRSI;
        if (!emlrtSetWarningFlag(&c_st)) {
          d_st.site = &jd_emlrtRSI;
          warning(&d_st);
        }
      }

      tol = 1.0 / tau->data[0] * A;
      maxmn = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)y, maxmn, (int32_T)sizeof(real_T),
                        &pe_emlrtRTEI);
      y->data[0] = tol;
    } else {
      st.site = &go_emlrtRSI;
      maxmn = b_A->size[0] * b_A->size[1];
      b_A->size[0] = 1;
      b_A->size[1] = B->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)b_A, maxmn, (int32_T)sizeof
                        (real_T), &pe_emlrtRTEI);
      minmn = B->size[0];
      for (maxmn = 0; maxmn < minmn; maxmn++) {
        b_A->data[b_A->size[0] * maxmn] = B->data[maxmn];
      }

      emxInit_int32_T(&st, &jpvt, 2, &pe_emlrtRTEI, true);
      b_st.site = &ld_emlrtRSI;
      b_xgeqp3(&b_st, b_A, tau, jpvt);
      b_st.site = &md_emlrtRSI;
      rankR = 0;
      tol = 0.0;
      if (1 < b_A->size[1]) {
        minmn = 1;
        maxmn = b_A->size[1];
      } else {
        minmn = b_A->size[1];
        maxmn = 1;
      }

      if (minmn > 0) {
        tol = (real_T)maxmn * muDoubleScalarAbs(b_A->data[0]) *
          2.2204460492503131E-16;
        while ((rankR < 1) && (muDoubleScalarAbs(b_A->data[0]) >= tol)) {
          rankR = 1;
        }
      }

      if ((rankR < minmn) && (!emlrtSetWarningFlag(&b_st))) {
        c_st.site = &td_emlrtRSI;
        for (maxmn = 0; maxmn < 6; maxmn++) {
          u[maxmn] = rfmt[maxmn];
        }

        b_y = NULL;
        m10 = emlrtCreateCharArray(2, iv56);
        emlrtInitCharArrayR2013a(&c_st, 6, m10, &u[0]);
        emlrtAssign(&b_y, m10);
        d_st.site = &iq_emlrtRSI;
        emlrt_marshallIn(&d_st, b_sprintf(&d_st, b_y, emlrt_marshallOut(tol),
          &e_emlrtMCI), "sprintf", cv9);
        c_st.site = &ud_emlrtRSI;
        b_warning(&c_st, 0, cv9);
      }

      emxInit_real_T1(&b_st, &Y, 1, &pe_emlrtRTEI, true);
      b_st.site = &nd_emlrtRSI;
      b_LSQFromQR(&b_st, b_A, tau, jpvt, A, rankR, Y);
      maxmn = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = Y->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)y, maxmn, (int32_T)sizeof(real_T),
                        &pe_emlrtRTEI);
      minmn = Y->size[0];
      emxFree_int32_T(&jpvt);
      for (maxmn = 0; maxmn < minmn; maxmn++) {
        y->data[y->size[0] * maxmn] = Y->data[maxmn];
      }

      emxFree_real_T(&Y);
    }

    emxFree_real_T(&tau);
  }

  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mrdivide.c) */
