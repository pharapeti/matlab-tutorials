/*
 * File: bh_my_lane_preprocess_mask.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef BH_MY_LANE_PREPROCESS_MASK_H
#define BH_MY_LANE_PREPROCESS_MASK_H

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
extern void bh_my_lane_preprocess_mask(const struct3_T *BLUE_s, const struct3_T *
  YELL_s, double fract_for_top_mask, struct3_T *BLUE_out_s, struct3_T
  *YELL_out_s);

#endif

/*
 * File trailer for bh_my_lane_preprocess_mask.h
 *
 * [EOF]
 */
