/*
 * _coder_bh_my_detect_ALGORITHM_for_codegen_api.c
 *
 * Code generation for function '_coder_bh_my_detect_ALGORITHM_for_codegen_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_api.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRTEInfo wd_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_bh_my_detect_ALGORITHM_for_codegen_api",/* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[230400];
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const struct2_T *
  u);
static boolean_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tf_do_init, const char_T *identifier);
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
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
static uint8_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[230400];
static boolean_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10]);

/* Function Definitions */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[230400]
{
  uint8_T (*y)[230400];
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
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
  const mxArray *m3;
  static const int32_T iv12[1] = { 2 };

  real_T *pData;
  static const int32_T iv13[1] = { 2 };

  static const int32_T iv14[1] = { 2 };

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
  m3 = emlrtCreateNumericArray(1, iv12, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m3);
  emxFree_boolean_T(&b_u);
  for (i = 0; i < 2; i++) {
    pData[i] = u->left_edge_xy_col[i];
  }

  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "left_edge_xy_col", b_y, 3);
  b_y = NULL;
  m3 = emlrtCreateNumericArray(1, iv13, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m3);
  for (i = 0; i < 2; i++) {
    pData[i] = u->right_edge_xy_col[i];
  }

  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "right_edge_xy_col", b_y, 4);
  b_y = NULL;
  m3 = emlrtCreateNumericArray(1, iv14, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m3);
  for (i = 0; i < 2; i++) {
    pData[i] = u->centroid_xy_col[i];
  }

  emlrtAssign(&b_y, m3);
  emlrtSetFieldR2017b(y, 0, "centroid_xy_col", b_y, 5);
  b_y = NULL;
  m3 = emlrtCreateLogicalScalar(u->tf_is_detected);
  emlrtAssign(&b_y, m3);
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

static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
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
  static const char * sv0[8] = { "BW", "NUM_ROWS", "NUM_COLS",
    "tip_upper_xy_col", "tip_lower_xy_col", "m", "c", "tf_is_detected" };

  int32_T i;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m2;
  static const int32_T iv10[1] = { 2 };

  real_T *pData;
  static const int32_T iv11[1] = { 2 };

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
  m2 = emlrtCreateLogicalArray(2, *(int32_T (*)[2])b_u->size);
  emlrtInitLogicalArray(u->BW->size[0] * 320, m2, b_u->data);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "BW", b_y, 0);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(u->NUM_ROWS);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "NUM_ROWS", b_y, 1);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(u->NUM_COLS);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "NUM_COLS", b_y, 2);
  b_y = NULL;
  m2 = emlrtCreateNumericArray(1, iv10, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m2);
  emxFree_boolean_T(&b_u);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_upper_xy_col[i];
  }

  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "tip_upper_xy_col", b_y, 3);
  b_y = NULL;
  m2 = emlrtCreateNumericArray(1, iv11, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m2);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_lower_xy_col[i];
  }

  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "tip_lower_xy_col", b_y, 4);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(u->m);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "m", b_y, 5);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(u->c);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "c", b_y, 6);
  b_y = NULL;
  m2 = emlrtCreateLogicalScalar(u->tf_is_detected);
  emlrtAssign(&b_y, m2);
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
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static uint8_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[230400]
{
  uint8_T (*ret)[230400];
  static const int32_T dims[3] = { 240, 320, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 3U, dims);
  ret = (uint8_T (*)[230400])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static boolean_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5])
{
  static const int32_T dims[2] = { 1, 5 };

  int32_T i12;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i12 = 0; i12 < 5; i12++) {
    ret[i12] = (*(real_T (*)[5])emlrtMxGetData(src))[i12];
  }

  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10])
{
  static const int32_T dims[2] = { 5, 2 };

  int32_T i13;
  int32_T i14;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i13 = 0; i13 < 2; i13++) {
    for (i14 = 0; i14 < 5; i14++) {
      ret[i14 + 5 * i13] = (*(real_T (*)[10])emlrtMxGetData(src))[i14 + 5 * i13];
    }
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
  emxInitStruct_struct1_T(&st, &BLUE_s, &wd_emlrtRTEI, true);
  emxInitStruct_struct1_T(&st, &YELL_s, &wd_emlrtRTEI, true);
  emxInitStruct_struct2_T(&st, &PURP_s, &wd_emlrtRTEI, true);

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

/* End of code generation (_coder_bh_my_detect_ALGORITHM_for_codegen_api.c) */
