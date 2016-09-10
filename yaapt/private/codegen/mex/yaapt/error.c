/*
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "error.h"
#include "path1.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void b_error(const emlrtStack *sp)
{
  int32_T i3;
  const mxArray *y;
  char_T u[39];
  static const char_T varargin_1[39] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'n', 'o', 'n', 'd', 'e', 'c', 'r', 'e', 'a', 's', 'i', 'n', 'g',
    '.' };

  const mxArray *m2;
  static const int32_T iv5[2] = { 1, 39 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i3 = 0; i3 < 39; i3++) {
    u[i3] = varargin_1[i3];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 39, m2, &u[0]);
  emlrtAssign(&y, m2);
  st.site = &fq_emlrtRSI;
  o_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void c_error(const emlrtStack *sp)
{
  int32_T i4;
  const mxArray *y;
  char_T u[40];
  static const char_T varargin_1[40] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'i', 'n', ' ', 'r', 'a', 'n', 'g', 'e', ' ', '[', '0', ',', '1',
    ']', '.' };

  const mxArray *m3;
  static const int32_T iv6[2] = { 1, 40 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i4 = 0; i4 < 40; i4++) {
    u[i4] = varargin_1[i4];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 40, m3, &u[0]);
  emlrtAssign(&y, m3);
  st.site = &fq_emlrtRSI;
  o_error(&st, y, &emlrtMCI);
}

/* End of code generation (error.c) */
