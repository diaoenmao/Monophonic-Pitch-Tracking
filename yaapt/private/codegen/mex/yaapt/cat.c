/*
 * cat.c
 *
 * Code generation for function 'cat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cat.h"
#include "eml_error.h"
#include "yaapt_emxutil.h"
#include "eml_warning.h"
#include "yaapt_mexutil.h"

/* Variable Definitions */
static emlrtRSInfo ti_emlrtRSI = { 29, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtMCInfo vb_emlrtMCI = { 32, 13, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtMCInfo wb_emlrtMCI = { 31, 23, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRTEInfo cd_emlrtRTEI = { 26, 5, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRSInfo kj_emlrtRSI = { 32, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRSInfo ek_emlrtRSI = { 31, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

/* Function Definitions */

/*
 *
 */
void cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
         emxArray_real_T *varargin_2, emxArray_real_T *y)
{
  uint32_T sz1[2];
  int32_T i;
  uint32_T ysize[2];
  int32_T exitg2;
  boolean_T p;
  const mxArray *b_y;
  static const int32_T iv82[2] = { 1, 39 };

  const mxArray *m36;
  char_T cv122[39];
  static const char_T cv123[39] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'c', 'a', 't', 'e', 'n', 'a', 't', 'e', '_', 'd', 'i',
    'm', 'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  int32_T exitg1;
  const mxArray *c_y;
  static const int32_T iv83[2] = { 1, 39 };

  int32_T iy;
  int32_T ix;
  int32_T l;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  for (i = 0; i < 2; i++) {
    sz1[i] = (uint32_T)varargin_1->size[i];
  }

  for (i = 0; i < 2; i++) {
    ysize[i] = sz1[i];
  }

  ysize[0] += 3U;
  i = y->size[0] * y->size[1];
  y->size[0] = (int32_T)ysize[0];
  y->size[1] = (int32_T)ysize[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                    &cd_emlrtRTEI);
  if (varargin_1->size[1] == 0) {
    st.site = &ti_emlrtRSI;
    e_eml_error(&st);
  }

  i = 0;
  do {
    exitg2 = 0;
    if (i < 2) {
      if ((i + 1 != 1) && ((int32_T)ysize[1] != varargin_1->size[1])) {
        p = false;
        exitg2 = 1;
      } else {
        i++;
      }
    } else {
      p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (p) {
  } else {
    b_y = NULL;
    m36 = emlrtCreateCharArray(2, iv82);
    for (i = 0; i < 39; i++) {
      cv122[i] = cv123[i];
    }

    emlrtInitCharArrayR2013a(sp, 39, m36, cv122);
    emlrtAssign(&b_y, m36);
    st.site = &ek_emlrtRSI;
    b_st.site = &kj_emlrtRSI;
    f_error(&st, b_message(&b_st, b_y, &vb_emlrtMCI), &wb_emlrtMCI);
  }

  if (varargin_2->size[1] == 0) {
    st.site = &ti_emlrtRSI;
    e_eml_error(&st);
  }

  i = 0;
  do {
    exitg1 = 0;
    if (i < 2) {
      if ((i + 1 != 1) && ((int32_T)ysize[1] != varargin_2->size[1])) {
        p = false;
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (p) {
  } else {
    c_y = NULL;
    m36 = emlrtCreateCharArray(2, iv83);
    for (i = 0; i < 39; i++) {
      cv122[i] = cv123[i];
    }

    emlrtInitCharArrayR2013a(sp, 39, m36, cv122);
    emlrtAssign(&c_y, m36);
    st.site = &ek_emlrtRSI;
    b_st.site = &kj_emlrtRSI;
    f_error(&st, b_message(&b_st, c_y, &vb_emlrtMCI), &wb_emlrtMCI);
  }

  ysize[1] = ysize[1];
  iy = 0;
  for (i = 0; i < (int32_T)ysize[1]; i++) {
    ix = i * 3;
    for (l = 0; l < 3; l++) {
      y->data[iy] = varargin_1->data[ix];
      ix++;
      iy++;
    }

    ix = i * 3;
    for (l = 0; l < 3; l++) {
      y->data[iy] = varargin_2->data[ix];
      ix++;
      iy++;
    }
  }
}

/* End of code generation (cat.c) */
