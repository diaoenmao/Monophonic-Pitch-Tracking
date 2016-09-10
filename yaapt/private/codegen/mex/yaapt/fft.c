/*
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "fft.h"
#include "yaapt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo lf_emlrtRSI = { 14, "fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" };

static emlrtRSInfo mf_emlrtRSI = { 67, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo nf_emlrtRSI = { 73, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo of_emlrtRSI = { 74, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo pf_emlrtRSI = { 76, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo qf_emlrtRSI = { 78, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo wf_emlrtRSI = { 124, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo xf_emlrtRSI = { 128, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo yf_emlrtRSI = { 135, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo ig_emlrtRSI = { 426, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo jg_emlrtRSI = { 435, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo kg_emlrtRSI = { 438, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo lg_emlrtRSI = { 440, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo mg_emlrtRSI = { 441, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo ng_emlrtRSI = { 293, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo og_emlrtRSI = { 308, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo pg_emlrtRSI = { 310, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo qg_emlrtRSI = { 319, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo rg_emlrtRSI = { 159, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo sg_emlrtRSI = { 160, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo tg_emlrtRSI = { 169, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo ug_emlrtRSI = { 170, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo vg_emlrtRSI = { 172, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo wg_emlrtRSI = { 173, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo xg_emlrtRSI = { 9, "bluestein_setup",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\bluestein_setup.m"
};

static emlrtRSInfo yg_emlrtRSI = { 40, "bluestein_setup",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\bluestein_setup.m"
};

static emlrtRSInfo ah_emlrtRSI = { 49, "bluestein_setup",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\bluestein_setup.m"
};

static emlrtRSInfo bh_emlrtRSI = { 205, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo ch_emlrtRSI = { 214, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo dh_emlrtRSI = { 219, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo eh_emlrtRSI = { 229, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo fh_emlrtRSI = { 232, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo gh_emlrtRSI = { 237, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo hh_emlrtRSI = { 251, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo ih_emlrtRSI = { 430, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo jh_emlrtRSI = { 296, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo bk_emlrtRSI = { 45, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo ck_emlrtRSI = { 163, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo dk_emlrtRSI = { 208, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo qb_emlrtRTEI = { 1, 14, "fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" };

static emlrtRTEInfo rb_emlrtRTEI = { 115, 40, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo sb_emlrtRTEI = { 124, 5, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo tb_emlrtRTEI = { 417, 14, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo ub_emlrtRTEI = { 440, 13, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo vb_emlrtRTEI = { 156, 14, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo wb_emlrtRTEI = { 172, 13, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo xb_emlrtRTEI = { 228, 5, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo yb_emlrtRTEI = { 231, 5, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo ac_emlrtRTEI = { 160, 1, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo bc_emlrtRTEI = { 261, 14, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo bd_emlrtRTEI = { 45, 9, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo cd_emlrtRTEI = { 1, 14, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo yf_emlrtRTEI = { 18, 19, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtDCInfo u_emlrtDCI = { 19, 34, "alloc_fft_output",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\alloc_fft_output.m",
  4 };

static emlrtRTEInfo ag_emlrtRTEI = { 109, 5, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtDCInfo v_emlrtDCI = { 479, 35, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m",
  4 };

static emlrtDCInfo w_emlrtDCI = { 505, 33, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m",
  4 };

static emlrtDCInfo x_emlrtDCI = { 506, 33, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m",
  4 };

static emlrtDCInfo y_emlrtDCI = { 510, 40, "eml_fft",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m",
  4 };

static emlrtDCInfo ab_emlrtDCI = { 31, 28, "bluestein_setup",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\bluestein_setup.m",
  4 };

/* Function Declarations */
static void b_dobluesteinfft(const emlrtStack *sp, const emxArray_real_T *x,
  int32_T N2, int32_T n1, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, const emxArray_real_T *sintabinv, emxArray_creal_T *y);
static void b_generate_twiddle_tables(const emlrtStack *sp, int32_T nRows,
  boolean_T useRadix2, emxArray_real_T *costab, emxArray_real_T *sintab,
  emxArray_real_T *sintabinv);
static void b_r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y);
static void c_r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y);
static void dobluesteinfft(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T N2, int32_T n1, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, const emxArray_real_T *sintabinv, emxArray_creal_T *y);
static void eml_fft(const emlrtStack *sp, const emxArray_real_T *x, int32_T n,
                    emxArray_creal_T *y);
static void generate_twiddle_tables(const emlrtStack *sp, int32_T nRows,
  boolean_T useRadix2, emxArray_real_T *costab, emxArray_real_T *sintab,
  emxArray_real_T *sintabinv);
static void get_algo_sizes(const emlrtStack *sp, int32_T n1, boolean_T useRadix2,
  int32_T *N2blue, int32_T *nRows);
static void r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y);
static void r2br_r2dit_trig_impl(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T xoffInit, int32_T unsigned_nRows, const emxArray_real_T *costab, const
  emxArray_real_T *sintab, emxArray_creal_T *y);

/* Function Definitions */

/*
 *
 */
static void b_dobluesteinfft(const emlrtStack *sp, const emxArray_real_T *x,
  int32_T N2, int32_T n1, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, const emxArray_real_T *sintabinv, emxArray_creal_T *y)
{
  emxArray_creal_T *wwc;
  int32_T nInt2m1;
  int32_T rt;
  int32_T idx;
  int32_T nInt2;
  int32_T k;
  int32_T b_y;
  real_T nt_im;
  real_T nt_re;
  int32_T sz[2];
  emxArray_creal_T *fy;
  emxArray_creal_T *fv;
  real_T fv_re;
  real_T fv_im;
  boolean_T overflow;
  real_T wwc_re;
  real_T b_fv_im;
  real_T wwc_im;
  real_T b_fv_re;
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
  emxInit_creal_T1(sp, &wwc, 1, &ac_emlrtRTEI, true);
  st.site = &sg_emlrtRSI;
  b_st.site = &xg_emlrtRSI;
  nInt2m1 = (n1 + n1) - 2;
  rt = wwc->size[0];
  idx = nInt2m1 + 1;
  if (!(idx >= 0)) {
    emlrtNonNegativeCheckR2012b(idx, &ab_emlrtDCI, &b_st);
  }

  wwc->size[0] = idx;
  emxEnsureCapacity(&b_st, (emxArray__common *)wwc, rt, (int32_T)sizeof(creal_T),
                    &vb_emlrtRTEI);
  idx = n1;
  rt = 0;
  wwc->data[n1 - 1].re = 1.0;
  wwc->data[n1 - 1].im = 0.0;
  nInt2 = n1 << 1;
  c_st.site = &yg_emlrtRSI;
  if ((!(1 > n1 - 1)) && (n1 - 1 > 2147483646)) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  for (k = 1; k < n1; k++) {
    b_y = (k << 1) - 1;
    if (nInt2 - rt <= b_y) {
      rt += b_y - nInt2;
    } else {
      rt += b_y;
    }

    nt_im = -3.1415926535897931 * (real_T)rt / (real_T)n1;
    nt_re = muDoubleScalarCos(nt_im);
    nt_im = muDoubleScalarSin(nt_im);
    wwc->data[idx - 2].re = nt_re;
    wwc->data[idx - 2].im = -nt_im;
    idx--;
  }

  idx = 0;
  c_st.site = &ah_emlrtRSI;
  if ((!(nInt2m1 < n1)) && (n1 < -2147483647)) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  while (nInt2m1 >= n1) {
    wwc->data[nInt2m1] = wwc->data[idx];
    idx++;
    nInt2m1--;
  }

  st.site = &ck_emlrtRSI;
  idx = x->size[0];
  nInt2 = muIntScalarMin_sint32(n1, idx);
  b_st.site = &dk_emlrtRSI;
  sz[1] = 1;
  sz[0] = n1;
  for (rt = 0; rt < 2; rt++) {
    idx = sz[rt];
    if (!(idx >= 0)) {
      emlrtNonNegativeCheckR2012b(idx, &u_emlrtDCI, &b_st);
    }
  }

  rt = y->size[0];
  y->size[0] = n1;
  emxEnsureCapacity(&b_st, (emxArray__common *)y, rt, (int32_T)sizeof(creal_T),
                    &vb_emlrtRTEI);
  if (n1 > x->size[0]) {
    b_y = y->size[0];
    rt = y->size[0];
    y->size[0] = b_y;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, rt, (int32_T)sizeof(creal_T),
                      &vb_emlrtRTEI);
    for (rt = 0; rt < b_y; rt++) {
      y->data[rt].re = 0.0;
      y->data[rt].im = 0.0;
    }
  }

  idx = 0;
  b_st.site = &ch_emlrtRSI;
  if ((!(1 > nInt2)) && (nInt2 > 2147483646)) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = 0; k + 1 <= nInt2; k++) {
    nt_re = wwc->data[(n1 + k) - 1].re;
    nt_im = wwc->data[(n1 + k) - 1].im;
    y->data[k].re = nt_re * x->data[idx];
    y->data[k].im = nt_im * -x->data[idx];
    idx++;
  }

  b_st.site = &dh_emlrtRSI;
  if ((!(nInt2 + 1 > n1)) && (n1 > 2147483646)) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  while (nInt2 + 1 <= n1) {
    y->data[nInt2].re = 0.0;
    y->data[nInt2].im = 0.0;
    nInt2++;
  }

  emxInit_creal_T1(&st, &fy, 1, &xb_emlrtRTEI, true);
  emxInit_creal_T1(&st, &fv, 1, &yb_emlrtRTEI, true);
  b_st.site = &eh_emlrtRSI;
  r2br_r2dit_trig_impl(&b_st, y, 0, N2, costab, sintab, fy);
  b_st.site = &fh_emlrtRSI;
  b_r2br_r2dit_trig(&b_st, wwc, N2, costab, sintab, fv);
  rt = fy->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)fy, rt, (int32_T)sizeof(creal_T),
                    &vb_emlrtRTEI);
  idx = fy->size[0];
  for (rt = 0; rt < idx; rt++) {
    nt_re = fy->data[rt].re;
    nt_im = fy->data[rt].im;
    fv_re = fv->data[rt].re;
    fv_im = fv->data[rt].im;
    fy->data[rt].re = nt_re * fv_re - nt_im * fv_im;
    fy->data[rt].im = nt_re * fv_im + nt_im * fv_re;
  }

  b_st.site = &gh_emlrtRSI;
  c_r2br_r2dit_trig(&b_st, fy, N2, costab, sintabinv, fv);
  idx = 0;
  b_st.site = &hh_emlrtRSI;
  emxFree_creal_T(&fy);
  overflow = ((!(n1 > wwc->size[0])) && (wwc->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = n1 - 1; k + 1 <= wwc->size[0]; k++) {
    nt_re = wwc->data[k].re;
    fv_re = fv->data[k].re;
    nt_im = wwc->data[k].im;
    fv_im = fv->data[k].im;
    wwc_re = wwc->data[k].re;
    b_fv_im = fv->data[k].im;
    wwc_im = wwc->data[k].im;
    b_fv_re = fv->data[k].re;
    y->data[idx].re = nt_re * fv_re + nt_im * fv_im;
    y->data[idx].im = wwc_re * b_fv_im - wwc_im * b_fv_re;
    idx++;
  }

  emxFree_creal_T(&fv);
  emxFree_creal_T(&wwc);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
static void b_generate_twiddle_tables(const emlrtStack *sp, int32_T nRows,
  boolean_T useRadix2, emxArray_real_T *costab, emxArray_real_T *sintab,
  emxArray_real_T *sintabinv)
{
  emxArray_real_T *costab1q;
  real_T e;
  int32_T nRowsD4;
  int32_T nd2;
  int32_T k;
  int32_T n2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &costab1q, 2, &sb_emlrtRTEI, true);
  e = 6.2831853071795862 / (real_T)nRows;
  nRowsD4 = nRows / 2 / 2;
  st.site = &wf_emlrtRSI;
  nd2 = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  k = nRowsD4 + 1;
  if (!(k >= 0)) {
    emlrtNonNegativeCheckR2012b(k, &v_emlrtDCI, &st);
  }

  costab1q->size[1] = k;
  emxEnsureCapacity(&st, (emxArray__common *)costab1q, nd2, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  costab1q->data[0] = 1.0;
  nd2 = nRowsD4 / 2;
  for (k = 1; k <= nd2; k++) {
    costab1q->data[k] = muDoubleScalarCos(e * (real_T)k);
  }

  for (k = nd2 + 1; k < nRowsD4; k++) {
    costab1q->data[k] = muDoubleScalarSin(e * (real_T)(nRowsD4 - k));
  }

  costab1q->data[nRowsD4] = 0.0;
  if (!useRadix2) {
    st.site = &xf_emlrtRSI;
    nRowsD4 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &w_emlrtDCI, &st);
    }

    costab->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)costab, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &x_emlrtDCI, &st);
    }

    sintab->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)sintab, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &y_emlrtDCI, &st);
    }

    sintabinv->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)sintabinv, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    for (k = 1; k <= nRowsD4; k++) {
      sintabinv->data[k] = costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      sintabinv->data[k] = costab1q->data[k - nRowsD4];
    }

    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nRowsD4];
    }
  } else {
    st.site = &yf_emlrtRSI;
    nRowsD4 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &w_emlrtDCI, &st);
    }

    costab->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)costab, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &x_emlrtDCI, &st);
    }

    sintab->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)sintab, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nRowsD4];
    }

    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)sintabinv, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
  }

  emxFree_real_T(&costab1q);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
static void b_r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y)
{
  int32_T SZ1;
  int32_T istart;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T sz[2];
  int32_T ix;
  int32_T ju;
  int32_T i;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  int32_T j;
  real_T twid_re;
  real_T twid_im;
  int32_T ihi;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ih_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  SZ1 = x->size[0];
  istart = muIntScalarMin_sint32(SZ1, n1_unsigned) - 1;
  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  b_st.site = &jh_emlrtRSI;
  sz[1] = 1;
  sz[0] = n1_unsigned;
  for (ix = 0; ix < 2; ix++) {
    SZ1 = sz[ix];
    if (!(SZ1 >= 0)) {
      emlrtNonNegativeCheckR2012b(SZ1, &u_emlrtDCI, &b_st);
    }
  }

  ix = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity(&b_st, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                    &tb_emlrtRTEI);
  if (n1_unsigned > x->size[0]) {
    SZ1 = y->size[0];
    ix = y->size[0];
    y->size[0] = SZ1;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                      &tb_emlrtRTEI);
    for (ix = 0; ix < SZ1; ix++) {
      y->data[ix].re = 0.0;
      y->data[ix].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  SZ1 = 0;
  b_st.site = &og_emlrtRSI;
  if ((!(1 > istart)) && (istart > 2147483646)) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (i = 1; i <= istart; i++) {
    y->data[SZ1] = x->data[ix];
    b_st.site = &pg_emlrtRSI;
    SZ1 = n1_unsigned;
    tst = true;
    while (tst) {
      SZ1 >>= 1;
      ju ^= SZ1;
      tst = ((ju & SZ1) == 0);
    }

    SZ1 = ju;
    ix++;
  }

  y->data[SZ1] = x->data[ix];
  if (n1_unsigned > 1) {
    b_st.site = &qg_emlrtRSI;
    for (i = 0; i <= n1_unsigned - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  SZ1 = 2;
  ix = 4;
  ju = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ju; i += ix) {
      temp_re = y->data[i + SZ1].re;
      temp_im = y->data[i + SZ1].im;
      y->data[i + SZ1].re = y->data[i].re - temp_re;
      y->data[i + SZ1].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        temp_re = twid_re * y->data[i + SZ1].re - twid_im * y->data[i + SZ1].im;
        temp_im = twid_re * y->data[i + SZ1].im + twid_im * y->data[i + SZ1].re;
        y->data[i + SZ1].re = y->data[i].re - temp_re;
        y->data[i + SZ1].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    nRowsD4 /= 2;
    SZ1 = ix;
    ix <<= 1;
    ju -= SZ1;
  }
}

/*
 *
 */
static void c_r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y)
{
  int32_T SZ1;
  int32_T istart;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T sz[2];
  int32_T ix;
  int32_T ju;
  int32_T i;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  real_T r;
  int32_T j;
  real_T twid_im;
  int32_T ihi;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ih_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  SZ1 = x->size[0];
  istart = muIntScalarMin_sint32(SZ1, n1_unsigned) - 1;
  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  b_st.site = &jh_emlrtRSI;
  sz[1] = 1;
  sz[0] = n1_unsigned;
  for (ix = 0; ix < 2; ix++) {
    SZ1 = sz[ix];
    if (!(SZ1 >= 0)) {
      emlrtNonNegativeCheckR2012b(SZ1, &u_emlrtDCI, &b_st);
    }
  }

  ix = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity(&b_st, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                    &tb_emlrtRTEI);
  if (n1_unsigned > x->size[0]) {
    SZ1 = y->size[0];
    ix = y->size[0];
    y->size[0] = SZ1;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                      &tb_emlrtRTEI);
    for (ix = 0; ix < SZ1; ix++) {
      y->data[ix].re = 0.0;
      y->data[ix].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  SZ1 = 0;
  b_st.site = &og_emlrtRSI;
  if ((!(1 > istart)) && (istart > 2147483646)) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (i = 1; i <= istart; i++) {
    y->data[SZ1] = x->data[ix];
    b_st.site = &pg_emlrtRSI;
    SZ1 = n1_unsigned;
    tst = true;
    while (tst) {
      SZ1 >>= 1;
      ju ^= SZ1;
      tst = ((ju & SZ1) == 0);
    }

    SZ1 = ju;
    ix++;
  }

  y->data[SZ1] = x->data[ix];
  if (n1_unsigned > 1) {
    b_st.site = &qg_emlrtRSI;
    for (i = 0; i <= n1_unsigned - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  SZ1 = 2;
  ix = 4;
  ju = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ju; i += ix) {
      temp_re = y->data[i + SZ1].re;
      temp_im = y->data[i + SZ1].im;
      y->data[i + SZ1].re = y->data[i].re - temp_re;
      y->data[i + SZ1].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      r = costab->data[j];
      twid_im = sintab->data[j];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        temp_re = r * y->data[i + SZ1].re - twid_im * y->data[i + SZ1].im;
        temp_im = r * y->data[i + SZ1].im + twid_im * y->data[i + SZ1].re;
        y->data[i + SZ1].re = y->data[i].re - temp_re;
        y->data[i + SZ1].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    nRowsD4 /= 2;
    SZ1 = ix;
    ix <<= 1;
    ju -= SZ1;
  }

  if (y->size[0] > 1) {
    r = 1.0 / (real_T)y->size[0];
    ix = y->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                      &tb_emlrtRTEI);
    SZ1 = y->size[0];
    for (ix = 0; ix < SZ1; ix++) {
      y->data[ix].re *= r;
      y->data[ix].im *= r;
    }
  }
}

/*
 *
 */
static void dobluesteinfft(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T N2, int32_T n1, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, const emxArray_real_T *sintabinv, emxArray_creal_T *y)
{
  uint32_T sx[2];
  int32_T nInt2;
  emxArray_creal_T *wwc;
  int32_T nInt2m1;
  int32_T k;
  int32_T idx;
  int32_T rt;
  int32_T nrows;
  real_T nt_im;
  real_T nt_re;
  int32_T sz[2];
  boolean_T overflow;
  int32_T b_k;
  emxArray_creal_T *fv;
  emxArray_creal_T *fy;
  emxArray_creal_T *rwork;
  int32_T c_k;
  int32_T xoff;
  int32_T b_idx;
  int32_T minNrowsNx;
  int32_T b_sz[2];
  int32_T d_k;
  real_T wwc_re;
  real_T wwc_im;
  real_T b_wwc_re;
  real_T fv_im;
  real_T b_wwc_im;
  real_T fv_re;
  real_T b_fv_re;
  boolean_T b_overflow;
  real_T b_fv_im;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &rg_emlrtRSI;
  for (nInt2 = 0; nInt2 < 2; nInt2++) {
    sx[nInt2] = (uint32_T)x->size[nInt2];
  }

  emxInit_creal_T1(&st, &wwc, 1, &ac_emlrtRTEI, true);
  st.site = &sg_emlrtRSI;
  b_st.site = &xg_emlrtRSI;
  nInt2m1 = (n1 + n1) - 2;
  nInt2 = wwc->size[0];
  k = nInt2m1 + 1;
  if (!(k >= 0)) {
    emlrtNonNegativeCheckR2012b(k, &ab_emlrtDCI, &b_st);
  }

  wwc->size[0] = k;
  emxEnsureCapacity(&b_st, (emxArray__common *)wwc, nInt2, (int32_T)sizeof
                    (creal_T), &vb_emlrtRTEI);
  idx = n1;
  rt = 0;
  wwc->data[n1 - 1].re = 1.0;
  wwc->data[n1 - 1].im = 0.0;
  nInt2 = n1 << 1;
  c_st.site = &yg_emlrtRSI;
  if ((!(1 > n1 - 1)) && (n1 - 1 > 2147483646)) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  for (k = 1; k < n1; k++) {
    nrows = (k << 1) - 1;
    if (nInt2 - rt <= nrows) {
      rt += nrows - nInt2;
    } else {
      rt += nrows;
    }

    nt_im = -3.1415926535897931 * (real_T)rt / (real_T)n1;
    nt_re = muDoubleScalarCos(nt_im);
    nt_im = muDoubleScalarSin(nt_im);
    wwc->data[idx - 2].re = nt_re;
    wwc->data[idx - 2].im = -nt_im;
    idx--;
  }

  idx = 0;
  c_st.site = &ah_emlrtRSI;
  if ((!(nInt2m1 < n1)) && (n1 < -2147483647)) {
    d_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  while (nInt2m1 >= n1) {
    wwc->data[nInt2m1] = wwc->data[idx];
    idx++;
    nInt2m1--;
  }

  nrows = x->size[0];
  st.site = &tg_emlrtRSI;
  for (nInt2 = 0; nInt2 < 2; nInt2++) {
    sz[nInt2] = x->size[nInt2];
  }

  sz[0] = n1;
  for (nInt2 = 0; nInt2 < 2; nInt2++) {
    k = sz[nInt2];
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &u_emlrtDCI, &st);
    }
  }

  nInt2 = y->size[0] * y->size[1];
  y->size[0] = n1;
  y->size[1] = sz[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, nInt2, (int32_T)sizeof(creal_T),
                    &vb_emlrtRTEI);
  if (n1 > x->size[0]) {
    nInt2 = y->size[0] * y->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)y, nInt2, (int32_T)sizeof(creal_T),
                      &vb_emlrtRTEI);
    idx = y->size[1];
    for (nInt2 = 0; nInt2 < idx; nInt2++) {
      rt = y->size[0];
      for (k = 0; k < rt; k++) {
        y->data[k + y->size[0] * nInt2].re = 0.0;
        y->data[k + y->size[0] * nInt2].im = 0.0;
      }
    }
  }

  st.site = &ug_emlrtRSI;
  if (1 > (int32_T)sx[1]) {
    overflow = false;
  } else {
    overflow = ((int32_T)sx[1] > 2147483646);
  }

  if (overflow) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st, true);
  }

  idx = (int32_T)sx[1];
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(fv,fy,rwork,c_k,xoff,b_idx,minNrowsNx,d_k,wwc_re,wwc_im,b_wwc_re,fv_im,b_wwc_im,fv_re,b_fv_re,b_fv_im,b_overflow,b_emlrtJBEnviron) \
 firstprivate(e_st,f_st,g_st,h_st,b_sz,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      e_st.prev = sp;
      e_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      e_st.site = NULL;
      emlrtSetJmpBuf(&e_st, &b_emlrtJBEnviron);
      f_st.prev = &e_st;
      f_st.tls = e_st.tls;
      g_st.prev = &f_st;
      g_st.tls = f_st.tls;
      h_st.prev = &g_st;
      h_st.tls = g_st.tls;
      emxInit_creal_T1(&e_st, &fv, 1, &yb_emlrtRTEI, true);
      emxInit_creal_T1(&e_st, &fy, 1, &xb_emlrtRTEI, true);
      emxInit_creal_T1(&e_st, &rwork, 1, &wb_emlrtRTEI, true);
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (b_k = 1; b_k <= idx; b_k++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        c_k = b_k;
        xoff = (c_k - 1) * nrows;
        f_st.site = &vg_emlrtRSI;
        b_idx = x->size[0];
        minNrowsNx = muIntScalarMin_sint32(n1, b_idx);
        g_st.site = &bh_emlrtRSI;
        b_sz[1] = 1;
        b_sz[0] = n1;
        for (d_k = 0; d_k < 2; d_k++) {
          b_idx = b_sz[d_k];
          if (!(b_idx >= 0)) {
            emlrtNonNegativeCheckR2012b(b_idx, &u_emlrtDCI, &g_st);
          }
        }

        d_k = rwork->size[0];
        rwork->size[0] = n1;
        emxEnsureCapacity(&g_st, (emxArray__common *)rwork, d_k, (int32_T)sizeof
                          (creal_T), &vb_emlrtRTEI);
        b_idx = x->size[0];
        if (n1 > b_idx) {
          b_idx = rwork->size[0];
          d_k = rwork->size[0];
          rwork->size[0] = b_idx;
          emxEnsureCapacity(&g_st, (emxArray__common *)rwork, d_k, (int32_T)
                            sizeof(creal_T), &vb_emlrtRTEI);
          for (d_k = 0; d_k < b_idx; d_k++) {
            rwork->data[d_k].re = 0.0;
            rwork->data[d_k].im = 0.0;
          }
        }

        g_st.site = &ch_emlrtRSI;
        if ((!(1 > minNrowsNx)) && (minNrowsNx > 2147483646)) {
          h_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&h_st, true);
        }

        for (d_k = 0; d_k + 1 <= minNrowsNx; d_k++) {
          wwc_re = wwc->data[(n1 + d_k) - 1].re;
          wwc_im = wwc->data[(n1 + d_k) - 1].im;
          b_wwc_re = x->data[xoff].re;
          fv_im = x->data[xoff].im;
          b_wwc_im = x->data[xoff].im;
          fv_re = x->data[xoff].re;
          rwork->data[d_k].re = wwc_re * b_wwc_re + wwc_im * fv_im;
          rwork->data[d_k].im = wwc_re * b_wwc_im - wwc_im * fv_re;
          xoff++;
        }

        g_st.site = &dh_emlrtRSI;
        if ((!(minNrowsNx + 1 > n1)) && (n1 > 2147483646)) {
          h_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&h_st, true);
        }

        while (minNrowsNx + 1 <= n1) {
          rwork->data[minNrowsNx].re = 0.0;
          rwork->data[minNrowsNx].im = 0.0;
          minNrowsNx++;
        }

        g_st.site = &eh_emlrtRSI;
        r2br_r2dit_trig_impl(&g_st, rwork, 0, N2, costab, sintab, fy);
        g_st.site = &fh_emlrtRSI;
        b_r2br_r2dit_trig(&g_st, wwc, N2, costab, sintab, fv);
        d_k = fy->size[0];
        emxEnsureCapacity(&f_st, (emxArray__common *)fy, d_k, (int32_T)sizeof
                          (creal_T), &vb_emlrtRTEI);
        b_idx = fy->size[0];
        for (d_k = 0; d_k < b_idx; d_k++) {
          wwc_re = fy->data[d_k].re;
          wwc_im = fy->data[d_k].im;
          b_fv_re = fv->data[d_k].re;
          b_fv_im = fv->data[d_k].im;
          fy->data[d_k].re = wwc_re * b_fv_re - wwc_im * b_fv_im;
          fy->data[d_k].im = wwc_re * b_fv_im + wwc_im * b_fv_re;
        }

        g_st.site = &gh_emlrtRSI;
        c_r2br_r2dit_trig(&g_st, fy, N2, costab, sintabinv, fv);
        b_idx = 0;
        g_st.site = &hh_emlrtRSI;
        b_overflow = ((!(n1 > wwc->size[0])) && (wwc->size[0] > 2147483646));
        if (b_overflow) {
          h_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&h_st, true);
        }

        for (d_k = n1 - 1; d_k + 1 <= wwc->size[0]; d_k++) {
          wwc_re = wwc->data[d_k].re;
          b_fv_re = fv->data[d_k].re;
          wwc_im = wwc->data[d_k].im;
          b_fv_im = fv->data[d_k].im;
          b_wwc_re = wwc->data[d_k].re;
          fv_im = fv->data[d_k].im;
          b_wwc_im = wwc->data[d_k].im;
          fv_re = fv->data[d_k].re;
          rwork->data[b_idx].re = wwc_re * b_fv_re + wwc_im * b_fv_im;
          rwork->data[b_idx].im = b_wwc_re * fv_im - b_wwc_im * fv_re;
          b_idx++;
        }

        f_st.site = &wg_emlrtRSI;
        for (b_idx = 0; b_idx + 1 <= n1; b_idx++) {
          y->data[b_idx + y->size[0] * (c_k - 1)] = rwork->data[b_idx];
        }
      } else {
        emlrtHadParallelError = true;
      }
    }

    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&e_st, 3);
      emxFree_creal_T(&rwork);
      emxFree_creal_T(&fy);
      emxFree_creal_T(&fv);
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
  emxFree_creal_T(&wwc);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
static void eml_fft(const emlrtStack *sp, const emxArray_real_T *x, int32_T n,
                    emxArray_creal_T *y)
{
  int32_T iy;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  boolean_T useRadix2;
  int32_T iDelta;
  int32_T sz[2];
  int32_T b_x[1];
  emxArray_real_T c_x;
  int32_T j;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T ix;
  int32_T ju;
  int32_T i;
  real_T temp_re;
  real_T temp_im;
  real_T twid_re;
  real_T twid_im;
  int32_T ihi;
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
  iy = x->size[0];
  emxInit_real_T(sp, &costab, 2, &cd_emlrtRTEI, true);
  emxInit_real_T(sp, &sintab, 2, &cd_emlrtRTEI, true);
  emxInit_real_T(sp, &sintabinv, 2, &cd_emlrtRTEI, true);
  if ((iy == 0) || (n == 0)) {
    st.site = &mf_emlrtRSI;
    sz[1] = 1;
    sz[0] = n;
    for (iDelta = 0; iDelta < 2; iDelta++) {
      iy = sz[iDelta];
      if (!(iy >= 0)) {
        emlrtNonNegativeCheckR2012b(iy, &u_emlrtDCI, &st);
      }
    }

    iDelta = y->size[0];
    y->size[0] = n;
    emxEnsureCapacity(&st, (emxArray__common *)y, iDelta, (int32_T)sizeof
                      (creal_T), &cd_emlrtRTEI);
    iy = x->size[0];
    if (n > iy) {
      iy = y->size[0];
      iDelta = y->size[0];
      y->size[0] = iy;
      emxEnsureCapacity(&st, (emxArray__common *)y, iDelta, (int32_T)sizeof
                        (creal_T), &cd_emlrtRTEI);
      for (iDelta = 0; iDelta < iy; iDelta++) {
        y->data[iDelta].re = 0.0;
        y->data[iDelta].im = 0.0;
      }
    }
  } else {
    useRadix2 = ((!(n <= 0)) && ((n & (n - 1)) == 0));
    st.site = &nf_emlrtRSI;
    get_algo_sizes(&st, n, useRadix2, &iy, &iDelta);
    st.site = &of_emlrtRSI;
    b_generate_twiddle_tables(&st, iDelta, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      st.site = &pf_emlrtRSI;
      b_st.site = &ih_emlrtRSI;
      iy = x->size[0];
      j = muIntScalarMin_sint32(iy, n) - 1;
      nRowsD2 = n / 2;
      nRowsD4 = nRowsD2 / 2;
      c_st.site = &jh_emlrtRSI;
      sz[1] = 1;
      sz[0] = n;
      for (iDelta = 0; iDelta < 2; iDelta++) {
        iy = sz[iDelta];
        if (!(iy >= 0)) {
          emlrtNonNegativeCheckR2012b(iy, &u_emlrtDCI, &c_st);
        }
      }

      iDelta = y->size[0];
      y->size[0] = n;
      emxEnsureCapacity(&c_st, (emxArray__common *)y, iDelta, (int32_T)sizeof
                        (creal_T), &cd_emlrtRTEI);
      iy = x->size[0];
      if (n > iy) {
        iy = y->size[0];
        iDelta = y->size[0];
        y->size[0] = iy;
        emxEnsureCapacity(&c_st, (emxArray__common *)y, iDelta, (int32_T)sizeof
                          (creal_T), &cd_emlrtRTEI);
        for (iDelta = 0; iDelta < iy; iDelta++) {
          y->data[iDelta].re = 0.0;
          y->data[iDelta].im = 0.0;
        }
      }

      ix = 0;
      ju = 0;
      iy = 0;
      c_st.site = &og_emlrtRSI;
      if ((!(1 > j)) && (j > 2147483646)) {
        d_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (i = 1; i <= j; i++) {
        y->data[iy].re = x->data[ix];
        y->data[iy].im = 0.0;
        c_st.site = &pg_emlrtRSI;
        iDelta = n;
        useRadix2 = true;
        while (useRadix2) {
          iDelta >>= 1;
          ju ^= iDelta;
          useRadix2 = ((ju & iDelta) == 0);
        }

        iy = ju;
        ix++;
      }

      y->data[iy].re = x->data[ix];
      y->data[iy].im = 0.0;
      if (n > 1) {
        c_st.site = &qg_emlrtRSI;
        for (i = 0; i <= n - 2; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }
      }

      iDelta = 2;
      iy = 4;
      ix = 1 + ((nRowsD4 - 1) << 2);
      while (nRowsD4 > 0) {
        for (i = 0; i < ix; i += iy) {
          temp_re = y->data[i + iDelta].re;
          temp_im = y->data[i + iDelta].im;
          y->data[i + iDelta].re = y->data[i].re - temp_re;
          y->data[i + iDelta].im = y->data[i].im - temp_im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }

        ju = 1;
        for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
          twid_re = costab->data[j];
          twid_im = sintab->data[j];
          i = ju;
          ihi = ju + ix;
          while (i < ihi) {
            temp_re = twid_re * y->data[i + iDelta].re - twid_im * y->data[i +
              iDelta].im;
            temp_im = twid_re * y->data[i + iDelta].im + twid_im * y->data[i +
              iDelta].re;
            y->data[i + iDelta].re = y->data[i].re - temp_re;
            y->data[i + iDelta].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += iy;
          }

          ju++;
        }

        nRowsD4 /= 2;
        iDelta = iy;
        iy <<= 1;
        ix -= iDelta;
      }
    } else {
      b_x[0] = x->size[0];
      c_x = *x;
      c_x.size = (int32_T *)&b_x;
      c_x.numDimensions = 1;
      st.site = &qf_emlrtRSI;
      b_dobluesteinfft(&st, &c_x, iy, n, costab, sintab, sintabinv, y);
    }
  }

  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
static void generate_twiddle_tables(const emlrtStack *sp, int32_T nRows,
  boolean_T useRadix2, emxArray_real_T *costab, emxArray_real_T *sintab,
  emxArray_real_T *sintabinv)
{
  emxArray_real_T *costab1q;
  real_T e;
  int32_T nRowsD4;
  int32_T nd2;
  int32_T k;
  int32_T n2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &costab1q, 2, &sb_emlrtRTEI, true);
  e = 6.2831853071795862 / (real_T)nRows;
  nRowsD4 = nRows / 2 / 2;
  st.site = &wf_emlrtRSI;
  nd2 = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  k = nRowsD4 + 1;
  if (!(k >= 0)) {
    emlrtNonNegativeCheckR2012b(k, &v_emlrtDCI, &st);
  }

  costab1q->size[1] = k;
  emxEnsureCapacity(&st, (emxArray__common *)costab1q, nd2, (int32_T)sizeof
                    (real_T), &rb_emlrtRTEI);
  costab1q->data[0] = 1.0;
  nd2 = nRowsD4 / 2;
  for (k = 1; k <= nd2; k++) {
    costab1q->data[k] = muDoubleScalarCos(e * (real_T)k);
  }

  for (k = nd2 + 1; k < nRowsD4; k++) {
    costab1q->data[k] = muDoubleScalarSin(e * (real_T)(nRowsD4 - k));
  }

  costab1q->data[nRowsD4] = 0.0;
  if (!useRadix2) {
    st.site = &xf_emlrtRSI;
    nRowsD4 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &w_emlrtDCI, &st);
    }

    costab->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)costab, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &x_emlrtDCI, &st);
    }

    sintab->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)sintab, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &y_emlrtDCI, &st);
    }

    sintabinv->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)sintabinv, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    for (k = 1; k <= nRowsD4; k++) {
      sintabinv->data[k] = costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      sintabinv->data[k] = costab1q->data[k - nRowsD4];
    }

    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nRowsD4];
    }
  } else {
    st.site = &yf_emlrtRSI;
    nRowsD4 = costab1q->size[1] - 1;
    n2 = (costab1q->size[1] - 1) << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &w_emlrtDCI, &st);
    }

    costab->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)costab, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    k = n2 + 1;
    if (!(k >= 0)) {
      emlrtNonNegativeCheckR2012b(k, &x_emlrtDCI, &st);
    }

    sintab->size[1] = k;
    emxEnsureCapacity(&st, (emxArray__common *)sintab, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[nRowsD4 - k];
    }

    for (k = costab1q->size[1]; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - nRowsD4];
    }

    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)sintabinv, nd2, (int32_T)sizeof
                      (real_T), &rb_emlrtRTEI);
  }

  emxFree_real_T(&costab1q);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
static void get_algo_sizes(const emlrtStack *sp, int32_T n1, boolean_T useRadix2,
  int32_T *N2blue, int32_T *nRows)
{
  int32_T nn1m1;
  int32_T pmax;
  int32_T pmin;
  boolean_T exitg1;
  int32_T i21;
  int32_T pow2p;
  *N2blue = 1;
  if (useRadix2) {
    *nRows = n1;
  } else {
    if (n1 > 0) {
      nn1m1 = (n1 + n1) - 1;
      pmax = 31;
      if (nn1m1 > MIN_int32_T) {
        if (nn1m1 < 0) {
          nn1m1 = -nn1m1;
        }

        if (nn1m1 <= 1) {
          pmax = 0;
        } else {
          pmin = 0;
          exitg1 = false;
          while ((!exitg1) && (pmax - pmin > 1)) {
            i21 = (pmin + pmax) >> 1;
            pow2p = 1 << i21;
            if (pow2p == nn1m1) {
              pmax = i21;
              exitg1 = true;
            } else if (pow2p > nn1m1) {
              pmax = i21;
            } else {
              pmin = i21;
            }
          }
        }
      }

      *N2blue = 1 << pmax;
    }

    nn1m1 = n1 << 2;
    if (*N2blue <= muIntScalarMax_sint32(nn1m1, 1)) {
    } else {
      emlrtErrorWithMessageIdR2012b(sp, &ag_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    *nRows = *N2blue;
  }
}

/*
 *
 */
static void r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y)
{
  uint32_T sx[2];
  int32_T ub_loop;
  int32_T n1;
  int32_T nrows;
  int32_T sz[2];
  int32_T i22;
  int32_T loop_ub;
  boolean_T overflow;
  int32_T b_loop_ub;
  int32_T k;
  emxArray_creal_T *rwork;
  int32_T b_k;
  int32_T xoff;
  int32_T SZ1;
  int32_T iheight;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T b_sz[2];
  int32_T ju;
  int32_T i;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  int32_T j;
  real_T twid_re;
  real_T twid_im;
  int32_T ihi;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &ig_emlrtRSI;
  for (ub_loop = 0; ub_loop < 2; ub_loop++) {
    sx[ub_loop] = (uint32_T)x->size[ub_loop];
  }

  n1 = n1_unsigned;
  nrows = x->size[0];
  st.site = &jg_emlrtRSI;
  for (ub_loop = 0; ub_loop < 2; ub_loop++) {
    sz[ub_loop] = x->size[ub_loop];
  }

  sz[0] = n1_unsigned;
  for (ub_loop = 0; ub_loop < 2; ub_loop++) {
    i22 = sz[ub_loop];
    if (!(i22 >= 0)) {
      emlrtNonNegativeCheckR2012b(i22, &u_emlrtDCI, &st);
    }
  }

  ub_loop = y->size[0] * y->size[1];
  y->size[0] = n1_unsigned;
  y->size[1] = sz[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, ub_loop, (int32_T)sizeof(creal_T),
                    &tb_emlrtRTEI);
  if (n1_unsigned > x->size[0]) {
    ub_loop = y->size[0] * y->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)y, ub_loop, (int32_T)sizeof
                      (creal_T), &tb_emlrtRTEI);
    loop_ub = y->size[1];
    for (ub_loop = 0; ub_loop < loop_ub; ub_loop++) {
      b_loop_ub = y->size[0];
      for (i22 = 0; i22 < b_loop_ub; i22++) {
        y->data[i22 + y->size[0] * ub_loop].re = 0.0;
        y->data[i22 + y->size[0] * ub_loop].im = 0.0;
      }
    }
  }

  st.site = &kg_emlrtRSI;
  if (1 > (int32_T)sx[1]) {
    overflow = false;
  } else {
    overflow = ((int32_T)sx[1] > 2147483646);
  }

  if (overflow) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st, true);
  }

  ub_loop = (int32_T)sx[1];
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(rwork,b_k,xoff,SZ1,iheight,nRowsD2,nRowsD4,ju,i,tst,temp_re,temp_im,j,twid_re,twid_im,ihi,b_emlrtJBEnviron) \
 firstprivate(c_st,d_st,e_st,f_st,b_sz,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      c_st.prev = sp;
      c_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      c_st.site = NULL;
      emlrtSetJmpBuf(&c_st, &b_emlrtJBEnviron);
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      e_st.prev = &d_st;
      e_st.tls = d_st.tls;
      f_st.prev = &e_st;
      f_st.tls = e_st.tls;
      emxInit_creal_T1(&c_st, &rwork, 1, &ub_emlrtRTEI, true);
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (k = 1; k <= ub_loop; k++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        b_k = k;
        xoff = (b_k - 1) * nrows;
        d_st.site = &lg_emlrtRSI;
        SZ1 = x->size[0];
        iheight = muIntScalarMin_sint32(SZ1, n1_unsigned) - 1;
        nRowsD2 = n1_unsigned / 2;
        nRowsD4 = nRowsD2 / 2;
        e_st.site = &ng_emlrtRSI;
        b_sz[1] = 1;
        b_sz[0] = n1_unsigned;
        for (ju = 0; ju < 2; ju++) {
          SZ1 = b_sz[ju];
          if (!(SZ1 >= 0)) {
            emlrtNonNegativeCheckR2012b(SZ1, &u_emlrtDCI, &e_st);
          }
        }

        ju = rwork->size[0];
        rwork->size[0] = n1_unsigned;
        emxEnsureCapacity(&e_st, (emxArray__common *)rwork, ju, (int32_T)sizeof
                          (creal_T), &tb_emlrtRTEI);
        SZ1 = x->size[0];
        if (n1_unsigned > SZ1) {
          SZ1 = rwork->size[0];
          ju = rwork->size[0];
          rwork->size[0] = SZ1;
          emxEnsureCapacity(&e_st, (emxArray__common *)rwork, ju, (int32_T)
                            sizeof(creal_T), &tb_emlrtRTEI);
          for (ju = 0; ju < SZ1; ju++) {
            rwork->data[ju].re = 0.0;
            rwork->data[ju].im = 0.0;
          }
        }

        ju = 0;
        SZ1 = 0;
        e_st.site = &og_emlrtRSI;
        if ((!(1 > iheight)) && (iheight > 2147483646)) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        for (i = 1; i <= iheight; i++) {
          rwork->data[SZ1] = x->data[xoff];
          e_st.site = &pg_emlrtRSI;
          SZ1 = n1_unsigned;
          tst = true;
          while (tst) {
            SZ1 >>= 1;
            ju ^= SZ1;
            tst = ((ju & SZ1) == 0);
          }

          SZ1 = ju;
          xoff++;
        }

        rwork->data[SZ1] = x->data[xoff];
        if (n1_unsigned > 1) {
          e_st.site = &qg_emlrtRSI;
          for (i = 0; i <= n1_unsigned - 2; i += 2) {
            temp_re = rwork->data[i + 1].re;
            temp_im = rwork->data[i + 1].im;
            rwork->data[i + 1].re = rwork->data[i].re - rwork->data[i + 1].re;
            rwork->data[i + 1].im = rwork->data[i].im - rwork->data[i + 1].im;
            rwork->data[i].re += temp_re;
            rwork->data[i].im += temp_im;
          }
        }

        SZ1 = 2;
        ju = 4;
        iheight = 1 + ((nRowsD4 - 1) << 2);
        while (nRowsD4 > 0) {
          for (i = 0; i < iheight; i += ju) {
            temp_re = rwork->data[i + SZ1].re;
            temp_im = rwork->data[i + SZ1].im;
            rwork->data[i + SZ1].re = rwork->data[i].re - temp_re;
            rwork->data[i + SZ1].im = rwork->data[i].im - temp_im;
            rwork->data[i].re += temp_re;
            rwork->data[i].im += temp_im;
          }

          xoff = 1;
          for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
            twid_re = costab->data[j];
            twid_im = sintab->data[j];
            i = xoff;
            ihi = xoff + iheight;
            while (i < ihi) {
              temp_re = twid_re * rwork->data[i + SZ1].re - twid_im *
                rwork->data[i + SZ1].im;
              temp_im = twid_re * rwork->data[i + SZ1].im + twid_im *
                rwork->data[i + SZ1].re;
              rwork->data[i + SZ1].re = rwork->data[i].re - temp_re;
              rwork->data[i + SZ1].im = rwork->data[i].im - temp_im;
              rwork->data[i].re += temp_re;
              rwork->data[i].im += temp_im;
              i += ju;
            }

            xoff++;
          }

          nRowsD4 /= 2;
          SZ1 = ju;
          ju <<= 1;
          iheight -= SZ1;
        }

        d_st.site = &mg_emlrtRSI;
        if ((!(1 > n1)) && (n1 > 2147483646)) {
          e_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&e_st, true);
        }

        for (SZ1 = 0; SZ1 + 1 <= n1; SZ1++) {
          y->data[SZ1 + y->size[0] * (b_k - 1)] = rwork->data[SZ1];
        }
      } else {
        emlrtHadParallelError = true;
      }
    }

    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&c_st, 1);
      emxFree_creal_T(&rwork);
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
static void r2br_r2dit_trig_impl(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T xoffInit, int32_T unsigned_nRows, const emxArray_real_T *costab, const
  emxArray_real_T *sintab, emxArray_creal_T *y)
{
  int32_T SZ1;
  int32_T istart;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T sz[2];
  int32_T ix;
  int32_T ju;
  int32_T i;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  int32_T j;
  real_T twid_re;
  real_T twid_im;
  int32_T ihi;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  SZ1 = x->size[0];
  istart = muIntScalarMin_sint32(SZ1, unsigned_nRows) - 1;
  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  st.site = &ng_emlrtRSI;
  sz[1] = 1;
  sz[0] = unsigned_nRows;
  for (ix = 0; ix < 2; ix++) {
    SZ1 = sz[ix];
    if (!(SZ1 >= 0)) {
      emlrtNonNegativeCheckR2012b(SZ1, &u_emlrtDCI, &st);
    }
  }

  ix = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity(&st, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                    &bc_emlrtRTEI);
  SZ1 = x->size[0];
  if (unsigned_nRows > SZ1) {
    SZ1 = y->size[0];
    ix = y->size[0];
    y->size[0] = SZ1;
    emxEnsureCapacity(&st, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                      &bc_emlrtRTEI);
    for (ix = 0; ix < SZ1; ix++) {
      y->data[ix].re = 0.0;
      y->data[ix].im = 0.0;
    }
  }

  ix = xoffInit;
  ju = 0;
  SZ1 = 0;
  st.site = &og_emlrtRSI;
  if ((!(1 > istart)) && (istart > 2147483646)) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st, true);
  }

  for (i = 1; i <= istart; i++) {
    y->data[SZ1] = x->data[ix];
    st.site = &pg_emlrtRSI;
    SZ1 = unsigned_nRows;
    tst = true;
    while (tst) {
      SZ1 >>= 1;
      ju ^= SZ1;
      tst = ((ju & SZ1) == 0);
    }

    SZ1 = ju;
    ix++;
  }

  y->data[SZ1] = x->data[ix];
  if (unsigned_nRows > 1) {
    st.site = &qg_emlrtRSI;
    for (i = 0; i <= unsigned_nRows - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  SZ1 = 2;
  ix = 4;
  ju = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ju; i += ix) {
      temp_re = y->data[i + SZ1].re;
      temp_im = y->data[i + SZ1].im;
      y->data[i + SZ1].re = y->data[i].re - temp_re;
      y->data[i + SZ1].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        temp_re = twid_re * y->data[i + SZ1].re - twid_im * y->data[i + SZ1].im;
        temp_im = twid_re * y->data[i + SZ1].im + twid_im * y->data[i + SZ1].re;
        y->data[i + SZ1].re = y->data[i].re - temp_re;
        y->data[i + SZ1].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    nRowsD4 /= 2;
    SZ1 = ix;
    ix <<= 1;
    ju -= SZ1;
  }
}

/*
 *
 */
void b_fft(const emlrtStack *sp, const emxArray_real_T *x, real_T varargin_1,
           emxArray_creal_T *y)
{
  boolean_T b2;
  emxArray_creal_T *b_y1;
  int32_T b_x[2];
  emxArray_real_T c_x;
  int32_T i32;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &lf_emlrtRSI;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b2 = true;
  } else {
    b2 = false;
  }

  if (b2) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &yf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  emxInit_creal_T1(&st, &b_y1, 1, &bd_emlrtRTEI, true);
  b_x[0] = x->size[1];
  b_x[1] = 1;
  c_x = *x;
  c_x.size = (int32_T *)&b_x;
  c_x.numDimensions = 1;
  b_st.site = &bk_emlrtRSI;
  eml_fft(&b_st, &c_x, (int32_T)varargin_1, b_y1);
  i32 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)varargin_1;
  emxEnsureCapacity(&st, (emxArray__common *)y, i32, (int32_T)sizeof(creal_T),
                    &qb_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i32 = 0; i32 < loop_ub; i32++) {
    y->data[i32] = b_y1->data[i32];
  }

  emxFree_creal_T(&b_y1);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void fft(const emlrtStack *sp, const emxArray_creal_T *x, real_T varargin_1,
         emxArray_creal_T *y)
{
  boolean_T useRadix2;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  int32_T N2blue;
  int32_T nRows;
  int32_T sz[2];
  int32_T i20;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &lf_emlrtRSI;
  useRadix2 = (x->size[0] != 1);
  if (useRadix2) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &yf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  emxInit_real_T(&st, &costab, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &sintab, 2, &qb_emlrtRTEI, true);
  emxInit_real_T(&st, &sintabinv, 2, &qb_emlrtRTEI, true);
  if ((x->size[0] == 0) || (x->size[1] == 0) || ((int32_T)varargin_1 == 0)) {
    b_st.site = &mf_emlrtRSI;
    for (N2blue = 0; N2blue < 2; N2blue++) {
      sz[N2blue] = x->size[N2blue];
    }

    sz[0] = (int32_T)varargin_1;
    for (N2blue = 0; N2blue < 2; N2blue++) {
      i20 = sz[N2blue];
      if (!(i20 >= 0)) {
        emlrtNonNegativeCheckR2012b(i20, &u_emlrtDCI, &b_st);
      }
    }

    N2blue = y->size[0] * y->size[1];
    y->size[0] = (int32_T)varargin_1;
    y->size[1] = sz[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)y, N2blue, (int32_T)sizeof
                      (creal_T), &qb_emlrtRTEI);
    if ((int32_T)varargin_1 > x->size[0]) {
      N2blue = y->size[0] * y->size[1];
      emxEnsureCapacity(&b_st, (emxArray__common *)y, N2blue, (int32_T)sizeof
                        (creal_T), &qb_emlrtRTEI);
      nRows = y->size[1];
      for (N2blue = 0; N2blue < nRows; N2blue++) {
        loop_ub = y->size[0];
        for (i20 = 0; i20 < loop_ub; i20++) {
          y->data[i20 + y->size[0] * N2blue].re = 0.0;
          y->data[i20 + y->size[0] * N2blue].im = 0.0;
        }
      }
    }
  } else {
    useRadix2 = ((!((int32_T)varargin_1 <= 0)) && (((int32_T)varargin_1 &
      ((int32_T)varargin_1 - 1)) == 0));
    b_st.site = &nf_emlrtRSI;
    get_algo_sizes(&b_st, (int32_T)varargin_1, useRadix2, &N2blue, &nRows);
    b_st.site = &of_emlrtRSI;
    generate_twiddle_tables(&b_st, nRows, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      b_st.site = &pf_emlrtRSI;
      r2br_r2dit_trig(&b_st, x, (int32_T)varargin_1, costab, sintab, y);
    } else {
      b_st.site = &qf_emlrtRSI;
      dobluesteinfft(&b_st, x, N2blue, (int32_T)varargin_1, costab, sintab,
                     sintabinv, y);
    }
  }

  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fft.c) */
