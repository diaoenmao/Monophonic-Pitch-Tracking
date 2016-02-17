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
#include "path1.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = { 18, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo li_emlrtRSI = { 114, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo mi_emlrtRSI = { 117, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo ni_emlrtRSI = { 112, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRSInfo oi_emlrtRSI = { 119, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtMCInfo b_emlrtMCI = { 37, 5, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtRTEInfo pc_emlrtRTEI = { 1, 14, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

static emlrtDCInfo ob_emlrtDCI = { 21, 14, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", 4 };

static emlrtRSInfo io_emlrtRSI = { 37, "repmat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" };

/* Function Definitions */

/*
 *
 */
void b_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_2,
              emxArray_real_T *b)
{
  boolean_T p;
  boolean_T guard1 = false;
  real_T b_varargin_2;
  int32_T outsize_idx_0;
  int32_T jtilecol;
  static const char_T cv7[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  char_T u[15];
  const mxArray *y;
  static const int32_T iv42[2] = { 1, 15 };

  const mxArray *m8;
  boolean_T b10;
  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
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

  if (!(varargin_2 > 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, &ob_emlrtDCI, sp);
  }

  outsize_idx_0 = a->size[0];
  if (outsize_idx_0 == a->size[0]) {
  } else {
    for (jtilecol = 0; jtilecol < 15; jtilecol++) {
      u[jtilecol] = cv7[jtilecol];
    }

    y = NULL;
    m8 = emlrtCreateCharArray(2, iv42);
    emlrtInitCharArrayR2013a(sp, 15, m8, &u[0]);
    emlrtAssign(&y, m8);
    st.site = &io_emlrtRSI;
    n_error(&st, y, &b_emlrtMCI);
  }

  jtilecol = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  b->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity(sp, (emxArray__common *)b, jtilecol, (int32_T)sizeof(real_T),
                    &pc_emlrtRTEI);
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
      st.site = &ni_emlrtRSI;
      if (1 > (int32_T)varargin_2) {
        b10 = false;
      } else {
        b10 = ((int32_T)varargin_2 > 2147483646);
      }

      if (b10) {
        b_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (jtilecol = 1; jtilecol <= (int32_T)varargin_2; jtilecol++) {
        ibtile = (jtilecol - 1) * outsize_idx_0;
        st.site = &oi_emlrtRSI;
        if (outsize_idx_0 > 2147483646) {
          b_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (k = 1; k <= outsize_idx_0; k++) {
          b->data[(ibtile + k) - 1] = a->data[k - 1];
        }
      }
    }
  }
}

/*
 *
 */
void repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_1,
            emxArray_real_T *b)
{
  boolean_T overflow;
  boolean_T guard1 = false;
  real_T b_varargin_1;
  int32_T outsize_idx_1;
  int32_T jcol;
  static const char_T cv6[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  char_T u[15];
  const mxArray *y;
  static const int32_T iv41[2] = { 1, 15 };

  const mxArray *m7;
  boolean_T b9;
  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) || muDoubleScalarIsInf
      (varargin_1)) {
    overflow = false;
  } else {
    overflow = true;
  }

  guard1 = false;
  if (overflow) {
    if ((-2.147483648E+9 > varargin_1) || (2.147483647E+9 < varargin_1)) {
      overflow = false;
    } else {
      overflow = true;
    }

    if (overflow) {
      overflow = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &cg_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }

  if (2.147483647E+9 >= b_varargin_1) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &dg_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }

  if (!(varargin_1 > 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &ob_emlrtDCI, sp);
  }

  outsize_idx_1 = a->size[1];
  if (outsize_idx_1 == a->size[1]) {
  } else {
    for (jcol = 0; jcol < 15; jcol++) {
      u[jcol] = cv6[jcol];
    }

    y = NULL;
    m7 = emlrtCreateCharArray(2, iv41);
    emlrtInitCharArrayR2013a(sp, 15, m7, &u[0]);
    emlrtAssign(&y, m7);
    st.site = &io_emlrtRSI;
    n_error(&st, y, &b_emlrtMCI);
  }

  jcol = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)b, jcol, (int32_T)sizeof(real_T),
                    &pc_emlrtRTEI);
  if (!(a->size[1] == 0)) {
    if ((int32_T)varargin_1 == 0) {
      overflow = true;
    } else if (outsize_idx_1 == 0) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (!overflow) {
      st.site = &li_emlrtRSI;
      overflow = (a->size[1] > 2147483646);
      if (overflow) {
        b_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (jcol = 0; jcol + 1 <= a->size[1]; jcol++) {
        outsize_idx_1 = jcol * (int32_T)varargin_1;
        st.site = &mi_emlrtRSI;
        if (1 > (int32_T)varargin_1) {
          b9 = false;
        } else {
          b9 = ((int32_T)varargin_1 > 2147483646);
        }

        if (b9) {
          b_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (itilerow = 1; itilerow <= (int32_T)varargin_1; itilerow++) {
          b->data[(outsize_idx_1 + itilerow) - 1] = a->data[jcol];
        }
      }
    }
  }
}

/* End of code generation (repmat.c) */
