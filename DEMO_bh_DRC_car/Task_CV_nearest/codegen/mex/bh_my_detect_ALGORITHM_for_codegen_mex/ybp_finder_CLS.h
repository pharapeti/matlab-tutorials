/*
 * ybp_finder_CLS.h
 *
 * Code generation for function 'ybp_finder_CLS'
 *
 */

#ifndef YBP_FINDER_CLS_H
#define YBP_FINDER_CLS_H

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
extern void LOC_find_thin_lane_marking(const emlrtStack *sp, const
  emxArray_boolean_T *BW, emxArray_boolean_T *new_BW, boolean_T *tf_found_it);
extern void ybp_finder_CLS_classify(const emlrtStack *sp, ybp_finder_CLS *OBJ,
  const uint8_T DRC_image[230400]);

#endif

/* End of code generation (ybp_finder_CLS.h) */
