/*
 * bh_my_lane_preprocess_mask.h
 *
 * Code generation for function 'bh_my_lane_preprocess_mask'
 *
 */

#ifndef BH_MY_LANE_PREPROCESS_MASK_H
#define BH_MY_LANE_PREPROCESS_MASK_H

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
extern void bh_my_lane_preprocess_mask(g_bh_my_detect_ALGORITHM_for_co *SD,
  const emlrtStack *sp, const struct3_T *BLUE_s, const struct3_T *YELL_s, real_T
  fract_for_top_mask, struct3_T *BLUE_out_s, struct3_T *YELL_out_s);

#endif

/* End of code generation (bh_my_lane_preprocess_mask.h) */
