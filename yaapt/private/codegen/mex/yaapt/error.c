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
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void b_error(const emlrtStack *sp)
{
  int32_T i4;
  static const char_T varargin_1[39] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'n', 'o', 'n', 'd', 'e', 'c', 'r', 'e', 'a', 's', 'i', 'n', 'g',
    '.' };

  char_T u[39];
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 39 };

  const mxArray *m2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i4 = 0; i4 < 39; i4++) {
    u[i4] = varargin_1[i4];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 39, m2, &u[0]);
  emlrtAssign(&y, m2);
  st.site = &ho_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void c_error(const emlrtStack *sp)
{
  int32_T i5;
  static const char_T varargin_1[40] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'i', 'n', ' ', 'r', 'a', 'n', 'g', 'e', ' ', '[', '0', ',', '1',
    ']', '.' };

  char_T u[40];
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 40 };

  const mxArray *m3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i5 = 0; i5 < 40; i5++) {
    u[i5] = varargin_1[i5];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 40, m3, &u[0]);
  emlrtAssign(&y, m3);
  st.site = &ho_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

/* End of code generation (error.c) */
