/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "repmat.h"
#include "pchip.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo kf_emlrtRSI = { 42, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo lf_emlrtRSI = { 40, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo mf_emlrtRSI = { 12, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtMCInfo cb_emlrtMCI = { 24, 5, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtMCInfo db_emlrtMCI = { 57, 5, "eml_assert_valid_size_arg",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_assert_valid_size_arg.m" };

static emlrtMCInfo eb_emlrtMCI = { 56, 15, "eml_assert_valid_size_arg",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_assert_valid_size_arg.m" };

static emlrtRTEInfo yb_emlrtRTEI = { 30, 1, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtDCInfo v_emlrtDCI = { 15, 14, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", 4 };

static emlrtRSInfo xj_emlrtRSI = { 57, "eml_assert_valid_size_arg",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_assert_valid_size_arg.m" };

static emlrtRSInfo qk_emlrtRSI = { 56, "eml_assert_valid_size_arg",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_assert_valid_size_arg.m" };

static emlrtRSInfo sk_emlrtRSI = { 24, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

/* Function Definitions */

/*
 *
 */
void b_repmat(const emlrtStack *sp, real_T varargin_2, emxArray_real_T *b)
{
  boolean_T p;
  boolean_T guard1 = false;
  const mxArray *y;
  static const int32_T iv39[2] = { 1, 28 };

  const mxArray *m19;
  char_T cv61[28];
  int32_T i;
  static const char_T cv62[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I',
    'n', 'p', 'u', 't' };

  const mxArray *b_y;
  const mxArray *c_y;
  real_T b_varargin_2;
  const mxArray *d_y;
  static const int32_T iv40[2] = { 1, 21 };

  char_T cv63[21];
  static const char_T cv64[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  boolean_T b2;
  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  if ((varargin_2 != muDoubleScalarFloor(varargin_2)) || muDoubleScalarIsInf
      (varargin_2)) {
    p = false;
  } else {
    p = true;
  }

  guard1 = false;
  if (p) {
    if ((-2.147483648E+9 > varargin_2) || (2.147483647E+9 < varargin_2)) {
      p = false;
    } else {
      p = true;
    }

    if (p) {
      p = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    p = false;
  }

  if (p) {
  } else {
    y = NULL;
    m19 = emlrtCreateCharArray(2, iv39);
    for (i = 0; i < 28; i++) {
      cv61[i] = cv62[i];
    }

    emlrtInitCharArrayR2013a(&st, 28, m19, cv61);
    emlrtAssign(&y, m19);
    b_y = NULL;
    m19 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)mxGetData(m19) = MIN_int32_T;
    emlrtAssign(&b_y, m19);
    c_y = NULL;
    m19 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)mxGetData(m19) = MAX_int32_T;
    emlrtAssign(&c_y, m19);
    b_st.site = &rk_emlrtRSI;
    c_st.site = &fl_emlrtRSI;
    f_error(&b_st, c_message(&c_st, y, b_y, c_y, &ab_emlrtMCI), &bb_emlrtMCI);
  }

  if (varargin_2 <= 0.0) {
    b_varargin_2 = 0.0;
  } else {
    b_varargin_2 = varargin_2;
  }

  if (2.147483647E+9 >= b_varargin_2) {
  } else {
    d_y = NULL;
    m19 = emlrtCreateCharArray(2, iv40);
    for (i = 0; i < 21; i++) {
      cv63[i] = cv64[i];
    }

    emlrtInitCharArrayR2013a(&st, 21, m19, cv63);
    emlrtAssign(&d_y, m19);
    b_st.site = &qk_emlrtRSI;
    c_st.site = &xj_emlrtRSI;
    f_error(&b_st, b_message(&c_st, d_y, &db_emlrtMCI), &eb_emlrtMCI);
  }

  emlrtNonNegativeCheckFastR2012b(varargin_2, &v_emlrtDCI, sp);
  i = b->size[0] * b->size[1];
  b->size[0] = 4;
  b->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity(sp, (emxArray__common *)b, i, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  if ((int32_T)varargin_2 == 0) {
  } else {
    st.site = &lf_emlrtRSI;
    if (1 > (int32_T)varargin_2) {
      b2 = false;
    } else {
      b2 = ((int32_T)varargin_2 > 2147483646);
    }

    if (b2) {
      b_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 1; i <= (int32_T)varargin_2; i++) {
      ibtile = (i - 1) << 2;
      for (k = 0; k < 4; k++) {
        b->data[ibtile + k] = 1.0 + (((real_T)k + 1.0) - 1.0);
      }
    }
  }
}

/*
 *
 */
void repmat(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *b)
{
  int32_T outsize_idx_1;
  const mxArray *y;
  static const int32_T iv38[2] = { 1, 15 };

  const mxArray *m18;
  char_T cv59[15];
  static const char_T cv60[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  boolean_T overflow;
  int32_T ibmat;
  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  outsize_idx_1 = a->size[1];
  if (outsize_idx_1 == a->size[1]) {
  } else {
    y = NULL;
    m18 = emlrtCreateCharArray(2, iv38);
    for (outsize_idx_1 = 0; outsize_idx_1 < 15; outsize_idx_1++) {
      cv59[outsize_idx_1] = cv60[outsize_idx_1];
    }

    emlrtInitCharArrayR2013a(sp, 15, m18, cv59);
    emlrtAssign(&y, m18);
    st.site = &sk_emlrtRSI;
    f_error(&st, y, &cb_emlrtMCI);
  }

  outsize_idx_1 = b->size[0] * b->size[1];
  b->size[0] = 4;
  b->size[1] = a->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b, outsize_idx_1, (int32_T)sizeof
                    (real_T), &yb_emlrtRTEI);
  outsize_idx_1 = a->size[1];
  if (outsize_idx_1 == 0) {
  } else {
    st.site = &kf_emlrtRSI;
    if (1 > a->size[1]) {
      overflow = false;
    } else {
      overflow = (a->size[1] > 2147483646);
    }

    if (overflow) {
      b_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (outsize_idx_1 = 0; outsize_idx_1 + 1 <= a->size[1]; outsize_idx_1++) {
      ibmat = outsize_idx_1 << 2;
      for (itilerow = 0; itilerow < 4; itilerow++) {
        b->data[ibmat + itilerow] = a->data[outsize_idx_1];
      }
    }
  }
}

/* End of code generation (repmat.c) */
