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
#include "median.h"
#include "eml_int_forloop_overflow_check.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo mf_emlrtRSI = { 14, "fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" };

static emlrtRSInfo nf_emlrtRSI = { 47, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo of_emlrtRSI = { 91, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo pf_emlrtRSI = { 93, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo qf_emlrtRSI = { 102, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo rf_emlrtRSI = { 107, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo sf_emlrtRSI = { 109, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo tf_emlrtRSI = { 120, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRSInfo pi_emlrtRSI = { 42, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo pb_emlrtRTEI = { 1, 14, "fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" };

static emlrtRTEInfo qb_emlrtRTEI = { 91, 5, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo qc_emlrtRTEI = { 42, 5, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo rc_emlrtRTEI = { 1, 14, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo nf_emlrtRTEI = { 18, 19, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtRTEInfo of_emlrtRTEI = { 34, 19, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m" };

static emlrtDCInfo r_emlrtDCI = { 69, 34, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m", 4 };

static emlrtDCInfo s_emlrtDCI = { 245, 35, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m", 4 };

static emlrtDCInfo t_emlrtDCI = { 267, 33, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m", 4 };

static emlrtDCInfo u_emlrtDCI = { 268, 33, "eml_fft",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m", 4 };

static emlrtRSInfo no_emlrtRSI = { 18, "indexDivide",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\indexDivide.m" };

/* Function Declarations */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
static void eml_fft(const emlrtStack *sp, const emxArray_real_T *x, int32_T n,
                    emxArray_creal_T *y);

/* Function Definitions */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator >= 0) {
      absNumerator = (uint32_T)numerator;
    } else {
      absNumerator = (uint32_T)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (uint32_T)denominator;
    } else {
      absDenominator = (uint32_T)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int32_T)absNumerator;
    } else {
      quotient = (int32_T)absNumerator;
    }
  }

  return quotient;
}

/*
 *
 */
static void eml_fft(const emlrtStack *sp, const emxArray_real_T *x, int32_T n,
                    emxArray_creal_T *y)
{
  boolean_T b_n;
  int32_T SZ1;
  int32_T sz[2];
  int32_T iheight;
  int32_T nd2;
  emxArray_real_T *costab1q;
  int32_T minval;
  int32_T ixDelta;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T lastChan;
  real_T e;
  int32_T k;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  int32_T c_n;
  int32_T ix;
  boolean_T overflow;
  int32_T chanStart;
  boolean_T b12;
  int32_T i;
  boolean_T b_chanStart;
  real_T temp_re;
  real_T temp_im;
  int32_T istart;
  int32_T j;
  real_T twid_im;
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
  if (n <= 0) {
    b_n = false;
  } else {
    b_n = ((n & (n - 1)) == 0);
  }

  if (b_n) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &of_emlrtRTEI,
      "Coder:toolbox:eml_fft_sizeMustBePower2", 0);
  }

  st.site = &nf_emlrtRSI;
  SZ1 = x->size[0];
  sz[1] = 1;
  sz[0] = n;
  for (iheight = 0; iheight < 2; iheight++) {
    nd2 = sz[iheight];
    if (!(nd2 > 0)) {
      emlrtNonNegativeCheckR2012b(nd2, &r_emlrtDCI, &st);
    }
  }

  iheight = y->size[0];
  y->size[0] = n;
  emxEnsureCapacity(&st, (emxArray__common *)y, iheight, (int32_T)sizeof(creal_T),
                    &rc_emlrtRTEI);
  if (n > x->size[0]) {
    nd2 = y->size[0];
    iheight = y->size[0];
    y->size[0] = nd2;
    emxEnsureCapacity(&st, (emxArray__common *)y, iheight, (int32_T)sizeof
                      (creal_T), &rc_emlrtRTEI);
    for (iheight = 0; iheight < nd2; iheight++) {
      y->data[iheight].re = 0.0;
      y->data[iheight].im = 0.0;
    }
  }

  if (x->size[0] == 0) {
  } else {
    emxInit_real_T(&st, &costab1q, 2, &qb_emlrtRTEI, true);
    minval = muIntScalarMin_sint32(SZ1, n) - 1;
    nd2 = x->size[0] - minval;
    ixDelta = muIntScalarMax_sint32(1, nd2);
    nRowsD2 = asr_s32(n + (n < 0), 1U);
    nRowsD4 = asr_s32(nRowsD2 + (nRowsD2 < 0), 1U);
    b_st.site = &no_emlrtRSI;
    lastChan = n * (div_s32(&b_st, x->size[0], x->size[0]) - 1);
    e = 6.2831853071795862 / (real_T)n;
    b_st.site = &of_emlrtRSI;
    iheight = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    nd2 = nRowsD4 + 1;
    if (!(nd2 > 0)) {
      emlrtNonNegativeCheckR2012b(nd2, &s_emlrtDCI, &b_st);
    }

    costab1q->size[1] = nd2;
    emxEnsureCapacity(&b_st, (emxArray__common *)costab1q, iheight, (int32_T)
                      sizeof(real_T), &rc_emlrtRTEI);
    costab1q->data[0] = 1.0;
    nd2 = asr_s32(nRowsD4 + (nRowsD4 < 0), 1U);
    for (k = 1; k <= nd2; k++) {
      costab1q->data[k] = muDoubleScalarCos(e * (real_T)k);
    }

    for (k = nd2 + 1; k < nRowsD4; k++) {
      costab1q->data[k] = muDoubleScalarSin(e * (real_T)(nRowsD4 - k));
    }

    emxInit_real_T(&b_st, &costab, 2, &rc_emlrtRTEI, true);
    emxInit_real_T(&b_st, &sintab, 2, &rc_emlrtRTEI, true);
    costab1q->data[nRowsD4] = 0.0;
    b_st.site = &pf_emlrtRSI;
    c_n = costab1q->size[1] - 1;
    SZ1 = (costab1q->size[1] - 1) << 1;
    iheight = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    nd2 = SZ1 + 1;
    if (!(nd2 > 0)) {
      emlrtNonNegativeCheckR2012b(nd2, &t_emlrtDCI, &b_st);
    }

    costab->size[1] = nd2;
    emxEnsureCapacity(&b_st, (emxArray__common *)costab, iheight, (int32_T)
                      sizeof(real_T), &rc_emlrtRTEI);
    iheight = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    nd2 = SZ1 + 1;
    if (!(nd2 > 0)) {
      emlrtNonNegativeCheckR2012b(nd2, &u_emlrtDCI, &b_st);
    }

    sintab->size[1] = nd2;
    emxEnsureCapacity(&b_st, (emxArray__common *)sintab, iheight, (int32_T)
                      sizeof(real_T), &rc_emlrtRTEI);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= c_n; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[c_n - k];
    }

    for (k = costab1q->size[1]; k <= SZ1; k++) {
      costab->data[k] = -costab1q->data[SZ1 - k];
      sintab->data[k] = -costab1q->data[k - c_n];
    }

    emxFree_real_T(&costab1q);
    ix = 0;
    b_st.site = &qf_emlrtRSI;
    if ((n == 0) || ((n > 0) && (0 > lastChan)) || ((n < 0) && (0 < lastChan)))
    {
      overflow = false;
    } else if (n > 0) {
      overflow = (lastChan > MAX_int32_T - n);
    } else {
      overflow = (lastChan < MIN_int32_T - n);
    }

    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    chanStart = 0;
    while (((n > 0) && (chanStart <= lastChan)) || ((n < 0) && (chanStart >=
             lastChan))) {
      nd2 = 0;
      SZ1 = chanStart;
      b_st.site = &rf_emlrtRSI;
      if (1 > minval) {
        b12 = false;
      } else {
        b12 = (minval > 2147483646);
      }

      if (b12) {
        c_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (i = 1; i <= minval; i++) {
        y->data[SZ1].re = x->data[ix];
        y->data[SZ1].im = 0.0;
        b_st.site = &sf_emlrtRSI;
        c_n = n;
        overflow = true;
        while (overflow) {
          c_n = asr_s32(c_n, 1U);
          nd2 ^= c_n;
          overflow = ((nd2 & c_n) == 0);
        }

        SZ1 = chanStart + nd2;
        ix++;
      }

      y->data[SZ1].re = x->data[ix];
      y->data[SZ1].im = 0.0;
      ix += ixDelta;
      SZ1 = (chanStart + n) - 2;
      if (n > 1) {
        b_st.site = &tf_emlrtRSI;
        if (chanStart > SZ1) {
          b_chanStart = false;
        } else {
          b_chanStart = (SZ1 > 2147483645);
        }

        if (b_chanStart) {
          c_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&c_st, true);
        }

        for (i = chanStart; i <= SZ1; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }
      }

      SZ1 = 2;
      nd2 = 4;
      k = nRowsD4;
      iheight = 1 + ((nRowsD4 - 1) << 2);
      while (k > 0) {
        i = chanStart;
        c_n = chanStart + iheight;
        while (i < c_n) {
          temp_re = y->data[i + SZ1].re;
          temp_im = y->data[i + SZ1].im;
          y->data[i + SZ1].re = y->data[i].re - temp_re;
          y->data[i + SZ1].im = y->data[i].im - temp_im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
          i += nd2;
        }

        istart = chanStart + 1;
        for (j = k; j < nRowsD2; j += k) {
          e = costab->data[j];
          twid_im = sintab->data[j];
          i = istart;
          c_n = istart + iheight;
          while (i < c_n) {
            temp_re = e * y->data[i + SZ1].re - twid_im * y->data[i + SZ1].im;
            temp_im = e * y->data[i + SZ1].im + twid_im * y->data[i + SZ1].re;
            y->data[i + SZ1].re = y->data[i].re - temp_re;
            y->data[i + SZ1].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += nd2;
          }

          istart++;
        }

        k = asr_s32(k, 1U);
        SZ1 = nd2;
        nd2 <<= 1;
        iheight -= SZ1;
      }

      chanStart += n;
    }

    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void b_fft(const emlrtStack *sp, const emxArray_real_T *x, real_T varargin_1,
           emxArray_creal_T *y)
{
  boolean_T b11;
  boolean_T b_varargin_1;
  emxArray_real_T *b_x;
  int32_T i28;
  int32_T loop_ub;
  emxArray_creal_T *b_y1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &mf_emlrtRSI;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    b11 = true;
  } else {
    b11 = false;
  }

  if (b11) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &nf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (varargin_1 <= 0.0) {
    b_varargin_1 = false;
  } else if (varargin_1 == muDoubleScalarFloor(varargin_1)) {
    if ((int32_T)varargin_1 <= 0) {
      b_varargin_1 = false;
    } else {
      b_varargin_1 = (((int32_T)varargin_1 & ((int32_T)varargin_1 - 1)) == 0);
    }
  } else {
    b_varargin_1 = false;
  }

  if (b_varargin_1) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &of_emlrtRTEI,
      "Coder:toolbox:eml_fft_sizeMustBePower2", 0);
  }

  emxInit_real_T1(&st, &b_x, 1, &pb_emlrtRTEI, true);
  i28 = b_x->size[0];
  b_x->size[0] = x->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i28, (int32_T)sizeof(real_T),
                    &pb_emlrtRTEI);
  loop_ub = x->size[1];
  for (i28 = 0; i28 < loop_ub; i28++) {
    b_x->data[i28] = x->data[x->size[0] * i28];
  }

  emxInit_creal_T1(&st, &b_y1, 1, &qc_emlrtRTEI, true);
  b_st.site = &pi_emlrtRSI;
  eml_fft(&b_st, b_x, (int32_T)varargin_1, b_y1);
  i28 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_y1->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)y, i28, (int32_T)sizeof(creal_T),
                    &pb_emlrtRTEI);
  loop_ub = b_y1->size[0];
  emxFree_real_T(&b_x);
  for (i28 = 0; i28 < loop_ub; i28++) {
    y->data[y->size[0] * i28] = b_y1->data[i28];
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
  boolean_T overflow;
  boolean_T b_varargin_1;
  int32_T n1;
  int32_T SZ1;
  int32_T sz[2];
  int32_T ihi;
  int32_T istart;
  int32_T n;
  int32_T iheight;
  emxArray_real_T *costab1q;
  int32_T minval;
  int32_T ixDelta;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T lastChan;
  real_T e;
  int32_T k;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  int32_T ix;
  int32_T chanStart;
  boolean_T b7;
  int32_T i;
  boolean_T b_chanStart;
  real_T temp_re;
  real_T temp_im;
  real_T twid_im;
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
  st.site = &mf_emlrtRSI;
  overflow = (x->size[0] != 1);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &nf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (varargin_1 <= 0.0) {
    b_varargin_1 = false;
  } else if (varargin_1 == muDoubleScalarFloor(varargin_1)) {
    if ((int32_T)varargin_1 <= 0) {
      b_varargin_1 = false;
    } else {
      b_varargin_1 = (((int32_T)varargin_1 & ((int32_T)varargin_1 - 1)) == 0);
    }
  } else {
    b_varargin_1 = false;
  }

  if (b_varargin_1) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &of_emlrtRTEI,
      "Coder:toolbox:eml_fft_sizeMustBePower2", 0);
  }

  n1 = (int32_T)varargin_1;
  b_st.site = &nf_emlrtRSI;
  SZ1 = x->size[0];
  for (ihi = 0; ihi < 2; ihi++) {
    sz[ihi] = x->size[ihi];
  }

  sz[0] = (int32_T)varargin_1;
  for (ihi = 0; ihi < 2; ihi++) {
    istart = sz[ihi];
    if (!(istart > 0)) {
      emlrtNonNegativeCheckR2012b(istart, &r_emlrtDCI, &b_st);
    }
  }

  ihi = y->size[0] * y->size[1];
  y->size[0] = (int32_T)varargin_1;
  y->size[1] = sz[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)y, ihi, (int32_T)sizeof(creal_T),
                    &pb_emlrtRTEI);
  if ((int32_T)varargin_1 > x->size[0]) {
    ihi = y->size[0] * y->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)y, ihi, (int32_T)sizeof(creal_T),
                      &pb_emlrtRTEI);
    n = y->size[1];
    for (ihi = 0; ihi < n; ihi++) {
      iheight = y->size[0];
      for (istart = 0; istart < iheight; istart++) {
        y->data[istart + y->size[0] * ihi].re = 0.0;
        y->data[istart + y->size[0] * ihi].im = 0.0;
      }
    }
  }

  if ((x->size[0] == 0) || (x->size[1] == 0)) {
  } else {
    emxInit_real_T(&b_st, &costab1q, 2, &qb_emlrtRTEI, true);
    minval = muIntScalarMin_sint32(SZ1, n1) - 1;
    n1 = x->size[0] - minval;
    ixDelta = muIntScalarMax_sint32(1, n1);
    ihi = (int32_T)varargin_1;
    nRowsD2 = asr_s32(ihi + (ihi < 0), 1U);
    nRowsD4 = asr_s32(nRowsD2 + (nRowsD2 < 0), 1U);
    c_st.site = &no_emlrtRSI;
    lastChan = (int32_T)varargin_1 * (div_s32(&c_st, x->size[0] * x->size[1],
      x->size[0]) - 1);
    e = 6.2831853071795862 / (real_T)(int32_T)varargin_1;
    c_st.site = &of_emlrtRSI;
    ihi = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    istart = nRowsD4 + 1;
    if (!(istart > 0)) {
      emlrtNonNegativeCheckR2012b(istart, &s_emlrtDCI, &c_st);
    }

    costab1q->size[1] = istart;
    emxEnsureCapacity(&c_st, (emxArray__common *)costab1q, ihi, (int32_T)sizeof
                      (real_T), &pb_emlrtRTEI);
    costab1q->data[0] = 1.0;
    n1 = asr_s32(nRowsD4 + (nRowsD4 < 0), 1U);
    for (k = 1; k <= n1; k++) {
      costab1q->data[k] = muDoubleScalarCos(e * (real_T)k);
    }

    for (k = n1 + 1; k < nRowsD4; k++) {
      costab1q->data[k] = muDoubleScalarSin(e * (real_T)(nRowsD4 - k));
    }

    emxInit_real_T(&c_st, &costab, 2, &pb_emlrtRTEI, true);
    emxInit_real_T(&c_st, &sintab, 2, &pb_emlrtRTEI, true);
    costab1q->data[nRowsD4] = 0.0;
    c_st.site = &pf_emlrtRSI;
    n = costab1q->size[1] - 1;
    n1 = (costab1q->size[1] - 1) << 1;
    ihi = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    istart = n1 + 1;
    if (!(istart > 0)) {
      emlrtNonNegativeCheckR2012b(istart, &t_emlrtDCI, &c_st);
    }

    costab->size[1] = istart;
    emxEnsureCapacity(&c_st, (emxArray__common *)costab, ihi, (int32_T)sizeof
                      (real_T), &pb_emlrtRTEI);
    ihi = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    istart = n1 + 1;
    if (!(istart > 0)) {
      emlrtNonNegativeCheckR2012b(istart, &u_emlrtDCI, &c_st);
    }

    sintab->size[1] = istart;
    emxEnsureCapacity(&c_st, (emxArray__common *)sintab, ihi, (int32_T)sizeof
                      (real_T), &pb_emlrtRTEI);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= n; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[n - k];
    }

    for (k = costab1q->size[1]; k <= n1; k++) {
      costab->data[k] = -costab1q->data[n1 - k];
      sintab->data[k] = -costab1q->data[k - n];
    }

    emxFree_real_T(&costab1q);
    ix = 0;
    c_st.site = &qf_emlrtRSI;
    if (((int32_T)varargin_1 == 0) || (((int32_T)varargin_1 > 0) && (0 >
          lastChan)) || (((int32_T)varargin_1 < 0) && (0 < lastChan))) {
      overflow = false;
    } else if ((int32_T)varargin_1 > 0) {
      overflow = (lastChan > MAX_int32_T - (int32_T)varargin_1);
    } else {
      overflow = (lastChan < MIN_int32_T - (int32_T)varargin_1);
    }

    if (overflow) {
      d_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    chanStart = 0;
    while ((((int32_T)varargin_1 > 0) && (chanStart <= lastChan)) || (((int32_T)
             varargin_1 < 0) && (chanStart >= lastChan))) {
      SZ1 = 0;
      n1 = chanStart;
      c_st.site = &rf_emlrtRSI;
      if (1 > minval) {
        b7 = false;
      } else {
        b7 = (minval > 2147483646);
      }

      if (b7) {
        d_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (i = 1; i <= minval; i++) {
        y->data[n1] = x->data[ix];
        c_st.site = &sf_emlrtRSI;
        n = (int32_T)varargin_1;
        overflow = true;
        while (overflow) {
          n = asr_s32(n, 1U);
          SZ1 ^= n;
          overflow = ((SZ1 & n) == 0);
        }

        n1 = chanStart + SZ1;
        ix++;
      }

      y->data[n1] = x->data[ix];
      ix += ixDelta;
      n1 = (chanStart + (int32_T)varargin_1) - 2;
      if ((int32_T)varargin_1 > 1) {
        c_st.site = &tf_emlrtRSI;
        if (chanStart > n1) {
          b_chanStart = false;
        } else {
          b_chanStart = (n1 > 2147483645);
        }

        if (b_chanStart) {
          d_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&d_st, true);
        }

        for (i = chanStart; i <= n1; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }
      }

      n1 = 2;
      SZ1 = 4;
      k = nRowsD4;
      iheight = 1 + ((nRowsD4 - 1) << 2);
      while (k > 0) {
        i = chanStart;
        ihi = chanStart + iheight;
        while (i < ihi) {
          temp_re = y->data[i + n1].re;
          temp_im = y->data[i + n1].im;
          y->data[i + n1].re = y->data[i].re - temp_re;
          y->data[i + n1].im = y->data[i].im - temp_im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
          i += SZ1;
        }

        istart = chanStart + 1;
        for (n = k; n < nRowsD2; n += k) {
          e = costab->data[n];
          twid_im = sintab->data[n];
          i = istart;
          ihi = istart + iheight;
          while (i < ihi) {
            temp_re = e * y->data[i + n1].re - twid_im * y->data[i + n1].im;
            temp_im = e * y->data[i + n1].im + twid_im * y->data[i + n1].re;
            y->data[i + n1].re = y->data[i].re - temp_re;
            y->data[i + n1].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += SZ1;
          }

          istart++;
        }

        k = asr_s32(k, 1U);
        n1 = SZ1;
        SZ1 <<= 1;
        iheight -= n1;
      }

      chanStart += (int32_T)varargin_1;
    }

    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fft.c) */
