/*
 * eml_warning.c
 *
 * Code generation for function 'eml_warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "eml_warning.h"
#include "yaapt_mexutil.h"

/* Variable Definitions */
static emlrtMCInfo d_emlrtMCI = { 16, 13, "eml_warning",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m" };

static emlrtMCInfo e_emlrtMCI = { 16, 5, "eml_warning",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m" };

static emlrtRSInfo jj_emlrtRSI = { 16, "eml_warning",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m" };

/* Function Declarations */
static void warning(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

/* Function Definitions */
static void warning(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "warning", true, location);
}

/*
 *
 */
void eml_warning(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv11[2] = { 1, 27 };

  const mxArray *m4;
  char_T cv17[27];
  int32_T i;
  static const char_T cv18[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m4 = emlrtCreateCharArray(2, iv11);
  for (i = 0; i < 27; i++) {
    cv17[i] = cv18[i];
  }

  emlrtInitCharArrayR2013a(sp, 27, m4, cv17);
  emlrtAssign(&y, m4);
  st.site = &jj_emlrtRSI;
  warning(&st, b_message(&st, y, &d_emlrtMCI), &e_emlrtMCI);
}

/* End of code generation (eml_warning.c) */
