/*
 * yaapt.c
 *
 * Code generation for function 'yaapt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "yaapt_emxutil.h"
#include "Myfirls.h"
#include "spec_trk.h"
#include "dynamic.h"
#include "median.h"
#include "eml_sort.h"
#include "cat.h"
#include "tm_trk.h"
#include "nlfer.h"
#include "peaks.h"
#include "filter.h"
#include "yaapt_mexutil.h"
#include "yaapt_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 120, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo b_emlrtRSI = { 125, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo c_emlrtRSI = { 128, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo d_emlrtRSI = { 133, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo e_emlrtRSI = { 137, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo f_emlrtRSI = { 143, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo g_emlrtRSI = { 146, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo h_emlrtRSI = { 149, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo i_emlrtRSI = { 153, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRSInfo j_emlrtRSI = { 54, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo k_emlrtRSI = { 63, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo l_emlrtRSI = { 79, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtRSInfo m_emlrtRSI = { 146, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo n_emlrtRSI = { 149, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo o_emlrtRSI = { 156, "Myfir1",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\Myfir1.m" };

static emlrtRSInfo pi_emlrtRSI = { 57, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo qi_emlrtRSI = { 51, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo ri_emlrtRSI = { 46, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRSInfo si_emlrtRSI = { 45, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 37, "yaapt",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" };

static emlrtRTEInfo c_emlrtRTEI = { 63, 1, "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m" };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 53, 30, "Idx", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 53, 33, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 53, 13, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo b_emlrtECI = { -1, 53, 5, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtECInfo c_emlrtECI = { 2, 57, 13, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 64, 17, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 65, 17, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 81, 33, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 85, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 85, 30, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 86, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 86, 30, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 101, 40, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 106, 7, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo d_emlrtECI = { -1, 106, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 107, 7, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtECInfo e_emlrtECI = { -1, 107, 1, "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m" };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 82, 9, "tempData", "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 65, 9, "tempData", "nonlinear",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\nonlinear.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 94, 11, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 94, 22, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 94, 39, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 98, 21, "BestPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 101, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 101, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 99, 15, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 99, 26, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 99, 39, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 62, 9, "Energy", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 67, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 80, 21, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 80, 27, "SPitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 81, 21, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 86, 47, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 70, 19, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 70, 28, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 71, 19, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 71, 28, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 71, 46, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 73, 27, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 73, 29, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 74, 27, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 74, 29, "Merit", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 53, 24, "Pitch", "refine",
  "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\refine.m", 0 };

/* Function Declarations */
static void g_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);

/* Function Definitions */
static void g_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

/*
 * function[Pitch, numfrms, frmrate] = yaapt(Data, Fs)
 */
void yaapt(yaaptStackData *SD, const emlrtStack *sp, const emxArray_real_T *Data,
           real_T Fs, emxArray_real_T *Pitch, real_T *numfrms, real_T *frmrate)
{
  real_T w[2];
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  const mxArray *b_y;
  static const int32_T iv0[2] = { 1, 47 };

  const mxArray *m0;
  char_T cv0[47];
  int32_T i;
  static const char_T cv1[47] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c', 'i',
    'e', 's', ' ', 'm', 'u', 's', 't', ' ', 'f', 'a', 'l', 'l', ' ', 'i', 'n',
    ' ', 'r', 'a', 'n', 'g', 'e', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ',
    '0', ' ', 'a', 'n', 'd', ' ', '1', '.' };

  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 30 };

  char_T cv2[30];
  static const char_T cv3[30] = { 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c', 'i',
    'e', 's', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 'i', 'n', 'c', 'r',
    'e', 'a', 's', 'i', 'n', 'g' };

  real_T ff[6];
  int32_T i0;
  real_T b_ff[6];
  real_T hh[151];
  static const real_T dv0[151] = { 0.080000000000000016, 0.080403498154525133,
    0.081613284745228, 0.08362723739534017, 0.086441822947567748,
    0.090052103662449423, 0.094451745880829718, 0.099633031135249073,
    0.10558686969075876, 0.11230281649140433, 0.11976908948440362,
    0.12797259028987007, 0.13689892717982277, 0.14653244032616691,
    0.1568562292733543, 0.16785218258752421, 0.17950100963011367,
    0.19178227440019208, 0.20467443138615071, 0.21815486336385193,
    0.23219992107492521, 0.24678496471560279, 0.26188440716330758,
    0.2774717588651614, 0.29351967430966164, 0.30999999999999994,
    0.32688382384486359, 0.34414152588006663, 0.36174283023203269,
    0.379656858231965, 0.39785218258752419, 0.41629688251697783,
    0.4349585997490984, 0.45380459529056666, 0.4728018068612907,
    0.49191690689687945, 0.51111636101651581, 0.53036648685365584,
    0.54963351314634423, 0.56888363898348415, 0.58808309310312057,
    0.60719819313870937, 0.62619540470943347, 0.64504140025090173,
    0.66370311748302224, 0.68214781741247577, 0.70034314176803492,
    0.71825716976796738, 0.73585847411993344, 0.75311617615513637,
    0.76999999999999991, 0.78648032569033854, 0.80252824113483856,
    0.81811559283669255, 0.83321503528439733, 0.8478000789250747,
    0.86184513663614815, 0.87532556861384925, 0.88821772559980794,
    0.90049899036988634, 0.91214781741247575, 0.92314377072664577,
    0.9334675596738331, 0.94310107282017719, 0.95202740971013,
    0.9602309105155965, 0.96769718350859568, 0.97441313030924137,
    0.98036696886475094, 0.98554825411917035, 0.98994789633755065,
    0.99355817705243232, 0.9963727626046599, 0.99838671525477207,
    0.99959650184547488, 1.0, 0.99959650184547488, 0.99838671525477207,
    0.9963727626046599, 0.99355817705243232, 0.98994789633755065,
    0.98554825411917035, 0.98036696886475094, 0.97441313030924137,
    0.96769718350859568, 0.9602309105155965, 0.95202740971013,
    0.94310107282017719, 0.9334675596738331, 0.92314377072664577,
    0.91214781741247575, 0.90049899036988634, 0.88821772559980794,
    0.87532556861384925, 0.86184513663614815, 0.8478000789250747,
    0.83321503528439733, 0.81811559283669255, 0.80252824113483856,
    0.78648032569033854, 0.76999999999999991, 0.75311617615513637,
    0.73585847411993344, 0.71825716976796738, 0.70034314176803492,
    0.68214781741247577, 0.66370311748302224, 0.64504140025090173,
    0.62619540470943347, 0.60719819313870937, 0.58808309310312057,
    0.56888363898348415, 0.54963351314634423, 0.53036648685365584,
    0.51111636101651581, 0.49191690689687945, 0.4728018068612907,
    0.45380459529056666, 0.4349585997490984, 0.41629688251697783,
    0.39785218258752419, 0.379656858231965, 0.36174283023203269,
    0.34414152588006663, 0.32688382384486359, 0.30999999999999994,
    0.29351967430966164, 0.2774717588651614, 0.26188440716330758,
    0.24678496471560279, 0.23219992107492521, 0.21815486336385193,
    0.20467443138615071, 0.19178227440019208, 0.17950100963011367,
    0.16785218258752421, 0.1568562292733543, 0.14653244032616691,
    0.13689892717982277, 0.12797259028987007, 0.11976908948440362,
    0.11230281649140433, 0.10558686969075876, 0.099633031135249073,
    0.094451745880829718, 0.090052103662449423, 0.086441822947567748,
    0.08362723739534017, 0.081613284745228, 0.080403498154525133,
    0.080000000000000016 };

  real_T f0;
  creal_T x[151];
  real_T r;
  real_T x_im;
  emxArray_real_T *tempData;
  int32_T loop_ub;
  int32_T i1;
  emxArray_real_T *DataB;
  emxArray_real_T *b_tempData;
  emxArray_real_T *DataD;
  const mxArray *d_y;
  static const int32_T iv2[2] = { 1, 34 };

  char_T cv4[34];
  static const char_T cv5[34] = { 'F', 'r', 'a', 'm', 'e', ' ', 'l', 'e', 'n',
    'g', 't', 'h', ' ', 'v', 'a', 'l', 'u', 'e', ' ', '%', 'd', ' ', 'i', 's',
    ' ', 't', 'o', 'o', ' ', 's', 'h', 'o', 'r', 't' };

  const mxArray *e_y;
  static const int32_T iv3[2] = { 1, 39 };

  char_T cv6[39];
  static const char_T cv7[39] = { 'F', 'r', 'a', 'm', 'e', ' ', 'l', 'e', 'n',
    'g', 't', 'h', ' ', 'v', 'a', 'l', 'u', 'e', ' ', '%', 'd', ' ', 'e', 'x',
    'c', 'e', 'e', 'd', 's', ' ', 't', 'h', 'e', ' ', 'l', 'i', 'm', 'i', 't' };

  emxArray_real_T *Energy;
  emxArray_boolean_T *VUVEnergy;
  emxArray_real_T *b_DataD;
  emxArray_real_T *SPitch;
  emxArray_real_T *TPitch1;
  emxArray_real_T *TMerit1;
  emxArray_real_T *TPitch2;
  emxArray_real_T *TMerit2;
  emxArray_real_T *RPitch;
  emxArray_real_T *Merit;
  emxArray_real_T *b_Merit;
  int32_T pStd_size[1];
  real_T pStd_data[1];
  int32_T pAvg_size[1];
  real_T pAvg_data[1];
  int32_T maxcands;
  int32_T numframes;
  emxArray_real_T *Idx;
  emxArray_int32_T *iidx;
  emxArray_real_T *r0;
  emxArray_int32_T *r1;
  emxArray_real_T *b_RPitch;
  int32_T i2;
  int32_T i3;
  int32_T iv4[1];
  int32_T c_RPitch[1];
  emxArray_real_T *d_RPitch;
  emxArray_real_T *m;
  int32_T c_tempData[2];
  emxArray_real_T *d_tempData;
  int32_T b_VUVEnergy[2];
  int32_T iv5[2];
  int32_T iv6[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  YAAPT Fundamental Frequency (Pitch) tracking */
  /*  */
  /*  [Pitch, numfrms, frmrate] = yaapt(Data, Fs, VU, ExtrPrm, fig) */
  /*    , the function is to check input parameters and invoke a number of associated routines  */
  /*    for the YAAPT pitch tracking. */
  /*  */
  /*  INPUTS:  */
  /*    Data:       Input speech raw data */
  /*    Fs:         Sampling rate of the input data */
  /*    VU:         Whether to use voiced/unvoiced decision with 1 for True and 0 for  */
  /*                False.The default is 1. */
  /*    ExtrPrm:    Extra parameters in a struct type for performance control. */
  /*                See available parameters defined in yaapt.m  */
  /*                e.g.,  */
  /*                ExtrPrm.f0_min = 60;         % Change minimum search F0 to 60Hz  */
  /*                ExtrmPrm.fft_length = 8192;  % Change FFT length to 8192 */
  /*    fig:        Whether to plot pitch tracks, spectrum, engergy, etc. The parameter */
  /*                is 1 for True and 0 for False. The default is 0.    */
  /*  */
  /*  OUTPUTS: */
  /*    Pitch:      Final pitch track in Hz. Unvoiced frames are assigned to 0s. */
  /*    numfrms:    Total number of calculated frames, or the length of */
  /*                output pitch track */
  /*    frmrate:    Frame rate of output pitch track in ms */
  /*   Creation Date:  June 2000 */
  /*   Revision date:  Jan 2, 2002 , Jan 13, 2002 Feb 19, 2002, Mar 3, 2002 */
  /*                   June 11, 2002, Jun 30, 2006, July 27, 2007 */
  /*                   May 20, 2012: Add the VU parameter for whether to use */
  /*                   voiced/unvoiced decision.  */
  /*   Authors:        Hongbing Hu, Stephen A.Zahorian */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*      This file is a part of the YAAPT program, designed for a fundamental  */
  /*    frequency tracking algorithm that is extermely robust for both high quality  */
  /*    and telephone speech.   */
  /*      The YAAPT program was created by the Speech Communication Laboratory of */
  /*    the state university of New York at Binghamton. The program is available  */
  /*    at http://www.ws.binghamton.edu/zahorian as free software. Further  */
  /*    information about the program can be found at "A spectral/temporal  */
  /*    method for robust fundamental frequency tracking," J.Acosut.Soc.Am. 123(6),  */
  /*    June 2008. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* -- PARAMETERS ---------------------------------------------------------------- */
  /*  Preliminary input arguments check */
  /* 'yaapt:49' if nargin<2 */
  /*  Default values for the tracking with voiced/unvoiced decision */
  /*  % Length of each analysis frame (ms) */
  /*  % Spacing between analysis frame (ms) */
  /*  % Minimum F0 searched (Hz) */
  /*  % Maximum F0 searached (Hz) */
  /*  % FFT length */
  /*  % Order of bandpass filter */
  /*  % Low frequency of filter passband (Hz) */
  /*  % High frequency of filter passband (Hz) */
  /*  % NLFER boundary for voiced/unvoiced decisions */
  /*  % Threshold for NLFER definitely unvocied */
  /*  % Number of harmonics in SHC calculation */
  /*  % SHC window length (Hz) */
  /*  % Maximum number of SHC peaks to be found */
  /*  % Window width in SHC peak picking (Hz) */
  /*  % Threshold 1 for SHC peak picking */
  /*  % Threshold 2 for SHC peak picking */
  /*  % F0 doubling decision threshold (Hz) */
  /*  % F0 halving decision threshold (Hz) */
  /*  % Weight used in dynaimc program */
  /*  % Factor for signal resampling */
  /*  % Threshold for considering a peak in NCCF */
  /*  % Threshold for terminating serach in NCCF */
  /*  % Maximum number of candidates found */
  /*  % Window width in NCCF peak picking */
  /*  % Boost merit */
  /*  % Merit assigned to unvoiced candidates in */
  /*  % defintely unvoiced frames */
  /*  % Merit assigned to extra candidates */
  /*  % in reducing F0 doubling/halving errors */
  /*  % Order of medial filter */
  /*  % DP weight factor for V-V transitions */
  /*  % DP weight factor for V-UV or UV-V transitions */
  /*  % DP weight factor of UV-UV transitions */
  /*  % Weight factor for local costs */
  /* 'yaapt:54' Prm = struct(... */
  /* 'yaapt:55'     'frame_length',   25, ... % Length of each analysis frame (ms) */
  /* 'yaapt:56'     'frame_space',    10, ... % Spacing between analysis frame (ms) */
  /* 'yaapt:57'     'f0_min',         60, ... % Minimum F0 searched (Hz) */
  /* 'yaapt:58'     'f0_max',        400, ... % Maximum F0 searached (Hz) */
  /* 'yaapt:59'     'fft_length',   8192, ... % FFT length */
  /* 'yaapt:60'     'bp_forder',     150, ... % Order of bandpass filter */
  /* 'yaapt:61'     'bp_low',         50, ... % Low frequency of filter passband (Hz) */
  /* 'yaapt:62'     'bp_high',      1500, ... % High frequency of filter passband (Hz) */
  /* 'yaapt:63'     'nlfer_thresh1',0.75, ... % NLFER boundary for voiced/unvoiced decisions */
  /* 'yaapt:64'     'nlfer_thresh2', 0.1, ... % Threshold for NLFER definitely unvocied */
  /* 'yaapt:65'     'shc_numharms',    3, ... % Number of harmonics in SHC calculation */
  /* 'yaapt:66'     'shc_window',     40, ... % SHC window length (Hz) */
  /* 'yaapt:67'     'shc_maxpeaks',    4, ... % Maximum number of SHC peaks to be found */
  /* 'yaapt:68'     'shc_pwidth',     50, ... % Window width in SHC peak picking (Hz) */
  /* 'yaapt:69'     'shc_thresh1',   5.0, ... % Threshold 1 for SHC peak picking */
  /* 'yaapt:70'     'shc_thresh2',  1.25, ... % Threshold 2 for SHC peak picking */
  /* 'yaapt:71'     'f0_double',     150, ... % F0 doubling decision threshold (Hz) */
  /* 'yaapt:72'     'f0_half',       150, ... % F0 halving decision threshold (Hz) */
  /* 'yaapt:73'     'dp5_k1',         11, ... % Weight used in dynaimc program */
  /* 'yaapt:74'     'dec_factor',      1, ... % Factor for signal resampling */
  /* 'yaapt:75'     'nccf_thresh1', 0.25, ... % Threshold for considering a peak in NCCF */
  /* 'yaapt:76'     'nccf_thresh2',  0.9, ... % Threshold for terminating serach in NCCF */
  /* 'yaapt:77'     'nccf_maxcands',   3, ... % Maximum number of candidates found */
  /* 'yaapt:78'     'nccf_pwidth',     5, ... % Window width in NCCF peak picking */
  /* 'yaapt:79'     'merit_boost',  0.20, ... % Boost merit */
  /* 'yaapt:80'     'merit_pivot',  0.99, ... % Merit assigned to unvoiced candidates in */
  /* 'yaapt:81'                           ... % defintely unvoiced frames */
  /* 'yaapt:82'     'merit_extra',   0.4, ... % Merit assigned to extra candidates */
  /* 'yaapt:83'                           ... % in reducing F0 doubling/halving errors */
  /* 'yaapt:84'     'median_value',    7, ... % Order of medial filter */
  /* 'yaapt:85'     'dp_w1',        0.15, ... % DP weight factor for V-V transitions */
  /* 'yaapt:86'     'dp_w2',         0.5, ... % DP weight factor for V-UV or UV-V transitions */
  /* 'yaapt:87'     'dp_w3',         0.1, ... % DP weight factor of UV-UV transitions */
  /* 'yaapt:88'     'dp_w4',         0.9, ... % Weight factor for local costs */
  /* 'yaapt:89'     'end', -1); */
  /*  Select parameter set  */
  /*  if (nargin > 2 && ~isempty(VU) && VU == 0) */
  /*      Prm = Prm_aV; */
  /*  else  */
  /*      Prm = Prm_VU; */
  /*  end */
  /*  Not needed if ignoring gross error minimization */
  /*  Overwrite parameters if they are passed from command line(ExtrPar)   */
  /*  if ((nargin > 3) && isstruct(ExtrPrm)) */
  /*      fdNames = fieldnames(ExtrPrm); */
  /*      for n = 1:length(fdNames) */
  /*          pName = char(fdNames(n)); */
  /*          Prm.(pName) = ExtrPrm.(pName); */
  /*          %message('PT:det', 'Parameter %s replaced: %d', pName,Prm.(pName)); */
  /*      end */
  /*  end */
  /* Prm */
  /*  Whether to plot pitch tracks, spectrum, engergy, etc. */
  /*  GraphPar = 0; */
  /*  if (nargin > 4 && ~isempty(fig)) */
  /*      GraphPar = fig; */
  /*  end */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*   Step 1. Preprocessing */
  /*   Create the squared or absolute values of filtered speech data */
  /* 'yaapt:120' [DataB, DataC, DataD, nFs] = nonlinear(Data, Fs, Prm); */
  st.site = &emlrtRSI;

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
  /*  Creates the bandpass filters */
  /* 'nonlinear:48' lenDataA = length(DataA); */
  /*  filter F1 */
  /* 'nonlinear:51' w1  = (F_hp / (Fs/2)); */
  /* 'nonlinear:52' w2  = (F_lp / (Fs/2)); */
  /* 'nonlinear:53' w   = [w1 w2]; */
  w[0] = 50.0 / (Fs / 2.0);
  w[1] = 1500.0 / (Fs / 2.0);

  /* 'nonlinear:54' b_F1 = Myfir1(Filter_order,w); */
  b_st.site = &j_emlrtRSI;

  /* FIR1   FIR filter design using the window method.  */
  /*    B = FIR1(N,Wn) designs an N'th order lowpass FIR digital filter  */
  /*    and returns the filter coefficients in length N+1 vector B.  */
  /*    The cut-off frequency Wn must be between 0 < Wn < 1.0, with 1.0   */
  /*    corresponding to half the sample rate.  The filter B is real and  */
  /*    has linear phase, i.e., even symmetric coefficients obeying B(k) =  */
  /*    B(N+2-k), k = 1,2,...,N+1.  */
  /*   */
  /*    If Wn is a two-element vector, Wn = [W1 W2], FIR1 returns an  */
  /*    order N bandpass filter with passband  W1 < W < W2.  */
  /*    B = FIR1(N,Wn,'high') designs a highpass filter.  */
  /*    B = FIR1(N,Wn,'stop') is a bandstop filter if Wn = [W1 W2].  */
  /*   */
  /*    If Wn is a multi-element vector,   */
  /*           Wn = [W1 W2 W3 W4 W5 ... WN],  */
  /*    FIR1 returns an order N multiband filter with bands  */
  /*     0 < W < W1, W1 < W < W2, ..., WN < W < 1.  */
  /*    B = FIR1(N,Wn,'DC-1') makes the first band a passband.  */
  /*    B = FIR1(N,Wn,'DC-0') makes the first band a stopband.  */
  /*   */
  /*    For filters with a passband near Fs/2, e.g., highpass  */
  /*    and bandstop filters, N must be even.  */
  /*      */
  /*    By default FIR1 uses a Hamming window.  Other available windows,  */
  /*    including Boxcar, Hanning, Bartlett, Blackman, Kaiser and Chebwin  */
  /*    can be specified with an optional trailing argument.  For example,  */
  /*    B = FIR1(N,Wn,kaiser(N+1,4)) uses a Kaiser window with beta=4.  */
  /*    B = FIR1(N,Wn,'high',chebwin(N+1,R)) uses a Chebyshev window.  */
  /*   */
  /*    By default, the filter is scaled so the center of the first pass band   */
  /*    has magnitude exactly one after windowing. Use a trailing 'noscale'   */
  /*    argument to prevent this scaling, e.g. B = FIR1(N,Wn,'noscale'),   */
  /*    B = FIR1(N,Wn,'high','noscale'), B = FIR1(N,Wn,wind,'noscale').  */
  /*   */
  /*    See also KAISERORD, FIRCLS1, FIR2, FIRLS, FIRCLS, CREMEZ,  */
  /*             REMEZ, FREQZ, FILTER.  */
  /*    FIR1 is an M-file implementation of program 5.2 in the IEEE  */
  /*    Programs for Digital Signal Processing tape.   */
  /*    Author(s): L. Shure  */
  /*               L. Shure, 4-5-90, revised  */
  /*               T. Krauss, 3-5-96, revised  */
  /*    Copyright (c) 1988-98 by The MathWorks, Inc.  */
  /*    $Revision: 1.20 $  $Date: 1997/12/02 18:36:03 $  */
  /*    Reference(s):  */
  /*      [1] "Programs for Digital Signal Processing", IEEE Press  */
  /*          John Wiley & Sons, 1979, pg. 5.2-1.  */
  /*  nargchk(2,5,nargin);  */
  /*  Up to 3 optional input arguments, always in this order:  */
  /*    1 - Filter type flag, can be 'high', 'stop', '', 'DC-0', or 'DC-1'  */
  /*    2 - Window vector  */
  /*    3 - 'noscale' flag  */
  /*  default optional parameter values:  */
  /* 'Myfir1:60' Wind = []; */
  /*  Ftype = '';  */
  /*  Wind = [];  */
  /*  Scale = 'scale';  */
  /*  switch length(varargin)  */
  /*  case 1  */
  /*      if isstr(varargin{1})&(length(varargin{1})>0)  */
  /*          s = upper(varargin{1});  */
  /*          switch upper(s)  */
  /*          case {'SCALE','NOSCALE'}  */
  /*              Scale = s;  */
  /*          otherwise  */
  /*              Ftype = s;  */
  /*          end  */
  /*      else  */
  /*          Wind = varargin{1};  */
  /*      end  */
  /*  case 2  */
  /*      if isstr(varargin{1})  */
  /*          Ftype = varargin{1};  */
  /*      else  */
  /*          Wind = varargin{1};  */
  /*      end  */
  /*      if isstr(varargin{2})  */
  /*          Scale = varargin{2};  */
  /*      else  */
  /*          Wind = varargin{2};  */
  /*      end  */
  /*  case 3  */
  /*      Ftype = varargin{1};  */
  /*      Wind = varargin{2};  */
  /*      Scale = varargin{3};  */
  /*  end  */
  /*  switch upper(Scale)  */
  /*  case 'NOSCALE'  */
  /*      SCALING = 0;  */
  /*  case 'SCALE'  */
  /* 'Myfir1:99' SCALING = 1; */
  /*  otherwise  */
  /*      error('Scaling option must be ''noscale'' or ''scale''.')  */
  /*  end  */
  /* 'Myfir1:104' if isempty(N) | ~isnumeric(N) | ~isreal(N) | N~=round(N) | N<=0 */
  /*  Ftype = upper(Ftype);  */
  /*  if ~strncmp(Ftype,'HIGH',1) & ~strncmp(Ftype,'STOP',1) & ...  */
  /*     ~strncmp(Ftype,'DC-0',4) & ~strncmp(Ftype,'DC-1',4) & ...  */
  /*     ~isempty(Ftype)  */
  /*      error('Filter type must be ''high'',''stop'',''DC-0'', or ''DC-1''.')  */
  /*  end  */
  /* 'Myfir1:115' nw = length(Wind); */
  /* 'Myfir1:117' nbands = length(Wn) + 1; */
  /*  if (nbands > 2) & isempty(Ftype)  */
  /* 'Myfir1:119' if (nbands > 2) */
  /* 'Myfir1:120' Ftype = 'DC-0'; */
  /*  make sure default 3 band filter is bandpass  */
  /* 'Myfir1:122' First_Band = isempty(strfind('DC-0',Ftype)) & isempty(strfind('HIGH',Ftype)); */
  /* 'Myfir1:123' mags = rem( First_Band + (0:nbands-1), 2); */
  /* 'Myfir1:125' L = N + 1; */
  /* 'Myfir1:126' odd = rem(L, 2); */
  /*  if (mags(nbands) & ~odd)  */
  /*        disp('For highpass and bandstop filters, order must be even.')  */
  /*        disp('Order is being increased by 1.')  */
  /*        N = N + 1;  L = L + 1;  */
  /*        odd = 1;  */
  /*  end  */
  /* 'Myfir1:133' if nw ~= 0 & nw ~= L */
  /* 'Myfir1:136' if nw == 0 */
  /*  replace the following with the default window of your choice.  */
  /* 'Myfir1:137' Window = hamming(L); */
  /*   */
  /*  to use Kaiser window, beta must be supplied  */
  /*  att = 60; % dB of attenuation desired in sidelobe  */
  /*  beta = 0.1102*(att-8.7);  */
  /*  wind = kaiser(L,beta);  */
  /* 'Myfir1:145' if  any( Wn<0 | Wn>1 ) */
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(((w[k] < 0.0) || (w[k] > 1.0)) == 0)) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    c_st.site = &m_emlrtRSI;
    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    for (i = 0; i < 47; i++) {
      cv0[i] = cv1[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 47, m0, cv0);
    emlrtAssign(&b_y, m0);
    d_st.site = &dk_emlrtRSI;
    f_error(&d_st, b_y, &emlrtMCI);
  }

  /* 'Myfir1:148' if  any(diff(Wn)<0) */
  if (!((w[1] - w[0] < 0.0) == 0)) {
    c_st.site = &n_emlrtRSI;
    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    for (i = 0; i < 30; i++) {
      cv2[i] = cv3[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 30, m0, cv2);
    emlrtAssign(&c_y, m0);
    d_st.site = &dk_emlrtRSI;
    f_error(&d_st, c_y, &emlrtMCI);
  }

  /* 'Myfir1:152' Wn = Wn(:)'; */
  /* 'Myfir1:153' ff = [0,Wn(1:nbands-1); Wn(1:nbands-1),1]; */
  ff[0] = 0.0;
  for (i0 = 0; i0 < 2; i0++) {
    ff[(i0 + 1) << 1] = w[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    ff[1 + (i0 << 1)] = w[i0];
  }

  ff[5] = 1.0;

  /* 'Myfir1:154' mags = [mags(:)'; mags(:)']; */
  /*  hh_test = firls(L-1,ff(:),mags(:));  */
  /* 'Myfir1:156' hh = Myfirls(L-1,ff(:),mags(:)); */
  for (i0 = 0; i0 < 6; i0++) {
    b_ff[i0] = ff[i0];
  }

  c_st.site = &o_emlrtRSI;
  Myfirls(SD, &c_st, b_ff, hh);

  /* 'Myfir1:159' b = hh.*Window(:)'; */
  for (i0 = 0; i0 < 151; i0++) {
    hh[i0] *= dv0[i0];
  }

  /* 'Myfir1:160' a = 1; */
  /* 'Myfir1:162' if SCALING */
  /* 'Myfir1:163' if First_Band */
  /* 'Myfir1:165' else */
  /* 'Myfir1:166' if ff(4)==1 */
  if (ff[3] == 1.0) {
    /*  unity gain at Fs/2  */
    /* 'Myfir1:168' f0 = 1; */
    f0 = 1.0;
  } else {
    /* 'Myfir1:169' else */
    /*  unity gain at center of first passband  */
    /* 'Myfir1:171' f0 = mean(ff(3:4)); */
    f0 = (ff[2] + ff[3]) / 2.0;
  }

  /* 'Myfir1:173' b = b / abs( exp(-j*2*pi*(0:L-1)*(f0/2))*(b.') ); */
  f0 /= 2.0;
  for (i0 = 0; i0 < 151; i0++) {
    x[i0].re = f0 * -0.0;
    x[i0].im = f0 * (-6.2831853071795862 * (real_T)i0);
    r = muDoubleScalarExp(x[i0].re / 2.0);
    x_im = x[i0].im;
    x[i0].re = r * (r * muDoubleScalarCos(x[i0].im));
    x[i0].im = r * (r * muDoubleScalarSin(x_im));
  }

  f0 = 0.0;
  r = 0.0;
  for (i0 = 0; i0 < 151; i0++) {
    f0 += x[i0].re * hh[i0] - x[i0].im * 0.0;
    r += x[i0].re * 0.0 + x[i0].im * hh[i0];
  }

  f0 = muDoubleScalarHypot(f0, r);
  for (i0 = 0; i0 < 151; i0++) {
    hh[i0] /= f0;
  }

  emxInit_real_T(&b_st, &tempData, 2, &c_emlrtRTEI, true);

  /*   b_F1_test = fir1(Filter_order,w); */
  /* 'nonlinear:56' a   = 1; */
  /* filtering the original data with the bandpass filter, */
  /*  DataA   is original acoustic signal */
  /*  Original signal filtered with F1 */
  /* 'nonlinear:63' tempData = filter(b_F1,a,DataA); */
  b_st.site = &k_emlrtRSI;
  filter(&b_st, hh, Data, tempData);

  /*  LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  /* 'nonlinear:65' DataB = tempData(1:dec_factor:lenDataA); */
  if (1 > Data->size[1]) {
    loop_ub = 0;
  } else {
    i0 = tempData->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &r_emlrtBCI, &st);
    i0 = tempData->size[1];
    i1 = Data->size[1];
    loop_ub = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &r_emlrtBCI, &st);
  }

  emxInit_real_T(&st, &DataB, 2, &emlrtRTEI, true);
  i0 = DataB->size[0] * DataB->size[1];
  DataB->size[0] = 1;
  DataB->size[1] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)DataB, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    DataB->data[DataB->size[0] * i0] = tempData->data[i0];
  }

  /*    Create nonlinear version of signal */
  /*    Original signal */
  /*    DataC =  DataA; */
  /*    Absoulte value of the signal */
  /*    DataC =  abs(DataA); */
  /*    Squared value of the signal */
  /* 'nonlinear:75' DataC =  DataA .^2; */
  for (i0 = 0; i0 < 2; i0++) {
    w[i0] = Data->size[i0];
  }

  i0 = tempData->size[0] * tempData->size[1];
  tempData->size[0] = 1;
  tempData->size[1] = (int32_T)w[1];
  emxEnsureCapacity(&st, (emxArray__common *)tempData, i0, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  for (k = 0; k < (int32_T)w[1]; k++) {
    tempData->data[k] = Data->data[k] * Data->data[k];
  }

  emxInit_real_T(&st, &b_tempData, 2, &emlrtRTEI, true);

  /*    Nonlinear version filtered with F1 */
  /* 'nonlinear:79' tempData = filter(b_F1,a,DataC); */
  i0 = b_tempData->size[0] * b_tempData->size[1];
  b_tempData->size[0] = 1;
  b_tempData->size[1] = tempData->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_tempData, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = tempData->size[0] * tempData->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_tempData->data[i0] = tempData->data[i0];
  }

  b_st.site = &l_emlrtRSI;
  filter(&b_st, hh, b_tempData, tempData);

  /* 'nonlinear:80' LenData_dec = fix ((lenDataA+dec_factor-1)/dec_factor); */
  /* 'nonlinear:81' DataD = zeros(1, LenData_dec); */
  /* 'nonlinear:82' DataD = tempData(1:dec_factor:lenDataA); */
  emxFree_real_T(&b_tempData);
  if (1 > Data->size[1]) {
    loop_ub = 0;
  } else {
    i0 = tempData->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &q_emlrtBCI, &st);
    i0 = tempData->size[1];
    i1 = Data->size[1];
    loop_ub = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &q_emlrtBCI, &st);
  }

  emxInit_real_T(&st, &DataD, 2, &emlrtRTEI, true);
  i0 = DataD->size[0] * DataD->size[1];
  DataD->size[0] = 1;
  DataD->size[1] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)DataD, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    DataD->data[DataD->size[0] * i0] = tempData->data[i0];
  }

  /* 'nonlinear:84' newFs = Fs/dec_factor; */
  /*   Check frame size, frame jump and the number of frames for nonlinear singal */
  /* 'yaapt:123' nframesize = fix(Prm.frame_length*nFs/1000); */
  f0 = 25.0 * Fs / 1000.0;
  if (f0 < 0.0) {
    f0 = muDoubleScalarCeil(f0);
  } else {
    f0 = muDoubleScalarFloor(f0);
  }

  /* 'yaapt:124' if (nframesize < 15) */
  if (f0 < 15.0) {
    /* 'yaapt:125' error('Frame length value %d is too short', Prm.frame_length); */
    st.site = &b_emlrtRSI;
    d_y = NULL;
    m0 = emlrtCreateCharArray(2, iv2);
    for (i = 0; i < 34; i++) {
      cv4[i] = cv5[i];
    }

    emlrtInitCharArrayR2013a(&st, 34, m0, cv4);
    emlrtAssign(&d_y, m0);
    b_st.site = &dk_emlrtRSI;
    g_error(&b_st, d_y, emlrt_marshallOut(25.0), &emlrtMCI);
  }

  /* 'yaapt:127' if (nframesize > 2048) */
  if (f0 > 2048.0) {
    /* 'yaapt:128' error('Frame length value %d exceeds the limit', Prm.frame_length); */
    st.site = &c_emlrtRSI;
    e_y = NULL;
    m0 = emlrtCreateCharArray(2, iv3);
    for (i = 0; i < 39; i++) {
      cv6[i] = cv7[i];
    }

    emlrtInitCharArrayR2013a(&st, 39, m0, cv6);
    emlrtAssign(&e_y, m0);
    b_st.site = &dk_emlrtRSI;
    g_error(&b_st, e_y, emlrt_marshallOut(25.0), &emlrtMCI);
  }

  emxInit_real_T(sp, &Energy, 2, &emlrtRTEI, true);
  emxInit_boolean_T(sp, &VUVEnergy, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_DataD, 2, &emlrtRTEI, true);

  /*   Step 2. Spectral pitch tracking */
  /*   Calculate NLFER and determine voiced/unvoiced frames with NLFER */
  /* 'yaapt:133' [Energy, VUVEnergy]= nlfer(DataB, nFs, Prm); */
  st.site = &d_emlrtRSI;
  nlfer(&st, DataB, Fs, Energy, VUVEnergy);

  /*   Calculate an approximate pitch track from the spectrum. */
  /*   At this point, SPitch is best estimate of pitch track from spectrum */
  /* 'yaapt:137' [SPitch, VUVSPitch, pAvg, pStd]= spec_trk(DataD, nFs, VUVEnergy, Prm); */
  i0 = b_DataD->size[0] * b_DataD->size[1];
  b_DataD->size[0] = 1;
  b_DataD->size[1] = DataD->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DataD, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = DataD->size[0] * DataD->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_DataD->data[i0] = DataD->data[i0];
  }

  emxInit_real_T(sp, &SPitch, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TPitch1, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TMerit1, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TPitch2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &TMerit2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &RPitch, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &Merit, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_Merit, 2, &emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  spec_trk(SD, &st, b_DataD, Fs, VUVEnergy, SPitch, tempData, pAvg_data,
           pAvg_size, pStd_data, pStd_size);

  /*   Step 3. Temporal pitch tracking based on NCCF */
  /*   Calculate a pitch track based on time-domain processing */
  /*   Pitch tracking from the filterd original signal  */
  /* 'yaapt:143' [TPitch1, TMerit1] = tm_trk(DataB, nFs, SPitch, pStd, pAvg, Prm); */
  st.site = &f_emlrtRSI;
  tm_trk(&st, DataB, Fs, SPitch, pStd_data, pStd_size, TPitch1, TMerit1);

  /*   Pitch tracking from the filterd nonlinear signal  */
  /* 'yaapt:146' [TPitch2, TMerit2] = tm_trk(DataD, nFs, SPitch, pStd, pAvg, Prm); */
  st.site = &g_emlrtRSI;
  tm_trk(&st, DataD, Fs, SPitch, pStd_data, pStd_size, TPitch2, TMerit2);

  /*  Refine pitch candidates  */
  /* 'yaapt:149' [RPitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, ... */
  /* 'yaapt:150'                         Energy, VUVEnergy, Prm); */
  st.site = &h_emlrtRSI;

  /*  REFINE Refine pitch candidates for YAAPT Pitch tracking */
  /*  */
  /*  [Pitch, Merit] = refine(TPitch1, TMerit1, TPitch2, TMerit2, SPitch, Energy, VUVEnergy, Prm) */
  /*    refins pitch cadidates obtained from NCCF using spectral pitch */
  /*    track and NLFER energy information. */
  /*  */
  /*  INPUTS:  */
  /*    TPitch1:  Pitch candidates array 1 */
  /*    TMerti1:  Merits for pitch candidates array 1 */
  /*    TPitch2:  Pitch candidates array 2 */
  /*    TMerti2:  Merits for pitch candidates array 2 */
  /*    SPitch:   Smoothed spectral pitch track */
  /*    Energy:   NLFER Energy information */
  /*    VUVEnergy: Voiced/Unvoiced information determined by NLFER energy */
  /*    Prm:      Parameters */
  /*  */
  /*  OUTPUTS: */
  /*    Pitch:   Refined overall pitch candidates */
  /*    Merit:   Merit for overall pitch candidates */
  /*    Creation: July 27 2007 */
  /*    Author:   Hongbing Hu */
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
  /* -- PARAMETERS ---------------------------------------------------------------- */
  /*  Threshold for NLFER energy */
  /* 'refine:39' nlfer_thresh2  = Prm.nlfer_thresh2; */
  /* 'refine:40' Merit_pivot = Prm.merit_pivot; */
  /* -- MAIN ROUTINE -------------------------------------------------------------- */
  /*  Merge pitch candidates and their merits from two types of the signal */
  /* 'refine:45' Pitch = cat(1,TPitch1, TPitch2); */
  b_st.site = &si_emlrtRSI;
  cat(&b_st, TPitch1, TPitch2, RPitch);

  /* 'refine:46' Merit = cat(1,TMerit1, TMerit2); */
  b_st.site = &ri_emlrtRSI;
  cat(&b_st, TMerit1, TMerit2, Merit);

  /*   The rate/pitch arrays and the merit arrays are now arranged */
  /*   according to the index of the sorted Merit. */
  /* 'refine:50' [maxcands, numframes] = size(Pitch); */
  maxcands = RPitch->size[0];
  numframes = RPitch->size[1] - 1;

  /* 'refine:51' [Merit, Idx] = sort(Merit, 'descend'); */
  b_st.site = &qi_emlrtRSI;
  i0 = b_Merit->size[0] * b_Merit->size[1];
  b_Merit->size[0] = Merit->size[0];
  b_Merit->size[1] = Merit->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)b_Merit, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = Merit->size[0] * Merit->size[1];
  emxFree_real_T(&b_DataD);
  emxFree_real_T(&TMerit2);
  emxFree_real_T(&TPitch2);
  emxFree_real_T(&TMerit1);
  emxFree_real_T(&TPitch1);
  emxFree_real_T(&DataB);
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_Merit->data[i0] = Merit->data[i0];
  }

  emxInit_real_T(&b_st, &Idx, 2, &emlrtRTEI, true);
  b_emxInit_int32_T(&b_st, &iidx, 2, &emlrtRTEI, true);
  c_st.site = &wf_emlrtRSI;
  e_eml_sort(&c_st, b_Merit, Merit, iidx);
  i0 = Idx->size[0] * Idx->size[1];
  Idx->size[0] = iidx->size[0];
  Idx->size[1] = iidx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)Idx, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = iidx->size[0] * iidx->size[1];
  emxFree_real_T(&b_Merit);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Idx->data[i0] = iidx->data[i0];
  }

  emxFree_int32_T(&iidx);

  /* 'refine:52' for n=1:numframes */
  k = 0;
  b_emxInit_real_T(&st, &r0, 1, &emlrtRTEI, true);
  emxInit_int32_T(&st, &r1, 1, &emlrtRTEI, true);
  b_emxInit_real_T(&st, &b_RPitch, 1, &emlrtRTEI, true);
  while (k <= numframes) {
    /* 'refine:53' Pitch(:,n) = Pitch(Idx(:,n),n); */
    loop_ub = RPitch->size[0];
    i0 = r1->size[0];
    r1->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r1->data[i0] = i0;
    }

    i0 = RPitch->size[1];
    i1 = k + 1;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &f_emlrtBCI, &st);
    loop_ub = Idx->size[0];
    i0 = Idx->size[1];
    i1 = 1 + k;
    i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &d_emlrtBCI, &st);
    i1 = RPitch->size[1];
    i2 = 1 + k;
    i1 = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &e_emlrtBCI, &st);
    i2 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i2, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i2 = 0; i2 < loop_ub; i2++) {
      i3 = RPitch->size[0];
      i = (int32_T)Idx->data[i2 + Idx->size[0] * (i0 - 1)];
      r0->data[i2] = RPitch->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i3,
        &rb_emlrtBCI, &st) + RPitch->size[0] * (i1 - 1)) - 1];
    }

    iv4[0] = r1->size[0];
    loop_ub = Idx->size[0];
    i0 = b_RPitch->size[0];
    b_RPitch->size[0] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)b_RPitch, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_RPitch->data[i0] = RPitch->data[((int32_T)Idx->data[i0 + Idx->size[0] *
        k] + RPitch->size[0] * k) - 1];
    }

    c_RPitch[0] = b_RPitch->size[0];
    emlrtSubAssignSizeCheckR2012b(iv4, 1, c_RPitch, 1, &b_emlrtECI, &st);
    loop_ub = r0->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      RPitch->data[r1->data[i0] + RPitch->size[0] * k] = r0->data[i0];
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
  }

  emxFree_real_T(&b_RPitch);
  emxFree_real_T(&r0);
  emxFree_real_T(&Idx);
  emxInit_real_T(&st, &d_RPitch, 2, &emlrtRTEI, true);

  /*  A best pitch track is generated from the best candidates */
  /* 'refine:57' BestPitch = Mymedfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  b_st.site = &pi_emlrtRSI;

  /* MEDFILT1       One-dimensional median filter */
  /*  */
  /*        y = MEDFILT(x) */
  /*        y = MEDFILT(x, w) */
  /*  */
  /*        median filter the signal with window of width W (default is 5). */
  /*  Copyright (C) 1995-2009, by Peter I. Corke */
  /*  */
  /*  This file is part of The Machine Vision Toolbox for Matlab (MVTB). */
  /*   */
  /*  MVTB is free software: you can redistribute it and/or modify */
  /*  it under the terms of the GNU Lesser General Public License as published by */
  /*  the Free Software Foundation, either version 3 of the License, or */
  /*  (at your option) any later version. */
  /*   */
  /*  MVTB is distributed in the hope that it will be useful, */
  /*  but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*  GNU Lesser General Public License for more details. */
  /*   */
  /*  You should have received a copy of the GNU Leser General Public License */
  /*  along with MVTB.  If not, see <http://www.gnu.org/licenses/>. */
  /* 'Mymedfilt1:25' if nargin == 1 */
  /* 'Mymedfilt1:29' s = s(:)'; */
  loop_ub = RPitch->size[1];
  k = RPitch->size[1];
  i0 = d_RPitch->size[0] * d_RPitch->size[1];
  d_RPitch->size[0] = 1;
  d_RPitch->size[1] = k;
  emxEnsureCapacity(&b_st, (emxArray__common *)d_RPitch, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  for (i0 = 0; i0 < k; i0++) {
    d_RPitch->data[d_RPitch->size[0] * i0] = RPitch->data[RPitch->size[0] * i0];
  }

  i0 = DataD->size[0] * DataD->size[1];
  DataD->size[0] = 1;
  DataD->size[1] = loop_ub;
  emxEnsureCapacity(&b_st, (emxArray__common *)DataD, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    DataD->data[DataD->size[0] * i0] = d_RPitch->data[i0];
  }

  emxFree_real_T(&d_RPitch);
  emxInit_real_T(&b_st, &m, 2, &d_emlrtRTEI, true);

  /* 'Mymedfilt1:30' w2 = floor(w/2); */
  /* 'Mymedfilt1:31' w = 2*w2 + 1; */
  /* 'Mymedfilt1:33' n = length(s); */
  /* 'Mymedfilt1:34' m = zeros(w,n+w-1); */
  i0 = m->size[0] * m->size[1];
  m->size[0] = 7;
  emxEnsureCapacity(&b_st, (emxArray__common *)m, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  k = (int32_T)(((real_T)DataD->size[1] + 7.0) - 1.0);
  i0 = m->size[0] * m->size[1];
  m->size[1] = k;
  emxEnsureCapacity(&b_st, (emxArray__common *)m, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = 7 * (int32_T)(((real_T)DataD->size[1] + 7.0) - 1.0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    m->data[i0] = 0.0;
  }

  /* 'Mymedfilt1:35' s0 = s(1); */
  i0 = DataD->size[1];
  emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &c_emlrtBCI, &b_st);

  /* 'Mymedfilt1:35' sl = s(n); */
  i0 = DataD->size[1];
  i1 = DataD->size[1];
  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &b_emlrtBCI, &b_st);

  /* 'Mymedfilt1:37' for i=0:(w-1) */
  for (i = 0; i < 7; i++) {
    /* 'Mymedfilt1:38' m(i+1,:) = [s0*ones(1,i) s sl*ones(1,w-i-1)]; */
    loop_ub = m->size[1];
    i0 = r1->size[0];
    r1->size[0] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r1->data[i0] = i0;
    }

    f0 = DataD->data[0];
    r = DataD->data[DataD->size[1] - 1];
    k = 6 - i;
    i0 = tempData->size[0] * tempData->size[1];
    tempData->size[0] = 1;
    tempData->size[1] = (i + DataD->size[1]) + k;
    emxEnsureCapacity(&b_st, (emxArray__common *)tempData, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (i0 = 0; i0 < i; i0++) {
      tempData->data[tempData->size[0] * i0] = f0;
    }

    loop_ub = DataD->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      tempData->data[tempData->size[0] * (i0 + i)] = DataD->data[DataD->size[0] *
        i0];
    }

    for (i0 = 0; i0 < k; i0++) {
      tempData->data[tempData->size[0] * ((i0 + i) + DataD->size[1])] = r;
    }

    c_tempData[0] = 1;
    c_tempData[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(c_tempData, 2, *(int32_T (*)[2])tempData->size,
      2, &emlrtECI, &b_st);
    loop_ub = tempData->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      m->data[i + m->size[0] * r1->data[i0]] = tempData->data[tempData->size[0] *
        i0];
    }

    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &b_st);
  }

  /* 'Mymedfilt1:40' m = median(m); */
  c_st.site = &ig_emlrtRSI;
  b_median(&c_st, m, tempData);

  /* 'Mymedfilt1:41' m = m(w2+1:w2+n); */
  emxFree_real_T(&m);
  if (4U > 3U + DataD->size[1]) {
    i0 = 0;
    i1 = 0;
  } else {
    i0 = 3;
    i1 = tempData->size[1];
    i2 = (int32_T)(3U + DataD->size[1]);
    i1 = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &emlrtBCI, &b_st);
  }

  emxFree_real_T(&DataD);
  emxInit_real_T(&b_st, &d_tempData, 2, &emlrtRTEI, true);
  i2 = d_tempData->size[0] * d_tempData->size[1];
  d_tempData->size[0] = 1;
  d_tempData->size[1] = i1 - i0;
  emxEnsureCapacity(&b_st, (emxArray__common *)d_tempData, i2, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = i1 - i0;
  for (i1 = 0; i1 < loop_ub; i1++) {
    d_tempData->data[d_tempData->size[0] * i1] = tempData->data[i0 + i1];
  }

  i0 = tempData->size[0] * tempData->size[1];
  tempData->size[0] = 1;
  tempData->size[1] = d_tempData->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)tempData, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = d_tempData->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    tempData->data[tempData->size[0] * i0] = d_tempData->data[d_tempData->size[0]
      * i0];
  }

  emxFree_real_T(&d_tempData);
  for (i0 = 0; i0 < 2; i0++) {
    c_tempData[i0] = tempData->size[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    b_VUVEnergy[i0] = VUVEnergy->size[i0];
  }

  emlrtSizeEqCheck2DFastR2012b(c_tempData, b_VUVEnergy, &c_emlrtECI, &st);
  i0 = tempData->size[0] * tempData->size[1];
  tempData->size[0] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)tempData, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  k = tempData->size[0];
  i = tempData->size[1];
  loop_ub = k * i;
  for (i0 = 0; i0 < loop_ub; i0++) {
    tempData->data[i0] *= (real_T)VUVEnergy->data[i0];
  }

  emxFree_boolean_T(&VUVEnergy);

  /*  BestPitch_test = medfilt1(Pitch(1,:), Prm.median_value).*VUVEnergy; */
  /*  Refine pitch candidates */
  /* 'refine:61' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'refine:62' if (Energy(i)<=nlfer_thresh2) */
    i0 = Energy->size[1];
    if (Energy->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &cb_emlrtBCI,
         &st) - 1] <= 0.1) {
      /* Definitely unvoiced, all candidates will be unvoiced  with high merit */
      /* 'refine:64' Pitch(:,i) = 0; */
      loop_ub = RPitch->size[0];
      k = RPitch->size[1];
      emlrtDynamicBoundsCheckFastR2012b(i, 1, k, &g_emlrtBCI, &st);
      for (i0 = 0; i0 < loop_ub; i0++) {
        RPitch->data[i0 + RPitch->size[0] * (i - 1)] = 0.0;
      }

      /* 'refine:65' Merit(:,i) = Merit_pivot; */
      loop_ub = Merit->size[0];
      k = Merit->size[1];
      emlrtDynamicBoundsCheckFastR2012b(i, 1, k, &h_emlrtBCI, &st);
      for (i0 = 0; i0 < loop_ub; i0++) {
        Merit->data[i0 + Merit->size[0] * (i - 1)] = 0.99;
      }
    } else {
      /* 'refine:66' else */
      /* 'refine:67' if (Pitch(1,i) > 0) */
      i0 = RPitch->size[1];
      if (RPitch->data[RPitch->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i, 1,
            i0, &db_emlrtBCI, &st) - 1)] > 0.0) {
        /*  already have the voiced candidate, Want to have at */
        /*  least one unvoiced candidate */
        /* 'refine:70' Pitch(maxcands,i) = 0.0; */
        i0 = RPitch->size[0];
        i1 = RPitch->size[1];
        RPitch->data[(emlrtDynamicBoundsCheckFastR2012b(maxcands, 1, i0,
          &ib_emlrtBCI, &st) + RPitch->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(i, 1, i1, &jb_emlrtBCI,
          &st) - 1)) - 1] = 0.0;

        /* 'refine:71' Merit(maxcands,i) = (1 - Merit(1,i)) ; */
        i0 = Merit->size[0];
        i1 = Merit->size[1];
        i2 = Merit->size[1];
        Merit->data[(emlrtDynamicBoundsCheckFastR2012b(maxcands, 1, i0,
          &kb_emlrtBCI, &st) + Merit->size[0] *
                     (emlrtDynamicBoundsCheckFastR2012b(i, 1, i1, &lb_emlrtBCI,
          &st) - 1)) - 1] = 1.0 - Merit->data[Merit->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &mb_emlrtBCI, &st) - 1)];

        /* 'refine:72' for j = 2:maxcands-1 */
        k = 2;
        while (k - 2 <= maxcands - 3) {
          /* 'refine:73' if (Pitch(j,i) == 0) */
          i0 = RPitch->size[0];
          i1 = RPitch->size[1];
          if (RPitch->data[(emlrtDynamicBoundsCheckFastR2012b(k, 1, i0,
                &nb_emlrtBCI, &st) + RPitch->size[0] *
                            (emlrtDynamicBoundsCheckFastR2012b(i, 1, i1,
                 &ob_emlrtBCI, &st) - 1)) - 1] == 0.0) {
            /* 'refine:74' Merit(j,i) = 0.0; */
            i0 = Merit->size[0];
            i1 = Merit->size[1];
            Merit->data[(emlrtDynamicBoundsCheckFastR2012b(k, 1, i0,
              &pb_emlrtBCI, &st) + Merit->size[0] *
                         (emlrtDynamicBoundsCheckFastR2012b(i, 1, i1,
              &qb_emlrtBCI, &st) - 1)) - 1] = 0.0;
          }

          k++;
          emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
        }
      } else {
        /* 'refine:77' else */
        /*  there was no voiced candidate from nccf fill in */
        /*  option for F0 from spectrogram */
        /* 'refine:80' Pitch(1,i)  = SPitch(i); */
        i0 = RPitch->size[1];
        i1 = SPitch->size[1];
        RPitch->data[RPitch->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i, 1,
          i0, &eb_emlrtBCI, &st) - 1)] = SPitch->
          data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i1, &fb_emlrtBCI, &st) -
          1];

        /* 'refine:81' Merit(1,i) = min(1, Energy(i)/2); */
        i0 = Energy->size[1];
        i1 = (i - 1) + 1;
        emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &i_emlrtBCI, &st);
        i0 = Merit->size[1];
        Merit->data[Merit->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i, 1, i0,
          &gb_emlrtBCI, &st) - 1)] = muDoubleScalarMin(1.0, Energy->data[i - 1] /
          2.0);

        /*  all other candidates will be unvoiced */
        /*  with low merit */
        /* 'refine:85' Pitch(2:maxcands,i) = 0.0; */
        i0 = RPitch->size[0];
        emlrtDynamicBoundsCheckFastR2012b(maxcands, 1, i0, &j_emlrtBCI, &st);
        k = RPitch->size[1];
        emlrtDynamicBoundsCheckFastR2012b(i, 1, k, &k_emlrtBCI, &st);
        loop_ub = maxcands - 1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          RPitch->data[(i0 + RPitch->size[0] * (i - 1)) + 1] = 0.0;
        }

        /* 'refine:86' Merit(2:maxcands,i) = 1 - Merit(1,i); */
        i0 = Merit->size[0];
        emlrtDynamicBoundsCheckFastR2012b(maxcands, 1, i0, &l_emlrtBCI, &st);
        k = Merit->size[1];
        emlrtDynamicBoundsCheckFastR2012b(i, 1, k, &m_emlrtBCI, &st);
        k = Merit->size[1];
        f0 = Merit->data[Merit->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i,
          1, k, &hb_emlrtBCI, &st) - 1)];
        loop_ub = maxcands - 1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          Merit->data[(i0 + Merit->size[0] * (i - 1)) + 1] = 1.0 - f0;
        }
      }
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
  }

  /*   Insert some good values  from the track that appears */
  /*    the best, without dp, including both F0   and VUV info */
  /* 'refine:93' for i = 1:numframes */
  i = 1;
  while (i - 1 <= numframes) {
    /* 'refine:94' Pitch(maxcands-1,i) = BestPitch(1,i); */
    i0 = RPitch->size[0];
    i1 = maxcands - 1;
    i2 = RPitch->size[1];
    i3 = tempData->size[1];
    RPitch->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &s_emlrtBCI, &st)
                  + RPitch->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i, 1,
      i2, &t_emlrtBCI, &st) - 1)) - 1] = tempData->data[tempData->size[0] *
      (emlrtDynamicBoundsCheckFastR2012b(i, 1, i3, &u_emlrtBCI, &st) - 1)];

    /*   if this candidate was voiced, already have it, along with merit */
    /*   if unvoiced, need to assign appropriate merit */
    /* 'refine:98' if (BestPitch(1,i) > 0) */
    i0 = tempData->size[1];
    if (tempData->data[tempData->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i,
          1, i0, &v_emlrtBCI, &st) - 1)] > 0.0) {
      /*  voiced */
      /* 'refine:99' Merit(maxcands-1,i) = Merit(1,i); */
      i0 = Merit->size[0];
      i1 = maxcands - 1;
      i2 = Merit->size[1];
      i3 = Merit->size[1];
      Merit->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &y_emlrtBCI, &st)
                   + Merit->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i, 1,
        i2, &ab_emlrtBCI, &st) - 1)) - 1] = Merit->data[Merit->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i, 1, i3, &bb_emlrtBCI, &st) - 1)];
    } else {
      /* 'refine:100' else */
      /*  unvoiced */
      /* 'refine:101' Merit(maxcands-1,i) = 1-min(1, Energy(i)/2); */
      i0 = Energy->size[1];
      i1 = (i - 1) + 1;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &n_emlrtBCI, &st);
      i0 = Merit->size[0];
      i1 = maxcands - 1;
      i2 = Merit->size[1];
      Merit->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &w_emlrtBCI, &st)
                   + Merit->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i, 1,
        i2, &x_emlrtBCI, &st) - 1)) - 1] = 1.0 - muDoubleScalarMin(1.0,
        Energy->data[i - 1] / 2.0);
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, &st);
  }

  /*   Copy over the SPitch array */
  /* 'refine:106' Pitch(maxcands-2,:) = SPitch; */
  i0 = RPitch->size[0];
  i1 = (int32_T)((real_T)maxcands - 2.0);
  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &o_emlrtBCI, &st);
  loop_ub = RPitch->size[1];
  i0 = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    r1->data[i0] = i0;
  }

  iv5[0] = 1;
  iv5[1] = r1->size[0];
  emlrtSubAssignSizeCheckR2012b(iv5, 2, *(int32_T (*)[2])SPitch->size, 2,
    &d_emlrtECI, &st);
  loop_ub = SPitch->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    RPitch->data[(maxcands + RPitch->size[0] * r1->data[i0]) - 3] = SPitch->
      data[SPitch->size[0] * i0];
  }

  emxFree_real_T(&SPitch);

  /* 'refine:107' Merit(maxcands-2,:) = Energy/5; */
  i0 = Merit->size[0];
  i1 = (int32_T)((real_T)maxcands - 2.0);
  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &p_emlrtBCI, &st);
  loop_ub = Merit->size[1];
  i0 = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    r1->data[i0] = i0;
  }

  i0 = tempData->size[0] * tempData->size[1];
  tempData->size[0] = 1;
  tempData->size[1] = Energy->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)tempData, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = Energy->size[0] * Energy->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    tempData->data[i0] = Energy->data[i0] / 5.0;
  }

  iv6[0] = 1;
  iv6[1] = r1->size[0];
  emlrtSubAssignSizeCheckR2012b(iv6, 2, *(int32_T (*)[2])tempData->size, 2,
    &e_emlrtECI, &st);
  loop_ub = tempData->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Merit->data[(maxcands + Merit->size[0] * r1->data[i0]) - 3] = tempData->
      data[tempData->size[0] * i0];
  }

  emxFree_int32_T(&r1);
  emxFree_real_T(&tempData);

  /* ============================================================================== */
  /*  Step 5. Use dyanamic programming to determine the final pitch */
  /* 'yaapt:153' Pitch  = dynamic(RPitch, Merit, Energy, Prm); */
  st.site = &i_emlrtRSI;
  dynamic(&st, RPitch, Merit, Energy, Pitch);

  /* 'yaapt:154' numfrms = length(Pitch); */
  *numfrms = Pitch->size[1];

  /* 'yaapt:155' frmrate = Prm.frame_space; */
  *frmrate = 10.0;

  /* figure(3) */
  /*  plot(SPitch, 'b') */
  /*  hold on */
  /*  plot(Pitch, 'r') */
  /*  hold off */
  /*  title ('spectral pitch track') */
  /*  pause */
  /*   If VU = 0,  be sure entire track is voiced */
  /*      if (VU == 0)      %  Only applies if we want all voiced track     */
  /*         IDX_unvoiced = (Pitch < 1); */
  /*           Num_UV       = sum (IDX_unvoiced);    % Total number unvoiced frames */
  /*            if (Num_UV > 0)  */
  /*              for n = 1:numfrms;    %  there should be a more efficient way to do this */
  /*                 if (IDX_unvoiced(n) == 1); */
  /*                   Pitch(n) = SPitch(n); */
  /*                  end;   */
  /*              end;  */
  /*            end;   */
  /*       end; */
  /*  Replace above VU = 0 section for new ptch_fix() function */
  /*  if (VU==0) */
  /*      Pitch = ptch_fix(Pitch); */
  /*  end */
  /*  Pitch = SPitch;   % to see how good spectral track is */
  /* == FIGURE ==================================================================== */
  /*   Several plots to illustrate processing and performance */
  /*  if (GraphPar)      */
  /*      pt_figs(DataB, DataD, nFs, SPitch, Energy, VUVEnergy, RPitch, Pitch, Prm); */
  /*  end */
  /* ============================================================================== */
  emxFree_real_T(&Merit);
  emxFree_real_T(&RPitch);
  emxFree_real_T(&Energy);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (yaapt.c) */
