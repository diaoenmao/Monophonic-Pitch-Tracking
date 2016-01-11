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
#include "error1.h"
#include "yaapt_emxutil.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo fl_emlrtRSI = { 36, "cat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRTEInfo dd_emlrtRTEI = { 1, 14, "cat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRTEInfo hf_emlrtRTEI = { 38, 23, "cat",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

/* Function Declarations */
static boolean_T isconsistent(int32_T dim, const emxArray_real_T *y, const
  emxArray_real_T *x);

/* Function Definitions */

/*
 *
 */
static boolean_T isconsistent(int32_T dim, const emxArray_real_T *y, const
  emxArray_real_T *x)
{
  boolean_T p;
  int32_T j;
  int32_T exitg1;
  boolean_T guard1 = false;
  int32_T i40;
  int32_T i41;
  j = 0;
  do {
    exitg1 = 0;
    if (j < 2) {
      guard1 = false;
      if (!(dim == 1 + j)) {
        i40 = y->size[j];
        i41 = x->size[j];
        if (i40 != i41) {
          p = false;
          exitg1 = 1;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        j++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return p;
}

/*
 *
 */
void cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
         emxArray_real_T *varargin_2, emxArray_real_T *y)
{
  uint32_T sz1[2];
  int32_T iy;
  uint32_T ysize[2];
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
                    &dd_emlrtRTEI);
  if (varargin_1->size[1] == 0) {
    st.site = &fl_emlrtRSI;
    l_error(&st);
  }

  if (isconsistent(1, y, varargin_1)) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &hf_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  if (varargin_2->size[1] == 0) {
    st.site = &fl_emlrtRSI;
    l_error(&st);
  }

  if (isconsistent(1, y, varargin_2)) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &hf_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  for (iy = 0; iy < 2; iy++) {
    ysize[iy] = (uint32_T)y->size[iy];
  }

  iy = 1;
  for (i = 0; i < (int32_T)ysize[1]; i++) {
    ix = i * 3;
    for (l = 0; l < 3; l++) {
      y->data[iy - 1] = varargin_1->data[ix];
      ix++;
      iy++;
    }

    ix = i * 3;
    for (l = 0; l < 3; l++) {
      y->data[iy - 1] = varargin_2->data[ix];
      ix++;
      iy++;
    }
  }
}

/* End of code generation (cat.c) */
