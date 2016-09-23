/*
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "sortIdx.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo xj_emlrtRSI = { 582, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo yj_emlrtRSI = { 551, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo mm_emlrtRSI = { 339, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo nm_emlrtRSI = { 340, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo om_emlrtRSI = { 348, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo pm_emlrtRSI = { 413, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo qm_emlrtRSI = { 608, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo rm_emlrtRSI = { 610, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo sm_emlrtRSI = { 638, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo ge_emlrtRTEI = { 1, 20, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo ve_emlrtRTEI = { 406, 9, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo we_emlrtRTEI = { 408, 9, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo xe_emlrtRTEI = { 331, 14, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo ye_emlrtRTEI = { 331, 20, "sortIdx",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

/* Function Declarations */
static void b_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
  emxArray_real_T *x, int32_T offset, int32_T n, int32_T preSortLevel,
  emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void c_merge(const emlrtStack *sp, emxArray_int32_T *idx, emxArray_real_T
                    *x, int32_T offset, int32_T np, int32_T nq, emxArray_int32_T
                    *iwork, emxArray_real_T *xwork);
static void c_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
  emxArray_real_T *x, int32_T offset, int32_T n, int32_T preSortLevel,
  emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void d_merge(const emlrtStack *sp, emxArray_int32_T *idx, emxArray_real_T
                    *x, int32_T offset, int32_T np, int32_T nq, emxArray_int32_T
                    *iwork, emxArray_real_T *xwork);
static void merge(const emlrtStack *sp, int32_T idx[100], real_T x[100], int32_T
                  offset, int32_T np, int32_T nq, int32_T iwork[100], real_T
                  xwork[100]);

/* Function Definitions */
static void b_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
  emxArray_real_T *x, int32_T offset, int32_T n, int32_T preSortLevel,
  emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int32_T nPairs;
  int32_T bLen;
  int32_T tailOffset;
  int32_T nTail;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &tj_emlrtRSI;
        c_merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      st.site = &vj_emlrtRSI;
      c_merge(&st, idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen, iwork,
              xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    st.site = &wj_emlrtRSI;
    c_merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void c_merge(const emlrtStack *sp, emxArray_int32_T *idx, emxArray_real_T
                    *x, int32_T offset, int32_T np, int32_T nq, emxArray_int32_T
                    *iwork, emxArray_real_T *xwork)
{
  int32_T n;
  int32_T qend;
  int32_T p;
  int32_T iout;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq == 0) {
  } else {
    n = np + nq;
    st.site = &yj_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (qend = 0; qend + 1 <= n; qend++) {
      iwork->data[qend] = idx->data[offset + qend];
      xwork->data[qend] = x->data[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] >= xwork->data[n]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[n];
        x->data[iout] = xwork->data[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          st.site = &xj_emlrtRSI;
          if ((!(p + 1 > np)) && (np > 2147483646)) {
            b_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          while (p + 1 <= np) {
            idx->data[n + p] = iwork->data[p];
            x->data[n + p] = xwork->data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void c_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
  emxArray_real_T *x, int32_T offset, int32_T n, int32_T preSortLevel,
  emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int32_T nPairs;
  int32_T bLen;
  int32_T tailOffset;
  int32_T nTail;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &tj_emlrtRSI;
        d_merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
                xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      st.site = &vj_emlrtRSI;
      d_merge(&st, idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen, iwork,
              xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    st.site = &wj_emlrtRSI;
    d_merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void d_merge(const emlrtStack *sp, emxArray_int32_T *idx, emxArray_real_T
                    *x, int32_T offset, int32_T np, int32_T nq, emxArray_int32_T
                    *iwork, emxArray_real_T *xwork)
{
  int32_T n;
  int32_T qend;
  int32_T p;
  int32_T iout;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq == 0) {
  } else {
    n = np + nq;
    st.site = &yj_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (qend = 0; qend + 1 <= n; qend++) {
      iwork->data[qend] = idx->data[offset + qend];
      xwork->data[qend] = x->data[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[n]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[n];
        x->data[iout] = xwork->data[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          st.site = &xj_emlrtRSI;
          if ((!(p + 1 > np)) && (np > 2147483646)) {
            b_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          while (p + 1 <= np) {
            idx->data[n + p] = iwork->data[p];
            x->data[n + p] = xwork->data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge(const emlrtStack *sp, int32_T idx[100], real_T x[100], int32_T
                  offset, int32_T np, int32_T nq, int32_T iwork[100], real_T
                  xwork[100])
{
  int32_T n;
  int32_T qend;
  int32_T p;
  int32_T iout;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq == 0) {
  } else {
    n = np + nq;
    st.site = &yj_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (qend = 0; qend + 1 <= n; qend++) {
      iwork[qend] = idx[offset + qend];
      xwork[qend] = x[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[n]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[n];
        x[iout] = xwork[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          st.site = &xj_emlrtRSI;
          if ((!(p + 1 > np)) && (np > 2147483646)) {
            b_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          while (p + 1 <= np) {
            idx[n + p] = iwork[p];
            x[n + p] = xwork[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

void b_merge(const emlrtStack *sp, int32_T idx[20], real_T x[20], int32_T offset,
             int32_T np, int32_T nq, int32_T iwork[20], real_T xwork[20])
{
  int32_T n;
  int32_T qend;
  int32_T p;
  int32_T iout;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq == 0) {
  } else {
    n = np + nq;
    st.site = &yj_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (qend = 0; qend + 1 <= n; qend++) {
      iwork[qend] = idx[offset + qend];
      xwork[qend] = x[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[n]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[n];
        x[iout] = xwork[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          st.site = &xj_emlrtRSI;
          if ((!(p + 1 > np)) && (np > 2147483646)) {
            b_st.site = &ab_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          while (p + 1 <= np) {
            idx[n + p] = iwork[p];
            x[n + p] = xwork[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

void b_sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emxArray_real_T *b_x;
  int32_T ib;
  int32_T wOffset;
  int32_T m;
  int32_T n;
  real_T x4[4];
  int32_T idx4[4];
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  int32_T nNaNs;
  boolean_T overflow;
  int32_T k;
  int8_T perm[4];
  int32_T p;
  int32_T nNonNaN;
  int32_T i4;
  int32_T nBlocks;
  int32_T b_iwork[256];
  real_T b_xwork[256];
  int32_T bLen;
  int32_T bLen2;
  int32_T nPairs;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T2(sp, &b_x, 1, &ge_emlrtRTEI, true);
  ib = x->size[0];
  st.site = &nj_emlrtRSI;
  b_st.site = &oj_emlrtRSI;
  wOffset = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)b_x, wOffset, (int32_T)sizeof
                    (real_T), &ge_emlrtRTEI);
  m = x->size[0];
  for (wOffset = 0; wOffset < m; wOffset++) {
    b_x->data[wOffset] = x->data[wOffset];
  }

  wOffset = idx->size[0];
  idx->size[0] = ib;
  emxEnsureCapacity(&b_st, (emxArray__common *)idx, wOffset, (int32_T)sizeof
                    (int32_T), &ge_emlrtRTEI);
  for (wOffset = 0; wOffset < ib; wOffset++) {
    idx->data[wOffset] = 0;
  }

  n = x->size[0];
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  emxInit_int32_T1(&b_st, &iwork, 1, &xe_emlrtRTEI, true);
  wOffset = iwork->size[0];
  iwork->size[0] = ib;
  emxEnsureCapacity(&b_st, (emxArray__common *)iwork, wOffset, (int32_T)sizeof
                    (int32_T), &ve_emlrtRTEI);
  m = iwork->size[0];
  wOffset = iwork->size[0];
  iwork->size[0] = m;
  emxEnsureCapacity(&b_st, (emxArray__common *)iwork, wOffset, (int32_T)sizeof
                    (int32_T), &ge_emlrtRTEI);
  for (wOffset = 0; wOffset < m; wOffset++) {
    iwork->data[wOffset] = 0;
  }

  emxInit_real_T2(&b_st, &xwork, 1, &ye_emlrtRTEI, true);
  m = x->size[0];
  wOffset = xwork->size[0];
  xwork->size[0] = m;
  emxEnsureCapacity(&b_st, (emxArray__common *)xwork, wOffset, (int32_T)sizeof
                    (real_T), &we_emlrtRTEI);
  m = xwork->size[0];
  wOffset = xwork->size[0];
  xwork->size[0] = m;
  emxEnsureCapacity(&b_st, (emxArray__common *)xwork, wOffset, (int32_T)sizeof
                    (real_T), &ge_emlrtRTEI);
  for (wOffset = 0; wOffset < m; wOffset++) {
    xwork->data[wOffset] = 0.0;
  }

  nNaNs = 0;
  ib = 0;
  c_st.site = &pm_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    if (muDoubleScalarIsNaN(b_x->data[k])) {
      idx->data[(n - nNaNs) - 1] = k + 1;
      xwork->data[(n - nNaNs) - 1] = b_x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = b_x->data[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] <= x4[1]) {
          m = 1;
          wOffset = 2;
        } else {
          m = 2;
          wOffset = 1;
        }

        if (x4[2] <= x4[3]) {
          p = 3;
          i4 = 4;
        } else {
          p = 4;
          i4 = 3;
        }

        if (x4[m - 1] <= x4[p - 1]) {
          if (x4[wOffset - 1] <= x4[p - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)wOffset;
            perm[2] = (int8_T)p;
            perm[3] = (int8_T)i4;
          } else if (x4[wOffset - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)p;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)p;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)wOffset;
          }
        } else if (x4[m - 1] <= x4[i4 - 1]) {
          if (x4[wOffset - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)p;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)p;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)wOffset;
          }
        } else {
          perm[0] = (int8_T)p;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)m;
          perm[3] = (int8_T)wOffset;
        }

        idx->data[ib - 3] = idx4[perm[0] - 1];
        idx->data[ib - 2] = idx4[perm[1] - 1];
        idx->data[ib - 1] = idx4[perm[2] - 1];
        idx->data[ib] = idx4[perm[3] - 1];
        b_x->data[ib - 3] = x4[perm[0] - 1];
        b_x->data[ib - 2] = x4[perm[1] - 1];
        b_x->data[ib - 1] = x4[perm[2] - 1];
        b_x->data[ib] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  wOffset = (x->size[0] - nNaNs) - 1;
  if (ib > 0) {
    for (m = 0; m < 4; m++) {
      perm[m] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    c_st.site = &rj_emlrtRSI;
    if (ib > 2147483646) {
      d_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 1; k <= ib; k++) {
      idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
      b_x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
    }
  }

  m = (nNaNs >> 1) + 1;
  c_st.site = &sj_emlrtRSI;
  for (k = 1; k < m; k++) {
    ib = idx->data[wOffset + k];
    idx->data[wOffset + k] = idx->data[n - k];
    idx->data[n - k] = ib;
    b_x->data[wOffset + k] = xwork->data[n - k];
    b_x->data[n - k] = xwork->data[wOffset + k];
  }

  if ((nNaNs & 1) != 0) {
    b_x->data[wOffset + m] = xwork->data[wOffset + m];
  }

  nNonNaN = x->size[0] - nNaNs;
  m = 2;
  if (nNonNaN > 1) {
    if (x->size[0] >= 256) {
      nBlocks = nNonNaN >> 8;
      if (nBlocks > 0) {
        b_st.site = &mm_emlrtRSI;
        for (i4 = 1; i4 <= nBlocks; i4++) {
          b_st.site = &nm_emlrtRSI;
          nNaNs = (i4 - 1) << 8;
          for (n = 0; n < 6; n++) {
            bLen = 1 << (n + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (n + 3);
            c_st.site = &qm_emlrtRSI;
            for (k = 1; k <= nPairs; k++) {
              m = nNaNs + (k - 1) * bLen2;
              c_st.site = &rm_emlrtRSI;
              for (ib = 0; ib + 1 <= bLen2; ib++) {
                b_iwork[ib] = idx->data[m + ib];
                b_xwork[ib] = b_x->data[m + ib];
              }

              p = 0;
              wOffset = bLen;
              ib = m - 1;
              do {
                exitg1 = 0;
                ib++;
                if (b_xwork[p] <= b_xwork[wOffset]) {
                  idx->data[ib] = b_iwork[p];
                  b_x->data[ib] = b_xwork[p];
                  if (p + 1 < bLen) {
                    p++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[ib] = b_iwork[wOffset];
                  b_x->data[ib] = b_xwork[wOffset];
                  if (wOffset + 1 < bLen2) {
                    wOffset++;
                  } else {
                    ib = (ib - p) + 1;
                    c_st.site = &sm_emlrtRSI;
                    while (p + 1 <= bLen) {
                      idx->data[ib + p] = b_iwork[p];
                      b_x->data[ib + p] = b_xwork[p];
                      p++;
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        m = nBlocks << 8;
        ib = nNonNaN - m;
        if (ib > 0) {
          b_st.site = &om_emlrtRSI;
          c_merge_block(&b_st, idx, b_x, m, ib, 2, iwork, xwork);
        }

        m = 8;
      }
    }

    b_st.site = &pj_emlrtRSI;
    c_merge_block(&b_st, idx, b_x, 0, nNonNaN, m, iwork, xwork);
  }

  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  wOffset = x->size[0];
  x->size[0] = b_x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, wOffset, (int32_T)sizeof(real_T),
                    &ge_emlrtRTEI);
  m = b_x->size[0];
  for (wOffset = 0; wOffset < m; wOffset++) {
    x->data[wOffset] = b_x->data[wOffset];
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void merge_block(const emlrtStack *sp, int32_T idx[100], real_T x[100], int32_T
                 n, int32_T iwork[100], real_T xwork[100])
{
  int32_T nPairs;
  int32_T bLen;
  int32_T tailOffset;
  int32_T nTail;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> 2;
  bLen = 4;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &tj_emlrtRSI;
        merge(&st, idx, x, tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      st.site = &vj_emlrtRSI;
      merge(&st, idx, x, (nTail - 1) * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    st.site = &wj_emlrtRSI;
    merge(&st, idx, x, 0, bLen, n - bLen, iwork, xwork);
  }
}

void sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emxArray_real_T *b_x;
  int32_T ib;
  int32_T wOffset;
  int32_T m;
  int32_T n;
  real_T x4[4];
  int32_T idx4[4];
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  int32_T nNaNs;
  boolean_T overflow;
  int32_T k;
  int8_T perm[4];
  int32_T p;
  int32_T nNonNaN;
  int32_T i4;
  int32_T nBlocks;
  int32_T b_iwork[256];
  real_T b_xwork[256];
  int32_T b;
  int32_T bLen;
  int32_T bLen2;
  int32_T nPairs;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T2(sp, &b_x, 1, &ge_emlrtRTEI, true);
  ib = x->size[0];
  st.site = &nj_emlrtRSI;
  b_st.site = &oj_emlrtRSI;
  wOffset = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)b_x, wOffset, (int32_T)sizeof
                    (real_T), &ge_emlrtRTEI);
  m = x->size[0];
  for (wOffset = 0; wOffset < m; wOffset++) {
    b_x->data[wOffset] = x->data[wOffset];
  }

  wOffset = idx->size[0];
  idx->size[0] = ib;
  emxEnsureCapacity(&b_st, (emxArray__common *)idx, wOffset, (int32_T)sizeof
                    (int32_T), &ge_emlrtRTEI);
  for (wOffset = 0; wOffset < ib; wOffset++) {
    idx->data[wOffset] = 0;
  }

  n = x->size[0];
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  emxInit_int32_T1(&b_st, &iwork, 1, &xe_emlrtRTEI, true);
  wOffset = iwork->size[0];
  iwork->size[0] = ib;
  emxEnsureCapacity(&b_st, (emxArray__common *)iwork, wOffset, (int32_T)sizeof
                    (int32_T), &ve_emlrtRTEI);
  m = iwork->size[0];
  wOffset = iwork->size[0];
  iwork->size[0] = m;
  emxEnsureCapacity(&b_st, (emxArray__common *)iwork, wOffset, (int32_T)sizeof
                    (int32_T), &ge_emlrtRTEI);
  for (wOffset = 0; wOffset < m; wOffset++) {
    iwork->data[wOffset] = 0;
  }

  emxInit_real_T2(&b_st, &xwork, 1, &ye_emlrtRTEI, true);
  m = x->size[0];
  wOffset = xwork->size[0];
  xwork->size[0] = m;
  emxEnsureCapacity(&b_st, (emxArray__common *)xwork, wOffset, (int32_T)sizeof
                    (real_T), &we_emlrtRTEI);
  m = xwork->size[0];
  wOffset = xwork->size[0];
  xwork->size[0] = m;
  emxEnsureCapacity(&b_st, (emxArray__common *)xwork, wOffset, (int32_T)sizeof
                    (real_T), &ge_emlrtRTEI);
  for (wOffset = 0; wOffset < m; wOffset++) {
    xwork->data[wOffset] = 0.0;
  }

  nNaNs = 0;
  ib = 0;
  c_st.site = &pm_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    if (muDoubleScalarIsNaN(b_x->data[k])) {
      idx->data[(n - nNaNs) - 1] = k + 1;
      xwork->data[(n - nNaNs) - 1] = b_x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = b_x->data[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] >= x4[1]) {
          m = 1;
          wOffset = 2;
        } else {
          m = 2;
          wOffset = 1;
        }

        if (x4[2] >= x4[3]) {
          p = 3;
          i4 = 4;
        } else {
          p = 4;
          i4 = 3;
        }

        if (x4[m - 1] >= x4[p - 1]) {
          if (x4[wOffset - 1] >= x4[p - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)wOffset;
            perm[2] = (int8_T)p;
            perm[3] = (int8_T)i4;
          } else if (x4[wOffset - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)p;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)p;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)wOffset;
          }
        } else if (x4[m - 1] >= x4[i4 - 1]) {
          if (x4[wOffset - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)p;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)p;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)wOffset;
          }
        } else {
          perm[0] = (int8_T)p;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)m;
          perm[3] = (int8_T)wOffset;
        }

        idx->data[ib - 3] = idx4[perm[0] - 1];
        idx->data[ib - 2] = idx4[perm[1] - 1];
        idx->data[ib - 1] = idx4[perm[2] - 1];
        idx->data[ib] = idx4[perm[3] - 1];
        b_x->data[ib - 3] = x4[perm[0] - 1];
        b_x->data[ib - 2] = x4[perm[1] - 1];
        b_x->data[ib - 1] = x4[perm[2] - 1];
        b_x->data[ib] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  wOffset = (x->size[0] - nNaNs) - 1;
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

    c_st.site = &rj_emlrtRSI;
    if (ib > 2147483646) {
      d_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 1; k <= ib; k++) {
      idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
      b_x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
    }
  }

  m = (nNaNs >> 1) + 1;
  c_st.site = &sj_emlrtRSI;
  for (k = 1; k < m; k++) {
    ib = idx->data[wOffset + k];
    idx->data[wOffset + k] = idx->data[n - k];
    idx->data[n - k] = ib;
    b_x->data[wOffset + k] = xwork->data[n - k];
    b_x->data[n - k] = xwork->data[wOffset + k];
  }

  if ((nNaNs & 1) != 0) {
    b_x->data[wOffset + m] = xwork->data[wOffset + m];
  }

  nNonNaN = x->size[0] - nNaNs;
  m = 2;
  if (nNonNaN > 1) {
    if (x->size[0] >= 256) {
      nBlocks = nNonNaN >> 8;
      if (nBlocks > 0) {
        b_st.site = &mm_emlrtRSI;
        for (i4 = 1; i4 <= nBlocks; i4++) {
          b_st.site = &nm_emlrtRSI;
          n = (i4 - 1) << 8;
          for (b = 0; b < 6; b++) {
            bLen = 1 << (b + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (b + 3);
            c_st.site = &qm_emlrtRSI;
            for (k = 1; k <= nPairs; k++) {
              m = n + (k - 1) * bLen2;
              c_st.site = &rm_emlrtRSI;
              for (ib = 0; ib + 1 <= bLen2; ib++) {
                b_iwork[ib] = idx->data[m + ib];
                b_xwork[ib] = b_x->data[m + ib];
              }

              p = 0;
              wOffset = bLen;
              ib = m - 1;
              do {
                exitg1 = 0;
                ib++;
                if (b_xwork[p] >= b_xwork[wOffset]) {
                  idx->data[ib] = b_iwork[p];
                  b_x->data[ib] = b_xwork[p];
                  if (p + 1 < bLen) {
                    p++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[ib] = b_iwork[wOffset];
                  b_x->data[ib] = b_xwork[wOffset];
                  if (wOffset + 1 < bLen2) {
                    wOffset++;
                  } else {
                    ib = (ib - p) + 1;
                    c_st.site = &sm_emlrtRSI;
                    while (p + 1 <= bLen) {
                      idx->data[ib + p] = b_iwork[p];
                      b_x->data[ib + p] = b_xwork[p];
                      p++;
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        m = nBlocks << 8;
        ib = nNonNaN - m;
        if (ib > 0) {
          b_st.site = &om_emlrtRSI;
          b_merge_block(&b_st, idx, b_x, m, ib, 2, iwork, xwork);
        }

        m = 8;
      }
    }

    b_st.site = &pj_emlrtRSI;
    b_merge_block(&b_st, idx, b_x, 0, nNonNaN, m, iwork, xwork);
  }

  if ((nNaNs > 0) && (nNonNaN > 0)) {
    b_st.site = &qj_emlrtRSI;
    c_st.site = &ak_emlrtRSI;
    if (nNaNs > 2147483646) {
      d_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k + 1 <= nNaNs; k++) {
      xwork->data[k] = b_x->data[nNonNaN + k];
      iwork->data[k] = idx->data[nNonNaN + k];
    }

    for (k = nNonNaN - 1; k + 1 > 0; k--) {
      b_x->data[nNaNs + k] = b_x->data[k];
      idx->data[nNaNs + k] = idx->data[k];
    }

    c_st.site = &bk_emlrtRSI;
    for (k = 0; k + 1 <= nNaNs; k++) {
      b_x->data[k] = xwork->data[k];
      idx->data[k] = iwork->data[k];
    }
  }

  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  wOffset = x->size[0];
  x->size[0] = b_x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, wOffset, (int32_T)sizeof(real_T),
                    &ge_emlrtRTEI);
  m = b_x->size[0];
  for (wOffset = 0; wOffset < m; wOffset++) {
    x->data[wOffset] = b_x->data[wOffset];
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sortIdx.c) */
