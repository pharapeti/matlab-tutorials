/*
 * File: lane_info_CLS.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef LANE_INFO_CLS_H
#define LANE_INFO_CLS_H

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
extern void b_lane_info_CLS_calc_info(lane_info_CLS_1 *OBJ, const double vlim[2]);
extern void b_lane_info_CLS_convert_to_stru(const boolean_T OBJ_BW[76800], const
  double OBJ_tip_upper_xy_col[2], const double OBJ_tip_lower_xy_col[2], double
  OBJ_m, double OBJ_c, boolean_T OBJ_tf_is_detected, boolean_T my_S_BW[76800],
  double *my_S_NUM_ROWS, double *my_S_NUM_COLS, double my_S_tip_upper_xy_col[2],
  double my_S_tip_lower_xy_col[2], double *my_S_m, double *my_S_c, boolean_T
  *my_S_tf_is_detected);
extern void b_lane_info_CLS_lane_info_CLS(const boolean_T BW[76800], boolean_T
  tf_found, lane_info_CLS_1 *OBJ);
extern void lane_info_CLS_calc_info(lane_info_CLS_1 *OBJ);
extern void lane_info_CLS_convert_to_struct(const emxArray_boolean_T *OBJ_BW,
  double OBJ_NUM_ROWS, const double OBJ_tip_upper_xy_col[2], const double
  OBJ_tip_lower_xy_col[2], double OBJ_m, double OBJ_c, boolean_T
  OBJ_tf_is_detected, emxArray_boolean_T *my_S_BW, double *my_S_NUM_ROWS, double
  *my_S_NUM_COLS, double my_S_tip_upper_xy_col[2], double my_S_tip_lower_xy_col
  [2], double *my_S_m, double *my_S_c, boolean_T *my_S_tf_is_detected);
extern void lane_info_CLS_get_mc(double OBJ_m, double OBJ_c, boolean_T
  OBJ_tf_is_detected, double m_data[], int m_size[2], double c_data[], int
  c_size[2]);
extern void lane_info_CLS_lane_info_CLS(const emxArray_boolean_T *BW, boolean_T
  tf_found, emxArray_boolean_T *OBJ_BW, double *OBJ_NUM_ROWS, double
  *OBJ_NUM_COLS, double OBJ_tip_upper_xy_col[2], double OBJ_tip_lower_xy_col[2],
  double *OBJ_m, double *OBJ_c, boolean_T *OBJ_tf_is_detected);

#endif

/*
 * File trailer for lane_info_CLS.h
 *
 * [EOF]
 */
