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

/* Function Definitions */

/*
 *
 */
void b_error(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 40 };

  const mxArray *m2;
  char_T cv11[40];
  int32_T i;
  static const char_T cv12[40] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c', 'i',
    'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e',
    ' ', 'i', 'n', ' ', 'r', 'a', 'n', 'g', 'e', ' ', '[', '0', ',', '1', ']',
    '.' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m2 = emlrtCreateCharArray(2, iv8);
  for (i = 0; i < 40; i++) {
    cv11[i] = cv12[i];
  }

  emlrtInitCharArrayR2013a(sp, 40, m2, cv11);
  emlrtAssign(&y, m2);
  st.site = &dk_emlrtRSI;
  f_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void c_error(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv56[2] = { 1, 29 };

  const mxArray *m27;
  char_T cv88[29];
  int32_T i;
  static const char_T cv89[29] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ', 'D',
    'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ', 'N',
    '>', '1', '0', '0', '0' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m27 = emlrtCreateCharArray(2, iv56);
  for (i = 0; i < 29; i++) {
    cv88[i] = cv89[i];
  }

  emlrtInitCharArrayR2013a(sp, 29, m27, cv88);
  emlrtAssign(&y, m27);
  st.site = &dk_emlrtRSI;
  f_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void d_error(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv57[2] = { 1, 30 };

  const mxArray *m28;
  char_T cv90[30];
  int32_T i;
  static const char_T cv91[30] = { 'C', 'C', 'O', 'S', 'T', '>', '1', '.', '0',
    'E', '+', '5', '0', ',', ' ', 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ', 'D',
    'y', 'n', 'a', 'm', 'i', 'c' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m28 = emlrtCreateCharArray(2, iv57);
  for (i = 0; i < 30; i++) {
    cv90[i] = cv91[i];
  }

  emlrtInitCharArrayR2013a(sp, 30, m28, cv90);
  emlrtAssign(&y, m28);
  st.site = &dk_emlrtRSI;
  f_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void e_error(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv83[2] = { 1, 28 };

  const mxArray *m36;
  char_T cv122[28];
  int32_T i;
  static const char_T cv123[28] = { 'S', 't', 'o', 'p', ' ', 'i', 'n', ' ', 'D',
    'y', 'n', 'a', 'm', 'i', 'c', ' ', 'd', 'u', 'e', ' ', 't', 'o', ' ', 'M',
    '>', '1', '0', '0' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m36 = emlrtCreateCharArray(2, iv83);
  for (i = 0; i < 28; i++) {
    cv122[i] = cv123[i];
  }

  emlrtInitCharArrayR2013a(sp, 28, m36, cv122);
  emlrtAssign(&y, m36);
  st.site = &dk_emlrtRSI;
  f_error(&st, y, &emlrtMCI);
}

/*
 *
 */
void error(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv7[2] = { 1, 39 };

  const mxArray *m1;
  char_T cv9[39];
  int32_T i;
  static const char_T cv10[39] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c', 'i',
    'e', 's', ' ', 'i', 'n', ' ', 'F', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e',
    ' ', 'n', 'o', 'n', 'd', 'e', 'c', 'r', 'e', 'a', 's', 'i', 'n', 'g', '.' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m1 = emlrtCreateCharArray(2, iv7);
  for (i = 0; i < 39; i++) {
    cv9[i] = cv10[i];
  }

  emlrtInitCharArrayR2013a(sp, 39, m1, cv9);
  emlrtAssign(&y, m1);
  st.site = &dk_emlrtRSI;
  f_error(&st, y, &emlrtMCI);
}

/* End of code generation (error.c) */
