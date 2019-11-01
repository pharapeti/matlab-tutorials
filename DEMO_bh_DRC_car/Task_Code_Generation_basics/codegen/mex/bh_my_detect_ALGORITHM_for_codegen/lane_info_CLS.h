/*
 * lane_info_CLS.h
 *
 * Code generation for function 'lane_info_CLS'
 *
 */

#ifndef LANE_INFO_CLS_H
#define LANE_INFO_CLS_H

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
extern void lane_info_CLS_lane_info_CLS(const emlrtStack *sp, const
  emxArray_boolean_T *BW, boolean_T tf_found, emxArray_boolean_T *OBJ_BW, real_T
  *OBJ_NUM_ROWS, real_T *OBJ_NUM_COLS, real_T OBJ_tip_upper_xy_col[2], real_T
  OBJ_tip_lower_xy_col[2], real_T *OBJ_m, real_T *OBJ_c, boolean_T
  *OBJ_tf_is_detected);

#endif

/* End of code generation (lane_info_CLS.h) */
