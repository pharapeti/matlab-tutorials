/*
 * File: _coder_bh_MY_CV_ALGORITHMS_api.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_bh_MY_CV_ALGORITHMS_api.h"
#include "_coder_bh_MY_CV_ALGORITHMS_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "bh_MY_CV_ALGORITHMS",               /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
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
static void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int32_T
  oldNumel);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxFreeStruct_struct2_T(struct2_T *pStruct);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  boolean_T doPush);
static void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint8_T (*)[230400]
 */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[230400]
{
  uint8_T (*y)[230400];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const struct2_T *u
 * Return Type  : const mxArray *
 */
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
  const mxArray *m1;
  static const int32_T iv2[1] = { 2 };

  real_T *pData;
  static const int32_T iv3[1] = { 2 };

  static const int32_T iv4[1] = { 2 };

  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_u, 2, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 7, sv1));
  i = b_u->size[0] * b_u->size[1];
  b_u->size[0] = u->BW->size[0];
  b_u->size[1] = 320;
  emxEnsureCapacity_boolean_T(b_u, i);
  loop_ub = u->BW->size[0] * u->BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_u->data[i] = u->BW->data[i];
  }

  b_y = NULL;
  m1 = emlrtCreateLogicalArray(2, *(int32_T (*)[2])b_u->size);
  emlrtInitLogicalArray(u->BW->size[0] * 320, m1, b_u->data);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "BW", b_y, 0);
  b_y = NULL;
  m1 = emlrtCreateDoubleScalar(u->NUM_ROWS);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "NUM_ROWS", b_y, 1);
  b_y = NULL;
  m1 = emlrtCreateDoubleScalar(u->NUM_COLS);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "NUM_COLS", b_y, 2);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv2, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m1);
  emxFree_boolean_T(&b_u);
  for (i = 0; i < 2; i++) {
    pData[i] = u->left_edge_xy_col[i];
  }

  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "left_edge_xy_col", b_y, 3);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv3, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m1);
  for (i = 0; i < 2; i++) {
    pData[i] = u->right_edge_xy_col[i];
  }

  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "right_edge_xy_col", b_y, 4);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv4, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m1);
  for (i = 0; i < 2; i++) {
    pData[i] = u->centroid_xy_col[i];
  }

  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "centroid_xy_col", b_y, 5);
  b_y = NULL;
  m1 = emlrtCreateLogicalScalar(u->tf_is_detected);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "tf_is_detected", b_y, 6);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *tf_do_init
 *                const char_T *identifier
 * Return Type  : boolean_T
 */
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

/*
 * Arguments    : const struct3_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const struct3_T *u)
{
  const mxArray *y;
  boolean_T b_u[76800];
  const mxArray *b_y;
  const mxArray *m2;
  static const int32_T iv5[2] = { 240, 320 };

  static const int32_T iv6[1] = { 2 };

  real_T *pData;
  int32_T i;
  static const int32_T iv7[1] = { 2 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv0));
  memcpy(&b_u[0], &u->BW[0], 76800U * sizeof(boolean_T));
  b_y = NULL;
  m2 = emlrtCreateLogicalArray(2, iv5);
  emlrtInitLogicalArray(76800, m2, (boolean_T *)&b_u);
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
  m2 = emlrtCreateNumericArray(1, iv6, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m2);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_upper_xy_col[i];
  }

  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "tip_upper_xy_col", b_y, 3);
  b_y = NULL;
  m2 = emlrtCreateNumericArray(1, iv7, mxDOUBLE_CLASS, mxREAL);
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
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : boolean_T
 */
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[2]
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const real_T u[2])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv8[1] = { 0 };

  static const int32_T iv9[1] = { 2 };

  y = NULL;
  m3 = emlrtCreateNumericArray(1, iv8, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m3, iv9, 1);
  emlrtAssign(&y, m3);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *marker_s
 *                const char_T *identifier
 *                struct0_T *y
 * Return Type  : void
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *I
 *                const char_T *identifier
 * Return Type  : uint8_T (*)[230400]
 */
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
/*
 * Arguments    : const emlrtStack *sp
 *                const struct1_T *u
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct1_T *
  u)
{
  const mxArray *y;
  emxArray_boolean_T *b_u;
  int32_T i;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 2 };

  real_T *pData;
  static const int32_T iv1[1] = { 2 };

  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_u, 2, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv0));
  i = b_u->size[0] * b_u->size[1];
  b_u->size[0] = u->BW->size[0];
  b_u->size[1] = 320;
  emxEnsureCapacity_boolean_T(b_u, i);
  loop_ub = u->BW->size[0] * u->BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_u->data[i] = u->BW->data[i];
  }

  b_y = NULL;
  m0 = emlrtCreateLogicalArray(2, *(int32_T (*)[2])b_u->size);
  emlrtInitLogicalArray(u->BW->size[0] * 320, m0, b_u->data);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "BW", b_y, 0);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->NUM_ROWS);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "NUM_ROWS", b_y, 1);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->NUM_COLS);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "NUM_COLS", b_y, 2);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m0);
  emxFree_boolean_T(&b_u);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_upper_xy_col[i];
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "tip_upper_xy_col", b_y, 3);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv1, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m0);
  for (i = 0; i < 2; i++) {
    pData[i] = u->tip_lower_xy_col[i];
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "tip_lower_xy_col", b_y, 4);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->m);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "m", b_y, 5);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->c);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "c", b_y, 6);
  b_y = NULL;
  m0 = emlrtCreateLogicalScalar(u->tf_is_detected);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "tf_is_detected", b_y, 7);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

/*
 * Arguments    : emxArray_boolean_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int32_T
  oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex((void *)emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : struct1_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_boolean_T(&pStruct->BW);
}

/*
 * Arguments    : struct2_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct2_T(struct2_T *pStruct)
{
  emxFree_boolean_T(&pStruct->BW);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct1_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  boolean_T doPush)
{
  emxInit_boolean_T(sp, &pStruct->BW, 2, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct2_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  boolean_T doPush)
{
  emxInit_boolean_T(sp, &pStruct->BW, 2, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_boolean_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_boolean_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T *)emlrtMallocMex(sizeof(emxArray_boolean_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_boolean_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct0_T *y
 * Return Type  : void
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[5]
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[10]
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *BLUE_s
 *                const char_T *identifier
 *                struct3_T *y
 * Return Type  : void
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct3_T *y
 * Return Type  : void
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                boolean_T y[76800]
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, boolean_T y[76800])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[2]
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *fract_for_top_mask
 *                const char_T *identifier
 * Return Type  : real_T
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint8_T (*)[230400]
 */
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
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : boolean_T
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[5]
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5])
{
  static const int32_T dims[2] = { 1, 5 };

  int32_T i0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i0 = 0; i0 < 5; i0++) {
    ret[i0] = (*(real_T (*)[5])emlrtMxGetData(src))[i0];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[10]
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10])
{
  static const int32_T dims[2] = { 5, 2 };

  int32_T i1;
  int32_T i2;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < 5; i2++) {
      ret[i2 + 5 * i1] = (*(real_T (*)[10])emlrtMxGetData(src))[i2 + 5 * i1];
    }
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                boolean_T ret[76800]
 * Return Type  : void
 */
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, boolean_T ret[76800])
{
  static const int32_T dims[2] = { 240, 320 };

  int32_T i3;
  int32_T i4;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 2U, dims);
  for (i3 = 0; i3 < 320; i3++) {
    for (i4 = 0; i4 < 240; i4++) {
      ret[i4 + 240 * i3] = (*(boolean_T (*)[76800])emlrtMxGetLogicals(src))[i4 +
        240 * i3];
    }
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[2]
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[1] = { 2 };

  int32_T i5;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  for (i5 = 0; i5 < 2; i5++) {
    ret[i5] = (*(real_T (*)[2])emlrtMxGetData(src))[i5];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void bh_MY_CV_ALGORITHMS_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  bh_MY_CV_ALGORITHMS_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void bh_MY_CV_ALGORITHMS_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void bh_MY_CV_ALGORITHMS_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
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
  emxInitStruct_struct1_T(&st, &BLUE_s, true);
  emxInitStruct_struct1_T(&st, &YELL_s, true);
  emxInitStruct_struct2_T(&st, &PURP_s, true);

  /* Marshall function inputs */
  I = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "I");
  tf_do_init = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "tf_do_init");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "marker_s", &marker_s);

  /* Invoke the target function */
  bh_my_detect_ALGORITHM_for_codegen(*I, tf_do_init, &marker_s, &BLUE_s, &YELL_s,
    &PURP_s);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, &BLUE_s);
  plhs[1] = emlrt_marshallOut(&st, &YELL_s);
  plhs[2] = b_emlrt_marshallOut(&st, &PURP_s);
  emxFreeStruct_struct2_T(&PURP_s);
  emxFreeStruct_struct1_T(&YELL_s);
  emxFreeStruct_struct1_T(&BLUE_s);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void bh_my_lane_preprocess_mask_api(const mxArray * const prhs[3], const mxArray
  *plhs[2])
{
  static struct3_T BLUE_s;
  static struct3_T YELL_s;
  real_T fract_for_top_mask;
  static struct3_T BLUE_out_s;
  struct3_T YELL_out_s;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "BLUE_s", &BLUE_s);
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "YELL_s", &YELL_s);
  fract_for_top_mask = n_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]),
    "fract_for_top_mask");

  /* Invoke the target function */
  bh_my_lane_preprocess_mask(&BLUE_s, &YELL_s, fract_for_top_mask, &BLUE_out_s,
    &YELL_out_s);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(&BLUE_out_s);
  plhs[1] = c_emlrt_marshallOut(&YELL_out_s);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void bh_my_track_ALGORITHM_for_codegen_api(const mxArray * const prhs[3], const
  mxArray *plhs[2])
{
  real_T (*BLUE_mc_col)[2];
  real_T (*YELL_mc_col)[2];
  struct3_T BLUE_s;
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
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "BLUE_s", &BLUE_s);
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "YELL_s", &YELL_s);
  tf_do_init = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "tf_do_init");

  /* Invoke the target function */
  bh_my_track_ALGORITHM_for_codegen(&BLUE_s, &YELL_s, tf_do_init, *BLUE_mc_col, *
    YELL_mc_col);

  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(*BLUE_mc_col);
  plhs[1] = d_emlrt_marshallOut(*YELL_mc_col);
}

/*
 * File trailer for _coder_bh_MY_CV_ALGORITHMS_api.c
 *
 * [EOF]
 */
