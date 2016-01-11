/*
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "warning.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 14, 25, "warning",
  "F:\\Matlab2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo c_emlrtMCI = { 14, 9, "warning",
  "F:\\Matlab2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtRSInfo em_emlrtRSI = { 14, "warning",
  "F:\\Matlab2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m18;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m18, 4, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m16;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m16, 2, pArrays, "feval", true, location);
}

/*
 *
 */
void b_warning(const emlrtStack *sp, int32_T varargin_1, const char_T
               varargin_2[14])
{
  int32_T i37;
  static const char_T cv7[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv34[2] = { 1, 7 };

  const mxArray *m8;
  static const char_T cv8[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  char_T b_u[7];
  const mxArray *b_y;
  static const int32_T iv35[2] = { 1, 7 };

  static const char_T msgID[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e',
    'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c_u[32];
  const mxArray *c_y;
  static const int32_T iv36[2] = { 1, 32 };

  const mxArray *d_y;
  char_T d_u[14];
  const mxArray *e_y;
  static const int32_T iv37[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i37 = 0; i37 < 7; i37++) {
    u[i37] = cv7[i37];
  }

  y = NULL;
  m8 = emlrtCreateCharArray(2, iv34);
  emlrtInitCharArrayR2013a(sp, 7, m8, &u[0]);
  emlrtAssign(&y, m8);
  for (i37 = 0; i37 < 7; i37++) {
    b_u[i37] = cv8[i37];
  }

  b_y = NULL;
  m8 = emlrtCreateCharArray(2, iv35);
  emlrtInitCharArrayR2013a(sp, 7, m8, &b_u[0]);
  emlrtAssign(&b_y, m8);
  for (i37 = 0; i37 < 32; i37++) {
    c_u[i37] = msgID[i37];
  }

  c_y = NULL;
  m8 = emlrtCreateCharArray(2, iv36);
  emlrtInitCharArrayR2013a(sp, 32, m8, &c_u[0]);
  emlrtAssign(&c_y, m8);
  d_y = NULL;
  m8 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m8) = varargin_1;
  emlrtAssign(&d_y, m8);
  for (i37 = 0; i37 < 14; i37++) {
    d_u[i37] = varargin_2[i37];
  }

  e_y = NULL;
  m8 = emlrtCreateCharArray(2, iv37);
  emlrtInitCharArrayR2013a(sp, 14, m8, &d_u[0]);
  emlrtAssign(&e_y, m8);
  st.site = &em_emlrtRSI;
  b_feval(&st, y, c_feval(&st, b_y, c_y, d_y, e_y, &b_emlrtMCI), &c_emlrtMCI);
}

/*
 *
 */
void warning(const emlrtStack *sp)
{
  int32_T i5;
  static const char_T cv1[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 7 };

  const mxArray *m4;
  static const char_T cv2[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  char_T b_u[7];
  const mxArray *b_y;
  static const int32_T iv9[2] = { 1, 7 };

  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  char_T c_u[27];
  const mxArray *c_y;
  static const int32_T iv10[2] = { 1, 27 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i5 = 0; i5 < 7; i5++) {
    u[i5] = cv1[i5];
  }

  y = NULL;
  m4 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 7, m4, &u[0]);
  emlrtAssign(&y, m4);
  for (i5 = 0; i5 < 7; i5++) {
    b_u[i5] = cv2[i5];
  }

  b_y = NULL;
  m4 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 7, m4, &b_u[0]);
  emlrtAssign(&b_y, m4);
  for (i5 = 0; i5 < 27; i5++) {
    c_u[i5] = msgID[i5];
  }

  c_y = NULL;
  m4 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 27, m4, &c_u[0]);
  emlrtAssign(&c_y, m4);
  st.site = &em_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &b_emlrtMCI), &c_emlrtMCI);
}

/* End of code generation (warning.c) */
