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
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo cm_emlrtRSI = { 54, "cat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRSInfo dm_emlrtRSI = { 83, "cat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRTEInfo ee_emlrtRTEI = { 1, 14, "cat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

static emlrtRTEInfo pg_emlrtRTEI = { 56, 23, "cat",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" };

/* Function Definitions */
void cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
         emxArray_real_T *varargin_2, emxArray_real_T *y)
{
  int32_T ysize[2];
  int32_T iy;
  int32_T exitg2;
  boolean_T overflow;
  int32_T exitg1;
  int32_T i;
  int32_T ix;
  int32_T l;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ysize[0] = varargin_1->size[0] + varargin_2->size[0];
  ysize[1] = varargin_1->size[1];
  iy = y->size[0] * y->size[1];
  y->size[0] = ysize[0];
  y->size[1] = ysize[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, iy, (int32_T)sizeof(real_T),
                    &ee_emlrtRTEI);
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    st.site = &cm_emlrtRSI;
    l_error(&st);
  }

  iy = 0;
  do {
    exitg2 = 0;
    if (iy < 2) {
      if ((!(1 == 1 + iy)) && (y->size[iy] != varargin_1->size[iy])) {
        overflow = false;
        exitg2 = 1;
      } else {
        iy++;
      }
    } else {
      overflow = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &pg_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0)) {
    st.site = &cm_emlrtRSI;
    l_error(&st);
  }

  iy = 0;
  do {
    exitg1 = 0;
    if (iy < 2) {
      if ((!(1 == 1 + iy)) && (y->size[iy] != varargin_2->size[iy])) {
        overflow = false;
        exitg1 = 1;
      } else {
        iy++;
      }
    } else {
      overflow = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &pg_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  for (iy = 0; iy < 2; iy++) {
    ysize[iy] = y->size[iy];
  }

  iy = 1;
  for (i = 0; i < ysize[1]; i++) {
    ix = i * varargin_1->size[0];
    st.site = &dm_emlrtRSI;
    overflow = (varargin_1->size[0] > 2147483646);
    if (overflow) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (l = 1; l <= varargin_1->size[0]; l++) {
      y->data[iy - 1] = varargin_1->data[ix];
      ix++;
      iy++;
    }

    ix = i * varargin_2->size[0];
    st.site = &dm_emlrtRSI;
    overflow = (varargin_2->size[0] > 2147483646);
    if (overflow) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (l = 1; l <= varargin_2->size[0]; l++) {
      y->data[iy - 1] = varargin_2->data[ix];
      ix++;
      iy++;
    }
  }
}

/* End of code generation (cat.c) */
