/*
 * File: box_info_CLS.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef BOX_INFO_CLS_H
#define BOX_INFO_CLS_H

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
extern void box_info_CLS_box_info_CLS(const emxArray_boolean_T *BW, boolean_T
  tf_found, box_info_CLS *OBJ);
extern void box_info_CLS_convert_to_struct(const emxArray_boolean_T *OBJ_BW,
  double OBJ_NUM_ROWS, const double OBJ_left_edge_xy_col[2], const double
  OBJ_right_edge_xy_col[2], const double OBJ_centroid_xy_col[2], boolean_T
  OBJ_tf_is_detected, emxArray_boolean_T *my_S_BW, double *my_S_NUM_ROWS, double
  *my_S_NUM_COLS, double my_S_left_edge_xy_col[2], double
  my_S_right_edge_xy_col[2], double my_S_centroid_xy_col[2], boolean_T
  *my_S_tf_is_detected);

#endif

/*
 * File trailer for box_info_CLS.h
 *
 * [EOF]
 */
