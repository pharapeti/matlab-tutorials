/*
 * regionprops.h
 *
 * Code generation for function 'regionprops'
 *
 */

#ifndef REGIONPROPS_H
#define REGIONPROPS_H

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
extern void b_regionprops(const emlrtStack *sp, const emxArray_boolean_T
  *varargin_1, emxArray_struct_T *outstats);
extern void regionprops(const emlrtStack *sp, const emxArray_boolean_T
  *varargin_2, b_emxArray_struct_T *outstats);

#endif

/* End of code generation (regionprops.h) */
