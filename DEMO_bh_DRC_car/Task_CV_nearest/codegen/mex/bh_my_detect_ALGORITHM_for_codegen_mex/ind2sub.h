/*
 * ind2sub.h
 *
 * Code generation for function 'ind2sub'
 *
 */

#ifndef IND2SUB_H
#define IND2SUB_H

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
#include "bh_my_detect_ALGORITHM_for_codegen_mex_types.h"

/* Function Declarations */
extern boolean_T allinrange(const emxArray_int32_T *x, int32_T hi);
extern void ind2sub_indexClass(const emlrtStack *sp, const emxArray_real_T *ndx,
  emxArray_int32_T *varargout_1, emxArray_int32_T *varargout_2);

#endif

/* End of code generation (ind2sub.h) */
