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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo kk_emlrtRSI = { 58, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo cd_emlrtRTEI = { 1, 23, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo dd_emlrtRTEI = { 40, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtRTEInfo ed_emlrtRTEI = { 58, 1, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m" };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 48, 67, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 48, 65, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 48, 48, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 48, 46, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 64, 31, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtDCInfo wc_emlrtDCI = { 64, 31, "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 1 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 64, 31, "Path", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 64, 40, "Pitch_array", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 64, 5, "FinPitch", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 48, 19, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 48, 21, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 48, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 49, 40, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 49, 42, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 49, 44, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 49, 55, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 49, 57, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 49, 59, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 49, 19, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 49, 21, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 49, 23, "Trans", "dynamic5",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m", 0 };

/* Function Definitions */

/*
 * function [FinPitch] = dynamic5(Pitch_array, Merit_array, k1)
 */
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
  emxArray_real_T *r36;
  emxArray_real_T *Path;
  int32_T n;
  real_T d0;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T2(sp, &Trans, 3, &dd_emlrtRTEI, true);

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
  /* 'dynamic5:27' F0_min = 60; */
  /*  some initializations. */
  /* 'dynamic5:30' [numcands, numframes] = size(Pitch_array); */
  numframes = Pitch_array->size[1] - 1;
  numcands = Pitch_array->size[0] - 1;

  /* The following weighting factors are used to differentially weight */
  /*  the various types of transitions which can occur, as well as weight */
  /*  the relative value of transition costs and local costs */
  /* forming the local cost matrix */
  /* 'dynamic5:37' Local = 1 - Merit_array; */
  /* initialization for the formation of the transition cost matrix */
  /* 'dynamic5:40' Trans  = zeros(numcands, numcands, numframes); */
  b_Trans = Trans->size[0] * Trans->size[1] * Trans->size[2];
  Trans->size[0] = Pitch_array->size[0];
  Trans->size[1] = Pitch_array->size[0];
  Trans->size[2] = Pitch_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, b_Trans, (int32_T)sizeof
                    (real_T), &cd_emlrtRTEI);
  loop_ub = Pitch_array->size[0] * Pitch_array->size[0] * Pitch_array->size[1];
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    Trans->data[b_Trans] = 0.0;
  }

  /* the transition cost matrix is proportional to frequency differences */
  /* between successive candidates. */
  /* 'dynamic5:45' for i = 2:numframes */
  i = 0;
  while (i <= numframes - 1) {
    /* 'dynamic5:46' for j = 1:numcands */
    j = 1;
    while (j - 1 <= numcands) {
      /* 'dynamic5:47' for k = 1:numcands */
      k = 1;
      while (k - 1 <= numcands) {
        /* 'dynamic5:48' Trans(k,j,i)  = (abs(Pitch_array(j,i) - Pitch_array(k,i-1)))/ F0_min ; */
        b_Trans = Pitch_array->size[0];
        loop_ub = (j - 1) + 1;
        if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &wf_emlrtBCI, sp);
        }

        b_Trans = Pitch_array->size[1];
        loop_ub = (int32_T)(2.0 + (real_T)i);
        if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &vf_emlrtBCI, sp);
        }

        b_Trans = Pitch_array->size[0];
        loop_ub = (k - 1) + 1;
        if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &uf_emlrtBCI, sp);
        }

        b_Trans = Pitch_array->size[1];
        loop_ub = (int32_T)((2.0 + (real_T)i) - 1.0);
        if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &tf_emlrtBCI, sp);
        }

        b_Trans = Trans->size[0];
        if (!((k >= 1) && (k <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, b_Trans, &cg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[1];
        if (!((j >= 1) && (j <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b_Trans, &dg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, b_Trans, &eg_emlrtBCI, sp);
        }

        Trans->data[((k + Trans->size[0] * (j - 1)) + Trans->size[0] *
                     Trans->size[1] * (i + 1)) - 1] = muDoubleScalarAbs
          (Pitch_array->data[(j + Pitch_array->size[0] * (i + 1)) - 1] -
           Pitch_array->data[(k + Pitch_array->size[0] * i) - 1]) / 60.0;

        /* 'dynamic5:49' Trans(k,j,i) =  0.05*Trans(k,j,i) + Trans(k,j,i)^2; */
        b_Trans = Trans->size[0];
        if (!((k >= 1) && (k <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, b_Trans, &fg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[1];
        if (!((j >= 1) && (j <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b_Trans, &gg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, b_Trans, &hg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[0];
        if (!((k >= 1) && (k <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, b_Trans, &ig_emlrtBCI, sp);
        }

        b_Trans = Trans->size[1];
        if (!((j >= 1) && (j <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b_Trans, &jg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, b_Trans, &kg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[0];
        if (!((k >= 1) && (k <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, b_Trans, &lg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[1];
        if (!((j >= 1) && (j <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b_Trans, &mg_emlrtBCI, sp);
        }

        b_Trans = Trans->size[2];
        if (!((i + 2 >= 1) && (i + 2 <= b_Trans))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, b_Trans, &ng_emlrtBCI, sp);
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

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  Overal balance between Local and Transition costs */
  /* 'dynamic5:55' Trans = k1 * Trans; */
  b_Trans = Trans->size[0] * Trans->size[1] * Trans->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)Trans, b_Trans, (int32_T)sizeof
                    (real_T), &cd_emlrtRTEI);
  loop_ub = Trans->size[0];
  b_Trans = Trans->size[1];
  c_Trans = Trans->size[2];
  loop_ub = loop_ub * b_Trans * c_Trans;
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    Trans->data[b_Trans] *= k1;
  }

  emxInit_real_T(sp, &r36, 2, &cd_emlrtRTEI, true);

  /*  search the best path */
  /* 'dynamic5:58' Path = path1(Local, Trans); */
  b_Trans = r36->size[0] * r36->size[1];
  r36->size[0] = Merit_array->size[0];
  r36->size[1] = Merit_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r36, b_Trans, (int32_T)sizeof(real_T),
                    &cd_emlrtRTEI);
  loop_ub = Merit_array->size[0] * Merit_array->size[1];
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    r36->data[b_Trans] = 1.0 - Merit_array->data[b_Trans];
  }

  emxInit_real_T(sp, &Path, 2, &ed_emlrtRTEI, true);
  st.site = &kk_emlrtRSI;
  path1(&st, r36, Trans, Path);

  /*  Extract the final vocied F0 track which has the lowest cost */
  /*  At this point, VSpec_F0 is the spectral pitch track for voiced frames */
  /* 'dynamic5:62' FinPitch = zeros(1,numframes); */
  b_Trans = FinPitch->size[0] * FinPitch->size[1];
  FinPitch->size[0] = 1;
  FinPitch->size[1] = Pitch_array->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)FinPitch, b_Trans, (int32_T)sizeof
                    (real_T), &cd_emlrtRTEI);
  loop_ub = Pitch_array->size[1];
  emxFree_real_T(&r36);
  emxFree_real_T(&Trans);
  for (b_Trans = 0; b_Trans < loop_ub; b_Trans++) {
    FinPitch->data[b_Trans] = 0.0;
  }

  /* 'dynamic5:63' for n=1:numframes */
  n = 1;
  while (n - 1 <= numframes) {
    /* 'dynamic5:64' FinPitch(n) = Pitch_array(Path(n), n); */
    b_Trans = Pitch_array->size[0];
    loop_ub = Path->size[1];
    if (!((n >= 1) && (n <= loop_ub))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, loop_ub, &yf_emlrtBCI, sp);
    }

    d0 = Path->data[n - 1];
    if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
      emlrtIntegerCheckR2012b(d0, &wc_emlrtDCI, sp);
    }

    loop_ub = (int32_T)d0;
    if (!((loop_ub >= 1) && (loop_ub <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_Trans, &xf_emlrtBCI, sp);
    }

    b_Trans = Pitch_array->size[1];
    if (!((n >= 1) && (n <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, b_Trans, &ag_emlrtBCI, sp);
    }

    b_Trans = FinPitch->size[1];
    if (!((n >= 1) && (n <= b_Trans))) {
      emlrtDynamicBoundsCheckR2012b(n, 1, b_Trans, &bg_emlrtBCI, sp);
    }

    FinPitch->data[n - 1] = Pitch_array->data[(loop_ub + Pitch_array->size[0] *
      (n - 1)) - 1];
    n++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&Path);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (dynamic5.c) */
