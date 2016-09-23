/*
 * qrsolve.c
 *
 * Code generation for function 'qrsolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "qrsolve.h"
#include "error1.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "warning.h"
#include "xgeqp3.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ad_emlrtRSI = { 28, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo bd_emlrtRSI = { 32, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo cd_emlrtRSI = { 39, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo id_emlrtRSI = { 121, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo jd_emlrtRSI = { 120, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo kd_emlrtRSI = { 72, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo ld_emlrtRSI = { 79, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo md_emlrtRSI = { 89, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo nd_emlrtRSI = { 29, "xunormqr",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"
};

static emlrtRSInfo od_emlrtRSI = { 101, "xunormqr",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"
};

static emlrtMCInfo e_emlrtMCI = { 52, 19, "flt2str",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" };

static emlrtRTEInfo bb_emlrtRTEI = { 1, 24, "qrsolve",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo uo_emlrtRSI = { 52, "flt2str",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m15;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m15, 2, pArrays, "sprintf", true,
    location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, ret, 14);
  emlrtDestroyArray(&src);
}

void qrsolve(const emlrtStack *sp, const emxArray_real_T *A, const
             emxArray_real_T *B, emxArray_real_T *Y)
{
  emxArray_real_T *b_A;
  int32_T maxmn;
  int32_T minmn;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  int32_T rankR;
  real_T tol;
  const mxArray *y;
  char_T u[6];
  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *m4;
  static const int32_T iv17[2] = { 1, 6 };

  char_T cv2[14];
  emxArray_real_T *b_B;
  ptrdiff_t nrc_t;
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
  emxInit_real_T(sp, &b_A, 2, &bb_emlrtRTEI, true);
  maxmn = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_A, maxmn, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  minmn = A->size[0] * A->size[1];
  for (maxmn = 0; maxmn < minmn; maxmn++) {
    b_A->data[maxmn] = A->data[maxmn];
  }

  emxInit_real_T2(sp, &tau, 1, &bb_emlrtRTEI, true);
  emxInit_int32_T(sp, &jpvt, 2, &bb_emlrtRTEI, true);
  st.site = &ad_emlrtRSI;
  xgeqp3(&st, b_A, tau, jpvt);
  st.site = &bd_emlrtRSI;
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
    while ((rankR < minmn) && (muDoubleScalarAbs(b_A->data[rankR + b_A->size[0] *
             rankR]) >= tol)) {
      rankR++;
    }
  }

  if ((rankR < minmn) && (!emlrtSetWarningFlag(&st))) {
    b_st.site = &id_emlrtRSI;
    for (maxmn = 0; maxmn < 6; maxmn++) {
      u[maxmn] = rfmt[maxmn];
    }

    y = NULL;
    m4 = emlrtCreateCharArray(2, iv17);
    emlrtInitCharArrayR2013a(&b_st, 6, m4, &u[0]);
    emlrtAssign(&y, m4);
    c_st.site = &uo_emlrtRSI;
    emlrt_marshallIn(&c_st, b_sprintf(&c_st, y, emlrt_marshallOut(tol),
      &e_emlrtMCI), "sprintf", cv2);
    b_st.site = &jd_emlrtRSI;
    b_warning(&b_st, rankR, cv2);
  }

  st.site = &cd_emlrtRSI;
  minmn = b_A->size[1];
  maxmn = Y->size[0];
  Y->size[0] = minmn;
  emxEnsureCapacity(&st, (emxArray__common *)Y, maxmn, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  for (maxmn = 0; maxmn < minmn; maxmn++) {
    Y->data[maxmn] = 0.0;
  }

  emxInit_real_T2(&st, &b_B, 1, &bb_emlrtRTEI, true);
  b_st.site = &kd_emlrtRSI;
  c_st.site = &nd_emlrtRSI;
  maxmn = b_B->size[0];
  b_B->size[0] = B->size[0];
  emxEnsureCapacity(&c_st, (emxArray__common *)b_B, maxmn, (int32_T)sizeof
                    (real_T), &bb_emlrtRTEI);
  minmn = B->size[0];
  for (maxmn = 0; maxmn < minmn; maxmn++) {
    b_B->data[maxmn] = B->data[maxmn];
  }

  minmn = muIntScalarMin_sint32(b_A->size[0], b_A->size[1]);
  if (!((b_A->size[0] == 0) || (b_A->size[1] == 0))) {
    nrc_t = (ptrdiff_t)b_B->size[0];
    nrc_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)1, (ptrdiff_t)minmn,
      &b_A->data[0], (ptrdiff_t)b_A->size[0], &tau->data[0], &b_B->data[0],
      nrc_t);
    minmn = (int32_T)nrc_t;
    d_st.site = &od_emlrtRSI;
    if (minmn != 0) {
      if (minmn == -1010) {
        e_st.site = &pc_emlrtRSI;
        d_error(&e_st);
      } else {
        e_st.site = &qc_emlrtRSI;
        g_error(&e_st, minmn);
      }
    }
  }

  emxFree_real_T(&tau);
  b_st.site = &ld_emlrtRSI;
  if ((!(1 > rankR)) && (rankR > 2147483646)) {
    c_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (maxmn = 0; maxmn + 1 <= rankR; maxmn++) {
    Y->data[jpvt->data[maxmn] - 1] = b_B->data[maxmn];
  }

  emxFree_real_T(&b_B);
  for (minmn = rankR - 1; minmn + 1 > 0; minmn--) {
    Y->data[jpvt->data[minmn] - 1] /= b_A->data[minmn + b_A->size[0] * minmn];
    b_st.site = &md_emlrtRSI;
    for (maxmn = 0; maxmn + 1 <= minmn; maxmn++) {
      Y->data[jpvt->data[maxmn] - 1] -= Y->data[jpvt->data[minmn] - 1] *
        b_A->data[maxmn + b_A->size[0] * minmn];
    }
  }

  emxFree_int32_T(&jpvt);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (qrsolve.c) */
