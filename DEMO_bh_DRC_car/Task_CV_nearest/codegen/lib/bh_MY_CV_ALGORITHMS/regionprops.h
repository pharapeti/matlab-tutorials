/*
 * File: regionprops.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef REGIONPROPS_H
#define REGIONPROPS_H

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
extern void b_regionprops(const emxArray_boolean_T *varargin_1,
  emxArray_struct_T *outstats);
extern void regionprops(const emxArray_boolean_T *varargin_2,
  b_emxArray_struct_T *outstats);

#endif

/*
 * File trailer for regionprops.h
 *
 * [EOF]
 */
