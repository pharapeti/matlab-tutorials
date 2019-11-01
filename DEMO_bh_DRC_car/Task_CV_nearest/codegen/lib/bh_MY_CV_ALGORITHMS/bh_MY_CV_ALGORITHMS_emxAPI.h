/*
 * File: bh_MY_CV_ALGORITHMS_emxAPI.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef BH_MY_CV_ALGORITHMS_EMXAPI_H
#define BH_MY_CV_ALGORITHMS_EMXAPI_H

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
 * File trailer for bh_MY_CV_ALGORITHMS_emxAPI.h
 *
 * [EOF]
 */
