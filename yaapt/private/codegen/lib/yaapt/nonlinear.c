/*
 * File: nonlinear.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "nonlinear.h"
#include "yaapt_emxutil.h"
#include "Myhanning.h"
#include "filter.h"
#include "Myfir1.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * NONLINEAR Create the nonlinear processed signal
 *
 *    [DataB, DataC, DataD, newFs] = nonlinear(DataA, Fs, Prm) creates
 *    nonlinear signal (squared signal) and applys filtering.
 *
 *  INPUTS:
 *    DataA: The original signal from read_audio.m
 *    Fs:    The sampling rate for the signal
 *    Prm:   Array of parameters used to control performance
 *
 *  OUTPUTS:
 *    DataB: The original signal, bandpass filtered with F1.
 *    DataC: The nonlinear signal, no filtering
 *    DataD: The nonlinear signal, bandpass filtered with F1.
 *    newFs: The sampling rate of the new signal
 * Arguments    : const emxArray_real_T *DataA
 *                double Fs
 *                double Prm_bp_forder
 *                double Prm_bp_low
 *                double Prm_bp_high
 *                double Prm_dec_factor
 *                emxArray_real_T *DataB
 *                emxArray_real_T *DataC
 *                emxArray_real_T *DataD
 *                double *newFs
 * Return Type  : void
 */
void nonlinear(const emxArray_real_T *DataA, double Fs, double Prm_bp_forder,
               double Prm_bp_low, double Prm_bp_high, double Prm_dec_factor,
               emxArray_real_T *DataB, emxArray_real_T *DataC, emxArray_real_T
               *DataD, double *newFs)
{
  double dec_factor;
  emxArray_real_T *b_F1;
  emxArray_real_T *tempData;
  double b_Prm_bp_low[2];
  int i1;
  int i2;
  int k;

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
  /*  Do not decimate if Fs less than this */
  /*   Parameters for filtering original signal, with a broader band */
  if (Fs > 1000.0) {
    dec_factor = Prm_dec_factor;
  } else {
    dec_factor = 1.0;
  }

  emxInit_real_T(&b_F1, 2);
  emxInit_real_T(&tempData, 2);

  /*  Creates the bandpass filters */
  /*  filter F1 */
  b_Prm_bp_low[0] = Prm_bp_low / (Fs / 2.0);
  b_Prm_bp_low[1] = Prm_bp_high / (Fs / 2.0);
  Myfir1(Prm_bp_forder, b_Prm_bp_low, b_F1);

  /*   b_F1_test = fir1(Filter_order,w); */
  /* filtering the original data with the bandpass filter, */
  /*  DataA   is original acoustic signal */
  /*  Original signal filtered with F1 */
  filter(b_F1, DataA, tempData);

  /*  LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  if ((dec_factor == 0.0) || (((dec_factor > 0.0) && (1 > DataA->size[1])) ||
       ((0.0 > dec_factor) && (DataA->size[1] > 1)))) {
    i1 = 1;
    i2 = -1;
  } else {
    i1 = (int)dec_factor;
    i2 = DataA->size[1] - 1;
  }

  k = DataB->size[0] * DataB->size[1];
  DataB->size[0] = 1;
  DataB->size[1] = div_s32_floor(i2, i1) + 1;
  emxEnsureCapacity((emxArray__common *)DataB, k, (int)sizeof(double));
  k = div_s32_floor(i2, i1);
  for (i2 = 0; i2 <= k; i2++) {
    DataB->data[DataB->size[0] * i2] = tempData->data[i1 * i2];
  }

  /*    Create nonlinear version of signal */
  /*    Original signal */
  /*    DataC =  DataA; */
  /*    Absoulte value of the signal */
  /*    DataC =  abs(DataA); */
  /*    Squared value of the signal */
  i1 = DataC->size[0] * DataC->size[1];
  DataC->size[0] = 1;
  DataC->size[1] = DataA->size[1];
  emxEnsureCapacity((emxArray__common *)DataC, i1, (int)sizeof(double));
  for (k = 0; k + 1 <= DataA->size[1]; k++) {
    DataC->data[k] = DataA->data[k] * DataA->data[k];
  }

  /*    Nonlinear version filtered with F1 */
  filter(b_F1, DataC, tempData);
  emxFree_real_T(&b_F1);
  if ((dec_factor == 0.0) || (((dec_factor > 0.0) && (1 > DataA->size[1])) ||
       ((0.0 > dec_factor) && (DataA->size[1] > 1)))) {
    i1 = 1;
    i2 = -1;
  } else {
    i1 = (int)dec_factor;
    i2 = DataA->size[1] - 1;
  }

  k = DataD->size[0] * DataD->size[1];
  DataD->size[0] = 1;
  DataD->size[1] = div_s32_floor(i2, i1) + 1;
  emxEnsureCapacity((emxArray__common *)DataD, k, (int)sizeof(double));
  k = div_s32_floor(i2, i1);
  for (i2 = 0; i2 <= k; i2++) {
    DataD->data[DataD->size[0] * i2] = tempData->data[i1 * i2];
  }

  emxFree_real_T(&tempData);
  *newFs = Fs / dec_factor;
}

/*
 * File trailer for nonlinear.c
 *
 * [EOF]
 */
