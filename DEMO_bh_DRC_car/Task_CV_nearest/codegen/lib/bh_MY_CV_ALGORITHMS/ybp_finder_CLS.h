/*
 * File: ybp_finder_CLS.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef YBP_FINDER_CLS_H
#define YBP_FINDER_CLS_H

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
extern void LOC_find_thin_lane_marking(const emxArray_boolean_T *BW,
  emxArray_boolean_T *new_BW, boolean_T *tf_found_it);
extern void ybp_finder_CLS_classify(ybp_finder_CLS *OBJ, const unsigned char
  DRC_image[230400]);
extern void ybp_finder_CLS_ybp_finder_CLS(double marker_s_nColors, const double
  marker_s_color_labels[5], const double marker_s_color_markers[10], double
  *OBJ_E_tgt_for_lane, double *OBJ_A_tgt_for_lane, double
  *OBJ_fraction_of_img_to_ignore, double *OBJ_nColors, double OBJ_color_labels[5],
  double OBJ_color_markers[10], emxArray_real_T *OBJ_label);

#endif

/*
 * File trailer for ybp_finder_CLS.h
 *
 * [EOF]
 */
