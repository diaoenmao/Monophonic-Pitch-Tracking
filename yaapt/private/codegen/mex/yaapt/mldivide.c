/*
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "mldivide.h"
#include "eml_warning.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = { 1, "mldivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

static emlrtRSInfo w_emlrtRSI = { 90, "eml_lusolve",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_lusolve.m" };

static emlrtRSInfo x_emlrtRSI = { 128, "eml_lusolve",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_lusolve.m" };

static emlrtRSInfo y_emlrtRSI = { 130, "eml_lusolve",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\eml_lusolve.m" };

static emlrtRSInfo ab_emlrtRSI = { 8, "eml_xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\eml_xgetrf.m" };

static emlrtRSInfo bb_emlrtRSI = { 8, "eml_lapack_xgetrf",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\internal\\eml_lapack_xgetrf.m"
};

static emlrtRSInfo cb_emlrtRSI = { 36, "eml_matlab_zgetrf",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zgetrf.m"
};

static emlrtRSInfo db_emlrtRSI = { 44, "eml_matlab_zgetrf",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zgetrf.m"
};

static emlrtRSInfo eb_emlrtRSI = { 50, "eml_matlab_zgetrf",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zgetrf.m"
};

static emlrtRSInfo fb_emlrtRSI = { 58, "eml_matlab_zgetrf",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zgetrf.m"
};

static emlrtRSInfo gb_emlrtRSI = { 20, "eml_ixamax",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\blas\\eml_ixamax.m" };

static emlrtRSInfo hb_emlrtRSI = { 1, "ixamax",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\ixamax.p" };

static emlrtRSInfo kb_emlrtRSI = { 26, "eml_xswap",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\blas\\eml_xswap.m" };

static emlrtRSInfo lb_emlrtRSI = { 1, "xswap",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\xswap.p" };

static emlrtRSInfo mb_emlrtRSI = { 41, "eml_xgeru",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\eml\\blas\\eml_xgeru.m" };

static emlrtRSInfo nb_emlrtRSI = { 1, "xgeru",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\xgeru.p" };

static emlrtBCInfo bj_emlrtBCI = { 1, 5776, 1, 1, "", "ixamax",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+refblas\\ixamax.p", 0
};

static emlrtBCInfo cj_emlrtBCI = { 1, 5776, 1, 1, "", "xswap",
  "F:\\MATLAB\\toolbox\\coder\\coder\\+coder\\+internal\\+refblas\\xswap.p", 0 };

/* Function Declarations */
static void b_eml_xtrsm(const real_T A[5776], real_T B[76]);
static void eml_xswap(const emlrtStack *sp, real_T x[5776], int32_T ix0, int32_T
                      iy0);
static void eml_xtrsm(const real_T A[5776], real_T B[76]);
static void warn_singular(const emlrtStack *sp);

/* Function Definitions */

/*
 *
 */
static void b_eml_xtrsm(const real_T A[5776], real_T B[76])
{
  real_T alpha1;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  double * Aia0_t;
  double * Bib0_t;
  double * alpha1_t;
  alpha1 = 1.0;
  DIAGA = 'N';
  TRANSA = 'N';
  UPLO = 'U';
  SIDE = 'L';
  m_t = (ptrdiff_t)(76);
  n_t = (ptrdiff_t)(1);
  lda_t = (ptrdiff_t)(76);
  ldb_t = (ptrdiff_t)(76);
  Aia0_t = (double *)(&A[0]);
  Bib0_t = (double *)(&B[0]);
  alpha1_t = (double *)(&alpha1);
  dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, alpha1_t, Aia0_t, &lda_t,
        Bib0_t, &ldb_t);
}

/*
 *
 */
static void eml_xswap(const emlrtStack *sp, real_T x[5776], int32_T ix0, int32_T
                      iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &lb_emlrtRSI;
  ix = ix0;
  iy = iy0;
  for (k = 0; k < 76; k++) {
    temp = x[emlrtDynamicBoundsCheckFastR2012b(ix, 1, 5776, &cj_emlrtBCI, &b_st)
      - 1];
    x[ix - 1] = x[emlrtDynamicBoundsCheckFastR2012b(iy, 1, 5776, &cj_emlrtBCI,
      &b_st) - 1];
    x[iy - 1] = temp;
    ix += 76;
    iy += 76;
  }
}

/*
 *
 */
static void eml_xtrsm(const real_T A[5776], real_T B[76])
{
  real_T alpha1;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  double * Aia0_t;
  double * Bib0_t;
  double * alpha1_t;
  alpha1 = 1.0;
  DIAGA = 'U';
  TRANSA = 'N';
  UPLO = 'L';
  SIDE = 'L';
  m_t = (ptrdiff_t)(76);
  n_t = (ptrdiff_t)(1);
  lda_t = (ptrdiff_t)(76);
  ldb_t = (ptrdiff_t)(76);
  Aia0_t = (double *)(&A[0]);
  Bib0_t = (double *)(&B[0]);
  alpha1_t = (double *)(&alpha1);
  dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, alpha1_t, Aia0_t, &lda_t,
        Bib0_t, &ldb_t);
}

/*
 *
 */
static void warn_singular(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pb_emlrtRSI;
  eml_warning(&st);
}

/*
 *
 */
void mldivide(const emlrtStack *sp, const real_T A[5776], real_T B[76])
{
  real_T b_A[5776];
  uint8_T ipiv[76];
  int32_T xi;
  int32_T info;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T temp;
  int32_T k;
  real_T s;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  double * alpha1_t;
  double * Aia0_t;
  double * Aix0_t;
  double * Aiy0_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &t_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  b_st.site = &u_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &ab_emlrtRSI;
  e_st.site = &bb_emlrtRSI;
  memcpy(&b_A[0], &A[0], 5776U * sizeof(real_T));
  for (xi = 0; xi < 76; xi++) {
    ipiv[xi] = (uint8_T)(1 + xi);
  }

  info = 0;
  for (j = 0; j < 75; j++) {
    c = j * 77;
    f_st.site = &cb_emlrtRSI;
    g_st.site = &gb_emlrtRSI;
    h_st.site = &hb_emlrtRSI;
    xi = 1;
    ix = c;
    temp = muDoubleScalarAbs(b_A[c]);
    for (k = 2; k <= 76 - j; k++) {
      ix++;
      emlrtDynamicBoundsCheckFastR2012b(ix + 1, 1, 5776, &bj_emlrtBCI, &h_st);
      s = muDoubleScalarAbs(b_A[ix]);
      if (s > temp) {
        xi = k;
        temp = s;
      }
    }

    if (b_A[(c + xi) - 1] != 0.0) {
      if (xi - 1 != 0) {
        ipiv[j] = (uint8_T)(j + xi);
        f_st.site = &db_emlrtRSI;
        eml_xswap(&f_st, b_A, j + 1, j + xi);
      }

      xi = (c - j) + 76;
      f_st.site = &eb_emlrtRSI;
      for (ix = c + 1; ix + 1 <= xi; ix++) {
        b_A[ix] /= b_A[c];
      }
    } else {
      info = j + 1;
    }

    f_st.site = &fb_emlrtRSI;
    g_st.site = &mb_emlrtRSI;
    h_st.site = &nb_emlrtRSI;
    temp = -1.0;
    m_t = (ptrdiff_t)(75 - j);
    n_t = (ptrdiff_t)(75 - j);
    incx_t = (ptrdiff_t)(1);
    incy_t = (ptrdiff_t)(76);
    lda_t = (ptrdiff_t)(76);
    alpha1_t = (double *)(&temp);
    Aia0_t = (double *)(&b_A[c + 77]);
    Aix0_t = (double *)(&b_A[c + 1]);
    Aiy0_t = (double *)(&b_A[c + 76]);
    dger(&m_t, &n_t, alpha1_t, Aix0_t, &incx_t, Aiy0_t, &incy_t, Aia0_t, &lda_t);
  }

  if ((info == 0) && (!(b_A[5775] != 0.0))) {
    info = 76;
  }

  if (info > 0) {
    c_st.site = &v_emlrtRSI;
    warn_singular(&c_st);
  }

  for (xi = 0; xi < 75; xi++) {
    if (ipiv[xi] != xi + 1) {
      temp = B[xi];
      B[xi] = B[ipiv[xi] - 1];
      B[ipiv[xi] - 1] = temp;
    }
  }

  c_st.site = &x_emlrtRSI;
  eml_xtrsm(b_A, B);
  c_st.site = &y_emlrtRSI;
  b_eml_xtrsm(b_A, B);
}

/* End of code generation (mldivide.c) */
