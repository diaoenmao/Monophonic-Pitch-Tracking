/*
 * dynamic5.c
 *
 * Code generation for function 'dynamic5'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "dynamic5.h"
#include "mpower.h"
#include "yaapt_emxutil.h"
#include "path1.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo sk_emlrtRSI = { 58, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo jd_emlrtRTEI = { 1, 23, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo kd_emlrtRTEI = { 40, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 48, 46, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 48, 48, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 48, 65, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 48, 67, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 64, 31, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 64, 31, "Path", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 64, 40, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 64, 5, "FinPitch", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 48, 19, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 48, 21, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 48, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 49, 40, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 49, 42, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 49, 44, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 49, 55, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 49, 57, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 49, 59, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 49, 19, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 49, 21, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 49, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

/* Function Definitions */
void dynamic5(const emlrtStack *sp, const emxArray_real_T *Pitch_array, const
              emxArray_real_T *Merit_array, real_T k1, emxArray_real_T *FinPitch)
{
  emxArray_real_T *Trans;
  int32_T numframes;
  int32_T numcands;
  int32_T b_Trans;
  int32_T loop_ub;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T c_Trans;
  emxArray_real_T *r29;
  real_T Path_data[4999];
  int32_T Path_size[2];
  int32_T n;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &Trans, 3, &kd_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 14U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 0);

  /*   Dynamic programming on speech processing */
  /*  */
  /*  [FinPitch] =dynamic5(Pitch_array, Merit_array, k1); */
  /*  This routine is used to compute Local and Transition cost matrices */
  /*  to enable lowest cost tracking of pitch candidates; */
  /*  It uses NFLER from the spectrogram and the highly robust */
  /*  spectral F0 track, plus the merits, for */
  /*  computation of the cost matrices. */
  /*    Creation date:   Spring 2001 */
  /*    Revision dates:   January 3, 2002, March 7, 2005 */
  /*    Programmer: Dr. Zahorian,Kavita Kasi, Lingyun Gu; */
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
  /*  some initializations. */
  numframes = Pitch_array->size[1] - 1;
  numcands = Pitch_array->size[0] - 1;

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* forming the local cost matrix */
  /* initialization for the formation of the transition cost matrix */
  b_Trans = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = Pitch_array->size[0];
  Trans->size[1] = Pitch_array->size[0];
  Trans->size[2] = Pitch_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, b_Trans, (int32_T)sizeof
                    (real_T), &jd_emlrtRTEI);
  loop_ub = Pitch_array->size[0] * Pitch_array->size[0] * Pitch_array->size[1];
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    Trans->data[b_Trans] = 0.0;
  }

  /* the transition cost matrix is proportional to frequency differences */
  /* between successive candidates. */
  i = 0;
  while (i <= numframes - 1) {
    covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 0, 1);
    j = 1;
    while (j - 1 <= numcands) {
      covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 1, 1);
      k = 1;
      while (k - 1 <= numcands) {
        covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 2, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 1);
        b_Trans = Pitch_array->size[0];
        loop_ub = (j - 1) + 1;
        if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &ef_emlrtBCI, sp);
        }

        b_Trans = Pitch_array->size[1];
        loop_ub = (int32_T)(2.0 + (real_T)i);
        if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &ff_emlrtBCI, sp);
        }

        b_Trans = Pitch_array->size[0];
        loop_ub = (k - 1) + 1;
        if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &gf_emlrtBCI, sp);
        }

        b_Trans = Pitch_array->size[1];
        loop_ub = (int32_T)((2.0 + (real_T)i) - 1.0);
        if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &hf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[0];
        if (!((k >= 1) && (k <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, b_Trans, &mf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[1];
        if (!((j >= 1) && (j <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b_Trans, &nf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, b_Trans, &of_emlrtBCI, sp);
        }

        Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                     Trans->size[1] * (i + 1)) - 1] = muDoubleScalarAbs
          (Pitch_array->data[(j + Pitch_array->size[0] * (i + 1)) - 1] -
           Pitch_array->data[(k + Pitch_array->size[0] * i) - 1]) / 60.0;
        b_Trans = Trans->size[0];
        if (!((k >= 1) && (k <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, b_Trans, &pf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[1];
        if (!((j >= 1) && (j <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b_Trans, &qf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, b_Trans, &rf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[0];
        if (!((k >= 1) && (k <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, b_Trans, &sf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[1];
        if (!((j >= 1) && (j <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b_Trans, &tf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, b_Trans, &uf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[0];
        if (!((k >= 1) && (k <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, b_Trans, &vf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[1];
        if (!((j >= 1) && (j <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b_Trans, &wf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, b_Trans, &xf_emlrtBCI, sp);
        }

        Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                     Trans->size[1] * (i + 1)) - 1] = 0.05 * Trans->data[((k +
          Trans->size[0] * (j - 1)) + Trans->size[0] * Trans->size[1] * (i + 1))
          - 1] + mpower(Trans->data[((k + Trans->size[0] * (j - 1)) +
          Trans->size[0] * Trans->size[1] * (i + 1)) - 1]);
        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 2, 0);
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 1, 0);
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 2);

  /*  Overal balance between Local and Transition costs */
  b_Trans = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, b_Trans, (int32_T)sizeof
                    (real_T), &jd_emlrtRTEI);
  loop_ub = Trans->size[0];
  b_Trans = Trans->size[1];
  c_Trans = Trans->size[2];
  loop_ub = loop_ub * b_Trans * c_Trans;
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    Trans->data[b_Trans] *= k1;
  }

  emxInit_real_T(sp, &r29, 2, &jd_emlrtRTEI, true);

  /*  search the best path */
  b_Trans = r29->size[0] * r29->size[1];
  r29->size[0] = Merit_array->size[0];
  r29->size[1] = Merit_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r29, b_Trans, (int32_T)sizeof(real_T),
                    &jd_emlrtRTEI);
  loop_ub = Merit_array->size[0] * Merit_array->size[1];
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    r29->data[b_Trans] = 1.0 - Merit_array->data[b_Trans];
  }

  st.site = &sk_emlrtRSI;
  path1(&st, r29, Trans, Path_data, Path_size);

  /*  Extract the final vocied F0 track which has the lowest cost */
  /*  At this point, VSpec_F0 is the spectral pitch track for voiced frames */
  b_Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, b_Trans, (int32_T)sizeof
                    (real_T), &jd_emlrtRTEI);
  loop_ub = Pitch_array->size[1];
  emxFree_real_T(&r29);
  emxFree_real_T(&Trans);
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    FinPitch->data[b_Trans] = 0.0;
  }

  n = 1;
  while (n - 1 <= numframes) {
    covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 3);
    b_Trans = Pitch_array->size[0];
    if (!((n >= 1) && (n <= Path_size[1]))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, Path_size[1], &jf_emlrtBCI, sp);
    }

    loop_ub = (int32_T)Path_data[n - 1];
    if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &if_emlrtBCI, sp);
    }

    b_Trans = Pitch_array->size[1];
    if (!((n >= 1) && (n <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, b_Trans, &kf_emlrtBCI, sp);
    }

    b_Trans = FinPitch->size[1];
    if (!((n >= 1) && (n <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, b_Trans, &lf_emlrtBCI, sp);
    }

    FinPitch->data[n - 1] = Pitch_array->data[(loop_ub + Pitch_array->size[0] *
      (n - 1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (dynamic5.c) */
