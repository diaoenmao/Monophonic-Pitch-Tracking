/*
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "rdivide.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "yaapt_mexutil.h"

/* Variable Definitions */
static emlrtRSInfo ef_emlrtRSI = { 15, "rdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

static emlrtRSInfo ff_emlrtRSI = { 9, "eml_div",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_div.m" };

static emlrtMCInfo v_emlrtMCI = { 14, 5, "rdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

static emlrtMCInfo w_emlrtMCI = { 13, 15, "rdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

static emlrtRTEInfo t_emlrtRTEI = { 1, 14, "rdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

static emlrtECInfo nb_emlrtECI = { -1, 1, 1, "div",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\div.p" };

static emlrtRSInfo yj_emlrtRSI = { 14, "rdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

static emlrtRSInfo tk_emlrtRSI = { 13, "rdivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m" };

/* Function Definitions */

/*
 *
 */
void b_rdivide(const real_T x[5776], const real_T y[5776], real_T z[5776])
{
  int32_T i4;
  for (i4 = 0; i4 < 5776; i4++) {
    z[i4] = x[i4] / y[i4];
  }
}

/*
 *
 */
void c_rdivide(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
               emxArray_real_T *z)
{
  int32_T i10;
  int32_T loop_ub;
  i10 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i10, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  loop_ub = x->size[0];
  for (i10 = 0; i10 < loop_ub; i10++) {
    z->data[i10] = x->data[i10] / y;
  }
}

/*
 *
 */
void d_rdivide(const emlrtStack *sp, real_T x, const emxArray_real_T *y,
               emxArray_real_T *z)
{
  int32_T i15;
  int32_T loop_ub;
  i15 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i15, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  loop_ub = y->size[0];
  for (i15 = 0; i15 < loop_ub; i15++) {
    z->data[i15] = x / y->data[i15];
  }
}

/*
 *
 */
void e_rdivide(const emlrtStack *sp, const emxArray_real_T *x, const
               emxArray_real_T *y, emxArray_real_T *z)
{
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  boolean_T b_p;
  int32_T i;
  boolean_T exitg1;
  const mxArray *b_y;
  static const int32_T iv36[2] = { 1, 15 };

  const mxArray *m16;
  char_T cv55[15];
  static const char_T cv56[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i',
    'm', 'a', 'g', 'r', 'e', 'e' };

  int32_T i18;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  varargin_1[0] = (uint32_T)x->size[0];
  varargin_1[1] = 1U;
  varargin_2[0] = (uint32_T)y->size[0];
  varargin_2[1] = 1U;
  p = false;
  b_p = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    if (!(varargin_1[i] == varargin_2[i])) {
      b_p = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (p) {
  } else {
    b_y = NULL;
    m16 = emlrtCreateCharArray(2, iv36);
    for (i = 0; i < 15; i++) {
      cv55[i] = cv56[i];
    }

    emlrtInitCharArrayR2013a(sp, 15, m16, cv55);
    emlrtAssign(&b_y, m16);
    st.site = &tk_emlrtRSI;
    b_st.site = &yj_emlrtRSI;
    f_error(&st, b_message(&b_st, b_y, &v_emlrtMCI), &w_emlrtMCI);
  }

  st.site = &ef_emlrtRSI;
  c_st.site = &ff_emlrtRSI;
  i18 = x->size[0];
  i = y->size[0];
  emlrtSizeEqCheck1DFastR2012b(i18, i, &nb_emlrtECI, &c_st);
  i18 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(&c_st, (emxArray__common *)z, i18, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  i = x->size[0];
  for (i18 = 0; i18 < i; i18++) {
    z->data[i18] = x->data[i18] / y->data[i18];
  }
}

/*
 *
 */
void rdivide(const real_T x[75], const real_T y[75], real_T z[75])
{
  int32_T i;
  for (i = 0; i < 75; i++) {
    z[i] = x[i] / y[i];
  }
}

/* End of code generation (rdivide.c) */
