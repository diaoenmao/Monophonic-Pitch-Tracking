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
#include "median.h"
#include "mpower.h"
#include "Myhanning.h"
#include "rdivide.h"
#include "tm_trk.h"
#include "yaapt_emxutil.h"
#include "sinc.h"
#include "cos.h"
#include "indexShapeCheck.h"
#include "lusolve.h"
#include "qrsolve.h"
#include "warning.h"
#include "xgeqp3.h"
#include "error.h"
#include "any.h"
#include "diff.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = { 88, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo mb_emlrtRSI = { 90, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo nb_emlrtRSI = { 91, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo ob_emlrtRSI = { 99, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo pb_emlrtRSI = { 101, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo qb_emlrtRSI = { 110, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo rb_emlrtRSI = { 119, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo sb_emlrtRSI = { 120, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo tb_emlrtRSI = { 121, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo ub_emlrtRSI = { 122, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo vb_emlrtRSI = { 123, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo wb_emlrtRSI = { 124, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo xb_emlrtRSI = { 125, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo yb_emlrtRSI = { 126, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo ac_emlrtRSI = { 127, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo bc_emlrtRSI = { 135, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo cc_emlrtRSI = { 137, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo dc_emlrtRSI = { 139, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRSInfo oc_emlrtRSI = { 1, "mldivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

static emlrtRSInfo de_emlrtRSI = { 22, "flipud",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\flipud.m" };

static emlrtRTEInfo k_emlrtRTEI = { 1, 12, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo l_emlrtRTEI = { 99, 9, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo m_emlrtRTEI = { 104, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo n_emlrtRTEI = { 105, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo o_emlrtRTEI = { 106, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo p_emlrtRTEI = { 107, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo q_emlrtRTEI = { 110, 9, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo r_emlrtRTEI = { 114, 5, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo s_emlrtRTEI = { 130, 9, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtRTEInfo ef_emlrtRTEI = { 1, 1, "mldivide",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p" };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 137, 33, "a", "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 0 };

static emlrtDCInfo f_emlrtDCI = { 137, 33, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 137, 27, "a", "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 137, 12, "a", "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 137, 12, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtECInfo b_emlrtECI = { 2, 125, 13, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtDCInfo h_emlrtDCI = { 127, 28, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtECInfo c_emlrtECI = { 2, 125, 18, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo d_emlrtECI = { 2, 126, 27, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo e_emlrtECI = { 2, 125, 29, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo f_emlrtECI = { -1, 122, 13, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtDCInfo i_emlrtDCI = { 124, 28, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtECInfo g_emlrtECI = { -1, 122, 18, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo h_emlrtECI = { -1, 120, 13, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtDCInfo j_emlrtDCI = { 121, 28, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtECInfo i_emlrtECI = { -1, 120, 29, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtDCInfo k_emlrtDCI = { 119, 28, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 1 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 110, 11, "a", "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m", 0 };

static emlrtECInfo j_emlrtECI = { 2, 106, 8, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

static emlrtECInfo k_emlrtECI = { 2, 105, 8, "Myfirls",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m" };

/* Function Definitions */

/*
 * function h=Myfirls(N,F,M)
 */
void Myfirls(const emlrtStack *sp, real_T N, real_T F[6], emxArray_real_T *h)
{
  emxArray_real_T *a;
  emxArray_real_T *G;
  int32_T i6;
  real_T dv0[5];
  boolean_T bv0[5];
  int32_T ixstart;
  real_T tol;
  int32_T maxmn;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T exitg1;
  real_T L;
  emxArray_real_T *m;
  int32_T rankR;
  real_T apnd;
  boolean_T n_too_large;
  real_T ndbl;
  real_T cdiff;
  int32_T loop_ub;
  uint32_T uv1[2];
  emxArray_real_T *r3;
  uint32_T unnamed_idx_0;
  int32_T i7;
  emxArray_real_T *b_a;
  int32_T c_a[2];
  emxArray_real_T *b_m;
  int32_T c_m[2];
  emxArray_real_T *I1;
  emxArray_real_T *d_a;
  int32_T e_a[2];
  emxArray_real_T *d_m;
  int32_T e_m[2];
  emxArray_real_T *I2;
  real_T b0;
  emxArray_real_T *k;
  int32_T iv7[2];
  emxArray_real_T *b;
  int32_T s;
  emxArray_real_T *p;
  emxArray_real_T *r4;
  emxArray_real_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *tau;
  emxArray_real_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *r9;
  emxArray_real_T *r10;
  emxArray_real_T *r11;
  emxArray_real_T *r12;
  emxArray_real_T *y;
  emxArray_real_T *b_k;
  emxArray_real_T *r13;
  int32_T b_s;
  static const int8_T M[6] = { 0, 0, 1, 1, 0, 0 };

  real_T f_m;
  real_T b1;
  int32_T iv8[2];
  int32_T iv9[2];
  int32_T iv10[2];
  int32_T iv11[2];
  int32_T iv12[2];
  int32_T iv13[2];
  int32_T b_G[2];
  int32_T iv14[2];
  emxArray_int32_T *jpvt;
  emxArray_real_T *r14;
  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  char_T u[6];
  const mxArray *b_y;
  static const int32_T iv15[2] = { 1, 6 };

  const mxArray *m4;
  char_T cv1[14];
  int32_T iv16[2];
  int32_T i8;
  emxArray_real_T *f_a;
  int32_T iv17[2];
  emxArray_real_T *g_a;
  emxArray_real_T *b_tau;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &a, 1, &m_emlrtRTEI, true);
  emxInit_real_T(sp, &G, 2, &p_emlrtRTEI, true);

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
  /* 'Myfirls:48' W = ones(length(F)/2,1); */
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
  /* 'Myfirls:64' ftype = 0; */
  /* 'Myfirls:64' differ = 0; */
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
  /* 'Myfirls:76' N = N+1; */
  N++;

  /*  filter length */
  /* 'Myfirls:77' F=F(:)/2; */
  for (i6 = 0; i6 < 6; i6++) {
    F[i6] /= 2.0;
  }

  /* 'Myfirls:77' M=M(:); */
  /* 'Myfirls:77' W=sqrt(W(:)); */
  /*  make these guys columns */
  /* 'Myfirls:78' if (rem(length(F),2)~=0) */
  /* 'Myfirls:81' if (length(F)~=length(M)) */
  /* 'Myfirls:84' if (length(F)~=length(W)*2) */
  /* 'Myfirls:87' if any(diff(F)<0) */
  b_diff(F, dv0);
  for (ixstart = 0; ixstart < 5; ixstart++) {
    bv0[ixstart] = (dv0[ixstart] < 0.0);
  }

  if (c_any(bv0)) {
    st.site = &lb_emlrtRSI;
    b_error(&st);
  }

  /* 'Myfirls:90' if (max(F)>1)|(min(F)<0) */
  st.site = &mb_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &hb_emlrtRSI;
  ixstart = 1;
  tol = F[0];
  if (muDoubleScalarIsNaN(F[0])) {
    e_st.site = &ib_emlrtRSI;
    maxmn = 2;
    exitg2 = false;
    while ((!exitg2) && (maxmn < 7)) {
      ixstart = maxmn;
      if (!muDoubleScalarIsNaN(F[maxmn - 1])) {
        tol = F[maxmn - 1];
        exitg2 = true;
      } else {
        maxmn++;
      }
    }
  }

  if (ixstart < 6) {
    e_st.site = &jb_emlrtRSI;
    while (ixstart + 1 < 7) {
      if (F[ixstart] > tol) {
        tol = F[ixstart];
      }

      ixstart++;
    }
  }

  guard1 = false;
  if (tol > 1.0) {
    guard1 = true;
  } else {
    st.site = &mb_emlrtRSI;
    b_st.site = &kb_emlrtRSI;
    c_st.site = &gb_emlrtRSI;
    d_st.site = &hb_emlrtRSI;
    ixstart = 1;
    tol = F[0];
    if (muDoubleScalarIsNaN(F[0])) {
      e_st.site = &ib_emlrtRSI;
      maxmn = 2;
      exitg1 = false;
      while ((!exitg1) && (maxmn < 7)) {
        ixstart = maxmn;
        if (!muDoubleScalarIsNaN(F[maxmn - 1])) {
          tol = F[maxmn - 1];
          exitg1 = true;
        } else {
          maxmn++;
        }
      }
    }

    if (ixstart < 6) {
      e_st.site = &jb_emlrtRSI;
      while (ixstart + 1 < 7) {
        if (F[ixstart] < tol) {
          tol = F[ixstart];
        }

        ixstart++;
      }
    }

    if (tol < 0.0) {
      guard1 = true;
    }
  }

  if (guard1) {
    st.site = &nb_emlrtRSI;
    c_error(&st);
  }

  /* 'Myfirls:94' L=(N-1)/2; */
  L = (N - 1.0) / 2.0;

  /* 'Myfirls:96' if (ftype == 0) */
  /*  Type I and Type II linear phase FIR  */
  /*  basis vectors are cos(2*pi*m*f) (see m below) */
  /* 'Myfirls:98' if (rem(N,2)==0) */
  emxInit_real_T(sp, &m, 2, &l_emlrtRTEI, true);
  if (muDoubleScalarRem(N, 2.0) == 0.0) {
    /* 'Myfirls:99' m=(0:L)+.5; */
    st.site = &ob_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    if (muDoubleScalarIsNaN(L)) {
      rankR = 1;
      tol = rtNaN;
      apnd = L;
      n_too_large = false;
    } else if (L < 0.0) {
      rankR = 0;
      tol = 0.0;
      apnd = L;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(L)) {
      rankR = 1;
      tol = rtNaN;
      apnd = L;
      n_too_large = !(0.0 == L);
    } else {
      tol = 0.0;
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
        rankR = (int32_T)ndbl;
      } else {
        rankR = 0;
      }
    }

    d_st.site = &ab_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &ye_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i6 = m->size[0] * m->size[1];
    m->size[0] = 1;
    if (!(rankR > 0)) {
      emlrtNonNegativeCheckR2012b(rankR, &e_emlrtDCI, &c_st);
    }

    m->size[1] = rankR;
    emxEnsureCapacity(&c_st, (emxArray__common *)m, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    if (rankR > 0) {
      m->data[0] = tol;
      if (rankR > 1) {
        m->data[rankR - 1] = apnd;
        i6 = rankR - 1;
        ixstart = asr_s32(i6, 1U);
        d_st.site = &bb_emlrtRSI;
        for (maxmn = 1; maxmn < ixstart; maxmn++) {
          m->data[maxmn] = tol + (real_T)maxmn;
          m->data[(rankR - maxmn) - 1] = apnd - (real_T)maxmn;
        }

        if (ixstart << 1 == rankR - 1) {
          m->data[ixstart] = (tol + apnd) / 2.0;
        } else {
          m->data[ixstart] = tol + (real_T)ixstart;
          m->data[ixstart + 1] = apnd - (real_T)ixstart;
        }
      }
    }

    i6 = m->size[0] * m->size[1];
    m->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)m, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    rankR = m->size[0];
    ixstart = m->size[1];
    loop_ub = rankR * ixstart;
    for (i6 = 0; i6 < loop_ub; i6++) {
      m->data[i6] += 0.5;
    }

    /*  type II */
  } else {
    /* 'Myfirls:100' else */
    /* 'Myfirls:101' m=(0:L); */
    st.site = &pb_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    if (muDoubleScalarIsNaN(L)) {
      rankR = 1;
      tol = rtNaN;
      apnd = L;
      n_too_large = false;
    } else if (L < 0.0) {
      rankR = 0;
      tol = 0.0;
      apnd = L;
      n_too_large = false;
    } else if (muDoubleScalarIsInf(L)) {
      rankR = 1;
      tol = rtNaN;
      apnd = L;
      n_too_large = !(0.0 == L);
    } else {
      tol = 0.0;
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
        rankR = (int32_T)ndbl;
      } else {
        rankR = 0;
      }
    }

    d_st.site = &ab_emlrtRSI;
    if (!n_too_large) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &ye_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i6 = m->size[0] * m->size[1];
    m->size[0] = 1;
    if (!(rankR > 0)) {
      emlrtNonNegativeCheckR2012b(rankR, &e_emlrtDCI, &c_st);
    }

    m->size[1] = rankR;
    emxEnsureCapacity(&c_st, (emxArray__common *)m, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    if (rankR > 0) {
      m->data[0] = tol;
      if (rankR > 1) {
        m->data[rankR - 1] = apnd;
        i6 = rankR - 1;
        ixstart = asr_s32(i6, 1U);
        d_st.site = &bb_emlrtRSI;
        for (maxmn = 1; maxmn < ixstart; maxmn++) {
          m->data[maxmn] = tol + (real_T)maxmn;
          m->data[(rankR - maxmn) - 1] = apnd - (real_T)maxmn;
        }

        if (ixstart << 1 == rankR - 1) {
          m->data[ixstart] = (tol + apnd) / 2.0;
        } else {
          m->data[ixstart] = tol + (real_T)ixstart;
          m->data[ixstart + 1] = apnd - (real_T)ixstart;
        }
      }
    }

    /*  type I */
  }

  /*      k=m'; */
  /* 'Myfirls:104' a=m'; */
  i6 = a->size[0];
  a->size[0] = m->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)a, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = m->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    a->data[i6] = m->data[m->size[0] * i6];
  }

  /* 'Myfirls:105' I1=a(:,ones(size(m)))+m(ones(size(a)),:); */
  for (i6 = 0; i6 < 2; i6++) {
    uv1[i6] = (uint32_T)m->size[i6];
  }

  emxInit_real_T(sp, &r3, 2, &k_emlrtRTEI, true);
  unnamed_idx_0 = (uint32_T)a->size[0];
  loop_ub = a->size[0];
  i6 = r3->size[0] * r3->size[1];
  r3->size[0] = loop_ub;
  r3->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity(sp, (emxArray__common *)r3, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  ixstart = (int32_T)uv1[1];
  for (i6 = 0; i6 < ixstart; i6++) {
    for (i7 = 0; i7 < loop_ub; i7++) {
      r3->data[i7 + r3->size[0] * i6] = a->data[i7];
    }
  }

  emxInit_real_T(sp, &b_a, 2, &k_emlrtRTEI, true);
  loop_ub = a->size[0];
  i6 = b_a->size[0] * b_a->size[1];
  b_a->size[0] = loop_ub;
  b_a->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_a, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  ixstart = (int32_T)uv1[1];
  for (i6 = 0; i6 < ixstart; i6++) {
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_a->data[i7 + b_a->size[0] * i6] = a->data[i7];
    }
  }

  for (i6 = 0; i6 < 2; i6++) {
    c_a[i6] = b_a->size[i6];
  }

  emxFree_real_T(&b_a);
  emxInit_real_T(sp, &b_m, 2, &k_emlrtRTEI, true);
  loop_ub = m->size[1];
  i6 = b_m->size[0] * b_m->size[1];
  b_m->size[0] = (int32_T)unnamed_idx_0;
  b_m->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)b_m, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  for (i6 = 0; i6 < loop_ub; i6++) {
    ixstart = (int32_T)unnamed_idx_0;
    for (i7 = 0; i7 < ixstart; i7++) {
      b_m->data[i7 + b_m->size[0] * i6] = m->data[m->size[0] * i6];
    }
  }

  for (i6 = 0; i6 < 2; i6++) {
    c_m[i6] = b_m->size[i6];
  }

  emxFree_real_T(&b_m);
  emxInit_real_T(sp, &I1, 2, &n_emlrtRTEI, true);
  if ((c_a[0] != c_m[0]) || (c_a[1] != c_m[1])) {
    emlrtSizeEqCheckNDR2012b(&c_a[0], &c_m[0], &k_emlrtECI, sp);
  }

  i6 = I1->size[0] * I1->size[1];
  I1->size[0] = r3->size[0];
  I1->size[1] = r3->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)I1, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = r3->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    ixstart = r3->size[0];
    for (i7 = 0; i7 < ixstart; i7++) {
      I1->data[i7 + I1->size[0] * i6] = r3->data[i7 + r3->size[0] * i6] +
        m->data[m->size[0] * i6];
    }
  }

  /*  entries are m + k */
  /* 'Myfirls:106' I2=a(:,ones(size(m)))-m(ones(size(a)),:); */
  for (i6 = 0; i6 < 2; i6++) {
    uv1[i6] = (uint32_T)m->size[i6];
  }

  unnamed_idx_0 = (uint32_T)a->size[0];
  loop_ub = a->size[0];
  i6 = r3->size[0] * r3->size[1];
  r3->size[0] = loop_ub;
  r3->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity(sp, (emxArray__common *)r3, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  ixstart = (int32_T)uv1[1];
  for (i6 = 0; i6 < ixstart; i6++) {
    for (i7 = 0; i7 < loop_ub; i7++) {
      r3->data[i7 + r3->size[0] * i6] = a->data[i7];
    }
  }

  emxInit_real_T(sp, &d_a, 2, &k_emlrtRTEI, true);
  loop_ub = a->size[0];
  i6 = d_a->size[0] * d_a->size[1];
  d_a->size[0] = loop_ub;
  d_a->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_a, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  ixstart = (int32_T)uv1[1];
  for (i6 = 0; i6 < ixstart; i6++) {
    for (i7 = 0; i7 < loop_ub; i7++) {
      d_a->data[i7 + d_a->size[0] * i6] = a->data[i7];
    }
  }

  for (i6 = 0; i6 < 2; i6++) {
    e_a[i6] = d_a->size[i6];
  }

  emxFree_real_T(&d_a);
  emxInit_real_T(sp, &d_m, 2, &k_emlrtRTEI, true);
  loop_ub = m->size[1];
  i6 = d_m->size[0] * d_m->size[1];
  d_m->size[0] = (int32_T)unnamed_idx_0;
  d_m->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)d_m, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  for (i6 = 0; i6 < loop_ub; i6++) {
    ixstart = (int32_T)unnamed_idx_0;
    for (i7 = 0; i7 < ixstart; i7++) {
      d_m->data[i7 + d_m->size[0] * i6] = m->data[m->size[0] * i6];
    }
  }

  for (i6 = 0; i6 < 2; i6++) {
    e_m[i6] = d_m->size[i6];
  }

  emxFree_real_T(&d_m);
  emxInit_real_T(sp, &I2, 2, &o_emlrtRTEI, true);
  if ((e_a[0] != e_m[0]) || (e_a[1] != e_m[1])) {
    emlrtSizeEqCheckNDR2012b(&e_a[0], &e_m[0], &j_emlrtECI, sp);
  }

  i6 = I2->size[0] * I2->size[1];
  I2->size[0] = r3->size[0];
  I2->size[1] = r3->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)I2, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = r3->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    ixstart = r3->size[0];
    for (i7 = 0; i7 < ixstart; i7++) {
      I2->data[i7 + I2->size[0] * i6] = r3->data[i7 + r3->size[0] * i6] -
        m->data[m->size[0] * i6];
    }
  }

  /*  entries are m - k */
  /* 'Myfirls:107' G=zeros(size(I1)); */
  for (i6 = 0; i6 < 2; i6++) {
    uv1[i6] = (uint32_T)I1->size[i6];
  }

  i6 = G->size[0] * G->size[1];
  G->size[0] = (int32_T)uv1[0];
  G->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity(sp, (emxArray__common *)G, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = (int32_T)uv1[0] * (int32_T)uv1[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    G->data[i6] = 0.0;
  }

  /* 'Myfirls:108' b0=0; */
  b0 = 0.0;

  /*   first entry must be handled separately (where k(1)=0) */
  /* 'Myfirls:109' if (rem(N,2)~=0) */
  emxInit_real_T1(sp, &k, 1, &q_emlrtRTEI, true);
  if (muDoubleScalarRem(N, 2.0) != 0.0) {
    /* 'Myfirls:110' k=a(2:length(a)); */
    if (2 > a->size[0]) {
      i6 = 0;
      maxmn = 0;
    } else {
      i6 = 1;
      i7 = a->size[0];
      maxmn = a->size[0];
      if (!((maxmn >= 1) && (maxmn <= i7))) {
        emlrtDynamicBoundsCheckR2012b(maxmn, 1, i7, &ac_emlrtBCI, sp);
      }
    }

    iv7[0] = 1;
    iv7[1] = maxmn - i6;
    st.site = &qb_emlrtRSI;
    indexShapeCheck(&st, a->size[0], iv7);
    i7 = k->size[0];
    k->size[0] = maxmn - i6;
    emxEnsureCapacity(sp, (emxArray__common *)k, i7, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = maxmn - i6;
    for (i7 = 0; i7 < loop_ub; i7++) {
      k->data[i7] = a->data[i6 + i7];
    }
  } else {
    /* 'Myfirls:111' else */
    /* 'Myfirls:112' k=m'; */
    i6 = k->size[0];
    k->size[0] = m->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)k, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = m->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      k->data[i6] = m->data[m->size[0] * i6];
    }
  }

  emxFree_real_T(&m);
  emxInit_real_T1(sp, &b, 1, &r_emlrtRTEI, true);

  /* 'Myfirls:114' b=zeros(size(k)); */
  uv1[0] = (uint32_T)k->size[0];
  i6 = b->size[0];
  b->size[0] = (int32_T)uv1[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, i6, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = (int32_T)uv1[0];
  for (i6 = 0; i6 < loop_ub; i6++) {
    b->data[i6] = 0.0;
  }

  /* 'Myfirls:115' for s=1:2:length(F) */
  s = 0;
  emxInit_real_T1(sp, &p, 1, &s_emlrtRTEI, true);
  emxInit_real_T(sp, &r4, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r5, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r6, 2, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &tau, 1, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r7, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r8, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r9, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &r10, 2, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &r11, 1, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &r12, 1, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &y, 1, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_k, 1, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &r13, 1, &k_emlrtRTEI, true);
  while (s < 3) {
    b_s = 1 + (s << 1);

    /* 'Myfirls:116' m=(M(s+1)-M(s))/(F(s+1)-F(s)); */
    f_m = (real_T)(M[b_s] - M[b_s - 1]) / (F[b_s] - F[b_s - 1]);

    /*   slope */
    /* 'Myfirls:117' b1=M(s)-m*F(s); */
    b1 = (real_T)M[b_s - 1] - f_m * F[b_s - 1];

    /*   y-intercept */
    /* 'Myfirls:118' b0 = b0 + (b1*(F(s+1)-F(s)) + m/2*(F(s+1)*F(s+1)-F(s)*F(s)))... */
    /* 'Myfirls:119'                      * abs(W((s+1)/2)^2) ; */
    tol = ((real_T)b_s + 1.0) / 2.0;
    if (tol != muDoubleScalarFloor(tol)) {
      emlrtIntegerCheckR2012b(tol, &k_emlrtDCI, sp);
    }

    st.site = &rb_emlrtRSI;
    tol = mpower(1.0);
    b0 += (b1 * (F[b_s] - F[b_s - 1]) + f_m / 2.0 * (F[b_s] * F[b_s] - F[b_s - 1]
            * F[b_s - 1])) * muDoubleScalarAbs(tol);

    /* 'Myfirls:120' b = b+(m/(4*pi*pi)*(cos(2*pi*k*F(s+1))-cos(2*pi*k*F(s)))./(k.*k))... */
    /* 'Myfirls:121'                      * abs(W((s+1)/2)^2); */
    i6 = tau->size[0];
    tau->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tau, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      tau->data[i6] = 6.2831853071795862 * k->data[i6] * F[b_s];
    }

    st.site = &sb_emlrtRSI;
    b_cos(&st, tau);
    i6 = p->size[0];
    p->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      p->data[i6] = 6.2831853071795862 * k->data[i6] * F[b_s - 1];
    }

    st.site = &sb_emlrtRSI;
    b_cos(&st, p);
    i6 = tau->size[0];
    i7 = p->size[0];
    if (i6 != i7) {
      emlrtSizeEqCheck1DR2012b(i6, i7, &i_emlrtECI, sp);
    }

    ndbl = f_m / 39.478417604357432;
    tol = ((real_T)b_s + 1.0) / 2.0;
    if (tol != muDoubleScalarFloor(tol)) {
      emlrtIntegerCheckR2012b(tol, &j_emlrtDCI, sp);
    }

    st.site = &tb_emlrtRSI;
    tol = mpower(1.0);
    tol = muDoubleScalarAbs(tol);
    i6 = y->size[0];
    y->size[0] = tau->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)y, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = tau->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      y->data[i6] = ndbl * (tau->data[i6] - p->data[i6]);
    }

    i6 = b_k->size[0];
    b_k->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_k, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_k->data[i6] = k->data[i6] * k->data[i6];
    }

    st.site = &sb_emlrtRSI;
    b_rdivide(&st, y, b_k, r13);
    i6 = a->size[0];
    a->size[0] = r13->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = r13->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      a->data[i6] = r13->data[i6];
    }

    i6 = a->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)a, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = a->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      a->data[i6] *= tol;
    }

    i6 = b->size[0];
    i7 = a->size[0];
    if (i6 != i7) {
      emlrtSizeEqCheck1DR2012b(i6, i7, &h_emlrtECI, sp);
    }

    i6 = b->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = b->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      b->data[i6] += a->data[i6];
    }

    /* 'Myfirls:122' b = b + (F(s+1)*(m*F(s+1)+b1)*sinc(2*k*F(s+1)) ... */
    /* 'Myfirls:123'                    - F(s)*(m*F(s)+b1)*sinc(2*k*F(s))) ... */
    /* 'Myfirls:124'                      * abs(W((s+1)/2)^2); */
    tol = F[b_s] * (f_m * F[b_s] + b1);
    i6 = r12->size[0];
    r12->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r12, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r12->data[i6] = 2.0 * k->data[i6] * F[b_s];
    }

    st.site = &ub_emlrtRSI;
    sinc(&st, r12, tau);
    i6 = tau->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tau, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = tau->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      tau->data[i6] *= tol;
    }

    tol = F[b_s - 1] * (f_m * F[b_s - 1] + b1);
    i6 = r11->size[0];
    r11->size[0] = k->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)r11, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = k->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r11->data[i6] = 2.0 * k->data[i6] * F[b_s - 1];
    }

    st.site = &vb_emlrtRSI;
    sinc(&st, r11, p);
    i6 = p->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = p->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      p->data[i6] *= tol;
    }

    i6 = tau->size[0];
    i7 = p->size[0];
    if (i6 != i7) {
      emlrtSizeEqCheck1DR2012b(i6, i7, &g_emlrtECI, sp);
    }

    tol = ((real_T)b_s + 1.0) / 2.0;
    if (tol != muDoubleScalarFloor(tol)) {
      emlrtIntegerCheckR2012b(tol, &i_emlrtDCI, sp);
    }

    st.site = &wb_emlrtRSI;
    tol = mpower(1.0);
    ndbl = muDoubleScalarAbs(tol);
    i6 = tau->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tau, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = tau->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      tau->data[i6] = (tau->data[i6] - p->data[i6]) * ndbl;
    }

    i6 = b->size[0];
    i7 = tau->size[0];
    if (i6 != i7) {
      emlrtSizeEqCheck1DR2012b(i6, i7, &f_emlrtECI, sp);
    }

    i6 = b->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = b->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      b->data[i6] += tau->data[i6];
    }

    /* 'Myfirls:125' G = G + (.5*F(s+1)*(sinc(2*I1*F(s+1))+sinc(2*I2*F(s+1))) ... */
    /* 'Myfirls:126'                - .5*F(s)*(sinc(2*I1*F(s))+sinc(2*I2*F(s))) ) ... */
    /* 'Myfirls:127'                      * abs(W((s+1)/2)^2); */
    i6 = r10->size[0] * r10->size[1];
    r10->size[0] = I1->size[0];
    r10->size[1] = I1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r10, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = I1->size[0] * I1->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r10->data[i6] = 2.0 * I1->data[i6] * F[b_s];
    }

    st.site = &xb_emlrtRSI;
    b_sinc(&st, r10, r3);
    i6 = r9->size[0] * r9->size[1];
    r9->size[0] = I2->size[0];
    r9->size[1] = I2->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r9, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = I2->size[0] * I2->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r9->data[i6] = 2.0 * I2->data[i6] * F[b_s];
    }

    st.site = &xb_emlrtRSI;
    b_sinc(&st, r9, r4);
    for (i6 = 0; i6 < 2; i6++) {
      iv8[i6] = r3->size[i6];
    }

    for (i6 = 0; i6 < 2; i6++) {
      iv9[i6] = r4->size[i6];
    }

    if ((iv8[0] != iv9[0]) || (iv8[1] != iv9[1])) {
      emlrtSizeEqCheckNDR2012b(&iv8[0], &iv9[0], &e_emlrtECI, sp);
    }

    i6 = r8->size[0] * r8->size[1];
    r8->size[0] = I1->size[0];
    r8->size[1] = I1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r8, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = I1->size[0] * I1->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r8->data[i6] = 2.0 * I1->data[i6] * F[b_s - 1];
    }

    st.site = &yb_emlrtRSI;
    b_sinc(&st, r8, r5);
    i6 = r7->size[0] * r7->size[1];
    r7->size[0] = I2->size[0];
    r7->size[1] = I2->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r7, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = I2->size[0] * I2->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r7->data[i6] = 2.0 * I2->data[i6] * F[b_s - 1];
    }

    st.site = &yb_emlrtRSI;
    b_sinc(&st, r7, r6);
    for (i6 = 0; i6 < 2; i6++) {
      iv10[i6] = r5->size[i6];
    }

    for (i6 = 0; i6 < 2; i6++) {
      iv11[i6] = r6->size[i6];
    }

    if ((iv10[0] != iv11[0]) || (iv10[1] != iv11[1])) {
      emlrtSizeEqCheckNDR2012b(&iv10[0], &iv11[0], &d_emlrtECI, sp);
    }

    tol = 0.5 * F[b_s];
    i6 = r3->size[0] * r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    i6 = r3->size[0];
    i7 = r3->size[1];
    loop_ub = i6 * i7;
    for (i6 = 0; i6 < loop_ub; i6++) {
      r3->data[i6] = tol * (r3->data[i6] + r4->data[i6]);
    }

    tol = 0.5 * F[b_s - 1];
    i6 = r5->size[0] * r5->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r5, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    i6 = r5->size[0];
    i7 = r5->size[1];
    loop_ub = i6 * i7;
    for (i6 = 0; i6 < loop_ub; i6++) {
      r5->data[i6] = tol * (r5->data[i6] + r6->data[i6]);
    }

    for (i6 = 0; i6 < 2; i6++) {
      iv12[i6] = r3->size[i6];
    }

    for (i6 = 0; i6 < 2; i6++) {
      iv13[i6] = r5->size[i6];
    }

    if ((iv12[0] != iv13[0]) || (iv12[1] != iv13[1])) {
      emlrtSizeEqCheckNDR2012b(&iv12[0], &iv13[0], &c_emlrtECI, sp);
    }

    tol = ((real_T)b_s + 1.0) / 2.0;
    if (tol != muDoubleScalarFloor(tol)) {
      emlrtIntegerCheckR2012b(tol, &h_emlrtDCI, sp);
    }

    st.site = &ac_emlrtRSI;
    tol = mpower(1.0);
    ndbl = muDoubleScalarAbs(tol);
    i6 = r3->size[0] * r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    i6 = r3->size[0];
    i7 = r3->size[1];
    loop_ub = i6 * i7;
    for (i6 = 0; i6 < loop_ub; i6++) {
      r3->data[i6] = (r3->data[i6] - r5->data[i6]) * ndbl;
    }

    for (i6 = 0; i6 < 2; i6++) {
      b_G[i6] = G->size[i6];
    }

    for (i6 = 0; i6 < 2; i6++) {
      iv14[i6] = r3->size[i6];
    }

    if ((b_G[0] != iv14[0]) || (b_G[1] != iv14[1])) {
      emlrtSizeEqCheckNDR2012b(&b_G[0], &iv14[0], &b_emlrtECI, sp);
    }

    i6 = G->size[0] * G->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)G, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    ixstart = G->size[0];
    maxmn = G->size[1];
    loop_ub = ixstart * maxmn;
    for (i6 = 0; i6 < loop_ub; i6++) {
      G->data[i6] += r3->data[i6];
    }

    s++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r13);
  emxFree_real_T(&b_k);
  emxFree_real_T(&y);
  emxFree_real_T(&r12);
  emxFree_real_T(&r11);
  emxFree_real_T(&r10);
  emxFree_real_T(&r9);
  emxFree_real_T(&r8);
  emxFree_real_T(&r7);
  emxFree_real_T(&r6);
  emxFree_real_T(&r5);
  emxFree_real_T(&r4);
  emxFree_real_T(&r3);
  emxFree_real_T(&k);
  emxFree_real_T(&I2);
  emxFree_real_T(&I1);

  /* 'Myfirls:129' if (rem(N,2)~=0) */
  if (muDoubleScalarRem(N, 2.0) != 0.0) {
    /* 'Myfirls:130' p=[b0; b]; */
    i6 = p->size[0];
    p->size[0] = 1 + b->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    p->data[0] = b0;
    loop_ub = b->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      p->data[i6 + 1] = b->data[i6];
    }
  } else {
    /* 'Myfirls:131' else */
    /* 'Myfirls:132' p=b; */
    i6 = p->size[0];
    p->size[0] = b->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)p, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = b->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      p->data[i6] = b->data[i6];
    }
  }

  emxFree_real_T(&b);

  /* 'Myfirls:135' a=G\p; */
  st.site = &bc_emlrtRSI;
  if (p->size[0] == G->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ef_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  emxInit_int32_T(&st, &jpvt, 2, &k_emlrtRTEI, true);
  emxInit_real_T1(&st, &r14, 1, &k_emlrtRTEI, true);
  if ((G->size[0] == 0) || (G->size[1] == 0) || (p->size[0] == 0)) {
    uv1[0] = (uint32_T)G->size[1];
    i6 = a->size[0];
    a->size[0] = (int32_T)uv1[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = (int32_T)uv1[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      a->data[i6] = 0.0;
    }
  } else if (G->size[0] == G->size[1]) {
    i6 = a->size[0];
    a->size[0] = p->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)a, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = p->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      a->data[i6] = p->data[i6];
    }

    b_st.site = &oc_emlrtRSI;
    lusolve(&b_st, G, a);
  } else {
    b_st.site = &oc_emlrtRSI;
    c_st.site = &md_emlrtRSI;
    xgeqp3(&c_st, G, tau, jpvt);
    c_st.site = &nd_emlrtRSI;
    rankR = 0;
    tol = 0.0;
    if (G->size[0] < G->size[1]) {
      ixstart = G->size[0];
      maxmn = G->size[1];
    } else {
      ixstart = G->size[1];
      maxmn = G->size[0];
    }

    if (ixstart > 0) {
      tol = (real_T)maxmn * muDoubleScalarAbs(G->data[0]) *
        2.2204460492503131E-16;
      while ((rankR < ixstart) && (muDoubleScalarAbs(G->data[rankR + G->size[0] *
               rankR]) >= tol)) {
        rankR++;
      }
    }

    if ((rankR < ixstart) && (!emlrtSetWarningFlag(&c_st))) {
      d_st.site = &ud_emlrtRSI;
      for (i6 = 0; i6 < 6; i6++) {
        u[i6] = rfmt[i6];
      }

      b_y = NULL;
      m4 = emlrtCreateCharArray(2, iv15);
      emlrtInitCharArrayR2013a(&d_st, 6, m4, &u[0]);
      emlrtAssign(&b_y, m4);
      e_st.site = &ko_emlrtRSI;
      emlrt_marshallIn(&e_st, b_sprintf(&e_st, b_y, emlrt_marshallOut(tol),
        &e_emlrtMCI), "sprintf", cv1);
      d_st.site = &vd_emlrtRSI;
      b_warning(&d_st, rankR, cv1);
    }

    c_st.site = &od_emlrtRSI;
    LSQFromQR(&c_st, G, tau, jpvt, p, rankR, r14);
    i6 = a->size[0];
    a->size[0] = r14->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)a, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = r14->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      a->data[i6] = r14->data[i6];
    }
  }

  emxFree_real_T(&r14);
  emxFree_int32_T(&jpvt);

  /* 'Myfirls:136' if (rem(N,2)~=0) */
  if (muDoubleScalarRem(N, 2.0) != 0.0) {
    /* 'Myfirls:137' h=[a(L+1:-1:2)/2; a(1); a(2:L+1)/2].'; */
    if (2.0 > L + 1.0) {
      i7 = 1;
      i6 = 1;
      maxmn = 0;
    } else {
      i6 = a->size[0];
      if (L + 1.0 != (int32_T)muDoubleScalarFloor(L + 1.0)) {
        emlrtIntegerCheckR2012b(L + 1.0, &g_emlrtDCI, sp);
      }

      i7 = (int32_T)(L + 1.0);
      if (!((i7 >= 1) && (i7 <= i6))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &yb_emlrtBCI, sp);
      }

      i6 = -1;
      maxmn = a->size[0];
      if (!(2 <= maxmn)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, maxmn, &yb_emlrtBCI, sp);
      }

      maxmn = 2;
    }

    iv16[0] = 1;
    iv16[1] = div_s32_floor(sp, maxmn - i7, i6) + 1;
    st.site = &cc_emlrtRSI;
    indexShapeCheck(&st, a->size[0], iv16);
    if (2.0 > L + 1.0) {
      rankR = 0;
      i8 = 0;
    } else {
      rankR = a->size[0];
      if (!(2 <= rankR)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, rankR, &wb_emlrtBCI, sp);
      }

      rankR = 1;
      ixstart = a->size[0];
      if (L + 1.0 != (int32_T)muDoubleScalarFloor(L + 1.0)) {
        emlrtIntegerCheckR2012b(L + 1.0, &f_emlrtDCI, sp);
      }

      i8 = (int32_T)(L + 1.0);
      if (!((i8 >= 1) && (i8 <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(i8, 1, ixstart, &wb_emlrtBCI, sp);
      }
    }

    emxInit_real_T1(sp, &f_a, 1, &k_emlrtRTEI, true);
    iv17[0] = 1;
    iv17[1] = i8 - rankR;
    st.site = &cc_emlrtRSI;
    indexShapeCheck(&st, a->size[0], iv17);
    ixstart = f_a->size[0];
    f_a->size[0] = div_s32_floor(sp, maxmn - i7, i6) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)f_a, ixstart, (int32_T)sizeof
                      (real_T), &k_emlrtRTEI);
    loop_ub = div_s32_floor(sp, maxmn - i7, i6);
    for (maxmn = 0; maxmn <= loop_ub; maxmn++) {
      f_a->data[maxmn] = a->data[(i7 + i6 * maxmn) - 1];
    }

    emxInit_real_T1(sp, &g_a, 1, &k_emlrtRTEI, true);
    rdivide(sp, f_a, 2.0, tau);
    i6 = g_a->size[0];
    g_a->size[0] = i8 - rankR;
    emxEnsureCapacity(sp, (emxArray__common *)g_a, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = i8 - rankR;
    emxFree_real_T(&f_a);
    for (i6 = 0; i6 < loop_ub; i6++) {
      g_a->data[i6] = a->data[rankR + i6];
    }

    rdivide(sp, g_a, 2.0, p);
    i6 = a->size[0];
    if (!(1 <= i6)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, &xb_emlrtBCI, sp);
    }

    i6 = h->size[0] * h->size[1];
    h->size[0] = 1;
    h->size[1] = (tau->size[0] + p->size[0]) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)h, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = tau->size[0];
    emxFree_real_T(&g_a);
    for (i6 = 0; i6 < loop_ub; i6++) {
      h->data[h->size[0] * i6] = tau->data[i6];
    }

    h->data[h->size[0] * tau->size[0]] = a->data[0];
    loop_ub = p->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      h->data[h->size[0] * ((i6 + tau->size[0]) + 1)] = p->data[i6];
    }
  } else {
    /* 'Myfirls:138' else */
    /* 'Myfirls:139' h=.5*[flipud(a); a].'; */
    st.site = &dc_emlrtRSI;
    i6 = tau->size[0];
    tau->size[0] = a->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)tau, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = a->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      tau->data[i6] = a->data[i6];
    }

    rankR = a->size[0];
    maxmn = asr_s32(a->size[0], 1U);
    b_st.site = &de_emlrtRSI;
    for (ixstart = 1; ixstart <= maxmn; ixstart++) {
      tol = tau->data[ixstart - 1];
      tau->data[ixstart - 1] = tau->data[rankR - ixstart];
      tau->data[rankR - ixstart] = tol;
    }

    emxInit_real_T(&st, &b_tau, 2, &k_emlrtRTEI, true);
    i6 = b_tau->size[0] * b_tau->size[1];
    b_tau->size[0] = 1;
    b_tau->size[1] = tau->size[0] + a->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_tau, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = tau->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_tau->data[b_tau->size[0] * i6] = tau->data[i6];
    }

    loop_ub = a->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_tau->data[b_tau->size[0] * (i6 + tau->size[0])] = a->data[i6];
    }

    i6 = h->size[0] * h->size[1];
    h->size[0] = 1;
    h->size[1] = b_tau->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)h, i6, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    loop_ub = b_tau->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      h->data[h->size[0] * i6] = 0.5 * b_tau->data[b_tau->size[0] * i6];
    }

    emxFree_real_T(&b_tau);
  }

  emxFree_real_T(&tau);
  emxFree_real_T(&p);

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
  emxFree_real_T(&G);
  emxFree_real_T(&a);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Myfirls.c) */
