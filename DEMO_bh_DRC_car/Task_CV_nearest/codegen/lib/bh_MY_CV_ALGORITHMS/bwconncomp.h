/*
 * File: bwconncomp.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef BWCONNCOMP_H
#define BWCONNCOMP_H

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
extern void bwconncomp(const emxArray_boolean_T *varargin_1, double
  *CC_Connectivity, double CC_ImageSize[2], double *CC_NumObjects,
  emxArray_real_T *CC_RegionIndices, emxArray_int32_T *CC_RegionLengths);

#endif

/*
 * File trailer for bwconncomp.h
 *
 * [EOF]
 */
