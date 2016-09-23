/*
 * Myfirls.c
 *
 * Code generation for function 'Myfirls'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myfirls.h"
#include "mpower.h"
#include "Myhanning.h"
#include "yaapt_emxutil.h"
#include "sinc.h"
#include "rdivide.h"
#include "cos.h"
#include "indexShapeCheck.h"
#include "mldivide.h"
#include "error.h"
#include "any.h"
#include "diff.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 88, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo eb_emlrtRSI = { 91, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo fb_emlrtRSI = { 99, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo gb_emlrtRSI = { 101, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo hb_emlrtRSI = { 110, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo ib_emlrtRSI = { 119, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo jb_emlrtRSI = { 120, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo kb_emlrtRSI = { 121, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo lb_emlrtRSI = { 122, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo mb_emlrtRSI = { 123, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo nb_emlrtRSI = { 124, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo ob_emlrtRSI = { 125, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo pb_emlrtRSI = { 126, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo qb_emlrtRSI = { 127, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo rb_emlrtRSI = { 135, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo sb_emlrtRSI = { 137, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo tb_emlrtRSI = { 139, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo pd_emlrtRSI = { 22, "flipud",
  "F:\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\flipud.m" };

static emlrtRTEInfo k_emlrtRTEI = { 1, 12, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo l_emlrtRTEI = { 99, 9, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo m_emlrtRTEI = { 105, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo n_emlrtRTEI = { 106, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo o_emlrtRTEI = { 107, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo p_emlrtRTEI = { 110, 9, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo q_emlrtRTEI = { 114, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo r_emlrtRTEI = { 130, 9, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 137, 33, "a", "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 137, 33, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 137, 27, "a", "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 137, 12, "a", "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 137, 12, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtECInfo b_emlrtECI = { 2, 125, 13, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtDCInfo f_emlrtDCI = { 127, 28, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtECInfo c_emlrtECI = { 2, 125, 18, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo d_emlrtECI = { 2, 126, 27, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo e_emlrtECI = { 2, 125, 29, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo f_emlrtECI = { -1, 122, 13, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtDCInfo g_emlrtDCI = { 124, 28, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtECInfo g_emlrtECI = { -1, 122, 18, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo h_emlrtECI = { -1, 120, 13, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtDCInfo h_emlrtDCI = { 121, 28, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtECInfo i_emlrtECI = { -1, 120, 29, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtDCInfo i_emlrtDCI = { 119, 28, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 110, 11, "a", "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 0 };

static emlrtECInfo j_emlrtECI = { 2, 106, 8, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo k_emlrtECI = { 2, 105, 8, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

/* Function Definitions */
void Myfirls(const emlrtStack *sp, real_T N, real_T F[6], emxArray_real_T *h)
{
  emxArray_real_T *p;
  int32_T i5;
  real_T dv0[5];
  boolean_T bv0[5];
  int32_T ixstart;
  real_T xtmp;
  int32_T md2;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T exitg1;
  real_T L;
  emxArray_real_T *m;
  int32_T n;
  real_T apnd;
  real_T ndbl;
  boolean_T n_too_large;
  real_T cdiff;
  int32_T loop_ub;
  uint32_T uv0[2];
  emxArray_real_T *b_p;
  uint32_T unnamed_idx_0;
  int32_T c_p[2];
  int32_T i6;
  emxArray_real_T *b_m;
  int32_T c_m[2];
  emxArray_real_T *I1;
  emxArray_real_T *d_p;
  int32_T e_p[2];
  emxArray_real_T *d_m;
  int32_T e_m[2];
  emxArray_real_T *I2;
  emxArray_real_T *G;
  real_T b0;
  emxArray_real_T *k;
  int32_T iv5[2];
  emxArray_real_T *b;
  int32_T s;
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  emxArray_real_T *r4;
  emxArray_real_T *x;
  emxArray_real_T *a;
  emxArray_real_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *r9;
  emxArray_real_T *r10;
  emxArray_real_T *r11;
  emxArray_real_T *y;
  emxArray_real_T *b_k;
  int32_T b_s;
  real_T f_m;
  static const int8_T M[6] = { 0, 0, 1, 1, 0, 0 };

  real_T b1;
  int32_T iv6[2];
  int32_T i7;
  int32_T iv7[2];
  emxArray_real_T *b_x;
  int32_T b_a[2];
  int32_T iv8[2];
  int32_T iv9[2];
  int32_T iv10[2];
  int32_T c_a[2];
  int32_T iv11[2];
  int32_T b_G[2];
  int32_T d_a[2];
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
  emxInit_real_T2(sp, &p, 1, &r_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 5U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 0);

  /*  FIRLS	Linear-phase FIR filter design using least-squares error minimization */
  /* 	B=FIRLS(N,F,M) returns a length N+1 linear phase (real, symmetric */
  /* 	coefficients) FIR filter which has the best approximation to the  */
  /* 	desired frequency response described by F and M in the least squares  */
  /* 	sense. F is a vector of frequency band edges in pairs, in ascending  */
  /* 	order between 0 and 1. 1 corresponds to the Nyquist frequency or half */
  /* 	the sampling frequency. M is a real vector the same size as F  */
  /* 	which specifies the desired magnitude of the frequency response of the */
  /* 	resultant filter B. The desired response is the line connecting the */
  /* 	points (F(k),M(k)) and (F(k+1),M(k+1)) for odd k; FIRLS treats the  */
  /* 	bands between F(k+1) and F(k+2) for odd k as "transition bands" or  */
  /* 	"don't care" regions. Thus the desired magnitude is piecewise linear */
  /* 	with transition bands.  The integrated squared error is minimized. */
  /*  */
  /* 	B=FIRLS(N,F,M,W) uses the weights in W to weight the error. W has one */
  /* 	entry per band (so it is half the length of F and M) which tells */
  /* 	FIRLS how much emphasis to put on minimizing the integral squared error */
  /* 	in each band relative to the other bands. */
  /* 	 */
  /* 	B=FIRLS(N,F,M,'Hilbert') and B=FIRLS(N,F,M,W,'Hilbert') design filters  */
  /* 	that have odd symmetry, that is, B(k) = -B(N+2-k) for k = 1, ..., N+1.  */
  /* 	A special case is a Hilbert transformer which has an approx. magnitude */
  /* 	of 1 across the entire band, e.g. B=FIRLS(30,[.1 .9],[1 1],'Hilbert').  */
  /*  */
  /* 	B=FIRLS(N,F,M,'differentiator') and B=FIRLS(N,F,M,W,'differentiator') */
  /* 	also design filters with odd symmetry, but with a special weighting */
  /* 	scheme for non-zero magnitude bands. The weight is assumed to be equal  */
  /* 	to the inverse of frequency, squared, times the weight W. Thus the  */
  /* 	filter has a much better fit at low frequency than at high frequency.  */
  /* 	This designs FIR differentiators. */
  /*  */
  /* 	See also REMEZ, FIR1, FIR2, FREQZ and FILTER. */
  /* 	Example of a length 29 low-pass filter: */
  /* 		h=firls(30,[0 .1 .2 .5]*2,[1 1 0 0]); */
  /* 	Example of a low-pass differentiator:  */
  /* 		h=firls(N,[0 10 20 40]/50,[0 .2 0 0],'differentiator'); */
  /*  */
  /*        Author(s): T. Krauss, 10-18-91 */
  /*    		   T. Krauss, 3-30-93, updated */
  /* 	Copyright (c) 1984-94 by The MathWorks, Inc. */
  /* 	$Revision: 1.8 $  $Date: 1994/01/25 17:59:10 $ */
  /*  check number of arguments, set up defaults. */
  /*  nargchk(3,5,nargin); */
  /*  if (nargin==3) */
  /*      ftype = ''; */
  /*  end */
  /*  if (nargin==4), */
  /*      if isstr(W),  */
  /*          ftype = W; W = ones(length(F)/2,1); */
  /*      else */
  /*          ftype = ''; */
  /*      end */
  /*  end	 */
  /*  if (nargin==5), */
  /*      if isempty(W),  */
  /*          W = ones(length(F)/2,1); */
  /*      end */
  /*  end */
  /*  if isempty(ftype) */
  /*  else */
  /*      ftype = lower(ftype); */
  /*      if strcmp(ftype,'h')|strcmp(ftype,'hilbert') */
  /*          ftype = 1;  differ = 0; */
  /*      elseif strcmp(ftype,'d')|strcmp(ftype,'differentiator') */
  /*          ftype = 1;  differ = 1; */
  /*      else */
  /*          error('Requires symmetry to be ''Hilbert'' or ''differentiator''.') */
  /*      end */
  /*  end */
  N++;

  /*  filter length */
  for (i5 = 0; i5 < 6; i5++) {
    F[i5] /= 2.0;
  }

  /*  make these guys columns */
  covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 1, false);
  covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 2, false);
  diff(F, dv0);
  for (ixstart = 0; ixstart < 5; ixstart++) {
    bv0[ixstart] = (dv0[ixstart] < 0.0);
  }

  if (covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 3, b_any(bv0))) {
    st.site = &db_emlrtRSI;
    b_error(&st);
  }

  ixstart = 1;
  xtmp = F[0];
  if (muDoubleScalarIsNaN(F[0])) {
    md2 = 2;
    exitg2 = false;
    while ((!exitg2) && (md2 < 7)) {
      ixstart = md2;
      if (!muDoubleScalarIsNaN(F[md2 - 1])) {
        xtmp = F[md2 - 1];
        exitg2 = true;
      } else {
        md2++;
      }
    }
  }

  if (ixstart < 6) {
    while (ixstart + 1 < 7) {
      if (F[ixstart] > xtmp) {
        xtmp = F[ixstart];
      }

      ixstart++;
    }
  }

  guard1 = false;
  if (covrtLogCond(&emlrtCoverageInstance, 5U, 0U, 0, xtmp > 1.0)) {
    guard1 = true;
  } else {
    ixstart = 1;
    xtmp = F[0];
    if (muDoubleScalarIsNaN(F[0])) {
      md2 = 2;
      exitg1 = false;
      while ((!exitg1) && (md2 < 7)) {
        ixstart = md2;
        if (!muDoubleScalarIsNaN(F[md2 - 1])) {
          xtmp = F[md2 - 1];
          exitg1 = true;
        } else {
          md2++;
        }
      }
    }

    if (ixstart < 6) {
      while (ixstart + 1 < 7) {
        if (F[ixstart] < xtmp) {
          xtmp = F[ixstart];
        }

        ixstart++;
      }
    }

    if (covrtLogCond(&emlrtCoverageInstance, 5U, 0U, 1, xtmp < 0.0)) {
      guard1 = true;
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 5U, 0U, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 4, false);
    }
  }

  if (guard1) {
    covrtLogMcdc(&emlrtCoverageInstance, 5U, 0U, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 4, true);
    st.site = &eb_emlrtRSI;
    c_error(&st);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 4);
  L = (N - 1.0) / 2.0;
  covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 5, true);

  /*  Type I and Type II linear phase FIR  */
  /*  basis vectors are cos(2*pi*m*f) (see m below) */
  emxInit_real_T(sp, &m, 2, &l_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 6, muDoubleScalarRem(N, 2.0) ==
                 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 5);
    st.site = &fb_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    c_st.site = &w_emlrtRSI;
    if (muDoubleScalarIsNaN(L)) {
      n = 1;
      xtmp = rtNaN;
      apnd = L;
      n_too_large = false;
    } else if (L < 0.0) {
      n = 0;
      xtmp = 0.0;
      apnd = L;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(L)) {
      n = 1;
      xtmp = rtNaN;
      apnd = L;
      n_too_large = !(0.0 == L);
    } else {
      xtmp = 0.0;
      ndbl = muDoubleScalarFloor(L + 0.5);
      apnd = ndbl;
      cdiff = ndbl - L;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * L) {
        ndbl++;
        apnd = L;
      } else if (cdiff > 0.0) {
        apnd = ndbl - 1.0;
      } else {
        ndbl++;
      }

      n_too_large = (2.147483647E+9 < ndbl);
      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }
    }

    d_st.site = &x_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &df_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i5 = m->size[0] * m->size[1];
    m->size[0] = 1;
    m->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)m, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    if (n > 0) {
      m->data[0] = xtmp;
      if (n > 1) {
        m->data[n - 1] = apnd;
        ixstart = (n - 1) / 2;
        d_st.site = &y_emlrtRSI;
        for (md2 = 1; md2 < ixstart; md2++) {
          m->data[md2] = xtmp + (real_T)md2;
          m->data[(n - md2) - 1] = apnd - (real_T)md2;
        }

        if (ixstart << 1 == n - 1) {
          m->data[ixstart] = (xtmp + apnd) / 2.0;
        } else {
          m->data[ixstart] = xtmp + (real_T)ixstart;
          m->data[ixstart + 1] = apnd - (real_T)ixstart;
        }
      }
    }

    i5 = m->size[0] * m->size[1];
    m->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)m, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    n = m->size[0];
    ixstart = m->size[1];
    loop_ub = n * ixstart;
    for (i5 = 0; i5 < loop_ub; i5++) {
      m->data[i5] += 0.5;
    }

    /*  type II */
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 6);
    st.site = &gb_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    c_st.site = &w_emlrtRSI;
    if (muDoubleScalarIsNaN(L)) {
      n = 1;
      xtmp = rtNaN;
      apnd = L;
      n_too_large = false;
    } else if (L < 0.0) {
      n = 0;
      xtmp = 0.0;
      apnd = L;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(L)) {
      n = 1;
      xtmp = rtNaN;
      apnd = L;
      n_too_large = !(0.0 == L);
    } else {
      xtmp = 0.0;
      ndbl = muDoubleScalarFloor(L + 0.5);
      apnd = ndbl;
      cdiff = ndbl - L;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * L) {
        ndbl++;
        apnd = L;
      } else if (cdiff > 0.0) {
        apnd = ndbl - 1.0;
      } else {
        ndbl++;
      }

      n_too_large = (2.147483647E+9 < ndbl);
      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }
    }

    d_st.site = &x_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &df_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i5 = m->size[0] * m->size[1];
    m->size[0] = 1;
    m->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)m, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    if (n > 0) {
      m->data[0] = xtmp;
      if (n > 1) {
        m->data[n - 1] = apnd;
        ixstart = (n - 1) / 2;
        d_st.site = &y_emlrtRSI;
        for (md2 = 1; md2 < ixstart; md2++) {
          m->data[md2] = xtmp + (real_T)md2;
          m->data[(n - md2) - 1] = apnd - (real_T)md2;
        }

        if (ixstart << 1 == n - 1) {
          m->data[ixstart] = (xtmp + apnd) / 2.0;
        } else {
          m->data[ixstart] = xtmp + (real_T)ixstart;
          m->data[ixstart + 1] = apnd - (real_T)ixstart;
        }
      }
    }

    /*  type I */
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 7);

  /*      k=m'; */
  i5 = p->size[0];
  p->size[0] = m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)p, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = m->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    p->data[i5] = m->data[m->size[0] * i5];
  }

  for (i5 = 0; i5 < 2; i5++) {
    uv0[i5] = (uint32_T)m->size[i5];
  }

  emxInit_real_T(sp, &b_p, 2, &k_emlrtRTEI, true);
  unnamed_idx_0 = (uint32_T)p->size[0];
  loop_ub = p->size[0];
  i5 = b_p->size[0] * b_p->size[1];
  b_p->size[0] = loop_ub;
  b_p->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_p, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  ixstart = (int32_T)uv0[1];
  for (i5 = 0; i5 < ixstart; i5++) {
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_p->data[i6 + b_p->size[0] * i5] = p->data[i6];
    }
  }

  for (i5 = 0; i5 < 2; i5++) {
    c_p[i5] = b_p->size[i5];
  }

  emxFree_real_T(&b_p);
  emxInit_real_T(sp, &b_m, 2, &k_emlrtRTEI, true);
  loop_ub = m->size[1];
  i5 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = (int32_T)unnamed_idx_0;
  b_m->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  for (i5 = 0; i5 < loop_ub; i5++) {
    ixstart = (int32_T)unnamed_idx_0;
    for (i6 = 0; i6 < ixstart; i6++) {
      b_m->data[i6 + b_m->size[0] * i5] = m->data[m->size[0] * i5];
    }
  }

  for (i5 = 0; i5 < 2; i5++) {
    c_m[i5] = b_m->size[i5];
  }

  emxFree_real_T(&b_m);
  emxInit_real_T(sp, &I1, 2, &m_emlrtRTEI, true);
  if ((c_p[0] != c_m[0]) || (c_p[1] != c_m[1])) {
    emlrtSizeEqCheckNDR2012b(&c_p[0], &c_m[0], &k_emlrtECI, sp);
  }

  loop_ub = p->size[0];
  i5 = I1->size[0] * I1->size[1];
  I1->size[0] = loop_ub;
  I1->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(sp, (emxArray__common *)I1, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  ixstart = (int32_T)uv0[1];
  for (i5 = 0; i5 < ixstart; i5++) {
    for (i6 = 0; i6 < loop_ub; i6++) {
      I1->data[i6 + I1->size[0] * i5] = p->data[i6] + m->data[m->size[0] * i5];
    }
  }

  /*  entries are m + k */
  for (i5 = 0; i5 < 2; i5++) {
    uv0[i5] = (uint32_T)m->size[i5];
  }

  emxInit_real_T(sp, &d_p, 2, &k_emlrtRTEI, true);
  unnamed_idx_0 = (uint32_T)p->size[0];
  loop_ub = p->size[0];
  i5 = d_p->size[0] * d_p->size[1];
  d_p->size[0] = loop_ub;
  d_p->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_p, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  ixstart = (int32_T)uv0[1];
  for (i5 = 0; i5 < ixstart; i5++) {
    for (i6 = 0; i6 < loop_ub; i6++) {
      d_p->data[i6 + d_p->size[0] * i5] = p->data[i6];
    }
  }

  for (i5 = 0; i5 < 2; i5++) {
    e_p[i5] = d_p->size[i5];
  }

  emxFree_real_T(&d_p);
  emxInit_real_T(sp, &d_m, 2, &k_emlrtRTEI, true);
  loop_ub = m->size[1];
  i5 = d_m->size[0] * d_m->size[1];
  d_m->size[0] = (int32_T)unnamed_idx_0;
  d_m->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)d_m, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  for (i5 = 0; i5 < loop_ub; i5++) {
    ixstart = (int32_T)unnamed_idx_0;
    for (i6 = 0; i6 < ixstart; i6++) {
      d_m->data[i6 + d_m->size[0] * i5] = m->data[m->size[0] * i5];
    }
  }

  for (i5 = 0; i5 < 2; i5++) {
    e_m[i5] = d_m->size[i5];
  }

  emxFree_real_T(&d_m);
  emxInit_real_T(sp, &I2, 2, &n_emlrtRTEI, true);
  if ((e_p[0] != e_m[0]) || (e_p[1] != e_m[1])) {
    emlrtSizeEqCheckNDR2012b(&e_p[0], &e_m[0], &j_emlrtECI, sp);
  }

  loop_ub = p->size[0];
  i5 = I2->size[0] * I2->size[1];
  I2->size[0] = loop_ub;
  I2->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(sp, (emxArray__common *)I2, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  ixstart = (int32_T)uv0[1];
  for (i5 = 0; i5 < ixstart; i5++) {
    for (i6 = 0; i6 < loop_ub; i6++) {
      I2->data[i6 + I2->size[0] * i5] = p->data[i6] - m->data[m->size[0] * i5];
    }
  }

  /*  entries are m - k */
  for (i5 = 0; i5 < 2; i5++) {
    uv0[i5] = (uint32_T)I1->size[i5];
  }

  emxInit_real_T(sp, &G, 2, &o_emlrtRTEI, true);
  i5 = G->size[0] * G->size[1];
  G->size[0] = (int32_T)uv0[0];
  G->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(sp, (emxArray__common *)G, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = (int32_T)uv0[0] * (int32_T)uv0[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    G->data[i5] = 0.0;
  }

  b0 = 0.0;

  /*   first entry must be handled separately (where k(1)=0) */
  emxInit_real_T2(sp, &k, 1, &p_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 7, muDoubleScalarRem(N, 2.0) !=
                 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 8);
    if (2 > p->size[0]) {
      i5 = 0;
      ixstart = 0;
    } else {
      i5 = 1;
      i6 = p->size[0];
      ixstart = p->size[0];
      if (!((ixstart >= 1) && (ixstart <= i6))) {
        emlrtDynamicBoundsCheckR2012b(ixstart, 1, i6, &xb_emlrtBCI, sp);
      }
    }

    iv5[0] = 1;
    iv5[1] = ixstart - i5;
    st.site = &hb_emlrtRSI;
    indexShapeCheck(&st, p->size[0], iv5);
    i6 = k->size[0];
    k->size[0] = ixstart - i5;
    emxEnsureCapacity(sp, (emxArray__common *)k, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = ixstart - i5;
    for (i6 = 0; i6 < loop_ub; i6++) {
      k->data[i6] = p->data[i5 + i6];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 9);
    i5 = k->size[0];
    k->size[0] = m->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)k, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = m->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      k->data[i5] = m->data[m->size[0] * i5];
    }
  }

  emxFree_real_T(&m);
  emxInit_real_T2(sp, &b, 1, &q_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 10);
  uv0[0] = (uint32_T)k->size[0];
  i5 = b->size[0];
  b->size[0] = (int32_T)uv0[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i5, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = (int32_T)uv0[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b->data[i5] = 0.0;
  }

  s = 0;
  emxInit_real_T(sp, &r2, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r3, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r4, 2, &k_emlrtRTEI, true);
  emxInit_real_T2(sp, &x, 1, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &a, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r5, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r6, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r7, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r8, 2, &k_emlrtRTEI, true);
  emxInit_real_T2(sp, &r9, 1, &k_emlrtRTEI, true);
  emxInit_real_T2(sp, &r10, 1, &k_emlrtRTEI, true);
  emxInit_real_T2(sp, &r11, 1, &k_emlrtRTEI, true);
  emxInit_real_T2(sp, &y, 1, &k_emlrtRTEI, true);
  emxInit_real_T2(sp, &b_k, 1, &k_emlrtRTEI, true);
  while (s < 3) {
    b_s = 1 + (s << 1);
    covrtLogFor(&emlrtCoverageInstance, 5U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 11);
    f_m = (real_T)(M[b_s] - M[b_s - 1]) / (F[b_s] - F[b_s - 1]);

    /*   slope */
    b1 = (real_T)M[b_s - 1] - f_m * F[b_s - 1];

    /*   y-intercept */
    xtmp = ((real_T)b_s + 1.0) / 2.0;
    if (xtmp != muDoubleScalarFloor(xtmp)) {
      emlrtIntegerCheckR2012b(xtmp, &i_emlrtDCI, sp);
    }

    st.site = &ib_emlrtRSI;
    mpower(1.0);
    b0 += b1 * (F[b_s] - F[b_s - 1]) + f_m / 2.0 * (F[b_s] * F[b_s] - F[b_s - 1]
      * F[b_s - 1]);
    i5 = x->size[0];
    x->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)x, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      x->data[i5] = 6.2831853071795862 * k->data[i5] * F[b_s];
    }

    st.site = &jb_emlrtRSI;
    b_cos(&st, x);
    i5 = p->size[0];
    p->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      p->data[i5] = 6.2831853071795862 * k->data[i5] * F[b_s - 1];
    }

    st.site = &jb_emlrtRSI;
    b_cos(&st, p);
    i5 = x->size[0];
    i6 = p->size[0];
    if (i5 != i6) {
      emlrtSizeEqCheck1DR2012b(i5, i6, &i_emlrtECI, sp);
    }

    xtmp = ((real_T)b_s + 1.0) / 2.0;
    if (xtmp != muDoubleScalarFloor(xtmp)) {
      emlrtIntegerCheckR2012b(xtmp, &h_emlrtDCI, sp);
    }

    st.site = &kb_emlrtRSI;
    mpower(1.0);
    xtmp = f_m / 39.478417604357432;
    i5 = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)y, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = x->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      y->data[i5] = xtmp * (x->data[i5] - p->data[i5]);
    }

    i5 = b_k->size[0];
    b_k->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_k, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_k->data[i5] = k->data[i5] * k->data[i5];
    }

    st.site = &jb_emlrtRSI;
    rdivide(&st, y, b_k, x);
    i5 = b->size[0];
    i6 = x->size[0];
    if (i5 != i6) {
      emlrtSizeEqCheck1DR2012b(i5, i6, &h_emlrtECI, sp);
    }

    i5 = b->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = b->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b->data[i5] += x->data[i5];
    }

    xtmp = F[b_s] * (f_m * F[b_s] + b1);
    i5 = r11->size[0];
    r11->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r11, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      r11->data[i5] = 2.0 * k->data[i5] * F[b_s];
    }

    st.site = &lb_emlrtRSI;
    sinc(&st, r11, x);
    i5 = x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)x, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = x->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      x->data[i5] *= xtmp;
    }

    xtmp = F[b_s - 1] * (f_m * F[b_s - 1] + b1);
    i5 = r9->size[0];
    r9->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r9, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      r9->data[i5] = 2.0 * k->data[i5] * F[b_s - 1];
    }

    st.site = &mb_emlrtRSI;
    sinc(&st, r9, r10);
    i5 = p->size[0];
    p->size[0] = r10->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = r10->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      p->data[i5] = r10->data[i5];
    }

    i5 = p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = p->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      p->data[i5] *= xtmp;
    }

    i5 = x->size[0];
    i6 = p->size[0];
    if (i5 != i6) {
      emlrtSizeEqCheck1DR2012b(i5, i6, &g_emlrtECI, sp);
    }

    xtmp = ((real_T)b_s + 1.0) / 2.0;
    if (xtmp != muDoubleScalarFloor(xtmp)) {
      emlrtIntegerCheckR2012b(xtmp, &g_emlrtDCI, sp);
    }

    st.site = &nb_emlrtRSI;
    mpower(1.0);
    i5 = x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)x, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = x->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      x->data[i5] -= p->data[i5];
    }

    i5 = b->size[0];
    i6 = x->size[0];
    if (i5 != i6) {
      emlrtSizeEqCheck1DR2012b(i5, i6, &f_emlrtECI, sp);
    }

    i5 = b->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = b->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b->data[i5] += x->data[i5];
    }

    i5 = r8->size[0] * r8->size[1];
    r8->size[0] = I1->size[0];
    r8->size[1] = I1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r8, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = I1->size[0] * I1->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      r8->data[i5] = 2.0 * I1->data[i5] * F[b_s];
    }

    st.site = &ob_emlrtRSI;
    b_sinc(&st, r8, a);
    i5 = r7->size[0] * r7->size[1];
    r7->size[0] = I2->size[0];
    r7->size[1] = I2->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r7, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = I2->size[0] * I2->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      r7->data[i5] = 2.0 * I2->data[i5] * F[b_s];
    }

    st.site = &ob_emlrtRSI;
    b_sinc(&st, r7, r2);
    for (i5 = 0; i5 < 2; i5++) {
      b_a[i5] = a->size[i5];
    }

    for (i5 = 0; i5 < 2; i5++) {
      iv8[i5] = r2->size[i5];
    }

    if ((b_a[0] != iv8[0]) || (b_a[1] != iv8[1])) {
      emlrtSizeEqCheckNDR2012b(&b_a[0], &iv8[0], &e_emlrtECI, sp);
    }

    i5 = r6->size[0] * r6->size[1];
    r6->size[0] = I1->size[0];
    r6->size[1] = I1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r6, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = I1->size[0] * I1->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      r6->data[i5] = 2.0 * I1->data[i5] * F[b_s - 1];
    }

    st.site = &pb_emlrtRSI;
    b_sinc(&st, r6, r3);
    i5 = r5->size[0] * r5->size[1];
    r5->size[0] = I2->size[0];
    r5->size[1] = I2->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r5, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = I2->size[0] * I2->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      r5->data[i5] = 2.0 * I2->data[i5] * F[b_s - 1];
    }

    st.site = &pb_emlrtRSI;
    b_sinc(&st, r5, r4);
    for (i5 = 0; i5 < 2; i5++) {
      iv9[i5] = r3->size[i5];
    }

    for (i5 = 0; i5 < 2; i5++) {
      iv10[i5] = r4->size[i5];
    }

    if ((iv9[0] != iv10[0]) || (iv9[1] != iv10[1])) {
      emlrtSizeEqCheckNDR2012b(&iv9[0], &iv10[0], &d_emlrtECI, sp);
    }

    xtmp = 0.5 * F[b_s];
    i5 = a->size[0] * a->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)a, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    ixstart = a->size[0];
    md2 = a->size[1];
    loop_ub = ixstart * md2;
    for (i5 = 0; i5 < loop_ub; i5++) {
      a->data[i5] = xtmp * (a->data[i5] + r2->data[i5]);
    }

    xtmp = 0.5 * F[b_s - 1];
    i5 = r3->size[0] * r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    i5 = r3->size[0];
    i6 = r3->size[1];
    loop_ub = i5 * i6;
    for (i5 = 0; i5 < loop_ub; i5++) {
      r3->data[i5] = xtmp * (r3->data[i5] + r4->data[i5]);
    }

    for (i5 = 0; i5 < 2; i5++) {
      c_a[i5] = a->size[i5];
    }

    for (i5 = 0; i5 < 2; i5++) {
      iv11[i5] = r3->size[i5];
    }

    if ((c_a[0] != iv11[0]) || (c_a[1] != iv11[1])) {
      emlrtSizeEqCheckNDR2012b(&c_a[0], &iv11[0], &c_emlrtECI, sp);
    }

    xtmp = ((real_T)b_s + 1.0) / 2.0;
    if (xtmp != muDoubleScalarFloor(xtmp)) {
      emlrtIntegerCheckR2012b(xtmp, &f_emlrtDCI, sp);
    }

    st.site = &qb_emlrtRSI;
    mpower(1.0);
    i5 = a->size[0] * a->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)a, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    ixstart = a->size[0];
    md2 = a->size[1];
    loop_ub = ixstart * md2;
    for (i5 = 0; i5 < loop_ub; i5++) {
      a->data[i5] -= r3->data[i5];
    }

    for (i5 = 0; i5 < 2; i5++) {
      b_G[i5] = G->size[i5];
    }

    for (i5 = 0; i5 < 2; i5++) {
      d_a[i5] = a->size[i5];
    }

    if ((b_G[0] != d_a[0]) || (b_G[1] != d_a[1])) {
      emlrtSizeEqCheckNDR2012b(&b_G[0], &d_a[0], &b_emlrtECI, sp);
    }

    i5 = G->size[0] * G->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)G, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    ixstart = G->size[0];
    md2 = G->size[1];
    loop_ub = ixstart * md2;
    for (i5 = 0; i5 < loop_ub; i5++) {
      G->data[i5] += a->data[i5];
    }

    s++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_k);
  emxFree_real_T(&y);
  emxFree_real_T(&r11);
  emxFree_real_T(&r10);
  emxFree_real_T(&r9);
  emxFree_real_T(&r8);
  emxFree_real_T(&r7);
  emxFree_real_T(&r6);
  emxFree_real_T(&r5);
  emxFree_real_T(&a);
  emxFree_real_T(&r4);
  emxFree_real_T(&r3);
  emxFree_real_T(&r2);
  emxFree_real_T(&k);
  emxFree_real_T(&I2);
  emxFree_real_T(&I1);
  covrtLogFor(&emlrtCoverageInstance, 5U, 0U, 0, 0);
  if (covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 8, muDoubleScalarRem(N, 2.0) !=
                 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 12);
    i5 = p->size[0];
    p->size[0] = 1 + b->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    p->data[0] = b0;
    loop_ub = b->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      p->data[i5 + 1] = b->data[i5];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 13);
    i5 = p->size[0];
    p->size[0] = b->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = b->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      p->data[i5] = b->data[i5];
    }
  }

  emxFree_real_T(&b);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 14);
  st.site = &rb_emlrtRSI;
  mldivide(&st, G, p);
  emxFree_real_T(&G);
  if (covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 9, muDoubleScalarRem(N, 2.0) !=
                 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 15);
    if (2.0 > L + 1.0) {
      i6 = 1;
      i5 = 1;
      ixstart = 0;
    } else {
      i5 = p->size[0];
      if (L + 1.0 != (int32_T)muDoubleScalarFloor(L + 1.0)) {
        emlrtIntegerCheckR2012b(L + 1.0, &e_emlrtDCI, sp);
      }

      i6 = (int32_T)(L + 1.0);
      if (!((i6 >= 1) && (i6 <= i5))) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, i5, &wb_emlrtBCI, sp);
      }

      i5 = -1;
      ixstart = p->size[0];
      if (!(2 <= ixstart)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, ixstart, &wb_emlrtBCI, sp);
      }

      ixstart = 2;
    }

    iv6[0] = 1;
    iv6[1] = div_s32_floor(sp, ixstart - i6, i5) + 1;
    st.site = &sb_emlrtRSI;
    indexShapeCheck(&st, p->size[0], iv6);
    if (2.0 > L + 1.0) {
      md2 = 0;
      i7 = 0;
    } else {
      md2 = p->size[0];
      if (!(2 <= md2)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, md2, &ub_emlrtBCI, sp);
      }

      md2 = 1;
      n = p->size[0];
      if (L + 1.0 != (int32_T)muDoubleScalarFloor(L + 1.0)) {
        emlrtIntegerCheckR2012b(L + 1.0, &d_emlrtDCI, sp);
      }

      i7 = (int32_T)(L + 1.0);
      if (!((i7 >= 1) && (i7 <= n))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, n, &ub_emlrtBCI, sp);
      }
    }

    iv7[0] = 1;
    iv7[1] = i7 - md2;
    st.site = &sb_emlrtRSI;
    indexShapeCheck(&st, p->size[0], iv7);
    n = p->size[0];
    if (!(1 <= n)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, n, &vb_emlrtBCI, sp);
    }

    n = h->size[0] * h->size[1];
    h->size[0] = 1;
    h->size[1] = ((div_s32_floor(sp, ixstart - i6, i5) + i7) - md2) + 2;
    emxEnsureCapacity(sp, (emxArray__common *)h, n, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = div_s32_floor(sp, ixstart - i6, i5);
    for (n = 0; n <= loop_ub; n++) {
      h->data[h->size[0] * n] = p->data[(i6 + i5 * n) - 1] / 2.0;
    }

    h->data[h->size[0] * (div_s32_floor(sp, ixstart - i6, i5) + 1)] = p->data[0];
    loop_ub = i7 - md2;
    for (n = 0; n < loop_ub; n++) {
      h->data[h->size[0] * ((n + div_s32_floor(sp, ixstart - i6, i5)) + 2)] =
        p->data[md2 + n] / 2.0;
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 16);
    st.site = &tb_emlrtRSI;
    i5 = x->size[0];
    x->size[0] = p->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)x, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = p->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      x->data[i5] = p->data[i5];
    }

    n = p->size[0];
    md2 = p->size[0] >> 1;
    b_st.site = &pd_emlrtRSI;
    for (ixstart = 1; ixstart <= md2; ixstart++) {
      xtmp = x->data[ixstart - 1];
      x->data[ixstart - 1] = x->data[n - ixstart];
      x->data[n - ixstart] = xtmp;
    }

    emxInit_real_T(&st, &b_x, 2, &k_emlrtRTEI, true);
    i5 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->size[0] + p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_x, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = x->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_x->data[b_x->size[0] * i5] = x->data[i5];
    }

    loop_ub = p->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_x->data[b_x->size[0] * (i5 + x->size[0])] = p->data[i5];
    }

    i5 = h->size[0] * h->size[1];
    h->size[0] = 1;
    h->size[1] = b_x->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)h, i5, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = b_x->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      h->data[h->size[0] * i5] = 0.5 * b_x->data[b_x->size[0] * i5];
    }

    emxFree_real_T(&b_x);
  }

  emxFree_real_T(&x);

  /*  elseif (ftype == 1),  % Type III and Type IV linear phase FIR */
  /*                    %  basis vectors are sin(2*pi*m*f) (see m below) */
  /*      if (differ),      % weight non-zero bands with 1/f^2 */
  /*          do_weight = ( abs(M(1:2:length(M))) +  abs(M(2:2:length(M))) ) > 0; */
  /*      else */
  /*          do_weight = zeros(size(F)); */
  /*      end */
  /*   */
  /*      if rem(N,2), */
  /*          m=(1:L);      % type III */
  /*      else */
  /*          m=(0:L)+.5;   % type IV */
  /*      end; */
  /*      k=m'; */
  /*      I1=k(:,ones(size(m)))+m(ones(size(k)),:);    % entries are m + k */
  /*      I2=k(:,ones(size(m)))-m(ones(size(k)),:);    % entries are m - k */
  /*      b=zeros(size(k)); */
  /*      G=zeros(size(I1)); */
  /*   */
  /*      i = sqrt(-1); */
  /*      for s=1:2:length(F), */
  /*          if (do_weight((s+1)/2)),      % weight bands with 1/f^2 */
  /*              if F(s) == 0, F(s) = 1e-5; end     % avoid singularities */
  /*              m=(M(s+1)-M(s))/(F(s+1)-F(s)); */
  /*              b1=M(s)-m*F(s); */
  /*              snint1 = sineint(2*pi*k*F(s+1)) - sineint(2*pi*k*F(s)); */
  /*              %snint1 = (-1/2/i)*(expint(i*2*pi*k*F(s+1)) ... */
  /*              %    -expint(-i*2*pi*k*F(s+1)) -expint(i*2*pi*k*F(s)) ... */
  /*              %    +expint(-i*2*pi*k*F(s)) ); */
  /*              % csint1 = cosint(2*pi*k*F(s+1)) - cosint(2*pi*k*F(s)) ; */
  /*              csint1 = (-1/2)*(expint(i*2*pi*k*F(s+1))+expint(-i*2*pi*k*F(s+1))... */
  /*                              -expint(i*2*pi*k*F(s))  -expint(-i*2*pi*k*F(s)) ); */
  /*              b=b + ( m*snint1 ... */
  /*                  + b1*2*pi*k.*( -sinc(2*k*F(s+1)) + sinc(2*k*F(s)) + csint1 ))... */
  /*                  * abs(W((s+1)/2)^2); */
  /*              snint1 = sineint(2*pi*F(s+1)*(-I2)); */
  /*              snint2 = sineint(2*pi*F(s+1)*I1); */
  /*              snint3 = sineint(2*pi*F(s)*(-I2)); */
  /*              snint4 = sineint(2*pi*F(s)*I1); */
  /*              G = G - ( ( -1/2*( cos(2*pi*F(s+1)*(-I2))/F(s+1)  ... */
  /*                        - 2*snint1*pi.*I2 ... */
  /*                        - cos(2*pi*F(s+1)*I1)/F(s+1) ... */
  /*                        - 2*snint2*pi.*I1 )) ... */
  /*                    - ( -1/2*( cos(2*pi*F(s)*(-I2))/F(s)  ... */
  /*                        - 2*snint3*pi.*I2 ... */
  /*                        - cos(2*pi*F(s)*I1)/F(s) ... */
  /*                        - 2*snint4*pi.*I1) ) ) ... */
  /*                           * abs(W((s+1)/2)^2); */
  /*          else      % use usual weights */
  /*              m=(M(s+1)-M(s))/(F(s+1)-F(s)); */
  /*              b1=M(s)-m*F(s); */
  /*              b=b+(m/(4*pi*pi)*(sin(2*pi*k*F(s+1))-sin(2*pi*k*F(s)))./(k.*k))... */
  /*                           * abs(W((s+1)/2)^2) ; */
  /*              b = b + (((m*F(s)+b1)*cos(2*pi*k*F(s)) - ... */
  /*                   (m*F(s+1)+b1)*cos(2*pi*k*F(s+1)))./(2*pi*k)) ... */
  /*                           * abs(W((s+1)/2)^2) ; */
  /*              G = G + (.5*F(s+1)*(sinc(2*I1*F(s+1))-sinc(2*I2*F(s+1))) ... */
  /*                 - .5*F(s)*(sinc(2*I1*F(s))-sinc(2*I2*F(s)))) * abs(W((s+1)/2)^2); */
  /*          end; */
  /*      end */
  /*   */
  /*      a=G\b; */
  /*      if (rem(N,2)~=0), */
  /*          h=.5*[flipud(a); 0; -a].'; */
  /*      else */
  /*          h=.5*[flipud(a); -a].'; */
  /*      end */
  /*  end     */
  emxFree_real_T(&p);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Myfirls.c) */
