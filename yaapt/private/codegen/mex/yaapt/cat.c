/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cat.c
 *
 * Code generation for function 'cat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "cat.h"
#include "error1.h"
#include "yaapt_emxutil.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ij_emlrtRSI = { 36, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRTEInfo ad_emlrtRTEI = { 1, 14, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRTEInfo cf_emlrtRTEI = { 38, 23, "cat",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

/* Function Definitions */

/*
 *
 */
void cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
         emxArray_real_T *varargin_2, emxArray_real_T *y)
{
  uint32_T sz1[2];
  int32_T iy;
  uint32_T ysize[2];
  int32_T exitg2;
  boolean_T p;
  int32_T exitg1;
  int32_T i;
  int32_T ix;
  int32_T l;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (iy = 0; iy < 2; iy++) {
    sz1[iy] = (uint32_T)varargin_1->size[iy];
  }

  for (iy = 0; iy < 2; iy++) {
    ysize[iy] = sz1[iy];
  }

  ysize[0] += 3U;
  iy = y->size[0] * y->size[1];
  y->size[0] = (int32_T)ysize[0];
  y->size[1] = (int32_T)ysize[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, iy, (int32_T)sizeof(real_T),
                    &ad_emlrtRTEI);
  if (varargin_1->size[1] == 0) {
    st.site = &ij_emlrtRSI;
    k_error(&st);
  }

  iy = 0;
  do {
    exitg2 = 0;
    if (iy < 2) {
      if ((!(1 == 1 + iy)) && (y->size[iy] != varargin_1->size[iy])) {
        p = false;
        exitg2 = 1;
      } else {
        iy++;
      }
    } else {
      p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &cf_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  if (varargin_2->size[1] == 0) {
    st.site = &ij_emlrtRSI;
    k_error(&st);
  }

  iy = 0;
  do {
    exitg1 = 0;
    if (iy < 2) {
      if ((!(1 == 1 + iy)) && (y->size[iy] != varargin_2->size[iy])) {
        p = false;
        exitg1 = 1;
      } else {
        iy++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &cf_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  for (iy = 0; iy < 2; iy++) {
    ysize[iy] = (uint32_T)y->size[iy];
  }

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
