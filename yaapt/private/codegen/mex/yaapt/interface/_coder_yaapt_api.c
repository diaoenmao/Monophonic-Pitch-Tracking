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

/* Variable Definitions */
static emlrtRTEInfo od_emlrtRTEI = { 1, 1, "_coder_yaapt_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Fs, const
  char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Data, const
  char_T *identifier, emxArray_real_T *y);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv85[2] = { 0, 0 };

  const mxArray *m39;
  y = NULL;
  m39 = emlrtCreateNumericArray(2, iv85, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m39, (void *)u->data);
  emlrtSetDimensions((mxArray *)m39, u->size, 2);
  emlrtAssign(&y, m39);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Fs, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(Fs), &thisId);
  emlrtDestroyArray(&Fs);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv86[2];
  boolean_T bv1[2];
  int32_T i40;
  static const boolean_T bv2[2] = { false, true };

  int32_T iv87[2];
  for (i40 = 0; i40 < 2; i40++) {
    iv86[i40] = 1 + -2 * i40;
    bv1[i40] = bv2[i40];
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv86, bv1, iv87);
  ret->size[0] = iv87[0];
  ret->size[1] = iv87[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Data, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(Data), &thisId, y);
  emlrtDestroyArray(&Data);
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
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
  emxInit_real_T(&st, &Data, 2, &od_emlrtRTEI, true);
  emxInit_real_T(&st, &Pitch, 2, &od_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Data", Data);
  Fs = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Fs");

  /* Invoke the target function */
  yaapt(SD, &st, Data, Fs, Pitch, &numfrms, &frmrate);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(Pitch);
  plhs[1] = emlrt_marshallOut(numfrms);
  plhs[2] = emlrt_marshallOut(frmrate);
  Pitch->canFreeData = false;
  emxFree_real_T(&Pitch);
  Data->canFreeData = false;
  emxFree_real_T(&Data);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_yaapt_api.c) */
