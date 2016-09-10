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
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtMCInfo c_emlrtMCI = { 14, 25, "warning",
  "F:\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo d_emlrtMCI = { 14, 9, "warning",
  "F:\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtRSInfo hq_emlrtRSI = { 14, "warning",
  "F:\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
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
  const mxArray *m17;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m17, 4, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m15;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m15, 2, pArrays, "feval", true, location);
}

/*
 *
 */
void b_warning(const emlrtStack *sp, int32_T varargin_1, const char_T
               varargin_2[14])
{
  int32_T i12;
  const mxArray *y;
  char_T u[7];
  static const char_T cv3[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m6;
  static const int32_T iv23[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv4[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv24[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[32];
  static const char_T msgID[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e',
    'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  static const int32_T iv25[2] = { 1, 32 };

  const mxArray *d_y;
  const mxArray *e_y;
  char_T d_u[14];
  static const int32_T iv26[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i12 = 0; i12 < 7; i12++) {
    u[i12] = cv3[i12];
  }

  y = NULL;
  m6 = emlrtCreateCharArray(2, iv23);
  emlrtInitCharArrayR2013a(sp, 7, m6, &u[0]);
  emlrtAssign(&y, m6);
  for (i12 = 0; i12 < 7; i12++) {
    b_u[i12] = cv4[i12];
  }

  b_y = NULL;
  m6 = emlrtCreateCharArray(2, iv24);
  emlrtInitCharArrayR2013a(sp, 7, m6, &b_u[0]);
  emlrtAssign(&b_y, m6);
  for (i12 = 0; i12 < 32; i12++) {
    c_u[i12] = msgID[i12];
  }

  c_y = NULL;
  m6 = emlrtCreateCharArray(2, iv25);
  emlrtInitCharArrayR2013a(sp, 32, m6, &c_u[0]);
  emlrtAssign(&c_y, m6);
  d_y = NULL;
  m6 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m6) = varargin_1;
  emlrtAssign(&d_y, m6);
  for (i12 = 0; i12 < 14; i12++) {
    d_u[i12] = varargin_2[i12];
  }

  e_y = NULL;
  m6 = emlrtCreateCharArray(2, iv26);
  emlrtInitCharArrayR2013a(sp, 14, m6, &d_u[0]);
  emlrtAssign(&e_y, m6);
  st.site = &hq_emlrtRSI;
  b_feval(&st, y, c_feval(&st, b_y, c_y, d_y, e_y, &c_emlrtMCI), &d_emlrtMCI);
}

/*
 *
 */
void warning(const emlrtStack *sp)
{
  int32_T i11;
  const mxArray *y;
  char_T u[7];
  static const char_T cv1[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m5;
  static const int32_T iv20[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv2[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv21[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[27];
  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  static const int32_T iv22[2] = { 1, 27 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i11 = 0; i11 < 7; i11++) {
    u[i11] = cv1[i11];
  }

  y = NULL;
  m5 = emlrtCreateCharArray(2, iv20);
  emlrtInitCharArrayR2013a(sp, 7, m5, &u[0]);
  emlrtAssign(&y, m5);
  for (i11 = 0; i11 < 7; i11++) {
    b_u[i11] = cv2[i11];
  }

  b_y = NULL;
  m5 = emlrtCreateCharArray(2, iv21);
  emlrtInitCharArrayR2013a(sp, 7, m5, &b_u[0]);
  emlrtAssign(&b_y, m5);
  for (i11 = 0; i11 < 27; i11++) {
    c_u[i11] = msgID[i11];
  }

  c_y = NULL;
  m5 = emlrtCreateCharArray(2, iv22);
  emlrtInitCharArrayR2013a(sp, 27, m5, &c_u[0]);
  emlrtAssign(&c_y, m5);
  st.site = &hq_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &c_emlrtMCI), &d_emlrtMCI);
}

/* End of code generation (warning.c) */
