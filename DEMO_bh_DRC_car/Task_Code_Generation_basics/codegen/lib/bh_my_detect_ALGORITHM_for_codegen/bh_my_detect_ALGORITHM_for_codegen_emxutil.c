/*
 * File: bh_my_detect_ALGORITHM_for_codegen_emxutil.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"

/* Function Declarations */
static void emxCopyMatrix_real_T(double dst[2], const double src[2]);
static void emxCopyMatrix_real_T1(double dst[4], const double src[4]);
static void emxCopyMatrix_real_T2(double dst[16], const double src[16]);
static void emxCopy_boolean_T(emxArray_boolean_T **dst, emxArray_boolean_T *
  const *src);
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src);
static void emxCopy_real_T1(emxArray_real_T **dst, emxArray_real_T * const *src);
static void emxExpand_struct_T(emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxExpand_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_struct_T2(b_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_struct_T3(c_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxTrim_struct_T(emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T2(c_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);

/* Function Definitions */

/*
 * Arguments    : double dst[2]
 *                const double src[2]
 * Return Type  : void
 */
static void emxCopyMatrix_real_T(double dst[2], const double src[2])
{
  int i;
  for (i = 0; i < 2; i++) {
    dst[i] = src[i];
  }
}

/*
 * Arguments    : double dst[4]
 *                const double src[4]
 * Return Type  : void
 */
static void emxCopyMatrix_real_T1(double dst[4], const double src[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    dst[i] = src[i];
  }
}

/*
 * Arguments    : double dst[16]
 *                const double src[16]
 * Return Type  : void
 */
static void emxCopyMatrix_real_T2(double dst[16], const double src[16])
{
  int i;
  for (i = 0; i < 16; i++) {
    dst[i] = src[i];
  }
}

/*
 * Arguments    : emxArray_boolean_T **dst
 *                emxArray_boolean_T * const *src
 * Return Type  : void
 */
static void emxCopy_boolean_T(emxArray_boolean_T **dst, emxArray_boolean_T *
  const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_boolean_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

/*
 * Arguments    : emxArray_real_T **dst
 *                emxArray_real_T * const *src
 * Return Type  : void
 */
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_real_T1(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

/*
 * Arguments    : emxArray_real_T **dst
 *                emxArray_real_T * const *src
 * Return Type  : void
 */
static void emxCopy_real_T1(emxArray_real_T **dst, emxArray_real_T * const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

/*
 * Arguments    : emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T(emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T(&emxArray->data[i]);
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T1(&emxArray->data[i]);
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T2(b_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T1(&emxArray->data[i]);
  }
}

/*
 * Arguments    : c_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T3(c_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T2(&emxArray->data[i]);
  }
}

/*
 * Arguments    : emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T(emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T(&emxArray->data[i]);
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T1(&emxArray->data[i]);
  }
}

/*
 * Arguments    : c_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T2(c_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T2(&emxArray->data[i]);
  }
}

/*
 * Arguments    : b_struct_T *dst
 *                const b_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T(b_struct_T *dst, const b_struct_T *src)
{
  dst->Area = src->Area;
  dst->Eccentricity = src->Eccentricity;
  emxCopy_real_T(&dst->PixelIdxList, &src->PixelIdxList);
}

/*
 * Arguments    : c_struct_T *dst
 *                const c_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T1(c_struct_T *dst, const c_struct_T *src)
{
  dst->Orientation = src->Orientation;
  dst->Eccentricity = src->Eccentricity;
  dst->Area = src->Area;
  emxCopy_real_T(&dst->PixelIdxList, &src->PixelIdxList);
}

/*
 * Arguments    : d_struct_T *dst
 *                const d_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T2(d_struct_T *dst, const d_struct_T *src)
{
  dst->Area = src->Area;
  emxCopyMatrix_real_T(dst->Centroid, src->Centroid);
  emxCopyMatrix_real_T1(dst->BoundingBox, src->BoundingBox);
  dst->MajorAxisLength = src->MajorAxisLength;
  dst->MinorAxisLength = src->MinorAxisLength;
  dst->Eccentricity = src->Eccentricity;
  dst->Orientation = src->Orientation;
  emxCopy_boolean_T(&dst->Image, &src->Image);
  emxCopy_boolean_T(&dst->FilledImage, &src->FilledImage);
  dst->FilledArea = src->FilledArea;
  dst->EulerNumber = src->EulerNumber;
  emxCopyMatrix_real_T2(dst->Extrema, src->Extrema);
  dst->EquivDiameter = src->EquivDiameter;
  dst->Extent = src->Extent;
  emxCopy_real_T(&dst->PixelIdxList, &src->PixelIdxList);
  emxCopy_real_T1(&dst->PixelList, &src->PixelList);
  dst->Perimeter = src->Perimeter;
  emxCopy_real_T(&dst->PixelValues, &src->PixelValues);
  emxCopyMatrix_real_T(dst->WeightedCentroid, src->WeightedCentroid);
  dst->MeanIntensity = src->MeanIntensity;
  dst->MinIntensity = src->MinIntensity;
  dst->MaxIntensity = src->MaxIntensity;
  emxCopy_real_T1(&dst->SubarrayIdx, &src->SubarrayIdx);
  emxCopyMatrix_real_T(dst->SubarrayIdxLengths, src->SubarrayIdxLengths);
}

/*
 * Arguments    : emxArray_boolean_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_boolean_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_boolean_T1(emxArray_boolean_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(int) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_int32_T1(emxArray_int32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(int) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(double) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T1(emxArray_real_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(double) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T2(emxArray_real_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(double) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T(emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(b_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(b_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (b_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T1(b_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(c_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(c_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (c_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T1(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T1(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T2(b_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(c_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(c_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (c_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T1(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T2(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : c_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T3(c_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(d_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(d_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (d_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T2(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T3(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : emxArray_uint8_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
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

    newData = calloc((unsigned int)i, sizeof(unsigned char));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(unsigned char) * oldNumel);
      if (emxArray->canFreeData) {
        free((void *)emxArray->data);
      }
    }

    emxArray->data = (unsigned char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : box_info_CLS *pStruct
 * Return Type  : void
 */
void emxFreeStruct_box_info_CLS(box_info_CLS *pStruct)
{
  emxFree_boolean_T(&pStruct->BW);
}

/*
 * Arguments    : lane_info_CLS *pStruct
 * Return Type  : void
 */
void emxFreeStruct_lane_info_CLS(lane_info_CLS *pStruct)
{
  emxFree_boolean_T(&pStruct->BW);
}

/*
 * Arguments    : struct1_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_boolean_T(&pStruct->BW);
}

/*
 * Arguments    : struct2_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct2_T(struct2_T *pStruct)
{
  emxFree_boolean_T(&pStruct->BW);
}

/*
 * Arguments    : b_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T(b_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->PixelIdxList);
}

/*
 * Arguments    : c_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T1(c_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->PixelIdxList);
}

/*
 * Arguments    : d_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T2(d_struct_T *pStruct)
{
  emxFree_boolean_T(&pStruct->Image);
  emxFree_boolean_T(&pStruct->FilledImage);
  emxFree_real_T(&pStruct->PixelIdxList);
  emxFree_real_T(&pStruct->PixelList);
  emxFree_real_T(&pStruct->PixelValues);
  emxFree_real_T(&pStruct->SubarrayIdx);
}

/*
 * Arguments    : ybp_finder_CLS *pStruct
 * Return Type  : void
 */
void emxFreeStruct_ybp_finder_CLS(ybp_finder_CLS *pStruct)
{
  emxFree_real_T(&pStruct->label);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T(emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (b_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((void *)(*pEmxArray)->data);
      }
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : b_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T1(b_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (b_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (c_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T1(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((void *)(*pEmxArray)->data);
      }
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (b_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : c_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T2(c_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (c_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (d_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T2(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((void *)(*pEmxArray)->data);
      }
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (c_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_uint8_T **pEmxArray
 * Return Type  : void
 */
void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned char *)NULL) && (*pEmxArray)
        ->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

/*
 * Arguments    : box_info_CLS *pStruct
 * Return Type  : void
 */
void emxInitStruct_box_info_CLS(box_info_CLS *pStruct)
{
  emxInit_boolean_T(&pStruct->BW, 2);
}

/*
 * Arguments    : lane_info_CLS *pStruct
 * Return Type  : void
 */
void emxInitStruct_lane_info_CLS(lane_info_CLS *pStruct)
{
  emxInit_boolean_T(&pStruct->BW, 2);
}

/*
 * Arguments    : struct1_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct1_T(struct1_T *pStruct)
{
  emxInit_boolean_T(&pStruct->BW, 2);
}

/*
 * Arguments    : struct2_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct2_T(struct2_T *pStruct)
{
  emxInit_boolean_T(&pStruct->BW, 2);
}

/*
 * Arguments    : b_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T(b_struct_T *pStruct)
{
  emxInit_real_T1(&pStruct->PixelIdxList, 1);
}

/*
 * Arguments    : c_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T1(c_struct_T *pStruct)
{
  emxInit_real_T1(&pStruct->PixelIdxList, 1);
}

/*
 * Arguments    : d_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T2(d_struct_T *pStruct)
{
  emxInit_boolean_T(&pStruct->Image, 2);
  emxInit_boolean_T(&pStruct->FilledImage, 2);
  emxInit_real_T1(&pStruct->PixelIdxList, 1);
  emxInit_real_T(&pStruct->PixelList, 2);
  emxInit_real_T1(&pStruct->PixelValues, 1);
  emxInit_real_T(&pStruct->SubarrayIdx, 2);
}

/*
 * Arguments    : ybp_finder_CLS *pStruct
 * Return Type  : void
 */
void emxInitStruct_ybp_finder_CLS(ybp_finder_CLS *pStruct)
{
  emxInit_real_T(&pStruct->label, 2);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions)
{
  emxArray_boolean_T *emxArray;
  int i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_boolean_T1(emxArray_boolean_T **pEmxArray, int numDimensions)
{
  emxArray_boolean_T *emxArray;
  int i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T1(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T2(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T(emxArray_struct_T **pEmxArray, int numDimensions)
{
  emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (emxArray_struct_T *)malloc(sizeof(emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (b_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : b_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T1(b_emxArray_struct_T **pEmxArray, int numDimensions)
{
  b_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (b_emxArray_struct_T *)malloc(sizeof(b_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (c_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : b_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T2(b_emxArray_struct_T **pEmxArray, int numDimensions)
{
  b_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (b_emxArray_struct_T *)malloc(sizeof(b_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (c_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : c_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T3(c_emxArray_struct_T **pEmxArray, int numDimensions)
{
  c_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (c_emxArray_struct_T *)malloc(sizeof(c_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (d_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_uint8_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * File trailer for bh_my_detect_ALGORITHM_for_codegen_emxutil.c
 *
 * [EOF]
 */
