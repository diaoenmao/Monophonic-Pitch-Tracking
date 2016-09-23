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
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "assertValidSizeArg.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo vi_emlrtRSI = { 112, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo wi_emlrtRSI = { 119, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRTEInfo wc_emlrtRTEI = { 1, 14, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtDCInfo kb_emlrtDCI = { 21, 14, "repmat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", 4 };

/* Function Definitions */
void b_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_2,
              emxArray_real_T *b)
{
  boolean_T p;
  boolean_T guard1 = false;
  real_T b_varargin_2;
  int32_T outsize_idx_0;
  int32_T jtilecol;
  const mxArray *y;
  char_T u[15];
  static const char_T cv6[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *m7;
  static const int32_T iv37[2] = { 1, 15 };

  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&st, &cg_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_2 <= 0.0) {
    b_varargin_2 = 0.0;
  } else {
    b_varargin_2 = varargin_2;
  }

  if (2.147483647E+9 >= b_varargin_2) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &dg_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }

  if (!(varargin_2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, &kb_emlrtDCI, sp);
  }

  outsize_idx_0 = a->size[0];
  if (outsize_idx_0 == a->size[0]) {
  } else {
    for (jtilecol = 0; jtilecol < 15; jtilecol++) {
      u[jtilecol] = cv6[jtilecol];
    }

    y = NULL;
    m7 = emlrtCreateCharArray(2, iv37);
    emlrtInitCharArrayR2013a(sp, 15, m7, &u[0]);
    emlrtAssign(&y, m7);
    st.site = &so_emlrtRSI;
    n_error(&st, y, &b_emlrtMCI);
  }

  jtilecol = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  b->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity(sp, (emxArray__common *)b, jtilecol, (int32_T)sizeof(real_T),
                    &wc_emlrtRTEI);
  if (!(a->size[0] == 0)) {
    if (outsize_idx_0 == 0) {
      p = true;
    } else if ((int32_T)varargin_2 == 0) {
      p = true;
    } else {
      p = false;
    }

    if (!p) {
      outsize_idx_0 = a->size[0];
      st.site = &vi_emlrtRSI;
      if ((!(1 > (int32_T)varargin_2)) && ((int32_T)varargin_2 > 2147483646)) {
        b_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (jtilecol = 1; jtilecol <= (int32_T)varargin_2; jtilecol++) {
        ibtile = (jtilecol - 1) * outsize_idx_0;
        st.site = &wi_emlrtRSI;
        if (outsize_idx_0 > 2147483646) {
          b_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (k = 1; k <= outsize_idx_0; k++) {
          b->data[(ibtile + k) - 1] = a->data[k - 1];
        }
      }
    }
  }
}

void repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_1,
            emxArray_real_T *b)
{
  int32_T outsize_idx_1;
  int32_T ibmat;
  const mxArray *y;
  char_T u[15];
  static const char_T cv5[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *m6;
  static const int32_T iv36[2] = { 1, 15 };

  boolean_T overflow;
  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_assertValidSizeArg(&st, varargin_1);
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &kb_emlrtDCI, sp);
  }

  outsize_idx_1 = a->size[1];
  if (outsize_idx_1 == a->size[1]) {
  } else {
    for (ibmat = 0; ibmat < 15; ibmat++) {
      u[ibmat] = cv5[ibmat];
    }

    y = NULL;
    m6 = emlrtCreateCharArray(2, iv36);
    emlrtInitCharArrayR2013a(sp, 15, m6, &u[0]);
    emlrtAssign(&y, m6);
    st.site = &so_emlrtRSI;
    n_error(&st, y, &b_emlrtMCI);
  }

  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)b, ibmat, (int32_T)sizeof(real_T),
                    &wc_emlrtRTEI);
  if (!(a->size[1] == 0)) {
    if ((int32_T)varargin_1 == 0) {
      overflow = true;
    } else if (outsize_idx_1 == 0) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (!overflow) {
      st.site = &ti_emlrtRSI;
      overflow = (a->size[1] > 2147483646);
      if (overflow) {
        b_st.site = &ab_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (outsize_idx_1 = 0; outsize_idx_1 + 1 <= a->size[1]; outsize_idx_1++)
      {
        ibmat = outsize_idx_1 * (int32_T)varargin_1;
        st.site = &ui_emlrtRSI;
        if ((!(1 > (int32_T)varargin_1)) && ((int32_T)varargin_1 > 2147483646))
        {
          b_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (itilerow = 1; itilerow <= (int32_T)varargin_1; itilerow++) {
          b->data[(ibmat + itilerow) - 1] = a->data[outsize_idx_1];
        }
      }
    }
  }
}

/* End of code generation (repmat.c) */
