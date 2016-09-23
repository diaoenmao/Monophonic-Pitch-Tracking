/*
 * yaapt_initialize.c
 *
 * Code generation for function 'yaapt_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_initialize.h"
#include "_coder_yaapt_mex.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Declarations */
static void yaapt_once(void);

/* Function Definitions */
static void yaapt_once(void)
{
  int32_T cond_starts_3_0[5] = { 3500, 3514, 3530, 3542, 3556 };

  int32_T cond_ends_3_0[5] = { 3510, 3526, 3539, 3553, 3560 };

  int32_T postfix_exprs_3_0[11] = { 0, 1, -1, -2, 2, -1, -2, 3, -2, 4, -2 };

  int32_T cond_starts_3_1[2] = { 4417, 4427 };

  int32_T cond_ends_3_1[2] = { 4424, 4434 };

  int32_T postfix_exprs_3_1[3] = { 0, 1, -3 };

  int32_T cond_starts_5_0[2] = { 3451, 3462 };

  int32_T cond_ends_5_0[2] = { 3459, 3470 };

  int32_T postfix_exprs_5_0[3] = { 0, 1, -2 };

  int32_T cond_starts_7_0[2] = { 3662, 3681 };

  int32_T cond_ends_7_0[2] = { 3677, 3690 };

  int32_T postfix_exprs_7_0[3] = { 0, 1, -2 };

  int32_T cond_starts_7_1[1] = { 4024 };

  int32_T cond_ends_7_1[1] = { 4033 };

  int32_T postfix_exprs_7_1[2] = { 0, -1 };

  int32_T cond_starts_7_2[1] = { 4128 };

  int32_T cond_ends_7_2[1] = { 4145 };

  int32_T postfix_exprs_7_2[2] = { 0, -1 };

  int32_T cond_starts_8_0[1] = { 1546 };

  int32_T cond_ends_8_0[1] = { 1554 };

  int32_T postfix_exprs_8_0[2] = { 0, -1 };

  int32_T cond_starts_11_0[1] = { 2258 };

  int32_T cond_ends_11_0[1] = { 2268 };

  int32_T postfix_exprs_11_0[2] = { 0, -1 };

  int32_T cond_starts_11_1[1] = { 8896 };

  int32_T cond_ends_11_1[1] = { 8901 };

  int32_T postfix_exprs_11_1[2] = { 0, -1 };

  int32_T cond_starts_12_0[2] = { 3686, 3704 };

  int32_T cond_ends_12_0[2] = { 3699, 3729 };

  int32_T postfix_exprs_12_0[3] = { 0, 1, -3 };

  int32_T cond_starts_18_0[2] = { 3177, 3196 };

  int32_T cond_ends_18_0[2] = { 3190, 3213 };

  int32_T postfix_exprs_18_0[3] = { 0, 1, -3 };

  int32_T cond_starts_20_0[2] = { 3011, 3031 };

  int32_T cond_ends_20_0[2] = { 3025, 3047 };

  int32_T postfix_exprs_20_0[3] = { 0, 1, -3 };

  int32_T cond_starts_20_1[4] = { 3241, 3258, 3278, 3294 };

  int32_T cond_ends_20_1[4] = { 3254, 3272, 3290, 3309 };

  int32_T postfix_exprs_20_1[7] = { 0, 1, -3, 2, 3, -3, -2 };

  int32_T cond_starts_20_2[2] = { 3513, 3534 };

  int32_T cond_ends_20_2[2] = { 3528, 3551 };

  int32_T postfix_exprs_20_2[3] = { 0, 1, -3 };

  int32_T cond_starts_21_0[2] = { 586, 603 };

  int32_T cond_ends_21_0[2] = { 599, 617 };

  int32_T postfix_exprs_21_0[3] = { 0, 1, -3 };

  int32_T cond_starts_21_1[2] = { 5297, 5315 };

  int32_T cond_ends_21_1[2] = { 5311, 5328 };

  int32_T postfix_exprs_21_1[3] = { 0, 1, -3 };

  int32_T cond_starts_23_0[2] = { 1891, 1913 };

  int32_T cond_ends_23_0[2] = { 1909, 1934 };

  int32_T postfix_exprs_23_0[3] = { 0, 1, -3 };

  int32_T cond_starts_23_1[2] = { 2224, 2248 };

  int32_T cond_ends_23_1[2] = { 2244, 2269 };

  int32_T postfix_exprs_23_1[3] = { 0, 1, -3 };

  int32_T cond_starts_23_2[3] = { 2287, 2345, 2381 };

  int32_T cond_ends_23_2[3] = { 2343, 2378, 2417 };

  int32_T postfix_exprs_23_2[5] = { 0, 1, -2, 2, -3 };

  int32_T cond_starts_23_3[2] = { 2657, 2681 };

  int32_T cond_ends_23_3[2] = { 2677, 2702 };

  int32_T postfix_exprs_23_3[3] = { 0, 1, -3 };

  int32_T cond_starts_23_4[3] = { 2720, 2779, 2815 };

  int32_T cond_ends_23_4[3] = { 2777, 2812, 2851 };

  int32_T postfix_exprs_23_4[5] = { 0, 1, -2, 2, -3 };

  int32_T cond_starts_23_5[3] = { 3249, 3307, 3343 };

  int32_T cond_ends_23_5[3] = { 3305, 3340, 3379 };

  int32_T postfix_exprs_23_5[5] = { 0, 1, -2, 2, -3 };

  int32_T cond_starts_23_6[3] = { 3712, 3770, 3806 };

  int32_T cond_ends_23_6[3] = { 3768, 3803, 3842 };

  int32_T postfix_exprs_23_6[5] = { 0, 1, -2, 2, -3 };

  int32_T cond_starts_23_7[3] = { 4230, 4308, 4344 };

  int32_T cond_ends_23_7[3] = { 4306, 4341, 4380 };

  int32_T postfix_exprs_23_7[5] = { 0, 1, -2, 2, -3 };

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m",
                  0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0, 0, "yaapt", 0, -1, 8806);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 1, 2550, -1, 7656);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 0, 2445, -1, 2479);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0, 0, 2429, 2440, -1, 2484);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Preprocess.m",
                  1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1, 0, "Preprocess", 0, -1, 402);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 0, 231, -1, 397);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m",
                  2, 1, 4, 1, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2, 0, "nonlinear", 0, -1, 2641);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2, 3, 1770, -1, 2636);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2, 2, 1717, -1, 1731);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2, 1, 1679, -1, 1706);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2, 0, 1465, -1, 1655);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 2, 0, 1658, 1674, 1708, 1736);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m",
                  3, 1, 10, 9, 0, 0, 0, 0, 0, 7, 2);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 3, 0, "Myfir1", 0, -1, 5511);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 9, 5447, -1, 5495);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 8, 5405, -1, 5423);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 7, 5316, -1, 5322);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 6, 5202, -1, 5216);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 5, 4968, -1, 5158);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 4, 4619, -1, 4640);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 3, 4054, -1, 4206);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 2, 3985, -1, 3999);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 1, 3880, -1, 3925);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 0, 2580, -1, 3407);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 3, 0, 3497, 3560, -1, 3615);
  covrtIfInit(&emlrtCoverageInstance, 3, 1, 3965, 3980, -1, 4052);
  covrtIfInit(&emlrtCoverageInstance, 3, 2, 4414, 4434, -1, 4509);
  covrtIfInit(&emlrtCoverageInstance, 3, 3, 4511, 4521, -1, 4646);
  covrtIfInit(&emlrtCoverageInstance, 3, 4, 4806, 4828, -1, 4894);
  covrtIfInit(&emlrtCoverageInstance, 3, 5, 4896, 4915, -1, 4964);
  covrtIfInit(&emlrtCoverageInstance, 3, 6, 5163, 5173, -1, 5510);
  covrtIfInit(&emlrtCoverageInstance, 3, 7, 5179, 5192, 5243, 5505);
  covrtIfInit(&emlrtCoverageInstance, 3, 8, 5257, 5268, 5333, 5437);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 3, 0, 3500, 3560, 5, 0, cond_starts_3_0,
                cond_ends_3_0, 11, postfix_exprs_3_0);
  covrtMcdcInit(&emlrtCoverageInstance, 3, 1, 4417, 4434, 2, 5, cond_starts_3_1,
                cond_ends_3_1, 3, postfix_exprs_3_1);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 3U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhamming.m",
                  4, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 4, 0, "Myhamming", 0, -1, 229);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 0, 186, -1, 224);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 4U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfirls.m",
                  5, 1, 17, 10, 0, 0, 0, 1, 0, 2, 1);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 5, 0, "Myfirls", 0, -1, 8010);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 16, 5005, -1, 5026);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 15, 4949, -1, 4986);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 14, 4912, -1, 4917);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 13, 4894, -1, 4897);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 12, 4866, -1, 4875);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 11, 4158, -1, 4825);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 10, 4107, -1, 4123);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 9, 4089, -1, 4093);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 8, 4054, -1, 4070);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 7, 3784, -1, 3959);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 6, 3737, -1, 3744);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 5, 3696, -1, 3706);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 4, 3531, -1, 3540);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 3, 3319, -1, 3364);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 2, 3242, -1, 3280);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 1, 3173, -1, 3205);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5, 0, 2396, -1, 3115);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 5, 0, 3144, 3168, -1, 3210);
  covrtIfInit(&emlrtCoverageInstance, 5, 1, 3212, 3237, -1, 3285);
  covrtIfInit(&emlrtCoverageInstance, 5, 2, 3287, 3314, -1, 3369);
  covrtIfInit(&emlrtCoverageInstance, 5, 3, 3371, 3388, -1, 3446);
  covrtIfInit(&emlrtCoverageInstance, 5, 4, 3447, 3471, -1, 3529);
  covrtIfInit(&emlrtCoverageInstance, 5, 5, 3543, 3558, -1, 8009);
  covrtIfInit(&emlrtCoverageInstance, 5, 6, 3670, 3686, 3724, 3767);
  covrtIfInit(&emlrtCoverageInstance, 5, 7, 4028, 4044, 4076, 4102);
  covrtIfInit(&emlrtCoverageInstance, 5, 8, 4840, 4856, 4881, 4906);
  covrtIfInit(&emlrtCoverageInstance, 5, 9, 4923, 4939, 4992, 5035);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 5, 0, 3450, 3471, 2, 0, cond_starts_5_0,
                cond_ends_5_0, 3, postfix_exprs_5_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 5, 0, 4129, 4149, 4834);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 5U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nlfer.m",
                  6, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 6, 0, "nlfer", 0, -1, 2489);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 6, 0, 1390, -1, 2486);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 6U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myspecgram.m",
                  7, 1, 19, 10, 0, 0, 0, 0, 0, 4, 3);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 7, 0, "Myspecgram", 0, -1, 6977);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 18, 5504, -1, 5534);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 17, 5459, -1, 5477);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 16, 5426, -1, 5432);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 15, 5071, -1, 5091);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 14, 4757, -1, 5063);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 13, 4475, -1, 4498);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 12, 4407, -1, 4432);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 11, 4370, -1, 4385);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 10, 4328, -1, 4343);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 9, 4279, -1, 4298);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 8, 4223, -1, 4244);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 7, 4099, -1, 4114);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 6, 3695, -1, 4014);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 5, 3615, -1, 3651);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 4, 3457, -1, 3604);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 3, 3384, -1, 3413);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 2, 3130, -1, 3340);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 1, 3103, -1, 3124);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7, 0, 2925, -1, 3022);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 7, 0, 3024, 3037, -1, 3129);
  covrtIfInit(&emlrtCoverageInstance, 7, 1, 3342, 3379, -1, 3433);
  covrtIfInit(&emlrtCoverageInstance, 7, 2, 3435, 3452, 3606, 3656);
  covrtIfInit(&emlrtCoverageInstance, 7, 3, 3658, 3690, 4704, 5069);
  covrtIfInit(&emlrtCoverageInstance, 7, 4, 4020, 4033, 4438, 4703);
  covrtIfInit(&emlrtCoverageInstance, 7, 5, 4124, 4145, 4353, 4398);
  covrtIfInit(&emlrtCoverageInstance, 7, 6, 4177, 4191, 4258, 4315);
  covrtIfInit(&emlrtCoverageInstance, 7, 7, 5405, 5420, 5434, 5453);
  covrtIfInit(&emlrtCoverageInstance, 7, 8, 5434, 5453, 5479, 5539);
  covrtIfInit(&emlrtCoverageInstance, 7, 9, 5479, 5498, -1, 5498);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 7, 0, 3661, 3690, 2, 0, cond_starts_7_0,
                cond_ends_7_0, 3, postfix_exprs_7_0);
  covrtMcdcInit(&emlrtCoverageInstance, 7, 1, 4023, 4033, 1, 2, cond_starts_7_1,
                cond_ends_7_1, 2, postfix_exprs_7_1);
  covrtMcdcInit(&emlrtCoverageInstance, 7, 2, 4127, 4145, 1, 3, cond_starts_7_2,
                cond_ends_7_2, 2, postfix_exprs_7_2);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 7U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myhanning.m",
                  8, 1, 3, 1, 0, 0, 0, 0, 0, 1, 1);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 8, 0, "Myhanning", 0, -1, 1787);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 8, 2, 1693, -1, 1777);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8, 1, 1582, -1, 1660);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8, 0, 886, -1, 893);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 8, 0, 1542, 1554, 1662, 1782);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 8, 0, 1545, 1554, 1, 0, cond_starts_8_0,
                cond_ends_8_0, 2, postfix_exprs_8_0);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 8U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\spec_trk.m",
                  9, 1, 18, 5, 0, 0, 0, 4, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 9, 0, "spec_trk", 0, -1, 8808);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 17, 7838, -1, 8778);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 16, 7669, -1, 7757);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 15, 7531, -1, 7557);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 14, 7100, -1, 7218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 13, 7016, -1, 7076);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 12, 6723, -1, 6852);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 11, 6445, -1, 6511);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 10, 6350, -1, 6438);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 9, 5745, -1, 6323);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 8, 4238, -1, 4326);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 7, 4079, -1, 4153);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 6, 4012, -1, 4057);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 5, 3613, -1, 3912);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 4, 3338, -1, 3548);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 3, 3187, -1, 3221);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 2, 2582, -1, 3157);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 1, 2523, -1, 2556);
  covrtBasicBlockInit(&emlrtCoverageInstance, 9, 0, 1954, -1, 2488);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 9, 0, 2490, 2518, -1, 2561);
  covrtIfInit(&emlrtCoverageInstance, 9, 1, 3159, 3178, -1, 3226);
  covrtIfInit(&emlrtCoverageInstance, 9, 2, 3579, 3604, 4159, 4335);
  covrtIfInit(&emlrtCoverageInstance, 9, 3, 7078, 7096, 7289, 7776);
  covrtIfInit(&emlrtCoverageInstance, 9, 4, 7304, 7323, 7656, 7766);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 9, 0, 3551, 3575, 4339);
  covrtForInit(&emlrtCoverageInstance, 9, 1, 3977, 3999, 4070);
  covrtForInit(&emlrtCoverageInstance, 9, 2, 6325, 6346, 6444);
  covrtForInit(&emlrtCoverageInstance, 9, 3, 6698, 6719, 6857);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 9U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mykaiser.m",
                  10, 1, 3, 1, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 10, 0, "Mykaiser", 1499, -1, 1768);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 10, 2, 1582, -1, 1701);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10, 1, 1564, -1, 1569);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10, 0, 1531, -1, 1541);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 10, 0, 1548, 1559, 1573, 1759);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 10U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mybesseli.m",
                  11, 1, 52, 29, 0, 0, 0, 4, 1, 2, 2);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 11, 0, "Mybesseli", 0, -1, 10133);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 14, 5904, -1, 5981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 13, 5787, -1, 5875);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 12, 5719, -1, 5750);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 38, 8957, -1, 8979);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 37, 8903, -1, 8923);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 36, 8827, -1, 8874);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 35, 8451, -1, 8525);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 34, 8420, -1, 8430);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 33, 8234, -1, 8390);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 32, 8079, -1, 8091);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 31, 7936, -1, 8010);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 30, 7905, -1, 7915);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 29, 7828, -1, 7875);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 28, 7786, -1, 7794);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 27, 7664, -1, 7745);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 26, 7543, -1, 7591);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 25, 7493, -1, 7507);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 22, 7284, -1, 7289);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 24, 7354, -1, 7427);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 23, 7323, -1, 7333);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 21, 7207, -1, 7254);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 20, 6981, -1, 7063);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 19, 6816, -1, 6940);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 18, 6728, -1, 6765);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 17, 6651, -1, 6684);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 16, 6397, -1, 6484);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 15, 6134, -1, 6366);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 11, 5660, -1, 5682);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 10, 3556, -1, 3580);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 9, 3510, -1, 3534);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 8, 3198, -1, 3475);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 51, 10111, -1, 10121);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 50, 10055, -1, 10094);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 49, 9994, -1, 10014);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 48, 9912, -1, 9938);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 47, 9861, -1, 9889);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 46, 9775, -1, 9792);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 45, 9535, -1, 9726);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 44, 9452, -1, 9498);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 43, 9309, -1, 9376);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 42, 9273, -1, 9297);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 41, 9217, -1, 9251);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 40, 9101, -1, 9191);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 39, 9047, -1, 9080);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 7, 3139, -1, 3177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 6, 3036, -1, 3067);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 5, 2812, -1, 3014);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 4, 2777, -1, 2786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 3, 2617, -1, 2756);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 2, 2587, -1, 2604);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 1, 2487, -1, 2521);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11, 0, 2055, -1, 2248);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 11, 0, 2253, 2269, -1, 2314);
  covrtIfInit(&emlrtCoverageInstance, 11, 1, 2318, 2338, -1, 2447);
  covrtIfInit(&emlrtCoverageInstance, 11, 2, 2345, 2382, -1, 2440);
  covrtIfInit(&emlrtCoverageInstance, 11, 3, 2565, 2579, -1, 2613);
  covrtIfInit(&emlrtCoverageInstance, 11, 4, 2761, 2770, -1, 3085);
  covrtIfInit(&emlrtCoverageInstance, 11, 5, 2794, 2802, 3022, 3078);
  covrtIfInit(&emlrtCoverageInstance, 11, 6, 3182, 3191, -1, 8997);
  covrtIfInit(&emlrtCoverageInstance, 11, 7, 3483, 3499, 3542, 3591);
  covrtIfInit(&emlrtCoverageInstance, 11, 8, 5761, 5774, 5886, 5995);
  covrtIfInit(&emlrtCoverageInstance, 11, 9, 6374, 6387, 6492, 8050);
  covrtIfInit(&emlrtCoverageInstance, 11, 10, 6506, 6519, -1, 7457);
  covrtIfInit(&emlrtCoverageInstance, 11, 11, 6782, 6796, 6957, 7083);
  covrtIfInit(&emlrtCoverageInstance, 11, 12, 7271, 7282, 7310, 7338);
  covrtIfInit(&emlrtCoverageInstance, 11, 13, 7310, 7321, -1, 7338);
  covrtIfInit(&emlrtCoverageInstance, 11, 14, 7518, 7530, 7602, 8040);
  covrtIfInit(&emlrtCoverageInstance, 11, 15, 7759, 7770, 7808, 8027);
  covrtIfInit(&emlrtCoverageInstance, 11, 16, 7892, 7903, -1, 7920);
  covrtIfInit(&emlrtCoverageInstance, 11, 17, 8057, 8069, -1, 8565);
  covrtIfInit(&emlrtCoverageInstance, 11, 18, 8102, 8115, -1, 8555);
  covrtIfInit(&emlrtCoverageInstance, 11, 19, 8407, 8418, -1, 8435);
  covrtIfInit(&emlrtCoverageInstance, 11, 20, 8802, 8817, -1, 8885);
  covrtIfInit(&emlrtCoverageInstance, 11, 21, 8892, 8901, -1, 8928);
  covrtIfInit(&emlrtCoverageInstance, 11, 22, 9085, 9094, -1, 9757);
  covrtIfInit(&emlrtCoverageInstance, 11, 23, 9199, 9214, -1, 9256);
  covrtIfInit(&emlrtCoverageInstance, 11, 24, 9263, 9271, -1, 9302);
  covrtIfInit(&emlrtCoverageInstance, 11, 25, 9384, 9395, -1, 9750);
  covrtIfInit(&emlrtCoverageInstance, 11, 26, 9797, 9806, -1, 9950);
  covrtIfInit(&emlrtCoverageInstance, 11, 27, 9897, 9910, -1, 9943);
  covrtIfInit(&emlrtCoverageInstance, 11, 28, 10034, 10048, 10099, 10129);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 11, 0, 2256, 2269, 1, 0,
                cond_starts_11_0, cond_ends_11_0, 2, postfix_exprs_11_0);
  covrtMcdcInit(&emlrtCoverageInstance, 11, 1, 8895, 8901, 1, 1,
                cond_starts_11_1, cond_ends_11_1, 2, postfix_exprs_11_1);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 11, 0, 6698, 6713, 7444);
  covrtForInit(&emlrtCoverageInstance, 11, 1, 8204, 8219, 8542);
  covrtForInit(&emlrtCoverageInstance, 11, 2, 8935, 8948, 8990);
  covrtForInit(&emlrtCoverageInstance, 11, 3, 9509, 9522, 9740);

  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 11, 0, 5690, 5710, 6056);

  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 11U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\peaks.m",
                  12, 1, 19, 11, 0, 0, 0, 1, 0, 2, 1);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 12, 0, "peaks", 0, -1, 5836);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 5, 3160, -1, 3281);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 9, 4052, -1, 4131);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 18, 5674, -1, 5738);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 17, 5465, -1, 5654);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 16, 5277, -1, 5350);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 15, 5147, -1, 5255);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 14, 5062, -1, 5098);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 13, 4839, -1, 4951);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 12, 4709, -1, 4817);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 11, 4624, -1, 4660);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 10, 4221, -1, 4425);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 8, 3836, -1, 3936);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 7, 3588, -1, 3624);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 6, 3546, -1, 3558);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 4, 3062, -1, 3100);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 3, 2962, -1, 2982);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 2, 2079, -1, 2932);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 1, 1996, -1, 2013);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12, 0, 1641, -1, 1940);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 12, 0, 1971, 1991, -1, 2018);
  covrtIfInit(&emlrtCoverageInstance, 12, 1, 2934, 2957, -1, 2987);
  covrtIfInit(&emlrtCoverageInstance, 12, 2, 3102, 3132, -1, -2);
  covrtIfInit(&emlrtCoverageInstance, 12, 3, 3682, 3729, -1, 3945);
  covrtIfInit(&emlrtCoverageInstance, 12, 4, 3990, 4029, 4510, 5743);
  covrtIfInit(&emlrtCoverageInstance, 12, 5, 4510, 4527, 5664, 5743);
  covrtIfInit(&emlrtCoverageInstance, 12, 6, 4583, 4612, -1, 4960);
  covrtIfInit(&emlrtCoverageInstance, 12, 7, 4670, 4696, -1, 4830);
  covrtIfInit(&emlrtCoverageInstance, 12, 8, 5021, 5048, -1, 5359);
  covrtIfInit(&emlrtCoverageInstance, 12, 9, 5108, 5134, -1, 5268);
  covrtIfInit(&emlrtCoverageInstance, 12, 10, 5432, 5456, -1, 5663);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 12, 0, 3685, 3729, 2, 0,
                cond_starts_12_0, cond_ends_12_0, 3, postfix_exprs_12_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 12, 0, 3560, 3584, 3949);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 12U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Mymedfilt1.m",
                  13, 1, 4, 1, 0, 0, 0, 1, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 13, 0, "Mymedfilt1", 923, -1, 1319);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 13, 3, 1275, -1, 1314);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13, 2, 1209, -1, 1253);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13, 1, 1029, -1, 1167);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13, 0, 993, -1, 998);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 13, 0, 961, 975, -1, 1011);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 13, 0, 1178, 1192, 1266);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 13U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic5.m",
                  14, 1, 4, 0, 0, 0, 0, 4, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 14, 0, "dynamic5", 0, -1, 2452);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 14, 3, 2404, -1, 2441);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14, 2, 2144, -1, 2380);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14, 1, 1932, -1, 2065);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14, 0, 1305, -1, 1748);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 14, 0, 1853, 1873, 2089);
  covrtForInit(&emlrtCoverageInstance, 14, 1, 1876, 1895, 2084);
  covrtForInit(&emlrtCoverageInstance, 14, 2, 1901, 1920, 2076);
  covrtForInit(&emlrtCoverageInstance, 14, 3, 2382, 2400, 2446);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 14U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\path1.m",
                  15, 1, 12, 5, 0, 0, 0, 7, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 15, 0, "path1", 0, -1, 3798);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 11, 3737, -1, 3743);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 10, 3659, -1, 3680);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 9, 3543, -1, 3552);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 8, 2925, -1, 2949);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 7, 2770, -1, 2776);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 6, 2656, -1, 2673);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 5, 2505, -1, 2533);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 4, 2215, -1, 2274);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 3, 1989, -1, 2005);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 2, 1822, -1, 1841);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 1, 1566, -1, 1735);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15, 0, 1226, -1, 1243);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 15, 0, 1314, 1323, -1, 1422);
  covrtIfInit(&emlrtCoverageInstance, 15, 1, 1423, 1433, -1, 1563);
  covrtIfInit(&emlrtCoverageInstance, 15, 2, 2096, 2130, -1, 2373);
  covrtIfInit(&emlrtCoverageInstance, 15, 3, 2403, 2423, -1, 2487);
  covrtIfInit(&emlrtCoverageInstance, 15, 4, 2891, 2912, -1, 2962);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 15, 0, 1738, 1748, 1851);
  covrtForInit(&emlrtCoverageInstance, 15, 1, 1853, 1863, 2974);
  covrtForInit(&emlrtCoverageInstance, 15, 2, 1971, 1981, 2628);
  covrtForInit(&emlrtCoverageInstance, 15, 3, 2074, 2084, 2385);
  covrtForInit(&emlrtCoverageInstance, 15, 4, 2638, 2648, 2760);
  covrtForInit(&emlrtCoverageInstance, 15, 5, 2782, 2792, 2970);
  covrtForInit(&emlrtCoverageInstance, 15, 6, 3555, 3570, 3736);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 15U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\tm_trk.m",
                  16, 1, 10, 1, 0, 0, 0, 5, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 16, 0, "tm_trk", 0, -1, 4217);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 9, 4162, -1, 4210);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 8, 4041, -1, 4093);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 7, 3974, -1, 4003);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 6, 3889, -1, 3922);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 5, 3841, -1, 3866);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 4, 3615, -1, 3769);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 3, 2712, -1, 3310);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 2, 2364, -1, 2604);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 1, 2292, -1, 2358);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16, 0, 1710, -1, 2261);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 16, 0, 3806, 3828, -1, 3879);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 16, 0, 2263, 2288, 2363);
  covrtForInit(&emlrtCoverageInstance, 16, 1, 2687, 2707, 3315);
  covrtForInit(&emlrtCoverageInstance, 16, 2, 3592, 3611, 4215);
  covrtForInit(&emlrtCoverageInstance, 16, 3, 3775, 3798, 3931);
  covrtForInit(&emlrtCoverageInstance, 16, 4, 4009, 4032, 4102);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 16U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\crs_corr.m",
                  17, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 17, 0, "crs_corr", 0, -1, 2572);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 17, 1, 2131, -1, 2505);
  covrtBasicBlockInit(&emlrtCoverageInstance, 17, 0, 1812, -1, 2022);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 17, 0, 2025, 2049, 2510);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 17U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\cmp_rate.m",
                  18, 1, 9, 5, 0, 0, 0, 1, 0, 2, 1);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 18, 0, "cmp_rate", 0, -1, 4576);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 8, 4544, -1, 4567);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 7, 4495, -1, 4517);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 6, 4286, -1, 4381);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 5, 4210, -1, 4271);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 4, 3859, -1, 4004);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 3, 3682, -1, 3687);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 2, 3232, -1, 3324);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 1, 3134, -1, 3167);
  covrtBasicBlockInit(&emlrtCoverageInstance, 18, 0, 1952, -1, 2657);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 18, 0, 3173, 3214, -1, 3709);
  covrtIfInit(&emlrtCoverageInstance, 18, 1, 3647, 3669, -1, 3700);
  covrtIfInit(&emlrtCoverageInstance, 18, 2, 4154, 4178, -1, 4474);
  covrtIfInit(&emlrtCoverageInstance, 18, 3, 4183, 4201, 4277, 4470);
  covrtIfInit(&emlrtCoverageInstance, 18, 4, 4519, 4539, -1, 4572);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 18, 0, 3176, 3214, 2, 0,
                cond_starts_18_0, cond_ends_18_0, 3, postfix_exprs_18_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 18, 0, 3099, 3130, 3714);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 18U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m",
                  19, 1, 11, 4, 0, 0, 0, 4, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 19, 0, "refine", 0, -1, 4248);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 10, 4056, -1, 4165);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 9, 3968, -1, 4011);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 8, 3875, -1, 3907);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 7, 3654, -1, 3690);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 6, 3235, -1, 3488);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 5, 3025, -1, 3041);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 4, 2858, -1, 2931);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 3, 2644, -1, 2692);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 2, 2334, -1, 2397);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 1, 2238, -1, 2268);
  covrtBasicBlockInit(&emlrtCoverageInstance, 19, 0, 1743, -1, 2214);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 19, 0, 2520, 2549, 2698, 3509);
  covrtIfInit(&emlrtCoverageInstance, 19, 1, 2711, 2730, 3087, 3501);
  covrtIfInit(&emlrtCoverageInstance, 19, 2, 2984, 3004, -1, 3062);
  covrtIfInit(&emlrtCoverageInstance, 19, 3, 3825, 3848, 3913, 4020);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 19, 0, 2216, 2234, 2273);
  covrtForInit(&emlrtCoverageInstance, 19, 1, 2496, 2516, 3513);
  covrtForInit(&emlrtCoverageInstance, 19, 2, 2946, 2967, 3078);
  covrtForInit(&emlrtCoverageInstance, 19, 3, 3630, 3650, 4024);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 19U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\dynamic.m",
                  20, 1, 6, 3, 0, 0, 0, 4, 0, 8, 3);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 20, 0, "dynamic", 0, -1, 3938);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 20, 5, 3901, -1, 3931);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20, 4, 3686, -1, 3877);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20, 3, 3570, -1, 3591);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20, 2, 3327, -1, 3422);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20, 1, 3075, -1, 3155);
  covrtBasicBlockInit(&emlrtCoverageInstance, 20, 0, 2136, -1, 2781);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 20, 0, 3006, 3048, -1, 3172);
  covrtIfInit(&emlrtCoverageInstance, 20, 1, 3237, 3310, -1, 3439);
  covrtIfInit(&emlrtCoverageInstance, 20, 2, 3508, 3553, -1, 3608);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 20, 0, 3010, 3048, 2, 0,
                cond_starts_20_0, cond_ends_20_0, 3, postfix_exprs_20_0);
  covrtMcdcInit(&emlrtCoverageInstance, 20, 1, 3240, 3310, 4, 2,
                cond_starts_20_1, cond_ends_20_1, 7, postfix_exprs_20_1);
  covrtMcdcInit(&emlrtCoverageInstance, 20, 2, 3512, 3552, 2, 6,
                cond_starts_20_2, cond_ends_20_2, 3, postfix_exprs_20_2);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 20, 0, 2887, 2907, 3632);
  covrtForInit(&emlrtCoverageInstance, 20, 1, 2911, 2930, 3628);
  covrtForInit(&emlrtCoverageInstance, 20, 2, 2938, 2957, 3620);
  covrtForInit(&emlrtCoverageInstance, 20, 3, 3879, 3899, 3936);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 20U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\freqSelect.m",
                  21, 1, 50, 48, 0, 0, 0, 1, 0, 4, 2);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 21, 0, "freqSelect", 0, -1, 10124);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 49, 10013, -1, 10024);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 48, 9760, -1, 9830);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 47, 9631, -1, 9701);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 46, 9469, -1, 9533);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 45, 9224, -1, 9293);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 44, 9094, -1, 9165);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 43, 8931, -1, 8996);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 42, 8621, -1, 8690);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 41, 8494, -1, 8562);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 40, 8330, -1, 8396);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 39, 8090, -1, 8154);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 38, 7959, -1, 8031);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 37, 7797, -1, 7861);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 36, 7440, -1, 7508);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 35, 7312, -1, 7381);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 34, 7149, -1, 7214);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 33, 6905, -1, 6973);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 32, 6778, -1, 6846);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 31, 6615, -1, 6680);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 30, 6307, -1, 6375);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 29, 6179, -1, 6248);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 28, 6016, -1, 6081);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 27, 5776, -1, 5842);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 26, 5649, -1, 5717);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 25, 5485, -1, 5551);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 24, 5053, -1, 5123);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 23, 4925, -1, 4994);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 22, 4762, -1, 4827);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 21, 4517, -1, 4586);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 20, 4389, -1, 4458);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 19, 4226, -1, 4291);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 18, 3920, -1, 3988);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 17, 3792, -1, 3861);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 16, 3629, -1, 3694);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 15, 3386, -1, 3450);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 14, 3258, -1, 3327);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 13, 3095, -1, 3160);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 12, 2727, -1, 2801);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 11, 2598, -1, 2668);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 10, 2433, -1, 2500);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 9, 2182, -1, 2257);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 8, 2055, -1, 2123);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 7, 1893, -1, 1957);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 6, 1585, -1, 1657);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 5, 1454, -1, 1526);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 4, 1291, -1, 1356);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 3, 1098, -1, 1165);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 2, 949, -1, 1019);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 1, 822, -1, 890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 21, 0, 451, -1, 554);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 21, 0, 582, 618, 5289, 10116);
  covrtIfInit(&emlrtCoverageInstance, 21, 1, 627, 645, 2961, 5284);
  covrtIfInit(&emlrtCoverageInstance, 21, 2, 658, 676, 1790, 2952);
  covrtIfInit(&emlrtCoverageInstance, 21, 3, 693, 711, 1223, 1768);
  covrtIfInit(&emlrtCoverageInstance, 21, 4, 732, 750, 1069, 1190);
  covrtIfInit(&emlrtCoverageInstance, 21, 5, 775, 793, 916, 1048);
  covrtIfInit(&emlrtCoverageInstance, 21, 6, 1248, 1266, 1378, 1730);
  covrtIfInit(&emlrtCoverageInstance, 21, 7, 1407, 1425, 1552, 1686);
  covrtIfInit(&emlrtCoverageInstance, 21, 8, 1811, 1829, 2365, 2912);
  covrtIfInit(&emlrtCoverageInstance, 21, 9, 1850, 1868, 1979, 2330);
  covrtIfInit(&emlrtCoverageInstance, 21, 10, 2008, 2026, 2149, 2286);
  covrtIfInit(&emlrtCoverageInstance, 21, 11, 2390, 2408, 2522, 2874);
  covrtIfInit(&emlrtCoverageInstance, 21, 12, 2551, 2569, 2694, 2830);
  covrtIfInit(&emlrtCoverageInstance, 21, 13, 2978, 2996, 4124, 5264);
  covrtIfInit(&emlrtCoverageInstance, 21, 14, 3013, 3031, 3561, 4098);
  covrtIfInit(&emlrtCoverageInstance, 21, 15, 3052, 3070, 3182, 3526);
  covrtIfInit(&emlrtCoverageInstance, 21, 16, 3211, 3229, 3353, 3479);
  covrtIfInit(&emlrtCoverageInstance, 21, 17, 3586, 3604, 3716, 4061);
  covrtIfInit(&emlrtCoverageInstance, 21, 18, 3745, 3763, 3887, 4017);
  covrtIfInit(&emlrtCoverageInstance, 21, 19, 4145, 4163, 4694, 5234);
  covrtIfInit(&emlrtCoverageInstance, 21, 20, 4184, 4202, 4313, 4659);
  covrtIfInit(&emlrtCoverageInstance, 21, 21, 4342, 4360, 4484, 4615);
  covrtIfInit(&emlrtCoverageInstance, 21, 22, 4719, 4737, 4849, 5196);
  covrtIfInit(&emlrtCoverageInstance, 21, 23, 4878, 4896, 5020, 5152);
  covrtIfInit(&emlrtCoverageInstance, 21, 24, 5289, 5329, 9999, 10116);
  covrtIfInit(&emlrtCoverageInstance, 21, 25, 5338, 5356, 7663, 9994);
  covrtIfInit(&emlrtCoverageInstance, 21, 26, 5369, 5387, 6512, 7649);
  covrtIfInit(&emlrtCoverageInstance, 21, 27, 5404, 5422, 5949, 6486);
  covrtIfInit(&emlrtCoverageInstance, 21, 28, 5443, 5461, 5573, 5914);
  covrtIfInit(&emlrtCoverageInstance, 21, 29, 5602, 5620, 5743, 5871);
  covrtIfInit(&emlrtCoverageInstance, 21, 30, 5974, 5992, 6103, 6448);
  covrtIfInit(&emlrtCoverageInstance, 21, 31, 6132, 6150, 6274, 6404);
  covrtIfInit(&emlrtCoverageInstance, 21, 32, 6533, 6551, 7081, 7619);
  covrtIfInit(&emlrtCoverageInstance, 21, 33, 6572, 6590, 6702, 7046);
  covrtIfInit(&emlrtCoverageInstance, 21, 34, 6731, 6749, 6872, 7002);
  covrtIfInit(&emlrtCoverageInstance, 21, 35, 7106, 7124, 7236, 7581);
  covrtIfInit(&emlrtCoverageInstance, 21, 36, 7265, 7283, 7407, 7537);
  covrtIfInit(&emlrtCoverageInstance, 21, 37, 7680, 7698, 8828, 9974);
  covrtIfInit(&emlrtCoverageInstance, 21, 38, 7715, 7733, 8261, 8801);
  covrtIfInit(&emlrtCoverageInstance, 21, 39, 7754, 7772, 7883, 8227);
  covrtIfInit(&emlrtCoverageInstance, 21, 40, 7912, 7930, 8057, 8183);
  covrtIfInit(&emlrtCoverageInstance, 21, 41, 8286, 8304, 8418, 8763);
  covrtIfInit(&emlrtCoverageInstance, 21, 42, 8447, 8465, 8588, 8719);
  covrtIfInit(&emlrtCoverageInstance, 21, 43, 8849, 8867, 9401, 9944);
  covrtIfInit(&emlrtCoverageInstance, 21, 44, 8888, 8906, 9018, 9366);
  covrtIfInit(&emlrtCoverageInstance, 21, 45, 9047, 9065, 9191, 9322);
  covrtIfInit(&emlrtCoverageInstance, 21, 46, 9426, 9444, 9555, 9906);
  covrtIfInit(&emlrtCoverageInstance, 21, 47, 9584, 9602, 9727, 9859);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 21, 0, 586, 617, 2, 0, cond_starts_21_0,
                cond_ends_21_0, 3, postfix_exprs_21_0);
  covrtMcdcInit(&emlrtCoverageInstance, 21, 1, 5297, 5328, 2, 2,
                cond_starts_21_1, cond_ends_21_1, 3, postfix_exprs_21_1);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 21, 0, 556, 578, 10120);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 21U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\fq2cnt.m",
                  22, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 22, 0, "fq2cnt", 0, -1, 312);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 22, 0, 278, -1, 307);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 22U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Smooth2.m",
                  23, 1, 19, 17, 0, 0, 0, 2, 1, 21, 8);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 23, 0, "Smooth2", 0, -1, 6437);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 18, 6267, -1, 6363);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 17, 6174, -1, 6237);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 5, 802, -1, 807);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 6, 834, -1, 874);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 16, 4401, -1, 4596);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 15, 3864, -1, 4155);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 14, 3401, -1, 3598);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 13, 2869, -1, 3144);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 12, 2435, -1, 2624);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 11, 2002, -1, 2191);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 10, 1623, -1, 1819);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 9, 1456, -1, 1604);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 8, 1254, -1, 1402);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 7, 909, -1, 1218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 4, 486, -1, 619);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 3, 335, -1, 471);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 2, 294, -1, 306);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 1, 215, -1, 280);
  covrtBasicBlockInit(&emlrtCoverageInstance, 23, 0, 35, -1, 163);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 23, 0, 189, 206, -1, 289);
  covrtIfInit(&emlrtCoverageInstance, 23, 1, 629, 648, -1, 899);
  covrtIfInit(&emlrtCoverageInstance, 23, 2, 756, 789, 817, 887);
  covrtIfInit(&emlrtCoverageInstance, 23, 3, 1224, 1245, 1408, 1828);
  covrtIfInit(&emlrtCoverageInstance, 23, 4, 1408, 1447, 1610, 1828);
  covrtIfInit(&emlrtCoverageInstance, 23, 5, 1854, 1879, -1, 6156);
  covrtIfInit(&emlrtCoverageInstance, 23, 6, 1888, 1935, 2217, 4643);
  covrtIfInit(&emlrtCoverageInstance, 23, 7, 1948, 1985, -1, 2208);
  covrtIfInit(&emlrtCoverageInstance, 23, 8, 2217, 2270, 2650, 4643);
  covrtIfInit(&emlrtCoverageInstance, 23, 9, 2283, 2418, -1, 2641);
  covrtIfInit(&emlrtCoverageInstance, 23, 10, 2650, 2703, 3170, 4643);
  covrtIfInit(&emlrtCoverageInstance, 23, 11, 2716, 2852, -1, 3161);
  covrtIfInit(&emlrtCoverageInstance, 23, 12, 3186, 3229, 3643, 4631);
  covrtIfInit(&emlrtCoverageInstance, 23, 13, 3245, 3380, -1, 3631);
  covrtIfInit(&emlrtCoverageInstance, 23, 14, 3643, 3692, 4206, 4631);
  covrtIfInit(&emlrtCoverageInstance, 23, 15, 3708, 3843, -1, 4194);
  covrtIfInit(&emlrtCoverageInstance, 23, 16, 4226, 4381, -1, 4616);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 23, 0, 1891, 1934, 2, 0,
                cond_starts_23_0, cond_ends_23_0, 3, postfix_exprs_23_0);
  covrtMcdcInit(&emlrtCoverageInstance, 23, 1, 2224, 2269, 2, 2,
                cond_starts_23_1, cond_ends_23_1, 3, postfix_exprs_23_1);
  covrtMcdcInit(&emlrtCoverageInstance, 23, 2, 2286, 2417, 3, 4,
                cond_starts_23_2, cond_ends_23_2, 5, postfix_exprs_23_2);
  covrtMcdcInit(&emlrtCoverageInstance, 23, 3, 2657, 2702, 2, 7,
                cond_starts_23_3, cond_ends_23_3, 3, postfix_exprs_23_3);
  covrtMcdcInit(&emlrtCoverageInstance, 23, 4, 2719, 2851, 3, 9,
                cond_starts_23_4, cond_ends_23_4, 5, postfix_exprs_23_4);
  covrtMcdcInit(&emlrtCoverageInstance, 23, 5, 3248, 3379, 3, 12,
                cond_starts_23_5, cond_ends_23_5, 5, postfix_exprs_23_5);
  covrtMcdcInit(&emlrtCoverageInstance, 23, 6, 3711, 3842, 3, 15,
                cond_starts_23_6, cond_ends_23_6, 5, postfix_exprs_23_6);
  covrtMcdcInit(&emlrtCoverageInstance, 23, 7, 4229, 4380, 3, 18,
                cond_starts_23_7, cond_ends_23_7, 5, postfix_exprs_23_7);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 23, 0, 165, 185, 311);
  covrtForInit(&emlrtCoverageInstance, 23, 1, 6239, 6263, 6368);

  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 23, 0, 473, 481, 6173);

  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 23U);
}

void yaapt_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    yaapt_once();
  }
}

/* End of code generation (yaapt_initialize.c) */
