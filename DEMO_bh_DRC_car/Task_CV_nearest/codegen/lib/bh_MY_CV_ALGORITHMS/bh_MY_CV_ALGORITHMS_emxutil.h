/*
 * File: bh_MY_CV_ALGORITHMS_emxutil.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef BH_MY_CV_ALGORITHMS_EMXUTIL_H
#define BH_MY_CV_ALGORITHMS_EMXUTIL_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "bh_MY_CV_ALGORITHMS_types.h"

/* Function Declarations */
extern void emxCopyStruct_struct_T(b_struct_T *dst, const b_struct_T *src);
extern void emxCopyStruct_struct_T1(c_struct_T *dst, const c_struct_T *src);
extern void emxCopyStruct_struct_T2(d_struct_T *dst, const d_struct_T *src);
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_boolean_T1(emxArray_boolean_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int32_T1(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T1(emxArray_real_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T2(emxArray_real_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_struct_T(emxArray_struct_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_struct_T1(b_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_struct_T2(c_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);
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
extern void emxInitStruct_box_info_CLS(box_info_CLS *pStruct);
extern void emxInitStruct_struct1_T(struct1_T *pStruct);
extern void emxInitStruct_struct2_T(struct2_T *pStruct);
extern void emxInitStruct_struct_T(b_struct_T *pStruct);
extern void emxInitStruct_struct_T1(c_struct_T *pStruct);
extern void emxInitStruct_struct_T2(d_struct_T *pStruct);
extern void emxInitStruct_ybp_finder_CLS(ybp_finder_CLS *pStruct);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_boolean_T1(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_real_T1(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_real_T2(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T(emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T1(b_emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T2(c_emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for bh_MY_CV_ALGORITHMS_emxutil.h
 *
 * [EOF]
 */
