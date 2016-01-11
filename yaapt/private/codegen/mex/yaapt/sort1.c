/*
 * sort1.c
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sort1.h"
#include "spec_trk.h"
#include "eml_int_forloop_overflow_check.h"
#include "sortIdx.h"
#include "yaapt_emxutil.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sg_emlrtRSI = { 19, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo tg_emlrtRSI = { 66, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo ch_emlrtRSI = { 527, "sortIdx",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo hl_emlrtRSI = { 48, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo il_emlrtRSI = { 69, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo jl_emlrtRSI = { 70, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo kl_emlrtRSI = { 72, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo ll_emlrtRSI = { 74, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo ml_emlrtRSI = { 77, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo nl_emlrtRSI = { 80, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo ol_emlrtRSI = { 82, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo pl_emlrtRSI = { 49, "prodsize",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\prodsize.m" };

static emlrtRSInfo ql_emlrtRSI = { 54, "prodsize",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\prodsize.m" };

static emlrtRTEInfo ed_emlrtRTEI = { 1, 20, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRTEInfo nd_emlrtRTEI = { 50, 1, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRTEInfo if_emlrtRTEI = { 23, 15, "assertValidDim",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidDim.m" };

static emlrtDCInfo sb_emlrtDCI = { 50, 62, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m", 4 };

static emlrtDCInfo tb_emlrtDCI = { 68, 32, "sort",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m", 4 };

/* Function Declarations */
static void b_sort(const emlrtStack *sp, real_T x[100], int32_T idx[100]);
static void d_sort(const emlrtStack *sp, real_T x[20], int32_T idx[20]);
static void f_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx);

/* Function Definitions */

/*
 *
 */
static void b_sort(const emlrtStack *sp, real_T x[100], int32_T idx[100])
{
  real_T x4[4];
  int8_T idx4[4];
  int32_T m;
  real_T xwork[100];
  int32_T nNaNs;
  int32_T ib;
  int32_T k;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int8_T perm[4];
  int32_T iwork[100];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ug_emlrtRSI;
  c_st.site = &vg_emlrtRSI;
  memset(&idx[0], 0, 100U * sizeof(int32_T));
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  memset(&xwork[0], 0, 100U * sizeof(real_T));
  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 100; k++) {
    if (muDoubleScalarIsNaN(x[k])) {
      idx[99 - nNaNs] = k + 1;
      xwork[99 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (int8_T)(k + 1);
      x4[ib - 1] = x[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] >= x4[1]) {
          m = 1;
          i2 = 2;
        } else {
          m = 2;
          i2 = 1;
        }

        if (x4[2] >= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        if (x4[m - 1] >= x4[i3 - 1]) {
          if (x4[i2 - 1] >= x4[i3 - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (x4[i2 - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else if (x4[m - 1] >= x4[i4 - 1]) {
          if (x4[i2 - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          perm[0] = (int8_T)i3;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)m;
          perm[3] = (int8_T)i2;
        }

        idx[ib - 3] = idx4[perm[0] - 1];
        idx[ib - 2] = idx4[perm[1] - 1];
        idx[ib - 1] = idx4[perm[2] - 1];
        idx[ib] = idx4[perm[3] - 1];
        x[ib - 3] = x4[perm[0] - 1];
        x[ib - 2] = x4[perm[1] - 1];
        x[ib - 1] = x4[perm[2] - 1];
        x[ib] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    for (m = 0; m < 4; m++) {
      perm[m] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    d_st.site = &yg_emlrtRSI;
    if (ib > 2147483646) {
      e_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (k = 100; k - 99 <= ib; k++) {
      idx[(k - nNaNs) - ib] = idx4[perm[k - 100] - 1];
      x[(k - nNaNs) - ib] = x4[perm[k - 100] - 1];
    }
  }

  m = asr_s32(nNaNs, 1U);
  d_st.site = &ah_emlrtRSI;
  for (k = 1; k <= m; k++) {
    ib = (int8_T)idx[(k - nNaNs) + 99];
    idx[(k - nNaNs) + 99] = (int8_T)idx[100 - k];
    idx[100 - k] = ib;
    x[(k - nNaNs) + 99] = xwork[100 - k];
    x[100 - k] = xwork[(k - nNaNs) + 99];
  }

  if ((nNaNs & 1) != 0) {
    x[(m - nNaNs) + 100] = xwork[(m - nNaNs) + 100];
  }

  memset(&iwork[0], 0, 100U * sizeof(int32_T));
  if (100 - nNaNs > 1) {
    c_st.site = &wg_emlrtRSI;
    merge_block(&c_st, idx, x, 0, 100 - nNaNs, 2, iwork, xwork);
  }

  if ((nNaNs > 0) && (100 - nNaNs > 0)) {
    c_st.site = &xg_emlrtRSI;
    d_st.site = &hh_emlrtRSI;
    if (nNaNs > 2147483646) {
      e_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (k = 100; k - 99 <= nNaNs; k++) {
      xwork[k - 100] = x[k - nNaNs];
      iwork[k - 100] = idx[k - nNaNs];
    }

    d_st.site = &ih_emlrtRSI;
    for (k = 99 - nNaNs; k + 1 > 0; k--) {
      x[nNaNs + k] = x[k];
      idx[nNaNs + k] = idx[k];
    }

    d_st.site = &jh_emlrtRSI;
    for (k = 0; k + 1 <= nNaNs; k++) {
      x[k] = xwork[k];
      idx[k] = iwork[k];
    }
  }
}

/*
 *
 */
static void d_sort(const emlrtStack *sp, real_T x[20], int32_T idx[20])
{
  real_T x4[4];
  int8_T idx4[4];
  int32_T m;
  real_T xwork[20];
  int32_T nNaNs;
  int32_T ib;
  int32_T k;
  int32_T bLen;
  int32_T nPairs;
  int32_T i4;
  int8_T perm[4];
  int32_T iwork[20];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ug_emlrtRSI;
  c_st.site = &vg_emlrtRSI;
  memset(&idx[0], 0, 20U * sizeof(int32_T));
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  memset(&xwork[0], 0, 20U * sizeof(real_T));
  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 20; k++) {
    if (muDoubleScalarIsNaN(x[k])) {
      idx[19 - nNaNs] = k + 1;
      xwork[19 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (int8_T)(k + 1);
      x4[ib - 1] = x[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] >= x4[1]) {
          m = 1;
          bLen = 2;
        } else {
          m = 2;
          bLen = 1;
        }

        if (x4[2] >= x4[3]) {
          nPairs = 3;
          i4 = 4;
        } else {
          nPairs = 4;
          i4 = 3;
        }

        if (x4[m - 1] >= x4[nPairs - 1]) {
          if (x4[bLen - 1] >= x4[nPairs - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)bLen;
            perm[2] = (int8_T)nPairs;
            perm[3] = (int8_T)i4;
          } else if (x4[bLen - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)nPairs;
            perm[2] = (int8_T)bLen;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)nPairs;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)bLen;
          }
        } else if (x4[m - 1] >= x4[i4 - 1]) {
          if (x4[bLen - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)nPairs;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)bLen;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)nPairs;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)bLen;
          }
        } else {
          perm[0] = (int8_T)nPairs;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)m;
          perm[3] = (int8_T)bLen;
        }

        idx[ib - 3] = idx4[perm[0] - 1];
        idx[ib - 2] = idx4[perm[1] - 1];
        idx[ib - 1] = idx4[perm[2] - 1];
        idx[ib] = idx4[perm[3] - 1];
        x[ib - 3] = x4[perm[0] - 1];
        x[ib - 2] = x4[perm[1] - 1];
        x[ib - 1] = x4[perm[2] - 1];
        x[ib] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    for (m = 0; m < 4; m++) {
      perm[m] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    d_st.site = &yg_emlrtRSI;
    if (ib > 2147483646) {
      e_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (k = 20; k - 19 <= ib; k++) {
      idx[(k - nNaNs) - ib] = idx4[perm[k - 20] - 1];
      x[(k - nNaNs) - ib] = x4[perm[k - 20] - 1];
    }
  }

  m = asr_s32(nNaNs, 1U);
  d_st.site = &ah_emlrtRSI;
  for (k = 1; k <= m; k++) {
    ib = (int8_T)idx[(k - nNaNs) + 19];
    idx[(k - nNaNs) + 19] = (int8_T)idx[20 - k];
    idx[20 - k] = ib;
    x[(k - nNaNs) + 19] = xwork[20 - k];
    x[20 - k] = xwork[(k - nNaNs) + 19];
  }

  if ((nNaNs & 1) != 0) {
    x[(m - nNaNs) + 20] = xwork[(m - nNaNs) + 20];
  }

  memset(&iwork[0], 0, 20U * sizeof(int32_T));
  if (20 - nNaNs > 1) {
    c_st.site = &wg_emlrtRSI;
    memset(&iwork[0], 0, 20U * sizeof(int32_T));
    nPairs = asr_s32(20 - nNaNs, 2U);
    bLen = 4;
    while (nPairs > 1) {
      if ((nPairs & 1) != 0) {
        nPairs--;
        ib = bLen * nPairs;
        m = 20 - (nNaNs + ib);
        if (m > bLen) {
          d_st.site = &bh_emlrtRSI;
          b_merge(&d_st, idx, x, ib, bLen, m - bLen, iwork, xwork);
        }
      }

      ib = bLen << 1;
      nPairs = asr_s32(nPairs, 1U);
      d_st.site = &ch_emlrtRSI;
      for (k = 1; k <= nPairs; k++) {
        d_st.site = &dh_emlrtRSI;
        b_merge(&d_st, idx, x, (k - 1) * ib, bLen, bLen, iwork, xwork);
      }

      bLen = ib;
    }

    if (20 - nNaNs > bLen) {
      d_st.site = &eh_emlrtRSI;
      b_merge(&d_st, idx, x, 0, bLen, 20 - (nNaNs + bLen), iwork, xwork);
    }
  }

  if ((nNaNs > 0) && (20 - nNaNs > 0)) {
    c_st.site = &xg_emlrtRSI;
    d_st.site = &hh_emlrtRSI;
    if (nNaNs > 2147483646) {
      e_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (k = 20; k - 19 <= nNaNs; k++) {
      xwork[k - 20] = x[k - nNaNs];
      iwork[k - 20] = idx[k - nNaNs];
    }

    d_st.site = &ih_emlrtRSI;
    for (k = 19 - nNaNs; k + 1 > 0; k--) {
      x[nNaNs + k] = x[k];
      idx[nNaNs + k] = idx[k];
    }

    d_st.site = &jh_emlrtRSI;
    for (k = 0; k + 1 <= nNaNs; k++) {
      x[k] = xwork[k];
      idx[k] = iwork[k];
    }
  }
}

/*
 *
 */
static void f_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx)
{
  int32_T i45;
  emxArray_real_T *vwork;
  int32_T pagesize;
  uint32_T uv7[2];
  uint32_T u0;
  int32_T vstride;
  boolean_T b22;
  int32_T k;
  int32_T npages;
  boolean_T b23;
  int32_T i;
  emxArray_int32_T *iidx;
  int32_T pageoffset;
  boolean_T b24;
  int32_T j;
  int32_T idx0;
  boolean_T b25;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &hl_emlrtRSI;
  if (dim >= 1) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &if_emlrtRTEI,
      "Coder:MATLAB:getdimarg_dimensionMustBePositiveInteger", 0);
  }

  if (dim <= 2) {
    i45 = x->size[dim - 1];
  } else {
    i45 = 1;
  }

  emxInit_real_T1(sp, &vwork, 1, &nd_emlrtRTEI, true);
  if (!(i45 > 0)) {
    emlrtNonNegativeCheckR2012b(i45, &sb_emlrtDCI, sp);
  }

  pagesize = vwork->size[0];
  vwork->size[0] = i45;
  emxEnsureCapacity(sp, (emxArray__common *)vwork, pagesize, (int32_T)sizeof
                    (real_T), &ed_emlrtRTEI);
  for (pagesize = 0; pagesize < 2; pagesize++) {
    u0 = (uint32_T)x->size[pagesize];
    if (!(u0 > 0U)) {
      emlrtNonNegativeCheckR2012b(0.0, &tb_emlrtDCI, sp);
    }

    uv7[pagesize] = u0;
  }

  pagesize = idx->size[0] * idx->size[1];
  idx->size[0] = (int32_T)uv7[0];
  idx->size[1] = (int32_T)uv7[1];
  emxEnsureCapacity(sp, (emxArray__common *)idx, pagesize, (int32_T)sizeof
                    (int32_T), &ed_emlrtRTEI);
  st.site = &il_emlrtRSI;
  if (dim > 2) {
    vstride = x->size[0] * x->size[1];
  } else {
    vstride = 1;
    b_st.site = &pl_emlrtRSI;
    if (1 > dim - 1) {
      b22 = false;
    } else {
      b22 = (dim - 1 > 2147483646);
    }

    if (b22) {
      c_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 1; k < dim; k++) {
      if (k <= 2) {
        pagesize = x->size[k - 1];
      } else {
        pagesize = 1;
      }

      vstride *= pagesize;
    }
  }

  st.site = &jl_emlrtRSI;
  if (dim > 2) {
    npages = 1;
  } else {
    npages = 1;
    b_st.site = &ql_emlrtRSI;
    for (k = dim; k + 1 < 3; k++) {
      pagesize = x->size[k];
      npages *= pagesize;
    }
  }

  pagesize = i45 * vstride;
  st.site = &kl_emlrtRSI;
  if (1 > npages) {
    b23 = false;
  } else {
    b23 = (npages > 2147483646);
  }

  if (b23) {
    b_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&b_st, true);
  }

  i = 1;
  emxInit_int32_T(sp, &iidx, 1, &ed_emlrtRTEI, true);
  while (i <= npages) {
    pageoffset = (i - 1) * pagesize;
    st.site = &ll_emlrtRSI;
    if (1 > vstride) {
      b24 = false;
    } else {
      b24 = (vstride > 2147483646);
    }

    if (b24) {
      b_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (j = 0; j + 1 <= vstride; j++) {
      idx0 = pageoffset + j;
      st.site = &ml_emlrtRSI;
      if (1 > i45) {
        b25 = false;
      } else {
        b25 = (i45 > 2147483646);
      }

      if (b25) {
        b_st.site = &ib_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (k = 0; k + 1 <= i45; k++) {
        vwork->data[k] = x->data[idx0 + k * vstride];
      }

      st.site = &nl_emlrtRSI;
      sortIdx(&st, vwork, iidx);
      st.site = &ol_emlrtRSI;
      for (k = 0; k + 1 <= i45; k++) {
        x->data[idx0 + k * vstride] = vwork->data[k];
        idx->data[idx0 + k * vstride] = iidx->data[k];
      }
    }

    i++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void c_sort(const emlrtStack *sp, real_T x[20], int32_T idx[20])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sg_emlrtRSI;
  d_sort(&st, x, idx);
}

/*
 *
 */
void e_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  int32_T i44;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  i44 = 2;
  if (x->size[0] != 1) {
    i44 = 1;
  }

  st.site = &sg_emlrtRSI;
  f_sort(&st, x, i44, idx);
}

/*
 *
 */
void sort(const emlrtStack *sp, real_T x[100], int32_T idx[100])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sg_emlrtRSI;
  b_sort(&st, x, idx);
}

/* End of code generation (sort1.c) */
