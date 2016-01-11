/*
 * tm_trk.c
 *
 * Code generation for function 'tm_trk'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "tm_trk.h"
#include "yaapt_emxutil.h"
#include "error1.h"
#include "cmp_rate.h"
#include "crs_corr.h"
#include "fix.h"
#include "warning.h"
#include "qrsolve.h"
#include "peaks.h"
#include "xgeqp3.h"
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo jb_emlrtRSI = { 16, "min",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" };

static emlrtRSInfo nc_emlrtRSI = { 19, "scalexpAllocNoCheck",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m"
};

static emlrtRSInfo fj_emlrtRSI = { 55, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo gj_emlrtRSI = { 56, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo hj_emlrtRSI = { 74, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo ij_emlrtRSI = { 78, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo jj_emlrtRSI = { 87, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo kj_emlrtRSI = { 95, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRSInfo lj_emlrtRSI = { 59, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo mj_emlrtRSI = { 182, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo nj_emlrtRSI = { 208, "minOrMax",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo ck_emlrtRSI = { 1, "mrdivide",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p" };

static emlrtRSInfo dk_emlrtRSI = { 88, "xgetrf",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

static emlrtRSInfo ek_emlrtRSI = { 92, "xgetrf",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m" };

static emlrtRSInfo hk_emlrtRSI = { 28, "qrsolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo ik_emlrtRSI = { 32, "qrsolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo jk_emlrtRSI = { 39, "qrsolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo sk_emlrtRSI = { 121, "qrsolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtRSInfo tk_emlrtRSI = { 120, "qrsolve",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" };

static emlrtMCInfo g_emlrtMCI = { 52, 19, "flt2str",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" };

static emlrtRTEInfo nc_emlrtRTEI = { 1, 27, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo oc_emlrtRTEI = { 46, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo pc_emlrtRTEI = { 47, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo qc_emlrtRTEI = { 49, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo rc_emlrtRTEI = { 50, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo sc_emlrtRTEI = { 88, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtRTEInfo tc_emlrtRTEI = { 93, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo gb_emlrtECI = { -1, 98, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo hb_emlrtECI = { 2, 98, 18, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 95, 10,
  "(1 - (diff(j)/freq_thresh)) * match1(j)", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo ib_emlrtECI = { -1, 95, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo jb_emlrtECI = { -1, 78, 17, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 78, 25, "Merit", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 95, 52, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 90, 10,
  "match1(j) = diff(j) < freq_thresh", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo kb_emlrtECI = { -1, 90, 10, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 95, 28, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo lb_emlrtECI = { 2, 87, 21, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo mb_emlrtECI = { -1, 78, 6, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 78, 14, "Pitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 72, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 71, 32, "SRange", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo nb_emlrtECI = { -1, 56, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtECInfo ob_emlrtECI = { -1, 55, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 66, 14, "Data", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtDCInfo ib_emlrtDCI = { 66, 14, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtRTEInfo cf_emlrtRTEI = { 63, 1, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtDCInfo jb_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 1 };

static emlrtDCInfo kb_emlrtDCI = { 59, 25, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 4 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 53, 5, "SPitch(i)+2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo pb_emlrtECI = { -1, 53, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 52, 5, "SPitch(i)-2*pStd", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtECInfo qb_emlrtECI = { -1, 52, 5, "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m" };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 95, 10, "match", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 90, 22, "diff", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 90, 10, "match1", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 52, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 52, 5, "temp_max", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 53, 19, "SPitch", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 53, 5, "temp_min", "tm_trk",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m", 0 };

static emlrtRSInfo km_emlrtRSI = { 52, "flt2str",
  "F:\\Matlab2015b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m17;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m17, 2, pArrays, "sprintf", true,
    location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, ret, 14);
  emlrtDestroyArray(&src);
}

/*
 * function [Pitch, Merit] = tm_trk(Data, Fs, SPitch, pStd, pAvg, Prm)
 */
void tm_trk(const emlrtStack *sp, const emxArray_real_T *Data, real_T Fs, const
            emxArray_real_T *SPitch, const emxArray_real_T *pStd,
            emxArray_real_T *Pitch, emxArray_real_T *Merit)
{
  emxArray_real_T *freq_thresh;
  emxArray_real_T *temp_max;
  real_T nframesize;
  real_T nframejump;
  real_T numframes;
  int32_T i30;
  int32_T minmn;
  emxArray_real_T *SRange;
  emxArray_real_T *temp_min;
  int32_T i;
  emxArray_real_T *tau;
  emxArray_int32_T *r19;
  uint32_T uv5[2];
  emxArray_real_T *match1;
  emxArray_real_T *r20;
  boolean_T overflow;
  int32_T iv26[2];
  emxArray_real_T *match;
  int32_T iv27[2];
  real_T d0;
  int32_T n;
  emxArray_real_T *b_Data;
  emxArray_real_T *r21;
  real_T firstp;
  int32_T rankR;
  int32_T maxmn;
  real_T tol;
  static const int32_T iv28[1] = { 3 };

  emxArray_real_T *Y;
  emxArray_int32_T *jpvt;
  emxArray_real_T *b_Pitch;
  emxArray_real_T *c_Pitch;
  emxArray_real_T *b_SPitch;
  int32_T d_Pitch[2];
  int32_T c_SPitch[2];
  int32_T j;
  ptrdiff_t ipiv_t;
  ptrdiff_t info_t;
  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  char_T u[6];
  const mxArray *y;
  static const int32_T iv29[2] = { 1, 6 };

  const mxArray *m7;
  char_T cv6[14];
  int32_T iv30[2];
  int32_T b_match[2];
  int32_T iv31[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &freq_thresh, 1, &oc_emlrtRTEI, true);
  emxInit_real_T(sp, &temp_max, 2, &qc_emlrtRTEI, true);

  /* TM_TRK  Temporal pitch tracking for YAAPT pitch tracking  */
  /*  */
  /*    [Pitch, Merit] = tm_trk(Data, Fs, SPitch, pStd, pAvg, Prm) */
  /*    computes estimates of pitch  using nonlinearly processed */
  /*    speech (typically square or absolute value) and frequency domain processing */
  /*    Search for frequencies which have energy at multiplies of that frequency */
  /*  */
  /* INPUTS: */
  /*    Data:   Nonlinearly processed signal */
  /*    Fs:    The sampling frequency. */
  /*    SPitch:The spectral F0 track, with the unvoiced */
  /*    pStd:  The STD of voiced spectral F0 track . */
  /*    pAvg:  The mean of voiced spectral F0 track . */
  /*    Prm:   Array of parameters used to control performance */
  /*  */
  /* OUTPUTS: */
  /*    Pitch: Computed pitch candidates array */
  /*    Merit: The merit of array of pitch candidates */
  /*    Creation :   Jun 20, 2006, July 27, 2007 */
  /*    Programers:  Hongbing Hu */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*      This file is a part of the YAAPT program, designed for a fundamental  */
  /*    frequency tracking algorithm that is extermely robust for both high quality  */
  /*    and telephone speech.   */
  /*      The YAAPT program was created by the Speech Communication Laboratory of */
  /*    the state university of New York at Binghamton. The program is available  */
  /*    at http://www.ws.binghamton.edu/zahorian as free software. Further  */
  /*    information about the program could be found at "A spectral/temporal  */
  /*    method for robust fundamental frequency tracking," J.Acosut.Soc.Am. 123(6),  */
  /*    June 2008. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* -- PARAMETERS ---------------------------------------------------------------- */
  /* 'tm_trk:37' nframesize = fix(Prm.frame_length*Fs/1000); */
  nframesize = 25.0 * Fs / 1000.0;
  b_fix(&nframesize);

  /* 'tm_trk:38' nframejump = fix(Prm.frame_space*Fs/1000); */
  nframejump = 10.0 * Fs / 1000.0;
  b_fix(&nframejump);

  /* 'tm_trk:39' noverlap   = nframesize-nframejump; */
  /*  overlap width in sample  */
  /* 'tm_trk:40' numframes  = fix((length(Data)-noverlap)/nframejump); */
  numframes = ((real_T)Data->size[1] - (nframesize - nframejump)) / nframejump;
  b_fix(&numframes);

  /* 'tm_trk:42' merit_boost = Prm.merit_boost; */
  /*  The maximum number of pitch candidates */
  /* 'tm_trk:44' maxcands   = Prm.nccf_maxcands; */
  /* freq_thresh = pAvg;  % seems too large */
  /* 'tm_trk:46' freq_thresh = 5 * pStd; */
  i30 = freq_thresh->size[0];
  freq_thresh->size[0] = pStd->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)freq_thresh, i30, (int32_T)sizeof
                    (real_T), &nc_emlrtRTEI);
  minmn = pStd->size[0];
  for (i30 = 0; i30 < minmn; i30++) {
    freq_thresh->data[i30] = 5.0 * pStd->data[i30];
  }

  emxInit_real_T(sp, &SRange, 2, &pc_emlrtRTEI, true);

  /* 'tm_trk:47' SRange = zeros(2,length(SPitch)); */
  i30 = SRange->size[0] * SRange->size[1];
  SRange->size[0] = 2;
  SRange->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)SRange, i30, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  minmn = SPitch->size[1] << 1;
  for (i30 = 0; i30 < minmn; i30++) {
    SRange->data[i30] = 0.0;
  }

  /*  Determine the search range according spectral pitch track */
  /* 'tm_trk:49' temp_max = zeros(1,length(SPitch)); */
  i30 = temp_max->size[0] * temp_max->size[1];
  temp_max->size[0] = 1;
  temp_max->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_max, i30, (int32_T)sizeof
                    (real_T), &nc_emlrtRTEI);
  minmn = SPitch->size[1];
  for (i30 = 0; i30 < minmn; i30++) {
    temp_max->data[i30] = 0.0;
  }

  emxInit_real_T(sp, &temp_min, 2, &rc_emlrtRTEI, true);

  /* 'tm_trk:50' temp_min = zeros(1,length(SPitch)); */
  i30 = temp_min->size[0] * temp_min->size[1];
  temp_min->size[0] = 1;
  temp_min->size[1] = SPitch->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)temp_min, i30, (int32_T)sizeof
                    (real_T), &nc_emlrtRTEI);
  minmn = SPitch->size[1];
  for (i30 = 0; i30 < minmn; i30++) {
    temp_min->data[i30] = 0.0;
  }

  /* 'tm_trk:51' for i = 1:length(SPitch) */
  i = 1;
  emxInit_real_T1(sp, &tau, 1, &nc_emlrtRTEI, true);
  while (i - 1 <= SPitch->size[1] - 1) {
    /* 'tm_trk:52' temp_max(i) = SPitch(i)-2*pStd; */
    i30 = tau->size[0];
    tau->size[0] = pStd->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tau, i30, (int32_T)sizeof(real_T),
                      &nc_emlrtRTEI);
    minmn = pStd->size[0];
    for (i30 = 0; i30 < minmn; i30++) {
      tau->data[i30] = 2.0 * pStd->data[i30];
    }

    i30 = tau->size[0];
    if (1 != i30) {
      emlrtSizeEqCheck1DR2012b(1, i30, &qb_emlrtECI, sp);
    }

    i30 = tau->size[0];
    if (!(1 <= i30)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i30, &te_emlrtBCI, sp);
    }

    i30 = SPitch->size[1];
    if (!((i >= 1) && (i <= i30))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i30, &xe_emlrtBCI, sp);
    }

    i30 = temp_max->size[1];
    if (!((i >= 1) && (i <= i30))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i30, &ye_emlrtBCI, sp);
    }

    temp_max->data[i - 1] = SPitch->data[i - 1] - tau->data[0];

    /* 'tm_trk:53' temp_min(i) = SPitch(i)+2*pStd; */
    i30 = tau->size[0];
    tau->size[0] = pStd->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)tau, i30, (int32_T)sizeof(real_T),
                      &nc_emlrtRTEI);
    minmn = pStd->size[0];
    for (i30 = 0; i30 < minmn; i30++) {
      tau->data[i30] = 2.0 * pStd->data[i30];
    }

    i30 = tau->size[0];
    if (1 != i30) {
      emlrtSizeEqCheck1DR2012b(1, i30, &pb_emlrtECI, sp);
    }

    i30 = tau->size[0];
    if (!(1 <= i30)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i30, &se_emlrtBCI, sp);
    }

    i30 = SPitch->size[1];
    if (!((i >= 1) && (i <= i30))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i30, &af_emlrtBCI, sp);
    }

    i30 = temp_min->size[1];
    if (!((i >= 1) && (i <= i30))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i30, &bf_emlrtBCI, sp);
    }

    temp_min->data[i - 1] = SPitch->data[i - 1] + tau->data[0];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_int32_T(sp, &r19, 1, &nc_emlrtRTEI, true);

  /* 'tm_trk:55' SRange(1,:)  = max(temp_max, Prm.f0_min); */
  minmn = SPitch->size[1];
  i30 = r19->size[0];
  r19->size[0] = minmn;
  emxEnsureCapacity(sp, (emxArray__common *)r19, i30, (int32_T)sizeof(int32_T),
                    &nc_emlrtRTEI);
  for (i30 = 0; i30 < minmn; i30++) {
    r19->data[i30] = i30;
  }

  st.site = &fj_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  d_st.site = &lj_emlrtRSI;
  e_st.site = &mj_emlrtRSI;
  f_st.site = &mc_emlrtRSI;
  g_st.site = &nc_emlrtRSI;
  for (i30 = 0; i30 < 2; i30++) {
    uv5[i30] = (uint32_T)temp_max->size[i30];
  }

  emxInit_real_T(&g_st, &match1, 2, &sc_emlrtRTEI, true);
  emxInit_real_T(&g_st, &r20, 2, &nc_emlrtRTEI, true);
  i30 = match1->size[0] * match1->size[1];
  match1->size[0] = 1;
  match1->size[1] = (int32_T)uv5[1];
  emxEnsureCapacity(&g_st, (emxArray__common *)match1, i30, (int32_T)sizeof
                    (real_T), &nc_emlrtRTEI);
  i30 = r20->size[0] * r20->size[1];
  r20->size[0] = 1;
  r20->size[1] = (int32_T)uv5[1];
  emxEnsureCapacity(&f_st, (emxArray__common *)r20, i30, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  if (dimagree(r20, temp_max)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &qd_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &nj_emlrtRSI;
  if (1 > match1->size[1]) {
    overflow = false;
  } else {
    overflow = (match1->size[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&f_st, true);
  }

  for (minmn = 0; minmn + 1 <= (int32_T)uv5[1]; minmn++) {
    r20->data[minmn] = muDoubleScalarMax(temp_max->data[minmn], 60.0);
  }

  iv26[0] = 1;
  iv26[1] = r19->size[0];
  emlrtSubAssignSizeCheckR2012b(iv26, 2, *(int32_T (*)[2])r20->size, 2,
    &ob_emlrtECI, sp);
  minmn = r20->size[1];
  for (i30 = 0; i30 < minmn; i30++) {
    SRange->data[SRange->size[0] * r19->data[i30]] = r20->data[r20->size[0] *
      i30];
  }

  /* 'tm_trk:56' SRange(2,:)  = min(temp_min, Prm.f0_max); */
  minmn = SRange->size[1];
  i30 = r19->size[0];
  r19->size[0] = minmn;
  emxEnsureCapacity(sp, (emxArray__common *)r19, i30, (int32_T)sizeof(int32_T),
                    &nc_emlrtRTEI);
  for (i30 = 0; i30 < minmn; i30++) {
    r19->data[i30] = i30;
  }

  st.site = &gj_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  d_st.site = &lj_emlrtRSI;
  e_st.site = &mj_emlrtRSI;
  f_st.site = &mc_emlrtRSI;
  g_st.site = &nc_emlrtRSI;
  for (i30 = 0; i30 < 2; i30++) {
    uv5[i30] = (uint32_T)temp_min->size[i30];
  }

  emxInit_real_T(&g_st, &match, 2, &tc_emlrtRTEI, true);
  i30 = match->size[0] * match->size[1];
  match->size[0] = 1;
  match->size[1] = (int32_T)uv5[1];
  emxEnsureCapacity(&g_st, (emxArray__common *)match, i30, (int32_T)sizeof
                    (real_T), &nc_emlrtRTEI);
  i30 = r20->size[0] * r20->size[1];
  r20->size[0] = 1;
  r20->size[1] = (int32_T)uv5[1];
  emxEnsureCapacity(&f_st, (emxArray__common *)r20, i30, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  if (dimagree(r20, temp_min)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &qd_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  e_st.site = &nj_emlrtRSI;
  if (1 > match->size[1]) {
    overflow = false;
  } else {
    overflow = (match->size[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&f_st, true);
  }

  for (minmn = 0; minmn + 1 <= (int32_T)uv5[1]; minmn++) {
    r20->data[minmn] = muDoubleScalarMin(temp_min->data[minmn], 400.0);
  }

  iv27[0] = 1;
  iv27[1] = r19->size[0];
  emlrtSubAssignSizeCheckR2012b(iv27, 2, *(int32_T (*)[2])r20->size, 2,
    &nb_emlrtECI, sp);
  minmn = r20->size[1];
  for (i30 = 0; i30 < minmn; i30++) {
    SRange->data[1 + SRange->size[0] * r19->data[i30]] = r20->data[r20->size[0] *
      i30];
  }

  /* -- INITIALIZATION ----------------------------------------------------------- */
  /* 'tm_trk:59' Pitch = zeros(maxcands, numframes); */
  i30 = Pitch->size[0] * Pitch->size[1];
  Pitch->size[0] = 3;
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &kb_emlrtDCI, sp);
  }

  d0 = numframes;
  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &jb_emlrtDCI, sp);
  }

  Pitch->size[1] = (int32_T)d0;
  emxEnsureCapacity(sp, (emxArray__common *)Pitch, i30, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  if (!(numframes > 0.0)) {
    emlrtNonNegativeCheckR2012b(numframes, &kb_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &jb_emlrtDCI, sp);
  }

  minmn = 3 * (int32_T)d0;
  for (i30 = 0; i30 < minmn; i30++) {
    Pitch->data[i30] = 0.0;
  }

  /* 'tm_trk:60' Merit = zeros(maxcands, numframes); */
  i30 = Merit->size[0] * Merit->size[1];
  Merit->size[0] = 3;
  Merit->size[1] = (int32_T)numframes;
  emxEnsureCapacity(sp, (emxArray__common *)Merit, i30, (int32_T)sizeof(real_T),
                    &nc_emlrtRTEI);
  minmn = 3 * (int32_T)numframes;
  for (i30 = 0; i30 < minmn; i30++) {
    Merit->data[i30] = 0.0;
  }

  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /* 'tm_trk:63' for n = 1:numframes */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numframes, mxDOUBLE_CLASS, (int32_T)
    numframes, &cf_emlrtRTEI, sp);
  n = 0;
  emxInit_real_T1(sp, &b_Data, 1, &nc_emlrtRTEI, true);
  emxInit_real_T(sp, &r21, 2, &nc_emlrtRTEI, true);
  while (n <= (int32_T)numframes - 1) {
    /* 'tm_trk:65' firstp = 1+((n-1)*(nframejump)); */
    firstp = 1.0 + ((1.0 + (real_T)n) - 1.0) * nframejump;

    /* 'tm_trk:66' Signal = Data(firstp:firstp+nframesize-1); */
    d0 = (firstp + nframesize) - 1.0;
    if (firstp > d0) {
      i30 = 0;
      minmn = 0;
    } else {
      i30 = Data->size[1];
      if (firstp != (int32_T)muDoubleScalarFloor(firstp)) {
        emlrtIntegerCheckR2012b(firstp, &ib_emlrtDCI, sp);
      }

      rankR = (int32_T)firstp;
      if (!((rankR >= 1) && (rankR <= i30))) {
        emlrtDynamicBoundsCheckR2012b(rankR, 1, i30, &re_emlrtBCI, sp);
      }

      i30 = rankR - 1;
      rankR = Data->size[1];
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, &ib_emlrtDCI, sp);
      }

      minmn = (int32_T)d0;
      if (!((minmn >= 1) && (minmn <= rankR))) {
        emlrtDynamicBoundsCheckR2012b(minmn, 1, rankR, &re_emlrtBCI, sp);
      }
    }

    /*  Compute pitch candidates,  and correspnding "merit" values, */
    /*  up to maxcands per frame Merit values are normalized (0 to */
    /*  1),  and depend mainly on size of correlation peaks */
    /* 'tm_trk:71' Lag_min0 = fix(Fs/SRange(2,n)) - 3; */
    rankR = SRange->size[1];
    maxmn = n + 1;
    if (!((maxmn >= 1) && (maxmn <= rankR))) {
      emlrtDynamicBoundsCheckR2012b(maxmn, 1, rankR, &qe_emlrtBCI, sp);
    }

    d0 = Fs / SRange->data[1 + SRange->size[0] * n];
    b_fix(&d0);

    /* 'tm_trk:72' Lag_max0 = fix(Fs/SRange(1,n)) + 3; */
    rankR = SRange->size[1];
    maxmn = n + 1;
    if (!((maxmn >= 1) && (maxmn <= rankR))) {
      emlrtDynamicBoundsCheckR2012b(maxmn, 1, rankR, &pe_emlrtBCI, sp);
    }

    tol = Fs / SRange->data[SRange->size[0] * n];
    b_fix(&tol);

    /*  Compute correaltion */
    /* 'tm_trk:74' Phi =  crs_corr(Signal', Lag_min0, Lag_max0); */
    rankR = b_Data->size[0];
    b_Data->size[0] = minmn - i30;
    emxEnsureCapacity(sp, (emxArray__common *)b_Data, rankR, (int32_T)sizeof
                      (real_T), &nc_emlrtRTEI);
    minmn -= i30;
    for (rankR = 0; rankR < minmn; rankR++) {
      b_Data->data[rankR] = Data->data[i30 + rankR];
    }

    st.site = &hj_emlrtRSI;
    crs_corr(&st, b_Data, d0 - 3.0, tol + 3.0, r21);
    i30 = temp_max->size[0] * temp_max->size[1];
    temp_max->size[0] = 1;
    temp_max->size[1] = r21->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)temp_max, i30, (int32_T)sizeof
                      (real_T), &nc_emlrtRTEI);
    minmn = r21->size[0] * r21->size[1];
    for (i30 = 0; i30 < minmn; i30++) {
      temp_max->data[i30] = r21->data[i30];
    }

    /*  The Max_cand pitch candidates are collected into Pitch and */
    /*  Merit arraies  */
    /* 'tm_trk:78' [Pitch(:,n),Merit(:,n)] = cmp_rate(Phi,Fs,maxcands,Lag_min0,Lag_max0,Prm); */
    st.site = &ij_emlrtRSI;
    cmp_rate(&st, temp_max, Fs, d0 - 3.0, tol + 3.0, r20, temp_min);
    i30 = Pitch->size[1];
    rankR = n + 1;
    if (!((rankR >= 1) && (rankR <= i30))) {
      emlrtDynamicBoundsCheckR2012b(rankR, 1, i30, &oe_emlrtBCI, sp);
    }

    emlrtSubAssignSizeCheckR2012b(iv28, 1, *(int32_T (*)[2])r20->size, 2,
      &mb_emlrtECI, sp);
    for (i30 = 0; i30 < 3; i30++) {
      Pitch->data[i30 + Pitch->size[0] * n] = r20->data[i30];
    }

    i30 = Merit->size[1];
    rankR = n + 1;
    if (!((rankR >= 1) && (rankR <= i30))) {
      emlrtDynamicBoundsCheckR2012b(rankR, 1, i30, &ke_emlrtBCI, sp);
    }

    emlrtSubAssignSizeCheckR2012b(iv28, 1, *(int32_T (*)[2])temp_min->size, 2,
      &jb_emlrtECI, sp);
    for (i30 = 0; i30 < 3; i30++) {
      Merit->data[i30 + Merit->size[0] * n] = temp_min->data[i30];
    }

    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r21);
  emxFree_real_T(&b_Data);
  emxFree_real_T(&SRange);

  /*    The following lines increase merit for peaks which are very */
  /*    close to in frequency to those peaks which are close to */
  /*    smoothed F0 track from spectrogram,   and decrease merit for peaks */
  /*    which are not close to the smoothed F0 track obtained from */
  /*    spectrogram */
  /* 'tm_trk:86' for i = 1:maxcands */
  i = 0;
  emxInit_real_T1(sp, &Y, 1, &nc_emlrtRTEI, true);
  emxInit_int32_T1(sp, &jpvt, 2, &nc_emlrtRTEI, true);
  emxInit_real_T(sp, &b_Pitch, 2, &nc_emlrtRTEI, true);
  emxInit_real_T(sp, &c_Pitch, 2, &nc_emlrtRTEI, true);
  emxInit_real_T(sp, &b_SPitch, 2, &nc_emlrtRTEI, true);
  while (i < 3) {
    /* 'tm_trk:87' diff   =  abs( (Pitch(i,:) - SPitch(1,:))); */
    minmn = Pitch->size[1];
    i30 = c_Pitch->size[0] * c_Pitch->size[1];
    c_Pitch->size[0] = 1;
    c_Pitch->size[1] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)c_Pitch, i30, (int32_T)sizeof
                      (real_T), &nc_emlrtRTEI);
    for (i30 = 0; i30 < minmn; i30++) {
      c_Pitch->data[c_Pitch->size[0] * i30] = Pitch->data[i + Pitch->size[0] *
        i30];
    }

    for (i30 = 0; i30 < 2; i30++) {
      d_Pitch[i30] = c_Pitch->size[i30];
    }

    minmn = SPitch->size[1];
    i30 = b_SPitch->size[0] * b_SPitch->size[1];
    b_SPitch->size[0] = 1;
    b_SPitch->size[1] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)b_SPitch, i30, (int32_T)sizeof
                      (real_T), &nc_emlrtRTEI);
    for (i30 = 0; i30 < minmn; i30++) {
      b_SPitch->data[b_SPitch->size[0] * i30] = SPitch->data[SPitch->size[0] *
        i30];
    }

    for (i30 = 0; i30 < 2; i30++) {
      c_SPitch[i30] = b_SPitch->size[i30];
    }

    if ((d_Pitch[0] != c_SPitch[0]) || (d_Pitch[1] != c_SPitch[1])) {
      emlrtSizeEqCheckNDR2012b(&d_Pitch[0], &c_SPitch[0], &lb_emlrtECI, sp);
    }

    minmn = Pitch->size[1];
    i30 = b_Pitch->size[0] * b_Pitch->size[1];
    b_Pitch->size[0] = 1;
    b_Pitch->size[1] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)b_Pitch, i30, (int32_T)sizeof
                      (real_T), &nc_emlrtRTEI);
    for (i30 = 0; i30 < minmn; i30++) {
      b_Pitch->data[b_Pitch->size[0] * i30] = Pitch->data[i + Pitch->size[0] *
        i30] - SPitch->data[SPitch->size[0] * i30];
    }

    st.site = &jj_emlrtRSI;
    d_abs(&st, b_Pitch, temp_min);

    /* 'tm_trk:88' match1 = zeros(1,length(diff)); */
    i30 = match1->size[0] * match1->size[1];
    match1->size[0] = 1;
    match1->size[1] = temp_min->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)match1, i30, (int32_T)sizeof
                      (real_T), &nc_emlrtRTEI);
    minmn = temp_min->size[1];
    for (i30 = 0; i30 < minmn; i30++) {
      match1->data[i30] = 0.0;
    }

    /* 'tm_trk:89' for j = 1:length(diff) */
    j = 1;
    while (j - 1 <= temp_min->size[1] - 1) {
      /* 'tm_trk:90' match1(j) = diff(j) < freq_thresh; */
      i30 = temp_min->size[1];
      if (!((j >= 1) && (j <= i30))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i30, &ve_emlrtBCI, sp);
      }

      tol = temp_min->data[j - 1];
      i30 = tau->size[0];
      tau->size[0] = freq_thresh->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)tau, i30, (int32_T)sizeof(real_T),
                        &nc_emlrtRTEI);
      minmn = freq_thresh->size[0];
      for (i30 = 0; i30 < minmn; i30++) {
        tau->data[i30] = (tol < freq_thresh->data[i30]);
      }

      i30 = tau->size[0];
      if (1 != i30) {
        emlrtSizeEqCheck1DR2012b(1, i30, &kb_emlrtECI, sp);
      }

      i30 = tau->size[0];
      if (!(1 <= i30)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i30, &me_emlrtBCI, sp);
      }

      i30 = match1->size[1];
      if (!((j >= 1) && (j <= i30))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i30, &we_emlrtBCI, sp);
      }

      match1->data[j - 1] = tau->data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*      match1 =  (diff < freq_thresh); */
    /* 'tm_trk:93' match = zeros(1,length(diff)); */
    i30 = match->size[0] * match->size[1];
    match->size[0] = 1;
    match->size[1] = temp_min->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)match, i30, (int32_T)sizeof(real_T),
                      &nc_emlrtRTEI);
    minmn = temp_min->size[1];
    for (i30 = 0; i30 < minmn; i30++) {
      match->data[i30] = 0.0;
    }

    /* 'tm_trk:94' for j = 1:length(diff) */
    j = 0;
    while (j <= temp_min->size[1] - 1) {
      /* 'tm_trk:95' match(j) = ((1 - (diff(j)/freq_thresh)) * match1(j)); */
      st.site = &kj_emlrtRSI;
      i30 = temp_min->size[1];
      rankR = j + 1;
      if (!((rankR >= 1) && (rankR <= i30))) {
        emlrtDynamicBoundsCheckR2012b(rankR, 1, i30, &ne_emlrtBCI, &st);
      }

      if (freq_thresh->size[0] == 0) {
        i30 = temp_max->size[0] * temp_max->size[1];
        temp_max->size[0] = 1;
        temp_max->size[1] = 0;
        emxEnsureCapacity(&st, (emxArray__common *)temp_max, i30, (int32_T)
                          sizeof(real_T), &nc_emlrtRTEI);
      } else if (freq_thresh->size[0] == 1) {
        b_st.site = &ck_emlrtRSI;
        c_st.site = &sb_emlrtRSI;
        d_st.site = &ub_emlrtRSI;
        e_st.site = &xb_emlrtRSI;
        i30 = tau->size[0];
        tau->size[0] = freq_thresh->size[0];
        emxEnsureCapacity(&e_st, (emxArray__common *)tau, i30, (int32_T)sizeof
                          (real_T), &nc_emlrtRTEI);
        minmn = freq_thresh->size[0];
        for (i30 = 0; i30 < minmn; i30++) {
          tau->data[i30] = freq_thresh->data[i30];
        }

        info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)1, (ptrdiff_t)1, &tau->
          data[0], (ptrdiff_t)1, &ipiv_t);
        minmn = (int32_T)info_t;
        f_st.site = &yb_emlrtRSI;
        if (minmn < 0) {
          if (minmn == -1010) {
            g_st.site = &ac_emlrtRSI;
            e_error(&g_st);
          } else {
            g_st.site = &bc_emlrtRSI;
            f_error(&g_st, minmn);
          }

          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
          maxmn = tau->size[0];
          i30 = tau->size[0];
          tau->size[0] = maxmn;
          emxEnsureCapacity(&e_st, (emxArray__common *)tau, i30, (int32_T)sizeof
                            (real_T), &nc_emlrtRTEI);
          for (i30 = 0; i30 < maxmn; i30++) {
            tau->data[i30] = rtNaN;
          }

          f_st.site = &dk_emlrtRSI;
        } else {
          f_st.site = &ek_emlrtRSI;
        }

        if (minmn > 0) {
          d_st.site = &tb_emlrtRSI;
          e_st.site = &cc_emlrtRSI;
          warning(&e_st);
        }

        tol = 1.0 / tau->data[0] * temp_min->data[j];
        i30 = temp_max->size[0] * temp_max->size[1];
        temp_max->size[0] = 1;
        temp_max->size[1] = 1;
        emxEnsureCapacity(&st, (emxArray__common *)temp_max, i30, (int32_T)
                          sizeof(real_T), &nc_emlrtRTEI);
        temp_max->data[0] = tol;
      } else {
        b_st.site = &ck_emlrtRSI;
        i30 = temp_max->size[0] * temp_max->size[1];
        temp_max->size[0] = 1;
        temp_max->size[1] = freq_thresh->size[0];
        emxEnsureCapacity(&b_st, (emxArray__common *)temp_max, i30, (int32_T)
                          sizeof(real_T), &nc_emlrtRTEI);
        minmn = freq_thresh->size[0];
        for (i30 = 0; i30 < minmn; i30++) {
          temp_max->data[temp_max->size[0] * i30] = freq_thresh->data[i30];
        }

        c_st.site = &hk_emlrtRSI;
        xgeqp3(&c_st, temp_max, tau, jpvt);
        c_st.site = &ik_emlrtRSI;
        rankR = 0;
        tol = 0.0;
        if (1 < temp_max->size[1]) {
          minmn = 1;
          maxmn = temp_max->size[1];
        } else {
          minmn = temp_max->size[1];
          maxmn = 1;
        }

        if (minmn > 0) {
          tol = (real_T)maxmn * muDoubleScalarAbs(temp_max->data[0]) *
            2.2204460492503131E-16;
          while ((rankR < 1) && (muDoubleScalarAbs(temp_max->data[0]) >= tol)) {
            rankR = 1;
          }
        }

        if (rankR < minmn) {
          d_st.site = &sk_emlrtRSI;
          for (i30 = 0; i30 < 6; i30++) {
            u[i30] = rfmt[i30];
          }

          y = NULL;
          m7 = emlrtCreateCharArray(2, iv29);
          emlrtInitCharArrayR2013a(&d_st, 6, m7, &u[0]);
          emlrtAssign(&y, m7);
          e_st.site = &km_emlrtRSI;
          emlrt_marshallIn(&e_st, b_sprintf(&e_st, y, emlrt_marshallOut(tol),
            &g_emlrtMCI), "sprintf", cv6);
          d_st.site = &tk_emlrtRSI;
          b_warning(&d_st, 0, cv6);
        }

        c_st.site = &jk_emlrtRSI;
        LSQFromQR(&c_st, temp_max, tau, jpvt, temp_min->data[j], rankR, Y);
        i30 = temp_max->size[0] * temp_max->size[1];
        temp_max->size[0] = 1;
        temp_max->size[1] = Y->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)temp_max, i30, (int32_T)
                          sizeof(real_T), &nc_emlrtRTEI);
        minmn = Y->size[0];
        for (i30 = 0; i30 < minmn; i30++) {
          temp_max->data[temp_max->size[0] * i30] = Y->data[i30];
        }
      }

      i30 = match1->size[1];
      rankR = j + 1;
      if (!((rankR >= 1) && (rankR <= i30))) {
        emlrtDynamicBoundsCheckR2012b(rankR, 1, i30, &le_emlrtBCI, sp);
      }

      i30 = temp_max->size[0] * temp_max->size[1];
      temp_max->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)temp_max, i30, (int32_T)sizeof
                        (real_T), &nc_emlrtRTEI);
      minmn = temp_max->size[0];
      maxmn = temp_max->size[1];
      tol = match1->data[j];
      minmn *= maxmn;
      for (i30 = 0; i30 < minmn; i30++) {
        temp_max->data[i30] = (1.0 - temp_max->data[i30]) * tol;
      }

      i30 = temp_max->size[1];
      if (1 != i30) {
        emlrtSizeEqCheck1DR2012b(1, i30, &ib_emlrtECI, sp);
      }

      i30 = temp_max->size[1];
      if (!(1 <= i30)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i30, &je_emlrtBCI, sp);
      }

      i30 = match->size[1];
      rankR = 1 + j;
      if (!((rankR >= 1) && (rankR <= i30))) {
        emlrtDynamicBoundsCheckR2012b(rankR, 1, i30, &ue_emlrtBCI, sp);
      }

      match->data[rankR - 1] = temp_max->data[0];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*      match  =  ((1 - (diff./freq_thresh)) .* match1); */
    /* 'tm_trk:98' Merit(i,:) = ((1+merit_boost)*Merit(i,:)).*match; */
    minmn = Merit->size[1];
    i30 = r20->size[0] * r20->size[1];
    r20->size[0] = 1;
    r20->size[1] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)r20, i30, (int32_T)sizeof(real_T),
                      &nc_emlrtRTEI);
    for (i30 = 0; i30 < minmn; i30++) {
      r20->data[r20->size[0] * i30] = 1.2 * Merit->data[i + Merit->size[0] * i30];
    }

    for (i30 = 0; i30 < 2; i30++) {
      iv30[i30] = r20->size[i30];
    }

    for (i30 = 0; i30 < 2; i30++) {
      b_match[i30] = match->size[i30];
    }

    if ((iv30[0] != b_match[0]) || (iv30[1] != b_match[1])) {
      emlrtSizeEqCheckNDR2012b(&iv30[0], &b_match[0], &hb_emlrtECI, sp);
    }

    minmn = Merit->size[1];
    i30 = r19->size[0];
    r19->size[0] = minmn;
    emxEnsureCapacity(sp, (emxArray__common *)r19, i30, (int32_T)sizeof(int32_T),
                      &nc_emlrtRTEI);
    for (i30 = 0; i30 < minmn; i30++) {
      r19->data[i30] = i30;
    }

    i30 = r20->size[0] * r20->size[1];
    r20->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r20, i30, (int32_T)sizeof(real_T),
                      &nc_emlrtRTEI);
    i30 = r20->size[0];
    rankR = r20->size[1];
    minmn = i30 * rankR;
    for (i30 = 0; i30 < minmn; i30++) {
      r20->data[i30] *= match->data[i30];
    }

    iv31[0] = 1;
    iv31[1] = r19->size[0];
    emlrtSubAssignSizeCheckR2012b(iv31, 2, *(int32_T (*)[2])r20->size, 2,
      &gb_emlrtECI, sp);
    minmn = r20->size[1];
    for (i30 = 0; i30 < minmn; i30++) {
      Merit->data[i + Merit->size[0] * r19->data[i30]] = r20->data[r20->size[0] *
        i30];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_SPitch);
  emxFree_real_T(&c_Pitch);
  emxFree_real_T(&b_Pitch);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&tau);
  emxFree_real_T(&Y);
  emxFree_real_T(&r20);
  emxFree_int32_T(&r19);
  emxFree_real_T(&match);
  emxFree_real_T(&match1);
  emxFree_real_T(&temp_min);
  emxFree_real_T(&freq_thresh);
  emxFree_real_T(&temp_max);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (tm_trk.c) */
