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
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  int32_T i3;
  const mxArray *y;
  char_T u[39];
  static const char_T varargin_1[39] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'n', 'o', 'n', 'd', 'e', 'c', 'r', 'e', 'a', 's', 'i', 'n', 'g',
    '.' };

  const mxArray *m1;
  static const int32_T iv3[2] = { 1, 39 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i3 = 0; i3 < 39; i3++) {
    u[i3] = varargin_1[i3];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 39, m1, &u[0]);
  emlrtAssign(&y, m1);
  st.site = &to_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

void c_error(const emlrtStack *sp)
{
  int32_T i4;
  const mxArray *y;
  char_T u[40];
  static const char_T varargin_1[40] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c',
    'i', 'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'i', 'n', ' ', 'r', 'a', 'n', 'g', 'e', ' ', '[', '0', ',', '1',
    ']', '.' };

  const mxArray *m2;
  static const int32_T iv4[2] = { 1, 40 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i4 = 0; i4 < 40; i4++) {
    u[i4] = varargin_1[i4];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 40, m2, &u[0]);
  emlrtAssign(&y, m2);
  st.site = &to_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

void i_error(const emlrtStack *sp)
{
  int32_T i35;
  const mxArray *y;
  char_T u[28];
  static const char_T varargin_1[28] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ',
    'M', '>', '1', '0', '0' };

  const mxArray *m8;
  static const int32_T iv39[2] = { 1, 28 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i35 = 0; i35 < 28; i35++) {
    u[i35] = varargin_1[i35];
  }

  y = NULL;
  m8 = emlrtCreateCharArray(2, iv39);
  emlrtInitCharArrayR2013a(sp, 28, m8, &u[0]);
  emlrtAssign(&y, m8);
  st.site = &to_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

void j_error(const emlrtStack *sp)
{
  int32_T i36;
  const mxArray *y;
  char_T u[29];
  static const char_T varargin_1[29] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ',
    'N', '>', '1', '0', '0', '0' };

  const mxArray *m9;
  static const int32_T iv40[2] = { 1, 29 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i36 = 0; i36 < 29; i36++) {
    u[i36] = varargin_1[i36];
  }

  y = NULL;
  m9 = emlrtCreateCharArray(2, iv40);
  emlrtInitCharArrayR2013a(sp, 29, m9, &u[0]);
  emlrtAssign(&y, m9);
  st.site = &to_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

void k_error(const emlrtStack *sp)
{
  int32_T i37;
  const mxArray *y;
  char_T u[30];
  static const char_T varargin_1[30] = { 'C', 'C', 'O', 'S', 'T', '>', '1', '.',
    '0', 'E', '+', '5', '0', ',', ' ', 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c' };

  const mxArray *m10;
  static const int32_T iv41[2] = { 1, 30 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i37 = 0; i37 < 30; i37++) {
    u[i37] = varargin_1[i37];
  }

  y = NULL;
  m10 = emlrtCreateCharArray(2, iv41);
  emlrtInitCharArrayR2013a(sp, 30, m10, &u[0]);
  emlrtAssign(&y, m10);
  st.site = &to_emlrtRSI;
  n_error(&st, y, &emlrtMCI);
}

/* End of code generation (error.c) */
