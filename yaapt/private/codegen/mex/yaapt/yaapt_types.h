/*
 * yaapt_types.h
 *
 * Code generation for function 'yaapt'
 *
 */

#ifndef YAAPT_TYPES_H
#define YAAPT_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T

struct emxArray_creal_T
{
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_creal_T*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct emxArray_creal_T emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#include <stdlib.h>
#ifndef struct_emxArray_ptrdiff_t
#define struct_emxArray_ptrdiff_t

struct emxArray_ptrdiff_t
{
  ptrdiff_t *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_ptrdiff_t*/

#ifndef typedef_emxArray_ptrdiff_t
#define typedef_emxArray_ptrdiff_t

typedef struct emxArray_ptrdiff_t emxArray_ptrdiff_t;

#endif                                 /*typedef_emxArray_ptrdiff_t*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T frame_length;
  real_T frame_space;
  real_T f0_min;
  real_T f0_max;
  real_T fft_length;
  real_T bp_forder;
  real_T bp_low;
  real_T bp_high;
  real_T nlfer_thresh1;
  real_T nlfer_thresh2;
  real_T shc_numharms;
  real_T shc_window;
  real_T shc_maxpeaks;
  real_T shc_pwidth;
  real_T shc_thresh1;
  real_T shc_thresh2;
  real_T f0_double;
  real_T f0_half;
  real_T dp5_k1;
  real_T dec_factor;
  real_T nccf_thresh1;
  real_T nccf_thresh2;
  real_T nccf_maxcands;
  real_T nccf_pwidth;
  real_T merit_boost;
  real_T merit_pivot;
  real_T merit_extra;
  real_T median_value;
  real_T dp_w1;
  real_T dp_w2;
  real_T dp_w3;
  real_T dp_w4;
  real_T smooth_threshold;
  real_T end;
} struct_T;

#endif                                 /*typedef_struct_T*/
#endif

/* End of code generation (yaapt_types.h) */
