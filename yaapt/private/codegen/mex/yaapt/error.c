/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
  static const int32_T iv7[2] = { 1, 39 };

  const mxArray *m2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i2 = 0; i2 < 39; i2++) {
    u[i2] = varargin_1[i2];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 39, m2, &u[0]);
  emlrtAssign(&y, m2);
  st.site = &dk_emlrtRSI;
  m_error(&st, y, &emlrtMCI);
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
  static const int32_T iv8[2] = { 1, 40 };

  const mxArray *m3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i3 = 0; i3 < 40; i3++) {
    u[i3] = varargin_1[i3];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 40, m3, &u[0]);
  emlrtAssign(&y, m3);
  st.site = &dk_emlrtRSI;
  m_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void g_error(const emlrtStack *sp)
{
  int32_T i22;
  static const char_T varargin_1[29] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ',
    'N', '>', '1', '0', '0', '0' };

  char_T u[29];
  const mxArray *y;
  static const int32_T iv25[2] = { 1, 29 };

  const mxArray *m6;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i22 = 0; i22 < 29; i22++) {
    u[i22] = varargin_1[i22];
  }

  y = NULL;
  m6 = emlrtCreateCharArray(2, iv25);
  emlrtInitCharArrayR2013a(sp, 29, m6, &u[0]);
  emlrtAssign(&y, m6);
  st.site = &dk_emlrtRSI;
  m_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void h_error(const emlrtStack *sp)
{
  int32_T i23;
  static const char_T varargin_1[30] = { 'C', 'C', 'O', 'S', 'T', '>', '1', '.',
    '0', 'E', '+', '5', '0', ',', ' ', 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c' };

  char_T u[30];
  const mxArray *y;
  static const int32_T iv26[2] = { 1, 30 };

  const mxArray *m7;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i23 = 0; i23 < 30; i23++) {
    u[i23] = varargin_1[i23];
  }

  y = NULL;
  m7 = emlrtCreateCharArray(2, iv26);
  emlrtInitCharArrayR2013a(sp, 30, m7, &u[0]);
  emlrtAssign(&y, m7);
  st.site = &dk_emlrtRSI;
  m_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void l_error(const emlrtStack *sp)
{
  int32_T i39;
  static const char_T varargin_1[28] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ',
    'D', 'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ',
    'M', '>', '1', '0', '0' };

  char_T u[28];
  const mxArray *y;
  static const int32_T iv34[2] = { 1, 28 };

  const mxArray *m8;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i39 = 0; i39 < 28; i39++) {
    u[i39] = varargin_1[i39];
  }

  y = NULL;
  m8 = emlrtCreateCharArray(2, iv34);
  emlrtInitCharArrayR2013a(sp, 28, m8, &u[0]);
  emlrtAssign(&y, m8);
  st.site = &dk_emlrtRSI;
  m_error(&st, y, &emlrtMCI);
}

/* End of code generation (error.c) */
