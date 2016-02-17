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
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo ne_emlrtRTEI = { 1, 18, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtRTEInfo ue_emlrtRTEI = { 10, 1, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtRTEInfo ve_emlrtRTEI = { 11, 1, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtRTEInfo we_emlrtRTEI = { 12, 1, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtECInfo jc_emlrtECI = { 1, 44, 13, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtECInfo kc_emlrtECI = { 1, 36, 13, "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m" };

static emlrtBCInfo tq_emlrtBCI = { -1, -1, 43, 6, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo uq_emlrtBCI = { -1, -1, 68, 25, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo vq_emlrtBCI = { -1, -1, 68, 29, "chunk3", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo wq_emlrtBCI = { -1, -1, 63, 29, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo xq_emlrtBCI = { -1, -1, 63, 33, "chunk2", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo yq_emlrtBCI = { -1, -1, 59, 29, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo ar_emlrtBCI = { -1, -1, 59, 33, "chunk2", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo br_emlrtBCI = { -1, -1, 72, 19, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo cr_emlrtBCI = { -1, -1, 52, 25, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo dr_emlrtBCI = { -1, -1, 52, 29, "chunk1", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo er_emlrtBCI = { -1, -1, 35, 6, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo fr_emlrtBCI = { -1, -1, 39, 19, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo gr_emlrtBCI = { -1, -1, 26, 7, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo hr_emlrtBCI = { -1, -1, 30, 20, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo ir_emlrtBCI = { -1, -1, 23, 17, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo jr_emlrtBCI = { -1, -1, 18, 20, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo kr_emlrtBCI = { -1, -1, 110, 25, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo lr_emlrtBCI = { -1, -1, 110, 29, "chunk3", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo mr_emlrtBCI = { -1, -1, 105, 29, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo nr_emlrtBCI = { -1, -1, 105, 33, "chunk2", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo or_emlrtBCI = { -1, -1, 101, 29, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo pr_emlrtBCI = { -1, -1, 101, 33, "chunk2", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo qr_emlrtBCI = { -1, -1, 94, 25, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo rr_emlrtBCI = { -1, -1, 94, 29, "chunk1", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo sr_emlrtBCI = { -1, -1, 85, 21, "arr", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

static emlrtBCInfo tr_emlrtBCI = { -1, -1, 85, 25, "chunk1", "Smooth",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth.m", 0 };

/* Function Definitions */

/*
 * function [out] = Smooth(arr)
 */
void Smooth(const emlrtStack *sp, emxArray_real_T *arr)
{
  emxArray_real_T *chunk1;
  emxArray_real_T *chunk2;
  emxArray_real_T *chunk3;
  real_T chunk1_value;
  real_T chunk2_value;
  real_T chunk3_value;
  int32_T i60;
  int32_T pointer;
  int32_T i;
  emxArray_real_T *b_chunk3;
  emxArray_real_T *b_chunk2;
  emxArray_real_T *b_chunk1;
  int32_T ix;
  int32_T mtmp;
  int32_T itmp;
  int32_T i61;
  int32_T n;
  uint32_T len_tmp[3];
  int32_T m;
  uint32_T b_mtmp;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &chunk1, 2, &ue_emlrtRTEI, true);
  emxInit_real_T(sp, &chunk2, 2, &ve_emlrtRTEI, true);
  emxInit_real_T(sp, &chunk3, 2, &we_emlrtRTEI, true);

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
  i60 = chunk1->size[0] * chunk1->size[1];
  chunk1->size[0] = 0;
  chunk1->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)chunk1, i60, (int32_T)sizeof(real_T),
                    &ne_emlrtRTEI);

  /* 'Smooth:11' chunk2 = []; */
  i60 = chunk2->size[0] * chunk2->size[1];
  chunk2->size[0] = 0;
  chunk2->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)chunk2, i60, (int32_T)sizeof(real_T),
                    &ne_emlrtRTEI);

  /* 'Smooth:12' chunk3 = []; */
  i60 = chunk3->size[0] * chunk3->size[1];
  chunk3->size[0] = 0;
  chunk3->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)chunk3, i60, (int32_T)sizeof(real_T),
                    &ne_emlrtRTEI);

  /* 'Smooth:13' pointer = 0; */
  pointer = 0;

  /* 'Smooth:14' fixed_threshold = 10; */
  /*  10 frames */
  /*  percent_threshold = 0.01; % 1 percent */
  /* 'Smooth:16' for i=1:length(arr) */
  i60 = arr->size[1];
  i = 0;
  emxInit_real_T(sp, &b_chunk3, 2, &ne_emlrtRTEI, true);
  emxInit_real_T(sp, &b_chunk2, 2, &ne_emlrtRTEI, true);
  emxInit_real_T(sp, &b_chunk1, 2, &ne_emlrtRTEI, true);
  while (i <= i60 - 1) {
    /* 'Smooth:17' if pointer== 0 */
    if (pointer == 0) {
      /* 'Smooth:18' chunk1_value = arr(i); */
      ix = arr->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= ix))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &jr_emlrtBCI, sp);
      }

      chunk1_value = arr->data[i];

      /* 'Smooth:19' chunk1 = i; */
      ix = chunk1->size[0] * chunk1->size[1];
      chunk1->size[0] = 1;
      chunk1->size[1] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)chunk1, ix, (int32_T)sizeof
                        (real_T), &ne_emlrtRTEI);
      chunk1->data[0] = 1.0 + (real_T)i;

      /* 'Smooth:20' pointer = pointer + 1; */
      pointer = 1;
    } else if (pointer == 1) {
      /* 'Smooth:21' elseif pointer == 1 */
      /* 'Smooth:22' if isempty(chunk1) */
      if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
        /* 'Smooth:23' chunk1_value=arr(i); */
        ix = arr->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= ix))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &ir_emlrtBCI, sp);
        }

        chunk1_value = arr->data[i];

        /* 'Smooth:24' chunk1 = i; */
        ix = chunk1->size[0] * chunk1->size[1];
        chunk1->size[0] = 1;
        chunk1->size[1] = 1;
        emxEnsureCapacity(sp, (emxArray__common *)chunk1, ix, (int32_T)sizeof
                          (real_T), &ne_emlrtRTEI);
        chunk1->data[0] = 1.0 + (real_T)i;
      } else {
        /* 'Smooth:25' else */
        /* 'Smooth:26' if arr(i)==chunk1_value */
        ix = arr->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= ix))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &gr_emlrtBCI, sp);
        }

        if (arr->data[i] == chunk1_value) {
          /* 'Smooth:27' chunk1 = [chunk1 i]; */
          ix = b_chunk1->size[0] * b_chunk1->size[1];
          b_chunk1->size[0] = chunk1->size[0];
          b_chunk1->size[1] = chunk1->size[1] + 1;
          emxEnsureCapacity(sp, (emxArray__common *)b_chunk1, ix, (int32_T)
                            sizeof(real_T), &ne_emlrtRTEI);
          mtmp = chunk1->size[1];
          for (ix = 0; ix < mtmp; ix++) {
            itmp = chunk1->size[0];
            for (i61 = 0; i61 < itmp; i61++) {
              b_chunk1->data[i61 + b_chunk1->size[0] * ix] = chunk1->data[i61 +
                chunk1->size[0] * ix];
            }
          }

          b_chunk1->data[b_chunk1->size[0] * chunk1->size[1]] = 1.0 + (real_T)i;
          ix = chunk1->size[0] * chunk1->size[1];
          chunk1->size[0] = b_chunk1->size[0];
          chunk1->size[1] = b_chunk1->size[1];
          emxEnsureCapacity(sp, (emxArray__common *)chunk1, ix, (int32_T)sizeof
                            (real_T), &ne_emlrtRTEI);
          mtmp = b_chunk1->size[1];
          for (ix = 0; ix < mtmp; ix++) {
            itmp = b_chunk1->size[0];
            for (i61 = 0; i61 < itmp; i61++) {
              chunk1->data[i61 + chunk1->size[0] * ix] = b_chunk1->data[i61 +
                b_chunk1->size[0] * ix];
            }
          }
        } else {
          /* 'Smooth:28' else */
          /* 'Smooth:29' pointer = pointer +1; */
          pointer = 2;

          /* 'Smooth:30' chunk2_value = arr(i); */
          ix = arr->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= ix))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &hr_emlrtBCI, sp);
          }

          chunk2_value = arr->data[i];

          /* 'Smooth:31' chunk2 = i; */
          ix = chunk2->size[0] * chunk2->size[1];
          chunk2->size[0] = 1;
          chunk2->size[1] = 1;
          emxEnsureCapacity(sp, (emxArray__common *)chunk2, ix, (int32_T)sizeof
                            (real_T), &ne_emlrtRTEI);
          chunk2->data[0] = 1.0 + (real_T)i;
        }
      }
    } else if (pointer == 2) {
      /* 'Smooth:34' elseif pointer == 2 */
      /* 'Smooth:35' if arr(i)==chunk2_value */
      ix = arr->size[1];
      if (!((i + 1 >= 1) && (i + 1 <= ix))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &er_emlrtBCI, sp);
      }

      if (arr->data[i] == chunk2_value) {
        /* 'Smooth:36' chunk2 = [chunk2 i]; */
        ix = chunk2->size[0];
        if (1 != ix) {
          emlrtDimSizeEqCheckR2012b(1, ix, &kc_emlrtECI, sp);
        }

        ix = b_chunk2->size[0] * b_chunk2->size[1];
        b_chunk2->size[0] = chunk2->size[0];
        b_chunk2->size[1] = chunk2->size[1] + 1;
        emxEnsureCapacity(sp, (emxArray__common *)b_chunk2, ix, (int32_T)sizeof
                          (real_T), &ne_emlrtRTEI);
        mtmp = chunk2->size[1];
        for (ix = 0; ix < mtmp; ix++) {
          itmp = chunk2->size[0];
          for (i61 = 0; i61 < itmp; i61++) {
            b_chunk2->data[i61 + b_chunk2->size[0] * ix] = chunk2->data[i61 +
              chunk2->size[0] * ix];
          }
        }

        b_chunk2->data[b_chunk2->size[0] * chunk2->size[1]] = 1.0 + (real_T)i;
        ix = chunk2->size[0] * chunk2->size[1];
        chunk2->size[0] = b_chunk2->size[0];
        chunk2->size[1] = b_chunk2->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)chunk2, ix, (int32_T)sizeof
                          (real_T), &ne_emlrtRTEI);
        mtmp = b_chunk2->size[1];
        for (ix = 0; ix < mtmp; ix++) {
          itmp = b_chunk2->size[0];
          for (i61 = 0; i61 < itmp; i61++) {
            chunk2->data[i61 + chunk2->size[0] * ix] = b_chunk2->data[i61 +
              b_chunk2->size[0] * ix];
          }
        }
      } else {
        /* 'Smooth:37' else */
        /* 'Smooth:38' pointer = pointer +1; */
        pointer = 3;

        /* 'Smooth:39' chunk3_value = arr(i); */
        ix = arr->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= ix))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &fr_emlrtBCI, sp);
        }

        chunk3_value = arr->data[i];

        /* 'Smooth:40' chunk3 = i; */
        ix = chunk3->size[0] * chunk3->size[1];
        chunk3->size[0] = 1;
        chunk3->size[1] = 1;
        emxEnsureCapacity(sp, (emxArray__common *)chunk3, ix, (int32_T)sizeof
                          (real_T), &ne_emlrtRTEI);
        chunk3->data[0] = 1.0 + (real_T)i;
      }
    } else {
      if (pointer == 3) {
        /* 'Smooth:42' elseif pointer == 3 */
        /* 'Smooth:43' if arr(i)==chunk3_value */
        ix = arr->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= ix))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &tq_emlrtBCI, sp);
        }

        if (arr->data[i] == chunk3_value) {
          /* 'Smooth:44' chunk3 = [chunk3 i]; */
          ix = chunk3->size[0];
          if (1 != ix) {
            emlrtDimSizeEqCheckR2012b(1, ix, &jc_emlrtECI, sp);
          }

          ix = b_chunk3->size[0] * b_chunk3->size[1];
          b_chunk3->size[0] = chunk3->size[0];
          b_chunk3->size[1] = chunk3->size[1] + 1;
          emxEnsureCapacity(sp, (emxArray__common *)b_chunk3, ix, (int32_T)
                            sizeof(real_T), &ne_emlrtRTEI);
          mtmp = chunk3->size[1];
          for (ix = 0; ix < mtmp; ix++) {
            itmp = chunk3->size[0];
            for (i61 = 0; i61 < itmp; i61++) {
              b_chunk3->data[i61 + b_chunk3->size[0] * ix] = chunk3->data[i61 +
                chunk3->size[0] * ix];
            }
          }

          b_chunk3->data[b_chunk3->size[0] * chunk3->size[1]] = 1.0 + (real_T)i;
          ix = chunk3->size[0] * chunk3->size[1];
          chunk3->size[0] = b_chunk3->size[0];
          chunk3->size[1] = b_chunk3->size[1];
          emxEnsureCapacity(sp, (emxArray__common *)chunk3, ix, (int32_T)sizeof
                            (real_T), &ne_emlrtRTEI);
          mtmp = b_chunk3->size[1];
          for (ix = 0; ix < mtmp; ix++) {
            itmp = b_chunk3->size[0];
            for (i61 = 0; i61 < itmp; i61++) {
              chunk3->data[i61 + chunk3->size[0] * ix] = b_chunk3->data[i61 +
                b_chunk3->size[0] * ix];
            }
          }
        } else {
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
          if (mtmp <= 10) {
            /* 'Smooth:50' if idx == 1 */
            if (itmp == 1) {
              /* 'Smooth:51' for m=1:length(chunk1) */
              if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
                n = 0;
              } else {
                n = chunk1->size[1];
              }

              m = 0;
              while (m <= n - 1) {
                /* 'Smooth:52' arr(chunk1(m)) = chunk2_value; */
                ix = arr->size[1];
                i61 = chunk1->size[0] * chunk1->size[1];
                if (!((m + 1 >= 1) && (m + 1 <= i61))) {
                  emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &dr_emlrtBCI, sp);
                }

                i61 = (int32_T)chunk1->data[m];
                if (!((i61 >= 1) && (i61 <= ix))) {
                  emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &cr_emlrtBCI, sp);
                }

                arr->data[i61 - 1] = chunk2_value;
                m++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }
            } else if (itmp == 2) {
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
              if (itmp == 1) {
                /* 'Smooth:58' for m=1:length(chunk2) */
                if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
                  n = 0;
                } else {
                  n = chunk2->size[1];
                }

                m = 0;
                while (m <= n - 1) {
                  /* 'Smooth:59' arr(chunk2(m)) = chunk1_value; */
                  ix = arr->size[1];
                  i61 = chunk2->size[0] * chunk2->size[1];
                  if (!((m + 1 >= 1) && (m + 1 <= i61))) {
                    emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &ar_emlrtBCI,
                      sp);
                  }

                  i61 = (int32_T)chunk2->data[m];
                  if (!((i61 >= 1) && (i61 <= ix))) {
                    emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &yq_emlrtBCI, sp);
                  }

                  arr->data[i61 - 1] = chunk1_value;
                  m++;
                  if (*emlrtBreakCheckR2012bFlagVar != 0) {
                    emlrtBreakCheckR2012b(sp);
                  }
                }
              } else {
                if (itmp == 3) {
                  /* 'Smooth:61' elseif second_min_idx == 3 */
                  /* 'Smooth:62' for m=1:length(chunk2) */
                  if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
                    n = 0;
                  } else {
                    n = chunk2->size[1];
                  }

                  m = 0;
                  while (m <= n - 1) {
                    /* 'Smooth:63' arr(chunk2(m)) = chunk3_value; */
                    ix = arr->size[1];
                    i61 = chunk2->size[0] * chunk2->size[1];
                    if (!((m + 1 >= 1) && (m + 1 <= i61))) {
                      emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &xq_emlrtBCI,
                        sp);
                    }

                    i61 = (int32_T)chunk2->data[m];
                    if (!((i61 >= 1) && (i61 <= ix))) {
                      emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &wq_emlrtBCI, sp);
                    }

                    arr->data[i61 - 1] = chunk3_value;
                    m++;
                    if (*emlrtBreakCheckR2012bFlagVar != 0) {
                      emlrtBreakCheckR2012b(sp);
                    }
                  }
                }
              }
            } else {
              /* 'Smooth:66' elseif idx == 3 */
              /* 'Smooth:67' for m=1:length(chunk3) */
              if ((chunk3->size[0] == 0) || (chunk3->size[1] == 0)) {
                n = 0;
              } else {
                n = chunk3->size[1];
              }

              m = 0;
              while (m <= n - 1) {
                /* 'Smooth:68' arr(chunk3(m)) = chunk2_value; */
                ix = arr->size[1];
                i61 = chunk3->size[0] * chunk3->size[1];
                if (!((m + 1 >= 1) && (m + 1 <= i61))) {
                  emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &vq_emlrtBCI, sp);
                }

                i61 = (int32_T)chunk3->data[m];
                if (!((i61 >= 1) && (i61 <= ix))) {
                  emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &uq_emlrtBCI, sp);
                }

                arr->data[i61 - 1] = chunk2_value;
                m++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }
            }
          }

          /* 'Smooth:72' chunk1_value = arr(i); */
          ix = arr->size[1];
          if (!((i + 1 >= 1) && (i + 1 <= ix))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &br_emlrtBCI, sp);
          }

          chunk1_value = arr->data[i];

          /* 'Smooth:73' chunk2_value = 0; */
          chunk2_value = 0.0;

          /* 'Smooth:74' chunk3_value = 0; */
          chunk3_value = 0.0;

          /* 'Smooth:75' chunk1 = i; */
          ix = chunk1->size[0] * chunk1->size[1];
          chunk1->size[0] = 1;
          chunk1->size[1] = 1;
          emxEnsureCapacity(sp, (emxArray__common *)chunk1, ix, (int32_T)sizeof
                            (real_T), &ne_emlrtRTEI);
          chunk1->data[0] = 1.0 + (real_T)i;

          /* 'Smooth:76' chunk2 = []; */
          ix = chunk2->size[0] * chunk2->size[1];
          chunk2->size[0] = 0;
          chunk2->size[1] = 0;
          emxEnsureCapacity(sp, (emxArray__common *)chunk2, ix, (int32_T)sizeof
                            (real_T), &ne_emlrtRTEI);

          /* 'Smooth:77' chunk3 = []; */
          ix = chunk3->size[0] * chunk3->size[1];
          chunk3->size[0] = 0;
          chunk3->size[1] = 0;
          emxEnsureCapacity(sp, (emxArray__common *)chunk3, ix, (int32_T)sizeof
                            (real_T), &ne_emlrtRTEI);

          /* 'Smooth:78' pointer = 1; */
          pointer = 1;
        }
      }
    }

    /* 'Smooth:81' if i==length(arr) */
    if (1.0 + (real_T)i == arr->size[1]) {
      /* 'Smooth:82' if pointer == 2 */
      if (pointer == 2) {
        /* 'Smooth:83' if length(chunk1)<fixed_threshold */
        if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
          n = 0;
        } else {
          n = chunk1->size[1];
        }

        if (n < 10) {
          /* 'Smooth:84' for m=1:length(chunk1) */
          if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
            n = 0;
          } else {
            n = chunk1->size[1];
          }

          m = 0;
          while (m <= n - 1) {
            /* 'Smooth:85' arr(chunk1(m)) = chunk2_value; */
            ix = arr->size[1];
            i61 = chunk1->size[0] * chunk1->size[1];
            if (!((m + 1 >= 1) && (m + 1 <= i61))) {
              emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &tr_emlrtBCI, sp);
            }

            i61 = (int32_T)chunk1->data[m];
            if (!((i61 >= 1) && (i61 <= ix))) {
              emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &sr_emlrtBCI, sp);
            }

            arr->data[i61 - 1] = chunk2_value;
            m++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }
        }
      } else {
        if (pointer == 3) {
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
          if (mtmp <= 10) {
            /* 'Smooth:92' if idx == 1 */
            if (itmp == 1) {
              /* 'Smooth:93' for m=1:length(chunk1) */
              if ((chunk1->size[0] == 0) || (chunk1->size[1] == 0)) {
                n = 0;
              } else {
                n = chunk1->size[1];
              }

              m = 0;
              while (m <= n - 1) {
                /* 'Smooth:94' arr(chunk1(m)) = chunk2_value; */
                ix = arr->size[1];
                i61 = chunk1->size[0] * chunk1->size[1];
                if (!((m + 1 >= 1) && (m + 1 <= i61))) {
                  emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &rr_emlrtBCI, sp);
                }

                i61 = (int32_T)chunk1->data[m];
                if (!((i61 >= 1) && (i61 <= ix))) {
                  emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &qr_emlrtBCI, sp);
                }

                arr->data[i61 - 1] = chunk2_value;
                m++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }
            } else if (itmp == 2) {
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
              if (itmp == 1) {
                /* 'Smooth:100' for m=1:length(chunk2) */
                if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
                  n = 0;
                } else {
                  n = chunk2->size[1];
                }

                m = 0;
                while (m <= n - 1) {
                  /* 'Smooth:101' arr(chunk2(m)) = chunk1_value; */
                  ix = arr->size[1];
                  i61 = chunk2->size[0] * chunk2->size[1];
                  if (!((m + 1 >= 1) && (m + 1 <= i61))) {
                    emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &pr_emlrtBCI,
                      sp);
                  }

                  i61 = (int32_T)chunk2->data[m];
                  if (!((i61 >= 1) && (i61 <= ix))) {
                    emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &or_emlrtBCI, sp);
                  }

                  arr->data[i61 - 1] = chunk1_value;
                  m++;
                  if (*emlrtBreakCheckR2012bFlagVar != 0) {
                    emlrtBreakCheckR2012b(sp);
                  }
                }
              } else {
                if (itmp == 3) {
                  /* 'Smooth:103' elseif second_min_idx == 3 */
                  /* 'Smooth:104' for m=1:length(chunk2) */
                  if ((chunk2->size[0] == 0) || (chunk2->size[1] == 0)) {
                    n = 0;
                  } else {
                    n = chunk2->size[1];
                  }

                  m = 0;
                  while (m <= n - 1) {
                    /* 'Smooth:105' arr(chunk2(m)) = chunk3_value; */
                    ix = arr->size[1];
                    i61 = chunk2->size[0] * chunk2->size[1];
                    if (!((m + 1 >= 1) && (m + 1 <= i61))) {
                      emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &nr_emlrtBCI,
                        sp);
                    }

                    i61 = (int32_T)chunk2->data[m];
                    if (!((i61 >= 1) && (i61 <= ix))) {
                      emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &mr_emlrtBCI, sp);
                    }

                    arr->data[i61 - 1] = chunk3_value;
                    m++;
                    if (*emlrtBreakCheckR2012bFlagVar != 0) {
                      emlrtBreakCheckR2012b(sp);
                    }
                  }
                }
              }
            } else {
              /* 'Smooth:108' elseif idx == 3 */
              /* 'Smooth:109' for m=1:length(chunk3) */
              if ((chunk3->size[0] == 0) || (chunk3->size[1] == 0)) {
                n = 0;
              } else {
                n = chunk3->size[1];
              }

              m = 0;
              while (m <= n - 1) {
                /* 'Smooth:110' arr(chunk3(m)) = chunk2_value; */
                ix = arr->size[1];
                i61 = chunk3->size[0] * chunk3->size[1];
                if (!((m + 1 >= 1) && (m + 1 <= i61))) {
                  emlrtDynamicBoundsCheckR2012b(m + 1, 1, i61, &lr_emlrtBCI, sp);
                }

                i61 = (int32_T)chunk3->data[m];
                if (!((i61 >= 1) && (i61 <= ix))) {
                  emlrtDynamicBoundsCheckR2012b(i61, 1, ix, &kr_emlrtBCI, sp);
                }

                arr->data[i61 - 1] = chunk2_value;
                m++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(sp);
                }
              }
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

  /* 'Smooth:117' out = arr; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Smooth.c) */
