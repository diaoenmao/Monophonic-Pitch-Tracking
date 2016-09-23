/*
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "indexShapeCheck.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 18, "indexShapeCheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"
};

static emlrtRSInfo bj_emlrtRSI = { 14, "indexShapeCheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"
};

static emlrtRSInfo cj_emlrtRSI = { 80, "indexShapeCheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"
};

static emlrtRTEInfo gf_emlrtRTEI = { 88, 9, "indexShapeCheck",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"
};

/* Function Definitions */
void b_indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
  indexSize[2])
{
  boolean_T nonSingletonDimFound;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nonSingletonDimFound = false;
  if (matrixSize != 1) {
    nonSingletonDimFound = true;
  }

  if (nonSingletonDimFound) {
    nonSingletonDimFound = false;
    if (indexSize[0] != 1) {
      nonSingletonDimFound = true;
    }

    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }

    if (nonSingletonDimFound) {
      st.site = &bj_emlrtRSI;
      if (((matrixSize == 1) != (indexSize[0] == 1)) || (indexSize[1] != 1)) {
        nonSingletonDimFound = true;
      } else {
        nonSingletonDimFound = false;
      }

      b_st.site = &cj_emlrtRSI;
      if (!nonSingletonDimFound) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &gf_emlrtRTEI,
          "Coder:FE:PotentialMatrixMatrix", 0);
      }
    }
  }
}

void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
                     indexSize[2])
{
  boolean_T guard1 = false;
  boolean_T nonSingletonDimFound;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  guard1 = false;
  if (!(matrixSize != 1)) {
    nonSingletonDimFound = false;
    if (indexSize[0] != 1) {
      nonSingletonDimFound = true;
    }

    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }

    if (nonSingletonDimFound) {
      nonSingletonDimFound = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    nonSingletonDimFound = false;
  }

  st.site = &ub_emlrtRSI;
  if (!nonSingletonDimFound) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &gf_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.c) */
