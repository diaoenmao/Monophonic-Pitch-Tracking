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
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "nonlinear.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo dg_emlrtRSI = { 114, "repmat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo eg_emlrtRSI = { 18, "repmat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo fg_emlrtRSI = { 112, "repmat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtMCInfo d_emlrtMCI = { 37, 5, "repmat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRTEInfo rb_emlrtRTEI = { 1, 14, "repmat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtDCInfo x_emlrtDCI = { 21, 14, "repmat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", 4 };

static emlrtRSInfo gm_emlrtRSI = { 37, "repmat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

/* Function Definitions */

/*
 *
 */
void b_repmat(const emlrtStack *sp, real_T varargin_2, emxArray_real_T *b)
{
  boolean_T p;
  boolean_T guard1 = false;
  real_T b_varargin_2;
  int32_T jtilecol;
  boolean_T b5;
  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
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
    emlrtErrorWithMessageIdR2012b(&st, &oe_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_2 <= 0.0) {
    b_varargin_2 = 0.0;
  } else {
    b_varargin_2 = varargin_2;
  }

  if (2.147483647E+9 >= b_varargin_2) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &pe_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }

  if (!(varargin_2 > 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, &x_emlrtDCI, sp);
  }

  jtilecol = b->size[0] * b->size[1];
  b->size[0] = 4;
  b->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity(sp, (emxArray__common *)b, jtilecol, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  if (!((int32_T)varargin_2 == 0)) {
    st.site = &fg_emlrtRSI;
    if (1 > (int32_T)varargin_2) {
      b5 = false;
    } else {
      b5 = ((int32_T)varargin_2 > 2147483646);
    }

    if (b5) {
      b_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (jtilecol = 1; jtilecol <= (int32_T)varargin_2; jtilecol++) {
      ibtile = (jtilecol - 1) << 2;
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
  int32_T ibmat;
  static const char_T cv3[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  char_T u[15];
  const mxArray *y;
  static const int32_T iv21[2] = { 1, 15 };

  const mxArray *m5;
  boolean_T overflow;
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
    for (ibmat = 0; ibmat < 15; ibmat++) {
      u[ibmat] = cv3[ibmat];
    }

    y = NULL;
    m5 = emlrtCreateCharArray(2, iv21);
    emlrtInitCharArrayR2013a(sp, 15, m5, &u[0]);
    emlrtAssign(&y, m5);
    st.site = &gm_emlrtRSI;
    m_error(&st, y, &d_emlrtMCI);
  }

  ibmat = b->size[0] * b->size[1];
  b->size[0] = 4;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)b, ibmat, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  if ((!(a->size[1] == 0)) && (!(outsize_idx_1 == 0))) {
    st.site = &dg_emlrtRSI;
    overflow = (a->size[1] > 2147483646);
    if (overflow) {
      b_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
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
