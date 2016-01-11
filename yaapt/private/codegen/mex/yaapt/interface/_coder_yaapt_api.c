/*
 * _coder_yaapt_api.c
 *
 * Code generation for function '_coder_yaapt_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "_coder_yaapt_api.h"
#include "yaapt_emxutil.h"
#include "peaks.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo ld_emlrtRTEI = { 1, 1, "_coder_yaapt_api", "" };

/* Function Declarations */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Data, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Fs, const
  char_T *identifier);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *f_emlrt_marshallOut(const emxArray_real_T *u);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Data, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(Data), &thisId, y);
  emlrtDestroyArray(&Data);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Fs, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(Fs), &thisId);
  emlrtDestroyArray(&Fs);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv47[2] = { 0, 0 };

  const mxArray *m15;
  y = NULL;
  m15 = emlrtCreateNumericArray(2, iv47, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m15, (void *)u->data);
  emlrtSetDimensions((mxArray *)m15, u->size, 2);
  emlrtAssign(&y, m15);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv48[2];
  boolean_T bv1[2] = { false, true };

  static const int32_T dims[2] = { 1, -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv48);
  ret->size[0] = iv48[0];
  ret->size[1] = iv48[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void yaapt_api(yaaptStackData *SD, const mxArray * const prhs[2], const mxArray *
               plhs[3])
{
  emxArray_real_T *Data;
  emxArray_real_T *Pitch;
  real_T Fs;
  real_T frmrate;
  real_T numfrms;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Data, 2, &ld_emlrtRTEI, true);
  emxInit_real_T(&st, &Pitch, 2, &ld_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Data", Data);
  Fs = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Fs");

  /* Invoke the target function */
  yaapt(SD, &st, Data, Fs, Pitch, &numfrms, &frmrate);

  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(Pitch);
  plhs[1] = emlrt_marshallOut(numfrms);
  plhs[2] = emlrt_marshallOut(frmrate);
  Pitch->canFreeData = false;
  emxFree_real_T(&Pitch);
  Data->canFreeData = false;
  emxFree_real_T(&Data);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_yaapt_api.c) */
