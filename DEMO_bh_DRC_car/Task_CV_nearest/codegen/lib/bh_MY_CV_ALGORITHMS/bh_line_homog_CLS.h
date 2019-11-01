/*
 * File: bh_line_homog_CLS.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef BH_LINE_HOMOG_CLS_H
#define BH_LINE_HOMOG_CLS_H

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
extern void bh_line_homog_CLS_get_mc(double OBJ_a, double OBJ_b, double OBJ_d,
  const char OBJ_line_type_data[], const int OBJ_line_type_size[2], double
  mc_col[2]);
extern void c_bh_line_homog_CLS_bh_line_hom(emxArray_real_T *u, emxArray_real_T *
  v, double *OBJ_a, double *OBJ_b, double *OBJ_d, char OBJ_line_type_data[], int
  OBJ_line_type_size[2]);
extern void c_bh_line_homog_CLS_get_roi_int(double OBJ_a, double OBJ_b, double
  OBJ_d, const char OBJ_line_type_data[], const int OBJ_line_type_size[2], const
  double vlim[2], boolean_T *tf_is_valid, double uv_bot[2], double uv_top[2]);

#endif

/*
 * File trailer for bh_line_homog_CLS.h
 *
 * [EOF]
 */
