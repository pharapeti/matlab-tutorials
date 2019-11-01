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
#include "bh_my_detect_ALGORITHM_for_codegen_mex_types.h"

/* Function Declarations */
extern void b_lane_info_CLS_calc_info(const emlrtStack *sp, lane_info_CLS_1 *OBJ,
  const real_T vlim[2]);
extern void b_lane_info_CLS_lane_info_CLS(const emlrtStack *sp, const boolean_T
  BW[76800], boolean_T tf_found, lane_info_CLS_1 *OBJ);
extern void lane_info_CLS_calc_info(const emlrtStack *sp, lane_info_CLS_1 *OBJ);
extern void lane_info_CLS_convert_to_struct(const boolean_T OBJ_BW[76800], const
  real_T OBJ_tip_upper_xy_col[2], const real_T OBJ_tip_lower_xy_col[2], real_T
  OBJ_m, real_T OBJ_c, boolean_T OBJ_tf_is_detected, boolean_T my_S_BW[76800],
  real_T *my_S_NUM_ROWS, real_T *my_S_NUM_COLS, real_T my_S_tip_upper_xy_col[2],
  real_T my_S_tip_lower_xy_col[2], real_T *my_S_m, real_T *my_S_c, boolean_T
  *my_S_tf_is_detected);
extern void lane_info_CLS_get_mc(real_T OBJ_m, real_T OBJ_c, boolean_T
  OBJ_tf_is_detected, real_T m_data[], int32_T m_size[2], real_T c_data[],
  int32_T c_size[2]);
extern void lane_info_CLS_lane_info_CLS(const emlrtStack *sp, const
  emxArray_boolean_T *BW, boolean_T tf_found, emxArray_boolean_T *OBJ_BW, real_T
  *OBJ_NUM_ROWS, real_T *OBJ_NUM_COLS, real_T OBJ_tip_upper_xy_col[2], real_T
  OBJ_tip_lower_xy_col[2], real_T *OBJ_m, real_T *OBJ_c, boolean_T
  *OBJ_tf_is_detected);

#endif

/* End of code generation (lane_info_CLS.h) */
