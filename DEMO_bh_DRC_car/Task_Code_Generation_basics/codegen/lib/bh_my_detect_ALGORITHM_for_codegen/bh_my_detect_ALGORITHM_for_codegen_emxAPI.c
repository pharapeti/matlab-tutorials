/*
 * File: bh_my_detect_ALGORITHM_for_codegen_emxAPI.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include <stdlib.h>
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxAPI.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : int numDimensions
 *                int *size
 * Return Type  : emxArray_boolean_T *
 */
emxArray_boolean_T *emxCreateND_boolean_T(int numDimensions, int *size)
{
  emxArray_boolean_T *emx;
  int numEl;
  int i;
  emxInit_boolean_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (boolean_T *)calloc((unsigned int)numEl, sizeof(boolean_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : boolean_T *data
 *                int numDimensions
 *                int *size
 * Return Type  : emxArray_boolean_T *
 */
emxArray_boolean_T *emxCreateWrapperND_boolean_T(boolean_T *data, int
  numDimensions, int *size)
{
  emxArray_boolean_T *emx;
  int numEl;
  int i;
  emxInit_boolean_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : boolean_T *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_boolean_T *
 */
emxArray_boolean_T *emxCreateWrapper_boolean_T(boolean_T *data, int rows, int
  cols)
{
  emxArray_boolean_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_boolean_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_boolean_T *
 */
emxArray_boolean_T *emxCreate_boolean_T(int rows, int cols)
{
  emxArray_boolean_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_boolean_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (boolean_T *)calloc((unsigned int)numEl, sizeof(boolean_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : emxArray_boolean_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_boolean_T(emxArray_boolean_T *emxArray)
{
  emxFree_boolean_T(&emxArray);
}

/*
 * Arguments    : struct1_T emxArray
 * Return Type  : void
 */
void emxDestroy_struct1_T(struct1_T emxArray)
{
  emxFreeStruct_struct1_T(&emxArray);
}

/*
 * Arguments    : struct2_T emxArray
 * Return Type  : void
 */
void emxDestroy_struct2_T(struct2_T emxArray)
{
  emxFreeStruct_struct2_T(&emxArray);
}

/*
 * Arguments    : struct1_T *pStruct
 * Return Type  : void
 */
void emxInit_struct1_T(struct1_T *pStruct)
{
  emxInitStruct_struct1_T(pStruct);
}

/*
 * Arguments    : struct2_T *pStruct
 * Return Type  : void
 */
void emxInit_struct2_T(struct2_T *pStruct)
{
  emxInitStruct_struct2_T(pStruct);
}

/*
 * File trailer for bh_my_detect_ALGORITHM_for_codegen_emxAPI.c
 *
 * [EOF]
 */
