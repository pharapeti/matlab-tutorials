/*
 * bh_line_homog_CLS.h
 *
 * Code generation for function 'bh_line_homog_CLS'
 *
 */

#ifndef BH_LINE_HOMOG_CLS_H
#define BH_LINE_HOMOG_CLS_H

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
extern void c_bh_line_homog_CLS_bh_line_hom(const emlrtStack *sp,
  emxArray_real_T *u, emxArray_real_T *v, real_T *OBJ_a, real_T *OBJ_b, real_T
  *OBJ_d, char_T OBJ_line_type_data[], int32_T OBJ_line_type_size[2]);
extern void c_bh_line_homog_CLS_get_roi_int(const emlrtStack *sp, real_T OBJ_a,
  real_T OBJ_b, real_T OBJ_d, const char_T OBJ_line_type_data[], const int32_T
  OBJ_line_type_size[2], const real_T vlim[2], boolean_T *tf_is_valid, real_T
  uv_bot[2], real_T uv_top[2]);

#endif

/* End of code generation (bh_line_homog_CLS.h) */
