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
#include "nonlinear.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void b_error(const emlrtStack *sp)
{
  int32_T i2;
  static const char_T varargin_1[39] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'n', 'o', 'n', 'd', 'e', 'c', 'r', 'e', 'a', 's', 'i', 'n', 'g',
    '.' };

  char_T u[39];
  const mxArray *y;
  static const int32_T iv4[2] = { 1, 39 };

  const mxArray *m2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i2 = 0; i2 < 39; i2++) {
    u[i2] = varargin_1[i2];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 39, m2, &u[0]);
  emlrtAssign(&y, m2);
  st.site = &nm_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void c_error(const emlrtStack *sp)
{
  int32_T i3;
  static const char_T varargin_1[40] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'i', 'n', ' ', 'r', 'a', 'n', 'g', 'e', ' ', '[', '0', ',', '1',
    ']', '.' };

  char_T u[40];
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 40 };

  const mxArray *m3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i3 = 0; i3 < 40; i3++) {
    u[i3] = varargin_1[i3];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 40, m3, &u[0]);
  emlrtAssign(&y, m3);
  st.site = &nm_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

/* End of code generation (error.c) */
