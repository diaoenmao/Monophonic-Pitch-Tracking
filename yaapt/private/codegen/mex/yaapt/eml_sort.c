/*
 * eml_sort.c
 *
 * Code generation for function 'eml_sort'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "eml_sort.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo xf_emlrtRSI = { 20, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRSInfo ag_emlrtRSI = { 185, "eml_sort_idx",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort_idx.m" };

static emlrtRSInfo ui_emlrtRSI = { 78, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRSInfo vi_emlrtRSI = { 69, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRSInfo wi_emlrtRSI = { 66, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRSInfo xi_emlrtRSI = { 62, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRSInfo yi_emlrtRSI = { 50, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRSInfo aj_emlrtRSI = { 12, "eml_assert_valid_dim",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_assert_valid_dim.m" };

static emlrtRSInfo bj_emlrtRSI = { 86, "eml_matrix_vstride",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_matrix_vstride.m" };

static emlrtRSInfo cj_emlrtRSI = { 49, "prodsize",
  "F:\\MATLAB\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\prodsize.m" };

static emlrtRSInfo dj_emlrtRSI = { 42, "eml_sort_idx",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort_idx.m" };

static emlrtRSInfo ej_emlrtRSI = { 134, "eml_sort_idx",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort_idx.m" };

static emlrtRSInfo fj_emlrtRSI = { 138, "eml_sort_idx",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort_idx.m" };

static emlrtRTEInfo dd_emlrtRTEI = { 52, 1, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRTEInfo ed_emlrtRTEI = { 53, 1, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRTEInfo fd_emlrtRTEI = { 61, 5, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRTEInfo gd_emlrtRTEI = { 27, 5, "eml_sort_idx",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort_idx.m" };

static emlrtRTEInfo hd_emlrtRTEI = { 1, 20, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRTEInfo id_emlrtRTEI = { 78, 13, "eml_sort",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort.m" };

static emlrtRTEInfo jd_emlrtRTEI = { 145, 5, "eml_sort_idx",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_sort_idx.m" };

/* Function Declarations */
static void b_eml_sort(const real_T x[100], real_T y[100], int32_T idx[100]);
static void d_eml_sort(const real_T x[3], real_T y[3], int32_T idx[3]);
static void f_eml_sort(const emlrtStack *sp, const emxArray_real_T *x, int32_T
  dim, emxArray_real_T *y, emxArray_int32_T *idx);

/* Function Definitions */

/*
 *
 */
static void b_eml_sort(const real_T x[100], real_T y[100], int32_T idx[100])
{
  int32_T k;
  boolean_T p;
  int8_T idx0[100];
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  for (k = 0; k < 100; k++) {
    idx[k] = k + 1;
  }

  for (k = 0; k < 100; k += 2) {
    if ((x[k] >= x[k + 1]) || muDoubleScalarIsNaN(x[k])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  memset(&idx0[0], 1, 100U * sizeof(int8_T));
  i = 2;
  while (i < 100) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 101; pEnd = qEnd + i) {
      b_p = j - 1;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > 101) {
        qEnd = 101;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if ((x[idx[b_p] - 1] >= x[idx[q - 1] - 1]) || muDoubleScalarIsNaN
            (x[idx[b_p] - 1])) {
          p = true;
        } else {
          p = false;
        }

        if (p) {
          idx0[k] = (int8_T)idx[b_p];
          b_p++;
          if (b_p + 1 == pEnd) {
            while (q < qEnd) {
              k++;
              idx0[k] = (int8_T)idx[q - 1];
              q++;
            }
          }
        } else {
          idx0[k] = (int8_T)idx[q - 1];
          q++;
          if (q == qEnd) {
            while (b_p + 1 < pEnd) {
              k++;
              idx0[k] = (int8_T)idx[b_p];
              b_p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k + 1 <= kEnd; k++) {
        idx[(j + k) - 1] = idx0[k];
      }

      j = qEnd;
    }

    i = i2;
  }

  for (k = 0; k < 100; k++) {
    y[k] = x[idx[k] - 1];
  }
}

/*
 *
 */
static void d_eml_sort(const real_T x[3], real_T y[3], int32_T idx[3])
{
  boolean_T p;
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
      y[0] = x[0];
      y[1] = x[1];
      y[2] = x[2];
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
        y[0] = x[0];
        y[1] = x[2];
        y[2] = x[1];
      } else {
        idx[0] = 3;
        idx[1] = 1;
        idx[2] = 2;
        y[0] = x[2];
        y[1] = x[0];
        y[2] = x[1];
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
      y[0] = x[1];
      y[1] = x[0];
      y[2] = x[2];
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
        y[0] = x[1];
        y[1] = x[2];
        y[2] = x[0];
      } else {
        idx[0] = 3;
        idx[1] = 2;
        idx[2] = 1;
        y[0] = x[2];
        y[1] = x[1];
        y[2] = x[0];
      }
    }
  }
}

/*
 *
 */
static void f_eml_sort(const emlrtStack *sp, const emxArray_real_T *x, int32_T
  dim, emxArray_real_T *y, emxArray_int32_T *idx)
{
  emxArray_real_T *vwork;
  uint32_T uv4[2];
  int32_T i2;
  int32_T ix;
  int32_T vstride;
  boolean_T b10;
  int32_T k;
  int32_T vspread;
  int32_T npages;
  int32_T b_i2;
  boolean_T b11;
  int32_T i;
  emxArray_int32_T *iidx;
  emxArray_int32_T *idx0;
  int32_T i1;
  boolean_T b12;
  int32_T j;
  boolean_T overflow;
  int32_T b_j;
  int32_T pEnd;
  int32_T p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
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
  b_emxInit_real_T(sp, &vwork, 1, &dd_emlrtRTEI, true);
  st.site = &yi_emlrtRSI;
  b_st.site = &aj_emlrtRSI;
  uv4[0] = (uint32_T)x->size[dim - 1];
  i2 = vwork->size[0];
  vwork->size[0] = (int32_T)uv4[0];
  emxEnsureCapacity(sp, (emxArray__common *)vwork, i2, (int32_T)sizeof(real_T),
                    &dd_emlrtRTEI);
  for (i2 = 0; i2 < 2; i2++) {
    ix = y->size[0] * y->size[1];
    y->size[i2] = x->size[i2];
    emxEnsureCapacity(sp, (emxArray__common *)y, ix, (int32_T)sizeof(real_T),
                      &ed_emlrtRTEI);
  }

  for (i2 = 0; i2 < 2; i2++) {
    uv4[i2] = (uint32_T)x->size[i2];
  }

  i2 = idx->size[0] * idx->size[1];
  idx->size[0] = (int32_T)uv4[0];
  idx->size[1] = (int32_T)uv4[1];
  emxEnsureCapacity(sp, (emxArray__common *)idx, i2, (int32_T)sizeof(int32_T),
                    &fd_emlrtRTEI);
  st.site = &xi_emlrtRSI;
  b_st.site = &bj_emlrtRSI;
  vstride = 1;
  c_st.site = &cj_emlrtRSI;
  if (1 > dim - 1) {
    b10 = false;
  } else {
    b10 = (dim - 1 > 2147483646);
  }

  if (b10) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  vspread = (x->size[dim - 1] - 1) * vstride;
  npages = 1;
  k = dim + 1;
  while (k < 3) {
    npages *= x->size[1];
    k = 3;
  }

  b_i2 = 0;
  st.site = &wi_emlrtRSI;
  if (1 > npages) {
    b11 = false;
  } else {
    b11 = (npages > 2147483646);
  }

  if (b11) {
    b_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  i = 1;
  emxInit_int32_T(sp, &iidx, 1, &id_emlrtRTEI, true);
  emxInit_int32_T(sp, &idx0, 1, &jd_emlrtRTEI, true);
  while (i <= npages) {
    i1 = b_i2;
    b_i2 += vspread;
    st.site = &vi_emlrtRSI;
    if (1 > vstride) {
      b12 = false;
    } else {
      b12 = (vstride > 2147483646);
    }

    if (b12) {
      b_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (j = 1; j <= vstride; j++) {
      i1++;
      b_i2++;
      ix = i1;
      for (k = 0; k < x->size[dim - 1]; k++) {
        vwork->data[k] = x->data[ix - 1];
        ix += vstride;
      }

      st.site = &ui_emlrtRSI;
      uv4[0] = (uint32_T)vwork->size[0];
      i2 = iidx->size[0];
      iidx->size[0] = (int32_T)uv4[0];
      emxEnsureCapacity(&st, (emxArray__common *)iidx, i2, (int32_T)sizeof
                        (int32_T), &gd_emlrtRTEI);
      if (vwork->size[0] == 0) {
        b_st.site = &dj_emlrtRSI;
      } else {
        b_st.site = &ej_emlrtRSI;
        overflow = (vwork->size[0] > 2147483646);
        if (overflow) {
          c_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (k = 1; k <= vwork->size[0]; k++) {
          iidx->data[k - 1] = k;
        }

        b_st.site = &fj_emlrtRSI;
        for (k = 1; k <= vwork->size[0] - 1; k += 2) {
          if ((vwork->data[k - 1] >= vwork->data[k]) || muDoubleScalarIsNaN
              (vwork->data[k - 1])) {
            overflow = true;
          } else {
            overflow = false;
          }

          if (overflow) {
          } else {
            iidx->data[k - 1] = k + 1;
            iidx->data[k] = k;
          }
        }

        i2 = idx0->size[0];
        idx0->size[0] = vwork->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)idx0, i2, (int32_T)sizeof
                          (int32_T), &hd_emlrtRTEI);
        ix = vwork->size[0];
        for (i2 = 0; i2 < ix; i2++) {
          idx0->data[i2] = 1;
        }

        ix = 2;
        while (ix < vwork->size[0]) {
          i2 = ix << 1;
          b_j = 1;
          for (pEnd = 1 + ix; pEnd < vwork->size[0] + 1; pEnd = qEnd + ix) {
            p = b_j - 1;
            q = pEnd;
            qEnd = b_j + i2;
            if (qEnd > vwork->size[0] + 1) {
              qEnd = vwork->size[0] + 1;
            }

            k = 0;
            kEnd = qEnd - b_j;
            while (k + 1 <= kEnd) {
              if ((vwork->data[iidx->data[p] - 1] >= vwork->data[iidx->data[q -
                   1] - 1]) || muDoubleScalarIsNaN(vwork->data[iidx->data[p] - 1]))
              {
                overflow = true;
              } else {
                overflow = false;
              }

              if (overflow) {
                idx0->data[k] = iidx->data[p];
                p++;
                if (p + 1 == pEnd) {
                  while (q < qEnd) {
                    k++;
                    idx0->data[k] = iidx->data[q - 1];
                    q++;
                  }
                }
              } else {
                idx0->data[k] = iidx->data[q - 1];
                q++;
                if (q == qEnd) {
                  while (p + 1 < pEnd) {
                    k++;
                    idx0->data[k] = iidx->data[p];
                    p++;
                  }
                }
              }

              k++;
            }

            b_st.site = &ag_emlrtRSI;
            for (k = 0; k + 1 <= kEnd; k++) {
              iidx->data[(b_j + k) - 1] = idx0->data[k];
            }

            b_j = qEnd;
          }

          ix = i2;
        }
      }

      ix = i1 - 1;
      for (k = 0; k < x->size[dim - 1]; k++) {
        y->data[ix] = vwork->data[iidx->data[k] - 1];
        idx->data[ix] = iidx->data[k];
        ix += vstride;
      }
    }

    i++;
  }

  emxFree_int32_T(&idx0);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void c_eml_sort(const real_T x[3], real_T y[3], int32_T idx[3])
{
  d_eml_sort(x, y, idx);
}

/*
 *
 */
void e_eml_sort(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *
                y, emxArray_int32_T *idx)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xf_emlrtRSI;
  f_eml_sort(&st, x, 1, y, idx);
}

/*
 *
 */
void eml_sort(const real_T x[100], real_T y[100], int32_T idx[100])
{
  b_eml_sort(x, y, idx);
}

/* End of code generation (eml_sort.c) */
