/*
 * nonlinear.c
 *
 * Code generation for function 'nonlinear'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "nonlinear.h"
#include "Myhanning.h"
#include "yaapt_emxutil.h"
#include "filter.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "Myfir1.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo m_emlrtRSI = { 54, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo n_emlrtRSI = { 63, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo o_emlrtRSI = { 75, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo p_emlrtRSI = { 79, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo qe_emlrtRSI = { 58, "power",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo re_emlrtRSI = { 60, "power",
  "F:\\MATLAB\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo se_emlrtRSI = { 73, "applyScalarFunction",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m" };

static emlrtRSInfo te_emlrtRSI = { 132, "applyScalarFunction",
  "F:\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m" };

static emlrtRTEInfo e_emlrtRTEI = { 1, 40, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRTEInfo f_emlrtRTEI = { 54, 2, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRTEInfo g_emlrtRTEI = { 63, 1, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtDCInfo b_emlrtDCI = { 82, 9, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 1 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 82, 9, "tempData", "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 81, 18, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 4 };

static emlrtDCInfo d_emlrtDCI = { 65, 9, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 1 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 65, 9, "tempData", "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 0 };

/* Function Definitions */

/*
 * function[DataB, DataC, DataD, newFs] = nonlinear(DataA, Fs, Prm)
 */
void nonlinear(const emlrtStack *sp, const emxArray_real_T *DataA, real_T Fs,
               real_T Prm_bp_forder, real_T Prm_bp_low, real_T Prm_bp_high,
               real_T Prm_dec_factor, emxArray_real_T *DataB, emxArray_real_T
               *DataC, emxArray_real_T *DataD, real_T *newFs)
{
  real_T dec_factor;
  emxArray_real_T *b_F1;
  emxArray_real_T *tempData;
  int32_T lenDataA;
  real_T b_Prm_bp_low[2];
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  uint32_T uv0[2];
  boolean_T overflow;
  int32_T k;
  int32_T b_k;
  real_T y;
  jmp_buf * volatile emlrtJBStack;
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

  /* NONLINEAR Create the nonlinear processed signal */
  /*  */
  /*    [DataB, DataC, DataD, newFs] = nonlinear(DataA, Fs, Prm) creates */
  /*    nonlinear signal (squared signal) and applys filtering. */
  /*  */
  /*  INPUTS:  */
  /*    DataA: The original signal from read_audio.m  */
  /*    Fs:    The sampling rate for the signal */
  /*    Prm:   Array of parameters used to control performance */
  /*  */
  /*  OUTPUTS: */
  /*    DataB: The original signal, bandpass filtered with F1. */
  /*    DataC: The nonlinear signal, no filtering */
  /*    DataD: The nonlinear signal, bandpass filtered with F1. */
  /*    newFs: The sampling rate of the new signal  */
  /*    Creation date:  Jun. 30, 2006 */
  /*    Programers:     Hongbing Hu, Princy, Zahorian */
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
  /* 'nonlinear:33' Fs_min = 1000; */
  /*  Do not decimate if Fs less than this */
  /*   Parameters for filtering original signal, with a broader band */
  /* 'nonlinear:36' Filter_order = Prm.bp_forder; */
  /* 'nonlinear:37' F_hp = Prm.bp_low; */
  /* 'nonlinear:38' F_lp = Prm.bp_high; */
  /* 'nonlinear:40' if (Fs > Fs_min) */
  if (Fs > 1000.0) {
    /* 'nonlinear:41' dec_factor = Prm.dec_factor; */
    dec_factor = Prm_dec_factor;
  } else {
    /* 'nonlinear:42' else */
    /* 'nonlinear:43' dec_factor = 1; */
    dec_factor = 1.0;
  }

  emxInit_real_T(sp, &b_F1, 2, &f_emlrtRTEI, true);
  emxInit_real_T(sp, &tempData, 2, &g_emlrtRTEI, true);

  /*  Creates the bandpass filters */
  /* 'nonlinear:48' lenDataA = length(DataA); */
  lenDataA = DataA->size[1];

  /*  filter F1 */
  /* 'nonlinear:51' w1  = (F_hp / (Fs/2)); */
  /* 'nonlinear:52' w2  = (F_lp / (Fs/2)); */
  /* 'nonlinear:53' w   = [w1 w2]; */
  /* 'nonlinear:54' b_F1 = Myfir1(Filter_order,w); */
  b_Prm_bp_low[0] = Prm_bp_low / (Fs / 2.0);
  b_Prm_bp_low[1] = Prm_bp_high / (Fs / 2.0);
  st.site = &m_emlrtRSI;
  Myfir1(&st, Prm_bp_forder, b_Prm_bp_low, b_F1);

  /*   b_F1_test = fir1(Filter_order,w); */
  /* 'nonlinear:56' a   = 1; */
  /* filtering the original data with the bandpass filter, */
  /*  DataA   is original acoustic signal */
  /*  Original signal filtered with F1 */
  /* 'nonlinear:63' tempData = filter(b_F1,a,DataA); */
  st.site = &n_emlrtRSI;
  filter(&st, b_F1, DataA, tempData);

  /*  LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  /* 'nonlinear:65' DataB = tempData(1:dec_factor:lenDataA); */
  if ((dec_factor == 0.0) || (((dec_factor > 0.0) && (1 > DataA->size[1])) ||
       ((0.0 > dec_factor) && (DataA->size[1] > 1)))) {
    i1 = 1;
    i2 = -1;
  } else {
    i1 = tempData->size[1];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &vb_emlrtBCI, sp);
    }

    if (dec_factor != (int32_T)muDoubleScalarFloor(dec_factor)) {
      emlrtIntegerCheckR2012b(dec_factor, &d_emlrtDCI, sp);
    }

    i1 = (int32_T)dec_factor;
    i2 = tempData->size[1];
    loop_ub = DataA->size[1];
    if (!((loop_ub >= 1) && (loop_ub <= i2))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &vb_emlrtBCI, sp);
    }

    i2 = loop_ub - 1;
  }

  loop_ub = DataB->size[0] * DataB->size[1];
  DataB->size[0] = 1;
  DataB->size[1] = div_s32_floor(sp, i2, i1) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)DataB, loop_ub, (int32_T)sizeof
                    (real_T), &e_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i2, i1);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    DataB->data[DataB->size[0] * i2] = tempData->data[i1 * i2];
  }

  /*    Create nonlinear version of signal */
  /*    Original signal */
  /*    DataC =  DataA; */
  /*    Absoulte value of the signal */
  /*    DataC =  abs(DataA); */
  /*    Squared value of the signal */
  /* 'nonlinear:75' DataC =  DataA .^2; */
  st.site = &o_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  c_st.site = &qe_emlrtRSI;
  i1 = tempData->size[0] * tempData->size[1];
  tempData->size[0] = 1;
  tempData->size[1] = DataA->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)tempData, i1, (int32_T)sizeof
                    (real_T), &e_emlrtRTEI);
  loop_ub = DataA->size[0] * DataA->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    tempData->data[i1] = DataA->data[i1];
  }

  d_st.site = &se_emlrtRSI;
  e_st.site = &ue_emlrtRSI;
  for (i1 = 0; i1 < 2; i1++) {
    uv0[i1] = (uint32_T)DataA->size[i1];
  }

  i1 = DataC->size[0] * DataC->size[1];
  DataC->size[0] = 1;
  DataC->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(&e_st, (emxArray__common *)DataC, i1, (int32_T)sizeof(real_T),
                    &e_emlrtRTEI);
  if (dimagree(DataC, DataA)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&d_st, &xe_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  loop_ub = DataA->size[1];
  d_st.site = &te_emlrtRSI;
  if (1 > DataA->size[1]) {
    overflow = false;
  } else {
    overflow = (DataA->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&e_st, true);
  }

  emlrtEnterParallelRegion(&c_st, omp_in_parallel());
  emlrtPushJmpBuf(&c_st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(c_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(b_k)

  for (k = 1; k <= loop_ub; k++) {
    b_k = k;
    DataC->data[b_k - 1] = tempData->data[b_k - 1] * tempData->data[b_k - 1];
  }

  emlrtPopJmpBuf(&c_st, &emlrtJBStack);
  emlrtExitParallelRegion(&c_st, omp_in_parallel());
  c_st.site = &re_emlrtRSI;

  /*    Nonlinear version filtered with F1 */
  /* 'nonlinear:79' tempData = filter(b_F1,a,DataC); */
  st.site = &p_emlrtRSI;
  filter(&st, b_F1, DataC, tempData);

  /* 'nonlinear:80' LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  y = (((real_T)lenDataA + dec_factor) - 1.0) / dec_factor;
  emxFree_real_T(&b_F1);

  /* 'nonlinear:81' DataD = zeros(1, LenData_dec); */
  if (y < 0.0) {
    y = muDoubleScalarCeil(y);
  } else {
    y = muDoubleScalarFloor(y);
  }

  if (!(y > 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &c_emlrtDCI, sp);
  }

  /* 'nonlinear:82' DataD = tempData(1:dec_factor:lenDataA); */
  if ((dec_factor == 0.0) || (((dec_factor > 0.0) && (1 > lenDataA)) || ((0.0 >
         dec_factor) && (lenDataA > 1)))) {
    i1 = 1;
    i2 = -1;
  } else {
    i1 = tempData->size[1];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &ub_emlrtBCI, sp);
    }

    if (dec_factor != (int32_T)muDoubleScalarFloor(dec_factor)) {
      emlrtIntegerCheckR2012b(dec_factor, &b_emlrtDCI, sp);
    }

    i1 = (int32_T)dec_factor;
    i2 = tempData->size[1];
    if (!((lenDataA >= 1) && (lenDataA <= i2))) {
      emlrtDynamicBoundsCheckR2012b(lenDataA, 1, i2, &ub_emlrtBCI, sp);
    }

    i2 = lenDataA - 1;
  }

  loop_ub = DataD->size[0] * DataD->size[1];
  DataD->size[0] = 1;
  DataD->size[1] = div_s32_floor(sp, i2, i1) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)DataD, loop_ub, (int32_T)sizeof
                    (real_T), &e_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i2, i1);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    DataD->data[DataD->size[0] * i2] = tempData->data[i1 * i2];
  }

  emxFree_real_T(&tempData);

  /* 'nonlinear:84' newFs = Fs/dec_factor; */
  *newFs = Fs / dec_factor;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nonlinear.c) */
