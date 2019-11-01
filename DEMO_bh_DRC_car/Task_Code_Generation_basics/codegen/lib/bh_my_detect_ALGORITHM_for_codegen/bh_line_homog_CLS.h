/*
 * File: bh_line_homog_CLS.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

#ifndef BH_LINE_HOMOG_CLS_H
#define BH_LINE_HOMOG_CLS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "bh_my_detect_ALGORITHM_for_codegen_types.h"

/* Function Declarations */
extern void LOC_classify_line_type(double normal_vec[2], char a_str_data[], int
  a_str_size[2]);
extern void c_bh_line_homog_CLS_get_roi_int(double OBJ_a, double OBJ_b, double
  OBJ_d, const char OBJ_line_type_data[], const int OBJ_line_type_size[2], const
  double vlim[2], boolean_T *tf_is_valid, double uv_bot[2], double uv_top[2]);

#endif

/*
 * File trailer for bh_line_homog_CLS.h
 *
 * [EOF]
 */
