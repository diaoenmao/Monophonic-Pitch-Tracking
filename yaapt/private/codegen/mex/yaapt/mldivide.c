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
#include "mrdivide.h"
#include "yaapt_emxutil.h"
#include "lusolve.h"
#include "qrsolve.h"
#include "warning.h"
#include "xgeqp3.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo oc_emlrtRSI = { 1, "mldivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

static emlrtRTEInfo y_emlrtRTEI = { 1, 2, "mldivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

static emlrtRTEInfo tf_emlrtRTEI = { 1, 1, "mldivide",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

/* Function Definitions */

/*
 *
 */
void mldivide(const emlrtStack *sp, const emxArray_real_T *A, const
              emxArray_real_T *B, emxArray_real_T *Y)
{
  emxArray_real_T *b_A;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  emxArray_real_T *b_B;
  emxArray_real_T *r14;
  uint32_T unnamed_idx_0;
  int32_T minmn;
  int32_T maxmn;
  int32_T rankR;
  real_T tol;
  const mxArray *y;
  char_T u[6];
  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *m4;
  static const int32_T iv19[2] = { 1, 6 };

  char_T cv0[14];
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
  emxInit_real_T(sp, &b_A, 2, &y_emlrtRTEI, true);
  if (B->size[0] == A->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &tf_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  emxInit_real_T1(sp, &tau, 1, &y_emlrtRTEI, true);
  emxInit_int32_T(sp, &jpvt, 2, &y_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_B, 1, &y_emlrtRTEI, true);
  emxInit_real_T1(sp, &r14, 1, &y_emlrtRTEI, true);
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0)) {
    unnamed_idx_0 = (uint32_T)A->size[1];
    minmn = Y->size[0];
    Y->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity(sp, (emxArray__common *)Y, minmn, (int32_T)sizeof(real_T),
                      &y_emlrtRTEI);
    maxmn = (int32_T)unnamed_idx_0;
    for (minmn = 0; minmn < maxmn; minmn++) {
      Y->data[minmn] = 0.0;
    }
  } else if (A->size[0] == A->size[1]) {
    minmn = Y->size[0];
    Y->size[0] = B->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)Y, minmn, (int32_T)sizeof(real_T),
                      &y_emlrtRTEI);
    maxmn = B->size[0];
    for (minmn = 0; minmn < maxmn; minmn++) {
      Y->data[minmn] = B->data[minmn];
    }

    st.site = &oc_emlrtRSI;
    lusolve(&st, A, Y);
  } else {
    st.site = &oc_emlrtRSI;
    minmn = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)b_A, minmn, (int32_T)sizeof
                      (real_T), &y_emlrtRTEI);
    maxmn = A->size[0] * A->size[1];
    for (minmn = 0; minmn < maxmn; minmn++) {
      b_A->data[minmn] = A->data[minmn];
    }

    b_st.site = &ld_emlrtRSI;
    xgeqp3(&b_st, b_A, tau, jpvt);
    b_st.site = &md_emlrtRSI;
    rankR = 0;
    tol = 0.0;
    if (b_A->size[0] < b_A->size[1]) {
      minmn = b_A->size[0];
      maxmn = b_A->size[1];
    } else {
      minmn = b_A->size[1];
      maxmn = b_A->size[0];
    }

    if (minmn > 0) {
      tol = (real_T)maxmn * muDoubleScalarAbs(b_A->data[0]) *
        2.2204460492503131E-16;
      while ((rankR < minmn) && (muDoubleScalarAbs(b_A->data[rankR + b_A->size[0]
               * rankR]) >= tol)) {
        rankR++;
      }
    }

    if ((rankR < minmn) && (!emlrtSetWarningFlag(&b_st))) {
      c_st.site = &td_emlrtRSI;
      for (minmn = 0; minmn < 6; minmn++) {
        u[minmn] = rfmt[minmn];
      }

      y = NULL;
      m4 = emlrtCreateCharArray(2, iv19);
      emlrtInitCharArrayR2013a(&c_st, 6, m4, &u[0]);
      emlrtAssign(&y, m4);
      d_st.site = &iq_emlrtRSI;
      emlrt_marshallIn(&d_st, b_sprintf(&d_st, y, emlrt_marshallOut(tol),
        &e_emlrtMCI), "sprintf", cv0);
      c_st.site = &ud_emlrtRSI;
      b_warning(&c_st, rankR, cv0);
    }

    minmn = b_B->size[0];
    b_B->size[0] = B->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)b_B, minmn, (int32_T)sizeof
                      (real_T), &y_emlrtRTEI);
    maxmn = B->size[0];
    for (minmn = 0; minmn < maxmn; minmn++) {
      b_B->data[minmn] = B->data[minmn];
    }

    b_st.site = &nd_emlrtRSI;
    LSQFromQR(&b_st, b_A, tau, jpvt, b_B, rankR, r14);
    minmn = Y->size[0];
    Y->size[0] = r14->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)Y, minmn, (int32_T)sizeof(real_T),
                      &y_emlrtRTEI);
    maxmn = r14->size[0];
    for (minmn = 0; minmn < maxmn; minmn++) {
      Y->data[minmn] = r14->data[minmn];
    }
  }

  emxFree_real_T(&r14);
  emxFree_real_T(&b_B);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&tau);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mldivide.c) */
