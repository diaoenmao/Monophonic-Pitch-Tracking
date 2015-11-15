/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
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
static emlrtRSInfo cg_emlrtRSI = { 19, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo dg_emlrtRSI = { 66, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo jj_emlrtRSI = { 82, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo kj_emlrtRSI = { 80, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo lj_emlrtRSI = { 77, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo mj_emlrtRSI = { 74, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo nj_emlrtRSI = { 72, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo oj_emlrtRSI = { 69, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo pj_emlrtRSI = { 48, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo qj_emlrtRSI = { 49, "prodsize",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\prodsize.m" };

static emlrtRTEInfo bd_emlrtRTEI = { 1, 20, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRTEInfo hd_emlrtRTEI = { 50, 1, "sort",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

/* Function Declarations */
static void b_sort(const emlrtStack *sp, real_T x[100], int32_T idx[100]);
static void d_sort(real_T x[3], int32_T idx[3]);
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
  st.site = &dg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &eg_emlrtRSI;
  c_st.site = &fg_emlrtRSI;
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

    d_st.site = &ig_emlrtRSI;
    if (ib > 2147483646) {
      e_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 100; k - 99 <= ib; k++) {
      idx[(k - nNaNs) - ib] = idx4[perm[k - 100] - 1];
      x[(k - nNaNs) - ib] = x4[perm[k - 100] - 1];
    }
  }

  m = asr_s32(nNaNs, 1U);
  d_st.site = &jg_emlrtRSI;
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
    c_st.site = &gg_emlrtRSI;
    merge_block(&c_st, idx, x, 100 - nNaNs, iwork, xwork);
  }

  if ((nNaNs > 0) && (100 - nNaNs > 0)) {
    c_st.site = &hg_emlrtRSI;
    d_st.site = &qg_emlrtRSI;
    if (nNaNs > 2147483646) {
      e_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 100; k - 99 <= nNaNs; k++) {
      xwork[k - 100] = x[k - nNaNs];
      iwork[k - 100] = idx[k - nNaNs];
    }

    for (k = 99 - nNaNs; k + 1 > 0; k--) {
      x[nNaNs + k] = x[k];
      idx[nNaNs + k] = idx[k];
    }

    d_st.site = &rg_emlrtRSI;
    for (k = 0; k + 1 <= nNaNs; k++) {
      x[k] = xwork[k];
      idx[k] = iwork[k];
    }
  }
}

/*
 *
 */
static void d_sort(real_T x[3], int32_T idx[3])
{
  real_T b_x[3];
  int32_T i40;
  boolean_T p;
  for (i40 = 0; i40 < 3; i40++) {
    b_x[i40] = x[i40];
  }

  if ((x[0] >= x[1]) || muDoubleScalarIsNaN(x[0])) {
    p = true;
  } else {
    p = false;
  }

  if (p) {
    if ((x[1] >= x[2]) || muDoubleScalarIsNaN(x[1])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx[0] = 1;
      idx[1] = 2;
      idx[2] = 3;
    } else {
      if ((x[0] >= x[2]) || muDoubleScalarIsNaN(x[0])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        idx[0] = 1;
        idx[1] = 3;
        idx[2] = 2;
        b_x[1] = x[2];
        b_x[2] = x[1];
      } else {
        idx[0] = 3;
        idx[1] = 1;
        idx[2] = 2;
        b_x[2] = x[1];
        b_x[1] = x[0];
        b_x[0] = x[2];
      }
    }
  } else {
    if ((x[0] >= x[2]) || muDoubleScalarIsNaN(x[0])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx[0] = 2;
      idx[1] = 1;
      idx[2] = 3;
      b_x[0] = x[1];
      b_x[1] = x[0];
    } else {
      if ((x[1] >= x[2]) || muDoubleScalarIsNaN(x[1])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        idx[0] = 2;
        idx[1] = 3;
        idx[2] = 1;
        b_x[0] = x[1];
        b_x[1] = x[2];
        b_x[2] = x[0];
      } else {
        idx[0] = 3;
        idx[1] = 2;
        idx[2] = 1;
        b_x[0] = x[2];
        b_x[2] = x[0];
      }
    }
  }

  for (i40 = 0; i40 < 3; i40++) {
    x[i40] = b_x[i40];
  }
}

/*
 *
 */
static void f_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx)
{
  emxArray_real_T *vwork;
  int32_T i41;
  int32_T vstride;
  int32_T k;
  int32_T iv39[2];
  boolean_T b17;
  int32_T npages;
  int32_T pagesize;
  boolean_T b18;
  int32_T i;
  emxArray_int32_T *iidx;
  int32_T pageoffset;
  boolean_T b19;
  int32_T j;
  int32_T idx0;
  boolean_T b20;
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
  emxInit_real_T1(sp, &vwork, 1, &hd_emlrtRTEI, true);
  st.site = &pj_emlrtRSI;
  i41 = x->size[dim - 1];
  vstride = x->size[dim - 1];
  k = vwork->size[0];
  vwork->size[0] = vstride;
  emxEnsureCapacity(sp, (emxArray__common *)vwork, k, (int32_T)sizeof(real_T),
                    &bd_emlrtRTEI);
  for (k = 0; k < 2; k++) {
    iv39[k] = x->size[k];
  }

  k = idx->size[0] * idx->size[1];
  idx->size[0] = iv39[0];
  idx->size[1] = iv39[1];
  emxEnsureCapacity(sp, (emxArray__common *)idx, k, (int32_T)sizeof(int32_T),
                    &bd_emlrtRTEI);
  st.site = &oj_emlrtRSI;
  vstride = 1;
  b_st.site = &qj_emlrtRSI;
  if (1 > dim - 1) {
    b17 = false;
  } else {
    b17 = (dim - 1 > 2147483646);
  }

  if (b17) {
    c_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  npages = 1;
  k = dim + 1;
  while (k < 3) {
    npages *= x->size[1];
    k = 3;
  }

  pagesize = x->size[dim - 1] * vstride;
  st.site = &nj_emlrtRSI;
  if (1 > npages) {
    b18 = false;
  } else {
    b18 = (npages > 2147483646);
  }

  if (b18) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  i = 1;
  emxInit_int32_T(sp, &iidx, 1, &bd_emlrtRTEI, true);
  while (i <= npages) {
    pageoffset = (i - 1) * pagesize;
    st.site = &mj_emlrtRSI;
    if (1 > vstride) {
      b19 = false;
    } else {
      b19 = (vstride > 2147483646);
    }

    if (b19) {
      b_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (j = 0; j + 1 <= vstride; j++) {
      idx0 = pageoffset + j;
      st.site = &lj_emlrtRSI;
      if (1 > i41) {
        b20 = false;
      } else {
        b20 = (i41 > 2147483646);
      }

      if (b20) {
        b_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (k = 0; k + 1 <= i41; k++) {
        vwork->data[k] = x->data[idx0 + k * vstride];
      }

      st.site = &kj_emlrtRSI;
      sortIdx(&st, vwork, iidx);
      st.site = &jj_emlrtRSI;
      for (k = 0; k + 1 <= i41; k++) {
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
void c_sort(real_T x[3], int32_T idx[3])
{
  d_sort(x, idx);
}

/*
 *
 */
void e_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cg_emlrtRSI;
  f_sort(&st, x, 1, idx);
}

/*
 *
 */
void sort(const emlrtStack *sp, real_T x[100], int32_T idx[100])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cg_emlrtRSI;
  b_sort(&st, x, idx);
}

/* End of code generation (sort1.c) */
