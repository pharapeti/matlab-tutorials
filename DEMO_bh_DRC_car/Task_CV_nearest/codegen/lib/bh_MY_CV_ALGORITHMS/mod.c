/*
 * File: mod.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "mod.h"

/* Function Definitions */

/*
 * Arguments    : int x
 * Return Type  : int
 */
int b_mod(int x)
{
  return x - x / 10 * 10;
}

/*
 * File trailer for mod.c
 *
 * [EOF]
 */
