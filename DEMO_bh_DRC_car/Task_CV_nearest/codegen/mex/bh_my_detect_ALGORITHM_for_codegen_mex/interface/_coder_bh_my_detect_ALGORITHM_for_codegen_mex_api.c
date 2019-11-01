/*
 * _coder_bh_my_detect_ALGORITHM_for_codegen_mex_api.c
 *
 * Code generation for function '_coder_bh_my_detect_ALGORITHM_for_codegen_mex_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_mex_api.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_emxutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRTEInfo de_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_bh_my_detect_ALGORITHM_for_codegen_mex_api",/* fName */
  ""                                   /* pName */
};

static const char * sv0[8] = { "BW", "NUM_ROWS", "NUM_COLS", "tip_upper_xy_col",
  "tip_lower_xy_col", "m", "c", "tf_is_detected" };

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[230400];
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const struct2_T *
  u);
static boolean_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tf_do_init, const char_T *identifier);
static const mxArray *c_emlrt_marshallOut(const struct3_T *u);
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static const mxArray *d_emlrt_marshallOut(const real_T u[2]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *marker_s,
  const char_T *identifier, struct0_T *y);
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *I, const
  char_T *identifier))[230400];
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct1_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *BLUE_s,
  const char_T *identifier, struct3_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, boolean_T y[76800]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fract_for_top_mask, const char_T *identifier);
static uint8_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[230400];
static boolean_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, boolean_T ret[76800]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);

/* Function Definitions */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[230400]
{
  uint8_T (*y)[230400];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const
  struct2_T *u)
{
  const mxArray *y;
  emxArray_boolean_T *b_u;
  static const char * sv1[7] = { "BW", "NUM_ROWS", "NUM_COLS",
    "left_edge_xy_col", "right_edge_xy_col", "centroid_xy_col", "tf_is_detected"
  };

  int32_T i;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m4;
  static const int32_T iv16[1] = { 2 };

  real_T *pData;
  static const int32_T iv17[1] = { 2 };

  static const int32_T iv18[1] = { 2 };

  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_u, 2, (emlrtRTEInfo *)NULL, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 7, sv1));
  i = b_u->size[0] * b_u->size[1];
  b_u->size[0] = u->BW->size[0];
  b_u->size[1] = 320;
  emxEnsureCapacity_boolean_T(sp, b_u, i, (emlrtRTEInfo *)NULL);
  loop_ub = u->BW->size[0] * u->BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_u->data[i] = u->BW->data[i];
  }

  b_y = NULL;
  m4 = emlrtCreateLogicalArray(2, *(int32_T (*)[2])b_u->size);
  emlrtInitLogicalArray(u->BW->size[0] * 320, m4, b_u->data);
  emlrtAssign(&b_y, m4);
  emlrtSetFieldR2017b(y, 0, "BW", b_y, 0);
  b_y = NULL;
  m4 = emlrtCreateDoubleScalar(u->NUM_ROWS);
  emlrtAssign(&b_y, m4);
  emlrtSetFieldR2017b(y, 0, "NUM_ROWS", b_y, 1);
  b_y = NULL;
  m4 = emlrtCreateDoubleScalar(u->NUM_COLS);
  emlrtAssign(&b_y, m4);
  emlrtSetFieldR2017b(y, 0, "NUM_COLS", b_y, 2);
  b_y = NULL;
  m4 = emlrtCreateNumericArray(1, iv16, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m4);
  emxFree_boolean_T(&b_u);
  for (i = 0; i < 2; i++) {
    pData[i] = u->left_edge_xy_col[i];
  }

  emlrtAssign(&b_y, m4);
  emlrtSetFieldR2017b(y, 0, "left_edge_xy_col", b_y, 3);
  b_y = NULL;
  m4 = emlrtCreateNumericArray(1, iv17, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m4);
  for (i = 0; i < 2; i++) {
    pData[i] = u->right_edge_xy_col[i];
  }

  emlrtAssign(&b_y, m4);
  emlrtSetFieldR2017b(y, 0, "right_edge_xy_col", b_y, 4);
  b_y = NULL;
  m4 = emlrtCreateNumericArray(1, iv18, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m4);
  for (i = 0; i < 2; i++) {
    pData[i] = u->centroid_xy_col[i];
  }

  emlrtAssign(&b_y, m4);
  emlrtSetFieldR2017b(y, 0, "centroid_xy_col", b_y, 5);
  b_y = NULL;
  m4 = emlrtCreateLogicalScalar(u->tf_is_detected);
  emlrtAssign(&b_y, m4);
  emlrtSetFieldR2017b(y, 0, "tf_is_detected", b_y, 6);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static boolean_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tf_do_init, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(tf_do_init), &thisId);
  emlrtDestroyArray(&tf_do_init);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const struct3_T *u)
{
  const mxArray *y;
  boolean_T b_u[76800];
  const mxArray *b_y;
  const mxArray *m5;
  static const int32_T iv19[2] = { 240, 320 };

  static const int32_T iv20[1] = { 2 };

  real_T *pData;
  int32_T i;
  static const int32_T iv21[1] = { 2 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv0));
  memcpy(&b_u[0], &u->BW[0], 76800U * sizeof(boolean_T));
  b_y = NULL;
  m5 = emlrtCreateLogicalArray(2, iv19);
  emlrtInitLogicalArray(76800, m5, (boolean_T *)&b_u);
  emlrtAssign(&b_y, m5);
  emlrtSetFieldR2017b(y, 0, "BW", b_y, 0);
  b_y = NULL;
  m5 = emlrtCreateDoubleScalar(u->NUM_ROWS);
  emlrtAssign(&b_y, m5);
  emlrtSetFieldR2017b(y, 0, "NUM_ROWS", b_y, 1);
  b_y = NULL;
  m5 = emlrtCreateDoubleScalar(u->NUM_COLS);
  emlrtAssign(&b_y, m5);
  emlrtSetFieldR2017b(y, 0, "NUM_COLS", b_y, 2);
  b_y = NULL;
  m5 = emlrtCreateNumericArray(1, iv20, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m5);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_upper_xy_col[i];
  }

  emlrtAssign(&b_y, m5);
  emlrtSetFieldR2017b(y, 0, "tip_upper_xy_col", b_y, 3);
  b_y = NULL;
  m5 = emlrtCreateNumericArray(1, iv21, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m5);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_lower_xy_col[i];
  }

  emlrtAssign(&b_y, m5);
  emlrtSetFieldR2017b(y, 0, "tip_lower_xy_col", b_y, 4);
  b_y = NULL;
  m5 = emlrtCreateDoubleScalar(u->m);
  emlrtAssign(&b_y, m5);
  emlrtSetFieldR2017b(y, 0, "m", b_y, 5);
  b_y = NULL;
  m5 = emlrtCreateDoubleScalar(u->c);
  emlrtAssign(&b_y, m5);
  emlrtSetFieldR2017b(y, 0, "c", b_y, 6);
  b_y = NULL;
  m5 = emlrtCreateLogicalScalar(u->tf_is_detected);
  emlrtAssign(&b_y, m5);
  emlrtSetFieldR2017b(y, 0, "tf_is_detected", b_y, 7);
  return y;
}

static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const real_T u[2])
{
  const mxArray *y;
  const mxArray *m6;
  static const int32_T iv22[1] = { 0 };

  static const int32_T iv23[1] = { 2 };

  y = NULL;
  m6 = emlrtCreateNumericArray(1, iv22, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m6, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m6, iv23, 1);
  emlrtAssign(&y, m6);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *marker_s,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(marker_s), &thisId, y);
  emlrtDestroyArray(&marker_s);
}

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *I, const
  char_T *identifier))[230400]
{
  uint8_T (*y)[230400];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(I), &thisId);
  emlrtDestroyArray(&I);
  return y;
}
  static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct1_T *
  u)
{
  const mxArray *y;
  emxArray_boolean_T *b_u;
  int32_T i;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m3;
  static const int32_T iv14[1] = { 2 };

  real_T *pData;
  static const int32_T iv15[1] = { 2 };

  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_u, 2, (emlrtRTEInfo *)NULL, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv0));
  i = b_u->size[0] * b_u->size[1];
  b_u->size[0] = u->BW->size[0];
  b_u->size[1] = 320;
  emxEnsureCapacity_boolean_T(sp, b_u, i, (emlrtRTEInfo *)NULL);
  loop_ub = u->BW->size[0] * u->BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_u->data[i] = u->BW->data[i];
  }

  b_y = NULL;
  m3 = emlrtCreateLogicalArray(2, *(int32_T (*)[2])b_u->size);
  emlrtInitLogicalArray(u->BW->size[0] * 320, m3, b_u->data);
  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "BW", b_y, 0);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(u->NUM_ROWS);
  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "NUM_ROWS", b_y, 1);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(u->NUM_COLS);
  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "NUM_COLS", b_y, 2);
  b_y = NULL;
  m3 = emlrtCreateNumericArray(1, iv14, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m3);
  emxFree_boolean_T(&b_u);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_upper_xy_col[i];
  }

  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "tip_upper_xy_col", b_y, 3);
  b_y = NULL;
  m3 = emlrtCreateNumericArray(1, iv15, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m3);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_lower_xy_col[i];
  }

  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "tip_lower_xy_col", b_y, 4);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(u->m);
  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "m", b_y, 5);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(u->c);
  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "c", b_y, 6);
  b_y = NULL;
  m3 = emlrtCreateLogicalScalar(u->tf_is_detected);
  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "tf_is_detected", b_y, 7);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "nColors", "color_labels",
    "color_markers" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "nColors";
  y->nColors = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "nColors")), &thisId);
  thisId.fIdentifier = "color_labels";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "color_labels")), &thisId, y->color_labels);
  thisId.fIdentifier = "color_markers";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "color_markers")), &thisId, y->color_markers);
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *BLUE_s,
  const char_T *identifier, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  k_emlrt_marshallIn(sp, emlrtAlias(BLUE_s), &thisId, y);
  emlrtDestroyArray(&BLUE_s);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[8] = { "BW", "NUM_ROWS", "NUM_COLS",
    "tip_upper_xy_col", "tip_lower_xy_col", "m", "c", "tf_is_detected" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 8, fieldNames, 0U, &dims);
  thisId.fIdentifier = "BW";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "BW")),
                     &thisId, y->BW);
  thisId.fIdentifier = "NUM_ROWS";
  y->NUM_ROWS = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    1, "NUM_ROWS")), &thisId);
  thisId.fIdentifier = "NUM_COLS";
  y->NUM_COLS = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    2, "NUM_COLS")), &thisId);
  thisId.fIdentifier = "tip_upper_xy_col";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "tip_upper_xy_col")), &thisId, y->tip_upper_xy_col);
  thisId.fIdentifier = "tip_lower_xy_col";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "tip_lower_xy_col")), &thisId, y->tip_lower_xy_col);
  thisId.fIdentifier = "m";
  y->m = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "m")),
    &thisId);
  thisId.fIdentifier = "c";
  y->c = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "c")),
    &thisId);
  thisId.fIdentifier = "tf_is_detected";
  y->tf_is_detected = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 7, "tf_is_detected")), &thisId);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, boolean_T y[76800])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fract_for_top_mask, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = g_emlrt_marshallIn(sp, emlrtAlias(fract_for_top_mask), &thisId);
  emlrtDestroyArray(&fract_for_top_mask);
  return y;
}

static uint8_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[230400]
{
  uint8_T (*ret)[230400];
  static const int32_T dims[3] = { 240, 320, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 3U, dims);
  ret = (uint8_T (*)[230400])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static boolean_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5])
{
  static const int32_T dims[2] = { 1, 5 };

  int32_T i13;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i13 = 0; i13 < 5; i13++) {
    ret[i13] = (*(real_T (*)[5])emlrtMxGetData(src))[i13];
  }

  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10])
{
  static const int32_T dims[2] = { 5, 2 };

  int32_T i14;
  int32_T i15;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i14 = 0; i14 < 2; i14++) {
    for (i15 = 0; i15 < 5; i15++) {
      ret[i15 + 5 * i14] = (*(real_T (*)[10])emlrtMxGetData(src))[i15 + 5 * i14];
    }
  }

  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, boolean_T ret[76800])
{
  static const int32_T dims[2] = { 240, 320 };

  int32_T i16;
  int32_T i17;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 2U, dims);
  for (i16 = 0; i16 < 320; i16++) {
    for (i17 = 0; i17 < 240; i17++) {
      ret[i17 + 240 * i16] = (*(boolean_T (*)[76800])emlrtMxGetLogicals(src))
        [i17 + 240 * i16];
    }
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[1] = { 2 };

  int32_T i18;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  for (i18 = 0; i18 < 2; i18++) {
    ret[i18] = (*(real_T (*)[2])emlrtMxGetData(src))[i18];
  }

  emlrtDestroyArray(&src);
}

void bh_my_detect_ALGORITHM_for_codegen_api(const mxArray * const prhs[3], const
  mxArray *plhs[3])
{
  struct1_T BLUE_s;
  struct1_T YELL_s;
  struct2_T PURP_s;
  uint8_T (*I)[230400];
  boolean_T tf_do_init;
  struct0_T marker_s;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct1_T(&st, &BLUE_s, &de_emlrtRTEI, true);
  emxInitStruct_struct1_T(&st, &YELL_s, &de_emlrtRTEI, true);
  emxInitStruct_struct2_T(&st, &PURP_s, &de_emlrtRTEI, true);

  /* Marshall function inputs */
  I = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "I");
  tf_do_init = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "tf_do_init");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "marker_s", &marker_s);

  /* Invoke the target function */
  bh_my_detect_ALGORITHM_for_codegen(&st, *I, tf_do_init, &marker_s, &BLUE_s,
    &YELL_s, &PURP_s);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, &BLUE_s);
  plhs[1] = emlrt_marshallOut(&st, &YELL_s);
  plhs[2] = b_emlrt_marshallOut(&st, &PURP_s);
  emxFreeStruct_struct2_T(&PURP_s);
  emxFreeStruct_struct1_T(&YELL_s);
  emxFreeStruct_struct1_T(&BLUE_s);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void bh_my_lane_preprocess_mask_api(g_bh_my_detect_ALGORITHM_for_co *SD, const
  mxArray * const prhs[3], const mxArray *plhs[2])
{
  real_T fract_for_top_mask;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "BLUE_s", &SD->f2.BLUE_s);
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "YELL_s", &SD->f2.YELL_s);
  fract_for_top_mask = n_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]),
    "fract_for_top_mask");

  /* Invoke the target function */
  bh_my_lane_preprocess_mask(SD, &st, &SD->f2.BLUE_s, &SD->f2.YELL_s,
    fract_for_top_mask, &SD->f2.BLUE_out_s, &SD->f2.YELL_out_s);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(&SD->f2.BLUE_out_s);
  plhs[1] = c_emlrt_marshallOut(&SD->f2.YELL_out_s);
}

void bh_my_track_ALGORITHM_for_codegen_api(g_bh_my_detect_ALGORITHM_for_co *SD,
  const mxArray * const prhs[3], const mxArray *plhs[2])
{
  real_T (*BLUE_mc_col)[2];
  real_T (*YELL_mc_col)[2];
  struct3_T YELL_s;
  boolean_T tf_do_init;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  BLUE_mc_col = (real_T (*)[2])mxMalloc(sizeof(real_T [2]));
  YELL_mc_col = (real_T (*)[2])mxMalloc(sizeof(real_T [2]));

  /* Marshall function inputs */
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "BLUE_s", &SD->u1.f1.BLUE_s);
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "YELL_s", &YELL_s);
  tf_do_init = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "tf_do_init");

  /* Invoke the target function */
  bh_my_track_ALGORITHM_for_codegen(&st, &SD->u1.f1.BLUE_s, &YELL_s, tf_do_init,
    *BLUE_mc_col, *YELL_mc_col);

  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(*BLUE_mc_col);
  plhs[1] = d_emlrt_marshallOut(*YELL_mc_col);
}

/* End of code generation (_coder_bh_my_detect_ALGORITHM_for_codegen_mex_api.c) */
