/*
 * File: bh_my_detect_ALGORITHM_for_codegen_emxAPI.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

#ifndef BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_EMXAPI_H
#define BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_EMXAPI_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "bh_my_detect_ALGORITHM_for_codegen_types.h"

/* Function Declarations */
extern emxArray_boolean_T *emxCreateND_boolean_T(int numDimensions, int *size);
extern emxArray_boolean_T *emxCreateWrapperND_boolean_T(boolean_T *data, int
  numDimensions, int *size);
extern emxArray_boolean_T *emxCreateWrapper_boolean_T(boolean_T *data, int rows,
  int cols);
extern emxArray_boolean_T *emxCreate_boolean_T(int rows, int cols);
extern void emxDestroyArray_boolean_T(emxArray_boolean_T *emxArray);
extern void emxDestroy_struct1_T(struct1_T emxArray);
extern void emxDestroy_struct2_T(struct2_T emxArray);
extern void emxInit_struct1_T(struct1_T *pStruct);
extern void emxInit_struct2_T(struct2_T *pStruct);

#endif

/*
 * File trailer for bh_my_detect_ALGORITHM_for_codegen_emxAPI.h
 *
 * [EOF]
 */
