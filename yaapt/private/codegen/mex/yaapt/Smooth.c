/*
 * Smooth.c
 *
 * Code generation for function 'Smooth'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Smooth.h"
#include "yaapt_emxutil.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo ye_emlrtRTEI = { 1, 18, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtRTEInfo gf_emlrtRTEI = { 10, 1, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtRTEInfo hf_emlrtRTEI = { 11, 1, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtRTEInfo if_emlrtRTEI = { 12, 1, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtBCInfo sq_emlrtBCI = { -1, -1, 43, 6, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo tq_emlrtBCI = { -1, -1, 68, 25, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo uq_emlrtBCI = { -1, -1, 68, 29, "chunk3", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo vq_emlrtBCI = { -1, -1, 63, 29, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo wq_emlrtBCI = { -1, -1, 63, 33, "chunk2", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo xq_emlrtBCI = { -1, -1, 59, 29, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo yq_emlrtBCI = { -1, -1, 59, 33, "chunk2", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo ar_emlrtBCI = { -1, -1, 72, 19, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo br_emlrtBCI = { -1, -1, 52, 25, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo cr_emlrtBCI = { -1, -1, 52, 29, "chunk1", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo dr_emlrtBCI = { -1, -1, 35, 6, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo er_emlrtBCI = { -1, -1, 39, 19, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo fr_emlrtBCI = { -1, -1, 26, 7, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo gr_emlrtBCI = { -1, -1, 30, 20, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo hr_emlrtBCI = { -1, -1, 23, 17, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo ir_emlrtBCI = { -1, -1, 18, 20, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo jr_emlrtBCI = { -1, -1, 110, 25, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo kr_emlrtBCI = { -1, -1, 110, 29, "chunk3", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo lr_emlrtBCI = { -1, -1, 105, 29, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo mr_emlrtBCI = { -1, -1, 105, 33, "chunk2", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo nr_emlrtBCI = { -1, -1, 101, 29, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo or_emlrtBCI = { -1, -1, 101, 33, "chunk2", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo pr_emlrtBCI = { -1, -1, 94, 25, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo qr_emlrtBCI = { -1, -1, 94, 29, "chunk1", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo rr_emlrtBCI = { -1, -1, 85, 21, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo sr_emlrtBCI = { -1, -1, 85, 25, "chunk1", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

/* Function Definitions */

/*
 * function [out] = Smooth(arr, Prm)
 */
void Smooth(const emlrtStack *sp, emxArray_real_T *arr, real_T
            Prm_smooth_threshold)
{
  emxArray_real_T *chunk1;
  emxArray_real_T *chunk2;
  emxArray_real_T *chunk3;
  real_T chunk1_value;
  real_T chunk2_value;
  real_T chunk3_value;
  int32_T i64;
  int32_T pointer;
  int32_T i;
  emxArray_real_T *b_chunk3;
  emxArray_real_T *b_chunk2;
  emxArray_real_T *b_chunk1;
  int32_T i65;
  int32_T n;
  int32_T mtmp;
  int32_T m;
  int32_T itmp;
  uint32_T len_tmp[3];
  int32_T ix;
  uint32_T b_mtmp;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &chunk1, 2, &gf_emlrtRTEI, true);
  emxInit_real_T(sp, &chunk2, 2, &hf_emlrtRTEI, true);
  emxInit_real_T(sp, &chunk3, 2, &if_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 24U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 0);

  /*  Smooth frequency data by 3 chunks */
  /*  arr = frequency data */
  /*  out = data after smoothed */
  /*  3 chunks is one window, if the lengh of the middle chunk is below */
  /*  threshold it will be absorbed by the head or tail chunk. */
  /* 'Smooth:7' chunk1_value = 0; */
  chunk1_value = 0.0;

  /* 'Smooth:8' chunk2_value = 0; */
  chunk2_value = 0.0;

  /* 'Smooth:9' chunk3_value = 0; */
  chunk3_value = 0.0;

  /* 'Smooth:10' chunk1 = []; */
  i64 = chunk1->size[0] * chunk1->size[1];
  chunk1->size[0] = 0;
  chunk1->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)chunk1, i64, (int32_T)sizeof(real_T),
                    &ye_emlrtRTEI);

  /* 'Smooth:11' chunk2 = []; */
  i64 = chunk2->size[0] * chunk2->size[1];
  chunk2->size[0] = 0;
  chunk2->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)chunk2, i64, (int32_T)sizeof(real_T),
                    &ye_emlrtRTEI);

  /* 'Smooth:12' chunk3 = []; */
  i64 = chunk3->size[0] * chunk3->size[1];
  chunk3->size[0] = 0;
  chunk3->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)chunk3, i64, (int32_T)sizeof(real_T),
                    &ye_emlrtRTEI);

  /* 'Smooth:13' pointer = 0; */
  pointer = 0;

  /* 'Smooth:14' fixed_threshold = Prm.smooth_threshold; */
  /*  10 frames */
  /*  percent_threshold = 0.01; % 1 percent */
  /* 'Smooth:16' for i=1:length(arr) */
  i64 = arr->size[1];
  i = 0;
  emxInit_real_T(sp, &b_chunk3, 2, &ye_emlrtRTEI, true);
  emxInit_real_T(sp, &b_chunk2, 2, &ye_emlrtRTEI, true);
  emxInit_real_T(sp, &b_chunk1, 2, &ye_emlrtRTEI, true);
  while (i <= i64 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 0, 1);

    /* 'Smooth:17' if pointer== 0 */
    if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 0, pointer == 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 1);

      /* 'Smooth:18' chunk1_value = arr(i); */
      i65 = arr->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i65))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i65, &ir_emlrtBCI, sp);
      }

      chunk1_value = arr->data[i];

      /* 'Smooth:19' chunk1 = i; */
      i65 = chunk1->size[0] * chunk1->size[1];
      chunk1->size[0] = 1;
      chunk1->size[1] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)chunk1, i65, (int32_T)sizeof
                        (real_T), &ye_emlrtRTEI);
      chunk1->data[0] = 1.0 + (real_T)i;

      /* 'Smooth:20' pointer = pointer + 1; */
      pointer = 1;
    } else if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 1, pointer == 1)) {
      /* 'Smooth:21' elseif pointer == 1 */
      /* 'Smooth:22' if isempty(chunk1) */
      if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 2, (chunk1->size[0] == 0) ||
                     (chunk1->size[1] == 0))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 2);

        /* 'Smooth:23' chunk1_value=arr(i); */
        i65 = arr->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i65))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i65, &hr_emlrtBCI, sp);
        }

        chunk1_value = arr->data[i];

        /* 'Smooth:24' chunk1 = i; */
        i65 = chunk1->size[0] * chunk1->size[1];
        chunk1->size[0] = 1;
        chunk1->size[1] = 1;
        emxEnsureCapacity(sp, (emxArray__common *)chunk1, i65, (int32_T)sizeof
                          (real_T), &ye_emlrtRTEI);
        chunk1->data[0] = 1.0 + (real_T)i;
      } else {
        /* 'Smooth:25' else */
        /* 'Smooth:26' if arr(i)==chunk1_value */
        i65 = arr->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i65))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i65, &fr_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 3, arr->data[i] ==
                       chunk1_value)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 3);

          /* 'Smooth:27' chunk1 = [chunk1 i]; */
          mtmp = chunk1->size[1];
          i65 = b_chunk1->size[0] * b_chunk1->size[1];
          b_chunk1->size[0] = 1;
          b_chunk1->size[1] = mtmp + 1;
          emxEnsureCapacity(sp, (emxArray__common *)b_chunk1, i65, (int32_T)
                            sizeof(real_T), &ye_emlrtRTEI);
          for (i65 = 0; i65 < mtmp; i65++) {
            b_chunk1->data[b_chunk1->size[0] * i65] = chunk1->data[i65];
          }

          b_chunk1->data[b_chunk1->size[0] * mtmp] = 1.0 + (real_T)i;
          i65 = chunk1->size[0] * chunk1->size[1];
          chunk1->size[0] = b_chunk1->size[0];
          chunk1->size[1] = b_chunk1->size[1];
          emxEnsureCapacity(sp, (emxArray__common *)chunk1, i65, (int32_T)sizeof
                            (real_T), &ye_emlrtRTEI);
          mtmp = b_chunk1->size[1];
          for (i65 = 0; i65 < mtmp; i65++) {
            itmp = b_chunk1->size[0];
            for (ix = 0; ix < itmp; ix++) {
              chunk1->data[ix + chunk1->size[0] * i65] = b_chunk1->data[ix +
                b_chunk1->size[0] * i65];
            }
          }
        } else {
          covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 4);

          /* 'Smooth:28' else */
          /* 'Smooth:29' pointer = pointer +1; */
          pointer = 2;

          /* 'Smooth:30' chunk2_value = arr(i); */
          i65 = arr->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= i65))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i65, &gr_emlrtBCI, sp);
          }

          chunk2_value = arr->data[i];

          /* 'Smooth:31' chunk2 = i; */
          i65 = chunk2->size[0] * chunk2->size[1];
          chunk2->size[0] = 1;
          chunk2->size[1] = 1;
          emxEnsureCapacity(sp, (emxArray__common *)chunk2, i65, (int32_T)sizeof
                            (real_T), &ye_emlrtRTEI);
          chunk2->data[0] = 1.0 + (real_T)i;
        }
      }
    } else if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 4, pointer == 2)) {
      /* 'Smooth:34' elseif pointer == 2 */
      /* 'Smooth:35' if arr(i)==chunk2_value */
      i65 = arr->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= i65))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i65, &dr_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 5, arr->data[i] ==
                     chunk2_value)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 5);

        /* 'Smooth:36' chunk2 = [chunk2 i]; */
        if (!((chunk2->size[0] == 0) || (chunk2->size[1] == 0))) {
          mtmp = chunk2->size[1];
        } else {
          mtmp = 0;
        }

        i65 = b_chunk2->size[0] * b_chunk2->size[1];
        b_chunk2->size[0] = 1;
        b_chunk2->size[1] = mtmp + 1;
        emxEnsureCapacity(sp, (emxArray__common *)b_chunk2, i65, (int32_T)sizeof
                          (real_T), &ye_emlrtRTEI);
        for (i65 = 0; i65 < mtmp; i65++) {
          b_chunk2->data[b_chunk2->size[0] * i65] = chunk2->data[i65];
        }

        b_chunk2->data[b_chunk2->size[0] * mtmp] = 1.0 + (real_T)i;
        i65 = chunk2->size[0] * chunk2->size[1];
        chunk2->size[0] = b_chunk2->size[0];
        chunk2->size[1] = b_chunk2->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)chunk2, i65, (int32_T)sizeof
                          (real_T), &ye_emlrtRTEI);
        mtmp = b_chunk2->size[1];
        for (i65 = 0; i65 < mtmp; i65++) {
          itmp = b_chunk2->size[0];
          for (ix = 0; ix < itmp; ix++) {
            chunk2->data[ix + chunk2->size[0] * i65] = b_chunk2->data[ix +
              b_chunk2->size[0] * i65];
          }
        }
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 6);

        /* 'Smooth:37' else */
        /* 'Smooth:38' pointer = pointer +1; */
        pointer = 3;

        /* 'Smooth:39' chunk3_value = arr(i); */
        i65 = arr->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i65))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i65, &er_emlrtBCI, sp);
        }

        chunk3_value = arr->data[i];

        /* 'Smooth:40' chunk3 = i; */
        i65 = chunk3->size[0] * chunk3->size[1];
        chunk3->size[0] = 1;
        chunk3->size[1] = 1;
        emxEnsureCapacity(sp, (emxArray__common *)chunk3, i65, (int32_T)sizeof
                          (real_T), &ye_emlrtRTEI);
        chunk3->data[0] = 1.0 + (real_T)i;
      }
    } else {
      if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 6, pointer == 3)) {
        /* 'Smooth:42' elseif pointer == 3 */
        /* 'Smooth:43' if arr(i)==chunk3_value */
        i65 = arr->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i65))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i65, &sq_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 7, arr->data[i] ==
                       chunk3_value)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 7);

          /* 'Smooth:44' chunk3 = [chunk3 i]; */
          if (!((chunk3->size[0] == 0) || (chunk3->size[1] == 0))) {
            mtmp = chunk3->size[1];
          } else {
            mtmp = 0;
          }

          i65 = b_chunk3->size[0] * b_chunk3->size[1];
          b_chunk3->size[0] = 1;
          b_chunk3->size[1] = mtmp + 1;
          emxEnsureCapacity(sp, (emxArray__common *)b_chunk3, i65, (int32_T)
                            sizeof(real_T), &ye_emlrtRTEI);
          for (i65 = 0; i65 < mtmp; i65++) {
            b_chunk3->data[b_chunk3->size[0] * i65] = chunk3->data[i65];
          }

          b_chunk3->data[b_chunk3->size[0] * mtmp] = 1.0 + (real_T)i;
          i65 = chunk3->size[0] * chunk3->size[1];
          chunk3->size[0] = b_chunk3->size[0];
          chunk3->size[1] = b_chunk3->size[1];
          emxEnsureCapacity(sp, (emxArray__common *)chunk3, i65, (int32_T)sizeof
                            (real_T), &ye_emlrtRTEI);
          mtmp = b_chunk3->size[1];
          for (i65 = 0; i65 < mtmp; i65++) {
            itmp = b_chunk3->size[0];
            for (ix = 0; ix < itmp; ix++) {
              chunk3->data[ix + chunk3->size[0] * i65] = b_chunk3->data[ix +
                b_chunk3->size[0] * i65];
            }
          }
        } else {
          covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 8);

          /* 'Smooth:45' else */
          /*  new chunk found */
          /* 'Smooth:47' len_tmp=[length(chunk1), length(chunk2), length(chunk3)]; */
          if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
            n = 0;
          } else {
            n = chunk1->size[1];
          }

          if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
            mtmp = 0;
          } else {
            mtmp = chunk2->size[1];
          }

          if ((chunk3->size[0] == 0) || (chunk3->size[1] == 0)) {
            itmp = 0;
          } else {
            itmp = chunk3->size[1];
          }

          len_tmp[0] = (uint32_T)n;
          len_tmp[1] = (uint32_T)mtmp;
          len_tmp[2] = (uint32_T)itmp;

          /* 'Smooth:48' [min_len,idx] = min(len_tmp); */
          mtmp = n;
          itmp = 1;
          for (ix = 2; ix < 4; ix++) {
            if ((int32_T)len_tmp[ix - 1] < mtmp) {
              mtmp = (int32_T)len_tmp[ix - 1];
              itmp = ix;
            }
          }

          /* 'Smooth:49' if(min_len<=fixed_threshold) */
          if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 8, mtmp <=
                         Prm_smooth_threshold)) {
            /* 'Smooth:50' if idx == 1 */
            if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 9, itmp == 1)) {
              /* 'Smooth:51' for m=1:length(chunk1) */
              if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
                n = 0;
              } else {
                n = chunk1->size[1];
              }

              m = 0;
              while (m <= n - 1) {
                covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 1, 1);
                covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 9);

                /* 'Smooth:52' arr(chunk1(m)) = chunk2_value; */
                i65 = arr->size[1];
                ix = chunk1->size[0] * chunk1->size[1];
                if (!((m + 1 >= 1) && (m + 1 <= ix))) {
                  emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &cr_emlrtBCI, sp);
                }

                ix = (int32_T)chunk1->data[m];
                if (!((ix >= 1) && (ix <= i65))) {
                  emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &br_emlrtBCI, sp);
                }

                arr->data[ix - 1] = chunk2_value;
                m++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }

              covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 1, 0);
            } else if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 10, itmp == 2))
            {
              covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 10);

              /* 'Smooth:54' elseif idx == 2 */
              /* 'Smooth:55' len_tmp(idx) = max(len_tmp)+100; */
              mtmp = n;
              for (ix = 1; ix + 1 < 4; ix++) {
                if ((int32_T)len_tmp[ix] > mtmp) {
                  mtmp = (int32_T)len_tmp[ix];
                }
              }

              len_tmp[1] = mtmp + 100U;

              /* 'Smooth:56' [~,second_min_idx] = min(len_tmp); */
              b_mtmp = (uint32_T)n;
              itmp = 1;
              for (ix = 2; ix < 4; ix++) {
                if (len_tmp[ix - 1] < b_mtmp) {
                  b_mtmp = len_tmp[ix - 1];
                  itmp = ix;
                }
              }

              /* 'Smooth:56' ~ */
              /* 'Smooth:57' if second_min_idx == 1 */
              if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 11, itmp == 1)) {
                /* 'Smooth:58' for m=1:length(chunk2) */
                if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
                  n = 0;
                } else {
                  n = chunk2->size[1];
                }

                m = 0;
                while (m <= n - 1) {
                  covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 2, 1);
                  covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 11);

                  /* 'Smooth:59' arr(chunk2(m)) = chunk1_value; */
                  i65 = arr->size[1];
                  ix = chunk2->size[0] * chunk2->size[1];
                  if (!((m + 1 >= 1) && (m + 1 <= ix))) {
                    emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &yq_emlrtBCI, sp);
                  }

                  ix = (int32_T)chunk2->data[m];
                  if (!((ix >= 1) && (ix <= i65))) {
                    emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &xq_emlrtBCI, sp);
                  }

                  arr->data[ix - 1] = chunk1_value;
                  m++;
                  if (*emlrtBreakCheckR2012bFlagVar != 0) {
                    emlrtBreakCheckR2012b(sp);
                  }
                }

                covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 2, 0);
              } else {
                if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 12, itmp == 3))
                {
                  /* 'Smooth:61' elseif second_min_idx == 3 */
                  /* 'Smooth:62' for m=1:length(chunk2) */
                  if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
                    n = 0;
                  } else {
                    n = chunk2->size[1];
                  }

                  m = 0;
                  while (m <= n - 1) {
                    covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 3, 1);
                    covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 12);

                    /* 'Smooth:63' arr(chunk2(m)) = chunk3_value; */
                    i65 = arr->size[1];
                    ix = chunk2->size[0] * chunk2->size[1];
                    if (!((m + 1 >= 1) && (m + 1 <= ix))) {
                      emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &wq_emlrtBCI,
                        sp);
                    }

                    ix = (int32_T)chunk2->data[m];
                    if (!((ix >= 1) && (ix <= i65))) {
                      emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &vq_emlrtBCI, sp);
                    }

                    arr->data[ix - 1] = chunk3_value;
                    m++;
                    if (*emlrtBreakCheckR2012bFlagVar != 0) {
                      emlrtBreakCheckR2012b(sp);
                    }
                  }

                  covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 3, 0);
                }
              }
            } else {
              covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 13, true);

              /* 'Smooth:66' elseif idx == 3 */
              /* 'Smooth:67' for m=1:length(chunk3) */
              if ((chunk3->size[0] == 0) || (chunk3->size[1] == 0)) {
                n = 0;
              } else {
                n = chunk3->size[1];
              }

              m = 0;
              while (m <= n - 1) {
                covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 4, 1);
                covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 13);

                /* 'Smooth:68' arr(chunk3(m)) = chunk2_value; */
                i65 = arr->size[1];
                ix = chunk3->size[0] * chunk3->size[1];
                if (!((m + 1 >= 1) && (m + 1 <= ix))) {
                  emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &uq_emlrtBCI, sp);
                }

                ix = (int32_T)chunk3->data[m];
                if (!((ix >= 1) && (ix <= i65))) {
                  emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &tq_emlrtBCI, sp);
                }

                arr->data[ix - 1] = chunk2_value;
                m++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }

              covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 4, 0);
            }
          }

          covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 14);

          /* 'Smooth:72' chunk1_value = arr(i); */
          i65 = arr->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= i65))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i65, &ar_emlrtBCI, sp);
          }

          chunk1_value = arr->data[i];

          /* 'Smooth:73' chunk2_value = 0; */
          chunk2_value = 0.0;

          /* 'Smooth:74' chunk3_value = 0; */
          chunk3_value = 0.0;

          /* 'Smooth:75' chunk1 = i; */
          i65 = chunk1->size[0] * chunk1->size[1];
          chunk1->size[0] = 1;
          chunk1->size[1] = 1;
          emxEnsureCapacity(sp, (emxArray__common *)chunk1, i65, (int32_T)sizeof
                            (real_T), &ye_emlrtRTEI);
          chunk1->data[0] = 1.0 + (real_T)i;

          /* 'Smooth:76' chunk2 = []; */
          i65 = chunk2->size[0] * chunk2->size[1];
          chunk2->size[0] = 0;
          chunk2->size[1] = 0;
          emxEnsureCapacity(sp, (emxArray__common *)chunk2, i65, (int32_T)sizeof
                            (real_T), &ye_emlrtRTEI);

          /* 'Smooth:77' chunk3 = []; */
          i65 = chunk3->size[0] * chunk3->size[1];
          chunk3->size[0] = 0;
          chunk3->size[1] = 0;
          emxEnsureCapacity(sp, (emxArray__common *)chunk3, i65, (int32_T)sizeof
                            (real_T), &ye_emlrtRTEI);

          /* 'Smooth:78' pointer = 1; */
          pointer = 1;
        }
      }
    }

    /* 'Smooth:81' if i==length(arr) */
    if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 14, 1.0 + (real_T)i ==
                   arr->size[1])) {
      /* 'Smooth:82' if pointer == 2 */
      if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 15, pointer == 2)) {
        /* 'Smooth:83' if length(chunk1)<fixed_threshold */
        if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
          n = 0;
        } else {
          n = chunk1->size[1];
        }

        if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 16, n <
                       Prm_smooth_threshold)) {
          /* 'Smooth:84' for m=1:length(chunk1) */
          if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
            n = 0;
          } else {
            n = chunk1->size[1];
          }

          m = 0;
          while (m <= n - 1) {
            covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 5, 1);
            covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 15);

            /* 'Smooth:85' arr(chunk1(m)) = chunk2_value; */
            i65 = arr->size[1];
            ix = chunk1->size[0] * chunk1->size[1];
            if (!((m + 1 >= 1) && (m + 1 <= ix))) {
              emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &sr_emlrtBCI, sp);
            }

            ix = (int32_T)chunk1->data[m];
            if (!((ix >= 1) && (ix <= i65))) {
              emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &rr_emlrtBCI, sp);
            }

            arr->data[ix - 1] = chunk2_value;
            m++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }

          covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 5, 0);
        }
      } else {
        if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 17, pointer == 3)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 16);

          /* 'Smooth:88' elseif pointer == 3 */
          /* 'Smooth:89' len_tmp=[length(chunk1), length(chunk2), length(chunk3)]; */
          if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
            n = 0;
          } else {
            n = chunk1->size[1];
          }

          if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
            mtmp = 0;
          } else {
            mtmp = chunk2->size[1];
          }

          if ((chunk3->size[0] == 0) || (chunk3->size[1] == 0)) {
            itmp = 0;
          } else {
            itmp = chunk3->size[1];
          }

          len_tmp[0] = (uint32_T)n;
          len_tmp[1] = (uint32_T)mtmp;
          len_tmp[2] = (uint32_T)itmp;

          /* 'Smooth:90' [min_len,idx] = min(len_tmp); */
          mtmp = n;
          itmp = 1;
          for (ix = 2; ix < 4; ix++) {
            if ((int32_T)len_tmp[ix - 1] < mtmp) {
              mtmp = (int32_T)len_tmp[ix - 1];
              itmp = ix;
            }
          }

          /* 'Smooth:91' if(min_len<=fixed_threshold) */
          if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 18, mtmp <=
                         Prm_smooth_threshold)) {
            /* 'Smooth:92' if idx == 1 */
            if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 19, itmp == 1)) {
              /* 'Smooth:93' for m=1:length(chunk1) */
              if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
                n = 0;
              } else {
                n = chunk1->size[1];
              }

              m = 0;
              while (m <= n - 1) {
                covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 6, 1);
                covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 17);

                /* 'Smooth:94' arr(chunk1(m)) = chunk2_value; */
                i65 = arr->size[1];
                ix = chunk1->size[0] * chunk1->size[1];
                if (!((m + 1 >= 1) && (m + 1 <= ix))) {
                  emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &qr_emlrtBCI, sp);
                }

                ix = (int32_T)chunk1->data[m];
                if (!((ix >= 1) && (ix <= i65))) {
                  emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &pr_emlrtBCI, sp);
                }

                arr->data[ix - 1] = chunk2_value;
                m++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }

              covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 6, 0);
            } else if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 20, itmp == 2))
            {
              covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 18);

              /* 'Smooth:96' elseif idx == 2 */
              /* 'Smooth:97' len_tmp(idx) = max(len_tmp)+100; */
              mtmp = n;
              for (ix = 1; ix + 1 < 4; ix++) {
                if ((int32_T)len_tmp[ix] > mtmp) {
                  mtmp = (int32_T)len_tmp[ix];
                }
              }

              len_tmp[1] = mtmp + 100U;

              /* 'Smooth:98' [~,second_min_idx] = min(len_tmp); */
              b_mtmp = (uint32_T)n;
              itmp = 1;
              for (ix = 2; ix < 4; ix++) {
                if (len_tmp[ix - 1] < b_mtmp) {
                  b_mtmp = len_tmp[ix - 1];
                  itmp = ix;
                }
              }

              /* 'Smooth:98' ~ */
              /* 'Smooth:99' if second_min_idx == 1 */
              if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 21, itmp == 1)) {
                /* 'Smooth:100' for m=1:length(chunk2) */
                if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
                  n = 0;
                } else {
                  n = chunk2->size[1];
                }

                m = 0;
                while (m <= n - 1) {
                  covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 7, 1);
                  covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 19);

                  /* 'Smooth:101' arr(chunk2(m)) = chunk1_value; */
                  i65 = arr->size[1];
                  ix = chunk2->size[0] * chunk2->size[1];
                  if (!((m + 1 >= 1) && (m + 1 <= ix))) {
                    emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &or_emlrtBCI, sp);
                  }

                  ix = (int32_T)chunk2->data[m];
                  if (!((ix >= 1) && (ix <= i65))) {
                    emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &nr_emlrtBCI, sp);
                  }

                  arr->data[ix - 1] = chunk1_value;
                  m++;
                  if (*emlrtBreakCheckR2012bFlagVar != 0) {
                    emlrtBreakCheckR2012b(sp);
                  }
                }

                covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 7, 0);
              } else {
                if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 22, itmp == 3))
                {
                  /* 'Smooth:103' elseif second_min_idx == 3 */
                  /* 'Smooth:104' for m=1:length(chunk2) */
                  if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
                    n = 0;
                  } else {
                    n = chunk2->size[1];
                  }

                  m = 0;
                  while (m <= n - 1) {
                    covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 8, 1);
                    covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 20);

                    /* 'Smooth:105' arr(chunk2(m)) = chunk3_value; */
                    i65 = arr->size[1];
                    ix = chunk2->size[0] * chunk2->size[1];
                    if (!((m + 1 >= 1) && (m + 1 <= ix))) {
                      emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &mr_emlrtBCI,
                        sp);
                    }

                    ix = (int32_T)chunk2->data[m];
                    if (!((ix >= 1) && (ix <= i65))) {
                      emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &lr_emlrtBCI, sp);
                    }

                    arr->data[ix - 1] = chunk3_value;
                    m++;
                    if (*emlrtBreakCheckR2012bFlagVar != 0) {
                      emlrtBreakCheckR2012b(sp);
                    }
                  }

                  covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 8, 0);
                }
              }
            } else {
              covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 23, true);

              /* 'Smooth:108' elseif idx == 3 */
              /* 'Smooth:109' for m=1:length(chunk3) */
              if ((chunk3->size[0] == 0) || (chunk3->size[1] == 0)) {
                n = 0;
              } else {
                n = chunk3->size[1];
              }

              m = 0;
              while (m <= n - 1) {
                covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 9, 1);
                covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 21);

                /* 'Smooth:110' arr(chunk3(m)) = chunk2_value; */
                i65 = arr->size[1];
                ix = chunk3->size[0] * chunk3->size[1];
                if (!((m + 1 >= 1) && (m + 1 <= ix))) {
                  emlrtDynamicBoundsCheckR2012b(m + 1, 1, ix, &kr_emlrtBCI, sp);
                }

                ix = (int32_T)chunk3->data[m];
                if (!((ix >= 1) && (ix <= i65))) {
                  emlrtDynamicBoundsCheckR2012b(ix, 1, i65, &jr_emlrtBCI, sp);
                }

                arr->data[ix - 1] = chunk2_value;
                m++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }

              covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 9, 0);
            }
          }
        }
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_chunk1);
  emxFree_real_T(&b_chunk2);
  emxFree_real_T(&b_chunk3);
  emxFree_real_T(&chunk3);
  emxFree_real_T(&chunk2);
  emxFree_real_T(&chunk1);
  covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 22);

  /* 'Smooth:117' out = arr; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Smooth.c) */
