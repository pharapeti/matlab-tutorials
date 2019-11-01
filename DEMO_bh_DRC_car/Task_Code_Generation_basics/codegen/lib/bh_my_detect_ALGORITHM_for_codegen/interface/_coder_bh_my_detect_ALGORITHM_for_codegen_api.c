/*
 * File: _coder_bh_my_detect_ALGORITHM_for_codegen_api.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include <string.h>
#include "tmwtypes.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_api.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "bh_my_detect_ALGORITHM_for_codegen",/* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, uint8_T y[230400]);
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const struct2_T *
  u);
static boolean_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tf_do_init, const char_T *identifier);
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *marker_s,
  const char_T *identifier, struct0_T *y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *I, const
  char_T *identifier, uint8_T y[230400]);
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
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, uint8_T ret[230400]);
static boolean_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                uint8_T y[230400]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, uint8_T y[230400])
{
  static uint8_T uv0[230400];
  int32_T i0;
  int32_T i1;
  int32_T i2;
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, uv0);
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 320; i1++) {
      for (i2 = 0; i2 < 240; i2++) {
        y[(i0 + 3 * i1) + 960 * i2] = uv0[(i2 + 240 * i1) + 76800 * i0];
      }
    }
  }

  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const struct2_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const struct2_T *
  u)
{
  const mxArray *y;
  emxArray_boolean_T *b_u;
  static const char * sv1[7] = { "BW", "NUM_ROWS", "NUM_COLS",
    "left_edge_xy_col", "right_edge_xy_col", "centroid_xy_col", "tf_is_detected"
  };

  int32_T i7;
  const mxArray *b_y;
  int32_T loop_ub;
  int32_T iv3[2];
  int32_T i8;
  const mxArray *m1;
  static const int32_T iv4[1] = { 2 };

  real_T *pData;
  static const int32_T iv5[1] = { 2 };

  static const int32_T iv6[1] = { 2 };

  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_u, 2, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 7, sv1));
  i7 = b_u->size[0] * b_u->size[1];
  b_u->size[1] = u->BW->size[0];
  b_u->size[0] = 320;
  emxEnsureCapacity_boolean_T(b_u, i7);
  for (i7 = 0; i7 < 320; i7++) {
    loop_ub = u->BW->size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_u->data[i8 + b_u->size[1] * i7] = u->BW->data[i7 + u->BW->size[1] * i8];
    }
  }

  b_y = NULL;
  iv3[0] = b_u->size[1];
  iv3[1] = b_u->size[0];
  m1 = emlrtCreateLogicalArray(2, iv3);
  b_u->size[1] = iv3[0];
  b_u->size[0] = iv3[1];
  emlrtInitLogicalArray(b_u->size[1] * 320, m1, b_u->data);
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
  m1 = emlrtCreateNumericArray(1, iv4, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m1);
  i7 = 0;
  emxFree_boolean_T(&b_u);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    pData[i7] = u->left_edge_xy_col[loop_ub];
    i7++;
  }

  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "left_edge_xy_col", b_y, 3);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv5, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m1);
  i7 = 0;
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    pData[i7] = u->right_edge_xy_col[loop_ub];
    i7++;
  }

  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "right_edge_xy_col", b_y, 4);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv6, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m1);
  i7 = 0;
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    pData[i7] = u->centroid_xy_col[loop_ub];
    i7++;
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
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : boolean_T
 */
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
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
 *                uint8_T y[230400]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *I, const
  char_T *identifier, uint8_T y[230400])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(I), &thisId, y);
  emlrtDestroyArray(&I);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const struct1_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct1_T *u)
{
  const mxArray *y;
  emxArray_boolean_T *b_u;
  static const char * sv0[8] = { "BW", "NUM_ROWS", "NUM_COLS",
    "tip_upper_xy_col", "tip_lower_xy_col", "m", "c", "tf_is_detected" };

  int32_T i5;
  const mxArray *b_y;
  int32_T loop_ub;
  int32_T iv0[2];
  int32_T i6;
  const mxArray *m0;
  static const int32_T iv1[1] = { 2 };

  real_T *pData;
  static const int32_T iv2[1] = { 2 };

  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_u, 2, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv0));
  i5 = b_u->size[0] * b_u->size[1];
  b_u->size[1] = u->BW->size[0];
  b_u->size[0] = 320;
  emxEnsureCapacity_boolean_T(b_u, i5);
  for (i5 = 0; i5 < 320; i5++) {
    loop_ub = u->BW->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_u->data[i6 + b_u->size[1] * i5] = u->BW->data[i5 + u->BW->size[1] * i6];
    }
  }

  b_y = NULL;
  iv0[0] = b_u->size[1];
  iv0[1] = b_u->size[0];
  m0 = emlrtCreateLogicalArray(2, iv0);
  b_u->size[1] = iv0[0];
  b_u->size[0] = iv0[1];
  emlrtInitLogicalArray(b_u->size[1] * 320, m0, b_u->data);
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
  m0 = emlrtCreateNumericArray(1, iv1, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i5 = 0;
  emxFree_boolean_T(&b_u);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    pData[i5] = u->tip_upper_xy_col[loop_ub];
    i5++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "tip_upper_xy_col", b_y, 3);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv2, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m0);
  i5 = 0;
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    pData[i5] = u->tip_lower_xy_col[loop_ub];
    i5++;
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
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
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
  real_T dv0[5];
  int32_T i3;
  real_T dv1[10];
  int32_T i4;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "nColors";
  y->nColors = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "nColors")), &thisId);
  thisId.fIdentifier = "color_labels";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "color_labels")), &thisId, dv0);
  for (i3 = 0; i3 < 5; i3++) {
    y->color_labels[i3] = dv0[i3];
  }

  thisId.fIdentifier = "color_markers";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "color_markers")), &thisId, dv1);
  for (i3 = 0; i3 < 5; i3++) {
    for (i4 = 0; i4 < 2; i4++) {
      y->color_markers[i4 + (i3 << 1)] = dv1[i3 + 5 * i4];
    }
  }

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
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
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
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
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
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                uint8_T ret[230400]
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, uint8_T ret[230400])
{
  static const int32_T dims[3] = { 240, 320, 3 };

  int32_T i9;
  int32_T i10;
  int32_T i11;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 3U, dims);
  for (i9 = 0; i9 < 3; i9++) {
    for (i10 = 0; i10 < 320; i10++) {
      for (i11 = 0; i11 < 240; i11++) {
        ret[(i11 + 240 * i10) + 76800 * i9] = (*(uint8_T (*)[230400])
          emlrtMxGetData(src))[(i11 + 240 * i10) + 76800 * i9];
      }
    }
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : boolean_T
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[5]
 * Return Type  : void
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[10]
 * Return Type  : void
 */
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

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void bh_my_detect_ALGORITHM_for_codegen_api(const mxArray * const prhs[3],
  int32_T nlhs, const mxArray *plhs[3])
{
  struct1_T BLUE_s;
  struct1_T YELL_s;
  struct2_T PURP_s;
  static uint8_T I[230400];
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
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "I", I);
  tf_do_init = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "tf_do_init");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "marker_s", &marker_s);

  /* Invoke the target function */
  bh_my_detect_ALGORITHM_for_codegen(I, tf_do_init, &marker_s, &BLUE_s, &YELL_s,
    &PURP_s);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, &BLUE_s);
  emxFreeStruct_struct1_T(&BLUE_s);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&st, &YELL_s);
  }

  emxFreeStruct_struct1_T(&YELL_s);
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(&st, &PURP_s);
  }

  emxFreeStruct_struct2_T(&PURP_s);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void bh_my_detect_ALGORITHM_for_codegen_atexit(void)
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
  bh_my_detect_ALGORITHM_for_codegen_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void bh_my_detect_ALGORITHM_for_codegen_initialize(void)
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
void bh_my_detect_ALGORITHM_for_codegen_terminate(void)
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
 * File trailer for _coder_bh_my_detect_ALGORITHM_for_codegen_api.c
 *
 * [EOF]
 */
