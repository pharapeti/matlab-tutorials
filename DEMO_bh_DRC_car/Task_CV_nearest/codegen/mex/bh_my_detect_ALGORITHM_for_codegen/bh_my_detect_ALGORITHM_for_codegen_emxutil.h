/*
 * bh_my_detect_ALGORITHM_for_codegen_emxutil.h
 *
 * Code generation for function 'bh_my_detect_ALGORITHM_for_codegen_emxutil'
 *
 */

#ifndef BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_EMXUTIL_H
#define BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_EMXUTIL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "bh_my_detect_ALGORITHM_for_codegen_types.h"

/* Function Declarations */
extern void emxCopyStruct_struct_T(const emlrtStack *sp, b_struct_T *dst, const
  b_struct_T *src, const emlrtRTEInfo *srcLocation);
extern void emxCopyStruct_struct_T1(const emlrtStack *sp, c_struct_T *dst, const
  c_struct_T *src, const emlrtRTEInfo *srcLocation);
extern void emxCopyStruct_struct_T2(const emlrtStack *sp, d_struct_T *dst, const
  d_struct_T *src, const emlrtRTEInfo *srcLocation);
extern void emxCopyStruct_ybp_finder_CLS(const emlrtStack *sp, ybp_finder_CLS
  *dst, const ybp_finder_CLS *src, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_boolean_T1(const emlrtStack *sp,
  emxArray_boolean_T *emxArray, int32_T oldNumel, const emlrtRTEInfo
  *srcLocation);
extern void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_int32_T1(const emlrtStack *sp, emxArray_int32_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_real_T1(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_real_T2(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_struct_T(const emlrtStack *sp, emxArray_struct_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_struct_T1(const emlrtStack *sp,
  b_emxArray_struct_T *emxArray, int32_T oldNumel, const emlrtRTEInfo
  *srcLocation);
extern void emxEnsureCapacity_struct_T2(const emlrtStack *sp,
  c_emxArray_struct_T *emxArray, int32_T oldNumel, const emlrtRTEInfo
  *srcLocation);
extern void emxEnsureCapacity_uint8_T(const emlrtStack *sp, emxArray_uint8_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxFreeStruct_box_info_CLS(box_info_CLS *pStruct);
extern void emxFreeStruct_struct1_T(struct1_T *pStruct);
extern void emxFreeStruct_struct2_T(struct2_T *pStruct);
extern void emxFreeStruct_struct_T(b_struct_T *pStruct);
extern void emxFreeStruct_struct_T1(c_struct_T *pStruct);
extern void emxFreeStruct_struct_T2(d_struct_T *pStruct);
extern void emxFreeStruct_ybp_finder_CLS(ybp_finder_CLS *pStruct);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxFree_struct_T(emxArray_struct_T **pEmxArray);
extern void emxFree_struct_T1(b_emxArray_struct_T **pEmxArray);
extern void emxFree_struct_T2(c_emxArray_struct_T **pEmxArray);
extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
extern void emxInitStruct_box_info_CLS(const emlrtStack *sp, box_info_CLS
  *pStruct, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInitStruct_struct_T(const emlrtStack *sp, b_struct_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInitStruct_struct_T1(const emlrtStack *sp, c_struct_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInitStruct_struct_T2(const emlrtStack *sp, d_struct_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInitStruct_ybp_finder_CLS(const emlrtStack *sp, ybp_finder_CLS
  *pStruct, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void emxInit_boolean_T1(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_int32_T1(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_real_T1(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_real_T2(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_struct_T(const emlrtStack *sp, emxArray_struct_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_struct_T1(const emlrtStack *sp, b_emxArray_struct_T
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void emxInit_struct_T2(const emlrtStack *sp, c_emxArray_struct_T
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (bh_my_detect_ALGORITHM_for_codegen_emxutil.h) */
